
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

#include "TbSame1/Generated/Jni/TbSame1DataJavaConverter.h"
#include "TbSame1/Generated/Jni/TbSame1JniCache.h"
#include "TbSame1/Generated/api/TbSame1_data.h"
#include "TbSame1/Implementation/TbSame1SameStruct1Interface.h"
#include "TbSame1/Implementation/TbSame1SameStruct2Interface.h"
#include "TbSame1/Implementation/TbSame1SameEnum1Interface.h"
#include "TbSame1/Implementation/TbSame1SameEnum2Interface.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

DEFINE_LOG_CATEGORY(LogTbSame1DataJavaConverter_JNI);

void TbSame1DataJavaConverter::fillStruct1(JNIEnv* env, jobject input, FTbSame1Struct1& out_struct1)
{

	jfieldID jFieldId_field1 = TbSame1JniCache::javaStructStruct1Field1FieldId;
	if (jFieldId_field1)
	{
		out_struct1.field1 = env->GetIntField(input, jFieldId_field1);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame1Struct1 not found"));
	}

	jfieldID jFieldId_field2 = TbSame1JniCache::javaStructStruct1Field2FieldId;
	if (jFieldId_field2)
	{
		out_struct1.field2 = env->GetIntField(input, jFieldId_field2);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame1Struct1 not found"));
	}

	jfieldID jFieldId_field3 = TbSame1JniCache::javaStructStruct1Field3FieldId;
	if (jFieldId_field3)
	{
		out_struct1.field3 = env->GetIntField(input, jFieldId_field3);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame1Struct1 not found"));
	}
}

void TbSame1DataJavaConverter::fillStruct1Array(JNIEnv* env, jobjectArray input, TArray<FTbSame1Struct1>& out_array)
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

jobject TbSame1DataJavaConverter::makeJavaStruct1(JNIEnv* env, const FTbSame1Struct1& in_struct1)
{
	jclass javaClass = TbSame1JniCache::javaStructStruct1;
	if (TbSame1JniCache::javaStructStruct1Ctor == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("FTbSame1Struct1 not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, TbSame1JniCache::javaStructStruct1Ctor);

	jfieldID jFieldId_field1 = TbSame1JniCache::javaStructStruct1Field1FieldId;
	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct1.field1);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame1Struct1 not found"));
	}

	jfieldID jFieldId_field2 = TbSame1JniCache::javaStructStruct1Field2FieldId;
	if (jFieldId_field2 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field2, in_struct1.field2);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame1Struct1 not found"));
	}

	jfieldID jFieldId_field3 = TbSame1JniCache::javaStructStruct1Field3FieldId;
	if (jFieldId_field3 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field3, in_struct1.field3);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame1Struct1 not found"));
	}
	return javaObjInstance;
}

