
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

#include "Testbed1/Generated/Jni/Testbed1JniCache.h"
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
jclass Testbed1JniCache::javaStructStructBool = nullptr;
jmethodID Testbed1JniCache::javaStructStructBoolCtor = nullptr;
jfieldID Testbed1JniCache::javaStructStructBoolFieldBoolFieldId = nullptr;
jclass Testbed1JniCache::javaStructStructInt = nullptr;
jmethodID Testbed1JniCache::javaStructStructIntCtor = nullptr;
jfieldID Testbed1JniCache::javaStructStructIntFieldIntFieldId = nullptr;
jclass Testbed1JniCache::javaStructStructFloat = nullptr;
jmethodID Testbed1JniCache::javaStructStructFloatCtor = nullptr;
jfieldID Testbed1JniCache::javaStructStructFloatFieldFloatFieldId = nullptr;
jclass Testbed1JniCache::javaStructStructString = nullptr;
jmethodID Testbed1JniCache::javaStructStructStringCtor = nullptr;
jfieldID Testbed1JniCache::javaStructStructStringFieldStringFieldId = nullptr;
jclass Testbed1JniCache::javaStructStructStruct = nullptr;
jmethodID Testbed1JniCache::javaStructStructStructCtor = nullptr;
jfieldID Testbed1JniCache::javaStructStructStructFieldStringFieldId = nullptr;
jclass Testbed1JniCache::javaStructStructEnum = nullptr;
jmethodID Testbed1JniCache::javaStructStructEnumCtor = nullptr;
jfieldID Testbed1JniCache::javaStructStructEnumFieldEnumFieldId = nullptr;
jclass Testbed1JniCache::javaStructStructBoolWithArray = nullptr;
jmethodID Testbed1JniCache::javaStructStructBoolWithArrayCtor = nullptr;
jfieldID Testbed1JniCache::javaStructStructBoolWithArrayFieldBoolFieldId = nullptr;
jclass Testbed1JniCache::javaStructStructIntWithArray = nullptr;
jmethodID Testbed1JniCache::javaStructStructIntWithArrayCtor = nullptr;
jfieldID Testbed1JniCache::javaStructStructIntWithArrayFieldIntFieldId = nullptr;
jclass Testbed1JniCache::javaStructStructFloatWithArray = nullptr;
jmethodID Testbed1JniCache::javaStructStructFloatWithArrayCtor = nullptr;
jfieldID Testbed1JniCache::javaStructStructFloatWithArrayFieldFloatFieldId = nullptr;
jclass Testbed1JniCache::javaStructStructStringWithArray = nullptr;
jmethodID Testbed1JniCache::javaStructStructStringWithArrayCtor = nullptr;
jfieldID Testbed1JniCache::javaStructStructStringWithArrayFieldStringFieldId = nullptr;
jclass Testbed1JniCache::javaStructStructStructWithArray = nullptr;
jmethodID Testbed1JniCache::javaStructStructStructWithArrayCtor = nullptr;
jfieldID Testbed1JniCache::javaStructStructStructWithArrayFieldStructFieldId = nullptr;
jclass Testbed1JniCache::javaStructStructEnumWithArray = nullptr;
jmethodID Testbed1JniCache::javaStructStructEnumWithArrayCtor = nullptr;
jfieldID Testbed1JniCache::javaStructStructEnumWithArrayFieldEnumFieldId = nullptr;
jclass Testbed1JniCache::javaEnumEnum0 = nullptr;
jmethodID Testbed1JniCache::javaEnumEnum0FromValueMethodId = nullptr;
jmethodID Testbed1JniCache::javaEnumEnum0GetValueMethod = nullptr;
jclass Testbed1JniCache::javaClassStructInterface = nullptr;
jmethodID Testbed1JniCache::javaClassStructInterfacePropBoolSetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructInterfacePropBoolGetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructInterfacePropIntSetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructInterfacePropIntGetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructInterfacePropFloatSetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructInterfacePropFloatGetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructInterfacePropStringSetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructInterfacePropStringGetterId = nullptr;
jclass Testbed1JniCache::serviceClassStructInterface = nullptr;
jmethodID Testbed1JniCache::serviceClassStructInterfaceReadyMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructInterfacePropBoolChangedMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructInterfacePropIntChangedMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructInterfacePropFloatChangedMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructInterfacePropStringChangedMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructInterfaceSigBoolSignalMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructInterfaceSigIntSignalMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructInterfaceSigFloatSignalMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructInterfaceSigStringSignalMethodID = nullptr;
jclass Testbed1JniCache::clientClassStructInterface = nullptr;
jmethodID Testbed1JniCache::clientClassStructInterfaceCtor = nullptr;
jmethodID Testbed1JniCache::clientClassStructInterfaceBindMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructInterfaceUnbindMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructInterfaceFuncBoolAsyncMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructInterfaceFuncIntAsyncMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructInterfaceFuncFloatAsyncMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructInterfaceFuncStringAsyncMethodID = nullptr;
jclass Testbed1JniCache::javaClassStructArrayInterface = nullptr;
jmethodID Testbed1JniCache::javaClassStructArrayInterfacePropBoolSetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArrayInterfacePropBoolGetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArrayInterfacePropIntSetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArrayInterfacePropIntGetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArrayInterfacePropFloatSetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArrayInterfacePropFloatGetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArrayInterfacePropStringSetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArrayInterfacePropStringGetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArrayInterfacePropEnumSetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArrayInterfacePropEnumGetterId = nullptr;
jclass Testbed1JniCache::serviceClassStructArrayInterface = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArrayInterfaceReadyMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArrayInterfacePropBoolChangedMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArrayInterfacePropIntChangedMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArrayInterfacePropFloatChangedMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArrayInterfacePropStringChangedMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArrayInterfacePropEnumChangedMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArrayInterfaceSigBoolSignalMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArrayInterfaceSigIntSignalMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArrayInterfaceSigFloatSignalMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArrayInterfaceSigStringSignalMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArrayInterfaceSigEnumSignalMethodID = nullptr;
jclass Testbed1JniCache::clientClassStructArrayInterface = nullptr;
jmethodID Testbed1JniCache::clientClassStructArrayInterfaceCtor = nullptr;
jmethodID Testbed1JniCache::clientClassStructArrayInterfaceBindMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructArrayInterfaceUnbindMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructArrayInterfaceFuncBoolAsyncMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructArrayInterfaceFuncIntAsyncMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructArrayInterfaceFuncFloatAsyncMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructArrayInterfaceFuncStringAsyncMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructArrayInterfaceFuncEnumAsyncMethodID = nullptr;
jclass Testbed1JniCache::javaClassStructArray2Interface = nullptr;
jmethodID Testbed1JniCache::javaClassStructArray2InterfacePropBoolSetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArray2InterfacePropBoolGetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArray2InterfacePropIntSetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArray2InterfacePropIntGetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArray2InterfacePropFloatSetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArray2InterfacePropFloatGetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArray2InterfacePropStringSetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArray2InterfacePropStringGetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArray2InterfacePropEnumSetterId = nullptr;
jmethodID Testbed1JniCache::javaClassStructArray2InterfacePropEnumGetterId = nullptr;
jclass Testbed1JniCache::serviceClassStructArray2Interface = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArray2InterfaceReadyMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArray2InterfacePropBoolChangedMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArray2InterfacePropIntChangedMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArray2InterfacePropFloatChangedMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArray2InterfacePropStringChangedMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArray2InterfacePropEnumChangedMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArray2InterfaceSigBoolSignalMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArray2InterfaceSigIntSignalMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArray2InterfaceSigFloatSignalMethodID = nullptr;
jmethodID Testbed1JniCache::serviceClassStructArray2InterfaceSigStringSignalMethodID = nullptr;
jclass Testbed1JniCache::clientClassStructArray2Interface = nullptr;
jmethodID Testbed1JniCache::clientClassStructArray2InterfaceCtor = nullptr;
jmethodID Testbed1JniCache::clientClassStructArray2InterfaceBindMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructArray2InterfaceUnbindMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructArray2InterfaceFuncBoolAsyncMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructArray2InterfaceFuncIntAsyncMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructArray2InterfaceFuncFloatAsyncMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructArray2InterfaceFuncStringAsyncMethodID = nullptr;
jmethodID Testbed1JniCache::clientClassStructArray2InterfaceFuncEnumAsyncMethodID = nullptr;

