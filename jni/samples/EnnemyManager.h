#ifndef DEF_ENNEMYMANAGER_INCLUDE
#define DEF_ENNEMYMANAGER_INCLUDE

#include "Ennemies/Ennemy.h"
#include "Updatable.h"
#include "Materials/TextureMaterial.h"
#include <stdlib.h>

#define NBFRAME_BEFORE_NEXT_UPDATE_MIN 40
#define NBFRAME_BEFORE_NEXT_UPDATE_MAX 60
#define RAND_ENNEMY_MAX 300
#define RAND_ZOMBIE     250
#define RAND_KAMIKAZE   300

enum TypeEnnemy
{
	ZOMBIE,
	KAMIKAZE
};

class Player;

class EnnemyManager : public Updatable
{
	public:
		EnnemyManager(Updatable* parent);
		~EnnemyManager();
		void onUpdate(Render& render);
		uint32_t doDamage(uint32_t i, uint32_t damage);
		Ennemy** getEnnemies();
		uint32_t getNbEnnemies() const;
		bool collisionPlayer(Player& player);
		void deleteEnnemies();
	private:
		TextureMaterial m_textureMaterial;
		Ennemy** m_ennemies;
		uint32_t m_nbEnnemies;
		uint32_t m_nbFrameBeforeNextUpdate;
};

#endif
