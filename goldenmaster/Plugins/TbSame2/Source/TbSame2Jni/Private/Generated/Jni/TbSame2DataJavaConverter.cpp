
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

#include "TbSame2/Generated/Jni/TbSame2DataJavaConverter.h"
#include "TbSame2/Generated/api/TbSame2_data.h"
#include "TbSame2/Implementation/TbSame2SameStruct1Interface.h"
#include "TbSame2/Implementation/TbSame2SameStruct2Interface.h"
#include "TbSame2/Implementation/TbSame2SameEnum1Interface.h"
#include "TbSame2/Implementation/TbSame2SameEnum2Interface.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

void TbSame2DataJavaConverter::fillStruct1(JNIEnv* env, jobject input, FTbSame2Struct1& out_struct1)
{
	jclass cls = env->GetObjectClass(input);

	jfieldID jFieldId_field1 = env->GetFieldID(cls, "field1", "I");
	out_struct1.field1 = env->GetIntField(input, jFieldId_field1);

	jfieldID jFieldId_field2 = env->GetFieldID(cls, "field2", "I");
	out_struct1.field2 = env->GetIntField(input, jFieldId_field2);

	jfieldID jFieldId_field3 = env->GetFieldID(cls, "field3", "I");
	out_struct1.field3 = env->GetIntField(input, jFieldId_field3);
}

void TbSame2DataJavaConverter::fillStruct1Array(JNIEnv* env, jobjectArray input, TArray<FTbSame2Struct1>& out_array)
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

jobject TbSame2DataJavaConverter::makeJavaStruct1(JNIEnv* env, const FTbSame2Struct1& in_struct1)
{
	jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Struct1");
	jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
	jobject javaObjInstance = env->NewObject(javaClass, ctor);

	jfieldID jFieldId_field1 = env->GetFieldID(javaClass, "field1", "I");
	env->SetIntField(javaObjInstance, jFieldId_field1, in_struct1.field1);

	jfieldID jFieldId_field2 = env->GetFieldID(javaClass, "field2", "I");
	env->SetIntField(javaObjInstance, jFieldId_field2, in_struct1.field2);

	jfieldID jFieldId_field3 = env->GetFieldID(javaClass, "field3", "I");
	env->SetIntField(javaObjInstance, jFieldId_field3, in_struct1.field3);
	return javaObjInstance;
}

jobjectArray TbSame2DataJavaConverter::makeJavaStruct1Array(JNIEnv* env, const TArray<FTbSame2Struct1>& cppArray)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Struct1");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaStruct, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStruct1(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void TbSame2DataJavaConverter::fillStruct2(JNIEnv* env, jobject input, FTbSame2Struct2& out_struct2)
{
	jclass cls = env->GetObjectClass(input);

	jfieldID jFieldId_field1 = env->GetFieldID(cls, "field1", "I");
	out_struct2.field1 = env->GetIntField(input, jFieldId_field1);

	jfieldID jFieldId_field2 = env->GetFieldID(cls, "field2", "I");
	out_struct2.field2 = env->GetIntField(input, jFieldId_field2);

	jfieldID jFieldId_field3 = env->GetFieldID(cls, "field3", "I");
	out_struct2.field3 = env->GetIntField(input, jFieldId_field3);
}

void TbSame2DataJavaConverter::fillStruct2Array(JNIEnv* env, jobjectArray input, TArray<FTbSame2Struct2>& out_array)
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

jobject TbSame2DataJavaConverter::makeJavaStruct2(JNIEnv* env, const FTbSame2Struct2& in_struct2)
{
	jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Struct2");
	jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
	jobject javaObjInstance = env->NewObject(javaClass, ctor);

	jfieldID jFieldId_field1 = env->GetFieldID(javaClass, "field1", "I");
	env->SetIntField(javaObjInstance, jFieldId_field1, in_struct2.field1);

	jfieldID jFieldId_field2 = env->GetFieldID(javaClass, "field2", "I");
	env->SetIntField(javaObjInstance, jFieldId_field2, in_struct2.field2);

	jfieldID jFieldId_field3 = env->GetFieldID(javaClass, "field3", "I");
	env->SetIntField(javaObjInstance, jFieldId_field3, in_struct2.field3);
	return javaObjInstance;
}

jobjectArray TbSame2DataJavaConverter::makeJavaStruct2Array(JNIEnv* env, const TArray<FTbSame2Struct2>& cppArray)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Struct2");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaStruct, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStruct2(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void TbSame2DataJavaConverter::fillEnum1Array(JNIEnv* env, jobjectArray input, TArray<ETbSame2Enum1>& out_array)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Enum1");
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		out_array.Add(getEnum1Value(env, element));
		env->DeleteLocalRef(element);
	}
}

ETbSame2Enum1 TbSame2DataJavaConverter::getEnum1Value(JNIEnv* env, jobject input)
{
	ETbSame2Enum1 cppEnumValue;
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Enum1");
	jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
	int int_value = env->CallIntMethod(input, getValueMethod);
	UTbSame2Library::toTbSame2Enum1(cppEnumValue, int_value);
	return cppEnumValue;
}

jobjectArray TbSame2DataJavaConverter::makeJavaEnum1Array(JNIEnv* env, const TArray<ETbSame2Enum1>& cppArray)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Enum1");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaStruct, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum1(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject TbSame2DataJavaConverter::makeJavaEnum1(JNIEnv* env, ETbSame2Enum1 value)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Enum1");
	jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)LtbSame2/tbSame2_api/Enum1;");
	if (!fromValueMethod)
		return nullptr;
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
	return javaObj;
}

