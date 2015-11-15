#include "Context/ContextManager.h"

ContextManager::ContextManager(Updatable* parent) : Updatable(parent), m_game(this), m_mainMenu(this)
{
	contextManager = this;
	game = &m_game;
	m_currentContext = &m_mainMenu;
	m_game.setCanUpdate(false);
}

void ContextManager::onFocus(uint32_t pID, Render& render)
{
	if(m_currentContext == &m_game)
		m_currentContext->onFocus(pID, render);
}

void ContextManager::changeContext(uint8_t c)
{
	if(m_currentContext)
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
	if(m_currentContext)
		m_currentContext->resume();
}

void ContextManager::accelerometerEvent(float x, float y, float z)
{
	if(m_currentContext == &m_game)
		m_game.accelerometerEvent(x, y, z);
}

void ContextManager::initResources()
{
	fontResources.add("dejavusansmono", Font::fontFromAssets("fonts/dejavusansmono.ttf"));
	textureResources.add("players", Texture::loadAndroidFile("tileset.png"));
	textureResources.add("character", Texture::loadAndroidFile("character.png"));
}
