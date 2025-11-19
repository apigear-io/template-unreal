
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
#pragma once

#include "CoreMinimal.h"

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

class TESTBED2API_API Testbed2JniCache
{
	static jclass javaStructStruct1 = nullptr;
	static jmethodID javaStructStruct1Ctor = nullptr;
	static jfieldID javaStructStruct1Field1FieldId = nullptr;
	static jclass javaStructStruct2 = nullptr;
	static jmethodID javaStructStruct2Ctor = nullptr;
	static jfieldID javaStructStruct2Field1FieldId = nullptr;
	static jfieldID javaStructStruct2Field2FieldId = nullptr;
	static jclass javaStructStruct3 = nullptr;
	static jmethodID javaStructStruct3Ctor = nullptr;
	static jfieldID javaStructStruct3Field1FieldId = nullptr;
	static jfieldID javaStructStruct3Field2FieldId = nullptr;
	static jfieldID javaStructStruct3Field3FieldId = nullptr;
	static jclass javaStructStruct4 = nullptr;
	static jmethodID javaStructStruct4Ctor = nullptr;
	static jfieldID javaStructStruct4Field1FieldId = nullptr;
	static jfieldID javaStructStruct4Field2FieldId = nullptr;
	static jfieldID javaStructStruct4Field3FieldId = nullptr;
	static jfieldID javaStructStruct4Field4FieldId = nullptr;
	static jclass javaStructNestedStruct1 = nullptr;
	static jmethodID javaStructNestedStruct1Ctor = nullptr;
	static jfieldID javaStructNestedStruct1Field1FieldId = nullptr;
	static jclass javaStructNestedStruct2 = nullptr;
	static jmethodID javaStructNestedStruct2Ctor = nullptr;
	static jfieldID javaStructNestedStruct2Field1FieldId = nullptr;
	static jfieldID javaStructNestedStruct2Field2FieldId = nullptr;
	static jclass javaStructNestedStruct3 = nullptr;
	static jmethodID javaStructNestedStruct3Ctor = nullptr;
	static jfieldID javaStructNestedStruct3Field1FieldId = nullptr;
	static jfieldID javaStructNestedStruct3Field2FieldId = nullptr;
	static jfieldID javaStructNestedStruct3Field3FieldId = nullptr;
	static jclass javaEnumEnum1 = nullptr;
	static jmethodID javaEnumEnum1FromValueMethodId = nullptr;
	static jmethodID javaEnumEnum1GetValueMethod = nullptr;
	static jclass javaEnumEnum2 = nullptr;
	static jmethodID javaEnumEnum2FromValueMethodId = nullptr;
	static jmethodID javaEnumEnum2GetValueMethod = nullptr;
	static jclass javaEnumEnum3 = nullptr;
	static jmethodID javaEnumEnum3FromValueMethodId = nullptr;
	static jmethodID javaEnumEnum3GetValueMethod = nullptr;
	static jclass javaClassManyParamInterface = nullptr;
	static jmethodID javaClassManyParamInterfaceProp1SetterId = nullptr;
	static jmethodID javaClassManyParamInterfaceProp1GetterId = nullptr;
	static jmethodID javaClassManyParamInterfaceProp2SetterId = nullptr;
	static jmethodID javaClassManyParamInterfaceProp2GetterId = nullptr;
	static jmethodID javaClassManyParamInterfaceProp3SetterId = nullptr;
	static jmethodID javaClassManyParamInterfaceProp3GetterId = nullptr;
	static jmethodID javaClassManyParamInterfaceProp4SetterId = nullptr;
	static jmethodID javaClassManyParamInterfaceProp4GetterId = nullptr;
	static jmethodID javaClassManyParamInterfaceSig1SignalMethodID = nullptr;
	static jmethodID javaClassManyParamInterfaceSig2SignalMethodID = nullptr;
	static jmethodID javaClassManyParamInterfaceSig3SignalMethodID = nullptr;
	static jmethodID javaClassManyParamInterfaceSig4SignalMethodID = nullptr;
	static jmethodID javaClassManyParamInterfaceFunc1MethodID = nullptr;
	static jmethodID javaClassManyParamInterfaceFunc2MethodID = nullptr;
	static jmethodID javaClassManyParamInterfaceFunc3MethodID = nullptr;
	static jmethodID javaClassManyParamInterfaceFunc4MethodID = nullptr;
	static jclass javaClassNestedStruct1Interface = nullptr;
	static jmethodID javaClassNestedStruct1InterfaceProp1SetterId = nullptr;
	static jmethodID javaClassNestedStruct1InterfaceProp1GetterId = nullptr;
	static jmethodID javaClassNestedStruct1InterfaceSig1SignalMethodID = nullptr;
	static jmethodID javaClassNestedStruct1InterfaceFuncNoReturnValueMethodID = nullptr;
	static jmethodID javaClassNestedStruct1InterfaceFuncNoParamsMethodID = nullptr;
	static jmethodID javaClassNestedStruct1InterfaceFunc1MethodID = nullptr;
	static jclass javaClassNestedStruct2Interface = nullptr;
	static jmethodID javaClassNestedStruct2InterfaceProp1SetterId = nullptr;
	static jmethodID javaClassNestedStruct2InterfaceProp1GetterId = nullptr;
	static jmethodID javaClassNestedStruct2InterfaceProp2SetterId = nullptr;
	static jmethodID javaClassNestedStruct2InterfaceProp2GetterId = nullptr;
	static jmethodID javaClassNestedStruct2InterfaceSig1SignalMethodID = nullptr;
	static jmethodID javaClassNestedStruct2InterfaceSig2SignalMethodID = nullptr;
	static jmethodID javaClassNestedStruct2InterfaceFunc1MethodID = nullptr;
	static jmethodID javaClassNestedStruct2InterfaceFunc2MethodID = nullptr;
	static jclass javaClassNestedStruct3Interface = nullptr;
	static jmethodID javaClassNestedStruct3InterfaceProp1SetterId = nullptr;
	static jmethodID javaClassNestedStruct3InterfaceProp1GetterId = nullptr;
	static jmethodID javaClassNestedStruct3InterfaceProp2SetterId = nullptr;
	static jmethodID javaClassNestedStruct3InterfaceProp2GetterId = nullptr;
	static jmethodID javaClassNestedStruct3InterfaceProp3SetterId = nullptr;
	static jmethodID javaClassNestedStruct3InterfaceProp3GetterId = nullptr;
	static jmethodID javaClassNestedStruct3InterfaceSig1SignalMethodID = nullptr;
	static jmethodID javaClassNestedStruct3InterfaceSig2SignalMethodID = nullptr;
	static jmethodID javaClassNestedStruct3InterfaceSig3SignalMethodID = nullptr;
	static jmethodID javaClassNestedStruct3InterfaceFunc1MethodID = nullptr;
	static jmethodID javaClassNestedStruct3InterfaceFunc2MethodID = nullptr;
	static jmethodID javaClassNestedStruct3InterfaceFunc3MethodID = nullptr;

	static void init();
	static void clear();
	static bool isInitialized();

private:
	static bool m_isInitialized = false;
}

#endif
