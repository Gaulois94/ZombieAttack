#ifndef DEF_MACHINEGUN
#define DEF_MACHINEGUN

#define MACHINEBULLET_SPEED  0.01
#define MACHINEBULLET_UPDATE 20

#include "Materials/UniColorMaterial.h"
#include "Weapons/Weapon.h"
#include "Shots/MachineBullet.h"
#include "Shots/Shot.h"
#include "Player.h"

class MachineGun : public Weapon
{
	public:
		MachineGun(Updatable* parent, Material* material);
		~MachineGun();
		void createShots(const Player& player, Shot**& shots, uint32_t& nbShots);
	private:
		Material* m_shotMaterial;
};

#endif
