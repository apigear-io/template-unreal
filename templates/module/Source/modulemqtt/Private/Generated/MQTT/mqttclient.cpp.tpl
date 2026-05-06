{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sMQTTClient" $DisplayName}}
{{- $abstractclass := printf "UAbstract%s%s" (Camel .Module.Name) (Camel .Interface.Name) }}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}

#include "{{$ModuleName}}/Generated/MQTT/{{$Iface}}MQTTClient.h"
#include "{{$ModuleName}}/Generated/Core/{{$ModuleName}}PropertiesData.h"
#include "ApiGearSettings.h"
#include "apigearmqtt.h"
#include "ApiGearMQTTClient.h"
#include "Async/Async.h"
#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}.json.adapter.h"
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Generated/api/{{Camel .Name}}.json.adapter.h"
{{- end }}
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionsStore.h"
#include "Misc/DateTime.h"
#include "{{$ModuleName}}Settings.h"
THIRD_PARTY_INCLUDES_START
#include "nlohmann/json.hpp"
THIRD_PARTY_INCLUDES_END

DEFINE_LOG_CATEGORY(Log{{$Iface}}MQTTClient);
{{ if .Interface.Description }}
/**
   \brief {{.Interface.Description}}
*/
{{- end }}
{{$Class}}::{{$Class}}()
	: {{$abstractclass}}()
{{- if len .Interface.Properties }}
	, _SentData(MakePimpl<{{$Iface}}PropertiesData>())
{{- end }}
{
}

{{$Class}}::{{$Class}}(FVTableHelper& Helper)
	: Super(Helper)
{
}
{{$Class}}::~{{$Class}}() = default;

TMap<FString, ApiGear::MQTT::FCallbackFunction> {{$Class}}::createTopicMap(const FString& ClientId)
{
	TMap<FString, ApiGear::MQTT::FCallbackFunction> Result;
{{- range .Interface.Properties}}
	Result.Add(FString::Printf(TEXT("{{$.Module.Name}}/{{$IfaceName}}/prop/%s"), TEXT("{{.Name}}")), [this](const IApiGearMqttClient::FReceivedMessage& InMsg)
		{
		this->set{{Camel .Name}}Local(InMsg);
	});
{{- end }}
{{- range .Interface.Signals}}
	Result.Add(FString::Printf(TEXT("{{$.Module.Name}}/{{$IfaceName}}/sig/%s"), TEXT("{{.Name}}")), [this](const IApiGearMqttClient::FReceivedMessage& InMsg)
		{
		this->on{{Camel .Name}}(InMsg);
	});
{{- end }}
{{- range .Interface.Operations}}
{{- if not .Return.IsVoid }}
	Result.Add(FString::Printf(TEXT("{{$.Module.Name}}/{{$IfaceName}}/rpc/%s/%s/result"), TEXT("{{.Name}}"), *ClientId), [this](const IApiGearMqttClient::FReceivedMessage& InMsg)
		{
		this->onInvokeReply(InMsg);
	});
{{- end }}
{{- end }}
	return Result;
}

void {{$Class}}::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	check(GEngine);
	U{{$ModuleName}}Settings* settings = GetMutableDefault<U{{$ModuleName}}Settings>();

	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	TScriptInterface<IApiGearConnection> MQTTConnection = AGCM->GetConnection(settings->MQTTConnectionIdentifier);

	if (!MQTTConnection.GetInterface())
	{
		return;
	}
	UseConnection(MQTTConnection);
	MQTTConnection->Connect();
}

void {{$Class}}::Deinitialize()
{
	if (Connection.GetObject())
	{
		UApiGearMQTTClient* ApiGearMQTTClient = Cast<UApiGearMQTTClient>(Connection.GetObject());
		if (ApiGearMQTTClient)
		{
			ApiGearMQTTClient->OnConnectionStatusChanged().RemoveAll(this);

			TArray<FString> TopicsArray;
			Topics.GetKeys(TopicsArray);
			ApiGearMQTTClient->unsubscribeTopic(TopicsArray);
		}
	}

	// cancel all outstanding response promises
	{
		FScopeLock Lock(&ResponseHandlerMutex);
		for (auto& Pair : ResponseHandlerMap)
		{
			ApiGear::MQTT::InvokeReplyArg EmptyReply;
			Pair.Value(EmptyReply);
		}
		ResponseHandlerMap.Empty();
	}

	Super::Deinitialize();
}

