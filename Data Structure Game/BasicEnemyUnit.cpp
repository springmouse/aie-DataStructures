#include "BasicEnemyUnit.h"



BasicEnemyUnit::BasicEnemyUnit()
{
}


BasicEnemyUnit::~BasicEnemyUnit()
{
}


void BasicEnemyUnit::Init(Vector2 pos, Unit * player)
{
	m_localPos.Translate(pos);
	m_player = player;

	m_health = 10;

	m_speed = 250;
	m_radius = 20;
}

void BasicEnemyUnit::Update(float deltaTime)
{
	m_movemeantTimer += deltaTime;

	if (m_movemeantTimer >= 0.2)
	{
		m_movemeantTimer = 0;

		//finds the direction the player is from the BasicEnemyUnit
		Vector2 v1 = m_localPos.GetTranslation();
		Vector2 v2 = m_player->m_localPos.GetTranslation();
		Vector2 v3 = v2 - v1;
		v3.normalise();

		//moves BasicEnemyUnit towards the player
		m_localPos.Translate((v3 * m_speed) * deltaTime);

		//updates our global position
		m_globalPos = m_localPos;
	}

}

bool BasicEnemyUnit::CheckAlive()
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


