#ifndef DEF_MACHINEBULLET_INCLUDE
#define DEF_MACHINEBULLET_INCLUDE

#include "Shots/Shot.h"
#define MACHINEBULLET_DAMAGE 100

class MachineBullet : public Shot
{
	public:
		MachineBullet(Updatable* parent, Material* material, float speed);
		virtual uint32_t doDamage(EnnemyManager& ennemyManager);
	private:
		//Function used for updating many time the damage on one doDamage call (because the speed is too much)
		uint32_t updateDamage(EnnemyManager& ennemyManager);
		float m_speed;
};

#endif
