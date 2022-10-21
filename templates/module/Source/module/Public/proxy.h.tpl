
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
#include "apig/{{$ModuleName}}_apig.h"
#include "{{$Iface}}Proxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "{{$DisplayName}}")
class {{ $API_MACRO }} {{$Class}} : public UGameInstanceSubsystem, public I{{$Iface}}Interface
{
	GENERATED_BODY()

public:
	explicit {{$Class}}();
	virtual ~{{$Class}}();

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
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}")
	{{ueReturn "" .}} Get{{Camel .Name}}() const override;

	UFUNCTION(BlueprintCallable, Category = "{{$Category}}")
	void Set{{Camel .Name}}({{ueParam "" .}}) override;
{{ end }}
	// operations
{{- range .Interface.Operations }}
	{{- if .Return.IsVoid }}
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}")
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override;
	{{ else }}
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void {{Camel .Name}}(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}},{{end}} {{ueParams "" .Params}});
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override;
	{{- end }}
{{ end }}
private:
	/** The connection to the service backend. */
	TSharedPtr<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface, ESPMode::ThreadSafe> service;

	// signals
{{- range .Interface.Signals }}
	UFUNCTION(Category = "{{$Category}}", BlueprintInternalUseOnly)
	void On{{Camel .Name}}({{ueParams "" .Params}});
{{ end }}
{{- range .Interface.Properties }}
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}", BlueprintInternalUseOnly)
	void On{{Camel .Name}}Changed({{ueParam "" .}});
{{ end }}
	// properties - local copy
{{- range .Interface.Properties }}
{{- if .Description }}
	/** {{.Description}} */
{{- end }}
	UPROPERTY(EditAnywhere, BlueprintGetter = Get{{Camel .Name}}, BlueprintSetter = Set{{Camel .Name}}, Category = "{{$Category}}")
	{{ueReturn "" .}} {{ueVar "" .}};
{{ else }}
{{ end -}}
};