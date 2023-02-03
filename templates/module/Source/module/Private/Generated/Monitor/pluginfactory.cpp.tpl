{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" $ModuleName }}
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

#include "{{$ModuleName}}Factory.h"
{{- range .Module.Interfaces }}
{{- $iclass := printf "%s%s" $ModuleName .Name}}
{{- if $.Features.stubs }}
#include "Implementation/{{$iclass}}.h"
{{- end }}
{{- if $.Features.olink }}
#include "Generated/OLink/{{$iclass}}OLinkClient.h"
{{- end }}
{{- end }}
#include "{{$ModuleName}}Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(Log{{$mclass}});

{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName .Name }}
{{- $iclass := printf "I%sInterface" $class }}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Name) }}
{{- if $.Features.olink }}

TScriptInterface<I{{$class}}Interface> create{{$class}}OLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(Log{{$mclass}}, Log, TEXT("create{{$iclass}}: Using OLink service backend"));
	{{ printf "U%sOLinkClient" $DisplayName}}* Instance = GameInstance->GetSubsystem<{{ printf "U%sOLinkClient" $DisplayName}}>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency({{ printf "U%sOLinkClient" $DisplayName}}::StaticClass());
		Instance = GameInstance->GetSubsystem<{{ printf "U%sOLinkClient" $DisplayName}}>(GameInstance);
	}
	return Instance;
}
{{- end }}

TScriptInterface<I{{$class}}Interface> {{$mclass}}::create{{$iclass}}(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	U{{$ModuleName}}Settings* settings = GetMutableDefault<U{{$ModuleName}}Settings>();

	switch (settings->ServiceConnection)
	{
{{- if $.Features.olink }}{{ nl }}	case E{{$ModuleName}}Connection::CONNECTION_OLINK:
		return create{{$class}}OLink(GameInstance, Collection);{{ end }}
{{- if $.Features.stubs }}{{ nl }}	case E{{$ModuleName}}Connection::CONNECTION_LOCAL:
		UE_LOG(Log{{$mclass}}, Log, TEXT("create{{$iclass}}: Using local service backend"));{{ end }}
	default:
{{- if $.Features.stubs }}{{ nl }}		UE_LOG(Log{{$mclass}}, Log, TEXT("create{{$iclass}}: Defaulting to local service backend"));
		return NewObject<{{ printf "U%s" $DisplayName}}>();
{{- else if $.Features.olink }}{{ nl }}		return create{{$class}}OLink(GameInstance, Collection);
{{- end }}
	}
}
{{- end }}
