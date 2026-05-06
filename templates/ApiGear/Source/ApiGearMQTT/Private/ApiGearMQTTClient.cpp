// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "ApiGearMQTTClient.h"
#include "Misc/Guid.h"
#include <functional>

DEFINE_LOG_CATEGORY(LogApiGearMQTTClient);

TScriptInterface<IApiGearConnection> MQTTFactory::Create(UObject* Outer, FString UniqueConnectionIdentifier)
{
	TScriptInterface<IApiGearConnection> MQTTConnection = NewObject<UApiGearMQTTClient>(Outer, *UniqueConnectionIdentifier);
	return MQTTConnection;
}

UApiGearMQTTClient::UApiGearMQTTClient(const FObjectInitializer& ObjectInitializer)
	: UAbstractApiGearConnection(ObjectInitializer)
{
}

UApiGearMQTTClient::~UApiGearMQTTClient()
{
	CancelAllPendingPromises();
}

void UApiGearMQTTClient::Configure(FString InServerURL, bool bInAutoReconnectEnabled)
{
	m_serverURL = InServerURL;
	SetAutoReconnectEnabled(bInAutoReconnectEnabled);

	UE_LOG(LogApiGearMQTTClient, Display, TEXT("MQTT configured with URL: %s"), *m_serverURL);
}

void UApiGearMQTTClient::SetMqttImplementation(TSharedPtr<IApiGearMqttClient> InMqttImpl)
{
	MqttImpl = InMqttImpl;

	if (MqttImpl.IsValid())
	{
		MqttImpl->OnConnectionChanged().AddLambda([this](bool bConnected)
			{
			if (bConnected)
			{
				OnConnected();
			}
			else
			{
				bool bReconnect = IsAutoReconnectEnabled();
				OnDisconnected(bReconnect);
			}
		});
	}
}

void UApiGearMQTTClient::Connect_Implementation()
{
	if (!MqttImpl.IsValid())
	{
		UE_LOG(LogApiGearMQTTClient, Error, TEXT("Cannot connect: no MQTT implementation set. Call SetMqttImplementation() first."));
		return;
	}

	MqttImpl->Connect(m_serverURL);
}

void UApiGearMQTTClient::Disconnect_Implementation()
{
	if (MqttImpl.IsValid())
	{
		MqttImpl->Disconnect();
	}
}

bool UApiGearMQTTClient::IsConnected()
{
	return MqttImpl.IsValid() && MqttImpl->IsConnected();
}

void UApiGearMQTTClient::OnConnected_Implementation()
{
	UE_LOG(LogApiGearMQTTClient, Display, TEXT("MQTT connected"));
	ResubscribeAllTopics();
	OnConnectionStatusChanged().Broadcast(true);
}

void UApiGearMQTTClient::OnDisconnected_Implementation(bool /* bReconnect */)
{
	UE_LOG(LogApiGearMQTTClient, Display, TEXT("MQTT disconnected"));
	CancelAllPendingPromises();
	OnConnectionStatusChanged().Broadcast(false);
}

FString UApiGearMQTTClient::GetUniqueEndpointIdentifier() const
{
	return GetName();
}

FString UApiGearMQTTClient::getClientId() const
{
	if (!MqttImpl.IsValid())
	{
		return TEXT("");
	}
	return MqttImpl->GetClientId();
}

void UApiGearMQTTClient::subscribeTopic(const FString& Topic, ApiGear::MQTT::FCallbackFunction Callback, IApiGearMqttClient::FSubscribeAckCallback OnSubscribed)
{
	{
		FScopeLock Lock(&TopicSubscriptionsMutex);
		TopicSubscriptions.Add(Topic, {MoveTemp(Callback), OnSubscribed});
	}

	if (MqttImpl.IsValid() && MqttImpl->IsConnected())
	{
		// Re-fetch the callback from the stored subscription
		FScopeLock Lock(&TopicSubscriptionsMutex);
		if (FTopicSubscription* Sub = TopicSubscriptions.Find(Topic))
		{
			MqttImpl->Subscribe(Topic, Sub->Callback, Sub->OnSubscribed);
		}
	}
}

