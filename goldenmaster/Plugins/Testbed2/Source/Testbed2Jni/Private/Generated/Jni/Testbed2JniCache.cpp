
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

// TODO
// after each findJAvaClassGlobalRef and getting methodId or FieldId
// if (env->ExceptionCheck()) {
//	env->ExceptionDescribe(); // logs in java
//	env->ExceptionClear();
//	LOG UE;
//}

void Testbed2JniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	javaStructStruct1 = FAndroidApplication::FindJavaClassGlobalRef("Testbed2/Testbed2_api/Struct1");
	javaStructStruct1Ctor = env->GetMethodID(Testbed2JniCache::javaStructStruct1, "<init>", "()V");
	javaStructField1field1FieldId = env->GetFieldID(Testbed2JniCache::javaStructField1, "field1", "I");
	javaStructStruct2 = FAndroidApplication::FindJavaClassGlobalRef("Testbed2/Testbed2_api/Struct2");
	javaStructStruct2Ctor = env->GetMethodID(Testbed2JniCache::javaStructStruct2, "<init>", "()V");
	javaStructField1field1FieldId = env->GetFieldID(Testbed2JniCache::javaStructField1, "field1", "I");
	javaStructField2field2FieldId = env->GetFieldID(Testbed2JniCache::javaStructField2, "field2", "I");
	javaStructStruct3 = FAndroidApplication::FindJavaClassGlobalRef("Testbed2/Testbed2_api/Struct3");
	javaStructStruct3Ctor = env->GetMethodID(Testbed2JniCache::javaStructStruct3, "<init>", "()V");
	javaStructField1field1FieldId = env->GetFieldID(Testbed2JniCache::javaStructField1, "field1", "I");
	javaStructField2field2FieldId = env->GetFieldID(Testbed2JniCache::javaStructField2, "field2", "I");
	javaStructField3field3FieldId = env->GetFieldID(Testbed2JniCache::javaStructField3, "field3", "I");
	javaStructStruct4 = FAndroidApplication::FindJavaClassGlobalRef("Testbed2/Testbed2_api/Struct4");
	javaStructStruct4Ctor = env->GetMethodID(Testbed2JniCache::javaStructStruct4, "<init>", "()V");
	javaStructField1field1FieldId = env->GetFieldID(Testbed2JniCache::javaStructField1, "field1", "I");
	javaStructField2field2FieldId = env->GetFieldID(Testbed2JniCache::javaStructField2, "field2", "I");
	javaStructField3field3FieldId = env->GetFieldID(Testbed2JniCache::javaStructField3, "field3", "I");
	javaStructField4field4FieldId = env->GetFieldID(Testbed2JniCache::javaStructField4, "field4", "I");
	javaStructNestedStruct1 = FAndroidApplication::FindJavaClassGlobalRef("Testbed2/Testbed2_api/NestedStruct1");
	javaStructNestedStruct1Ctor = env->GetMethodID(Testbed2JniCache::javaStructNestedStruct1, "<init>", "()V");
	javaStructField1field1FieldId = env->GetFieldID(Testbed2JniCache::javaStructField1, "field1", "Ltestbed2/testbed2_api/Struct1;");
	javaStructNestedStruct2 = FAndroidApplication::FindJavaClassGlobalRef("Testbed2/Testbed2_api/NestedStruct2");
	javaStructNestedStruct2Ctor = env->GetMethodID(Testbed2JniCache::javaStructNestedStruct2, "<init>", "()V");
	javaStructField1field1FieldId = env->GetFieldID(Testbed2JniCache::javaStructField1, "field1", "Ltestbed2/testbed2_api/Struct1;");
	javaStructField2field2FieldId = env->GetFieldID(Testbed2JniCache::javaStructField2, "field2", "Ltestbed2/testbed2_api/Struct2;");
	javaStructNestedStruct3 = FAndroidApplication::FindJavaClassGlobalRef("Testbed2/Testbed2_api/NestedStruct3");
	javaStructNestedStruct3Ctor = env->GetMethodID(Testbed2JniCache::javaStructNestedStruct3, "<init>", "()V");
	javaStructField1field1FieldId = env->GetFieldID(Testbed2JniCache::javaStructField1, "field1", "Ltestbed2/testbed2_api/Struct1;");
	javaStructField2field2FieldId = env->GetFieldID(Testbed2JniCache::javaStructField2, "field2", "Ltestbed2/testbed2_api/Struct2;");
	javaStructField3field3FieldId = env->GetFieldID(Testbed2JniCache::javaStructField3, "field3", "Ltestbed2/testbed2_api/Struct3;");
	javaEnumEnum1 = FAndroidApplication::FindJavaClassGlobalRef("Testbed2/Testbed2_api/Enum1");
	javaEnumEnum1FromValueMethodId = env->GetStaticMethodID(Testbed2JniCache::javaEnumEnum1, "fromValue", "(I)LTestbed2/Testbed2_api/Enum1;");
	javaEnumEnum1GetValueMethod = env->GetMethodID(Testbed2JniCache::javaEnumEnum1, "getValue", "()I");
	javaEnumEnum2 = FAndroidApplication::FindJavaClassGlobalRef("Testbed2/Testbed2_api/Enum2");
	javaEnumEnum2FromValueMethodId = env->GetStaticMethodID(Testbed2JniCache::javaEnumEnum2, "fromValue", "(I)LTestbed2/Testbed2_api/Enum2;");
	javaEnumEnum2GetValueMethod = env->GetMethodID(Testbed2JniCache::javaEnumEnum2, "getValue", "()I");
	javaEnumEnum3 = FAndroidApplication::FindJavaClassGlobalRef("Testbed2/Testbed2_api/Enum3");
	javaEnumEnum3FromValueMethodId = env->GetStaticMethodID(Testbed2JniCache::javaEnumEnum3, "fromValue", "(I)LTestbed2/Testbed2_api/Enum3;");
	javaEnumEnum3GetValueMethod = env->GetMethodID(Testbed2JniCache::javaEnumEnum3, "getValue", "()I");

	javaClassManyParamInterface = FAndroidApplication::FindJavaClassGlobalRef("Testbed2/Testbed2_api/IManyParamInterface");
	javaClassManyParamInterfaceProp1SetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "setProp1", "(I)V");
	javaClassManyParamInterfaceProp1GetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "getProp1", "()I");
	javaClassManyParamInterfaceProp2SetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "setProp2", "(I)V");
	javaClassManyParamInterfaceProp2GetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "getProp2", "()I");
	javaClassManyParamInterfaceProp3SetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "setProp3", "(I)V");
	javaClassManyParamInterfaceProp3GetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "getProp3", "()I");
	javaClassManyParamInterfaceProp4SetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "setProp4", "(I)V");
	javaClassManyParamInterfaceProp4GetterId = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "getProp4", "()I");
	javaClassManyParamInterfaceSig1SignalMethodID = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "onSig1", "(I)V");
	javaClassManyParamInterfaceSig2SignalMethodID = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "onSig2", "(II)V");
	javaClassManyParamInterfaceSig3SignalMethodID = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "onSig3", "(III)V");
	javaClassManyParamInterfaceSig4SignalMethodID = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "onSig4", "(IIII)V");
	javaClassManyParamInterfaceFunc1MethodID = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "func1Async", "(Ljava/lang/String;I)V");
	javaClassManyParamInterfaceFunc2MethodID = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "func2Async", "(Ljava/lang/String;II)V");
	javaClassManyParamInterfaceFunc3MethodID = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "func3Async", "(Ljava/lang/String;III)V");
	javaClassManyParamInterfaceFunc4MethodID = env->GetMethodID(Testbed2JniCache::javaClassManyParamInterface, "func4Async", "(Ljava/lang/String;IIII)V");

	javaClassNestedStruct1Interface = FAndroidApplication::FindJavaClassGlobalRef("Testbed2/Testbed2_api/INestedStruct1Interface");
	javaClassNestedStruct1InterfaceProp1SetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct1Interface, "setProp1", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	javaClassNestedStruct1InterfaceProp1GetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct1Interface, "getProp1", "()Ltestbed2/testbed2_api/NestedStruct1;");
	javaClassNestedStruct1InterfaceSig1SignalMethodID = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct1Interface, "onSig1", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	javaClassNestedStruct1InterfaceFuncNoReturnValueMethodID = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct1Interface, "funcNoReturnValueAsync", "(Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;)V");
	javaClassNestedStruct1InterfaceFuncNoParamsMethodID = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct1Interface, "funcNoParamsAsync", "(Ljava/lang/String;)V");
	javaClassNestedStruct1InterfaceFunc1MethodID = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct1Interface, "func1Async", "(Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;)V");

	javaClassNestedStruct2Interface = FAndroidApplication::FindJavaClassGlobalRef("Testbed2/Testbed2_api/INestedStruct2Interface");
	javaClassNestedStruct2InterfaceProp1SetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct2Interface, "setProp1", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	javaClassNestedStruct2InterfaceProp1GetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct2Interface, "getProp1", "()Ltestbed2/testbed2_api/NestedStruct1;");
	javaClassNestedStruct2InterfaceProp2SetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct2Interface, "setProp2", "(Ltestbed2/testbed2_api/NestedStruct2;)V");
	javaClassNestedStruct2InterfaceProp2GetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct2Interface, "getProp2", "()Ltestbed2/testbed2_api/NestedStruct2;");
	javaClassNestedStruct2InterfaceSig1SignalMethodID = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct2Interface, "onSig1", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	javaClassNestedStruct2InterfaceSig2SignalMethodID = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct2Interface, "onSig2", "(Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;)V");
	javaClassNestedStruct2InterfaceFunc1MethodID = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct2Interface, "func1Async", "(Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;)V");
	javaClassNestedStruct2InterfaceFunc2MethodID = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct2Interface, "func2Async", "(Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;)V");

	javaClassNestedStruct3Interface = FAndroidApplication::FindJavaClassGlobalRef("Testbed2/Testbed2_api/INestedStruct3Interface");
	javaClassNestedStruct3InterfaceProp1SetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "setProp1", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	javaClassNestedStruct3InterfaceProp1GetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "getProp1", "()Ltestbed2/testbed2_api/NestedStruct1;");
	javaClassNestedStruct3InterfaceProp2SetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "setProp2", "(Ltestbed2/testbed2_api/NestedStruct2;)V");
	javaClassNestedStruct3InterfaceProp2GetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "getProp2", "()Ltestbed2/testbed2_api/NestedStruct2;");
	javaClassNestedStruct3InterfaceProp3SetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "setProp3", "(Ltestbed2/testbed2_api/NestedStruct3;)V");
	javaClassNestedStruct3InterfaceProp3GetterId = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "getProp3", "()Ltestbed2/testbed2_api/NestedStruct3;");
	javaClassNestedStruct3InterfaceSig1SignalMethodID = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "onSig1", "(Ltestbed2/testbed2_api/NestedStruct1;)V");
	javaClassNestedStruct3InterfaceSig2SignalMethodID = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "onSig2", "(Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;)V");
	javaClassNestedStruct3InterfaceSig3SignalMethodID = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "onSig3", "(Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;Ltestbed2/testbed2_api/NestedStruct3;)V");
	javaClassNestedStruct3InterfaceFunc1MethodID = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "func1Async", "(Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;)V");
	javaClassNestedStruct3InterfaceFunc2MethodID = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "func2Async", "(Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;)V");
	javaClassNestedStruct3InterfaceFunc3MethodID = env->GetMethodID(Testbed2JniCache::javaClassNestedStruct3Interface, "func3Async", "(Ljava/lang/String;Ltestbed2/testbed2_api/NestedStruct1;Ltestbed2/testbed2_api/NestedStruct2;Ltestbed2/testbed2_api/NestedStruct3;)V");
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
	javaClassManyParamInterfaceSig1SignalMethodID = nullptr;
	javaClassManyParamInterfaceSig2SignalMethodID = nullptr;
	javaClassManyParamInterfaceSig3SignalMethodID = nullptr;
	javaClassManyParamInterfaceSig4SignalMethodID = nullptr;
	javaClassManyParamInterfaceFunc1MethodID = nullptr;
	javaClassManyParamInterfaceFunc2MethodID = nullptr;
	javaClassManyParamInterfaceFunc3MethodID = nullptr;
	javaClassManyParamInterfaceFunc4MethodID = nullptr;
	env->DeleteGlobalRef(javaClassNestedStruct1Interface);
	javaClassNestedStruct1Interface = nullptr;
	javaClassNestedStruct1InterfaceProp1SetterId = nullptr;
	javaClassNestedStruct1InterfaceProp1GetterId = nullptr;
	javaClassNestedStruct1InterfaceSig1SignalMethodID = nullptr;
	javaClassNestedStruct1InterfaceFuncNoReturnValueMethodID = nullptr;
	javaClassNestedStruct1InterfaceFuncNoParamsMethodID = nullptr;
	javaClassNestedStruct1InterfaceFunc1MethodID = nullptr;
	env->DeleteGlobalRef(javaClassNestedStruct2Interface);
	javaClassNestedStruct2Interface = nullptr;
	javaClassNestedStruct2InterfaceProp1SetterId = nullptr;
	javaClassNestedStruct2InterfaceProp1GetterId = nullptr;
	javaClassNestedStruct2InterfaceProp2SetterId = nullptr;
	javaClassNestedStruct2InterfaceProp2GetterId = nullptr;
	javaClassNestedStruct2InterfaceSig1SignalMethodID = nullptr;
	javaClassNestedStruct2InterfaceSig2SignalMethodID = nullptr;
	javaClassNestedStruct2InterfaceFunc1MethodID = nullptr;
	javaClassNestedStruct2InterfaceFunc2MethodID = nullptr;
	env->DeleteGlobalRef(javaClassNestedStruct3Interface);
	javaClassNestedStruct3Interface = nullptr;
	javaClassNestedStruct3InterfaceProp1SetterId = nullptr;
	javaClassNestedStruct3InterfaceProp1GetterId = nullptr;
	javaClassNestedStruct3InterfaceProp2SetterId = nullptr;
	javaClassNestedStruct3InterfaceProp2GetterId = nullptr;
	javaClassNestedStruct3InterfaceProp3SetterId = nullptr;
	javaClassNestedStruct3InterfaceProp3GetterId = nullptr;
	javaClassNestedStruct3InterfaceSig1SignalMethodID = nullptr;
	javaClassNestedStruct3InterfaceSig2SignalMethodID = nullptr;
	javaClassNestedStruct3InterfaceSig3SignalMethodID = nullptr;
	javaClassNestedStruct3InterfaceFunc1MethodID = nullptr;
	javaClassNestedStruct3InterfaceFunc2MethodID = nullptr;
	javaClassNestedStruct3InterfaceFunc3MethodID = nullptr;
}

bool Testbed2JniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
