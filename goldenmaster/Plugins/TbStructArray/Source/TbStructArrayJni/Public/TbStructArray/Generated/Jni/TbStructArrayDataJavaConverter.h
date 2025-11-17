
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
#include "TbStructArray/Generated/api/TbStructArray_data.h"
#include "TbStructArray/Generated/api/TbStructArray_apig.h"
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

class TBSTRUCTARRAYAPI_API TbStructArrayDataJavaConverter
{
public:
	static void fillPoint(JNIEnv* env, jobject input, FTbStructArrayPoint& out_point);
	static void fillPointArray(JNIEnv* env, jobjectArray input, TArray<FTbStructArrayPoint>& out_array);
	static jobject makeJavaPoint(JNIEnv* env, const FTbStructArrayPoint& out_point);
	static jobjectArray makeJavaPointArray(JNIEnv* env, const TArray<FTbStructArrayPoint>& cppArray);
	static void fillStructWithArrayOfStructs(JNIEnv* env, jobject input, FTbStructArrayStructWithArrayOfStructs& out_struct_with_array_of_structs);
	static void fillStructWithArrayOfStructsArray(JNIEnv* env, jobjectArray input, TArray<FTbStructArrayStructWithArrayOfStructs>& out_array);
	static jobject makeJavaStructWithArrayOfStructs(JNIEnv* env, const FTbStructArrayStructWithArrayOfStructs& out_struct_with_array_of_structs);
	static jobjectArray makeJavaStructWithArrayOfStructsArray(JNIEnv* env, const TArray<FTbStructArrayStructWithArrayOfStructs>& cppArray);
	static void fillStructWithArrayOfEnums(JNIEnv* env, jobject input, FTbStructArrayStructWithArrayOfEnums& out_struct_with_array_of_enums);
	static void fillStructWithArrayOfEnumsArray(JNIEnv* env, jobjectArray input, TArray<FTbStructArrayStructWithArrayOfEnums>& out_array);
	static jobject makeJavaStructWithArrayOfEnums(JNIEnv* env, const FTbStructArrayStructWithArrayOfEnums& out_struct_with_array_of_enums);
	static jobjectArray makeJavaStructWithArrayOfEnumsArray(JNIEnv* env, const TArray<FTbStructArrayStructWithArrayOfEnums>& cppArray);
	static void fillStructWithArrayOfInts(JNIEnv* env, jobject input, FTbStructArrayStructWithArrayOfInts& out_struct_with_array_of_ints);
	static void fillStructWithArrayOfIntsArray(JNIEnv* env, jobjectArray input, TArray<FTbStructArrayStructWithArrayOfInts>& out_array);
	static jobject makeJavaStructWithArrayOfInts(JNIEnv* env, const FTbStructArrayStructWithArrayOfInts& out_struct_with_array_of_ints);
	static jobjectArray makeJavaStructWithArrayOfIntsArray(JNIEnv* env, const TArray<FTbStructArrayStructWithArrayOfInts>& cppArray);
	static void fillMixedStruct(JNIEnv* env, jobject input, FTbStructArrayMixedStruct& out_mixed_struct);
	static void fillMixedStructArray(JNIEnv* env, jobjectArray input, TArray<FTbStructArrayMixedStruct>& out_array);
	static jobject makeJavaMixedStruct(JNIEnv* env, const FTbStructArrayMixedStruct& out_mixed_struct);
	static jobjectArray makeJavaMixedStructArray(JNIEnv* env, const TArray<FTbStructArrayMixedStruct>& cppArray);

	static void fillTestEnumArray(JNIEnv* env, jobjectArray input, TArray<ETbStructArrayTestEnum>& out_array);
	static ETbStructArrayTestEnum getTestEnumValue(JNIEnv* env, jobject input);
	static jobjectArray makeJavaTestEnumArray(JNIEnv* env, const TArray<ETbStructArrayTestEnum>& cppArray);
	static jobject makeJavaTestEnum(JNIEnv* env, ETbStructArrayTestEnum value);

	static void fillStructArrayFieldInterface(JNIEnv* env, jobject input, TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> out_struct_array_field_interface);
	static void fillStructArrayFieldInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface>>& out_array);
	static jobject makeJavaStructArrayFieldInterface(JNIEnv* env, const TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> out_struct_array_field_interface);
	static jobjectArray makeJavaStructArrayFieldInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface>>& cppArray);

	static TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> getCppInstanceTbStructArrayStructArrayFieldInterface();
};

#endif
