#ifndef DEF_CONTEXTMANAGER
#define DEF_CONTEXTMANAGER

#define GAME_CONTEXT     0x01
#define MAINMENU_CONTEXT 0x02

#include "Updatable.h"
#include "Context/MainMenu.h"
#include "Game.h"
#include "Resources.h"

class ContextManager : public Updatable
{
	public:
		ContextManager(Updatable* parent);
		void changeContext(uint8_t context);
	private:
		MainMenu m_mainMenu;
		Game     m_game;
		Updatable* m_currentContext;
};

#endif
