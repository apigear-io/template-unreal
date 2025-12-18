
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

DEFINE_LOG_CATEGORY(LogTbSame2DataJavaConverter_JNI);

jclass TbSame2DataJavaConverter::jStruct1 = nullptr;

void TbSame2DataJavaConverter::fillStruct1(JNIEnv* env, jobject input, FTbSame2Struct1& out_struct1)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTbSame2Struct1");
	static const jfieldID jFieldId_field1 = getFieldId(jStruct1, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1)
	{
		out_struct1.field1 = env->GetIntField(input, jFieldId_field1);
		static const TCHAR* errorMsgfield1 = TEXT("failed when getting the jFieldId_field1 for out_struct1.field1");
		checkJniErrorOccured(errorMsgfield1);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame2Struct1 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 I for FTbSame2Struct1");
	static const jfieldID jFieldId_field2 = getFieldId(jStruct1, "field2", "I", errorMsgFindfield2);

	if (jFieldId_field2)
	{
		out_struct1.field2 = env->GetIntField(input, jFieldId_field2);
		static const TCHAR* errorMsgfield2 = TEXT("failed when getting the jFieldId_field2 for out_struct1.field2");
		checkJniErrorOccured(errorMsgfield2);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame2Struct1 not found"));
	}

	static const TCHAR* errorMsgFindfield3 = TEXT("failed when trying to field field3 I for FTbSame2Struct1");
	static const jfieldID jFieldId_field3 = getFieldId(jStruct1, "field3", "I", errorMsgFindfield3);

	if (jFieldId_field3)
	{
		out_struct1.field3 = env->GetIntField(input, jFieldId_field3);
		static const TCHAR* errorMsgfield3 = TEXT("failed when getting the jFieldId_field3 for out_struct1.field3");
		checkJniErrorOccured(errorMsgfield3);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame2Struct1 not found"));
	}
}

