{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" (Camel .Module.Name) }}
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
{{- $mclass := printf "F%sModuleFactory" $ModuleName}}

#include "Generated/{{$ModuleName}}Factory.h"
#include "{{$ModuleName}}Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"
{{- range $i, $e := .Module.Interfaces -}}
{{- if eq $i 0 }}{{nl}}{{ end }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
TMap<FString, {{$mclass}}::F{{$class}}FactoryFunction> {{$mclass}}::{{$class}}Factories{};
{{- end }}

// General Log
DEFINE_LOG_CATEGORY(Log{{$mclass}});

{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
{{- $iclass := printf "I%sInterface" $class }}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Name) }}

bool {{$mclass}}::RegisterFactory(FString TypeIdentifier, F{{$class}}FactoryFunction FactoryFunction)
{
	if ({{$class}}Factories.Contains(TypeIdentifier))
	{
		UE_LOG(Log{{$mclass}}, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	{{$class}}Factories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<I{{$class}}Interface> {{$mclass}}::Get{{$class}}Implementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if ({{$class}}Factories.Contains(UniqueImplementationIdentifier))
	{
		return {{$class}}Factories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}
{{- end }}
