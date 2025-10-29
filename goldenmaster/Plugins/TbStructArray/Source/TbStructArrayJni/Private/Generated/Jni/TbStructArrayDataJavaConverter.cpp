
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

#include "TbStructArray/Generated/Jni/TbStructArrayDataJavaConverter.h"

#include "TbStructArray/Generated/api/TbStructArray_data.h"

#include "TbStructArray/Implementation/TbStructArrayStructArrayFieldInterface.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif


#if PLATFORM_ANDROID && USE_ANDROID_JNI



void TbStructArrayDataJavaConverter::fillPoint(JNIEnv* env, jobject input, FTbStructArrayPoint& out_point)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_x = env->GetFieldID(cls, "x", "F");
    out_point.x =  env->GetFloatField(input, jFieldId_x);
    
    jfieldID jFieldId_y = env->GetFieldID(cls, "y", "F");
    out_point.y =  env->GetFloatField(input, jFieldId_y);

}

void TbStructArrayDataJavaConverter::fillPointArray(JNIEnv* env, jobjectArray input, TArray<FTbStructArrayPoint>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillPoint(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject TbStructArrayDataJavaConverter::makeJavaPoint(JNIEnv* env, const FTbStructArrayPoint& in_point)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/Point");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_x = env->GetFieldID(javaClass, "x", "F");
    env->SetFloatField(javaObjInstance, jFieldId_x, in_point.x);
    
    jfieldID jFieldId_y = env->GetFieldID(javaClass, "y", "F");
    env->SetFloatField(javaObjInstance, jFieldId_y, in_point.y);
    return javaObjInstance;
}

jobjectArray TbStructArrayDataJavaConverter::makeJavaPointArray(JNIEnv* env, const TArray<FTbStructArrayPoint>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/Point");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaPoint(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void TbStructArrayDataJavaConverter::fillStructWithArrayOfStructs(JNIEnv* env, jobject input, FTbStructArrayStructWithArrayOfStructs& out_struct_with_array_of_structs)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_points = env->GetFieldID(cls, "points", "[LtbStructArray/tbStructArray_api/Point;");
    jobjectArray points_value = (jobjectArray)env->GetObjectField(input, jFieldId_points);
    fillPointArray(env, points_value, out_struct_with_array_of_structs.points);
    env->DeleteLocalRef(points_value);

}

void TbStructArrayDataJavaConverter::fillStructWithArrayOfStructsArray(JNIEnv* env, jobjectArray input, TArray<FTbStructArrayStructWithArrayOfStructs>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructWithArrayOfStructs(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject TbStructArrayDataJavaConverter::makeJavaStructWithArrayOfStructs(JNIEnv* env, const FTbStructArrayStructWithArrayOfStructs& in_struct_with_array_of_structs)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/StructWithArrayOfStructs");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_points = env->GetFieldID(javaClass, "points", "[LtbStructArray/tbStructArray_api/Point;");
    jobjectArray l_points = makeJavaPointArray(env, in_struct_with_array_of_structs.points);
    env->SetObjectField(javaObjInstance, jFieldId_points, l_points);
    env->DeleteLocalRef(l_points);
    return javaObjInstance;
}

jobjectArray TbStructArrayDataJavaConverter::makeJavaStructWithArrayOfStructsArray(JNIEnv* env, const TArray<FTbStructArrayStructWithArrayOfStructs>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/StructWithArrayOfStructs");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructWithArrayOfStructs(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void TbStructArrayDataJavaConverter::fillStructWithArrayOfEnums(JNIEnv* env, jobject input, FTbStructArrayStructWithArrayOfEnums& out_struct_with_array_of_enums)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_tags = env->GetFieldID(cls, "tags", "[LtbStructArray/tbStructArray_api/TestEnum;");
    jobjectArray tags_value = (jobjectArray)env->GetObjectField(input, jFieldId_tags);
    fillTestEnumArray(env, tags_value, out_struct_with_array_of_enums.tags);
    env->DeleteLocalRef(tags_value);

}

void TbStructArrayDataJavaConverter::fillStructWithArrayOfEnumsArray(JNIEnv* env, jobjectArray input, TArray<FTbStructArrayStructWithArrayOfEnums>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructWithArrayOfEnums(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject TbStructArrayDataJavaConverter::makeJavaStructWithArrayOfEnums(JNIEnv* env, const FTbStructArrayStructWithArrayOfEnums& in_struct_with_array_of_enums)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/StructWithArrayOfEnums");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_tags = env->GetFieldID(javaClass, "tags", "[LtbStructArray/tbStructArray_api/TestEnum;");
    jobjectArray l_tags = makeJavaTestEnumArray(env, in_struct_with_array_of_enums.tags);
    env->SetObjectField(javaObjInstance, jFieldId_tags, l_tags);
    env->DeleteLocalRef(l_tags);
    return javaObjInstance;
}

jobjectArray TbStructArrayDataJavaConverter::makeJavaStructWithArrayOfEnumsArray(JNIEnv* env, const TArray<FTbStructArrayStructWithArrayOfEnums>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/StructWithArrayOfEnums");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructWithArrayOfEnums(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void TbStructArrayDataJavaConverter::fillStructWithArrayOfInts(JNIEnv* env, jobject input, FTbStructArrayStructWithArrayOfInts& out_struct_with_array_of_ints)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_values = env->GetFieldID(cls, "values", "[I");
    jintArray values_value = (jintArray)env->GetObjectField(input, jFieldId_values);
    jsize lenvalues = env->GetArrayLength(values_value);
    out_struct_with_array_of_ints.values.AddUninitialized(lenvalues);
    env->GetIntArrayRegion(values_value, 0,  lenvalues,out_struct_with_array_of_ints.values.GetData());
    env->DeleteLocalRef(values_value);

}

void TbStructArrayDataJavaConverter::fillStructWithArrayOfIntsArray(JNIEnv* env, jobjectArray input, TArray<FTbStructArrayStructWithArrayOfInts>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructWithArrayOfInts(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject TbStructArrayDataJavaConverter::makeJavaStructWithArrayOfInts(JNIEnv* env, const FTbStructArrayStructWithArrayOfInts& in_struct_with_array_of_ints)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/StructWithArrayOfInts");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_values = env->GetFieldID(javaClass, "values", "[I");
    auto lenvalues = in_struct_with_array_of_ints.values.Num();
    jintArray l_values= env->NewIntArray(lenvalues);
    if (l_values  == NULL){/*Log error, skip?*/};
    env->SetIntArrayRegion(l_values, 0, lenvalues,in_struct_with_array_of_ints.values.GetData());
    env->SetObjectField(javaObjInstance, jFieldId_values, l_values);
    env->DeleteLocalRef(l_values);
    return javaObjInstance;
}

jobjectArray TbStructArrayDataJavaConverter::makeJavaStructWithArrayOfIntsArray(JNIEnv* env, const TArray<FTbStructArrayStructWithArrayOfInts>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/StructWithArrayOfInts");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructWithArrayOfInts(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void TbStructArrayDataJavaConverter::fillMixedStruct(JNIEnv* env, jobject input, FTbStructArrayMixedStruct& out_mixed_struct)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_id = env->GetFieldID(cls, "id", "I");
    out_mixed_struct.id =  env->GetIntField(input, jFieldId_id);
    
    jfieldID jFieldId_name = env->GetFieldID(cls, "name", "Ljava/lang/String;");
    jstring name_value = (jstring)env->GetObjectField(input, jFieldId_name);
    out_mixed_struct.name = FJavaHelper::FStringFromLocalRef(env,name_value);
    
    jfieldID jFieldId_origin = env->GetFieldID(cls, "origin", "LtbStructArray/tbStructArray_api/Point;");
    jobject origin_value = env->GetObjectField(input, jFieldId_origin);
    fillPoint(env, origin_value,out_mixed_struct.origin);
    env->DeleteLocalRef(origin_value);
    
    jfieldID jFieldId_points = env->GetFieldID(cls, "points", "[LtbStructArray/tbStructArray_api/Point;");
    jobjectArray points_value = (jobjectArray)env->GetObjectField(input, jFieldId_points);
    fillPointArray(env, points_value, out_mixed_struct.points);
    env->DeleteLocalRef(points_value);
    
    jfieldID jFieldId_flags = env->GetFieldID(cls, "flags", "[LtbStructArray/tbStructArray_api/TestEnum;");
    jobjectArray flags_value = (jobjectArray)env->GetObjectField(input, jFieldId_flags);
    fillTestEnumArray(env, flags_value, out_mixed_struct.flags);
    env->DeleteLocalRef(flags_value);
    
    jfieldID jFieldId_scores = env->GetFieldID(cls, "scores", "[I");
    jintArray scores_value = (jintArray)env->GetObjectField(input, jFieldId_scores);
    jsize lenscores = env->GetArrayLength(scores_value);
    out_mixed_struct.scores.AddUninitialized(lenscores);
    env->GetIntArrayRegion(scores_value, 0,  lenscores,out_mixed_struct.scores.GetData());
    env->DeleteLocalRef(scores_value);

}

void TbStructArrayDataJavaConverter::fillMixedStructArray(JNIEnv* env, jobjectArray input, TArray<FTbStructArrayMixedStruct>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillMixedStruct(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject TbStructArrayDataJavaConverter::makeJavaMixedStruct(JNIEnv* env, const FTbStructArrayMixedStruct& in_mixed_struct)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/MixedStruct");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_id = env->GetFieldID(javaClass, "id", "I");
    env->SetIntField(javaObjInstance, jFieldId_id, in_mixed_struct.id);
    
    jfieldID jFieldId_name = env->GetFieldID(javaClass, "name", "Ljava/lang/String;");
    auto l_nameWrapper =  FJavaHelper::ToJavaString(env,in_mixed_struct.name);
    jstring l_name = static_cast<jstring>(env->NewLocalRef(*l_nameWrapper));
    env->SetObjectField(javaObjInstance, jFieldId_name, l_name);
    // in UE 5.6 no need for new local ref
    
    jfieldID jFieldId_origin = env->GetFieldID(javaClass, "origin", "LtbStructArray/tbStructArray_api/Point;");
    jobject l_origin = makeJavaPoint(env,in_mixed_struct.origin);
    env->SetObjectField(javaObjInstance, jFieldId_origin, l_origin);
    env->DeleteLocalRef(l_origin);
    
    jfieldID jFieldId_points = env->GetFieldID(javaClass, "points", "[LtbStructArray/tbStructArray_api/Point;");
    jobjectArray l_points = makeJavaPointArray(env, in_mixed_struct.points);
    env->SetObjectField(javaObjInstance, jFieldId_points, l_points);
    env->DeleteLocalRef(l_points);
    
    jfieldID jFieldId_flags = env->GetFieldID(javaClass, "flags", "[LtbStructArray/tbStructArray_api/TestEnum;");
    jobjectArray l_flags = makeJavaTestEnumArray(env, in_mixed_struct.flags);
    env->SetObjectField(javaObjInstance, jFieldId_flags, l_flags);
    env->DeleteLocalRef(l_flags);
    
    jfieldID jFieldId_scores = env->GetFieldID(javaClass, "scores", "[I");
    auto lenscores = in_mixed_struct.scores.Num();
    jintArray l_scores= env->NewIntArray(lenscores);
    if (l_scores  == NULL){/*Log error, skip?*/};
    env->SetIntArrayRegion(l_scores, 0, lenscores,in_mixed_struct.scores.GetData());
    env->SetObjectField(javaObjInstance, jFieldId_scores, l_scores);
    env->DeleteLocalRef(l_scores);
    return javaObjInstance;
}

jobjectArray TbStructArrayDataJavaConverter::makeJavaMixedStructArray(JNIEnv* env, const TArray<FTbStructArrayMixedStruct>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/MixedStruct");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaMixedStruct(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void TbStructArrayDataJavaConverter::fillTestEnumArray(JNIEnv* env, jobjectArray input, TArray<ETbStructArrayTestEnum>& out_array)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/TestEnum");
    out_array.Empty();
    jsize len = env->GetArrayLength(input);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        out_array.Add(getTestEnumValue(env, element));
        env->DeleteLocalRef(element);
    }
}

ETbStructArrayTestEnum TbStructArrayDataJavaConverter::getTestEnumValue(JNIEnv* env, jobject input)
{
    ETbStructArrayTestEnum cppEnumValue;
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/TestEnum");
    jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
    int int_value = env->CallIntMethod(input, getValueMethod);
    UTbStructArrayLibrary::toTbStructArrayTestEnum(cppEnumValue, int_value);
    return cppEnumValue;
}


jobjectArray TbStructArrayDataJavaConverter::makeJavaTestEnumArray(JNIEnv* env, const TArray<ETbStructArrayTestEnum>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/TestEnum");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaTestEnum(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

jobject TbStructArrayDataJavaConverter::makeJavaTestEnum(JNIEnv* env, ETbStructArrayTestEnum value)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/TestEnum");
    jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)LtbStructArray/tbStructArray_api/TestEnum;");
    if (!fromValueMethod) return nullptr;
    int int_value = (uint8)value;
    jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
    return javaObj;
}


void TbStructArrayDataJavaConverter::fillStructArrayFieldInterface(JNIEnv* env, jobject input, TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> out_struct_array_field_interface)
{
    if (!input || !out_struct_array_field_interface)
    {
        return;
    }
    // currently not supported, stub function generated for possible custom implementation
}

void TbStructArrayDataJavaConverter::fillStructArrayFieldInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface>>& out_array)
{
    // currently not supported, stub function generated for possible custom implementation
}
jobject TbStructArrayDataJavaConverter::makeJavaStructArrayFieldInterface(JNIEnv* env, const TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> out_struct_array_field_interface)
{
    if (!out_struct_array_field_interface)
    {
        return nullptr;
    }

    jobject javaObjInstance = nullptr;
    // currently not supported, stub function generated for possible custom implementation
    return javaObjInstance;
}

jobjectArray TbStructArrayDataJavaConverter::makeJavaStructArrayFieldInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface>>& cppArray)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("tbStructArray/tbStructArray_api/IStructArrayFieldInterface");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaClass, nullptr);
    // currently not supported, stub function generated for possible custom implementation 
    return javaArray;
}

TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> TbStructArrayDataJavaConverter::getCppInstanceTbStructArrayStructArrayFieldInterface()
{
    UTbStructArrayStructArrayFieldInterfaceImplementation* Impl = NewObject<UTbStructArrayStructArrayFieldInterfaceImplementation>();
    TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> wrapped;
    wrapped.SetObject(Impl);
    wrapped.SetInterface(Cast<ITbStructArrayStructArrayFieldInterfaceInterface>(Impl));
    return wrapped;
}


#endif
