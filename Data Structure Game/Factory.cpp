#include "Factory.h"



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

    return &factory;
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
        return nullptr;
    }

    return p;
}
