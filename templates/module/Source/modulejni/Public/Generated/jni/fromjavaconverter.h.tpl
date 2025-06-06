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
{{- $includeName :=  printf "\"%s/Generated/Jni/%sFromJavaConverter.h\"" $importModuleName $importModuleName }}
{{- $includes = (appendList $includes $includeName) }}
{{- end }}
{{- $includes = unique $includes }}
{{ range $includes }}
#include {{ .}}
{{- end }}
{{ if or (len .Module.Enums) (len .Module.Structs) -}}
#include "{{ $ModuleName }}_data.generated.h"
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

#include "Engine/Engine.h"
{{$className := printf "%sJavaConverter" $ModuleName}}

class  {{ $API_MACRO }} {{$className }}{

{{- range .Module.Structs }}

{{- $structType := printf "F%s%s" $ModuleName .Name }}
{{- $structName := printf "out_%s" (snake .Name)}}

void fill{{Camel .Name }}(JNIEnv* env, jobject input, {{$structType}}& {{$structName}})

void fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$structType}}>& out_array);

{{- $in_cppStructName := printf "out_%s" (snake .Name)}}
jobject makeJava{{Camel .Name }}(JNIEnv* env, {{$structType}}& {{$in_cppStructName}})
jobjectArray makeJava{{Camel .Name }}Array(JNIEnv* env, TArray<{{$structType}}>& cppArray);
{{- end }}

{{- range .Module.Enums }}
{{- $cpp_class := printf "E%s%s" $ModuleName .Name }}

void fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$cpp_class}}>& out_array)
{{$cpp_class}} get{{Camel .Name }}Value(JNIEnv* env, jobject input)
jobjectArray makeJava{{Camel .Name }}Array(JNIEnv* env, TArray<{{$cpp_class}}>& cppArray);
jobject makeJava{{Camel .Name }}(JNIEnv* env,  int value);
{{- end }}


}
#endif