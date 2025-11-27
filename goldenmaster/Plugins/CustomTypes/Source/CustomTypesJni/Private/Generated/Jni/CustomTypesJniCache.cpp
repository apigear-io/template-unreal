
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

#include "CustomTypes/Generated/Jni/CustomTypesJniCache.h"
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

DEFINE_LOG_CATEGORY(LogCustomTypesJniCache_JNI);

void CustomTypesJniCache::checkException(JNIEnv* env, FString memberInfo)
{
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogCustomTypesJniCache_JNI, Warning, TEXT("Could not find %s"), *memberInfo);
	}
}
jclass CustomTypesJniCache::javaStructVector3D = nullptr;
jmethodID CustomTypesJniCache::javaStructVector3DCtor = nullptr;
jfieldID CustomTypesJniCache::javaStructVector3DXFieldId = nullptr;
jfieldID CustomTypesJniCache::javaStructVector3DYFieldId = nullptr;
jfieldID CustomTypesJniCache::javaStructVector3DZFieldId = nullptr;

bool CustomTypesJniCache::m_isInitialized = false;

void CustomTypesJniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	javaStructVector3D = FAndroidApplication::FindJavaClassGlobalRef("customTypes/customTypes_api/Vector3D");
	checkException(env, "customTypes/customTypes_api/Vector3D");
	javaStructVector3DCtor = env->GetMethodID(CustomTypesJniCache::javaStructVector3D, "<init>", "()V");
	checkException(env, "method <init>, ()V for customTypes/customTypes_api/Vector3D");
	javaStructVector3DXFieldId = env->GetFieldID(CustomTypesJniCache::javaStructVector3D, "x", "F");
	checkException(env, "x, F for customTypes/customTypes_api/Vector3D");
	javaStructVector3DYFieldId = env->GetFieldID(CustomTypesJniCache::javaStructVector3D, "y", "F");
	checkException(env, "y, F for customTypes/customTypes_api/Vector3D");
	javaStructVector3DZFieldId = env->GetFieldID(CustomTypesJniCache::javaStructVector3D, "z", "F");
	checkException(env, "z, F for customTypes/customTypes_api/Vector3D");
	m_isInitialized = true;
}

void CustomTypesJniCache::clear()
{
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(javaStructVector3D);
	javaStructVector3D = nullptr;
	javaStructVector3DCtor = nullptr;
	javaStructVector3DXFieldId = nullptr;
	javaStructVector3DYFieldId = nullptr;
	javaStructVector3DZFieldId = nullptr;
}

bool CustomTypesJniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
