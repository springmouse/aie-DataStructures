#pragma once
#include "GameStates.h"
#include "Global Type.h"

#define FACTORY Factory::GetInstanceOfFactory() /*lets us call and use the factory*/


class Factory
{
public:
    /*
    * Function: GetInstanceOfFactory
    * ------------------------------
    *
    * this function returns a static instance of a factory
    *
    * Parameters: it takes no parameters
    *
    * returns: a static pointer to a factory
    */
    static Factory * GetInstanceOfFactory();

    GameStates * MakeState(GameStateType type);

private:
    /*
    * Function: Constructor
    * ---------------------
    *
    * this is the Default constructor of the game
    *
    */
    Factory();

    /*
    * Function: DeConstructor
    * -----------------------
    *
    * this is the default DeConstructor of the game
    *
    */
    ~Factory();
};

