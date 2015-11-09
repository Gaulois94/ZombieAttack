#ifndef DEF_ZOMBIERENDERER
#define DEF_ZOMBIERENDERER

#include "Renderer.h"
#include "Context/ContextManager.cpp"

class ZombieRenderer : public Renderer
{
	public:
		ZombieRenderer(Updatable* parent);
		~ZombieRenderer();
		accelerometerEvent(float x, float y, float z);
		void init();
	private:
		ContextManager* m_contextManager;
};

#endif
