
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

#include "TbIfaceimport/Generated/Jni/TbIfaceimportJniCache.h"
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

DEFINE_LOG_CATEGORY(LogTbIfaceimportJniCache_JNI);

void TbIfaceimportJniCache::checkException(JNIEnv* env, FString memberInfo)
{
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbIfaceimportJniCache_JNI, Warning, TEXT("Could not find %s"), *memberInfo);
	}
}
jclass TbIfaceimportJniCache::javaClassEmptyIf = nullptr;
jclass TbIfaceimportJniCache::serviceClassEmptyIf = nullptr;
jmethodID TbIfaceimportJniCache::serviceClassEmptyIfReadyMethodID = nullptr;
jclass TbIfaceimportJniCache::clientClassEmptyIf = nullptr;
jmethodID TbIfaceimportJniCache::clientClassEmptyIfCtor = nullptr;
jmethodID TbIfaceimportJniCache::clientClassEmptyIfBindMethodID = nullptr;
jmethodID TbIfaceimportJniCache::clientClassEmptyIfUnbindMethodID = nullptr;

bool TbIfaceimportJniCache::m_isInitialized = false;

void TbIfaceimportJniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();

	javaClassEmptyIf = FAndroidApplication::FindJavaClassGlobalRef("tbIfaceimport/tbIfaceimport_api/IEmptyIf");
	checkException(env, "tbIfaceimport/tbIfaceimport_api/IEmptyIf");

	serviceClassEmptyIf = FAndroidApplication::FindJavaClassGlobalRef("tbIfaceimport/tbIfaceimportjniservice/EmptyIfJniService");
	checkException(env, "tbIfaceimport/tbIfaceimportjniservice/EmptyIfJniService");
	serviceClassEmptyIfReadyMethodID = env->GetMethodID(TbIfaceimportJniCache::serviceClassEmptyIf, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for tbIfaceimport/tbIfaceimportjniservice/EmptyIfJniService");
	clientClassEmptyIf = FAndroidApplication::FindJavaClassGlobalRef("tbIfaceimport/tbIfaceimportjniclient/EmptyIfJniClient");
	checkException(env, "tbIfaceimport/tbIfaceimportjniclient/EmptyIfJniClient");
	clientClassEmptyIfCtor = env->GetMethodID(TbIfaceimportJniCache::clientClassEmptyIf, "<init>", "()V");
	checkException(env, "init, ()V for tbIfaceimport/tbIfaceimportjniclient/EmptyIfJniClient");
	clientClassEmptyIfBindMethodID = env->GetMethodID(TbIfaceimportJniCache::clientClassEmptyIf, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for tbIfaceimport/tbIfaceimportjniclient/EmptyIfJniClient");
	clientClassEmptyIfUnbindMethodID = env->GetMethodID(TbIfaceimportJniCache::clientClassEmptyIf, "unbind", "()V");
	checkException(env, "unbind, ()V for tbIfaceimport/tbIfaceimportjniclient/EmptyIfJniClient");
	m_isInitialized = true;
}

void TbIfaceimportJniCache::clear()
{
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(javaClassEmptyIf);
	javaClassEmptyIf = nullptr;
	env->DeleteGlobalRef(serviceClassEmptyIf);
	serviceClassEmptyIf = nullptr;
	serviceClassEmptyIfReadyMethodID = nullptr;
	env->DeleteGlobalRef(clientClassEmptyIf);
	clientClassEmptyIf = nullptr;
	clientClassEmptyIfCtor = nullptr;
	clientClassEmptyIfBindMethodID = nullptr;
	clientClassEmptyIfUnbindMethodID = nullptr;
}

bool TbIfaceimportJniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
