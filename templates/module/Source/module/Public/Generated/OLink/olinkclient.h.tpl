
{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sOLinkClient" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "{{$Iface}}Interface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "unrealolinksink.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "{{$Iface}}OLinkClient.generated.h"

UCLASS(BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public UGameInstanceSubsystem, public I{{$Iface}}Interface
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
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// properties - local copy
{{- range .Interface.Properties }}
{{- if .Description }}
	/** {{ .Description }} */
{{- end }}
	{{ueReturn "" .}} {{ueVar "" .}}{ {{- ueDefault "" . -}} };
{{- end }}
};
