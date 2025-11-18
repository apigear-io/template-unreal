
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

void CustomTypesDataJavaConverter::fillVector3D(JNIEnv* env, jobject input, FCustomTypesVector3D& out_vector3_d)
{
	jclass cls = env->GetObjectClass(input);

	jfieldID jFieldId_x = env->GetFieldID(cls, "x", "F");
	out_vector3_d.x = env->GetFloatField(input, jFieldId_x);

	jfieldID jFieldId_y = env->GetFieldID(cls, "y", "F");
	out_vector3_d.y = env->GetFloatField(input, jFieldId_y);

	jfieldID jFieldId_z = env->GetFieldID(cls, "z", "F");
	out_vector3_d.z = env->GetFloatField(input, jFieldId_z);
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
	jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("customTypes/customTypes_api/Vector3D");
	jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
	jobject javaObjInstance = env->NewObject(javaClass, ctor);

	jfieldID jFieldId_x = env->GetFieldID(javaClass, "x", "F");
	env->SetFloatField(javaObjInstance, jFieldId_x, in_vector3_d.x);

	jfieldID jFieldId_y = env->GetFieldID(javaClass, "y", "F");
	env->SetFloatField(javaObjInstance, jFieldId_y, in_vector3_d.y);

	jfieldID jFieldId_z = env->GetFieldID(javaClass, "z", "F");
	env->SetFloatField(javaObjInstance, jFieldId_z, in_vector3_d.z);
	return javaObjInstance;
}

jobjectArray CustomTypesDataJavaConverter::makeJavaVector3DArray(JNIEnv* env, const TArray<FCustomTypesVector3D>& cppArray)
{
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("customTypes/customTypes_api/Vector3D");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaStruct, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJavaVector3D(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

#endif
