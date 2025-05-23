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
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "Async/Future.h"
#include "Async/Async.h"
#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}.json.adapter.h"
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Generated/api/{{Camel .Name}}.json.adapter.h"
{{- end }}
#include "OLinkClientConnection.h"
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

DEFINE_LOG_CATEGORY(Log{{$Class}});

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
		UE_LOG(Log{{$Class}}, Error, TEXT("Cannot set backend service - interface {{$Iface}} is not fully implemented"));
		return;
	}

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
void {{$Class}}::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
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
	if (!BackendService)
	{
		UE_LOG(Log{{$Class}}, Error, TEXT("No backend service set - please specify a service in the adapter {{$Iface}}OLinkAdapter which implements the {{$Iface}} interface"));
		return nlohmann::json();
	}

	const std::string path = Name::getMemberName(methodId);
{{- range .Interface.Operations }}
	if (path == "{{.Name}}")
	{
{{- range  $i, $e := .Params }}
		{{ueType "" .}} {{ueVar "" .}} = args.at({{ $i }}).get<{{ueReturn "" .}}>();
{{- end }}
{{- if .Return.IsVoid }}
		BackendService->{{Camel .Name}}({{ ueVars "" .Params }});
		return nlohmann::json{};
{{- else }}
		{{ueReturn "" .Return}} result = BackendService->{{Camel .Name}}({{ ueVars "" .Params }});
		return result;
{{- end }}
	}
{{- end }}
	return nlohmann::json();
}

void {{$Class}}::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
	if (!BackendService)
	{
		UE_LOG(Log{{$Class}}, Error, TEXT("No backend service set - please specify a service in the adapter {{$Iface}}OLinkAdapter which implements the {{$Iface}} interface"));
		return;
	}

	const std::string path = Name::getMemberName(propertyId);
{{- range .Interface.Properties }}
{{- if not .IsReadOnly }}
	if (path == "{{.Name}}")
	{
		{{ueReturn "" .}} {{ueVar "" .}} = value.get<{{ueReturn "" .}}>();
		BackendService->Set{{Camel .Name}}({{ueVar "" .}});
	}
{{- end }}
{{- end }}
}

nlohmann::json {{$Class}}::olinkCollectProperties()
{
	if (!BackendService)
	{
		UE_LOG(Log{{$Class}}, Error, TEXT("No backend service set - please specify a service in the adapter {{$Iface}}OLinkAdapter which implements the {{$Iface}} interface"));
		return nlohmann::json();
	}

	return nlohmann::json::object({ {{- if len .Interface.Properties}}{{nl}}{{end}}
{{- range $i, $e := .Interface.Properties }}{{if $i}},{{end}}
		{"{{.Name}}", BackendService->Get{{Camel .Name}}()}
{{- end }}});
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
