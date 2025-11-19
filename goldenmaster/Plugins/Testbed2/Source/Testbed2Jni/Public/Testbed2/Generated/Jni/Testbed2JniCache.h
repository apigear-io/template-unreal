
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
public:
	static jclass javaStructStruct1;
	static jmethodID javaStructStruct1Ctor;
	static jfieldID javaStructStruct1Field1FieldId;
	static jclass javaStructStruct2;
	static jmethodID javaStructStruct2Ctor;
	static jfieldID javaStructStruct2Field1FieldId;
	static jfieldID javaStructStruct2Field2FieldId;
	static jclass javaStructStruct3;
	static jmethodID javaStructStruct3Ctor;
	static jfieldID javaStructStruct3Field1FieldId;
	static jfieldID javaStructStruct3Field2FieldId;
	static jfieldID javaStructStruct3Field3FieldId;
	static jclass javaStructStruct4;
	static jmethodID javaStructStruct4Ctor;
	static jfieldID javaStructStruct4Field1FieldId;
	static jfieldID javaStructStruct4Field2FieldId;
	static jfieldID javaStructStruct4Field3FieldId;
	static jfieldID javaStructStruct4Field4FieldId;
	static jclass javaStructNestedStruct1;
	static jmethodID javaStructNestedStruct1Ctor;
	static jfieldID javaStructNestedStruct1Field1FieldId;
	static jclass javaStructNestedStruct2;
	static jmethodID javaStructNestedStruct2Ctor;
	static jfieldID javaStructNestedStruct2Field1FieldId;
	static jfieldID javaStructNestedStruct2Field2FieldId;
	static jclass javaStructNestedStruct3;
	static jmethodID javaStructNestedStruct3Ctor;
	static jfieldID javaStructNestedStruct3Field1FieldId;
	static jfieldID javaStructNestedStruct3Field2FieldId;
	static jfieldID javaStructNestedStruct3Field3FieldId;
	static jclass javaEnumEnum1;
	static jmethodID javaEnumEnum1FromValueMethodId;
	static jmethodID javaEnumEnum1GetValueMethod;
	static jclass javaEnumEnum2;
	static jmethodID javaEnumEnum2FromValueMethodId;
	static jmethodID javaEnumEnum2GetValueMethod;
	static jclass javaEnumEnum3;
	static jmethodID javaEnumEnum3FromValueMethodId;
	static jmethodID javaEnumEnum3GetValueMethod;
	static jclass javaClassManyParamInterface;
	static jmethodID javaClassManyParamInterfaceProp1SetterId;
	static jmethodID javaClassManyParamInterfaceProp1GetterId;
	static jmethodID javaClassManyParamInterfaceProp1ChangedMethodID;
	static jmethodID javaClassManyParamInterfaceProp2SetterId;
	static jmethodID javaClassManyParamInterfaceProp2GetterId;
	static jmethodID javaClassManyParamInterfaceProp2ChangedMethodID;
	static jmethodID javaClassManyParamInterfaceProp3SetterId;
	static jmethodID javaClassManyParamInterfaceProp3GetterId;
	static jmethodID javaClassManyParamInterfaceProp3ChangedMethodID;
	static jmethodID javaClassManyParamInterfaceProp4SetterId;
	static jmethodID javaClassManyParamInterfaceProp4GetterId;
	static jmethodID javaClassManyParamInterfaceProp4ChangedMethodID;
	static jclass serviceClassManyParamInterface;
	static jmethodID serviceClassManyParamInterfaceReadyMethodID;
	static jmethodID serviceClassManyParamInterfaceProp1ChangedMethodID;
	static jmethodID serviceClassManyParamInterfaceProp2ChangedMethodID;
	static jmethodID serviceClassManyParamInterfaceProp3ChangedMethodID;
	static jmethodID serviceClassManyParamInterfaceProp4ChangedMethodID;
	static jmethodID serviceClassManyParamInterfaceSig1SignalMethodID;
	static jmethodID serviceClassManyParamInterfaceSig2SignalMethodID;
	static jmethodID serviceClassManyParamInterfaceSig3SignalMethodID;
	static jmethodID serviceClassManyParamInterfaceSig4SignalMethodID;
	static jclass clientClassManyParamInterface;
	static jmethodID clientClassManyParamInterfaceCtor;
	static jmethodID clientClassManyParamInterfaceBindMethodID;
	static jmethodID clientClassManyParamInterfaceUnbindMethodID;
	static jmethodID clientClassManyParamInterfaceFunc1AsyncMethodID;
	static jmethodID clientClassManyParamInterfaceFunc2AsyncMethodID;
	static jmethodID clientClassManyParamInterfaceFunc3AsyncMethodID;
	static jmethodID clientClassManyParamInterfaceFunc4AsyncMethodID;
	static jclass javaClassNestedStruct1Interface;
	static jmethodID javaClassNestedStruct1InterfaceProp1SetterId;
	static jmethodID javaClassNestedStruct1InterfaceProp1GetterId;
	static jmethodID javaClassNestedStruct1InterfaceProp1ChangedMethodID;
	static jclass serviceClassNestedStruct1Interface;
	static jmethodID serviceClassNestedStruct1InterfaceReadyMethodID;
	static jmethodID serviceClassNestedStruct1InterfaceProp1ChangedMethodID;
	static jmethodID serviceClassNestedStruct1InterfaceSig1SignalMethodID;
	static jclass clientClassNestedStruct1Interface;
	static jmethodID clientClassNestedStruct1InterfaceCtor;
	static jmethodID clientClassNestedStruct1InterfaceBindMethodID;
	static jmethodID clientClassNestedStruct1InterfaceUnbindMethodID;
	static jmethodID clientClassNestedStruct1InterfaceFuncNoReturnValueAsyncMethodID;
	static jmethodID clientClassNestedStruct1InterfaceFuncNoParamsAsyncMethodID;
	static jmethodID clientClassNestedStruct1InterfaceFunc1AsyncMethodID;
	static jclass javaClassNestedStruct2Interface;
	static jmethodID javaClassNestedStruct2InterfaceProp1SetterId;
	static jmethodID javaClassNestedStruct2InterfaceProp1GetterId;
	static jmethodID javaClassNestedStruct2InterfaceProp1ChangedMethodID;
	static jmethodID javaClassNestedStruct2InterfaceProp2SetterId;
	static jmethodID javaClassNestedStruct2InterfaceProp2GetterId;
	static jmethodID javaClassNestedStruct2InterfaceProp2ChangedMethodID;
	static jclass serviceClassNestedStruct2Interface;
	static jmethodID serviceClassNestedStruct2InterfaceReadyMethodID;
	static jmethodID serviceClassNestedStruct2InterfaceProp1ChangedMethodID;
	static jmethodID serviceClassNestedStruct2InterfaceProp2ChangedMethodID;
	static jmethodID serviceClassNestedStruct2InterfaceSig1SignalMethodID;
	static jmethodID serviceClassNestedStruct2InterfaceSig2SignalMethodID;
	static jclass clientClassNestedStruct2Interface;
	static jmethodID clientClassNestedStruct2InterfaceCtor;
	static jmethodID clientClassNestedStruct2InterfaceBindMethodID;
	static jmethodID clientClassNestedStruct2InterfaceUnbindMethodID;
	static jmethodID clientClassNestedStruct2InterfaceFunc1AsyncMethodID;
	static jmethodID clientClassNestedStruct2InterfaceFunc2AsyncMethodID;
	static jclass javaClassNestedStruct3Interface;
	static jmethodID javaClassNestedStruct3InterfaceProp1SetterId;
	static jmethodID javaClassNestedStruct3InterfaceProp1GetterId;
	static jmethodID javaClassNestedStruct3InterfaceProp1ChangedMethodID;
	static jmethodID javaClassNestedStruct3InterfaceProp2SetterId;
	static jmethodID javaClassNestedStruct3InterfaceProp2GetterId;
	static jmethodID javaClassNestedStruct3InterfaceProp2ChangedMethodID;
	static jmethodID javaClassNestedStruct3InterfaceProp3SetterId;
	static jmethodID javaClassNestedStruct3InterfaceProp3GetterId;
	static jmethodID javaClassNestedStruct3InterfaceProp3ChangedMethodID;
	static jclass serviceClassNestedStruct3Interface;
	static jmethodID serviceClassNestedStruct3InterfaceReadyMethodID;
	static jmethodID serviceClassNestedStruct3InterfaceProp1ChangedMethodID;
	static jmethodID serviceClassNestedStruct3InterfaceProp2ChangedMethodID;
	static jmethodID serviceClassNestedStruct3InterfaceProp3ChangedMethodID;
	static jmethodID serviceClassNestedStruct3InterfaceSig1SignalMethodID;
	static jmethodID serviceClassNestedStruct3InterfaceSig2SignalMethodID;
	static jmethodID serviceClassNestedStruct3InterfaceSig3SignalMethodID;
	static jclass clientClassNestedStruct3Interface;
	static jmethodID clientClassNestedStruct3InterfaceCtor;
	static jmethodID clientClassNestedStruct3InterfaceBindMethodID;
	static jmethodID clientClassNestedStruct3InterfaceUnbindMethodID;
	static jmethodID clientClassNestedStruct3InterfaceFunc1AsyncMethodID;
	static jmethodID clientClassNestedStruct3InterfaceFunc2AsyncMethodID;
	static jmethodID clientClassNestedStruct3InterfaceFunc3AsyncMethodID;

	static void init();
	static void clear();
	static bool isInitialized();

private:
	static bool m_isInitialized;
};

#endif
