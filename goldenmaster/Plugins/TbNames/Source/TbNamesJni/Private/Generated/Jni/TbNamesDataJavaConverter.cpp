
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

DEFINE_LOG_CATEGORY(LogTbNamesDataJavaConverter_JNI);
jclass TbNamesDataJavaConverter::jEnumWithUnderScores = nullptr;

void TbNamesDataJavaConverter::fillEnumWithUnderScoresArray(JNIEnv* env, jobjectArray input, TArray<ETbNamesEnum_With_Under_scores>& out_array)
{
	ensureInitialized();
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
	ensureInitialized();
	jclass javaStruct = jEnumWithUnderScores;
	jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
	int int_value = env->CallIntMethod(input, getValueMethod);
	UTbNamesLibrary::toTbNamesEnum_With_Under_scores(cppEnumValue, int_value);
	return cppEnumValue;
}

jobjectArray TbNamesDataJavaConverter::makeJavaEnumWithUnderScoresArray(JNIEnv* env, const TArray<ETbNamesEnum_With_Under_scores>& cppArray)
{
	ensureInitialized();
	jclass javaStruct = jEnumWithUnderScores;
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
	ensureInitialized();
	jclass javaStruct = jEnumWithUnderScores;
	jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)LtbNames/tbNames_api/EnumWithUnderScores;");
	if (!fromValueMethod)
		return nullptr;
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
	return javaObj;
}
jclass TbNamesDataJavaConverter::jNamEs = nullptr;

void TbNamesDataJavaConverter::fillNamEs(JNIEnv* env, jobject input, TScriptInterface<ITbNamesNamEsInterface> out_nam_es)
{
	ensureInitialized();
	if (!input || !out_nam_es)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbNamesDataJavaConverter::fillNamEsArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbNamesNamEsInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbNamesDataJavaConverter::makeJavaNamEs(JNIEnv* env, const TScriptInterface<ITbNamesNamEsInterface> out_nam_es)
{
	ensureInitialized();
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
	ensureInitialized();
	jclass javaClass = jNamEs;
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaClass, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbNamesNamEsInterface> TbNamesDataJavaConverter::getCppInstanceTbNamesNamEs()
{
	ensureInitialized();
	UTbNamesNamEsImplementation* Impl = NewObject<UTbNamesNamEsImplementation>();
	TScriptInterface<ITbNamesNamEsInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbNamesNamEsInterface>(Impl));
	return wrapped;
}

bool TbNamesDataJavaConverter::checkJniErrorOccured(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbNamesDataJavaConverter_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

void TbNamesDataJavaConverter::cleanJavaReferences()
{
	FScopeLock Lock(&initMutex);
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(jEnumWithUnderScores);
	env->DeleteGlobalRef(jNamEs);
}

FCriticalSection TbNamesDataJavaConverter::initMutex;

bool TbNamesDataJavaConverter::m_isInitialized = false;

void TbNamesDataJavaConverter::ensureInitialized()
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
	jEnumWithUnderScores = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNames_api/EnumWithUnderScores");
	static const TCHAR* errorMsgEnumWithUnderScores= TEXT("failed to get tbNames/tbNames_api/EnumWithUnderScores");
	checkJniErrorOccured(errorMsgEnumWithUnderScores);
	jNamEs = FAndroidApplication::FindJavaClassGlobalRef("tbNames/tbNames_api/INamEs");
	static const TCHAR* errorMsgNamEs= TEXT("failed to get tbNames/tbNames_api/INamEs");
	checkJniErrorOccured(errorMsgNamEs);
	m_isInitialized = true;
}

}
}

#endif
