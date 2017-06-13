#include "aieProject2D1App.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

aieProject2D1App::aieProject2D1App() 
{

}

aieProject2D1App::~aieProject2D1App() {

}

bool aieProject2D1App::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

    m_gameSM = GameStateManagmeant(2);

    m_gameSM.registerState((int)eGameState::MENU,  FACTORY->MakeState(GameStateType::MENU));
    m_gameSM.registerState((int)eGameState::INGAME, FACTORY->MakeState(GameStateType::INGAME));

    m_gameSM.pushState((int)eGameState::MENU);

	return true;
}

void aieProject2D1App::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void aieProject2D1App::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
    if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
    {
        quit();
    }

    if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
    {
        quit();
    }

    while (m_gameSM.ActiveStateCount() > 0)
    {
        m_gameSM.Update(deltaTime);
    }
}

void aieProject2D1App::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

    while (m_gameSM.ActiveStateCount() > 0)
    {
        m_gameSM.draw(m_2dRenderer, m_font);
    }

	// done drawing sprites
	m_2dRenderer->end();
}