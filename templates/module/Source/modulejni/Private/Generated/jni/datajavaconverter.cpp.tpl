{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name -}}
{{- $jmoduleName := camel .Module.Name -}}
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
{{- $includeName := printf "\"%s\"" $class.Include }}
{{- $includes = (appendList $includes $includeName) }}
{{- end }}
{{- end }}
{{- range .Module.Imports }}
{{- $importModuleName := Camel .Name }}
{{- $includeNameData := printf "\"%s/Generated/api/%s_data.h\"" $importModuleName $importModuleName }}
{{- $includes = (appendList $includes $includeNameData) }}
{{- $includeName := printf "\"%s/Generated/Jni/%sDataJavaConverter.h\"" $importModuleName $importModuleName }}
{{- $includes = (appendList $includes $includeName) }}
{{- end }}
{{- $includes = unique $includes }}
{{- range $includes }}
#include {{ .}}
{{- end }}
{{- if or (len .Module.Enums) (len .Module.Structs) }}
#include "{{$ModuleName}}/Generated/api/{{ $ModuleName }}_data.h"
{{- end -}}

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

{{- $className := printf "%sDataJavaConverter" $ModuleName}}

DEFINE_LOG_CATEGORY(Log{{$className}}_JNI);

struct F{{$className}}CacheData
{
{{- range .Module.Structs }}
	jclass j{{Camel .Name}} = nullptr;
{{- end }}
{{- range .Module.Enums }}
	jclass j{{Camel .Name}} = nullptr;
{{- end }}
{{- range .Module.Interfaces }}
	jclass j{{Camel .Name}} = nullptr;
{{- end }}
{{- range .Module.Externs }}
	jclass j{{Camel .Name}} = nullptr;
{{- end }}

	~F{{$className}}CacheData()
	{
		JNIEnv* Env = FAndroidApplication::GetJavaEnv();
		if (Env)
		{
		{{- range .Module.Structs }}
			if (j{{Camel .Name}}) Env->DeleteGlobalRef(j{{Camel .Name}});
		{{- end }}
		{{- range .Module.Enums }}
			if (j{{Camel .Name}}) Env->DeleteGlobalRef(j{{Camel .Name}});
		{{- end }}
		{{- range .Module.Interfaces }}
			if (j{{Camel .Name}}) Env->DeleteGlobalRef(j{{Camel .Name}});
		{{- end }}
		{{- range .Module.Externs }}
			if (j{{Camel .Name}}) Env->DeleteGlobalRef(j{{Camel .Name}});
		{{- end }}
		}
	}
};

FCriticalSection {{$className}}::CacheLock;
TSharedPtr<F{{$className}}CacheData, ESPMode::ThreadSafe> {{$className}}::CacheData;

{{- range .Module.Structs }}
{{- $cachedStruct := printf "j%s" (Camel .Name) }}
{{- $structType := printf "F%s%s" $ModuleName .Name }}
{{- $structName := printf "out_%s" (snake .Name)}}

