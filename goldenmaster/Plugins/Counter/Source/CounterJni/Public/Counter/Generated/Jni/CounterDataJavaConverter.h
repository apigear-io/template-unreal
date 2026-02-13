
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

#include "CustomTypes/Generated/Jni/CustomTypesDataJavaConverter.h"
#include "ExternTypes/Generated/Jni/ExternTypesDataJavaConverter.h"
#include "Counter/Generated/api/Counter_apig.h"
#if PLATFORM_ANDROID

#include "HAL/CriticalSection.h"
#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI
DECLARE_LOG_CATEGORY_EXTERN(LogCounterDataJavaConverter_JNI, Log, All);

struct FCounterDataJavaConverterCacheData;

class COUNTERAPI_API CounterDataJavaConverter
{
public:
	static void fillCounter(JNIEnv* env, jobject input, TScriptInterface<ICounterCounterInterface> out_counter);
	static void fillCounterArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ICounterCounterInterface>>& out_array);
	static jobject makeJavaCounter(JNIEnv* env, const TScriptInterface<ICounterCounterInterface> out_counter);
	static jobjectArray makeJavaCounterArray(JNIEnv* env, const TArray<TScriptInterface<ICounterCounterInterface>>& cppArray);

	static TScriptInterface<ICounterCounterInterface> getCppInstanceCounterCounter();

	static bool checkJniErrorOccured(const TCHAR* Msg);
	static void cleanJavaReferences();

private:
	static FCriticalSection CacheLock;
	static TSharedPtr<FCounterDataJavaConverterCacheData, ESPMode::ThreadSafe> CacheData;
	static TSharedPtr<FCounterDataJavaConverterCacheData, ESPMode::ThreadSafe> ensureInitialized();
	static jmethodID getMethod(jclass cls, const char* name, const char* signature, const TCHAR*);
	static jmethodID getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo);
	static jfieldID getFieldId(jclass cls, const char* name, const char* signature, const TCHAR*);
};

#endif
