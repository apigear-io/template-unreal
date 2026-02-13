
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

DEFINE_LOG_CATEGORY(LogTbEnumDataJavaConverter_JNI);

struct FTbEnumDataJavaConverterCacheData
{
	jclass jEnum0 = nullptr;
	jclass jEnum1 = nullptr;
	jclass jEnum2 = nullptr;
	jclass jEnum3 = nullptr;
	jclass jEnumInterface = nullptr;

	~FTbEnumDataJavaConverterCacheData()
	{
		JNIEnv* Env = FAndroidApplication::GetJavaEnv();
		if (Env)
		{
			if (jEnum0) Env->DeleteGlobalRef(jEnum0);
			if (jEnum1) Env->DeleteGlobalRef(jEnum1);
			if (jEnum2) Env->DeleteGlobalRef(jEnum2);
			if (jEnum3) Env->DeleteGlobalRef(jEnum3);
			if (jEnumInterface) Env->DeleteGlobalRef(jEnumInterface);
		}
	}
};

FCriticalSection TbEnumDataJavaConverter::CacheLock;
TSharedPtr<FTbEnumDataJavaConverterCacheData, ESPMode::ThreadSafe> TbEnumDataJavaConverter::CacheData;

void TbEnumDataJavaConverter::fillEnum0Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum0>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for fillEnum0Array"));
		return;
	}
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

ETbEnumEnum0 TbEnumDataJavaConverter::getEnum0Value(JNIEnv* env, jobject input)
{
	ETbEnumEnum0 cppEnumValue = ETbEnumEnum0::TEE0_Value0;
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for getEnum0Value"));
		return cppEnumValue;
	}
	static const TCHAR* errorMsgGetMethod = TEXT("failed when trying to get java method getVaue for object for Enum0.");
	static const jmethodID getValueMethod = getMethod(Cache->jEnum0, "getValue", "()I", errorMsgGetMethod);
	if (getValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, getValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for Enum0.");
		if (!checkJniErrorOccured(errorMsg))
		{
			UTbEnumLibrary::toTbEnumEnum0(cppEnumValue, int_value);
		}
	}
	else
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum0::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbEnumDataJavaConverter::makeJavaEnum0Array(JNIEnv* env, const TArray<ETbEnumEnum0>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jEnum0)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum0 not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jEnum0, nullptr);
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

jobject TbEnumDataJavaConverter::makeJavaEnum0(JNIEnv* env, ETbEnumEnum0 value)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for makeJavaEnum0"));
		return nullptr;
	}
	static const TCHAR* errorMsgFromValueMethod = TEXT("failed when trying to get java method fromValue for object for Enum0.");
	static const jmethodID fromValueMethod = getStaticMethod(Cache->jEnum0, "fromValue", "(I)LtbEnum/tbEnum_api/Enum0;", errorMsgFromValueMethod);
	if (fromValueMethod == nullptr)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgFromValueMethod);
		return nullptr;
	}
	int int_value = (int)value;
	jobject javaObj = env->CallStaticObjectMethod(Cache->jEnum0, fromValueMethod, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum0.");
	checkJniErrorOccured(errorMsg);
	return javaObj;
}

void TbEnumDataJavaConverter::fillEnum1Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum1>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for fillEnum1Array"));
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

ETbEnumEnum1 TbEnumDataJavaConverter::getEnum1Value(JNIEnv* env, jobject input)
{
	ETbEnumEnum1 cppEnumValue = ETbEnumEnum1::TEE1_Value1;
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for getEnum1Value"));
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
			UTbEnumLibrary::toTbEnumEnum1(cppEnumValue, int_value);
		}
	}
	else
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum1::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbEnumDataJavaConverter::makeJavaEnum1Array(JNIEnv* env, const TArray<ETbEnumEnum1>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jEnum1)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum1 not found"));
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

jobject TbEnumDataJavaConverter::makeJavaEnum1(JNIEnv* env, ETbEnumEnum1 value)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for makeJavaEnum1"));
		return nullptr;
	}
	static const TCHAR* errorMsgFromValueMethod = TEXT("failed when trying to get java method fromValue for object for Enum1.");
	static const jmethodID fromValueMethod = getStaticMethod(Cache->jEnum1, "fromValue", "(I)LtbEnum/tbEnum_api/Enum1;", errorMsgFromValueMethod);
	if (fromValueMethod == nullptr)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgFromValueMethod);
		return nullptr;
	}
	int int_value = (int)value;
	jobject javaObj = env->CallStaticObjectMethod(Cache->jEnum1, fromValueMethod, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum1.");
	checkJniErrorOccured(errorMsg);
	return javaObj;
}

void TbEnumDataJavaConverter::fillEnum2Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum2>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for fillEnum2Array"));
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

ETbEnumEnum2 TbEnumDataJavaConverter::getEnum2Value(JNIEnv* env, jobject input)
{
	ETbEnumEnum2 cppEnumValue = ETbEnumEnum2::TEE2_Value2;
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for getEnum2Value"));
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
			UTbEnumLibrary::toTbEnumEnum2(cppEnumValue, int_value);
		}
	}
	else
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum2::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbEnumDataJavaConverter::makeJavaEnum2Array(JNIEnv* env, const TArray<ETbEnumEnum2>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jEnum2)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum2 not found"));
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

