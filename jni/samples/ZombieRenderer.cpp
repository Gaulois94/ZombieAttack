#include "ZombieRenderer.h"

ZombieRenderer::ZombieRenderer(Updatable* parent) : Renderer(parent), m_contextManager(NULL)
{
}

ZombieRenderer::~ZombieRenderer()
{
	if(m_contextManager)
		delete m_contextManager;
}

void ZombieRenderer::onFocus(uint32_t pID, Render& render)
{
	m_contextManager->onFocus(pID, render);
}

void ZombieRenderer::accelerometerEvent(float x, float y, float z)
{
	if(m_contextManager)
		m_contextManager->accelerometerEvent(x, y, z);
}

void ZombieRenderer::init()
{
	ContextManager::initResources();
	m_contextManager = new ContextManager(this);
}
