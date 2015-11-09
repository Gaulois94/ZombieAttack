#ifndef DEF_ZOMBIE_INCLUDE
#define DEF_ZOMBIE_INCLUDE

#define ZOMBIE_SCORE 50
#define ZOMBIE_LIFE 100
#define ZOMBIE_SPEED 0.001

#include "Ennemies/Ennemy.h"
#include "Materials/TextureMaterial.h"
#include "Player.h"

class Zombie : public Ennemy
{
	public:
		Zombie(Updatable* parent, Material* material, Texture* texture, float x, float y, Orientation orientation);
		~Zombie();
		void onUpdate(Render& render);
		bool collisionPlayer(Player& player);
	private:
		TextureMaterial* m_textureMaterial;
		float m_paramBezier1;
		float m_paramBezier2;
		float m_x;
		float m_y;
		float m_t;
};

#endif
