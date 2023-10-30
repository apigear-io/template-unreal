{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" $ModuleName }}
{{- $ConnecitonEnabled := or .Features.stubs .Features.olink -}}
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
#include "{{$ModuleName}}Settings.h"
{{- if .Features.api }}
#include "Generated/{{$ModuleName}}LogCategories.h"
{{- end }}
{{- if $.Features.apigear }}
#include "ApiGearConnectionsStore.h"
{{- end }}
#include "Engine/Engine.h"
#include "Misc/CoreDelegates.h"

U{{$ModuleName}}Settings::U{{$ModuleName}}Settings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FCoreDelegates::OnPostEngineInit.AddUObject(this, &U{{$ModuleName}}Settings::ValidateSettingsPostEngineInit);
}

void U{{$ModuleName}}Settings::ValidateSettingsPostEngineInit()
{
	check(GEngine);
{{- if $.Features.apigear }}
	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();
{{- end }}

{{- if $.Features.olink}}

	if (!AGCM->DoesConnectionExist(OLinkConnectionIdentifier))
	{
		UE_LOG(Log{{$ModuleName}}, Warning, TEXT("U{{$ModuleName}}Settings could not find connection %s."), *OLinkConnectionIdentifier);
		OLinkConnectionIdentifier = "";
	}
{{- end }}

{{- if $.Features.monitor }}

	// the local backend does not require configuration
	if (TracerServiceIdentifier == {{$ModuleName}}LocalBackendIdentifier)
	{
		return;
	}

	if (!AGCM->DoesConnectionExist(TracerServiceIdentifier))
	{
		UE_LOG(Log{{$ModuleName}}, Warning, TEXT("U{{$ModuleName}}Settings could not find connection %s, falling back to local backend."), *TracerServiceIdentifier);
		TracerServiceIdentifier = {{$ModuleName}}LocalBackendIdentifier;
	}
{{- end }}
}
