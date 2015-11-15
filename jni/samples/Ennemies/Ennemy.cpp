#include "Ennemies/Ennemy.h"

Ennemy::Ennemy(Updatable* parent, Material* material, Texture* texture, uint32_t score, uint32_t life, 
			   uint32_t tileX, uint32_t tileY, float x, float y, Orientation orientation) : 
				PatternAnimation(parent, material, texture,  
				Vector2ui(32*tileX, 32*tileY), Vector2ui(0, 0), Vector2ui(32, 32), Vector2ui(3, 1), 3, 10),	m_score(score), m_life(life), m_orientation(orientation)
{
	m_updateFocus = false;
	scale(glm::vec3(0.15, 0.15, 1.0));
	setPosition(glm::vec3(x, y, 0.0), false);
	setPositionOrigin(glm::vec3(0.5, 0.5, 0.0), true);
}

uint32_t Ennemy::doDamage(uint32_t damage)
{
	m_life -= damage;
	if(m_life <= 0)
		return m_score;
	return 0;
}

bool Ennemy::destroy()
{
	return (m_life <= 0);
}
