#include "Context/ContextManager.h"

Context::Context(Updatable* parent) : Updatable(this), MainMenu(this), Game(this)
{
	m_currentContext = &MainMenu;
	Game.setCanUpdate(false);
	contextManager = this;
	game = this;
}

void Context::changeContext(uint8_t c)
{
	m_currentContext->pause();
	switch(c)
	{
		case GAME_CONTEXT:
			m_currentContext = &m_game;
			break;
		case MAINMENU_CONTEXT:
			m_currentContext = &m_mainMenu;
			break;
		default:
			break;
	}
	m_currentContext->resume();
}
