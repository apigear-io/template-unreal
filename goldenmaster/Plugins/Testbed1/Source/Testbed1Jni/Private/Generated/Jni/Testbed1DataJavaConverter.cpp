
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

jclass Testbed1DataJavaConverter::jStructBool = nullptr;

void Testbed1DataJavaConverter::fillStructBool(JNIEnv* env, jobject input, FTestbed1StructBool& out_struct_bool)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfieldBool = TEXT("failed when trying to field fieldBool Z for FTestbed1StructBool");
	static const jfieldID jFieldId_field_bool = getFieldId(jStructBool, "fieldBool", "Z", errorMsgFindfieldBool);

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
	ensureInitialized();
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
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct_bool.");
	static const jmethodID ctor = getMethod(jStructBool, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr )
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStructBool, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_bool.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfieldBool = TEXT("failed when trying to field fieldBool Z for FTestbed1StructBool");
	static const jfieldID jFieldId_field_bool = getFieldId(jStructBool, "fieldBool", "Z", errorMsgFindfieldBool);

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
	ensureInitialized();
	if (jStructBool == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructBool not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructBool, nullptr);
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

jclass Testbed1DataJavaConverter::jStructInt = nullptr;

void Testbed1DataJavaConverter::fillStructInt(JNIEnv* env, jobject input, FTestbed1StructInt& out_struct_int)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfieldInt = TEXT("failed when trying to field fieldInt I for FTestbed1StructInt");
	static const jfieldID jFieldId_field_int = getFieldId(jStructInt, "fieldInt", "I", errorMsgFindfieldInt);

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
	ensureInitialized();
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
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct_int.");
	static const jmethodID ctor = getMethod(jStructInt, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr )
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStructInt, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_int.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfieldInt = TEXT("failed when trying to field fieldInt I for FTestbed1StructInt");
	static const jfieldID jFieldId_field_int = getFieldId(jStructInt, "fieldInt", "I", errorMsgFindfieldInt);

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
	ensureInitialized();
	if (jStructInt == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructInt not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructInt, nullptr);
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

jclass Testbed1DataJavaConverter::jStructFloat = nullptr;

void Testbed1DataJavaConverter::fillStructFloat(JNIEnv* env, jobject input, FTestbed1StructFloat& out_struct_float)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfieldFloat = TEXT("failed when trying to field fieldFloat F for FTestbed1StructFloat");
	static const jfieldID jFieldId_field_float = getFieldId(jStructFloat, "fieldFloat", "F", errorMsgFindfieldFloat);

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
	ensureInitialized();
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
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct_float.");
	static const jmethodID ctor = getMethod(jStructFloat, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr )
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStructFloat, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_float.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfieldFloat = TEXT("failed when trying to field fieldFloat F for FTestbed1StructFloat");
	static const jfieldID jFieldId_field_float = getFieldId(jStructFloat, "fieldFloat", "F", errorMsgFindfieldFloat);

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
	ensureInitialized();
	if (jStructFloat == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructFloat not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructFloat, nullptr);
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

jclass Testbed1DataJavaConverter::jStructString = nullptr;

