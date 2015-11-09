LOCAL_PATH := $(call my-dir)
LIBENGINE  := /home/mickael/Programmation/Java/Android/Engine/libs/$(TARGET_ARCH_ABI)/libengine.so

#LIBENGINE
include $(CLEAR_VARS)
LOCAL_MODULE := Engine
LOCAL_SRC_FILES := ${LIBENGINE}
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/jni/samples/
LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/../Engine/jni/Graphics/
LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/../Engine/jni
LOCAL_SHARED_LIBRARIES := 
LOCAL_MODULE := zombieAttack
LOCAL_CFLAGS := -Wall --std=c++11
APP_OPTIM := debug

LOCAL_SRC_FILES := samples/Context/MainMenu.cpp samples/Context/Context.cpp samples/Context/Game.cpp
LOCAL_SRC_FILES += samples/Ennemies/Ennemy.cpp samples/EnnemyManager.cpp samples/Interface.cpp samples/Player.cpp
LOCAL_SRC_FILES += samples/Ennemies/Zombie.cpp samples/Ennemies/Kamikaze.cpp
LOCAL_SRC_FILES += samples/Shots/Shot.cpp samples/Shots/MachineBullet.cpp samples/Shots/ShotGunBullet.cpp
LOCAL_SRC_FILES += samples/Weapons/Weapon.cpp samples/Weapons/MachineGun.cpp samples/Weapons/ShotGun.cpp
LOCAL_SRC_FILES += samples/Resources.cpp

LOCAL_LDLIBS    += -llog -landroid -lEGL -lGLESv2 -ljnigraphics -latomic
LOCAL_SHARED_LIBRARIES := Engine

include $(BUILD_SHARED_LIBRARY)
