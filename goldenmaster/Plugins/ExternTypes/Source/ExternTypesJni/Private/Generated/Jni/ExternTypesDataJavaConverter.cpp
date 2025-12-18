
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

jclass ExternTypesDataJavaConverter::jMyVector3D = nullptr;

void ExternTypesDataJavaConverter::fillMyVector3D(JNIEnv* env, jobject input, FVector& out_my_vector3_d)
{
	ensureInitialized();
	if (!jMyVector3D)
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
	ensureInitialized();
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get len of Vector3D jarray.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of Vector3D jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
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
	ensureInitialized();
	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for org/apache/commons/math3/geometry/euclidean/threed/Vector3D.");
	// Make sure either that the extern class has default ctor or provide proper signature and arguments.
	static const jmethodID ctor = getMethod(jMyVector3D, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(LogExternTypesDataJavaConverter_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(jMyVector3D, ctor);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate Vector3D.");
	if (checkJniErrorOccured(errorMsgAlloc))
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
	ensureInitialized();
	if (!jMyVector3D)
	{
		UE_LOG(LogExternTypesDataJavaConverter_JNI, Warning, TEXT("org/apache/commons/math3/geometry/euclidean/threed/Vector3D not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, jMyVector3D, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate Vector3D jarray.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaMyVector3D(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of Vector3D array.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

bool ExternTypesDataJavaConverter::checkJniErrorOccured(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogExternTypesDataJavaConverter_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

void ExternTypesDataJavaConverter::cleanJavaReferences()
{
	FScopeLock Lock(&initMutex);
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	env->DeleteGlobalRef(jMyVector3D);
}

FCriticalSection ExternTypesDataJavaConverter::initMutex;

bool ExternTypesDataJavaConverter::m_isInitialized = false;

void ExternTypesDataJavaConverter::ensureInitialized()
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
	jMyVector3D = FAndroidApplication::FindJavaClassGlobalRef("org/apache/commons/math3/geometry/euclidean/threed/Vector3D");
	static const TCHAR* errorMsgMyVector3D = TEXT("failed to get org/apache/commons/math3/geometry/euclidean/threed/Vector3D");
	checkJniErrorOccured(errorMsgMyVector3D);
	m_isInitialized = true;
}

jmethodID ExternTypesDataJavaConverter::getMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jmethodID ExternTypesDataJavaConverter::getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetStaticMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jfieldID ExternTypesDataJavaConverter::getFieldId(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jfieldID field = env->GetFieldID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return field;
}

#endif
