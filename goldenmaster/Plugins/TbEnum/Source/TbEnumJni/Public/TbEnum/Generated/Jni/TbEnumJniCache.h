
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

class TBENUMAPI_API TbEnumJniCache
{
	static jclass javaEnumEnum0 = nullptr;
	static jmethodID javaEnumEnum0FromValueMethodId = nullptr;
	static jmethodID javaEnumEnum0GetValueMethod = nullptr;
	static jclass javaEnumEnum1 = nullptr;
	static jmethodID javaEnumEnum1FromValueMethodId = nullptr;
	static jmethodID javaEnumEnum1GetValueMethod = nullptr;
	static jclass javaEnumEnum2 = nullptr;
	static jmethodID javaEnumEnum2FromValueMethodId = nullptr;
	static jmethodID javaEnumEnum2GetValueMethod = nullptr;
	static jclass javaEnumEnum3 = nullptr;
	static jmethodID javaEnumEnum3FromValueMethodId = nullptr;
	static jmethodID javaEnumEnum3GetValueMethod = nullptr;
	static jclass javaClassEnumInterface = nullptr;
	static jmethodID javaClassEnumInterfaceProp0SetterId = nullptr;
	static jmethodID javaClassEnumInterfaceProp0GetterId = nullptr;
	static jmethodID javaClassEnumInterfaceProp1SetterId = nullptr;
	static jmethodID javaClassEnumInterfaceProp1GetterId = nullptr;
	static jmethodID javaClassEnumInterfaceProp2SetterId = nullptr;
	static jmethodID javaClassEnumInterfaceProp2GetterId = nullptr;
	static jmethodID javaClassEnumInterfaceProp3SetterId = nullptr;
	static jmethodID javaClassEnumInterfaceProp3GetterId = nullptr;
	static jmethodID javaClassEnumInterfaceSig0SignalMethodID = nullptr;
	static jmethodID javaClassEnumInterfaceSig1SignalMethodID = nullptr;
	static jmethodID javaClassEnumInterfaceSig2SignalMethodID = nullptr;
	static jmethodID javaClassEnumInterfaceSig3SignalMethodID = nullptr;
	static jmethodID javaClassEnumInterfaceFunc0MethodID = nullptr;
	static jmethodID javaClassEnumInterfaceFunc1MethodID = nullptr;
	static jmethodID javaClassEnumInterfaceFunc2MethodID = nullptr;
	static jmethodID javaClassEnumInterfaceFunc3MethodID = nullptr;

	static void init();
	static void clear();
	static bool isInitialized();

private:
	static bool m_isInitialized = false;
}

#endif
