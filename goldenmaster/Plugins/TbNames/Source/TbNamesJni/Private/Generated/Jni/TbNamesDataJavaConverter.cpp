
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
#include "TbNames/Generated/Jni/TbNamesJniCache.h"
#include "TbNames/Generated/api/TbNames_data.h"
#include "TbNames/Implementation/TbNamesNamEs.h"

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

void TbNamesDataJavaConverter::fillEnumWithUnderScoresArray(JNIEnv* env, jobjectArray input, TArray<ETbNamesEnum_With_Under_scores>& out_array)
{
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of EnumWithUnderScores array.");
	checkJniError(errorMsgLen);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of EnumWithUnderScores array.");
		checkJniError(errorMsg);
		out_array.Add(getEnumWithUnderScoresValue(env, element));
		env->DeleteLocalRef(element);
	}
}

ETbNamesEnum_With_Under_scores TbNamesDataJavaConverter::getEnumWithUnderScoresValue(JNIEnv* env, jobject input)
{
	ETbNamesEnum_With_Under_scores cppEnumValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;

	if (TbNamesJniCache::javaEnumEnumWithUnderScoresGetValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, TbNamesJniCache::javaEnumEnumWithUnderScoresGetValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for EnumWithUnderScores.");
		checkJniError(errorMsg);
		UTbNamesLibrary::toTbNamesEnum_With_Under_scores(cppEnumValue, int_value);
	}
	else
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("Enum EnumWithUnderScores::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray TbNamesDataJavaConverter::makeJavaEnumWithUnderScoresArray(JNIEnv* env, const TArray<ETbNamesEnum_With_Under_scores>& cppArray)
{
	if (TbNamesJniCache::javaEnumEnumWithUnderScores == nullptr)
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("Enum EnumWithUnderScores not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbNamesJniCache::javaEnumEnumWithUnderScores, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate EnumWithUnderScores jarray.");
	checkJniError(errorMsgAlloc);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnumWithUnderScores(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of EnumWithUnderScores array.");
		checkJniError(errorMsg);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject TbNamesDataJavaConverter::makeJavaEnumWithUnderScores(JNIEnv* env, ETbNamesEnum_With_Under_scores value)
{
	if (TbNamesJniCache::javaEnumEnumWithUnderScoresFromValueMethodId == nullptr)
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("Enum EnumWithUnderScores::fromValue not found"));
		return nullptr;
	}
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(TbNamesJniCache::javaEnumEnumWithUnderScores, TbNamesJniCache::javaEnumEnumWithUnderScoresFromValueMethodId, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for EnumWithUnderScores.");
	checkJniError(errorMsg);
	return javaObj;
}

void TbNamesDataJavaConverter::fillNamEs(JNIEnv* env, jobject input, TScriptInterface<ITbNamesNamEsInterface> out_nam_es)
{
	if (!input || !out_nam_es)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbNamesDataJavaConverter::fillNamEsArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbNamesNamEsInterface>>& out_array)
{
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbNamesDataJavaConverter::makeJavaNamEs(JNIEnv* env, const TScriptInterface<ITbNamesNamEsInterface> out_nam_es)
{
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
	if (!TbNamesJniCache::javaClassNamEs)
	{
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("INamEs not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, TbNamesJniCache::javaClassNamEs, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_nam_es.");
	checkJniError(errorMsg);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbNamesNamEsInterface> TbNamesDataJavaConverter::getCppInstanceTbNamesNamEs()
{
	UTbNamesNamEsImplementation* Impl = NewObject<UTbNamesNamEsImplementation>();
	TScriptInterface<ITbNamesNamEsInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbNamesNamEsInterface>(Impl));
	return wrapped;
}

void TbNamesDataJavaConverter::checkJniError(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Warning, TEXT("%s"), Msg);
	}
}

#endif
