// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "PahoMqttClient.h"
#include "Async/Async.h"
#include "Misc/Guid.h"
#include <string>

DEFINE_LOG_CATEGORY(LogPahoMqttClient);

FPahoMqttClient::FPahoMqttClient()
	: Handle(nullptr)
	, ClientId(FGuid::NewGuid().ToString())
	, AliveFlag(MakeShared<std::atomic<bool>>(true))
{
}

FPahoMqttClient::~FPahoMqttClient()
{
	bDestroying.store(true);
	AliveFlag->store(false);

	if (Handle)
	{
		if (MQTTAsync_isConnected(Handle))
		{
			MQTTAsync_disconnectOptions Opts = MQTTAsync_disconnectOptions_initializer;
			Opts.timeout = 1000;
			MQTTAsync_disconnect(Handle, &Opts);

			int WaitMs = 0;
			while (MQTTAsync_isConnected(Handle) && WaitMs < 2000)
			{
				FPlatformProcess::Sleep(0.01f);
				WaitMs += 10;
			}
		}

		MQTTAsync_destroy(&Handle);
		Handle = nullptr;
	}
}

void FPahoMqttClient::Connect(const FString& URL)
{
	if (Handle)
	{
		MQTTAsync_destroy(&Handle);
		Handle = nullptr;
	}

	const std::string ServerUri = TCHAR_TO_UTF8(*URL);
	const std::string ClientIdStr = TCHAR_TO_UTF8(*ClientId);

	MQTTAsync_createOptions CreateOpts = MQTTAsync_createOptions_initializer5;
	CreateOpts.MQTTVersion = MQTTVERSION_5;
	int rc = MQTTAsync_createWithOptions(&Handle, ServerUri.c_str(), ClientIdStr.c_str(),
		MQTTCLIENT_PERSISTENCE_NONE, nullptr, &CreateOpts);
	if (rc != MQTTASYNC_SUCCESS)
	{
		UE_LOG(LogPahoMqttClient, Error, TEXT("MQTTAsync_createWithOptions failed: %d"), rc);
		DispatchConnectionChanged(false);
		return;
	}

	rc = MQTTAsync_setCallbacks(Handle, this, OnConnectionLost, OnMessageArrived, nullptr);
	if (rc != MQTTASYNC_SUCCESS)
	{
		UE_LOG(LogPahoMqttClient, Error, TEXT("MQTTAsync_setCallbacks failed: %d"), rc);
		DispatchConnectionChanged(false);
		return;
	}

	MQTTAsync_connectOptions ConnOpts = MQTTAsync_connectOptions_initializer5;
	ConnOpts.keepAliveInterval = 20;
	ConnOpts.cleanstart = 1;
	ConnOpts.onSuccess5 = OnConnectSuccess5;
	ConnOpts.onFailure5 = OnConnectFailure5;
	ConnOpts.context = this;
	ConnOpts.MQTTVersion = MQTTVERSION_5;
	ConnOpts.automaticReconnect = 0;

	MQTTAsync_SSLOptions SslOpts = MQTTAsync_SSLOptions_initializer;
	bool bUseSsl = URL.StartsWith(TEXT("ssl://")) || URL.StartsWith(TEXT("mqtts://"));
	if (bUseSsl)
	{
		SslOpts.verify = 1;
		ConnOpts.ssl = &SslOpts;
	}

	rc = MQTTAsync_connect(Handle, &ConnOpts);
	if (rc != MQTTASYNC_SUCCESS)
	{
		UE_LOG(LogPahoMqttClient, Error, TEXT("MQTTAsync_connect failed: %d (URL: %s)"), rc, *URL);
		DispatchConnectionChanged(false);
	}
}

