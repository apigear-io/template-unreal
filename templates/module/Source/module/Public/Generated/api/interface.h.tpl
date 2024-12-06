{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name ) -}}
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

#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
{{- $ModuleName := Camel .Module.Name}}
#include "Generated/api/{{$ModuleName}}_data.h"
{{- with .Interface }}
{{- $Class := printf "%s%s" $ModuleName (Camel .Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName (Camel .Name) }}
{{- $class := printf "U%sInterface" $Class }}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Name) }}
{{- range .Module.Imports }}
#include "Generated/api/{{Camel .Name}}_data.h"
{{- end }}
#include "{{$Class}}Interface.generated.h"

{{- if or (len .Properties) (len .Signals) }}
{{- nl }}
/**
 * Declaration for {{.Name}}
 */
// signal delegates
{{- range .Signals }}
DECLARE_DYNAMIC_MULTICAST_DELEGATE{{Int2Word (len .Params) "_" "Param"}}(F{{$Class}}{{Camel .Name}}Delegate{{range $idx, $elem := .Params}}, {{ueConstType "" .}}, {{ueVar "" .}}{{end}});
{{ end }}
// property delegates
{{- range .Properties }}
DECLARE_DYNAMIC_MULTICAST_DELEGATE{{Int2Word 1 "_" "Param"}}(F{{$Class}}{{Camel .Name}}ChangedDelegate, {{ueConstType "" .}}, {{ueVar "" .}});
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
	UPROPERTY(BlueprintAssignable, Category = "{{$Category}}|Signals", DisplayName = "{{Camel .Name}} Signal")
	F{{$Iface}}{{Camel .Name}}Delegate On{{Camel .Name}}Signal;
	/// C++ wrapper for BP functions to safely call {{Camel .Name}}Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}|Signals", DisplayName = "Broadcast {{Camel .Name}} Signal")
	void Broadcast{{Camel .Name}}Signal({{ueParams "" .Params}})
	{
		On{{Camel .Name}}Signal.Broadcast({{ueVars "" .Params}});
	}
{{- end }}
{{- if and (len .Properties) (len .Signals) }}{{ nl }}{{ end }}
{{- range $i, $e := .Properties }}
	{{- if $i }}{{nl}}{{ end }}
	UPROPERTY(BlueprintAssignable, Category = "{{$Category}}|Signals", DisplayName = "Property {{Camel .Name}} Changed")
	F{{$Iface}}{{Camel .Name}}ChangedDelegate On{{Camel .Name}}Changed;
	/// C++ wrapper for BP functions to safely call On{{Camel .Name}}Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}|Signals", DisplayName = "Broadcast Property {{Camel .Name}} Changed")
	void Broadcast{{Camel .Name}}Changed(UPARAM(DisplayName = "{{ueVar "" .}}") {{ueParam "In" .}})
	{
		On{{Camel .Name}}Changed.Broadcast({{ueVar "In" .}});
	}
{{- end }}
};
{{- end}}

/**
 * Interface {{$class}} only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
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
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}")
	U{{$Class}}Signals* _GetSignals();
	virtual U{{$Class}}Signals* _GetSignals_Implementation() = 0;
	{{- nl }}
{{- end}}
	// methods
{{- range $i, $e := .Operations }}
{{- if .Return.IsVoid }}
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}|Operations")
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}});
	virtual {{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) = 0;
{{- else }}
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void {{Camel .Name}}Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}},{{end}} {{ueParams "" .Params}});
	virtual void {{Camel .Name}}Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}},{{end}} {{ueParams "" .Params}}) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}|Operations")
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}});
	virtual {{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) = 0;
{{- end }}
{{ else }}
{{ end }}
	// properties
{{- range .Properties }}
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}|Properties")
	{{ueReturn "" .}} Get{{Camel .Name}}() const;
	virtual {{ueReturn "" .}} Get{{Camel .Name}}_Implementation() const = 0;
{{- if not .IsReadOnly }}
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}|Properties")
	void Set{{Camel .Name}}({{ueParam "In" .}});
	virtual void Set{{Camel .Name}}_Implementation(UPARAM(DisplayName = "{{ueVar "" .}}") {{ueParam "In" .}}) = 0;
{{- end }}
{{- end }}
};
{{- end }}
