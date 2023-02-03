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
#include "ApiGearConnectionsStore.h"
#include "Engine/Engine.h"

U{{$ModuleName}}Settings::U{{$ModuleName}}Settings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void U{{$ModuleName}}Settings::PostInitProperties()
{
	Super::PostInitProperties();

	// the local backend does not require configuration
	if (ConnectionIdentifier == "Local")
	{
		return;
	}

	check(GEngine);
	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	if (!AGCM->DoesConnectionExist(ConnectionIdentifier))
	{
		UE_LOG(LogTemp, Warning, TEXT("U{{$ModuleName}}Settings could not find connection %s, falling back to local backend."), *ConnectionIdentifier);
		ConnectionIdentifier = "Local";
	}
}
