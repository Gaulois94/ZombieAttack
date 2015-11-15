#ifndef DEF_ZOMBIERENDERER
#define DEF_ZOMBIERENDERER

#include "Renderer.h"
#include "Context/ContextManager.h"
#include "Materials/UniColorMaterial.h"
#include "Shape/Circle.h"
#include "Shape/Rectangle.h"

class ZombieRenderer : public Renderer
{
	public:
		ZombieRenderer(Updatable* parent);
		~ZombieRenderer();
		void onFocus(uint32_t pID, Render& render);
		void accelerometerEvent(float x, float y, float z);
		void init();
	private:
		ContextManager* m_contextManager;
};

#endif
