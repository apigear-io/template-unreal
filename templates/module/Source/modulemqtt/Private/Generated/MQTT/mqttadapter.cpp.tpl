{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sMQTTAdapter" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}

#include "{{$ModuleName}}/Generated/MQTT/{{$Iface}}MQTTAdapter.h"
#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}.json.adapter.h"
#include "ApiGearMQTTHost.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include <nlohmann/json.hpp>
THIRD_PARTY_INCLUDES_END

DEFINE_LOG_CATEGORY(Log{{$Iface}}MQTTAdapter);

{{- if .Interface.Description }}
/**
   \brief {{.Interface.Description}}
*/
{{- end }}
{{$Class}}::{{$Class}}()
{
}

void {{$Class}}::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void {{$Class}}::Deinitialize()
{
	if (Host.IsValid() && bIsConnected)
	{
		TArray<FString> TopicsArray;
		Topics.GetKeys(TopicsArray);
		Host.Get()->unsubscribeTopic(TopicsArray);
	}

	Super::Deinitialize();
}

TMap<FString, ApiGear::MQTT::FCallbackFunction> {{$Class}}::createTopicMap()
{
	TMap<FString, ApiGear::MQTT::FCallbackFunction> Result;
{{- range .Interface.Properties }}
{{- if not .IsReadOnly }}
	Result.Add(FString(TEXT("{{$.Module.Name}}/{{$IfaceName}}/set/{{.}}")), [this](const IApiGearMqttClient::FReceivedMessage& InMsg)
		{
		OnSet{{Camel .Name}}(InMsg);
	});
{{- end }}
{{- end }}
{{- range .Interface.Operations }}
	Result.Add(FString(TEXT("{{$.Module.Name}}/{{$IfaceName}}/rpc/{{.}}")), [this](const IApiGearMqttClient::FReceivedMessage& InMsg)
		{
		OnInvoke{{Camel .Name}}(InMsg);
	});
{{- end }}
	return Result;
}

void {{$Class}}::setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		U{{$Iface}}Publisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service {{$Iface}}"));
		if (!BackendPublisher)
		{
			return;
		}
		BackendPublisher->Unsubscribe(TWeakInterfacePtr<I{{$Iface}}SubscriberInterface>(this));
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface {{$Iface}} is not fully implemented"));
	if (InService.GetInterface() == nullptr)
	{
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	U{{$Iface}}Publisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot subscribe to delegates from backend service {{$Iface}}"));
	if (!BackendPublisher)
	{
		return;
	}
	// connect property changed signals or simple events
	BackendPublisher->Subscribe(TWeakInterfacePtr<I{{$Iface}}SubscriberInterface>(this));
}

void {{$Class}}::setMQTTHost(TSoftObjectPtr<UApiGearMQTTHost> InHost)
{
	checkf(InHost.IsValid(), TEXT("Invalid pointer to MQTT host"));

	// remove old connection
	if (Host.IsValid())
	{
		TArray<FString> TopicsArray;
		Topics.GetKeys(TopicsArray);
		Host.Get()->unsubscribeTopic(TopicsArray);
	}
	Host = InHost;

	// set up new connection
	Host.Get()->OnConnectionStatusChanged().AddUObject(this, &{{$Class}}::OnConnectionStatusChanged);

	// call right away, host could already be connected
	OnConnectionStatusChanged(Host.Get()->IsConnected());
}

void {{$Class}}::OnConnectionStatusChanged(bool InIsConnected)
{
	bIsConnected = InIsConnected;
	if (!Host.IsValid() || !bIsConnected)
	{
		return;
	}

	// update topics map and subscribe
	Topics = createTopicMap();
	for (auto& Topic : Topics)
	{
		Host.Get()->subscribeTopic(Topic.Key, Topic.Value);
	}

	if (!BackendService)
	{
		return;
	}
	// push current property values to newly connected clients (retained)
{{- range .Interface.Properties }}
	On{{Camel .Name}}Changed(BackendService->Get{{Camel .Name}}());
{{- end }}
}
{{- range .Interface.Operations }}

void {{$Class}}::OnInvoke{{Camel .Name}}(const IApiGearMqttClient::FReceivedMessage& InMsg)
{
	if (!BackendService)
	{
		UE_LOG(Log{{$Iface}}MQTTAdapter, Error, TEXT("No backend service set for {{$Iface}} - cannot handle {{Camel .Name}} invoke"));
		return;
	}

{{- if not .Return.IsVoid }}
	if (InMsg.CorrelationData.Num() == 0 || InMsg.ResponseTopic.IsEmpty())
	{
		UE_LOG(Log{{$Iface}}MQTTAdapter, Error, TEXT("OnInvoke{{Camel .Name}}: missing CorrelationData or ResponseTopic"));
		return;
	}
{{- end }}

{{- if len .Params }}
	const std::string PayloadStr(reinterpret_cast<const char*>(InMsg.Payload.GetData()), InMsg.Payload.Num());
	const nlohmann::json FunctionPayload = nlohmann::json::parse(PayloadStr);
{{- end }}
{{- range $idx, $elem := .Params }}
	{{ueType "" .}} {{ueVar "" .}} = FunctionPayload.at({{$idx}}).get<{{ueType "" .}}>();
{{- end }}
{{- if .Return.IsVoid }}

	BackendService->{{Camel .Name}}({{ueVars "" .Params}});
{{- else }}

	{{ueReturn "" .Return}} Result = BackendService->{{Camel .Name}}({{ueVars "" .Params}});
	const nlohmann::json ResponsePayload = Result;
	Host.Get()->notifyInvokeResponseWithCorrelation(InMsg.ResponseTopic,
		UTF8_TO_TCHAR(ResponsePayload.dump().c_str()), InMsg.CorrelationData);
{{- end }}
}
{{- end }}
{{- range .Interface.Signals }}

void {{$Class}}::On{{Camel .Name}}Signal({{ueParams "In" .Params}})
{
	if (!Host.IsValid() || !bIsConnected)
	{
		return;
	}
	const nlohmann::json Args = {{ "{" }}{{ueVars "In" .Params}}};
	const FString Topic = TEXT("{{$.Module.Name}}/{{$IfaceName}}/sig/{{.}}");
	Host.Get()->notifySignal(Topic, UTF8_TO_TCHAR(Args.dump().c_str()));
}
{{- end }}
{{- range .Interface.Properties }}
{{- if not .IsReadOnly }}

