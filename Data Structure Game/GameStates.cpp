#include "GameStates.h"
#include "Factory.h"
#include "Input.h"
#include "Information.h"
#include <string>


#pragma region GameStates

GameStates::GameStates()
{
}


GameStates::~GameStates()
{
}

#pragma endregion

///////////////////////////////////

#pragma region MenuState

MenuState::MenuState()
{
}

MenuState::~MenuState()
{
}

void MenuState::onUpdate(float deltaTime)
{
    if (m_active)
    {
        if (INPUT->isKeyDown(aie::INPUT_KEY_1))
        {
            INFOMATION->pushInfo(GameStateType::INGAME);
        }

        if (INPUT->isKeyDown(aie::INPUT_KEY_2))
        {
            INFOMATION->pop = true;
        }
    }
}

void MenuState::onDraw(aie::Renderer2D * m_2dRenderer, aie::Font* font)
{
    if (m_active)
    {
        m_2dRenderer->drawText(font, "1: start game", 500, 360);
        m_2dRenderer->drawText(font, "2: close game", 500, 180);
    }
}

void MenuState::onPopped()
{
    INFOMATION->quit = true;
}

#pragma endregion

///////////////////////////////////

#pragma region InGameState

InGameState::InGameState()
{
    m_playerUnits.PushFront(FACTORY->MakeUnit(eUnitTypes::PLAYER));
}

InGameState::~InGameState()
{
}

void InGameState::onUpdate(float deltaTime)
{
    if (m_active)
    {
        timer += deltaTime;

        if (INPUT->isKeyDown(aie::INPUT_KEY_ESCAPE))
        {
            INFOMATION->pop = true;
        }


        for (auto p : m_playerUnits)
        {
            p->Update(deltaTime);
        }
    }
}

void InGameState::onDraw(aie::Renderer2D * m_2dRenderer, aie::Font* font)
{
    if (m_active)
    {
        std::string name = "Time since started running " + std::to_string(timer);
        m_2dRenderer->drawText(font, name.c_str(), 500, 360);

        m_2dRenderer->drawText(font, "press esc to go back to main menu", 0, 10);

        for (auto p : m_playerUnits)
        {
            m_2dRenderer->setRenderColour(0, 1, 1, 1);
            m_2dRenderer->drawCircle( p->m_globalPos[2].x, p->m_globalPos[2].y, 10);
        }
    }
}

#pragma endregion

///////////////////////////////////

