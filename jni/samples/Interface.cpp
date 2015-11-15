#include "Interface.h"

Interface::Interface(Updatable* parent) : Updatable(parent), m_mtl(Color(1.0, 1.0, 1.0, 1.0)), m_joystick(this, NULL, 0.2, 64), m_score(this, NULL, fontResources.get("dejavusansmono"), "0"), m_touchID(0)
{
	m_score.setMaterial(&m_mtl);
	m_joystick.setMaterial(&m_mtl);
	m_score.scale(glm::vec3(0.5, 0.5, 1.0));
	m_score.setPosition(glm::vec3(1.0, 1.0, 0.0));
	m_joystick.setCanUpdate(false);
	setScore(0);
}

Interface::~Interface()
{
}

void Interface::onFocus(uint32_t pID, Render& render)
{
	if(m_joystick.getCanUpdate() == false)
	{
		m_touchID = pID;
		m_joystick.setCanUpdate(true);
		m_joystick.setPosition(glm::vec3(touchCoord[pID].x, touchCoord[pID].y, 0.0));
	}
}

void Interface::onUpdate(Render& render)
{
	if(m_joystick.getCanUpdate())
	{
		if(touchCoord[m_touchID].type == UP)
			m_joystick.setCanUpdate(false);
		else if(touchCoord[m_touchID].type==MOVE)
		{
			glm::vec2 distance(touchCoord[m_touchID].x - touchCoord[m_touchID].startX, touchCoord[m_touchID].y-touchCoord[m_touchID].startY);
			if(glm::length(distance) < MAX_JOYSTICK_DISTANCE)
				m_joystick.setPosition(glm::vec3(touchCoord[m_touchID].x, touchCoord[m_touchID].y, 0.0));
			else
			{
				m_joystick.setPosition(glm::vec3(glm::vec2(touchCoord[m_touchID].startX, touchCoord[m_touchID].startY) + glm::normalize(distance) * MAX_JOYSTICK_DISTANCE, 0.0f));
			}
		}
	}
	Updatable::onUpdate(render);
}

void Interface::setScore(uint32_t score)
{
	char s[8];
	sprintf(s, "%d", score);
	m_score.setText(s);
	m_score.setPositionOrigin(glm::vec3(m_score.getDefaultSize()), true);
}
