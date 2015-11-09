#ifndef DEF_RESOURCES
#define DEF_RESOURCES

#include "ResourcesManager.h"
#include "Font.h"

class Game;
class ContextManager;

extern ResourcesManager<Texture*> textureResources;
extern ResourcesManager<Font*> fontResources;
extern ContextManager* contextManager;
extern Game* game;

void startEvent();
void quitEvent();

#endif