jobjectArray TbSame1DataJavaConverter::makeJavaStruct1Array(JNIEnv* env, const TArray<FTbSame1Struct1>& cppArray)
{
	if (TbSame1JniCache::javaStructStruct1 == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("FTbSame1Struct1 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame1JniCache::javaStructStruct1, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStruct1(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void TbSame1DataJavaConverter::fillStruct2(JNIEnv* env, jobject input, FTbSame1Struct2& out_struct2)
{

	jfieldID jFieldId_field1 = TbSame1JniCache::javaStructStruct2Field1FieldId;
	if (jFieldId_field1)
	{
		out_struct2.field1 = env->GetIntField(input, jFieldId_field1);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame1Struct2 not found"));
	}

	jfieldID jFieldId_field2 = TbSame1JniCache::javaStructStruct2Field2FieldId;
	if (jFieldId_field2)
	{
		out_struct2.field2 = env->GetIntField(input, jFieldId_field2);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame1Struct2 not found"));
	}

	jfieldID jFieldId_field3 = TbSame1JniCache::javaStructStruct2Field3FieldId;
	if (jFieldId_field3)
	{
		out_struct2.field3 = env->GetIntField(input, jFieldId_field3);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame1Struct2 not found"));
	}
}

void TbSame1DataJavaConverter::fillStruct2Array(JNIEnv* env, jobjectArray input, TArray<FTbSame1Struct2>& out_array)
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

jobject TbSame1DataJavaConverter::makeJavaStruct2(JNIEnv* env, const FTbSame1Struct2& in_struct2)
{
	jclass javaClass = TbSame1JniCache::javaStructStruct2;
	if (TbSame1JniCache::javaStructStruct2Ctor == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("FTbSame1Struct2 not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, TbSame1JniCache::javaStructStruct2Ctor);

	jfieldID jFieldId_field1 = TbSame1JniCache::javaStructStruct2Field1FieldId;
	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct2.field1);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame1Struct2 not found"));
	}

	jfieldID jFieldId_field2 = TbSame1JniCache::javaStructStruct2Field2FieldId;
	if (jFieldId_field2 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field2, in_struct2.field2);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame1Struct2 not found"));
	}

	jfieldID jFieldId_field3 = TbSame1JniCache::javaStructStruct2Field3FieldId;
	if (jFieldId_field3 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field3, in_struct2.field3);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame1Struct2 not found"));
	}
	return javaObjInstance;
}

jobjectArray TbSame1DataJavaConverter::makeJavaStruct2Array(JNIEnv* env, const TArray<FTbSame1Struct2>& cppArray)
{
	if (TbSame1JniCache::javaStructStruct2 == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("FTbSame1Struct2 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame1JniCache::javaStructStruct2, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStruct2(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void TbSame1DataJavaConverter::fillEnum1Array(JNIEnv* env, jobjectArray input, TArray<ETbSame1Enum1>& out_array)
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

ETbSame1Enum1 TbSame1DataJavaConverter::getEnum1Value(JNIEnv* env, jobject input)
{
	ETbSame1Enum1 cppEnumValue = ETbSame1Enum1::TS1E1_Value1;

	if (TbSame1JniCache::javaEnumEnum1GetValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, TbSame1JniCache::javaEnumEnum1GetValueMethod);
		UTbSame1Library::toTbSame1Enum1(cppEnumValue, int_value);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("Enum Enum1::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbSame1DataJavaConverter::makeJavaEnum1Array(JNIEnv* env, const TArray<ETbSame1Enum1>& cppArray)
{
	if (TbSame1JniCache::javaEnumEnum1 == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("Enum Enum1 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame1JniCache::javaEnumEnum1, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum1(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject TbSame1DataJavaConverter::makeJavaEnum1(JNIEnv* env, ETbSame1Enum1 value)
{
	if (TbSame1JniCache::javaEnumEnum1FromValueMethodId == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("Enum Enum1::fromValue not found"));
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(TbSame1JniCache::javaEnumEnum1, TbSame1JniCache::javaEnumEnum1FromValueMethodId, int_value);
	return javaObj;
}

void TbSame1DataJavaConverter::fillEnum2Array(JNIEnv* env, jobjectArray input, TArray<ETbSame1Enum2>& out_array)
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

ETbSame1Enum2 TbSame1DataJavaConverter::getEnum2Value(JNIEnv* env, jobject input)
{
	ETbSame1Enum2 cppEnumValue = ETbSame1Enum2::TS1E2_Value1;

	if (TbSame1JniCache::javaEnumEnum2GetValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, TbSame1JniCache::javaEnumEnum2GetValueMethod);
		UTbSame1Library::toTbSame1Enum2(cppEnumValue, int_value);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("Enum Enum2::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbSame1DataJavaConverter::makeJavaEnum2Array(JNIEnv* env, const TArray<ETbSame1Enum2>& cppArray)
{
	if (TbSame1JniCache::javaEnumEnum2 == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("Enum Enum2 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame1JniCache::javaEnumEnum2, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum2(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject TbSame1DataJavaConverter::makeJavaEnum2(JNIEnv* env, ETbSame1Enum2 value)
{
	if (TbSame1JniCache::javaEnumEnum2FromValueMethodId == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("Enum Enum2::fromValue not found"));
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(TbSame1JniCache::javaEnumEnum2, TbSame1JniCache::javaEnumEnum2FromValueMethodId, int_value);
	return javaObj;
}

void TbSame1DataJavaConverter::fillSameStruct1Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame1SameStruct1InterfaceInterface> out_same_struct1_interface)
{
	if (!input || !out_same_struct1_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame1DataJavaConverter::fillSameStruct1InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame1SameStruct1InterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame1DataJavaConverter::makeJavaSameStruct1Interface(JNIEnv* env, const TScriptInterface<ITbSame1SameStruct1InterfaceInterface> out_same_struct1_interface)
{
	if (!out_same_struct1_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSame1DataJavaConverter::makeJavaSameStruct1InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame1SameStruct1InterfaceInterface>>& cppArray)
{
	if (!TbSame1JniCache::javaClassSameStruct1Interface)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("ISameStruct1Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame1JniCache::javaClassSameStruct1Interface, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> TbSame1DataJavaConverter::getCppInstanceTbSame1SameStruct1Interface()
{
	UTbSame1SameStruct1InterfaceImplementation* Impl = NewObject<UTbSame1SameStruct1InterfaceImplementation>();
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame1SameStruct1InterfaceInterface>(Impl));
	return wrapped;
}

void TbSame1DataJavaConverter::fillSameStruct2Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame1SameStruct2InterfaceInterface> out_same_struct2_interface)
{
	if (!input || !out_same_struct2_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame1DataJavaConverter::fillSameStruct2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame1SameStruct2InterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame1DataJavaConverter::makeJavaSameStruct2Interface(JNIEnv* env, const TScriptInterface<ITbSame1SameStruct2InterfaceInterface> out_same_struct2_interface)
{
	if (!out_same_struct2_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSame1DataJavaConverter::makeJavaSameStruct2InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame1SameStruct2InterfaceInterface>>& cppArray)
{
	if (!TbSame1JniCache::javaClassSameStruct2Interface)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("ISameStruct2Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame1JniCache::javaClassSameStruct2Interface, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> TbSame1DataJavaConverter::getCppInstanceTbSame1SameStruct2Interface()
{
	UTbSame1SameStruct2InterfaceImplementation* Impl = NewObject<UTbSame1SameStruct2InterfaceImplementation>();
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame1SameStruct2InterfaceInterface>(Impl));
	return wrapped;
}

void TbSame1DataJavaConverter::fillSameEnum1Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame1SameEnum1InterfaceInterface> out_same_enum1_interface)
{
	if (!input || !out_same_enum1_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame1DataJavaConverter::fillSameEnum1InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame1SameEnum1InterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame1DataJavaConverter::makeJavaSameEnum1Interface(JNIEnv* env, const TScriptInterface<ITbSame1SameEnum1InterfaceInterface> out_same_enum1_interface)
{
	if (!out_same_enum1_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSame1DataJavaConverter::makeJavaSameEnum1InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame1SameEnum1InterfaceInterface>>& cppArray)
{
	if (!TbSame1JniCache::javaClassSameEnum1Interface)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("ISameEnum1Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame1JniCache::javaClassSameEnum1Interface, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSame1SameEnum1InterfaceInterface> TbSame1DataJavaConverter::getCppInstanceTbSame1SameEnum1Interface()
{
	UTbSame1SameEnum1InterfaceImplementation* Impl = NewObject<UTbSame1SameEnum1InterfaceImplementation>();
	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame1SameEnum1InterfaceInterface>(Impl));
	return wrapped;
}

void TbSame1DataJavaConverter::fillSameEnum2Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame1SameEnum2InterfaceInterface> out_same_enum2_interface)
{
	if (!input || !out_same_enum2_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame1DataJavaConverter::fillSameEnum2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame1SameEnum2InterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame1DataJavaConverter::makeJavaSameEnum2Interface(JNIEnv* env, const TScriptInterface<ITbSame1SameEnum2InterfaceInterface> out_same_enum2_interface)
{
	if (!out_same_enum2_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSame1DataJavaConverter::makeJavaSameEnum2InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame1SameEnum2InterfaceInterface>>& cppArray)
{
	if (!TbSame1JniCache::javaClassSameEnum2Interface)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("ISameEnum2Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame1JniCache::javaClassSameEnum2Interface, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> TbSame1DataJavaConverter::getCppInstanceTbSame1SameEnum2Interface()
{
	UTbSame1SameEnum2InterfaceImplementation* Impl = NewObject<UTbSame1SameEnum2InterfaceImplementation>();
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame1SameEnum2InterfaceInterface>(Impl));
	return wrapped;
}

#endif
