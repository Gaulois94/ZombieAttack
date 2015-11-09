#ifndef DEF_ENNEMY_INCLUDE
#define DEF_ENNEMY_INCLUDE

#include "PatternAnimation.h"
#include "Orientation.h"

class Player;

class Ennemy : public PatternAnimation
{
	public:
		Ennemy(Updatable* parent, Material* material, Texture* texture, uint32_t score, uint32_t life, uint32_t tileX, uint32_t tileY, float x, float y, Orientation orientation);
		uint32_t doDamage(uint32_t damage);
		virtual bool collisionPlayer(Player& player)=0;
		virtual bool destroy();
	protected:
		uint32_t m_score;
		int32_t m_life;
		Orientation m_orientation;
};

#endif
