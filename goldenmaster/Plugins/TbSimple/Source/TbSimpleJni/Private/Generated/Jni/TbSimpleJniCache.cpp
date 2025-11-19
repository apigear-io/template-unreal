
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

#include "TbSimple/Generated/Jni/TbSimpleJniCache.h"
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

void TbSimpleJniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();

	javaClassVoidInterface = FAndroidApplication::FindJavaClassGlobalRef("TbSimple/TbSimple_api/IVoidInterface");
	javaClassVoidInterfaceSigVoidSignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassVoidInterface, "onSigVoid", "()V");
	javaClassVoidInterfaceFuncVoidMethodID = env->GetMethodID(TbSimpleJniCache::javaClassVoidInterface, "funcVoidAsync", "(Ljava/lang/String;)V");

	javaClassSimpleInterface = FAndroidApplication::FindJavaClassGlobalRef("TbSimple/TbSimple_api/ISimpleInterface");
	javaClassSimpleInterfacePropBoolSetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "setPropBool", "(Z)V");
	javaClassSimpleInterfacePropBoolGetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "getPropBool", "()Z");
	javaClassSimpleInterfacePropIntSetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "setPropInt", "(I)V");
	javaClassSimpleInterfacePropIntGetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "getPropInt", "()I");
	javaClassSimpleInterfacePropInt32SetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "setPropInt32", "(I)V");
	javaClassSimpleInterfacePropInt32GetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "getPropInt32", "()I");
	javaClassSimpleInterfacePropInt64SetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "setPropInt64", "(J)V");
	javaClassSimpleInterfacePropInt64GetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "getPropInt64", "()J");
	javaClassSimpleInterfacePropFloatSetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "setPropFloat", "(F)V");
	javaClassSimpleInterfacePropFloatGetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "getPropFloat", "()F");
	javaClassSimpleInterfacePropFloat32SetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "setPropFloat32", "(F)V");
	javaClassSimpleInterfacePropFloat32GetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "getPropFloat32", "()F");
	javaClassSimpleInterfacePropFloat64SetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "setPropFloat64", "(D)V");
	javaClassSimpleInterfacePropFloat64GetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "getPropFloat64", "()D");
	javaClassSimpleInterfacePropStringSetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "setPropString", "(Ljava/lang/String;)V");
	javaClassSimpleInterfacePropStringGetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "getPropString", "()Ljava/lang/String;");
	javaClassSimpleInterfaceSigBoolSignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "onSigBool", "(Z)V");
	javaClassSimpleInterfaceSigIntSignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "onSigInt", "(I)V");
	javaClassSimpleInterfaceSigInt32SignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "onSigInt32", "(I)V");
	javaClassSimpleInterfaceSigInt64SignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "onSigInt64", "(J)V");
	javaClassSimpleInterfaceSigFloatSignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "onSigFloat", "(F)V");
	javaClassSimpleInterfaceSigFloat32SignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "onSigFloat32", "(F)V");
	javaClassSimpleInterfaceSigFloat64SignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "onSigFloat64", "(D)V");
	javaClassSimpleInterfaceSigStringSignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "onSigString", "(Ljava/lang/String;)V");
	javaClassSimpleInterfaceFuncNoReturnValueMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "funcNoReturnValueAsync", "(Ljava/lang/String;Z)V");
	javaClassSimpleInterfaceFuncNoParamsMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "funcNoParamsAsync", "(Ljava/lang/String;)V");
	javaClassSimpleInterfaceFuncBoolMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "funcBoolAsync", "(Ljava/lang/String;Z)V");
	javaClassSimpleInterfaceFuncIntMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "funcIntAsync", "(Ljava/lang/String;I)V");
	javaClassSimpleInterfaceFuncInt32MethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "funcInt32Async", "(Ljava/lang/String;I)V");
	javaClassSimpleInterfaceFuncInt64MethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "funcInt64Async", "(Ljava/lang/String;J)V");
	javaClassSimpleInterfaceFuncFloatMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "funcFloatAsync", "(Ljava/lang/String;F)V");
	javaClassSimpleInterfaceFuncFloat32MethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "funcFloat32Async", "(Ljava/lang/String;F)V");
	javaClassSimpleInterfaceFuncFloat64MethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "funcFloat64Async", "(Ljava/lang/String;D)V");
	javaClassSimpleInterfaceFuncStringMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleInterface, "funcStringAsync", "(Ljava/lang/String;Ljava/lang/String;)V");

	javaClassSimpleArrayInterface = FAndroidApplication::FindJavaClassGlobalRef("TbSimple/TbSimple_api/ISimpleArrayInterface");
	javaClassSimpleArrayInterfacePropBoolSetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "setPropBool", "([Z)V");
	javaClassSimpleArrayInterfacePropBoolGetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "getPropBool", "()[Z");
	javaClassSimpleArrayInterfacePropIntSetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "setPropInt", "([I)V");
	javaClassSimpleArrayInterfacePropIntGetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "getPropInt", "()[I");
	javaClassSimpleArrayInterfacePropInt32SetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "setPropInt32", "([I)V");
	javaClassSimpleArrayInterfacePropInt32GetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "getPropInt32", "()[I");
	javaClassSimpleArrayInterfacePropInt64SetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "setPropInt64", "([J)V");
	javaClassSimpleArrayInterfacePropInt64GetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "getPropInt64", "()[J");
	javaClassSimpleArrayInterfacePropFloatSetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "setPropFloat", "([F)V");
	javaClassSimpleArrayInterfacePropFloatGetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "getPropFloat", "()[F");
	javaClassSimpleArrayInterfacePropFloat32SetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "setPropFloat32", "([F)V");
	javaClassSimpleArrayInterfacePropFloat32GetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "getPropFloat32", "()[F");
	javaClassSimpleArrayInterfacePropFloat64SetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "setPropFloat64", "([D)V");
	javaClassSimpleArrayInterfacePropFloat64GetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "getPropFloat64", "()[D");
	javaClassSimpleArrayInterfacePropStringSetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "setPropString", "([Ljava/lang/String;)V");
	javaClassSimpleArrayInterfacePropStringGetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "getPropString", "()[Ljava/lang/String;");
	javaClassSimpleArrayInterfacePropReadOnlyStringGetterId = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "getPropReadOnlyString", "()Ljava/lang/String;");
	javaClassSimpleArrayInterfaceSigBoolSignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "onSigBool", "([Z)V");
	javaClassSimpleArrayInterfaceSigIntSignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "onSigInt", "([I)V");
	javaClassSimpleArrayInterfaceSigInt32SignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "onSigInt32", "([I)V");
	javaClassSimpleArrayInterfaceSigInt64SignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "onSigInt64", "([J)V");
	javaClassSimpleArrayInterfaceSigFloatSignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "onSigFloat", "([F)V");
	javaClassSimpleArrayInterfaceSigFloat32SignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "onSigFloat32", "([F)V");
	javaClassSimpleArrayInterfaceSigFloat64SignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "onSigFloat64", "([D)V");
	javaClassSimpleArrayInterfaceSigStringSignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "onSigString", "([Ljava/lang/String;)V");
	javaClassSimpleArrayInterfaceFuncBoolMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "funcBoolAsync", "(Ljava/lang/String;[Z)V");
	javaClassSimpleArrayInterfaceFuncIntMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "funcIntAsync", "(Ljava/lang/String;[I)V");
	javaClassSimpleArrayInterfaceFuncInt32MethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "funcInt32Async", "(Ljava/lang/String;[I)V");
	javaClassSimpleArrayInterfaceFuncInt64MethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "funcInt64Async", "(Ljava/lang/String;[J)V");
	javaClassSimpleArrayInterfaceFuncFloatMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "funcFloatAsync", "(Ljava/lang/String;[F)V");
	javaClassSimpleArrayInterfaceFuncFloat32MethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "funcFloat32Async", "(Ljava/lang/String;[F)V");
	javaClassSimpleArrayInterfaceFuncFloat64MethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "funcFloat64Async", "(Ljava/lang/String;[D)V");
	javaClassSimpleArrayInterfaceFuncStringMethodID = env->GetMethodID(TbSimpleJniCache::javaClassSimpleArrayInterface, "funcStringAsync", "(Ljava/lang/String;[Ljava/lang/String;)V");

	javaClassNoPropertiesInterface = FAndroidApplication::FindJavaClassGlobalRef("TbSimple/TbSimple_api/INoPropertiesInterface");
	javaClassNoPropertiesInterfaceSigVoidSignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassNoPropertiesInterface, "onSigVoid", "()V");
	javaClassNoPropertiesInterfaceSigBoolSignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassNoPropertiesInterface, "onSigBool", "(Z)V");
	javaClassNoPropertiesInterfaceFuncVoidMethodID = env->GetMethodID(TbSimpleJniCache::javaClassNoPropertiesInterface, "funcVoidAsync", "(Ljava/lang/String;)V");
	javaClassNoPropertiesInterfaceFuncBoolMethodID = env->GetMethodID(TbSimpleJniCache::javaClassNoPropertiesInterface, "funcBoolAsync", "(Ljava/lang/String;Z)V");

	javaClassNoOperationsInterface = FAndroidApplication::FindJavaClassGlobalRef("TbSimple/TbSimple_api/INoOperationsInterface");
	javaClassNoOperationsInterfacePropBoolSetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoOperationsInterface, "setPropBool", "(Z)V");
	javaClassNoOperationsInterfacePropBoolGetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoOperationsInterface, "getPropBool", "()Z");
	javaClassNoOperationsInterfacePropIntSetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoOperationsInterface, "setPropInt", "(I)V");
	javaClassNoOperationsInterfacePropIntGetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoOperationsInterface, "getPropInt", "()I");
	javaClassNoOperationsInterfaceSigVoidSignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassNoOperationsInterface, "onSigVoid", "()V");
	javaClassNoOperationsInterfaceSigBoolSignalMethodID = env->GetMethodID(TbSimpleJniCache::javaClassNoOperationsInterface, "onSigBool", "(Z)V");

	javaClassNoSignalsInterface = FAndroidApplication::FindJavaClassGlobalRef("TbSimple/TbSimple_api/INoSignalsInterface");
	javaClassNoSignalsInterfacePropBoolSetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoSignalsInterface, "setPropBool", "(Z)V");
	javaClassNoSignalsInterfacePropBoolGetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoSignalsInterface, "getPropBool", "()Z");
	javaClassNoSignalsInterfacePropIntSetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoSignalsInterface, "setPropInt", "(I)V");
	javaClassNoSignalsInterfacePropIntGetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoSignalsInterface, "getPropInt", "()I");
	javaClassNoSignalsInterfaceFuncVoidMethodID = env->GetMethodID(TbSimpleJniCache::javaClassNoSignalsInterface, "funcVoidAsync", "(Ljava/lang/String;)V");
	javaClassNoSignalsInterfaceFuncBoolMethodID = env->GetMethodID(TbSimpleJniCache::javaClassNoSignalsInterface, "funcBoolAsync", "(Ljava/lang/String;Z)V");

	javaClassEmptyInterface = FAndroidApplication::FindJavaClassGlobalRef("TbSimple/TbSimple_api/IEmptyInterface");
	m_isInitialized = true;
}

