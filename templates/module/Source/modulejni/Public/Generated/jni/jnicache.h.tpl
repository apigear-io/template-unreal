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

#include "CoreMinimal.h"

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
{{- $CacheClassName := printf "%sJniCache" $ModuleName}}

class {{ $API_MACRO }} {{$CacheClassName }}
{

{{- range .Module.Structs }}
	{{- $className:= printf "javaStruct%s" (Camel .Name) }}
	static jclass {{$className}} = nullptr;
	static jmethodID {{$className}}Ctor = nullptr;
{{- range .Fields }}
	static jfieldID {{$className}}{{Camel .Name}}FieldId = nullptr;
{{- end }}
{{- end }}

{{- range .Module.Enums }}
	{{- $className:= printf "javaEnum%s" (Camel .Name) }}
	static jclass {{$className}} = nullptr;
	static jmethodID {{$className}}FromValueMethodId = nullptr;
	static jmethodID {{$className}}GetValueMethod = nullptr;

{{- end }}

{{- range .Module.Interfaces }}
{{- $className:= printf "javaClass%s" (Camel .Name) }}
	static jclass {{$className}} = nullptr;
{{- range .Properties }}
	{{- if not .IsReadOnly }}
	static jmethodID {{$className}}{{ Camel .Name}}SetterId = nullptr;
	{{- end }}
	static jmethodID {{$className}}{{ Camel .Name}}GetterId = nullptr;
{{- end }}
{{- range .Signals }}
	static jmethodID {{$className}}{{ Camel .Name}}SignalMethodID = nullptr;
{{- end }}
{{- range .Operations }}
	static jmethodID {{$className}}{{ Camel .Name}}MethodID = nullptr;
{{- end }}

{{- end }}

{{- range .Module.Externs }}
	static jclass javaClass{{.Name}} = nullptr;
	static jmethodID ctor{{.Name}} = nullptr;
{{- end }}

	static void init();
	static void clear();
	static bool isInitialized();

private:
	static bool m_isInitialized = false;
}

#endif
