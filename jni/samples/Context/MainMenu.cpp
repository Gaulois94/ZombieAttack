#include "Context/MainMenu.h"

MainMenu::MainMenu(Updatable* parent) : Context(parent), m_startButton(this, *(m_startText = new Text(this, NULL, fontResources.get("dejavusansmono"), "Start"))),
														   m_quitButton(this, *(m_quitText = new Text(this, NULL, fontResources.get("dejavusansmono"), "Quit")))
{
	
}

MainMenu::~MainMenu()
{
	delete m_startText;
	delete m_quitText;
}