void TbSame2DataJavaConverter::fillEnum2Array(JNIEnv* env, jobjectArray input, TArray<ETbSame2Enum2>& out_array)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Enum2");
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		out_array.Add(getEnum2Value(env, element));
		env->DeleteLocalRef(element);
	}
}

ETbSame2Enum2 TbSame2DataJavaConverter::getEnum2Value(JNIEnv* env, jobject input)
{
	ETbSame2Enum2 cppEnumValue;
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Enum2");
	jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
	int int_value = env->CallIntMethod(input, getValueMethod);
	UTbSame2Library::toTbSame2Enum2(cppEnumValue, int_value);
	return cppEnumValue;
}

jobjectArray TbSame2DataJavaConverter::makeJavaEnum2Array(JNIEnv* env, const TArray<ETbSame2Enum2>& cppArray)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Enum2");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaStruct, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum2(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject TbSame2DataJavaConverter::makeJavaEnum2(JNIEnv* env, ETbSame2Enum2 value)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Enum2");
	jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)LtbSame2/tbSame2_api/Enum2;");
	if (!fromValueMethod)
		return nullptr;
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
	return javaObj;
}

void TbSame2DataJavaConverter::fillSameStruct1Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame2SameStruct1InterfaceInterface> out_same_struct1_interface)
{
	if (!input || !out_same_struct1_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame2DataJavaConverter::fillSameStruct1InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame2SameStruct1InterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame2DataJavaConverter::makeJavaSameStruct1Interface(JNIEnv* env, const TScriptInterface<ITbSame2SameStruct1InterfaceInterface> out_same_struct1_interface)
{
	if (!out_same_struct1_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSame2DataJavaConverter::makeJavaSameStruct1InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame2SameStruct1InterfaceInterface>>& cppArray)
{
	jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/ISameStruct1Interface");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaClass, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> TbSame2DataJavaConverter::getCppInstanceTbSame2SameStruct1Interface()
{
	UTbSame2SameStruct1InterfaceImplementation* Impl = NewObject<UTbSame2SameStruct1InterfaceImplementation>();
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame2SameStruct1InterfaceInterface>(Impl));
	return wrapped;
}

void TbSame2DataJavaConverter::fillSameStruct2Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame2SameStruct2InterfaceInterface> out_same_struct2_interface)
{
	if (!input || !out_same_struct2_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame2DataJavaConverter::fillSameStruct2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame2SameStruct2InterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame2DataJavaConverter::makeJavaSameStruct2Interface(JNIEnv* env, const TScriptInterface<ITbSame2SameStruct2InterfaceInterface> out_same_struct2_interface)
{
	if (!out_same_struct2_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSame2DataJavaConverter::makeJavaSameStruct2InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame2SameStruct2InterfaceInterface>>& cppArray)
{
	jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/ISameStruct2Interface");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaClass, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> TbSame2DataJavaConverter::getCppInstanceTbSame2SameStruct2Interface()
{
	UTbSame2SameStruct2InterfaceImplementation* Impl = NewObject<UTbSame2SameStruct2InterfaceImplementation>();
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame2SameStruct2InterfaceInterface>(Impl));
	return wrapped;
}

void TbSame2DataJavaConverter::fillSameEnum1Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame2SameEnum1InterfaceInterface> out_same_enum1_interface)
{
	if (!input || !out_same_enum1_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame2DataJavaConverter::fillSameEnum1InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame2SameEnum1InterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame2DataJavaConverter::makeJavaSameEnum1Interface(JNIEnv* env, const TScriptInterface<ITbSame2SameEnum1InterfaceInterface> out_same_enum1_interface)
{
	if (!out_same_enum1_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSame2DataJavaConverter::makeJavaSameEnum1InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame2SameEnum1InterfaceInterface>>& cppArray)
{
	jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/ISameEnum1Interface");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaClass, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSame2SameEnum1InterfaceInterface> TbSame2DataJavaConverter::getCppInstanceTbSame2SameEnum1Interface()
{
	UTbSame2SameEnum1InterfaceImplementation* Impl = NewObject<UTbSame2SameEnum1InterfaceImplementation>();
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame2SameEnum1InterfaceInterface>(Impl));
	return wrapped;
}

void TbSame2DataJavaConverter::fillSameEnum2Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame2SameEnum2InterfaceInterface> out_same_enum2_interface)
{
	if (!input || !out_same_enum2_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame2DataJavaConverter::fillSameEnum2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame2SameEnum2InterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame2DataJavaConverter::makeJavaSameEnum2Interface(JNIEnv* env, const TScriptInterface<ITbSame2SameEnum2InterfaceInterface> out_same_enum2_interface)
{
	if (!out_same_enum2_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSame2DataJavaConverter::makeJavaSameEnum2InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame2SameEnum2InterfaceInterface>>& cppArray)
{
	jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/ISameEnum2Interface");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaClass, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> TbSame2DataJavaConverter::getCppInstanceTbSame2SameEnum2Interface()
{
	UTbSame2SameEnum2InterfaceImplementation* Impl = NewObject<UTbSame2SameEnum2InterfaceImplementation>();
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame2SameEnum2InterfaceInterface>(Impl));
	return wrapped;
}

#endif