jobject TbEnumDataJavaConverter::makeJavaEnum2(JNIEnv* env, ETbEnumEnum2 value)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for makeJavaEnum2"));
		return nullptr;
	}
	static const TCHAR* errorMsgFromValueMethod = TEXT("failed when trying to get java method fromValue for object for Enum2.");
	static const jmethodID fromValueMethod = getStaticMethod(Cache->jEnum2, "fromValue", "(I)LtbEnum/tbEnum_api/Enum2;", errorMsgFromValueMethod);
	if (fromValueMethod == nullptr)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgFromValueMethod);
		return nullptr;
	}
	int int_value = (int)value;
	jobject javaObj = env->CallStaticObjectMethod(Cache->jEnum2, fromValueMethod, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum2.");
	checkJniErrorOccured(errorMsg);
	return javaObj;
}

void TbEnumDataJavaConverter::fillEnum3Array(JNIEnv* env, jobjectArray input, TArray<ETbEnumEnum3>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for fillEnum3Array"));
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

ETbEnumEnum3 TbEnumDataJavaConverter::getEnum3Value(JNIEnv* env, jobject input)
{
	ETbEnumEnum3 cppEnumValue = ETbEnumEnum3::TEE3_Value3;
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for getEnum3Value"));
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
			UTbEnumLibrary::toTbEnumEnum3(cppEnumValue, int_value);
		}
	}
	else
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum3::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbEnumDataJavaConverter::makeJavaEnum3Array(JNIEnv* env, const TArray<ETbEnumEnum3>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jEnum3)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("Enum Enum3 not found"));
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

jobject TbEnumDataJavaConverter::makeJavaEnum3(JNIEnv* env, ETbEnumEnum3 value)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for makeJavaEnum3"));
		return nullptr;
	}
	static const TCHAR* errorMsgFromValueMethod = TEXT("failed when trying to get java method fromValue for object for Enum3.");
	static const jmethodID fromValueMethod = getStaticMethod(Cache->jEnum3, "fromValue", "(I)LtbEnum/tbEnum_api/Enum3;", errorMsgFromValueMethod);
	if (fromValueMethod == nullptr)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgFromValueMethod);
		return nullptr;
	}
	int int_value = (int)value;
	jobject javaObj = env->CallStaticObjectMethod(Cache->jEnum3, fromValueMethod, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for Enum3.");
	checkJniErrorOccured(errorMsg);
	return javaObj;
}

void TbEnumDataJavaConverter::fillEnumInterface(JNIEnv* env, jobject input, TScriptInterface<ITbEnumEnumInterfaceInterface> out_enum_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for fillEnumInterface"));
		return;
	}
	if (!input || !out_enum_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbEnumDataJavaConverter::fillEnumInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbEnumEnumInterfaceInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for fillEnumInterfaceArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbEnumDataJavaConverter::makeJavaEnumInterface(JNIEnv* env, const TScriptInterface<ITbEnumEnumInterfaceInterface> out_enum_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for makeJavaEnumInterface"));
		return nullptr;
	}
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
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jEnumInterface)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("IEnumInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jEnumInterface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_enum_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbEnumEnumInterfaceInterface> TbEnumDataJavaConverter::getCppInstanceTbEnumEnumInterface()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Warning, TEXT("TbEnumDataJavaConverter cache not initialized for getCppInstanceTbEnumEnumInterface"));
		return nullptr;
	}
	UTbEnumEnumInterfaceImplementation* Impl = NewObject<UTbEnumEnumInterfaceImplementation>();
	TScriptInterface<ITbEnumEnumInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbEnumEnumInterfaceInterface>(Impl));
	return wrapped;
}

bool TbEnumDataJavaConverter::checkJniErrorOccured(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbEnumDataJavaConverter_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

void TbEnumDataJavaConverter::cleanJavaReferences()
{
	FScopeLock Lock(&CacheLock);
	CacheData.Reset();
}

TSharedPtr<FTbEnumDataJavaConverterCacheData, ESPMode::ThreadSafe> TbEnumDataJavaConverter::ensureInitialized()
{
	{
		FScopeLock Lock(&CacheLock);
		if (CacheData)
		{
			return CacheData;
		}
	}

	auto NewData = MakeShared<FTbEnumDataJavaConverterCacheData, ESPMode::ThreadSafe>();
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	NewData->jEnum0 = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum0");
	static const TCHAR* errorMsgEnum0 = TEXT("failed to get tbEnum/tbEnum_api/Enum0");
	checkJniErrorOccured(errorMsgEnum0);
	NewData->jEnum1 = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum1");
	static const TCHAR* errorMsgEnum1 = TEXT("failed to get tbEnum/tbEnum_api/Enum1");
	checkJniErrorOccured(errorMsgEnum1);
	NewData->jEnum2 = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum2");
	static const TCHAR* errorMsgEnum2 = TEXT("failed to get tbEnum/tbEnum_api/Enum2");
	checkJniErrorOccured(errorMsgEnum2);
	NewData->jEnum3 = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/Enum3");
	static const TCHAR* errorMsgEnum3 = TEXT("failed to get tbEnum/tbEnum_api/Enum3");
	checkJniErrorOccured(errorMsgEnum3);
	NewData->jEnumInterface = FAndroidApplication::FindJavaClassGlobalRef("tbEnum/tbEnum_api/IEnumInterface");
	static const TCHAR* errorMsgEnumInterface = TEXT("failed to get tbEnum/tbEnum_api/IEnumInterface");
	checkJniErrorOccured(errorMsgEnumInterface);

	{
		FScopeLock Lock(&CacheLock);
		if (!CacheData)
		{
			CacheData = NewData;
		}
		return CacheData;
	}
}

jmethodID TbEnumDataJavaConverter::getMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jmethodID TbEnumDataJavaConverter::getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetStaticMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jfieldID TbEnumDataJavaConverter::getFieldId(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jfieldID field = env->GetFieldID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return field;
}

#endif
