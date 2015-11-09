#ifndef DEF_KAMIKAZE_INCLUDE
#define DEF_KAMIKAZE_INCLUDE

#include "Ennemies/Ennemy.h"
#include "Player.h"
#define KAMIKAZE_EXPLOSION_X 0.4
#define KAMIKAZE_SCORE 300
#define KAMIKAZE_LIFE 400
#define KAMIKAZE_SPEED 0.003

class Kamikaze : public Ennemy
{
	public:
		Kamikaze(Updatable* parent, Material* material, Texture* texture, float x, float y, Orientation orientation);
		void onUpdate(Render& render);
		virtual bool collisionPlayer(Player& player);
		bool destroy();
	private:
};

#endif
