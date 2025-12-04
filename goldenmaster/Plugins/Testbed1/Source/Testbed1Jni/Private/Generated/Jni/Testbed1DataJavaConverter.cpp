
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

#include "Testbed1/Generated/Jni/Testbed1DataJavaConverter.h"
#include "Testbed1/Generated/Jni/Testbed1JniCache.h"
#include "Testbed1/Generated/api/Testbed1_data.h"
#include "Testbed1/Implementation/Testbed1StructInterface.h"
#include "Testbed1/Implementation/Testbed1StructArrayInterface.h"
#include "Testbed1/Implementation/Testbed1StructArray2Interface.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

DEFINE_LOG_CATEGORY(LogTestbed1DataJavaConverter_JNI);

void Testbed1DataJavaConverter::fillStructBool(JNIEnv* env, jobject input, FTestbed1StructBool& out_struct_bool)
{

	jfieldID jFieldId_field_bool = Testbed1JniCache::javaStructStructBoolFieldBoolFieldId;
	if (jFieldId_field_bool)
	{
		out_struct_bool.fieldBool = env->GetBooleanField(input, jFieldId_field_bool);
		static const TCHAR* errorMsgfieldBool = TEXT("failed when getting the jFieldId_field_bool for out_struct_bool.fieldBool");
		checkJniErrorOccured(errorMsgfieldBool);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_bool field in FTestbed1StructBool not found"));
	}
}

