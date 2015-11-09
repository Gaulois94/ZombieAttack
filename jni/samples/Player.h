#ifndef DEF_PLAYER_INCLUDE
#define DEF_PLAYER_INCLUDE

#include <cmath>
#include "Resources.h"
#include "Graphics/PatternAnimation.h"
#include "Graphics/Render.h"
#include "Graphics/Materials/TextureMaterial.h"
#include "Weapons/Weapon.h"
#include "Weapons/MachineGun.h"
#include "Weapons/ShotGun.h"
#include "Shots/Shot.h"
#include "Orientation.h"
#include "Vector2.h"

class Player : public PatternAnimation
{
	public:
		Player(Updatable* parent);
		~Player();

		void move(const glm::vec3& m, int useScale=false);
		void onUpdate(Render& render);
		void deleteShots();
		void changeOrientation();
		Shot** getShots();
		void destroyShot(uint32_t i);
		uint32_t getNbShots() const;
		Orientation getOrientation() const;
	private:
		Shot**     m_shots;
		uint32_t    m_nbShots;
		Orientation m_orientation;
		Weapon*     m_currentWeapon;
		ResourcesManager<Weapon*> m_weapons;
		TextureMaterial* m_textureMaterial;
};

#endif
