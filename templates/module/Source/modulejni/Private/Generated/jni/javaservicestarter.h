#pragma once
#include "Engine/Engine.h"
#include <string>

namespace ApiGear
{
class JavaServiceStarter
{
public:
	static void startAndroidServer(std::string fullJavaClassName);

	static void stopAdnroidServer(std::string fullJavaClassName);
};

}