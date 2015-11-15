#ifndef DEF_MAINMENU
#define DEF_MAINMENU

#include "Updatable.h"
#include "Text.h"
#include "Widgets/Button.h"
#include "Resources.h"
#include "Materials/UniColorMaterial.h"

#include "Context/Context.h"

class MainMenu : public Context
{
	public:
		MainMenu(Updatable* parent);
		~MainMenu();
		static void setContext(void*);
	private:
		UniColorMaterial m_buttonMaterial;
		Text* m_startText;
		Text* m_quitText;
		Button m_startButton;
		Button m_quitButton;
};

#endif
