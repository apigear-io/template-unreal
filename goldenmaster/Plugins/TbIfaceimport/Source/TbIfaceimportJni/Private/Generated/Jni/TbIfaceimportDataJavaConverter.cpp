
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

#include "TbIfaceimport/Generated/Jni/TbIfaceimportDataJavaConverter.h"
#include "TbIfaceimport/Implementation/TbIfaceimportEmptyIf.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

DEFINE_LOG_CATEGORY(LogTbIfaceimportDataJavaConverter_JNI);

jclass TbIfaceimportDataJavaConverter::jEmptyIf = nullptr;

void TbIfaceimportDataJavaConverter::fillEmptyIf(JNIEnv* env, jobject input, TScriptInterface<ITbIfaceimportEmptyIfInterface> out_empty_if)
{
	ensureInitialized();
	if (!input || !out_empty_if)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbIfaceimportDataJavaConverter::fillEmptyIfArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbIfaceimportDataJavaConverter::makeJavaEmptyIf(JNIEnv* env, const TScriptInterface<ITbIfaceimportEmptyIfInterface> out_empty_if)
{
	ensureInitialized();
	if (!out_empty_if)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbIfaceimportDataJavaConverter::makeJavaEmptyIfArray(JNIEnv* env, const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& cppArray)
{
	ensureInitialized();
	if (!jEmptyIf)
	{
		UE_LOG(LogTbIfaceimportDataJavaConverter_JNI, Warning, TEXT("IEmptyIf not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jEmptyIf, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_empty_if.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> TbIfaceimportDataJavaConverter::getCppInstanceTbIfaceimportEmptyIf()
{
	ensureInitialized();
	UTbIfaceimportEmptyIfImplementation* Impl = NewObject<UTbIfaceimportEmptyIfImplementation>();
	TScriptInterface<ITbIfaceimportEmptyIfInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbIfaceimportEmptyIfInterface>(Impl));
	return wrapped;
}

bool TbIfaceimportDataJavaConverter::checkJniErrorOccured(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbIfaceimportDataJavaConverter_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

void TbIfaceimportDataJavaConverter::cleanJavaReferences()
{
	FScopeLock Lock(&initMutex);
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(jEmptyIf);
}

FCriticalSection TbIfaceimportDataJavaConverter::initMutex;

bool TbIfaceimportDataJavaConverter::m_isInitialized = false;

void TbIfaceimportDataJavaConverter::ensureInitialized()
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
	jEmptyIf = FAndroidApplication::FindJavaClassGlobalRef("tbIfaceimport/tbIfaceimport_api/IEmptyIf");
	static const TCHAR* errorMsgEmptyIf= TEXT("failed to get tbIfaceimport/tbIfaceimport_api/IEmptyIf");
	checkJniErrorOccured(errorMsgEmptyIf);
	m_isInitialized = true;
}

jmethodID TbIfaceimportDataJavaConverter::getMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jmethodID TbIfaceimportDataJavaConverter::getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetStaticMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jfieldID TbIfaceimportDataJavaConverter::getFieldId(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jfieldID field = env->GetFieldID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return field;
}

#endif
