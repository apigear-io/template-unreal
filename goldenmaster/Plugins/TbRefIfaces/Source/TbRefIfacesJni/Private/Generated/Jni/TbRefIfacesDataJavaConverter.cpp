
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
jclass TbRefIfacesDataJavaConverter::jSimpleLocalIf = nullptr;

void TbRefIfacesDataJavaConverter::fillSimpleLocalIf(JNIEnv* env, jobject input, TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> out_simple_local_if)
{
	ensureInitialized();
	if (!input || !out_simple_local_if)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbRefIfacesDataJavaConverter::fillSimpleLocalIfArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbRefIfacesDataJavaConverter::makeJavaSimpleLocalIf(JNIEnv* env, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> out_simple_local_if)
{
	ensureInitialized();
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
	ensureInitialized();
	jclass javaClass = jSimpleLocalIf;
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaClass, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> TbRefIfacesDataJavaConverter::getCppInstanceTbRefIfacesSimpleLocalIf()
{
	ensureInitialized();
	UTbRefIfacesSimpleLocalIfImplementation* Impl = NewObject<UTbRefIfacesSimpleLocalIfImplementation>();
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbRefIfacesSimpleLocalIfInterface>(Impl));
	return wrapped;
}
jclass TbRefIfacesDataJavaConverter::jParentIf = nullptr;

void TbRefIfacesDataJavaConverter::fillParentIf(JNIEnv* env, jobject input, TScriptInterface<ITbRefIfacesParentIfInterface> out_parent_if)
{
	ensureInitialized();
	if (!input || !out_parent_if)
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void TbRefIfacesDataJavaConverter::fillParentIfArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbRefIfacesParentIfInterface>>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

jobject TbRefIfacesDataJavaConverter::makeJavaParentIf(JNIEnv* env, const TScriptInterface<ITbRefIfacesParentIfInterface> out_parent_if)
{
	ensureInitialized();
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
	ensureInitialized();
	jclass javaClass = jParentIf;
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaClass, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

TScriptInterface<ITbRefIfacesParentIfInterface> TbRefIfacesDataJavaConverter::getCppInstanceTbRefIfacesParentIf()
{
	ensureInitialized();
	UTbRefIfacesParentIfImplementation* Impl = NewObject<UTbRefIfacesParentIfImplementation>();
	TScriptInterface<ITbRefIfacesParentIfInterface> wrapped;
	wrapped.SetObject(Impl);
	wrapped.SetInterface(Cast<ITbRefIfacesParentIfInterface>(Impl));
	return wrapped;
}

bool TbRefIfacesDataJavaConverter::checkJniErrorOccured(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogTbRefIfacesDataJavaConverter_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

void TbRefIfacesDataJavaConverter::cleanJavaReferences()
{
	FScopeLock Lock(&initMutex);
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(jSimpleLocalIf);
	env->DeleteGlobalRef(jParentIf);
}

FCriticalSection TbRefIfacesDataJavaConverter::initMutex;

bool TbRefIfacesDataJavaConverter::m_isInitialized = false;

void TbRefIfacesDataJavaConverter::ensureInitialized()
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
	jSimpleLocalIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfaces_api/ISimpleLocalIf");
	static const TCHAR* errorMsgSimpleLocalIf= TEXT("failed to get tbRefIfaces/tbRefIfaces_api/ISimpleLocalIf");
	checkJniErrorOccured(errorMsgSimpleLocalIf);
	jParentIf = FAndroidApplication::FindJavaClassGlobalRef("tbRefIfaces/tbRefIfaces_api/IParentIf");
	static const TCHAR* errorMsgParentIf= TEXT("failed to get tbRefIfaces/tbRefIfaces_api/IParentIf");
	checkJniErrorOccured(errorMsgParentIf);
	m_isInitialized = true;
}

}
}

#endif
