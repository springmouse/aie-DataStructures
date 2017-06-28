#include "GameStates.h"
#include "Factory.h"
#include "Input.h"
#include "Information.h"
#include <string>
#include <time.h>

#include <iostream>

#pragma region GameStates

GameStates::GameStates()
{
}


GameStates::~GameStates()
{
}

#pragma endregion

///////////////////////////////////

#pragma region MenuState

MenuState::MenuState()
{
}

MenuState::~MenuState()
{
}

void MenuState::onUpdate(float deltaTime)
{
	//runs while state is active
    if (m_active)
    {
		//checks to see if game should run or close down
        if (INPUT->isKeyDown(aie::INPUT_KEY_1))
        {
            INFOMATION->pushInfo(eGameStateType::INGAME);
        }

        if (INPUT->isKeyDown(aie::INPUT_KEY_2))
        {
            INFOMATION->pop = true;
        }
    }
}

void MenuState::onDraw(aie::Renderer2D * m_2dRenderer, aie::Font* font)
{
	//renders the options to the screen
    if (m_active)
    {
        m_2dRenderer->drawText(font, "1: start game", 500, 360);
        m_2dRenderer->drawText(font, "2: close game", 500, 180);
    }
}

void MenuState::onPopped()
{
	//slates the programe to close down
    INFOMATION->quit = true;
}

#pragma endregion

///////////////////////////////////

#pragma region InGameState

InGameState::InGameState()
{
	//creates the player
	m_playerUnit = FACTORY->MakeUnit(eUnitTypes::PLAYER);

	//makes sure the wave number is set to zero
	m_waveNumber = 0;

	//spawns in a new wave
	SpawnWave();

	//initilizes the player unit
	m_playerUnit->PlayerInit(Vector2(760, 460));

	//set timers to zero
	m_shotTimer = 0;
	m_timer = 0;

	//sets the seed for rand
	srand(time(NULL));
}

InGameState::~InGameState()
{
}

void InGameState::onUpdate(float deltaTime)
{
    if (m_active)
    {
		//update timers
        m_timer += deltaTime;
		m_shotTimer += deltaTime;
		m_collisionTimer += deltaTime;

		//check if we need to pop the game out
        if (INPUT->isKeyDown(aie::INPUT_KEY_ESCAPE))
        {
            INFOMATION->pop = true;
        }

		//update the unit
        m_playerUnit->Update(deltaTime);

		//fire any bullets
		if (INPUT->isMouseButtonDown(0) && m_shotTimer >= 0.1f)
		{
			Vector2 mousPos = Vector2((float)INPUT->getMouseX(), (float)INPUT->getMouseY());
			Vector2 spawnpoint = m_playerUnit->m_globalPos.GetTranslation();

			Vector2 dir = mousPos - spawnpoint;
			dir.normalise();

			Unit * holder = FACTORY->MakeUnit(eUnitTypes::BULLET);

			holder->BulletInit(spawnpoint, dir);

			m_bullets.PushBack(holder);

			m_shotTimer = 0;
		}

		//update the bullets
		for (auto & p : m_bullets)
		{
			p->Update(deltaTime);
		}

		//update the enemeys
		for (auto & p : m_enemyUnits)
		{
			p->Update(deltaTime);
		}

		//check for collisions
		if (m_collisionTimer >= 0.1f && m_playerUnit->CheckAlive())
		{
			//check if the enemies have collided with the player
			for (auto & i : m_enemyUnits)
			{
				if (CollisionDitection(m_playerUnit, i))
				{
					m_playerUnit->ChangeHealth(-10);
				}
			}

			//check if the bullets have collided with the enemies
			for (auto & i : m_bullets)
			{
				//if the bullet is already dead add it to the list to be destroyed and break
				if (i->CheckAlive() == false)
				{
					m_bulletsToBeDestroyed.PushBack(i);
					break;
				}

				for (auto & p : m_enemyUnits)
				{
					if (BulletCollision(i, p))
					{
						//if collided deal damage to the enemies
						p->ChangeHealth(i->GetDamage());

						//if enemies are dead slate them for termination
						if (p->CheckAlive() == false)
						{
							m_enemystoBeDestroyed.PushBack(p);
						}

						//slate bullet for termination if it has hit as well
						m_bulletsToBeDestroyed.PushBack(i);
						break;
					}
				}
			}

			//reset collision timer
			m_collisionTimer = 0;
		}

		//destroy an enemies slated to be terminated
		if (m_enemystoBeDestroyed.GetLength() > 0)
		{
			for (auto & i : m_enemystoBeDestroyed)
			{
				m_enemyUnits.Remove(i);
			}
			m_enemystoBeDestroyed.DeleteAll();
		}
		
		//destroys any bullets slated for termination
		if (m_bulletsToBeDestroyed.GetLength() > 0)
		{
			for (auto & i : m_bulletsToBeDestroyed)
			{
				m_bullets.Remove(i);
			}
			m_bulletsToBeDestroyed.DeleteAll();
		}

		//if players dead end the game
		if (m_playerUnit->CheckAlive() == false)
		{
			INFOMATION->quit = true;
		}

		//if all enemies are dead start new wave
		if (m_enemyUnits.GetLength() <= 0)
		{
			m_waveNumber++;
			SpawnWave();
		}

		//the enemy list should nevre be emtpy at this point
		if (m_enemyUnits.GetLength() <= 0)
		{
			assert(m_enemyUnits.GetLength() > 0 && "the enemy list was empty when it should not of been");
		}
    }
}

