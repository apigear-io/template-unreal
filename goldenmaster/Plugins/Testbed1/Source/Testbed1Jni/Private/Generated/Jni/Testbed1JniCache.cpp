
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

void Testbed1JniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	javaStructStructBool = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/StructBool");
	javaStructStructBoolCtor = env->GetMethodID(Testbed1JniCache::javaStructStructBool, "<init>", "()V");
	javaStructFieldBoolfield_boolFieldId = env->GetFieldID(Testbed1JniCache::javaStructFieldBool, "fieldBool", "Z");
	javaStructStructInt = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/StructInt");
	javaStructStructIntCtor = env->GetMethodID(Testbed1JniCache::javaStructStructInt, "<init>", "()V");
	javaStructFieldIntfield_intFieldId = env->GetFieldID(Testbed1JniCache::javaStructFieldInt, "fieldInt", "I");
	javaStructStructFloat = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/StructFloat");
	javaStructStructFloatCtor = env->GetMethodID(Testbed1JniCache::javaStructStructFloat, "<init>", "()V");
	javaStructFieldFloatfield_floatFieldId = env->GetFieldID(Testbed1JniCache::javaStructFieldFloat, "fieldFloat", "F");
	javaStructStructString = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/StructString");
	javaStructStructStringCtor = env->GetMethodID(Testbed1JniCache::javaStructStructString, "<init>", "()V");
	javaStructFieldStringfield_stringFieldId = env->GetFieldID(Testbed1JniCache::javaStructFieldString, "fieldString", "Ljava/lang/String;");
	javaStructStructStruct = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/StructStruct");
	javaStructStructStructCtor = env->GetMethodID(Testbed1JniCache::javaStructStructStruct, "<init>", "()V");
	javaStructFieldStringfield_stringFieldId = env->GetFieldID(Testbed1JniCache::javaStructFieldString, "fieldString", "Ltestbed1/testbed1_api/StructString;");
	javaStructStructEnum = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/StructEnum");
	javaStructStructEnumCtor = env->GetMethodID(Testbed1JniCache::javaStructStructEnum, "<init>", "()V");
	javaStructFieldEnumfield_enumFieldId = env->GetFieldID(Testbed1JniCache::javaStructFieldEnum, "fieldEnum", "Ltestbed1/testbed1_api/Enum0;");
	javaStructStructBoolWithArray = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/StructBoolWithArray");
	javaStructStructBoolWithArrayCtor = env->GetMethodID(Testbed1JniCache::javaStructStructBoolWithArray, "<init>", "()V");
	javaStructFieldBoolfield_boolFieldId = env->GetFieldID(Testbed1JniCache::javaStructFieldBool, "fieldBool", "[Z");
	javaStructStructIntWithArray = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/StructIntWithArray");
	javaStructStructIntWithArrayCtor = env->GetMethodID(Testbed1JniCache::javaStructStructIntWithArray, "<init>", "()V");
	javaStructFieldIntfield_intFieldId = env->GetFieldID(Testbed1JniCache::javaStructFieldInt, "fieldInt", "[I");
	javaStructStructFloatWithArray = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/StructFloatWithArray");
	javaStructStructFloatWithArrayCtor = env->GetMethodID(Testbed1JniCache::javaStructStructFloatWithArray, "<init>", "()V");
	javaStructFieldFloatfield_floatFieldId = env->GetFieldID(Testbed1JniCache::javaStructFieldFloat, "fieldFloat", "[F");
	javaStructStructStringWithArray = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/StructStringWithArray");
	javaStructStructStringWithArrayCtor = env->GetMethodID(Testbed1JniCache::javaStructStructStringWithArray, "<init>", "()V");
	javaStructFieldStringfield_stringFieldId = env->GetFieldID(Testbed1JniCache::javaStructFieldString, "fieldString", "[Ljava/lang/String;");
	javaStructStructStructWithArray = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/StructStructWithArray");
	javaStructStructStructWithArrayCtor = env->GetMethodID(Testbed1JniCache::javaStructStructStructWithArray, "<init>", "()V");
	javaStructFieldStructfield_structFieldId = env->GetFieldID(Testbed1JniCache::javaStructFieldStruct, "fieldStruct", "[Ltestbed1/testbed1_api/StructStringWithArray;");
	javaStructStructEnumWithArray = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/StructEnumWithArray");
	javaStructStructEnumWithArrayCtor = env->GetMethodID(Testbed1JniCache::javaStructStructEnumWithArray, "<init>", "()V");
	javaStructFieldEnumfield_enumFieldId = env->GetFieldID(Testbed1JniCache::javaStructFieldEnum, "fieldEnum", "[Ltestbed1/testbed1_api/Enum0;");
	javaEnumEnum0 = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/Enum0");
	javaEnumEnum0FromValueMethodId = env->GetStaticMethodID(Testbed1JniCache::javaEnumEnum0, "fromValue", "(I)LTestbed1/Testbed1_api/Enum0;");
	javaEnumEnum0GetValueMethod = env->GetMethodID(Testbed1JniCache::javaEnumEnum0, "getValue", "()I");

	javaClassStructInterface = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/IStructInterface");
	javaClassStructInterfacePropBoolSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "setPropBool", "(Ltestbed1/testbed1_api/StructBool;)V");
	javaClassStructInterfacePropBoolGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "getPropBool", "()Ltestbed1/testbed1_api/StructBool;");
	javaClassStructInterfacePropIntSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "setPropInt", "(Ltestbed1/testbed1_api/StructInt;)V");
	javaClassStructInterfacePropIntGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "getPropInt", "()Ltestbed1/testbed1_api/StructInt;");
	javaClassStructInterfacePropFloatSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "setPropFloat", "(Ltestbed1/testbed1_api/StructFloat;)V");
	javaClassStructInterfacePropFloatGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "getPropFloat", "()Ltestbed1/testbed1_api/StructFloat;");
	javaClassStructInterfacePropStringSetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "setPropString", "(Ltestbed1/testbed1_api/StructString;)V");
	javaClassStructInterfacePropStringGetterId = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "getPropString", "()Ltestbed1/testbed1_api/StructString;");
	javaClassStructInterfaceSigBoolSignalMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "onSigBool", "(Ltestbed1/testbed1_api/StructBool;)V");
	javaClassStructInterfaceSigIntSignalMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "onSigInt", "(Ltestbed1/testbed1_api/StructInt;)V");
	javaClassStructInterfaceSigFloatSignalMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "onSigFloat", "(Ltestbed1/testbed1_api/StructFloat;)V");
	javaClassStructInterfaceSigStringSignalMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "onSigString", "(Ltestbed1/testbed1_api/StructString;)V");
	javaClassStructInterfaceFuncBoolMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "funcBoolAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructBool;)V");
	javaClassStructInterfaceFuncIntMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "funcIntAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructInt;)V");
	javaClassStructInterfaceFuncFloatMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "funcFloatAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructFloat;)V");
	javaClassStructInterfaceFuncStringMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructInterface, "funcStringAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructString;)V");

	javaClassStructArrayInterface = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/IStructArrayInterface");
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
	javaClassStructArrayInterfaceSigBoolSignalMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "onSigBool", "([Ltestbed1/testbed1_api/StructBool;)V");
	javaClassStructArrayInterfaceSigIntSignalMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "onSigInt", "([Ltestbed1/testbed1_api/StructInt;)V");
	javaClassStructArrayInterfaceSigFloatSignalMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "onSigFloat", "([Ltestbed1/testbed1_api/StructFloat;)V");
	javaClassStructArrayInterfaceSigStringSignalMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "onSigString", "([Ltestbed1/testbed1_api/StructString;)V");
	javaClassStructArrayInterfaceSigEnumSignalMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "onSigEnum", "([Ltestbed1/testbed1_api/Enum0;)V");
	javaClassStructArrayInterfaceFuncBoolMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "funcBoolAsync", "(Ljava/lang/String;[Ltestbed1/testbed1_api/StructBool;)V");
	javaClassStructArrayInterfaceFuncIntMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "funcIntAsync", "(Ljava/lang/String;[Ltestbed1/testbed1_api/StructInt;)V");
	javaClassStructArrayInterfaceFuncFloatMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "funcFloatAsync", "(Ljava/lang/String;[Ltestbed1/testbed1_api/StructFloat;)V");
	javaClassStructArrayInterfaceFuncStringMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "funcStringAsync", "(Ljava/lang/String;[Ltestbed1/testbed1_api/StructString;)V");
	javaClassStructArrayInterfaceFuncEnumMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArrayInterface, "funcEnumAsync", "(Ljava/lang/String;[Ltestbed1/testbed1_api/Enum0;)V");

	javaClassStructArray2Interface = FAndroidApplication::FindJavaClassGlobalRef("Testbed1/Testbed1_api/IStructArray2Interface");
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
	javaClassStructArray2InterfaceSigBoolSignalMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "onSigBool", "(Ltestbed1/testbed1_api/StructBoolWithArray;)V");
	javaClassStructArray2InterfaceSigIntSignalMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "onSigInt", "(Ltestbed1/testbed1_api/StructIntWithArray;)V");
	javaClassStructArray2InterfaceSigFloatSignalMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "onSigFloat", "(Ltestbed1/testbed1_api/StructFloatWithArray;)V");
	javaClassStructArray2InterfaceSigStringSignalMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "onSigString", "(Ltestbed1/testbed1_api/StructStringWithArray;)V");
	javaClassStructArray2InterfaceFuncBoolMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "funcBoolAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructBoolWithArray;)V");
	javaClassStructArray2InterfaceFuncIntMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "funcIntAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructIntWithArray;)V");
	javaClassStructArray2InterfaceFuncFloatMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "funcFloatAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructFloatWithArray;)V");
	javaClassStructArray2InterfaceFuncStringMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "funcStringAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructStringWithArray;)V");
	javaClassStructArray2InterfaceFuncEnumMethodID = env->GetMethodID(Testbed1JniCache::javaClassStructArray2Interface, "funcEnumAsync", "(Ljava/lang/String;Ltestbed1/testbed1_api/StructEnumWithArray;)V");
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
	javaClassStructInterfaceSigBoolSignalMethodID = nullptr;
	javaClassStructInterfaceSigIntSignalMethodID = nullptr;
	javaClassStructInterfaceSigFloatSignalMethodID = nullptr;
	javaClassStructInterfaceSigStringSignalMethodID = nullptr;
	javaClassStructInterfaceFuncBoolMethodID = nullptr;
	javaClassStructInterfaceFuncIntMethodID = nullptr;
	javaClassStructInterfaceFuncFloatMethodID = nullptr;
	javaClassStructInterfaceFuncStringMethodID = nullptr;
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
	javaClassStructArrayInterfaceSigBoolSignalMethodID = nullptr;
	javaClassStructArrayInterfaceSigIntSignalMethodID = nullptr;
	javaClassStructArrayInterfaceSigFloatSignalMethodID = nullptr;
	javaClassStructArrayInterfaceSigStringSignalMethodID = nullptr;
	javaClassStructArrayInterfaceSigEnumSignalMethodID = nullptr;
	javaClassStructArrayInterfaceFuncBoolMethodID = nullptr;
	javaClassStructArrayInterfaceFuncIntMethodID = nullptr;
	javaClassStructArrayInterfaceFuncFloatMethodID = nullptr;
	javaClassStructArrayInterfaceFuncStringMethodID = nullptr;
	javaClassStructArrayInterfaceFuncEnumMethodID = nullptr;
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
	javaClassStructArray2InterfaceSigBoolSignalMethodID = nullptr;
	javaClassStructArray2InterfaceSigIntSignalMethodID = nullptr;
	javaClassStructArray2InterfaceSigFloatSignalMethodID = nullptr;
	javaClassStructArray2InterfaceSigStringSignalMethodID = nullptr;
	javaClassStructArray2InterfaceFuncBoolMethodID = nullptr;
	javaClassStructArray2InterfaceFuncIntMethodID = nullptr;
	javaClassStructArray2InterfaceFuncFloatMethodID = nullptr;
	javaClassStructArray2InterfaceFuncStringMethodID = nullptr;
	javaClassStructArray2InterfaceFuncEnumMethodID = nullptr;
}

bool Testbed1JniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
