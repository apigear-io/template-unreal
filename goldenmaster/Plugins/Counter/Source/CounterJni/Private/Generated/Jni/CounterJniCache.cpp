
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

void CounterJniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();

	javaClassCounter = FAndroidApplication::FindJavaClassGlobalRef("Counter/Counter_api/ICounter");
	javaClassCounterVectorSetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "setVector", "(LcustomTypes/customTypes_api/Vector3D;)V");
	javaClassCounterVectorGetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "getVector", "()LcustomTypes/customTypes_api/Vector3D;");
	javaClassCounterExternVectorSetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "setExternVector", "(Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	javaClassCounterExternVectorGetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "getExternVector", "()Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
	javaClassCounterVectorArraySetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "setVectorArray", "([LcustomTypes/customTypes_api/Vector3D;)V");
	javaClassCounterVectorArrayGetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "getVectorArray", "()[LcustomTypes/customTypes_api/Vector3D;");
	javaClassCounterExternVectorArraySetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "setExternVectorArray", "([Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	javaClassCounterExternVectorArrayGetterId = env->GetMethodID(CounterJniCache::javaClassCounter, "getExternVectorArray", "()[Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;");
	javaClassCounterValueChangedSignalMethodID = env->GetMethodID(CounterJniCache::javaClassCounter, "onValueChanged", "(LcustomTypes/customTypes_api/Vector3D;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;[LcustomTypes/customTypes_api/Vector3D;[Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	javaClassCounterIncrementMethodID = env->GetMethodID(CounterJniCache::javaClassCounter, "incrementAsync", "(Ljava/lang/String;Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	javaClassCounterIncrementArrayMethodID = env->GetMethodID(CounterJniCache::javaClassCounter, "incrementArrayAsync", "(Ljava/lang/String;[Lorg/apache/commons/math3/geometry/euclidean/threed/Vector3D;)V");
	javaClassCounterDecrementMethodID = env->GetMethodID(CounterJniCache::javaClassCounter, "decrementAsync", "(Ljava/lang/String;LcustomTypes/customTypes_api/Vector3D;)V");
	javaClassCounterDecrementArrayMethodID = env->GetMethodID(CounterJniCache::javaClassCounter, "decrementArrayAsync", "(Ljava/lang/String;[LcustomTypes/customTypes_api/Vector3D;)V");
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
	javaClassCounterValueChangedSignalMethodID = nullptr;
	javaClassCounterIncrementMethodID = nullptr;
	javaClassCounterIncrementArrayMethodID = nullptr;
	javaClassCounterDecrementMethodID = nullptr;
	javaClassCounterDecrementArrayMethodID = nullptr;
}

bool CounterJniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
