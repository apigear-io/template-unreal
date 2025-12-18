
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
jclass CounterDataJavaConverter::jCounter = nullptr;

void CounterDataJavaConverter::fillCounter(JNIEnv* env, jobject input, TScriptInterface<ICounterCounterInterface> out_counter)
{
	ensureInitialized();
	if (!input || !out_counter)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void CounterDataJavaConverter::fillCounterArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ICounterCounterInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject CounterDataJavaConverter::makeJavaCounter(JNIEnv* env, const TScriptInterface<ICounterCounterInterface> out_counter)
{
	ensureInitialized();
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
	ensureInitialized();
	jclass javaClass = jCounter;
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaClass, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ICounterCounterInterface> CounterDataJavaConverter::getCppInstanceCounterCounter()
{
	ensureInitialized();
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
		UE_LOG(LogCounterDataJavaConverter_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

void CounterDataJavaConverter::cleanJavaReferences()
{
	FScopeLock Lock(&initMutex);
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(jCounter);
}

FCriticalSection CounterDataJavaConverter::initMutex;

bool CounterDataJavaConverter::m_isInitialized = false;

void CounterDataJavaConverter::ensureInitialized()
{
	if (m_isInitialized)
	{
		return;
	}
	FScopeLock Lock(&initMutex);
	if (m_isInitialized)
	{
		return;
	}
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jCounter = FAndroidApplication::FindJavaClassGlobalRef("counter/counter_api/ICounter");
	static const TCHAR* errorMsgCounter= TEXT("failed to get counter/counter_api/ICounter");
	checkJniErrorOccured(errorMsgCounter);
	m_isInitialized = true;
}

}
}

#endif
