
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

#include "Testbed2/Generated/Jni/Testbed2DataJavaConverter.h"

#include "Testbed2/Generated/api/Testbed2_data.h"

#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"
#include "Testbed2/Implementation/Testbed2NestedStruct1Interface.h"
#include "Testbed2/Implementation/Testbed2NestedStruct2Interface.h"
#include "Testbed2/Implementation/Testbed2NestedStruct3Interface.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif


#if PLATFORM_ANDROID && USE_ANDROID_JNI



void Testbed2DataJavaConverter::fillStruct1(JNIEnv* env, jobject input, FTestbed2Struct1& out_struct1)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field1 = env->GetFieldID(cls, "field1", "I");
    out_struct1.field1 =  env->GetIntField(input, jFieldId_field1);

}

void Testbed2DataJavaConverter::fillStruct1Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct1>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStruct1(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed2DataJavaConverter::makeJavaStruct1(JNIEnv* env, const FTestbed2Struct1& in_struct1)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct1");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field1 = env->GetFieldID(javaClass, "field1", "I");
    env->SetIntField(javaObjInstance, jFieldId_field1, in_struct1.field1);
    return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaStruct1Array(JNIEnv* env, const TArray<FTestbed2Struct1>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct1");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStruct1(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed2DataJavaConverter::fillStruct2(JNIEnv* env, jobject input, FTestbed2Struct2& out_struct2)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field1 = env->GetFieldID(cls, "field1", "I");
    out_struct2.field1 =  env->GetIntField(input, jFieldId_field1);
    
    jfieldID jFieldId_field2 = env->GetFieldID(cls, "field2", "I");
    out_struct2.field2 =  env->GetIntField(input, jFieldId_field2);

}

void Testbed2DataJavaConverter::fillStruct2Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct2>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStruct2(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed2DataJavaConverter::makeJavaStruct2(JNIEnv* env, const FTestbed2Struct2& in_struct2)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct2");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field1 = env->GetFieldID(javaClass, "field1", "I");
    env->SetIntField(javaObjInstance, jFieldId_field1, in_struct2.field1);
    
    jfieldID jFieldId_field2 = env->GetFieldID(javaClass, "field2", "I");
    env->SetIntField(javaObjInstance, jFieldId_field2, in_struct2.field2);
    return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaStruct2Array(JNIEnv* env, const TArray<FTestbed2Struct2>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct2");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStruct2(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed2DataJavaConverter::fillStruct3(JNIEnv* env, jobject input, FTestbed2Struct3& out_struct3)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field1 = env->GetFieldID(cls, "field1", "I");
    out_struct3.field1 =  env->GetIntField(input, jFieldId_field1);
    
    jfieldID jFieldId_field2 = env->GetFieldID(cls, "field2", "I");
    out_struct3.field2 =  env->GetIntField(input, jFieldId_field2);
    
    jfieldID jFieldId_field3 = env->GetFieldID(cls, "field3", "I");
    out_struct3.field3 =  env->GetIntField(input, jFieldId_field3);

}

void Testbed2DataJavaConverter::fillStruct3Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct3>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStruct3(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed2DataJavaConverter::makeJavaStruct3(JNIEnv* env, const FTestbed2Struct3& in_struct3)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct3");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field1 = env->GetFieldID(javaClass, "field1", "I");
    env->SetIntField(javaObjInstance, jFieldId_field1, in_struct3.field1);
    
    jfieldID jFieldId_field2 = env->GetFieldID(javaClass, "field2", "I");
    env->SetIntField(javaObjInstance, jFieldId_field2, in_struct3.field2);
    
    jfieldID jFieldId_field3 = env->GetFieldID(javaClass, "field3", "I");
    env->SetIntField(javaObjInstance, jFieldId_field3, in_struct3.field3);
    return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaStruct3Array(JNIEnv* env, const TArray<FTestbed2Struct3>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct3");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStruct3(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed2DataJavaConverter::fillStruct4(JNIEnv* env, jobject input, FTestbed2Struct4& out_struct4)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field1 = env->GetFieldID(cls, "field1", "I");
    out_struct4.field1 =  env->GetIntField(input, jFieldId_field1);
    
    jfieldID jFieldId_field2 = env->GetFieldID(cls, "field2", "I");
    out_struct4.field2 =  env->GetIntField(input, jFieldId_field2);
    
    jfieldID jFieldId_field3 = env->GetFieldID(cls, "field3", "I");
    out_struct4.field3 =  env->GetIntField(input, jFieldId_field3);
    
    jfieldID jFieldId_field4 = env->GetFieldID(cls, "field4", "I");
    out_struct4.field4 =  env->GetIntField(input, jFieldId_field4);

}

void Testbed2DataJavaConverter::fillStruct4Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2Struct4>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillStruct4(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed2DataJavaConverter::makeJavaStruct4(JNIEnv* env, const FTestbed2Struct4& in_struct4)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct4");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field1 = env->GetFieldID(javaClass, "field1", "I");
    env->SetIntField(javaObjInstance, jFieldId_field1, in_struct4.field1);
    
    jfieldID jFieldId_field2 = env->GetFieldID(javaClass, "field2", "I");
    env->SetIntField(javaObjInstance, jFieldId_field2, in_struct4.field2);
    
    jfieldID jFieldId_field3 = env->GetFieldID(javaClass, "field3", "I");
    env->SetIntField(javaObjInstance, jFieldId_field3, in_struct4.field3);
    
    jfieldID jFieldId_field4 = env->GetFieldID(javaClass, "field4", "I");
    env->SetIntField(javaObjInstance, jFieldId_field4, in_struct4.field4);
    return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaStruct4Array(JNIEnv* env, const TArray<FTestbed2Struct4>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Struct4");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaStruct4(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed2DataJavaConverter::fillNestedStruct1(JNIEnv* env, jobject input, FTestbed2NestedStruct1& out_nested_struct1)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field1 = env->GetFieldID(cls, "field1", "Ltestbed2/testbed2_api/Struct1;");
    jobject field1_value = env->GetObjectField(input, jFieldId_field1);
    fillStruct1(env, field1_value,out_nested_struct1.field1);
    env->DeleteLocalRef(field1_value);

}

void Testbed2DataJavaConverter::fillNestedStruct1Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2NestedStruct1>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillNestedStruct1(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct1(JNIEnv* env, const FTestbed2NestedStruct1& in_nested_struct1)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/NestedStruct1");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field1 = env->GetFieldID(javaClass, "field1", "Ltestbed2/testbed2_api/Struct1;");
    jobject l_field1 = makeJavaStruct1(env,in_nested_struct1.field1);
    env->SetObjectField(javaObjInstance, jFieldId_field1, l_field1);
    env->DeleteLocalRef(l_field1);
    return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaNestedStruct1Array(JNIEnv* env, const TArray<FTestbed2NestedStruct1>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/NestedStruct1");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaNestedStruct1(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed2DataJavaConverter::fillNestedStruct2(JNIEnv* env, jobject input, FTestbed2NestedStruct2& out_nested_struct2)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field1 = env->GetFieldID(cls, "field1", "Ltestbed2/testbed2_api/Struct1;");
    jobject field1_value = env->GetObjectField(input, jFieldId_field1);
    fillStruct1(env, field1_value,out_nested_struct2.field1);
    env->DeleteLocalRef(field1_value);
    
    jfieldID jFieldId_field2 = env->GetFieldID(cls, "field2", "Ltestbed2/testbed2_api/Struct2;");
    jobject field2_value = env->GetObjectField(input, jFieldId_field2);
    fillStruct2(env, field2_value,out_nested_struct2.field2);
    env->DeleteLocalRef(field2_value);

}

void Testbed2DataJavaConverter::fillNestedStruct2Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2NestedStruct2>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillNestedStruct2(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct2(JNIEnv* env, const FTestbed2NestedStruct2& in_nested_struct2)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/NestedStruct2");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field1 = env->GetFieldID(javaClass, "field1", "Ltestbed2/testbed2_api/Struct1;");
    jobject l_field1 = makeJavaStruct1(env,in_nested_struct2.field1);
    env->SetObjectField(javaObjInstance, jFieldId_field1, l_field1);
    env->DeleteLocalRef(l_field1);
    
    jfieldID jFieldId_field2 = env->GetFieldID(javaClass, "field2", "Ltestbed2/testbed2_api/Struct2;");
    jobject l_field2 = makeJavaStruct2(env,in_nested_struct2.field2);
    env->SetObjectField(javaObjInstance, jFieldId_field2, l_field2);
    env->DeleteLocalRef(l_field2);
    return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaNestedStruct2Array(JNIEnv* env, const TArray<FTestbed2NestedStruct2>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/NestedStruct2");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaNestedStruct2(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed2DataJavaConverter::fillNestedStruct3(JNIEnv* env, jobject input, FTestbed2NestedStruct3& out_nested_struct3)
{
    jclass cls = env->GetObjectClass(input);
    
    jfieldID jFieldId_field1 = env->GetFieldID(cls, "field1", "Ltestbed2/testbed2_api/Struct1;");
    jobject field1_value = env->GetObjectField(input, jFieldId_field1);
    fillStruct1(env, field1_value,out_nested_struct3.field1);
    env->DeleteLocalRef(field1_value);
    
    jfieldID jFieldId_field2 = env->GetFieldID(cls, "field2", "Ltestbed2/testbed2_api/Struct2;");
    jobject field2_value = env->GetObjectField(input, jFieldId_field2);
    fillStruct2(env, field2_value,out_nested_struct3.field2);
    env->DeleteLocalRef(field2_value);
    
    jfieldID jFieldId_field3 = env->GetFieldID(cls, "field3", "Ltestbed2/testbed2_api/Struct3;");
    jobject field3_value = env->GetObjectField(input, jFieldId_field3);
    fillStruct3(env, field3_value,out_nested_struct3.field3);
    env->DeleteLocalRef(field3_value);

}

void Testbed2DataJavaConverter::fillNestedStruct3Array(JNIEnv* env, jobjectArray input, TArray<FTestbed2NestedStruct3>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fillNestedStruct3(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

jobject Testbed2DataJavaConverter::makeJavaNestedStruct3(JNIEnv* env, const FTestbed2NestedStruct3& in_nested_struct3)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/NestedStruct3");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    jfieldID jFieldId_field1 = env->GetFieldID(javaClass, "field1", "Ltestbed2/testbed2_api/Struct1;");
    jobject l_field1 = makeJavaStruct1(env,in_nested_struct3.field1);
    env->SetObjectField(javaObjInstance, jFieldId_field1, l_field1);
    env->DeleteLocalRef(l_field1);
    
    jfieldID jFieldId_field2 = env->GetFieldID(javaClass, "field2", "Ltestbed2/testbed2_api/Struct2;");
    jobject l_field2 = makeJavaStruct2(env,in_nested_struct3.field2);
    env->SetObjectField(javaObjInstance, jFieldId_field2, l_field2);
    env->DeleteLocalRef(l_field2);
    
    jfieldID jFieldId_field3 = env->GetFieldID(javaClass, "field3", "Ltestbed2/testbed2_api/Struct3;");
    jobject l_field3 = makeJavaStruct3(env,in_nested_struct3.field3);
    env->SetObjectField(javaObjInstance, jFieldId_field3, l_field3);
    env->DeleteLocalRef(l_field3);
    return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaNestedStruct3Array(JNIEnv* env, const TArray<FTestbed2NestedStruct3>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/NestedStruct3");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaNestedStruct3(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

void Testbed2DataJavaConverter::fillEnum1Array(JNIEnv* env, jobjectArray input, TArray<ETestbed2Enum1>& out_array)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum1");
    out_array.Empty();
    jsize len = env->GetArrayLength(input);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        out_array.Add(getEnum1Value(env, element));
        env->DeleteLocalRef(element);
    }
}

ETestbed2Enum1 Testbed2DataJavaConverter::getEnum1Value(JNIEnv* env, jobject input)
{
    ETestbed2Enum1 cppEnumValue;
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum1");
    jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
    int int_value = env->CallIntMethod(input, getValueMethod);
    UTestbed2Library::toTestbed2Enum1(cppEnumValue, int_value);
    return cppEnumValue;
}


jobjectArray Testbed2DataJavaConverter::makeJavaEnum1Array(JNIEnv* env, const TArray<ETestbed2Enum1>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum1");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaEnum1(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

jobject Testbed2DataJavaConverter::makeJavaEnum1(JNIEnv* env, ETestbed2Enum1 value)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum1");
    jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)Ltestbed2/testbed2_api/Enum1;");
    if (!fromValueMethod) return nullptr;
    int int_value = (uint8)value;
    jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
    return javaObj;
}

void Testbed2DataJavaConverter::fillEnum2Array(JNIEnv* env, jobjectArray input, TArray<ETestbed2Enum2>& out_array)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum2");
    out_array.Empty();
    jsize len = env->GetArrayLength(input);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        out_array.Add(getEnum2Value(env, element));
        env->DeleteLocalRef(element);
    }
}

ETestbed2Enum2 Testbed2DataJavaConverter::getEnum2Value(JNIEnv* env, jobject input)
{
    ETestbed2Enum2 cppEnumValue;
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum2");
    jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
    int int_value = env->CallIntMethod(input, getValueMethod);
    UTestbed2Library::toTestbed2Enum2(cppEnumValue, int_value);
    return cppEnumValue;
}


jobjectArray Testbed2DataJavaConverter::makeJavaEnum2Array(JNIEnv* env, const TArray<ETestbed2Enum2>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum2");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaEnum2(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

jobject Testbed2DataJavaConverter::makeJavaEnum2(JNIEnv* env, ETestbed2Enum2 value)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum2");
    jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)Ltestbed2/testbed2_api/Enum2;");
    if (!fromValueMethod) return nullptr;
    int int_value = (uint8)value;
    jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
    return javaObj;
}

void Testbed2DataJavaConverter::fillEnum3Array(JNIEnv* env, jobjectArray input, TArray<ETestbed2Enum3>& out_array)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum3");
    out_array.Empty();
    jsize len = env->GetArrayLength(input);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        out_array.Add(getEnum3Value(env, element));
        env->DeleteLocalRef(element);
    }
}

ETestbed2Enum3 Testbed2DataJavaConverter::getEnum3Value(JNIEnv* env, jobject input)
{
    ETestbed2Enum3 cppEnumValue;
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum3");
    jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
    int int_value = env->CallIntMethod(input, getValueMethod);
    UTestbed2Library::toTestbed2Enum3(cppEnumValue, int_value);
    return cppEnumValue;
}


jobjectArray Testbed2DataJavaConverter::makeJavaEnum3Array(JNIEnv* env, const TArray<ETestbed2Enum3>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum3");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJavaEnum3(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

jobject Testbed2DataJavaConverter::makeJavaEnum3(JNIEnv* env, ETestbed2Enum3 value)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/Enum3");
    jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)Ltestbed2/testbed2_api/Enum3;");
    if (!fromValueMethod) return nullptr;
    int int_value = (uint8)value;
    jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
    return javaObj;
}


void Testbed2DataJavaConverter::fillManyParamInterface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2ManyParamInterfaceInterface> out_many_param_interface)
{
    if (!input || !out_many_param_interface)
    {
        return;
    }
    // currently not supported, stub function generated for possible custom implementation
}

