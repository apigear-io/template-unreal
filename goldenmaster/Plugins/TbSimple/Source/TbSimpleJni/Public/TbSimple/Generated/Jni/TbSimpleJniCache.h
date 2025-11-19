
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

class TBSIMPLEAPI_API TbSimpleJniCache
{
	static jclass javaClassVoidInterface = nullptr;
	static jmethodID javaClassVoidInterfaceSigVoidSignalMethodID = nullptr;
	static jmethodID javaClassVoidInterfaceFuncVoidMethodID = nullptr;
	static jclass javaClassSimpleInterface = nullptr;
	static jmethodID javaClassSimpleInterfacePropBoolSetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropBoolGetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropIntSetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropIntGetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropInt32SetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropInt32GetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropInt64SetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropInt64GetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropFloatSetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropFloatGetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropFloat32SetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropFloat32GetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropFloat64SetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropFloat64GetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropStringSetterId = nullptr;
	static jmethodID javaClassSimpleInterfacePropStringGetterId = nullptr;
	static jmethodID javaClassSimpleInterfaceSigBoolSignalMethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceSigIntSignalMethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceSigInt32SignalMethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceSigInt64SignalMethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceSigFloatSignalMethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceSigFloat32SignalMethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceSigFloat64SignalMethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceSigStringSignalMethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceFuncNoReturnValueMethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceFuncNoParamsMethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceFuncBoolMethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceFuncIntMethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceFuncInt32MethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceFuncInt64MethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceFuncFloatMethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceFuncFloat32MethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceFuncFloat64MethodID = nullptr;
	static jmethodID javaClassSimpleInterfaceFuncStringMethodID = nullptr;
	static jclass javaClassSimpleArrayInterface = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropBoolSetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropBoolGetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropIntSetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropIntGetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropInt32SetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropInt32GetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropInt64SetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropInt64GetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropFloatSetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropFloatGetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropFloat32SetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropFloat32GetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropFloat64SetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropFloat64GetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropStringSetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropStringGetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfacePropReadOnlyStringGetterId = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceSigBoolSignalMethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceSigIntSignalMethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceSigInt32SignalMethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceSigInt64SignalMethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceSigFloatSignalMethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceSigFloat32SignalMethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceSigFloat64SignalMethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceSigStringSignalMethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceFuncBoolMethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceFuncIntMethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceFuncInt32MethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceFuncInt64MethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceFuncFloatMethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceFuncFloat32MethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceFuncFloat64MethodID = nullptr;
	static jmethodID javaClassSimpleArrayInterfaceFuncStringMethodID = nullptr;
	static jclass javaClassNoPropertiesInterface = nullptr;
	static jmethodID javaClassNoPropertiesInterfaceSigVoidSignalMethodID = nullptr;
	static jmethodID javaClassNoPropertiesInterfaceSigBoolSignalMethodID = nullptr;
	static jmethodID javaClassNoPropertiesInterfaceFuncVoidMethodID = nullptr;
	static jmethodID javaClassNoPropertiesInterfaceFuncBoolMethodID = nullptr;
	static jclass javaClassNoOperationsInterface = nullptr;
	static jmethodID javaClassNoOperationsInterfacePropBoolSetterId = nullptr;
	static jmethodID javaClassNoOperationsInterfacePropBoolGetterId = nullptr;
	static jmethodID javaClassNoOperationsInterfacePropIntSetterId = nullptr;
	static jmethodID javaClassNoOperationsInterfacePropIntGetterId = nullptr;
	static jmethodID javaClassNoOperationsInterfaceSigVoidSignalMethodID = nullptr;
	static jmethodID javaClassNoOperationsInterfaceSigBoolSignalMethodID = nullptr;
	static jclass javaClassNoSignalsInterface = nullptr;
	static jmethodID javaClassNoSignalsInterfacePropBoolSetterId = nullptr;
	static jmethodID javaClassNoSignalsInterfacePropBoolGetterId = nullptr;
	static jmethodID javaClassNoSignalsInterfacePropIntSetterId = nullptr;
	static jmethodID javaClassNoSignalsInterfacePropIntGetterId = nullptr;
	static jmethodID javaClassNoSignalsInterfaceFuncVoidMethodID = nullptr;
	static jmethodID javaClassNoSignalsInterfaceFuncBoolMethodID = nullptr;
	static jclass javaClassEmptyInterface = nullptr;

	static void init();
	static void clear();
	static bool isInitialized();

private:
	static bool m_isInitialized = false;
}

#endif
