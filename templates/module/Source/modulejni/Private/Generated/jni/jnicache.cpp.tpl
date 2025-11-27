{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name -}}
{{- $jmoduleName := camel .Module.Name -}}
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
{{- $StaticCacheName := printf "%sJniCache" $ModuleName}}

DEFINE_LOG_CATEGORY(Log{{$StaticCacheName}}_JNI);

void {{$StaticCacheName }}::checkException(JNIEnv* env, FString memberInfo)
{
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(Log{{$StaticCacheName}}_JNI, Warning, TEXT("Could not find %s"), *memberInfo);
	}
}

{{- range .Module.Structs }}
{{- $className:= printf "javaStruct%s" (Camel .Name) }}
jclass {{$StaticCacheName }}::{{$className}} = nullptr;
jmethodID {{$StaticCacheName }}::{{$className}}Ctor = nullptr;
{{- range .Fields }}
jfieldID {{$StaticCacheName }}::{{$className}}{{Camel .Name}}FieldId = nullptr;
{{- end }}
{{- end }}

{{- range .Module.Enums }}
{{- $className:= printf "javaEnum%s" (Camel .Name) }}
jclass {{$StaticCacheName }}::{{$className}} = nullptr;
jmethodID {{$StaticCacheName }}::{{$className}}FromValueMethodId = nullptr;
jmethodID {{$StaticCacheName }}::{{$className}}GetValueMethod = nullptr;
{{- end }}

{{- range .Module.Interfaces }}
{{- $className:= printf "javaClass%s" (Camel .Name) }}
jclass {{$StaticCacheName }}::{{$className}} = nullptr;
{{- range .Properties }}
{{- if not .IsReadOnly }}
jmethodID {{$StaticCacheName }}::{{$className}}{{ Camel .Name}}SetterId = nullptr;
{{- end }}
jmethodID {{$StaticCacheName }}::{{$className}}{{ Camel .Name}}GetterId = nullptr;
{{- end }}

{{- $serviceClass:= printf "serviceClass%s" (Camel .Name) }}
{{- $clientClass:= printf "clientClass%s" (Camel .Name) }}
jclass {{$StaticCacheName }}::{{$serviceClass}} = nullptr;
jmethodID {{$StaticCacheName }}::{{$serviceClass}}ReadyMethodID = nullptr;
{{- range .Properties }}
jmethodID {{$StaticCacheName }}::{{$serviceClass}}{{ Camel .Name}}ChangedMethodID = nullptr;
{{- end }}
{{- range .Signals }}
jmethodID {{$StaticCacheName }}::{{$serviceClass}}{{ Camel .Name}}SignalMethodID = nullptr;
{{- end }}
jclass {{$StaticCacheName }}::{{$clientClass}} = nullptr;
jmethodID {{$StaticCacheName }}::{{$clientClass}}Ctor = nullptr;
jmethodID {{$StaticCacheName }}::{{$clientClass}}BindMethodID = nullptr;
jmethodID {{$StaticCacheName }}::{{$clientClass}}UnbindMethodID = nullptr;

{{- range .Operations }}
jmethodID {{$StaticCacheName }}::{{$clientClass}}{{ Camel .Name}}AsyncMethodID = nullptr;
{{- end }}


{{- end }}

{{- range .Module.Externs }}
jclass {{$StaticCacheName }}::javaClass{{.Name}} = nullptr;
jmethodID {{$StaticCacheName }}::javaClass{{.Name}}Ctor = nullptr;
{{- end }}

bool {{$StaticCacheName }}::m_isInitialized = false;

void {{$StaticCacheName }}::init()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
{{- range .Module.Structs }}
	{{- $className:= printf "javaStruct%s" (Camel .Name) }}
	{{- $packageName := printf "%s/%s_api" $jmoduleName $jmoduleName }}
	{{- $javaClassTypeName := Camel .Name}}
	{{$className}} = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
	checkException(env, "{{$packageName}}/{{$javaClassTypeName}}");
	{{$className}}Ctor = env->GetMethodID({{$StaticCacheName }}::{{$className}}, "<init>", "()V");
	checkException(env, "method <init>, ()V for {{$packageName}}/{{$javaClassTypeName}}");
{{- range .Fields }}
	{{- $javaFieldName := camel .Name}}
	{{$className}}{{Camel .Name}}FieldId = env->GetFieldID({{$StaticCacheName }}::{{$className}}, "{{$javaFieldName}}", "{{jniSignatureType . }}");
	checkException(env, "{{$javaFieldName}}, {{jniSignatureType . }} for {{$packageName}}/{{$javaClassTypeName}}");
{{- end }}
{{- end }}

