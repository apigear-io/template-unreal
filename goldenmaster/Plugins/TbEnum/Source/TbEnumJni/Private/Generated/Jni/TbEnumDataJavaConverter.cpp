
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

#include "TbEnum/Generated/Jni/TbEnumDataJavaConverter.h"
#include "TbEnum/Generated/api/TbEnum_data.h"
#include "TbEnum/Implementation/TbEnumEnumInterface.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

void TbEnumDataJavaConverter::fillEnum0Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum0>& out_array)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum0");
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		out_array.Add(getEnum0Value(env, element));
		env->DeleteLocalRef(element);
	}
}

ETbEnumEnum0 TbEnumDataJavaConverter::getEnum0Value(JNIEnv* env, jobject input)
{
	ETbEnumEnum0 cppEnumValue;
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum0");
	jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
	int int_value = env->CallIntMethod(input, getValueMethod);
	UTbEnumLibrary::toTbEnumEnum0(cppEnumValue, int_value);
	return cppEnumValue;
}

jobjectArray TbEnumDataJavaConverter::makeJavaEnum0Array(JNIEnv* env, const TArray<ETbEnumEnum0>& cppArray)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum0");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaStruct, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum0(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject TbEnumDataJavaConverter::makeJavaEnum0(JNIEnv* env, ETbEnumEnum0 value)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum0");
	jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)LtbEnum/tbEnum_api/Enum0;");
	if (!fromValueMethod)
		return nullptr;
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
	return javaObj;
}

void TbEnumDataJavaConverter::fillEnum1Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum1>& out_array)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum1");
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		out_array.Add(getEnum1Value(env, element));
		env->DeleteLocalRef(element);
	}
}

ETbEnumEnum1 TbEnumDataJavaConverter::getEnum1Value(JNIEnv* env, jobject input)
{
	ETbEnumEnum1 cppEnumValue;
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum1");
	jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
	int int_value = env->CallIntMethod(input, getValueMethod);
	UTbEnumLibrary::toTbEnumEnum1(cppEnumValue, int_value);
	return cppEnumValue;
}

jobjectArray TbEnumDataJavaConverter::makeJavaEnum1Array(JNIEnv* env, const TArray<ETbEnumEnum1>& cppArray)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum1");
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

jobject TbEnumDataJavaConverter::makeJavaEnum1(JNIEnv* env, ETbEnumEnum1 value)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum1");
	jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)LtbEnum/tbEnum_api/Enum1;");
	if (!fromValueMethod)
		return nullptr;
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
	return javaObj;
}

void TbEnumDataJavaConverter::fillEnum2Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum2>& out_array)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum2");
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		out_array.Add(getEnum2Value(env, element));
		env->DeleteLocalRef(element);
	}
}

ETbEnumEnum2 TbEnumDataJavaConverter::getEnum2Value(JNIEnv* env, jobject input)
{
	ETbEnumEnum2 cppEnumValue;
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum2");
	jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
	int int_value = env->CallIntMethod(input, getValueMethod);
	UTbEnumLibrary::toTbEnumEnum2(cppEnumValue, int_value);
	return cppEnumValue;
}

jobjectArray TbEnumDataJavaConverter::makeJavaEnum2Array(JNIEnv* env, const TArray<ETbEnumEnum2>& cppArray)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum2");
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

jobject TbEnumDataJavaConverter::makeJavaEnum2(JNIEnv* env, ETbEnumEnum2 value)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum2");
	jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)LtbEnum/tbEnum_api/Enum2;");
	if (!fromValueMethod)
		return nullptr;
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
	return javaObj;
}

void TbEnumDataJavaConverter::fillEnum3Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum3>& out_array)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum3");
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		out_array.Add(getEnum3Value(env, element));
		env->DeleteLocalRef(element);
	}
}

ETbEnumEnum3 TbEnumDataJavaConverter::getEnum3Value(JNIEnv* env, jobject input)
{
	ETbEnumEnum3 cppEnumValue;
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum3");
	jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
	int int_value = env->CallIntMethod(input, getValueMethod);
	UTbEnumLibrary::toTbEnumEnum3(cppEnumValue, int_value);
	return cppEnumValue;
}

jobjectArray TbEnumDataJavaConverter::makeJavaEnum3Array(JNIEnv* env, const TArray<ETbEnumEnum3>& cppArray)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum3");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaStruct, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum3(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject TbEnumDataJavaConverter::makeJavaEnum3(JNIEnv* env, ETbEnumEnum3 value)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum3");
	jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)LtbEnum/tbEnum_api/Enum3;");
	if (!fromValueMethod)
		return nullptr;
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
	return javaObj;
}

void TbEnumDataJavaConverter::fillEnumInterface(JNIEnv* env, jobject input, TScriptInterface<ITbEnumEnumInterfaceInterface> out_enum_interface)
{
	if (!input || !out_enum_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbEnumDataJavaConverter::fillEnumInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbEnumEnumInterfaceInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbEnumDataJavaConverter::makeJavaEnumInterface(JNIEnv* env, const TScriptInterface<ITbEnumEnumInterfaceInterface> out_enum_interface)
{
	if (!out_enum_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbEnumDataJavaConverter::makeJavaEnumInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbEnumEnumInterfaceInterface>>& cppArray)
{
	jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/IEnumInterface");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaClass, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbEnumEnumInterfaceInterface> TbEnumDataJavaConverter::getCppInstanceTbEnumEnumInterface()
{
	UTbEnumEnumInterfaceImplementation* Impl = NewObject<UTbEnumEnumInterfaceImplementation>();
	TScriptInterface<ITbEnumEnumInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbEnumEnumInterfaceInterface>(Impl));
	return wrapped;
}

#endif
