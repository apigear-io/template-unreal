
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

// TODO
// after each findJAvaClassGlobalRef and getting methodId or FieldId
// if (env->ExceptionCheck()) {
//	env->ExceptionDescribe(); // logs in java
//	env->ExceptionClear();
//	LOG UE;
//}
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
	javaClassCounterVectorSetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "setVector", "(LcustomTypes/customTypes_api/Vector3D;)V");
	javaClassCounterVectorGetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "getVector", "()LcustomTypes/customTypes_api/Vector3D;");
	javaClassCounterExternVectorSetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "setExternVector", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	javaClassCounterExternVectorGetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "getExternVector", "()Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
	javaClassCounterVectorArraySetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "setVectorArray", "([LcustomTypes/customTypes_api/Vector3D;)V");
	javaClassCounterVectorArrayGetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "getVectorArray", "()[LcustomTypes/customTypes_api/Vector3D;");
	javaClassCounterExternVectorArraySetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "setExternVectorArray", "([Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	javaClassCounterExternVectorArrayGetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "getExternVectorArray", "()[Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");

	serviceClassCounter = FAndroidApplication::FindJavaClassGlobalRef("counter/counterjniservice/CounterJniService");
	serviceClassCounterReadyMethodID = env->GetMethodID(CounterJniCache::serviceClassCounter, "nativeServiceReady", "(Z)V");
	serviceClassCounterVectorChangedMethodID = env->GetMethodID(CounterJniCache::serviceClassCounter, "onVectorChanged", "(LcustomTypes/customTypes_api/Vector3D;)V");
	serviceClassCounterExternVectorChangedMethodID = env->GetMethodID(CounterJniCache::serviceClassCounter, "onExternVectorChanged", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	serviceClassCounterVectorArrayChangedMethodID = env->GetMethodID(CounterJniCache::serviceClassCounter, "onVectorArrayChanged", "([LcustomTypes/customTypes_api/Vector3D;)V");
	serviceClassCounterExternVectorArrayChangedMethodID = env->GetMethodID(CounterJniCache::serviceClassCounter, "onExternVectorArrayChanged", "([Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	serviceClassCounterValueChangedSignalMethodID = env->GetMethodID(CounterJniCache::serviceClassCounter, "onValueChanged", "(LcustomTypes/customTypes_api/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;[LcustomTypes/customTypes_api/Vector3D;[Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	clientClassCounter = FAndroidApplication::FindJavaClassGlobalRef("counter/counterjniclient/CounterJniClient");
	clientClassCounterIncrementAsyncMethodID = env->GetMethodID(CounterJniCache::clientClassCounter, "incrementAsync", "(Ljava/lang/String;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	clientClassCounterIncrementArrayAsyncMethodID = env->GetMethodID(CounterJniCache::clientClassCounter, "incrementArrayAsync", "(Ljava/lang/String;[Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	clientClassCounterDecrementAsyncMethodID = env->GetMethodID(CounterJniCache::clientClassCounter, "decrementAsync", "(Ljava/lang/String;LcustomTypes/customTypes_api/Vector3D;)V");
	clientClassCounterDecrementArrayAsyncMethodID = env->GetMethodID(CounterJniCache::clientClassCounter, "decrementArrayAsync", "(Ljava/lang/String;[LcustomTypes/customTypes_api/Vector3D;)V");
	clientClassCounterCtor = env->GetMethodID(CounterJniCache::clientClassCounter, "<init>", "()V");
	clientClassCounterBindMethodID = env->GetMethodID(CounterJniCache::clientClassCounter, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	clientClassCounterUnbindMethodID = env->GetMethodID(CounterJniCache::clientClassCounter, "unbind", "()V");
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
