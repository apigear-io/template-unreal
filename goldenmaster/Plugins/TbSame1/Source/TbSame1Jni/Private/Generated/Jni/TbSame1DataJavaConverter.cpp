
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

jclass TbSame1DataJavaConverter::jStruct1 = nullptr;

void TbSame1DataJavaConverter::fillStruct1(JNIEnv* env, jobject input, FTbSame1Struct1& out_struct1)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTbSame1Struct1");
	static const jfieldID jFieldId_field1 = getFieldId(jStruct1, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1)
	{
		out_struct1.field1 = env->GetIntField(input, jFieldId_field1);
		static const TCHAR* errorMsgfield1 = TEXT("failed when getting the jFieldId_field1 for out_struct1.field1");
		checkJniErrorOccured(errorMsgfield1);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame1Struct1 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 I for FTbSame1Struct1");
	static const jfieldID jFieldId_field2 = getFieldId(jStruct1, "field2", "I", errorMsgFindfield2);

	if (jFieldId_field2)
	{
		out_struct1.field2 = env->GetIntField(input, jFieldId_field2);
		static const TCHAR* errorMsgfield2 = TEXT("failed when getting the jFieldId_field2 for out_struct1.field2");
		checkJniErrorOccured(errorMsgfield2);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame1Struct1 not found"));
	}

	static const TCHAR* errorMsgFindfield3 = TEXT("failed when trying to field field3 I for FTbSame1Struct1");
	static const jfieldID jFieldId_field3 = getFieldId(jStruct1, "field3", "I", errorMsgFindfield3);

	if (jFieldId_field3)
	{
		out_struct1.field3 = env->GetIntField(input, jFieldId_field3);
		static const TCHAR* errorMsgfield3 = TEXT("failed when getting the jFieldId_field3 for out_struct1.field3");
		checkJniErrorOccured(errorMsgfield3);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame1Struct1 not found"));
	}
}

void TbSame1DataJavaConverter::fillStruct1Array(JNIEnv* env, jobjectArray input, TArray<FTbSame1Struct1>& out_array)
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

jobject TbSame1DataJavaConverter::makeJavaStruct1(JNIEnv* env, const FTbSame1Struct1& in_struct1)
{
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct1.");
	static const jmethodID ctor = getMethod(jStruct1, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStruct1, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct1.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTbSame1Struct1");
	static const jfieldID jFieldId_field1 = getFieldId(jStruct1, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct1.field1);
		static const TCHAR* errorMsgfield1Set = TEXT("failed when seting field for out_struct1.field1");
		checkJniErrorOccured(errorMsgfield1Set);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame1Struct1 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 I for FTbSame1Struct1");
	static const jfieldID jFieldId_field2 = getFieldId(jStruct1, "field2", "I", errorMsgFindfield2);

	if (jFieldId_field2 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field2, in_struct1.field2);
		static const TCHAR* errorMsgfield2Set = TEXT("failed when seting field for out_struct1.field2");
		checkJniErrorOccured(errorMsgfield2Set);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame1Struct1 not found"));
	}

	static const TCHAR* errorMsgFindfield3 = TEXT("failed when trying to field field3 I for FTbSame1Struct1");
	static const jfieldID jFieldId_field3 = getFieldId(jStruct1, "field3", "I", errorMsgFindfield3);

	if (jFieldId_field3 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field3, in_struct1.field3);
		static const TCHAR* errorMsgfield3Set = TEXT("failed when seting field for out_struct1.field3");
		checkJniErrorOccured(errorMsgfield3Set);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame1Struct1 not found"));
	}
	return javaObjInstance;
}

