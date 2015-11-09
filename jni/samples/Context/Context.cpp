#include "Context.h"

Context::Context(Updatable* parent) : Updatable(parent)
{}

void Context::resume()
{
	m_canUpdate = true;
}

void Context::pause()
{
	m_canUpdate = false;
}