void {{$className }}::fill{{Camel .Name }}(JNIEnv* env, jobject input, {{$structType}}& {{$structName}})
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$className}} cache not initialized for fill{{Camel .Name}}"));
		return;
	}
{{- range .Fields }}
	{{- $cppFieldName := .Name}}
	{{- $javaFieldName := camel .Name}}

	static const TCHAR* errorMsgFind{{$javaFieldName}} = TEXT("failed when trying to field {{$javaFieldName}} {{jniSignatureType . }} for {{$structType}}");
	static const jfieldID jFieldId_{{snake .Name}} = getFieldId(Cache->{{$cachedStruct}}, "{{$javaFieldName}}", "{{jniSignatureType . }}", errorMsgFind{{$javaFieldName}});

	if (jFieldId_{{snake .Name}})
	{
	{{- if .IsArray }}
		{{ jniToReturnType . }} {{snake .Name}}_value = ({{jniToReturnType . }})env->GetObjectField(input, jFieldId_{{snake .Name}});
		static const TCHAR* errorMsg{{$cppFieldName}}Field = TEXT("failed when getting the jFieldId_{{snake .Name}} for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}}Field);
	{{- if (eq .KindType "enum") }}
		{{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
		{{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
		fill{{Camel .Type }}Array(env, {{snake .Name}}_value, {{$structName}}.{{$cppFieldName}});
	{{- else if (eq .KindType "string")}}
		{{$structName}}.{{$cppFieldName}} = FJavaHelper::ObjectArrayToFStringTArray(env, {{snake .Name}}_value);
		static const TCHAR* errorMsg{{$cppFieldName}} = TEXT("failed when converting from jstring array for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}});

	{{- else if (eq .KindType "bool")}}
		jsize len{{snake .Name}} = env->GetArrayLength({{snake .Name}}_value);
		static const TCHAR* errorMsg{{$cppFieldName}}Len = TEXT("failed when getting lengt of a java array {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}}Len);
		{{$structName}}.{{$cppFieldName}}.Reserve(len{{snake .Name}});
		TArray<jboolean> Temp;
		Temp.SetNumUninitialized(len{{snake .Name}});
		env->GetBooleanArrayRegion({{snake .Name}}_value, 0, len{{snake .Name}}, Temp.GetData());
		static const TCHAR* errorMsg{{$cppFieldName}} = TEXT("failed when getting a java array region for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}});
		for (int i = 0; i < len{{snake .Name}}; i++)
		{
			{{$structName}}.{{$cppFieldName}}.Add(Temp[i] == JNI_TRUE);
		}
	{{- else if .IsPrimitive }}
		jsize len{{snake .Name}} = env->GetArrayLength({{snake .Name}}_value);
		static const TCHAR* errorMsg{{$cppFieldName}}Len = TEXT("failed when getting lengt of a java array {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}}Len);
		{{$structName}}.{{$cppFieldName}}.AddUninitialized(len{{snake .Name}});
		env->Get{{jniToEnvNameType .}}ArrayRegion({{snake .Name}}_value, 0, len{{snake .Name}}, {{ if (eq .KindType "int64") -}}
			reinterpret_cast<jlong*>({{$structName}}.{{$cppFieldName}}.GetData()));
			{{- else -}}
			{{$structName}}.{{$cppFieldName}}.GetData());
			{{- end }}
		static const TCHAR* errorMsg{{$cppFieldName}} = TEXT("failed when getting a java array region for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}});
	{{- else }}
		{{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
		{{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
		fill{{Camel .Type }}Array(env, {{snake .Name}}_value, {{$structName}}.{{$cppFieldName}});
	{{- end }}
		env->DeleteLocalRef({{snake .Name}}_value);
	{{- else if eq .KindType "enum"}}
		{{ jniToReturnType . }} {{snake .Name}}_value = env->GetObjectField(input, jFieldId_{{snake .Name}});
		static const TCHAR* errorMsg{{$cppFieldName}} = TEXT("failed when getting the jFieldId_{{snake .Name}} for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}});
		{{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
		{{$structName}}.{{$cppFieldName}} = {{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
		get{{Camel .Type }}Value(env, {{snake .Name}}_value);
		env->DeleteLocalRef({{snake .Name}}_value);
	{{- else if eq .KindType "string"}}
		jstring {{snake .Name}}_value = (jstring)env->GetObjectField(input, jFieldId_{{snake .Name}});
		static const TCHAR* errorMsg{{$cppFieldName}} = TEXT("failed when getting the jFieldId_{{snake .Name}} for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}});
		{{$structName}}.{{$cppFieldName}} = FJavaHelper::FStringFromLocalRef(env, {{snake .Name}}_value);
		static const TCHAR* errorMsg{{$cppFieldName}}StringConv = TEXT("failed when converting from jstring for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}}StringConv);
	{{- else if .IsPrimitive }}
		{{$structName}}.{{$cppFieldName}} = env->Get{{jniToEnvNameType .}}Field(input, jFieldId_{{snake .Name}});
		static const TCHAR* errorMsg{{$cppFieldName}} = TEXT("failed when getting the jFieldId_{{snake .Name}} for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}});
	{{- else }}
		{{ jniToReturnType . }} {{snake .Name}}_value = env->GetObjectField(input, jFieldId_{{snake .Name}});
		static const TCHAR* errorMsg{{$cppFieldName}} = TEXT("failed when getting the jFieldId_{{snake .Name}} for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}});
		{{- if eq .KindType "interface"}}
		if ({{$structName}}.{{$cppFieldName }} == nullptr && {{snake .Name}}_value != nullptr)
		{
			{{$structName}}.{{$cppFieldName }} = {{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
		getCppInstance{{if not (eq .Schema.Import "" )}}{{ Camel .Schema.Import }}{{else}}{{$ModuleName}}{{end -}}{{Camel .Type }}();
		}
		{{- end }}
		{{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
		{{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
		fill{{Camel .Type }}(env, {{snake .Name}}_value, {{$structName}}.{{$cppFieldName }});
		env->DeleteLocalRef({{snake .Name}}_value);
	{{- end }}
	}
	else
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{snake .Name}} field in {{$structType}} not found"));
	}
{{- end }}
}

void {{$className }}::fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$structType}}>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$className}} cache not initialized for fill{{Camel .Name}}Array"));
		return;
	}
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of {{$structName}} array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of {{$structName}} array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fill{{Camel .Name }}(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

{{- $in_cppStructName := printf "in_%s" (snake .Name)}}
{{- $api_package_name := printf "%s_api" $jmoduleName }}
{{- $packageName := printf "%s/%s_api" $jmoduleName $jmoduleName}}
{{- $javaClassTypeName := Camel .Name}}

jobject {{$className }}::makeJava{{Camel .Name }}(JNIEnv* env, const {{$structType}}& {{$in_cppStructName}})
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$className}} cache not initialized for makeJava{{Camel .Name}}"));
		return nullptr;
	}

	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for {{$structName}}.");
	static const jmethodID ctor = getMethod(Cache->{{$cachedStruct}}, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(Cache->{{$cachedStruct}}, ctor);
	static const TCHAR* errorMsgObj = TEXT("failed when creating an instance of java object for {{$structName}}.");
	if (checkJniErrorOccured(errorMsgObj))
	{
		return nullptr;
	}

{{- range .Fields }}
	{{- $cppFieldName := .Name}}
	{{- $javaFieldName := camel .Name}}
	{{- $tmpObjName := printf "l_%s" $javaFieldName }}

	static const TCHAR* errorMsgFind{{$javaFieldName}} = TEXT("failed when trying to field {{$javaFieldName}} {{jniSignatureType . }} for {{$structType}}");
	static const jfieldID jFieldId_{{snake .Name}} = getFieldId(Cache->{{$cachedStruct}}, "{{$javaFieldName}}", "{{jniSignatureType . }}", errorMsgFind{{$javaFieldName}});

	if (jFieldId_{{snake .Name}} != nullptr)
	{
	{{- if .IsArray }}
	{{- if (eq .KindType "enum") }}
		{{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
		jobjectArray {{$tmpObjName}} = {{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
		makeJava{{Camel .Type }}Array(env, {{$in_cppStructName}}.{{$cppFieldName}});
	{{- else if (eq .KindType "string")}}
		TArray<FStringView> {{$cppFieldName}}StringViews;
		{{$cppFieldName}}StringViews.Reserve({{$in_cppStructName}}.{{$cppFieldName}}.Num());
		for (const FString& Str : {{$in_cppStructName}}.{{$cppFieldName}})
		{
			{{$cppFieldName}}StringViews.Add(FStringView(Str));
		}
		auto {{$tmpObjName}}Wrapper = FJavaHelper::ToJavaStringArray(env, {{$cppFieldName}}StringViews);
		static const TCHAR* errorMsg{{$cppFieldName}}Field = TEXT("failed when creating an converting to a jstring for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}}Field);
		jobjectArray {{$tmpObjName}} = static_cast<jobjectArray>(env->NewLocalRef(*{{$tmpObjName}}Wrapper));
	{{- else if (eq .KindType "bool")}}
		auto len{{snake .Name}} = {{$in_cppStructName}}.{{$cppFieldName}}.Num();
		TArray<jboolean> Temp;
		Temp.SetNumUninitialized(len{{snake .Name}});
		{{ jniToReturnType . }} {{$tmpObjName}} = env->New{{jniToEnvNameType .}}Array(len{{snake .Name}});
		static const TCHAR* errorMsg{{$cppFieldName}}Alloc = TEXT("failed when allocating jarray {{$structName}}.{{$cppFieldName}}");
		if (!checkJniErrorOccured(errorMsg{{$cppFieldName}}Alloc))
		{
			for (int i = 0; i < len{{snake .Name}}; i++)
			{
				Temp[i] = {{$in_cppStructName}}.{{$cppFieldName}}[i] ? JNI_TRUE : JNI_FALSE;
			}
			env->SetBooleanArrayRegion({{$tmpObjName}}, 0, len{{snake .Name}}, Temp.GetData());
			static const TCHAR* errorMsg{{$cppFieldName}} = TEXT("failed when seting jarray region for {{$structName}}.{{$cppFieldName}}");
			checkJniErrorOccured(errorMsg{{$cppFieldName}});
		}
	{{- else if .IsPrimitive }}
		auto len{{snake .Name}} = {{$in_cppStructName}}.{{$cppFieldName}}.Num();
		{{ jniToReturnType . }} {{$tmpObjName}} = env->New{{jniToEnvNameType .}}Array(len{{snake .Name}});
		static const TCHAR* errorMsg{{$cppFieldName}}Alloc = TEXT("failed when allocating jarray {{$structName}}.{{$cppFieldName}}");
		if (!checkJniErrorOccured(errorMsg{{$cppFieldName}}Alloc))
		{
			env->Set{{jniToEnvNameType .}}ArrayRegion({{$tmpObjName}}, 0, len{{snake .Name}}, {{ if (eq .KindType "int64") -}}
			reinterpret_cast<const jlong*>({{$in_cppStructName}}.{{$cppFieldName}}.GetData()));
			{{- else -}}
			{{$in_cppStructName}}.{{$cppFieldName}}.GetData());
			{{- end }}
			static const TCHAR* errorMsg{{$cppFieldName}} = TEXT("failed when seting jarray region for {{$structName}}.{{$cppFieldName}}");
			checkJniErrorOccured(errorMsg{{$cppFieldName}});
		};
	{{- else }}
		{{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
		jobjectArray {{$tmpObjName}} = {{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
		makeJava{{Camel .Type }}Array(env, {{$in_cppStructName}}.{{$cppFieldName}});
	{{- end }}
		env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, {{$tmpObjName}});
		static const TCHAR* errorMsg{{$cppFieldName}}Set = TEXT("failed when seting field for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}}Set);
		env->DeleteLocalRef({{$tmpObjName}});
	{{- else if eq .KindType "enum"}}
		{{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
		jobject {{$tmpObjName}} = {{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
		makeJava{{Camel .Type }}(env, {{$in_cppStructName}}.{{$cppFieldName}});
		env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, {{$tmpObjName}});
		static const TCHAR* errorMsg{{$cppFieldName}}Set = TEXT("failed when seting field for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}}Set);
		env->DeleteLocalRef({{$tmpObjName}});
	{{- else if eq .KindType "string"}}
		auto {{$tmpObjName}}Wrapped = FJavaHelper::ToJavaString(env, {{$in_cppStructName}}.{{$cppFieldName}});
		static const TCHAR* errorMsg{{$cppFieldName}}Str = TEXT("failed when converting to jstring {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}}Str);
		env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, *{{$tmpObjName}}Wrapped);
		static const TCHAR* errorMsg{{$cppFieldName}}Set = TEXT("failed when seting field for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}}Set);
	{{- else if .IsPrimitive }}
		env->Set{{jniToEnvNameType .}}Field(javaObjInstance, jFieldId_{{snake .Name}}, {{$in_cppStructName}}.{{$cppFieldName}});
		static const TCHAR* errorMsg{{$cppFieldName}}Set = TEXT("failed when seting field for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}}Set);
	{{- else }}
		{{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
		jobject {{$tmpObjName}} = {{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
		makeJava{{Camel .Type }}(env, {{$in_cppStructName}}.{{$cppFieldName }});
		env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, {{$tmpObjName}});
		static const TCHAR* errorMsg{{$cppFieldName}}Set = TEXT("failed when seting field for {{$structName}}.{{$cppFieldName}}");
		checkJniErrorOccured(errorMsg{{$cppFieldName}}Set);
		env->DeleteLocalRef({{$tmpObjName}});
	{{- end }}
	}
	else
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{snake .Name}} field in {{$structType}} not found"));
	}
{{- end }}
	return javaObjInstance;
}

jobjectArray {{$className }}::makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$structType}}>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->{{$cachedStruct}})
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$structType}} not found"));
		return nullptr;
	}

	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->{{$cachedStruct}}, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when allocating jarray of {{$structName}}.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJava{{Camel .Name }}(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when setting an element for {{$structName}} jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}
{{- end }}

{{- range .Module.Enums }}
{{- $moduleEnumName := printf "%s%s" $ModuleName .Name }}
{{- $cpp_class := printf "E%s%s" $ModuleName .Name }}

{{- $in_cppStructName := printf "out_%s" (snake .Name)}}
{{- $packageName := printf "%s/%s_api" $jmoduleName $jmoduleName}}
{{- $javaClassTypeName := Camel .Name}}
{{- $cachedEnum := printf "j%s" (Camel .Name) }}

void {{$className }}::fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$cpp_class}}>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$className}} cache not initialized for fill{{Camel .Name}}Array"));
		return;
	}
	out_array.Empty();
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get length of {{$javaClassTypeName}} array.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of {{$javaClassTypeName}} array.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			out_array.Add(get{{Camel .Name }}Value(env, element));
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

{{$cpp_class}} {{$className }}::get{{Camel .Name }}Value(JNIEnv* env, jobject input)
{
	{{- if len .Members }}
	{{- $member:= (index .Members 0) }}
	{{$cpp_class}} cppEnumValue = {{$cpp_class}}::{{ abbreviate $moduleEnumName }}_{{Camel $member.Name}};
	{{- else}}
	{{$cpp_class}} cppEnumValue;
	{{- end}}
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$className}} cache not initialized for get{{Camel .Name}}Value"));
		return cppEnumValue;
	}
	static const TCHAR* errorMsgGetMethod = TEXT("failed when trying to get java method getVaue for object for {{$javaClassTypeName}}.");
	static const jmethodID getValueMethod = getMethod(Cache->{{$cachedEnum}}, "getValue", "()I", errorMsgGetMethod);
	if (getValueMethod != nullptr)
	{
		int int_value = env->CallIntMethod(input, getValueMethod);
		static const TCHAR* errorMsg = TEXT("failed when trying to call getValue method for {{$javaClassTypeName}}.");
		if (!checkJniErrorOccured(errorMsg))
		{
			{{- $toEnumFuncName := printf "U%sLibrary::to%s%s" $ModuleName $ModuleName .Name }}
			{{$toEnumFuncName}}(cppEnumValue, int_value);
		}
	}
	else
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("Enum {{Camel .Name }}::getValue not found"));
	}
	return cppEnumValue;
}

jobjectArray {{$className }}::makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$cpp_class}}>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->{{$cachedEnum}})
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("Enum {{Camel .Name }} not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->{{$cachedEnum}}, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate {{$javaClassTypeName}} jarray.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJava{{Camel .Name }}(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of {{$javaClassTypeName}} array.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

jobject {{$className }}::makeJava{{Camel .Name }}(JNIEnv* env, {{$cpp_class}} value)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$className}} cache not initialized for makeJava{{Camel .Name}}"));
		return nullptr;
	}
	static const TCHAR* errorMsgFromValueMethod = TEXT("failed when trying to get java method fromValue for object for {{$javaClassTypeName}}.");
	static const jmethodID fromValueMethod = getStaticMethod(Cache->{{$cachedEnum}}, "fromValue", "(I)L{{$packageName}}/{{$javaClassTypeName}};", errorMsgFromValueMethod);
	if (fromValueMethod == nullptr)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("%s"), errorMsgFromValueMethod);
		return nullptr;
	}
	int int_value = (int)value;
	jobject javaObj = env->CallStaticObjectMethod(Cache->{{$cachedEnum}}, fromValueMethod, int_value);
	static const TCHAR* errorMsg = TEXT("failed when trying to call fromValue method for {{$javaClassTypeName}}.");
	checkJniErrorOccured(errorMsg);
	return javaObj;
}
{{- end }}

{{- range .Module.Interfaces }}

{{- $ifType := printf "TScriptInterface<I%s%sInterface>" $ModuleName (Camel .Name) }}
{{- $ifName := printf "out_%s" (snake .Name)}}
{{- $cachedClass:= printf "j%s" (Camel .Name) }}

void {{$className }}::fill{{Camel .Name }}(JNIEnv* env, jobject input, {{$ifType}} {{$ifName}})
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$className}} cache not initialized for fill{{Camel .Name}}"));
		return;
	}
	if (!input || !{{$ifName}})
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void {{$className }}::fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$ifType}}>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$className}} cache not initialized for fill{{Camel .Name}}Array"));
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

{{- $in_cppIfName := printf "out_%s" (snake .Name)}}

jobject {{$className }}::makeJava{{Camel .Name }}(JNIEnv* env, const {{$ifType}} {{$in_cppIfName}})
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$className}} cache not initialized for makeJava{{Camel .Name}}"));
		return nullptr;
	}
	if (!{{$in_cppIfName}})
	{
		return nullptr;
	}

	jobject javaObjInstance = nullptr;
	// currently not supported, stub function generated for possible custom implementation
	return javaObjInstance;
}

