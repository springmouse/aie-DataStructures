#include "aieProject2D1App.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>


aieProject2D1App::aieProject2D1App() 
{
}

aieProject2D1App::~aieProject2D1App() {

}

bool aieProject2D1App::startup() 
{
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	//creates the states to be used
    m_gameSM.registerState(FACTORY->MakeState(eGameStateType::MENU));
    m_gameSM.registerState(FACTORY->MakeState(eGameStateType::INGAME));

	//adds Menu to the states being run
    m_gameSM.pushState((int)eGameStateType::MENU);

	return true;
}

void aieProject2D1App::shutdown() 
{

	delete m_font;
	delete m_2dRenderer;
}

void aieProject2D1App::update(float deltaTime) 
{
	//runs the game state manager update to run the games
    m_gameSM.Update(deltaTime);

    // exit the application
    if (INFOMATION->quit)
    {
        quit();
    }
}

void aieProject2D1App::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	//draws the game to the screen
    m_gameSM.draw(m_2dRenderer, m_font);

	// done drawing sprites
	m_2dRenderer->end();
}