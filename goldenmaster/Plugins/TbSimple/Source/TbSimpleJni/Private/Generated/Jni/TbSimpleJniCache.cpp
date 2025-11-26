
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
jclass TbSimpleJniCache::javaClassVoidInterface = nullptr;
jclass TbSimpleJniCache::serviceClassVoidInterface = nullptr;
jmethodID TbSimpleJniCache::serviceClassVoidInterfaceReadyMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassVoidInterfaceSigVoidSignalMethodID = nullptr;
jclass TbSimpleJniCache::clientClassVoidInterface = nullptr;
jmethodID TbSimpleJniCache::clientClassVoidInterfaceCtor = nullptr;
jmethodID TbSimpleJniCache::clientClassVoidInterfaceBindMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassVoidInterfaceUnbindMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassVoidInterfaceFuncVoidAsyncMethodID = nullptr;
jclass TbSimpleJniCache::javaClassSimpleInterface = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropBoolSetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropBoolGetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropIntSetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropIntGetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropInt32SetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropInt32GetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropInt64SetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropInt64GetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropFloatSetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropFloatGetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropFloat32SetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropFloat32GetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropFloat64SetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropFloat64GetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropStringSetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleInterfacePropStringGetterId = nullptr;
jclass TbSimpleJniCache::serviceClassSimpleInterface = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfaceReadyMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfacePropBoolChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfacePropIntChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfacePropInt32ChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfacePropInt64ChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfacePropFloatChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfacePropFloat32ChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfacePropFloat64ChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfacePropStringChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfaceSigBoolSignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfaceSigIntSignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfaceSigInt32SignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfaceSigInt64SignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfaceSigFloatSignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfaceSigFloat32SignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfaceSigFloat64SignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleInterfaceSigStringSignalMethodID = nullptr;
jclass TbSimpleJniCache::clientClassSimpleInterface = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleInterfaceCtor = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleInterfaceBindMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleInterfaceUnbindMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleInterfaceFuncNoReturnValueAsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleInterfaceFuncNoParamsAsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleInterfaceFuncBoolAsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleInterfaceFuncIntAsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleInterfaceFuncInt32AsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleInterfaceFuncInt64AsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleInterfaceFuncFloatAsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleInterfaceFuncFloat32AsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleInterfaceFuncFloat64AsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleInterfaceFuncStringAsyncMethodID = nullptr;
jclass TbSimpleJniCache::javaClassSimpleArrayInterface = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropBoolSetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropBoolGetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropIntSetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropIntGetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropInt32SetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropInt32GetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropInt64SetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropInt64GetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropFloatSetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropFloatGetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropFloat32SetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropFloat32GetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropFloat64SetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropFloat64GetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropStringSetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropStringGetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassSimpleArrayInterfacePropReadOnlyStringGetterId = nullptr;
jclass TbSimpleJniCache::serviceClassSimpleArrayInterface = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfaceReadyMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfacePropBoolChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfacePropIntChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfacePropInt32ChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfacePropInt64ChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfacePropFloatChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfacePropFloat32ChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfacePropFloat64ChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfacePropStringChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfacePropReadOnlyStringChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfaceSigBoolSignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfaceSigIntSignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfaceSigInt32SignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfaceSigInt64SignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfaceSigFloatSignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfaceSigFloat32SignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfaceSigFloat64SignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassSimpleArrayInterfaceSigStringSignalMethodID = nullptr;
jclass TbSimpleJniCache::clientClassSimpleArrayInterface = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleArrayInterfaceCtor = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleArrayInterfaceBindMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleArrayInterfaceUnbindMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleArrayInterfaceFuncBoolAsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleArrayInterfaceFuncIntAsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleArrayInterfaceFuncInt32AsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleArrayInterfaceFuncInt64AsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleArrayInterfaceFuncFloatAsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleArrayInterfaceFuncFloat32AsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleArrayInterfaceFuncFloat64AsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassSimpleArrayInterfaceFuncStringAsyncMethodID = nullptr;
jclass TbSimpleJniCache::javaClassNoPropertiesInterface = nullptr;
jclass TbSimpleJniCache::serviceClassNoPropertiesInterface = nullptr;
jmethodID TbSimpleJniCache::serviceClassNoPropertiesInterfaceReadyMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassNoPropertiesInterfaceSigVoidSignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassNoPropertiesInterfaceSigBoolSignalMethodID = nullptr;
jclass TbSimpleJniCache::clientClassNoPropertiesInterface = nullptr;
jmethodID TbSimpleJniCache::clientClassNoPropertiesInterfaceCtor = nullptr;
jmethodID TbSimpleJniCache::clientClassNoPropertiesInterfaceBindMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassNoPropertiesInterfaceUnbindMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassNoPropertiesInterfaceFuncVoidAsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassNoPropertiesInterfaceFuncBoolAsyncMethodID = nullptr;
jclass TbSimpleJniCache::javaClassNoOperationsInterface = nullptr;
jmethodID TbSimpleJniCache::javaClassNoOperationsInterfacePropBoolSetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassNoOperationsInterfacePropBoolGetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassNoOperationsInterfacePropIntSetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassNoOperationsInterfacePropIntGetterId = nullptr;
jclass TbSimpleJniCache::serviceClassNoOperationsInterface = nullptr;
jmethodID TbSimpleJniCache::serviceClassNoOperationsInterfaceReadyMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassNoOperationsInterfacePropBoolChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassNoOperationsInterfacePropIntChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassNoOperationsInterfaceSigVoidSignalMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassNoOperationsInterfaceSigBoolSignalMethodID = nullptr;
jclass TbSimpleJniCache::clientClassNoOperationsInterface = nullptr;
jmethodID TbSimpleJniCache::clientClassNoOperationsInterfaceCtor = nullptr;
jmethodID TbSimpleJniCache::clientClassNoOperationsInterfaceBindMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassNoOperationsInterfaceUnbindMethodID = nullptr;
jclass TbSimpleJniCache::javaClassNoSignalsInterface = nullptr;
jmethodID TbSimpleJniCache::javaClassNoSignalsInterfacePropBoolSetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassNoSignalsInterfacePropBoolGetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassNoSignalsInterfacePropIntSetterId = nullptr;
jmethodID TbSimpleJniCache::javaClassNoSignalsInterfacePropIntGetterId = nullptr;
jclass TbSimpleJniCache::serviceClassNoSignalsInterface = nullptr;
jmethodID TbSimpleJniCache::serviceClassNoSignalsInterfaceReadyMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassNoSignalsInterfacePropBoolChangedMethodID = nullptr;
jmethodID TbSimpleJniCache::serviceClassNoSignalsInterfacePropIntChangedMethodID = nullptr;
jclass TbSimpleJniCache::clientClassNoSignalsInterface = nullptr;
jmethodID TbSimpleJniCache::clientClassNoSignalsInterfaceCtor = nullptr;
jmethodID TbSimpleJniCache::clientClassNoSignalsInterfaceBindMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassNoSignalsInterfaceUnbindMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassNoSignalsInterfaceFuncVoidAsyncMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassNoSignalsInterfaceFuncBoolAsyncMethodID = nullptr;
jclass TbSimpleJniCache::javaClassEmptyInterface = nullptr;
jclass TbSimpleJniCache::serviceClassEmptyInterface = nullptr;
jmethodID TbSimpleJniCache::serviceClassEmptyInterfaceReadyMethodID = nullptr;
jclass TbSimpleJniCache::clientClassEmptyInterface = nullptr;
jmethodID TbSimpleJniCache::clientClassEmptyInterfaceCtor = nullptr;
jmethodID TbSimpleJniCache::clientClassEmptyInterfaceBindMethodID = nullptr;
jmethodID TbSimpleJniCache::clientClassEmptyInterfaceUnbindMethodID = nullptr;

