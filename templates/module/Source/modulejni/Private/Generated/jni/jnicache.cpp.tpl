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

#include "{{$ModuleName}}/Generated/Jni/{{$ModuleName}}JniCache.h"
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

// TODO
// after each findJAvaClassGlobalRef and getting methodId or FieldId
// if (env->ExceptionCheck()) {
//	env->ExceptionDescribe(); // logs in java
//	env->ExceptionClear();
//	LOG UE;
//}

void {{$CacheClassName }}::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
{{- range .Module.Structs }}
	{{- $className:= printf "javaStruct%s" (Camel .Name) }}
	{{- $packageName := printf "%s/%s_api" $ModuleName $ModuleName }}
	{{- $javaClassTypeName := Camel .Name}}
	{{$className}} = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
	{{$className}}Ctor = env->GetMethodID({{$CacheClassName }}::{{$className}}, "<init>", "()V");
{{- range .Fields }}
	{{- $javaFieldName := camel .Name}}
	{{- $className:= printf "javaStruct%s" (Camel .Name) }}
	{{$className}}{{snake .Name}}FieldId = env->GetFieldID({{$CacheClassName }}::{{$className}}, "{{$javaFieldName}}", "{{jniSignatureType . }}");
{{- end }}
{{- end }}

{{- range .Module.Enums }}
{{- $packageName := printf "%s/%s_api" $ModuleName $ModuleName}}
{{- $javaClassTypeName := Camel .Name}}

	{{- $className:= printf "javaEnum%s" (Camel .Name) }}
	{{$className}} = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
	{{$className}}FromValueMethodId = env->GetStaticMethodID({{$CacheClassName }}::{{$className}}, "fromValue", "(I)L{{$packageName}}/{{$javaClassTypeName}};");
	{{$className}}GetValueMethod = env->GetMethodID({{$CacheClassName }}::{{$className}}, "getValue", "()I");

{{- end }}

{{- range .Module.Interfaces }}
{{- $fullJavaClassType := printf "%s/%s_api/I%s" $ModuleName $ModuleName (Camel .Name) }}
{{- $className:= printf "javaClass%s" (Camel .Name) }}

	{{$className}} = FAndroidApplication::FindJavaClassGlobalRef("{{$fullJavaClassType}}");
{{- range .Properties }}
	{{- $signatureParam := jniJavaSignatureParam . }}
	{{- if not .IsReadOnly }}
	{{$className}}{{ Camel .Name}}SetterId = env->GetMethodID({{$CacheClassName }}::{{$className}}, "set{{Camel .Name}}", "({{$signatureParam}})V");
	{{- end }}
	{{$className}}{{ Camel .Name}}GetterId = env->GetMethodID({{$CacheClassName }}::{{$className}}, "get{{Camel .Name}}", "(){{$signatureParam}}");
{{- end }}
{{- range .Signals }}
	{{- $signatureParams := jniJavaSignatureParams .Params }}
	{{$className}}{{ Camel .Name}}SignalMethodID = env->GetMethodID({{$CacheClassName }}::{{$className}}, "on{{Camel .Name}}", "({{$signatureParams}})V");
{{- end }}
{{- range .Operations }}
	{{- $signatureParams := jniJavaSignatureParams .Params }}
	{{$className}}{{ Camel .Name}}MethodID = env->GetMethodID({{$CacheClassName }}::{{$className}}, "{{camel .Name}}Async", "(Ljava/lang/String;{{$signatureParams}})V");
{{- end }}

{{- end }}

{{- range .Module.Externs }}
{{- $extJava := (javaExtern .) }}
{{- $fullJavaClassType := $extJava.Name }}
{{- $prefix := (replace ($extJava.Package) "." "/" ) }}
{{- if ne $prefix "" }}
{{- $fullJavaClassType = printf "%s/%s" $prefix $fullJavaClassType }}
{{- end }}
	javaClass{{.Name}} = FAndroidApplication::FindJavaClassGlobalRef("{{$fullJavaClassType}}");
	ctor{{.Name}} = env->GetMethodID({{$CacheClassName }}::javaClass{{.Name}}, "<init>", "()V");
{{- end }}
	m_isInitialized = true;
}

void {{$CacheClassName }}::clear()
{
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();

{{- range .Module.Structs }}
	{{- $className:= printf "javaStruct%s" (Camel .Name) }}
	env->DeleteGlobalRef({{$className}});
	{{$className}} = nullptr;
	{{$className}}Ctor = nullptr;
{{- range .Fields }}
	{{$className}}{{Camel .Name}}FieldId = nullptr;
{{- end }}
{{- end }}

{{- range .Module.Enums }}
	{{- $className:= printf "javaEnum%s" (Camel .Name) }}
	env->DeleteGlobalRef({{$className}});
	{{$className}} = nullptr;
	{{$className}}FromValueMethodId = nullptr;
	{{$className}}GetValueMethod = nullptr;

{{- end }}

{{- range .Module.Interfaces }}
{{- $fullJavaClassType := printf "%s/%s_api/I%s" $ModuleName $ModuleName (Camel .Name) }}
{{- $className:= printf "javaClass%s" (Camel .Name) }}
	env->DeleteGlobalRef({{$className}});
	{{$className}} = nullptr;
{{- range .Properties }}
	{{- if not .IsReadOnly }}
	{{$className}}{{ Camel .Name}}SetterId = nullptr;
	{{- end }}
	{{$className}}{{ Camel .Name}}GetterId = nullptr;
{{- end }}
{{- range .Signals }}
	{{$className}}{{ Camel .Name}}SignalMethodID = nullptr;
{{- end }}
{{- range .Operations }}
	{{$className}}{{ Camel .Name}}MethodID = nullptr;
{{- end }}

{{- end }}

{{- range .Module.Externs }}
	env->DeleteGlobalRef(javaClass{{.Name}});
	javaClass{{.Name}} = nullptr;
	ctor{{.Name}} = nullptr;
{{- end }}
}

bool {{$CacheClassName }}::isInitialized()
{
	return m_isInitialized;
}

#endif
