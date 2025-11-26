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
{{- $StaticCacheName := printf "%sJniCache" $ModuleName}}

class {{ $API_MACRO }} {{$StaticCacheName }}
{
public:
{{- range .Module.Structs }}
	{{- $className:= printf "javaStruct%s" (Camel .Name) }}
	static jclass {{$className}};
	static jmethodID {{$className}}Ctor;
{{- range .Fields }}
	static jfieldID {{$className}}{{Camel .Name}}FieldId;
{{- end }}
{{- end }}

{{- range .Module.Enums }}
	{{- $className:= printf "javaEnum%s" (Camel .Name) }}
	static jclass {{$className}};
	static jmethodID {{$className}}FromValueMethodId;
	static jmethodID {{$className}}GetValueMethod;

{{- end }}

{{- range .Module.Interfaces }}
{{- $className:= printf "javaClass%s" (Camel .Name) }}
	static jclass {{$className}};
{{- range .Properties }}
	{{- if not .IsReadOnly }}
	static jmethodID {{$className}}{{ Camel .Name}}SetterId;
	{{- end }}
	static jmethodID {{$className}}{{ Camel .Name}}GetterId;
	static jmethodID {{$className}}{{ Camel .Name}}ChangedMethodID;
{{- end }}

{{- $serviceClass:= printf "serviceClass%s" (Camel .Name) }}
{{- $clientClass:= printf "clientClass%s" (Camel .Name) }}
	static jclass {{$serviceClass}};
	static jmethodID {{$serviceClass}}ReadyMethodID;
{{- range .Properties }}
	static jmethodID {{$serviceClass}}{{ Camel .Name}}ChangedMethodID;
{{- end }}
{{- range .Signals }}
	static jmethodID {{$serviceClass}}{{ Camel .Name}}SignalMethodID;
{{- end }}
	static jclass {{$clientClass}};
	static jmethodID {{$clientClass}}Ctor;
	static jmethodID {{$clientClass}}BindMethodID;
	static jmethodID {{$clientClass}}UnbindMethodID;

{{- range .Operations }}
	static jmethodID {{$clientClass}}{{ Camel .Name}}AsyncMethodID;
{{- end }}


{{- end }}

{{- range .Module.Externs }}
	static jclass javaClass{{.Name}};
	static jmethodID javaClass{{.Name}}Ctor;
{{- end }}

	static void init();
	static void clear();
	static bool isInitialized();

private:
	static bool m_isInitialized;
};

#endif