jobjectArray {{$className }}::makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$ifType}}>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->{{$cachedClass}})
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("I{{Camel .Name}} not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->{{$cachedClass}}, nullptr);
	static const TCHAR* errorMsg = TEXT("failed when trying to allocate jarray for {{$ifName}}.");
	if (checkJniErrorOccured(errorMsg))
	{
		return nullptr;
	}
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

{{$ifType}} {{$className }}::getCppInstance{{$ModuleName}}{{Camel .Name }}()
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$className}} cache not initialized for getCppInstance{{$ModuleName}}{{Camel .Name}}"));
		return nullptr;
	}
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
{{- $cachedClass:= printf "j%s" (Camel .Name) }}

void {{$className }}::fill{{Camel .Name }}(JNIEnv* env, jobject input, {{$exCppType}}& {{$exName}})
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->{{$cachedClass}})
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$fullJavaClassType}} not found"));
		return;
	}

	// do the serialization field by field: e.g. for int type field
	// static const jfieldID jFieldId_firstField = env->GetFieldID(cls, "firstField", "I");
	// {{$exName}}.FirstField = env->GetIntField(input, jFieldId_firstField);
}

void {{$className }}::fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$exCppType}}>& out_array)
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$className}} cache not initialized for fill{{Camel .Name}}Array"));
		return;
	}
	jsize len = env->GetArrayLength(input);
	static const TCHAR* errorMsgLen = TEXT("failed when trying to get len of {{$extJava.Name}} jarray.");
	if (checkJniErrorOccured(errorMsgLen))
	{
		return;
	}
	out_array.Reserve(len);
	out_array.AddDefaulted(len);
	for (jsize i = 0; i < len; ++i)
	{
		jobject element = env->GetObjectArrayElement(input, i);
		static const TCHAR* errorMsg = TEXT("failed when trying to get element of {{$extJava.Name}} jarray.");
		auto failed = checkJniErrorOccured(errorMsg);
		if (!failed)
		{
			fill{{Camel .Name }}(env, element, out_array[i]);
		}
		env->DeleteLocalRef(element);
		if (failed)
		{
			return;
		}
	}
}

