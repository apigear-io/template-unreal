
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
DECLARE_LOG_CATEGORY_EXTERN(LogCounterJniCache_JNI, Log, All);

class COUNTERAPI_API CounterJniCache
{
public:
	static jclass javaClassCounter;
	static jmethodID javaClassCounterVectorSetterId;
	static jmethodID javaClassCounterVectorGetterId;
	static jmethodID javaClassCounterVectorChangedMethodID;
	static jmethodID javaClassCounterExternVectorSetterId;
	static jmethodID javaClassCounterExternVectorGetterId;
	static jmethodID javaClassCounterExternVectorChangedMethodID;
	static jmethodID javaClassCounterVectorArraySetterId;
	static jmethodID javaClassCounterVectorArrayGetterId;
	static jmethodID javaClassCounterVectorArrayChangedMethodID;
	static jmethodID javaClassCounterExternVectorArraySetterId;
	static jmethodID javaClassCounterExternVectorArrayGetterId;
	static jmethodID javaClassCounterExternVectorArrayChangedMethodID;
	static jclass serviceClassCounter;
	static jmethodID serviceClassCounterReadyMethodID;
	static jmethodID serviceClassCounterVectorChangedMethodID;
	static jmethodID serviceClassCounterExternVectorChangedMethodID;
	static jmethodID serviceClassCounterVectorArrayChangedMethodID;
	static jmethodID serviceClassCounterExternVectorArrayChangedMethodID;
	static jmethodID serviceClassCounterValueChangedSignalMethodID;
	static jclass clientClassCounter;
	static jmethodID clientClassCounterCtor;
	static jmethodID clientClassCounterBindMethodID;
	static jmethodID clientClassCounterUnbindMethodID;
	static jmethodID clientClassCounterIncrementAsyncMethodID;
	static jmethodID clientClassCounterIncrementArrayAsyncMethodID;
	static jmethodID clientClassCounterDecrementAsyncMethodID;
	static jmethodID clientClassCounterDecrementArrayAsyncMethodID;

	static void init();
	static void clear();
	static bool isInitialized();

private:
	static bool m_isInitialized;
	static void checkException(JNIEnv* env, FString memberInfo);
};

#endif
