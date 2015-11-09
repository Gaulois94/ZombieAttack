#ifndef DEF_CONTEXT
#define DEF_CONTEXT

#include "Updatable.h"

class Context : public Updatable
{
	public:
		Context(Updatable* parent);
		void resume();
		void pause();
};

#endif
