{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sSimulationClient" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "{{$Iface}}Interface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "{{$Iface}}SimulationClient.generated.h"

UCLASS(BlueprintType)
class {{$Class}} : public UGameInstanceSubsystem, public I{{$Iface}}Interface
{
	GENERATED_BODY()
public:
	explicit {{$Class}}();
	virtual ~{{$Class}}() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
{{- range .Interface.Signals }}
	F{{$Iface}}{{Camel .Name}}Delegate {{Camel .Name}}Signal;
	F{{$Iface}}{{Camel .Name}}Delegate& Get{{Camel .Name}}SignalDelegate() override;
{{ end }}
{{- range .Interface.Properties }}
	F{{$Iface}}{{Camel .Name}}ChangedDelegate {{Camel .Name}}Changed;
	F{{$Iface}}{{Camel .Name}}ChangedDelegate& Get{{Camel .Name}}ChangedDelegate() override;
{{ end }}
	// properties
{{- range .Interface.Properties }}
	{{ueReturn "" .}} Get{{Camel .Name}}_Implementation() const override;
	void Set{{Camel .Name}}_Implementation({{ueParam "" .}}) override;
{{ end }}
	// operations
{{- range $i, $e := .Interface.Operations }}
{{- if $i }}{{nl}}{{ end }}
	{{- if .Return.IsVoid }}
	{{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) override;
	{{- else }}
	void {{Camel .Name}}Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}}, {{end}}{{ueParams "" .Params}}) override{};
	{{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) override;
	{{- end }}
{{- end }}

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
	// properties - local copy
{{- range .Interface.Properties }}
{{- if .Description }}
	/** {{ .Description }} */
{{- end }}
	{{ueReturn "" .}} {{ueVar "" .}};
{{- end }}
};