void FPahoMqttClient::Disconnect()
{
	if (!Handle || !MQTTAsync_isConnected(Handle))
	{
		return;
	}

	MQTTAsync_disconnectOptions Opts = MQTTAsync_disconnectOptions_initializer;
	Opts.onSuccess5 = OnDisconnectComplete5;
	Opts.context = this;
	Opts.timeout = 1000;

	int rc = MQTTAsync_disconnect(Handle, &Opts);
	if (rc != MQTTASYNC_SUCCESS)
	{
		UE_LOG(LogPahoMqttClient, Warning, TEXT("MQTTAsync_disconnect failed: %d"), rc);
		DispatchConnectionChanged(false);
	}
}

bool FPahoMqttClient::IsConnected() const
{
	return Handle && MQTTAsync_isConnected(Handle);
}

FString FPahoMqttClient::GetClientId() const
{
	return ClientId;
}

void FPahoMqttClient::Subscribe(const FString& Topic, FMessageCallback OnMessage, FSubscribeAckCallback OnSubscribed)
{
	{
		FScopeLock Lock(&SubscriptionsMutex);
		Subscriptions.Add(Topic, {MoveTemp(OnMessage), MoveTemp(OnSubscribed)});
	}

	if (!Handle || !MQTTAsync_isConnected(Handle))
	{
		return;
	}

	// Paho v5 rejects v3 callbacks (onSuccess/onFailure) with MQTTASYNC_BAD_MQTT_OPTION (-15).
	// The connection is always created with MQTTVERSION_5 — use the v5 callbacks.
	MQTTAsync_responseOptions Opts = MQTTAsync_responseOptions_initializer;
	Opts.onSuccess5 = OnSubscribeSuccess5;
	Opts.onFailure5 = OnSubscribeFailure5;
	Opts.context = this;

	int rc = MQTTAsync_subscribe(Handle, TCHAR_TO_UTF8(*Topic), /*QoS=*/1, &Opts);
	if (rc == MQTTASYNC_SUCCESS)
	{
		FScopeLock Lock(&PendingTokensMutex);
		PendingSubscribeTokens.Add(Opts.token, Topic);
	}
	else
	{
		UE_LOG(LogPahoMqttClient, Warning, TEXT("MQTTAsync_subscribe failed for topic '%s': %d"), *Topic, rc);
		FScopeLock Lock(&SubscriptionsMutex);
		if (FSubscriptionEntry* Entry = Subscriptions.Find(Topic))
		{
			if (Entry->OnSubscribed)
			{
				Entry->OnSubscribed(false);
			}
		}
	}
}

void FPahoMqttClient::Unsubscribe(const TArray<FString>& Topics)
{
	{
		FScopeLock Lock(&SubscriptionsMutex);
		for (const FString& Topic : Topics)
		{
			Subscriptions.Remove(Topic);
		}
	}

	if (!Handle || !MQTTAsync_isConnected(Handle))
	{
		return;
	}

	for (const FString& Topic : Topics)
	{
		MQTTAsync_responseOptions Opts = MQTTAsync_responseOptions_initializer;
		MQTTAsync_unsubscribe(Handle, TCHAR_TO_UTF8(*Topic), &Opts);
	}
}

