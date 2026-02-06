{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $Category := printf "ApiGear%s" $ModuleName -}}
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

{{- $class := printf "F%sJniModule" $ModuleName}}

#include "{{$ModuleName}}/{{$ModuleName}}Jni.h"
#include "{{$ModuleName}}/Generated/{{$ModuleName}}Factory.h"
#include "{{$ModuleName}}/Generated/Jni/{{$ModuleName}}DataJavaConverter.h"
#include "Engine/Engine.h"
#include "{{$ModuleName}}Settings.h"
#include "Modules/ModuleManager.h"

#include "Generated/Detail/{{$ModuleName}}MethodHelper.h"

#define LOCTEXT_NAMESPACE "{{$ModuleName}}Jni"

DEFINE_LOG_CATEGORY(Log{{Camel .Module.Name}}MethodHelper_JNI);

void {{$class}}::StartupModule()
{
}

void {{$class}}::ShutdownModule()
{
// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
// we call this function before unloading the module.
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	{{- $converterName := printf "%sDataJavaConverter" $ModuleName}}
	{{$converterName}}::cleanJavaReferences();
#endif
}

IMPLEMENT_MODULE({{$class}}, {{$ModuleName}}Jni)

#undef LOCTEXT_NAMESPACE