bool Testbed1JniCache::m_isInitialized = false;

void Testbed1JniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	javaStructStructBool = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructBool");
	javaStructStructBoolCtor = env->GetMethodID(Testbed1JniCache::javaStructStructBool, "<init>", "()V");
	javaStructStructBoolFieldBoolFieldId = env->GetFieldID(Testbed1JniCache::javaStructStructBool, "fieldBool", "Z");
	javaStructStructInt = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructInt");
	javaStructStructIntCtor = env->GetMethodID(Testbed1JniCache::javaStructStructInt, "<init>", "()V");
	javaStructStructIntFieldIntFieldId = env->GetFieldID(Testbed1JniCache::javaStructStructInt, "fieldInt", "I");
	javaStructStructFloat = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructFloat");
	javaStructStructFloatCtor = env->GetMethodID(Testbed1JniCache::javaStructStructFloat, "<init>", "()V");
	javaStructStructFloatFieldFloatFieldId = env->GetFieldID(Testbed1JniCache::javaStructStructFloat, "fieldFloat", "F");
	javaStructStructString = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructString");
	javaStructStructStringCtor = env->GetMethodID(Testbed1JniCache::javaStructStructString, "<init>", "()V");
	javaStructStructStringFieldStringFieldId = env->GetFieldID(Testbed1JniCache::javaStructStructString, "fieldString", "Ljava/lang/String;");
	javaStructStructStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructStruct");
	javaStructStructStructCtor = env->GetMethodID(Testbed1JniCache::javaStructStructStruct, "<init>", "()V");
	javaStructStructStructFieldStringFieldId = env->GetFieldID(Testbed1JniCache::javaStructStructStruct, "fieldString", "Ltestbed1/testbed1_api/StructString;");
	javaStructStructEnum = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructEnum");
	javaStructStructEnumCtor = env->GetMethodID(Testbed1JniCache::javaStructStructEnum, "<init>", "()V");
	javaStructStructEnumFieldEnumFieldId = env->GetFieldID(Testbed1JniCache::javaStructStructEnum, "fieldEnum", "Ltestbed1/testbed1_api/Enum0;");
	javaStructStructBoolWithArray = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructBoolWithArray");
	javaStructStructBoolWithArrayCtor = env->GetMethodID(Testbed1JniCache::javaStructStructBoolWithArray, "<init>", "()V");
	javaStructStructBoolWithArrayFieldBoolFieldId = env->GetFieldID(Testbed1JniCache::javaStructStructBoolWithArray, "fieldBool", "[Z");
	javaStructStructIntWithArray = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructIntWithArray");
	javaStructStructIntWithArrayCtor = env->GetMethodID(Testbed1JniCache::javaStructStructIntWithArray, "<init>", "()V");
	javaStructStructIntWithArrayFieldIntFieldId = env->GetFieldID(Testbed1JniCache::javaStructStructIntWithArray, "fieldInt", "[I");
	javaStructStructFloatWithArray = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructFloatWithArray");
	javaStructStructFloatWithArrayCtor = env->GetMethodID(Testbed1JniCache::javaStructStructFloatWithArray, "<init>", "()V");
	javaStructStructFloatWithArrayFieldFloatFieldId = env->GetFieldID(Testbed1JniCache::javaStructStructFloatWithArray, "fieldFloat", "[F");
	javaStructStructStringWithArray = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructStringWithArray");
	javaStructStructStringWithArrayCtor = env->GetMethodID(Testbed1JniCache::javaStructStructStringWithArray, "<init>", "()V");
	javaStructStructStringWithArrayFieldStringFieldId = env->GetFieldID(Testbed1JniCache::javaStructStructStringWithArray, "fieldString", "[Ljava/lang/String;");
	javaStructStructStructWithArray = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructStructWithArray");
	javaStructStructStructWithArrayCtor = env->GetMethodID(Testbed1JniCache::javaStructStructStructWithArray, "<init>", "()V");
	javaStructStructStructWithArrayFieldStructFieldId = env->GetFieldID(Testbed1JniCache::javaStructStructStructWithArray, "fieldStruct", "[Ltestbed1/testbed1_api/StructStringWithArray;");
	javaStructStructEnumWithArray = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructEnumWithArray");
	javaStructStructEnumWithArrayCtor = env->GetMethodID(Testbed1JniCache::javaStructStructEnumWithArray, "<init>", "()V");
	javaStructStructEnumWithArrayFieldEnumFieldId = env->GetFieldID(Testbed1JniCache::javaStructStructEnumWithArray, "fieldEnum", "[Ltestbed1/testbed1_api/Enum0;");
	javaEnumEnum0 = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/Enum0");
	javaEnumEnum0FromValueMethodId = env->GetStaticMethodID(Testbed1JniCache::javaEnumEnum0, "fromValue", "(I)Ltestbed1/testbed1_api/Enum0;");
	javaEnumEnum0GetValueMethod = env->GetMethodID(Testbed1JniCache::javaEnumEnum0, "getValue", "()I");

	javaClassStructInterface = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/IStructInterface");
	javaClassStructInterfacePropBoolSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "setPropBool", "(Ltestbed1/testbed1_api/StructBool;)V");
	javaClassStructInterfacePropBoolGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "getPropBool", "()Ltestbed1/testbed1_api/StructBool;");
	javaClassStructInterfacePropIntSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "setPropInt", "(Ltestbed1/testbed1_api/StructInt;)V");
	javaClassStructInterfacePropIntGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "getPropInt", "()Ltestbed1/testbed1_api/StructInt;");
	javaClassStructInterfacePropFloatSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "setPropFloat", "(Ltestbed1/testbed1_api/StructFloat;)V");
	javaClassStructInterfacePropFloatGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "getPropFloat", "()Ltestbed1/testbed1_api/StructFloat;");
	javaClassStructInterfacePropStringSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "setPropString", "(Ltestbed1/testbed1_api/StructString;)V");
	javaClassStructInterfacePropStringGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "getPropString", "()Ltestbed1/testbed1_api/StructString;");

	serviceClassStructInterface = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1jniservice/StructInterfaceJniService");
	serviceClassStructInterfaceReadyMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructInterface, "nativeServiceReady", "(Z)V");
	serviceClassStructInterfacePropBoolChangedMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructInterface, "onPropBoolChanged", "(Ltestbed1/testbed1_api/StructBool;)V");
	serviceClassStructInterfacePropIntChangedMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructInterface, "onPropIntChanged", "(Ltestbed1/testbed1_api/StructInt;)V");
	serviceClassStructInterfacePropFloatChangedMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructInterface, "onPropFloatChanged", "(Ltestbed1/testbed1_api/StructFloat;)V");
	serviceClassStructInterfacePropStringChangedMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructInterface, "onPropStringChanged", "(Ltestbed1/testbed1_api/StructString;)V");
	serviceClassStructInterfaceSigBoolSignalMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructInterface, "onSigBool", "(Ltestbed1/testbed1_api/StructBool;)V");
	serviceClassStructInterfaceSigIntSignalMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructInterface, "onSigInt", "(Ltestbed1/testbed1_api/StructInt;)V");
	serviceClassStructInterfaceSigFloatSignalMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructInterface, "onSigFloat", "(Ltestbed1/testbed1_api/StructFloat;)V");
	serviceClassStructInterfaceSigStringSignalMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructInterface, "onSigString", "(Ltestbed1/testbed1_api/StructString;)V");
	clientClassStructInterface = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1jniclient/StructInterfaceJniClient");
	clientClassStructInterfaceFuncBoolAsyncMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructInterface, "funcBoolAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructBool;)V");
	clientClassStructInterfaceFuncIntAsyncMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructInterface, "funcIntAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructInt;)V");
	clientClassStructInterfaceFuncFloatAsyncMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructInterface, "funcFloatAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructFloat;)V");
	clientClassStructInterfaceFuncStringAsyncMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructInterface, "funcStringAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructString;)V");
	clientClassStructInterfaceCtor = env->GetMethodID(Testbed1JniCache::clientClassStructInterface, "<init>", "()V");
	clientClassStructInterfaceBindMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructInterface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	clientClassStructInterfaceUnbindMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructInterface, "unbind", "()V");

	javaClassStructArrayInterface = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/IStructArrayInterface");
	javaClassStructArrayInterfacePropBoolSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "setPropBool", "([Ltestbed1/testbed1_api/StructBool;)V");
	javaClassStructArrayInterfacePropBoolGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "getPropBool", "()[Ltestbed1/testbed1_api/StructBool;");
	javaClassStructArrayInterfacePropIntSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "setPropInt", "([Ltestbed1/testbed1_api/StructInt;)V");
	javaClassStructArrayInterfacePropIntGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "getPropInt", "()[Ltestbed1/testbed1_api/StructInt;");
	javaClassStructArrayInterfacePropFloatSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "setPropFloat", "([Ltestbed1/testbed1_api/StructFloat;)V");
	javaClassStructArrayInterfacePropFloatGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "getPropFloat", "()[Ltestbed1/testbed1_api/StructFloat;");
	javaClassStructArrayInterfacePropStringSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "setPropString", "([Ltestbed1/testbed1_api/StructString;)V");
	javaClassStructArrayInterfacePropStringGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "getPropString", "()[Ltestbed1/testbed1_api/StructString;");
	javaClassStructArrayInterfacePropEnumSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "setPropEnum", "([Ltestbed1/testbed1_api/Enum0;)V");
	javaClassStructArrayInterfacePropEnumGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "getPropEnum", "()[Ltestbed1/testbed1_api/Enum0;");

	serviceClassStructArrayInterface = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1jniservice/StructArrayInterfaceJniService");
	serviceClassStructArrayInterfaceReadyMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArrayInterface, "nativeServiceReady", "(Z)V");
	serviceClassStructArrayInterfacePropBoolChangedMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArrayInterface, "onPropBoolChanged", "([Ltestbed1/testbed1_api/StructBool;)V");
	serviceClassStructArrayInterfacePropIntChangedMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArrayInterface, "onPropIntChanged", "([Ltestbed1/testbed1_api/StructInt;)V");
	serviceClassStructArrayInterfacePropFloatChangedMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArrayInterface, "onPropFloatChanged", "([Ltestbed1/testbed1_api/StructFloat;)V");
	serviceClassStructArrayInterfacePropStringChangedMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArrayInterface, "onPropStringChanged", "([Ltestbed1/testbed1_api/StructString;)V");
	serviceClassStructArrayInterfacePropEnumChangedMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArrayInterface, "onPropEnumChanged", "([Ltestbed1/testbed1_api/Enum0;)V");
	serviceClassStructArrayInterfaceSigBoolSignalMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArrayInterface, "onSigBool", "([Ltestbed1/testbed1_api/StructBool;)V");
	serviceClassStructArrayInterfaceSigIntSignalMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArrayInterface, "onSigInt", "([Ltestbed1/testbed1_api/StructInt;)V");
	serviceClassStructArrayInterfaceSigFloatSignalMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArrayInterface, "onSigFloat", "([Ltestbed1/testbed1_api/StructFloat;)V");
	serviceClassStructArrayInterfaceSigStringSignalMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArrayInterface, "onSigString", "([Ltestbed1/testbed1_api/StructString;)V");
	serviceClassStructArrayInterfaceSigEnumSignalMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArrayInterface, "onSigEnum", "([Ltestbed1/testbed1_api/Enum0;)V");
	clientClassStructArrayInterface = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1jniclient/StructArrayInterfaceJniClient");
	clientClassStructArrayInterfaceFuncBoolAsyncMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructArrayInterface, "funcBoolAsync", "(Ljava/lang/String;[Ltestbed1/testbed1_api/StructBool;)V");
	clientClassStructArrayInterfaceFuncIntAsyncMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructArrayInterface, "funcIntAsync", "(Ljava/lang/String;[Ltestbed1/testbed1_api/StructInt;)V");
	clientClassStructArrayInterfaceFuncFloatAsyncMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructArrayInterface, "funcFloatAsync", "(Ljava/lang/String;[Ltestbed1/testbed1_api/StructFloat;)V");
	clientClassStructArrayInterfaceFuncStringAsyncMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructArrayInterface, "funcStringAsync", "(Ljava/lang/String;[Ltestbed1/testbed1_api/StructString;)V");
	clientClassStructArrayInterfaceFuncEnumAsyncMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructArrayInterface, "funcEnumAsync", "(Ljava/lang/String;[Ltestbed1/testbed1_api/Enum0;)V");
	clientClassStructArrayInterfaceCtor = env->GetMethodID(Testbed1JniCache::clientClassStructArrayInterface, "<init>", "()V");
	clientClassStructArrayInterfaceBindMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructArrayInterface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	clientClassStructArrayInterfaceUnbindMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructArrayInterface, "unbind", "()V");

	javaClassStructArray2Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/IStructArray2Interface");
	javaClassStructArray2InterfacePropBoolSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "setPropBool", "(Ltestbed1/testbed1_api/StructBoolWithArray;)V");
	javaClassStructArray2InterfacePropBoolGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "getPropBool", "()Ltestbed1/testbed1_api/StructBoolWithArray;");
	javaClassStructArray2InterfacePropIntSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "setPropInt", "(Ltestbed1/testbed1_api/StructIntWithArray;)V");
	javaClassStructArray2InterfacePropIntGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "getPropInt", "()Ltestbed1/testbed1_api/StructIntWithArray;");
	javaClassStructArray2InterfacePropFloatSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "setPropFloat", "(Ltestbed1/testbed1_api/StructFloatWithArray;)V");
	javaClassStructArray2InterfacePropFloatGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "getPropFloat", "()Ltestbed1/testbed1_api/StructFloatWithArray;");
	javaClassStructArray2InterfacePropStringSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "setPropString", "(Ltestbed1/testbed1_api/StructStringWithArray;)V");
	javaClassStructArray2InterfacePropStringGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "getPropString", "()Ltestbed1/testbed1_api/StructStringWithArray;");
	javaClassStructArray2InterfacePropEnumSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "setPropEnum", "(Ltestbed1/testbed1_api/StructEnumWithArray;)V");
	javaClassStructArray2InterfacePropEnumGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "getPropEnum", "()Ltestbed1/testbed1_api/StructEnumWithArray;");

	serviceClassStructArray2Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1jniservice/StructArray2InterfaceJniService");
	serviceClassStructArray2InterfaceReadyMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArray2Interface, "nativeServiceReady", "(Z)V");
	serviceClassStructArray2InterfacePropBoolChangedMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArray2Interface, "onPropBoolChanged", "(Ltestbed1/testbed1_api/StructBoolWithArray;)V");
	serviceClassStructArray2InterfacePropIntChangedMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArray2Interface, "onPropIntChanged", "(Ltestbed1/testbed1_api/StructIntWithArray;)V");
	serviceClassStructArray2InterfacePropFloatChangedMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArray2Interface, "onPropFloatChanged", "(Ltestbed1/testbed1_api/StructFloatWithArray;)V");
	serviceClassStructArray2InterfacePropStringChangedMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArray2Interface, "onPropStringChanged", "(Ltestbed1/testbed1_api/StructStringWithArray;)V");
	serviceClassStructArray2InterfacePropEnumChangedMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArray2Interface, "onPropEnumChanged", "(Ltestbed1/testbed1_api/StructEnumWithArray;)V");
	serviceClassStructArray2InterfaceSigBoolSignalMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArray2Interface, "onSigBool", "(Ltestbed1/testbed1_api/StructBoolWithArray;)V");
	serviceClassStructArray2InterfaceSigIntSignalMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArray2Interface, "onSigInt", "(Ltestbed1/testbed1_api/StructIntWithArray;)V");
	serviceClassStructArray2InterfaceSigFloatSignalMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArray2Interface, "onSigFloat", "(Ltestbed1/testbed1_api/StructFloatWithArray;)V");
	serviceClassStructArray2InterfaceSigStringSignalMethodID = env->GetMethodID(Testbed1JniCache::serviceClassStructArray2Interface, "onSigString", "(Ltestbed1/testbed1_api/StructStringWithArray;)V");
	clientClassStructArray2Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1jniclient/StructArray2InterfaceJniClient");
	clientClassStructArray2InterfaceFuncBoolAsyncMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructArray2Interface, "funcBoolAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructBoolWithArray;)V");
	clientClassStructArray2InterfaceFuncIntAsyncMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructArray2Interface, "funcIntAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructIntWithArray;)V");
	clientClassStructArray2InterfaceFuncFloatAsyncMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructArray2Interface, "funcFloatAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructFloatWithArray;)V");
	clientClassStructArray2InterfaceFuncStringAsyncMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructArray2Interface, "funcStringAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructStringWithArray;)V");
	clientClassStructArray2InterfaceFuncEnumAsyncMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructArray2Interface, "funcEnumAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructEnumWithArray;)V");
	clientClassStructArray2InterfaceCtor = env->GetMethodID(Testbed1JniCache::clientClassStructArray2Interface, "<init>", "()V");
	clientClassStructArray2InterfaceBindMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructArray2Interface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	clientClassStructArray2InterfaceUnbindMethodID = env->GetMethodID(Testbed1JniCache::clientClassStructArray2Interface, "unbind", "()V");
	m_isInitialized = true;
}

