
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

#include "TbRefIfaces/Generated/Jni/TbRefIfacesDataJavaConverter.h"
#include "TbIfaceimport/Generated/Jni/TbIfaceimportDataJavaConverter.h"
#include "TbIfaceimport/Generated/api/TbIfaceimport_data.h"
#include "TbRefIfaces/Implementation/TbRefIfacesSimpleLocalIf.h"
#include "TbRefIfaces/Implementation/TbRefIfacesParentIf.h"

#include "Generated/Detail/TbRefIfacesCommonJavaConverter.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

DEFINE_LOG_CATEGORY(LogTbRefIfacesDataJavaConverter_JNI);

struct FTbRefIfacesDataJavaConverterCacheData
{
	jclass jSimpleLocalIf = nullptr;
	jclass jParentIf = nullptr;

	~FTbRefIfacesDataJavaConverterCacheData()
	{
		JNIEnv* Env = FAndroidApplication::GetJavaEnv();
		if (Env)
		{
			if (jSimpleLocalIf)
			{
				Env->DeleteGlobalRef(jSimpleLocalIf);
			}
			if (jParentIf)
			{
				Env->DeleteGlobalRef(jParentIf);
			}
		}
	}
};

FCriticalSection TbRefIfacesDataJavaConverter::CacheLock;
TSharedPtr<FTbRefIfacesDataJavaConverterCacheData, ESPMode::ThreadSafe> TbRefIfacesDataJavaConverter::CacheData;

void TbRefIfacesDataJavaConverter::fillSimpleLocalIf(JNIEnv* env, jobject input, TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> out_simple_local_if)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbRefIfacesDataJavaConverter_JNI, Warning, TEXT("TbRefIfacesDataJavaConverter cache not initialized for fillSimpleLocalIf"));
		return;
	}
	if (!input || !out_simple_local_if)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbRefIfacesDataJavaConverter::fillSimpleLocalIfArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbRefIfacesDataJavaConverter_JNI, Warning, TEXT("TbRefIfacesDataJavaConverter cache not initialized for fillSimpleLocalIfArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbRefIfacesDataJavaConverter::makeJavaSimpleLocalIf(JNIEnv* env, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> out_simple_local_if)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbRefIfacesDataJavaConverter_JNI, Warning, TEXT("TbRefIfacesDataJavaConverter cache not initialized for makeJavaSimpleLocalIf"));
		return nullptr;
	}
	if (!out_simple_local_if)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbRefIfacesDataJavaConverter::makeJavaSimpleLocalIfArray(JNIEnv* env, const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jSimpleLocalIf)
	{
		UE_LOG(LogTbRefIfacesDataJavaConverter_JNI, Warning, TEXT("ISimpleLocalIf not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jSimpleLocalIf, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_simple_local_if.");
	if (CheckJniErrorOccurred(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> TbRefIfacesDataJavaConverter::getCppInstanceTbRefIfacesSimpleLocalIf()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbRefIfacesDataJavaConverter_JNI, Warning, TEXT("TbRefIfacesDataJavaConverter cache not initialized for getCppInstanceTbRefIfacesSimpleLocalIf"));
		return nullptr;
	}
	UTbRefIfacesSimpleLocalIfImplementation* Impl = NewObject<UTbRefIfacesSimpleLocalIfImplementation>();
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbRefIfacesSimpleLocalIfInterface>(Impl));
	return wrapped;
}

void TbRefIfacesDataJavaConverter::fillParentIf(JNIEnv* env, jobject input, TScriptInterface<ITbRefIfacesParentIfInterface> out_parent_if)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbRefIfacesDataJavaConverter_JNI, Warning, TEXT("TbRefIfacesDataJavaConverter cache not initialized for fillParentIf"));
		return;
	}
	if (!input || !out_parent_if)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbRefIfacesDataJavaConverter::fillParentIfArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbRefIfacesParentIfInterface>>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbRefIfacesDataJavaConverter_JNI, Warning, TEXT("TbRefIfacesDataJavaConverter cache not initialized for fillParentIfArray"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbRefIfacesDataJavaConverter::makeJavaParentIf(JNIEnv* env, const TScriptInterface<ITbRefIfacesParentIfInterface> out_parent_if)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbRefIfacesDataJavaConverter_JNI, Warning, TEXT("TbRefIfacesDataJavaConverter cache not initialized for makeJavaParentIf"));
		return nullptr;
	}
	if (!out_parent_if)
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray TbRefIfacesDataJavaConverter::makeJavaParentIfArray(JNIEnv* env, const TArray<TScriptInterface<ITbRefIfacesParentIfInterface>>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jParentIf)
	{
		UE_LOG(LogTbRefIfacesDataJavaConverter_JNI, Warning, TEXT("IParentIf not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jParentIf, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for out_parent_if.");
	if (CheckJniErrorOccurred(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbRefIfacesParentIfInterface> TbRefIfacesDataJavaConverter::getCppInstanceTbRefIfacesParentIf()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogTbRefIfacesDataJavaConverter_JNI, Warning, TEXT("TbRefIfacesDataJavaConverter cache not initialized for getCppInstanceTbRefIfacesParentIf"));
		return nullptr;
	}
	UTbRefIfacesParentIfImplementation* Impl = NewObject<UTbRefIfacesParentIfImplementation>();
	TScriptInterface<ITbRefIfacesParentIfInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbRefIfacesParentIfInterface>(Impl));
	return wrapped;
}

bool TbRefIfacesDataJavaConverter::CheckJniErrorOccurred(const TCHAR* Msg)
{
	return FTbRefIfacesCommonJavaConverter::CheckJniErrorOccurred(Msg);
}

void TbRefIfacesDataJavaConverter::cleanJavaReferences()
{
	FScopeLock Lock(&CacheLock);
	CacheData.Reset();
}

TSharedPtr<FTbRefIfacesDataJavaConverterCacheData, ESPMode::ThreadSafe> TbRefIfacesDataJavaConverter::ensureInitialized()
{
	{
		FScopeLock Lock(&CacheLock);
		if (CacheData)
		{
			return CacheData;
		}
	}

	auto NewData = MakeShared<FTbRefIfacesDataJavaConverterCacheData, ESPMode::ThreadSafe>();
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	NewData->jSimpleLocalIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfaces_api/ISimpleLocalIf");
	static const TCHAR* errorMsgSimpleLocalIf = TEXT("failed to get tbRefIfaces/tbRefIfaces_api/ISimpleLocalIf");
	CheckJniErrorOccurred(errorMsgSimpleLocalIf);
	NewData->jParentIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfaces_api/IParentIf");
	static const TCHAR* errorMsgParentIf = TEXT("failed to get tbRefIfaces/tbRefIfaces_api/IParentIf");
	CheckJniErrorOccurred(errorMsgParentIf);

	{
		FScopeLock Lock(&CacheLock);
		if (!CacheData)
		{
			CacheData = NewData;
		}
		return CacheData;
	}
}

jmethodID TbRefIfacesDataJavaConverter::getMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetMethodID(cls, name, signature);
	CheckJniErrorOccurred(errorMsgInfo);
	return method;
}

jmethodID TbRefIfacesDataJavaConverter::getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetStaticMethodID(cls, name, signature);
	CheckJniErrorOccurred(errorMsgInfo);
	return method;
}

jfieldID TbRefIfacesDataJavaConverter::getFieldId(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jfieldID field = env->GetFieldID(cls, name, signature);
	CheckJniErrorOccurred(errorMsgInfo);
	return field;
}

#endif
