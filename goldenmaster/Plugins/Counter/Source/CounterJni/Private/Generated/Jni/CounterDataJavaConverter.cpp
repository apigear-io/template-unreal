
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

#include "Counter/Generated/Jni/CounterDataJavaConverter.h"
#include "Counter/Generated/Jni/CounterJniCache.h"
#include "CustomTypes/Generated/Jni/CustomTypesDataJavaConverter.h"
#include "CustomTypes/Generated/api/CustomTypes_data.h"
#include "ExternTypes/Generated/Jni/ExternTypesDataJavaConverter.h"
#include "ExternTypes/Generated/api/ExternTypes_data.h"
#include "Counter/Implementation/CounterCounter.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

DEFINE_LOG_CATEGORY(LogCounterDataJavaConverter_JNI);

void CounterDataJavaConverter::fillCounter(JNIEnv* env, jobject input, TScriptInterface<ICounterCounterInterface> out_counter)
{
	if (!input || !out_counter)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void CounterDataJavaConverter::fillCounterArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ICounterCounterInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject CounterDataJavaConverter::makeJavaCounter(JNIEnv* env, const TScriptInterface<ICounterCounterInterface> out_counter)
{
	if (!out_counter)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray CounterDataJavaConverter::makeJavaCounterArray(JNIEnv* env, const TArray<TScriptInterface<ICounterCounterInterface>>& cppArray)
{
	if (!CounterJniCache::javaClassCounter)
	{
		UE_LOG(LogCounterDataJavaConverter_JNI, Warning, TEXT("ICounter not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, CounterJniCache::javaClassCounter, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_counter.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ICounterCounterInterface> CounterDataJavaConverter::getCppInstanceCounterCounter()
{
	UCounterCounterImplementation* Impl = NewObject<UCounterCounterImplementation>();
	TScriptInterface<ICounterCounterInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ICounterCounterInterface>(Impl));
	return wrapped;
}

bool CounterDataJavaConverter::checkJniErrorOccured(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogCounterDataJavaConverter_JNI, Warning, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

#endif