void Testbed1DataJavaConverter::fillStructBoolArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructBool>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct_bool array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct_bool array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStructBool(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed1DataJavaConverter::makeJavaStructBool(JNIEnv* env, const FTestbed1StructBool& in_struct_bool)
{
	jclass javaClass = Testbed1JniCache::javaStructStructBool;
	if (Testbed1JniCache::javaStructStructBoolCtor == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructBool not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed1JniCache::javaStructStructBoolCtor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_bool.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	jfieldID jFieldId_field_bool = Testbed1JniCache::javaStructStructBoolFieldBoolFieldId;
	if (jFieldId_field_bool != nullptr)
	{
		env->SetBooleanField(javaObjInstance, jFieldId_field_bool, in_struct_bool.fieldBool);
		static const TCHAR* errorMsgfieldBoolSet = TEXT("failed when seting field for out_struct_bool.fieldBool");
		checkJniErrorOccured(errorMsgfieldBoolSet);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_bool field in FTestbed1StructBool not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructBoolArray(JNIEnv* env, const TArray<FTestbed1StructBool>& cppArray)
{
	if (Testbed1JniCache::javaStructStructBool == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructBool not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaStructStructBool, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct_bool.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStructBool(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct_bool jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed1DataJavaConverter::fillStructInt(JNIEnv* env, jobject input, FTestbed1StructInt& out_struct_int)
{

	jfieldID jFieldId_field_int = Testbed1JniCache::javaStructStructIntFieldIntFieldId;
	if (jFieldId_field_int)
	{
		out_struct_int.fieldInt = env->GetIntField(input, jFieldId_field_int);
		static const TCHAR* errorMsgfieldInt = TEXT("failed when getting the jFieldId_field_int for out_struct_int.fieldInt");
		checkJniErrorOccured(errorMsgfieldInt);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_int field in FTestbed1StructInt not found"));
	}
}

void Testbed1DataJavaConverter::fillStructIntArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructInt>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct_int array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct_int array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStructInt(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed1DataJavaConverter::makeJavaStructInt(JNIEnv* env, const FTestbed1StructInt& in_struct_int)
{
	jclass javaClass = Testbed1JniCache::javaStructStructInt;
	if (Testbed1JniCache::javaStructStructIntCtor == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructInt not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed1JniCache::javaStructStructIntCtor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_int.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	jfieldID jFieldId_field_int = Testbed1JniCache::javaStructStructIntFieldIntFieldId;
	if (jFieldId_field_int != nullptr)
	{
		env->SetIntField(javaObjInstance, jFieldId_field_int, in_struct_int.fieldInt);
		static const TCHAR* errorMsgfieldIntSet = TEXT("failed when seting field for out_struct_int.fieldInt");
		checkJniErrorOccured(errorMsgfieldIntSet);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_int field in FTestbed1StructInt not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructIntArray(JNIEnv* env, const TArray<FTestbed1StructInt>& cppArray)
{
	if (Testbed1JniCache::javaStructStructInt == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructInt not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaStructStructInt, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct_int.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStructInt(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct_int jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed1DataJavaConverter::fillStructFloat(JNIEnv* env, jobject input, FTestbed1StructFloat& out_struct_float)
{

	jfieldID jFieldId_field_float = Testbed1JniCache::javaStructStructFloatFieldFloatFieldId;
	if (jFieldId_field_float)
	{
		out_struct_float.fieldFloat = env->GetFloatField(input, jFieldId_field_float);
		static const TCHAR* errorMsgfieldFloat = TEXT("failed when getting the jFieldId_field_float for out_struct_float.fieldFloat");
		checkJniErrorOccured(errorMsgfieldFloat);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_float field in FTestbed1StructFloat not found"));
	}
}

void Testbed1DataJavaConverter::fillStructFloatArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructFloat>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct_float array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct_float array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStructFloat(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed1DataJavaConverter::makeJavaStructFloat(JNIEnv* env, const FTestbed1StructFloat& in_struct_float)
{
	jclass javaClass = Testbed1JniCache::javaStructStructFloat;
	if (Testbed1JniCache::javaStructStructFloatCtor == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructFloat not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed1JniCache::javaStructStructFloatCtor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_float.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	jfieldID jFieldId_field_float = Testbed1JniCache::javaStructStructFloatFieldFloatFieldId;
	if (jFieldId_field_float != nullptr)
	{
		env->SetFloatField(javaObjInstance, jFieldId_field_float, in_struct_float.fieldFloat);
		static const TCHAR* errorMsgfieldFloatSet = TEXT("failed when seting field for out_struct_float.fieldFloat");
		checkJniErrorOccured(errorMsgfieldFloatSet);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_float field in FTestbed1StructFloat not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructFloatArray(JNIEnv* env, const TArray<FTestbed1StructFloat>& cppArray)
{
	if (Testbed1JniCache::javaStructStructFloat == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructFloat not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaStructStructFloat, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct_float.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStructFloat(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct_float jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed1DataJavaConverter::fillStructString(JNIEnv* env, jobject input, FTestbed1StructString& out_struct_string)
{

	jfieldID jFieldId_field_string = Testbed1JniCache::javaStructStructStringFieldStringFieldId;
	if (jFieldId_field_string)
	{
		jstring field_string_value = (jstring)env->GetObjectField(input, jFieldId_field_string);
		static const TCHAR* errorMsgfieldString = TEXT("failed when getting the jFieldId_field_string for out_struct_string.fieldString");
		checkJniErrorOccured(errorMsgfieldString);
		out_struct_string.fieldString = FJavaHelper::FStringFromLocalRef(env, field_string_value);
		static const TCHAR* errorMsgfieldStringStringConv = TEXT("failed when converting from jstring for out_struct_string.fieldString");
		checkJniErrorOccured(errorMsgfieldStringStringConv);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_string field in FTestbed1StructString not found"));
	}
}

void Testbed1DataJavaConverter::fillStructStringArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructString>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct_string array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct_string array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStructString(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed1DataJavaConverter::makeJavaStructString(JNIEnv* env, const FTestbed1StructString& in_struct_string)
{
	jclass javaClass = Testbed1JniCache::javaStructStructString;
	if (Testbed1JniCache::javaStructStructStringCtor == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructString not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed1JniCache::javaStructStructStringCtor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_string.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	jfieldID jFieldId_field_string = Testbed1JniCache::javaStructStructStringFieldStringFieldId;
	if (jFieldId_field_string != nullptr)
	{
		auto l_fieldStringWrapper = FJavaHelper::ToJavaString(env, in_struct_string.fieldString);
		static const TCHAR* errorMsgfieldStringStr = TEXT("failed when converting to jstring out_struct_string.fieldString");
		checkJniErrorOccured(errorMsgfieldStringStr);
		jstring l_fieldString = static_cast<jstring>(env->NewLocalRef(*l_fieldStringWrapper));
		env->SetObjectField(javaObjInstance, jFieldId_field_string, l_fieldString);
		static const TCHAR* errorMsgfieldStringSet = TEXT("failed when seting field for out_struct_string.fieldString");
		checkJniErrorOccured(errorMsgfieldStringSet);
		// in UE 5.6 no need for new local ref
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_string field in FTestbed1StructString not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructStringArray(JNIEnv* env, const TArray<FTestbed1StructString>& cppArray)
{
	if (Testbed1JniCache::javaStructStructString == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructString not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaStructStructString, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct_string.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStructString(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct_string jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed1DataJavaConverter::fillStructStruct(JNIEnv* env, jobject input, FTestbed1StructStruct& out_struct_struct)
{

	jfieldID jFieldId_field_string = Testbed1JniCache::javaStructStructStructFieldStringFieldId;
	if (jFieldId_field_string)
	{
		jobject field_string_value = env->GetObjectField(input, jFieldId_field_string);
		static const TCHAR* errorMsgfieldString = TEXT("failed when getting the jFieldId_field_string for out_struct_struct.fieldString");
		checkJniErrorOccured(errorMsgfieldString);
		fillStructString(env, field_string_value, out_struct_struct.fieldString);
		env->DeleteLocalRef(field_string_value);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_string field in FTestbed1StructStruct not found"));
	}
}

void Testbed1DataJavaConverter::fillStructStructArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructStruct>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct_struct array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct_struct array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStructStruct(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed1DataJavaConverter::makeJavaStructStruct(JNIEnv* env, const FTestbed1StructStruct& in_struct_struct)
{
	jclass javaClass = Testbed1JniCache::javaStructStructStruct;
	if (Testbed1JniCache::javaStructStructStructCtor == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructStruct not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed1JniCache::javaStructStructStructCtor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_struct.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	jfieldID jFieldId_field_string = Testbed1JniCache::javaStructStructStructFieldStringFieldId;
	if (jFieldId_field_string != nullptr)
	{
		jobject l_fieldString = makeJavaStructString(env, in_struct_struct.fieldString);
		env->SetObjectField(javaObjInstance, jFieldId_field_string, l_fieldString);
		static const TCHAR* errorMsgfieldStringSet = TEXT("failed when seting field for out_struct_struct.fieldString");
		checkJniErrorOccured(errorMsgfieldStringSet);
		env->DeleteLocalRef(l_fieldString);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_string field in FTestbed1StructStruct not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructStructArray(JNIEnv* env, const TArray<FTestbed1StructStruct>& cppArray)
{
	if (Testbed1JniCache::javaStructStructStruct == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructStruct not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaStructStructStruct, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct_struct.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStructStruct(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct_struct jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed1DataJavaConverter::fillStructEnum(JNIEnv* env, jobject input, FTestbed1StructEnum& out_struct_enum)
{

	jfieldID jFieldId_field_enum = Testbed1JniCache::javaStructStructEnumFieldEnumFieldId;
	if (jFieldId_field_enum)
	{
		jobject field_enum_value = env->GetObjectField(input, jFieldId_field_enum);
		static const TCHAR* errorMsgfieldEnum = TEXT("failed when getting the jFieldId_field_enum for out_struct_enum.fieldEnum");
		checkJniErrorOccured(errorMsgfieldEnum);
		out_struct_enum.fieldEnum = getEnum0Value(env, field_enum_value);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_enum field in FTestbed1StructEnum not found"));
	}
}

void Testbed1DataJavaConverter::fillStructEnumArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructEnum>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct_enum array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct_enum array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStructEnum(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed1DataJavaConverter::makeJavaStructEnum(JNIEnv* env, const FTestbed1StructEnum& in_struct_enum)
{
	jclass javaClass = Testbed1JniCache::javaStructStructEnum;
	if (Testbed1JniCache::javaStructStructEnumCtor == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructEnum not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed1JniCache::javaStructStructEnumCtor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_enum.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	jfieldID jFieldId_field_enum = Testbed1JniCache::javaStructStructEnumFieldEnumFieldId;
	if (jFieldId_field_enum != nullptr)
	{
		jobject l_fieldEnum = makeJavaEnum0(env, in_struct_enum.fieldEnum);
		env->SetObjectField(javaObjInstance, jFieldId_field_enum, l_fieldEnum);
		static const TCHAR* errorMsgfieldEnumSet = TEXT("failed when seting field for out_struct_enum.fieldEnum");
		checkJniErrorOccured(errorMsgfieldEnumSet);
		env->DeleteLocalRef(l_fieldEnum);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_enum field in FTestbed1StructEnum not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructEnumArray(JNIEnv* env, const TArray<FTestbed1StructEnum>& cppArray)
{
	if (Testbed1JniCache::javaStructStructEnum == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructEnum not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaStructStructEnum, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct_enum.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStructEnum(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct_enum jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed1DataJavaConverter::fillStructBoolWithArray(JNIEnv* env, jobject input, FTestbed1StructBoolWithArray& out_struct_bool_with_array)
{

	jfieldID jFieldId_field_bool = Testbed1JniCache::javaStructStructBoolWithArrayFieldBoolFieldId;
	if (jFieldId_field_bool)
	{
		jbooleanArray field_bool_value = (jbooleanArray)env->GetObjectField(input, jFieldId_field_bool);
		static const TCHAR* errorMsgfieldBoolField = TEXT("failed when getting the jFieldId_field_bool for out_struct_bool_with_array.fieldBool");
		checkJniErrorOccured(errorMsgfieldBoolField);
		jsize lenfield_bool = env->GetArrayLength(field_bool_value);
		static const TCHAR* errorMsgfieldBoolLen = TEXT("failed when getting lengt of a java array out_struct_bool_with_array.fieldBool");
		checkJniErrorOccured(errorMsgfieldBoolLen);
		out_struct_bool_with_array.fieldBool.Reserve(lenfield_bool);
		TArray<jboolean> Temp;
		Temp.SetNumUninitialized(lenfield_bool);
		env->GetBooleanArrayRegion(field_bool_value, 0, lenfield_bool, Temp.GetData());
		static const TCHAR* errorMsgfieldBool = TEXT("failed when getting a java array region for out_struct_bool_with_array.fieldBool");
		checkJniErrorOccured(errorMsgfieldBool);
		for (int i = 0; i < lenfield_bool; i++)
		{
			out_struct_bool_with_array.fieldBool.Add(Temp[i] == JNI_TRUE);
		}
		env->DeleteLocalRef(field_bool_value);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_bool field in FTestbed1StructBoolWithArray not found"));
	}
}

void Testbed1DataJavaConverter::fillStructBoolWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructBoolWithArray>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct_bool_with_array array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct_bool_with_array array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStructBoolWithArray(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed1DataJavaConverter::makeJavaStructBoolWithArray(JNIEnv* env, const FTestbed1StructBoolWithArray& in_struct_bool_with_array)
{
	jclass javaClass = Testbed1JniCache::javaStructStructBoolWithArray;
	if (Testbed1JniCache::javaStructStructBoolWithArrayCtor == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructBoolWithArray not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed1JniCache::javaStructStructBoolWithArrayCtor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_bool_with_array.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	jfieldID jFieldId_field_bool = Testbed1JniCache::javaStructStructBoolWithArrayFieldBoolFieldId;
	if (jFieldId_field_bool != nullptr)
	{
		auto lenfield_bool = in_struct_bool_with_array.fieldBool.Num();
		TArray<jboolean> Temp;
		Temp.SetNumUninitialized(lenfield_bool);
		jbooleanArray l_fieldBool = env->NewBooleanArray(lenfield_bool);
		static const TCHAR* errorMsgfieldBoolAlloc = TEXT("failed when allocating jarray out_struct_bool_with_array.fieldBool");
		if (!checkJniErrorOccured(errorMsgfieldBoolAlloc))
		{
			for (int i = 0; i < lenfield_bool; i++)
			{
				Temp[i] = in_struct_bool_with_array.fieldBool[i] ? JNI_TRUE : JNI_FALSE;
			}
			env->SetBooleanArrayRegion(l_fieldBool, 0, lenfield_bool, Temp.GetData());
			static const TCHAR* errorMsgfieldBool = TEXT("failed when seting jarray region for out_struct_bool_with_array.fieldBool");
			checkJniErrorOccured(errorMsgfieldBool);
		}
		env->SetObjectField(javaObjInstance, jFieldId_field_bool, l_fieldBool);
		static const TCHAR* errorMsgfieldBoolSet = TEXT("failed when seting field for out_struct_bool_with_array.fieldBool");
		checkJniErrorOccured(errorMsgfieldBoolSet);
		env->DeleteLocalRef(l_fieldBool);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_bool field in FTestbed1StructBoolWithArray not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructBoolWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructBoolWithArray>& cppArray)
{
	if (Testbed1JniCache::javaStructStructBoolWithArray == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructBoolWithArray not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaStructStructBoolWithArray, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct_bool_with_array.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStructBoolWithArray(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct_bool_with_array jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed1DataJavaConverter::fillStructIntWithArray(JNIEnv* env, jobject input, FTestbed1StructIntWithArray& out_struct_int_with_array)
{

	jfieldID jFieldId_field_int = Testbed1JniCache::javaStructStructIntWithArrayFieldIntFieldId;
	if (jFieldId_field_int)
	{
		jintArray field_int_value = (jintArray)env->GetObjectField(input, jFieldId_field_int);
		static const TCHAR* errorMsgfieldIntField = TEXT("failed when getting the jFieldId_field_int for out_struct_int_with_array.fieldInt");
		checkJniErrorOccured(errorMsgfieldIntField);
		jsize lenfield_int = env->GetArrayLength(field_int_value);
		static const TCHAR* errorMsgfieldIntLen = TEXT("failed when getting lengt of a java array out_struct_int_with_array.fieldInt");
		checkJniErrorOccured(errorMsgfieldIntLen);
		out_struct_int_with_array.fieldInt.AddUninitialized(lenfield_int);
		env->GetIntArrayRegion(field_int_value, 0, lenfield_int, out_struct_int_with_array.fieldInt.GetData());
		static const TCHAR* errorMsgfieldInt = TEXT("failed when getting a java array region for out_struct_int_with_array.fieldInt");
		checkJniErrorOccured(errorMsgfieldInt);
		env->DeleteLocalRef(field_int_value);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_int field in FTestbed1StructIntWithArray not found"));
	}
}

void Testbed1DataJavaConverter::fillStructIntWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructIntWithArray>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct_int_with_array array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct_int_with_array array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStructIntWithArray(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed1DataJavaConverter::makeJavaStructIntWithArray(JNIEnv* env, const FTestbed1StructIntWithArray& in_struct_int_with_array)
{
	jclass javaClass = Testbed1JniCache::javaStructStructIntWithArray;
	if (Testbed1JniCache::javaStructStructIntWithArrayCtor == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructIntWithArray not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed1JniCache::javaStructStructIntWithArrayCtor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_int_with_array.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	jfieldID jFieldId_field_int = Testbed1JniCache::javaStructStructIntWithArrayFieldIntFieldId;
	if (jFieldId_field_int != nullptr)
	{
		auto lenfield_int = in_struct_int_with_array.fieldInt.Num();
		jintArray l_fieldInt = env->NewIntArray(lenfield_int);
		static const TCHAR* errorMsgfieldIntAlloc = TEXT("failed when allocating jarray out_struct_int_with_array.fieldInt");
		if (!checkJniErrorOccured(errorMsgfieldIntAlloc))
		{
			env->SetIntArrayRegion(l_fieldInt, 0, lenfield_int, in_struct_int_with_array.fieldInt.GetData());
			static const TCHAR* errorMsgfieldInt = TEXT("failed when seting jarray region for out_struct_int_with_array.fieldInt");
			checkJniErrorOccured(errorMsgfieldInt);
		};
		env->SetObjectField(javaObjInstance, jFieldId_field_int, l_fieldInt);
		static const TCHAR* errorMsgfieldIntSet = TEXT("failed when seting field for out_struct_int_with_array.fieldInt");
		checkJniErrorOccured(errorMsgfieldIntSet);
		env->DeleteLocalRef(l_fieldInt);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_int field in FTestbed1StructIntWithArray not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructIntWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructIntWithArray>& cppArray)
{
	if (Testbed1JniCache::javaStructStructIntWithArray == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructIntWithArray not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaStructStructIntWithArray, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct_int_with_array.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStructIntWithArray(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct_int_with_array jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed1DataJavaConverter::fillStructFloatWithArray(JNIEnv* env, jobject input, FTestbed1StructFloatWithArray& out_struct_float_with_array)
{

	jfieldID jFieldId_field_float = Testbed1JniCache::javaStructStructFloatWithArrayFieldFloatFieldId;
	if (jFieldId_field_float)
	{
		jfloatArray field_float_value = (jfloatArray)env->GetObjectField(input, jFieldId_field_float);
		static const TCHAR* errorMsgfieldFloatField = TEXT("failed when getting the jFieldId_field_float for out_struct_float_with_array.fieldFloat");
		checkJniErrorOccured(errorMsgfieldFloatField);
		jsize lenfield_float = env->GetArrayLength(field_float_value);
		static const TCHAR* errorMsgfieldFloatLen = TEXT("failed when getting lengt of a java array out_struct_float_with_array.fieldFloat");
		checkJniErrorOccured(errorMsgfieldFloatLen);
		out_struct_float_with_array.fieldFloat.AddUninitialized(lenfield_float);
		env->GetFloatArrayRegion(field_float_value, 0, lenfield_float, out_struct_float_with_array.fieldFloat.GetData());
		static const TCHAR* errorMsgfieldFloat = TEXT("failed when getting a java array region for out_struct_float_with_array.fieldFloat");
		checkJniErrorOccured(errorMsgfieldFloat);
		env->DeleteLocalRef(field_float_value);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_float field in FTestbed1StructFloatWithArray not found"));
	}
}

void Testbed1DataJavaConverter::fillStructFloatWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructFloatWithArray>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct_float_with_array array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct_float_with_array array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStructFloatWithArray(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed1DataJavaConverter::makeJavaStructFloatWithArray(JNIEnv* env, const FTestbed1StructFloatWithArray& in_struct_float_with_array)
{
	jclass javaClass = Testbed1JniCache::javaStructStructFloatWithArray;
	if (Testbed1JniCache::javaStructStructFloatWithArrayCtor == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructFloatWithArray not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed1JniCache::javaStructStructFloatWithArrayCtor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_float_with_array.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	jfieldID jFieldId_field_float = Testbed1JniCache::javaStructStructFloatWithArrayFieldFloatFieldId;
	if (jFieldId_field_float != nullptr)
	{
		auto lenfield_float = in_struct_float_with_array.fieldFloat.Num();
		jfloatArray l_fieldFloat = env->NewFloatArray(lenfield_float);
		static const TCHAR* errorMsgfieldFloatAlloc = TEXT("failed when allocating jarray out_struct_float_with_array.fieldFloat");
		if (!checkJniErrorOccured(errorMsgfieldFloatAlloc))
		{
			env->SetFloatArrayRegion(l_fieldFloat, 0, lenfield_float, in_struct_float_with_array.fieldFloat.GetData());
			static const TCHAR* errorMsgfieldFloat = TEXT("failed when seting jarray region for out_struct_float_with_array.fieldFloat");
			checkJniErrorOccured(errorMsgfieldFloat);
		};
		env->SetObjectField(javaObjInstance, jFieldId_field_float, l_fieldFloat);
		static const TCHAR* errorMsgfieldFloatSet = TEXT("failed when seting field for out_struct_float_with_array.fieldFloat");
		checkJniErrorOccured(errorMsgfieldFloatSet);
		env->DeleteLocalRef(l_fieldFloat);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_float field in FTestbed1StructFloatWithArray not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructFloatWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructFloatWithArray>& cppArray)
{
	if (Testbed1JniCache::javaStructStructFloatWithArray == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructFloatWithArray not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaStructStructFloatWithArray, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct_float_with_array.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStructFloatWithArray(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct_float_with_array jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed1DataJavaConverter::fillStructStringWithArray(JNIEnv* env, jobject input, FTestbed1StructStringWithArray& out_struct_string_with_array)
{

	jfieldID jFieldId_field_string = Testbed1JniCache::javaStructStructStringWithArrayFieldStringFieldId;
	if (jFieldId_field_string)
	{
		jobjectArray field_string_value = (jobjectArray)env->GetObjectField(input, jFieldId_field_string);
		static const TCHAR* errorMsgfieldStringField = TEXT("failed when getting the jFieldId_field_string for out_struct_string_with_array.fieldString");
		checkJniErrorOccured(errorMsgfieldStringField);
		out_struct_string_with_array.fieldString = FJavaHelper::ObjectArrayToFStringTArray(env, field_string_value);
		static const TCHAR* errorMsgfieldString = TEXT("failed when converting from jstring array for out_struct_string_with_array.fieldString");
		checkJniErrorOccured(errorMsgfieldString);
		env->DeleteLocalRef(field_string_value);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_string field in FTestbed1StructStringWithArray not found"));
	}
}

void Testbed1DataJavaConverter::fillStructStringWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructStringWithArray>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct_string_with_array array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct_string_with_array array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStructStringWithArray(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed1DataJavaConverter::makeJavaStructStringWithArray(JNIEnv* env, const FTestbed1StructStringWithArray& in_struct_string_with_array)
{
	jclass javaClass = Testbed1JniCache::javaStructStructStringWithArray;
	if (Testbed1JniCache::javaStructStructStringWithArrayCtor == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructStringWithArray not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed1JniCache::javaStructStructStringWithArrayCtor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_string_with_array.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	jfieldID jFieldId_field_string = Testbed1JniCache::javaStructStructStringWithArrayFieldStringFieldId;
	if (jFieldId_field_string != nullptr)
	{
		TArray<FStringView> fieldStringStringViews;
		fieldStringStringViews.Reserve(in_struct_string_with_array.fieldString.Num());
		for (const FString& Str : in_struct_string_with_array.fieldString)
		{
			fieldStringStringViews.Add(FStringView(Str));
		}
		auto l_fieldStringWrapper = FJavaHelper::ToJavaStringArray(env, fieldStringStringViews);
		static const TCHAR* errorMsgfieldStringField = TEXT("failed when creating an converting to a jstring for out_struct_string_with_array.fieldString");
		checkJniErrorOccured(errorMsgfieldStringField);
		jobjectArray l_fieldString = static_cast<jobjectArray>(env->NewLocalRef(*l_fieldStringWrapper));
		env->SetObjectField(javaObjInstance, jFieldId_field_string, l_fieldString);
		static const TCHAR* errorMsgfieldStringSet = TEXT("failed when seting field for out_struct_string_with_array.fieldString");
		checkJniErrorOccured(errorMsgfieldStringSet);
		env->DeleteLocalRef(l_fieldString);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_string field in FTestbed1StructStringWithArray not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructStringWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructStringWithArray>& cppArray)
{
	if (Testbed1JniCache::javaStructStructStringWithArray == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructStringWithArray not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaStructStructStringWithArray, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct_string_with_array.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStructStringWithArray(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct_string_with_array jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed1DataJavaConverter::fillStructStructWithArray(JNIEnv* env, jobject input, FTestbed1StructStructWithArray& out_struct_struct_with_array)
{

	jfieldID jFieldId_field_struct = Testbed1JniCache::javaStructStructStructWithArrayFieldStructFieldId;
	if (jFieldId_field_struct)
	{
		jobjectArray field_struct_value = (jobjectArray)env->GetObjectField(input, jFieldId_field_struct);
		static const TCHAR* errorMsgfieldStructField = TEXT("failed when getting the jFieldId_field_struct for out_struct_struct_with_array.fieldStruct");
		checkJniErrorOccured(errorMsgfieldStructField);
		fillStructStringWithArrayArray(env, field_struct_value, out_struct_struct_with_array.fieldStruct);
		env->DeleteLocalRef(field_struct_value);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_struct field in FTestbed1StructStructWithArray not found"));
	}
}

void Testbed1DataJavaConverter::fillStructStructWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructStructWithArray>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct_struct_with_array array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct_struct_with_array array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStructStructWithArray(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed1DataJavaConverter::makeJavaStructStructWithArray(JNIEnv* env, const FTestbed1StructStructWithArray& in_struct_struct_with_array)
{
	jclass javaClass = Testbed1JniCache::javaStructStructStructWithArray;
	if (Testbed1JniCache::javaStructStructStructWithArrayCtor == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructStructWithArray not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed1JniCache::javaStructStructStructWithArrayCtor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_struct_with_array.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	jfieldID jFieldId_field_struct = Testbed1JniCache::javaStructStructStructWithArrayFieldStructFieldId;
	if (jFieldId_field_struct != nullptr)
	{
		jobjectArray l_fieldStruct = makeJavaStructStringWithArrayArray(env, in_struct_struct_with_array.fieldStruct);
		env->SetObjectField(javaObjInstance, jFieldId_field_struct, l_fieldStruct);
		static const TCHAR* errorMsgfieldStructSet = TEXT("failed when seting field for out_struct_struct_with_array.fieldStruct");
		checkJniErrorOccured(errorMsgfieldStructSet);
		env->DeleteLocalRef(l_fieldStruct);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_struct field in FTestbed1StructStructWithArray not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructStructWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructStructWithArray>& cppArray)
{
	if (Testbed1JniCache::javaStructStructStructWithArray == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructStructWithArray not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaStructStructStructWithArray, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct_struct_with_array.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStructStructWithArray(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct_struct_with_array jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed1DataJavaConverter::fillStructEnumWithArray(JNIEnv* env, jobject input, FTestbed1StructEnumWithArray& out_struct_enum_with_array)
{

	jfieldID jFieldId_field_enum = Testbed1JniCache::javaStructStructEnumWithArrayFieldEnumFieldId;
	if (jFieldId_field_enum)
	{
		jobjectArray field_enum_value = (jobjectArray)env->GetObjectField(input, jFieldId_field_enum);
		static const TCHAR* errorMsgfieldEnumField = TEXT("failed when getting the jFieldId_field_enum for out_struct_enum_with_array.fieldEnum");
		checkJniErrorOccured(errorMsgfieldEnumField);
		fillEnum0Array(env, field_enum_value, out_struct_enum_with_array.fieldEnum);
		env->DeleteLocalRef(field_enum_value);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_enum field in FTestbed1StructEnumWithArray not found"));
	}
}

void Testbed1DataJavaConverter::fillStructEnumWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructEnumWithArray>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_struct_enum_with_array array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_struct_enum_with_array array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillStructEnumWithArray(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject Testbed1DataJavaConverter::makeJavaStructEnumWithArray(JNIEnv* env, const FTestbed1StructEnumWithArray& in_struct_enum_with_array)
{
	jclass javaClass = Testbed1JniCache::javaStructStructEnumWithArray;
	if (Testbed1JniCache::javaStructStructEnumWithArrayCtor == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructEnumWithArray not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, Testbed1JniCache::javaStructStructEnumWithArrayCtor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_enum_with_array.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	jfieldID jFieldId_field_enum = Testbed1JniCache::javaStructStructEnumWithArrayFieldEnumFieldId;
	if (jFieldId_field_enum != nullptr)
	{
		jobjectArray l_fieldEnum = makeJavaEnum0Array(env, in_struct_enum_with_array.fieldEnum);
		env->SetObjectField(javaObjInstance, jFieldId_field_enum, l_fieldEnum);
		static const TCHAR* errorMsgfieldEnumSet = TEXT("failed when seting field for out_struct_enum_with_array.fieldEnum");
		checkJniErrorOccured(errorMsgfieldEnumSet);
		env->DeleteLocalRef(l_fieldEnum);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_enum field in FTestbed1StructEnumWithArray not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructEnumWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructEnumWithArray>& cppArray)
{
	if (Testbed1JniCache::javaStructStructEnumWithArray == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructEnumWithArray not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaStructStructEnumWithArray, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_struct_enum_with_array.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaStructEnumWithArray(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_struct_enum_with_array jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

void Testbed1DataJavaConverter::fillEnum0Array(JNIEnv* env, jobjectArray input, TArray<ETestbed1Enum0>& out_array)
{
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of Enum0 array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of Enum0 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			out_array.Add(getEnum0Value(env, element));
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

ETestbed1Enum0 Testbed1DataJavaConverter::getEnum0Value(JNIEnv* env, jobject input)
{
	ETestbed1Enum0 cppEnumValue = ETestbed1Enum0::T1E0_Value0;

	if (Testbed1JniCache::javaEnumEnum0GetValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, Testbed1JniCache::javaEnumEnum0GetValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum0.");
		if (!checkJniErrorOccured(errorMsg))
		{
			UTestbed1Library::toTestbed1Enum0(cppEnumValue, int_value);
		}
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("Enum Enum0::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray Testbed1DataJavaConverter::makeJavaEnum0Array(JNIEnv* env, const TArray<ETestbed1Enum0>& cppArray)
{
	if (Testbed1JniCache::javaEnumEnum0 == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("Enum Enum0 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaEnumEnum0, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate Enum0 jarray.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum0(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of Enum0 array.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

jobject Testbed1DataJavaConverter::makeJavaEnum0(JNIEnv* env, ETestbed1Enum0 value)
{
	if (Testbed1JniCache::javaEnumEnum0FromValueMethodId == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("Enum Enum0::fromValue not found"));
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(Testbed1JniCache::javaEnumEnum0, Testbed1JniCache::javaEnumEnum0FromValueMethodId, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum0.");
	checkJniErrorOccured(errorMsg);
	return javaObj;
}

void Testbed1DataJavaConverter::fillStructInterface(JNIEnv* env, jobject input, TScriptInterface<ITestbed1StructInterfaceInterface> out_struct_interface)
{
	if (!input || !out_struct_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void Testbed1DataJavaConverter::fillStructInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed1StructInterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject Testbed1DataJavaConverter::makeJavaStructInterface(JNIEnv* env, const TScriptInterface<ITestbed1StructInterfaceInterface> out_struct_interface)
{
	if (!out_struct_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed1StructInterfaceInterface>>& cppArray)
{
	if (!Testbed1JniCache::javaClassStructInterface)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("IStructInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaClassStructInterface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_struct_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITestbed1StructInterfaceInterface> Testbed1DataJavaConverter::getCppInstanceTestbed1StructInterface()
{
	UTestbed1StructInterfaceImplementation* Impl = NewObject<UTestbed1StructInterfaceImplementation>();
	TScriptInterface<ITestbed1StructInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITestbed1StructInterfaceInterface>(Impl));
	return wrapped;
}

void Testbed1DataJavaConverter::fillStructArrayInterface(JNIEnv* env, jobject input, TScriptInterface<ITestbed1StructArrayInterfaceInterface> out_struct_array_interface)
{
	if (!input || !out_struct_array_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void Testbed1DataJavaConverter::fillStructArrayInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed1StructArrayInterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject Testbed1DataJavaConverter::makeJavaStructArrayInterface(JNIEnv* env, const TScriptInterface<ITestbed1StructArrayInterfaceInterface> out_struct_array_interface)
{
	if (!out_struct_array_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructArrayInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed1StructArrayInterfaceInterface>>& cppArray)
{
	if (!Testbed1JniCache::javaClassStructArrayInterface)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("IStructArrayInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaClassStructArrayInterface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_struct_array_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> Testbed1DataJavaConverter::getCppInstanceTestbed1StructArrayInterface()
{
	UTestbed1StructArrayInterfaceImplementation* Impl = NewObject<UTestbed1StructArrayInterfaceImplementation>();
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITestbed1StructArrayInterfaceInterface>(Impl));
	return wrapped;
}

void Testbed1DataJavaConverter::fillStructArray2Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed1StructArray2InterfaceInterface> out_struct_array2_interface)
{
	if (!input || !out_struct_array2_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void Testbed1DataJavaConverter::fillStructArray2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed1StructArray2InterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject Testbed1DataJavaConverter::makeJavaStructArray2Interface(JNIEnv* env, const TScriptInterface<ITestbed1StructArray2InterfaceInterface> out_struct_array2_interface)
{
	if (!out_struct_array2_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructArray2InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed1StructArray2InterfaceInterface>>& cppArray)
{
	if (!Testbed1JniCache::javaClassStructArray2Interface)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("IStructArray2Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Testbed1JniCache::javaClassStructArray2Interface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_struct_array2_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITestbed1StructArray2InterfaceInterface> Testbed1DataJavaConverter::getCppInstanceTestbed1StructArray2Interface()
{
	UTestbed1StructArray2InterfaceImplementation* Impl = NewObject<UTestbed1StructArray2InterfaceImplementation>();
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITestbed1StructArray2InterfaceInterface>(Impl));
	return wrapped;
}

bool Testbed1DataJavaConverter::checkJniErrorOccured(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

#endif
