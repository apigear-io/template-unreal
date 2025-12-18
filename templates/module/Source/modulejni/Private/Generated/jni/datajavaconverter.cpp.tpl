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

{{- range .Module.Structs }}
{{- $cachedStruct := printf "j%s" (Camel .Name) }}
{{- $structType := printf "F%s%s" $ModuleName .Name }}
{{- $structName := printf "out_%s" (snake .Name)}}

jclass {{$className }}::{{$cachedStruct}} = nullptr;
void {{$className }}::fill{{Camel .Name }}(JNIEnv* env, jobject input, {{$structType}}& {{$structName}})
{
	ensureInitialized();
	jclass cls = {{$cachedStruct}};

{{- range .Fields }}
	{{- $cppFieldName := .Name}}
	{{- $javaFieldName := camel .Name}}

	jfieldID jFieldId_{{snake .Name}} = env->GetFieldID(cls, "{{$javaFieldName}}", "{{jniSignatureType . }}");
	
{{- if .IsArray }}
	{{ jniToReturnType . }} {{snake .Name}}_value = ({{jniToReturnType . }})env->GetObjectField(input, jFieldId_{{snake .Name}});		
{{- if (eq .KindType "enum") }}
	{{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
	{{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
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
	env->Get{{jniToEnvNameType .}}ArrayRegion({{snake .Name}}_value, 0, len{{snake .Name}}, {{ if (eq .KindType "int64") -}}
		reinterpret_cast<jlong*>({{$structName}}.{{$cppFieldName}}.GetData()));
		{{- else -}}
		{{$structName}}.{{$cppFieldName}}.GetData());
		{{- end }}
{{- else }}
	{{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
	{{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
	fill{{Camel .Type }}Array(env, {{snake .Name}}_value, {{$structName}}.{{$cppFieldName}});
{{- end }}
	env->DeleteLocalRef({{snake .Name}}_value);
{{- else if eq .KindType "enum"}}
	{{ jniToReturnType . }} {{snake .Name}}_value = env->GetObjectField(input, jFieldId_{{snake .Name}});
	{{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
	{{$structName}}.{{$cppFieldName}} = {{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
	get{{Camel .Type }}Value(env, {{snake .Name}}_value);
{{- else if eq .KindType "string"}}
	jstring {{snake .Name}}_value = (jstring)env->GetObjectField(input, jFieldId_{{snake .Name}});
	{{$structName}}.{{$cppFieldName}} = FJavaHelper::FStringFromLocalRef(env, {{snake .Name}}_value);
{{- else if .IsPrimitive }}
	{{$structName}}.{{$cppFieldName}} = env->Get{{jniToEnvNameType .}}Field(input, jFieldId_{{snake .Name}});
{{- else }}
	{{ jniToReturnType . }} {{snake .Name}}_value = env->GetObjectField(input, jFieldId_{{snake .Name}});
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
{{- end }}
}

void {{$className }}::fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$structType}}>& out_array)
{
	ensureInitialized();
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
{{- $api_package_name := printf "%s_api" $jmoduleName }}
{{- $packageName := printf "%s/%s_api" $jmoduleName $jmoduleName}}
{{- $javaClassTypeName := Camel .Name}}

jobject {{$className }}::makeJava{{Camel .Name }}(JNIEnv* env, const {{$structType}}& {{$in_cppStructName}})
{
	ensureInitialized();
	jclass javaClass = {{$cachedStruct}};
	jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
	jobject javaObjInstance = env->NewObject(javaClass, ctor);

{{- range .Fields }}
	{{- $cppFieldName := .Name}}
	{{- $javaFieldName := camel .Name}}
	{{- $tmpObjName := printf "l_%s" $javaFieldName }}

	jfieldID jFieldId_{{snake .Name}} = env->GetFieldID(javaClass, "{{$javaFieldName}}", "{{jniSignatureType . }}");

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
	jobjectArray {{$tmpObjName}} = static_cast<jobjectArray>(env->NewLocalRef(*{{$tmpObjName}}Wrapper));
{{- else if (eq .KindType "bool")}}
	auto len{{snake .Name}} = {{$in_cppStructName}}.{{$cppFieldName}}.Num();
	TArray<jboolean> Temp;
	Temp.SetNumUninitialized(len{{snake .Name}});
	{{ jniToReturnType . }} {{$tmpObjName}} = env->New{{jniToEnvNameType .}}Array(len{{snake .Name}});
	for (int i = 0; i < len{{snake .Name}}; i++)
	{
		Temp[i] = {{$in_cppStructName}}.{{$cppFieldName}}[i] ? JNI_TRUE : JNI_FALSE;
	}
	env->SetBooleanArrayRegion({{$tmpObjName}}, 0, len{{snake .Name}}, Temp.GetData());
{{- else if .IsPrimitive }}
	auto len{{snake .Name}} = {{$in_cppStructName}}.{{$cppFieldName}}.Num();
	{{ jniToReturnType . }} {{$tmpObjName}} = env->New{{jniToEnvNameType .}}Array(len{{snake .Name}});
	if ({{$tmpObjName}} != NULL)
	{
		env->Set{{jniToEnvNameType .}}ArrayRegion({{$tmpObjName}}, 0, len{{snake .Name}}, {{ if (eq .KindType "int64") -}}
		reinterpret_cast<const jlong*>({{$in_cppStructName}}.{{$cppFieldName}}.GetData()));
		{{- else -}}
		{{$in_cppStructName}}.{{$cppFieldName}}.GetData());
		{{- end }}
	};
{{- else }}
	{{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
	jobjectArray {{$tmpObjName}} = {{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
	makeJava{{Camel .Type }}Array(env, {{$in_cppStructName}}.{{$cppFieldName}});
{{- end }}
	env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, {{$tmpObjName}});
	env->DeleteLocalRef({{$tmpObjName}});
{{- else if eq .KindType "enum"}}
	{{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
	jobject {{$tmpObjName}} = {{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
	makeJava{{Camel .Type }}(env, {{$in_cppStructName}}.{{$cppFieldName}});
	env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, {{$tmpObjName}});
	env->DeleteLocalRef({{$tmpObjName}});
{{- else if eq .KindType "string"}}
	auto {{$tmpObjName}}Wrapper = FJavaHelper::ToJavaString(env, {{$in_cppStructName}}.{{$cppFieldName}});
	jstring {{$tmpObjName}} = static_cast<jstring>(env->NewLocalRef(*{{$tmpObjName}}Wrapper));
	env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, {{$tmpObjName}});
	// in UE 5.6 no need for new local ref
{{- else if .IsPrimitive }}
	env->Set{{jniToEnvNameType .}}Field(javaObjInstance, jFieldId_{{snake .Name}}, {{$in_cppStructName}}.{{$cppFieldName}});
{{- else }}
	{{- $otherModuleClassName := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
	jobject {{$tmpObjName}} = {{if not (eq $otherModuleClassName "DataJavaConverter" )}}{{$otherModuleClassName}}::{{end -}}
	makeJava{{Camel .Type }}(env, {{$in_cppStructName}}.{{$cppFieldName }});
	env->SetObjectField(javaObjInstance, jFieldId_{{snake .Name}}, {{$tmpObjName}});
	env->DeleteLocalRef({{$tmpObjName}});
{{- end }}

{{- end }}
	return javaObjInstance;
}

jobjectArray {{$className }}::makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$structType}}>& cppArray)
{
	ensureInitialized();
	jclass javaStruct = {{$cachedStruct}};
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaStruct, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
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
{{- $packageName := printf "%s/%s_api" $jmoduleName $jmoduleName}}
{{- $javaClassTypeName := Camel .Name}}
{{- $cachedEnum := printf "j%s" (Camel .Name) }}
jclass {{$className }}::{{$cachedEnum}} = nullptr;

void {{$className }}::fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$cpp_class}}>& out_array)
{
	ensureInitialized();
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
	ensureInitialized();
	jclass javaStruct = {{$cachedEnum}};
	jmethodID getValueMethod = env->GetMethodID(javaStruct, "getValue", "()I");
	int int_value = env->CallIntMethod(input, getValueMethod);
	{{- $toEnumFuncName := printf "U%sLibrary::to%s%s" $ModuleName $ModuleName .Name }}
	{{$toEnumFuncName}}(cppEnumValue, int_value);
	return cppEnumValue;
}

jobjectArray {{$className }}::makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$cpp_class}}>& cppArray)
{
	ensureInitialized();
	jclass javaStruct = {{$cachedEnum}};
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaStruct, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJava{{Camel .Name }}(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
	}
	return javaArray;
}

jobject {{$className }}::makeJava{{Camel .Name }}(JNIEnv* env, {{$cpp_class}} value)
{
	ensureInitialized();
	jclass javaStruct = {{$cachedEnum}};
	jmethodID fromValueMethod = env->GetStaticMethodID(javaStruct, "fromValue", "(I)L{{$packageName}}/{{$javaClassTypeName}};");
	if (!fromValueMethod)
		return nullptr;
	int int_value = (uint8)value;
	jobject javaObj = env->CallStaticObjectMethod(javaStruct, fromValueMethod, int_value);
	return javaObj;
}
{{- end }}

{{- range .Module.Interfaces }}

{{- $ifType := printf "TScriptInterface<I%s%sInterface>" $ModuleName (Camel .Name) }}
{{- $ifName := printf "out_%s" (snake .Name)}}
{{- $cachedClass:= printf "j%s" (Camel .Name) }}
{{- $fullJavaClassType := printf "%s/%s_api/I%s" $jmoduleName $jmoduleName (Camel .Name) }}
jclass {{$className }}::{{$cachedClass}} = nullptr;

void {{$className }}::fill{{Camel .Name }}(JNIEnv* env, jobject input, {{$ifType}} {{$ifName}})
{
	ensureInitialized();
	if (!input || !{{$ifName}})
	{
		return;
	}
	// currently not supported, stub function generated for possible custom implementation
}

void {{$className }}::fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$ifType}}>& out_array)
{
	ensureInitialized();
	// currently not supported, stub function generated for possible custom implementation
}

{{- $in_cppIfName := printf "out_%s" (snake .Name)}}

jobject {{$className }}::makeJava{{Camel .Name }}(JNIEnv* env, const {{$ifType}} {{$in_cppIfName}})
{
	ensureInitialized();
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
	ensureInitialized();
	jclass javaClass = {{$cachedClass}};
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaClass, nullptr);
	// Currently not supported, stub function generated for possible custom implementation.
	return javaArray;
}

{{$ifType}} {{$className }}::getCppInstance{{$ModuleName}}{{Camel .Name }}()
{
	ensureInitialized();
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

jclass {{$className }}::{{$cachedClass}} = nullptr;
void {{$className }}::fill{{Camel .Name }}(JNIEnv* env, jobject input, {{$exCppType}}& {{$exName}})
{
	ensureInitialized();
	jclass cls = {{$cachedClass}};

	// do the serialization field by field: e.g. for int type field
	// jfieldID jFieldId_firstField = env->GetFieldID(cls, "firstField", "I");
	// {{$exName}}.FirstField = env->GetIntField(input, jFieldId_firstField);
}

void {{$className }}::fill{{Camel .Name }}Array(JNIEnv* env, jobjectArray input, TArray<{{$exCppType}}>& out_array)
{
	ensureInitialized();
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
	ensureInitialized();
	jclass javaClass = {{$cachedClass}};
	jmethodID ctor = env->GetMethodID(javaClass, "<init>", "()V");
	jobject javaObjInstance = env->NewObject(javaClass, ctor);

	// do the serialization field by field: e.g. for int type field
	// jfieldID jFieldId_firstField = env->GetFieldID(javaClass, "jFieldId_firstField", "I");
	// env->SetIntField(javaObjInstance, jFieldId_firstField, {{$in_cppExName}}.FirstField);
	return javaObjInstance;
}

jobjectArray {{$className }}::makeJava{{Camel .Name }}Array(JNIEnv* env, const TArray<{{$exCppType}}>& cppArray)
{
	ensureInitialized();
	jclass javaClass = {{$cachedClass}};
	auto arraySize = cppArray.Num();
	jobjectArray javaArray = env->NewObjectArray(arraySize, javaStruct, nullptr);

	for (jsize i = 0; i < arraySize; ++i)
	{
		jobject element = makeJava{{Camel .Name }}(env, cppArray[i]);
		env->SetObjectArrayElement(javaArray, i, element);
		env->DeleteLocalRef(element);
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
	FScopeLock Lock(&initMutex);
	m_isInitialized = false;
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
{{- range .Module.Structs }}
	env->DeleteGlobalRef(j{{Camel .Name}});
{{- end }}
{{- range .Module.Enums }}
	env->DeleteGlobalRef(j{{Camel .Name}});
{{- end }}
{{- range .Module.Interfaces }}
	env->DeleteGlobalRef(j{{Camel .Name}});
{{- end }}
{{- range .Module.Externs }}
	env->DeleteGlobalRef(j{{Camel .Name}});
{{- end }}
}

FCriticalSection {{$className }}::initMutex;

bool {{$className }}::m_isInitialized = false;

void {{$className }}::ensureInitialized()
{
	if (m_isInitialized)
	{
		return;
	}
	FScopeLock Lock(&initMutex);
	if (m_isInitialized)
	{
		return;
	}

	{{- $packageName := printf "%s/%s_api" $jmoduleName $jmoduleName }}
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
{{- range .Module.Structs }}
	{{- $javaClassTypeName := Camel .Name}}
	j{{Camel .Name}} = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
	static const TCHAR* errorMsg{{Camel .Name}}= TEXT("failed to get {{$packageName}}/{{$javaClassTypeName}}");
	checkJniErrorOccured(errorMsg{{Camel .Name}});
{{- end }}

{{- range .Module.Enums }}
{{- $javaClassTypeName := Camel .Name}}
	j{{Camel .Name}} = FAndroidApplication::FindJavaClassGlobalRef("{{$packageName}}/{{$javaClassTypeName}}");
	static const TCHAR* errorMsg{{Camel .Name}}= TEXT("failed to get {{$packageName}}/{{$javaClassTypeName}}");
	checkJniErrorOccured(errorMsg{{Camel .Name}});
{{- end }}

{{- range .Module.Interfaces }}
{{- $fullJavaClassType := printf "%s/%s_api/I%s" $jmoduleName $jmoduleName (Camel .Name) }}
	j{{Camel .Name}} = FAndroidApplication::FindJavaClassGlobalRef("{{$fullJavaClassType}}");
	static const TCHAR* errorMsg{{Camel .Name}}= TEXT("failed to get {{$fullJavaClassType}}");
	checkJniErrorOccured(errorMsg{{Camel .Name}});
{{- end }}

{{- range .Module.Externs }}
{{- $extJava := (javaExtern .) }}
{{- $fullJavaClassType := $extJava.Name }}
{{- $prefix := (replace ($extJava.Package) "." "/" ) }}
{{- if ne $prefix "" }}
{{- $fullJavaClassType = printf "%s/%s" $prefix $fullJavaClassType }}
{{- end }}
	j{{Camel .Name}} = FAndroidApplication::FindJavaClassGlobalRef("{{$fullJavaClassType}}");
	static const TCHAR* errorMsg{{Camel .Name}}= TEXT("failed to get {{$fullJavaClassType}}");
	checkJniErrorOccured(errorMsg{{Camel .Name}});
{{- end }}
	m_isInitialized = true;
}

}
}

#endif
