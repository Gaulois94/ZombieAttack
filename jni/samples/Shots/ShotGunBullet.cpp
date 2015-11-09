#include "ShotGunBullet.h"

ShotGunBullet::ShotGunBullet(Updatable* parent, Material* material, const glm::vec2& speed) : Shot(parent, material, SHOTGUNBULLET_DAMAGE), m_speed(speed)
{
}

uint32_t ShotGunBullet::doDamage(EnnemyManager& ennemyManager)
{
	uint32_t score;
	float x = m_speed.x/3.0f;
	float y = m_speed.y/3.0f;
	move(glm::vec3(x, y, 0.0f));
	if(score = updateDamage(ennemyManager))
	{
		move(glm::vec3(2.0f*x, 2.0f*y, 0.0f), true);
		return score;
	}

	move(glm::vec3(x, y, 0.0f));
	if(score = updateDamage(ennemyManager))
	{
		move(glm::vec3(x, y, 0.0f));
		return score;
	}

	move(glm::vec3(x, y, 0.0f));
	return updateDamage(ennemyManager);
}

uint32_t ShotGunBullet::updateDamage(EnnemyManager& ennemyManager)
{
	Ennemy** e = ennemyManager.getEnnemies();
	Rectangle3f r = getRect();
	for(uint32_t i=0; i < ennemyManager.getNbEnnemies(); i++)
		if(rectCollision2(r, e[i]->getRect()))
		{
			m_destroy = true;
			return m_damage + ennemyManager.doDamage(i, SHOTGUNBULLET_DAMAGE);
		}
	return 0;
}
