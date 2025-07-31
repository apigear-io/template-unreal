{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name -}}
{{- $moduleName := Camel .Module.Name -}}
{{- $Category := printf "ApiGear|%s" $ModuleName }}
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

#include "{{$ModuleName}}/Generated/Jni/PocFromJavaConverter.h"

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
{{- $includeName :=  printf "\"%s/Generated/Jni/%sFromJavaConverter.h\"" $importModuleName $importModuleName }}
{{- $includes = (appendList $includes $includeName) }}
{{- end }}
{{- $includes = unique $includes }}
{{ range $includes }}
#include {{ .}}
{{- end }}
{{ if or (len .Module.Enums) (len .Module.Structs) -}}
#include "{{$ModuleName}}/Generated/api/{{ $ModuleName }}_data.h"
{{ end }}

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif


#if PLATFORM_ANDROID && USE_ANDROID_JNI

{{$className := printf "%sJavaConverter" $ModuleName}}

//TODO refs should be somhow static - globalref?, not searched each time
{{- range .Module.Structs }}

{{- $structType := printf "F%s%s" $ModuleName .Name }}
{{- $structName := printf "out_%s" (snake .Name)}}

void {{$className }}::fill{{Camel .Name }}(JNIEnv* env, jobject input, {{$structType}}& {{$structName}})
{

    jclass cls = env->GetObjectClass(input);

{{- range .Fields }}
	{{- $cppFieldName :=  .Name}}
	{{- $javaFieldName := camel .Name}}

	jfieldID jFieldId_{{snake .Name}} = env->GetFieldID(cls, "{{$javaFieldName}}", "{{ueJniSignatureType . }}");

	{{- if .IsArray }}
	{{ ueJniToReturnType . }} {{snake .Name}}_value = (jobjectArray)env->GetObjectField(input,jFieldId_{{snake .Name}});		
	{{- if (eq .KindType "enum") }}
		{{- $otherModuleClassName := printf "%sJavaConverter" ( Camel .Schema.Import ) }}
		{{if not (eq $otherModuleClassName  "JavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
		fill{{Camel .Type }}Array(env, {{snake .Name}}_value, {{$structName}}.{{$cppFieldName}});
	{{- else if (eq .KindType "string")}}
		{{$structName}}.{{$cppFieldName}} = FJavaHelper::ObjectArrayToFStringTArray(env, {{snake .Name}}_value);
	{{- else if .IsPrimitive }}
		jsize len{{snake .Name}} = env->GetArrayLength({{snake .Name}}_value);
		{{$structName}}.{{$cppFieldName}}.Reserve(len{{snake .Name}});
		env->Get{{ueToEnvNameType .}}ArrayRegion({{snake .Name}}_value, 0,  len{{snake .Name}}, {{$structName}}.{{$cppFieldName}}.GetData());
	{{- else if not (eq .KindType "extern")}}
		{{- $otherModuleClassName := printf "%sJavaConverter" ( Camel .Schema.Import ) }}
		{{if not (eq $otherModuleClassName  "JavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
		fill{{Camel .Name }}Array(env, {{snake .Name}}_value, {{$structName}}.{{$cppFieldName}});
	{{- end }}
		env->DeleteLocalRef({{snake .Name}}_value);
	{{- else if eq .KindType "enum"}}
		{{- $otherModuleClassName := printf "%sJavaConverter" ( Camel .Schema.Import ) }}
		{{$structName}}.{{$cppFieldName}} = {{if not (eq $otherModuleClassName  "JavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
		get{{Camel .Name }}Value(env, jFieldId_{{snake .Name}});
	{{- else if eq .KindType "string"}}
		jstring {{snake .Name}}_value = (jstring)env->GetObjectField(input, jFieldId_{{snake .Name}});
		{{$structName}}.{{$cppFieldName}} = FJavaHelper::FStringFromLocalRef(env,{{snake .Name}}_value);
	{{- else if .IsPrimitive }}
		{{$structName}}.{{$cppFieldName}} =  env->Get{{ueToEnvNameType .}}Field(input, jFieldId_{{snake .Name}});
	{{- else if not (eq .KindType "extern")}}
		{{ ueJniToReturnType . }} {{snake .Name}}_value = env->GetObjectField(input, jFieldId_{{snake .Name}});
		{{- $otherModuleClassName := printf "%sJavaConverter" ( Camel .Schema.Import ) }}
		{{if not (eq $otherModuleClassName  "JavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
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

//--------------------------TO JAVA-------------------------------

{{- $in_cppStructName := printf "out_%s" (snake .Name)}}
{{- $api_package_name := printf "%s_api" (camel $moduleName) }}
{{- $packageName := ueJavaPath $moduleName $api_package_name ""}}
{{- $javaClassTypeName := .Name}}

jobject {{$className }}::makeJava{{Camel .Name }}(JNIEnv* env, const {{$structType}}& {{$in_cppStructName}})
{
	//make instance

	// TODO SHOULD BE STATIC, not searched each time
	jclass javaClass = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
    jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
    jobject javaObjInstance = env->NewObject(javaClass, ctor);

{{- range .Fields }}
	{{- $cppFieldName :=  .Name}}
	{{- $javaFieldName := camel .Name}}
	{{- $tmpObjName := printf "l_%s" $javaFieldName }}

	jfieldID jFieldId_{{snake .Name}} = env->GetFieldID(javaClass, "{{$javaFieldName}}", "{{ueJniSignatureType . }}");

{{- if .IsArray }}
{{ ueJniToReturnType . }} {{snake .Name}}_value = (jobjectArray)env->GetObjectField(input,jFieldId_{{snake .Name}});		
{{- if (eq .KindType "enum") }}
	{{- $otherModuleClassName := printf "%sJavaConverter" ( Camel .Schema.Import ) }}
	jobjectArray {{$tmpObjName}} = s{{if not (eq $otherModuleClassName  "JavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
	makeJava{{Camel .Name }}Array(env, {{$structName}}.{{$cppFieldName}});
{{- else if (eq .KindType "string")}}
	jobjectArray {{$tmpObjName}} = FJavaHelper::ToJavaStringArray(env,{{$structName}}.{{$cppFieldName}});
{{- else if .IsPrimitive }}
	auto len = {{$structName}}.{{$cppFieldName}}.Num();
	jFieldId_{{snake .Name}} = (*env)->New{{ueToEnvNameType .}}Array(len);
	if (jFieldId_{{snake .Name}}  == NULL){/*Log error, skip?*/};
	env->Set{{ueToEnvNameType .}}ArrayRegion(jFieldId_{{snake .Name}}, 0, len, {{$structName}}.{{$cppFieldName}}.GetData());
{{- else if not (eq .KindType "extern")}}
	{{- $otherModuleClassName := printf "%sJavaConverter" ( Camel .Schema.Import ) }}
	jobjectArray {{$tmpObjName}} = {{if not (eq $otherModuleClassName  "JavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
	makeJava{{Camel .Name }}Array(env, {{$structName}}.{{$cppFieldName}});
{{- end }}
	env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, {{$tmpObjName}});
	env->DeleteLocalRef({{$tmpObjName}});
{{- else if eq .KindType "enum"}}
	{{- $otherModuleClassName := printf "%sJavaConverter" ( Camel .Schema.Import ) }}
	jobject {{$tmpObjName}} = {{if not (eq $otherModuleClassName  "JavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
	makeJava{{Camel .Name }}(env, {{$structName}}.{{$cppFieldName}});
	env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, {{$tmpObjName}});
	env->DeleteLocalRef({{$tmpObjName}});
{{- else if eq .KindType "string"}}
	jobject {{$tmpObjName}} = (jstring)env->GetObjectField(input, jFieldId_{{snake .Name}});
	{{$structName}}.{{$cppFieldName}} = FJavaHelper::ToJavaString(env,{{$in_cppStructName}}.{{$cppFieldName}});
	env->DeleteLocalRef({{$tmpObjName}});
{{- else if .IsPrimitive }}
	env->Set{{ueToEnvNameType .}}Field(javaObjInstance, jFieldId_{{snake .Name}}, {{$in_cppStructName}}.{{$cppFieldName}});
{{- else if not (eq .KindType "extern")}}
	{{- $otherModuleClassName := printf "%sJavaConverter" ( Camel .Schema.Import ) }}
	jobject {{$tmpObjName}} = {{if not (eq $otherModuleClassName  "JavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
	makeJava{{Camel .Type }}(env,{{$structName}}.{{$cppFieldName }});
	env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, {{$tmpObjName}});
	env->DeleteLocalRef({{$tmpObjName}});
{{- end }}

{{- end }}
	return javaObjInstance;
}

jobjectArray {{$className }}::makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$structType}}>& cppArray)
{
	//TODO globalref should be stored somewhere
	jclass javaStruct = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray( arraySize, javaStruct, nullptr);
	for (jsize i = 0; i < arraySize; ++i) {
		jobject element = makeJava{{Camel .Name }}(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);  // Clean up
	}
	return javaArray;
}
//----------------------------------------------------------------
{{- end }}

{{- range .Module.Enums }}
{{- $moduleEnumName := printf "%s%s" $ModuleName .Name }}
{{- $cpp_class := printf "E%s%s" $ModuleName .Name }}

{{- $in_cppStructName := printf "out_%s" (snake .Name)}}
{{- $api_package_name := printf "%s_api" (camel $moduleName) }}
{{- $packageName := ueJavaPath $moduleName $api_package_name ""}}
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
	//TODO globalref should be stored somewhere
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
#endif
