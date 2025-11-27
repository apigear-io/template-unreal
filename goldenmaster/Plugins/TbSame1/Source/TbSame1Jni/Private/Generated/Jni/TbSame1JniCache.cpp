
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

#include "TbSame1/Generated/Jni/TbSame1JniCache.h"
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

DEFINE_LOG_CATEGORY(LogTbSame1JniCache_JNI);

void TbSame1JniCache::checkException(JNIEnv* env, FString memberInfo)
{
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbSame1JniCache_JNI, Warning, TEXT("Could not find %s"), *memberInfo);
	}
}
jclass TbSame1JniCache::javaStructStruct1 = nullptr;
jmethodID TbSame1JniCache::javaStructStruct1Ctor = nullptr;
jfieldID TbSame1JniCache::javaStructStruct1Field1FieldId = nullptr;
jfieldID TbSame1JniCache::javaStructStruct1Field2FieldId = nullptr;
jfieldID TbSame1JniCache::javaStructStruct1Field3FieldId = nullptr;
jclass TbSame1JniCache::javaStructStruct2 = nullptr;
jmethodID TbSame1JniCache::javaStructStruct2Ctor = nullptr;
jfieldID TbSame1JniCache::javaStructStruct2Field1FieldId = nullptr;
jfieldID TbSame1JniCache::javaStructStruct2Field2FieldId = nullptr;
jfieldID TbSame1JniCache::javaStructStruct2Field3FieldId = nullptr;
jclass TbSame1JniCache::javaEnumEnum1 = nullptr;
jmethodID TbSame1JniCache::javaEnumEnum1FromValueMethodId = nullptr;
jmethodID TbSame1JniCache::javaEnumEnum1GetValueMethod = nullptr;
jclass TbSame1JniCache::javaEnumEnum2 = nullptr;
jmethodID TbSame1JniCache::javaEnumEnum2FromValueMethodId = nullptr;
jmethodID TbSame1JniCache::javaEnumEnum2GetValueMethod = nullptr;
jclass TbSame1JniCache::javaClassSameStruct1Interface = nullptr;
jmethodID TbSame1JniCache::javaClassSameStruct1InterfaceProp1SetterId = nullptr;
jmethodID TbSame1JniCache::javaClassSameStruct1InterfaceProp1GetterId = nullptr;
jclass TbSame1JniCache::serviceClassSameStruct1Interface = nullptr;
jmethodID TbSame1JniCache::serviceClassSameStruct1InterfaceReadyMethodID = nullptr;
jmethodID TbSame1JniCache::serviceClassSameStruct1InterfaceProp1ChangedMethodID = nullptr;
jmethodID TbSame1JniCache::serviceClassSameStruct1InterfaceSig1SignalMethodID = nullptr;
jclass TbSame1JniCache::clientClassSameStruct1Interface = nullptr;
jmethodID TbSame1JniCache::clientClassSameStruct1InterfaceCtor = nullptr;
jmethodID TbSame1JniCache::clientClassSameStruct1InterfaceBindMethodID = nullptr;
jmethodID TbSame1JniCache::clientClassSameStruct1InterfaceUnbindMethodID = nullptr;
jmethodID TbSame1JniCache::clientClassSameStruct1InterfaceFunc1AsyncMethodID = nullptr;
jclass TbSame1JniCache::javaClassSameStruct2Interface = nullptr;
jmethodID TbSame1JniCache::javaClassSameStruct2InterfaceProp1SetterId = nullptr;
jmethodID TbSame1JniCache::javaClassSameStruct2InterfaceProp1GetterId = nullptr;
jmethodID TbSame1JniCache::javaClassSameStruct2InterfaceProp2SetterId = nullptr;
jmethodID TbSame1JniCache::javaClassSameStruct2InterfaceProp2GetterId = nullptr;
jclass TbSame1JniCache::serviceClassSameStruct2Interface = nullptr;
jmethodID TbSame1JniCache::serviceClassSameStruct2InterfaceReadyMethodID = nullptr;
jmethodID TbSame1JniCache::serviceClassSameStruct2InterfaceProp1ChangedMethodID = nullptr;
jmethodID TbSame1JniCache::serviceClassSameStruct2InterfaceProp2ChangedMethodID = nullptr;
jmethodID TbSame1JniCache::serviceClassSameStruct2InterfaceSig1SignalMethodID = nullptr;
jmethodID TbSame1JniCache::serviceClassSameStruct2InterfaceSig2SignalMethodID = nullptr;
jclass TbSame1JniCache::clientClassSameStruct2Interface = nullptr;
jmethodID TbSame1JniCache::clientClassSameStruct2InterfaceCtor = nullptr;
jmethodID TbSame1JniCache::clientClassSameStruct2InterfaceBindMethodID = nullptr;
jmethodID TbSame1JniCache::clientClassSameStruct2InterfaceUnbindMethodID = nullptr;
jmethodID TbSame1JniCache::clientClassSameStruct2InterfaceFunc1AsyncMethodID = nullptr;
jmethodID TbSame1JniCache::clientClassSameStruct2InterfaceFunc2AsyncMethodID = nullptr;
jclass TbSame1JniCache::javaClassSameEnum1Interface = nullptr;
jmethodID TbSame1JniCache::javaClassSameEnum1InterfaceProp1SetterId = nullptr;
jmethodID TbSame1JniCache::javaClassSameEnum1InterfaceProp1GetterId = nullptr;
jclass TbSame1JniCache::serviceClassSameEnum1Interface = nullptr;
jmethodID TbSame1JniCache::serviceClassSameEnum1InterfaceReadyMethodID = nullptr;
jmethodID TbSame1JniCache::serviceClassSameEnum1InterfaceProp1ChangedMethodID = nullptr;
jmethodID TbSame1JniCache::serviceClassSameEnum1InterfaceSig1SignalMethodID = nullptr;
jclass TbSame1JniCache::clientClassSameEnum1Interface = nullptr;
jmethodID TbSame1JniCache::clientClassSameEnum1InterfaceCtor = nullptr;
jmethodID TbSame1JniCache::clientClassSameEnum1InterfaceBindMethodID = nullptr;
jmethodID TbSame1JniCache::clientClassSameEnum1InterfaceUnbindMethodID = nullptr;
jmethodID TbSame1JniCache::clientClassSameEnum1InterfaceFunc1AsyncMethodID = nullptr;
jclass TbSame1JniCache::javaClassSameEnum2Interface = nullptr;
jmethodID TbSame1JniCache::javaClassSameEnum2InterfaceProp1SetterId = nullptr;
jmethodID TbSame1JniCache::javaClassSameEnum2InterfaceProp1GetterId = nullptr;
jmethodID TbSame1JniCache::javaClassSameEnum2InterfaceProp2SetterId = nullptr;
jmethodID TbSame1JniCache::javaClassSameEnum2InterfaceProp2GetterId = nullptr;
jclass TbSame1JniCache::serviceClassSameEnum2Interface = nullptr;
jmethodID TbSame1JniCache::serviceClassSameEnum2InterfaceReadyMethodID = nullptr;
jmethodID TbSame1JniCache::serviceClassSameEnum2InterfaceProp1ChangedMethodID = nullptr;
jmethodID TbSame1JniCache::serviceClassSameEnum2InterfaceProp2ChangedMethodID = nullptr;
jmethodID TbSame1JniCache::serviceClassSameEnum2InterfaceSig1SignalMethodID = nullptr;
jmethodID TbSame1JniCache::serviceClassSameEnum2InterfaceSig2SignalMethodID = nullptr;
jclass TbSame1JniCache::clientClassSameEnum2Interface = nullptr;
jmethodID TbSame1JniCache::clientClassSameEnum2InterfaceCtor = nullptr;
jmethodID TbSame1JniCache::clientClassSameEnum2InterfaceBindMethodID = nullptr;
jmethodID TbSame1JniCache::clientClassSameEnum2InterfaceUnbindMethodID = nullptr;
jmethodID TbSame1JniCache::clientClassSameEnum2InterfaceFunc1AsyncMethodID = nullptr;
jmethodID TbSame1JniCache::clientClassSameEnum2InterfaceFunc2AsyncMethodID = nullptr;