{{- $in_cppExName := printf "out_%s" (snake .Name)}}

jobject {{$className }}::makeJava{{Camel .Name }}(JNIEnv* env, const {{$exCppType}}& {{$in_cppExName}})
{
	auto Cache = ensureInitialized();
	if (!Cache)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$className}} cache not initialized for makeJava{{Camel .Name}}"));
		return nullptr;
	}
	static const TCHAR* errorMsgCtor = TEXT("failed when trying to get java ctor for object for {{$fullJavaClassType}}.");
	// Make sure either that the extern class has default ctor or provide proper signature and arguments.
	static const jmethodID ctor = getMethod(Cache->{{$cachedClass}}, "<init>", "()V", errorMsgCtor);
	if (ctor == nullptr)
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("%s"), errorMsgCtor);
		return nullptr;
	}
	jobject javaObjInstance = env->NewObject(Cache->{{$cachedClass}}, ctor);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate {{$extJava.Name}}.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	// do the serialization field by field: e.g. for int type field
	// jfieldID jFieldId_firstField = getField({{$cachedClass}}, "jFieldId_firstField", "I", "Error Message in case java exception");
	// env->SetIntField(javaObjInstance, jFieldId_firstField, {{$in_cppExName}}.FirstField);
	return javaObjInstance;
}

