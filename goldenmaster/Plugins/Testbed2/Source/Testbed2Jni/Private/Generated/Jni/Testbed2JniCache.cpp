
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

#include "Testbed2/Generated/Jni/Testbed2JniCache.h"
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

DEFINE_LOG_CATEGORY(LogTestbed2JniCache_JNI);

void Testbed2JniCache::checkException(JNIEnv* env, FString memberInfo)
{
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTestbed2JniCache_JNI, Warning, TEXT("Could not find %s"), *memberInfo);
	}
}
jclass Testbed2JniCache::javaStructStruct1 = nullptr;
jmethodID Testbed2JniCache::javaStructStruct1Ctor = nullptr;
jfieldID Testbed2JniCache::javaStructStruct1Field1FieldId = nullptr;
jclass Testbed2JniCache::javaStructStruct2 = nullptr;
jmethodID Testbed2JniCache::javaStructStruct2Ctor = nullptr;
jfieldID Testbed2JniCache::javaStructStruct2Field1FieldId = nullptr;
jfieldID Testbed2JniCache::javaStructStruct2Field2FieldId = nullptr;
jclass Testbed2JniCache::javaStructStruct3 = nullptr;
jmethodID Testbed2JniCache::javaStructStruct3Ctor = nullptr;
jfieldID Testbed2JniCache::javaStructStruct3Field1FieldId = nullptr;
jfieldID Testbed2JniCache::javaStructStruct3Field2FieldId = nullptr;
jfieldID Testbed2JniCache::javaStructStruct3Field3FieldId = nullptr;
jclass Testbed2JniCache::javaStructStruct4 = nullptr;
jmethodID Testbed2JniCache::javaStructStruct4Ctor = nullptr;
jfieldID Testbed2JniCache::javaStructStruct4Field1FieldId = nullptr;
jfieldID Testbed2JniCache::javaStructStruct4Field2FieldId = nullptr;
jfieldID Testbed2JniCache::javaStructStruct4Field3FieldId = nullptr;
jfieldID Testbed2JniCache::javaStructStruct4Field4FieldId = nullptr;
jclass Testbed2JniCache::javaStructNestedStruct1 = nullptr;
jmethodID Testbed2JniCache::javaStructNestedStruct1Ctor = nullptr;
jfieldID Testbed2JniCache::javaStructNestedStruct1Field1FieldId = nullptr;
jclass Testbed2JniCache::javaStructNestedStruct2 = nullptr;
jmethodID Testbed2JniCache::javaStructNestedStruct2Ctor = nullptr;
jfieldID Testbed2JniCache::javaStructNestedStruct2Field1FieldId = nullptr;
jfieldID Testbed2JniCache::javaStructNestedStruct2Field2FieldId = nullptr;
jclass Testbed2JniCache::javaStructNestedStruct3 = nullptr;
jmethodID Testbed2JniCache::javaStructNestedStruct3Ctor = nullptr;
jfieldID Testbed2JniCache::javaStructNestedStruct3Field1FieldId = nullptr;
jfieldID Testbed2JniCache::javaStructNestedStruct3Field2FieldId = nullptr;
jfieldID Testbed2JniCache::javaStructNestedStruct3Field3FieldId = nullptr;
jclass Testbed2JniCache::javaEnumEnum1 = nullptr;
jmethodID Testbed2JniCache::javaEnumEnum1FromValueMethodId = nullptr;
jmethodID Testbed2JniCache::javaEnumEnum1GetValueMethod = nullptr;
jclass Testbed2JniCache::javaEnumEnum2 = nullptr;
jmethodID Testbed2JniCache::javaEnumEnum2FromValueMethodId = nullptr;
jmethodID Testbed2JniCache::javaEnumEnum2GetValueMethod = nullptr;
jclass Testbed2JniCache::javaEnumEnum3 = nullptr;
jmethodID Testbed2JniCache::javaEnumEnum3FromValueMethodId = nullptr;
jmethodID Testbed2JniCache::javaEnumEnum3GetValueMethod = nullptr;
jclass Testbed2JniCache::javaClassManyParamInterface = nullptr;
jmethodID Testbed2JniCache::javaClassManyParamInterfaceProp1SetterId = nullptr;
jmethodID Testbed2JniCache::javaClassManyParamInterfaceProp1GetterId = nullptr;
jmethodID Testbed2JniCache::javaClassManyParamInterfaceProp2SetterId = nullptr;
jmethodID Testbed2JniCache::javaClassManyParamInterfaceProp2GetterId = nullptr;
jmethodID Testbed2JniCache::javaClassManyParamInterfaceProp3SetterId = nullptr;
jmethodID Testbed2JniCache::javaClassManyParamInterfaceProp3GetterId = nullptr;
jmethodID Testbed2JniCache::javaClassManyParamInterfaceProp4SetterId = nullptr;
jmethodID Testbed2JniCache::javaClassManyParamInterfaceProp4GetterId = nullptr;
jclass Testbed2JniCache::serviceClassManyParamInterface = nullptr;
jmethodID Testbed2JniCache::serviceClassManyParamInterfaceReadyMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassManyParamInterfaceProp1ChangedMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassManyParamInterfaceProp2ChangedMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassManyParamInterfaceProp3ChangedMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassManyParamInterfaceProp4ChangedMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassManyParamInterfaceSig1SignalMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassManyParamInterfaceSig2SignalMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassManyParamInterfaceSig3SignalMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassManyParamInterfaceSig4SignalMethodID = nullptr;
jclass Testbed2JniCache::clientClassManyParamInterface = nullptr;
jmethodID Testbed2JniCache::clientClassManyParamInterfaceCtor = nullptr;
jmethodID Testbed2JniCache::clientClassManyParamInterfaceBindMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassManyParamInterfaceUnbindMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassManyParamInterfaceFunc1AsyncMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassManyParamInterfaceFunc2AsyncMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassManyParamInterfaceFunc3AsyncMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassManyParamInterfaceFunc4AsyncMethodID = nullptr;
jclass Testbed2JniCache::javaClassNestedStruct1Interface = nullptr;
jmethodID Testbed2JniCache::javaClassNestedStruct1InterfaceProp1SetterId = nullptr;
jmethodID Testbed2JniCache::javaClassNestedStruct1InterfaceProp1GetterId = nullptr;
jclass Testbed2JniCache::serviceClassNestedStruct1Interface = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct1InterfaceReadyMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct1InterfaceProp1ChangedMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct1InterfaceSig1SignalMethodID = nullptr;
jclass Testbed2JniCache::clientClassNestedStruct1Interface = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct1InterfaceCtor = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct1InterfaceBindMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct1InterfaceUnbindMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct1InterfaceFuncNoReturnValueAsyncMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct1InterfaceFuncNoParamsAsyncMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct1InterfaceFunc1AsyncMethodID = nullptr;
jclass Testbed2JniCache::javaClassNestedStruct2Interface = nullptr;
jmethodID Testbed2JniCache::javaClassNestedStruct2InterfaceProp1SetterId = nullptr;
jmethodID Testbed2JniCache::javaClassNestedStruct2InterfaceProp1GetterId = nullptr;
jmethodID Testbed2JniCache::javaClassNestedStruct2InterfaceProp2SetterId = nullptr;
jmethodID Testbed2JniCache::javaClassNestedStruct2InterfaceProp2GetterId = nullptr;
jclass Testbed2JniCache::serviceClassNestedStruct2Interface = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct2InterfaceReadyMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct2InterfaceProp1ChangedMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct2InterfaceProp2ChangedMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct2InterfaceSig1SignalMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct2InterfaceSig2SignalMethodID = nullptr;
jclass Testbed2JniCache::clientClassNestedStruct2Interface = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct2InterfaceCtor = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct2InterfaceBindMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct2InterfaceUnbindMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct2InterfaceFunc1AsyncMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct2InterfaceFunc2AsyncMethodID = nullptr;
jclass Testbed2JniCache::javaClassNestedStruct3Interface = nullptr;
jmethodID Testbed2JniCache::javaClassNestedStruct3InterfaceProp1SetterId = nullptr;
jmethodID Testbed2JniCache::javaClassNestedStruct3InterfaceProp1GetterId = nullptr;
jmethodID Testbed2JniCache::javaClassNestedStruct3InterfaceProp2SetterId = nullptr;
jmethodID Testbed2JniCache::javaClassNestedStruct3InterfaceProp2GetterId = nullptr;
jmethodID Testbed2JniCache::javaClassNestedStruct3InterfaceProp3SetterId = nullptr;
jmethodID Testbed2JniCache::javaClassNestedStruct3InterfaceProp3GetterId = nullptr;
jclass Testbed2JniCache::serviceClassNestedStruct3Interface = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct3InterfaceReadyMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct3InterfaceProp1ChangedMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct3InterfaceProp2ChangedMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct3InterfaceProp3ChangedMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct3InterfaceSig1SignalMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct3InterfaceSig2SignalMethodID = nullptr;
jmethodID Testbed2JniCache::serviceClassNestedStruct3InterfaceSig3SignalMethodID = nullptr;
jclass Testbed2JniCache::clientClassNestedStruct3Interface = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct3InterfaceCtor = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct3InterfaceBindMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct3InterfaceUnbindMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct3InterfaceFunc1AsyncMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct3InterfaceFunc2AsyncMethodID = nullptr;
jmethodID Testbed2JniCache::clientClassNestedStruct3InterfaceFunc3AsyncMethodID = nullptr;

