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

#include "Subsystems/GameInstanceSubsystem.h"
{{- $ModuleName := Camel .Module.Name}}
#include "{{$ModuleName}}_data.h"
{{- with .Interface }}
{{- $Class := printf "%s%s" $ModuleName (Camel .Name) }}
#include "{{$Class}}Interface.h"
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
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
{{- range $i, $e := .Signals }}
	{{- if $i }}{{nl}}{{ end }}
	UPROPERTY(BlueprintAssignable, Category = "{{$Category}}", DisplayName = "{{Camel .Name}} Signal")
	F{{$Iface}}{{Camel .Name}}Delegate {{Camel .Name}}Signal;
	virtual F{{$Class}}{{Camel .Name}}Delegate& Get{{Camel .Name}}SignalDelegate() override;
{{- end }}
{{- if len .Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Properties }}
	{{- if $i }}{{nl}}{{ end }}
	UPROPERTY(BlueprintAssignable, Category = "{{$Category}}", DisplayName = "{{Camel .Name}} Changed")
	F{{$Iface}}{{Camel .Name}}ChangedDelegate {{Camel .Name}}Changed;
	virtual F{{$Class}}{{Camel .Name}}ChangedDelegate& Get{{Camel .Name}}ChangedDelegate() override;
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

	virtual void Set{{Camel .Name}}_Implementation({{ueParam "In" .}}) override PURE_VIRTUAL({{ $abstractclass}}::Set{{Camel .Name}}_Implementation, return;);
{{- else }}
{{- end }}

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;
	// signals
{{- range $i, $e := .Signals }}
	{{- if $i }}{{nl}}{{ end }}
	virtual void Broadcast{{Camel .Name}}_Implementation({{ueParams "" .Params}}) override;
{{- end }}
{{- if len .Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Properties }}
	{{- if $i }}{{nl}}{{ end }}
	virtual void Broadcast{{Camel .Name}}Changed_Implementation({{ueParam "In" .}}) override;
{{- end }}

	// properties - local copy
{{- range $i, $e := .Properties }}
{{- if $i }}{{nl}}{{ end }}
{{- if .Description }}
	/** {{.Description}} */
{{- end }}
	UPROPERTY(EditAnywhere, BlueprintGetter = Get{{Camel .Name}}_Private, BlueprintSetter = Set{{Camel .Name}}_Private, Category = "{{$Category}}")
	{{ueReturn "" .}} {{ueVar "" .}}{ {{- ueDefault "" . -}} };

	UFUNCTION(BlueprintGetter, Category = "{{$Category}}", BlueprintInternalUseOnly)
	{{ueReturn "" .}} Get{{Camel .Name}}_Private() const;

	UFUNCTION(BlueprintSetter, Category = "{{$Category}}", BlueprintInternalUseOnly)
	void Set{{Camel .Name}}_Private({{ueParam "In" .}});
{{- end }}
};
{{- end }}