void TbSimpleJniCache::clear()
{
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(javaClassVoidInterface);
	javaClassVoidInterface = nullptr;
	javaClassVoidInterfaceSigVoidSignalMethodID = nullptr;
	javaClassVoidInterfaceFuncVoidMethodID = nullptr;
	env->DeleteGlobalRef(javaClassSimpleInterface);
	javaClassSimpleInterface = nullptr;
	javaClassSimpleInterfacePropBoolSetterId = nullptr;
	javaClassSimpleInterfacePropBoolGetterId = nullptr;
	javaClassSimpleInterfacePropIntSetterId = nullptr;
	javaClassSimpleInterfacePropIntGetterId = nullptr;
	javaClassSimpleInterfacePropInt32SetterId = nullptr;
	javaClassSimpleInterfacePropInt32GetterId = nullptr;
	javaClassSimpleInterfacePropInt64SetterId = nullptr;
	javaClassSimpleInterfacePropInt64GetterId = nullptr;
	javaClassSimpleInterfacePropFloatSetterId = nullptr;
	javaClassSimpleInterfacePropFloatGetterId = nullptr;
	javaClassSimpleInterfacePropFloat32SetterId = nullptr;
	javaClassSimpleInterfacePropFloat32GetterId = nullptr;
	javaClassSimpleInterfacePropFloat64SetterId = nullptr;
	javaClassSimpleInterfacePropFloat64GetterId = nullptr;
	javaClassSimpleInterfacePropStringSetterId = nullptr;
	javaClassSimpleInterfacePropStringGetterId = nullptr;
	javaClassSimpleInterfaceSigBoolSignalMethodID = nullptr;
	javaClassSimpleInterfaceSigIntSignalMethodID = nullptr;
	javaClassSimpleInterfaceSigInt32SignalMethodID = nullptr;
	javaClassSimpleInterfaceSigInt64SignalMethodID = nullptr;
	javaClassSimpleInterfaceSigFloatSignalMethodID = nullptr;
	javaClassSimpleInterfaceSigFloat32SignalMethodID = nullptr;
	javaClassSimpleInterfaceSigFloat64SignalMethodID = nullptr;
	javaClassSimpleInterfaceSigStringSignalMethodID = nullptr;
	javaClassSimpleInterfaceFuncNoReturnValueMethodID = nullptr;
	javaClassSimpleInterfaceFuncNoParamsMethodID = nullptr;
	javaClassSimpleInterfaceFuncBoolMethodID = nullptr;
	javaClassSimpleInterfaceFuncIntMethodID = nullptr;
	javaClassSimpleInterfaceFuncInt32MethodID = nullptr;
	javaClassSimpleInterfaceFuncInt64MethodID = nullptr;
	javaClassSimpleInterfaceFuncFloatMethodID = nullptr;
	javaClassSimpleInterfaceFuncFloat32MethodID = nullptr;
	javaClassSimpleInterfaceFuncFloat64MethodID = nullptr;
	javaClassSimpleInterfaceFuncStringMethodID = nullptr;
	env->DeleteGlobalRef(javaClassSimpleArrayInterface);
	javaClassSimpleArrayInterface = nullptr;
	javaClassSimpleArrayInterfacePropBoolSetterId = nullptr;
	javaClassSimpleArrayInterfacePropBoolGetterId = nullptr;
	javaClassSimpleArrayInterfacePropIntSetterId = nullptr;
	javaClassSimpleArrayInterfacePropIntGetterId = nullptr;
	javaClassSimpleArrayInterfacePropInt32SetterId = nullptr;
	javaClassSimpleArrayInterfacePropInt32GetterId = nullptr;
	javaClassSimpleArrayInterfacePropInt64SetterId = nullptr;
	javaClassSimpleArrayInterfacePropInt64GetterId = nullptr;
	javaClassSimpleArrayInterfacePropFloatSetterId = nullptr;
	javaClassSimpleArrayInterfacePropFloatGetterId = nullptr;
	javaClassSimpleArrayInterfacePropFloat32SetterId = nullptr;
	javaClassSimpleArrayInterfacePropFloat32GetterId = nullptr;
	javaClassSimpleArrayInterfacePropFloat64SetterId = nullptr;
	javaClassSimpleArrayInterfacePropFloat64GetterId = nullptr;
	javaClassSimpleArrayInterfacePropStringSetterId = nullptr;
	javaClassSimpleArrayInterfacePropStringGetterId = nullptr;
	javaClassSimpleArrayInterfacePropReadOnlyStringGetterId = nullptr;
	javaClassSimpleArrayInterfaceSigBoolSignalMethodID = nullptr;
	javaClassSimpleArrayInterfaceSigIntSignalMethodID = nullptr;
	javaClassSimpleArrayInterfaceSigInt32SignalMethodID = nullptr;
	javaClassSimpleArrayInterfaceSigInt64SignalMethodID = nullptr;
	javaClassSimpleArrayInterfaceSigFloatSignalMethodID = nullptr;
	javaClassSimpleArrayInterfaceSigFloat32SignalMethodID = nullptr;
	javaClassSimpleArrayInterfaceSigFloat64SignalMethodID = nullptr;
	javaClassSimpleArrayInterfaceSigStringSignalMethodID = nullptr;
	javaClassSimpleArrayInterfaceFuncBoolMethodID = nullptr;
	javaClassSimpleArrayInterfaceFuncIntMethodID = nullptr;
	javaClassSimpleArrayInterfaceFuncInt32MethodID = nullptr;
	javaClassSimpleArrayInterfaceFuncInt64MethodID = nullptr;
	javaClassSimpleArrayInterfaceFuncFloatMethodID = nullptr;
	javaClassSimpleArrayInterfaceFuncFloat32MethodID = nullptr;
	javaClassSimpleArrayInterfaceFuncFloat64MethodID = nullptr;
	javaClassSimpleArrayInterfaceFuncStringMethodID = nullptr;
	env->DeleteGlobalRef(javaClassNoPropertiesInterface);
	javaClassNoPropertiesInterface = nullptr;
	javaClassNoPropertiesInterfaceSigVoidSignalMethodID = nullptr;
	javaClassNoPropertiesInterfaceSigBoolSignalMethodID = nullptr;
	javaClassNoPropertiesInterfaceFuncVoidMethodID = nullptr;
	javaClassNoPropertiesInterfaceFuncBoolMethodID = nullptr;
	env->DeleteGlobalRef(javaClassNoOperationsInterface);
	javaClassNoOperationsInterface = nullptr;
	javaClassNoOperationsInterfacePropBoolSetterId = nullptr;
	javaClassNoOperationsInterfacePropBoolGetterId = nullptr;
	javaClassNoOperationsInterfacePropIntSetterId = nullptr;
	javaClassNoOperationsInterfacePropIntGetterId = nullptr;
	javaClassNoOperationsInterfaceSigVoidSignalMethodID = nullptr;
	javaClassNoOperationsInterfaceSigBoolSignalMethodID = nullptr;
	env->DeleteGlobalRef(javaClassNoSignalsInterface);
	javaClassNoSignalsInterface = nullptr;
	javaClassNoSignalsInterfacePropBoolSetterId = nullptr;
	javaClassNoSignalsInterfacePropBoolGetterId = nullptr;
	javaClassNoSignalsInterfacePropIntSetterId = nullptr;
	javaClassNoSignalsInterfacePropIntGetterId = nullptr;
	javaClassNoSignalsInterfaceFuncVoidMethodID = nullptr;
	javaClassNoSignalsInterfaceFuncBoolMethodID = nullptr;
	env->DeleteGlobalRef(javaClassEmptyInterface);
	javaClassEmptyInterface = nullptr;
}

bool TbSimpleJniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
