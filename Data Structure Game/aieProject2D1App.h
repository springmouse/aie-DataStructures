#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "GameStateManagmeant.h"
#include "Factory.h"

enum class eGameState
{
    MENU,
    INGAME,
    STATE_COUNT
};

class aieProject2D1App : public aie::Application {
public:

	aieProject2D1App();
	virtual ~aieProject2D1App();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

    GameStateManagmeant  m_gameSM;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};