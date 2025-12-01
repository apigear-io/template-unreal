
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
#include "ExternTypes/Generated/Jni/ExternTypesJniCache.h"
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

void ExternTypesDataJavaConverter::fillMyVector3D(JNIEnv* env, jobject input, FVector& out_my_vector3_d)
{
	if (!ExternTypesJniCache::javaClassMyVector3D)
	{
		UE_LOG(LogExternTypesDataJavaConverter_JNI, Warning, TEXT("org/apache/commons/math3/geometry/euclidean/threed/Vector3D not found"));
		return;
	}

	// do the serialization field by field: e.g. for int type field
	// jfieldID jFieldId_firstField = env->GetFieldID(cls, "firstField", "I");
	// out_my_vector3_d.FirstField = env->GetIntField(input, jFieldId_firstField);
}

void ExternTypesDataJavaConverter::fillMyVector3DArray(JNIEnv* env, jobjectArray input, TArray<FVector>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get len of Vector3D jarray.");
	checkJniError(errorMsgLen);
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of Vector3D jarray.");
		checkJniError(errorMsg);
		fillMyVector3D(env, element, out_array[i]);
		env->DeleteLocalRef(element);
	}
}

jobject ExternTypesDataJavaConverter::makeJavaMyVector3D(JNIEnv* env, const FVector& out_my_vector3_d)
{
	if (!ExternTypesJniCache::javaClassMyVector3DCtor)
	{
		UE_LOG(LogExternTypesDataJavaConverter_JNI, Warning, TEXT("org/apache/commons/math3/geometry/euclidean/threed/Vector3D  ctor not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(ExternTypesJniCache::javaClassMyVector3D, ExternTypesJniCache::javaClassMyVector3DCtor);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate Vector3D.");
	checkJniError(errorMsgAlloc);

	// do the serialization field by field: e.g. for int type field
	// jfieldID jFieldId_firstField = env->GetFieldID(ExternTypesJniCache::javaClassMyVector3D, "jFieldId_firstField", "I");
	// env->SetIntField(javaObjInstance, jFieldId_firstField, out_my_vector3_d.FirstField);
	return javaObjInstance;
}

jobjectArray ExternTypesDataJavaConverter::makeJavaMyVector3DArray(JNIEnv* env, const TArray<FVector>& cppArray)
{
	if (!ExternTypesJniCache::javaClassMyVector3D)
	{
		UE_LOG(LogExternTypesDataJavaConverter_JNI, Warning, TEXT("org/apache/commons/math3/geometry/euclidean/threed/Vector3D not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, ExternTypesJniCache::javaClassMyVector3D, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate Vector3D jarray.");
	checkJniError(errorMsgAlloc);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaMyVector3D(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of Vector3D array.");
		checkJniError(errorMsg);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void ExternTypesDataJavaConverter::checkJniError(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogExternTypesDataJavaConverter_JNI, Warning, TEXT("%s"), Msg);
	}
}

#endif
