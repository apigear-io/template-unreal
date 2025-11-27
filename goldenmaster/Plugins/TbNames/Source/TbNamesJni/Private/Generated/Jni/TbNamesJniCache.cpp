
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

DEFINE_LOG_CATEGORY(LogTbNamesJniCache_JNI);

void TbNamesJniCache::checkException(JNIEnv* env, FString memberInfo)
{
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbNamesJniCache_JNI, Warning, TEXT("Could not find %s"), *memberInfo);
	}
}
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
	checkException(env, "tbNames/tbNames_api/EnumWithUnderScores");
	javaEnumEnumWithUnderScoresFromValueMethodId = env->GetStaticMethodID(TbNamesJniCache::javaEnumEnumWithUnderScores, "fromValue", "(I)LtbNames/tbNames_api/EnumWithUnderScores;");
	checkException(env, "fromValue (I)LtbNames/tbNames_api/EnumWithUnderScores; for tbNames/tbNames_api/EnumWithUnderScores");
	javaEnumEnumWithUnderScoresGetValueMethod = env->GetMethodID(TbNamesJniCache::javaEnumEnumWithUnderScores, "getValue", "()I");
	checkException(env, "getValue (I)LtbNames/tbNames_api/EnumWithUnderScores; for tbNames/tbNames_api/EnumWithUnderScores");

	javaClassNamEs = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNames_api/INamEs");
	checkException(env, "tbNames/tbNames_api/INamEs");
	javaClassNamEsSwitchSetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "setSwitch", "(Z)V");
	checkException(env, "setSwitch, (Z)V  for tbNames/tbNames_api/INamEs");
	javaClassNamEsSwitchGetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "getSwitch", "()Z");
	checkException(env, "getSwitch, ()Z for tbNames/tbNames_api/INamEs");
	javaClassNamEsSomePropertySetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "setSomeProperty", "(I)V");
	checkException(env, "setSomeProperty, (I)V  for tbNames/tbNames_api/INamEs");
	javaClassNamEsSomePropertyGetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "getSomeProperty", "()I");
	checkException(env, "getSomeProperty, ()I for tbNames/tbNames_api/INamEs");
	javaClassNamEsSomePoperty2SetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "setSomePoperty2", "(I)V");
	checkException(env, "setSomePoperty2, (I)V  for tbNames/tbNames_api/INamEs");
	javaClassNamEsSomePoperty2GetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "getSomePoperty2", "()I");
	checkException(env, "getSomePoperty2, ()I for tbNames/tbNames_api/INamEs");
	javaClassNamEsEnumPropertySetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "setEnumProperty", "(LtbNames/tbNames_api/EnumWithUnderScores;)V");
	checkException(env, "setEnumProperty, (LtbNames/tbNames_api/EnumWithUnderScores;)V  for tbNames/tbNames_api/INamEs");
	javaClassNamEsEnumPropertyGetterId = env->GetMethodID(TbNamesJniCache::javaClassNamEs, "getEnumProperty", "()LtbNames/tbNames_api/EnumWithUnderScores;");
	checkException(env, "getEnumProperty, ()LtbNames/tbNames_api/EnumWithUnderScores; for tbNames/tbNames_api/INamEs");

	serviceClassNamEs = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNamesjniservice/NamEsJniService");
	checkException(env, "tbNames/tbNamesjniservice/NamEsJniService");
	serviceClassNamEsReadyMethodID = env->GetMethodID(TbNamesJniCache::serviceClassNamEs, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for tbNames/tbNamesjniservice/NamEsJniService");
	serviceClassNamEsSwitchChangedMethodID = env->GetMethodID(TbNamesJniCache::serviceClassNamEs, "onSwitchChanged", "(Z)V");
	checkException(env, "onSwitchChanged, (Z)V for tbNames/tbNamesjniservice/NamEsJniService");
	serviceClassNamEsSomePropertyChangedMethodID = env->GetMethodID(TbNamesJniCache::serviceClassNamEs, "onSomePropertyChanged", "(I)V");
	checkException(env, "onSomePropertyChanged, (I)V for tbNames/tbNamesjniservice/NamEsJniService");
	serviceClassNamEsSomePoperty2ChangedMethodID = env->GetMethodID(TbNamesJniCache::serviceClassNamEs, "onSomePoperty2Changed", "(I)V");
	checkException(env, "onSomePoperty2Changed, (I)V for tbNames/tbNamesjniservice/NamEsJniService");
	serviceClassNamEsEnumPropertyChangedMethodID = env->GetMethodID(TbNamesJniCache::serviceClassNamEs, "onEnumPropertyChanged", "(LtbNames/tbNames_api/EnumWithUnderScores;)V");
	checkException(env, "onEnumPropertyChanged, (LtbNames/tbNames_api/EnumWithUnderScores;)V for tbNames/tbNamesjniservice/NamEsJniService");
	serviceClassNamEsSomeSignalSignalMethodID = env->GetMethodID(TbNamesJniCache::serviceClassNamEs, "onSomeSignal", "(Z)V");
	checkException(env, "onSomeSignal, (Z)V for tbNames/tbNamesjniservice/NamEsJniService");
	serviceClassNamEsSomeSignal2SignalMethodID = env->GetMethodID(TbNamesJniCache::serviceClassNamEs, "onSomeSignal2", "(Z)V");
	checkException(env, "onSomeSignal2, (Z)V for tbNames/tbNamesjniservice/NamEsJniService");
	clientClassNamEs = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNamesjniclient/NamEsJniClient");
	checkException(env, "tbNames/tbNamesjniclient/NamEsJniClient");
	clientClassNamEsSomeFunctionAsyncMethodID = env->GetMethodID(TbNamesJniCache::clientClassNamEs, "someFunctionAsync", "(Ljava/lang/String;Z)V");
	checkException(env, "someFunctionAsync, (Ljava/lang/String;Z)V for tbNames/tbNamesjniclient/NamEsJniClient");
	clientClassNamEsSomeFunction2AsyncMethodID = env->GetMethodID(TbNamesJniCache::clientClassNamEs, "someFunction2Async", "(Ljava/lang/String;Z)V");
	checkException(env, "someFunction2Async, (Ljava/lang/String;Z)V for tbNames/tbNamesjniclient/NamEsJniClient");
	clientClassNamEsCtor = env->GetMethodID(TbNamesJniCache::clientClassNamEs, "<init>", "()V");
	checkException(env, "init, ()V for tbNames/tbNamesjniclient/NamEsJniClient");
	clientClassNamEsBindMethodID = env->GetMethodID(TbNamesJniCache::clientClassNamEs, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for tbNames/tbNamesjniclient/NamEsJniClient");
	clientClassNamEsUnbindMethodID = env->GetMethodID(TbNamesJniCache::clientClassNamEs, "unbind", "()V");
	checkException(env, "unbind, ()V for tbNames/tbNamesjniclient/NamEsJniClient");
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
