
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

#include "TbSimple/Generated/Jni/TbSimpleDataJavaConverter.h"
#include "TbSimple/Implementation/TbSimpleVoidInterface.h"
#include "TbSimple/Implementation/TbSimpleSimpleInterface.h"
#include "TbSimple/Implementation/TbSimpleSimpleArrayInterface.h"
#include "TbSimple/Implementation/TbSimpleNoPropertiesInterface.h"
#include "TbSimple/Implementation/TbSimpleNoOperationsInterface.h"
#include "TbSimple/Implementation/TbSimpleNoSignalsInterface.h"
#include "TbSimple/Implementation/TbSimpleEmptyInterface.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

DEFINE_LOG_CATEGORY(LogTbSimpleDataJavaConverter_JNI);

struct FTbSimpleDataJavaConverterCacheData
{
	jclass jVoidInterface = nullptr;
	jclass jSimpleInterface = nullptr;
	jclass jSimpleArrayInterface = nullptr;
	jclass jNoPropertiesInterface = nullptr;
	jclass jNoOperationsInterface = nullptr;
	jclass jNoSignalsInterface = nullptr;
	jclass jEmptyInterface = nullptr;

	~FTbSimpleDataJavaConverterCacheData()
	{
		JNIEnv* Env = FAndroidApplication::GetJavaEnv();
		if (Env)
		{
			if (jVoidInterface) Env->DeleteGlobalRef(jVoidInterface);
			if (jSimpleInterface) Env->DeleteGlobalRef(jSimpleInterface);
			if (jSimpleArrayInterface) Env->DeleteGlobalRef(jSimpleArrayInterface);
			if (jNoPropertiesInterface) Env->DeleteGlobalRef(jNoPropertiesInterface);
			if (jNoOperationsInterface) Env->DeleteGlobalRef(jNoOperationsInterface);
			if (jNoSignalsInterface) Env->DeleteGlobalRef(jNoSignalsInterface);
			if (jEmptyInterface) Env->DeleteGlobalRef(jEmptyInterface);
		}
	}
};

FCriticalSection TbSimpleDataJavaConverter::CacheLock;
TSharedPtr<FTbSimpleDataJavaConverterCacheData, ESPMode::ThreadSafe> TbSimpleDataJavaConverter::CacheData;

void TbSimpleDataJavaConverter::fillVoidInterface(JNIEnv* env, jobject input, TScriptInterface<ITbSimpleVoidInterfaceInterface> out_void_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for fillVoidInterface"));
		return;
	}
	if (!input || !out_void_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSimpleDataJavaConverter::fillVoidInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSimpleVoidInterfaceInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for fillVoidInterfaceArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSimpleDataJavaConverter::makeJavaVoidInterface(JNIEnv* env, const TScriptInterface<ITbSimpleVoidInterfaceInterface> out_void_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for makeJavaVoidInterface"));
		return nullptr;
	}
	if (!out_void_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSimpleDataJavaConverter::makeJavaVoidInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSimpleVoidInterfaceInterface>>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jVoidInterface)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("IVoidInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jVoidInterface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_void_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSimpleVoidInterfaceInterface> TbSimpleDataJavaConverter::getCppInstanceTbSimpleVoidInterface()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for getCppInstanceTbSimpleVoidInterface"));
		return nullptr;
	}
	UTbSimpleVoidInterfaceImplementation* Impl = NewObject<UTbSimpleVoidInterfaceImplementation>();
	TScriptInterface<ITbSimpleVoidInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSimpleVoidInterfaceInterface>(Impl));
	return wrapped;
}

void TbSimpleDataJavaConverter::fillSimpleInterface(JNIEnv* env, jobject input, TScriptInterface<ITbSimpleSimpleInterfaceInterface> out_simple_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for fillSimpleInterface"));
		return;
	}
	if (!input || !out_simple_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSimpleDataJavaConverter::fillSimpleInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSimpleSimpleInterfaceInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for fillSimpleInterfaceArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSimpleDataJavaConverter::makeJavaSimpleInterface(JNIEnv* env, const TScriptInterface<ITbSimpleSimpleInterfaceInterface> out_simple_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for makeJavaSimpleInterface"));
		return nullptr;
	}
	if (!out_simple_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSimpleDataJavaConverter::makeJavaSimpleInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSimpleSimpleInterfaceInterface>>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jSimpleInterface)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("ISimpleInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jSimpleInterface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_simple_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSimpleSimpleInterfaceInterface> TbSimpleDataJavaConverter::getCppInstanceTbSimpleSimpleInterface()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for getCppInstanceTbSimpleSimpleInterface"));
		return nullptr;
	}
	UTbSimpleSimpleInterfaceImplementation* Impl = NewObject<UTbSimpleSimpleInterfaceImplementation>();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSimpleSimpleInterfaceInterface>(Impl));
	return wrapped;
}

