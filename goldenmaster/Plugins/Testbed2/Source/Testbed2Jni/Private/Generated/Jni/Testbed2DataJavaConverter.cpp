
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

struct FTestbed2DataJavaConverterCacheData
{
	jclass jStruct1 = nullptr;
	jclass jStruct2 = nullptr;
	jclass jStruct3 = nullptr;
	jclass jStruct4 = nullptr;
	jclass jNestedStruct1 = nullptr;
	jclass jNestedStruct2 = nullptr;
	jclass jNestedStruct3 = nullptr;
	jclass jEnum1 = nullptr;
	jclass jEnum2 = nullptr;
	jclass jEnum3 = nullptr;
	jclass jManyParamInterface = nullptr;
	jclass jNestedStruct1Interface = nullptr;
	jclass jNestedStruct2Interface = nullptr;
	jclass jNestedStruct3Interface = nullptr;

	~FTestbed2DataJavaConverterCacheData()
	{
		JNIEnv* Env = FAndroidApplication::GetJavaEnv();
		if (Env)
		{
			if (jStruct1) Env->DeleteGlobalRef(jStruct1);
			if (jStruct2) Env->DeleteGlobalRef(jStruct2);
			if (jStruct3) Env->DeleteGlobalRef(jStruct3);
			if (jStruct4) Env->DeleteGlobalRef(jStruct4);
			if (jNestedStruct1) Env->DeleteGlobalRef(jNestedStruct1);
			if (jNestedStruct2) Env->DeleteGlobalRef(jNestedStruct2);
			if (jNestedStruct3) Env->DeleteGlobalRef(jNestedStruct3);
			if (jEnum1) Env->DeleteGlobalRef(jEnum1);
			if (jEnum2) Env->DeleteGlobalRef(jEnum2);
			if (jEnum3) Env->DeleteGlobalRef(jEnum3);
			if (jManyParamInterface) Env->DeleteGlobalRef(jManyParamInterface);
			if (jNestedStruct1Interface) Env->DeleteGlobalRef(jNestedStruct1Interface);
			if (jNestedStruct2Interface) Env->DeleteGlobalRef(jNestedStruct2Interface);
			if (jNestedStruct3Interface) Env->DeleteGlobalRef(jNestedStruct3Interface);
		}
	}
};

FCriticalSection Testbed2DataJavaConverter::CacheLock;
TSharedPtr<FTestbed2DataJavaConverterCacheData, ESPMode::ThreadSafe> Testbed2DataJavaConverter::CacheData;

void Testbed2DataJavaConverter::fillStruct1(JNIEnv* env, jobject input, FTestbed2Struct1& out_struct1)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillStruct1"));
		return;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTestbed2Struct1");
	static const jfieldID jFieldId_field1 = getFieldId(Cache->jStruct1, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1)
	{
		out_struct1.field1 = env->GetIntField(input, jFieldId_field1);
		static const TCHAR* errorMsgfield1 = TEXT("failed when getting the jFieldId_field1 for out_struct1.field1");
		checkJniErrorOccured(errorMsgfield1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct1 not found"));
	}
}

void Testbed2DataJavaConverter::fillStruct1Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct1>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillStruct1Array"));
		return;
	}
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

