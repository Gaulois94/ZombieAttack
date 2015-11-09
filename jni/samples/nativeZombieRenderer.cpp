#include "nativeZombieRenderer.h"
#include "ZombieRenderer.h"

JNIEXPORT jlong JNICALL Java_com_gaulois94_samples_ZombieRenderer_createZombieRenderer(JNIEnv* jenv, jclass jcls, jlong parent, jobject surface)
{
	Renderer* renderer = new ZombieRenderer((Updatable*)parent);
	ANativeWindow* window = ANativeWindow_fromSurface(jenv, surface);
	renderer->initializeContext(window);

	return (jlong)renderer;
}

