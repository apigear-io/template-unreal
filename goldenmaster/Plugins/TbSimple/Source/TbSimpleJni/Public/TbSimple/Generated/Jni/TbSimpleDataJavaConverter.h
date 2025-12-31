
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

#include "TbSimple/Generated/api/TbSimple_apig.h"
#if PLATFORM_ANDROID

#include "HAL/CriticalSection.h"
#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleDataJavaConverter_JNI, Log, All);

class TBSIMPLEAPI_API TbSimpleDataJavaConverter
{
public:
	static jclass jVoidInterface;
	static void fillVoidInterface(JNIEnv* env, jobject input, TScriptInterface<ITbSimpleVoidInterfaceInterface> out_void_interface);
	static void fillVoidInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSimpleVoidInterfaceInterface>>& out_array);
	static jobject makeJavaVoidInterface(JNIEnv* env, const TScriptInterface<ITbSimpleVoidInterfaceInterface> out_void_interface);
	static jobjectArray makeJavaVoidInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSimpleVoidInterfaceInterface>>& cppArray);

	static TScriptInterface<ITbSimpleVoidInterfaceInterface> getCppInstanceTbSimpleVoidInterface();

	static jclass jSimpleInterface;
	static void fillSimpleInterface(JNIEnv* env, jobject input, TScriptInterface<ITbSimpleSimpleInterfaceInterface> out_simple_interface);
	static void fillSimpleInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSimpleSimpleInterfaceInterface>>& out_array);
	static jobject makeJavaSimpleInterface(JNIEnv* env, const TScriptInterface<ITbSimpleSimpleInterfaceInterface> out_simple_interface);
	static jobjectArray makeJavaSimpleInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSimpleSimpleInterfaceInterface>>& cppArray);

	static TScriptInterface<ITbSimpleSimpleInterfaceInterface> getCppInstanceTbSimpleSimpleInterface();

	static jclass jSimpleArrayInterface;
	static void fillSimpleArrayInterface(JNIEnv* env, jobject input, TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> out_simple_array_interface);
	static void fillSimpleArrayInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface>>& out_array);
	static jobject makeJavaSimpleArrayInterface(JNIEnv* env, const TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> out_simple_array_interface);
	static jobjectArray makeJavaSimpleArrayInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface>>& cppArray);

	static TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> getCppInstanceTbSimpleSimpleArrayInterface();

	static jclass jNoPropertiesInterface;
	static void fillNoPropertiesInterface(JNIEnv* env, jobject input, TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> out_no_properties_interface);
	static void fillNoPropertiesInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface>>& out_array);
	static jobject makeJavaNoPropertiesInterface(JNIEnv* env, const TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> out_no_properties_interface);
	static jobjectArray makeJavaNoPropertiesInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface>>& cppArray);

	static TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> getCppInstanceTbSimpleNoPropertiesInterface();

	static jclass jNoOperationsInterface;
	static void fillNoOperationsInterface(JNIEnv* env, jobject input, TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> out_no_operations_interface);
	static void fillNoOperationsInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceInterface>>& out_array);
	static jobject makeJavaNoOperationsInterface(JNIEnv* env, const TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> out_no_operations_interface);
	static jobjectArray makeJavaNoOperationsInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceInterface>>& cppArray);

	static TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> getCppInstanceTbSimpleNoOperationsInterface();

	static jclass jNoSignalsInterface;
	static void fillNoSignalsInterface(JNIEnv* env, jobject input, TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> out_no_signals_interface);
	static void fillNoSignalsInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSimpleNoSignalsInterfaceInterface>>& out_array);
	static jobject makeJavaNoSignalsInterface(JNIEnv* env, const TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> out_no_signals_interface);
	static jobjectArray makeJavaNoSignalsInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSimpleNoSignalsInterfaceInterface>>& cppArray);

	static TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> getCppInstanceTbSimpleNoSignalsInterface();

	static jclass jEmptyInterface;
	static void fillEmptyInterface(JNIEnv* env, jobject input, TScriptInterface<ITbSimpleEmptyInterfaceInterface> out_empty_interface);
	static void fillEmptyInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSimpleEmptyInterfaceInterface>>& out_array);
	static jobject makeJavaEmptyInterface(JNIEnv* env, const TScriptInterface<ITbSimpleEmptyInterfaceInterface> out_empty_interface);
	static jobjectArray makeJavaEmptyInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSimpleEmptyInterfaceInterface>>& cppArray);

	static TScriptInterface<ITbSimpleEmptyInterfaceInterface> getCppInstanceTbSimpleEmptyInterface();

	static bool checkJniErrorOccured(const TCHAR* Msg);
	static void cleanJavaReferences();

private:
	static FCriticalSection initMutex;
	static void ensureInitialized();
	static bool m_isInitialized;
	static jmethodID getMethod(jclass cls, const char* name, const char* signature, const TCHAR*);
	static jmethodID getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo);
	static jfieldID getFieldId(jclass cls, const char* name, const char* signature, const TCHAR*);
};

#endif
