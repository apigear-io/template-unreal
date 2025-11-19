
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

// TODO
// after each findJAvaClassGlobalRef and getting methodId or FieldId
// if (env->ExceptionCheck()) {
//	env->ExceptionDescribe(); // logs in java
//	env->ExceptionClear();
//	LOG UE;
//}

void CustomTypesJniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	javaStructVector3D = FAndroidApplication::FindJavaClassGlobalRef("CustomTypes/CustomTypes_api/Vector3D");
	javaStructVector3DCtor = env->GetMethodID(CustomTypesJniCache::javaStructVector3D, "<init>", "()V");
	javaStructXxFieldId = env->GetFieldID(CustomTypesJniCache::javaStructX, "x", "F");
	javaStructYyFieldId = env->GetFieldID(CustomTypesJniCache::javaStructY, "y", "F");
	javaStructZzFieldId = env->GetFieldID(CustomTypesJniCache::javaStructZ, "z", "F");
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
