#pragma once
#include "Unit.h"

/*
* Class: PlayerUnit
* ------------------
*
* this is the PlayerUnit that the player will control that is derived from Unit
*
* Author: Callum Dunstone
*/
class PlayerUnit :
    public Unit
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* this is the Default constructor of the class
	*
	*/
    PlayerUnit();

	/*
	* Function: DeConstructor
	* ---------------------
	*
	* this is the Default Deconstructor of the class
	*
	*/
    ~PlayerUnit();

	/*
	* Function: Update
	* ----------------
	*
	* this runs every fram of the programe updating our Player unit
	*
	* Parameters: this takes in a float, which is the delta time between the frames
	*
	* returns: returns nothing as it is a void function
	*/
    void Update(float deltaTime);

	/*
	* Function: PlayerInit
	* --------------------
	*
	* this is used to initlizes the player unit
	*
	* Parameters: Vector2 pos the players new position in world space
	*
	* returns: returns nothing as it is a void function
	*/
	void PlayerInit(Vector2 pos);

	/*
	* Function: CheckAlive
	* --------------------
	*
	* this is used to check if the unit is alive or not by seeing what
	* the units health is set at if below 0 returns false
	*
	* Parameters: takes no parameters
	*
	* returns: returns true if alive and false if dead
	*/
	bool CheckAlive();
	
};

