#ifndef DEF_CONTEXTMANAGER
#define DEF_CONTEXTMANAGER

#define GAME_CONTEXT     0x01
#define MAINMENU_CONTEXT 0x02

#include "Updatable.h"
#include "Context/MainMenu.h"
#include "Context/Game.h"
#include "Context/Context.h"
#include "Resources.h"

class ContextManager : public Updatable
{
	public:
		ContextManager(Updatable* parent);
		void onFocus(uint32_t pID, Render& render);
		void accelerometerEvent(float x, float y, float z);
		void changeContext(uint8_t context);
		static void initResources();
	private:
		Game     m_game;
		MainMenu m_mainMenu;
		Context* m_currentContext;
};

#endif
