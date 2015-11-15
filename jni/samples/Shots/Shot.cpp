#include "Shot.h"

Shot::Shot(Updatable* parent, Material* material, uint32_t damage) : Sprite(parent, material, NULL), m_damage(damage), m_destroy(false)
{
	m_updateFocus = false;
	scale(glm::vec3(0.01, 0.15, 1.0));
}

bool Shot::destroy() const
{
	if(m_destroy)
		return true;
	Rectangle3f rect(getPosition(true) - getPositionOrigin(true), getDefaultSize()*getScale());
	return !rectCollision2(rect, Rectangle3f(-1.0f, -1.0f, 0.0f, 2.0f, 2.0f, 0.0f));
}

uint32_t Shot::getDamage() const
{
	return m_damage;
}
