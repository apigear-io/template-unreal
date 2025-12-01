
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
#include "TbEnum/Generated/Jni/TbEnumJniCache.h"
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

DEFINE_LOG_CATEGORY(LogTbEnumDataJavaConverter_JNI);

void TbEnumDataJavaConverter::fillEnum0Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum0>& out_array)
{
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of Enum0 array.");
	checkJniError(errorMsgLen);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of Enum0 array.");
		checkJniError(errorMsg);
		out_array.Add(getEnum0Value(env, element));
		env->DeleteLocalRef(element);
	}
}

ETbEnumEnum0 TbEnumDataJavaConverter::getEnum0Value(JNIEnv* env, jobject input)
{
	ETbEnumEnum0 cppEnumValue = ETbEnumEnum0::TEE0_Value0;

	if (TbEnumJniCache::javaEnumEnum0GetValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, TbEnumJniCache::javaEnumEnum0GetValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum0.");
		checkJniError(errorMsg);
		UTbEnumLibrary::toTbEnumEnum0(cppEnumValue, int_value);
	}
	else
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum0::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbEnumDataJavaConverter::makeJavaEnum0Array(JNIEnv* env, const TArray<ETbEnumEnum0>& cppArray)
{
	if (TbEnumJniCache::javaEnumEnum0 == nullptr)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum0 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbEnumJniCache::javaEnumEnum0, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate Enum0 jarray.");
	checkJniError(errorMsgAlloc);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum0(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of Enum0 array.");
		checkJniError(errorMsg);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject TbEnumDataJavaConverter::makeJavaEnum0(JNIEnv* env, ETbEnumEnum0 value)
{
	if (TbEnumJniCache::javaEnumEnum0FromValueMethodId == nullptr)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum0::fromValue not found"));
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(TbEnumJniCache::javaEnumEnum0, TbEnumJniCache::javaEnumEnum0FromValueMethodId, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum0.");
	checkJniError(errorMsg);
	return javaObj;
}

void TbEnumDataJavaConverter::fillEnum1Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum1>& out_array)
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

ETbEnumEnum1 TbEnumDataJavaConverter::getEnum1Value(JNIEnv* env, jobject input)
{
	ETbEnumEnum1 cppEnumValue = ETbEnumEnum1::TEE1_Value1;

	if (TbEnumJniCache::javaEnumEnum1GetValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, TbEnumJniCache::javaEnumEnum1GetValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum1.");
		checkJniError(errorMsg);
		UTbEnumLibrary::toTbEnumEnum1(cppEnumValue, int_value);
	}
	else
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum1::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbEnumDataJavaConverter::makeJavaEnum1Array(JNIEnv* env, const TArray<ETbEnumEnum1>& cppArray)
{
	if (TbEnumJniCache::javaEnumEnum1 == nullptr)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum1 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbEnumJniCache::javaEnumEnum1, nullptr);
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

jobject TbEnumDataJavaConverter::makeJavaEnum1(JNIEnv* env, ETbEnumEnum1 value)
{
	if (TbEnumJniCache::javaEnumEnum1FromValueMethodId == nullptr)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum1::fromValue not found"));
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(TbEnumJniCache::javaEnumEnum1, TbEnumJniCache::javaEnumEnum1FromValueMethodId, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum1.");
	checkJniError(errorMsg);
	return javaObj;
}

void TbEnumDataJavaConverter::fillEnum2Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum2>& out_array)
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

ETbEnumEnum2 TbEnumDataJavaConverter::getEnum2Value(JNIEnv* env, jobject input)
{
	ETbEnumEnum2 cppEnumValue = ETbEnumEnum2::TEE2_Value2;

	if (TbEnumJniCache::javaEnumEnum2GetValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, TbEnumJniCache::javaEnumEnum2GetValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum2.");
		checkJniError(errorMsg);
		UTbEnumLibrary::toTbEnumEnum2(cppEnumValue, int_value);
	}
	else
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum2::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbEnumDataJavaConverter::makeJavaEnum2Array(JNIEnv* env, const TArray<ETbEnumEnum2>& cppArray)
{
	if (TbEnumJniCache::javaEnumEnum2 == nullptr)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum2 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbEnumJniCache::javaEnumEnum2, nullptr);
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

jobject TbEnumDataJavaConverter::makeJavaEnum2(JNIEnv* env, ETbEnumEnum2 value)
{
	if (TbEnumJniCache::javaEnumEnum2FromValueMethodId == nullptr)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum2::fromValue not found"));
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(TbEnumJniCache::javaEnumEnum2, TbEnumJniCache::javaEnumEnum2FromValueMethodId, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum2.");
	checkJniError(errorMsg);
	return javaObj;
}

void TbEnumDataJavaConverter::fillEnum3Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum3>& out_array)
{
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of Enum3 array.");
	checkJniError(errorMsgLen);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of Enum3 array.");
		checkJniError(errorMsg);
		out_array.Add(getEnum3Value(env, element));
		env->DeleteLocalRef(element);
	}
}

ETbEnumEnum3 TbEnumDataJavaConverter::getEnum3Value(JNIEnv* env, jobject input)
{
	ETbEnumEnum3 cppEnumValue = ETbEnumEnum3::TEE3_Value3;

	if (TbEnumJniCache::javaEnumEnum3GetValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, TbEnumJniCache::javaEnumEnum3GetValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum3.");
		checkJniError(errorMsg);
		UTbEnumLibrary::toTbEnumEnum3(cppEnumValue, int_value);
	}
	else
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum3::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbEnumDataJavaConverter::makeJavaEnum3Array(JNIEnv* env, const TArray<ETbEnumEnum3>& cppArray)
{
	if (TbEnumJniCache::javaEnumEnum3 == nullptr)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum3 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbEnumJniCache::javaEnumEnum3, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate Enum3 jarray.");
	checkJniError(errorMsgAlloc);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnum3(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of Enum3 array.");
		checkJniError(errorMsg);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject TbEnumDataJavaConverter::makeJavaEnum3(JNIEnv* env, ETbEnumEnum3 value)
{
	if (TbEnumJniCache::javaEnumEnum3FromValueMethodId == nullptr)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum3::fromValue not found"));
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(TbEnumJniCache::javaEnumEnum3, TbEnumJniCache::javaEnumEnum3FromValueMethodId, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum3.");
	checkJniError(errorMsg);
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
	if (!TbEnumJniCache::javaClassEnumInterface)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("IEnumInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbEnumJniCache::javaClassEnumInterface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_enum_interface.");
	checkJniError(errorMsg);
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

void TbEnumDataJavaConverter::checkJniError(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("%s"), Msg);
	}
}

#endif
