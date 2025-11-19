
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
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("x field in FCustomTypesVector3D not found"));
	}

	jfieldID jFieldId_y = CustomTypesJniCache::javaStructVector3DYFieldId;
	if (jFieldId_y)
	{
		out_vector3_d.y = env->GetFloatField(input, jFieldId_y);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("y field in FCustomTypesVector3D not found"));
	}

	jfieldID jFieldId_z = CustomTypesJniCache::javaStructVector3DZFieldId;
	if (jFieldId_z)
	{
		out_vector3_d.z = env->GetFloatField(input, jFieldId_z);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("z field in FCustomTypesVector3D not found"));
	}
}

void CustomTypesDataJavaConverter::fillVector3DArray(JNIEnv* env, jobjectArray input, TArray<FCustomTypesVector3D>& out_array)
{
	jsize len = env->GetArrayLength(input);
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
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

	jfieldID jFieldId_x = CustomTypesJniCache::javaStructVector3DXFieldId;
	if (jFieldId_x != nullptr)
	{
		env->SetFloatField(javaObjInstance, jFieldId_x, in_vector3_d.x);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("x field in FCustomTypesVector3D not found"));
	}

	jfieldID jFieldId_y = CustomTypesJniCache::javaStructVector3DYFieldId;
	if (jFieldId_y != nullptr)
	{
		env->SetFloatField(javaObjInstance, jFieldId_y, in_vector3_d.y);
	}
	else
	{
		UE_LOG(LogCustomTypesDataJavaConverter_JNI, Warning, TEXT("y field in FCustomTypesVector3D not found"));
	}

	jfieldID jFieldId_z = CustomTypesJniCache::javaStructVector3DZFieldId;
	if (jFieldId_z != nullptr)
	{
		env->SetFloatField(javaObjInstance, jFieldId_z, in_vector3_d.z);
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

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaVector3D(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

#endif
