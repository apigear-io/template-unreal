
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

#include "CustomTypes/Generated/Jni/CustomTypesDataJavaConverter.h"
#include "CustomTypes/Generated/api/CustomTypes_data.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#if PLATFORM_ANDROID && USE_ANDROID_JNI

DEFINE_LOG_CATEGORY(LogCustomTypesDataJavaConverter_JNI);

struct FCustomTypesDataJavaConverterCacheData
{
	jclass jVector3D = nullptr;

	~FCustomTypesDataJavaConverterCacheData()
	{
		JNIEnv* Env = FAndroidApplication::GetJavaEnv();
		if (Env)
		{
			if (jVector3D)
			{
				Env->DeleteGlobalRef(jVector3D);
			}
		}
	}
};

FCriticalSection CustomTypesDataJavaConverter::CacheLock;
TSharedPtr<FCustomTypesDataJavaConverterCacheData, ESPMode::ThreadSafe> CustomTypesDataJavaConverter::CacheData;

void CustomTypesDataJavaConverter::fillVector3D(JNIEnv* env, jobject input, FCustomTypesVector3D& out_vector3_d)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("CustomTypesDataJavaConverter cache not initialized for fillVector3D"));
		return;
	}

	static const TCHAR* errorMsgFindx = TEXT("failed when trying to field x F for FCustomTypesVector3D");
	static const jfieldID jFieldId_x = getFieldId(Cache->jVector3D, "x", "F", errorMsgFindx);

	if (jFieldId_x)
	{
		out_vector3_d.x = env->GetFloatField(input, jFieldId_x);
		static const TCHAR* errorMsgx = TEXT("failed when getting the jFieldId_x for out_vector3_d.x");
		checkJniErrorOccured(errorMsgx);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("x field in FCustomTypesVector3D not found"));
	}

	static const TCHAR* errorMsgFindy = TEXT("failed when trying to field y F for FCustomTypesVector3D");
	static const jfieldID jFieldId_y = getFieldId(Cache->jVector3D, "y", "F", errorMsgFindy);

	if (jFieldId_y)
	{
		out_vector3_d.y = env->GetFloatField(input, jFieldId_y);
		static const TCHAR* errorMsgy = TEXT("failed when getting the jFieldId_y for out_vector3_d.y");
		checkJniErrorOccured(errorMsgy);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("y field in FCustomTypesVector3D not found"));
	}

	static const TCHAR* errorMsgFindz = TEXT("failed when trying to field z F for FCustomTypesVector3D");
	static const jfieldID jFieldId_z = getFieldId(Cache->jVector3D, "z", "F", errorMsgFindz);

	if (jFieldId_z)
	{
		out_vector3_d.z = env->GetFloatField(input, jFieldId_z);
		static const TCHAR* errorMsgz = TEXT("failed when getting the jFieldId_z for out_vector3_d.z");
		checkJniErrorOccured(errorMsgz);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("z field in FCustomTypesVector3D not found"));
	}
}

void CustomTypesDataJavaConverter::fillVector3DArray(JNIEnv* env, jobjectArray input, TArray<FCustomTypesVector3D>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("CustomTypesDataJavaConverter cache not initialized for fillVector3DArray"));
		return;
	}
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_vector3_d array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_vector3_d array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fillVector3D(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

jobject CustomTypesDataJavaConverter::makeJavaVector3D(JNIEnv* env, const FCustomTypesVector3D& in_vector3_d)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("CustomTypesDataJavaConverter cache not initialized for makeJavaVector3D"));
		return nullptr;
	}

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for out_vector3_d.");
	static const jmethodID ctor = getMethod(Cache->jVector3D, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(Cache->jVector3D, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_vector3_d.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

	static const TCHAR* errorMsgFindx = TEXT("failed when trying to field x F for FCustomTypesVector3D");
	static const jfieldID jFieldId_x = getFieldId(Cache->jVector3D, "x", "F", errorMsgFindx);

	if (jFieldId_x != nullptr)
	{
		env->SetFloatField(javaObjInstance, jFieldId_x, in_vector3_d.x);
		static const TCHAR* errorMsgxSet = TEXT("failed when seting field for out_vector3_d.x");
		checkJniErrorOccured(errorMsgxSet);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("x field in FCustomTypesVector3D not found"));
	}

	static const TCHAR* errorMsgFindy = TEXT("failed when trying to field y F for FCustomTypesVector3D");
	static const jfieldID jFieldId_y = getFieldId(Cache->jVector3D, "y", "F", errorMsgFindy);

	if (jFieldId_y != nullptr)
	{
		env->SetFloatField(javaObjInstance, jFieldId_y, in_vector3_d.y);
		static const TCHAR* errorMsgySet = TEXT("failed when seting field for out_vector3_d.y");
		checkJniErrorOccured(errorMsgySet);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("y field in FCustomTypesVector3D not found"));
	}

	static const TCHAR* errorMsgFindz = TEXT("failed when trying to field z F for FCustomTypesVector3D");
	static const jfieldID jFieldId_z = getFieldId(Cache->jVector3D, "z", "F", errorMsgFindz);

	if (jFieldId_z != nullptr)
	{
		env->SetFloatField(javaObjInstance, jFieldId_z, in_vector3_d.z);
		static const TCHAR* errorMsgzSet = TEXT("failed when seting field for out_vector3_d.z");
		checkJniErrorOccured(errorMsgzSet);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("z field in FCustomTypesVector3D not found"));
	}
	return javaObjInstance;
}

jobjectArray CustomTypesDataJavaConverter::makeJavaVector3DArray(JNIEnv* env, const TArray<FCustomTypesVector3D>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->jVector3D)
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("FCustomTypesVector3D not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->jVector3D, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_vector3_d.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaVector3D(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_vector3_d jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

bool CustomTypesDataJavaConverter::checkJniErrorOccured(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

void CustomTypesDataJavaConverter::cleanJavaReferences()
{
	FScopeLock Lock(&CacheLock);
	CacheData.Reset();
}

TSharedPtr<FCustomTypesDataJavaConverterCacheData, ESPMode::ThreadSafe> CustomTypesDataJavaConverter::ensureInitialized()
{
	{
		FScopeLock Lock(&CacheLock);
		if (CacheData)
		{
			return CacheData;
		}
	}

	auto NewData = MakeShared<FCustomTypesDataJavaConverterCacheData, ESPMode::ThreadSafe>();
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	NewData->jVector3D = FAndroidApplication::FindJavaClassGlobalRef("customTypes/customTypes_api/Vector3D");
	static const TCHAR* errorMsgVector3D = TEXT("failed to get customTypes/customTypes_api/Vector3D");
	checkJniErrorOccured(errorMsgVector3D);

	{
		FScopeLock Lock(&CacheLock);
		if (!CacheData)
		{
			CacheData = NewData;
		}
		return CacheData;
	}
}

jmethodID CustomTypesDataJavaConverter::getMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jmethodID CustomTypesDataJavaConverter::getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetStaticMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jfieldID CustomTypesDataJavaConverter::getFieldId(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jfieldID field = env->GetFieldID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return field;
}

#endif