jobject Testbed2DataJavaConverter::makeJavaStruct1(JNIEnv* env, const FTestbed2Struct1& in_struct1)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for makeJavaStruct1"));
		return nullptr;
	}

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct1.");
	static const jmethodID ctor = getMethod(Cache->jStruct1, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(Cache->jStruct1, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct1.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTestbed2Struct1");
	static const jfieldID jFieldId_field1 = getFieldId(Cache->jStruct1, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct1.field1);
		static const TCHAR* errorMsgfield1Set = TEXT("failed when seting field for out_struct1.field1");
		checkJniErrorOccured(errorMsgfield1Set);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct1 not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaStruct1Array(JNIEnv* env, const TArray<FTestbed2Struct1>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jStruct1)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2Struct1 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jStruct1, nullptr);
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

void Testbed2DataJavaConverter::fillStruct2(JNIEnv* env, jobject input, FTestbed2Struct2& out_struct2)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillStruct2"));
		return;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTestbed2Struct2");
	static const jfieldID jFieldId_field1 = getFieldId(Cache->jStruct2, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1)
	{
		out_struct2.field1 = env->GetIntField(input, jFieldId_field1);
		static const TCHAR* errorMsgfield1 = TEXT("failed when getting the jFieldId_field1 for out_struct2.field1");
		checkJniErrorOccured(errorMsgfield1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct2 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 I for FTestbed2Struct2");
	static const jfieldID jFieldId_field2 = getFieldId(Cache->jStruct2, "field2", "I", errorMsgFindfield2);

	if (jFieldId_field2)
	{
		out_struct2.field2 = env->GetIntField(input, jFieldId_field2);
		static const TCHAR* errorMsgfield2 = TEXT("failed when getting the jFieldId_field2 for out_struct2.field2");
		checkJniErrorOccured(errorMsgfield2);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2Struct2 not found"));
	}
}

void Testbed2DataJavaConverter::fillStruct2Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct2>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillStruct2Array"));
		return;
	}
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

jobject Testbed2DataJavaConverter::makeJavaStruct2(JNIEnv* env, const FTestbed2Struct2& in_struct2)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for makeJavaStruct2"));
		return nullptr;
	}

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct2.");
	static const jmethodID ctor = getMethod(Cache->jStruct2, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(Cache->jStruct2, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct2.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTestbed2Struct2");
	static const jfieldID jFieldId_field1 = getFieldId(Cache->jStruct2, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct2.field1);
		static const TCHAR* errorMsgfield1Set = TEXT("failed when seting field for out_struct2.field1");
		checkJniErrorOccured(errorMsgfield1Set);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct2 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 I for FTestbed2Struct2");
	static const jfieldID jFieldId_field2 = getFieldId(Cache->jStruct2, "field2", "I", errorMsgFindfield2);

	if (jFieldId_field2 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field2, in_struct2.field2);
		static const TCHAR* errorMsgfield2Set = TEXT("failed when seting field for out_struct2.field2");
		checkJniErrorOccured(errorMsgfield2Set);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2Struct2 not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaStruct2Array(JNIEnv* env, const TArray<FTestbed2Struct2>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jStruct2)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2Struct2 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jStruct2, nullptr);
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

void Testbed2DataJavaConverter::fillStruct3(JNIEnv* env, jobject input, FTestbed2Struct3& out_struct3)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillStruct3"));
		return;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTestbed2Struct3");
	static const jfieldID jFieldId_field1 = getFieldId(Cache->jStruct3, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1)
	{
		out_struct3.field1 = env->GetIntField(input, jFieldId_field1);
		static const TCHAR* errorMsgfield1 = TEXT("failed when getting the jFieldId_field1 for out_struct3.field1");
		checkJniErrorOccured(errorMsgfield1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct3 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 I for FTestbed2Struct3");
	static const jfieldID jFieldId_field2 = getFieldId(Cache->jStruct3, "field2", "I", errorMsgFindfield2);

	if (jFieldId_field2)
	{
		out_struct3.field2 = env->GetIntField(input, jFieldId_field2);
		static const TCHAR* errorMsgfield2 = TEXT("failed when getting the jFieldId_field2 for out_struct3.field2");
		checkJniErrorOccured(errorMsgfield2);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2Struct3 not found"));
	}

	static const TCHAR* errorMsgFindfield3 = TEXT("failed when trying to field field3 I for FTestbed2Struct3");
	static const jfieldID jFieldId_field3 = getFieldId(Cache->jStruct3, "field3", "I", errorMsgFindfield3);

	if (jFieldId_field3)
	{
		out_struct3.field3 = env->GetIntField(input, jFieldId_field3);
		static const TCHAR* errorMsgfield3 = TEXT("failed when getting the jFieldId_field3 for out_struct3.field3");
		checkJniErrorOccured(errorMsgfield3);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTestbed2Struct3 not found"));
	}
}

void Testbed2DataJavaConverter::fillStruct3Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct3>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillStruct3Array"));
		return;
	}
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct3 array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct3 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStruct3(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed2DataJavaConverter::makeJavaStruct3(JNIEnv* env, const FTestbed2Struct3& in_struct3)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for makeJavaStruct3"));
		return nullptr;
	}

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct3.");
	static const jmethodID ctor = getMethod(Cache->jStruct3, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(Cache->jStruct3, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct3.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTestbed2Struct3");
	static const jfieldID jFieldId_field1 = getFieldId(Cache->jStruct3, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct3.field1);
		static const TCHAR* errorMsgfield1Set = TEXT("failed when seting field for out_struct3.field1");
		checkJniErrorOccured(errorMsgfield1Set);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct3 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 I for FTestbed2Struct3");
	static const jfieldID jFieldId_field2 = getFieldId(Cache->jStruct3, "field2", "I", errorMsgFindfield2);

	if (jFieldId_field2 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field2, in_struct3.field2);
		static const TCHAR* errorMsgfield2Set = TEXT("failed when seting field for out_struct3.field2");
		checkJniErrorOccured(errorMsgfield2Set);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2Struct3 not found"));
	}

	static const TCHAR* errorMsgFindfield3 = TEXT("failed when trying to field field3 I for FTestbed2Struct3");
	static const jfieldID jFieldId_field3 = getFieldId(Cache->jStruct3, "field3", "I", errorMsgFindfield3);

	if (jFieldId_field3 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field3, in_struct3.field3);
		static const TCHAR* errorMsgfield3Set = TEXT("failed when seting field for out_struct3.field3");
		checkJniErrorOccured(errorMsgfield3Set);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTestbed2Struct3 not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaStruct3Array(JNIEnv* env, const TArray<FTestbed2Struct3>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jStruct3)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2Struct3 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jStruct3, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct3.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStruct3(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct3 jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed2DataJavaConverter::fillStruct4(JNIEnv* env, jobject input, FTestbed2Struct4& out_struct4)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillStruct4"));
		return;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTestbed2Struct4");
	static const jfieldID jFieldId_field1 = getFieldId(Cache->jStruct4, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1)
	{
		out_struct4.field1 = env->GetIntField(input, jFieldId_field1);
		static const TCHAR* errorMsgfield1 = TEXT("failed when getting the jFieldId_field1 for out_struct4.field1");
		checkJniErrorOccured(errorMsgfield1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct4 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 I for FTestbed2Struct4");
	static const jfieldID jFieldId_field2 = getFieldId(Cache->jStruct4, "field2", "I", errorMsgFindfield2);

	if (jFieldId_field2)
	{
		out_struct4.field2 = env->GetIntField(input, jFieldId_field2);
		static const TCHAR* errorMsgfield2 = TEXT("failed when getting the jFieldId_field2 for out_struct4.field2");
		checkJniErrorOccured(errorMsgfield2);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2Struct4 not found"));
	}

	static const TCHAR* errorMsgFindfield3 = TEXT("failed when trying to field field3 I for FTestbed2Struct4");
	static const jfieldID jFieldId_field3 = getFieldId(Cache->jStruct4, "field3", "I", errorMsgFindfield3);

	if (jFieldId_field3)
	{
		out_struct4.field3 = env->GetIntField(input, jFieldId_field3);
		static const TCHAR* errorMsgfield3 = TEXT("failed when getting the jFieldId_field3 for out_struct4.field3");
		checkJniErrorOccured(errorMsgfield3);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTestbed2Struct4 not found"));
	}

	static const TCHAR* errorMsgFindfield4 = TEXT("failed when trying to field field4 I for FTestbed2Struct4");
	static const jfieldID jFieldId_field4 = getFieldId(Cache->jStruct4, "field4", "I", errorMsgFindfield4);

	if (jFieldId_field4)
	{
		out_struct4.field4 = env->GetIntField(input, jFieldId_field4);
		static const TCHAR* errorMsgfield4 = TEXT("failed when getting the jFieldId_field4 for out_struct4.field4");
		checkJniErrorOccured(errorMsgfield4);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field4 field in FTestbed2Struct4 not found"));
	}
}

void Testbed2DataJavaConverter::fillStruct4Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct4>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillStruct4Array"));
		return;
	}
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct4 array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct4 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStruct4(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed2DataJavaConverter::makeJavaStruct4(JNIEnv* env, const FTestbed2Struct4& in_struct4)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for makeJavaStruct4"));
		return nullptr;
	}

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct4.");
	static const jmethodID ctor = getMethod(Cache->jStruct4, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(Cache->jStruct4, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct4.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 I for FTestbed2Struct4");
	static const jfieldID jFieldId_field1 = getFieldId(Cache->jStruct4, "field1", "I", errorMsgFindfield1);

	if (jFieldId_field1 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field1, in_struct4.field1);
		static const TCHAR* errorMsgfield1Set = TEXT("failed when seting field for out_struct4.field1");
		checkJniErrorOccured(errorMsgfield1Set);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2Struct4 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 I for FTestbed2Struct4");
	static const jfieldID jFieldId_field2 = getFieldId(Cache->jStruct4, "field2", "I", errorMsgFindfield2);

	if (jFieldId_field2 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field2, in_struct4.field2);
		static const TCHAR* errorMsgfield2Set = TEXT("failed when seting field for out_struct4.field2");
		checkJniErrorOccured(errorMsgfield2Set);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2Struct4 not found"));
	}

	static const TCHAR* errorMsgFindfield3 = TEXT("failed when trying to field field3 I for FTestbed2Struct4");
	static const jfieldID jFieldId_field3 = getFieldId(Cache->jStruct4, "field3", "I", errorMsgFindfield3);

	if (jFieldId_field3 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field3, in_struct4.field3);
		static const TCHAR* errorMsgfield3Set = TEXT("failed when seting field for out_struct4.field3");
		checkJniErrorOccured(errorMsgfield3Set);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field3 field in FTestbed2Struct4 not found"));
	}

	static const TCHAR* errorMsgFindfield4 = TEXT("failed when trying to field field4 I for FTestbed2Struct4");
	static const jfieldID jFieldId_field4 = getFieldId(Cache->jStruct4, "field4", "I", errorMsgFindfield4);

	if (jFieldId_field4 != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field4, in_struct4.field4);
		static const TCHAR* errorMsgfield4Set = TEXT("failed when seting field for out_struct4.field4");
		checkJniErrorOccured(errorMsgfield4Set);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field4 field in FTestbed2Struct4 not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaStruct4Array(JNIEnv* env, const TArray<FTestbed2Struct4>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jStruct4)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2Struct4 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jStruct4, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct4.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStruct4(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct4 jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed2DataJavaConverter::fillNestedStruct1(JNIEnv* env, jobject input, FTestbed2NestedStruct1& out_nested_struct1)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillNestedStruct1"));
		return;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 Ltestbed2/testbed2_api/Struct1; for FTestbed2NestedStruct1");
	static const jfieldID jFieldId_field1 = getFieldId(Cache->jNestedStruct1, "field1", "Ltestbed2/testbed2_api/Struct1;", errorMsgFindfield1);

	if (jFieldId_field1)
	{
		jobject field1_value = env->GetObjectField(input, jFieldId_field1);
		static const TCHAR* errorMsgfield1 = TEXT("failed when getting the jFieldId_field1 for out_nested_struct1.field1");
		checkJniErrorOccured(errorMsgfield1);
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
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillNestedStruct1Array"));
		return;
	}
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_nested_struct1 array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_nested_struct1 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillNestedStruct1(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct1(JNIEnv* env, const FTestbed2NestedStruct1& in_nested_struct1)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for makeJavaNestedStruct1"));
		return nullptr;
	}

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_nested_struct1.");
	static const jmethodID ctor = getMethod(Cache->jNestedStruct1, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(Cache->jNestedStruct1, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_nested_struct1.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 Ltestbed2/testbed2_api/Struct1; for FTestbed2NestedStruct1");
	static const jfieldID jFieldId_field1 = getFieldId(Cache->jNestedStruct1, "field1", "Ltestbed2/testbed2_api/Struct1;", errorMsgFindfield1);

	if (jFieldId_field1 != nullptr)
	{
		jobject l_field1 = makeJavaStruct1(env, in_nested_struct1.field1);
		env->SetObjectField(javaObjInstance, jFieldId_field1, l_field1);
		static const TCHAR* errorMsgfield1Set = TEXT("failed when seting field for out_nested_struct1.field1");
		checkJniErrorOccured(errorMsgfield1Set);
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
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jNestedStruct1)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2NestedStruct1 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jNestedStruct1, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_nested_struct1.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaNestedStruct1(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_nested_struct1 jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed2DataJavaConverter::fillNestedStruct2(JNIEnv* env, jobject input, FTestbed2NestedStruct2& out_nested_struct2)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillNestedStruct2"));
		return;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 Ltestbed2/testbed2_api/Struct1; for FTestbed2NestedStruct2");
	static const jfieldID jFieldId_field1 = getFieldId(Cache->jNestedStruct2, "field1", "Ltestbed2/testbed2_api/Struct1;", errorMsgFindfield1);

	if (jFieldId_field1)
	{
		jobject field1_value = env->GetObjectField(input, jFieldId_field1);
		static const TCHAR* errorMsgfield1 = TEXT("failed when getting the jFieldId_field1 for out_nested_struct2.field1");
		checkJniErrorOccured(errorMsgfield1);
		fillStruct1(env, field1_value, out_nested_struct2.field1);
		env->DeleteLocalRef(field1_value);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2NestedStruct2 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 Ltestbed2/testbed2_api/Struct2; for FTestbed2NestedStruct2");
	static const jfieldID jFieldId_field2 = getFieldId(Cache->jNestedStruct2, "field2", "Ltestbed2/testbed2_api/Struct2;", errorMsgFindfield2);

	if (jFieldId_field2)
	{
		jobject field2_value = env->GetObjectField(input, jFieldId_field2);
		static const TCHAR* errorMsgfield2 = TEXT("failed when getting the jFieldId_field2 for out_nested_struct2.field2");
		checkJniErrorOccured(errorMsgfield2);
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
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillNestedStruct2Array"));
		return;
	}
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_nested_struct2 array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_nested_struct2 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillNestedStruct2(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct2(JNIEnv* env, const FTestbed2NestedStruct2& in_nested_struct2)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for makeJavaNestedStruct2"));
		return nullptr;
	}

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_nested_struct2.");
	static const jmethodID ctor = getMethod(Cache->jNestedStruct2, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(Cache->jNestedStruct2, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_nested_struct2.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 Ltestbed2/testbed2_api/Struct1; for FTestbed2NestedStruct2");
	static const jfieldID jFieldId_field1 = getFieldId(Cache->jNestedStruct2, "field1", "Ltestbed2/testbed2_api/Struct1;", errorMsgFindfield1);

	if (jFieldId_field1 != nullptr)
	{
		jobject l_field1 = makeJavaStruct1(env, in_nested_struct2.field1);
		env->SetObjectField(javaObjInstance, jFieldId_field1, l_field1);
		static const TCHAR* errorMsgfield1Set = TEXT("failed when seting field for out_nested_struct2.field1");
		checkJniErrorOccured(errorMsgfield1Set);
		env->DeleteLocalRef(l_field1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2NestedStruct2 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 Ltestbed2/testbed2_api/Struct2; for FTestbed2NestedStruct2");
	static const jfieldID jFieldId_field2 = getFieldId(Cache->jNestedStruct2, "field2", "Ltestbed2/testbed2_api/Struct2;", errorMsgFindfield2);

	if (jFieldId_field2 != nullptr)
	{
		jobject l_field2 = makeJavaStruct2(env, in_nested_struct2.field2);
		env->SetObjectField(javaObjInstance, jFieldId_field2, l_field2);
		static const TCHAR* errorMsgfield2Set = TEXT("failed when seting field for out_nested_struct2.field2");
		checkJniErrorOccured(errorMsgfield2Set);
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
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jNestedStruct2)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2NestedStruct2 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jNestedStruct2, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_nested_struct2.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaNestedStruct2(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_nested_struct2 jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed2DataJavaConverter::fillNestedStruct3(JNIEnv* env, jobject input, FTestbed2NestedStruct3& out_nested_struct3)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillNestedStruct3"));
		return;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 Ltestbed2/testbed2_api/Struct1; for FTestbed2NestedStruct3");
	static const jfieldID jFieldId_field1 = getFieldId(Cache->jNestedStruct3, "field1", "Ltestbed2/testbed2_api/Struct1;", errorMsgFindfield1);

	if (jFieldId_field1)
	{
		jobject field1_value = env->GetObjectField(input, jFieldId_field1);
		static const TCHAR* errorMsgfield1 = TEXT("failed when getting the jFieldId_field1 for out_nested_struct3.field1");
		checkJniErrorOccured(errorMsgfield1);
		fillStruct1(env, field1_value, out_nested_struct3.field1);
		env->DeleteLocalRef(field1_value);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2NestedStruct3 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 Ltestbed2/testbed2_api/Struct2; for FTestbed2NestedStruct3");
	static const jfieldID jFieldId_field2 = getFieldId(Cache->jNestedStruct3, "field2", "Ltestbed2/testbed2_api/Struct2;", errorMsgFindfield2);

	if (jFieldId_field2)
	{
		jobject field2_value = env->GetObjectField(input, jFieldId_field2);
		static const TCHAR* errorMsgfield2 = TEXT("failed when getting the jFieldId_field2 for out_nested_struct3.field2");
		checkJniErrorOccured(errorMsgfield2);
		fillStruct2(env, field2_value, out_nested_struct3.field2);
		env->DeleteLocalRef(field2_value);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2NestedStruct3 not found"));
	}

	static const TCHAR* errorMsgFindfield3 = TEXT("failed when trying to field field3 Ltestbed2/testbed2_api/Struct3; for FTestbed2NestedStruct3");
	static const jfieldID jFieldId_field3 = getFieldId(Cache->jNestedStruct3, "field3", "Ltestbed2/testbed2_api/Struct3;", errorMsgFindfield3);

	if (jFieldId_field3)
	{
		jobject field3_value = env->GetObjectField(input, jFieldId_field3);
		static const TCHAR* errorMsgfield3 = TEXT("failed when getting the jFieldId_field3 for out_nested_struct3.field3");
		checkJniErrorOccured(errorMsgfield3);
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
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillNestedStruct3Array"));
		return;
	}
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_nested_struct3 array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_nested_struct3 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillNestedStruct3(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct3(JNIEnv* env, const FTestbed2NestedStruct3& in_nested_struct3)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for makeJavaNestedStruct3"));
		return nullptr;
	}

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_nested_struct3.");
	static const jmethodID ctor = getMethod(Cache->jNestedStruct3, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(Cache->jNestedStruct3, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_nested_struct3.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfield1 = TEXT("failed when trying to field field1 Ltestbed2/testbed2_api/Struct1; for FTestbed2NestedStruct3");
	static const jfieldID jFieldId_field1 = getFieldId(Cache->jNestedStruct3, "field1", "Ltestbed2/testbed2_api/Struct1;", errorMsgFindfield1);

	if (jFieldId_field1 != nullptr)
	{
		jobject l_field1 = makeJavaStruct1(env, in_nested_struct3.field1);
		env->SetObjectField(javaObjInstance, jFieldId_field1, l_field1);
		static const TCHAR* errorMsgfield1Set = TEXT("failed when seting field for out_nested_struct3.field1");
		checkJniErrorOccured(errorMsgfield1Set);
		env->DeleteLocalRef(l_field1);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field1 field in FTestbed2NestedStruct3 not found"));
	}

	static const TCHAR* errorMsgFindfield2 = TEXT("failed when trying to field field2 Ltestbed2/testbed2_api/Struct2; for FTestbed2NestedStruct3");
	static const jfieldID jFieldId_field2 = getFieldId(Cache->jNestedStruct3, "field2", "Ltestbed2/testbed2_api/Struct2;", errorMsgFindfield2);

	if (jFieldId_field2 != nullptr)
	{
		jobject l_field2 = makeJavaStruct2(env, in_nested_struct3.field2);
		env->SetObjectField(javaObjInstance, jFieldId_field2, l_field2);
		static const TCHAR* errorMsgfield2Set = TEXT("failed when seting field for out_nested_struct3.field2");
		checkJniErrorOccured(errorMsgfield2Set);
		env->DeleteLocalRef(l_field2);
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("field2 field in FTestbed2NestedStruct3 not found"));
	}

	static const TCHAR* errorMsgFindfield3 = TEXT("failed when trying to field field3 Ltestbed2/testbed2_api/Struct3; for FTestbed2NestedStruct3");
	static const jfieldID jFieldId_field3 = getFieldId(Cache->jNestedStruct3, "field3", "Ltestbed2/testbed2_api/Struct3;", errorMsgFindfield3);

	if (jFieldId_field3 != nullptr)
	{
		jobject l_field3 = makeJavaStruct3(env, in_nested_struct3.field3);
		env->SetObjectField(javaObjInstance, jFieldId_field3, l_field3);
		static const TCHAR* errorMsgfield3Set = TEXT("failed when seting field for out_nested_struct3.field3");
		checkJniErrorOccured(errorMsgfield3Set);
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
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jNestedStruct3)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("FTestbed2NestedStruct3 not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jNestedStruct3, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_nested_struct3.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaNestedStruct3(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_nested_struct3 jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed2DataJavaConverter::fillEnum1Array(JNIEnv* env, jobjectArray input, TArray<ETestbed2Enum1>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillEnum1Array"));
		return;
	}
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

ETestbed2Enum1 Testbed2DataJavaConverter::getEnum1Value(JNIEnv* env, jobject input)
{
	ETestbed2Enum1 cppEnumValue = ETestbed2Enum1::T2E1_Value1;
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for getEnum1Value"));
		return cppEnumValue;
	}
	static const TCHAR* errorMsgGetMethod = TEXT("failed when trying to get java method getVaue for object for Enum1.");
	static const jmethodID getValueMethod = getMethod(Cache->jEnum1, "getValue", "()I", errorMsgGetMethod);
	if (getValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, getValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum1.");
		if (!checkJniErrorOccured(errorMsg))
		{
			UTestbed2Library::toTestbed2Enum1(cppEnumValue, int_value);
		}
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum1::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray Testbed2DataJavaConverter::makeJavaEnum1Array(JNIEnv* env, const TArray<ETestbed2Enum1>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jEnum1)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum1 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jEnum1, nullptr);
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

jobject Testbed2DataJavaConverter::makeJavaEnum1(JNIEnv* env, ETestbed2Enum1 value)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for makeJavaEnum1"));
		return nullptr;
	}
	static const TCHAR* errorMsgFromValueMethod = TEXT("failed when trying to get java method fromValue for object for Enum1.");
	static const jmethodID fromValueMethod = getStaticMethod(Cache->jEnum1, "fromValue", "(I)Ltestbed2/testbed2_api/Enum1;", errorMsgFromValueMethod);
	if (fromValueMethod == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgFromValueMethod);
		return nullptr;
	}
	int int_value = (int)value;
	jobject javaObj = env->CallStaticObjectMethod(Cache->jEnum1, fromValueMethod, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum1.");
	checkJniErrorOccured(errorMsg);
	return javaObj;
}

void Testbed2DataJavaConverter::fillEnum2Array(JNIEnv* env, jobjectArray input, TArray<ETestbed2Enum2>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillEnum2Array"));
		return;
	}
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

ETestbed2Enum2 Testbed2DataJavaConverter::getEnum2Value(JNIEnv* env, jobject input)
{
	ETestbed2Enum2 cppEnumValue = ETestbed2Enum2::T2E2_Value1;
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for getEnum2Value"));
		return cppEnumValue;
	}
	static const TCHAR* errorMsgGetMethod = TEXT("failed when trying to get java method getVaue for object for Enum2.");
	static const jmethodID getValueMethod = getMethod(Cache->jEnum2, "getValue", "()I", errorMsgGetMethod);
	if (getValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, getValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum2.");
		if (!checkJniErrorOccured(errorMsg))
		{
			UTestbed2Library::toTestbed2Enum2(cppEnumValue, int_value);
		}
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum2::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray Testbed2DataJavaConverter::makeJavaEnum2Array(JNIEnv* env, const TArray<ETestbed2Enum2>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jEnum2)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum2 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jEnum2, nullptr);
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

jobject Testbed2DataJavaConverter::makeJavaEnum2(JNIEnv* env, ETestbed2Enum2 value)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for makeJavaEnum2"));
		return nullptr;
	}
	static const TCHAR* errorMsgFromValueMethod = TEXT("failed when trying to get java method fromValue for object for Enum2.");
	static const jmethodID fromValueMethod = getStaticMethod(Cache->jEnum2, "fromValue", "(I)Ltestbed2/testbed2_api/Enum2;", errorMsgFromValueMethod);
	if (fromValueMethod == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgFromValueMethod);
		return nullptr;
	}
	int int_value = (int)value;
	jobject javaObj = env->CallStaticObjectMethod(Cache->jEnum2, fromValueMethod, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum2.");
	checkJniErrorOccured(errorMsg);
	return javaObj;
}

void Testbed2DataJavaConverter::fillEnum3Array(JNIEnv* env, jobjectArray input, TArray<ETestbed2Enum3>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillEnum3Array"));
		return;
	}
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of Enum3 array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of Enum3 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			out_array.Add(getEnum3Value(env, element));
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

ETestbed2Enum3 Testbed2DataJavaConverter::getEnum3Value(JNIEnv* env, jobject input)
{
	ETestbed2Enum3 cppEnumValue = ETestbed2Enum3::T2E3_Value1;
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for getEnum3Value"));
		return cppEnumValue;
	}
	static const TCHAR* errorMsgGetMethod = TEXT("failed when trying to get java method getVaue for object for Enum3.");
	static const jmethodID getValueMethod = getMethod(Cache->jEnum3, "getValue", "()I", errorMsgGetMethod);
	if (getValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, getValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum3.");
		if (!checkJniErrorOccured(errorMsg))
		{
			UTestbed2Library::toTestbed2Enum3(cppEnumValue, int_value);
		}
	}
	else
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum3::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray Testbed2DataJavaConverter::makeJavaEnum3Array(JNIEnv* env, const TArray<ETestbed2Enum3>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jEnum3)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Enum Enum3 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jEnum3, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate Enum3 jarray.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum3(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of Enum3 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

jobject Testbed2DataJavaConverter::makeJavaEnum3(JNIEnv* env, ETestbed2Enum3 value)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for makeJavaEnum3"));
		return nullptr;
	}
	static const TCHAR* errorMsgFromValueMethod = TEXT("failed when trying to get java method fromValue for object for Enum3.");
	static const jmethodID fromValueMethod = getStaticMethod(Cache->jEnum3, "fromValue", "(I)Ltestbed2/testbed2_api/Enum3;", errorMsgFromValueMethod);
	if (fromValueMethod == nullptr)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgFromValueMethod);
		return nullptr;
	}
	int int_value = (int)value;
	jobject javaObj = env->CallStaticObjectMethod(Cache->jEnum3, fromValueMethod, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum3.");
	checkJniErrorOccured(errorMsg);
	return javaObj;
}

void Testbed2DataJavaConverter::fillManyParamInterface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2ManyParamInterfaceInterface> out_many_param_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillManyParamInterface"));
		return;
	}
	if (!input || !out_many_param_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void Testbed2DataJavaConverter::fillManyParamInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2ManyParamInterfaceInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillManyParamInterfaceArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject Testbed2DataJavaConverter::makeJavaManyParamInterface(JNIEnv* env, const TScriptInterface<ITestbed2ManyParamInterfaceInterface> out_many_param_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for makeJavaManyParamInterface"));
		return nullptr;
	}
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
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jManyParamInterface)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("IManyParamInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jManyParamInterface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_many_param_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> Testbed2DataJavaConverter::getCppInstanceTestbed2ManyParamInterface()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for getCppInstanceTestbed2ManyParamInterface"));
		return nullptr;
	}
	UTestbed2ManyParamInterfaceImplementation* Impl = NewObject<UTestbed2ManyParamInterfaceImplementation>();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITestbed2ManyParamInterfaceInterface>(Impl));
	return wrapped;
}

void Testbed2DataJavaConverter::fillNestedStruct1Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> out_nested_struct1_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillNestedStruct1Interface"));
		return;
	}
	if (!input || !out_nested_struct1_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void Testbed2DataJavaConverter::fillNestedStruct1InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2NestedStruct1InterfaceInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillNestedStruct1InterfaceArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct1Interface(JNIEnv* env, const TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> out_nested_struct1_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for makeJavaNestedStruct1Interface"));
		return nullptr;
	}
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
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jNestedStruct1Interface)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("INestedStruct1Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jNestedStruct1Interface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_nested_struct1_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> Testbed2DataJavaConverter::getCppInstanceTestbed2NestedStruct1Interface()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for getCppInstanceTestbed2NestedStruct1Interface"));
		return nullptr;
	}
	UTestbed2NestedStruct1InterfaceImplementation* Impl = NewObject<UTestbed2NestedStruct1InterfaceImplementation>();
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITestbed2NestedStruct1InterfaceInterface>(Impl));
	return wrapped;
}