void {{$Class}}::UseConnection(TScriptInterface<IApiGearConnection> InConnection)
{
	if (!InConnection.GetInterface())
	{
		UE_LOG(Log{{$Iface}}MQTTClient, Error, TEXT("The MQTT connection for the %s client does not implement the connection interface."), TEXT("{{$Iface}}"));
		return;
	}

	// only accept connections of type mqtt
	checkf(InConnection->GetConnectionProtocolIdentifier() == ApiGearMQTTProtocolIdentifier, TEXT("Cannot use connection - must be of type mqtt"));

	UApiGearMQTTClient* ApiGearMQTTClient = nullptr;
	// remove old connection
	if (Connection.GetObject())
	{
		ApiGearMQTTClient = Cast<UApiGearMQTTClient>(Connection.GetObject());
		if (ApiGearMQTTClient)
		{
			ApiGearMQTTClient->OnConnectionStatusChanged().RemoveAll(this);

			TArray<FString> TopicsArray;
			Topics.GetKeys(TopicsArray);
			ApiGearMQTTClient->unsubscribeTopic(TopicsArray);
		}
		ApiGearMQTTClient = nullptr;
	}

	// set up new connection
	ApiGearMQTTClient = Cast<UApiGearMQTTClient>(InConnection.GetObject());
	ApiGearMQTTClient->OnConnectionStatusChanged().AddUObject(this, &{{$Class}}::onConnectionStatusChanged);

	Connection = InConnection;

	// call right away, client could already be connected
	onConnectionStatusChanged(ApiGearMQTTClient->IsConnected());
}

void {{$Class}}::onConnectionStatusChanged(bool bIsConnected)
{
	if (!bIsConnected)
	{
		// Reset subscription bookkeeping on every disconnect, including ones where
		// we never reached bIsSubscribed (e.g. all subscribes failed). Otherwise a
		// stale bAnySubscribeFailed=true poisons the next reconnect.
		bAnySubscribeFailed = false;
		PendingSubscriptions = 0;
		if (bIsSubscribed)
		{
			bIsSubscribed = false;
			_SubscriptionStatusChanged.Broadcast(false);
			_SubscriptionStatusChangedBP.Broadcast(false);
		}
		return;
	}

	UApiGearMQTTClient* ApiGearMQTTClient = Cast<UApiGearMQTTClient>(Connection.GetObject());
	if (!ApiGearMQTTClient)
	{
		return;
	}

	Topics = createTopicMap(ApiGearMQTTClient->getClientId());

	if (Topics.Num() == 0)
	{
		// no topics to subscribe to, consider immediately ready
		bIsSubscribed = true;
		_SubscriptionStatusChanged.Broadcast(true);
		_SubscriptionStatusChangedBP.Broadcast(true);
		return;
	}

	PendingSubscriptions = Topics.Num();

	TWeakObjectPtr<{{$Class}}> weak(this);
	for (auto& Topic : Topics)
	{
		ApiGearMQTTClient->subscribeTopic(Topic.Key, Topic.Value,
			[weak](bool bSuccess)
			{
			if (auto* self = weak.Get())
			{
				self->DecrementPendingSubscription(bSuccess);
			}
		});
	}
}

void {{$Class}}::DecrementPendingSubscription(bool bSuccess)
{
	if (!bSuccess)
	{
		bAnySubscribeFailed = true;
	}
	PendingSubscriptions--;
	if (PendingSubscriptions > 0 || bIsSubscribed)
	{
		return;
	}
	bIsSubscribed = !bAnySubscribeFailed;
	_SubscriptionStatusChanged.Broadcast(bIsSubscribed);
	_SubscriptionStatusChangedBP.Broadcast(bIsSubscribed);
}

