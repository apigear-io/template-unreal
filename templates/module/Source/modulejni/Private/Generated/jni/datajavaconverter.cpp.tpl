{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name -}}
{{- $moduleName := camel .Module.Name -}}
{{- $Category := printf "ApiGear|%s" $ModuleName }}
{{- $features := .Features }}
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

#include "{{$ModuleName}}/Generated/Jni/{{$ModuleName}}DataJavaConverter.h"

{{- $includes := getEmptyStringList}}
{{- range .Module.Externs }}
{{- $class := ueExtern . }}
{{- if $class.Include }}
{{- $includeName :=  printf "\"%s\"" $class.Include }}
{{- $includes = (appendList $includes $includeName) }}
{{- end }}
{{- end }}
{{- range .Module.Imports }}
{{- $importModuleName := Camel .Name }}
{{- $includeName :=  printf "\"%s/Generated/api/%s_data.h\"" $importModuleName $importModuleName }}
{{- $includeName :=  printf "\"%s/Generated/Jni/%sDataJavaConverter.h\"" $importModuleName $importModuleName }}
{{- $includes = (appendList $includes $includeName) }}
{{- end }}
{{- $includes = unique $includes }}
{{ range $includes }}
#include {{ .}}
{{- end }}
{{ if or (len .Module.Enums) (len .Module.Structs) -}}
#include "{{$ModuleName}}/Generated/api/{{ $ModuleName }}_data.h"
{{ end }}

{{- if .Features.stubs }}
{{- range .Module.Interfaces }}
#include "{{$ModuleName}}/Implementation/{{ $ModuleName }}{{Camel .Name}}.h"
{{- end }}
{{- end }}

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif


#if PLATFORM_ANDROID && USE_ANDROID_JNI

{{$className := printf "%sDataJavaConverter" $ModuleName}}

{{- range .Module.Structs }}

{{- $structType := printf "F%s%s" $ModuleName .Name }}
{{- $structName := printf "out_%s" (snake .Name)}}