bool Testbed2JniCache::m_isInitialized = false;

void Testbed2JniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	javaStructStruct1 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct1");
	checkException(env, "testbed2/testbed2_api/Struct1");
	javaStructStruct1Ctor = env->GetMethodID(Testbed2JniCache::javaStructStruct1, "<init>", "()V");
	checkException(env, "method <init>, ()V for testbed2/testbed2_api/Struct1");
	javaStructStruct1Field1FieldId = env->GetFieldID(Testbed2JniCache::javaStructStruct1, "field1", "I");
	checkException(env, "field1, I for testbed2/testbed2_api/Struct1");
	javaStructStruct2 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct2");
	checkException(env, "testbed2/testbed2_api/Struct2");
	javaStructStruct2Ctor = env->GetMethodID(Testbed2JniCache::javaStructStruct2, "<init>", "()V");
	checkException(env, "method <init>, ()V for testbed2/testbed2_api/Struct2");
	javaStructStruct2Field1FieldId = env->GetFieldID(Testbed2JniCache::javaStructStruct2, "field1", "I");
	checkException(env, "field1, I for testbed2/testbed2_api/Struct2");
	javaStructStruct2Field2FieldId = env->GetFieldID(Testbed2JniCache::javaStructStruct2, "field2", "I");
	checkException(env, "field2, I for testbed2/testbed2_api/Struct2");
	javaStructStruct3 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct3");
	checkException(env, "testbed2/testbed2_api/Struct3");
	javaStructStruct3Ctor = env->GetMethodID(Testbed2JniCache::javaStructStruct3, "<init>", "()V");
	checkException(env, "method <init>, ()V for testbed2/testbed2_api/Struct3");
	javaStructStruct3Field1FieldId = env->GetFieldID(Testbed2JniCache::javaStructStruct3, "field1", "I");
	checkException(env, "field1, I for testbed2/testbed2_api/Struct3");
	javaStructStruct3Field2FieldId = env->GetFieldID(Testbed2JniCache::javaStructStruct3, "field2", "I");
	checkException(env, "field2, I for testbed2/testbed2_api/Struct3");
	javaStructStruct3Field3FieldId = env->GetFieldID(Testbed2JniCache::javaStructStruct3, "field3", "I");
	checkException(env, "field3, I for testbed2/testbed2_api/Struct3");
	javaStructStruct4 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct4");
	checkException(env, "testbed2/testbed2_api/Struct4");
	javaStructStruct4Ctor = env->GetMethodID(Testbed2JniCache::javaStructStruct4, "<init>", "()V");
	checkException(env, "method <init>, ()V for testbed2/testbed2_api/Struct4");
	javaStructStruct4Field1FieldId = env->GetFieldID(Testbed2JniCache::javaStructStruct4, "field1", "I");
	checkException(env, "field1, I for testbed2/testbed2_api/Struct4");
	javaStructStruct4Field2FieldId = env->GetFieldID(Testbed2JniCache::javaStructStruct4, "field2", "I");
	checkException(env, "field2, I for testbed2/testbed2_api/Struct4");
	javaStructStruct4Field3FieldId = env->GetFieldID(Testbed2JniCache::javaStructStruct4, "field3", "I");
	checkException(env, "field3, I for testbed2/testbed2_api/Struct4");
	javaStructStruct4Field4FieldId = env->GetFieldID(Testbed2JniCache::javaStructStruct4, "field4", "I");
	checkException(env, "field4, I for testbed2/testbed2_api/Struct4");
	javaStructNestedStruct1 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/NestedStruct1");
	checkException(env, "testbed2/testbed2_api/NestedStruct1");
	javaStructNestedStruct1Ctor = env->GetMethodID(Testbed2JniCache::javaStructNestedStruct1, "<init>", "()V");
	checkException(env, "method <init>, ()V for testbed2/testbed2_api/NestedStruct1");
	javaStructNestedStruct1Field1FieldId = env->GetFieldID(Testbed2JniCache::javaStructNestedStruct1, "field1", "Ltestbed2/testbed2_api/Struct1;");
	checkException(env, "field1, Ltestbed2/testbed2_api/Struct1; for testbed2/testbed2_api/NestedStruct1");
	javaStructNestedStruct2 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/NestedStruct2");
	checkException(env, "testbed2/testbed2_api/NestedStruct2");
	javaStructNestedStruct2Ctor = env->GetMethodID(Testbed2JniCache::javaStructNestedStruct2, "<init>", "()V");
	checkException(env, "method <init>, ()V for testbed2/testbed2_api/NestedStruct2");
	javaStructNestedStruct2Field1FieldId = env->GetFieldID(Testbed2JniCache::javaStructNestedStruct2, "field1", "Ltestbed2/testbed2_api/Struct1;");
	checkException(env, "field1, Ltestbed2/testbed2_api/Struct1; for testbed2/testbed2_api/NestedStruct2");
	javaStructNestedStruct2Field2FieldId = env->GetFieldID(Testbed2JniCache::javaStructNestedStruct2, "field2", "Ltestbed2/testbed2_api/Struct2;");
	checkException(env, "field2, Ltestbed2/testbed2_api/Struct2; for testbed2/testbed2_api/NestedStruct2");
	javaStructNestedStruct3 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/NestedStruct3");
	checkException(env, "testbed2/testbed2_api/NestedStruct3");
	javaStructNestedStruct3Ctor = env->GetMethodID(Testbed2JniCache::javaStructNestedStruct3, "<init>", "()V");
	checkException(env, "method <init>, ()V for testbed2/testbed2_api/NestedStruct3");
	javaStructNestedStruct3Field1FieldId = env->GetFieldID(Testbed2JniCache::javaStructNestedStruct3, "field1", "Ltestbed2/testbed2_api/Struct1;");
	checkException(env, "field1, Ltestbed2/testbed2_api/Struct1; for testbed2/testbed2_api/NestedStruct3");
	javaStructNestedStruct3Field2FieldId = env->GetFieldID(Testbed2JniCache::javaStructNestedStruct3, "field2", "Ltestbed2/testbed2_api/Struct2;");
	checkException(env, "field2, Ltestbed2/testbed2_api/Struct2; for testbed2/testbed2_api/NestedStruct3");
	javaStructNestedStruct3Field3FieldId = env->GetFieldID(Testbed2JniCache::javaStructNestedStruct3, "field3", "Ltestbed2/testbed2_api/Struct3;");
	checkException(env, "field3, Ltestbed2/testbed2_api/Struct3; for testbed2/testbed2_api/NestedStruct3");
	javaEnumEnum1 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum1");
	checkException(env, "testbed2/testbed2_api/Enum1");
	javaEnumEnum1FromValueMethodId = env->GetStaticMethodID(Testbed2JniCache::javaEnumEnum1, "fromValue", "(I)Ltestbed2/testbed2_api/Enum1;");
	checkException(env, "fromValue (I)Ltestbed2/testbed2_api/Enum1; for testbed2/testbed2_api/Enum1");
	javaEnumEnum1GetValueMethod = env->GetMethodID(Testbed2JniCache::javaEnumEnum1, "getValue", "()I");
	checkException(env, "getValue (I)Ltestbed2/testbed2_api/Enum1; for testbed2/testbed2_api/Enum1");
	javaEnumEnum2 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum2");
	checkException(env, "testbed2/testbed2_api/Enum2");
	javaEnumEnum2FromValueMethodId = env->GetStaticMethodID(Testbed2JniCache::javaEnumEnum2, "fromValue", "(I)Ltestbed2/testbed2_api/Enum2;");
	checkException(env, "fromValue (I)Ltestbed2/testbed2_api/Enum2; for testbed2/testbed2_api/Enum2");
	javaEnumEnum2GetValueMethod = env->GetMethodID(Testbed2JniCache::javaEnumEnum2, "getValue", "()I");
	checkException(env, "getValue (I)Ltestbed2/testbed2_api/Enum2; for testbed2/testbed2_api/Enum2");
	javaEnumEnum3 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum3");
	checkException(env, "testbed2/testbed2_api/Enum3");
	javaEnumEnum3FromValueMethodId = env->GetStaticMethodID(Testbed2JniCache::javaEnumEnum3, "fromValue", "(I)Ltestbed2/testbed2_api/Enum3;");
	checkException(env, "fromValue (I)Ltestbed2/testbed2_api/Enum3; for testbed2/testbed2_api/Enum3");
	javaEnumEnum3GetValueMethod = env->GetMethodID(Testbed2JniCache::javaEnumEnum3, "getValue", "()I");
	checkException(env, "getValue (I)Ltestbed2/testbed2_api/Enum3; for testbed2/testbed2_api/Enum3");

	javaClassManyParamInterface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/IManyParamInterface");
	checkException(env, "testbed2/testbed2_api/IManyParamInterface");
	javaClassManyParamInterfaceProp1SetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "setProp1", "(I)V");
	checkException(env, "setProp1, (I)V  for testbed2/testbed2_api/IManyParamInterface");
	javaClassManyParamInterfaceProp1GetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "getProp1", "()I");
	checkException(env, "getProp1, ()I for testbed2/testbed2_api/IManyParamInterface");
	javaClassManyParamInterfaceProp2SetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "setProp2", "(I)V");
	checkException(env, "setProp2, (I)V  for testbed2/testbed2_api/IManyParamInterface");
	javaClassManyParamInterfaceProp2GetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "getProp2", "()I");
	checkException(env, "getProp2, ()I for testbed2/testbed2_api/IManyParamInterface");
	javaClassManyParamInterfaceProp3SetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "setProp3", "(I)V");
	checkException(env, "setProp3, (I)V  for testbed2/testbed2_api/IManyParamInterface");
	javaClassManyParamInterfaceProp3GetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "getProp3", "()I");
	checkException(env, "getProp3, ()I for testbed2/testbed2_api/IManyParamInterface");
	javaClassManyParamInterfaceProp4SetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "setProp4", "(I)V");
	checkException(env, "setProp4, (I)V  for testbed2/testbed2_api/IManyParamInterface");
	javaClassManyParamInterfaceProp4GetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "getProp4", "()I");
	checkException(env, "getProp4, ()I for testbed2/testbed2_api/IManyParamInterface");

	serviceClassManyParamInterface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2jniservice/ManyParamInterfaceJniService");
	checkException(env, "testbed2/testbed2jniservice/ManyParamInterfaceJniService");
	serviceClassManyParamInterfaceReadyMethodID = env->GetMethodID(Testbed2JniCache::serviceClassManyParamInterface, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for testbed2/testbed2jniservice/ManyParamInterfaceJniService");
	serviceClassManyParamInterfaceProp1ChangedMethodID = env->GetMethodID(Testbed2JniCache::serviceClassManyParamInterface, "onProp1Changed", "(I)V");
	checkException(env, "onProp1Changed, (I)V for testbed2/testbed2jniservice/ManyParamInterfaceJniService");
	serviceClassManyParamInterfaceProp2ChangedMethodID = env->GetMethodID(Testbed2JniCache::serviceClassManyParamInterface, "onProp2Changed", "(I)V");
	checkException(env, "onProp2Changed, (I)V for testbed2/testbed2jniservice/ManyParamInterfaceJniService");
	serviceClassManyParamInterfaceProp3ChangedMethodID = env->GetMethodID(Testbed2JniCache::serviceClassManyParamInterface, "onProp3Changed", "(I)V");
	checkException(env, "onProp3Changed, (I)V for testbed2/testbed2jniservice/ManyParamInterfaceJniService");
	serviceClassManyParamInterfaceProp4ChangedMethodID = env->GetMethodID(Testbed2JniCache::serviceClassManyParamInterface, "onProp4Changed", "(I)V");
	checkException(env, "onProp4Changed, (I)V for testbed2/testbed2jniservice/ManyParamInterfaceJniService");
	serviceClassManyParamInterfaceSig1SignalMethodID = env->GetMethodID(Testbed2JniCache::serviceClassManyParamInterface, "onSig1", "(I)V");
	checkException(env, "onSig1, (I)V for testbed2/testbed2jniservice/ManyParamInterfaceJniService");
	serviceClassManyParamInterfaceSig2SignalMethodID = env->GetMethodID(Testbed2JniCache::serviceClassManyParamInterface, "onSig2", "(II)V");
	checkException(env, "onSig2, (II)V for testbed2/testbed2jniservice/ManyParamInterfaceJniService");
	serviceClassManyParamInterfaceSig3SignalMethodID = env->GetMethodID(Testbed2JniCache::serviceClassManyParamInterface, "onSig3", "(III)V");
	checkException(env, "onSig3, (III)V for testbed2/testbed2jniservice/ManyParamInterfaceJniService");
	serviceClassManyParamInterfaceSig4SignalMethodID = env->GetMethodID(Testbed2JniCache::serviceClassManyParamInterface, "onSig4", "(IIII)V");
	checkException(env, "onSig4, (IIII)V for testbed2/testbed2jniservice/ManyParamInterfaceJniService");
	clientClassManyParamInterface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2jniclient/ManyParamInterfaceJniClient");
	checkException(env, "testbed2/testbed2jniclient/ManyParamInterfaceJniClient");
	clientClassManyParamInterfaceFunc1AsyncMethodID = env->GetMethodID(Testbed2JniCache::clientClassManyParamInterface, "func1Async", "(Ljava/lang/String;I)V");
	checkException(env, "func1Async, (Ljava/lang/String;I)V for testbed2/testbed2jniclient/ManyParamInterfaceJniClient");
	clientClassManyParamInterfaceFunc2AsyncMethodID = env->GetMethodID(Testbed2JniCache::clientClassManyParamInterface, "func2Async", "(Ljava/lang/String;II)V");
	checkException(env, "func2Async, (Ljava/lang/String;II)V for testbed2/testbed2jniclient/ManyParamInterfaceJniClient");
	clientClassManyParamInterfaceFunc3AsyncMethodID = env->GetMethodID(Testbed2JniCache::clientClassManyParamInterface, "func3Async", "(Ljava/lang/String;III)V");
	checkException(env, "func3Async, (Ljava/lang/String;III)V for testbed2/testbed2jniclient/ManyParamInterfaceJniClient");
	clientClassManyParamInterfaceFunc4AsyncMethodID = env->GetMethodID(Testbed2JniCache::clientClassManyParamInterface, "func4Async", "(Ljava/lang/String;IIII)V");
	checkException(env, "func4Async, (Ljava/lang/String;IIII)V for testbed2/testbed2jniclient/ManyParamInterfaceJniClient");
	clientClassManyParamInterfaceCtor = env->GetMethodID(Testbed2JniCache::clientClassManyParamInterface, "<init>", "()V");
	checkException(env, "init, ()V for testbed2/testbed2jniclient/ManyParamInterfaceJniClient");
	clientClassManyParamInterfaceBindMethodID = env->GetMethodID(Testbed2JniCache::clientClassManyParamInterface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for testbed2/testbed2jniclient/ManyParamInterfaceJniClient");
	clientClassManyParamInterfaceUnbindMethodID = env->GetMethodID(Testbed2JniCache::clientClassManyParamInterface, "unbind", "()V");
	checkException(env, "unbind, ()V for testbed2/testbed2jniclient/ManyParamInterfaceJniClient");

	javaClassNestedStruct1Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/INestedStruct1Interface");
	checkException(env, "testbed2/testbed2_api/INestedStruct1Interface");
	javaClassNestedStruct1InterfaceProp1SetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct1Interface, "setProp1", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	checkException(env, "setProp1, (Ltestbed2/testbed2_api/NestedStruct1;)V  for testbed2/testbed2_api/INestedStruct1Interface");
	javaClassNestedStruct1InterfaceProp1GetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct1Interface, "getProp1", "()Ltestbed2/testbed2_api/NestedStruct1;");
	checkException(env, "getProp1, ()Ltestbed2/testbed2_api/NestedStruct1; for testbed2/testbed2_api/INestedStruct1Interface");

	serviceClassNestedStruct1Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2jniservice/NestedStruct1InterfaceJniService");
	checkException(env, "testbed2/testbed2jniservice/NestedStruct1InterfaceJniService");
	serviceClassNestedStruct1InterfaceReadyMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct1Interface, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for testbed2/testbed2jniservice/NestedStruct1InterfaceJniService");
	serviceClassNestedStruct1InterfaceProp1ChangedMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct1Interface, "onProp1Changed", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	checkException(env, "onProp1Changed, (Ltestbed2/testbed2_api/NestedStruct1;)V for testbed2/testbed2jniservice/NestedStruct1InterfaceJniService");
	serviceClassNestedStruct1InterfaceSig1SignalMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct1Interface, "onSig1", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	checkException(env, "onSig1, (Ltestbed2/testbed2_api/NestedStruct1;)V for testbed2/testbed2jniservice/NestedStruct1InterfaceJniService");
	clientClassNestedStruct1Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2jniclient/NestedStruct1InterfaceJniClient");
	checkException(env, "testbed2/testbed2jniclient/NestedStruct1InterfaceJniClient");
	clientClassNestedStruct1InterfaceFuncNoReturnValueAsyncMethodID = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct1Interface, "funcNoReturnValueAsync", "(Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;)V");
	checkException(env, "funcNoReturnValueAsync, (Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;)V for testbed2/testbed2jniclient/NestedStruct1InterfaceJniClient");
	clientClassNestedStruct1InterfaceFuncNoParamsAsyncMethodID = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct1Interface, "funcNoParamsAsync", "(Ljava/lang/String;)V");
	checkException(env, "funcNoParamsAsync, (Ljava/lang/String;)V for testbed2/testbed2jniclient/NestedStruct1InterfaceJniClient");
	clientClassNestedStruct1InterfaceFunc1AsyncMethodID = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct1Interface, "func1Async", "(Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;)V");
	checkException(env, "func1Async, (Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;)V for testbed2/testbed2jniclient/NestedStruct1InterfaceJniClient");
	clientClassNestedStruct1InterfaceCtor = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct1Interface, "<init>", "()V");
	checkException(env, "init, ()V for testbed2/testbed2jniclient/NestedStruct1InterfaceJniClient");
	clientClassNestedStruct1InterfaceBindMethodID = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct1Interface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for testbed2/testbed2jniclient/NestedStruct1InterfaceJniClient");
	clientClassNestedStruct1InterfaceUnbindMethodID = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct1Interface, "unbind", "()V");
	checkException(env, "unbind, ()V for testbed2/testbed2jniclient/NestedStruct1InterfaceJniClient");

	javaClassNestedStruct2Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/INestedStruct2Interface");
	checkException(env, "testbed2/testbed2_api/INestedStruct2Interface");
	javaClassNestedStruct2InterfaceProp1SetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct2Interface, "setProp1", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	checkException(env, "setProp1, (Ltestbed2/testbed2_api/NestedStruct1;)V  for testbed2/testbed2_api/INestedStruct2Interface");
	javaClassNestedStruct2InterfaceProp1GetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct2Interface, "getProp1", "()Ltestbed2/testbed2_api/NestedStruct1;");
	checkException(env, "getProp1, ()Ltestbed2/testbed2_api/NestedStruct1; for testbed2/testbed2_api/INestedStruct2Interface");
	javaClassNestedStruct2InterfaceProp2SetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct2Interface, "setProp2", "(Ltestbed2/testbed2_api/NestedStruct2;)V");
	checkException(env, "setProp2, (Ltestbed2/testbed2_api/NestedStruct2;)V  for testbed2/testbed2_api/INestedStruct2Interface");
	javaClassNestedStruct2InterfaceProp2GetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct2Interface, "getProp2", "()Ltestbed2/testbed2_api/NestedStruct2;");
	checkException(env, "getProp2, ()Ltestbed2/testbed2_api/NestedStruct2; for testbed2/testbed2_api/INestedStruct2Interface");

	serviceClassNestedStruct2Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2jniservice/NestedStruct2InterfaceJniService");
	checkException(env, "testbed2/testbed2jniservice/NestedStruct2InterfaceJniService");
	serviceClassNestedStruct2InterfaceReadyMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct2Interface, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for testbed2/testbed2jniservice/NestedStruct2InterfaceJniService");
	serviceClassNestedStruct2InterfaceProp1ChangedMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct2Interface, "onProp1Changed", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	checkException(env, "onProp1Changed, (Ltestbed2/testbed2_api/NestedStruct1;)V for testbed2/testbed2jniservice/NestedStruct2InterfaceJniService");
	serviceClassNestedStruct2InterfaceProp2ChangedMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct2Interface, "onProp2Changed", "(Ltestbed2/testbed2_api/NestedStruct2;)V");
	checkException(env, "onProp2Changed, (Ltestbed2/testbed2_api/NestedStruct2;)V for testbed2/testbed2jniservice/NestedStruct2InterfaceJniService");
	serviceClassNestedStruct2InterfaceSig1SignalMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct2Interface, "onSig1", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	checkException(env, "onSig1, (Ltestbed2/testbed2_api/NestedStruct1;)V for testbed2/testbed2jniservice/NestedStruct2InterfaceJniService");
	serviceClassNestedStruct2InterfaceSig2SignalMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct2Interface, "onSig2", "(Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;)V");
	checkException(env, "onSig2, (Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;)V for testbed2/testbed2jniservice/NestedStruct2InterfaceJniService");
	clientClassNestedStruct2Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2jniclient/NestedStruct2InterfaceJniClient");
	checkException(env, "testbed2/testbed2jniclient/NestedStruct2InterfaceJniClient");
	clientClassNestedStruct2InterfaceFunc1AsyncMethodID = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct2Interface, "func1Async", "(Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;)V");
	checkException(env, "func1Async, (Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;)V for testbed2/testbed2jniclient/NestedStruct2InterfaceJniClient");
	clientClassNestedStruct2InterfaceFunc2AsyncMethodID = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct2Interface, "func2Async", "(Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;)V");
	checkException(env, "func2Async, (Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;)V for testbed2/testbed2jniclient/NestedStruct2InterfaceJniClient");
	clientClassNestedStruct2InterfaceCtor = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct2Interface, "<init>", "()V");
	checkException(env, "init, ()V for testbed2/testbed2jniclient/NestedStruct2InterfaceJniClient");
	clientClassNestedStruct2InterfaceBindMethodID = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct2Interface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for testbed2/testbed2jniclient/NestedStruct2InterfaceJniClient");
	clientClassNestedStruct2InterfaceUnbindMethodID = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct2Interface, "unbind", "()V");
	checkException(env, "unbind, ()V for testbed2/testbed2jniclient/NestedStruct2InterfaceJniClient");

	javaClassNestedStruct3Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/INestedStruct3Interface");
	checkException(env, "testbed2/testbed2_api/INestedStruct3Interface");
	javaClassNestedStruct3InterfaceProp1SetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "setProp1", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	checkException(env, "setProp1, (Ltestbed2/testbed2_api/NestedStruct1;)V  for testbed2/testbed2_api/INestedStruct3Interface");
	javaClassNestedStruct3InterfaceProp1GetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "getProp1", "()Ltestbed2/testbed2_api/NestedStruct1;");
	checkException(env, "getProp1, ()Ltestbed2/testbed2_api/NestedStruct1; for testbed2/testbed2_api/INestedStruct3Interface");
	javaClassNestedStruct3InterfaceProp2SetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "setProp2", "(Ltestbed2/testbed2_api/NestedStruct2;)V");
	checkException(env, "setProp2, (Ltestbed2/testbed2_api/NestedStruct2;)V  for testbed2/testbed2_api/INestedStruct3Interface");
	javaClassNestedStruct3InterfaceProp2GetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "getProp2", "()Ltestbed2/testbed2_api/NestedStruct2;");
	checkException(env, "getProp2, ()Ltestbed2/testbed2_api/NestedStruct2; for testbed2/testbed2_api/INestedStruct3Interface");
	javaClassNestedStruct3InterfaceProp3SetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "setProp3", "(Ltestbed2/testbed2_api/NestedStruct3;)V");
	checkException(env, "setProp3, (Ltestbed2/testbed2_api/NestedStruct3;)V  for testbed2/testbed2_api/INestedStruct3Interface");
	javaClassNestedStruct3InterfaceProp3GetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "getProp3", "()Ltestbed2/testbed2_api/NestedStruct3;");
	checkException(env, "getProp3, ()Ltestbed2/testbed2_api/NestedStruct3; for testbed2/testbed2_api/INestedStruct3Interface");

	serviceClassNestedStruct3Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2jniservice/NestedStruct3InterfaceJniService");
	checkException(env, "testbed2/testbed2jniservice/NestedStruct3InterfaceJniService");
	serviceClassNestedStruct3InterfaceReadyMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct3Interface, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for testbed2/testbed2jniservice/NestedStruct3InterfaceJniService");
	serviceClassNestedStruct3InterfaceProp1ChangedMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct3Interface, "onProp1Changed", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	checkException(env, "onProp1Changed, (Ltestbed2/testbed2_api/NestedStruct1;)V for testbed2/testbed2jniservice/NestedStruct3InterfaceJniService");
	serviceClassNestedStruct3InterfaceProp2ChangedMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct3Interface, "onProp2Changed", "(Ltestbed2/testbed2_api/NestedStruct2;)V");
	checkException(env, "onProp2Changed, (Ltestbed2/testbed2_api/NestedStruct2;)V for testbed2/testbed2jniservice/NestedStruct3InterfaceJniService");
	serviceClassNestedStruct3InterfaceProp3ChangedMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct3Interface, "onProp3Changed", "(Ltestbed2/testbed2_api/NestedStruct3;)V");
	checkException(env, "onProp3Changed, (Ltestbed2/testbed2_api/NestedStruct3;)V for testbed2/testbed2jniservice/NestedStruct3InterfaceJniService");
	serviceClassNestedStruct3InterfaceSig1SignalMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct3Interface, "onSig1", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	checkException(env, "onSig1, (Ltestbed2/testbed2_api/NestedStruct1;)V for testbed2/testbed2jniservice/NestedStruct3InterfaceJniService");
	serviceClassNestedStruct3InterfaceSig2SignalMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct3Interface, "onSig2", "(Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;)V");
	checkException(env, "onSig2, (Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;)V for testbed2/testbed2jniservice/NestedStruct3InterfaceJniService");
	serviceClassNestedStruct3InterfaceSig3SignalMethodID = env->GetMethodID(Testbed2JniCache::serviceClassNestedStruct3Interface, "onSig3", "(Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;Ltestbed2/testbed2_api/NestedStruct3;)V");
	checkException(env, "onSig3, (Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;Ltestbed2/testbed2_api/NestedStruct3;)V for testbed2/testbed2jniservice/NestedStruct3InterfaceJniService");
	clientClassNestedStruct3Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2jniclient/NestedStruct3InterfaceJniClient");
	checkException(env, "testbed2/testbed2jniclient/NestedStruct3InterfaceJniClient");
	clientClassNestedStruct3InterfaceFunc1AsyncMethodID = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct3Interface, "func1Async", "(Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;)V");
	checkException(env, "func1Async, (Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;)V for testbed2/testbed2jniclient/NestedStruct3InterfaceJniClient");
	clientClassNestedStruct3InterfaceFunc2AsyncMethodID = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct3Interface, "func2Async", "(Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;)V");
	checkException(env, "func2Async, (Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;)V for testbed2/testbed2jniclient/NestedStruct3InterfaceJniClient");
	clientClassNestedStruct3InterfaceFunc3AsyncMethodID = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct3Interface, "func3Async", "(Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;Ltestbed2/testbed2_api/NestedStruct3;)V");
	checkException(env, "func3Async, (Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;Ltestbed2/testbed2_api/NestedStruct3;)V for testbed2/testbed2jniclient/NestedStruct3InterfaceJniClient");
	clientClassNestedStruct3InterfaceCtor = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct3Interface, "<init>", "()V");
	checkException(env, "init, ()V for testbed2/testbed2jniclient/NestedStruct3InterfaceJniClient");
	clientClassNestedStruct3InterfaceBindMethodID = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct3Interface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for testbed2/testbed2jniclient/NestedStruct3InterfaceJniClient");
	clientClassNestedStruct3InterfaceUnbindMethodID = env->GetMethodID(Testbed2JniCache::clientClassNestedStruct3Interface, "unbind", "()V");
	checkException(env, "unbind, ()V for testbed2/testbed2jniclient/NestedStruct3InterfaceJniClient");
	m_isInitialized = true;
}

