#include "Factory.h"
#include "PlayerUnit.h"
#include "BasicEnemyUnit.h"



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

GameStates * Factory::MakeState(GameStateType type)
{
    GameStates * p = nullptr;

    switch (type)
    {
    case GameStateType::MENU:
        p = new MenuState;
        break;

    case GameStateType::INGAME:
        p = new InGameState;
        break;

    default:
        assert(false && "Factory was passed an invalid Game State type to try and create or type does not yet exist in factory.");
        break;
    }

    return p;
}

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

    default:
        assert(false && "Factory was passed an invalid Unit type to try and create or type does not yet exist in factory.");
        break;
    }


    return p;
}