void InGameState::onDraw(aie::Renderer2D * m_2dRenderer, aie::Font* font)
{
    if (m_active)
    {
		//draws the player
        m_2dRenderer->setRenderColour(0, 1, 1, 1);
        m_2dRenderer->drawCircle(m_playerUnit->m_globalPos[2].x, m_playerUnit->m_globalPos[2].y, m_playerUnit->GetRadius());

		//draws all the bullets to screen
		for (auto p : m_bullets)
		{
			if (p->CheckAlive())
			{
				m_2dRenderer->setRenderColour(0, 1, 0, 1);
				m_2dRenderer->drawCircle(p->m_globalPos[2].x, p->m_globalPos[2].y, p->GetRadius());
			}
		}

		//draws the enemies to screen
		for (auto p : m_enemyUnits)
		{
			m_2dRenderer->setRenderColour(1, 0, 0, 1);
			m_2dRenderer->drawCircle(p->m_globalPos[2].x, p->m_globalPos[2].y, p->GetRadius());
		}

		//draws options to screen
		m_2dRenderer->setRenderColour(1, 1, 1, 1);
		std::string name = "Time since started running " + std::to_string(m_timer);
		m_2dRenderer->drawText(font, name.c_str(), 0, 700);

		m_2dRenderer->drawText(font, "press esc to go back to main menu", 0, 10);
    }
}

bool InGameState::CollisionDitection(Unit * a, Unit * b)
{

	//finds the vector between the two centers of the objects colliding
	Vector2 p = Vector2(b->m_globalPos[2].x, b->m_globalPos[2].y);
	Vector2 c = Vector2(a->m_globalPos[2].x, a->m_globalPos[2].y);

	Vector2 mtv = p - c;

	//the magnatuied^2 of the vector
	float t = mtv.dot(mtv);

	//if the magnatuied^2 of the vector between the two points is less then the combined radiuses of the two points^2
	//then we have collided
	if (t <= ((a->GetRadius() + b->GetRadius())*(a->GetRadius() + b->GetRadius())))
	{
		b->ChangeLocalPos(Vector2(mtv.x, mtv.y));

		return true;
	}

	return false;
}

bool InGameState::BulletCollision(Unit * a, Unit * b)
{
	//finds the vector between the two centers of the objects colliding
	Vector2 p = Vector2(b->m_globalPos[2].x, b->m_globalPos[2].y);
	Vector2 c = Vector2(a->m_globalPos[2].x, a->m_globalPos[2].y);

	Vector2 mtv = p - c;

	//the magnatuied^2 of the vector
	float t = mtv.dot(mtv);

	//if the magnatuied^2 of the vector between the two points is less then the combined radiuses of the two points^2
	//then we have collided
	if (t <= ((a->GetRadius() + b->GetRadius())*(a->GetRadius() + b->GetRadius())))
	{
		return true;
	}
	else
	{
		return false;
	}
}



void InGameState::SpawnWave()
{
	//creat all the units
	for (int i = 0; i < 100 + (10 * m_waveNumber); i++)
	{
		m_enemyUnits.PushBack(FACTORY->MakeUnit(eUnitTypes::BASICENEMY));
	}

	for (auto & i : m_enemyUnits)
	{
		//get a random angle
		float xAngle = rand() % 360;
		float yAngle = rand() % 360;

		//get a random point on the circle 
		float x = 360 * cos(xAngle);
		float y = 360 * sin(yAngle);

		//assign it to a vector
		Vector2 v1 = Vector2(x, y);

		//normalise the vector so we get a direction
		v1.normalise();

		//multiply it or so that everything should be in a nice big circle
		v1 *= 360;

		//offset it so it is in the right position
		v1.x += 620 * 1;
		v1.y += 460 * 1;

		//initialise the enemy unit
		i->Init(v1, m_playerUnit);
	}
}
#pragma endregion

///////////////////////////////////

