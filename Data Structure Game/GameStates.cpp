#include "GameStates.h"


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

}

void MenuState::onDraw(aie::Renderer2D * m_2dRenderer, aie::Font* font)
{

    m_2dRenderer->drawText(font, "Press g to play", 500, 360);
}

#pragma endregion

///////////////////////////////////

#pragma region InGameState

InGameState::InGameState()
{
}

InGameState::~InGameState()
{
}

void InGameState::onUpdate(float deltaTime)
{

    timer += deltaTime;

}

void InGameState::onDraw(aie::Renderer2D * m_2dRenderer, aie::Font* font)
{
    std::string name = "Time since started running " + std::to_string(timer);
    m_2dRenderer->drawText(font, name.c_str(), 500, 360);
}

#pragma endregion

///////////////////////////////////

