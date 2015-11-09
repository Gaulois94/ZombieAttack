#include "EnnemyManager.h"
#include "Ennemies/Zombie.h"
#include "Ennemies/Kamikaze.h"
#include "Player.h"

EnnemyManager::EnnemyManager(Updatable* parent) : Updatable(parent), m_ennemies(0), m_nbEnnemies(0), m_nbFrameBeforeNextUpdate(60)
{
	m_ennemiesTexture = Texture::loadAndroidFile("tileset.png");
}

EnnemyManager::~EnnemyManager()
{
	for(uint32_t i=0; i < m_nbEnnemies; i++)
		if(m_ennemies[i])
			delete m_ennemies[i];
	delete m_ennemiesTexture;
}

void EnnemyManager::update(Render& render)
{
	if(m_nbFrameBeforeNextUpdate == 0)
	{
		m_nbFrameBeforeNextUpdate = rand()%(NBFRAME_BEFORE_NEXT_UPDATE_MAX - NBFRAME_BEFORE_NEXT_UPDATE_MIN) + NBFRAME_BEFORE_NEXT_UPDATE_MIN;
		m_ennemies = (Ennemy**)realloc(m_ennemies, (m_nbEnnemies+1)*sizeof(Ennemy*));

		int r = rand()%RAND_ENNEMY_MAX;
		Orientation o=AHEAD;
		if(rand()%2)
			o = BACK;

		if(r < RAND_ZOMBIE)
			m_ennemies[m_nbEnnemies] = new Zombie(this, &m_textureMaterial, m_ennemiesTexture, ((rand()%200)-100)/100.0f, (o==BACK) ? 1 : -1, o);
		else if(r < RAND_KAMIKAZE)
			m_ennemies[m_nbEnnemies] = new Kamikaze(this, &m_textureMaterial, m_ennemiesTexture, ((rand()%200)-100)/100.0f, (o==BACK) ? 1 : -1, o);
		m_nbEnnemies++;
	}

	m_nbFrameBeforeNextUpdate--;
	for(uint32_t i=0; i < m_nbEnnemies; i++)
	{
		if(m_ennemies[i]->destroy())
		{
			delete m_ennemies[i];
			for(uint32_t j=i; j < m_nbEnnemies-1; j++)
				m_ennemies[j] = m_ennemies[j+1];
			m_nbEnnemies--;
		}
	}
	Updatable::update(render);
}

uint32_t EnnemyManager::doDamage(uint32_t i, uint32_t damage)
{
	if(i >= m_nbEnnemies)
		return 0;

	LOG_ERROR("DAMAGE %d", damage);
	uint32_t score = m_ennemies[i]->doDamage(damage);
	return score;
}

bool EnnemyManager::collisionPlayer(Player& player)
{
	for(uint32_t i=0; i < m_nbEnnemies; i++)
		if(m_ennemies[i]->collisionPlayer(player))
			return true;
	return false;
}

void EnnemyManager::deleteEnnemies()
{
	for(uint32_t i=0; i < m_nbEnnemies; i++)
		delete m_ennemies[i];
	delete m_ennemies;
	m_ennemies = NULL;
	m_nbEnnemies = 0;
}

Ennemy** EnnemyManager::getEnnemies()
{
	return m_ennemies;
}

uint32_t EnnemyManager::getNbEnnemies() const
{
	return m_nbEnnemies;
}
