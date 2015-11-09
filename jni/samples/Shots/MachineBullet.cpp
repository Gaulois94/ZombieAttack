#include "Shots/MachineBullet.h"

MachineBullet::MachineBullet(Updatable* parent, Material* material, float speed) : Shot(parent, material, MACHINEBULLET_DAMAGE), m_speed(speed)
{
}

uint32_t MachineBullet::doDamage(EnnemyManager& ennemyManager)
{
	uint32_t score;
	move(glm::vec3(0.0f, m_speed/3.0f, 0.0f));
	if(score = updateDamage(ennemyManager))
	{
		move(glm::vec3(0.0f, 2.0f*m_speed/3.0f, 0.0f), true);
		return score;
	}

	move(glm::vec3(0.0f, m_speed/3.0f, 0.0f));
	if(score = updateDamage(ennemyManager))
	{
		move(glm::vec3(0.0f, m_speed/3.0f, 0.0f));
		return score;
	}

	move(glm::vec3(0.0f, m_speed/3.0f, 0.0f));
	return updateDamage(ennemyManager);
}

uint32_t MachineBullet::updateDamage(EnnemyManager& ennemyManager)
{
	Ennemy** e = ennemyManager.getEnnemies();
	Rectangle3f r = getRect();
	for(uint32_t i=0; i < ennemyManager.getNbEnnemies(); i++)
		if(rectCollision2(r, e[i]->getRect()))
		{
			m_destroy = true;
			return m_damage + ennemyManager.doDamage(i, m_damage);
		}
	return 0;
}
