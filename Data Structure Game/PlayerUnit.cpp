#include "PlayerUnit.h"



PlayerUnit::PlayerUnit()
{
    m_globalPos.Translate(Vector2(500, 180));
    m_speed = 250;
}


PlayerUnit::~PlayerUnit()
{
}

void PlayerUnit::Update(float deltaTime)
{
    m_movemeantTimer += deltaTime;
    m_rotateTimer += deltaTime;

    if (m_movemeantTimer > 0.2f)
    {
        //up
        if (INPUT->isKeyDown(aie::INPUT_KEY_W))
        {
            m_movemeantTimer = 0;
            m_localPos.Translate((Vector2(0, 1) * m_speed)* deltaTime);
        }
        //down
        if (INPUT->isKeyDown(aie::INPUT_KEY_S))
        {
            m_movemeantTimer = 0;
            m_localPos.Translate((Vector2(0, -1) * m_speed) * deltaTime);
        }
        //right
        if (INPUT->isKeyDown(aie::INPUT_KEY_D))
        {
            m_movemeantTimer = 0;
            m_localPos.Translate((Vector2(1, 0) * m_speed) * deltaTime);
        }
        //left
        if (INPUT->isKeyDown(aie::INPUT_KEY_A))
        {
            m_movemeantTimer = 0;
            m_localPos.Translate((Vector2(-1, 0) * m_speed) * deltaTime);
        }
    }

    if (m_rotateTimer >= 0.02f)
    {
        if (INPUT->isKeyDown(aie::INPUT_KEY_E))
        {
            m_localPos.RotateZ(-deltaTime);
            m_rotateTimer = 0;
        }

        if (INPUT->isKeyDown(aie::INPUT_KEY_Q))
        {
            m_localPos.RotateZ(deltaTime);
            m_rotateTimer = 0;
        }
    }

    m_globalPos = m_localPos;
}
