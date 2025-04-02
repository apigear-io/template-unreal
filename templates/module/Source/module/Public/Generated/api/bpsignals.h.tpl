{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name ) -}}
{{- $hasVoidFunctions := false }}
{{- range $i, $e := .Interface.Operations }}
{{- if .Return.IsVoid }}{{- $hasVoidFunctions = true }}{{- end }}
{{- end -}}
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

#include "UObject/Interface.h"
{{- $ModuleName := Camel .Module.Name}}
#include "Generated/api/{{$ModuleName}}_data.h"
{{- with .Interface }}
{{- $Class := printf "%s%s" $ModuleName (Camel .Name) }}
{{- $Category := printf "ApiGear Helper|%s|%s" $ModuleName (Camel .Name) }}
{{- $class := printf "U%sInterface" $Class }}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Name) }}
{{- range .Module.Imports }}
#include "Generated/api/{{Camel .Name}}_data.h"
{{- end }}
#include "{{$Class}}InterfaceBPSignals.generated.h"

{{- if or (len .Properties) (len .Signals) (len .Operations) }}
{{- nl }}
/**
 * Helper interface for {{$Class}} events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class U{{$Class}}BPSignalsInterface : public UInterface
{
	GENERATED_BODY()
};

class {{$API_MACRO}} I{{$Class}}BPSignalsInterface
{
	GENERATED_BODY()

public:
{{- range $i, $e := .Signals }}
	{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "{{$Category}}|Signals", DisplayName = "On {{Camel .Name}} Signal")
	void On{{Camel .Name}}Signal({{ueParams "" .Params}});
{{- end }}
{{- if and (len .Properties) (len .Signals) }}{{ nl }}{{ end }}
{{- range $i, $e := .Properties }}
	{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "{{$Category}}|Signals", DisplayName = "On Property {{Camel .Name}} Changed")
	void On{{Camel .Name}}Changed(UPARAM(DisplayName = "{{ueVar "" .}}") {{ueParam "In" .}});
{{- end }}
{{- if or (and (len .Properties) $hasVoidFunctions) (and (len .Signals) $hasVoidFunctions) }}{{ nl }}{{ end }}
{{- range $i, $e := .Operations }}
{{- if .Return.IsVoid }}
	{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "{{$Category}}|Signals", DisplayName = "Do {{Camel .Name}}")
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}});
{{- end }}
{{- end }}
};
{{- end }}
{{- end }}
