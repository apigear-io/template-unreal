
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
#include "Testbed1/Generated/api/Testbed1_data.h"
#include "Testbed1/Generated/api/Testbed1_apig.h"
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
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1DataJavaConverter_JNI, Log, All);

class TESTBED1API_API Testbed1DataJavaConverter
{
public:
	static jclass jStructBool;
	static void fillStructBool(JNIEnv* env, jobject input, FTestbed1StructBool& out_struct_bool);
	static void fillStructBoolArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructBool>& out_array);
	static jobject makeJavaStructBool(JNIEnv* env, const FTestbed1StructBool& out_struct_bool);
	static jobjectArray makeJavaStructBoolArray(JNIEnv* env, const TArray<FTestbed1StructBool>& cppArray);
	static jclass jStructInt;
	static void fillStructInt(JNIEnv* env, jobject input, FTestbed1StructInt& out_struct_int);
	static void fillStructIntArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructInt>& out_array);
	static jobject makeJavaStructInt(JNIEnv* env, const FTestbed1StructInt& out_struct_int);
	static jobjectArray makeJavaStructIntArray(JNIEnv* env, const TArray<FTestbed1StructInt>& cppArray);
	static jclass jStructFloat;
	static void fillStructFloat(JNIEnv* env, jobject input, FTestbed1StructFloat& out_struct_float);
	static void fillStructFloatArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructFloat>& out_array);
	static jobject makeJavaStructFloat(JNIEnv* env, const FTestbed1StructFloat& out_struct_float);
	static jobjectArray makeJavaStructFloatArray(JNIEnv* env, const TArray<FTestbed1StructFloat>& cppArray);
	static jclass jStructString;
	static void fillStructString(JNIEnv* env, jobject input, FTestbed1StructString& out_struct_string);
	static void fillStructStringArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructString>& out_array);
	static jobject makeJavaStructString(JNIEnv* env, const FTestbed1StructString& out_struct_string);
	static jobjectArray makeJavaStructStringArray(JNIEnv* env, const TArray<FTestbed1StructString>& cppArray);
	static jclass jStructStruct;
	static void fillStructStruct(JNIEnv* env, jobject input, FTestbed1StructStruct& out_struct_struct);
	static void fillStructStructArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructStruct>& out_array);
	static jobject makeJavaStructStruct(JNIEnv* env, const FTestbed1StructStruct& out_struct_struct);
	static jobjectArray makeJavaStructStructArray(JNIEnv* env, const TArray<FTestbed1StructStruct>& cppArray);
	static jclass jStructEnum;
	static void fillStructEnum(JNIEnv* env, jobject input, FTestbed1StructEnum& out_struct_enum);
	static void fillStructEnumArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructEnum>& out_array);
	static jobject makeJavaStructEnum(JNIEnv* env, const FTestbed1StructEnum& out_struct_enum);
	static jobjectArray makeJavaStructEnumArray(JNIEnv* env, const TArray<FTestbed1StructEnum>& cppArray);
	static jclass jStructBoolWithArray;
	static void fillStructBoolWithArray(JNIEnv* env, jobject input, FTestbed1StructBoolWithArray& out_struct_bool_with_array);
	static void fillStructBoolWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructBoolWithArray>& out_array);
	static jobject makeJavaStructBoolWithArray(JNIEnv* env, const FTestbed1StructBoolWithArray& out_struct_bool_with_array);
	static jobjectArray makeJavaStructBoolWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructBoolWithArray>& cppArray);
	static jclass jStructIntWithArray;
	static void fillStructIntWithArray(JNIEnv* env, jobject input, FTestbed1StructIntWithArray& out_struct_int_with_array);
	static void fillStructIntWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructIntWithArray>& out_array);
	static jobject makeJavaStructIntWithArray(JNIEnv* env, const FTestbed1StructIntWithArray& out_struct_int_with_array);
	static jobjectArray makeJavaStructIntWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructIntWithArray>& cppArray);
	static jclass jStructFloatWithArray;
	static void fillStructFloatWithArray(JNIEnv* env, jobject input, FTestbed1StructFloatWithArray& out_struct_float_with_array);
	static void fillStructFloatWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructFloatWithArray>& out_array);
	static jobject makeJavaStructFloatWithArray(JNIEnv* env, const FTestbed1StructFloatWithArray& out_struct_float_with_array);
	static jobjectArray makeJavaStructFloatWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructFloatWithArray>& cppArray);
	static jclass jStructStringWithArray;
	static void fillStructStringWithArray(JNIEnv* env, jobject input, FTestbed1StructStringWithArray& out_struct_string_with_array);
	static void fillStructStringWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructStringWithArray>& out_array);
	static jobject makeJavaStructStringWithArray(JNIEnv* env, const FTestbed1StructStringWithArray& out_struct_string_with_array);
	static jobjectArray makeJavaStructStringWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructStringWithArray>& cppArray);
	static jclass jStructStructWithArray;
	static void fillStructStructWithArray(JNIEnv* env, jobject input, FTestbed1StructStructWithArray& out_struct_struct_with_array);
	static void fillStructStructWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructStructWithArray>& out_array);
	static jobject makeJavaStructStructWithArray(JNIEnv* env, const FTestbed1StructStructWithArray& out_struct_struct_with_array);
	static jobjectArray makeJavaStructStructWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructStructWithArray>& cppArray);
	static jclass jStructEnumWithArray;
	static void fillStructEnumWithArray(JNIEnv* env, jobject input, FTestbed1StructEnumWithArray& out_struct_enum_with_array);
	static void fillStructEnumWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructEnumWithArray>& out_array);
	static jobject makeJavaStructEnumWithArray(JNIEnv* env, const FTestbed1StructEnumWithArray& out_struct_enum_with_array);
	static jobjectArray makeJavaStructEnumWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructEnumWithArray>& cppArray);

	static jclass jEnum0;
	static void fillEnum0Array(JNIEnv* env, jobjectArray input, TArray<ETestbed1Enum0>& out_array);
	static ETestbed1Enum0 getEnum0Value(JNIEnv* env, jobject input);
	static jobjectArray makeJavaEnum0Array(JNIEnv* env, const TArray<ETestbed1Enum0>& cppArray);
	static jobject makeJavaEnum0(JNIEnv* env, ETestbed1Enum0 value);

	static jclass jStructInterface;
	static void fillStructInterface(JNIEnv* env, jobject input, TScriptInterface<ITestbed1StructInterfaceInterface> out_struct_interface);
	static void fillStructInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed1StructInterfaceInterface>>& out_array);
	static jobject makeJavaStructInterface(JNIEnv* env, const TScriptInterface<ITestbed1StructInterfaceInterface> out_struct_interface);
	static jobjectArray makeJavaStructInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed1StructInterfaceInterface>>& cppArray);

	static TScriptInterface<ITestbed1StructInterfaceInterface> getCppInstanceTestbed1StructInterface();

	static jclass jStructArrayInterface;
	static void fillStructArrayInterface(JNIEnv* env, jobject input, TScriptInterface<ITestbed1StructArrayInterfaceInterface> out_struct_array_interface);
	static void fillStructArrayInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed1StructArrayInterfaceInterface>>& out_array);
	static jobject makeJavaStructArrayInterface(JNIEnv* env, const TScriptInterface<ITestbed1StructArrayInterfaceInterface> out_struct_array_interface);
	static jobjectArray makeJavaStructArrayInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed1StructArrayInterfaceInterface>>& cppArray);

	static TScriptInterface<ITestbed1StructArrayInterfaceInterface> getCppInstanceTestbed1StructArrayInterface();

	static jclass jStructArray2Interface;
	static void fillStructArray2Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed1StructArray2InterfaceInterface> out_struct_array2_interface);
	static void fillStructArray2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed1StructArray2InterfaceInterface>>& out_array);
	static jobject makeJavaStructArray2Interface(JNIEnv* env, const TScriptInterface<ITestbed1StructArray2InterfaceInterface> out_struct_array2_interface);
	static jobjectArray makeJavaStructArray2InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed1StructArray2InterfaceInterface>>& cppArray);

	static TScriptInterface<ITestbed1StructArray2InterfaceInterface> getCppInstanceTestbed1StructArray2Interface();

	static bool checkJniErrorOccured(const TCHAR* Msg);
	static void cleanJavaReferences();

private:
	static FCriticalSection initMutex;
	static void ensureInitialized();
	static bool m_isInitialized;
};

#endif