void UApiGearMQTTClient::unsubscribeTopic(const TArray<FString>& Topics)
{
	{
		FScopeLock Lock(&TopicSubscriptionsMutex);
		for (const FString& Topic : Topics)
		{
			TopicSubscriptions.Remove(Topic);
		}
	}

	if (MqttImpl.IsValid() && MqttImpl->IsConnected())
	{
		MqttImpl->Unsubscribe(Topics);
	}
}

void UApiGearMQTTClient::ResubscribeAllTopics()
{
	FScopeLock Lock(&TopicSubscriptionsMutex);
	for (auto& Pair : TopicSubscriptions)
	{
		if (MqttImpl.IsValid())
		{
			MqttImpl->Subscribe(Pair.Key, Pair.Value.Callback, Pair.Value.OnSubscribed);
		}
	}
}

void UApiGearMQTTClient::invokeRemote(const FString& Topic, const FString& Payload)
{
	if (!MqttImpl.IsValid() || !MqttImpl->IsConnected())
	{
		UE_LOG(LogApiGearMQTTClient, Warning, TEXT("Cannot invoke remote: not connected"));
		return;
	}

	TArray<uint8> PayloadBytes;
	FTCHARToUTF8 Converter(*Payload);
	PayloadBytes.Append(reinterpret_cast<const uint8*>(Converter.Get()), Converter.Length());

	MqttImpl->Publish(Topic, PayloadBytes, /*Options=*/{});
}

void UApiGearMQTTClient::invokeRemoteWithProps(const FString& Topic, const FString& Payload, const FString& ResponseTopic, const TArray<uint8>& CorrelationData)
{
	if (!MqttImpl.IsValid() || !MqttImpl->IsConnected())
	{
		UE_LOG(LogApiGearMQTTClient, Warning, TEXT("Cannot invoke remote: not connected"));
		return;
	}

	TArray<uint8> PayloadBytes;
	FTCHARToUTF8 Converter(*Payload);
	PayloadBytes.Append(reinterpret_cast<const uint8*>(Converter.Get()), Converter.Length());

	IApiGearMqttClient::FPublishOptions Options;
	Options.bRetain = false;
	Options.CorrelationData = CorrelationData;
	Options.ResponseTopic = ResponseTopic;
	MqttImpl->Publish(Topic, PayloadBytes, Options);
}

void UApiGearMQTTClient::setRemoteProperty(const FString& Topic, const FString& Value)
{
	if (!MqttImpl.IsValid() || !MqttImpl->IsConnected())
	{
		UE_LOG(LogApiGearMQTTClient, Warning, TEXT("Cannot set remote property: not connected"));
		return;
	}

	TArray<uint8> PayloadBytes;
	FTCHARToUTF8 Converter(*Value);
	PayloadBytes.Append(reinterpret_cast<const uint8*>(Converter.Get()), Converter.Length());

	MqttImpl->Publish(Topic, PayloadBytes, /*Options=*/{});
}

FGuid UApiGearMQTTClient::RegisterResponseHandler(ApiGear::MQTT::InvokeReplyFunc&& Handler)
{
	FScopeLock Lock(&ResponseHandlerMutex);
	FGuid ResponseId = FGuid::NewGuid();
	ResponseHandlerMap.Add(ResponseId, MoveTemp(Handler));
	return ResponseId;
}

void UApiGearMQTTClient::RemoveResponseHandler(const FGuid& ResponseId)
{
	FScopeLock Lock(&ResponseHandlerMutex);
	ResponseHandlerMap.Remove(ResponseId);
}

void UApiGearMQTTClient::CancelAllPendingPromises()
{
	FScopeLock Lock(&ResponseHandlerMutex);
	for (auto& Pair : ResponseHandlerMap)
	{
		ApiGear::MQTT::InvokeReplyArg EmptyReply;
		Pair.Value(EmptyReply);
	}
	ResponseHandlerMap.Empty();
}