void TbSame2DataJavaConverter::fillStruct1Array(JNIEnv* env, jobjectArray input, TArray<FTbSame2Struct1>& out_array)
{
	ensureInitialized();
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct1 array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct1 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStruct1(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject TbSame2DataJavaConverter::makeJavaStruct1(JNIEnv* env, const FTbSame2Struct1& in_struct1)
{
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct1.");
	static const jmethodID ctor = getMethod(jStruct1, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStruct1, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct1.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTbSame2Struct1");
	static const jfieldID jFieldId_field1 = getFieldId(jStruct1, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct1.field1);
		static const TCHAR* errorMsgfield1Set = TEXT("failed when seting field for out_struct1.field1");
		checkJniErrorOccured(errorMsgfield1Set);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame2Struct1 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 I for FTbSame2Struct1");
	static const jfieldID jFieldId_field2 = getFieldId(jStruct1, "field2", "I", errorMsgFindfield2);

	if (jFieldId_field2 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field2, in_struct1.field2);
		static const TCHAR* errorMsgfield2Set = TEXT("failed when seting field for out_struct1.field2");
		checkJniErrorOccured(errorMsgfield2Set);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame2Struct1 not found"));
	}

	static const TCHAR* errorMsgFindfield3 = TEXT("failed when trying to field field3 I for FTbSame2Struct1");
	static const jfieldID jFieldId_field3 = getFieldId(jStruct1, "field3", "I", errorMsgFindfield3);

	if (jFieldId_field3 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field3, in_struct1.field3);
		static const TCHAR* errorMsgfield3Set = TEXT("failed when seting field for out_struct1.field3");
		checkJniErrorOccured(errorMsgfield3Set);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame2Struct1 not found"));
	}
	return javaObjInstance;
}

jobjectArray TbSame2DataJavaConverter::makeJavaStruct1Array(JNIEnv* env, const TArray<FTbSame2Struct1>& cppArray)
{
	ensureInitialized();
	if (jStruct1 == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("FTbSame2Struct1 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStruct1, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct1.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStruct1(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct1 jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

jclass TbSame2DataJavaConverter::jStruct2 = nullptr;

void TbSame2DataJavaConverter::fillStruct2(JNIEnv* env, jobject input, FTbSame2Struct2& out_struct2)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTbSame2Struct2");
	static const jfieldID jFieldId_field1 = getFieldId(jStruct2, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1)
	{
		out_struct2.field1 = env->GetIntField(input, jFieldId_field1);
		static const TCHAR* errorMsgfield1 = TEXT("failed when getting the jFieldId_field1 for out_struct2.field1");
		checkJniErrorOccured(errorMsgfield1);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame2Struct2 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 I for FTbSame2Struct2");
	static const jfieldID jFieldId_field2 = getFieldId(jStruct2, "field2", "I", errorMsgFindfield2);

	if (jFieldId_field2)
	{
		out_struct2.field2 = env->GetIntField(input, jFieldId_field2);
		static const TCHAR* errorMsgfield2 = TEXT("failed when getting the jFieldId_field2 for out_struct2.field2");
		checkJniErrorOccured(errorMsgfield2);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame2Struct2 not found"));
	}

	static const TCHAR* errorMsgFindfield3 = TEXT("failed when trying to field field3 I for FTbSame2Struct2");
	static const jfieldID jFieldId_field3 = getFieldId(jStruct2, "field3", "I", errorMsgFindfield3);

	if (jFieldId_field3)
	{
		out_struct2.field3 = env->GetIntField(input, jFieldId_field3);
		static const TCHAR* errorMsgfield3 = TEXT("failed when getting the jFieldId_field3 for out_struct2.field3");
		checkJniErrorOccured(errorMsgfield3);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame2Struct2 not found"));
	}
}

void TbSame2DataJavaConverter::fillStruct2Array(JNIEnv* env, jobjectArray input, TArray<FTbSame2Struct2>& out_array)
{
	ensureInitialized();
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct2 array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct2 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStruct2(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject TbSame2DataJavaConverter::makeJavaStruct2(JNIEnv* env, const FTbSame2Struct2& in_struct2)
{
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct2.");
	static const jmethodID ctor = getMethod(jStruct2, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStruct2, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct2.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTbSame2Struct2");
	static const jfieldID jFieldId_field1 = getFieldId(jStruct2, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct2.field1);
		static const TCHAR* errorMsgfield1Set = TEXT("failed when seting field for out_struct2.field1");
		checkJniErrorOccured(errorMsgfield1Set);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame2Struct2 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 I for FTbSame2Struct2");
	static const jfieldID jFieldId_field2 = getFieldId(jStruct2, "field2", "I", errorMsgFindfield2);

	if (jFieldId_field2 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field2, in_struct2.field2);
		static const TCHAR* errorMsgfield2Set = TEXT("failed when seting field for out_struct2.field2");
		checkJniErrorOccured(errorMsgfield2Set);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame2Struct2 not found"));
	}

	static const TCHAR* errorMsgFindfield3 = TEXT("failed when trying to field field3 I for FTbSame2Struct2");
	static const jfieldID jFieldId_field3 = getFieldId(jStruct2, "field3", "I", errorMsgFindfield3);

	if (jFieldId_field3 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field3, in_struct2.field3);
		static const TCHAR* errorMsgfield3Set = TEXT("failed when seting field for out_struct2.field3");
		checkJniErrorOccured(errorMsgfield3Set);
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame2Struct2 not found"));
	}
	return javaObjInstance;
}

jobjectArray TbSame2DataJavaConverter::makeJavaStruct2Array(JNIEnv* env, const TArray<FTbSame2Struct2>& cppArray)
{
	ensureInitialized();
	if (jStruct2 == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("FTbSame2Struct2 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStruct2, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct2.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStruct2(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct2 jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}
jclass TbSame2DataJavaConverter::jEnum1 = nullptr;

void TbSame2DataJavaConverter::fillEnum1Array(JNIEnv* env, jobjectArray input, TArray<ETbSame2Enum1>& out_array)
{
	ensureInitialized();
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of Enum1 array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of Enum1 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			out_array.Add(getEnum1Value(env, element));
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

ETbSame2Enum1 TbSame2DataJavaConverter::getEnum1Value(JNIEnv* env, jobject input)
{
	ETbSame2Enum1 cppEnumValue = ETbSame2Enum1::TS2E1_Value1;
	ensureInitialized();
	static const TCHAR* errorMsgGetMethod = TEXT("failed when trying to get java method getVaue for object for Enum1.");
	static const jmethodID getValueMethod = getMethod(jEnum1, "getValue", "()I", errorMsgGetMethod);
	if (getValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, getValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum1.");
		if (!checkJniErrorOccured(errorMsg))
		{
			UTbSame2Library::toTbSame2Enum1(cppEnumValue, int_value);
		}
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("Enum Enum1::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbSame2DataJavaConverter::makeJavaEnum1Array(JNIEnv* env, const TArray<ETbSame2Enum1>& cppArray)
{
	ensureInitialized();
	if (jEnum1 == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("Enum Enum1 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jEnum1, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate Enum1 jarray.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum1(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of Enum1 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

jobject TbSame2DataJavaConverter::makeJavaEnum1(JNIEnv* env, ETbSame2Enum1 value)
{
	ensureInitialized();
	static const TCHAR* errorMsgFromValueMethod = TEXT("failed when trying to get java method fromValue for object for Enum1.");
	static const jmethodID fromValueMethod = getStaticMethod(jEnum1, "fromValue", "(I)LtbSame2/tbSame2_api/Enum1;", errorMsgFromValueMethod);
	if (fromValueMethod == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgFromValueMethod);
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(jEnum1, fromValueMethod, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum1.");
	checkJniErrorOccured(errorMsg);
	return javaObj;
}
jclass TbSame2DataJavaConverter::jEnum2 = nullptr;

void TbSame2DataJavaConverter::fillEnum2Array(JNIEnv* env, jobjectArray input, TArray<ETbSame2Enum2>& out_array)
{
	ensureInitialized();
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of Enum2 array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of Enum2 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			out_array.Add(getEnum2Value(env, element));
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

ETbSame2Enum2 TbSame2DataJavaConverter::getEnum2Value(JNIEnv* env, jobject input)
{
	ETbSame2Enum2 cppEnumValue = ETbSame2Enum2::TS2E2_Value1;
	ensureInitialized();
	static const TCHAR* errorMsgGetMethod = TEXT("failed when trying to get java method getVaue for object for Enum2.");
	static const jmethodID getValueMethod = getMethod(jEnum2, "getValue", "()I", errorMsgGetMethod);
	if (getValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, getValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum2.");
		if (!checkJniErrorOccured(errorMsg))
		{
			UTbSame2Library::toTbSame2Enum2(cppEnumValue, int_value);
		}
	}
	else
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("Enum Enum2::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbSame2DataJavaConverter::makeJavaEnum2Array(JNIEnv* env, const TArray<ETbSame2Enum2>& cppArray)
{
	ensureInitialized();
	if (jEnum2 == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("Enum Enum2 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jEnum2, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate Enum2 jarray.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum2(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of Enum2 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

jobject TbSame2DataJavaConverter::makeJavaEnum2(JNIEnv* env, ETbSame2Enum2 value)
{
	ensureInitialized();
	static const TCHAR* errorMsgFromValueMethod = TEXT("failed when trying to get java method fromValue for object for Enum2.");
	static const jmethodID fromValueMethod = getStaticMethod(jEnum2, "fromValue", "(I)LtbSame2/tbSame2_api/Enum2;", errorMsgFromValueMethod);
	if (fromValueMethod == nullptr)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgFromValueMethod);
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(jEnum2, fromValueMethod, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum2.");
	checkJniErrorOccured(errorMsg);
	return javaObj;
}

jclass TbSame2DataJavaConverter::jSameStruct1Interface = nullptr;

void TbSame2DataJavaConverter::fillSameStruct1Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame2SameStruct1InterfaceInterface> out_same_struct1_interface)
{
	ensureInitialized();
	if (!input || !out_same_struct1_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame2DataJavaConverter::fillSameStruct1InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame2SameStruct1InterfaceInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame2DataJavaConverter::makeJavaSameStruct1Interface(JNIEnv* env, const TScriptInterface<ITbSame2SameStruct1InterfaceInterface> out_same_struct1_interface)
{
	ensureInitialized();
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
	ensureInitialized();
	if (!jSameStruct1Interface)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("ISameStruct1Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jSameStruct1Interface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_same_struct1_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> TbSame2DataJavaConverter::getCppInstanceTbSame2SameStruct1Interface()
{
	ensureInitialized();
	UTbSame2SameStruct1InterfaceImplementation* Impl = NewObject<UTbSame2SameStruct1InterfaceImplementation>();
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame2SameStruct1InterfaceInterface>(Impl));
	return wrapped;
}

jclass TbSame2DataJavaConverter::jSameStruct2Interface = nullptr;

void TbSame2DataJavaConverter::fillSameStruct2Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame2SameStruct2InterfaceInterface> out_same_struct2_interface)
{
	ensureInitialized();
	if (!input || !out_same_struct2_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame2DataJavaConverter::fillSameStruct2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame2SameStruct2InterfaceInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame2DataJavaConverter::makeJavaSameStruct2Interface(JNIEnv* env, const TScriptInterface<ITbSame2SameStruct2InterfaceInterface> out_same_struct2_interface)
{
	ensureInitialized();
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
	ensureInitialized();
	if (!jSameStruct2Interface)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("ISameStruct2Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jSameStruct2Interface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_same_struct2_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> TbSame2DataJavaConverter::getCppInstanceTbSame2SameStruct2Interface()
{
	ensureInitialized();
	UTbSame2SameStruct2InterfaceImplementation* Impl = NewObject<UTbSame2SameStruct2InterfaceImplementation>();
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame2SameStruct2InterfaceInterface>(Impl));
	return wrapped;
}

jclass TbSame2DataJavaConverter::jSameEnum1Interface = nullptr;

void TbSame2DataJavaConverter::fillSameEnum1Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame2SameEnum1InterfaceInterface> out_same_enum1_interface)
{
	ensureInitialized();
	if (!input || !out_same_enum1_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame2DataJavaConverter::fillSameEnum1InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame2SameEnum1InterfaceInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame2DataJavaConverter::makeJavaSameEnum1Interface(JNIEnv* env, const TScriptInterface<ITbSame2SameEnum1InterfaceInterface> out_same_enum1_interface)
{
	ensureInitialized();
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
	ensureInitialized();
	if (!jSameEnum1Interface)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("ISameEnum1Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jSameEnum1Interface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_same_enum1_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSame2SameEnum1InterfaceInterface> TbSame2DataJavaConverter::getCppInstanceTbSame2SameEnum1Interface()
{
	ensureInitialized();
	UTbSame2SameEnum1InterfaceImplementation* Impl = NewObject<UTbSame2SameEnum1InterfaceImplementation>();
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame2SameEnum1InterfaceInterface>(Impl));
	return wrapped;
}

jclass TbSame2DataJavaConverter::jSameEnum2Interface = nullptr;

void TbSame2DataJavaConverter::fillSameEnum2Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame2SameEnum2InterfaceInterface> out_same_enum2_interface)
{
	ensureInitialized();
	if (!input || !out_same_enum2_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame2DataJavaConverter::fillSameEnum2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame2SameEnum2InterfaceInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame2DataJavaConverter::makeJavaSameEnum2Interface(JNIEnv* env, const TScriptInterface<ITbSame2SameEnum2InterfaceInterface> out_same_enum2_interface)
{
	ensureInitialized();
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
	ensureInitialized();
	if (!jSameEnum2Interface)
	{
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Warning, TEXT("ISameEnum2Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jSameEnum2Interface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_same_enum2_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> TbSame2DataJavaConverter::getCppInstanceTbSame2SameEnum2Interface()
{
	ensureInitialized();
	UTbSame2SameEnum2InterfaceImplementation* Impl = NewObject<UTbSame2SameEnum2InterfaceImplementation>();
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame2SameEnum2InterfaceInterface>(Impl));
	return wrapped;
}

bool TbSame2DataJavaConverter::checkJniErrorOccured(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbSame2DataJavaConverter_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

void TbSame2DataJavaConverter::cleanJavaReferences()
{
	FScopeLock Lock(&initMutex);
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(jStruct1);
	env->DeleteGlobalRef(jStruct2);
	env->DeleteGlobalRef(jEnum1);
	env->DeleteGlobalRef(jEnum2);
	env->DeleteGlobalRef(jSameStruct1Interface);
	env->DeleteGlobalRef(jSameStruct2Interface);
	env->DeleteGlobalRef(jSameEnum1Interface);
	env->DeleteGlobalRef(jSameEnum2Interface);
}

FCriticalSection TbSame2DataJavaConverter::initMutex;

bool TbSame2DataJavaConverter::m_isInitialized = false;

void TbSame2DataJavaConverter::ensureInitialized()
{
	if (m_isInitialized)
	{
		return;
	}
	FScopeLock Lock(&initMutex);
	if (m_isInitialized)
	{
		return;
	}
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jStruct1 = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Struct1");
	static const TCHAR* errorMsgStruct1 = TEXT("failed to get tbSame2/tbSame2_api/Struct1");
	checkJniErrorOccured(errorMsgStruct1);
	jStruct2 = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Struct2");
	static const TCHAR* errorMsgStruct2 = TEXT("failed to get tbSame2/tbSame2_api/Struct2");
	checkJniErrorOccured(errorMsgStruct2);
	jEnum1 = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Enum1");
	static const TCHAR* errorMsgEnum1 = TEXT("failed to get tbSame2/tbSame2_api/Enum1");
	checkJniErrorOccured(errorMsgEnum1);
	jEnum2 = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/Enum2");
	static const TCHAR* errorMsgEnum2 = TEXT("failed to get tbSame2/tbSame2_api/Enum2");
	checkJniErrorOccured(errorMsgEnum2);
	jSameStruct1Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/ISameStruct1Interface");
	static const TCHAR* errorMsgSameStruct1Interface = TEXT("failed to get tbSame2/tbSame2_api/ISameStruct1Interface");
	checkJniErrorOccured(errorMsgSameStruct1Interface);
	jSameStruct2Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/ISameStruct2Interface");
	static const TCHAR* errorMsgSameStruct2Interface = TEXT("failed to get tbSame2/tbSame2_api/ISameStruct2Interface");
	checkJniErrorOccured(errorMsgSameStruct2Interface);
	jSameEnum1Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/ISameEnum1Interface");
	static const TCHAR* errorMsgSameEnum1Interface = TEXT("failed to get tbSame2/tbSame2_api/ISameEnum1Interface");
	checkJniErrorOccured(errorMsgSameEnum1Interface);
	jSameEnum2Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame2/tbSame2_api/ISameEnum2Interface");
	static const TCHAR* errorMsgSameEnum2Interface = TEXT("failed to get tbSame2/tbSame2_api/ISameEnum2Interface");
	checkJniErrorOccured(errorMsgSameEnum2Interface);
	m_isInitialized = true;
}

jmethodID TbSame2DataJavaConverter::getMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jmethodID TbSame2DataJavaConverter::getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetStaticMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jfieldID TbSame2DataJavaConverter::getFieldId(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jfieldID field = env->GetFieldID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return field;
}

#endif
