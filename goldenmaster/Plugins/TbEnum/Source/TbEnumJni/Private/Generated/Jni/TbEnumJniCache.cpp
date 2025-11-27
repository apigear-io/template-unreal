
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

#include "TbEnum/Generated/Jni/TbEnumJniCache.h"
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

DEFINE_LOG_CATEGORY(LogTbEnumJniCache_JNI);

void TbEnumJniCache::checkException(JNIEnv* env, FString memberInfo)
{
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbEnumJniCache_JNI, Warning, TEXT("Could not find %s"), *memberInfo);
	}
}
jclass TbEnumJniCache::javaEnumEnum0 = nullptr;
jmethodID TbEnumJniCache::javaEnumEnum0FromValueMethodId = nullptr;
jmethodID TbEnumJniCache::javaEnumEnum0GetValueMethod = nullptr;
jclass TbEnumJniCache::javaEnumEnum1 = nullptr;
jmethodID TbEnumJniCache::javaEnumEnum1FromValueMethodId = nullptr;
jmethodID TbEnumJniCache::javaEnumEnum1GetValueMethod = nullptr;
jclass TbEnumJniCache::javaEnumEnum2 = nullptr;
jmethodID TbEnumJniCache::javaEnumEnum2FromValueMethodId = nullptr;
jmethodID TbEnumJniCache::javaEnumEnum2GetValueMethod = nullptr;
jclass TbEnumJniCache::javaEnumEnum3 = nullptr;
jmethodID TbEnumJniCache::javaEnumEnum3FromValueMethodId = nullptr;
jmethodID TbEnumJniCache::javaEnumEnum3GetValueMethod = nullptr;
jclass TbEnumJniCache::javaClassEnumInterface = nullptr;
jmethodID TbEnumJniCache::javaClassEnumInterfaceProp0SetterId = nullptr;
jmethodID TbEnumJniCache::javaClassEnumInterfaceProp0GetterId = nullptr;
jmethodID TbEnumJniCache::javaClassEnumInterfaceProp1SetterId = nullptr;
jmethodID TbEnumJniCache::javaClassEnumInterfaceProp1GetterId = nullptr;
jmethodID TbEnumJniCache::javaClassEnumInterfaceProp2SetterId = nullptr;
jmethodID TbEnumJniCache::javaClassEnumInterfaceProp2GetterId = nullptr;
jmethodID TbEnumJniCache::javaClassEnumInterfaceProp3SetterId = nullptr;
jmethodID TbEnumJniCache::javaClassEnumInterfaceProp3GetterId = nullptr;
jclass TbEnumJniCache::serviceClassEnumInterface = nullptr;
jmethodID TbEnumJniCache::serviceClassEnumInterfaceReadyMethodID = nullptr;
jmethodID TbEnumJniCache::serviceClassEnumInterfaceProp0ChangedMethodID = nullptr;
jmethodID TbEnumJniCache::serviceClassEnumInterfaceProp1ChangedMethodID = nullptr;
jmethodID TbEnumJniCache::serviceClassEnumInterfaceProp2ChangedMethodID = nullptr;
jmethodID TbEnumJniCache::serviceClassEnumInterfaceProp3ChangedMethodID = nullptr;
jmethodID TbEnumJniCache::serviceClassEnumInterfaceSig0SignalMethodID = nullptr;
jmethodID TbEnumJniCache::serviceClassEnumInterfaceSig1SignalMethodID = nullptr;
jmethodID TbEnumJniCache::serviceClassEnumInterfaceSig2SignalMethodID = nullptr;
jmethodID TbEnumJniCache::serviceClassEnumInterfaceSig3SignalMethodID = nullptr;
jclass TbEnumJniCache::clientClassEnumInterface = nullptr;
jmethodID TbEnumJniCache::clientClassEnumInterfaceCtor = nullptr;
jmethodID TbEnumJniCache::clientClassEnumInterfaceBindMethodID = nullptr;
jmethodID TbEnumJniCache::clientClassEnumInterfaceUnbindMethodID = nullptr;
jmethodID TbEnumJniCache::clientClassEnumInterfaceFunc0AsyncMethodID = nullptr;
jmethodID TbEnumJniCache::clientClassEnumInterfaceFunc1AsyncMethodID = nullptr;
jmethodID TbEnumJniCache::clientClassEnumInterfaceFunc2AsyncMethodID = nullptr;
jmethodID TbEnumJniCache::clientClassEnumInterfaceFunc3AsyncMethodID = nullptr;

bool TbEnumJniCache::m_isInitialized = false;

void TbEnumJniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	javaEnumEnum0 = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum0");
	checkException(env, "tbEnum/tbEnum_api/Enum0");
	javaEnumEnum0FromValueMethodId = env->GetStaticMethodID(TbEnumJniCache::javaEnumEnum0, "fromValue", "(I)LtbEnum/tbEnum_api/Enum0;");
	checkException(env, "fromValue (I)LtbEnum/tbEnum_api/Enum0; for tbEnum/tbEnum_api/Enum0");
	javaEnumEnum0GetValueMethod = env->GetMethodID(TbEnumJniCache::javaEnumEnum0, "getValue", "()I");
	checkException(env, "getValue (I)LtbEnum/tbEnum_api/Enum0; for tbEnum/tbEnum_api/Enum0");
	javaEnumEnum1 = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum1");
	checkException(env, "tbEnum/tbEnum_api/Enum1");
	javaEnumEnum1FromValueMethodId = env->GetStaticMethodID(TbEnumJniCache::javaEnumEnum1, "fromValue", "(I)LtbEnum/tbEnum_api/Enum1;");
	checkException(env, "fromValue (I)LtbEnum/tbEnum_api/Enum1; for tbEnum/tbEnum_api/Enum1");
	javaEnumEnum1GetValueMethod = env->GetMethodID(TbEnumJniCache::javaEnumEnum1, "getValue", "()I");
	checkException(env, "getValue (I)LtbEnum/tbEnum_api/Enum1; for tbEnum/tbEnum_api/Enum1");
	javaEnumEnum2 = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum2");
	checkException(env, "tbEnum/tbEnum_api/Enum2");
	javaEnumEnum2FromValueMethodId = env->GetStaticMethodID(TbEnumJniCache::javaEnumEnum2, "fromValue", "(I)LtbEnum/tbEnum_api/Enum2;");
	checkException(env, "fromValue (I)LtbEnum/tbEnum_api/Enum2; for tbEnum/tbEnum_api/Enum2");
	javaEnumEnum2GetValueMethod = env->GetMethodID(TbEnumJniCache::javaEnumEnum2, "getValue", "()I");
	checkException(env, "getValue (I)LtbEnum/tbEnum_api/Enum2; for tbEnum/tbEnum_api/Enum2");
	javaEnumEnum3 = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum3");
	checkException(env, "tbEnum/tbEnum_api/Enum3");
	javaEnumEnum3FromValueMethodId = env->GetStaticMethodID(TbEnumJniCache::javaEnumEnum3, "fromValue", "(I)LtbEnum/tbEnum_api/Enum3;");
	checkException(env, "fromValue (I)LtbEnum/tbEnum_api/Enum3; for tbEnum/tbEnum_api/Enum3");
	javaEnumEnum3GetValueMethod = env->GetMethodID(TbEnumJniCache::javaEnumEnum3, "getValue", "()I");
	checkException(env, "getValue (I)LtbEnum/tbEnum_api/Enum3; for tbEnum/tbEnum_api/Enum3");

	javaClassEnumInterface = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/IEnumInterface");
	checkException(env, "tbEnum/tbEnum_api/IEnumInterface");
	javaClassEnumInterfaceProp0SetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "setProp0", "(LtbEnum/tbEnum_api/Enum0;)V");
	checkException(env, "setProp0, (LtbEnum/tbEnum_api/Enum0;)V  for tbEnum/tbEnum_api/IEnumInterface");
	javaClassEnumInterfaceProp0GetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "getProp0", "()LtbEnum/tbEnum_api/Enum0;");
	checkException(env, "getProp0, ()LtbEnum/tbEnum_api/Enum0; for tbEnum/tbEnum_api/IEnumInterface");
	javaClassEnumInterfaceProp1SetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "setProp1", "(LtbEnum/tbEnum_api/Enum1;)V");
	checkException(env, "setProp1, (LtbEnum/tbEnum_api/Enum1;)V  for tbEnum/tbEnum_api/IEnumInterface");
	javaClassEnumInterfaceProp1GetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "getProp1", "()LtbEnum/tbEnum_api/Enum1;");
	checkException(env, "getProp1, ()LtbEnum/tbEnum_api/Enum1; for tbEnum/tbEnum_api/IEnumInterface");
	javaClassEnumInterfaceProp2SetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "setProp2", "(LtbEnum/tbEnum_api/Enum2;)V");
	checkException(env, "setProp2, (LtbEnum/tbEnum_api/Enum2;)V  for tbEnum/tbEnum_api/IEnumInterface");
	javaClassEnumInterfaceProp2GetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "getProp2", "()LtbEnum/tbEnum_api/Enum2;");
	checkException(env, "getProp2, ()LtbEnum/tbEnum_api/Enum2; for tbEnum/tbEnum_api/IEnumInterface");
	javaClassEnumInterfaceProp3SetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "setProp3", "(LtbEnum/tbEnum_api/Enum3;)V");
	checkException(env, "setProp3, (LtbEnum/tbEnum_api/Enum3;)V  for tbEnum/tbEnum_api/IEnumInterface");
	javaClassEnumInterfaceProp3GetterId = env->GetMethodID(TbEnumJniCache::javaClassEnumInterface, "getProp3", "()LtbEnum/tbEnum_api/Enum3;");
	checkException(env, "getProp3, ()LtbEnum/tbEnum_api/Enum3; for tbEnum/tbEnum_api/IEnumInterface");

	serviceClassEnumInterface = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnumjniservice/EnumInterfaceJniService");
	checkException(env, "tbEnum/tbEnumjniservice/EnumInterfaceJniService");
	serviceClassEnumInterfaceReadyMethodID = env->GetMethodID(TbEnumJniCache::serviceClassEnumInterface, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for tbEnum/tbEnumjniservice/EnumInterfaceJniService");
	serviceClassEnumInterfaceProp0ChangedMethodID = env->GetMethodID(TbEnumJniCache::serviceClassEnumInterface, "onProp0Changed", "(LtbEnum/tbEnum_api/Enum0;)V");
	checkException(env, "onProp0Changed, (LtbEnum/tbEnum_api/Enum0;)V for tbEnum/tbEnumjniservice/EnumInterfaceJniService");
	serviceClassEnumInterfaceProp1ChangedMethodID = env->GetMethodID(TbEnumJniCache::serviceClassEnumInterface, "onProp1Changed", "(LtbEnum/tbEnum_api/Enum1;)V");
	checkException(env, "onProp1Changed, (LtbEnum/tbEnum_api/Enum1;)V for tbEnum/tbEnumjniservice/EnumInterfaceJniService");
	serviceClassEnumInterfaceProp2ChangedMethodID = env->GetMethodID(TbEnumJniCache::serviceClassEnumInterface, "onProp2Changed", "(LtbEnum/tbEnum_api/Enum2;)V");
	checkException(env, "onProp2Changed, (LtbEnum/tbEnum_api/Enum2;)V for tbEnum/tbEnumjniservice/EnumInterfaceJniService");
	serviceClassEnumInterfaceProp3ChangedMethodID = env->GetMethodID(TbEnumJniCache::serviceClassEnumInterface, "onProp3Changed", "(LtbEnum/tbEnum_api/Enum3;)V");
	checkException(env, "onProp3Changed, (LtbEnum/tbEnum_api/Enum3;)V for tbEnum/tbEnumjniservice/EnumInterfaceJniService");
	serviceClassEnumInterfaceSig0SignalMethodID = env->GetMethodID(TbEnumJniCache::serviceClassEnumInterface, "onSig0", "(LtbEnum/tbEnum_api/Enum0;)V");
	checkException(env, "onSig0, (LtbEnum/tbEnum_api/Enum0;)V for tbEnum/tbEnumjniservice/EnumInterfaceJniService");
	serviceClassEnumInterfaceSig1SignalMethodID = env->GetMethodID(TbEnumJniCache::serviceClassEnumInterface, "onSig1", "(LtbEnum/tbEnum_api/Enum1;)V");
	checkException(env, "onSig1, (LtbEnum/tbEnum_api/Enum1;)V for tbEnum/tbEnumjniservice/EnumInterfaceJniService");
	serviceClassEnumInterfaceSig2SignalMethodID = env->GetMethodID(TbEnumJniCache::serviceClassEnumInterface, "onSig2", "(LtbEnum/tbEnum_api/Enum2;)V");
	checkException(env, "onSig2, (LtbEnum/tbEnum_api/Enum2;)V for tbEnum/tbEnumjniservice/EnumInterfaceJniService");
	serviceClassEnumInterfaceSig3SignalMethodID = env->GetMethodID(TbEnumJniCache::serviceClassEnumInterface, "onSig3", "(LtbEnum/tbEnum_api/Enum3;)V");
	checkException(env, "onSig3, (LtbEnum/tbEnum_api/Enum3;)V for tbEnum/tbEnumjniservice/EnumInterfaceJniService");
	clientClassEnumInterface = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnumjniclient/EnumInterfaceJniClient");
	checkException(env, "tbEnum/tbEnumjniclient/EnumInterfaceJniClient");
	clientClassEnumInterfaceFunc0AsyncMethodID = env->GetMethodID(TbEnumJniCache::clientClassEnumInterface, "func0Async", "(Ljava/lang/String;LtbEnum/tbEnum_api/Enum0;)V");
	checkException(env, "func0Async, (Ljava/lang/String;LtbEnum/tbEnum_api/Enum0;)V for tbEnum/tbEnumjniclient/EnumInterfaceJniClient");
	clientClassEnumInterfaceFunc1AsyncMethodID = env->GetMethodID(TbEnumJniCache::clientClassEnumInterface, "func1Async", "(Ljava/lang/String;LtbEnum/tbEnum_api/Enum1;)V");
	checkException(env, "func1Async, (Ljava/lang/String;LtbEnum/tbEnum_api/Enum1;)V for tbEnum/tbEnumjniclient/EnumInterfaceJniClient");
	clientClassEnumInterfaceFunc2AsyncMethodID = env->GetMethodID(TbEnumJniCache::clientClassEnumInterface, "func2Async", "(Ljava/lang/String;LtbEnum/tbEnum_api/Enum2;)V");
	checkException(env, "func2Async, (Ljava/lang/String;LtbEnum/tbEnum_api/Enum2;)V for tbEnum/tbEnumjniclient/EnumInterfaceJniClient");
	clientClassEnumInterfaceFunc3AsyncMethodID = env->GetMethodID(TbEnumJniCache::clientClassEnumInterface, "func3Async", "(Ljava/lang/String;LtbEnum/tbEnum_api/Enum3;)V");
	checkException(env, "func3Async, (Ljava/lang/String;LtbEnum/tbEnum_api/Enum3;)V for tbEnum/tbEnumjniclient/EnumInterfaceJniClient");
	clientClassEnumInterfaceCtor = env->GetMethodID(TbEnumJniCache::clientClassEnumInterface, "<init>", "()V");
	checkException(env, "init, ()V for tbEnum/tbEnumjniclient/EnumInterfaceJniClient");
	clientClassEnumInterfaceBindMethodID = env->GetMethodID(TbEnumJniCache::clientClassEnumInterface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for tbEnum/tbEnumjniclient/EnumInterfaceJniClient");
	clientClassEnumInterfaceUnbindMethodID = env->GetMethodID(TbEnumJniCache::clientClassEnumInterface, "unbind", "()V");
	checkException(env, "unbind, ()V for tbEnum/tbEnumjniclient/EnumInterfaceJniClient");
	m_isInitialized = true;
}

void TbEnumJniCache::clear()
{
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(javaEnumEnum0);
	javaEnumEnum0 = nullptr;
	javaEnumEnum0FromValueMethodId = nullptr;
	javaEnumEnum0GetValueMethod = nullptr;
	env->DeleteGlobalRef(javaEnumEnum1);
	javaEnumEnum1 = nullptr;
	javaEnumEnum1FromValueMethodId = nullptr;
	javaEnumEnum1GetValueMethod = nullptr;
	env->DeleteGlobalRef(javaEnumEnum2);
	javaEnumEnum2 = nullptr;
	javaEnumEnum2FromValueMethodId = nullptr;
	javaEnumEnum2GetValueMethod = nullptr;
	env->DeleteGlobalRef(javaEnumEnum3);
	javaEnumEnum3 = nullptr;
	javaEnumEnum3FromValueMethodId = nullptr;
	javaEnumEnum3GetValueMethod = nullptr;
	env->DeleteGlobalRef(javaClassEnumInterface);
	javaClassEnumInterface = nullptr;
	javaClassEnumInterfaceProp0SetterId = nullptr;
	javaClassEnumInterfaceProp0GetterId = nullptr;
	javaClassEnumInterfaceProp1SetterId = nullptr;
	javaClassEnumInterfaceProp1GetterId = nullptr;
	javaClassEnumInterfaceProp2SetterId = nullptr;
	javaClassEnumInterfaceProp2GetterId = nullptr;
	javaClassEnumInterfaceProp3SetterId = nullptr;
	javaClassEnumInterfaceProp3GetterId = nullptr;
	env->DeleteGlobalRef(serviceClassEnumInterface);
	serviceClassEnumInterface = nullptr;
	serviceClassEnumInterfaceReadyMethodID = nullptr;
	serviceClassEnumInterfaceProp0ChangedMethodID = nullptr;
	serviceClassEnumInterfaceProp1ChangedMethodID = nullptr;
	serviceClassEnumInterfaceProp2ChangedMethodID = nullptr;
	serviceClassEnumInterfaceProp3ChangedMethodID = nullptr;
	serviceClassEnumInterfaceSig0SignalMethodID = nullptr;
	serviceClassEnumInterfaceSig1SignalMethodID = nullptr;
	serviceClassEnumInterfaceSig2SignalMethodID = nullptr;
	serviceClassEnumInterfaceSig3SignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassEnumInterface);
	clientClassEnumInterface = nullptr;
	clientClassEnumInterfaceFunc0AsyncMethodID = nullptr;
	clientClassEnumInterfaceFunc1AsyncMethodID = nullptr;
	clientClassEnumInterfaceFunc2AsyncMethodID = nullptr;
	clientClassEnumInterfaceFunc3AsyncMethodID = nullptr;
	clientClassEnumInterfaceCtor = nullptr;
	clientClassEnumInterfaceBindMethodID = nullptr;
	clientClassEnumInterfaceUnbindMethodID = nullptr;
}

bool TbEnumJniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
