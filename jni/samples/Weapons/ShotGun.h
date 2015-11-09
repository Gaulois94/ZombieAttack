#ifndef DEF_SHOTGUN
#define DEF_SHOTGUN

#include "cmath"
#include "Materials/UniColorMaterial.h"
#include "Weapons/Weapon.h"
#include "Shots/ShotGunBullet.h"
#include "Player.h"

#define SHOTGUNBULLET_SPEED 0.01
#define SHOTGUNBULLET_UPDATE 60
#define SHOTGUNBULLET_NBSHOTS 5
#define SHOTGUNBULLET_ANGLEORIGIN PI/4

class ShotGun : public Weapon
{
	public:
		ShotGun(Updatable* parent, Material* material);
		~ShotGun();
		void createShots(const Player& player, Shot**& shots, uint32_t& nbShots);
	private:
		Material* m_shotMaterial;
};

#endif