void {{$className }}::fill{{Camel .Name }}(JNIEnv* env, jobject input, {{$structType}}& {{$structName}})
{
    jclass cls = env->GetObjectClass(input);

{{- range .Fields }}
    {{- $cppFieldName :=  .Name}}
    {{- $javaFieldName := camel .Name}}
    
    jfieldID jFieldId_{{snake .Name}} = env->GetFieldID(cls, "{{$javaFieldName}}", "{{jniSignatureType . }}");
    
{{- if .IsArray }}
    {{ jniToReturnType . }} {{snake .Name}}_value = ({{jniToReturnType . }})env->GetObjectField(input, jFieldId_{{snake .Name}});		
{{- if (eq .KindType "enum") }}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    fill{{Camel .Type }}Array(env, {{snake .Name}}_value, {{$structName}}.{{$cppFieldName}});
{{- else if (eq .KindType "string")}}
    {{$structName}}.{{$cppFieldName}} = FJavaHelper::ObjectArrayToFStringTArray(env, {{snake .Name}}_value);

{{- else if (eq .KindType "bool")}}
    jsize len{{snake .Name}} = env->GetArrayLength({{snake .Name}}_value);
    {{$structName}}.{{$cppFieldName}}.Reserve(len{{snake .Name}});
    TArray<jboolean> Temp;
    Temp.SetNumUninitialized(len{{snake .Name}});
    env->GetBooleanArrayRegion({{snake .Name}}_value, 0, len{{snake .Name}}, Temp.GetData());
    for (int i = 0; i < len{{snake .Name}}; i++)
    {
        {{$structName}}.{{$cppFieldName}}.Add(Temp[i] == JNI_TRUE);
    }
{{- else if .IsPrimitive }}
    jsize len{{snake .Name}} = env->GetArrayLength({{snake .Name}}_value);
    {{$structName}}.{{$cppFieldName}}.AddUninitialized(len{{snake .Name}});
    env->Get{{jniToEnvNameType .}}ArrayRegion({{snake .Name}}_value, 0,  len{{snake .Name}}, {{- if (eq .KindType "int64") -}}
        reinterpret_cast<jlong*>({{$structName}}.{{$cppFieldName}}.GetData()));
        {{- else -}}
        {{$structName}}.{{$cppFieldName}}.GetData());
        {{- end }}
{{- else }}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    fill{{Camel .Type }}Array(env, {{snake .Name}}_value, {{$structName}}.{{$cppFieldName}});
{{- end }}
    env->DeleteLocalRef({{snake .Name}}_value);
{{- else if eq .KindType "enum"}}
    {{ jniToReturnType . }} {{snake .Name}}_value = env->GetObjectField(input, jFieldId_{{snake .Name}});
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    {{$structName}}.{{$cppFieldName}} = {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    get{{Camel .Type }}Value(env, {{snake .Name}}_value);
{{- else if eq .KindType "string"}}
    jstring {{snake .Name}}_value = (jstring)env->GetObjectField(input, jFieldId_{{snake .Name}});
    {{$structName}}.{{$cppFieldName}} = FJavaHelper::FStringFromLocalRef(env,{{snake .Name}}_value);
{{- else if .IsPrimitive }}
    {{$structName}}.{{$cppFieldName}} =  env->Get{{jniToEnvNameType .}}Field(input, jFieldId_{{snake .Name}});
{{- else }}
    {{ jniToReturnType . }} {{snake .Name}}_value = env->GetObjectField(input, jFieldId_{{snake .Name}});
    {{- if eq .KindType "interface"}}
    if ({{$structName}}.{{$cppFieldName }} == nullptr && {{snake .Name}}_value != nullptr)
    {
        {{$structName}}.{{$cppFieldName }} = {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    getCppInstance{{if not (eq .Schema.Import  "" )}}{{ Camel .Schema.Import }}{{else}}{{$ModuleName}}{{end -}}{{Camel .Type }}();
    }
    {{- end }}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}    
    fill{{Camel .Type }}(env, {{snake .Name}}_value,{{$structName}}.{{$cppFieldName }});
    env->DeleteLocalRef({{snake .Name}}_value);
{{- end }}

{{- end }}

}

