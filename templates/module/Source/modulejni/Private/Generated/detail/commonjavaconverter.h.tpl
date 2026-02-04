{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/

#pragma once

#include "HAL/Platform.h"
#include "Logging/LogMacros.h"

#if PLATFORM_ANDROID && USE_ANDROID_JNI

DECLARE_LOG_CATEGORY_EXTERN(Log{{Camel .Module.Name}}CommonJavaConverter_JNI, Log, All);

class F{{Camel .Module.Name}}CommonJavaConverter
{
public:
	static bool CheckJniErrorOccurred(const TCHAR* Msg);

private:
	F{{Camel .Module.Name}}CommonJavaConverter() = delete;
};

#endif
