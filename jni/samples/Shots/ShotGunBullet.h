#ifndef DEF_SHOTGUNBULLET
#define DEF_SHOTGUNBULLET

#include "Shots/Shot.h"
#define SHOTGUNBULLET_DAMAGE 500

class ShotGunBullet : public Shot
{
	public:
		ShotGunBullet(Updatable* parent, Material* material, const glm::vec2& speed);
		virtual uint32_t doDamage(EnnemyManager& ennemyManager);
	private:
		uint32_t updateDamage(EnnemyManager& ennemyManager);
		glm::vec2 m_speed;
};

#endif
