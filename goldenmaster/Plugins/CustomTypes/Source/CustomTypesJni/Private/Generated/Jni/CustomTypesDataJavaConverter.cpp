
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
#include "CustomTypes/Generated/Jni/CustomTypesJniCache.h"
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

void CustomTypesDataJavaConverter::fillVector3D(JNIEnv* env, jobject input, FCustomTypesVector3D& out_vector3_d)
{

	jfieldID jFieldId_x = CustomTypesJniCache::javaStructVector3DXFieldId;
	if (jFieldId_x)
	{
		out_vector3_d.x = env->GetFloatField(input, jFieldId_x);
		static const TCHAR* errorMsgx = TEXT("failed when getting the jFieldId_x for out_vector3_d.x");
		checkJniError(errorMsgx);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("x field in FCustomTypesVector3D not found"));
	}

	jfieldID jFieldId_y = CustomTypesJniCache::javaStructVector3DYFieldId;
	if (jFieldId_y)
	{
		out_vector3_d.y = env->GetFloatField(input, jFieldId_y);
		static const TCHAR* errorMsgy = TEXT("failed when getting the jFieldId_y for out_vector3_d.y");
		checkJniError(errorMsgy);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("y field in FCustomTypesVector3D not found"));
	}

	jfieldID jFieldId_z = CustomTypesJniCache::javaStructVector3DZFieldId;
	if (jFieldId_z)
	{
		out_vector3_d.z = env->GetFloatField(input, jFieldId_z);
		static const TCHAR* errorMsgz = TEXT("failed when getting the jFieldId_z for out_vector3_d.z");
		checkJniError(errorMsgz);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("z field in FCustomTypesVector3D not found"));
	}
}

void CustomTypesDataJavaConverter::fillVector3DArray(JNIEnv* env, jobjectArray input, TArray<FCustomTypesVector3D>& out_array)
{
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of out_vector3_d array.");
	checkJniError(errorMsgLen);
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of out_vector3_d array.");
		checkJniError(errorMsg);
		fillVector3D(env, element, out_array[i]);
		env->DeleteLocalRef(element);
	}
}

jobject CustomTypesDataJavaConverter::makeJavaVector3D(JNIEnv* env, const FCustomTypesVector3D& in_vector3_d)
{
	jclass javaClass = CustomTypesJniCache::javaStructVector3D;
	if (CustomTypesJniCache::javaStructVector3DCtor == nullptr)
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("FCustomTypesVector3D not found"));
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(javaClass, CustomTypesJniCache::javaStructVector3DCtor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for out_vector3_d.");
	checkJniError(errorMsgObj);

	jfieldID jFieldId_x = CustomTypesJniCache::javaStructVector3DXFieldId;
	if (jFieldId_x != nullptr)
	{
		env->SetFloatField(javaObjInstance, jFieldId_x, in_vector3_d.x);
		static const TCHAR* errorMsgxSet = TEXT("failed when seting field for out_vector3_d.x");
		checkJniError(errorMsgxSet);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("x field in FCustomTypesVector3D not found"));
	}

	jfieldID jFieldId_y = CustomTypesJniCache::javaStructVector3DYFieldId;
	if (jFieldId_y != nullptr)
	{
		env->SetFloatField(javaObjInstance, jFieldId_y, in_vector3_d.y);
		static const TCHAR* errorMsgySet = TEXT("failed when seting field for out_vector3_d.y");
		checkJniError(errorMsgySet);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("y field in FCustomTypesVector3D not found"));
	}

	jfieldID jFieldId_z = CustomTypesJniCache::javaStructVector3DZFieldId;
	if (jFieldId_z != nullptr)
	{
		env->SetFloatField(javaObjInstance, jFieldId_z, in_vector3_d.z);
		static const TCHAR* errorMsgzSet = TEXT("failed when seting field for out_vector3_d.z");
		checkJniError(errorMsgzSet);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("z field in FCustomTypesVector3D not found"));
	}
	return javaObjInstance;
}

jobjectArray CustomTypesDataJavaConverter::makeJavaVector3DArray(JNIEnv* env, const TArray<FCustomTypesVector3D>& cppArray)
{
	if (CustomTypesJniCache::javaStructVector3D == nullptr)
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("FCustomTypesVector3D not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, CustomTypesJniCache::javaStructVector3D, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of out_vector3_d.");
	checkJniError(errorMsgAlloc);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaVector3D(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for out_vector3_d jarray.");
		checkJniError(errorMsg);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

void CustomTypesDataJavaConverter::checkJniError(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("%s"), Msg);
	}
}

#endif