void Testbed2DataJavaConverter::fillNestedStruct2Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> out_nested_struct2_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillNestedStruct2Interface"));
		return;
	}
	if (!input || !out_nested_struct2_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void Testbed2DataJavaConverter::fillNestedStruct2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2NestedStruct2InterfaceInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillNestedStruct2InterfaceArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct2Interface(JNIEnv* env, const TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> out_nested_struct2_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for makeJavaNestedStruct2Interface"));
		return nullptr;
	}
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
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jNestedStruct2Interface)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("INestedStruct2Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jNestedStruct2Interface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_nested_struct2_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> Testbed2DataJavaConverter::getCppInstanceTestbed2NestedStruct2Interface()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for getCppInstanceTestbed2NestedStruct2Interface"));
		return nullptr;
	}
	UTestbed2NestedStruct2InterfaceImplementation* Impl = NewObject<UTestbed2NestedStruct2InterfaceImplementation>();
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITestbed2NestedStruct2InterfaceInterface>(Impl));
	return wrapped;
}

void Testbed2DataJavaConverter::fillNestedStruct3Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> out_nested_struct3_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillNestedStruct3Interface"));
		return;
	}
	if (!input || !out_nested_struct3_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void Testbed2DataJavaConverter::fillNestedStruct3InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for fillNestedStruct3InterfaceArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct3Interface(JNIEnv* env, const TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> out_nested_struct3_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for makeJavaNestedStruct3Interface"));
		return nullptr;
	}
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
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jNestedStruct3Interface)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("INestedStruct3Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jNestedStruct3Interface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_nested_struct3_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> Testbed2DataJavaConverter::getCppInstanceTestbed2NestedStruct3Interface()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Warning, TEXT("Testbed2DataJavaConverter cache not initialized for getCppInstanceTestbed2NestedStruct3Interface"));
		return nullptr;
	}
	UTestbed2NestedStruct3InterfaceImplementation* Impl = NewObject<UTestbed2NestedStruct3InterfaceImplementation>();
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITestbed2NestedStruct3InterfaceInterface>(Impl));
	return wrapped;
}

