#ifndef NATIVE_ZOMBIERENDERER
#define NATIVE_ZOMBIERENDERER

extern "C"
{
	JNIEXPORT jlong JNICALL Java_com_gaulois94_samples_ZombieRenderer_createZombieRenderer(JNIEnv* jenv, jclass jcls, jlong parent, jobject surface);
};

#endif