void {{$className }}::fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$structType}}>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fill{{Camel .Name }}(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

{{- $in_cppStructName := printf "in_%s" (snake .Name)}}
{{- $api_package_name := printf "%s_api" (camel $moduleName) }}
{{- $packageName := printf "%s/%s_api" (camel $moduleName) (camel $moduleName)}}
{{- $javaClassTypeName := Camel .Name}}

jobject {{$className }}::makeJava{{Camel .Name }}(JNIEnv* env, const {{$structType}}& {{$in_cppStructName}})
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
{{- range .Fields }}
    {{- $cppFieldName :=  .Name}}
    {{- $javaFieldName := camel .Name}}
    {{- $tmpObjName := printf "l_%s" $javaFieldName }}
    
    jfieldID jFieldId_{{snake .Name}} = env->GetFieldID(javaClass, "{{$javaFieldName}}", "{{jniSignatureType . }}");
    
{{- if .IsArray }}	
{{- if (eq .KindType "enum") }}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    jobjectArray {{$tmpObjName}} = {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    makeJava{{Camel .Type }}Array(env, {{$in_cppStructName}}.{{$cppFieldName}});
{{- else if (eq .KindType "string")}}
    TArray<FStringView> {{$cppFieldName}}StringViews;
    {{$cppFieldName}}StringViews.Reserve({{$in_cppStructName}}.{{$cppFieldName}}.Num());
    for (const FString& Str : {{$in_cppStructName}}.{{$cppFieldName}})
    {
        {{$cppFieldName}}StringViews.Add(FStringView(Str));
    }
    auto {{$tmpObjName}}Wrapper = FJavaHelper::ToJavaStringArray(env,{{$cppFieldName}}StringViews);
    jobjectArray {{$tmpObjName}} = static_cast<jobjectArray>(env->NewLocalRef(*{{$tmpObjName}}Wrapper));
{{- else if (eq .KindType "bool")}}
    auto len{{snake .Name}} = {{$in_cppStructName}}.{{$cppFieldName}}.Num();
    TArray<jboolean> Temp;
    Temp.SetNumUninitialized(len{{snake .Name}});
    {{ jniToReturnType . }} {{$tmpObjName}}= env->New{{jniToEnvNameType .}}Array(len{{snake .Name}});
    for (int i = 0; i < len{{snake .Name}}; i++)
    {
        Temp[i] = {{$in_cppStructName}}.{{$cppFieldName}}[i] ? JNI_TRUE : JNI_FALSE;
    }
    env->SetBooleanArrayRegion({{$tmpObjName}}, 0, len{{snake .Name}}, Temp.GetData());
{{- else if .IsPrimitive }}
    auto len{{snake .Name}} = {{$in_cppStructName}}.{{$cppFieldName}}.Num();
    {{ jniToReturnType . }} {{$tmpObjName}}= env->New{{jniToEnvNameType .}}Array(len{{snake .Name}});
    if ({{$tmpObjName}}  == NULL){/*Log error, skip?*/};
    env->Set{{jniToEnvNameType .}}ArrayRegion({{$tmpObjName}}, 0, len{{snake .Name}}, {{- if (eq .KindType "int64") -}}
        reinterpret_cast<const jlong*>({{$in_cppStructName}}.{{$cppFieldName}}.GetData()));
        {{- else -}}
        {{$in_cppStructName}}.{{$cppFieldName}}.GetData());
        {{- end }}
{{- else }}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    jobjectArray {{$tmpObjName}} = {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    makeJava{{Camel .Type }}Array(env, {{$in_cppStructName}}.{{$cppFieldName}});
{{- end }}
    env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, {{$tmpObjName}});
    env->DeleteLocalRef({{$tmpObjName}});
{{- else if eq .KindType "enum"}}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    jobject {{$tmpObjName}} = {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    makeJava{{Camel .Type }}(env, {{$in_cppStructName}}.{{$cppFieldName}});
    env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, {{$tmpObjName}});
    env->DeleteLocalRef({{$tmpObjName}});
{{- else if eq .KindType "string"}}
    auto {{$tmpObjName}}Wrapper =  FJavaHelper::ToJavaString(env,{{$in_cppStructName}}.{{$cppFieldName}});
    jstring {{$tmpObjName}} = static_cast<jstring>(env->NewLocalRef(*{{$tmpObjName}}Wrapper));
    env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, {{$tmpObjName}});
    // in UE 5.6 no need for new local ref
{{- else if .IsPrimitive }}
    env->Set{{jniToEnvNameType .}}Field(javaObjInstance, jFieldId_{{snake .Name}}, {{$in_cppStructName}}.{{$cppFieldName}});
{{- else }}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    jobject {{$tmpObjName}} = {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    makeJava{{Camel .Type }}(env,{{$in_cppStructName}}.{{$cppFieldName }});
    env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, {{$tmpObjName}});
    env->DeleteLocalRef({{$tmpObjName}});
{{- end }}

{{- end }}
    return javaObjInstance;
}

jobjectArray {{$className }}::makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$structType}}>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJava{{Camel .Name }}(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}
{{- end }}

{{- range .Module.Enums }}
{{- $moduleEnumName := printf "%s%s" $ModuleName .Name }}
{{- $cpp_class := printf "E%s%s" $ModuleName .Name }}

{{- $in_cppStructName := printf "out_%s" (snake .Name)}}
{{- $packageName := printf "%s/%s_api" (camel $moduleName) (camel $moduleName)}}
{{- $javaClassTypeName := Camel .Name}}

void {{$className }}::fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$cpp_class}}>& out_array)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
    out_array.Empty();
    jsize len = env->GetArrayLength(input);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        out_array.Add(get{{Camel .Name }}Value(env, element));
        env->DeleteLocalRef(element);
    }
}

