#include "Context/Game.h"
#include "ContextManager.h"

Game::Game(Updatable* parent) : Context(parent), m_score(0), m_hasChangedOrientation(false), m_player(this), m_ennemyManager(this), m_interface(this)
{
	srand(time(NULL));		
}

void Game::start()
{}

void Game::quit()
{}

void Game::onFocus(uint32_t pID, Render& render)
{
	m_interface.onFocus(pID, render);
}

void Game::onUpdate(Render& render)
{
	//Get the shots collisions
    Shot** shots     = m_player.getShots();
	for(uint32_t i=0; i < m_player.getNbShots(); i++)
	{
		uint32_t add = shots[i]->doDamage(m_ennemyManager);
		if(add)
			addScore(add);
		if(shots[i]->destroy())
			m_player.destroyShot(i);
	}

	//Get the player Collision
	if(m_ennemyManager.collisionPlayer(m_player))
		finish();

	Updatable::onUpdate(render);
}

void Game::finish()
{
	updateScore(m_score);
	m_ennemyManager.deleteEnnemies();
	m_player.deleteShots();
	m_score = 0;
	m_interface.setScore(0);
	contextManager->changeContext(MAINMENU_CONTEXT);
}

void Game::addScore(uint32_t add)
{
	m_score += add;
	m_interface.setScore(m_score);
}

void Game::setWeapon(const char* weapon)
{
	m_player.setWeapon(weapon);
}

void Game::accelerometerEvent(float x, float y, float z)
{
	m_player.move(glm::vec3(-x/50.0f, 0, 0));

	if(z > 10 && !m_hasChangedOrientation)
	{
		m_player.changeOrientation();
		m_hasChangedOrientation = true;
	}

	else if(z < 0 && m_hasChangedOrientation)
		m_hasChangedOrientation = false;
}
