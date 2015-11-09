#include "Weapon.h"

Weapon::Weapon(Updatable* parent, Material* material, const Texture* texture, uint32_t nbFrame) : Sprite(parent, material, texture), m_iFrame(0), m_nbFrame(nbFrame)
{

}

void Weapon::onUpdate(Render& render)
{
	if(m_iFrame < m_nbFrame)
		m_iFrame++;
	Sprite::onUpdate(render);
}

bool Weapon::addShots()
{
	if(m_iFrame < m_nbFrame)
		return false;
	m_iFrame=0;
	return true;
}
