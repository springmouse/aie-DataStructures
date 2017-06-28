#pragma once
#include "Unit.h"

/*
* Class: BasicEnemyUnit
* ---------------------
*
* this is the BasicEnemyUnit that that is derived from Unit
*
* Author: Callum Dunstone
*/
class BasicEnemyUnit :
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
    BasicEnemyUnit();

	/*
	* Function: DeConstructor
	* ---------------------
	*
	* this is the Default Deconstructor of the class
	*
	*/
    ~BasicEnemyUnit();

	/*
	* Function: Init
	* --------------
	*
	* this is used to initlizes the enemy Units
	*
	* Parameters: Vector2 pos this will be the units position in world space
	*	Unit * player this is a refrence to the player for the enemy to use
	*
	* returns: returns nothing as it is a void function
	*/
	void Init(Vector2 pos, Unit * player);

	/*
	* Function: Update
	* ----------------
	*
	* this runs every frame of the programe updating our unit
	*
	* Parameters: this takes in a float, which is the delta time between the frames
	*
	* returns: returns nothing as it is a void function
	*/
	void Update(float deltaTime);

	/*
	* Function: CheckAlive
	* --------------------
	*
	* this is used to check if the unit is alive or not, returns true if health is > 0
	*
	* Parameters: takes no parameters
	*
	* returns: returns true if alive and false if dead
	*/
	bool CheckAlive();
private:

	Unit * m_player; /*refrence to the player so we know where they are to hunt them down*/

};

