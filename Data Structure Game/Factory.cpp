#include "Factory.h"
#include "PlayerUnit.h"
#include "BasicEnemyUnit.h"
#include "Bullet.h"



Factory::Factory()
{
}


Factory::~Factory()
{
}

//returns a pointer to a static factory 
//this helps to ensure that there can only be one factory instance
Factory * Factory::GetInstanceOfFactory()
{
    static Factory factory;

    return & factory;
}

//this makes a new GameState to pass out
GameStates * Factory::MakeState(eGameStateType type)
{
    GameStates * p = nullptr;

    switch (type)
    {
    case eGameStateType::MENU:
        p = new MenuState;
        break;

    case eGameStateType::INGAME:
        p = new InGameState;
        break;

    default:
        assert(false && "Factory was passed an invalid Game State type to try and create or type does not yet exist in factory.");
        break;
    }

    return p;
}

//creates a new unit to pass out
Unit * Factory::MakeUnit(eUnitTypes type)
{
    Unit * p = nullptr;

    switch (type)
    {
    case PLAYER:
        p = new PlayerUnit;
        break;

    case BASICENEMY:
        p = new BasicEnemyUnit;
        break;

	case BULLET:
		p = new Bullet;
		break;

    default:
        assert(false && "Factory was passed an invalid Unit type to try and create or type does not yet exist in factory.");
        break;
    }


    return p;
}
