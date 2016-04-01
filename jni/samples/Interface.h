#ifndef DEF_INTERFACE_INCLUDE
#define DEF_INTERFACE_INCLUDE

#define MAX_JOYSTICK_DISTANCE 0.2f

#include <string>
#include <glm/gtx/norm.hpp>
#include "Updatable.h"
#include "Graphics/Text.h"
#include "Graphics/Shape/Circle.h"
#include "Widgets/Button.h"
#include "EventManager.h"
#include "Resources.h"
#include "Materials/UniColorMaterial.h"

class Interface : public Updatable
{
	public:
		Interface(Updatable* parent);
		~Interface();
		void onFocus(uint32_t pID, Render& render);
		void onUpdate(Render& render);
		void setScore(uint32_t score);
		static void interfaceWeapon(void* weapon);
	private:
		UniColorMaterial m_mtl;
		Circle m_joystick;
		Text m_score;
		uint32_t m_touchID;
		Sprite* m_sprite1;
		Button m_weapon1;
		Sprite* m_sprite2;
		Button m_weapon2;
};

#endif