{{- range .Module.Enums }}
{{- $packageName := printf "%s/%s_api" $jmoduleName $jmoduleName}}
{{- $javaClassTypeName := Camel .Name}}

	{{- $className:= printf "javaEnum%s" (Camel .Name) }}
	{{$className}} = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
	checkException(env, "{{$packageName}}/{{$javaClassTypeName}}");
	{{$className}}FromValueMethodId = env->GetStaticMethodID({{$StaticCacheName }}::{{$className}}, "fromValue", "(I)L{{$packageName}}/{{$javaClassTypeName}};");
	checkException(env, "fromValue (I)L{{$packageName}}/{{$javaClassTypeName}}; for {{$packageName}}/{{$javaClassTypeName}}");
	{{$className}}GetValueMethod = env->GetMethodID({{$StaticCacheName }}::{{$className}}, "getValue", "()I");
	checkException(env, "getValue (I)L{{$packageName}}/{{$javaClassTypeName}}; for {{$packageName}}/{{$javaClassTypeName}}");

{{- end }}

{{- range .Module.Interfaces }}
{{- $fullJavaClassType := printf "%s/%s_api/I%s" $jmoduleName $jmoduleName (Camel .Name) }}
{{- $className:= printf "javaClass%s" (Camel .Name) }}

	{{$className}} = FAndroidApplication::FindJavaClassGlobalRef("{{$fullJavaClassType}}");
	checkException(env, "{{$fullJavaClassType}}");
{{- range .Properties }}
	{{- $signatureParam := jniJavaSignatureParam . }}
	{{- if not .IsReadOnly }}
	{{$className}}{{ Camel .Name}}SetterId = env->GetMethodID({{$StaticCacheName }}::{{$className}}, "set{{Camel .Name}}", "({{$signatureParam}})V");
	checkException(env, "set{{Camel .Name}}, ({{$signatureParam}})V  for {{$fullJavaClassType}}");
	{{- end }}
	{{$className}}{{ Camel .Name}}GetterId = env->GetMethodID({{$StaticCacheName }}::{{$className}}, "get{{Camel .Name}}", "(){{$signatureParam}}");
	checkException(env, "get{{Camel .Name}}, (){{$signatureParam}} for {{$fullJavaClassType}}");
{{- end }}

{{- $serviceClass:= printf "serviceClass%s" (Camel .Name) }}
{{- $javaServiceTypeName := printf "%sJniService" (Camel .Name) }}
{{- $jniservice_name:= printf "%sjniservice" ( camel $ModuleName) }}
{{- $javaServicePath := ( join "/" (strSlice ( camel $ModuleName) $jniservice_name) ) }}
{{- $clientClass:= printf "clientClass%s" (Camel .Name) }}
{{- $javaClientTypeName := printf "%sJniClient"  (Camel .Name) }}
{{- $jniclient_name:= printf "%sjniclient" ( camel $ModuleName) }}
{{- $javaClientPath := ( join "/" (strSlice ( camel $ModuleName) $jniclient_name) ) }}

	{{$serviceClass}} = FAndroidApplication::FindJavaClassGlobalRef("{{$javaServicePath}}/{{$javaServiceTypeName}}");
	checkException(env, "{{$javaServicePath}}/{{$javaServiceTypeName}}");
	{{$serviceClass}}ReadyMethodID = env->GetMethodID({{$StaticCacheName }}::{{$serviceClass}}, "nativeServiceReady", "(Z)V");
	checkException(env, "nativeServiceReady, (Z)V for {{$javaServicePath}}/{{$javaServiceTypeName}}");
{{- range .Properties }}
	{{- $signatureParam := jniJavaSignatureParam . }}
	{{$serviceClass}}{{ Camel .Name}}ChangedMethodID = env->GetMethodID({{$StaticCacheName }}::{{$serviceClass}}, "on{{Camel .Name}}Changed", "({{$signatureParam}})V");
	checkException(env, "on{{Camel .Name}}Changed, ({{$signatureParam}})V for {{$javaServicePath}}/{{$javaServiceTypeName}}");
{{- end }}
{{- range .Signals }}
	{{- $signatureParams := jniJavaSignatureParams .Params }}
	{{$serviceClass}}{{ Camel .Name}}SignalMethodID = env->GetMethodID({{$StaticCacheName }}::{{$serviceClass}}, "on{{Camel .Name}}", "({{$signatureParams}})V");
	checkException(env, "on{{Camel .Name}}, ({{$signatureParams}})V for {{$javaServicePath}}/{{$javaServiceTypeName}}");
{{- end }}
	{{$clientClass}} = FAndroidApplication::FindJavaClassGlobalRef("{{$javaClientPath}}/{{$javaClientTypeName}}");
	checkException(env, "{{$javaClientPath}}/{{$javaClientTypeName}}");
{{- range .Operations }}
	{{- $signatureParams := jniJavaSignatureParams .Params }}
	{{$clientClass}}{{Camel .Name}}AsyncMethodID = env->GetMethodID({{$StaticCacheName }}::{{$clientClass}}, "{{camel .Name}}Async", "(Ljava/lang/String;{{$signatureParams}})V");
	checkException(env, "{{camel .Name}}Async, (Ljava/lang/String;{{$signatureParams}})V for {{$javaClientPath}}/{{$javaClientTypeName}}");
{{- end }}
	{{$clientClass}}Ctor = env->GetMethodID({{$StaticCacheName}}::{{$clientClass}}, "<init>", "()V");
	checkException(env, "init, ()V for {{$javaClientPath}}/{{$javaClientTypeName}}");
	{{$clientClass}}BindMethodID = env->GetMethodID({{$StaticCacheName}}::{{$clientClass}}, "bind", "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z");
	checkException(env, "bind, (Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Z for {{$javaClientPath}}/{{$javaClientTypeName}}");
	{{$clientClass}}UnbindMethodID = env->GetMethodID({{$StaticCacheName}}::{{$clientClass}}, "unbind", "()V");
	checkException(env, "unbind, ()V for {{$javaClientPath}}/{{$javaClientTypeName}}");
{{- end }}

