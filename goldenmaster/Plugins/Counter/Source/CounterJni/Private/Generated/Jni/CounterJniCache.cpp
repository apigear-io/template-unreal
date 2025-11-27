
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

#include "Counter/Generated/Jni/CounterJniCache.h"
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

DEFINE_LOG_CATEGORY(LogCounterJniCache_JNI);

void CounterJniCache::checkException(JNIEnv* env, FString memberInfo)
{
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogCounterJniCache_JNI, Warning, TEXT("Could not find %s"), *memberInfo);
	}
}
jclass CounterJniCache::javaClassCounter = nullptr;
jmethodID CounterJniCache::javaClassCounterVectorSetterId = nullptr;
jmethodID CounterJniCache::javaClassCounterVectorGetterId = nullptr;
jmethodID CounterJniCache::javaClassCounterExternVectorSetterId = nullptr;
jmethodID CounterJniCache::javaClassCounterExternVectorGetterId = nullptr;
jmethodID CounterJniCache::javaClassCounterVectorArraySetterId = nullptr;
jmethodID CounterJniCache::javaClassCounterVectorArrayGetterId = nullptr;
jmethodID CounterJniCache::javaClassCounterExternVectorArraySetterId = nullptr;
jmethodID CounterJniCache::javaClassCounterExternVectorArrayGetterId = nullptr;
jclass CounterJniCache::serviceClassCounter = nullptr;
jmethodID CounterJniCache::serviceClassCounterReadyMethodID = nullptr;
jmethodID CounterJniCache::serviceClassCounterVectorChangedMethodID = nullptr;
jmethodID CounterJniCache::serviceClassCounterExternVectorChangedMethodID = nullptr;
jmethodID CounterJniCache::serviceClassCounterVectorArrayChangedMethodID = nullptr;
jmethodID CounterJniCache::serviceClassCounterExternVectorArrayChangedMethodID = nullptr;
jmethodID CounterJniCache::serviceClassCounterValueChangedSignalMethodID = nullptr;
jclass CounterJniCache::clientClassCounter = nullptr;
jmethodID CounterJniCache::clientClassCounterCtor = nullptr;
jmethodID CounterJniCache::clientClassCounterBindMethodID = nullptr;
jmethodID CounterJniCache::clientClassCounterUnbindMethodID = nullptr;
jmethodID CounterJniCache::clientClassCounterIncrementAsyncMethodID = nullptr;
jmethodID CounterJniCache::clientClassCounterIncrementArrayAsyncMethodID = nullptr;
jmethodID CounterJniCache::clientClassCounterDecrementAsyncMethodID = nullptr;
jmethodID CounterJniCache::clientClassCounterDecrementArrayAsyncMethodID = nullptr;

bool CounterJniCache::m_isInitialized = false;

void CounterJniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();

	javaClassCounter = FAndroidApplication::FindJavaClassGlobalRef("counter/counter_api/ICounter");
	checkException(env, "counter/counter_api/ICounter");
	javaClassCounterVectorSetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "setVector", "(LcustomTypes/customTypes_api/Vector3D;)V");
	checkException(env, "setVector, (LcustomTypes/customTypes_api/Vector3D;)V  for counter/counter_api/ICounter");
	javaClassCounterVectorGetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "getVector", "()LcustomTypes/customTypes_api/Vector3D;");
	checkException(env, "getVector, ()LcustomTypes/customTypes_api/Vector3D; for counter/counter_api/ICounter");
	javaClassCounterExternVectorSetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "setExternVector", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	checkException(env, "setExternVector, (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V  for counter/counter_api/ICounter");
	javaClassCounterExternVectorGetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "getExternVector", "()Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
	checkException(env, "getExternVector, ()Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D; for counter/counter_api/ICounter");
	javaClassCounterVectorArraySetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "setVectorArray", "([LcustomTypes/customTypes_api/Vector3D;)V");
	checkException(env, "setVectorArray, ([LcustomTypes/customTypes_api/Vector3D;)V  for counter/counter_api/ICounter");
	javaClassCounterVectorArrayGetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "getVectorArray", "()[LcustomTypes/customTypes_api/Vector3D;");
	checkException(env, "getVectorArray, ()[LcustomTypes/customTypes_api/Vector3D; for counter/counter_api/ICounter");
	javaClassCounterExternVectorArraySetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "setExternVectorArray", "([Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	checkException(env, "setExternVectorArray, ([Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V  for counter/counter_api/ICounter");
	javaClassCounterExternVectorArrayGetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "getExternVectorArray", "()[Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
	checkException(env, "getExternVectorArray, ()[Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D; for counter/counter_api/ICounter");

	serviceClassCounter = FAndroidApplication::FindJavaClassGlobalRef("counter/counterjniservice/CounterJniService");
	checkException(env, "counter/counterjniservice/CounterJniService");
	serviceClassCounterReadyMethodID = env->GetMethodID(CounterJniCache::serviceClassCounter, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for counter/counterjniservice/CounterJniService");
	serviceClassCounterVectorChangedMethodID = env->GetMethodID(CounterJniCache::serviceClassCounter, "onVectorChanged", "(LcustomTypes/customTypes_api/Vector3D;)V");
	checkException(env, "onVectorChanged, (LcustomTypes/customTypes_api/Vector3D;)V for counter/counterjniservice/CounterJniService");
	serviceClassCounterExternVectorChangedMethodID = env->GetMethodID(CounterJniCache::serviceClassCounter, "onExternVectorChanged", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	checkException(env, "onExternVectorChanged, (Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V for counter/counterjniservice/CounterJniService");
	serviceClassCounterVectorArrayChangedMethodID = env->GetMethodID(CounterJniCache::serviceClassCounter, "onVectorArrayChanged", "([LcustomTypes/customTypes_api/Vector3D;)V");
	checkException(env, "onVectorArrayChanged, ([LcustomTypes/customTypes_api/Vector3D;)V for counter/counterjniservice/CounterJniService");
	serviceClassCounterExternVectorArrayChangedMethodID = env->GetMethodID(CounterJniCache::serviceClassCounter, "onExternVectorArrayChanged", "([Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	checkException(env, "onExternVectorArrayChanged, ([Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V for counter/counterjniservice/CounterJniService");
	serviceClassCounterValueChangedSignalMethodID = env->GetMethodID(CounterJniCache::serviceClassCounter, "onValueChanged", "(LcustomTypes/customTypes_api/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;[LcustomTypes/customTypes_api/Vector3D;[Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	checkException(env, "onValueChanged, (LcustomTypes/customTypes_api/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;[LcustomTypes/customTypes_api/Vector3D;[Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V for counter/counterjniservice/CounterJniService");
	clientClassCounter = FAndroidApplication::FindJavaClassGlobalRef("counter/counterjniclient/CounterJniClient");
	checkException(env, "counter/counterjniclient/CounterJniClient");
	clientClassCounterIncrementAsyncMethodID = env->GetMethodID(CounterJniCache::clientClassCounter, "incrementAsync", "(Ljava/lang/String;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	checkException(env, "incrementAsync, (Ljava/lang/String;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V for counter/counterjniclient/CounterJniClient");
	clientClassCounterIncrementArrayAsyncMethodID = env->GetMethodID(CounterJniCache::clientClassCounter, "incrementArrayAsync", "(Ljava/lang/String;[Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	checkException(env, "incrementArrayAsync, (Ljava/lang/String;[Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V for counter/counterjniclient/CounterJniClient");
	clientClassCounterDecrementAsyncMethodID = env->GetMethodID(CounterJniCache::clientClassCounter, "decrementAsync", "(Ljava/lang/String;LcustomTypes/customTypes_api/Vector3D;)V");
	checkException(env, "decrementAsync, (Ljava/lang/String;LcustomTypes/customTypes_api/Vector3D;)V for counter/counterjniclient/CounterJniClient");
	clientClassCounterDecrementArrayAsyncMethodID = env->GetMethodID(CounterJniCache::clientClassCounter, "decrementArrayAsync", "(Ljava/lang/String;[LcustomTypes/customTypes_api/Vector3D;)V");
	checkException(env, "decrementArrayAsync, (Ljava/lang/String;[LcustomTypes/customTypes_api/Vector3D;)V for counter/counterjniclient/CounterJniClient");
	clientClassCounterCtor = env->GetMethodID(CounterJniCache::clientClassCounter, "<init>", "()V");
	checkException(env, "init, ()V for counter/counterjniclient/CounterJniClient");
	clientClassCounterBindMethodID = env->GetMethodID(CounterJniCache::clientClassCounter, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for counter/counterjniclient/CounterJniClient");
	clientClassCounterUnbindMethodID = env->GetMethodID(CounterJniCache::clientClassCounter, "unbind", "()V");
	checkException(env, "unbind, ()V for counter/counterjniclient/CounterJniClient");
	m_isInitialized = true;
}

void CounterJniCache::clear()
{
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(javaClassCounter);
	javaClassCounter = nullptr;
	javaClassCounterVectorSetterId = nullptr;
	javaClassCounterVectorGetterId = nullptr;
	javaClassCounterExternVectorSetterId = nullptr;
	javaClassCounterExternVectorGetterId = nullptr;
	javaClassCounterVectorArraySetterId = nullptr;
	javaClassCounterVectorArrayGetterId = nullptr;
	javaClassCounterExternVectorArraySetterId = nullptr;
	javaClassCounterExternVectorArrayGetterId = nullptr;
	env->DeleteGlobalRef(serviceClassCounter);
	serviceClassCounter = nullptr;
	serviceClassCounterReadyMethodID = nullptr;
	serviceClassCounterVectorChangedMethodID = nullptr;
	serviceClassCounterExternVectorChangedMethodID = nullptr;
	serviceClassCounterVectorArrayChangedMethodID = nullptr;
	serviceClassCounterExternVectorArrayChangedMethodID = nullptr;
	serviceClassCounterValueChangedSignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassCounter);
	clientClassCounter = nullptr;
	clientClassCounterIncrementAsyncMethodID = nullptr;
	clientClassCounterIncrementArrayAsyncMethodID = nullptr;
	clientClassCounterDecrementAsyncMethodID = nullptr;
	clientClassCounterDecrementArrayAsyncMethodID = nullptr;
	clientClassCounterCtor = nullptr;
	clientClassCounterBindMethodID = nullptr;
	clientClassCounterUnbindMethodID = nullptr;
}

bool CounterJniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
