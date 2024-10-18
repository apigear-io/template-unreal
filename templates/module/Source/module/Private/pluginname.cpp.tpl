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

{{- $class := printf "F%sModule" $ModuleName}}

#include "{{$ModuleName}}.h"
#include "Generated/{{$ModuleName}}Factory.h"
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
{{- if $.Features.olink }}
#include "Generated/OLink/{{$class}}OLinkClient.h"
{{- end }}
{{- end }}
#include "Engine/Engine.h"
#include "{{$ModuleName}}Settings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "{{$ModuleName}}"

void {{$class}}::StartupModule()
{
{{- $classFactory := printf "F%sModuleFactory" $ModuleName}}
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
{{- if $.Features.olink }}
	{{$classFactory}}::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<I{{$class}}Interface>
		{
		return Cast<{{ printf "U%sOLinkClient" $class}}>(Collection.InitializeDependency({{ printf "U%sOLinkClient" $class}}::StaticClass()));
	});
{{- end }}
{{- end }}
}

void {{$class}}::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE({{$class}}, {{$ModuleName}})

#undef LOCTEXT_NAMESPACE