bool {{$Class}}::_IsSubscribed() const
{
	return bIsSubscribed;
}

FGuid {{$Class}}::RegisterResponseHandler(ApiGear::MQTT::InvokeReplyFunc&& Handler)
{
	FScopeLock Lock(&ResponseHandlerMutex);
	FGuid ResponseId = FGuid::NewGuid();
	ResponseHandlerMap.Add(ResponseId, MoveTemp(Handler));
	return ResponseId;
}

void {{$Class}}::onInvokeReply(const IApiGearMqttClient::FReceivedMessage& InMsg)
{
	if (InMsg.CorrelationData.Num() == 0)
	{
		UE_LOG(Log{{$Iface}}MQTTClient, Error, TEXT("onInvokeReply: missing CorrelationData"));
		return;
	}

	const FString GuidStr = FString(InMsg.CorrelationData.Num(),
		UTF8_TO_TCHAR(reinterpret_cast<const char*>(InMsg.CorrelationData.GetData())));
	FGuid ResponseId;
	if (!FGuid::Parse(GuidStr, ResponseId))
	{
		UE_LOG(Log{{$Iface}}MQTTClient, Error, TEXT("onInvokeReply: CorrelationData is not a valid GUID: %s"), *GuidStr);
		return;
	}

	FScopeLock Lock(&ResponseHandlerMutex);
	if (!ResponseHandlerMap.Contains(ResponseId))
	{
		UE_LOG(Log{{$Iface}}MQTTClient, Warning, TEXT("onInvokeReply: no handler found for correlation id %s"), *ResponseId.ToString());
		return;
	}
	ApiGear::MQTT::InvokeReplyFunc ResponseHandler = MoveTemp(ResponseHandlerMap[ResponseId]);
	ResponseHandlerMap.Remove(ResponseId);
	Lock.Unlock();

	const std::string ResultJson(reinterpret_cast<const char*>(InMsg.Payload.GetData()), InMsg.Payload.Num());
	const ApiGear::MQTT::InvokeReplyArg response{ResultJson};
	ResponseHandler(response);
}

