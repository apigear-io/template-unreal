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
{{- with .Interface }}
{{- $Class := printf "%s%s" $ModuleName (Camel .Name) }}
#include "{{$ModuleName}}/Generated/api/{{$Class}}Interface.h"
{{- $Category := printf "ApiGear|%s|%s" $ModuleName (Camel .Name) }}
{{- $class := printf "I%sInterface" $Class }}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Name) }}
#include "Abstract{{$Class}}.generated.h"
{{ $abstractclass := printf "UAbstract%s" $Class }}
/**
 * Abstract {{$abstractclass}}
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class {{ $API_MACRO }} {{ $abstractclass}} : public UGameInstanceSubsystem, public {{ $class }}
{
	GENERATED_BODY()

public:
	// constructor
	{{ $abstractclass}}();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

{{- if or (len .Properties) (len .Signals) }}
{{- nl }}
	// signals
	virtual U{{$Class}}Signals* _GetSignals_Implementation() override;
{{- end }}

	// methods
{{- range $i, $e := .Operations }}
{{- if .Return.IsVoid }}
	virtual {{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) override PURE_VIRTUAL({{ $abstractclass}}::{{Camel .Name}}_Implementation, return;);
{{- else }}
	virtual void {{Camel .Name}}Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}},{{end}} {{ueParams "" .Params}}) override;
	virtual {{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) override PURE_VIRTUAL({{ $abstractclass}}::{{Camel .Name}}_Implementation, return {{ueDefault "" .Return}};);
{{- end }}
{{ else }}
{{ end }}
	// properties
{{- range .Properties }}
	virtual {{ueReturn "" .}} Get{{Camel .Name}}_Implementation() const override PURE_VIRTUAL({{ $abstractclass}}::Get{{Camel .Name}}_Implementation, return {{ueDefault "" .}};);
{{- if not .IsReadOnly }}
	virtual void Set{{Camel .Name}}_Implementation({{ueParam "In" .}}) override PURE_VIRTUAL({{ $abstractclass}}::Set{{Camel .Name}}_Implementation, return;);
{{- end }}
{{- nl }}
{{- else }}{{- nl }}
{{- end }}
	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
{{- range $i, $e := .Properties }}
{{- if $i }}{{nl}}{{ end }}
{{- if .Description }}
	/** {{.Description}} */
{{- end }}
	UPROPERTY(EditAnywhere, BlueprintGetter = Get{{Camel .Name}}_Private, {{ if not .IsReadOnly -}} BlueprintSetter = Set{{Camel .Name}}_Private, {{ end }}Category = "{{$Category}}")
	{{ueReturn "" .}} {{ueVar "" .}}{ {{- ueDefault "" . -}} };

	UFUNCTION(BlueprintGetter, Category = "{{$Category}}|Properties", BlueprintInternalUseOnly)
	{{ueReturn "" .}} Get{{Camel .Name}}_Private() const;
{{- if not .IsReadOnly }}{{nl}}
	UFUNCTION(BlueprintSetter, Category = "{{$Category}}|Properties", BlueprintInternalUseOnly)
	void Set{{Camel .Name}}_Private({{ueParam "In" .}});
{{- end }}
{{- end }}

private:
{{- if or (len .Properties) (len .Signals) }}
	// signals
	UPROPERTY()
	U{{$Class}}Signals* {{$Iface}}Signals;
{{- end }}
};
{{- end }}
