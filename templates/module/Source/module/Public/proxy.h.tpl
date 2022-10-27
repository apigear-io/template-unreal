
{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName (Camel .Interface.Name) }}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $Class := printf "U%sProxy" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Interface.Name) -}}
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
#include "UObject/NoExportTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/LatentActionManager.h"
#include "{{$ModuleName}}_apig.h"
#include "{{$Iface}}Proxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "{{$DisplayName}}")
class {{ $API_MACRO }} {{$Class}} : public UGameInstanceSubsystem, public I{{$Iface}}Interface
{
	GENERATED_BODY()

public:
	explicit {{$Class}}();
	virtual ~{{$Class}}();

	UFUNCTION(BlueprintCallable, Category = "{{$Category}}")
	void setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> InService);

	// signals
{{- range .Interface.Signals }}
	UPROPERTY(BlueprintAssignable, Category = "{{$Category}}", DisplayName = "{{Camel .Name}} Signal")
	F{{$Iface}}{{Camel .Name}}Delegate {{Camel .Name}}Signal;
	F{{$Iface}}{{Camel .Name}}Delegate& Get{{Camel .Name}}SignalDelegate() override;
{{ end }}
{{- range .Interface.Properties }}
	UPROPERTY(BlueprintAssignable, Category = "{{$Category}}", DisplayName = "{{Camel .Name}} Changed")
	F{{$Iface}}{{Camel .Name}}ChangedDelegate {{Camel .Name}}Changed;
	F{{$Iface}}{{Camel .Name}}ChangedDelegate& Get{{Camel .Name}}ChangedDelegate() override;
{{ end }}
	// properties
{{- range .Interface.Properties }}
{{- if .Description }}
	/** {{.Description}} */
{{- end }}
	{{ueReturn "" .}} Get{{Camel .Name}}_Implementation() const override;

	void Set{{Camel .Name}}_Implementation({{ueParam "In" .}}) override;
{{ end }}
	// operations
{{- range .Interface.Operations }}
	{{- if .Return.IsVoid }}
	{{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) override;
	{{- else }}
	void {{Camel .Name}}Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}}, {{end}}{{ueParams "" .Params}}) override;
	{{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) override;
	{{- end }}
{{ end }}
protected:
	// signals
{{- range $i, $e := .Interface.Signals }}
{{- if $i }}{{nl}}{{ end }}
	void Broadcast{{Camel .Name}}_Implementation({{ueParams "" .Params}}) override;
{{- end }}
{{- if len .Interface.Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
	void Broadcast{{Camel .Name}}Changed_Implementation({{ueParam "" .}}) override;
{{- end }}

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "{{$Category}}")
	TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> BackendService;

	// signals
{{- range $i, $e := .Interface.Signals }}
{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(Category = "{{$Category}}", BlueprintInternalUseOnly)
	void On{{Camel .Name}}({{ueParams "" .Params}});
{{- end }}
{{- if len .Interface.Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(Category = "{{$Category}}", BlueprintInternalUseOnly)
	void On{{Camel .Name}}Changed({{ueParam "" .}});
{{- end }}

	// properties - local copy
{{- range $i, $e := .Interface.Properties }}
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
