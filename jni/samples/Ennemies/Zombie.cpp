#include "Ennemies/Zombie.h"

Zombie::Zombie(Updatable* parent, Material* material, Texture* texture, float x, float y, Orientation orientation) : Ennemy(parent, material, texture, ZOMBIE_SCORE, ZOMBIE_LIFE, 6, 3, x, y, orientation), m_x(x), m_y(y), m_t(0)
{
	m_textureMaterial = new TextureMaterial();
	setMaterial(m_textureMaterial);
	m_paramBezier1 = (rand()%100) / 100.0f;
	m_paramBezier2 = (rand()%100) / 100.0f;

	if(orientation == AHEAD)
	{
		m_paramBezier1 *= -1;
		m_paramBezier2 *= -1;
	}
}

Zombie::~Zombie()
{
	delete m_textureMaterial;
	m_textureMaterial = NULL;
}

void Zombie::onUpdate(Render& render)
{
	//Bezier curve
    float x = (1-m_t)*(1-m_t)*(1-m_t)*m_x+ 3*m_t*(1-m_t)*(1-m_t)*m_x            +3*m_t*m_t*(1-m_t)*m_x;
	float y = (1-m_t)*(1-m_t)*(1-m_t)*m_y+ 3*m_t*(1-m_t)*(1-m_t)*m_paramBezier1 +3*m_t*m_t*(1-m_t)*m_paramBezier2;
	m_t+=ZOMBIE_SPEED;
	setPosition(glm::vec3(x, y, 0.0f), false);

	PatternAnimation::onUpdate(render);
}

bool Zombie::collisionPlayer(Player& player)
{
	return rectCollision2(getRect(), player.getRect());
}
