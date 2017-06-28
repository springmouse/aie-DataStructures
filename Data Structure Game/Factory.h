#pragma once
#include "GameStates.h"
#include "Unit.h"
#include <assert.h>

#define FACTORY Factory::GetInstanceOfFactory() /*lets us call and use the factory*/

/*
* class: Factory
* ----------------
*
* this class is our main gameObject in this programe
*
* Aurthor: Callum Dunstone, AIE
*/
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

	/*
	* Function: MakeState
	* -------------------
	*
	* this creates a state based on the enum passed in and passes it out as a GameState pointer
	*
	* Parameters: this takes a eGameStateType so we know what type of GameState to pass out
	*
	* returns: a pointer to a new gamestate
	*/
    GameStates * MakeState(eGameStateType type);

	/*
	* Function: MakeUnit
	* ------------------
	*
	* this creates a Unit based on the enum passed in and passes it out as a Unit pointer
	*
	* Parameters: this takes a eUnitTypes so we know what type of Unit to pass out
	*
	* returns: a pointer to a new Unit
	*/
    Unit * MakeUnit(eUnitTypes type);

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