void Testbed2JniCache::clear()
{
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(javaStructStruct1);
	javaStructStruct1 = nullptr;
	javaStructStruct1Ctor = nullptr;
	javaStructStruct1Field1FieldId = nullptr;
	env->DeleteGlobalRef(javaStructStruct2);
	javaStructStruct2 = nullptr;
	javaStructStruct2Ctor = nullptr;
	javaStructStruct2Field1FieldId = nullptr;
	javaStructStruct2Field2FieldId = nullptr;
	env->DeleteGlobalRef(javaStructStruct3);
	javaStructStruct3 = nullptr;
	javaStructStruct3Ctor = nullptr;
	javaStructStruct3Field1FieldId = nullptr;
	javaStructStruct3Field2FieldId = nullptr;
	javaStructStruct3Field3FieldId = nullptr;
	env->DeleteGlobalRef(javaStructStruct4);
	javaStructStruct4 = nullptr;
	javaStructStruct4Ctor = nullptr;
	javaStructStruct4Field1FieldId = nullptr;
	javaStructStruct4Field2FieldId = nullptr;
	javaStructStruct4Field3FieldId = nullptr;
	javaStructStruct4Field4FieldId = nullptr;
	env->DeleteGlobalRef(javaStructNestedStruct1);
	javaStructNestedStruct1 = nullptr;
	javaStructNestedStruct1Ctor = nullptr;
	javaStructNestedStruct1Field1FieldId = nullptr;
	env->DeleteGlobalRef(javaStructNestedStruct2);
	javaStructNestedStruct2 = nullptr;
	javaStructNestedStruct2Ctor = nullptr;
	javaStructNestedStruct2Field1FieldId = nullptr;
	javaStructNestedStruct2Field2FieldId = nullptr;
	env->DeleteGlobalRef(javaStructNestedStruct3);
	javaStructNestedStruct3 = nullptr;
	javaStructNestedStruct3Ctor = nullptr;
	javaStructNestedStruct3Field1FieldId = nullptr;
	javaStructNestedStruct3Field2FieldId = nullptr;
	javaStructNestedStruct3Field3FieldId = nullptr;
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
	env->DeleteGlobalRef(javaClassManyParamInterface);
	javaClassManyParamInterface = nullptr;
	javaClassManyParamInterfaceProp1SetterId = nullptr;
	javaClassManyParamInterfaceProp1GetterId = nullptr;
	javaClassManyParamInterfaceProp2SetterId = nullptr;
	javaClassManyParamInterfaceProp2GetterId = nullptr;
	javaClassManyParamInterfaceProp3SetterId = nullptr;
	javaClassManyParamInterfaceProp3GetterId = nullptr;
	javaClassManyParamInterfaceProp4SetterId = nullptr;
	javaClassManyParamInterfaceProp4GetterId = nullptr;
	env->DeleteGlobalRef(serviceClassManyParamInterface);
	serviceClassManyParamInterface = nullptr;
	serviceClassManyParamInterfaceReadyMethodID = nullptr;
	serviceClassManyParamInterfaceProp1ChangedMethodID = nullptr;
	serviceClassManyParamInterfaceProp2ChangedMethodID = nullptr;
	serviceClassManyParamInterfaceProp3ChangedMethodID = nullptr;
	serviceClassManyParamInterfaceProp4ChangedMethodID = nullptr;
	serviceClassManyParamInterfaceSig1SignalMethodID = nullptr;
	serviceClassManyParamInterfaceSig2SignalMethodID = nullptr;
	serviceClassManyParamInterfaceSig3SignalMethodID = nullptr;
	serviceClassManyParamInterfaceSig4SignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassManyParamInterface);
	clientClassManyParamInterface = nullptr;
	clientClassManyParamInterfaceFunc1AsyncMethodID = nullptr;
	clientClassManyParamInterfaceFunc2AsyncMethodID = nullptr;
	clientClassManyParamInterfaceFunc3AsyncMethodID = nullptr;
	clientClassManyParamInterfaceFunc4AsyncMethodID = nullptr;
	clientClassManyParamInterfaceCtor = nullptr;
	clientClassManyParamInterfaceBindMethodID = nullptr;
	clientClassManyParamInterfaceUnbindMethodID = nullptr;
	env->DeleteGlobalRef(javaClassNestedStruct1Interface);
	javaClassNestedStruct1Interface = nullptr;
	javaClassNestedStruct1InterfaceProp1SetterId = nullptr;
	javaClassNestedStruct1InterfaceProp1GetterId = nullptr;
	env->DeleteGlobalRef(serviceClassNestedStruct1Interface);
	serviceClassNestedStruct1Interface = nullptr;
	serviceClassNestedStruct1InterfaceReadyMethodID = nullptr;
	serviceClassNestedStruct1InterfaceProp1ChangedMethodID = nullptr;
	serviceClassNestedStruct1InterfaceSig1SignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassNestedStruct1Interface);
	clientClassNestedStruct1Interface = nullptr;
	clientClassNestedStruct1InterfaceFuncNoReturnValueAsyncMethodID = nullptr;
	clientClassNestedStruct1InterfaceFuncNoParamsAsyncMethodID = nullptr;
	clientClassNestedStruct1InterfaceFunc1AsyncMethodID = nullptr;
	clientClassNestedStruct1InterfaceCtor = nullptr;
	clientClassNestedStruct1InterfaceBindMethodID = nullptr;
	clientClassNestedStruct1InterfaceUnbindMethodID = nullptr;
	env->DeleteGlobalRef(javaClassNestedStruct2Interface);
	javaClassNestedStruct2Interface = nullptr;
	javaClassNestedStruct2InterfaceProp1SetterId = nullptr;
	javaClassNestedStruct2InterfaceProp1GetterId = nullptr;
	javaClassNestedStruct2InterfaceProp2SetterId = nullptr;
	javaClassNestedStruct2InterfaceProp2GetterId = nullptr;
	env->DeleteGlobalRef(serviceClassNestedStruct2Interface);
	serviceClassNestedStruct2Interface = nullptr;
	serviceClassNestedStruct2InterfaceReadyMethodID = nullptr;
	serviceClassNestedStruct2InterfaceProp1ChangedMethodID = nullptr;
	serviceClassNestedStruct2InterfaceProp2ChangedMethodID = nullptr;
	serviceClassNestedStruct2InterfaceSig1SignalMethodID = nullptr;
	serviceClassNestedStruct2InterfaceSig2SignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassNestedStruct2Interface);
	clientClassNestedStruct2Interface = nullptr;
	clientClassNestedStruct2InterfaceFunc1AsyncMethodID = nullptr;
	clientClassNestedStruct2InterfaceFunc2AsyncMethodID = nullptr;
	clientClassNestedStruct2InterfaceCtor = nullptr;
	clientClassNestedStruct2InterfaceBindMethodID = nullptr;
	clientClassNestedStruct2InterfaceUnbindMethodID = nullptr;
	env->DeleteGlobalRef(javaClassNestedStruct3Interface);
	javaClassNestedStruct3Interface = nullptr;
	javaClassNestedStruct3InterfaceProp1SetterId = nullptr;
	javaClassNestedStruct3InterfaceProp1GetterId = nullptr;
	javaClassNestedStruct3InterfaceProp2SetterId = nullptr;
	javaClassNestedStruct3InterfaceProp2GetterId = nullptr;
	javaClassNestedStruct3InterfaceProp3SetterId = nullptr;
	javaClassNestedStruct3InterfaceProp3GetterId = nullptr;
	env->DeleteGlobalRef(serviceClassNestedStruct3Interface);
	serviceClassNestedStruct3Interface = nullptr;
	serviceClassNestedStruct3InterfaceReadyMethodID = nullptr;
	serviceClassNestedStruct3InterfaceProp1ChangedMethodID = nullptr;
	serviceClassNestedStruct3InterfaceProp2ChangedMethodID = nullptr;
	serviceClassNestedStruct3InterfaceProp3ChangedMethodID = nullptr;
	serviceClassNestedStruct3InterfaceSig1SignalMethodID = nullptr;
	serviceClassNestedStruct3InterfaceSig2SignalMethodID = nullptr;
	serviceClassNestedStruct3InterfaceSig3SignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassNestedStruct3Interface);
	clientClassNestedStruct3Interface = nullptr;
	clientClassNestedStruct3InterfaceFunc1AsyncMethodID = nullptr;
	clientClassNestedStruct3InterfaceFunc2AsyncMethodID = nullptr;
	clientClassNestedStruct3InterfaceFunc3AsyncMethodID = nullptr;
	clientClassNestedStruct3InterfaceCtor = nullptr;
	clientClassNestedStruct3InterfaceBindMethodID = nullptr;
	clientClassNestedStruct3InterfaceUnbindMethodID = nullptr;
}

bool Testbed2JniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
