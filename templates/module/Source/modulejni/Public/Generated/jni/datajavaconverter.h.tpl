{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name -}}
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
#pragma once
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
{{- $includeName :=  printf "\"%s/Generated/api/%s_apig.h\"" $importModuleName $importModuleName }}
{{- $includeName :=  printf "\"%s/Generated/Jni/%sDataJavaConverter.h\"" $importModuleName $importModuleName }}
{{- $includes = (appendList $includes $includeName) }}
{{- end }}
{{- $includes = unique $includes }}
{{ range $includes }}
#include {{ .}}
{{- end }}
{{- if or (len .Module.Enums) (len .Module.Structs) -}}
#include "{{ $ModuleName }}/Generated/api/{{ $ModuleName }}_data.h"
{{- end }}
{{- if len .Module.Interfaces }}
#include "{{ $ModuleName }}/Generated/api/{{ $ModuleName }}_apig.h"
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

#include "Engine/Engine.h"
{{$className := printf "%sDataJavaConverter" $ModuleName}}

class  {{ $API_MACRO }} {{$className }}{
public:

{{- range .Module.Structs }}

{{- $structType := printf "F%s%s" $ModuleName .Name }}
{{- $structName := printf "out_%s" (snake .Name)}}

	static void fill{{Camel .Name }}(JNIEnv* env, jobject input, {{$structType}}& {{$structName}});
	static void fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$structType}}>& out_array);
{{- $in_cppStructName := printf "out_%s" (snake .Name)}}
	static jobject makeJava{{Camel .Name }}(JNIEnv* env, const {{$structType}}& {{$in_cppStructName}});
	static jobjectArray makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$structType}}>& cppArray);
{{- end }}

{{- range .Module.Enums }}
{{- $cpp_class := printf "E%s%s" $ModuleName .Name }}

	static void fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$cpp_class}}>& out_array);
	static {{$cpp_class}} get{{Camel .Name }}Value(JNIEnv* env, jobject input);
	static jobjectArray makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$cpp_class}}>& cppArray);
	static jobject makeJava{{Camel .Name }}(JNIEnv* env, {{$cpp_class}} value);
{{- end }}

{{- range .Module.Interfaces }}

{{- $ifType := printf "TScriptInterface<I%s%sInterface>" $ModuleName (Camel .Name) }}
{{- $ifName := printf "out_%s" (snake .Name)}}

	static void fill{{Camel .Name }}(JNIEnv* env, jobject input, {{$ifType}} {{$ifName}});
	static void fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$ifType}}>& out_array);
{{- $in_cppIfName := printf "out_%s" (snake .Name)}}
	static jobject makeJava{{Camel .Name }}(JNIEnv* env, const {{$ifType}} {{$in_cppIfName}});
	static jobjectArray makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$ifType}}>& cppArray);

	static {{$ifType}} getCppInstance{{$ModuleName}}{{Camel .Name }}();
{{- end }}

{{- range .Module.Externs }}
{{- $module:= $.Module }}
{{- $ext := (ueExtern .) }}
{{- $namespace :=  $ext.NameSpace}}
{{- if $namespace }}
{{- $namespace =  "%s::"}}
{{- end }}
{{- $exType := printf "%s%s" $namespace $ext.Name }}
{{- $exName := printf "out_%s" (snake .Name)}}

	static void fill{{Camel .Name }}(JNIEnv* env, jobject input, {{$exType}}& {{$exName}});
	static void fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$exType}}>& out_array);
{{- $in_cppExName := printf "out_%s" (snake .Name)}}
	static jobject makeJava{{Camel .Name }}(JNIEnv* env, const {{$exType}}& {{$in_cppExName}});
	static jobjectArray makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$exType}}>& cppArray);
{{- end }}
};

#endif