jobjectArray TbSame1DataJavaConverter::makeJavaStruct1Array(JNIEnv* env, const TArray<FTbSame1Struct1>& cppArray)
{
	ensureInitialized();
	if (jStruct1 == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("FTbSame1Struct1 not found"));
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

jclass TbSame1DataJavaConverter::jStruct2 = nullptr;

void TbSame1DataJavaConverter::fillStruct2(JNIEnv* env, jobject input, FTbSame1Struct2& out_struct2)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTbSame1Struct2");
	static const jfieldID jFieldId_field1 = getFieldId(jStruct2, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1)
	{
		out_struct2.field1 = env->GetIntField(input, jFieldId_field1);
		static const TCHAR* errorMsgfield1 = TEXT("failed when getting the jFieldId_field1 for out_struct2.field1");
		checkJniErrorOccured(errorMsgfield1);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame1Struct2 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 I for FTbSame1Struct2");
	static const jfieldID jFieldId_field2 = getFieldId(jStruct2, "field2", "I", errorMsgFindfield2);

	if (jFieldId_field2)
	{
		out_struct2.field2 = env->GetIntField(input, jFieldId_field2);
		static const TCHAR* errorMsgfield2 = TEXT("failed when getting the jFieldId_field2 for out_struct2.field2");
		checkJniErrorOccured(errorMsgfield2);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame1Struct2 not found"));
	}

	static const TCHAR* errorMsgFindfield3 = TEXT("failed when trying to field field3 I for FTbSame1Struct2");
	static const jfieldID jFieldId_field3 = getFieldId(jStruct2, "field3", "I", errorMsgFindfield3);

	if (jFieldId_field3)
	{
		out_struct2.field3 = env->GetIntField(input, jFieldId_field3);
		static const TCHAR* errorMsgfield3 = TEXT("failed when getting the jFieldId_field3 for out_struct2.field3");
		checkJniErrorOccured(errorMsgfield3);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame1Struct2 not found"));
	}
}

void TbSame1DataJavaConverter::fillStruct2Array(JNIEnv* env, jobjectArray input, TArray<FTbSame1Struct2>& out_array)
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

jobject TbSame1DataJavaConverter::makeJavaStruct2(JNIEnv* env, const FTbSame1Struct2& in_struct2)
{
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct2.");
	static const jmethodID ctor = getMethod(jStruct2, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStruct2, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct2.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTbSame1Struct2");
	static const jfieldID jFieldId_field1 = getFieldId(jStruct2, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct2.field1);
		static const TCHAR* errorMsgfield1Set = TEXT("failed when seting field for out_struct2.field1");
		checkJniErrorOccured(errorMsgfield1Set);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field1 field in FTbSame1Struct2 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 I for FTbSame1Struct2");
	static const jfieldID jFieldId_field2 = getFieldId(jStruct2, "field2", "I", errorMsgFindfield2);

	if (jFieldId_field2 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field2, in_struct2.field2);
		static const TCHAR* errorMsgfield2Set = TEXT("failed when seting field for out_struct2.field2");
		checkJniErrorOccured(errorMsgfield2Set);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field2 field in FTbSame1Struct2 not found"));
	}

	static const TCHAR* errorMsgFindfield3 = TEXT("failed when trying to field field3 I for FTbSame1Struct2");
	static const jfieldID jFieldId_field3 = getFieldId(jStruct2, "field3", "I", errorMsgFindfield3);

	if (jFieldId_field3 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field3, in_struct2.field3);
		static const TCHAR* errorMsgfield3Set = TEXT("failed when seting field for out_struct2.field3");
		checkJniErrorOccured(errorMsgfield3Set);
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("field3 field in FTbSame1Struct2 not found"));
	}
	return javaObjInstance;
}

