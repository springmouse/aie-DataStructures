#pragma once
#include <Vector2.h>
#include <Vector3.h>
#include <Matrix3.h>
#include "Input.h"

/*
* enum for all the Unit types
*/
enum eUnitTypes
{
    PLAYER,
    BASICENEMY,
	BULLET
};

/*
* Class: Unit
* -----------
*
* this is the base Unit that all the rest are derived from
*
* Author: Callum Dunstone
*/
class Unit
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* this is the Default constructor of the class
	*
	*/
    Unit();

	/*
	* Function: DeConstructor
	* ---------------------
	*
	* this is the Default Deconstructor of the class
	*
	*/
    ~Unit();

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
    virtual void Update(float deltaTime) {};

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
	virtual void Init(Vector2 pos, Unit * player) {};

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
	virtual void PlayerInit(Vector2 pos) {};

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
	virtual void BulletInit(Vector2 pos, Vector2 dir) {};

	/*
	* Function: CheckAlive
	* --------------------
	*
	* this is used to check if the unit is alive or not
	*
	* Parameters: takes no parameters
	*
	* returns: returns true if alive and false if dead
	*/
	virtual bool CheckAlive() { return true; };

	/*
	* Function: ChangeHealth
	* ----------------------
	*
	* this is used to modifie the units health so it can take damage or heal up
	*
	* Parameters: takes no parameters
	*
	* returns: returns nothing
	*/
	void ChangeHealth(float change) { m_health += change; };

	/*
	* Function: GetRadius
	* -------------------
	*
	* this returns the units m_radius
	*
	* Parameters: takes no parameters
	*
	* returns: m_radius
	*/
	float GetRadius() { return m_radius; };

	/*
	* Function: GetRadius
	* -------------------
	*
	* this returns the units m_speed
	*
	* Parameters: takes no parameters
	*
	* returns: m_speed
	*/
	float GetSpeed() { return m_speed; };

	/*
	* Function: GetDamage
	* -------------------
	*
	* this returns the units m_damage
	*
	* Parameters: takes no parameters
	*
	* returns: m_damage
	*/
	float GetDamage() { return m_damage; };

	/*
	* Function: ChangeLocalPos
	* ------------------------
	*
	* this alwos you to change the Units local position
	*
	* Parameters: Vector2 pos used to modifie the units local position
	*
	* returns: nothing
	*/
	void ChangeLocalPos(Vector2 pos) { m_localPos.Translate(pos); };

	/*
	* Function: operator==
	* --------------------
	*
	* this lets you check the units against each other to see if they are the same or not
	* by checking against the units m_globalPos 
	*
	* Parameters: const Unit & refA refrence to the other unit to check there m_globalPos
	*
	* returns: m_damage
	*/
	bool operator== (const Unit & refA) { if (this->m_globalPos == refA.m_globalPos) { return true; } else { return false; } };


    Matrix3 m_globalPos; /*this is the Units global position in the world*/

	Matrix3 m_localPos; /*this is the units local position in their world*/


protected:

    float m_speed; /*the modifier to move the units by*/

    float m_movemeantTimer; /*the timer to regulate how often units move*/

	float m_radius; /*the radius of the unit to be used to render to screen and collision checking*/

	float m_health; /*the units health*/

	float m_damage; /*the units damage*/

	Vector2 m_movemeantDirection; /*the direction you want something to move in(mainly used by the bullet)*/
};