void Testbed1DataJavaConverter::fillStructString(JNIEnv* env, jobject input, FTestbed1StructString& out_struct_string)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfieldString = TEXT("failed when trying to field fieldString Ljava/lang/String; for FTestbed1StructString");
	static const jfieldID jFieldId_field_string = getFieldId(jStructString, "fieldString", "Ljava/lang/String;", errorMsgFindfieldString);

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
	ensureInitialized();
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
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct_string.");
	static const jmethodID ctor = getMethod(jStructString, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr )
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStructString, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_string.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfieldString = TEXT("failed when trying to field fieldString Ljava/lang/String; for FTestbed1StructString");
	static const jfieldID jFieldId_field_string = getFieldId(jStructString, "fieldString", "Ljava/lang/String;", errorMsgFindfieldString);

	if (jFieldId_field_string != nullptr)
	{
		auto l_fieldStringWrapper = FJavaHelper::ToJavaString(env, in_struct_string.fieldString);
		static const TCHAR* errorMsgfieldStringStr = TEXT("failed when converting to jstring out_struct_string.fieldString");
		checkJniErrorOccured(errorMsgfieldStringStr);
		jstring l_fieldString = static_cast<jstring>(env->NewLocalRef(*l_fieldStringWrapper));
		env->SetObjectField(javaObjInstance, jFieldId_field_string, l_fieldString);
		static const TCHAR* errorMsgfieldStringSet = TEXT("failed when seting field for out_struct_string.fieldString");
		checkJniErrorOccured(errorMsgfieldStringSet);
	}
	else
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("field_string field in FTestbed1StructString not found"));
	}
	return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructStringArray(JNIEnv* env, const TArray<FTestbed1StructString>& cppArray)
{
	ensureInitialized();
	if (jStructString == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructString not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructString, nullptr);
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

jclass Testbed1DataJavaConverter::jStructStruct = nullptr;

void Testbed1DataJavaConverter::fillStructStruct(JNIEnv* env, jobject input, FTestbed1StructStruct& out_struct_struct)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfieldString = TEXT("failed when trying to field fieldString Ltestbed1/testbed1_api/StructString; for FTestbed1StructStruct");
	static const jfieldID jFieldId_field_string = getFieldId(jStructStruct, "fieldString", "Ltestbed1/testbed1_api/StructString;", errorMsgFindfieldString);

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
	ensureInitialized();
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
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct_struct.");
	static const jmethodID ctor = getMethod(jStructStruct, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr )
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStructStruct, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_struct.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfieldString = TEXT("failed when trying to field fieldString Ltestbed1/testbed1_api/StructString; for FTestbed1StructStruct");
	static const jfieldID jFieldId_field_string = getFieldId(jStructStruct, "fieldString", "Ltestbed1/testbed1_api/StructString;", errorMsgFindfieldString);

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
	ensureInitialized();
	if (jStructStruct == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructStruct not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructStruct, nullptr);
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

jclass Testbed1DataJavaConverter::jStructEnum = nullptr;

void Testbed1DataJavaConverter::fillStructEnum(JNIEnv* env, jobject input, FTestbed1StructEnum& out_struct_enum)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfieldEnum = TEXT("failed when trying to field fieldEnum Ltestbed1/testbed1_api/Enum0; for FTestbed1StructEnum");
	static const jfieldID jFieldId_field_enum = getFieldId(jStructEnum, "fieldEnum", "Ltestbed1/testbed1_api/Enum0;", errorMsgFindfieldEnum);

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
	ensureInitialized();
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
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct_enum.");
	static const jmethodID ctor = getMethod(jStructEnum, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr )
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStructEnum, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_enum.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfieldEnum = TEXT("failed when trying to field fieldEnum Ltestbed1/testbed1_api/Enum0; for FTestbed1StructEnum");
	static const jfieldID jFieldId_field_enum = getFieldId(jStructEnum, "fieldEnum", "Ltestbed1/testbed1_api/Enum0;", errorMsgFindfieldEnum);

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
	ensureInitialized();
	if (jStructEnum == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructEnum not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructEnum, nullptr);
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

jclass Testbed1DataJavaConverter::jStructBoolWithArray = nullptr;

void Testbed1DataJavaConverter::fillStructBoolWithArray(JNIEnv* env, jobject input, FTestbed1StructBoolWithArray& out_struct_bool_with_array)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfieldBool = TEXT("failed when trying to field fieldBool [Z for FTestbed1StructBoolWithArray");
	static const jfieldID jFieldId_field_bool = getFieldId(jStructBoolWithArray, "fieldBool", "[Z", errorMsgFindfieldBool);

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
	ensureInitialized();
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
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct_bool_with_array.");
	static const jmethodID ctor = getMethod(jStructBoolWithArray, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr )
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStructBoolWithArray, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_bool_with_array.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfieldBool = TEXT("failed when trying to field fieldBool [Z for FTestbed1StructBoolWithArray");
	static const jfieldID jFieldId_field_bool = getFieldId(jStructBoolWithArray, "fieldBool", "[Z", errorMsgFindfieldBool);

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
	ensureInitialized();
	if (jStructBoolWithArray == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructBoolWithArray not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructBoolWithArray, nullptr);
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

jclass Testbed1DataJavaConverter::jStructIntWithArray = nullptr;

void Testbed1DataJavaConverter::fillStructIntWithArray(JNIEnv* env, jobject input, FTestbed1StructIntWithArray& out_struct_int_with_array)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfieldInt = TEXT("failed when trying to field fieldInt [I for FTestbed1StructIntWithArray");
	static const jfieldID jFieldId_field_int = getFieldId(jStructIntWithArray, "fieldInt", "[I", errorMsgFindfieldInt);

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
	ensureInitialized();
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
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct_int_with_array.");
	static const jmethodID ctor = getMethod(jStructIntWithArray, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr )
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStructIntWithArray, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_int_with_array.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfieldInt = TEXT("failed when trying to field fieldInt [I for FTestbed1StructIntWithArray");
	static const jfieldID jFieldId_field_int = getFieldId(jStructIntWithArray, "fieldInt", "[I", errorMsgFindfieldInt);

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
	ensureInitialized();
	if (jStructIntWithArray == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructIntWithArray not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructIntWithArray, nullptr);
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

jclass Testbed1DataJavaConverter::jStructFloatWithArray = nullptr;

void Testbed1DataJavaConverter::fillStructFloatWithArray(JNIEnv* env, jobject input, FTestbed1StructFloatWithArray& out_struct_float_with_array)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfieldFloat = TEXT("failed when trying to field fieldFloat [F for FTestbed1StructFloatWithArray");
	static const jfieldID jFieldId_field_float = getFieldId(jStructFloatWithArray, "fieldFloat", "[F", errorMsgFindfieldFloat);

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
	ensureInitialized();
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
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct_float_with_array.");
	static const jmethodID ctor = getMethod(jStructFloatWithArray, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr )
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStructFloatWithArray, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_float_with_array.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfieldFloat = TEXT("failed when trying to field fieldFloat [F for FTestbed1StructFloatWithArray");
	static const jfieldID jFieldId_field_float = getFieldId(jStructFloatWithArray, "fieldFloat", "[F", errorMsgFindfieldFloat);

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
	ensureInitialized();
	if (jStructFloatWithArray == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructFloatWithArray not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructFloatWithArray, nullptr);
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

jclass Testbed1DataJavaConverter::jStructStringWithArray = nullptr;

void Testbed1DataJavaConverter::fillStructStringWithArray(JNIEnv* env, jobject input, FTestbed1StructStringWithArray& out_struct_string_with_array)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfieldString = TEXT("failed when trying to field fieldString [Ljava/lang/String; for FTestbed1StructStringWithArray");
	static const jfieldID jFieldId_field_string = getFieldId(jStructStringWithArray, "fieldString", "[Ljava/lang/String;", errorMsgFindfieldString);

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
	ensureInitialized();
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
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct_string_with_array.");
	static const jmethodID ctor = getMethod(jStructStringWithArray, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr )
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStructStringWithArray, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_string_with_array.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfieldString = TEXT("failed when trying to field fieldString [Ljava/lang/String; for FTestbed1StructStringWithArray");
	static const jfieldID jFieldId_field_string = getFieldId(jStructStringWithArray, "fieldString", "[Ljava/lang/String;", errorMsgFindfieldString);

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
	ensureInitialized();
	if (jStructStringWithArray == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructStringWithArray not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructStringWithArray, nullptr);
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

jclass Testbed1DataJavaConverter::jStructStructWithArray = nullptr;

void Testbed1DataJavaConverter::fillStructStructWithArray(JNIEnv* env, jobject input, FTestbed1StructStructWithArray& out_struct_struct_with_array)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfieldStruct = TEXT("failed when trying to field fieldStruct [Ltestbed1/testbed1_api/StructStringWithArray; for FTestbed1StructStructWithArray");
	static const jfieldID jFieldId_field_struct = getFieldId(jStructStructWithArray, "fieldStruct", "[Ltestbed1/testbed1_api/StructStringWithArray;", errorMsgFindfieldStruct);

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
	ensureInitialized();
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
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct_struct_with_array.");
	static const jmethodID ctor = getMethod(jStructStructWithArray, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr )
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStructStructWithArray, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_struct_with_array.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfieldStruct = TEXT("failed when trying to field fieldStruct [Ltestbed1/testbed1_api/StructStringWithArray; for FTestbed1StructStructWithArray");
	static const jfieldID jFieldId_field_struct = getFieldId(jStructStructWithArray, "fieldStruct", "[Ltestbed1/testbed1_api/StructStringWithArray;", errorMsgFindfieldStruct);

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
	ensureInitialized();
	if (jStructStructWithArray == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructStructWithArray not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructStructWithArray, nullptr);
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

jclass Testbed1DataJavaConverter::jStructEnumWithArray = nullptr;

void Testbed1DataJavaConverter::fillStructEnumWithArray(JNIEnv* env, jobject input, FTestbed1StructEnumWithArray& out_struct_enum_with_array)
{
	ensureInitialized();

	static const TCHAR* errorMsgFindfieldEnum = TEXT("failed when trying to field fieldEnum [Ltestbed1/testbed1_api/Enum0; for FTestbed1StructEnumWithArray");
	static const jfieldID jFieldId_field_enum = getFieldId(jStructEnumWithArray, "fieldEnum", "[Ltestbed1/testbed1_api/Enum0;", errorMsgFindfieldEnum);

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
	ensureInitialized();
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
	ensureInitialized();

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_struct_enum_with_array.");
	static const jmethodID ctor = getMethod(jStructEnumWithArray, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr )
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jStructEnumWithArray, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_struct_enum_with_array.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindfieldEnum = TEXT("failed when trying to field fieldEnum [Ltestbed1/testbed1_api/Enum0; for FTestbed1StructEnumWithArray");
	static const jfieldID jFieldId_field_enum = getFieldId(jStructEnumWithArray, "fieldEnum", "[Ltestbed1/testbed1_api/Enum0;", errorMsgFindfieldEnum);

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
	ensureInitialized();
	if (jStructEnumWithArray == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("FTestbed1StructEnumWithArray not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructEnumWithArray, nullptr);
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
jclass Testbed1DataJavaConverter::jEnum0 = nullptr;

void Testbed1DataJavaConverter::fillEnum0Array(JNIEnv* env, jobjectArray input, TArray<ETestbed1Enum0>& out_array)
{
	ensureInitialized();
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
	ensureInitialized();
	static const TCHAR* errorMsgGetMethod = TEXT("failed when trying to get java method getVaue for object for Enum0.");
	static const jmethodID getValueMethod = getMethod(jEnum0, "getValue", "()I", errorMsgGetMethod);
	if (getValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, getValueMethod);
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
	ensureInitialized();
	if (jEnum0 == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("Enum Enum0 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jEnum0, nullptr);
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
	ensureInitialized();
	static const TCHAR* errorMsgFromValueMethod = TEXT("failed when trying to get java method fromValue for object for Enum0.");
	static const jmethodID fromValueMethod = getStaticMethod(jEnum0, "fromValue", "(I)Ltestbed1/testbed1_api/Enum0;", errorMsgFromValueMethod);
	if (fromValueMethod == nullptr)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgFromValueMethod);
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(jEnum0, fromValueMethod, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum0.");
	checkJniErrorOccured(errorMsg);
	return javaObj;
}

jclass Testbed1DataJavaConverter::jStructInterface = nullptr;

void Testbed1DataJavaConverter::fillStructInterface(JNIEnv* env, jobject input, TScriptInterface<ITestbed1StructInterfaceInterface> out_struct_interface)
{
	ensureInitialized();
	if (!input || !out_struct_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void Testbed1DataJavaConverter::fillStructInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed1StructInterfaceInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject Testbed1DataJavaConverter::makeJavaStructInterface(JNIEnv* env, const TScriptInterface<ITestbed1StructInterfaceInterface> out_struct_interface)
{
	ensureInitialized();
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
	ensureInitialized();
	if (!jStructInterface)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("IStructInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructInterface, nullptr);
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
	ensureInitialized();
	UTestbed1StructInterfaceImplementation* Impl = NewObject<UTestbed1StructInterfaceImplementation>();
	TScriptInterface<ITestbed1StructInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITestbed1StructInterfaceInterface>(Impl));
	return wrapped;
}

jclass Testbed1DataJavaConverter::jStructArrayInterface = nullptr;

void Testbed1DataJavaConverter::fillStructArrayInterface(JNIEnv* env, jobject input, TScriptInterface<ITestbed1StructArrayInterfaceInterface> out_struct_array_interface)
{
	ensureInitialized();
	if (!input || !out_struct_array_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void Testbed1DataJavaConverter::fillStructArrayInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed1StructArrayInterfaceInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject Testbed1DataJavaConverter::makeJavaStructArrayInterface(JNIEnv* env, const TScriptInterface<ITestbed1StructArrayInterfaceInterface> out_struct_array_interface)
{
	ensureInitialized();
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
	ensureInitialized();
	if (!jStructArrayInterface)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("IStructArrayInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructArrayInterface, nullptr);
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
	ensureInitialized();
	UTestbed1StructArrayInterfaceImplementation* Impl = NewObject<UTestbed1StructArrayInterfaceImplementation>();
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITestbed1StructArrayInterfaceInterface>(Impl));
	return wrapped;
}

jclass Testbed1DataJavaConverter::jStructArray2Interface = nullptr;

void Testbed1DataJavaConverter::fillStructArray2Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed1StructArray2InterfaceInterface> out_struct_array2_interface)
{
	ensureInitialized();
	if (!input || !out_struct_array2_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void Testbed1DataJavaConverter::fillStructArray2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed1StructArray2InterfaceInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject Testbed1DataJavaConverter::makeJavaStructArray2Interface(JNIEnv* env, const TScriptInterface<ITestbed1StructArray2InterfaceInterface> out_struct_array2_interface)
{
	ensureInitialized();
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
	ensureInitialized();
	if (!jStructArray2Interface)
	{
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Warning, TEXT("IStructArray2Interface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jStructArray2Interface, nullptr);
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
	ensureInitialized();
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
		UE_LOG(LogTestbed1DataJavaConverter_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

void Testbed1DataJavaConverter::cleanJavaReferences()
{
	FScopeLock Lock(&initMutex);
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(jStructBool);
	env->DeleteGlobalRef(jStructInt);
	env->DeleteGlobalRef(jStructFloat);
	env->DeleteGlobalRef(jStructString);
	env->DeleteGlobalRef(jStructStruct);
	env->DeleteGlobalRef(jStructEnum);
	env->DeleteGlobalRef(jStructBoolWithArray);
	env->DeleteGlobalRef(jStructIntWithArray);
	env->DeleteGlobalRef(jStructFloatWithArray);
	env->DeleteGlobalRef(jStructStringWithArray);
	env->DeleteGlobalRef(jStructStructWithArray);
	env->DeleteGlobalRef(jStructEnumWithArray);
	env->DeleteGlobalRef(jEnum0);
	env->DeleteGlobalRef(jStructInterface);
	env->DeleteGlobalRef(jStructArrayInterface);
	env->DeleteGlobalRef(jStructArray2Interface);
}

FCriticalSection Testbed1DataJavaConverter::initMutex;

bool Testbed1DataJavaConverter::m_isInitialized = false;

void Testbed1DataJavaConverter::ensureInitialized()
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
	jStructBool = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructBool");
	static const TCHAR* errorMsgStructBool= TEXT("failed to get testbed1/testbed1_api/StructBool");
	checkJniErrorOccured(errorMsgStructBool);
	jStructInt = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructInt");
	static const TCHAR* errorMsgStructInt= TEXT("failed to get testbed1/testbed1_api/StructInt");
	checkJniErrorOccured(errorMsgStructInt);
	jStructFloat = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructFloat");
	static const TCHAR* errorMsgStructFloat= TEXT("failed to get testbed1/testbed1_api/StructFloat");
	checkJniErrorOccured(errorMsgStructFloat);
	jStructString = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructString");
	static const TCHAR* errorMsgStructString= TEXT("failed to get testbed1/testbed1_api/StructString");
	checkJniErrorOccured(errorMsgStructString);
	jStructStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructStruct");
	static const TCHAR* errorMsgStructStruct= TEXT("failed to get testbed1/testbed1_api/StructStruct");
	checkJniErrorOccured(errorMsgStructStruct);
	jStructEnum = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructEnum");
	static const TCHAR* errorMsgStructEnum= TEXT("failed to get testbed1/testbed1_api/StructEnum");
	checkJniErrorOccured(errorMsgStructEnum);
	jStructBoolWithArray = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructBoolWithArray");
	static const TCHAR* errorMsgStructBoolWithArray= TEXT("failed to get testbed1/testbed1_api/StructBoolWithArray");
	checkJniErrorOccured(errorMsgStructBoolWithArray);
	jStructIntWithArray = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructIntWithArray");
	static const TCHAR* errorMsgStructIntWithArray= TEXT("failed to get testbed1/testbed1_api/StructIntWithArray");
	checkJniErrorOccured(errorMsgStructIntWithArray);
	jStructFloatWithArray = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructFloatWithArray");
	static const TCHAR* errorMsgStructFloatWithArray= TEXT("failed to get testbed1/testbed1_api/StructFloatWithArray");
	checkJniErrorOccured(errorMsgStructFloatWithArray);
	jStructStringWithArray = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructStringWithArray");
	static const TCHAR* errorMsgStructStringWithArray= TEXT("failed to get testbed1/testbed1_api/StructStringWithArray");
	checkJniErrorOccured(errorMsgStructStringWithArray);
	jStructStructWithArray = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructStructWithArray");
	static const TCHAR* errorMsgStructStructWithArray= TEXT("failed to get testbed1/testbed1_api/StructStructWithArray");
	checkJniErrorOccured(errorMsgStructStructWithArray);
	jStructEnumWithArray = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructEnumWithArray");
	static const TCHAR* errorMsgStructEnumWithArray= TEXT("failed to get testbed1/testbed1_api/StructEnumWithArray");
	checkJniErrorOccured(errorMsgStructEnumWithArray);
	jEnum0 = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/Enum0");
	static const TCHAR* errorMsgEnum0= TEXT("failed to get testbed1/testbed1_api/Enum0");
	checkJniErrorOccured(errorMsgEnum0);
	jStructInterface = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/IStructInterface");
	static const TCHAR* errorMsgStructInterface= TEXT("failed to get testbed1/testbed1_api/IStructInterface");
	checkJniErrorOccured(errorMsgStructInterface);
	jStructArrayInterface = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/IStructArrayInterface");
	static const TCHAR* errorMsgStructArrayInterface= TEXT("failed to get testbed1/testbed1_api/IStructArrayInterface");
	checkJniErrorOccured(errorMsgStructArrayInterface);
	jStructArray2Interface = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/IStructArray2Interface");
	static const TCHAR* errorMsgStructArray2Interface= TEXT("failed to get testbed1/testbed1_api/IStructArray2Interface");
	checkJniErrorOccured(errorMsgStructArray2Interface);
	m_isInitialized = true;
}

jmethodID Testbed1DataJavaConverter::getMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jmethodID Testbed1DataJavaConverter::getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetStaticMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jfieldID Testbed1DataJavaConverter::getFieldId(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jfieldID field = env->GetFieldID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return field;
}

#endif
