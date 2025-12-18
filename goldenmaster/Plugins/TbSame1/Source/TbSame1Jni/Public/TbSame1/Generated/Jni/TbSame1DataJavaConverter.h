
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
#include "TbSame1/Generated/api/TbSame1_data.h"
#include "TbSame1/Generated/api/TbSame1_apig.h"
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
DECLARE_LOG_CATEGORY_EXTERN(LogTbSame1DataJavaConverter_JNI, Log, All);

class TBSAME1API_API TbSame1DataJavaConverter
{
public:
	static jclass jStruct1;
	static void fillStruct1(JNIEnv* env, jobject input, FTbSame1Struct1& out_struct1);
	static void fillStruct1Array(JNIEnv* env, jobjectArray input, TArray<FTbSame1Struct1>& out_array);
	static jobject makeJavaStruct1(JNIEnv* env, const FTbSame1Struct1& out_struct1);
	static jobjectArray makeJavaStruct1Array(JNIEnv* env, const TArray<FTbSame1Struct1>& cppArray);
	static jclass jStruct2;
	static void fillStruct2(JNIEnv* env, jobject input, FTbSame1Struct2& out_struct2);
	static void fillStruct2Array(JNIEnv* env, jobjectArray input, TArray<FTbSame1Struct2>& out_array);
	static jobject makeJavaStruct2(JNIEnv* env, const FTbSame1Struct2& out_struct2);
	static jobjectArray makeJavaStruct2Array(JNIEnv* env, const TArray<FTbSame1Struct2>& cppArray);

	static jclass jEnum1;
	static void fillEnum1Array(JNIEnv* env, jobjectArray input, TArray<ETbSame1Enum1>& out_array);
	static ETbSame1Enum1 getEnum1Value(JNIEnv* env, jobject input);
	static jobjectArray makeJavaEnum1Array(JNIEnv* env, const TArray<ETbSame1Enum1>& cppArray);
	static jobject makeJavaEnum1(JNIEnv* env, ETbSame1Enum1 value);

	static jclass jEnum2;
	static void fillEnum2Array(JNIEnv* env, jobjectArray input, TArray<ETbSame1Enum2>& out_array);
	static ETbSame1Enum2 getEnum2Value(JNIEnv* env, jobject input);
	static jobjectArray makeJavaEnum2Array(JNIEnv* env, const TArray<ETbSame1Enum2>& cppArray);
	static jobject makeJavaEnum2(JNIEnv* env, ETbSame1Enum2 value);

	static jclass jSameStruct1Interface;
	static void fillSameStruct1Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame1SameStruct1InterfaceInterface> out_same_struct1_interface);
	static void fillSameStruct1InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame1SameStruct1InterfaceInterface>>& out_array);
	static jobject makeJavaSameStruct1Interface(JNIEnv* env, const TScriptInterface<ITbSame1SameStruct1InterfaceInterface> out_same_struct1_interface);
	static jobjectArray makeJavaSameStruct1InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame1SameStruct1InterfaceInterface>>& cppArray);

	static TScriptInterface<ITbSame1SameStruct1InterfaceInterface> getCppInstanceTbSame1SameStruct1Interface();

	static jclass jSameStruct2Interface;
	static void fillSameStruct2Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame1SameStruct2InterfaceInterface> out_same_struct2_interface);
	static void fillSameStruct2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame1SameStruct2InterfaceInterface>>& out_array);
	static jobject makeJavaSameStruct2Interface(JNIEnv* env, const TScriptInterface<ITbSame1SameStruct2InterfaceInterface> out_same_struct2_interface);
	static jobjectArray makeJavaSameStruct2InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame1SameStruct2InterfaceInterface>>& cppArray);

	static TScriptInterface<ITbSame1SameStruct2InterfaceInterface> getCppInstanceTbSame1SameStruct2Interface();

	static jclass jSameEnum1Interface;
	static void fillSameEnum1Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame1SameEnum1InterfaceInterface> out_same_enum1_interface);
	static void fillSameEnum1InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame1SameEnum1InterfaceInterface>>& out_array);
	static jobject makeJavaSameEnum1Interface(JNIEnv* env, const TScriptInterface<ITbSame1SameEnum1InterfaceInterface> out_same_enum1_interface);
	static jobjectArray makeJavaSameEnum1InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame1SameEnum1InterfaceInterface>>& cppArray);

	static TScriptInterface<ITbSame1SameEnum1InterfaceInterface> getCppInstanceTbSame1SameEnum1Interface();

	static jclass jSameEnum2Interface;
	static void fillSameEnum2Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame1SameEnum2InterfaceInterface> out_same_enum2_interface);
	static void fillSameEnum2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame1SameEnum2InterfaceInterface>>& out_array);
	static jobject makeJavaSameEnum2Interface(JNIEnv* env, const TScriptInterface<ITbSame1SameEnum2InterfaceInterface> out_same_enum2_interface);
	static jobjectArray makeJavaSameEnum2InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame1SameEnum2InterfaceInterface>>& cppArray);

	static TScriptInterface<ITbSame1SameEnum2InterfaceInterface> getCppInstanceTbSame1SameEnum2Interface();

	static bool checkJniErrorOccured(const TCHAR* Msg);
	static void cleanJavaReferences();

private:
	static FCriticalSection initMutex;
	static void ensureInitialized();
	static bool m_isInitialized;
};

#endif
