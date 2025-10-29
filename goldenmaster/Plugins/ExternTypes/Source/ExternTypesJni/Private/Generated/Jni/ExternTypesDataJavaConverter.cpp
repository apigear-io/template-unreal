
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



void ExternTypesDataJavaConverter::fillMyVector3D(JNIEnv* env, jobject input, FVector& out_my_vector3_d)
{
    jclass cls = env->GetObjectClass(input);

    // do the serialization field by field: e.g. for int type field
    // jfieldID jFieldId_firstField = env->GetFieldID(cls, "firstField", "I");
    // out_my_vector3_d.FirstField = env->GetIntField(input, jFieldId_firstField);
}

void ExternTypesDataJavaConverter::fillMyVector3DArray(JNIEnv* env, jobjectArray input, TArray<FVector>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillMyVector3D(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}
jobject ExternTypesDataJavaConverter::makeJavaMyVector3D(JNIEnv* env, const FVector& out_my_vector3_d)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("org/apache/commons/math3/geometry/euclidean/threed/Vector3D");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    // do the serialization field by field: e.g. for int type field
    // jfieldID jFieldId_firstField = env->GetFieldID(javaClass, "jFieldId_firstField", "I");
    // env->SetIntField(javaObjInstance, jFieldId_firstField, out_my_vector3_d.FirstField);
    return javaObjInstance;
}

jobjectArray ExternTypesDataJavaConverter::makeJavaMyVector3DArray(JNIEnv* env, const TArray<FVector>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("org/apache/commons/math3/geometry/euclidean/threed/Vector3D");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaMyVector3D(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}


#endif
