#include "Bullet.h"



Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime)
{
	if (m_lifeTimmer <= 5.0f)
	{
		//update our timers
		m_movemeantTimer += deltaTime;
		m_lifeTimmer += deltaTime;

		//move the dullet in the direction that was passed in
		if (m_movemeantTimer <= 0.1f)
		{
			m_localPos.Translate((m_movemeantDirection * m_speed) * deltaTime);
			m_movemeantTimer = 0;
		}
	}

	//updates our position in world
	m_globalPos = m_localPos;
}

void Bullet::BulletInit(Vector2 pos, Vector2 dir)
{
	m_localPos.Translate(pos);
	m_movemeantDirection = dir;

	m_speed = 250;
	m_radius = 5;

	m_damage = -10;

	m_lifeTimmer = 0;
	m_movemeantTimer = 0;
}

bool Bullet::CheckAlive()
{
	if (m_lifeTimmer >= 5.0f)
	{
		return false;
	}
	else
	{
		return true;
	}
}
