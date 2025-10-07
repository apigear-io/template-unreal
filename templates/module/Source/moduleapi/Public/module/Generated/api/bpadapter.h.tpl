{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name -}}
/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "{{$ModuleName}}_data.h"
{{- $Class := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
#include "{{$ModuleName}}/Generated/api/{{$Class}}Interface.h"
#include "{{$ModuleName}}/Generated/api/{{$Class}}BPInterface.h"
{{- with .Interface }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName (Camel .Name) }}
{{- $cppinterface := printf "I%sInterface" $Class }}
{{- $bpinterface := printf "I%sBPInterface" $Class }}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Name) }}
#include "{{$Class}}BPAdapter.generated.h"
{{ $adapter := printf "U%sBPAdapter" $Class }}
/**
 * Adapter {{$adapter}} from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class {{ $API_MACRO }} {{ $adapter}} : public UObject, public {{ $cppinterface }}
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "{{$Category}}")
	TScriptInterface<{{ $bpinterface }}> Target;

	UFUNCTION(BlueprintCallable, Category = "{{$Category}}")
	void Initialize(TScriptInterface<{{ $bpinterface }}> InTarget);

{{- nl }}
	// signals
	U{{$Class}}Publisher* _GetPublisher() override;

	// methods
{{- range $i, $e := .Operations }}
{{- if .Return.IsVoid }}
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override;
{{- else }}
	void {{Camel .Name}}Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}},{{end}} {{ueParams "" .Params}}) override;
	TFuture<{{ueReturn "" .Return}}> {{Camel .Name}}Async({{ueParams "" .Params}}) override;
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override;
{{- end }}
{{ else }}
{{ end }}
	// properties
{{- range $i, $e := .Properties }}
{{- if $i }}{{nl}}{{ end }}
	{{ueReturn "" .}} Get{{Camel .Name}}() const override;
{{- if not .IsReadOnly }}
	void Set{{Camel .Name}}({{ueParam "In" .}}) override;
{{- end }}
{{- end }}
};
{{- end }}
