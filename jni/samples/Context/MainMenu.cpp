#include "Context/MainMenu.h"
#include "Context/ContextManager.h"

MainMenu::MainMenu(Updatable* parent) : Context(parent), m_buttonMaterial(Color(1.0, 1.0, 1.0, 1.0)), 
	m_startButton(this, *(m_startText = new Text(NULL, NULL, fontResources.get("dejavusansmono"), "Start"))),
	m_quitButton(this, *(m_quitText = new Text(NULL, NULL, fontResources.get("dejavusansmono"), "Quit")))
{
	m_startButton.setMaterial(&m_buttonMaterial);
	m_startButton.setActiveFunc(MainMenu::setContext, NULL);
	m_startButton.setPositionOrigin(m_startButton.getDefaultPos() + m_startButton.getDefaultSize()/2.0f, true);
	m_startButton.setPosition(glm::vec3(0.0, 0.5, 0.0));

	m_quitButton.setMaterial(&m_buttonMaterial);
	m_quitButton.setPositionOrigin(m_startButton.getDefaultPos() + m_startButton.getDefaultSize()/2.0f, true);
	m_quitButton.setPosition(glm::vec3(0.0, -0.5, 0.0));
	
}

MainMenu::~MainMenu()
{
	delete m_startText;
	delete m_quitText;
}

void MainMenu::setContext(void* p)
{
	contextManager->changeContext(GAME_CONTEXT);
}
