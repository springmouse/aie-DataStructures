#include "PlayerUnit.h"
#include "Factory.h"


PlayerUnit::PlayerUnit()
{
    m_globalPos.Translate(Vector2(500, 180));
    m_speed = 200;
	m_radius = 20;
}


PlayerUnit::~PlayerUnit()
{
}

void PlayerUnit::Update(float deltaTime)
{
    m_movemeantTimer += deltaTime;

    if (m_movemeantTimer > 0.2f)
    {
        //move up
        if (INPUT->isKeyDown(aie::INPUT_KEY_W))
        {
            m_movemeantTimer = 0;
            m_localPos.Translate((Vector2(0, 1) * m_speed)* deltaTime);
        }
        //move down
        if (INPUT->isKeyDown(aie::INPUT_KEY_S))
        {
            m_movemeantTimer = 0;
            m_localPos.Translate((Vector2(0, -1) * m_speed) * deltaTime);
        }
        //move right
        if (INPUT->isKeyDown(aie::INPUT_KEY_D))
        {
            m_movemeantTimer = 0;
            m_localPos.Translate((Vector2(1, 0) * m_speed) * deltaTime);
        }
        //move left
        if (INPUT->isKeyDown(aie::INPUT_KEY_A))
        {
            m_movemeantTimer = 0;
            m_localPos.Translate((Vector2(-1, 0) * m_speed) * deltaTime);
        }
    }

	//update our Global position
    m_globalPos = m_localPos;
}

void PlayerUnit::PlayerInit(Vector2 pos)
{
	m_localPos.Translate(pos);
	m_health = 100;
}

bool PlayerUnit::CheckAlive()
{
	if (m_health > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
