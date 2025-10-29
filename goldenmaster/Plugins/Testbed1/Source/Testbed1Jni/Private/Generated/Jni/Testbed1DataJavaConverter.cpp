
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

#include "Testbed1/Generated/Jni/Testbed1DataJavaConverter.h"

#include "Testbed1/Generated/api/Testbed1_data.h"

#include "Testbed1/Implementation/Testbed1StructInterface.h"
#include "Testbed1/Implementation/Testbed1StructArrayInterface.h"
#include "Testbed1/Implementation/Testbed1StructArray2Interface.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif


#if PLATFORM_ANDROID && USE_ANDROID_JNI



void Testbed1DataJavaConverter::fillStructBool(JNIEnv* env, jobject input, FTestbed1StructBool& out_struct_bool)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field_bool = env->GetFieldID(cls, "fieldBool", "Z");
    out_struct_bool.fieldBool =  env->GetBooleanField(input, jFieldId_field_bool);

}

void Testbed1DataJavaConverter::fillStructBoolArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructBool>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructBool(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed1DataJavaConverter::makeJavaStructBool(JNIEnv* env, const FTestbed1StructBool& in_struct_bool)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructBool");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field_bool = env->GetFieldID(javaClass, "fieldBool", "Z");
    env->SetBooleanField(javaObjInstance, jFieldId_field_bool, in_struct_bool.fieldBool);
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructBoolArray(JNIEnv* env, const TArray<FTestbed1StructBool>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructBool");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructBool(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed1DataJavaConverter::fillStructInt(JNIEnv* env, jobject input, FTestbed1StructInt& out_struct_int)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field_int = env->GetFieldID(cls, "fieldInt", "I");
    out_struct_int.fieldInt =  env->GetIntField(input, jFieldId_field_int);

}

void Testbed1DataJavaConverter::fillStructIntArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructInt>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructInt(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed1DataJavaConverter::makeJavaStructInt(JNIEnv* env, const FTestbed1StructInt& in_struct_int)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructInt");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field_int = env->GetFieldID(javaClass, "fieldInt", "I");
    env->SetIntField(javaObjInstance, jFieldId_field_int, in_struct_int.fieldInt);
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructIntArray(JNIEnv* env, const TArray<FTestbed1StructInt>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructInt");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructInt(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed1DataJavaConverter::fillStructFloat(JNIEnv* env, jobject input, FTestbed1StructFloat& out_struct_float)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field_float = env->GetFieldID(cls, "fieldFloat", "F");
    out_struct_float.fieldFloat =  env->GetFloatField(input, jFieldId_field_float);

}

void Testbed1DataJavaConverter::fillStructFloatArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructFloat>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructFloat(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed1DataJavaConverter::makeJavaStructFloat(JNIEnv* env, const FTestbed1StructFloat& in_struct_float)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructFloat");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field_float = env->GetFieldID(javaClass, "fieldFloat", "F");
    env->SetFloatField(javaObjInstance, jFieldId_field_float, in_struct_float.fieldFloat);
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructFloatArray(JNIEnv* env, const TArray<FTestbed1StructFloat>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructFloat");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructFloat(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed1DataJavaConverter::fillStructString(JNIEnv* env, jobject input, FTestbed1StructString& out_struct_string)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field_string = env->GetFieldID(cls, "fieldString", "Ljava/lang/String;");
    jstring field_string_value = (jstring)env->GetObjectField(input, jFieldId_field_string);
    out_struct_string.fieldString = FJavaHelper::FStringFromLocalRef(env,field_string_value);

}

void Testbed1DataJavaConverter::fillStructStringArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructString>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructString(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed1DataJavaConverter::makeJavaStructString(JNIEnv* env, const FTestbed1StructString& in_struct_string)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructString");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field_string = env->GetFieldID(javaClass, "fieldString", "Ljava/lang/String;");
    auto l_fieldStringWrapper =  FJavaHelper::ToJavaString(env,in_struct_string.fieldString);
    jstring l_fieldString = static_cast<jstring>(env->NewLocalRef(*l_fieldStringWrapper));
    env->SetObjectField(javaObjInstance, jFieldId_field_string, l_fieldString);
    // in UE 5.6 no need for new local ref
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructStringArray(JNIEnv* env, const TArray<FTestbed1StructString>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructString");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructString(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed1DataJavaConverter::fillStructStruct(JNIEnv* env, jobject input, FTestbed1StructStruct& out_struct_struct)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field_string = env->GetFieldID(cls, "fieldString", "Ltestbed1/testbed1_api/StructString;");
    jobject field_string_value = env->GetObjectField(input, jFieldId_field_string);
    fillStructString(env, field_string_value,out_struct_struct.fieldString);
    env->DeleteLocalRef(field_string_value);

}

void Testbed1DataJavaConverter::fillStructStructArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructStruct>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructStruct(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed1DataJavaConverter::makeJavaStructStruct(JNIEnv* env, const FTestbed1StructStruct& in_struct_struct)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructStruct");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field_string = env->GetFieldID(javaClass, "fieldString", "Ltestbed1/testbed1_api/StructString;");
    jobject l_fieldString = makeJavaStructString(env,in_struct_struct.fieldString);
    env->SetObjectField(javaObjInstance, jFieldId_field_string, l_fieldString);
    env->DeleteLocalRef(l_fieldString);
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructStructArray(JNIEnv* env, const TArray<FTestbed1StructStruct>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructStruct");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructStruct(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed1DataJavaConverter::fillStructEnum(JNIEnv* env, jobject input, FTestbed1StructEnum& out_struct_enum)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field_enum = env->GetFieldID(cls, "fieldEnum", "Ltestbed1/testbed1_api/Enum0;");
    jobject field_enum_value = env->GetObjectField(input, jFieldId_field_enum);
    out_struct_enum.fieldEnum = getEnum0Value(env, field_enum_value);

}

void Testbed1DataJavaConverter::fillStructEnumArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructEnum>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructEnum(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed1DataJavaConverter::makeJavaStructEnum(JNIEnv* env, const FTestbed1StructEnum& in_struct_enum)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructEnum");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field_enum = env->GetFieldID(javaClass, "fieldEnum", "Ltestbed1/testbed1_api/Enum0;");
    jobject l_fieldEnum = makeJavaEnum0(env, in_struct_enum.fieldEnum);
    env->SetObjectField(javaObjInstance, jFieldId_field_enum, l_fieldEnum);
    env->DeleteLocalRef(l_fieldEnum);
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructEnumArray(JNIEnv* env, const TArray<FTestbed1StructEnum>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructEnum");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructEnum(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed1DataJavaConverter::fillStructBoolWithArray(JNIEnv* env, jobject input, FTestbed1StructBoolWithArray& out_struct_bool_with_array)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field_bool = env->GetFieldID(cls, "fieldBool", "[Z");
    jbooleanArray field_bool_value = (jbooleanArray)env->GetObjectField(input, jFieldId_field_bool);
    jsize lenfield_bool = env->GetArrayLength(field_bool_value);
    out_struct_bool_with_array.fieldBool.Reserve(lenfield_bool);
    TArray<jboolean> Temp;
    Temp.SetNumUninitialized(lenfield_bool);
    env->GetBooleanArrayRegion(field_bool_value, 0, lenfield_bool, Temp.GetData());
    for (int i = 0; i < lenfield_bool; i++)
    {
        out_struct_bool_with_array.fieldBool.Add(Temp[i] == JNI_TRUE);
    }
    env->DeleteLocalRef(field_bool_value);

}

void Testbed1DataJavaConverter::fillStructBoolWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructBoolWithArray>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructBoolWithArray(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed1DataJavaConverter::makeJavaStructBoolWithArray(JNIEnv* env, const FTestbed1StructBoolWithArray& in_struct_bool_with_array)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructBoolWithArray");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field_bool = env->GetFieldID(javaClass, "fieldBool", "[Z");
    auto lenfield_bool = in_struct_bool_with_array.fieldBool.Num();
    TArray<jboolean> Temp;
    Temp.SetNumUninitialized(lenfield_bool);
    jbooleanArray l_fieldBool= env->NewBooleanArray(lenfield_bool);
    for (int i = 0; i < lenfield_bool; i++)
    {
        Temp[i] = in_struct_bool_with_array.fieldBool[i] ? JNI_TRUE : JNI_FALSE;
    }
    env->SetBooleanArrayRegion(l_fieldBool, 0, lenfield_bool, Temp.GetData());
    env->SetObjectField(javaObjInstance, jFieldId_field_bool, l_fieldBool);
    env->DeleteLocalRef(l_fieldBool);
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructBoolWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructBoolWithArray>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructBoolWithArray");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructBoolWithArray(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed1DataJavaConverter::fillStructIntWithArray(JNIEnv* env, jobject input, FTestbed1StructIntWithArray& out_struct_int_with_array)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field_int = env->GetFieldID(cls, "fieldInt", "[I");
    jintArray field_int_value = (jintArray)env->GetObjectField(input, jFieldId_field_int);
    jsize lenfield_int = env->GetArrayLength(field_int_value);
    out_struct_int_with_array.fieldInt.AddUninitialized(lenfield_int);
    env->GetIntArrayRegion(field_int_value, 0,  lenfield_int,out_struct_int_with_array.fieldInt.GetData());
    env->DeleteLocalRef(field_int_value);

}

void Testbed1DataJavaConverter::fillStructIntWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructIntWithArray>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructIntWithArray(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed1DataJavaConverter::makeJavaStructIntWithArray(JNIEnv* env, const FTestbed1StructIntWithArray& in_struct_int_with_array)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructIntWithArray");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field_int = env->GetFieldID(javaClass, "fieldInt", "[I");
    auto lenfield_int = in_struct_int_with_array.fieldInt.Num();
    jintArray l_fieldInt= env->NewIntArray(lenfield_int);
    if (l_fieldInt  == NULL){/*Log error, skip?*/};
    env->SetIntArrayRegion(l_fieldInt, 0, lenfield_int,in_struct_int_with_array.fieldInt.GetData());
    env->SetObjectField(javaObjInstance, jFieldId_field_int, l_fieldInt);
    env->DeleteLocalRef(l_fieldInt);
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructIntWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructIntWithArray>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructIntWithArray");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructIntWithArray(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed1DataJavaConverter::fillStructFloatWithArray(JNIEnv* env, jobject input, FTestbed1StructFloatWithArray& out_struct_float_with_array)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field_float = env->GetFieldID(cls, "fieldFloat", "[F");
    jfloatArray field_float_value = (jfloatArray)env->GetObjectField(input, jFieldId_field_float);
    jsize lenfield_float = env->GetArrayLength(field_float_value);
    out_struct_float_with_array.fieldFloat.AddUninitialized(lenfield_float);
    env->GetFloatArrayRegion(field_float_value, 0,  lenfield_float,out_struct_float_with_array.fieldFloat.GetData());
    env->DeleteLocalRef(field_float_value);

}

void Testbed1DataJavaConverter::fillStructFloatWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructFloatWithArray>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructFloatWithArray(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed1DataJavaConverter::makeJavaStructFloatWithArray(JNIEnv* env, const FTestbed1StructFloatWithArray& in_struct_float_with_array)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructFloatWithArray");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field_float = env->GetFieldID(javaClass, "fieldFloat", "[F");
    auto lenfield_float = in_struct_float_with_array.fieldFloat.Num();
    jfloatArray l_fieldFloat= env->NewFloatArray(lenfield_float);
    if (l_fieldFloat  == NULL){/*Log error, skip?*/};
    env->SetFloatArrayRegion(l_fieldFloat, 0, lenfield_float,in_struct_float_with_array.fieldFloat.GetData());
    env->SetObjectField(javaObjInstance, jFieldId_field_float, l_fieldFloat);
    env->DeleteLocalRef(l_fieldFloat);
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructFloatWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructFloatWithArray>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructFloatWithArray");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructFloatWithArray(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed1DataJavaConverter::fillStructStringWithArray(JNIEnv* env, jobject input, FTestbed1StructStringWithArray& out_struct_string_with_array)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field_string = env->GetFieldID(cls, "fieldString", "[Ljava/lang/String;");
    jobjectArray field_string_value = (jobjectArray)env->GetObjectField(input, jFieldId_field_string);
    out_struct_string_with_array.fieldString = FJavaHelper::ObjectArrayToFStringTArray(env, field_string_value);
    env->DeleteLocalRef(field_string_value);

}

void Testbed1DataJavaConverter::fillStructStringWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructStringWithArray>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructStringWithArray(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed1DataJavaConverter::makeJavaStructStringWithArray(JNIEnv* env, const FTestbed1StructStringWithArray& in_struct_string_with_array)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructStringWithArray");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field_string = env->GetFieldID(javaClass, "fieldString", "[Ljava/lang/String;");
    TArray<FStringView> fieldStringStringViews;
    fieldStringStringViews.Reserve(in_struct_string_with_array.fieldString.Num());
    for (const FString& Str : in_struct_string_with_array.fieldString)
    {
        fieldStringStringViews.Add(FStringView(Str));
    }
    auto l_fieldStringWrapper = FJavaHelper::ToJavaStringArray(env,fieldStringStringViews);
    jobjectArray l_fieldString = static_cast<jobjectArray>(env->NewLocalRef(*l_fieldStringWrapper));
    env->SetObjectField(javaObjInstance, jFieldId_field_string, l_fieldString);
    env->DeleteLocalRef(l_fieldString);
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructStringWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructStringWithArray>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructStringWithArray");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructStringWithArray(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed1DataJavaConverter::fillStructStructWithArray(JNIEnv* env, jobject input, FTestbed1StructStructWithArray& out_struct_struct_with_array)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field_struct = env->GetFieldID(cls, "fieldStruct", "[Ltestbed1/testbed1_api/StructStringWithArray;");
    jobjectArray field_struct_value = (jobjectArray)env->GetObjectField(input, jFieldId_field_struct);
    fillStructStringWithArrayArray(env, field_struct_value, out_struct_struct_with_array.fieldStruct);
    env->DeleteLocalRef(field_struct_value);

}

void Testbed1DataJavaConverter::fillStructStructWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructStructWithArray>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructStructWithArray(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed1DataJavaConverter::makeJavaStructStructWithArray(JNIEnv* env, const FTestbed1StructStructWithArray& in_struct_struct_with_array)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructStructWithArray");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field_struct = env->GetFieldID(javaClass, "fieldStruct", "[Ltestbed1/testbed1_api/StructStringWithArray;");
    jobjectArray l_fieldStruct = makeJavaStructStringWithArrayArray(env, in_struct_struct_with_array.fieldStruct);
    env->SetObjectField(javaObjInstance, jFieldId_field_struct, l_fieldStruct);
    env->DeleteLocalRef(l_fieldStruct);
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructStructWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructStructWithArray>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructStructWithArray");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructStructWithArray(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed1DataJavaConverter::fillStructEnumWithArray(JNIEnv* env, jobject input, FTestbed1StructEnumWithArray& out_struct_enum_with_array)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field_enum = env->GetFieldID(cls, "fieldEnum", "[Ltestbed1/testbed1_api/Enum0;");
    jobjectArray field_enum_value = (jobjectArray)env->GetObjectField(input, jFieldId_field_enum);
    fillEnum0Array(env, field_enum_value, out_struct_enum_with_array.fieldEnum);
    env->DeleteLocalRef(field_enum_value);

}

void Testbed1DataJavaConverter::fillStructEnumWithArrayArray(JNIEnv* env, jobjectArray input, TArray<FTestbed1StructEnumWithArray>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStructEnumWithArray(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed1DataJavaConverter::makeJavaStructEnumWithArray(JNIEnv* env, const FTestbed1StructEnumWithArray& in_struct_enum_with_array)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructEnumWithArray");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field_enum = env->GetFieldID(javaClass, "fieldEnum", "[Ltestbed1/testbed1_api/Enum0;");
    jobjectArray l_fieldEnum = makeJavaEnum0Array(env, in_struct_enum_with_array.fieldEnum);
    env->SetObjectField(javaObjInstance, jFieldId_field_enum, l_fieldEnum);
    env->DeleteLocalRef(l_fieldEnum);
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructEnumWithArrayArray(JNIEnv* env, const TArray<FTestbed1StructEnumWithArray>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/StructEnumWithArray");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStructEnumWithArray(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed1DataJavaConverter::fillEnum0Array(JNIEnv* env, jobjectArray input, TArray<ETestbed1Enum0>& out_array)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/Enum0");
    out_array.Empty();
    jsize len = env->GetArrayLength(input);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        out_array.Add(getEnum0Value(env, element));
        env->DeleteLocalRef(element);
    }
}

ETestbed1Enum0 Testbed1DataJavaConverter::getEnum0Value(JNIEnv* env, jobject input)
{
    ETestbed1Enum0 cppEnumValue;
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/Enum0");
    jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
    int int_value = env->CallIntMethod(input, getValueMethod);
    UTestbed1Library::toTestbed1Enum0(cppEnumValue, int_value);
    return cppEnumValue;
}


jobjectArray Testbed1DataJavaConverter::makeJavaEnum0Array(JNIEnv* env, const TArray<ETestbed1Enum0>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/Enum0");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaEnum0(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

jobject Testbed1DataJavaConverter::makeJavaEnum0(JNIEnv* env, ETestbed1Enum0 value)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/Enum0");
    jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)Ltestbed1/testbed1_api/Enum0;");
    if (!fromValueMethod) return nullptr;
    int int_value = (uint8)value;
    jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
    return javaObj;
}


void Testbed1DataJavaConverter::fillStructInterface(JNIEnv* env, jobject input, TScriptInterface<ITestbed1StructInterfaceInterface> out_struct_interface)
{
    if (!input || !out_struct_interface)
    {
        return;
    }
    // currently not supported, stub function generated for possible custom implementation
}

void Testbed1DataJavaConverter::fillStructInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed1StructInterfaceInterface>>& out_array)
{
    // currently not supported, stub function generated for possible custom implementation
}
jobject Testbed1DataJavaConverter::makeJavaStructInterface(JNIEnv* env, const TScriptInterface<ITestbed1StructInterfaceInterface> out_struct_interface)
{
    if (!out_struct_interface)
    {
        return nullptr;
    }

    jobject javaObjInstance = nullptr;
    // currently not supported, stub function generated for possible custom implementation
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed1StructInterfaceInterface>>& cppArray)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/IStructInterface");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaClass, nullptr);
    // currently not supported, stub function generated for possible custom implementation 
    return javaArray;
}

TScriptInterface<ITestbed1StructInterfaceInterface> Testbed1DataJavaConverter::getCppInstanceTestbed1StructInterface()
{
    UTestbed1StructInterfaceImplementation* Impl = NewObject<UTestbed1StructInterfaceImplementation>();
    TScriptInterface<ITestbed1StructInterfaceInterface> wrapped;
    wrapped.SetObject(Impl);
    wrapped.SetInterface(Cast<ITestbed1StructInterfaceInterface>(Impl));
    return wrapped;
}


void Testbed1DataJavaConverter::fillStructArrayInterface(JNIEnv* env, jobject input, TScriptInterface<ITestbed1StructArrayInterfaceInterface> out_struct_array_interface)
{
    if (!input || !out_struct_array_interface)
    {
        return;
    }
    // currently not supported, stub function generated for possible custom implementation
}

void Testbed1DataJavaConverter::fillStructArrayInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed1StructArrayInterfaceInterface>>& out_array)
{
    // currently not supported, stub function generated for possible custom implementation
}
jobject Testbed1DataJavaConverter::makeJavaStructArrayInterface(JNIEnv* env, const TScriptInterface<ITestbed1StructArrayInterfaceInterface> out_struct_array_interface)
{
    if (!out_struct_array_interface)
    {
        return nullptr;
    }

    jobject javaObjInstance = nullptr;
    // currently not supported, stub function generated for possible custom implementation
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructArrayInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed1StructArrayInterfaceInterface>>& cppArray)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/IStructArrayInterface");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaClass, nullptr);
    // currently not supported, stub function generated for possible custom implementation 
    return javaArray;
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> Testbed1DataJavaConverter::getCppInstanceTestbed1StructArrayInterface()
{
    UTestbed1StructArrayInterfaceImplementation* Impl = NewObject<UTestbed1StructArrayInterfaceImplementation>();
    TScriptInterface<ITestbed1StructArrayInterfaceInterface> wrapped;
    wrapped.SetObject(Impl);
    wrapped.SetInterface(Cast<ITestbed1StructArrayInterfaceInterface>(Impl));
    return wrapped;
}


void Testbed1DataJavaConverter::fillStructArray2Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed1StructArray2InterfaceInterface> out_struct_array2_interface)
{
    if (!input || !out_struct_array2_interface)
    {
        return;
    }
    // currently not supported, stub function generated for possible custom implementation
}

void Testbed1DataJavaConverter::fillStructArray2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed1StructArray2InterfaceInterface>>& out_array)
{
    // currently not supported, stub function generated for possible custom implementation
}
jobject Testbed1DataJavaConverter::makeJavaStructArray2Interface(JNIEnv* env, const TScriptInterface<ITestbed1StructArray2InterfaceInterface> out_struct_array2_interface)
{
    if (!out_struct_array2_interface)
    {
        return nullptr;
    }

    jobject javaObjInstance = nullptr;
    // currently not supported, stub function generated for possible custom implementation
    return javaObjInstance;
}

jobjectArray Testbed1DataJavaConverter::makeJavaStructArray2InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed1StructArray2InterfaceInterface>>& cppArray)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed1/testbed1_api/IStructArray2Interface");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaClass, nullptr);
    // currently not supported, stub function generated for possible custom implementation 
    return javaArray;
}

TScriptInterface<ITestbed1StructArray2InterfaceInterface> Testbed1DataJavaConverter::getCppInstanceTestbed1StructArray2Interface()
{
    UTestbed1StructArray2InterfaceImplementation* Impl = NewObject<UTestbed1StructArray2InterfaceImplementation>();
    TScriptInterface<ITestbed1StructArray2InterfaceInterface> wrapped;
    wrapped.SetObject(Impl);
    wrapped.SetInterface(Cast<ITestbed1StructArray2InterfaceInterface>(Impl));
    return wrapped;
}


#endif
