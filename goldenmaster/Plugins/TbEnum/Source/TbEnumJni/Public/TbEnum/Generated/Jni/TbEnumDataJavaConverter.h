
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
#include "TbEnum/Generated/api/TbEnum_data.h"
#include "TbEnum/Generated/api/TbEnum_apig.h"
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
DECLARE_LOG_CATEGORY_EXTERN(LogTbEnumDataJavaConverter_JNI, Log, All);

struct FTbEnumDataJavaConverterCacheData;

class TBENUMAPI_API TbEnumDataJavaConverter
{
public:
	static void fillEnum0Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum0>& out_array);
	static ETbEnumEnum0 getEnum0Value(JNIEnv* env, jobject input);
	static jobjectArray makeJavaEnum0Array(JNIEnv* env, const TArray<ETbEnumEnum0>& cppArray);
	static jobject makeJavaEnum0(JNIEnv* env, ETbEnumEnum0 value);

	static void fillEnum1Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum1>& out_array);
	static ETbEnumEnum1 getEnum1Value(JNIEnv* env, jobject input);
	static jobjectArray makeJavaEnum1Array(JNIEnv* env, const TArray<ETbEnumEnum1>& cppArray);
	static jobject makeJavaEnum1(JNIEnv* env, ETbEnumEnum1 value);

	static void fillEnum2Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum2>& out_array);
	static ETbEnumEnum2 getEnum2Value(JNIEnv* env, jobject input);
	static jobjectArray makeJavaEnum2Array(JNIEnv* env, const TArray<ETbEnumEnum2>& cppArray);
	static jobject makeJavaEnum2(JNIEnv* env, ETbEnumEnum2 value);

	static void fillEnum3Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum3>& out_array);
	static ETbEnumEnum3 getEnum3Value(JNIEnv* env, jobject input);
	static jobjectArray makeJavaEnum3Array(JNIEnv* env, const TArray<ETbEnumEnum3>& cppArray);
	static jobject makeJavaEnum3(JNIEnv* env, ETbEnumEnum3 value);

	static void fillEnumInterface(JNIEnv* env, jobject input, TScriptInterface<ITbEnumEnumInterfaceInterface> out_enum_interface);
	static void fillEnumInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbEnumEnumInterfaceInterface>>& out_array);
	static jobject makeJavaEnumInterface(JNIEnv* env, const TScriptInterface<ITbEnumEnumInterfaceInterface> out_enum_interface);
	static jobjectArray makeJavaEnumInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbEnumEnumInterfaceInterface>>& cppArray);

	static TScriptInterface<ITbEnumEnumInterfaceInterface> getCppInstanceTbEnumEnumInterface();

	static bool CheckJniErrorOccurred(const TCHAR* Msg);
	static void cleanJavaReferences();

private:
	static FCriticalSection CacheLock;
	static TSharedPtr<FTbEnumDataJavaConverterCacheData, ESPMode::ThreadSafe> CacheData;
	static TSharedPtr<FTbEnumDataJavaConverterCacheData, ESPMode::ThreadSafe> ensureInitialized();
	static jmethodID getMethod(jclass cls, const char* name, const char* signature, const TCHAR*);
	static jmethodID getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo);
	static jfieldID getFieldId(jclass cls, const char* name, const char* signature, const TCHAR*);
};

#endif
