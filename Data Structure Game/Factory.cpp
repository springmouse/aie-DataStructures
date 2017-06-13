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

GameStatePointer Factory::MakeState(GameStateType type)
{
    switch (type)
    {
    case GameStateType::MENU:
        return GameStatePointer(new MenuState);

    case GameStateType::INGAME:
        return GameStatePointer(new InGameState);

    default:
        return nullptr;
    }
}