jobjectArray {{$className }}::makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$exCppType}}>& cppArray)
{
	auto Cache = ensureInitialized();
	if (!Cache || !Cache->{{$cachedClass}})
	{
		UE_LOG(Log{{$className}}_JNI, Warning, TEXT("{{$fullJavaClassType}} not found"));
		return nullptr;
	}
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, Cache->{{$cachedClass}}, nullptr);
	static const TCHAR* errorMsgAlloc = TEXT("failed when trying to allocate {{$extJava.Name}} jarray.");
	if (checkJniErrorOccured(errorMsgAlloc))
	{
		return nullptr;
	}

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJava{{Camel .Name }}(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		static const TCHAR* errorMsg = TEXT("failed when trying to set element of {{$extJava.Name}} array.");
		auto failed = checkJniErrorOccured(errorMsg);
		env->DeleteLocalRef(element);
		if (failed)
		{
			return nullptr;
		}
	}
	return javaArray;
}

{{- end }}

bool {{$className}}::checkJniErrorOccured(const TCHAR* Msg)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	if (env->ExceptionCheck())
	{
		env->ExceptionDescribe(); // logs in java
		env->ExceptionClear();
		UE_LOG(Log{{$className}}_JNI, Error, TEXT("%s"), Msg);
		return true;
	}
	return false;
}