bool TbSame1JniCache::m_isInitialized = false;

void TbSame1JniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	javaStructStruct1 = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/Struct1");
	checkException(env, "tbSame1/tbSame1_api/Struct1");
	javaStructStruct1Ctor = env->GetMethodID(TbSame1JniCache::javaStructStruct1, "<init>", "()V");
	checkException(env, "method <init>, ()V for tbSame1/tbSame1_api/Struct1");
	javaStructStruct1Field1FieldId = env->GetFieldID(TbSame1JniCache::javaStructStruct1, "field1", "I");
	checkException(env, "field1, I for tbSame1/tbSame1_api/Struct1");
	javaStructStruct1Field2FieldId = env->GetFieldID(TbSame1JniCache::javaStructStruct1, "field2", "I");
	checkException(env, "field2, I for tbSame1/tbSame1_api/Struct1");
	javaStructStruct1Field3FieldId = env->GetFieldID(TbSame1JniCache::javaStructStruct1, "field3", "I");
	checkException(env, "field3, I for tbSame1/tbSame1_api/Struct1");
	javaStructStruct2 = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/Struct2");
	checkException(env, "tbSame1/tbSame1_api/Struct2");
	javaStructStruct2Ctor = env->GetMethodID(TbSame1JniCache::javaStructStruct2, "<init>", "()V");
	checkException(env, "method <init>, ()V for tbSame1/tbSame1_api/Struct2");
	javaStructStruct2Field1FieldId = env->GetFieldID(TbSame1JniCache::javaStructStruct2, "field1", "I");
	checkException(env, "field1, I for tbSame1/tbSame1_api/Struct2");
	javaStructStruct2Field2FieldId = env->GetFieldID(TbSame1JniCache::javaStructStruct2, "field2", "I");
	checkException(env, "field2, I for tbSame1/tbSame1_api/Struct2");
	javaStructStruct2Field3FieldId = env->GetFieldID(TbSame1JniCache::javaStructStruct2, "field3", "I");
	checkException(env, "field3, I for tbSame1/tbSame1_api/Struct2");
	javaEnumEnum1 = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/Enum1");
	checkException(env, "tbSame1/tbSame1_api/Enum1");
	javaEnumEnum1FromValueMethodId = env->GetStaticMethodID(TbSame1JniCache::javaEnumEnum1, "fromValue", "(I)LtbSame1/tbSame1_api/Enum1;");
	checkException(env, "fromValue (I)LtbSame1/tbSame1_api/Enum1; for tbSame1/tbSame1_api/Enum1");
	javaEnumEnum1GetValueMethod = env->GetMethodID(TbSame1JniCache::javaEnumEnum1, "getValue", "()I");
	checkException(env, "getValue (I)LtbSame1/tbSame1_api/Enum1; for tbSame1/tbSame1_api/Enum1");
	javaEnumEnum2 = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/Enum2");
	checkException(env, "tbSame1/tbSame1_api/Enum2");
	javaEnumEnum2FromValueMethodId = env->GetStaticMethodID(TbSame1JniCache::javaEnumEnum2, "fromValue", "(I)LtbSame1/tbSame1_api/Enum2;");
	checkException(env, "fromValue (I)LtbSame1/tbSame1_api/Enum2; for tbSame1/tbSame1_api/Enum2");
	javaEnumEnum2GetValueMethod = env->GetMethodID(TbSame1JniCache::javaEnumEnum2, "getValue", "()I");
	checkException(env, "getValue (I)LtbSame1/tbSame1_api/Enum2; for tbSame1/tbSame1_api/Enum2");

	javaClassSameStruct1Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/ISameStruct1Interface");
	checkException(env, "tbSame1/tbSame1_api/ISameStruct1Interface");
	javaClassSameStruct1InterfaceProp1SetterId = env->GetMethodID(TbSame1JniCache::javaClassSameStruct1Interface, "setProp1", "(LtbSame1/tbSame1_api/Struct1;)V");
	checkException(env, "setProp1, (LtbSame1/tbSame1_api/Struct1;)V  for tbSame1/tbSame1_api/ISameStruct1Interface");
	javaClassSameStruct1InterfaceProp1GetterId = env->GetMethodID(TbSame1JniCache::javaClassSameStruct1Interface, "getProp1", "()LtbSame1/tbSame1_api/Struct1;");
	checkException(env, "getProp1, ()LtbSame1/tbSame1_api/Struct1; for tbSame1/tbSame1_api/ISameStruct1Interface");

	serviceClassSameStruct1Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1jniservice/SameStruct1InterfaceJniService");
	checkException(env, "tbSame1/tbSame1jniservice/SameStruct1InterfaceJniService");
	serviceClassSameStruct1InterfaceReadyMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameStruct1Interface, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for tbSame1/tbSame1jniservice/SameStruct1InterfaceJniService");
	serviceClassSameStruct1InterfaceProp1ChangedMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameStruct1Interface, "onProp1Changed", "(LtbSame1/tbSame1_api/Struct1;)V");
	checkException(env, "onProp1Changed, (LtbSame1/tbSame1_api/Struct1;)V for tbSame1/tbSame1jniservice/SameStruct1InterfaceJniService");
	serviceClassSameStruct1InterfaceSig1SignalMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameStruct1Interface, "onSig1", "(LtbSame1/tbSame1_api/Struct1;)V");
	checkException(env, "onSig1, (LtbSame1/tbSame1_api/Struct1;)V for tbSame1/tbSame1jniservice/SameStruct1InterfaceJniService");
	clientClassSameStruct1Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1jniclient/SameStruct1InterfaceJniClient");
	checkException(env, "tbSame1/tbSame1jniclient/SameStruct1InterfaceJniClient");
	clientClassSameStruct1InterfaceFunc1AsyncMethodID = env->GetMethodID(TbSame1JniCache::clientClassSameStruct1Interface, "func1Async", "(Ljava/lang/String;LtbSame1/tbSame1_api/Struct1;)V");
	checkException(env, "func1Async, (Ljava/lang/String;LtbSame1/tbSame1_api/Struct1;)V for tbSame1/tbSame1jniclient/SameStruct1InterfaceJniClient");
	clientClassSameStruct1InterfaceCtor = env->GetMethodID(TbSame1JniCache::clientClassSameStruct1Interface, "<init>", "()V");
	checkException(env, "init, ()V for tbSame1/tbSame1jniclient/SameStruct1InterfaceJniClient");
	clientClassSameStruct1InterfaceBindMethodID = env->GetMethodID(TbSame1JniCache::clientClassSameStruct1Interface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for tbSame1/tbSame1jniclient/SameStruct1InterfaceJniClient");
	clientClassSameStruct1InterfaceUnbindMethodID = env->GetMethodID(TbSame1JniCache::clientClassSameStruct1Interface, "unbind", "()V");
	checkException(env, "unbind, ()V for tbSame1/tbSame1jniclient/SameStruct1InterfaceJniClient");

	javaClassSameStruct2Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/ISameStruct2Interface");
	checkException(env, "tbSame1/tbSame1_api/ISameStruct2Interface");
	javaClassSameStruct2InterfaceProp1SetterId = env->GetMethodID(TbSame1JniCache::javaClassSameStruct2Interface, "setProp1", "(LtbSame1/tbSame1_api/Struct2;)V");
	checkException(env, "setProp1, (LtbSame1/tbSame1_api/Struct2;)V  for tbSame1/tbSame1_api/ISameStruct2Interface");
	javaClassSameStruct2InterfaceProp1GetterId = env->GetMethodID(TbSame1JniCache::javaClassSameStruct2Interface, "getProp1", "()LtbSame1/tbSame1_api/Struct2;");
	checkException(env, "getProp1, ()LtbSame1/tbSame1_api/Struct2; for tbSame1/tbSame1_api/ISameStruct2Interface");
	javaClassSameStruct2InterfaceProp2SetterId = env->GetMethodID(TbSame1JniCache::javaClassSameStruct2Interface, "setProp2", "(LtbSame1/tbSame1_api/Struct2;)V");
	checkException(env, "setProp2, (LtbSame1/tbSame1_api/Struct2;)V  for tbSame1/tbSame1_api/ISameStruct2Interface");
	javaClassSameStruct2InterfaceProp2GetterId = env->GetMethodID(TbSame1JniCache::javaClassSameStruct2Interface, "getProp2", "()LtbSame1/tbSame1_api/Struct2;");
	checkException(env, "getProp2, ()LtbSame1/tbSame1_api/Struct2; for tbSame1/tbSame1_api/ISameStruct2Interface");

	serviceClassSameStruct2Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1jniservice/SameStruct2InterfaceJniService");
	checkException(env, "tbSame1/tbSame1jniservice/SameStruct2InterfaceJniService");
	serviceClassSameStruct2InterfaceReadyMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameStruct2Interface, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for tbSame1/tbSame1jniservice/SameStruct2InterfaceJniService");
	serviceClassSameStruct2InterfaceProp1ChangedMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameStruct2Interface, "onProp1Changed", "(LtbSame1/tbSame1_api/Struct2;)V");
	checkException(env, "onProp1Changed, (LtbSame1/tbSame1_api/Struct2;)V for tbSame1/tbSame1jniservice/SameStruct2InterfaceJniService");
	serviceClassSameStruct2InterfaceProp2ChangedMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameStruct2Interface, "onProp2Changed", "(LtbSame1/tbSame1_api/Struct2;)V");
	checkException(env, "onProp2Changed, (LtbSame1/tbSame1_api/Struct2;)V for tbSame1/tbSame1jniservice/SameStruct2InterfaceJniService");
	serviceClassSameStruct2InterfaceSig1SignalMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameStruct2Interface, "onSig1", "(LtbSame1/tbSame1_api/Struct1;)V");
	checkException(env, "onSig1, (LtbSame1/tbSame1_api/Struct1;)V for tbSame1/tbSame1jniservice/SameStruct2InterfaceJniService");
	serviceClassSameStruct2InterfaceSig2SignalMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameStruct2Interface, "onSig2", "(LtbSame1/tbSame1_api/Struct1;LtbSame1/tbSame1_api/Struct2;)V");
	checkException(env, "onSig2, (LtbSame1/tbSame1_api/Struct1;LtbSame1/tbSame1_api/Struct2;)V for tbSame1/tbSame1jniservice/SameStruct2InterfaceJniService");
	clientClassSameStruct2Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1jniclient/SameStruct2InterfaceJniClient");
	checkException(env, "tbSame1/tbSame1jniclient/SameStruct2InterfaceJniClient");
	clientClassSameStruct2InterfaceFunc1AsyncMethodID = env->GetMethodID(TbSame1JniCache::clientClassSameStruct2Interface, "func1Async", "(Ljava/lang/String;LtbSame1/tbSame1_api/Struct1;)V");
	checkException(env, "func1Async, (Ljava/lang/String;LtbSame1/tbSame1_api/Struct1;)V for tbSame1/tbSame1jniclient/SameStruct2InterfaceJniClient");
	clientClassSameStruct2InterfaceFunc2AsyncMethodID = env->GetMethodID(TbSame1JniCache::clientClassSameStruct2Interface, "func2Async", "(Ljava/lang/String;LtbSame1/tbSame1_api/Struct1;LtbSame1/tbSame1_api/Struct2;)V");
	checkException(env, "func2Async, (Ljava/lang/String;LtbSame1/tbSame1_api/Struct1;LtbSame1/tbSame1_api/Struct2;)V for tbSame1/tbSame1jniclient/SameStruct2InterfaceJniClient");
	clientClassSameStruct2InterfaceCtor = env->GetMethodID(TbSame1JniCache::clientClassSameStruct2Interface, "<init>", "()V");
	checkException(env, "init, ()V for tbSame1/tbSame1jniclient/SameStruct2InterfaceJniClient");
	clientClassSameStruct2InterfaceBindMethodID = env->GetMethodID(TbSame1JniCache::clientClassSameStruct2Interface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for tbSame1/tbSame1jniclient/SameStruct2InterfaceJniClient");
	clientClassSameStruct2InterfaceUnbindMethodID = env->GetMethodID(TbSame1JniCache::clientClassSameStruct2Interface, "unbind", "()V");
	checkException(env, "unbind, ()V for tbSame1/tbSame1jniclient/SameStruct2InterfaceJniClient");

	javaClassSameEnum1Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/ISameEnum1Interface");
	checkException(env, "tbSame1/tbSame1_api/ISameEnum1Interface");
	javaClassSameEnum1InterfaceProp1SetterId = env->GetMethodID(TbSame1JniCache::javaClassSameEnum1Interface, "setProp1", "(LtbSame1/tbSame1_api/Enum1;)V");
	checkException(env, "setProp1, (LtbSame1/tbSame1_api/Enum1;)V  for tbSame1/tbSame1_api/ISameEnum1Interface");
	javaClassSameEnum1InterfaceProp1GetterId = env->GetMethodID(TbSame1JniCache::javaClassSameEnum1Interface, "getProp1", "()LtbSame1/tbSame1_api/Enum1;");
	checkException(env, "getProp1, ()LtbSame1/tbSame1_api/Enum1; for tbSame1/tbSame1_api/ISameEnum1Interface");

	serviceClassSameEnum1Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1jniservice/SameEnum1InterfaceJniService");
	checkException(env, "tbSame1/tbSame1jniservice/SameEnum1InterfaceJniService");
	serviceClassSameEnum1InterfaceReadyMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameEnum1Interface, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for tbSame1/tbSame1jniservice/SameEnum1InterfaceJniService");
	serviceClassSameEnum1InterfaceProp1ChangedMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameEnum1Interface, "onProp1Changed", "(LtbSame1/tbSame1_api/Enum1;)V");
	checkException(env, "onProp1Changed, (LtbSame1/tbSame1_api/Enum1;)V for tbSame1/tbSame1jniservice/SameEnum1InterfaceJniService");
	serviceClassSameEnum1InterfaceSig1SignalMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameEnum1Interface, "onSig1", "(LtbSame1/tbSame1_api/Enum1;)V");
	checkException(env, "onSig1, (LtbSame1/tbSame1_api/Enum1;)V for tbSame1/tbSame1jniservice/SameEnum1InterfaceJniService");
	clientClassSameEnum1Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1jniclient/SameEnum1InterfaceJniClient");
	checkException(env, "tbSame1/tbSame1jniclient/SameEnum1InterfaceJniClient");
	clientClassSameEnum1InterfaceFunc1AsyncMethodID = env->GetMethodID(TbSame1JniCache::clientClassSameEnum1Interface, "func1Async", "(Ljava/lang/String;LtbSame1/tbSame1_api/Enum1;)V");
	checkException(env, "func1Async, (Ljava/lang/String;LtbSame1/tbSame1_api/Enum1;)V for tbSame1/tbSame1jniclient/SameEnum1InterfaceJniClient");
	clientClassSameEnum1InterfaceCtor = env->GetMethodID(TbSame1JniCache::clientClassSameEnum1Interface, "<init>", "()V");
	checkException(env, "init, ()V for tbSame1/tbSame1jniclient/SameEnum1InterfaceJniClient");
	clientClassSameEnum1InterfaceBindMethodID = env->GetMethodID(TbSame1JniCache::clientClassSameEnum1Interface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for tbSame1/tbSame1jniclient/SameEnum1InterfaceJniClient");
	clientClassSameEnum1InterfaceUnbindMethodID = env->GetMethodID(TbSame1JniCache::clientClassSameEnum1Interface, "unbind", "()V");
	checkException(env, "unbind, ()V for tbSame1/tbSame1jniclient/SameEnum1InterfaceJniClient");

	javaClassSameEnum2Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/ISameEnum2Interface");
	checkException(env, "tbSame1/tbSame1_api/ISameEnum2Interface");
	javaClassSameEnum2InterfaceProp1SetterId = env->GetMethodID(TbSame1JniCache::javaClassSameEnum2Interface, "setProp1", "(LtbSame1/tbSame1_api/Enum1;)V");
	checkException(env, "setProp1, (LtbSame1/tbSame1_api/Enum1;)V  for tbSame1/tbSame1_api/ISameEnum2Interface");
	javaClassSameEnum2InterfaceProp1GetterId = env->GetMethodID(TbSame1JniCache::javaClassSameEnum2Interface, "getProp1", "()LtbSame1/tbSame1_api/Enum1;");
	checkException(env, "getProp1, ()LtbSame1/tbSame1_api/Enum1; for tbSame1/tbSame1_api/ISameEnum2Interface");
	javaClassSameEnum2InterfaceProp2SetterId = env->GetMethodID(TbSame1JniCache::javaClassSameEnum2Interface, "setProp2", "(LtbSame1/tbSame1_api/Enum2;)V");
	checkException(env, "setProp2, (LtbSame1/tbSame1_api/Enum2;)V  for tbSame1/tbSame1_api/ISameEnum2Interface");
	javaClassSameEnum2InterfaceProp2GetterId = env->GetMethodID(TbSame1JniCache::javaClassSameEnum2Interface, "getProp2", "()LtbSame1/tbSame1_api/Enum2;");
	checkException(env, "getProp2, ()LtbSame1/tbSame1_api/Enum2; for tbSame1/tbSame1_api/ISameEnum2Interface");

	serviceClassSameEnum2Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1jniservice/SameEnum2InterfaceJniService");
	checkException(env, "tbSame1/tbSame1jniservice/SameEnum2InterfaceJniService");
	serviceClassSameEnum2InterfaceReadyMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameEnum2Interface, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for tbSame1/tbSame1jniservice/SameEnum2InterfaceJniService");
	serviceClassSameEnum2InterfaceProp1ChangedMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameEnum2Interface, "onProp1Changed", "(LtbSame1/tbSame1_api/Enum1;)V");
	checkException(env, "onProp1Changed, (LtbSame1/tbSame1_api/Enum1;)V for tbSame1/tbSame1jniservice/SameEnum2InterfaceJniService");
	serviceClassSameEnum2InterfaceProp2ChangedMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameEnum2Interface, "onProp2Changed", "(LtbSame1/tbSame1_api/Enum2;)V");
	checkException(env, "onProp2Changed, (LtbSame1/tbSame1_api/Enum2;)V for tbSame1/tbSame1jniservice/SameEnum2InterfaceJniService");
	serviceClassSameEnum2InterfaceSig1SignalMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameEnum2Interface, "onSig1", "(LtbSame1/tbSame1_api/Enum1;)V");
	checkException(env, "onSig1, (LtbSame1/tbSame1_api/Enum1;)V for tbSame1/tbSame1jniservice/SameEnum2InterfaceJniService");
	serviceClassSameEnum2InterfaceSig2SignalMethodID = env->GetMethodID(TbSame1JniCache::serviceClassSameEnum2Interface, "onSig2", "(LtbSame1/tbSame1_api/Enum1;LtbSame1/tbSame1_api/Enum2;)V");
	checkException(env, "onSig2, (LtbSame1/tbSame1_api/Enum1;LtbSame1/tbSame1_api/Enum2;)V for tbSame1/tbSame1jniservice/SameEnum2InterfaceJniService");
	clientClassSameEnum2Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1jniclient/SameEnum2InterfaceJniClient");
	checkException(env, "tbSame1/tbSame1jniclient/SameEnum2InterfaceJniClient");
	clientClassSameEnum2InterfaceFunc1AsyncMethodID = env->GetMethodID(TbSame1JniCache::clientClassSameEnum2Interface, "func1Async", "(Ljava/lang/String;LtbSame1/tbSame1_api/Enum1;)V");
	checkException(env, "func1Async, (Ljava/lang/String;LtbSame1/tbSame1_api/Enum1;)V for tbSame1/tbSame1jniclient/SameEnum2InterfaceJniClient");
	clientClassSameEnum2InterfaceFunc2AsyncMethodID = env->GetMethodID(TbSame1JniCache::clientClassSameEnum2Interface, "func2Async", "(Ljava/lang/String;LtbSame1/tbSame1_api/Enum1;LtbSame1/tbSame1_api/Enum2;)V");
	checkException(env, "func2Async, (Ljava/lang/String;LtbSame1/tbSame1_api/Enum1;LtbSame1/tbSame1_api/Enum2;)V for tbSame1/tbSame1jniclient/SameEnum2InterfaceJniClient");
	clientClassSameEnum2InterfaceCtor = env->GetMethodID(TbSame1JniCache::clientClassSameEnum2Interface, "<init>", "()V");
	checkException(env, "init, ()V for tbSame1/tbSame1jniclient/SameEnum2InterfaceJniClient");
	clientClassSameEnum2InterfaceBindMethodID = env->GetMethodID(TbSame1JniCache::clientClassSameEnum2Interface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for tbSame1/tbSame1jniclient/SameEnum2InterfaceJniClient");
	clientClassSameEnum2InterfaceUnbindMethodID = env->GetMethodID(TbSame1JniCache::clientClassSameEnum2Interface, "unbind", "()V");
	checkException(env, "unbind, ()V for tbSame1/tbSame1jniclient/SameEnum2InterfaceJniClient");
	m_isInitialized = true;
}

