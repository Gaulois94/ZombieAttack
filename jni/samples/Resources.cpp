#include "Resources.h"
#include "Context/Game.h"
#include "Context/ContextManager.h"

ResourcesManager<Texture*> textureResources;
ResourcesManager<Font*> fontResources;
Game* game=NULL;
ContextManager* contextManager=NULL;

void startEvent()
{
	if(game)
		game->start();
}

void quitEvent()
{
	if(game)
		game->quit();
}
