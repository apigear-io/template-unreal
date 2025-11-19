
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

#include "Testbed2/Generated/Jni/Testbed2DataJavaConverter.h"
#include "Testbed2/Generated/Jni/Testbed2JniCache.h"
#include "Testbed2/Generated/api/Testbed2_data.h"
#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"
#include "Testbed2/Implementation/Testbed2NestedStruct1Interface.h"
#include "Testbed2/Implementation/Testbed2NestedStruct2Interface.h"
#include "Testbed2/Implementation/Testbed2NestedStruct3Interface.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

DEFINE_LOG_CATEGORY(LogTestbed2DataJavaConverter_JNI);

void Testbed2DataJavaConverter::fillStruct1(JNIEnv* env, jobject input, FTestbed2Struct1& out_struct1)
{

	jfieldID jFieldId_field1 = Testbed2JniCache::javaStructStruct1Field1FieldId;
	if (jFieldId_field1)
	{
		out_struct1.field1 = env->GetIntField(input, jFieldId_field1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct1 not found"));
	}
}

void Testbed2DataJavaConverter::fillStruct1Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct1>& out_array)
{
	jsize len = env->GetArrayLength(input);
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		fillStruct1(env, element, out_array[i]);
		env->DeleteLocalRef(element);
	}
}

jobject Testbed2DataJavaConverter::makeJavaStruct1(JNIEnv* env, const FTestbed2Struct1& in_struct1)
{
	jclass javaClass = Testbed2JniCache::javaStructStruct1;
	if (Testbed2JniCache::javaStructStruct1Ctor == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2Struct1 not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed2JniCache::javaStructStruct1Ctor);

	jfieldID jFieldId_field1 = Testbed2JniCache::javaStructStruct1Field1FieldId;
	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct1.field1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct1 not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaStruct1Array(JNIEnv* env, const TArray<FTestbed2Struct1>& cppArray)
{
	if (Testbed2JniCache::javaStructStruct1 == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2Struct1 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed2JniCache::javaStructStruct1, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStruct1(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void Testbed2DataJavaConverter::fillStruct2(JNIEnv* env, jobject input, FTestbed2Struct2& out_struct2)
{

	jfieldID jFieldId_field1 = Testbed2JniCache::javaStructStruct2Field1FieldId;
	if (jFieldId_field1)
	{
		out_struct2.field1 = env->GetIntField(input, jFieldId_field1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct2 not found"));
	}

	jfieldID jFieldId_field2 = Testbed2JniCache::javaStructStruct2Field2FieldId;
	if (jFieldId_field2)
	{
		out_struct2.field2 = env->GetIntField(input, jFieldId_field2);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2Struct2 not found"));
	}
}

void Testbed2DataJavaConverter::fillStruct2Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct2>& out_array)
{
	jsize len = env->GetArrayLength(input);
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		fillStruct2(env, element, out_array[i]);
		env->DeleteLocalRef(element);
	}
}

jobject Testbed2DataJavaConverter::makeJavaStruct2(JNIEnv* env, const FTestbed2Struct2& in_struct2)
{
	jclass javaClass = Testbed2JniCache::javaStructStruct2;
	if (Testbed2JniCache::javaStructStruct2Ctor == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2Struct2 not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed2JniCache::javaStructStruct2Ctor);

	jfieldID jFieldId_field1 = Testbed2JniCache::javaStructStruct2Field1FieldId;
	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct2.field1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct2 not found"));
	}

	jfieldID jFieldId_field2 = Testbed2JniCache::javaStructStruct2Field2FieldId;
	if (jFieldId_field2 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field2, in_struct2.field2);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2Struct2 not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaStruct2Array(JNIEnv* env, const TArray<FTestbed2Struct2>& cppArray)
{
	if (Testbed2JniCache::javaStructStruct2 == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2Struct2 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed2JniCache::javaStructStruct2, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStruct2(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void Testbed2DataJavaConverter::fillStruct3(JNIEnv* env, jobject input, FTestbed2Struct3& out_struct3)
{

	jfieldID jFieldId_field1 = Testbed2JniCache::javaStructStruct3Field1FieldId;
	if (jFieldId_field1)
	{
		out_struct3.field1 = env->GetIntField(input, jFieldId_field1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct3 not found"));
	}

	jfieldID jFieldId_field2 = Testbed2JniCache::javaStructStruct3Field2FieldId;
	if (jFieldId_field2)
	{
		out_struct3.field2 = env->GetIntField(input, jFieldId_field2);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2Struct3 not found"));
	}

	jfieldID jFieldId_field3 = Testbed2JniCache::javaStructStruct3Field3FieldId;
	if (jFieldId_field3)
	{
		out_struct3.field3 = env->GetIntField(input, jFieldId_field3);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTestbed2Struct3 not found"));
	}
}

void Testbed2DataJavaConverter::fillStruct3Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct3>& out_array)
{
	jsize len = env->GetArrayLength(input);
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		fillStruct3(env, element, out_array[i]);
		env->DeleteLocalRef(element);
	}
}

jobject Testbed2DataJavaConverter::makeJavaStruct3(JNIEnv* env, const FTestbed2Struct3& in_struct3)
{
	jclass javaClass = Testbed2JniCache::javaStructStruct3;
	if (Testbed2JniCache::javaStructStruct3Ctor == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2Struct3 not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed2JniCache::javaStructStruct3Ctor);

	jfieldID jFieldId_field1 = Testbed2JniCache::javaStructStruct3Field1FieldId;
	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct3.field1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct3 not found"));
	}

	jfieldID jFieldId_field2 = Testbed2JniCache::javaStructStruct3Field2FieldId;
	if (jFieldId_field2 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field2, in_struct3.field2);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2Struct3 not found"));
	}

	jfieldID jFieldId_field3 = Testbed2JniCache::javaStructStruct3Field3FieldId;
	if (jFieldId_field3 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field3, in_struct3.field3);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTestbed2Struct3 not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaStruct3Array(JNIEnv* env, const TArray<FTestbed2Struct3>& cppArray)
{
	if (Testbed2JniCache::javaStructStruct3 == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2Struct3 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed2JniCache::javaStructStruct3, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStruct3(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void Testbed2DataJavaConverter::fillStruct4(JNIEnv* env, jobject input, FTestbed2Struct4& out_struct4)
{

	jfieldID jFieldId_field1 = Testbed2JniCache::javaStructStruct4Field1FieldId;
	if (jFieldId_field1)
	{
		out_struct4.field1 = env->GetIntField(input, jFieldId_field1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct4 not found"));
	}

	jfieldID jFieldId_field2 = Testbed2JniCache::javaStructStruct4Field2FieldId;
	if (jFieldId_field2)
	{
		out_struct4.field2 = env->GetIntField(input, jFieldId_field2);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2Struct4 not found"));
	}

	jfieldID jFieldId_field3 = Testbed2JniCache::javaStructStruct4Field3FieldId;
	if (jFieldId_field3)
	{
		out_struct4.field3 = env->GetIntField(input, jFieldId_field3);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTestbed2Struct4 not found"));
	}

	jfieldID jFieldId_field4 = Testbed2JniCache::javaStructStruct4Field4FieldId;
	if (jFieldId_field4)
	{
		out_struct4.field4 = env->GetIntField(input, jFieldId_field4);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field4 field in FTestbed2Struct4 not found"));
	}
}

void Testbed2DataJavaConverter::fillStruct4Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct4>& out_array)
{
	jsize len = env->GetArrayLength(input);
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		fillStruct4(env, element, out_array[i]);
		env->DeleteLocalRef(element);
	}
}

jobject Testbed2DataJavaConverter::makeJavaStruct4(JNIEnv* env, const FTestbed2Struct4& in_struct4)
{
	jclass javaClass = Testbed2JniCache::javaStructStruct4;
	if (Testbed2JniCache::javaStructStruct4Ctor == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2Struct4 not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed2JniCache::javaStructStruct4Ctor);

	jfieldID jFieldId_field1 = Testbed2JniCache::javaStructStruct4Field1FieldId;
	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct4.field1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct4 not found"));
	}

	jfieldID jFieldId_field2 = Testbed2JniCache::javaStructStruct4Field2FieldId;
	if (jFieldId_field2 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field2, in_struct4.field2);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2Struct4 not found"));
	}

	jfieldID jFieldId_field3 = Testbed2JniCache::javaStructStruct4Field3FieldId;
	if (jFieldId_field3 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field3, in_struct4.field3);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTestbed2Struct4 not found"));
	}

	jfieldID jFieldId_field4 = Testbed2JniCache::javaStructStruct4Field4FieldId;
	if (jFieldId_field4 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field4, in_struct4.field4);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field4 field in FTestbed2Struct4 not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaStruct4Array(JNIEnv* env, const TArray<FTestbed2Struct4>& cppArray)
{
	if (Testbed2JniCache::javaStructStruct4 == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2Struct4 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed2JniCache::javaStructStruct4, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStruct4(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void Testbed2DataJavaConverter::fillNestedStruct1(JNIEnv* env, jobject input, FTestbed2NestedStruct1& out_nested_struct1)
{

	jfieldID jFieldId_field1 = Testbed2JniCache::javaStructNestedStruct1Field1FieldId;
	if (jFieldId_field1)
	{
		jobject field1_value = env->GetObjectField(input, jFieldId_field1);
		fillStruct1(env, field1_value, out_nested_struct1.field1);
		env->DeleteLocalRef(field1_value);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2NestedStruct1 not found"));
	}
}

void Testbed2DataJavaConverter::fillNestedStruct1Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2NestedStruct1>& out_array)
{
	jsize len = env->GetArrayLength(input);
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		fillNestedStruct1(env, element, out_array[i]);
		env->DeleteLocalRef(element);
	}
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct1(JNIEnv* env, const FTestbed2NestedStruct1& in_nested_struct1)
{
	jclass javaClass = Testbed2JniCache::javaStructNestedStruct1;
	if (Testbed2JniCache::javaStructNestedStruct1Ctor == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2NestedStruct1 not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed2JniCache::javaStructNestedStruct1Ctor);

	jfieldID jFieldId_field1 = Testbed2JniCache::javaStructNestedStruct1Field1FieldId;
	if (jFieldId_field1 != nullptr)
	{
		jobject l_field1 = makeJavaStruct1(env, in_nested_struct1.field1);
		env->SetObjectField(javaObjInstance, jFieldId_field1, l_field1);
		env->DeleteLocalRef(l_field1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2NestedStruct1 not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaNestedStruct1Array(JNIEnv* env, const TArray<FTestbed2NestedStruct1>& cppArray)
{
	if (Testbed2JniCache::javaStructNestedStruct1 == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2NestedStruct1 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed2JniCache::javaStructNestedStruct1, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaNestedStruct1(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void Testbed2DataJavaConverter::fillNestedStruct2(JNIEnv* env, jobject input, FTestbed2NestedStruct2& out_nested_struct2)
{

	jfieldID jFieldId_field1 = Testbed2JniCache::javaStructNestedStruct2Field1FieldId;
	if (jFieldId_field1)
	{
		jobject field1_value = env->GetObjectField(input, jFieldId_field1);
		fillStruct1(env, field1_value, out_nested_struct2.field1);
		env->DeleteLocalRef(field1_value);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2NestedStruct2 not found"));
	}

	jfieldID jFieldId_field2 = Testbed2JniCache::javaStructNestedStruct2Field2FieldId;
	if (jFieldId_field2)
	{
		jobject field2_value = env->GetObjectField(input, jFieldId_field2);
		fillStruct2(env, field2_value, out_nested_struct2.field2);
		env->DeleteLocalRef(field2_value);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2NestedStruct2 not found"));
	}
}

void Testbed2DataJavaConverter::fillNestedStruct2Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2NestedStruct2>& out_array)
{
	jsize len = env->GetArrayLength(input);
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		fillNestedStruct2(env, element, out_array[i]);
		env->DeleteLocalRef(element);
	}
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct2(JNIEnv* env, const FTestbed2NestedStruct2& in_nested_struct2)
{
	jclass javaClass = Testbed2JniCache::javaStructNestedStruct2;
	if (Testbed2JniCache::javaStructNestedStruct2Ctor == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2NestedStruct2 not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed2JniCache::javaStructNestedStruct2Ctor);

	jfieldID jFieldId_field1 = Testbed2JniCache::javaStructNestedStruct2Field1FieldId;
	if (jFieldId_field1 != nullptr)
	{
		jobject l_field1 = makeJavaStruct1(env, in_nested_struct2.field1);
		env->SetObjectField(javaObjInstance, jFieldId_field1, l_field1);
		env->DeleteLocalRef(l_field1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2NestedStruct2 not found"));
	}

	jfieldID jFieldId_field2 = Testbed2JniCache::javaStructNestedStruct2Field2FieldId;
	if (jFieldId_field2 != nullptr)
	{
		jobject l_field2 = makeJavaStruct2(env, in_nested_struct2.field2);
		env->SetObjectField(javaObjInstance, jFieldId_field2, l_field2);
		env->DeleteLocalRef(l_field2);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2NestedStruct2 not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaNestedStruct2Array(JNIEnv* env, const TArray<FTestbed2NestedStruct2>& cppArray)
{
	if (Testbed2JniCache::javaStructNestedStruct2 == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2NestedStruct2 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed2JniCache::javaStructNestedStruct2, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaNestedStruct2(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void Testbed2DataJavaConverter::fillNestedStruct3(JNIEnv* env, jobject input, FTestbed2NestedStruct3& out_nested_struct3)
{

	jfieldID jFieldId_field1 = Testbed2JniCache::javaStructNestedStruct3Field1FieldId;
	if (jFieldId_field1)
	{
		jobject field1_value = env->GetObjectField(input, jFieldId_field1);
		fillStruct1(env, field1_value, out_nested_struct3.field1);
		env->DeleteLocalRef(field1_value);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2NestedStruct3 not found"));
	}

	jfieldID jFieldId_field2 = Testbed2JniCache::javaStructNestedStruct3Field2FieldId;
	if (jFieldId_field2)
	{
		jobject field2_value = env->GetObjectField(input, jFieldId_field2);
		fillStruct2(env, field2_value, out_nested_struct3.field2);
		env->DeleteLocalRef(field2_value);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2NestedStruct3 not found"));
	}

	jfieldID jFieldId_field3 = Testbed2JniCache::javaStructNestedStruct3Field3FieldId;
	if (jFieldId_field3)
	{
		jobject field3_value = env->GetObjectField(input, jFieldId_field3);
		fillStruct3(env, field3_value, out_nested_struct3.field3);
		env->DeleteLocalRef(field3_value);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTestbed2NestedStruct3 not found"));
	}
}

void Testbed2DataJavaConverter::fillNestedStruct3Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2NestedStruct3>& out_array)
{
	jsize len = env->GetArrayLength(input);
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		fillNestedStruct3(env, element, out_array[i]);
		env->DeleteLocalRef(element);
	}
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct3(JNIEnv* env, const FTestbed2NestedStruct3& in_nested_struct3)
{
	jclass javaClass = Testbed2JniCache::javaStructNestedStruct3;
	if (Testbed2JniCache::javaStructNestedStruct3Ctor == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2NestedStruct3 not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed2JniCache::javaStructNestedStruct3Ctor);

	jfieldID jFieldId_field1 = Testbed2JniCache::javaStructNestedStruct3Field1FieldId;
	if (jFieldId_field1 != nullptr)
	{
		jobject l_field1 = makeJavaStruct1(env, in_nested_struct3.field1);
		env->SetObjectField(javaObjInstance, jFieldId_field1, l_field1);
		env->DeleteLocalRef(l_field1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2NestedStruct3 not found"));
	}

	jfieldID jFieldId_field2 = Testbed2JniCache::javaStructNestedStruct3Field2FieldId;
	if (jFieldId_field2 != nullptr)
	{
		jobject l_field2 = makeJavaStruct2(env, in_nested_struct3.field2);
		env->SetObjectField(javaObjInstance, jFieldId_field2, l_field2);
		env->DeleteLocalRef(l_field2);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2NestedStruct3 not found"));
	}

	jfieldID jFieldId_field3 = Testbed2JniCache::javaStructNestedStruct3Field3FieldId;
	if (jFieldId_field3 != nullptr)
	{
		jobject l_field3 = makeJavaStruct3(env, in_nested_struct3.field3);
		env->SetObjectField(javaObjInstance, jFieldId_field3, l_field3);
		env->DeleteLocalRef(l_field3);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTestbed2NestedStruct3 not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaNestedStruct3Array(JNIEnv* env, const TArray<FTestbed2NestedStruct3>& cppArray)
{
	if (Testbed2JniCache::javaStructNestedStruct3 == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2NestedStruct3 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed2JniCache::javaStructNestedStruct3, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaNestedStruct3(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void Testbed2DataJavaConverter::fillEnum1Array(JNIEnv* env, jobjectArray input, TArray<ETestbed2Enum1>& out_array)
{
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		out_array.Add(getEnum1Value(env, element));
		env->DeleteLocalRef(element);
	}
}

ETestbed2Enum1 Testbed2DataJavaConverter::getEnum1Value(JNIEnv* env, jobject input)
{
	ETestbed2Enum1 cppEnumValue = ETestbed2Enum1::T2E1_Value1;

	if (Testbed2JniCache::javaEnumEnum1GetValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, Testbed2JniCache::javaEnumEnum1GetValueMethod);
		UTestbed2Library::toTestbed2Enum1(cppEnumValue, int_value);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum1::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray Testbed2DataJavaConverter::makeJavaEnum1Array(JNIEnv* env, const TArray<ETestbed2Enum1>& cppArray)
{
	if (Testbed2JniCache::javaEnumEnum1 == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum1 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed2JniCache::javaEnumEnum1, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum1(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject Testbed2DataJavaConverter::makeJavaEnum1(JNIEnv* env, ETestbed2Enum1 value)
{
	if (Testbed2JniCache::javaEnumEnum1FromValueMethodId == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum1::fromValue not found"));
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(Testbed2JniCache::javaEnumEnum1, Testbed2JniCache::javaEnumEnum1FromValueMethodId, int_value);
	return javaObj;
}

void Testbed2DataJavaConverter::fillEnum2Array(JNIEnv* env, jobjectArray input, TArray<ETestbed2Enum2>& out_array)
{
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		out_array.Add(getEnum2Value(env, element));
		env->DeleteLocalRef(element);
	}
}

ETestbed2Enum2 Testbed2DataJavaConverter::getEnum2Value(JNIEnv* env, jobject input)
{
	ETestbed2Enum2 cppEnumValue = ETestbed2Enum2::T2E2_Value1;

	if (Testbed2JniCache::javaEnumEnum2GetValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, Testbed2JniCache::javaEnumEnum2GetValueMethod);
		UTestbed2Library::toTestbed2Enum2(cppEnumValue, int_value);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum2::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray Testbed2DataJavaConverter::makeJavaEnum2Array(JNIEnv* env, const TArray<ETestbed2Enum2>& cppArray)
{
	if (Testbed2JniCache::javaEnumEnum2 == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum2 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed2JniCache::javaEnumEnum2, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum2(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject Testbed2DataJavaConverter::makeJavaEnum2(JNIEnv* env, ETestbed2Enum2 value)
{
	if (Testbed2JniCache::javaEnumEnum2FromValueMethodId == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum2::fromValue not found"));
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(Testbed2JniCache::javaEnumEnum2, Testbed2JniCache::javaEnumEnum2FromValueMethodId, int_value);
	return javaObj;
}

void Testbed2DataJavaConverter::fillEnum3Array(JNIEnv* env, jobjectArray input, TArray<ETestbed2Enum3>& out_array)
{
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		out_array.Add(getEnum3Value(env, element));
		env->DeleteLocalRef(element);
	}
}

ETestbed2Enum3 Testbed2DataJavaConverter::getEnum3Value(JNIEnv* env, jobject input)
{
	ETestbed2Enum3 cppEnumValue = ETestbed2Enum3::T2E3_Value1;

	if (Testbed2JniCache::javaEnumEnum3GetValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, Testbed2JniCache::javaEnumEnum3GetValueMethod);
		UTestbed2Library::toTestbed2Enum3(cppEnumValue, int_value);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum3::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray Testbed2DataJavaConverter::makeJavaEnum3Array(JNIEnv* env, const TArray<ETestbed2Enum3>& cppArray)
{
	if (Testbed2JniCache::javaEnumEnum3 == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum3 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed2JniCache::javaEnumEnum3, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum3(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject Testbed2DataJavaConverter::makeJavaEnum3(JNIEnv* env, ETestbed2Enum3 value)
{
	if (Testbed2JniCache::javaEnumEnum3FromValueMethodId == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum3::fromValue not found"));
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(Testbed2JniCache::javaEnumEnum3, Testbed2JniCache::javaEnumEnum3FromValueMethodId, int_value);
	return javaObj;
}

void Testbed2DataJavaConverter::fillManyParamInterface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2ManyParamInterfaceInterface> out_many_param_interface)
{
	if (!input || !out_many_param_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void Testbed2DataJavaConverter::fillManyParamInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2ManyParamInterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject Testbed2DataJavaConverter::makeJavaManyParamInterface(JNIEnv* env, const TScriptInterface<ITestbed2ManyParamInterfaceInterface> out_many_param_interface)
{
	if (!out_many_param_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaManyParamInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed2ManyParamInterfaceInterface>>& cppArray)
{
	if (!Testbed2JniCache::javaClassManyParamInterface)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("IManyParamInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed2JniCache::javaClassManyParamInterface, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> Testbed2DataJavaConverter::getCppInstanceTestbed2ManyParamInterface()
{
	UTestbed2ManyParamInterfaceImplementation* Impl = NewObject<UTestbed2ManyParamInterfaceImplementation>();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITestbed2ManyParamInterfaceInterface>(Impl));
	return wrapped;
}

void Testbed2DataJavaConverter::fillNestedStruct1Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> out_nested_struct1_interface)
{
	if (!input || !out_nested_struct1_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void Testbed2DataJavaConverter::fillNestedStruct1InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2NestedStruct1InterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct1Interface(JNIEnv* env, const TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> out_nested_struct1_interface)
{
	if (!out_nested_struct1_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaNestedStruct1InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed2NestedStruct1InterfaceInterface>>& cppArray)
{
	if (!Testbed2JniCache::javaClassNestedStruct1Interface)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("INestedStruct1Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed2JniCache::javaClassNestedStruct1Interface, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> Testbed2DataJavaConverter::getCppInstanceTestbed2NestedStruct1Interface()
{
	UTestbed2NestedStruct1InterfaceImplementation* Impl = NewObject<UTestbed2NestedStruct1InterfaceImplementation>();
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITestbed2NestedStruct1InterfaceInterface>(Impl));
	return wrapped;
}

void Testbed2DataJavaConverter::fillNestedStruct2Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> out_nested_struct2_interface)
{
	if (!input || !out_nested_struct2_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void Testbed2DataJavaConverter::fillNestedStruct2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2NestedStruct2InterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct2Interface(JNIEnv* env, const TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> out_nested_struct2_interface)
{
	if (!out_nested_struct2_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaNestedStruct2InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed2NestedStruct2InterfaceInterface>>& cppArray)
{
	if (!Testbed2JniCache::javaClassNestedStruct2Interface)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("INestedStruct2Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed2JniCache::javaClassNestedStruct2Interface, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> Testbed2DataJavaConverter::getCppInstanceTestbed2NestedStruct2Interface()
{
	UTestbed2NestedStruct2InterfaceImplementation* Impl = NewObject<UTestbed2NestedStruct2InterfaceImplementation>();
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITestbed2NestedStruct2InterfaceInterface>(Impl));
	return wrapped;
}

void Testbed2DataJavaConverter::fillNestedStruct3Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> out_nested_struct3_interface)
{
	if (!input || !out_nested_struct3_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void Testbed2DataJavaConverter::fillNestedStruct3InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct3Interface(JNIEnv* env, const TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> out_nested_struct3_interface)
{
	if (!out_nested_struct3_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaNestedStruct3InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceInterface>>& cppArray)
{
	if (!Testbed2JniCache::javaClassNestedStruct3Interface)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("INestedStruct3Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed2JniCache::javaClassNestedStruct3Interface, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> Testbed2DataJavaConverter::getCppInstanceTestbed2NestedStruct3Interface()
{
	UTestbed2NestedStruct3InterfaceImplementation* Impl = NewObject<UTestbed2NestedStruct3InterfaceImplementation>();
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITestbed2NestedStruct3InterfaceInterface>(Impl));
	return wrapped;
}

#endif
