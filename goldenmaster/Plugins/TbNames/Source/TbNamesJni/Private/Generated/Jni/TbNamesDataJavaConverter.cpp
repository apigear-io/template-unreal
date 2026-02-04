
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

#include "TbNames/Generated/Jni/TbNamesDataJavaConverter.h"
#include "TbNames/Generated/api/TbNames_data.h"
#include "TbNames/Implementation/TbNamesNamEs.h"

#include "Generated/Detail/TbNamesCommonJavaConverter.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

DEFINE_LOG_CATEGORY(LogTbNamesDataJavaConverter_JNI);

struct FTbNamesDataJavaConverterCacheData
{
	jclass jEnumWithUnderScores = nullptr;
	jclass jNamEs = nullptr;

	~FTbNamesDataJavaConverterCacheData()
	{
		JNIEnv* Env = FAndroidApplication::GetJavaEnv();
		if (Env)
		{
			if (jEnumWithUnderScores)
			{
				Env->DeleteGlobalRef(jEnumWithUnderScores);
			}
			if (jNamEs)
			{
				Env->DeleteGlobalRef(jNamEs);
			}
		}
	}
};

FCriticalSection TbNamesDataJavaConverter::CacheLock;
TSharedPtr<FTbNamesDataJavaConverterCacheData, ESPMode::ThreadSafe> TbNamesDataJavaConverter::CacheData;

void TbNamesDataJavaConverter::fillEnumWithUnderScoresArray(JNIEnv* env, jobjectArray input, TArray<ETbNamesEnum_With_Under_scores>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("TbNamesDataJavaConverter cache not initialized for fillEnumWithUnderScoresArray"));
		return;
	}
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of EnumWithUnderScores array.");
	if (CheckJniErrorOccurred(errorMsgLen))
	{
		return;
	}
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of EnumWithUnderScores array.");
		auto failed = CheckJniErrorOccurred(errorMsg);
		if (!failed)
		{
			out_array.Add(getEnumWithUnderScoresValue(env, element));
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

ETbNamesEnum_With_Under_scores TbNamesDataJavaConverter::getEnumWithUnderScoresValue(JNIEnv* env, jobject input)
{
	ETbNamesEnum_With_Under_scores cppEnumValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("TbNamesDataJavaConverter cache not initialized for getEnumWithUnderScoresValue"));
		return cppEnumValue;
	}
	static const TCHAR* errorMsgGetMethod = TEXT("failed when trying to get java method getVaue for object for EnumWithUnderScores.");
	static const jmethodID getValueMethod = getMethod(Cache->jEnumWithUnderScores, "getValue", "()I", errorMsgGetMethod);
	if (getValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, getValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for EnumWithUnderScores.");
		if (!CheckJniErrorOccurred(errorMsg))
		{
			UTbNamesLibrary::toTbNamesEnum_With_Under_scores(cppEnumValue, int_value);
		}
	}
	else
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("Enum EnumWithUnderScores::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbNamesDataJavaConverter::makeJavaEnumWithUnderScoresArray(JNIEnv* env, const TArray<ETbNamesEnum_With_Under_scores>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jEnumWithUnderScores)
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("Enum EnumWithUnderScores not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jEnumWithUnderScores, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate EnumWithUnderScores jarray.");
	if (CheckJniErrorOccurred(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnumWithUnderScores(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of EnumWithUnderScores array.");
		auto failed = CheckJniErrorOccurred(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

jobject TbNamesDataJavaConverter::makeJavaEnumWithUnderScores(JNIEnv* env, ETbNamesEnum_With_Under_scores value)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("TbNamesDataJavaConverter cache not initialized for makeJavaEnumWithUnderScores"));
		return nullptr;
	}
	static const TCHAR* errorMsgFromValueMethod = TEXT("failed when trying to get java method fromValue for object for EnumWithUnderScores.");
	static const jmethodID fromValueMethod = getStaticMethod(Cache->jEnumWithUnderScores, "fromValue", "(I)LtbNames/tbNames_api/EnumWithUnderScores;", errorMsgFromValueMethod);
	if (fromValueMethod == nullptr)
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgFromValueMethod);
		return nullptr;
	}
	int int_value = (int)value;
	jobject javaObj = env->CallStaticObjectMethod(Cache->jEnumWithUnderScores, fromValueMethod, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for EnumWithUnderScores.");
	CheckJniErrorOccurred(errorMsg);
	return javaObj;
}

void TbNamesDataJavaConverter::fillNamEs(JNIEnv* env, jobject input, TScriptInterface<ITbNamesNamEsInterface> out_nam_es)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("TbNamesDataJavaConverter cache not initialized for fillNamEs"));
		return;
	}
	if (!input || !out_nam_es)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbNamesDataJavaConverter::fillNamEsArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbNamesNamEsInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("TbNamesDataJavaConverter cache not initialized for fillNamEsArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbNamesDataJavaConverter::makeJavaNamEs(JNIEnv* env, const TScriptInterface<ITbNamesNamEsInterface> out_nam_es)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("TbNamesDataJavaConverter cache not initialized for makeJavaNamEs"));
		return nullptr;
	}
	if (!out_nam_es)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbNamesDataJavaConverter::makeJavaNamEsArray(JNIEnv* env, const TArray<TScriptInterface<ITbNamesNamEsInterface>>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jNamEs)
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("INamEs not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jNamEs, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_nam_es.");
	if (CheckJniErrorOccurred(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbNamesNamEsInterface> TbNamesDataJavaConverter::getCppInstanceTbNamesNamEs()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("TbNamesDataJavaConverter cache not initialized for getCppInstanceTbNamesNamEs"));
		return nullptr;
	}
	UTbNamesNamEsImplementation* Impl = NewObject<UTbNamesNamEsImplementation>();
	TScriptInterface<ITbNamesNamEsInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbNamesNamEsInterface>(Impl));
	return wrapped;
}

