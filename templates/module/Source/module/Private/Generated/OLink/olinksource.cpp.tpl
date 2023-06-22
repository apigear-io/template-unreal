{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "%sOLinkSource" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
{{- $ifaceId := printf "%s.%s" .Module.Name .Interface.Name}}

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "{{$Iface}}OLinkSource.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/{{$ModuleName}}.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END

using namespace ApiGear::ObjectLink;

namespace
{
static const std::string {{$Iface}}Identifier{"{{$.Module.Name}}.{{$.Interface.Name}}"};
}

{{- if .Interface.Description }}
/**
   \brief {{.Interface.Description}}
*/
{{- end }}
{{$Class}}::{{$Class}}()
	: Host(nullptr)
{
}

void {{$Class}}::setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> InService)
{
	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot set backend service to %s - interface {{$Iface}} is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	// set to new backend
	BackendService = InService;
}

{{- range .Interface.Signals }}
void {{$Class}}::On{{Camel .Name}}({{ueParams "" .Params}})
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "{{.Name}}");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {{ "{" }}{{ ueVars "" .Params }}};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}
{{ end }}

{{- range .Interface.Properties }}
void {{$Class}}::On{{Camel .Name}}Changed({{ueParam "In" .}})
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "{{.Name}}");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, {{ueVar "In" .}});
		}
	}
}
{{ end }}
void {{$Class}}::setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost)
{
	Host = InHost.Get();
}

//
// IObjectSource interface
//

std::string {{$Class}}::olinkObjectName()
{
	return {{$Iface}}Identifier;
}

nlohmann::json {{$Class}}::olinkInvoke(const std::string& methodId, const nlohmann::json& args)
{
	const std::string path = Name::getMemberName(methodId);
{{- range .Interface.Operations }}
	if (path == "{{.Name}}")
	{
{{- range  $i, $e := .Params }}
		{{ueType "" .}} {{ueVar "" .}} = args.at({{ $i }});
{{- end }}
{{- if .Return.IsVoid }}
		BackendService->Execute_{{Camel .Name}}(BackendService.GetObject(){{ if len .Params }}, {{end}}{{ ueVars "" .Params }});
		return nlohmann::json{};
{{- else }}
		{{ueReturn "" .Return}} result = BackendService->Execute_{{Camel .Name}}(BackendService.GetObject(){{ if len .Params }}, {{end}}{{ ueVars "" .Params }});
		return result;
{{- end }}
	}
{{- end }}
	return nlohmann::json();
}

void {{$Class}}::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
	const std::string path = Name::getMemberName(propertyId);
{{- range .Interface.Properties }}
{{- if not .IsReadOnly }}
	if (path == "{{.Name}}")
	{
		{{ueReturn "" .}} {{ueVar "" .}} = value.get<{{ueReturn "" .}}>();
		BackendService->Execute_Set{{Camel .Name}}(BackendService.GetObject(), {{ueVar "" .}});
	}
{{- end }}
{{- end }}
}

nlohmann::json {{$Class}}::olinkCollectProperties()
{
	return nlohmann::json::object({ {{- if len .Interface.Properties}}{{nl}}{{end}}
{{- range $i, $e := .Interface.Properties }}{{if $i}},{{end}}
		{"{{.Name}}", BackendService->Execute_Get{{Camel .Name}}(BackendService.GetObject())}
{{- end }}});
}
