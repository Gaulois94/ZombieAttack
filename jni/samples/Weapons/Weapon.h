#ifndef DEF_WEAPON_INCLUDE
#define DEF_WEAPON_INCLUDE

#include "Sprite.h"
#include "Shots/Shot.h"
#include "Graphics/Render.h"

class Player;

class Weapon : public Sprite
{
	public:
		Weapon(Updatable* parent, Material* material, const Texture* texture, uint32_t nbFrame);
		virtual void onUpdate(Render& render);
		virtual void createShots(const Player& player, Shot**& shots, uint32_t& nbShots)=0;
		bool addShots();
	private:
		uint32_t m_iFrame;
		uint32_t m_nbFrame;
};

#endif