{{- if len .Interface.Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
{{ueReturn "" .}} {{$Class}}::Get{{Camel .Name}}() const
{
	return {{ueVar "" .}};
}

{{- if not .IsReadOnly }}{{nl}}
void {{$Class}}::Set{{Camel .Name}}({{ueParam "In" .}})
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.{{$ModuleName}}.{{$IfaceName}}.MQTT.Set{{Camel .Name}}");
	if (!Connection.GetObject())
	{
		UE_LOG(Log{{$Iface}}MQTTClient, Error, TEXT("No connection for %s. Are the ApiGear {{$ModuleName}} plugin settings correct? Is the service set up correctly?"), TEXT("{{$Iface}}"));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (Get{{Camel .Name}}() == {{ueVar "In" .}})
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
{{- if not ( ueIsStdSimpleType . )}}
	if (_SentData->Get{{ueVar "" .}}() == {{ueVar "In" .}})
	{
		return;
	}
{{- else}}
	if (_SentData->{{ueVar "" .}} == {{ueVar "In" .}})
	{
		return;
	}
{{- end }}
	static const FString Topic = FString(TEXT("{{$.Module.Name}}/{{$IfaceName}}/set/{{.Name}}"));
	UApiGearMQTTClient* ApiGearMQTTClient = Cast<UApiGearMQTTClient>(Connection.GetObject());
	ApiGearMQTTClient->setRemoteProperty(Topic, UTF8_TO_TCHAR(nlohmann::json({{ueVar "In" .}}).dump().c_str()));
{{- if not ( ueIsStdSimpleType . ) }}
	_SentData->Set{{ueVar "" .}}({{ueVar "In" .}});
{{- else }}
	_SentData->{{ueVar "" .}} = {{ueVar "In" .}};
{{- end }}
}
{{- end }}

void {{$Class}}::set{{Camel .Name}}Local(const IApiGearMqttClient::FReceivedMessage& InMsg)
{
	const std::string Payload(reinterpret_cast<const char*>(InMsg.Payload.GetData()), InMsg.Payload.Num());
	nlohmann::json fields = nlohmann::json::parse(Payload);

	if (fields.empty())
	{
		return;
	}

	{{ueParam "In" .}} = fields.get<{{ueReturn "" .}}>();
	if ({{ueVar "" .}} != {{ueVar "In" .}})
	{
		{{ueVar "" .}} = {{ueVar "In" .}};
		// reset sent data to the current state
{{- if not ( ueIsStdSimpleType . )}}
		_SentData->Set{{ueVar "" .}}({{ueVar "" .}});
{{- else}}
		_SentData->{{ueVar "" .}} = {{ueVar "" .}};
{{- end }}
		TWeakObjectPtr<{{$Class}}> weak(this);
		AsyncTask(ENamedThreads::GameThread, [weak, {{ueVar "In" .}}]()
			{
			if (auto* self = weak.Get())
			{
				self->_GetPublisher()->Broadcast{{Camel .Name}}Changed({{ueVar "In" .}});
			}
		});
	}
}
{{- end }}
{{- if len .Interface.Operations }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Operations }}
{{- if $i }}{{nl}}{{ end }}
{{- if .Description }}
/**
   \brief {{.Description}}
*/
{{- end }}
{{- $returnVal := (ueReturn "" .Return)}}
{{$returnVal}} {{$Class}}::{{Camel .Name}}({{ueParams "" .Params}})
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.{{$ModuleName}}.{{$IfaceName}}.MQTT.{{Camel .Name}}");
	{{- if .Return.IsVoid }}
	if (!Connection.GetObject())
	{
		UE_LOG(Log{{$Iface}}MQTTClient, Error, TEXT("No connection for %s. Are the ApiGear {{$ModuleName}} plugin settings correct? Is the service set up correctly?"), TEXT("{{$Iface}}"));
		return;
	}

	static const FString Topic = FString(TEXT("{{$.Module.Name}}/{{$IfaceName}}/rpc/{{.Name}}"));
	UApiGearMQTTClient* ApiGearMQTTClient = Cast<UApiGearMQTTClient>(Connection.GetObject());
	ApiGearMQTTClient->invokeRemote(Topic, UTF8_TO_TCHAR(nlohmann::json::array({ {{- ueVars "" .Params -}} }).dump().c_str()));
	{{- else }}
	return {{Camel .Name}}Async({{ueVars "" .Params}}).Get();
	{{- end }}
}
{{- if not .Return.IsVoid }}{{nl}}
{{- if .Description }}
/**
   \brief {{.Description}} - Async version
*/
{{- end }}
{{- $returnVal := (ueReturn "" .Return)}}
TFuture<{{$returnVal}}> {{$Class}}::{{Camel .Name}}Async({{ueParams "" .Params}})
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.{{$ModuleName}}.{{$IfaceName}}.MQTT.{{Camel .Name}}Async");
	if (!Connection.GetObject())
	{
		UE_LOG(Log{{$Iface}}MQTTClient, Error, TEXT("No connection for %s. Are the ApiGear {{$ModuleName}} plugin settings correct? Is the service set up correctly?"), TEXT("{{$Iface}}"));

		TPromise<{{$returnVal}}> Promise;
		Promise.SetValue({{ ueDefault "" .Return }});
		return Promise.GetFuture();
	}

	TSharedRef<TPromise<{{$returnVal}}>> Promise = MakeShared<TPromise<{{$returnVal}}>>();

	ApiGear::MQTT::InvokeReplyFunc ResponseFunc = [Promise](const ApiGear::MQTT::InvokeReplyArg& args)
	{
		if (args.JsonValue.empty())
		{
			UE_LOG(Log{{$Iface}}MQTTClient, Error, TEXT("{{Camel .Name}}Async: MQTT service returned empty value - should have returned type of {{$returnVal}}"));
			Promise->SetValue({{ ueDefault "" .Return }});
			return;
		}

		nlohmann::json json_result = nlohmann::json::parse(args.JsonValue);
		Promise->SetValue(json_result.get<{{$returnVal}}>());
	};

	FGuid CorrelationId = RegisterResponseHandler(MoveTemp(ResponseFunc));

	UApiGearMQTTClient* ApiGearMQTTClient = Cast<UApiGearMQTTClient>(Connection.GetObject());
	static const FString Topic = FString(TEXT("{{$.Module.Name}}/{{$IfaceName}}/rpc/{{.Name}}"));

	const FString CorrelationStr = CorrelationId.ToString();
	TArray<uint8> CorrelationBytes;
	{
		FTCHARToUTF8 GuidUtf8(*CorrelationStr);
		CorrelationBytes.Append(reinterpret_cast<const uint8*>(GuidUtf8.Get()), GuidUtf8.Length());
	}
	const FString ResponseTopic = FString::Printf(
		TEXT("{{$.Module.Name}}/{{$IfaceName}}/rpc/{{.Name}}/%s/result"),
		*ApiGearMQTTClient->getClientId());

	const nlohmann::json ArgsJson = nlohmann::json::array({ {{- ueVars "" .Params -}} });

	ApiGearMQTTClient->invokeRemoteWithProps(Topic,
		UTF8_TO_TCHAR(ArgsJson.dump().c_str()),
		ResponseTopic, CorrelationBytes);

	return Promise->GetFuture();
}
{{- end }}
{{- end }}

