#pragma once
#include "GameStates.h"
#include "Global Type.h"
#include "Font.h"
#include "Renderer2D.h"

#include <List.h>

/*
* Class: GameStateManagmeant
* --------------------------
*
* this managers our GameStates with in the game and trys to run properly
*
* Author: Callum Dunstone
*/
class GameStateManagmeant
{
public:

    /*
    * Function: Constructor
    * ---------------------
    *
    * Default constructor, it does nothing.
    *
    */
    GameStateManagmeant();

    /*
    * Function: Constructor
    * ---------------------
    *
    * Default constructor, it does nothing.
    *
    */
    virtual  ~GameStateManagmeant();

    /*
    * Function: registerState
    * -----------------------
    *
    * this adds the state passed into it, in to the m_registeredStates so that they can be easily called and accessed 
    *
    * Parameters: this takes in a GameState pointer that will be added to the m_registeredStates
    *
    * returns: returns nothing as it is a null function
    */
    void registerState(GameStates * state) { m_registeredStates.PushBack(state); };


    void pushState(int id);


    void popState();


    void Update(float deltaTime);


    void draw(aie::Renderer2D * m_2dRenderer, aie::Font* font)
    {
        for (auto state : m_stateStack)
        {
            state->onDraw(m_2dRenderer, font);
        }
    }


    GameStates * GetTopState() { return m_stateStack.Last(); };
    

    int ActiveStateCount() { return (m_stateStack.GetLength() + m_pushedStates.GetLength()); };


    GameStates * GetState(int id) { return m_registeredStates.GetElemeantAt(id); };

protected:
    List<GameStates *> m_pushedStates;
    bool m_popState = false;

    List<GameStates *> m_stateStack;
    List<GameStates *> m_registeredStates;
};

