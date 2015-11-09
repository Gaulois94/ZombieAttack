#ifndef DEF_SHOOT_INCLUDE
#define DEF_SHOOT_INCLUDE

#include "Sprite.h"
#include "Rectangle3.h"
#include "EnnemyManager.h"
#include "Ennemies/Ennemy.h"

class Shot : public Sprite
{
	public:
		Shot(Updatable* parent, Material* material, uint32_t damage);
		bool destroy() const;
		virtual uint32_t doDamage(EnnemyManager& ennemyManager) = 0;
		uint32_t getDamage() const;
	protected:
		uint32_t m_damage;
		bool m_destroy;
};
#endif
