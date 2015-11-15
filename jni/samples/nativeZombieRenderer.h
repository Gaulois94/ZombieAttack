#ifndef NATIVE_ZOMBIERENDERER
#define NATIVE_ZOMBIERENDERER

#include <jni.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include "ZombieRenderer.h"

extern "C"
{
	JNIEXPORT jlong JNICALL Java_com_gaulois94_samples_ZombieRenderer_createZombieRenderer(JNIEnv* jenv, jclass jcls, jlong parent, jobject surface);
};

#endif