void TbSimpleDataJavaConverter::fillSimpleArrayInterface(JNIEnv* env, jobject input, TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> out_simple_array_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for fillSimpleArrayInterface"));
		return;
	}
	if (!input || !out_simple_array_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSimpleDataJavaConverter::fillSimpleArrayInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for fillSimpleArrayInterfaceArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSimpleDataJavaConverter::makeJavaSimpleArrayInterface(JNIEnv* env, const TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> out_simple_array_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for makeJavaSimpleArrayInterface"));
		return nullptr;
	}
	if (!out_simple_array_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSimpleDataJavaConverter::makeJavaSimpleArrayInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface>>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jSimpleArrayInterface)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("ISimpleArrayInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jSimpleArrayInterface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_simple_array_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> TbSimpleDataJavaConverter::getCppInstanceTbSimpleSimpleArrayInterface()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for getCppInstanceTbSimpleSimpleArrayInterface"));
		return nullptr;
	}
	UTbSimpleSimpleArrayInterfaceImplementation* Impl = NewObject<UTbSimpleSimpleArrayInterfaceImplementation>();
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSimpleSimpleArrayInterfaceInterface>(Impl));
	return wrapped;
}

void TbSimpleDataJavaConverter::fillNoPropertiesInterface(JNIEnv* env, jobject input, TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> out_no_properties_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for fillNoPropertiesInterface"));
		return;
	}
	if (!input || !out_no_properties_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSimpleDataJavaConverter::fillNoPropertiesInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for fillNoPropertiesInterfaceArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSimpleDataJavaConverter::makeJavaNoPropertiesInterface(JNIEnv* env, const TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> out_no_properties_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for makeJavaNoPropertiesInterface"));
		return nullptr;
	}
	if (!out_no_properties_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSimpleDataJavaConverter::makeJavaNoPropertiesInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface>>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jNoPropertiesInterface)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("INoPropertiesInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jNoPropertiesInterface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_no_properties_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> TbSimpleDataJavaConverter::getCppInstanceTbSimpleNoPropertiesInterface()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for getCppInstanceTbSimpleNoPropertiesInterface"));
		return nullptr;
	}
	UTbSimpleNoPropertiesInterfaceImplementation* Impl = NewObject<UTbSimpleNoPropertiesInterfaceImplementation>();
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSimpleNoPropertiesInterfaceInterface>(Impl));
	return wrapped;
}

void TbSimpleDataJavaConverter::fillNoOperationsInterface(JNIEnv* env, jobject input, TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> out_no_operations_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for fillNoOperationsInterface"));
		return;
	}
	if (!input || !out_no_operations_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSimpleDataJavaConverter::fillNoOperationsInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for fillNoOperationsInterfaceArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSimpleDataJavaConverter::makeJavaNoOperationsInterface(JNIEnv* env, const TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> out_no_operations_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for makeJavaNoOperationsInterface"));
		return nullptr;
	}
	if (!out_no_operations_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSimpleDataJavaConverter::makeJavaNoOperationsInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSimpleNoOperationsInterfaceInterface>>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jNoOperationsInterface)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("INoOperationsInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jNoOperationsInterface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_no_operations_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> TbSimpleDataJavaConverter::getCppInstanceTbSimpleNoOperationsInterface()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for getCppInstanceTbSimpleNoOperationsInterface"));
		return nullptr;
	}
	UTbSimpleNoOperationsInterfaceImplementation* Impl = NewObject<UTbSimpleNoOperationsInterfaceImplementation>();
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSimpleNoOperationsInterfaceInterface>(Impl));
	return wrapped;
}

void TbSimpleDataJavaConverter::fillNoSignalsInterface(JNIEnv* env, jobject input, TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> out_no_signals_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for fillNoSignalsInterface"));
		return;
	}
	if (!input || !out_no_signals_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSimpleDataJavaConverter::fillNoSignalsInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSimpleNoSignalsInterfaceInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for fillNoSignalsInterfaceArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSimpleDataJavaConverter::makeJavaNoSignalsInterface(JNIEnv* env, const TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> out_no_signals_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for makeJavaNoSignalsInterface"));
		return nullptr;
	}
	if (!out_no_signals_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSimpleDataJavaConverter::makeJavaNoSignalsInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSimpleNoSignalsInterfaceInterface>>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jNoSignalsInterface)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("INoSignalsInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jNoSignalsInterface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_no_signals_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> TbSimpleDataJavaConverter::getCppInstanceTbSimpleNoSignalsInterface()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for getCppInstanceTbSimpleNoSignalsInterface"));
		return nullptr;
	}
	UTbSimpleNoSignalsInterfaceImplementation* Impl = NewObject<UTbSimpleNoSignalsInterfaceImplementation>();
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSimpleNoSignalsInterfaceInterface>(Impl));
	return wrapped;
}

