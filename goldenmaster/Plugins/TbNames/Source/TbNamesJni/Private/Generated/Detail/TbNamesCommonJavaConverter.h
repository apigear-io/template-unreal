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

#pragma once

#include "Algo/Transform.h"
#include "Containers/Array.h"
#include "Containers/UnrealString.h"
#include "HAL/Platform.h"
#include "HAL/UnrealMemory.h"
#include "Logging/LogMacros.h"
#include "Templates/UnrealTemplate.h"
#include <type_traits>

#if PLATFORM_ANDROID && USE_ANDROID_JNI

#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbNamesCommonJavaConverter_JNI, Log, All);

class FTbNamesCommonJavaConverter
{
public:
	static bool CheckJniErrorOccurred(const TCHAR* Msg);

	static bool TryFillArray(
		JNIEnv* Env, TArray<FString>& OutStringArray, jobjectArray InJniArray, const FString& InPropertyName);

	template <typename PrimitiveType>
	static std::enable_if<std::is_arithmetic<PrimitiveType>::value, bool>::type TryFillArray(
		JNIEnv* Env, TArray<PrimitiveType>& OutPrimitiveArray, jarray InJniArray, const FString& InPropertyName);

private:
	template <typename T, typename = void>
	struct HasConvertFromJniFunc : std::false_type
	{
	};

	template <typename T>
	struct HasConvertFromJniFunc<T, std::void_t<decltype(T::ConvertFromJni(std::declval<typename T::JniElementType>()))>> : std::true_type
	{
	};

	template <typename T>
	struct JniArrayTraits;

	FTbNamesCommonJavaConverter() = delete;
};

template <>
struct FTbNamesCommonJavaConverter::JniArrayTraits<bool>
{
	using JniArrayType = jbooleanArray;
	using JniElementType = jboolean;

	static constexpr auto GetArrayRegionFunc = &JNIEnv::GetBooleanArrayRegion;

	static bool ConvertFromJni(jboolean jniValue)
	{
		return jniValue == JNI_TRUE;
	}
};

template <>
struct FTbNamesCommonJavaConverter::JniArrayTraits<int32>
{
	using JniArrayType = jintArray;
	using JniElementType = jint;

	static constexpr auto GetArrayRegionFunc = &JNIEnv::GetIntArrayRegion;
};

template <>
struct FTbNamesCommonJavaConverter::JniArrayTraits<int64>
{
	using JniArrayType = jlongArray;
	using JniElementType = jlong;

	static constexpr auto GetArrayRegionFunc = &JNIEnv::GetLongArrayRegion;
};

template <>
struct FTbNamesCommonJavaConverter::JniArrayTraits<float>
{
	using JniArrayType = jfloatArray;
	using JniElementType = jfloat;

	static constexpr auto GetArrayRegionFunc = &JNIEnv::GetFloatArrayRegion;
};

template <>
struct FTbNamesCommonJavaConverter::JniArrayTraits<double>
{
	using JniArrayType = jdoubleArray;
	using JniElementType = jdouble;

	static constexpr auto GetArrayRegionFunc = &JNIEnv::GetDoubleArrayRegion;
};

template <typename PrimitiveType>
std::enable_if<std::is_arithmetic<PrimitiveType>::value, bool>::type
FTbNamesCommonJavaConverter::TryFillArray(
	JNIEnv* Env, TArray<PrimitiveType>& OutPrimitiveArray, jarray InJniArray, const FString& InPropertyName)
{
	using Traits = JniArrayTraits<PrimitiveType>;
	using JniArrayType = typename Traits::JniArrayType;
	using JniElement = typename Traits::JniElementType;
	constexpr auto GetArrayRegionFunc = Traits::GetArrayRegionFunc;

	JniArrayType JniArray = (JniArrayType)InJniArray;
	jsize JniArrayLength = Env->GetArrayLength(JniArray);
	if (CheckJniErrorOccurred(*FString::Printf(TEXT("failed to get array length of %s"), *InPropertyName)))
	{
		return false;
	}

	TArray<JniElement> TempJniArray;
	TempJniArray.SetNumUninitialized(JniArrayLength);
	(Env->*GetArrayRegionFunc)(JniArray, 0, JniArrayLength, TempJniArray.GetData());
	if (CheckJniErrorOccurred(*FString::Printf(TEXT("failed to get an array elements for %s"), *InPropertyName)))
	{
		return false;
	}

	TArray<PrimitiveType> Result;

	if constexpr (HasConvertFromJniFunc<Traits>::value)
	{
		Algo::Transform(TempJniArray, Result, Traits::ConvertFromJni);
	}
	else if constexpr (sizeof(PrimitiveType) == sizeof(JniElement))
	{
		Result.SetNum(JniArrayLength);
		FMemory::Memcpy(Result.GetData(), TempJniArray.GetData(), JniArrayLength * sizeof(JniElement));
	}
	else
	{
		Algo::Transform(TempJniArray, Result, [](JniElement V)
			{
			return static_cast<PrimitiveType>(V);
		});
	}

	Swap(Result, OutPrimitiveArray);

	return true;
}

#endif
