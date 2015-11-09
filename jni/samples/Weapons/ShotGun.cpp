#include "ShotGun.h"

ShotGun::ShotGun(Updatable* parent, Material* material) : Weapon(parent, material, NULL, SHOTGUNBULLET_UPDATE)
{
	m_shotMaterial = new UniColorMaterial(Color(1.0, 1.0, 1.0, 1.0));
}

ShotGun::~ShotGun()
{
	delete m_shotMaterial;
}

void ShotGun::createShots(const Player& player, Shot**& shots, uint32_t& nbShots)
{
	shots = (Shot**)realloc(shots, (nbShots+SHOTGUNBULLET_NBSHOTS)*sizeof(Shot*));

	if(player.getOrientation() == AHEAD)
		for(uint32_t i=0; i < SHOTGUNBULLET_NBSHOTS; i++)
		{
			float angle = SHOTGUNBULLET_ANGLEORIGIN + i * (PI - 2*SHOTGUNBULLET_ANGLEORIGIN)/(SHOTGUNBULLET_NBSHOTS-1);
			shots[nbShots+i] = new ShotGunBullet(this, m_shotMaterial, glm::vec2(SHOTGUNBULLET_SPEED * cos(angle), SHOTGUNBULLET_SPEED * sin(angle)));
			shots[nbShots+i]->setPositionOrigin(glm::vec3(0.5, 0, 0.0), true);
			shots[nbShots+i]->setPosition(player.getPosition(true));
			shots[nbShots+i]->rotate(angle - PI/2, glm::vec3(0.0, 0.0, 1.0));
		}

	else
		for(uint32_t i=0; i < SHOTGUNBULLET_NBSHOTS; i++)
		{
			float angle = SHOTGUNBULLET_ANGLEORIGIN + i * (PI - 2*SHOTGUNBULLET_ANGLEORIGIN)/(SHOTGUNBULLET_NBSHOTS-1);
			shots[nbShots+i] = new ShotGunBullet(this, m_shotMaterial, glm::vec2(SHOTGUNBULLET_SPEED * cos(angle), -SHOTGUNBULLET_SPEED * sin(angle)));
			shots[nbShots+i]->setPositionOrigin(glm::vec3(0.5, 1, 0.0), true);
			shots[nbShots+i]->setPosition(player.getPosition(true));
			shots[nbShots+i]->rotate(-angle + PI/2, glm::vec3(0.0, 0.0, 1.0));
		}
	nbShots = nbShots + SHOTGUNBULLET_NBSHOTS;
}
