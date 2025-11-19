
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

#include "TbNames/Generated/Jni/TbNamesJniCache.h"
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

void TbNamesJniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	javaEnumEnumWithUnderScores = FAndroidApplication::FindJavaClassGlobalRef("TbNames/TbNames_api/EnumWithUnderScores");
	javaEnumEnumWithUnderScoresFromValueMethodId = env->GetStaticMethodID(TbNamesJniCache::javaEnumEnumWithUnderScores, "fromValue", "(I)LTbNames/TbNames_api/EnumWithUnderScores;");
	javaEnumEnumWithUnderScoresGetValueMethod = env->GetMethodID(TbNamesJniCache::javaEnumEnumWithUnderScores, "getValue", "()I");

	javaClassNamEs = FAndroidApplication::FindJavaClassGlobalRef("TbNames/TbNames_api/INamEs");
	javaClassNamEsSwitchSetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "setSwitch", "(Z)V");
	javaClassNamEsSwitchGetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "getSwitch", "()Z");
	javaClassNamEsSomePropertySetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "setSomeProperty", "(I)V");
	javaClassNamEsSomePropertyGetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "getSomeProperty", "()I");
	javaClassNamEsSomePoperty2SetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "setSomePoperty2", "(I)V");
	javaClassNamEsSomePoperty2GetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "getSomePoperty2", "()I");
	javaClassNamEsEnumPropertySetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "setEnumProperty", "(LtbNames/tbNames_api/EnumWithUnderScores;)V");
	javaClassNamEsEnumPropertyGetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "getEnumProperty", "()LtbNames/tbNames_api/EnumWithUnderScores;");
	javaClassNamEsSomeSignalSignalMethodID = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "onSomeSignal", "(Z)V");
	javaClassNamEsSomeSignal2SignalMethodID = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "onSomeSignal2", "(Z)V");
	javaClassNamEsSomeFunctionMethodID = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "someFunctionAsync", "(Ljava/lang/String;Z)V");
	javaClassNamEsSomeFunction2MethodID = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "someFunction2Async", "(Ljava/lang/String;Z)V");
	m_isInitialized = true;
}

void TbNamesJniCache::clear()
{
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(javaEnumEnumWithUnderScores);
	javaEnumEnumWithUnderScores = nullptr;
	javaEnumEnumWithUnderScoresFromValueMethodId = nullptr;
	javaEnumEnumWithUnderScoresGetValueMethod = nullptr;
	env->DeleteGlobalRef(javaClassNamEs);
	javaClassNamEs = nullptr;
	javaClassNamEsSwitchSetterId = nullptr;
	javaClassNamEsSwitchGetterId = nullptr;
	javaClassNamEsSomePropertySetterId = nullptr;
	javaClassNamEsSomePropertyGetterId = nullptr;
	javaClassNamEsSomePoperty2SetterId = nullptr;
	javaClassNamEsSomePoperty2GetterId = nullptr;
	javaClassNamEsEnumPropertySetterId = nullptr;
	javaClassNamEsEnumPropertyGetterId = nullptr;
	javaClassNamEsSomeSignalSignalMethodID = nullptr;
	javaClassNamEsSomeSignal2SignalMethodID = nullptr;
	javaClassNamEsSomeFunctionMethodID = nullptr;
	javaClassNamEsSomeFunction2MethodID = nullptr;
}

bool TbNamesJniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