void Testbed2DataJavaConverter::fillManyParamInterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2ManyParamInterfaceInterface>>& out_array)
{
    // currently not supported, stub function generated for possible custom implementation
}
jobject Testbed2DataJavaConverter::makeJavaManyParamInterface(JNIEnv* env, const TScriptInterface<ITestbed2ManyParamInterfaceInterface> out_many_param_interface)
{
    if (!out_many_param_interface)
    {
        return nullptr;
    }

    jobject javaObjInstance = nullptr;
    // currently not supported, stub function generated for possible custom implementation
    return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaManyParamInterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed2ManyParamInterfaceInterface>>& cppArray)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/IManyParamInterface");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaClass, nullptr);
    // currently not supported, stub function generated for possible custom implementation 
    return javaArray;
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> Testbed2DataJavaConverter::getCppInstanceTestbed2ManyParamInterface()
{
    UTestbed2ManyParamInterfaceImplementation* Impl = NewObject<UTestbed2ManyParamInterfaceImplementation>();
    TScriptInterface<ITestbed2ManyParamInterfaceInterface> wrapped;
    wrapped.SetObject(Impl);
    wrapped.SetInterface(Cast<ITestbed2ManyParamInterfaceInterface>(Impl));
    return wrapped;
}


void Testbed2DataJavaConverter::fillNestedStruct1Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> out_nested_struct1_interface)
{
    if (!input || !out_nested_struct1_interface)
    {
        return;
    }
    // currently not supported, stub function generated for possible custom implementation
}

