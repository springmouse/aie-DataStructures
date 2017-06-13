#pragma once
#include "Font.h"
#include "Renderer2D.h"
#include <string>


enum GameStateType
{
    MENU,
    INGAME
};

class GameStates
{
public:
    GameStates();
    virtual ~GameStates();

    bool isActive() const { return m_active; };

    void enter() { m_active = true; onEnter(); };
    void exit() { m_active = false; onExit(); };

    virtual void onPushed() {};
    virtual void onPopped() {};

    virtual void onUpdate(float deltaTime) = 0;
    virtual void onDraw(aie::Renderer2D*, aie::Font*) = 0;

protected:
    virtual void onEnter() {};
    virtual void onExit() {};

private:
    bool m_active = false;
};



class MenuState : 
    public GameStates
{
public:
    MenuState();
     ~MenuState();

    void onUpdate(float deltaTime);
    void onDraw(aie::Renderer2D*, aie::Font*);

private:

};



class InGameState :
    public GameStates
{
public:
    InGameState();
    ~InGameState();

    void onUpdate(float deltaTime);
    void onDraw(aie::Renderer2D*, aie::Font*);

private:
    float timer = 0;
};