bool TbSimpleJniCache::m_isInitialized = false;

void TbSimpleJniCache::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();

	javaClassVoidInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimple_api/IVoidInterface");

	serviceClassVoidInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimplejniservice/VoidInterfaceJniService");
	serviceClassVoidInterfaceReadyMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassVoidInterface, "nativeServiceReady", "(Z)V");
	serviceClassVoidInterfaceSigVoidSignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassVoidInterface, "onSigVoid", "()V");
	clientClassVoidInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimplejniclient/VoidInterfaceJniClient");
	clientClassVoidInterfaceFuncVoidAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassVoidInterface, "funcVoidAsync", "(Ljava/lang/String;)V");
	clientClassVoidInterfaceCtor = env->GetMethodID(TbSimpleJniCache::clientClassVoidInterface, "<init>", "()V");
	clientClassVoidInterfaceBindMethodID = env->GetMethodID(TbSimpleJniCache::clientClassVoidInterface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	clientClassVoidInterfaceUnbindMethodID = env->GetMethodID(TbSimpleJniCache::clientClassVoidInterface, "unbind", "()V");

	javaClassSimpleInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimple_api/ISimpleInterface");
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

	serviceClassSimpleInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimplejniservice/SimpleInterfaceJniService");
	serviceClassSimpleInterfaceReadyMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "nativeServiceReady", "(Z)V");
	serviceClassSimpleInterfacePropBoolChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onPropBoolChanged", "(Z)V");
	serviceClassSimpleInterfacePropIntChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onPropIntChanged", "(I)V");
	serviceClassSimpleInterfacePropInt32ChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onPropInt32Changed", "(I)V");
	serviceClassSimpleInterfacePropInt64ChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onPropInt64Changed", "(J)V");
	serviceClassSimpleInterfacePropFloatChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onPropFloatChanged", "(F)V");
	serviceClassSimpleInterfacePropFloat32ChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onPropFloat32Changed", "(F)V");
	serviceClassSimpleInterfacePropFloat64ChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onPropFloat64Changed", "(D)V");
	serviceClassSimpleInterfacePropStringChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onPropStringChanged", "(Ljava/lang/String;)V");
	serviceClassSimpleInterfaceSigBoolSignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onSigBool", "(Z)V");
	serviceClassSimpleInterfaceSigIntSignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onSigInt", "(I)V");
	serviceClassSimpleInterfaceSigInt32SignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onSigInt32", "(I)V");
	serviceClassSimpleInterfaceSigInt64SignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onSigInt64", "(J)V");
	serviceClassSimpleInterfaceSigFloatSignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onSigFloat", "(F)V");
	serviceClassSimpleInterfaceSigFloat32SignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onSigFloat32", "(F)V");
	serviceClassSimpleInterfaceSigFloat64SignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onSigFloat64", "(D)V");
	serviceClassSimpleInterfaceSigStringSignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleInterface, "onSigString", "(Ljava/lang/String;)V");
	clientClassSimpleInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimplejniclient/SimpleInterfaceJniClient");
	clientClassSimpleInterfaceFuncNoReturnValueAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleInterface, "funcNoReturnValueAsync", "(Ljava/lang/String;Z)V");
	clientClassSimpleInterfaceFuncNoParamsAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleInterface, "funcNoParamsAsync", "(Ljava/lang/String;)V");
	clientClassSimpleInterfaceFuncBoolAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleInterface, "funcBoolAsync", "(Ljava/lang/String;Z)V");
	clientClassSimpleInterfaceFuncIntAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleInterface, "funcIntAsync", "(Ljava/lang/String;I)V");
	clientClassSimpleInterfaceFuncInt32AsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleInterface, "funcInt32Async", "(Ljava/lang/String;I)V");
	clientClassSimpleInterfaceFuncInt64AsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleInterface, "funcInt64Async", "(Ljava/lang/String;J)V");
	clientClassSimpleInterfaceFuncFloatAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleInterface, "funcFloatAsync", "(Ljava/lang/String;F)V");
	clientClassSimpleInterfaceFuncFloat32AsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleInterface, "funcFloat32Async", "(Ljava/lang/String;F)V");
	clientClassSimpleInterfaceFuncFloat64AsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleInterface, "funcFloat64Async", "(Ljava/lang/String;D)V");
	clientClassSimpleInterfaceFuncStringAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleInterface, "funcStringAsync", "(Ljava/lang/String;Ljava/lang/String;)V");
	clientClassSimpleInterfaceCtor = env->GetMethodID(TbSimpleJniCache::clientClassSimpleInterface, "<init>", "()V");
	clientClassSimpleInterfaceBindMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleInterface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	clientClassSimpleInterfaceUnbindMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleInterface, "unbind", "()V");

	javaClassSimpleArrayInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimple_api/ISimpleArrayInterface");
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

	serviceClassSimpleArrayInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimplejniservice/SimpleArrayInterfaceJniService");
	serviceClassSimpleArrayInterfaceReadyMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "nativeServiceReady", "(Z)V");
	serviceClassSimpleArrayInterfacePropBoolChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onPropBoolChanged", "([Z)V");
	serviceClassSimpleArrayInterfacePropIntChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onPropIntChanged", "([I)V");
	serviceClassSimpleArrayInterfacePropInt32ChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onPropInt32Changed", "([I)V");
	serviceClassSimpleArrayInterfacePropInt64ChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onPropInt64Changed", "([J)V");
	serviceClassSimpleArrayInterfacePropFloatChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onPropFloatChanged", "([F)V");
	serviceClassSimpleArrayInterfacePropFloat32ChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onPropFloat32Changed", "([F)V");
	serviceClassSimpleArrayInterfacePropFloat64ChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onPropFloat64Changed", "([D)V");
	serviceClassSimpleArrayInterfacePropStringChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onPropStringChanged", "([Ljava/lang/String;)V");
	serviceClassSimpleArrayInterfacePropReadOnlyStringChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onPropReadOnlyStringChanged", "(Ljava/lang/String;)V");
	serviceClassSimpleArrayInterfaceSigBoolSignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onSigBool", "([Z)V");
	serviceClassSimpleArrayInterfaceSigIntSignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onSigInt", "([I)V");
	serviceClassSimpleArrayInterfaceSigInt32SignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onSigInt32", "([I)V");
	serviceClassSimpleArrayInterfaceSigInt64SignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onSigInt64", "([J)V");
	serviceClassSimpleArrayInterfaceSigFloatSignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onSigFloat", "([F)V");
	serviceClassSimpleArrayInterfaceSigFloat32SignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onSigFloat32", "([F)V");
	serviceClassSimpleArrayInterfaceSigFloat64SignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onSigFloat64", "([D)V");
	serviceClassSimpleArrayInterfaceSigStringSignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassSimpleArrayInterface, "onSigString", "([Ljava/lang/String;)V");
	clientClassSimpleArrayInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimplejniclient/SimpleArrayInterfaceJniClient");
	clientClassSimpleArrayInterfaceFuncBoolAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleArrayInterface, "funcBoolAsync", "(Ljava/lang/String;[Z)V");
	clientClassSimpleArrayInterfaceFuncIntAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleArrayInterface, "funcIntAsync", "(Ljava/lang/String;[I)V");
	clientClassSimpleArrayInterfaceFuncInt32AsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleArrayInterface, "funcInt32Async", "(Ljava/lang/String;[I)V");
	clientClassSimpleArrayInterfaceFuncInt64AsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleArrayInterface, "funcInt64Async", "(Ljava/lang/String;[J)V");
	clientClassSimpleArrayInterfaceFuncFloatAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleArrayInterface, "funcFloatAsync", "(Ljava/lang/String;[F)V");
	clientClassSimpleArrayInterfaceFuncFloat32AsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleArrayInterface, "funcFloat32Async", "(Ljava/lang/String;[F)V");
	clientClassSimpleArrayInterfaceFuncFloat64AsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleArrayInterface, "funcFloat64Async", "(Ljava/lang/String;[D)V");
	clientClassSimpleArrayInterfaceFuncStringAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleArrayInterface, "funcStringAsync", "(Ljava/lang/String;[Ljava/lang/String;)V");
	clientClassSimpleArrayInterfaceCtor = env->GetMethodID(TbSimpleJniCache::clientClassSimpleArrayInterface, "<init>", "()V");
	clientClassSimpleArrayInterfaceBindMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleArrayInterface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	clientClassSimpleArrayInterfaceUnbindMethodID = env->GetMethodID(TbSimpleJniCache::clientClassSimpleArrayInterface, "unbind", "()V");

	javaClassNoPropertiesInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimple_api/INoPropertiesInterface");

	serviceClassNoPropertiesInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimplejniservice/NoPropertiesInterfaceJniService");
	serviceClassNoPropertiesInterfaceReadyMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassNoPropertiesInterface, "nativeServiceReady", "(Z)V");
	serviceClassNoPropertiesInterfaceSigVoidSignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassNoPropertiesInterface, "onSigVoid", "()V");
	serviceClassNoPropertiesInterfaceSigBoolSignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassNoPropertiesInterface, "onSigBool", "(Z)V");
	clientClassNoPropertiesInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimplejniclient/NoPropertiesInterfaceJniClient");
	clientClassNoPropertiesInterfaceFuncVoidAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassNoPropertiesInterface, "funcVoidAsync", "(Ljava/lang/String;)V");
	clientClassNoPropertiesInterfaceFuncBoolAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassNoPropertiesInterface, "funcBoolAsync", "(Ljava/lang/String;Z)V");
	clientClassNoPropertiesInterfaceCtor = env->GetMethodID(TbSimpleJniCache::clientClassNoPropertiesInterface, "<init>", "()V");
	clientClassNoPropertiesInterfaceBindMethodID = env->GetMethodID(TbSimpleJniCache::clientClassNoPropertiesInterface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	clientClassNoPropertiesInterfaceUnbindMethodID = env->GetMethodID(TbSimpleJniCache::clientClassNoPropertiesInterface, "unbind", "()V");

	javaClassNoOperationsInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimple_api/INoOperationsInterface");
	javaClassNoOperationsInterfacePropBoolSetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoOperationsInterface, "setPropBool", "(Z)V");
	javaClassNoOperationsInterfacePropBoolGetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoOperationsInterface, "getPropBool", "()Z");
	javaClassNoOperationsInterfacePropIntSetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoOperationsInterface, "setPropInt", "(I)V");
	javaClassNoOperationsInterfacePropIntGetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoOperationsInterface, "getPropInt", "()I");

	serviceClassNoOperationsInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimplejniservice/NoOperationsInterfaceJniService");
	serviceClassNoOperationsInterfaceReadyMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassNoOperationsInterface, "nativeServiceReady", "(Z)V");
	serviceClassNoOperationsInterfacePropBoolChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassNoOperationsInterface, "onPropBoolChanged", "(Z)V");
	serviceClassNoOperationsInterfacePropIntChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassNoOperationsInterface, "onPropIntChanged", "(I)V");
	serviceClassNoOperationsInterfaceSigVoidSignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassNoOperationsInterface, "onSigVoid", "()V");
	serviceClassNoOperationsInterfaceSigBoolSignalMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassNoOperationsInterface, "onSigBool", "(Z)V");
	clientClassNoOperationsInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimplejniclient/NoOperationsInterfaceJniClient");
	clientClassNoOperationsInterfaceCtor = env->GetMethodID(TbSimpleJniCache::clientClassNoOperationsInterface, "<init>", "()V");
	clientClassNoOperationsInterfaceBindMethodID = env->GetMethodID(TbSimpleJniCache::clientClassNoOperationsInterface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	clientClassNoOperationsInterfaceUnbindMethodID = env->GetMethodID(TbSimpleJniCache::clientClassNoOperationsInterface, "unbind", "()V");

	javaClassNoSignalsInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimple_api/INoSignalsInterface");
	javaClassNoSignalsInterfacePropBoolSetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoSignalsInterface, "setPropBool", "(Z)V");
	javaClassNoSignalsInterfacePropBoolGetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoSignalsInterface, "getPropBool", "()Z");
	javaClassNoSignalsInterfacePropIntSetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoSignalsInterface, "setPropInt", "(I)V");
	javaClassNoSignalsInterfacePropIntGetterId = env->GetMethodID(TbSimpleJniCache::javaClassNoSignalsInterface, "getPropInt", "()I");

	serviceClassNoSignalsInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimplejniservice/NoSignalsInterfaceJniService");
	serviceClassNoSignalsInterfaceReadyMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassNoSignalsInterface, "nativeServiceReady", "(Z)V");
	serviceClassNoSignalsInterfacePropBoolChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassNoSignalsInterface, "onPropBoolChanged", "(Z)V");
	serviceClassNoSignalsInterfacePropIntChangedMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassNoSignalsInterface, "onPropIntChanged", "(I)V");
	clientClassNoSignalsInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimplejniclient/NoSignalsInterfaceJniClient");
	clientClassNoSignalsInterfaceFuncVoidAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassNoSignalsInterface, "funcVoidAsync", "(Ljava/lang/String;)V");
	clientClassNoSignalsInterfaceFuncBoolAsyncMethodID = env->GetMethodID(TbSimpleJniCache::clientClassNoSignalsInterface, "funcBoolAsync", "(Ljava/lang/String;Z)V");
	clientClassNoSignalsInterfaceCtor = env->GetMethodID(TbSimpleJniCache::clientClassNoSignalsInterface, "<init>", "()V");
	clientClassNoSignalsInterfaceBindMethodID = env->GetMethodID(TbSimpleJniCache::clientClassNoSignalsInterface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	clientClassNoSignalsInterfaceUnbindMethodID = env->GetMethodID(TbSimpleJniCache::clientClassNoSignalsInterface, "unbind", "()V");

	javaClassEmptyInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimple_api/IEmptyInterface");

	serviceClassEmptyInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimplejniservice/EmptyInterfaceJniService");
	serviceClassEmptyInterfaceReadyMethodID = env->GetMethodID(TbSimpleJniCache::serviceClassEmptyInterface, "nativeServiceReady", "(Z)V");
	clientClassEmptyInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimplejniclient/EmptyInterfaceJniClient");
	clientClassEmptyInterfaceCtor = env->GetMethodID(TbSimpleJniCache::clientClassEmptyInterface, "<init>", "()V");
	clientClassEmptyInterfaceBindMethodID = env->GetMethodID(TbSimpleJniCache::clientClassEmptyInterface, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	clientClassEmptyInterfaceUnbindMethodID = env->GetMethodID(TbSimpleJniCache::clientClassEmptyInterface, "unbind", "()V");
	m_isInitialized = true;
}

void TbSimpleJniCache::clear()
{
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(javaClassVoidInterface);
	javaClassVoidInterface = nullptr;
	env->DeleteGlobalRef(serviceClassVoidInterface);
	serviceClassVoidInterface = nullptr;
	serviceClassVoidInterfaceReadyMethodID = nullptr;
	serviceClassVoidInterfaceSigVoidSignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassVoidInterface);
	clientClassVoidInterface = nullptr;
	clientClassVoidInterfaceFuncVoidAsyncMethodID = nullptr;
	clientClassVoidInterfaceCtor = nullptr;
	clientClassVoidInterfaceBindMethodID = nullptr;
	clientClassVoidInterfaceUnbindMethodID = nullptr;
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
	env->DeleteGlobalRef(serviceClassSimpleInterface);
	serviceClassSimpleInterface = nullptr;
	serviceClassSimpleInterfaceReadyMethodID = nullptr;
	serviceClassSimpleInterfacePropBoolChangedMethodID = nullptr;
	serviceClassSimpleInterfacePropIntChangedMethodID = nullptr;
	serviceClassSimpleInterfacePropInt32ChangedMethodID = nullptr;
	serviceClassSimpleInterfacePropInt64ChangedMethodID = nullptr;
	serviceClassSimpleInterfacePropFloatChangedMethodID = nullptr;
	serviceClassSimpleInterfacePropFloat32ChangedMethodID = nullptr;
	serviceClassSimpleInterfacePropFloat64ChangedMethodID = nullptr;
	serviceClassSimpleInterfacePropStringChangedMethodID = nullptr;
	serviceClassSimpleInterfaceSigBoolSignalMethodID = nullptr;
	serviceClassSimpleInterfaceSigIntSignalMethodID = nullptr;
	serviceClassSimpleInterfaceSigInt32SignalMethodID = nullptr;
	serviceClassSimpleInterfaceSigInt64SignalMethodID = nullptr;
	serviceClassSimpleInterfaceSigFloatSignalMethodID = nullptr;
	serviceClassSimpleInterfaceSigFloat32SignalMethodID = nullptr;
	serviceClassSimpleInterfaceSigFloat64SignalMethodID = nullptr;
	serviceClassSimpleInterfaceSigStringSignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassSimpleInterface);
	clientClassSimpleInterface = nullptr;
	clientClassSimpleInterfaceFuncNoReturnValueAsyncMethodID = nullptr;
	clientClassSimpleInterfaceFuncNoParamsAsyncMethodID = nullptr;
	clientClassSimpleInterfaceFuncBoolAsyncMethodID = nullptr;
	clientClassSimpleInterfaceFuncIntAsyncMethodID = nullptr;
	clientClassSimpleInterfaceFuncInt32AsyncMethodID = nullptr;
	clientClassSimpleInterfaceFuncInt64AsyncMethodID = nullptr;
	clientClassSimpleInterfaceFuncFloatAsyncMethodID = nullptr;
	clientClassSimpleInterfaceFuncFloat32AsyncMethodID = nullptr;
	clientClassSimpleInterfaceFuncFloat64AsyncMethodID = nullptr;
	clientClassSimpleInterfaceFuncStringAsyncMethodID = nullptr;
	clientClassSimpleInterfaceCtor = nullptr;
	clientClassSimpleInterfaceBindMethodID = nullptr;
	clientClassSimpleInterfaceUnbindMethodID = nullptr;
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
	env->DeleteGlobalRef(serviceClassSimpleArrayInterface);
	serviceClassSimpleArrayInterface = nullptr;
	serviceClassSimpleArrayInterfaceReadyMethodID = nullptr;
	serviceClassSimpleArrayInterfacePropBoolChangedMethodID = nullptr;
	serviceClassSimpleArrayInterfacePropIntChangedMethodID = nullptr;
	serviceClassSimpleArrayInterfacePropInt32ChangedMethodID = nullptr;
	serviceClassSimpleArrayInterfacePropInt64ChangedMethodID = nullptr;
	serviceClassSimpleArrayInterfacePropFloatChangedMethodID = nullptr;
	serviceClassSimpleArrayInterfacePropFloat32ChangedMethodID = nullptr;
	serviceClassSimpleArrayInterfacePropFloat64ChangedMethodID = nullptr;
	serviceClassSimpleArrayInterfacePropStringChangedMethodID = nullptr;
	serviceClassSimpleArrayInterfacePropReadOnlyStringChangedMethodID = nullptr;
	serviceClassSimpleArrayInterfaceSigBoolSignalMethodID = nullptr;
	serviceClassSimpleArrayInterfaceSigIntSignalMethodID = nullptr;
	serviceClassSimpleArrayInterfaceSigInt32SignalMethodID = nullptr;
	serviceClassSimpleArrayInterfaceSigInt64SignalMethodID = nullptr;
	serviceClassSimpleArrayInterfaceSigFloatSignalMethodID = nullptr;
	serviceClassSimpleArrayInterfaceSigFloat32SignalMethodID = nullptr;
	serviceClassSimpleArrayInterfaceSigFloat64SignalMethodID = nullptr;
	serviceClassSimpleArrayInterfaceSigStringSignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassSimpleArrayInterface);
	clientClassSimpleArrayInterface = nullptr;
	clientClassSimpleArrayInterfaceFuncBoolAsyncMethodID = nullptr;
	clientClassSimpleArrayInterfaceFuncIntAsyncMethodID = nullptr;
	clientClassSimpleArrayInterfaceFuncInt32AsyncMethodID = nullptr;
	clientClassSimpleArrayInterfaceFuncInt64AsyncMethodID = nullptr;
	clientClassSimpleArrayInterfaceFuncFloatAsyncMethodID = nullptr;
	clientClassSimpleArrayInterfaceFuncFloat32AsyncMethodID = nullptr;
	clientClassSimpleArrayInterfaceFuncFloat64AsyncMethodID = nullptr;
	clientClassSimpleArrayInterfaceFuncStringAsyncMethodID = nullptr;
	clientClassSimpleArrayInterfaceCtor = nullptr;
	clientClassSimpleArrayInterfaceBindMethodID = nullptr;
	clientClassSimpleArrayInterfaceUnbindMethodID = nullptr;
	env->DeleteGlobalRef(javaClassNoPropertiesInterface);
	javaClassNoPropertiesInterface = nullptr;
	env->DeleteGlobalRef(serviceClassNoPropertiesInterface);
	serviceClassNoPropertiesInterface = nullptr;
	serviceClassNoPropertiesInterfaceReadyMethodID = nullptr;
	serviceClassNoPropertiesInterfaceSigVoidSignalMethodID = nullptr;
	serviceClassNoPropertiesInterfaceSigBoolSignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassNoPropertiesInterface);
	clientClassNoPropertiesInterface = nullptr;
	clientClassNoPropertiesInterfaceFuncVoidAsyncMethodID = nullptr;
	clientClassNoPropertiesInterfaceFuncBoolAsyncMethodID = nullptr;
	clientClassNoPropertiesInterfaceCtor = nullptr;
	clientClassNoPropertiesInterfaceBindMethodID = nullptr;
	clientClassNoPropertiesInterfaceUnbindMethodID = nullptr;
	env->DeleteGlobalRef(javaClassNoOperationsInterface);
	javaClassNoOperationsInterface = nullptr;
	javaClassNoOperationsInterfacePropBoolSetterId = nullptr;
	javaClassNoOperationsInterfacePropBoolGetterId = nullptr;
	javaClassNoOperationsInterfacePropIntSetterId = nullptr;
	javaClassNoOperationsInterfacePropIntGetterId = nullptr;
	env->DeleteGlobalRef(serviceClassNoOperationsInterface);
	serviceClassNoOperationsInterface = nullptr;
	serviceClassNoOperationsInterfaceReadyMethodID = nullptr;
	serviceClassNoOperationsInterfacePropBoolChangedMethodID = nullptr;
	serviceClassNoOperationsInterfacePropIntChangedMethodID = nullptr;
	serviceClassNoOperationsInterfaceSigVoidSignalMethodID = nullptr;
	serviceClassNoOperationsInterfaceSigBoolSignalMethodID = nullptr;
	env->DeleteGlobalRef(clientClassNoOperationsInterface);
	clientClassNoOperationsInterface = nullptr;
	clientClassNoOperationsInterfaceCtor = nullptr;
	clientClassNoOperationsInterfaceBindMethodID = nullptr;
	clientClassNoOperationsInterfaceUnbindMethodID = nullptr;
	env->DeleteGlobalRef(javaClassNoSignalsInterface);
	javaClassNoSignalsInterface = nullptr;
	javaClassNoSignalsInterfacePropBoolSetterId = nullptr;
	javaClassNoSignalsInterfacePropBoolGetterId = nullptr;
	javaClassNoSignalsInterfacePropIntSetterId = nullptr;
	javaClassNoSignalsInterfacePropIntGetterId = nullptr;
	env->DeleteGlobalRef(serviceClassNoSignalsInterface);
	serviceClassNoSignalsInterface = nullptr;
	serviceClassNoSignalsInterfaceReadyMethodID = nullptr;
	serviceClassNoSignalsInterfacePropBoolChangedMethodID = nullptr;
	serviceClassNoSignalsInterfacePropIntChangedMethodID = nullptr;
	env->DeleteGlobalRef(clientClassNoSignalsInterface);
	clientClassNoSignalsInterface = nullptr;
	clientClassNoSignalsInterfaceFuncVoidAsyncMethodID = nullptr;
	clientClassNoSignalsInterfaceFuncBoolAsyncMethodID = nullptr;
	clientClassNoSignalsInterfaceCtor = nullptr;
	clientClassNoSignalsInterfaceBindMethodID = nullptr;
	clientClassNoSignalsInterfaceUnbindMethodID = nullptr;
	env->DeleteGlobalRef(javaClassEmptyInterface);
	javaClassEmptyInterface = nullptr;
	env->DeleteGlobalRef(serviceClassEmptyInterface);
	serviceClassEmptyInterface = nullptr;
	serviceClassEmptyInterfaceReadyMethodID = nullptr;
	env->DeleteGlobalRef(clientClassEmptyInterface);
	clientClassEmptyInterface = nullptr;
	clientClassEmptyInterfaceCtor = nullptr;
	clientClassEmptyInterfaceBindMethodID = nullptr;
	clientClassEmptyInterfaceUnbindMethodID = nullptr;
}

bool TbSimpleJniCache::isInitialized()
{
	return m_isInitialized;
}

#endif
