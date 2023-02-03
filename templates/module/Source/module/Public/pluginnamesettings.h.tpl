{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name) }}
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
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "{{$ModuleName}}Settings.generated.h"
{{- if $ConnecitonEnabled}}

/**
 * Enumeration E{{$ModuleName}}Connection
 */
UENUM(BlueprintType)
enum class E{{$ModuleName}}Connection : uint8
{
{{ if .Features.stubs }}	CONNECTION_LOCAL UMETA(Displayname = "Local"){{ if .Features.olink }},{{nl}}{{- end }}{{- end -}}
{{ if .Features.olink }}	CONNECTION_OLINK UMETA(Displayname = "Remote OLink"){{- end }}
};
{{- end}}

/**
 * Implements the settings for the {{$ModuleName}} plugin.
 */
UCLASS(Config = Engine, DefaultConfig)
class {{$API_MACRO}} U{{$ModuleName}}Settings : public UObject
{
	GENERATED_UCLASS_BODY()
{{- if $ConnecitonEnabled}}

	// Choose the backend service to use
	UPROPERTY(EditAnywhere, config, Category = ServiceSetup)
	E{{$ModuleName}}Connection ServiceConnection;
{{- end}}
};
