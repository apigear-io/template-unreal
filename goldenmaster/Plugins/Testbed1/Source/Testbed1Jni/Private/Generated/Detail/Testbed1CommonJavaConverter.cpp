/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "Generated/Detail/Testbed1CommonJavaConverter.h"
#include "CoreMinimal.h"

#if PLATFORM_ANDROID && USE_ANDROID_JNI

DEFINE_LOG_CATEGORY(LogTestbed1CommonJavaConverter_JNI);

bool FTestbed1CommonJavaConverter::CheckJniErrorOccurred(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTestbed1CommonJavaConverter_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

bool FTestbed1CommonJavaConverter::TryFillArray(
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
