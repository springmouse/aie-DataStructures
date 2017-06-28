#pragma once
#include "Unit.h"

/*
* Class: Bullet
* -------------
*
* this is the Bullet Class derived from Unit
*
* Author: Callum Dunstone
*/
class Bullet :
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
	Bullet();

	/*
	* Function: DeConstructor
	* ---------------------
	*
	* this is the Default Deconstructor of the class
	*
	*/
	~Bullet();

	/*
	* Function: Update
	* ----------------
	*
	* this runs every fram of the programe updating our unit allowing it to move
	*
	* Parameters: this takes in a float, which is the delta time between the frames
	*
	* returns: returns nothing as it is a void function
	*/
	void Update(float deltaTime);

	/*
	* Function: BulletInit
	* --------------------
	*
	* this is used to initlizes the bullet unit
	*
	* Parameters: Vector2 pos the players new position in world space
	*	Vector2 dir the direction we want the bullet to move in
	*
	* returns: returns nothing as it is a void function
	*/
	void BulletInit(Vector2 pos, Vector2 dir);

	/*
	* Function: CheckAlive
	* --------------------
	*
	* this is used to check if the unit is alive or not by seeing if m_lifeTimer > 5. If >5 returns false
	*
	* Parameters: takes no parameters
	*
	* returns: returns true if alive and false if dead
	*/
	bool CheckAlive();

private:
	float m_lifeTimmer; /*how long the player will stay in effect*/
};

