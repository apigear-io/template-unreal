{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name -}}
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

{{- with .Interface }}
{{- $Class := printf "%s%s" $ModuleName (Camel .Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName (Camel .Name) }}
{{- $class := printf "U%sInterface" $Class }}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Name) }}
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "{{$ModuleName}}_data.h"
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Generated/api/{{Camel .Name}}_data.h"
{{- end }}
#include "{{$Class}}Interface.generated.h"

{{- if or (len .Properties) (len .Signals) }}
{{- nl }}
/**
 * Declaration for {{.Name}}
 */
// signal delegates
{{- range .Signals }}
DECLARE_MULTICAST_DELEGATE{{Int2Word (len .Params) "_" "Param"}}(F{{$Class}}{{Camel .Name}}Delegate{{range $idx, $elem := .Params}}, {{ueConstType "" .}} /* {{ueVar "" .}} */{{end}});
DECLARE_DYNAMIC_MULTICAST_DELEGATE{{Int2Word (len .Params) "_" "Param"}}(F{{$Class}}{{Camel .Name}}DelegateBP{{range $idx, $elem := .Params}}, {{ueConstType "" .}}, {{ueVar "" .}}{{end}});
{{ end }}
// property delegates
{{- range .Properties }}
DECLARE_MULTICAST_DELEGATE{{Int2Word 1 "_" "Param"}}(F{{$Class}}{{Camel .Name}}ChangedDelegate, {{ueConstType "" .}} /* {{ueVar "" .}} */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE{{Int2Word 1 "_" "Param"}}(F{{$Class}}{{Camel .Name}}ChangedDelegateBP, {{ueConstType "" .}}, {{ueVar "" .}});
{{- end }}

/**
 * Class {{$class}}Signals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class {{$API_MACRO}} U{{$Class}}Signals : public UObject
{
	GENERATED_BODY()

public:
{{- range $i, $e := .Signals }}
	{{- if $i }}{{nl}}{{ end }}
	F{{$Iface}}{{Camel .Name}}Delegate On{{Camel .Name}}Signal;
	UPROPERTY(BlueprintAssignable, Category = "{{$Category}}|Signals", DisplayName = "{{Camel .Name}} Signal")
	F{{$Iface}}{{Camel .Name}}DelegateBP On{{Camel .Name}}SignalBP;
	/// C++ wrapper for BP functions to safely call {{Camel .Name}}Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}|Signals", DisplayName = "Broadcast {{Camel .Name}} Signal")
	void Broadcast{{Camel .Name}}Signal({{ueParams "" .Params}})
	{
		On{{Camel .Name}}Signal.Broadcast({{ueVars "" .Params}});
		On{{Camel .Name}}SignalBP.Broadcast({{ueVars "" .Params}});
	}
{{- end }}
{{- if and (len .Properties) (len .Signals) }}{{ nl }}{{ end }}
{{- range $i, $e := .Properties }}
	{{- if $i }}{{nl}}{{ end }}
	F{{$Iface}}{{Camel .Name}}ChangedDelegate On{{Camel .Name}}Changed;
	UPROPERTY(BlueprintAssignable, Category = "{{$Category}}|Signals", DisplayName = "Property {{Camel .Name}} Changed")
	F{{$Iface}}{{Camel .Name}}ChangedDelegateBP On{{Camel .Name}}ChangedBP;
	/// C++ wrapper for BP functions to safely call On{{Camel .Name}}Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}|Signals", DisplayName = "Broadcast Property {{Camel .Name}} Changed")
	void Broadcast{{Camel .Name}}Changed(UPARAM(DisplayName = "{{ueVar "" .}}") {{ueParam "In" .}})
	{
		On{{Camel .Name}}Changed.Broadcast({{ueVar "In" .}});
		On{{Camel .Name}}ChangedBP.Broadcast({{ueVar "In" .}});
	}
{{- end }}
};
{{- end}}

/**
 * Interface {{$class}} only for Unreal Engine's reflection system
 */
// Note: meta=(CannotImplementInterfaceInBlueprint) is equal to NotBlueprintable and is only needed for UE 4.27
UINTERFACE(NotBlueprintable, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class {{$class}} : public UInterface
{
	GENERATED_BODY()
};
{{ $class := printf "I%sInterface" $Class }}
/**
 * Interface {{$class}}
 */
class {{ $API_MACRO }} {{ $class}}
{
	GENERATED_BODY()

public:
{{- if or (len .Properties) (len .Signals) }}
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}")
	virtual U{{$Class}}Signals* _GetSignals() = 0;
	{{- nl }}
{{- end}}
	// methods
{{- range $i, $e := .Operations }}
{{- if .Return.IsVoid }}
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}|Operations")
	virtual {{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) = 0;
{{- else }}
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void {{Camel .Name}}Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}},{{end}} {{ueParams "" .Params}}) = 0;
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}|Operations")
	virtual {{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) = 0;
{{- end }}
{{ else }}
{{ end }}
	// properties
{{- range .Properties }}
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}|Properties")
	virtual {{ueReturn "" .}} Get{{Camel .Name}}() const = 0;
{{- if not .IsReadOnly }}
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}|Properties")
	virtual void Set{{Camel .Name}}(UPARAM(DisplayName = "{{ueVar "" .}}") {{ueParam "In" .}}) = 0;
{{- end }}
{{- end }}
};
{{- end }}
