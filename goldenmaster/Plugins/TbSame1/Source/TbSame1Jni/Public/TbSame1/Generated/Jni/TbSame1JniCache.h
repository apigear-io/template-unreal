
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
	static jclass javaStructStruct1 = nullptr;
	static jmethodID javaStructStruct1Ctor = nullptr;
	static jfieldID javaStructStruct1Field1FieldId = nullptr;
	static jfieldID javaStructStruct1Field2FieldId = nullptr;
	static jfieldID javaStructStruct1Field3FieldId = nullptr;
	static jclass javaStructStruct2 = nullptr;
	static jmethodID javaStructStruct2Ctor = nullptr;
	static jfieldID javaStructStruct2Field1FieldId = nullptr;
	static jfieldID javaStructStruct2Field2FieldId = nullptr;
	static jfieldID javaStructStruct2Field3FieldId = nullptr;
	static jclass javaEnumEnum1 = nullptr;
	static jmethodID javaEnumEnum1FromValueMethodId = nullptr;
	static jmethodID javaEnumEnum1GetValueMethod = nullptr;
	static jclass javaEnumEnum2 = nullptr;
	static jmethodID javaEnumEnum2FromValueMethodId = nullptr;
	static jmethodID javaEnumEnum2GetValueMethod = nullptr;
	static jclass javaClassSameStruct1Interface = nullptr;
	static jmethodID javaClassSameStruct1InterfaceProp1SetterId = nullptr;
	static jmethodID javaClassSameStruct1InterfaceProp1GetterId = nullptr;
	static jmethodID javaClassSameStruct1InterfaceSig1SignalMethodID = nullptr;
	static jmethodID javaClassSameStruct1InterfaceFunc1MethodID = nullptr;
	static jclass javaClassSameStruct2Interface = nullptr;
	static jmethodID javaClassSameStruct2InterfaceProp1SetterId = nullptr;
	static jmethodID javaClassSameStruct2InterfaceProp1GetterId = nullptr;
	static jmethodID javaClassSameStruct2InterfaceProp2SetterId = nullptr;
	static jmethodID javaClassSameStruct2InterfaceProp2GetterId = nullptr;
	static jmethodID javaClassSameStruct2InterfaceSig1SignalMethodID = nullptr;
	static jmethodID javaClassSameStruct2InterfaceSig2SignalMethodID = nullptr;
	static jmethodID javaClassSameStruct2InterfaceFunc1MethodID = nullptr;
	static jmethodID javaClassSameStruct2InterfaceFunc2MethodID = nullptr;
	static jclass javaClassSameEnum1Interface = nullptr;
	static jmethodID javaClassSameEnum1InterfaceProp1SetterId = nullptr;
	static jmethodID javaClassSameEnum1InterfaceProp1GetterId = nullptr;
	static jmethodID javaClassSameEnum1InterfaceSig1SignalMethodID = nullptr;
	static jmethodID javaClassSameEnum1InterfaceFunc1MethodID = nullptr;
	static jclass javaClassSameEnum2Interface = nullptr;
	static jmethodID javaClassSameEnum2InterfaceProp1SetterId = nullptr;
	static jmethodID javaClassSameEnum2InterfaceProp1GetterId = nullptr;
	static jmethodID javaClassSameEnum2InterfaceProp2SetterId = nullptr;
	static jmethodID javaClassSameEnum2InterfaceProp2GetterId = nullptr;
	static jmethodID javaClassSameEnum2InterfaceSig1SignalMethodID = nullptr;
	static jmethodID javaClassSameEnum2InterfaceSig2SignalMethodID = nullptr;
	static jmethodID javaClassSameEnum2InterfaceFunc1MethodID = nullptr;
	static jmethodID javaClassSameEnum2InterfaceFunc2MethodID = nullptr;

	static void init();
	static void clear();
	static bool isInitialized();

private:
	static bool m_isInitialized = false;
}

#endif