void Testbed1JniCache::clear()
{
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(javaStructStructBool);
	javaStructStructBool = nullptr;
	javaStructStructBoolCtor = nullptr;
	javaStructStructBoolFieldBoolFieldId = nullptr;
	env->DeleteGlobalRef(javaStructStructInt);
	javaStructStructInt = nullptr;
	javaStructStructIntCtor = nullptr;
	javaStructStructIntFieldIntFieldId = nullptr;
	env->DeleteGlobalRef(javaStructStructFloat);
	javaStructStructFloat = nullptr;
	javaStructStructFloatCtor = nullptr;
	javaStructStructFloatFieldFloatFieldId = nullptr;
	env->DeleteGlobalRef(javaStructStructString);
	javaStructStructString = nullptr;
	javaStructStructStringCtor = nullptr;
	javaStructStructStringFieldStringFieldId = nullptr;
	env->DeleteGlobalRef(javaStructStructStruct);
	javaStructStructStruct = nullptr;
	javaStructStructStructCtor = nullptr;
	javaStructStructStructFieldStringFieldId = nullptr;
	env->DeleteGlobalRef(javaStructStructEnum);
	javaStructStructEnum = nullptr;
	javaStructStructEnumCtor = nullptr;
	javaStructStructEnumFieldEnumFieldId = nullptr;
	env->DeleteGlobalRef(javaStructStructBoolWithArray);
	javaStructStructBoolWithArray = nullptr;
	javaStructStructBoolWithArrayCtor = nullptr;
	javaStructStructBoolWithArrayFieldBoolFieldId = nullptr;
	env->DeleteGlobalRef(javaStructStructIntWithArray);
	javaStructStructIntWithArray = nullptr;
	javaStructStructIntWithArrayCtor = nullptr;
	javaStructStructIntWithArrayFieldIntFieldId = nullptr;
	env->DeleteGlobalRef(javaStructStructFloatWithArray);
	javaStructStructFloatWithArray = nullptr;
	javaStructStructFloatWithArrayCtor = nullptr;
	javaStructStructFloatWithArrayFieldFloatFieldId = nullptr;
	env->DeleteGlobalRef(javaStructStructStringWithArray);
	javaStructStructStringWithArray = nullptr;
	javaStructStructStringWithArrayCtor = nullptr;
	javaStructStructStringWithArrayFieldStringFieldId = nullptr;
	env->DeleteGlobalRef(javaStructStructStructWithArray);
	javaStructStructStructWithArray = nullptr;
	javaStructStructStructWithArrayCtor = nullptr;
	javaStructStructStructWithArrayFieldStructFieldId = nullptr;
	env->DeleteGlobalRef(javaStructStructEnumWithArray);
	javaStructStructEnumWithArray = nullptr;
	javaStructStructEnumWithArrayCtor = nullptr;
	javaStructStructEnumWithArrayFieldEnumFieldId = nullptr;
	env->DeleteGlobalRef(javaEnumEnum0);
	javaEnumEnum0 = nullptr;
	javaEnumEnum0FromValueMethodId = nullptr;
	javaEnumEnum0GetValueMethod = nullptr;
	env->DeleteGlobalRef(javaClassStructInterface);
	javaClassStructInterface = nullptr;
	javaClassStructInterfacePropBoolSetterId = nullptr;
	javaClassStructInterfacePropBoolGetterId = nullptr;
	javaClassStructInterfacePropIntSetterId = nullptr;
	javaClassStructInterfacePropIntGetterId = nullptr;
	javaClassStructInterfacePropFloatSetterId = nullptr;
	javaClassStructInterfacePropFloatGetterId = nullptr;
	javaClassStructInterfacePropStringSetterId = nullptr;
	javaClassStructInterfacePropStringGetterId = nullptr;
	env->DeleteGlobalRef(serviceClassStructInterface);
	serviceClassStructInterface = nullptr;
	serviceClassStructInterfaceReadyMethodID = nullptr;
	serviceClassStructInterfacePropBoolChangedMethodID = nullptr;
	serviceClassStructInterfacePropIntChangedMethodID = nullptr;
	serviceClassStructInterfacePropFloatChangedMethodID = nullptr;
	serviceClassStructInterfacePropStringChangedMethodID = nullptr;
	serviceClassStructInterfaceSigBoolSignalMethodID = nullptr;
	serviceClassStructInterfaceSigIntSignalMethodID = nullptr;
	serviceClassStructInterfaceSigFloatSignalMethodID = nullptr;
	serviceClassStructInterfaceSigStringSignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassStructInterface);
	clientClassStructInterface = nullptr;
	clientClassStructInterfaceFuncBoolAsyncMethodID = nullptr;
	clientClassStructInterfaceFuncIntAsyncMethodID = nullptr;
	clientClassStructInterfaceFuncFloatAsyncMethodID = nullptr;
	clientClassStructInterfaceFuncStringAsyncMethodID = nullptr;
	clientClassStructInterfaceCtor = nullptr;
	clientClassStructInterfaceBindMethodID = nullptr;
	clientClassStructInterfaceUnbindMethodID = nullptr;
	env->DeleteGlobalRef(javaClassStructArrayInterface);
	javaClassStructArrayInterface = nullptr;
	javaClassStructArrayInterfacePropBoolSetterId = nullptr;
	javaClassStructArrayInterfacePropBoolGetterId = nullptr;
	javaClassStructArrayInterfacePropIntSetterId = nullptr;
	javaClassStructArrayInterfacePropIntGetterId = nullptr;
	javaClassStructArrayInterfacePropFloatSetterId = nullptr;
	javaClassStructArrayInterfacePropFloatGetterId = nullptr;
	javaClassStructArrayInterfacePropStringSetterId = nullptr;
	javaClassStructArrayInterfacePropStringGetterId = nullptr;
	javaClassStructArrayInterfacePropEnumSetterId = nullptr;
	javaClassStructArrayInterfacePropEnumGetterId = nullptr;
	env->DeleteGlobalRef(serviceClassStructArrayInterface);
	serviceClassStructArrayInterface = nullptr;
	serviceClassStructArrayInterfaceReadyMethodID = nullptr;
	serviceClassStructArrayInterfacePropBoolChangedMethodID = nullptr;
	serviceClassStructArrayInterfacePropIntChangedMethodID = nullptr;
	serviceClassStructArrayInterfacePropFloatChangedMethodID = nullptr;
	serviceClassStructArrayInterfacePropStringChangedMethodID = nullptr;
	serviceClassStructArrayInterfacePropEnumChangedMethodID = nullptr;
	serviceClassStructArrayInterfaceSigBoolSignalMethodID = nullptr;
	serviceClassStructArrayInterfaceSigIntSignalMethodID = nullptr;
	serviceClassStructArrayInterfaceSigFloatSignalMethodID = nullptr;
	serviceClassStructArrayInterfaceSigStringSignalMethodID = nullptr;
	serviceClassStructArrayInterfaceSigEnumSignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassStructArrayInterface);
	clientClassStructArrayInterface = nullptr;
	clientClassStructArrayInterfaceFuncBoolAsyncMethodID = nullptr;
	clientClassStructArrayInterfaceFuncIntAsyncMethodID = nullptr;
	clientClassStructArrayInterfaceFuncFloatAsyncMethodID = nullptr;
	clientClassStructArrayInterfaceFuncStringAsyncMethodID = nullptr;
	clientClassStructArrayInterfaceFuncEnumAsyncMethodID = nullptr;
	clientClassStructArrayInterfaceCtor = nullptr;
	clientClassStructArrayInterfaceBindMethodID = nullptr;
	clientClassStructArrayInterfaceUnbindMethodID = nullptr;
	env->DeleteGlobalRef(javaClassStructArray2Interface);
	javaClassStructArray2Interface = nullptr;
	javaClassStructArray2InterfacePropBoolSetterId = nullptr;
	javaClassStructArray2InterfacePropBoolGetterId = nullptr;
	javaClassStructArray2InterfacePropIntSetterId = nullptr;
	javaClassStructArray2InterfacePropIntGetterId = nullptr;
	javaClassStructArray2InterfacePropFloatSetterId = nullptr;
	javaClassStructArray2InterfacePropFloatGetterId = nullptr;
	javaClassStructArray2InterfacePropStringSetterId = nullptr;
	javaClassStructArray2InterfacePropStringGetterId = nullptr;
	javaClassStructArray2InterfacePropEnumSetterId = nullptr;
	javaClassStructArray2InterfacePropEnumGetterId = nullptr;
	env->DeleteGlobalRef(serviceClassStructArray2Interface);
	serviceClassStructArray2Interface = nullptr;
	serviceClassStructArray2InterfaceReadyMethodID = nullptr;
	serviceClassStructArray2InterfacePropBoolChangedMethodID = nullptr;
	serviceClassStructArray2InterfacePropIntChangedMethodID = nullptr;
	serviceClassStructArray2InterfacePropFloatChangedMethodID = nullptr;
	serviceClassStructArray2InterfacePropStringChangedMethodID = nullptr;
	serviceClassStructArray2InterfacePropEnumChangedMethodID = nullptr;
	serviceClassStructArray2InterfaceSigBoolSignalMethodID = nullptr;
	serviceClassStructArray2InterfaceSigIntSignalMethodID = nullptr;
	serviceClassStructArray2InterfaceSigFloatSignalMethodID = nullptr;
	serviceClassStructArray2InterfaceSigStringSignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassStructArray2Interface);
	clientClassStructArray2Interface = nullptr;
	clientClassStructArray2InterfaceFuncBoolAsyncMethodID = nullptr;
	clientClassStructArray2InterfaceFuncIntAsyncMethodID = nullptr;
	clientClassStructArray2InterfaceFuncFloatAsyncMethodID = nullptr;
	clientClassStructArray2InterfaceFuncStringAsyncMethodID = nullptr;
	clientClassStructArray2InterfaceFuncEnumAsyncMethodID = nullptr;
	clientClassStructArray2InterfaceCtor = nullptr;
	clientClassStructArray2InterfaceBindMethodID = nullptr;
	clientClassStructArray2InterfaceUnbindMethodID = nullptr;
}

bool Testbed1JniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