void {{$Class}}::OnSet{{Camel .Name}}(const IApiGearMqttClient::FReceivedMessage& InMsg)
{
	if (!BackendService)
	{
		UE_LOG(Log{{$Iface}}MQTTAdapter, Error, TEXT("No backend service set for {{$Iface}} - cannot handle Set{{Camel .Name}} request"));
		return;
	}

	const std::string PayloadStr(reinterpret_cast<const char*>(InMsg.Payload.GetData()), InMsg.Payload.Num());
	const nlohmann::json JsonArgs = nlohmann::json::parse(PayloadStr);
	if (JsonArgs.empty())
	{
		return;
	}

	{{ueType "" .}} {{ueVar "" .}} = JsonArgs.get<{{ueType "" .}}>();
	BackendService->Set{{Camel .Name}}({{ueVar "" .}});
}
{{- end }}

void {{$Class}}::On{{Camel .Name}}Changed({{ueParam "In" .}})
{
	if (!Host.IsValid() || !bIsConnected)
	{
		return;
	}
	const FString Topic = TEXT("{{$.Module.Name}}/{{$IfaceName}}/prop/{{.}}");
	Host.Get()->notifyPropertyChange(Topic, UTF8_TO_TCHAR(nlohmann::json({{ueVar "In" .}}).dump().c_str()));
}
{{- end }}
