
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
#include "TbSame2/Generated/Jni/TbSame2JniCache.h"
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

DEFINE_LOG_CATEGORY(LogTbSame2DataJavaConverter_JNI);

void TbSame2DataJavaConverter::fillStruct1(JNIEnv* env, jobject input, FTbSame2Struct1& out_struct1)
{

	jfieldID jFieldId_field1 = TbSame2JniCache::javaStructStruct1Field1FieldId;
	if (jFieldId_field1)
	{
		out_struct1.field1 = env->GetIntField(input, jFieldId_field1);
		static const TCHAR* errorMsgfield1 = TEXT("failed when getting the jFieldId_field1 for out_struct1.field1");
		checkJniError(errorMsgfield1);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame2Struct1 not found"));
	}

	jfieldID jFieldId_field2 = TbSame2JniCache::javaStructStruct1Field2FieldId;
	if (jFieldId_field2)
	{
		out_struct1.field2 = env->GetIntField(input, jFieldId_field2);
		static const TCHAR* errorMsgfield2 = TEXT("failed when getting the jFieldId_field2 for out_struct1.field2");
		checkJniError(errorMsgfield2);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame2Struct1 not found"));
	}

	jfieldID jFieldId_field3 = TbSame2JniCache::javaStructStruct1Field3FieldId;
	if (jFieldId_field3)
	{
		out_struct1.field3 = env->GetIntField(input, jFieldId_field3);
		static const TCHAR* errorMsgfield3 = TEXT("failed when getting the jFieldId_field3 for out_struct1.field3");
		checkJniError(errorMsgfield3);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame2Struct1 not found"));
	}
}

void TbSame2DataJavaConverter::fillStruct1Array(JNIEnv* env, jobjectArray input, TArray<FTbSame2Struct1>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct1 array.");
	checkJniError(errorMsgLen);
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct1 array.");
		checkJniError(errorMsg);
		fillStruct1(env, element, out_array[i]);
		env->DeleteLocalRef(element);
	}
}

jobject TbSame2DataJavaConverter::makeJavaStruct1(JNIEnv* env, const FTbSame2Struct1& in_struct1)
{
	jclass javaClass = TbSame2JniCache::javaStructStruct1;
	if (TbSame2JniCache::javaStructStruct1Ctor == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("FTbSame2Struct1 not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, TbSame2JniCache::javaStructStruct1Ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct1.");
	checkJniError(errorMsgObj);

	jfieldID jFieldId_field1 = TbSame2JniCache::javaStructStruct1Field1FieldId;
	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct1.field1);
		static const TCHAR* errorMsgfield1Set = TEXT("failed when seting field for out_struct1.field1");
		checkJniError(errorMsgfield1Set);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame2Struct1 not found"));
	}

	jfieldID jFieldId_field2 = TbSame2JniCache::javaStructStruct1Field2FieldId;
	if (jFieldId_field2 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field2, in_struct1.field2);
		static const TCHAR* errorMsgfield2Set = TEXT("failed when seting field for out_struct1.field2");
		checkJniError(errorMsgfield2Set);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame2Struct1 not found"));
	}

	jfieldID jFieldId_field3 = TbSame2JniCache::javaStructStruct1Field3FieldId;
	if (jFieldId_field3 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field3, in_struct1.field3);
		static const TCHAR* errorMsgfield3Set = TEXT("failed when seting field for out_struct1.field3");
		checkJniError(errorMsgfield3Set);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame2Struct1 not found"));
	}
	return javaObjInstance;
}

