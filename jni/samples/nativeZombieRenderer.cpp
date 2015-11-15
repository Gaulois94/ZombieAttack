#include "nativeZombieRenderer.h"
#include "utils.h"

JNIEXPORT jlong JNICALL Java_com_gaulois94_samples_ZombieRenderer_createZombieRenderer(JNIEnv* jenv, jclass jcls, jlong parent, jobject surface)
{
	ZombieRenderer* renderer = new ZombieRenderer((Updatable*)parent);
	ANativeWindow* window = ANativeWindow_fromSurface(jenv, surface);
	renderer->initializeContext(window);

	return (jlong)renderer;
}
