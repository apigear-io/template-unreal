
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

#include "ExternTypes/Generated/Jni/ExternTypesDataJavaConverter.h"
#include "Runtime/Core/Public/Math/Vector.h"

#include "Generated/Detail/ExternTypesCommonJavaConverter.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

DEFINE_LOG_CATEGORY(LogExternTypesDataJavaConverter_JNI);

struct FExternTypesDataJavaConverterCacheData
{
	jclass jMyVector3D = nullptr;

	~FExternTypesDataJavaConverterCacheData()
	{
		JNIEnv* Env = FAndroidApplication::GetJavaEnv();
		if (Env)
		{
			if (jMyVector3D) Env->DeleteGlobalRef(jMyVector3D);
		}
	}
};

FCriticalSection ExternTypesDataJavaConverter::CacheLock;
TSharedPtr<FExternTypesDataJavaConverterCacheData, ESPMode::ThreadSafe> ExternTypesDataJavaConverter::CacheData;

void ExternTypesDataJavaConverter::fillMyVector3D(JNIEnv* env, jobject input, FVector& out_my_vector3_d)
{
	if (input == nullptr)
	{
		UE_LOG(LogExternTypesDataJavaConverter_JNI, Warning, TEXT("Cannot fill myVector3D, object is null"));
		return;
	}

	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jMyVector3D)
	{
		UE_LOG(LogExternTypesDataJavaConverter_JNI, Warning, TEXT("org/apache/commons/math3/geometry/euclidean/threed/Vector3D not found"));
		return;
	}

	// do the serialization field by field: e.g. for int type field
	// static const jfieldID jFieldId_firstField = env->GetFieldID(cls, "firstField", "I");
	// out_my_vector3_d.FirstField = env->GetIntField(input, jFieldId_firstField);
}

void ExternTypesDataJavaConverter::fillMyVector3DArray(JNIEnv* env, jobjectArray input, TArray<FVector>& out_array)
{
	if (input == nullptr)
	{
		UE_LOG(LogExternTypesDataJavaConverter_JNI, Warning, TEXT("Cannot fill myVector3D array, array object is null"));
		return;
	}

	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogExternTypesDataJavaConverter_JNI, Warning, TEXT("ExternTypesDataJavaConverter cache not initialized for fillMyVector3DArray"));
		return;
	}
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get len of Vector3D jarray.");
	if (CheckJniErrorOccurred(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of Vector3D jarray.");
		auto failed = CheckJniErrorOccurred(errorMsg);
		if (!failed)
		{
			fillMyVector3D(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject ExternTypesDataJavaConverter::makeJavaMyVector3D(JNIEnv* env, const FVector& out_my_vector3_d)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogExternTypesDataJavaConverter_JNI, Warning, TEXT("ExternTypesDataJavaConverter cache not initialized for makeJavaMyVector3D"));
		return nullptr;
	}
	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for org/apache/commons/math3/geometry/euclidean/threed/Vector3D.");
	// Make sure either that the extern class has default ctor or provide proper signature and arguments.
	static const jmethodID ctor = getMethod(Cache->jMyVector3D, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(LogExternTypesDataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(Cache->jMyVector3D, ctor);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate Vector3D.");
	if (CheckJniErrorOccurred(errorMsgAlloc))
	{
		return nullptr;
	}

	// do the serialization field by field: e.g. for int type field
	// jfieldID jFieldId_firstField = getField(jMyVector3D, "jFieldId_firstField", "I", "Error Message in case java exception");
	// env->SetIntField(javaObjInstance, jFieldId_firstField, out_my_vector3_d.FirstField);
	return javaObjInstance;
}

jobjectArray ExternTypesDataJavaConverter::makeJavaMyVector3DArray(JNIEnv* env, const TArray<FVector>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jMyVector3D)
	{
		UE_LOG(LogExternTypesDataJavaConverter_JNI, Warning, TEXT("org/apache/commons/math3/geometry/euclidean/threed/Vector3D not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jMyVector3D, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate Vector3D jarray.");
	if (CheckJniErrorOccurred(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaMyVector3D(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of Vector3D array.");
		auto failed = CheckJniErrorOccurred(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

bool ExternTypesDataJavaConverter::CheckJniErrorOccurred(const TCHAR* Msg)
{
	return FExternTypesCommonJavaConverter::CheckJniErrorOccurred(Msg);
}

void ExternTypesDataJavaConverter::cleanJavaReferences()
{
	FScopeLock Lock(&CacheLock);
	CacheData.Reset();
}

TSharedPtr<FExternTypesDataJavaConverterCacheData, ESPMode::ThreadSafe> ExternTypesDataJavaConverter::ensureInitialized()
{
	{
		FScopeLock Lock(&CacheLock);
		if (CacheData)
		{
			return CacheData;
		}
	}

	auto NewData = MakeShared<FExternTypesDataJavaConverterCacheData, ESPMode::ThreadSafe>();
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	NewData->jMyVector3D = FAndroidApplication::FindJavaClassGlobalRef("org/apache/commons/math3/geometry/euclidean/threed/Vector3D");
	static const TCHAR* errorMsgMyVector3D = TEXT("failed to get org/apache/commons/math3/geometry/euclidean/threed/Vector3D");
	CheckJniErrorOccurred(errorMsgMyVector3D);

	{
		FScopeLock Lock(&CacheLock);
		if (!CacheData)
		{
			CacheData = NewData;
		}
		return CacheData;
	}
}

jmethodID ExternTypesDataJavaConverter::getMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetMethodID(cls, name, signature);
	CheckJniErrorOccurred(errorMsgInfo);
	return method;
}

jmethodID ExternTypesDataJavaConverter::getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetStaticMethodID(cls, name, signature);
	CheckJniErrorOccurred(errorMsgInfo);
	return method;
}

jfieldID ExternTypesDataJavaConverter::getFieldId(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jfieldID field = env->GetFieldID(cls, name, signature);
	CheckJniErrorOccurred(errorMsgInfo);
	return field;
}

#endif