jobjectArray TbSame2DataJavaConverter::makeJavaStruct1Array(JNIEnv* env, const TArray<FTbSame2Struct1>& cppArray)
{
	if (TbSame2JniCache::javaStructStruct1 == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("FTbSame2Struct1 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame2JniCache::javaStructStruct1, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct1.");
	checkJniError(errorMsgAlloc);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStruct1(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct1 jarray.");
		checkJniError(errorMsg);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void TbSame2DataJavaConverter::fillStruct2(JNIEnv* env, jobject input, FTbSame2Struct2& out_struct2)
{

	jfieldID jFieldId_field1 = TbSame2JniCache::javaStructStruct2Field1FieldId;
	if (jFieldId_field1)
	{
		out_struct2.field1 = env->GetIntField(input, jFieldId_field1);
		static const TCHAR* errorMsgfield1 = TEXT("failed when getting the jFieldId_field1 for out_struct2.field1");
		checkJniError(errorMsgfield1);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame2Struct2 not found"));
	}

	jfieldID jFieldId_field2 = TbSame2JniCache::javaStructStruct2Field2FieldId;
	if (jFieldId_field2)
	{
		out_struct2.field2 = env->GetIntField(input, jFieldId_field2);
		static const TCHAR* errorMsgfield2 = TEXT("failed when getting the jFieldId_field2 for out_struct2.field2");
		checkJniError(errorMsgfield2);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame2Struct2 not found"));
	}

	jfieldID jFieldId_field3 = TbSame2JniCache::javaStructStruct2Field3FieldId;
	if (jFieldId_field3)
	{
		out_struct2.field3 = env->GetIntField(input, jFieldId_field3);
		static const TCHAR* errorMsgfield3 = TEXT("failed when getting the jFieldId_field3 for out_struct2.field3");
		checkJniError(errorMsgfield3);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame2Struct2 not found"));
	}
}

void TbSame2DataJavaConverter::fillStruct2Array(JNIEnv* env, jobjectArray input, TArray<FTbSame2Struct2>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct2 array.");
	checkJniError(errorMsgLen);
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct2 array.");
		checkJniError(errorMsg);
		fillStruct2(env, element, out_array[i]);
		env->DeleteLocalRef(element);
	}
}

jobject TbSame2DataJavaConverter::makeJavaStruct2(JNIEnv* env, const FTbSame2Struct2& in_struct2)
{
	jclass javaClass = TbSame2JniCache::javaStructStruct2;
	if (TbSame2JniCache::javaStructStruct2Ctor == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("FTbSame2Struct2 not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, TbSame2JniCache::javaStructStruct2Ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct2.");
	checkJniError(errorMsgObj);

	jfieldID jFieldId_field1 = TbSame2JniCache::javaStructStruct2Field1FieldId;
	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct2.field1);
		static const TCHAR* errorMsgfield1Set = TEXT("failed when seting field for out_struct2.field1");
		checkJniError(errorMsgfield1Set);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame2Struct2 not found"));
	}

	jfieldID jFieldId_field2 = TbSame2JniCache::javaStructStruct2Field2FieldId;
	if (jFieldId_field2 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field2, in_struct2.field2);
		static const TCHAR* errorMsgfield2Set = TEXT("failed when seting field for out_struct2.field2");
		checkJniError(errorMsgfield2Set);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame2Struct2 not found"));
	}

	jfieldID jFieldId_field3 = TbSame2JniCache::javaStructStruct2Field3FieldId;
	if (jFieldId_field3 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field3, in_struct2.field3);
		static const TCHAR* errorMsgfield3Set = TEXT("failed when seting field for out_struct2.field3");
		checkJniError(errorMsgfield3Set);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame2Struct2 not found"));
	}
	return javaObjInstance;
}

