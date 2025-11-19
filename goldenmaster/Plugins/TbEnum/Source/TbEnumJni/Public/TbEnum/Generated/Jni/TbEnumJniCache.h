
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
public:
	static jclass javaEnumEnum0;
	static jmethodID javaEnumEnum0FromValueMethodId;
	static jmethodID javaEnumEnum0GetValueMethod;
	static jclass javaEnumEnum1;
	static jmethodID javaEnumEnum1FromValueMethodId;
	static jmethodID javaEnumEnum1GetValueMethod;
	static jclass javaEnumEnum2;
	static jmethodID javaEnumEnum2FromValueMethodId;
	static jmethodID javaEnumEnum2GetValueMethod;
	static jclass javaEnumEnum3;
	static jmethodID javaEnumEnum3FromValueMethodId;
	static jmethodID javaEnumEnum3GetValueMethod;
	static jclass javaClassEnumInterface;
	static jmethodID javaClassEnumInterfaceProp0SetterId;
	static jmethodID javaClassEnumInterfaceProp0GetterId;
	static jmethodID javaClassEnumInterfaceProp0ChangedMethodID;
	static jmethodID javaClassEnumInterfaceProp1SetterId;
	static jmethodID javaClassEnumInterfaceProp1GetterId;
	static jmethodID javaClassEnumInterfaceProp1ChangedMethodID;
	static jmethodID javaClassEnumInterfaceProp2SetterId;
	static jmethodID javaClassEnumInterfaceProp2GetterId;
	static jmethodID javaClassEnumInterfaceProp2ChangedMethodID;
	static jmethodID javaClassEnumInterfaceProp3SetterId;
	static jmethodID javaClassEnumInterfaceProp3GetterId;
	static jmethodID javaClassEnumInterfaceProp3ChangedMethodID;
	static jclass serviceClassEnumInterface;
	static jmethodID serviceClassEnumInterfaceReadyMethodID;
	static jmethodID serviceClassEnumInterfaceProp0ChangedMethodID;
	static jmethodID serviceClassEnumInterfaceProp1ChangedMethodID;
	static jmethodID serviceClassEnumInterfaceProp2ChangedMethodID;
	static jmethodID serviceClassEnumInterfaceProp3ChangedMethodID;
	static jmethodID serviceClassEnumInterfaceSig0SignalMethodID;
	static jmethodID serviceClassEnumInterfaceSig1SignalMethodID;
	static jmethodID serviceClassEnumInterfaceSig2SignalMethodID;
	static jmethodID serviceClassEnumInterfaceSig3SignalMethodID;
	static jclass clientClassEnumInterface;
	static jmethodID clientClassEnumInterfaceCtor;
	static jmethodID clientClassEnumInterfaceBindMethodID;
	static jmethodID clientClassEnumInterfaceUnbindMethodID;
	static jmethodID clientClassEnumInterfaceFunc0AsyncMethodID;
	static jmethodID clientClassEnumInterfaceFunc1AsyncMethodID;
	static jmethodID clientClassEnumInterfaceFunc2AsyncMethodID;
	static jmethodID clientClassEnumInterfaceFunc3AsyncMethodID;

	static void init();
	static void clear();
	static bool isInitialized();

private:
	static bool m_isInitialized;
};

#endif
