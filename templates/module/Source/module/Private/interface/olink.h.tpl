
{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := "OLinkService" }}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "apig/{{$ModuleName}}_apig.h"
#include "olink/clientnode.h"

namespace {{$ModuleName}}
{
namespace {{$IfaceName}}
{
namespace Private
{

class {{$Class}} : public I{{$Iface}}Interface, public ApiGear::ObjectLink::IObjectSink
{
public:
	explicit {{$Class}}();
	virtual ~{{$Class}}();

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
	{{ueReturn "" .}} Get{{Camel .Name}}() const override;
	void Set{{Camel .Name}}({{ueParam "" .}}) override;
{{ end }}
	// operations
{{- range .Interface.Operations }}
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override;
{{ end }}
	// olink sink interface
	std::string olinkObjectName() override;
	void olinkOnSignal(std::string name, nlohmann::json args) override;
	void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
	void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode* node) override;
	void olinkOnRelease() override;

private:
	void applyState(const nlohmann::json& fields);
	ApiGear::ObjectLink::IClientNode* m_node;
	bool m_isReady;
	// properties - local copy
{{- range .Interface.Properties }}
{{- if .Description }}
	/** {{ .Description }} */
{{- end }}
	{{ueReturn "" .}} {{ueVar "" .}};
{{- end }}
};

} // namespace Private
} // namespace {{$IfaceName}}
} // namespace {{$ModuleName}}