#pragma once
#include "GameStates.h"
#include "Global Type.h"
#include "Font.h"
#include "Renderer2D.h"

#include <vector>
#include <List.h>

class GameStateManagmeant
{
public:
    GameStateManagmeant() {};

    GameStateManagmeant(unsigned int stateCount);

    virtual  ~GameStateManagmeant();

    void registerState(int id, GameStatePointer state);
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

    GameStatePointer GetTopState() { return m_stateStack.Last(); };
    int ActiveStateCount() { return m_stateStack.GetLength(); };
    GameStatePointer GetState(int id) { return m_registeredStates.GetElemeantAt(id); };

protected:
    List<GameStatePointer> m_pushedStates;
    bool m_popState = false;

    List<GameStatePointer> m_stateStack;
    List<GameStatePointer> m_registeredStates;
};

