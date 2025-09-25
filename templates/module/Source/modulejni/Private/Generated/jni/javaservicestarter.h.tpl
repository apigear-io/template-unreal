#pragma once
#include "Engine/Engine.h"
#include <string>

namespace ApiGear
{
class {{Camel .Module.Name}}JavaServiceStarter
{
public:
#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	static jobject startAndroidServer(std::string fullJavaClassName, std::string fullJavaUnrealServiceTypeString);
#endif
#endif
	static void stopAdnroidServer(std::string fullJavaClassName);
};

}