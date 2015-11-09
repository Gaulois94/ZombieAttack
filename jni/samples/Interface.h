#ifndef DEF_INTERFACE_INCLUDE
#define DEF_INTERFACE_INCLUDE

#include <string>
#include "Updatable.h"
#include "Graphics/Text.h"
#include "Resources.h"
#include "Materials/UniColorMaterial.h"

class Interface : public Updatable
{
	public:
		Interface(Updatable* parent);
		~Interface();
		void setScore(uint32_t score);
	private:
		UniColorMaterial m_mtl;
		Font* m_font;
		Text m_score;
};

#endif
