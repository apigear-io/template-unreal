
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

// TODO
// after each findJAvaClassGlobalRef and getting methodId or FieldId
// if (env->ExceptionCheck()) {
//	env->ExceptionDescribe(); // logs in java
//	env->ExceptionClear();
//	LOG UE;
//}

void TbSame1JniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	javaStructStruct1 = FAndroidApplication::FindJavaClassGlobalRef("TbSame1/TbSame1_api/Struct1");
	javaStructStruct1Ctor = env->GetMethodID(TbSame1JniCache::javaStructStruct1, "<init>", "()V");
	javaStructField1field1FieldId = env->GetFieldID(TbSame1JniCache::javaStructField1, "field1", "I");
	javaStructField2field2FieldId = env->GetFieldID(TbSame1JniCache::javaStructField2, "field2", "I");
	javaStructField3field3FieldId = env->GetFieldID(TbSame1JniCache::javaStructField3, "field3", "I");
	javaStructStruct2 = FAndroidApplication::FindJavaClassGlobalRef("TbSame1/TbSame1_api/Struct2");
	javaStructStruct2Ctor = env->GetMethodID(TbSame1JniCache::javaStructStruct2, "<init>", "()V");
	javaStructField1field1FieldId = env->GetFieldID(TbSame1JniCache::javaStructField1, "field1", "I");
	javaStructField2field2FieldId = env->GetFieldID(TbSame1JniCache::javaStructField2, "field2", "I");
	javaStructField3field3FieldId = env->GetFieldID(TbSame1JniCache::javaStructField3, "field3", "I");
	javaEnumEnum1 = FAndroidApplication::FindJavaClassGlobalRef("TbSame1/TbSame1_api/Enum1");
	javaEnumEnum1FromValueMethodId = env->GetStaticMethodID(TbSame1JniCache::javaEnumEnum1, "fromValue", "(I)LTbSame1/TbSame1_api/Enum1;");
	javaEnumEnum1GetValueMethod = env->GetMethodID(TbSame1JniCache::javaEnumEnum1, "getValue", "()I");
	javaEnumEnum2 = FAndroidApplication::FindJavaClassGlobalRef("TbSame1/TbSame1_api/Enum2");
	javaEnumEnum2FromValueMethodId = env->GetStaticMethodID(TbSame1JniCache::javaEnumEnum2, "fromValue", "(I)LTbSame1/TbSame1_api/Enum2;");
	javaEnumEnum2GetValueMethod = env->GetMethodID(TbSame1JniCache::javaEnumEnum2, "getValue", "()I");

	javaClassSameStruct1Interface = FAndroidApplication::FindJavaClassGlobalRef("TbSame1/TbSame1_api/ISameStruct1Interface");
	javaClassSameStruct1InterfaceProp1SetterId = env->GetMethodID(TbSame1JniCache::javaClassSameStruct1Interface, "setProp1", "(LtbSame1/tbSame1_api/Struct1;)V");
	javaClassSameStruct1InterfaceProp1GetterId = env->GetMethodID(TbSame1JniCache::javaClassSameStruct1Interface, "getProp1", "()LtbSame1/tbSame1_api/Struct1;");
	javaClassSameStruct1InterfaceSig1SignalMethodID = env->GetMethodID(TbSame1JniCache::javaClassSameStruct1Interface, "onSig1", "(LtbSame1/tbSame1_api/Struct1;)V");
	javaClassSameStruct1InterfaceFunc1MethodID = env->GetMethodID(TbSame1JniCache::javaClassSameStruct1Interface, "func1Async", "(Ljava/lang/String;LtbSame1/tbSame1_api/Struct1;)V");

	javaClassSameStruct2Interface = FAndroidApplication::FindJavaClassGlobalRef("TbSame1/TbSame1_api/ISameStruct2Interface");
	javaClassSameStruct2InterfaceProp1SetterId = env->GetMethodID(TbSame1JniCache::javaClassSameStruct2Interface, "setProp1", "(LtbSame1/tbSame1_api/Struct2;)V");
	javaClassSameStruct2InterfaceProp1GetterId = env->GetMethodID(TbSame1JniCache::javaClassSameStruct2Interface, "getProp1", "()LtbSame1/tbSame1_api/Struct2;");
	javaClassSameStruct2InterfaceProp2SetterId = env->GetMethodID(TbSame1JniCache::javaClassSameStruct2Interface, "setProp2", "(LtbSame1/tbSame1_api/Struct2;)V");
	javaClassSameStruct2InterfaceProp2GetterId = env->GetMethodID(TbSame1JniCache::javaClassSameStruct2Interface, "getProp2", "()LtbSame1/tbSame1_api/Struct2;");
	javaClassSameStruct2InterfaceSig1SignalMethodID = env->GetMethodID(TbSame1JniCache::javaClassSameStruct2Interface, "onSig1", "(LtbSame1/tbSame1_api/Struct1;)V");
	javaClassSameStruct2InterfaceSig2SignalMethodID = env->GetMethodID(TbSame1JniCache::javaClassSameStruct2Interface, "onSig2", "(LtbSame1/tbSame1_api/Struct1;LtbSame1/tbSame1_api/Struct2;)V");
	javaClassSameStruct2InterfaceFunc1MethodID = env->GetMethodID(TbSame1JniCache::javaClassSameStruct2Interface, "func1Async", "(Ljava/lang/String;LtbSame1/tbSame1_api/Struct1;)V");
	javaClassSameStruct2InterfaceFunc2MethodID = env->GetMethodID(TbSame1JniCache::javaClassSameStruct2Interface, "func2Async", "(Ljava/lang/String;LtbSame1/tbSame1_api/Struct1;LtbSame1/tbSame1_api/Struct2;)V");

	javaClassSameEnum1Interface = FAndroidApplication::FindJavaClassGlobalRef("TbSame1/TbSame1_api/ISameEnum1Interface");
	javaClassSameEnum1InterfaceProp1SetterId = env->GetMethodID(TbSame1JniCache::javaClassSameEnum1Interface, "setProp1", "(LtbSame1/tbSame1_api/Enum1;)V");
	javaClassSameEnum1InterfaceProp1GetterId = env->GetMethodID(TbSame1JniCache::javaClassSameEnum1Interface, "getProp1", "()LtbSame1/tbSame1_api/Enum1;");
	javaClassSameEnum1InterfaceSig1SignalMethodID = env->GetMethodID(TbSame1JniCache::javaClassSameEnum1Interface, "onSig1", "(LtbSame1/tbSame1_api/Enum1;)V");
	javaClassSameEnum1InterfaceFunc1MethodID = env->GetMethodID(TbSame1JniCache::javaClassSameEnum1Interface, "func1Async", "(Ljava/lang/String;LtbSame1/tbSame1_api/Enum1;)V");

	javaClassSameEnum2Interface = FAndroidApplication::FindJavaClassGlobalRef("TbSame1/TbSame1_api/ISameEnum2Interface");
	javaClassSameEnum2InterfaceProp1SetterId = env->GetMethodID(TbSame1JniCache::javaClassSameEnum2Interface, "setProp1", "(LtbSame1/tbSame1_api/Enum1;)V");
	javaClassSameEnum2InterfaceProp1GetterId = env->GetMethodID(TbSame1JniCache::javaClassSameEnum2Interface, "getProp1", "()LtbSame1/tbSame1_api/Enum1;");
	javaClassSameEnum2InterfaceProp2SetterId = env->GetMethodID(TbSame1JniCache::javaClassSameEnum2Interface, "setProp2", "(LtbSame1/tbSame1_api/Enum2;)V");
	javaClassSameEnum2InterfaceProp2GetterId = env->GetMethodID(TbSame1JniCache::javaClassSameEnum2Interface, "getProp2", "()LtbSame1/tbSame1_api/Enum2;");
	javaClassSameEnum2InterfaceSig1SignalMethodID = env->GetMethodID(TbSame1JniCache::javaClassSameEnum2Interface, "onSig1", "(LtbSame1/tbSame1_api/Enum1;)V");
	javaClassSameEnum2InterfaceSig2SignalMethodID = env->GetMethodID(TbSame1JniCache::javaClassSameEnum2Interface, "onSig2", "(LtbSame1/tbSame1_api/Enum1;LtbSame1/tbSame1_api/Enum2;)V");
	javaClassSameEnum2InterfaceFunc1MethodID = env->GetMethodID(TbSame1JniCache::javaClassSameEnum2Interface, "func1Async", "(Ljava/lang/String;LtbSame1/tbSame1_api/Enum1;)V");
	javaClassSameEnum2InterfaceFunc2MethodID = env->GetMethodID(TbSame1JniCache::javaClassSameEnum2Interface, "func2Async", "(Ljava/lang/String;LtbSame1/tbSame1_api/Enum1;LtbSame1/tbSame1_api/Enum2;)V");
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
	javaClassSameStruct1InterfaceSig1SignalMethodID = nullptr;
	javaClassSameStruct1InterfaceFunc1MethodID = nullptr;
	env->DeleteGlobalRef(javaClassSameStruct2Interface);
	javaClassSameStruct2Interface = nullptr;
	javaClassSameStruct2InterfaceProp1SetterId = nullptr;
	javaClassSameStruct2InterfaceProp1GetterId = nullptr;
	javaClassSameStruct2InterfaceProp2SetterId = nullptr;
	javaClassSameStruct2InterfaceProp2GetterId = nullptr;
	javaClassSameStruct2InterfaceSig1SignalMethodID = nullptr;
	javaClassSameStruct2InterfaceSig2SignalMethodID = nullptr;
	javaClassSameStruct2InterfaceFunc1MethodID = nullptr;
	javaClassSameStruct2InterfaceFunc2MethodID = nullptr;
	env->DeleteGlobalRef(javaClassSameEnum1Interface);
	javaClassSameEnum1Interface = nullptr;
	javaClassSameEnum1InterfaceProp1SetterId = nullptr;
	javaClassSameEnum1InterfaceProp1GetterId = nullptr;
	javaClassSameEnum1InterfaceSig1SignalMethodID = nullptr;
	javaClassSameEnum1InterfaceFunc1MethodID = nullptr;
	env->DeleteGlobalRef(javaClassSameEnum2Interface);
	javaClassSameEnum2Interface = nullptr;
	javaClassSameEnum2InterfaceProp1SetterId = nullptr;
	javaClassSameEnum2InterfaceProp1GetterId = nullptr;
	javaClassSameEnum2InterfaceProp2SetterId = nullptr;
	javaClassSameEnum2InterfaceProp2GetterId = nullptr;
	javaClassSameEnum2InterfaceSig1SignalMethodID = nullptr;
	javaClassSameEnum2InterfaceSig2SignalMethodID = nullptr;
	javaClassSameEnum2InterfaceFunc1MethodID = nullptr;
	javaClassSameEnum2InterfaceFunc2MethodID = nullptr;
}

bool TbSame1JniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