{{$cpp_class}} {{$className }}::get{{Camel .Name }}Value(JNIEnv* env, jobject input)
{
    {{$cpp_class}} cppEnumValue;
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
    jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
    int int_value = env->CallIntMethod(input, getValueMethod);
    {{- $toEnumFuncName := printf "U%sLibrary::to%s%s" $ModuleName $ModuleName .Name }}
    {{$toEnumFuncName}}(cppEnumValue, int_value);
    return cppEnumValue;
}


jobjectArray {{$className }}::makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$cpp_class}}>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJava{{Camel .Name }}(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

jobject {{$className }}::makeJava{{Camel .Name }}(JNIEnv* env, {{$cpp_class}} value)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
    jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)L{{$packageName}}/{{$javaClassTypeName}};");
    if (!fromValueMethod) return nullptr;
    int int_value = (uint8)value;
    jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
    return javaObj;
}
{{- end }}

{{- range .Module.Interfaces }}

{{- $ifType := printf "TScriptInterface<I%s%sInterface>" $ModuleName (Camel .Name) }}
{{- $ifName := printf "out_%s" (snake .Name)}}
{{- $fullJavaClassType := printf "%s/%s_api/I%s" (camel $moduleName) (camel $moduleName) (Camel .Name) }}


void {{$className }}::fill{{Camel .Name }}(JNIEnv* env, jobject input, {{$ifType}} {{$ifName}})
{
    if (!input || !{{$ifName}})
    {
        return;
    }

    jclass cls = env->GetObjectClass(input);
{{- range .Properties }}
    {{- if not .IsReadOnly }}
    {{- $javaFieldName := camel .Name}}
    
    //jfieldID jFieldId_{{snake .Name}} = env->GetFieldID(cls, "{{$javaFieldName}}", "{{jniSignatureType . }}");
    {{- $signatureParam:= jniJavaSignatureParam .}}
    static jmethodID getter_{{snake .Name}} = env->GetMethodID(cls, "get{{Camel .Name}}", "(){{$signatureParam}}");
    //if (getter_{{snake .Name}} == nullptr) // probably just return with error
    {{jniToReturnType . }} {{snake .Name}}_value = {{- if or .IsArray (eq .KindType "string") }}({{jniToReturnType . }}){{end -}}
    FJavaWrapper::{{- if or .IsArray }}CallObjectMethod{{else}}Call{{jniToEnvNameType .}}Method{{end}}(env, input, getter_{{snake .Name}});

{{- if .IsArray }}
    {{ueReturn "" .}} cpp{{Camel .Name}} = {{ ueDefault "" . }};
{{- if (eq .KindType "enum") }}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    fill{{Camel .Type }}Array(env, {{snake .Name}}_value, cpp{{Camel .Name}});
    {{$ifName}}->Set{{Camel .Name}}(cpp{{Camel .Name}});
{{- else if (eq .KindType "string")}}
    FJavaHelper::ObjectArrayToFStringTArray(env, {{snake .Name}}_value);
    {{$ifName}}->Set{{Camel .Name}}(cpp{{Camel .Name}});
{{- else if (eq .KindType "bool")}}
    jsize len{{snake .Name}} = env->GetArrayLength({{snake .Name}}_value);
    cpp{{Camel .Name}}.Reserve(len{{snake .Name}});
    TArray<jboolean> Temp;
    Temp.SetNumUninitialized(len{{snake .Name}});
    env->GetBooleanArrayRegion({{snake .Name}}_value, 0, len{{snake .Name}}, Temp.GetData());
    for (int i = 0; i < len{{snake .Name}}; i++)
    {
        cpp{{Camel .Name}}.Add(Temp[i] == JNI_TRUE);
    }
    //env->DeleteLocalRef({{snake .Name}}_value);
    {{$ifName}}->Set{{Camel .Name}}(cpp{{Camel .Name}});

{{- else if .IsPrimitive }}
    jsize len{{snake .Name}} = env->GetArrayLength({{snake .Name}}_value);
    cpp{{Camel .Name}}.AddUninitialized(len{{snake .Name}});
    env->Get{{jniToEnvNameType .}}ArrayRegion({{snake .Name}}_value, 0,  len{{snake .Name}}, {{- if (eq .KindType "int64") -}}
        reinterpret_cast<jlong*>(cpp{{Camel .Name}}.GetData()));
        {{- else -}}
        cpp{{Camel .Name}}.GetData());
        {{- end }}
    {{$ifName}}->Set{{Camel .Name}}(cpp{{Camel .Name}});
{{- else }}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    fill{{Camel .Type }}Array(env, {{snake .Name}}_value, cpp{{Camel .Name}});
    {{$ifName}}->Set{{Camel .Name}}(cpp{{Camel .Name}});
{{- end }}
    env->DeleteLocalRef({{snake .Name}}_value);
{{- else if eq .KindType "enum"}}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    {{$ifName}}->Set{{Camel .Name}}({{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    get{{Camel .Type }}Value(env, {{snake .Name}}_value));
{{- else if eq .KindType "string"}}
    {{$ifName}}->Set{{Camel .Name}}(FJavaHelper::FStringFromLocalRef(env, (jstring){{snake .Name}}_value));
{{- else if .IsPrimitive }}
    {{$ifName}}->Set{{Camel .Name}}({{snake .Name}}_value);
{{- else }}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    {{- if eq .KindType "interface"}}
    {{ueReturn "" .}} cpp{{Camel .Name}} = {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    getCppInstance{{if not (eq .Schema.Import  "" )}}{{ Camel .Schema.Import }}{{else}}{{$ModuleName}}{{end -}}{{Camel .Type }}();
    {{- else }}
    {{ueReturn "" .}} cpp{{Camel .Name}} = {{ ueDefault "" . }};
    {{- end }}
    {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    fill{{Camel .Type }}(env, {{snake .Name}}_value, cpp{{Camel .Name}});
    {{$ifName}}->Set{{Camel .Name}}(cpp{{Camel .Name}});
    env->DeleteLocalRef({{snake .Name}}_value);
{{- end }}

{{- end }}
{{- end }}
}

void {{$className }}::fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$ifType}}>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        out_array.Add(getCppInstance{{$ModuleName}}{{Camel .Name }}());
        fill{{Camel .Name }}(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

{{- $in_cppIfName := printf "out_%s" (snake .Name)}}
jobject {{$className }}::makeJava{{Camel .Name }}(JNIEnv* env, const {{$ifType}} {{$in_cppIfName}})
{
    if (!{{$in_cppIfName}})
    {
        return nullptr;
    }

    jobject javaObjInstance = getJavaInstance{{$ModuleName}}{{Camel .Name }}(env);
    if (!javaObjInstance)
    {
        return nullptr;
    }
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("{{$fullJavaClassType}}");

{{- range .Properties }}
    {{- $cppMethod :=  printf "Get%s()" (Camel .Name)}}
    {{- $javaFieldName := camel .Name}}
    {{- $tmpObjName := printf "l_%s" $javaFieldName }}
    
    {{- $signatureParam := jniJavaSignatureParam . }}
    static jmethodID javaSet{{ Camel .Name}}Method = env->GetMethodID(javaClass, "set{{Camel .Name}}", "({{$signatureParam}})V");
    // if (MethodID == nullptr) log and return default null
    
{{- if .IsArray }}		
{{- if (eq .KindType "enum") }}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    jobjectArray {{$tmpObjName}} = {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    makeJava{{Camel .Type }}Array(env, {{$in_cppIfName}}->{{$cppMethod}});
{{- else if (eq .KindType "string")}}
    TArray<FStringView> {{camel .Name}}StringViews;
    auto cpp_l_{{camel .Name}} = {{$in_cppIfName}}->{{$cppMethod}};
    {{camel .Name}}StringViews.Reserve(cpp_l_{{camel .Name}}.Num());
    for (const FString& Str : cpp_l_{{camel .Name}})
    {
        {{camel .Name}}StringViews.Add(FStringView(Str));
    }
    auto {{$tmpObjName}}Wrapper = FJavaHelper::ToJavaStringArray(env,{{camel .Name}}StringViews);
    jobjectArray {{$tmpObjName}} = static_cast<jobjectArray>(env->NewLocalRef(*{{$tmpObjName}}Wrapper));
{{- else if (eq .KindType "bool")}}
    auto cpp_l_{{camel .Name}} = {{$in_cppIfName}}->{{$cppMethod}};
    auto len{{snake .Name}} = cpp_l_{{camel .Name}}.Num();
    TArray<jboolean> Temp;
    Temp.SetNumUninitialized(len{{snake .Name}});
    for (int i = 0; i < len{{snake .Name}}; i++)
    {
        Temp[i] = cpp_l_{{camel .Name}}[i] ? JNI_TRUE : JNI_FALSE;
    }
    jbooleanArray {{$tmpObjName}} = env->NewBooleanArray(len{{snake .Name}});
    env->SetBooleanArrayRegion({{$tmpObjName}}, 0, len{{snake .Name}}, Temp.GetData());
    FJavaWrapper::CallVoidMethod(env, javaObjInstance, javaSet{{Camel .Name}}Method, {{$tmpObjName}});
{{- else if .IsPrimitive }}
    auto len{{snake .Name}} = {{$in_cppIfName}}->{{$cppMethod}}.Num();
    {{jniToReturnType . }} {{$tmpObjName}} = env->New{{jniToEnvNameType .}}Array(len{{snake .Name}});
    if ({{$tmpObjName}}  == NULL){/*Log error, skip?*/};
    env->Set{{jniToEnvNameType .}}ArrayRegion({{$tmpObjName}}, 0, len{{snake .Name}}, {{- if (eq .KindType "int64") -}}
        reinterpret_cast<const jlong*>({{$in_cppIfName}}->{{$cppMethod}}.GetData()));
        {{- else -}}
        {{$in_cppIfName}}->{{$cppMethod}}.GetData());
        {{- end }}
    FJavaWrapper::CallVoidMethod(env, javaObjInstance, javaSet{{Camel .Name}}Method, {{$tmpObjName}});
{{- else }}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    jobjectArray {{$tmpObjName}} = {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    makeJava{{Camel .Type }}Array(env, {{$in_cppIfName}}->{{$cppMethod}});
{{- end }}
    {{- if or (not .IsPrimitive) (eq .KindType "string") }}
    FJavaWrapper::CallVoidMethod(env, javaObjInstance, javaSet{{Camel .Name}}Method, {{$tmpObjName}});
    env->DeleteLocalRef({{$tmpObjName}});
    {{- end }}
{{- else if eq .KindType "enum"}}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    jobject {{$tmpObjName}} = {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    makeJava{{Camel .Type }}(env, {{$in_cppIfName}}->{{$cppMethod}});
    FJavaWrapper::CallVoidMethod(env, javaObjInstance, javaSet{{Camel .Name}}Method, {{$tmpObjName}});
    env->DeleteLocalRef({{$tmpObjName}});
{{- else if eq .KindType "string"}}
    auto {{$tmpObjName}}Wrapper =  FJavaHelper::ToJavaString(env,{{$in_cppIfName}}->{{$cppMethod}});
    jstring {{$tmpObjName}} = static_cast<jstring>(env->NewLocalRef(*{{$tmpObjName}}Wrapper));
    FJavaWrapper::CallVoidMethod(env, javaObjInstance, javaSet{{Camel .Name}}Method, {{$tmpObjName}});
    // in UE 5.6 no need for new local ref
{{- else if .IsPrimitive }}
    FJavaWrapper::CallVoidMethod(env, javaObjInstance, javaSet{{Camel .Name}}Method, {{$in_cppIfName}}->{{$cppMethod}});
{{- else }}
    {{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
    jobject {{$tmpObjName}} = {{if not (eq $otherModuleClassName  "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
    makeJava{{Camel .Type }}(env, {{$in_cppIfName}}->{{$cppMethod }});
    FJavaWrapper::CallVoidMethod(env, javaObjInstance, javaSet{{Camel .Name}}Method, {{$tmpObjName}});
    env->DeleteLocalRef({{$tmpObjName}});
{{- end }}

{{- end }}
    return javaObjInstance;
}

jobjectArray {{$className }}::makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$ifType}}>& cppArray)
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("{{$fullJavaClassType}}");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaClass, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJava{{Camel .Name }}(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

jobject {{$className }}::getJavaInstance{{$ModuleName}}{{Camel .Name }}(JNIEnv* env)
{   
    {{- if $features.stubs }}
    {{- $packageName := printf "%s/%s_impl" (camel $moduleName) (camel $moduleName)}}
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{Camel .Name}}Service");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    return javaObjInstance;
    {{- else}}
    return nullptr;
    {{- end }}
}

{{$ifType}} {{$className }}::getCppInstance{{$ModuleName}}{{Camel .Name }}()
{
    {{- if $features.stubs }}
    {{- $Class := printf "U%s%sImplementation" $ModuleName (Camel .Name)}}
    {{$Class}}* Impl = NewObject<{{$Class}}>();
    {{$ifType}} wrapped;
    wrapped.SetObject(Impl);
    wrapped.SetInterface(Cast<I{{$ModuleName}}{{Camel .Name}}Interface>(Impl));
    return wrapped;
    {{- else}}
    return nullptr;
    {{- end }}
}

{{- end }}

{{- range .Module.Externs }}
{{- $module:= $.Module }}
{{- $ext := (ueExtern .) }}
{{- $exCppType := $ext.Name }}
{{- if $ext.NameSpace }}
{{- $exCppType := printf "%s::%s" $ext.NameSpace $exCppType }}
{{- end }}
{{- $exName := printf "out_%s" (snake .Name)}}

{{- $extJava := (javaExtern .) }}
{{- $fullJavaClassType := $extJava.Name }}
{{- $prefix := (replace ($extJava.Package) "." "/" ) }}
{{- if ne $prefix "" }}
{{- $fullJavaClassType = printf "%s/%s" $prefix $fullJavaClassType }}
{{- end }}

void {{$className }}::fill{{Camel .Name }}(JNIEnv* env, jobject input, {{$exCppType}}& {{$exName}})
{
    jclass cls = env->GetObjectClass(input);

    // do the serialization field by field: e.g. for int type field
    // jfieldID jFieldId_firstField = env->GetFieldID(cls, "firstField", "I");
    // {{$exName}}.FirstField = env->GetIntField(input, jFieldId_firstField);
}

void {{$className }}::fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$exCppType}}>& out_array)
{
    jsize len = env->GetArrayLength(input);
    out_array.Reserve(len);
    out_array.AddDefaulted(len);
    for (jsize i = 0; i < len; ++i)
    {
        jobject element = env->GetObjectArrayElement(input, i);
        fill{{Camel .Name }}(env, element, out_array[i]);
        env->DeleteLocalRef(element);
    }
}

{{- $in_cppExName := printf "out_%s" (snake .Name)}}
jobject {{$className }}::makeJava{{Camel .Name }}(JNIEnv* env, const {{$exCppType}}& {{$in_cppExName}})
{
    jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("{{$fullJavaClassType}}");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);
    
    // do the serialization field by field: e.g. for int type field
    // jfieldID jFieldId_firstField = env->GetFieldID(javaClass, "jFieldId_firstField", "I");
    // env->SetIntField(javaObjInstance, jFieldId_firstField, {{$in_cppExName}}.FirstField);
    return javaObjInstance;
}

jobjectArray {{$className }}::makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$exCppType}}>& cppArray)
{
    jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("{{$fullJavaClassType}}");
    auto arraySize = cppArray.Num();
    jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
    for (jsize i = 0; i < arraySize; ++i) {
        jobject element = makeJava{{Camel .Name }}(env, cppArray[i]);
        env->SetObjectArrayElement(javaArray, i, element);
        env->DeleteLocalRef(element);
    }
    return javaArray;
}

{{- end }}


#endif
