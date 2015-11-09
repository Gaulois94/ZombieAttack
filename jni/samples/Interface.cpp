#include "Interface.h"

Interface::Interface(Updatable* parent) : Updatable(parent), m_mtl({1.0, 1.0, 1.0, 1.0}), m_score(this, &m_mtl, fontResources.get("dejavusansmono"), "0")
{
	m_score.scale(glm::vec3(0.5, 0.5, 1.0));
	m_score.setPosition(glm::vec3(1.0, 1.0, 0.0));
	setScore(0);
}

Interface::~Interface()
{
	if(m_font)
		delete m_font;
}

void Interface::setScore(uint32_t score)
{
	char s[10];
	sprintf(s, "%d", score);
	m_score.setText(s);
	m_score.setPositionOrigin(glm::vec3(m_score.getDefaultSize()), true);
}
