#ifndef DEF_GAME_INCLUDE
#define DEF_GAME_INCLUDE

#include "Resources.h"
#include "EnnemyManager.h"
#include "Ennemies/Ennemy.h"
#include "Player.h"
#include "Shots/Shot.h"
#include "Interface.h"
#include "Context/Context.h"
#include "scoreHandler.h"

#include "Render.h"
#include "Updatable.h"

#include <stdlib.h>
#include <time.h>

class Game : public Context
{
	public:
		Game(Updatable* parent);
		void start();
		void quit();
		void onFocus(uint32_t pID, Render& render);
		void onUpdate(Render& renderer);
		void finish();
		void addScore(uint32_t score);
		void accelerometerEvent(float x, float y, float z);
		void setWeapon(const char* weapon);
	private:
		uint32_t       m_score;
		bool           m_hasChangedOrientation;
		Player         m_player;
		EnnemyManager  m_ennemyManager;
		Interface      m_interface;
};

#endif