void TbSimpleDataJavaConverter::fillEmptyInterface(JNIEnv* env, jobject input, TScriptInterface<ITbSimpleEmptyInterfaceInterface> out_empty_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for fillEmptyInterface"));
		return;
	}
	if (!input || !out_empty_interface)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbSimpleDataJavaConverter::fillEmptyInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbSimpleEmptyInterfaceInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for fillEmptyInterfaceArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbSimpleDataJavaConverter::makeJavaEmptyInterface(JNIEnv* env, const TScriptInterface<ITbSimpleEmptyInterfaceInterface> out_empty_interface)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for makeJavaEmptyInterface"));
		return nullptr;
	}
	if (!out_empty_interface)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbSimpleDataJavaConverter::makeJavaEmptyInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbSimpleEmptyInterfaceInterface>>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jEmptyInterface)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("IEmptyInterface not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jEmptyInterface, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_empty_interface.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> TbSimpleDataJavaConverter::getCppInstanceTbSimpleEmptyInterface()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Warning, TEXT("TbSimpleDataJavaConverter cache not initialized for getCppInstanceTbSimpleEmptyInterface"));
		return nullptr;
	}
	UTbSimpleEmptyInterfaceImplementation* Impl = NewObject<UTbSimpleEmptyInterfaceImplementation>();
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbSimpleEmptyInterfaceInterface>(Impl));
	return wrapped;
}

bool TbSimpleDataJavaConverter::checkJniErrorOccured(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbSimpleDataJavaConverter_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

void TbSimpleDataJavaConverter::cleanJavaReferences()
{
	FScopeLock Lock(&CacheLock);
	CacheData.Reset();
}

TSharedPtr<FTbSimpleDataJavaConverterCacheData, ESPMode::ThreadSafe> TbSimpleDataJavaConverter::ensureInitialized()
{
	{
		FScopeLock Lock(&CacheLock);
		if (CacheData)
		{
			return CacheData;
		}
	}

	auto NewData = MakeShared<FTbSimpleDataJavaConverterCacheData, ESPMode::ThreadSafe>();
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	NewData->jVoidInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimple_api/IVoidInterface");
	static const TCHAR* errorMsgVoidInterface = TEXT("failed to get tbSimple/tbSimple_api/IVoidInterface");
	checkJniErrorOccured(errorMsgVoidInterface);
	NewData->jSimpleInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimple_api/ISimpleInterface");
	static const TCHAR* errorMsgSimpleInterface = TEXT("failed to get tbSimple/tbSimple_api/ISimpleInterface");
	checkJniErrorOccured(errorMsgSimpleInterface);
	NewData->jSimpleArrayInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimple_api/ISimpleArrayInterface");
	static const TCHAR* errorMsgSimpleArrayInterface = TEXT("failed to get tbSimple/tbSimple_api/ISimpleArrayInterface");
	checkJniErrorOccured(errorMsgSimpleArrayInterface);
	NewData->jNoPropertiesInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimple_api/INoPropertiesInterface");
	static const TCHAR* errorMsgNoPropertiesInterface = TEXT("failed to get tbSimple/tbSimple_api/INoPropertiesInterface");
	checkJniErrorOccured(errorMsgNoPropertiesInterface);
	NewData->jNoOperationsInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimple_api/INoOperationsInterface");
	static const TCHAR* errorMsgNoOperationsInterface = TEXT("failed to get tbSimple/tbSimple_api/INoOperationsInterface");
	checkJniErrorOccured(errorMsgNoOperationsInterface);
	NewData->jNoSignalsInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimple_api/INoSignalsInterface");
	static const TCHAR* errorMsgNoSignalsInterface = TEXT("failed to get tbSimple/tbSimple_api/INoSignalsInterface");
	checkJniErrorOccured(errorMsgNoSignalsInterface);
	NewData->jEmptyInterface = FAndroidApplication::FindJavaClassGlobalRef("tbSimple/tbSimple_api/IEmptyInterface");
	static const TCHAR* errorMsgEmptyInterface = TEXT("failed to get tbSimple/tbSimple_api/IEmptyInterface");
	checkJniErrorOccured(errorMsgEmptyInterface);

	{
		FScopeLock Lock(&CacheLock);
		if (!CacheData)
		{
			CacheData = NewData;
		}
		return CacheData;
	}
}

jmethodID TbSimpleDataJavaConverter::getMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jmethodID TbSimpleDataJavaConverter::getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetStaticMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jfieldID TbSimpleDataJavaConverter::getFieldId(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jfieldID field = env->GetFieldID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return field;
}

#endif
