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
#include "ApiGearSettings.h"
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

namespace
{
bool Is{{$ModuleName}}LogEnabled()
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	return settings->Tracer_EnableDebugLog;
}
} // namespace

{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName .Name }}
{{- $iclass := printf "I%sInterface" $class }}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Name) }}

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
{{- if $.Features.olink }}
TScriptInterface<I{{$class}}Interface> create{{$class}}OLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	if (Is{{$ModuleName}}LogEnabled())
	{
		UE_LOG(Log{{$mclass}}, Log, TEXT("create{{$iclass}}: Using OLink service backend"));
	}

	{{ printf "U%sOLinkClient" $DisplayName}}* Instance = GameInstance->GetSubsystem<{{ printf "U%sOLinkClient" $DisplayName}}>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency({{ printf "U%sOLinkClient" $DisplayName}}::StaticClass());
		Instance = GameInstance->GetSubsystem<{{ printf "U%sOLinkClient" $DisplayName}}>(GameInstance);
	}

	return Instance;
}
{{- end }}
{{- if $.Features.stubs }}

TScriptInterface<I{{$class}}Interface> create{{$class}}(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	if (Is{{$ModuleName}}LogEnabled())
	{
		UE_LOG(Log{{$mclass}}, Log, TEXT("create{{$iclass}}: Using local service backend"));
	}

	{{ printf "U%s" $DisplayName}}* Instance = GameInstance->GetSubsystem<{{ printf "U%s" $DisplayName}}>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency({{ printf "U%s" $DisplayName}}::StaticClass());
		Instance = GameInstance->GetSubsystem<{{ printf "U%s" $DisplayName}}>(GameInstance);
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
		return create{{$class}}(GameInstance, Collection);{{ end }}
	default:
{{- if $.Features.stubs }}
		return create{{$class}}(GameInstance, Collection);
{{- else if $.Features.olink }}
		return create{{$class}}OLink(GameInstance, Collection);
{{- end }}
	}
}

#else
{{- if $.Features.olink }}

TScriptInterface<I{{$class}}Interface> create{{$class}}OLink(FSubsystemCollectionBase& Collection)
{
	if (Is{{$ModuleName}}LogEnabled())
	{
		UE_LOG(Log{{$mclass}}, Log, TEXT("create{{$iclass}}: Using OLink service backend"));
	}

	{{ printf "U%sOLinkClient" $DisplayName}}* Instance = Cast<{{ printf "U%sOLinkClient" $DisplayName}}>(Collection.InitializeDependency({{ printf "U%sOLinkClient" $DisplayName}}::StaticClass()));
	return Instance;
}
{{- end }}
{{- if $.Features.stubs }}

TScriptInterface<I{{$class}}Interface> create{{$class}}(FSubsystemCollectionBase& Collection)
{
	if (Is{{$ModuleName}}LogEnabled())
	{
		UE_LOG(Log{{$mclass}}, Log, TEXT("create{{$iclass}}: Using local service backend"));
	}

	{{ printf "U%s" $DisplayName}}* Instance = Cast<{{ printf "U%s" $DisplayName}}>(Collection.InitializeDependency({{ printf "U%s" $DisplayName}}::StaticClass()));
	return Instance;
}
{{- end }}

TScriptInterface<I{{$class}}Interface> {{$mclass}}::create{{$iclass}}(FSubsystemCollectionBase& Collection)
{
	U{{$ModuleName}}Settings* settings = GetMutableDefault<U{{$ModuleName}}Settings>();

	switch (settings->ServiceConnection)
	{
{{- if $.Features.olink }}{{ nl }}	case E{{$ModuleName}}Connection::CONNECTION_OLINK:
		return create{{$class}}OLink(Collection);{{ end }}
{{- if $.Features.stubs }}{{ nl }}	case E{{$ModuleName}}Connection::CONNECTION_LOCAL:
		return create{{$class}}(Collection);{{ end }}
	default:
{{- if $.Features.stubs }}
		return create{{$class}}(Collection);
{{- else if $.Features.olink }}
		return create{{$class}}OLink(Collection);
{{- end }}
	}
}
#endif
{{- end }}
