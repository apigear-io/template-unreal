
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
#include "TbNames/Generated/api/TbNames_data.h"
#include "TbNames/Generated/api/TbNames_apig.h"
#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

#include "Engine/Engine.h"


class  TBNAMESAPI_API TbNamesDataJavaConverter{
public:

	static void fillEnumWithUnderScoresArray(JNIEnv* env, jobjectArray input, TArray<ETbNamesEnum_With_Under_scores>& out_array);
	static ETbNamesEnum_With_Under_scores getEnumWithUnderScoresValue(JNIEnv* env, jobject input);
	static jobjectArray makeJavaEnumWithUnderScoresArray(JNIEnv* env, const TArray<ETbNamesEnum_With_Under_scores>& cppArray);
	static jobject makeJavaEnumWithUnderScores(JNIEnv* env, ETbNamesEnum_With_Under_scores value);

	static void fillNamEs(JNIEnv* env, jobject input, TScriptInterface<ITbNamesNamEsInterface> out_nam_es);
	static void fillNamEsArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbNamesNamEsInterface>>& out_array);
	static jobject makeJavaNamEs(JNIEnv* env, const TScriptInterface<ITbNamesNamEsInterface> out_nam_es);
	static jobjectArray makeJavaNamEsArray(JNIEnv* env, const TArray<TScriptInterface<ITbNamesNamEsInterface>>& cppArray);

	static TScriptInterface<ITbNamesNamEsInterface> getCppInstanceTbNamesNamEs();
};

#endif