jobjectArray TbSame2DataJavaConverter::makeJavaStruct2Array(JNIEnv* env, const TArray<FTbSame2Struct2>& cppArray)
{
	if (TbSame2JniCache::javaStructStruct2 == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("FTbSame2Struct2 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame2JniCache::javaStructStruct2, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct2.");
	checkJniError(errorMsgAlloc);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStruct2(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct2 jarray.");
		checkJniError(errorMsg);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void TbSame2DataJavaConverter::fillEnum1Array(JNIEnv* env, jobjectArray input, TArray<ETbSame2Enum1>& out_array)
{
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of Enum1 array.");
	checkJniError(errorMsgLen);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of Enum1 array.");
		checkJniError(errorMsg);
		out_array.Add(getEnum1Value(env, element));
		env->DeleteLocalRef(element);
	}
}

ETbSame2Enum1 TbSame2DataJavaConverter::getEnum1Value(JNIEnv* env, jobject input)
{
	ETbSame2Enum1 cppEnumValue = ETbSame2Enum1::TS2E1_Value1;

	if (TbSame2JniCache::javaEnumEnum1GetValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, TbSame2JniCache::javaEnumEnum1GetValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum1.");
		checkJniError(errorMsg);
		UTbSame2Library::toTbSame2Enum1(cppEnumValue, int_value);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("Enum Enum1::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbSame2DataJavaConverter::makeJavaEnum1Array(JNIEnv* env, const TArray<ETbSame2Enum1>& cppArray)
{
	if (TbSame2JniCache::javaEnumEnum1 == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("Enum Enum1 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame2JniCache::javaEnumEnum1, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate Enum1 jarray.");
	checkJniError(errorMsgAlloc);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum1(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of Enum1 array.");
		checkJniError(errorMsg);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject TbSame2DataJavaConverter::makeJavaEnum1(JNIEnv* env, ETbSame2Enum1 value)
{
	if (TbSame2JniCache::javaEnumEnum1FromValueMethodId == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("Enum Enum1::fromValue not found"));
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(TbSame2JniCache::javaEnumEnum1, TbSame2JniCache::javaEnumEnum1FromValueMethodId, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum1.");
	checkJniError(errorMsg);
	return javaObj;
}

void TbSame2DataJavaConverter::fillEnum2Array(JNIEnv* env, jobjectArray input, TArray<ETbSame2Enum2>& out_array)
{
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of Enum2 array.");
	checkJniError(errorMsgLen);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of Enum2 array.");
		checkJniError(errorMsg);
		out_array.Add(getEnum2Value(env, element));
		env->DeleteLocalRef(element);
	}
}

ETbSame2Enum2 TbSame2DataJavaConverter::getEnum2Value(JNIEnv* env, jobject input)
{
	ETbSame2Enum2 cppEnumValue = ETbSame2Enum2::TS2E2_Value1;

	if (TbSame2JniCache::javaEnumEnum2GetValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, TbSame2JniCache::javaEnumEnum2GetValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum2.");
		checkJniError(errorMsg);
		UTbSame2Library::toTbSame2Enum2(cppEnumValue, int_value);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("Enum Enum2::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbSame2DataJavaConverter::makeJavaEnum2Array(JNIEnv* env, const TArray<ETbSame2Enum2>& cppArray)
{
	if (TbSame2JniCache::javaEnumEnum2 == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("Enum Enum2 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame2JniCache::javaEnumEnum2, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate Enum2 jarray.");
	checkJniError(errorMsgAlloc);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum2(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of Enum2 array.");
		checkJniError(errorMsg);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject TbSame2DataJavaConverter::makeJavaEnum2(JNIEnv* env, ETbSame2Enum2 value)
{
	if (TbSame2JniCache::javaEnumEnum2FromValueMethodId == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("Enum Enum2::fromValue not found"));
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(TbSame2JniCache::javaEnumEnum2, TbSame2JniCache::javaEnumEnum2FromValueMethodId, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum2.");
	checkJniError(errorMsg);
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
	if (!TbSame2JniCache::javaClassSameStruct1Interface)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("ISameStruct1Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame2JniCache::javaClassSameStruct1Interface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_same_struct1_interface.");
	checkJniError(errorMsg);
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
	if (!TbSame2JniCache::javaClassSameStruct2Interface)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("ISameStruct2Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame2JniCache::javaClassSameStruct2Interface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_same_struct2_interface.");
	checkJniError(errorMsg);
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
	if (!TbSame2JniCache::javaClassSameEnum1Interface)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("ISameEnum1Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame2JniCache::javaClassSameEnum1Interface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_same_enum1_interface.");
	checkJniError(errorMsg);
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
	if (!TbSame2JniCache::javaClassSameEnum2Interface)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("ISameEnum2Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbSame2JniCache::javaClassSameEnum2Interface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_same_enum2_interface.");
	checkJniError(errorMsg);
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

void TbSame2DataJavaConverter::checkJniError(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("%s"), Msg);
	}
}

#endif