bool Testbed2DataJavaConverter::checkJniErrorOccured(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTestbed2DataJavaConverter_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

void Testbed2DataJavaConverter::cleanJavaReferences()
{
	FScopeLock Lock(&CacheLock);
	CacheData.Reset();
}

TSharedPtr<FTestbed2DataJavaConverterCacheData, ESPMode::ThreadSafe> Testbed2DataJavaConverter::ensureInitialized()
{
	{
		FScopeLock Lock(&CacheLock);
		if (CacheData)
		{
			return CacheData;
		}
	}

	auto NewData = MakeShared<FTestbed2DataJavaConverterCacheData, ESPMode::ThreadSafe>();
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	NewData->jStruct1 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct1");
	static const TCHAR* errorMsgStruct1 = TEXT("failed to get testbed2/testbed2_api/Struct1");
	checkJniErrorOccured(errorMsgStruct1);
	NewData->jStruct2 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct2");
	static const TCHAR* errorMsgStruct2 = TEXT("failed to get testbed2/testbed2_api/Struct2");
	checkJniErrorOccured(errorMsgStruct2);
	NewData->jStruct3 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct3");
	static const TCHAR* errorMsgStruct3 = TEXT("failed to get testbed2/testbed2_api/Struct3");
	checkJniErrorOccured(errorMsgStruct3);
	NewData->jStruct4 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct4");
	static const TCHAR* errorMsgStruct4 = TEXT("failed to get testbed2/testbed2_api/Struct4");
	checkJniErrorOccured(errorMsgStruct4);
	NewData->jNestedStruct1 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/NestedStruct1");
	static const TCHAR* errorMsgNestedStruct1 = TEXT("failed to get testbed2/testbed2_api/NestedStruct1");
	checkJniErrorOccured(errorMsgNestedStruct1);
	NewData->jNestedStruct2 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/NestedStruct2");
	static const TCHAR* errorMsgNestedStruct2 = TEXT("failed to get testbed2/testbed2_api/NestedStruct2");
	checkJniErrorOccured(errorMsgNestedStruct2);
	NewData->jNestedStruct3 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/NestedStruct3");
	static const TCHAR* errorMsgNestedStruct3 = TEXT("failed to get testbed2/testbed2_api/NestedStruct3");
	checkJniErrorOccured(errorMsgNestedStruct3);
	NewData->jEnum1 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum1");
	static const TCHAR* errorMsgEnum1 = TEXT("failed to get testbed2/testbed2_api/Enum1");
	checkJniErrorOccured(errorMsgEnum1);
	NewData->jEnum2 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum2");
	static const TCHAR* errorMsgEnum2 = TEXT("failed to get testbed2/testbed2_api/Enum2");
	checkJniErrorOccured(errorMsgEnum2);
	NewData->jEnum3 = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum3");
	static const TCHAR* errorMsgEnum3 = TEXT("failed to get testbed2/testbed2_api/Enum3");
	checkJniErrorOccured(errorMsgEnum3);
	NewData->jManyParamInterface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/IManyParamInterface");
	static const TCHAR* errorMsgManyParamInterface = TEXT("failed to get testbed2/testbed2_api/IManyParamInterface");
	checkJniErrorOccured(errorMsgManyParamInterface);
	NewData->jNestedStruct1Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/INestedStruct1Interface");
	static const TCHAR* errorMsgNestedStruct1Interface = TEXT("failed to get testbed2/testbed2_api/INestedStruct1Interface");
	checkJniErrorOccured(errorMsgNestedStruct1Interface);
	NewData->jNestedStruct2Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/INestedStruct2Interface");
	static const TCHAR* errorMsgNestedStruct2Interface = TEXT("failed to get testbed2/testbed2_api/INestedStruct2Interface");
	checkJniErrorOccured(errorMsgNestedStruct2Interface);
	NewData->jNestedStruct3Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/INestedStruct3Interface");
	static const TCHAR* errorMsgNestedStruct3Interface = TEXT("failed to get testbed2/testbed2_api/INestedStruct3Interface");
	checkJniErrorOccured(errorMsgNestedStruct3Interface);

	{
		FScopeLock Lock(&CacheLock);
		if (!CacheData)
		{
			CacheData = NewData;
		}
		return CacheData;
	}
}

jmethodID Testbed2DataJavaConverter::getMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jmethodID Testbed2DataJavaConverter::getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetStaticMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jfieldID Testbed2DataJavaConverter::getFieldId(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jfieldID field = env->GetFieldID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return field;
}

#endif