void FPahoMqttClient::Publish(const FString& Topic, const TArray<uint8>& Payload, const FPublishOptions& Options)
{
	if (!Handle || !MQTTAsync_isConnected(Handle))
	{
		return;
	}

	MQTTAsync_message Msg = MQTTAsync_message_initializer;
	Msg.payload = const_cast<uint8*>(Payload.GetData());
	Msg.payloadlen = Payload.Num();
	Msg.qos = 1;
	Msg.retained = Options.bRetain ? 1 : 0;

	if (Options.CorrelationData.Num() > 0)
	{
		MQTTProperty Prop;
		Prop.identifier = MQTTPROPERTY_CODE_CORRELATION_DATA;
		Prop.value.data.len = Options.CorrelationData.Num();
		Prop.value.data.data = reinterpret_cast<char*>(
			const_cast<uint8*>(Options.CorrelationData.GetData()));
		MQTTProperties_add(&Msg.properties, &Prop);
	}

	FTCHARToUTF8 RespTopicUtf8(*Options.ResponseTopic);
	if (Options.ResponseTopic.Len() > 0)
	{
		MQTTProperty Prop;
		Prop.identifier = MQTTPROPERTY_CODE_RESPONSE_TOPIC;
		Prop.value.data.len = RespTopicUtf8.Length();
		Prop.value.data.data = const_cast<char*>(RespTopicUtf8.Get());
		MQTTProperties_add(&Msg.properties, &Prop);
	}

	MQTTAsync_responseOptions Opts = MQTTAsync_responseOptions_initializer;
	int rc = MQTTAsync_sendMessage(Handle, TCHAR_TO_UTF8(*Topic), &Msg, &Opts);

	MQTTProperties_free(&Msg.properties);

	if (rc != MQTTASYNC_SUCCESS)
	{
		UE_LOG(LogPahoMqttClient, Warning, TEXT("MQTTAsync_sendMessage failed for topic '%s': %d"), *Topic, rc);
	}
}

IApiGearMqttClient::FOnConnectionChanged& FPahoMqttClient::OnConnectionChanged()
{
	return OnConnectionChangedDelegate;
}

void FPahoMqttClient::OnConnectSuccess5(void* Context, MQTTAsync_successData5* /*Response*/)
{
	FPahoMqttClient* Self = static_cast<FPahoMqttClient*>(Context);
	if (Self->bDestroying.load())
	{
		return;
	}
	UE_LOG(LogPahoMqttClient, Display, TEXT("Paho MQTT 5 connected"));
	Self->DispatchConnectionChanged(true);
}

void FPahoMqttClient::OnConnectFailure5(void* Context, MQTTAsync_failureData5* Response)
{
	FPahoMqttClient* Self = static_cast<FPahoMqttClient*>(Context);
	if (Self->bDestroying.load())
	{
		return;
	}
	int Code = Response ? static_cast<int>(Response->code) : -1;
	const char* Msg = (Response && Response->message) ? Response->message : "unknown";
	UE_LOG(LogPahoMqttClient, Error, TEXT("Paho MQTT 5 connect failed: %d (%hs)"), Code, Msg);
	Self->DispatchConnectionChanged(false);
}

void FPahoMqttClient::OnConnectionLost(void* Context, char* Cause)
{
	FPahoMqttClient* Self = static_cast<FPahoMqttClient*>(Context);
	if (Self->bDestroying.load())
	{
		return;
	}
	UE_LOG(LogPahoMqttClient, Warning, TEXT("Paho MQTT connection lost: %hs"),
		Cause ? Cause : "unknown");
	Self->DispatchConnectionChanged(false);
}

int FPahoMqttClient::OnMessageArrived(void* Context, char* TopicName, int TopicLen, MQTTAsync_message* Message)
{
	FPahoMqttClient* Self = static_cast<FPahoMqttClient*>(Context);
	if (Self->bDestroying.load())
	{
		MQTTAsync_freeMessage(&Message);
		MQTTAsync_free(TopicName);
		return 1;
	}

	FString Topic = (TopicLen > 0)
						? FString(TopicLen, UTF8_TO_TCHAR(TopicName))
						: FString(UTF8_TO_TCHAR(TopicName));

	TArray<uint8> Payload;
	if (Message->payloadlen > 0)
	{
		Payload.Append(static_cast<const uint8*>(Message->payload), Message->payloadlen);
	}

	IApiGearMqttClient::FReceivedMessage Msg;
	Msg.Payload = MoveTemp(Payload);

	if (Message->properties.count > 0)
	{
		if (MQTTProperty* CorrProp = MQTTProperties_getProperty(
				&Message->properties, MQTTPROPERTY_CODE_CORRELATION_DATA))
		{
			const uint8* DataPtr = reinterpret_cast<const uint8*>(CorrProp->value.data.data);
			Msg.CorrelationData.Append(DataPtr, CorrProp->value.data.len);
		}
		if (MQTTProperty* RespProp = MQTTProperties_getProperty(
				&Message->properties, MQTTPROPERTY_CODE_RESPONSE_TOPIC))
		{
			Msg.ResponseTopic = FString(RespProp->value.data.len,
				UTF8_TO_TCHAR(RespProp->value.data.data));
		}
	}

	MQTTAsync_freeMessage(&Message);
	MQTTAsync_free(TopicName);

	FMessageCallback CallbackCopy;
	{
		FScopeLock Lock(&Self->SubscriptionsMutex);
		if (FSubscriptionEntry* Entry = Self->Subscriptions.Find(Topic))
		{
			CallbackCopy = Entry->OnMessage;
		}
	}

	if (CallbackCopy)
	{
		CallbackCopy(Msg);
	}

	return 1;
}