{{- range .Module.Externs }}
{{- $extJava := (javaExtern .) }}
{{- $fullJavaClassType := $extJava.Name }}
{{- $prefix := (replace ($extJava.Package) "." "/" ) }}
{{- if ne $prefix "" }}
{{- $fullJavaClassType = printf "%s/%s" $prefix $fullJavaClassType }}
{{- end }}
	javaClass{{.Name}} = FAndroidApplication::FindJavaClassGlobalRef("{{$fullJavaClassType}}");
	checkException(env, "{{$fullJavaClassType}}");
	javaClass{{.Name}}Ctor = env->GetMethodID({{$StaticCacheName }}::javaClass{{.Name}}, "<init>", "()V");
	checkException(env, "init, ()V for {{$fullJavaClassType}}");
{{- end }}
	m_isInitialized = true;
}

void {{$StaticCacheName }}::clear()
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
{{- $className:= printf "javaClass%s" (Camel .Name) }}
	env->DeleteGlobalRef({{$className}});
	{{$className}} = nullptr;
{{- range .Properties }}
	{{- if not .IsReadOnly }}
	{{$className}}{{ Camel .Name}}SetterId = nullptr;
	{{- end }}
	{{$className}}{{ Camel .Name}}GetterId = nullptr;
{{- end }}

{{- $serviceClass:= printf "serviceClass%s" (Camel .Name) }}
{{- $clientClass:= printf "clientClass%s" (Camel .Name) }}
	env->DeleteGlobalRef({{$serviceClass}});
	{{$serviceClass}} = nullptr;
	{{$serviceClass}}ReadyMethodID = nullptr;
{{- range .Properties }}
	{{$serviceClass}}{{ Camel .Name}}ChangedMethodID = nullptr;
{{- end }}
{{- range .Signals }}
	{{$serviceClass}}{{ Camel .Name}}SignalMethodID = nullptr;
{{- end }}
	env->DeleteGlobalRef({{$clientClass}});
	{{$clientClass}} = nullptr;
{{- range .Operations }}
	{{$clientClass}}{{ Camel .Name}}AsyncMethodID = nullptr;
{{- end }}
	{{$clientClass}}Ctor = nullptr;
	{{$clientClass}}BindMethodID = nullptr;
	{{$clientClass}}UnbindMethodID = nullptr;
{{- end }}

{{- range .Module.Externs }}
	env->DeleteGlobalRef(javaClass{{.Name}});
	javaClass{{.Name}} = nullptr;
	javaClass{{.Name}}Ctor = nullptr;
{{- end }}
}

bool {{$StaticCacheName }}::isInitialized()
{
	return m_isInitialized;
}

#endif
