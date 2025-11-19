
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

class TESTBED1API_API Testbed1JniCache
{
	static jclass javaStructStructBool = nullptr;
	static jmethodID javaStructStructBoolCtor = nullptr;
	static jfieldID javaStructStructBoolFieldBoolFieldId = nullptr;
	static jclass javaStructStructInt = nullptr;
	static jmethodID javaStructStructIntCtor = nullptr;
	static jfieldID javaStructStructIntFieldIntFieldId = nullptr;
	static jclass javaStructStructFloat = nullptr;
	static jmethodID javaStructStructFloatCtor = nullptr;
	static jfieldID javaStructStructFloatFieldFloatFieldId = nullptr;
	static jclass javaStructStructString = nullptr;
	static jmethodID javaStructStructStringCtor = nullptr;
	static jfieldID javaStructStructStringFieldStringFieldId = nullptr;
	static jclass javaStructStructStruct = nullptr;
	static jmethodID javaStructStructStructCtor = nullptr;
	static jfieldID javaStructStructStructFieldStringFieldId = nullptr;
	static jclass javaStructStructEnum = nullptr;
	static jmethodID javaStructStructEnumCtor = nullptr;
	static jfieldID javaStructStructEnumFieldEnumFieldId = nullptr;
	static jclass javaStructStructBoolWithArray = nullptr;
	static jmethodID javaStructStructBoolWithArrayCtor = nullptr;
	static jfieldID javaStructStructBoolWithArrayFieldBoolFieldId = nullptr;
	static jclass javaStructStructIntWithArray = nullptr;
	static jmethodID javaStructStructIntWithArrayCtor = nullptr;
	static jfieldID javaStructStructIntWithArrayFieldIntFieldId = nullptr;
	static jclass javaStructStructFloatWithArray = nullptr;
	static jmethodID javaStructStructFloatWithArrayCtor = nullptr;
	static jfieldID javaStructStructFloatWithArrayFieldFloatFieldId = nullptr;
	static jclass javaStructStructStringWithArray = nullptr;
	static jmethodID javaStructStructStringWithArrayCtor = nullptr;
	static jfieldID javaStructStructStringWithArrayFieldStringFieldId = nullptr;
	static jclass javaStructStructStructWithArray = nullptr;
	static jmethodID javaStructStructStructWithArrayCtor = nullptr;
	static jfieldID javaStructStructStructWithArrayFieldStructFieldId = nullptr;
	static jclass javaStructStructEnumWithArray = nullptr;
	static jmethodID javaStructStructEnumWithArrayCtor = nullptr;
	static jfieldID javaStructStructEnumWithArrayFieldEnumFieldId = nullptr;
	static jclass javaEnumEnum0 = nullptr;
	static jmethodID javaEnumEnum0FromValueMethodId = nullptr;
	static jmethodID javaEnumEnum0GetValueMethod = nullptr;
	static jclass javaClassStructInterface = nullptr;
	static jmethodID javaClassStructInterfacePropBoolSetterId = nullptr;
	static jmethodID javaClassStructInterfacePropBoolGetterId = nullptr;
	static jmethodID javaClassStructInterfacePropIntSetterId = nullptr;
	static jmethodID javaClassStructInterfacePropIntGetterId = nullptr;
	static jmethodID javaClassStructInterfacePropFloatSetterId = nullptr;
	static jmethodID javaClassStructInterfacePropFloatGetterId = nullptr;
	static jmethodID javaClassStructInterfacePropStringSetterId = nullptr;
	static jmethodID javaClassStructInterfacePropStringGetterId = nullptr;
	static jmethodID javaClassStructInterfaceSigBoolSignalMethodID = nullptr;
	static jmethodID javaClassStructInterfaceSigIntSignalMethodID = nullptr;
	static jmethodID javaClassStructInterfaceSigFloatSignalMethodID = nullptr;
	static jmethodID javaClassStructInterfaceSigStringSignalMethodID = nullptr;
	static jmethodID javaClassStructInterfaceFuncBoolMethodID = nullptr;
	static jmethodID javaClassStructInterfaceFuncIntMethodID = nullptr;
	static jmethodID javaClassStructInterfaceFuncFloatMethodID = nullptr;
	static jmethodID javaClassStructInterfaceFuncStringMethodID = nullptr;
	static jclass javaClassStructArrayInterface = nullptr;
	static jmethodID javaClassStructArrayInterfacePropBoolSetterId = nullptr;
	static jmethodID javaClassStructArrayInterfacePropBoolGetterId = nullptr;
	static jmethodID javaClassStructArrayInterfacePropIntSetterId = nullptr;
	static jmethodID javaClassStructArrayInterfacePropIntGetterId = nullptr;
	static jmethodID javaClassStructArrayInterfacePropFloatSetterId = nullptr;
	static jmethodID javaClassStructArrayInterfacePropFloatGetterId = nullptr;
	static jmethodID javaClassStructArrayInterfacePropStringSetterId = nullptr;
	static jmethodID javaClassStructArrayInterfacePropStringGetterId = nullptr;
	static jmethodID javaClassStructArrayInterfacePropEnumSetterId = nullptr;
	static jmethodID javaClassStructArrayInterfacePropEnumGetterId = nullptr;
	static jmethodID javaClassStructArrayInterfaceSigBoolSignalMethodID = nullptr;
	static jmethodID javaClassStructArrayInterfaceSigIntSignalMethodID = nullptr;
	static jmethodID javaClassStructArrayInterfaceSigFloatSignalMethodID = nullptr;
	static jmethodID javaClassStructArrayInterfaceSigStringSignalMethodID = nullptr;
	static jmethodID javaClassStructArrayInterfaceSigEnumSignalMethodID = nullptr;
	static jmethodID javaClassStructArrayInterfaceFuncBoolMethodID = nullptr;
	static jmethodID javaClassStructArrayInterfaceFuncIntMethodID = nullptr;
	static jmethodID javaClassStructArrayInterfaceFuncFloatMethodID = nullptr;
	static jmethodID javaClassStructArrayInterfaceFuncStringMethodID = nullptr;
	static jmethodID javaClassStructArrayInterfaceFuncEnumMethodID = nullptr;
	static jclass javaClassStructArray2Interface = nullptr;
	static jmethodID javaClassStructArray2InterfacePropBoolSetterId = nullptr;
	static jmethodID javaClassStructArray2InterfacePropBoolGetterId = nullptr;
	static jmethodID javaClassStructArray2InterfacePropIntSetterId = nullptr;
	static jmethodID javaClassStructArray2InterfacePropIntGetterId = nullptr;
	static jmethodID javaClassStructArray2InterfacePropFloatSetterId = nullptr;
	static jmethodID javaClassStructArray2InterfacePropFloatGetterId = nullptr;
	static jmethodID javaClassStructArray2InterfacePropStringSetterId = nullptr;
	static jmethodID javaClassStructArray2InterfacePropStringGetterId = nullptr;
	static jmethodID javaClassStructArray2InterfacePropEnumSetterId = nullptr;
	static jmethodID javaClassStructArray2InterfacePropEnumGetterId = nullptr;
	static jmethodID javaClassStructArray2InterfaceSigBoolSignalMethodID = nullptr;
	static jmethodID javaClassStructArray2InterfaceSigIntSignalMethodID = nullptr;
	static jmethodID javaClassStructArray2InterfaceSigFloatSignalMethodID = nullptr;
	static jmethodID javaClassStructArray2InterfaceSigStringSignalMethodID = nullptr;
	static jmethodID javaClassStructArray2InterfaceFuncBoolMethodID = nullptr;
	static jmethodID javaClassStructArray2InterfaceFuncIntMethodID = nullptr;
	static jmethodID javaClassStructArray2InterfaceFuncFloatMethodID = nullptr;
	static jmethodID javaClassStructArray2InterfaceFuncStringMethodID = nullptr;
	static jmethodID javaClassStructArray2InterfaceFuncEnumMethodID = nullptr;

	static void init();
	static void clear();
	static bool isInitialized();

private:
	static bool m_isInitialized = false;
}

#endif
