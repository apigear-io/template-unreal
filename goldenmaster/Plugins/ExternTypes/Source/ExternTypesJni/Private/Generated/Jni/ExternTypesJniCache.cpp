
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

#include "ExternTypes/Generated/Jni/ExternTypesJniCache.h"
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

DEFINE_LOG_CATEGORY(LogExternTypesJniCache_JNI);

void ExternTypesJniCache::checkException(JNIEnv* env, FString memberInfo)
{
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogExternTypesJniCache_JNI, Warning, TEXT("Could not find %s"), *memberInfo);
	}
}
jclass ExternTypesJniCache::javaClassMyVector3D = nullptr;
jmethodID ExternTypesJniCache::javaClassMyVector3DCtor = nullptr;

bool ExternTypesJniCache::m_isInitialized = false;

void ExternTypesJniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	javaClassMyVector3D = FAndroidApplication::FindJavaClassGlobalRef("org/apache/commons/math3/geometry/euclidean/threed/Vector3D");
	checkException(env, "org/apache/commons/math3/geometry/euclidean/threed/Vector3D");
	javaClassMyVector3DCtor = env->GetMethodID(ExternTypesJniCache::javaClassMyVector3D, "<init>", "()V");
	checkException(env, "init, ()V for org/apache/commons/math3/geometry/euclidean/threed/Vector3D");
	m_isInitialized = true;
}

void ExternTypesJniCache::clear()
{
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(javaClassMyVector3D);
	javaClassMyVector3D = nullptr;
	javaClassMyVector3DCtor = nullptr;
}

bool ExternTypesJniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
