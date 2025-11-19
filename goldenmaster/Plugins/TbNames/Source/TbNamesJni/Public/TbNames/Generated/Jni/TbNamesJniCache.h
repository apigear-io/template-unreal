
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
#pragma once

#include "CoreMinimal.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

#include "Engine/Engine.h"

class TBNAMESAPI_API TbNamesJniCache
{
public:
	static jclass javaEnumEnumWithUnderScores;
	static jmethodID javaEnumEnumWithUnderScoresFromValueMethodId;
	static jmethodID javaEnumEnumWithUnderScoresGetValueMethod;
	static jclass javaClassNamEs;
	static jmethodID javaClassNamEsSwitchSetterId;
	static jmethodID javaClassNamEsSwitchGetterId;
	static jmethodID javaClassNamEsSwitchChangedMethodID;
	static jmethodID javaClassNamEsSomePropertySetterId;
	static jmethodID javaClassNamEsSomePropertyGetterId;
	static jmethodID javaClassNamEsSomePropertyChangedMethodID;
	static jmethodID javaClassNamEsSomePoperty2SetterId;
	static jmethodID javaClassNamEsSomePoperty2GetterId;
	static jmethodID javaClassNamEsSomePoperty2ChangedMethodID;
	static jmethodID javaClassNamEsEnumPropertySetterId;
	static jmethodID javaClassNamEsEnumPropertyGetterId;
	static jmethodID javaClassNamEsEnumPropertyChangedMethodID;
	static jclass serviceClassNamEs;
	static jmethodID serviceClassNamEsReadyMethodID;
	static jmethodID serviceClassNamEsSwitchChangedMethodID;
	static jmethodID serviceClassNamEsSomePropertyChangedMethodID;
	static jmethodID serviceClassNamEsSomePoperty2ChangedMethodID;
	static jmethodID serviceClassNamEsEnumPropertyChangedMethodID;
	static jmethodID serviceClassNamEsSomeSignalSignalMethodID;
	static jmethodID serviceClassNamEsSomeSignal2SignalMethodID;
	static jclass clientClassNamEs;
	static jmethodID clientClassNamEsCtor;
	static jmethodID clientClassNamEsBindMethodID;
	static jmethodID clientClassNamEsUnbindMethodID;
	static jmethodID clientClassNamEsSomeFunctionAsyncMethodID;
	static jmethodID clientClassNamEsSomeFunction2AsyncMethodID;

	static void init();
	static void clear();
	static bool isInitialized();

private:
	static bool m_isInitialized;
};

#endif
