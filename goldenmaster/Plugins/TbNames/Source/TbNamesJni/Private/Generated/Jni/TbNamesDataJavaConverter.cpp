
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

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

void TbNamesDataJavaConverter::fillEnumWithUnderScoresArray(JNIEnv* env, jobjectArray input, TArray<ETbNamesEnum_With_Under_scores>& out_array)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNames_api/EnumWithUnderScores");
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		out_array.Add(getEnumWithUnderScoresValue(env, element));
		env->DeleteLocalRef(element);
	}
}

ETbNamesEnum_With_Under_scores TbNamesDataJavaConverter::getEnumWithUnderScoresValue(JNIEnv* env, jobject input)
{
	ETbNamesEnum_With_Under_scores cppEnumValue;
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNames_api/EnumWithUnderScores");
	jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
	int int_value = env->CallIntMethod(input, getValueMethod);
	UTbNamesLibrary::toTbNamesEnum_With_Under_scores(cppEnumValue, int_value);
	return cppEnumValue;
}

jobjectArray TbNamesDataJavaConverter::makeJavaEnumWithUnderScoresArray(JNIEnv* env, const TArray<ETbNamesEnum_With_Under_scores>& cppArray)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNames_api/EnumWithUnderScores");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaStruct, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaEnumWithUnderScores(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject TbNamesDataJavaConverter::makeJavaEnumWithUnderScores(JNIEnv* env, ETbNamesEnum_With_Under_scores value)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNames_api/EnumWithUnderScores");
	jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)LtbNames/tbNames_api/EnumWithUnderScores;");
	if (!fromValueMethod)
		return nullptr;
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
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
	jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNames_api/INamEs");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaClass, nullptr);
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

#endif
