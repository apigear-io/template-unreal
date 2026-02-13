
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
#include "Testbed2/Generated/api/Testbed2_data.h"
#include "Testbed2/Generated/api/Testbed2_apig.h"
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
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2DataJavaConverter_JNI, Log, All);

struct FTestbed2DataJavaConverterCacheData;

class TESTBED2API_API Testbed2DataJavaConverter
{
public:
	static void fillStruct1(JNIEnv* env, jobject input, FTestbed2Struct1& out_struct1);
	static void fillStruct1Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct1>& out_array);
	static jobject makeJavaStruct1(JNIEnv* env, const FTestbed2Struct1& out_struct1);
	static jobjectArray makeJavaStruct1Array(JNIEnv* env, const TArray<FTestbed2Struct1>& cppArray);
	static void fillStruct2(JNIEnv* env, jobject input, FTestbed2Struct2& out_struct2);
	static void fillStruct2Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct2>& out_array);
	static jobject makeJavaStruct2(JNIEnv* env, const FTestbed2Struct2& out_struct2);
	static jobjectArray makeJavaStruct2Array(JNIEnv* env, const TArray<FTestbed2Struct2>& cppArray);
	static void fillStruct3(JNIEnv* env, jobject input, FTestbed2Struct3& out_struct3);
	static void fillStruct3Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct3>& out_array);
	static jobject makeJavaStruct3(JNIEnv* env, const FTestbed2Struct3& out_struct3);
	static jobjectArray makeJavaStruct3Array(JNIEnv* env, const TArray<FTestbed2Struct3>& cppArray);
	static void fillStruct4(JNIEnv* env, jobject input, FTestbed2Struct4& out_struct4);
	static void fillStruct4Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct4>& out_array);
	static jobject makeJavaStruct4(JNIEnv* env, const FTestbed2Struct4& out_struct4);
	static jobjectArray makeJavaStruct4Array(JNIEnv* env, const TArray<FTestbed2Struct4>& cppArray);
	static void fillNestedStruct1(JNIEnv* env, jobject input, FTestbed2NestedStruct1& out_nested_struct1);
	static void fillNestedStruct1Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2NestedStruct1>& out_array);
	static jobject makeJavaNestedStruct1(JNIEnv* env, const FTestbed2NestedStruct1& out_nested_struct1);
	static jobjectArray makeJavaNestedStruct1Array(JNIEnv* env, const TArray<FTestbed2NestedStruct1>& cppArray);
	static void fillNestedStruct2(JNIEnv* env, jobject input, FTestbed2NestedStruct2& out_nested_struct2);
	static void fillNestedStruct2Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2NestedStruct2>& out_array);
	static jobject makeJavaNestedStruct2(JNIEnv* env, const FTestbed2NestedStruct2& out_nested_struct2);
	static jobjectArray makeJavaNestedStruct2Array(JNIEnv* env, const TArray<FTestbed2NestedStruct2>& cppArray);
	static void fillNestedStruct3(JNIEnv* env, jobject input, FTestbed2NestedStruct3& out_nested_struct3);
	static void fillNestedStruct3Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2NestedStruct3>& out_array);
	static jobject makeJavaNestedStruct3(JNIEnv* env, const FTestbed2NestedStruct3& out_nested_struct3);
	static jobjectArray makeJavaNestedStruct3Array(JNIEnv* env, const TArray<FTestbed2NestedStruct3>& cppArray);

	static void fillEnum1Array(JNIEnv* env, jobjectArray input, TArray<ETestbed2Enum1>& out_array);
	static ETestbed2Enum1 getEnum1Value(JNIEnv* env, jobject input);
	static jobjectArray makeJavaEnum1Array(JNIEnv* env, const TArray<ETestbed2Enum1>& cppArray);
	static jobject makeJavaEnum1(JNIEnv* env, ETestbed2Enum1 value);

	static void fillEnum2Array(JNIEnv* env, jobjectArray input, TArray<ETestbed2Enum2>& out_array);
	static ETestbed2Enum2 getEnum2Value(JNIEnv* env, jobject input);
	static jobjectArray makeJavaEnum2Array(JNIEnv* env, const TArray<ETestbed2Enum2>& cppArray);
	static jobject makeJavaEnum2(JNIEnv* env, ETestbed2Enum2 value);

	static void fillEnum3Array(JNIEnv* env, jobjectArray input, TArray<ETestbed2Enum3>& out_array);
	static ETestbed2Enum3 getEnum3Value(JNIEnv* env, jobject input);
	static jobjectArray makeJavaEnum3Array(JNIEnv* env, const TArray<ETestbed2Enum3>& cppArray);
	static jobject makeJavaEnum3(JNIEnv* env, ETestbed2Enum3 value);

	static void fillManyParamInterface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2ManyParamInterfaceInterface> out_many_param_interface);
	static void fillManyParamInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2ManyParamInterfaceInterface>>& out_array);
	static jobject makeJavaManyParamInterface(JNIEnv* env, const TScriptInterface<ITestbed2ManyParamInterfaceInterface> out_many_param_interface);
	static jobjectArray makeJavaManyParamInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed2ManyParamInterfaceInterface>>& cppArray);

	static TScriptInterface<ITestbed2ManyParamInterfaceInterface> getCppInstanceTestbed2ManyParamInterface();

	static void fillNestedStruct1Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> out_nested_struct1_interface);
	static void fillNestedStruct1InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2NestedStruct1InterfaceInterface>>& out_array);
	static jobject makeJavaNestedStruct1Interface(JNIEnv* env, const TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> out_nested_struct1_interface);
	static jobjectArray makeJavaNestedStruct1InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed2NestedStruct1InterfaceInterface>>& cppArray);

	static TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> getCppInstanceTestbed2NestedStruct1Interface();

	static void fillNestedStruct2Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> out_nested_struct2_interface);
	static void fillNestedStruct2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2NestedStruct2InterfaceInterface>>& out_array);
	static jobject makeJavaNestedStruct2Interface(JNIEnv* env, const TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> out_nested_struct2_interface);
	static jobjectArray makeJavaNestedStruct2InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed2NestedStruct2InterfaceInterface>>& cppArray);

	static TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> getCppInstanceTestbed2NestedStruct2Interface();

	static void fillNestedStruct3Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> out_nested_struct3_interface);
	static void fillNestedStruct3InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceInterface>>& out_array);
	static jobject makeJavaNestedStruct3Interface(JNIEnv* env, const TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> out_nested_struct3_interface);
	static jobjectArray makeJavaNestedStruct3InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceInterface>>& cppArray);

	static TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> getCppInstanceTestbed2NestedStruct3Interface();

	static bool checkJniErrorOccured(const TCHAR* Msg);
	static void cleanJavaReferences();

private:
	static FCriticalSection CacheLock;
	static TSharedPtr<FTestbed2DataJavaConverterCacheData, ESPMode::ThreadSafe> CacheData;
	static TSharedPtr<FTestbed2DataJavaConverterCacheData, ESPMode::ThreadSafe> ensureInitialized();
	static jmethodID getMethod(jclass cls, const char* name, const char* signature, const TCHAR*);
	static jmethodID getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo);
	static jfieldID getFieldId(jclass cls, const char* name, const char* signature, const TCHAR*);
};

#endif
