{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/

#include "Generated/Detail/{{Camel .Module.Name}}CommonJavaConverter.h"
#include "CoreMinimal.h"

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

bool F{{Camel .Module.Name}}CommonJavaConverter::TryFillArray(
    JNIEnv* Env, TArray<FString>& OutStringArray, jobjectArray InJniArray, const FString& InPropertyName)
{
	TArray<FString> TempArray = FJavaHelper::ObjectArrayToFStringTArray(Env, InJniArray);
	if (CheckJniErrorOccurred(*FString::Printf(TEXT("failed to convert %s from jstring array"), *InPropertyName)))
	{
		return false;
	}

	Swap(TempArray, OutStringArray);

	return true;
}

#endif