jobjectArray TbSame1DataJavaConverter::makeJavaStruct2Array(JNIEnv* env, const TArray<FTbSame1Struct2>& cppArray)
{
	ensureInitialized();
	if (jStruct2 == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("FTbSame1Struct2 not found"));
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
jclass TbSame1DataJavaConverter::jEnum1 = nullptr;

void TbSame1DataJavaConverter::fillEnum1Array(JNIEnv* env, jobjectArray input, TArray<ETbSame1Enum1>& out_array)
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

ETbSame1Enum1 TbSame1DataJavaConverter::getEnum1Value(JNIEnv* env, jobject input)
{
	ETbSame1Enum1 cppEnumValue = ETbSame1Enum1::TS1E1_Value1;
	ensureInitialized();
	static const TCHAR* errorMsgGetMethod = TEXT("failed when trying to get java method getVaue for object for Enum1.");
	static const jmethodID getValueMethod = getMethod(jEnum1, "getValue", "()I", errorMsgGetMethod);
	if (getValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, getValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum1.");
		if (!checkJniErrorOccured(errorMsg))
		{
			UTbSame1Library::toTbSame1Enum1(cppEnumValue, int_value);
		}
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("Enum Enum1::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbSame1DataJavaConverter::makeJavaEnum1Array(JNIEnv* env, const TArray<ETbSame1Enum1>& cppArray)
{
	ensureInitialized();
	if (jEnum1 == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("Enum Enum1 not found"));
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

jobject TbSame1DataJavaConverter::makeJavaEnum1(JNIEnv* env, ETbSame1Enum1 value)
{
	ensureInitialized();
	static const TCHAR* errorMsgFromValueMethod = TEXT("failed when trying to get java method fromValue for object for Enum1.");
	static const jmethodID fromValueMethod = getStaticMethod(jEnum1, "fromValue", "(I)LtbSame1/tbSame1_api/Enum1;", errorMsgFromValueMethod);
	if (fromValueMethod == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgFromValueMethod);
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(jEnum1, fromValueMethod, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum1.");
	checkJniErrorOccured(errorMsg);
	return javaObj;
}
jclass TbSame1DataJavaConverter::jEnum2 = nullptr;

void TbSame1DataJavaConverter::fillEnum2Array(JNIEnv* env, jobjectArray input, TArray<ETbSame1Enum2>& out_array)
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

ETbSame1Enum2 TbSame1DataJavaConverter::getEnum2Value(JNIEnv* env, jobject input)
{
	ETbSame1Enum2 cppEnumValue = ETbSame1Enum2::TS1E2_Value1;
	ensureInitialized();
	static const TCHAR* errorMsgGetMethod = TEXT("failed when trying to get java method getVaue for object for Enum2.");
	static const jmethodID getValueMethod = getMethod(jEnum2, "getValue", "()I", errorMsgGetMethod);
	if (getValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, getValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum2.");
		if (!checkJniErrorOccured(errorMsg))
		{
			UTbSame1Library::toTbSame1Enum2(cppEnumValue, int_value);
		}
	}
	else
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("Enum Enum2::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbSame1DataJavaConverter::makeJavaEnum2Array(JNIEnv* env, const TArray<ETbSame1Enum2>& cppArray)
{
	ensureInitialized();
	if (jEnum2 == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("Enum Enum2 not found"));
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

jobject TbSame1DataJavaConverter::makeJavaEnum2(JNIEnv* env, ETbSame1Enum2 value)
{
	ensureInitialized();
	static const TCHAR* errorMsgFromValueMethod = TEXT("failed when trying to get java method fromValue for object for Enum2.");
	static const jmethodID fromValueMethod = getStaticMethod(jEnum2, "fromValue", "(I)LtbSame1/tbSame1_api/Enum2;", errorMsgFromValueMethod);
	if (fromValueMethod == nullptr)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgFromValueMethod);
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(jEnum2, fromValueMethod, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum2.");
	checkJniErrorOccured(errorMsg);
	return javaObj;
}

jclass TbSame1DataJavaConverter::jSameStruct1Interface = nullptr;

void TbSame1DataJavaConverter::fillSameStruct1Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame1SameStruct1InterfaceInterface> out_same_struct1_interface)
{
	ensureInitialized();
	if (!input || !out_same_struct1_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame1DataJavaConverter::fillSameStruct1InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame1SameStruct1InterfaceInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame1DataJavaConverter::makeJavaSameStruct1Interface(JNIEnv* env, const TScriptInterface<ITbSame1SameStruct1InterfaceInterface> out_same_struct1_interface)
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

jobjectArray TbSame1DataJavaConverter::makeJavaSameStruct1InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame1SameStruct1InterfaceInterface>>& cppArray)
{
	ensureInitialized();
	if (!jSameStruct1Interface)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("ISameStruct1Interface not found"));
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

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> TbSame1DataJavaConverter::getCppInstanceTbSame1SameStruct1Interface()
{
	ensureInitialized();
	UTbSame1SameStruct1InterfaceImplementation* Impl = NewObject<UTbSame1SameStruct1InterfaceImplementation>();
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame1SameStruct1InterfaceInterface>(Impl));
	return wrapped;
}

jclass TbSame1DataJavaConverter::jSameStruct2Interface = nullptr;

void TbSame1DataJavaConverter::fillSameStruct2Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame1SameStruct2InterfaceInterface> out_same_struct2_interface)
{
	ensureInitialized();
	if (!input || !out_same_struct2_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame1DataJavaConverter::fillSameStruct2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame1SameStruct2InterfaceInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame1DataJavaConverter::makeJavaSameStruct2Interface(JNIEnv* env, const TScriptInterface<ITbSame1SameStruct2InterfaceInterface> out_same_struct2_interface)
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

jobjectArray TbSame1DataJavaConverter::makeJavaSameStruct2InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame1SameStruct2InterfaceInterface>>& cppArray)
{
	ensureInitialized();
	if (!jSameStruct2Interface)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("ISameStruct2Interface not found"));
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

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> TbSame1DataJavaConverter::getCppInstanceTbSame1SameStruct2Interface()
{
	ensureInitialized();
	UTbSame1SameStruct2InterfaceImplementation* Impl = NewObject<UTbSame1SameStruct2InterfaceImplementation>();
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame1SameStruct2InterfaceInterface>(Impl));
	return wrapped;
}

jclass TbSame1DataJavaConverter::jSameEnum1Interface = nullptr;

void TbSame1DataJavaConverter::fillSameEnum1Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame1SameEnum1InterfaceInterface> out_same_enum1_interface)
{
	ensureInitialized();
	if (!input || !out_same_enum1_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame1DataJavaConverter::fillSameEnum1InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame1SameEnum1InterfaceInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame1DataJavaConverter::makeJavaSameEnum1Interface(JNIEnv* env, const TScriptInterface<ITbSame1SameEnum1InterfaceInterface> out_same_enum1_interface)
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

jobjectArray TbSame1DataJavaConverter::makeJavaSameEnum1InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame1SameEnum1InterfaceInterface>>& cppArray)
{
	ensureInitialized();
	if (!jSameEnum1Interface)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("ISameEnum1Interface not found"));
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

TScriptInterface<ITbSame1SameEnum1InterfaceInterface> TbSame1DataJavaConverter::getCppInstanceTbSame1SameEnum1Interface()
{
	ensureInitialized();
	UTbSame1SameEnum1InterfaceImplementation* Impl = NewObject<UTbSame1SameEnum1InterfaceImplementation>();
	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame1SameEnum1InterfaceInterface>(Impl));
	return wrapped;
}

jclass TbSame1DataJavaConverter::jSameEnum2Interface = nullptr;

void TbSame1DataJavaConverter::fillSameEnum2Interface(JNIEnv* env, jobject input, TScriptInterface<ITbSame1SameEnum2InterfaceInterface> out_same_enum2_interface)
{
	ensureInitialized();
	if (!input || !out_same_enum2_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSame1DataJavaConverter::fillSameEnum2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSame1SameEnum2InterfaceInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSame1DataJavaConverter::makeJavaSameEnum2Interface(JNIEnv* env, const TScriptInterface<ITbSame1SameEnum2InterfaceInterface> out_same_enum2_interface)
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

jobjectArray TbSame1DataJavaConverter::makeJavaSameEnum2InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSame1SameEnum2InterfaceInterface>>& cppArray)
{
	ensureInitialized();
	if (!jSameEnum2Interface)
	{
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Warning, TEXT("ISameEnum2Interface not found"));
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

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> TbSame1DataJavaConverter::getCppInstanceTbSame1SameEnum2Interface()
{
	ensureInitialized();
	UTbSame1SameEnum2InterfaceImplementation* Impl = NewObject<UTbSame1SameEnum2InterfaceImplementation>();
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSame1SameEnum2InterfaceInterface>(Impl));
	return wrapped;
}

bool TbSame1DataJavaConverter::checkJniErrorOccured(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbSame1DataJavaConverter_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

void TbSame1DataJavaConverter::cleanJavaReferences()
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

FCriticalSection TbSame1DataJavaConverter::initMutex;

bool TbSame1DataJavaConverter::m_isInitialized = false;

void TbSame1DataJavaConverter::ensureInitialized()
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
	jStruct1 = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/Struct1");
	static const TCHAR* errorMsgStruct1 = TEXT("failed to get tbSame1/tbSame1_api/Struct1");
	checkJniErrorOccured(errorMsgStruct1);
	jStruct2 = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/Struct2");
	static const TCHAR* errorMsgStruct2 = TEXT("failed to get tbSame1/tbSame1_api/Struct2");
	checkJniErrorOccured(errorMsgStruct2);
	jEnum1 = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/Enum1");
	static const TCHAR* errorMsgEnum1 = TEXT("failed to get tbSame1/tbSame1_api/Enum1");
	checkJniErrorOccured(errorMsgEnum1);
	jEnum2 = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/Enum2");
	static const TCHAR* errorMsgEnum2 = TEXT("failed to get tbSame1/tbSame1_api/Enum2");
	checkJniErrorOccured(errorMsgEnum2);
	jSameStruct1Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/ISameStruct1Interface");
	static const TCHAR* errorMsgSameStruct1Interface = TEXT("failed to get tbSame1/tbSame1_api/ISameStruct1Interface");
	checkJniErrorOccured(errorMsgSameStruct1Interface);
	jSameStruct2Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/ISameStruct2Interface");
	static const TCHAR* errorMsgSameStruct2Interface = TEXT("failed to get tbSame1/tbSame1_api/ISameStruct2Interface");
	checkJniErrorOccured(errorMsgSameStruct2Interface);
	jSameEnum1Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/ISameEnum1Interface");
	static const TCHAR* errorMsgSameEnum1Interface = TEXT("failed to get tbSame1/tbSame1_api/ISameEnum1Interface");
	checkJniErrorOccured(errorMsgSameEnum1Interface);
	jSameEnum2Interface = FAndroidApplication::FindJavaClassGlobalRef("tbSame1/tbSame1_api/ISameEnum2Interface");
	static const TCHAR* errorMsgSameEnum2Interface = TEXT("failed to get tbSame1/tbSame1_api/ISameEnum2Interface");
	checkJniErrorOccured(errorMsgSameEnum2Interface);
	m_isInitialized = true;
}

jmethodID TbSame1DataJavaConverter::getMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jmethodID TbSame1DataJavaConverter::getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetStaticMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jfieldID TbSame1DataJavaConverter::getFieldId(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jfieldID field = env->GetFieldID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return field;
}

#endif
