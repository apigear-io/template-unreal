
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
jclass TbNamesJniCache::javaEnumEnumWithUnderScores = nullptr;
jmethodID TbNamesJniCache::javaEnumEnumWithUnderScoresFromValueMethodId = nullptr;
jmethodID TbNamesJniCache::javaEnumEnumWithUnderScoresGetValueMethod = nullptr;
jclass TbNamesJniCache::javaClassNamEs = nullptr;
jmethodID TbNamesJniCache::javaClassNamEsSwitchSetterId = nullptr;
jmethodID TbNamesJniCache::javaClassNamEsSwitchGetterId = nullptr;
jmethodID TbNamesJniCache::javaClassNamEsSomePropertySetterId = nullptr;
jmethodID TbNamesJniCache::javaClassNamEsSomePropertyGetterId = nullptr;
jmethodID TbNamesJniCache::javaClassNamEsSomePoperty2SetterId = nullptr;
jmethodID TbNamesJniCache::javaClassNamEsSomePoperty2GetterId = nullptr;
jmethodID TbNamesJniCache::javaClassNamEsEnumPropertySetterId = nullptr;
jmethodID TbNamesJniCache::javaClassNamEsEnumPropertyGetterId = nullptr;
jclass TbNamesJniCache::serviceClassNamEs = nullptr;
jmethodID TbNamesJniCache::serviceClassNamEsReadyMethodID = nullptr;
jmethodID TbNamesJniCache::serviceClassNamEsSwitchChangedMethodID = nullptr;
jmethodID TbNamesJniCache::serviceClassNamEsSomePropertyChangedMethodID = nullptr;
jmethodID TbNamesJniCache::serviceClassNamEsSomePoperty2ChangedMethodID = nullptr;
jmethodID TbNamesJniCache::serviceClassNamEsEnumPropertyChangedMethodID = nullptr;
jmethodID TbNamesJniCache::serviceClassNamEsSomeSignalSignalMethodID = nullptr;
jmethodID TbNamesJniCache::serviceClassNamEsSomeSignal2SignalMethodID = nullptr;
jclass TbNamesJniCache::clientClassNamEs = nullptr;
jmethodID TbNamesJniCache::clientClassNamEsCtor = nullptr;
jmethodID TbNamesJniCache::clientClassNamEsBindMethodID = nullptr;
jmethodID TbNamesJniCache::clientClassNamEsUnbindMethodID = nullptr;
jmethodID TbNamesJniCache::clientClassNamEsSomeFunctionAsyncMethodID = nullptr;
jmethodID TbNamesJniCache::clientClassNamEsSomeFunction2AsyncMethodID = nullptr;

bool TbNamesJniCache::m_isInitialized = false;

void TbNamesJniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	javaEnumEnumWithUnderScores = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNames_api/EnumWithUnderScores");
	javaEnumEnumWithUnderScoresFromValueMethodId = env->GetStaticMethodID(TbNamesJniCache::javaEnumEnumWithUnderScores, "fromValue", "(I)LtbNames/tbNames_api/EnumWithUnderScores;");
	javaEnumEnumWithUnderScoresGetValueMethod = env->GetMethodID(TbNamesJniCache::javaEnumEnumWithUnderScores, "getValue", "()I");

	javaClassNamEs = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNames_api/INamEs");
	javaClassNamEsSwitchSetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "setSwitch", "(Z)V");
	javaClassNamEsSwitchGetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "getSwitch", "()Z");
	javaClassNamEsSomePropertySetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "setSomeProperty", "(I)V");
	javaClassNamEsSomePropertyGetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "getSomeProperty", "()I");
	javaClassNamEsSomePoperty2SetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "setSomePoperty2", "(I)V");
	javaClassNamEsSomePoperty2GetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "getSomePoperty2", "()I");
	javaClassNamEsEnumPropertySetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "setEnumProperty", "(LtbNames/tbNames_api/EnumWithUnderScores;)V");
	javaClassNamEsEnumPropertyGetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "getEnumProperty", "()LtbNames/tbNames_api/EnumWithUnderScores;");

	serviceClassNamEs = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNamesjniservice/NamEsJniService");
	serviceClassNamEsReadyMethodID = env->GetMethodID(TbNamesJniCache::serviceClassNamEs, "nativeServiceReady", "(Z)V");
	serviceClassNamEsSwitchChangedMethodID = env->GetMethodID(TbNamesJniCache::serviceClassNamEs, "onSwitchChanged", "(Z)V");
	serviceClassNamEsSomePropertyChangedMethodID = env->GetMethodID(TbNamesJniCache::serviceClassNamEs, "onSomePropertyChanged", "(I)V");
	serviceClassNamEsSomePoperty2ChangedMethodID = env->GetMethodID(TbNamesJniCache::serviceClassNamEs, "onSomePoperty2Changed", "(I)V");
	serviceClassNamEsEnumPropertyChangedMethodID = env->GetMethodID(TbNamesJniCache::serviceClassNamEs, "onEnumPropertyChanged", "(LtbNames/tbNames_api/EnumWithUnderScores;)V");
	serviceClassNamEsSomeSignalSignalMethodID = env->GetMethodID(TbNamesJniCache::serviceClassNamEs, "onSomeSignal", "(Z)V");
	serviceClassNamEsSomeSignal2SignalMethodID = env->GetMethodID(TbNamesJniCache::serviceClassNamEs, "onSomeSignal2", "(Z)V");
	clientClassNamEs = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNamesjniclient/NamEsJniClient");
	clientClassNamEsSomeFunctionAsyncMethodID = env->GetMethodID(TbNamesJniCache::clientClassNamEs, "someFunctionAsync", "(Ljava/lang/String;Z)V");
	clientClassNamEsSomeFunction2AsyncMethodID = env->GetMethodID(TbNamesJniCache::clientClassNamEs, "someFunction2Async", "(Ljava/lang/String;Z)V");
	clientClassNamEsCtor = env->GetMethodID(TbNamesJniCache::clientClassNamEs, "<init>", "()V");
	clientClassNamEsBindMethodID = env->GetMethodID(TbNamesJniCache::clientClassNamEs, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	clientClassNamEsUnbindMethodID = env->GetMethodID(TbNamesJniCache::clientClassNamEs, "unbind", "()V");
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
	env->DeleteGlobalRef(serviceClassNamEs);
	serviceClassNamEs = nullptr;
	serviceClassNamEsReadyMethodID = nullptr;
	serviceClassNamEsSwitchChangedMethodID = nullptr;
	serviceClassNamEsSomePropertyChangedMethodID = nullptr;
	serviceClassNamEsSomePoperty2ChangedMethodID = nullptr;
	serviceClassNamEsEnumPropertyChangedMethodID = nullptr;
	serviceClassNamEsSomeSignalSignalMethodID = nullptr;
	serviceClassNamEsSomeSignal2SignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassNamEs);
	clientClassNamEs = nullptr;
	clientClassNamEsSomeFunctionAsyncMethodID = nullptr;
	clientClassNamEsSomeFunction2AsyncMethodID = nullptr;
	clientClassNamEsCtor = nullptr;
	clientClassNamEsBindMethodID = nullptr;
	clientClassNamEsUnbindMethodID = nullptr;
}

bool TbNamesJniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
