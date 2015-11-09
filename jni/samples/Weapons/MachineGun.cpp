#include "MachineGun.h"

MachineGun::MachineGun(Updatable* parent, Material* material) : Weapon(parent, material, NULL,MACHINEBULLET_UPDATE)
{
	scale(glm::vec3(0.2, 0.1, 0.0));
	m_shotMaterial = new UniColorMaterial(Color(1.0f, 1.0f, 1.0f, 1.0f));
}

MachineGun::~MachineGun()
{
	delete m_shotMaterial;
}

void MachineGun::createShots(const Player& player, Shot**& shots, uint32_t& nbShots)
{
	shots = (Shot**)realloc(shots, (nbShots+1)*sizeof(Shot*));
	if(player.getOrientation() == AHEAD)
	{
		shots[nbShots] = new MachineBullet(this, m_shotMaterial, MACHINEBULLET_SPEED);
		shots[nbShots]->setPositionOrigin(glm::vec3(0.5, 0.0, 0.0), true);
	}
	else
	{
		shots[nbShots] = new MachineBullet(this, m_shotMaterial, -MACHINEBULLET_SPEED);
		shots[nbShots]->setPositionOrigin(glm::vec3(0.5, 1.0, 0.0), true);
	}

	shots[nbShots]->setPosition(player.getPosition(true));
	nbShots++;
}