void Testbed2DataJavaConverter::fillNestedStruct1InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2NestedStruct1InterfaceInterface>>& out_array)
{
    // currently not supported, stub function generated for possible custom implementation
}
jobject Testbed2DataJavaConverter::makeJavaNestedStruct1Interface(JNIEnv* env, const TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> out_nested_struct1_interface)
{
    if (!out_nested_struct1_interface)
    {
        return nullptr;
    }

    jobject javaObjInstance = nullptr;
    // currently not supported, stub function generated for possible custom implementation
    return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaNestedStruct1InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed2NestedStruct1InterfaceInterface>>& cppArray)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/INestedStruct1Interface");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaClass, nullptr);
    // currently not supported, stub function generated for possible custom implementation 
    return javaArray;
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> Testbed2DataJavaConverter::getCppInstanceTestbed2NestedStruct1Interface()
{
    UTestbed2NestedStruct1InterfaceImplementation* Impl = NewObject<UTestbed2NestedStruct1InterfaceImplementation>();
    TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> wrapped;
    wrapped.SetObject(Impl);
    wrapped.SetInterface(Cast<ITestbed2NestedStruct1InterfaceInterface>(Impl));
    return wrapped;
}


void Testbed2DataJavaConverter::fillNestedStruct2Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> out_nested_struct2_interface)
{
    if (!input || !out_nested_struct2_interface)
    {
        return;
    }
    // currently not supported, stub function generated for possible custom implementation
}

