#include "MachineGun.h"

MachineGun::MachineGun(Updatable* parent, Material* material) : Weapon(parent, material, NULL,MACHINEBULLET_UPDATE), m_shotMaterial(Color(1.0f, 1.0f, 0.0f, 1.0f))
{
	scale(glm::vec3(0.2, 0.1, 0.0));
}

MachineGun::~MachineGun()
{
}

void MachineGun::createShots(const Player& player, Shot**& shots, uint32_t& nbShots)
{
	shots = (Shot**)realloc(shots, (nbShots+1)*sizeof(Shot*));
	if(player.getOrientation() == AHEAD)
	{
		shots[nbShots] = new MachineBullet(this, &m_shotMaterial, MACHINEBULLET_SPEED);
		shots[nbShots]->setPositionOrigin(glm::vec3(0.5, 0.0, 0.0), true);
	}
	else
	{
		shots[nbShots] = new MachineBullet(this, &m_shotMaterial, -MACHINEBULLET_SPEED);
		shots[nbShots]->setPositionOrigin(glm::vec3(0.5, 1.0, 0.0), true);
	}

	shots[nbShots]->setPosition(player.getPosition(true));
	nbShots++;
}