bool TbNamesDataJavaConverter::CheckJniErrorOccurred(const TCHAR* Msg)
{
	return FTbNamesCommonJavaConverter::CheckJniErrorOccurred(Msg);
}

void TbNamesDataJavaConverter::cleanJavaReferences()
{
	FScopeLock Lock(&CacheLock);
	CacheData.Reset();
}

TSharedPtr<FTbNamesDataJavaConverterCacheData, ESPMode::ThreadSafe> TbNamesDataJavaConverter::ensureInitialized()
{
	{
		FScopeLock Lock(&CacheLock);
		if (CacheData)
		{
			return CacheData;
		}
	}

	auto NewData = MakeShared<FTbNamesDataJavaConverterCacheData, ESPMode::ThreadSafe>();
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	NewData->jEnumWithUnderScores = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNames_api/EnumWithUnderScores");
	static const TCHAR* errorMsgEnumWithUnderScores = TEXT("failed to get tbNames/tbNames_api/EnumWithUnderScores");
	CheckJniErrorOccurred(errorMsgEnumWithUnderScores);
	NewData->jNamEs = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNames_api/INamEs");
	static const TCHAR* errorMsgNamEs = TEXT("failed to get tbNames/tbNames_api/INamEs");
	CheckJniErrorOccurred(errorMsgNamEs);

	{
		FScopeLock Lock(&CacheLock);
		if (!CacheData)
		{
			CacheData = NewData;
		}
		return CacheData;
	}
}

jmethodID TbNamesDataJavaConverter::getMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetMethodID(cls, name, signature);
	CheckJniErrorOccurred(errorMsgInfo);
	return method;
}

jmethodID TbNamesDataJavaConverter::getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetStaticMethodID(cls, name, signature);
	CheckJniErrorOccurred(errorMsgInfo);
	return method;
}

jfieldID TbNamesDataJavaConverter::getFieldId(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jfieldID field = env->GetFieldID(cls, name, signature);
	CheckJniErrorOccurred(errorMsgInfo);
	return field;
}

#endif