void Testbed2DataJavaConverter::fillNestedStruct2InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2NestedStruct2InterfaceInterface>>& out_array)
{
    // currently not supported, stub function generated for possible custom implementation
}
jobject Testbed2DataJavaConverter::makeJavaNestedStruct2Interface(JNIEnv* env, const TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> out_nested_struct2_interface)
{
    if (!out_nested_struct2_interface)
    {
        return nullptr;
    }

    jobject javaObjInstance = nullptr;
    // currently not supported, stub function generated for possible custom implementation
    return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaNestedStruct2InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed2NestedStruct2InterfaceInterface>>& cppArray)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/INestedStruct2Interface");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaClass, nullptr);
    // currently not supported, stub function generated for possible custom implementation 
    return javaArray;
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> Testbed2DataJavaConverter::getCppInstanceTestbed2NestedStruct2Interface()
{
    UTestbed2NestedStruct2InterfaceImplementation* Impl = NewObject<UTestbed2NestedStruct2InterfaceImplementation>();
    TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> wrapped;
    wrapped.SetObject(Impl);
    wrapped.SetInterface(Cast<ITestbed2NestedStruct2InterfaceInterface>(Impl));
    return wrapped;
}


void Testbed2DataJavaConverter::fillNestedStruct3Interface(JNIEnv* env, jobject input, TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> out_nested_struct3_interface)
{
    if (!input || !out_nested_struct3_interface)
    {
        return;
    }
    // currently not supported, stub function generated for possible custom implementation
}