void TbSame1JniCache::clear()
{
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(javaStructStruct1);
	javaStructStruct1 = nullptr;
	javaStructStruct1Ctor = nullptr;
	javaStructStruct1Field1FieldId = nullptr;
	javaStructStruct1Field2FieldId = nullptr;
	javaStructStruct1Field3FieldId = nullptr;
	env->DeleteGlobalRef(javaStructStruct2);
	javaStructStruct2 = nullptr;
	javaStructStruct2Ctor = nullptr;
	javaStructStruct2Field1FieldId = nullptr;
	javaStructStruct2Field2FieldId = nullptr;
	javaStructStruct2Field3FieldId = nullptr;
	env->DeleteGlobalRef(javaEnumEnum1);
	javaEnumEnum1 = nullptr;
	javaEnumEnum1FromValueMethodId = nullptr;
	javaEnumEnum1GetValueMethod = nullptr;
	env->DeleteGlobalRef(javaEnumEnum2);
	javaEnumEnum2 = nullptr;
	javaEnumEnum2FromValueMethodId = nullptr;
	javaEnumEnum2GetValueMethod = nullptr;
	env->DeleteGlobalRef(javaClassSameStruct1Interface);
	javaClassSameStruct1Interface = nullptr;
	javaClassSameStruct1InterfaceProp1SetterId = nullptr;
	javaClassSameStruct1InterfaceProp1GetterId = nullptr;
	env->DeleteGlobalRef(serviceClassSameStruct1Interface);
	serviceClassSameStruct1Interface = nullptr;
	serviceClassSameStruct1InterfaceReadyMethodID = nullptr;
	serviceClassSameStruct1InterfaceProp1ChangedMethodID = nullptr;
	serviceClassSameStruct1InterfaceSig1SignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassSameStruct1Interface);
	clientClassSameStruct1Interface = nullptr;
	clientClassSameStruct1InterfaceFunc1AsyncMethodID = nullptr;
	clientClassSameStruct1InterfaceCtor = nullptr;
	clientClassSameStruct1InterfaceBindMethodID = nullptr;
	clientClassSameStruct1InterfaceUnbindMethodID = nullptr;
	env->DeleteGlobalRef(javaClassSameStruct2Interface);
	javaClassSameStruct2Interface = nullptr;
	javaClassSameStruct2InterfaceProp1SetterId = nullptr;
	javaClassSameStruct2InterfaceProp1GetterId = nullptr;
	javaClassSameStruct2InterfaceProp2SetterId = nullptr;
	javaClassSameStruct2InterfaceProp2GetterId = nullptr;
	env->DeleteGlobalRef(serviceClassSameStruct2Interface);
	serviceClassSameStruct2Interface = nullptr;
	serviceClassSameStruct2InterfaceReadyMethodID = nullptr;
	serviceClassSameStruct2InterfaceProp1ChangedMethodID = nullptr;
	serviceClassSameStruct2InterfaceProp2ChangedMethodID = nullptr;
	serviceClassSameStruct2InterfaceSig1SignalMethodID = nullptr;
	serviceClassSameStruct2InterfaceSig2SignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassSameStruct2Interface);
	clientClassSameStruct2Interface = nullptr;
	clientClassSameStruct2InterfaceFunc1AsyncMethodID = nullptr;
	clientClassSameStruct2InterfaceFunc2AsyncMethodID = nullptr;
	clientClassSameStruct2InterfaceCtor = nullptr;
	clientClassSameStruct2InterfaceBindMethodID = nullptr;
	clientClassSameStruct2InterfaceUnbindMethodID = nullptr;
	env->DeleteGlobalRef(javaClassSameEnum1Interface);
	javaClassSameEnum1Interface = nullptr;
	javaClassSameEnum1InterfaceProp1SetterId = nullptr;
	javaClassSameEnum1InterfaceProp1GetterId = nullptr;
	env->DeleteGlobalRef(serviceClassSameEnum1Interface);
	serviceClassSameEnum1Interface = nullptr;
	serviceClassSameEnum1InterfaceReadyMethodID = nullptr;
	serviceClassSameEnum1InterfaceProp1ChangedMethodID = nullptr;
	serviceClassSameEnum1InterfaceSig1SignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassSameEnum1Interface);
	clientClassSameEnum1Interface = nullptr;
	clientClassSameEnum1InterfaceFunc1AsyncMethodID = nullptr;
	clientClassSameEnum1InterfaceCtor = nullptr;
	clientClassSameEnum1InterfaceBindMethodID = nullptr;
	clientClassSameEnum1InterfaceUnbindMethodID = nullptr;
	env->DeleteGlobalRef(javaClassSameEnum2Interface);
	javaClassSameEnum2Interface = nullptr;
	javaClassSameEnum2InterfaceProp1SetterId = nullptr;
	javaClassSameEnum2InterfaceProp1GetterId = nullptr;
	javaClassSameEnum2InterfaceProp2SetterId = nullptr;
	javaClassSameEnum2InterfaceProp2GetterId = nullptr;
	env->DeleteGlobalRef(serviceClassSameEnum2Interface);
	serviceClassSameEnum2Interface = nullptr;
	serviceClassSameEnum2InterfaceReadyMethodID = nullptr;
	serviceClassSameEnum2InterfaceProp1ChangedMethodID = nullptr;
	serviceClassSameEnum2InterfaceProp2ChangedMethodID = nullptr;
	serviceClassSameEnum2InterfaceSig1SignalMethodID = nullptr;
	serviceClassSameEnum2InterfaceSig2SignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassSameEnum2Interface);
	clientClassSameEnum2Interface = nullptr;
	clientClassSameEnum2InterfaceFunc1AsyncMethodID = nullptr;
	clientClassSameEnum2InterfaceFunc2AsyncMethodID = nullptr;
	clientClassSameEnum2InterfaceCtor = nullptr;
	clientClassSameEnum2InterfaceBindMethodID = nullptr;
	clientClassSameEnum2InterfaceUnbindMethodID = nullptr;
}

bool TbSame1JniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