void {{$className}}::cleanJavaReferences()
{
	FScopeLock Lock(&CacheLock);
	CacheData.Reset();
}

TSharedPtr<F{{$className}}CacheData, ESPMode::ThreadSafe> {{$className }}::ensureInitialized()
{
	{
		FScopeLock Lock(&CacheLock);
		if (CacheData)
		{
			return CacheData;
		}
	}

	auto NewData = MakeShared<F{{$className}}CacheData, ESPMode::ThreadSafe>();
	{{- $packageName := printf "%s/%s_api" $jmoduleName $jmoduleName }}
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
{{- range .Module.Structs }}
	{{- $javaClassTypeName := Camel .Name}}
	NewData->j{{Camel .Name}} = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
	static const TCHAR* errorMsg{{Camel .Name}} = TEXT("failed to get {{$packageName}}/{{$javaClassTypeName}}");
	checkJniErrorOccured(errorMsg{{Camel .Name}});
{{- end }}

{{- range .Module.Enums }}
{{- $javaClassTypeName := Camel .Name}}
	NewData->j{{Camel .Name}} = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
	static const TCHAR* errorMsg{{Camel .Name}} = TEXT("failed to get {{$packageName}}/{{$javaClassTypeName}}");
	checkJniErrorOccured(errorMsg{{Camel .Name}});
{{- end }}

{{- range .Module.Interfaces }}
{{- $fullJavaClassType := printf "%s/%s_api/I%s" $jmoduleName $jmoduleName (Camel .Name) }}
	NewData->j{{Camel .Name}} = FAndroidApplication::FindJavaClassGlobalRef("{{$fullJavaClassType}}");
	static const TCHAR* errorMsg{{Camel .Name}} = TEXT("failed to get {{$fullJavaClassType}}");
	checkJniErrorOccured(errorMsg{{Camel .Name}});
{{- end }}

{{- range .Module.Externs }}
{{- $extJava := (javaExtern .) }}
{{- $fullJavaClassType := $extJava.Name }}
{{- $prefix := (replace ($extJava.Package) "." "/" ) }}
{{- if ne $prefix "" }}
{{- $fullJavaClassType = printf "%s/%s" $prefix $fullJavaClassType }}
{{- end }}
	NewData->j{{Camel .Name}} = FAndroidApplication::FindJavaClassGlobalRef("{{$fullJavaClassType}}");
	static const TCHAR* errorMsg{{Camel .Name}} = TEXT("failed to get {{$fullJavaClassType}}");
	checkJniErrorOccured(errorMsg{{Camel .Name}});
{{- end }}

	{
		FScopeLock Lock(&CacheLock);
		if (!CacheData)
		{
			CacheData = NewData;
		}
		return CacheData;
	}
}

jmethodID {{$className }}::getMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jmethodID {{$className }}::getStaticMethod(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jmethodID method = env->GetStaticMethodID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return method;
}

jfieldID {{$className }}::getFieldId(jclass cls, const char* name, const char* signature, const TCHAR* errorMsgInfo)
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jfieldID field = env->GetFieldID(cls, name, signature);
	checkJniErrorOccured(errorMsgInfo);
	return field;
}

#endif
