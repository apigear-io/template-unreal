{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/

#include "Generated/Detail/{{Camel .Module.Name}}CommonJavaConverter.h"
#include "CoreMinimal.h"
#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

DEFINE_LOG_CATEGORY(Log{{Camel .Module.Name}}CommonJavaConverter_JNI);

bool F{{Camel .Module.Name}}CommonJavaConverter::CheckJniErrorOccurred(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(Log{{Camel .Module.Name}}CommonJavaConverter_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

#endif
