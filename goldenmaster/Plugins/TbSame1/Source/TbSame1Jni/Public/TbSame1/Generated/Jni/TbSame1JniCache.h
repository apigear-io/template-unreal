
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

class TBSAME1API_API TbSame1JniCache
{
public:
	static jclass javaStructStruct1;
	static jmethodID javaStructStruct1Ctor;
	static jfieldID javaStructStruct1Field1FieldId;
	static jfieldID javaStructStruct1Field2FieldId;
	static jfieldID javaStructStruct1Field3FieldId;
	static jclass javaStructStruct2;
	static jmethodID javaStructStruct2Ctor;
	static jfieldID javaStructStruct2Field1FieldId;
	static jfieldID javaStructStruct2Field2FieldId;
	static jfieldID javaStructStruct2Field3FieldId;
	static jclass javaEnumEnum1;
	static jmethodID javaEnumEnum1FromValueMethodId;
	static jmethodID javaEnumEnum1GetValueMethod;
	static jclass javaEnumEnum2;
	static jmethodID javaEnumEnum2FromValueMethodId;
	static jmethodID javaEnumEnum2GetValueMethod;
	static jclass javaClassSameStruct1Interface;
	static jmethodID javaClassSameStruct1InterfaceProp1SetterId;
	static jmethodID javaClassSameStruct1InterfaceProp1GetterId;
	static jmethodID javaClassSameStruct1InterfaceProp1ChangedMethodID;
	static jclass serviceClassSameStruct1Interface;
	static jmethodID serviceClassSameStruct1InterfaceReadyMethodID;
	static jmethodID serviceClassSameStruct1InterfaceProp1ChangedMethodID;
	static jmethodID serviceClassSameStruct1InterfaceSig1SignalMethodID;
	static jclass clientClassSameStruct1Interface;
	static jmethodID clientClassSameStruct1InterfaceCtor;
	static jmethodID clientClassSameStruct1InterfaceBindMethodID;
	static jmethodID clientClassSameStruct1InterfaceUnbindMethodID;
	static jmethodID clientClassSameStruct1InterfaceFunc1AsyncMethodID;
	static jclass javaClassSameStruct2Interface;
	static jmethodID javaClassSameStruct2InterfaceProp1SetterId;
	static jmethodID javaClassSameStruct2InterfaceProp1GetterId;
	static jmethodID javaClassSameStruct2InterfaceProp1ChangedMethodID;
	static jmethodID javaClassSameStruct2InterfaceProp2SetterId;
	static jmethodID javaClassSameStruct2InterfaceProp2GetterId;
	static jmethodID javaClassSameStruct2InterfaceProp2ChangedMethodID;
	static jclass serviceClassSameStruct2Interface;
	static jmethodID serviceClassSameStruct2InterfaceReadyMethodID;
	static jmethodID serviceClassSameStruct2InterfaceProp1ChangedMethodID;
	static jmethodID serviceClassSameStruct2InterfaceProp2ChangedMethodID;
	static jmethodID serviceClassSameStruct2InterfaceSig1SignalMethodID;
	static jmethodID serviceClassSameStruct2InterfaceSig2SignalMethodID;
	static jclass clientClassSameStruct2Interface;
	static jmethodID clientClassSameStruct2InterfaceCtor;
	static jmethodID clientClassSameStruct2InterfaceBindMethodID;
	static jmethodID clientClassSameStruct2InterfaceUnbindMethodID;
	static jmethodID clientClassSameStruct2InterfaceFunc1AsyncMethodID;
	static jmethodID clientClassSameStruct2InterfaceFunc2AsyncMethodID;
	static jclass javaClassSameEnum1Interface;
	static jmethodID javaClassSameEnum1InterfaceProp1SetterId;
	static jmethodID javaClassSameEnum1InterfaceProp1GetterId;
	static jmethodID javaClassSameEnum1InterfaceProp1ChangedMethodID;
	static jclass serviceClassSameEnum1Interface;
	static jmethodID serviceClassSameEnum1InterfaceReadyMethodID;
	static jmethodID serviceClassSameEnum1InterfaceProp1ChangedMethodID;
	static jmethodID serviceClassSameEnum1InterfaceSig1SignalMethodID;
	static jclass clientClassSameEnum1Interface;
	static jmethodID clientClassSameEnum1InterfaceCtor;
	static jmethodID clientClassSameEnum1InterfaceBindMethodID;
	static jmethodID clientClassSameEnum1InterfaceUnbindMethodID;
	static jmethodID clientClassSameEnum1InterfaceFunc1AsyncMethodID;
	static jclass javaClassSameEnum2Interface;
	static jmethodID javaClassSameEnum2InterfaceProp1SetterId;
	static jmethodID javaClassSameEnum2InterfaceProp1GetterId;
	static jmethodID javaClassSameEnum2InterfaceProp1ChangedMethodID;
	static jmethodID javaClassSameEnum2InterfaceProp2SetterId;
	static jmethodID javaClassSameEnum2InterfaceProp2GetterId;
	static jmethodID javaClassSameEnum2InterfaceProp2ChangedMethodID;
	static jclass serviceClassSameEnum2Interface;
	static jmethodID serviceClassSameEnum2InterfaceReadyMethodID;
	static jmethodID serviceClassSameEnum2InterfaceProp1ChangedMethodID;
	static jmethodID serviceClassSameEnum2InterfaceProp2ChangedMethodID;
	static jmethodID serviceClassSameEnum2InterfaceSig1SignalMethodID;
	static jmethodID serviceClassSameEnum2InterfaceSig2SignalMethodID;
	static jclass clientClassSameEnum2Interface;
	static jmethodID clientClassSameEnum2InterfaceCtor;
	static jmethodID clientClassSameEnum2InterfaceBindMethodID;
	static jmethodID clientClassSameEnum2InterfaceUnbindMethodID;
	static jmethodID clientClassSameEnum2InterfaceFunc1AsyncMethodID;
	static jmethodID clientClassSameEnum2InterfaceFunc2AsyncMethodID;

	static void init();
	static void clear();
	static bool isInitialized();

private:
	static bool m_isInitialized;
};

#endif