{{- range .Interface.Signals }}

void {{$Class}}::on{{Camel .Name}}(const IApiGearMqttClient::FReceivedMessage& InMsg)
{
	const std::string Payload(reinterpret_cast<const char*>(InMsg.Payload.GetData()), InMsg.Payload.Num());
	nlohmann::json json_args = nlohmann::json::parse(Payload);
{{- if gt (len .Params) 0 }}

	// check for correct array size
	if (!json_args.is_array() || json_args.size() < {{len .Params}})
	{
		UE_LOG(Log{{$Iface}}MQTTClient, Error, TEXT("Signal {{.Name}}: invalid args array (expected {{len .Params}} elements)"));
		return;
	}
{{- end }}
{{- range $idx, $elem := .Params }}

	// make sure the type matches our expectation
	if (json_args[{{$idx}}].is_null(){{ " " }}
	{{- if .IsArray -}}
		|| !json_args[{{$idx}}].is_array()
	{{- else if eq .KindType "enum" -}}
		|| !json_args[{{$idx}}].is_number_integer()
	{{- else if .IsPrimitive -}}
		{{- if eq .Type "bool" -}}
		|| !json_args[{{$idx}}].is_boolean()
		{{- else if or (eq .Type "int") (eq .Type "int32") (eq .Type "int64") -}}
		|| !json_args[{{$idx}}].is_number_integer()
		{{- else if or (eq .Type "float") (eq .Type "float32") (eq .Type "float64") -}}
		|| !json_args[{{$idx}}].is_number()
		{{- else if eq .Type "string" -}}
		|| !json_args[{{$idx}}].is_string()
		{{- end }}
	{{- else -}}
		|| !json_args[{{$idx}}].is_object()
	{{- end }})
	{
		UE_LOG(Log{{$Iface}}MQTTClient, Error, TEXT("Signal {{.Name}}: invalid type for parameter {{$idx}}"));
		return;
	}
	{{ueParam "out" .}} = json_args[{{$idx}}].get<{{ueReturn "" .}}>();
{{- end }}

	TWeakObjectPtr<{{$Class}}> weak(this);
	AsyncTask(ENamedThreads::GameThread, [weak{{range .Params}}, {{ueVar "out" .}}{{end}}]()
		{
		if (auto* self = weak.Get())
		{
			self->_GetPublisher()->Broadcast{{Camel .Name}}Signal({{ueVars "out" .Params}});
		}
	});
}
{{- end }}