void FPahoMqttClient::OnSubscribeSuccess5(void* Context, MQTTAsync_successData5* Response)
{
	FPahoMqttClient* Self = static_cast<FPahoMqttClient*>(Context);
	if (Self->bDestroying.load() || !Response)
	{
		return;
	}

	FString Topic;
	FSubscribeAckCallback AckCallback;
	{
		FScopeLock Lock(&Self->PendingTokensMutex);
		if (FString* FoundTopic = Self->PendingSubscribeTokens.Find(Response->token))
		{
			Topic = *FoundTopic;
			Self->PendingSubscribeTokens.Remove(Response->token);
		}
	}

	if (!Topic.IsEmpty())
	{
		FScopeLock Lock(&Self->SubscriptionsMutex);
		if (FSubscriptionEntry* Entry = Self->Subscriptions.Find(Topic))
		{
			AckCallback = Entry->OnSubscribed;
		}
	}

	if (AckCallback)
	{
		AckCallback(true);
	}
}

void FPahoMqttClient::OnSubscribeFailure5(void* Context, MQTTAsync_failureData5* Response)
{
	FPahoMqttClient* Self = static_cast<FPahoMqttClient*>(Context);
	if (Self->bDestroying.load() || !Response)
	{
		return;
	}

	FString Topic;
	FSubscribeAckCallback AckCallback;
	{
		FScopeLock Lock(&Self->PendingTokensMutex);
		if (FString* FoundTopic = Self->PendingSubscribeTokens.Find(Response->token))
		{
			Topic = *FoundTopic;
			Self->PendingSubscribeTokens.Remove(Response->token);
		}
	}

	if (!Topic.IsEmpty())
	{
		UE_LOG(LogPahoMqttClient, Warning, TEXT("Subscribe failed for topic '%s': %d"), *Topic,
			static_cast<int>(Response->code));

		FScopeLock Lock(&Self->SubscriptionsMutex);
		if (FSubscriptionEntry* Entry = Self->Subscriptions.Find(Topic))
		{
			AckCallback = Entry->OnSubscribed;
		}
	}

	if (AckCallback)
	{
		AckCallback(false);
	}
}

void FPahoMqttClient::OnDisconnectComplete5(void* Context, MQTTAsync_successData5* /*Response*/)
{
	FPahoMqttClient* Self = static_cast<FPahoMqttClient*>(Context);
	if (Self->bDestroying.load())
	{
		return;
	}
	UE_LOG(LogPahoMqttClient, Display, TEXT("Paho MQTT disconnected"));
	Self->DispatchConnectionChanged(false);
}

void FPahoMqttClient::DispatchConnectionChanged(bool bConnected)
{
	TSharedPtr<std::atomic<bool>> Flag = AliveFlag;
	AsyncTask(ENamedThreads::GameThread, [Flag, this, bConnected]()
		{
		if (Flag->load())
		{
			OnConnectionChangedDelegate.Broadcast(bConnected);
		}
	});
}