void Testbed2DataJavaConverter::fillNestedStruct3InterfaceArray(JNIEnv* env, jobjectArray input, TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceInterface>>& out_array)
{
    // currently not supported, stub function generated for possible custom implementation
}
jobject Testbed2DataJavaConverter::makeJavaNestedStruct3Interface(JNIEnv* env, const TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> out_nested_struct3_interface)
{
    if (!out_nested_struct3_interface)
    {
        return nullptr;
    }

    jobject javaObjInstance = nullptr;
    // currently not supported, stub function generated for possible custom implementation
    return javaObjInstance;
}

jobjectArray Testbed2DataJavaConverter::makeJavaNestedStruct3InterfaceArray(JNIEnv* env, const TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceInterface>>& cppArray)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("testbed2/testbed2_api/INestedStruct3Interface");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaClass, nullptr);
    // currently not supported, stub function generated for possible custom implementation 
    return javaArray;
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> Testbed2DataJavaConverter::getCppInstanceTestbed2NestedStruct3Interface()
{
    UTestbed2NestedStruct3InterfaceImplementation* Impl = NewObject<UTestbed2NestedStruct3InterfaceImplementation>();
    TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> wrapped;
    wrapped.SetObject(Impl);
    wrapped.SetInterface(Cast<ITestbed2NestedStruct3InterfaceInterface>(Impl));
    return wrapped;
}


#endif
