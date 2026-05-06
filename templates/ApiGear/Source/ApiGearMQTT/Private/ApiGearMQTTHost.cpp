// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "ApiGearMQTTHost.h"

DEFINE_LOG_CATEGORY(LogApiGearMQTTHost);

void UApiGearMQTTHost::SetMqttImplementation(TSharedPtr<IApiGearMqttClient> InMqttImpl)
{
	MqttImpl = InMqttImpl;

	if (MqttImpl.IsValid())
	{
		MqttImpl->OnConnectionChanged().AddLambda([this](bool bConnected)
			{
			if (bConnected)
			{
				UE_LOG(LogApiGearMQTTHost, Display, TEXT("MQTT host connected"));
				ResubscribeAllTopics();
			}
			else
			{
				UE_LOG(LogApiGearMQTTHost, Display, TEXT("MQTT host disconnected"));
			}
			OnConnectionStatusChanged().Broadcast(bConnected);
		});
	}
}

bool UApiGearMQTTHost::Start(const FString& URL)
{
	if (!MqttImpl.IsValid())
	{
		UE_LOG(LogApiGearMQTTHost, Error, TEXT("Cannot start: no MQTT implementation set. Call SetMqttImplementation() first."));
		return false;
	}

	m_serverURL = URL;
	MqttImpl->Connect(URL);
	return true;
}

void UApiGearMQTTHost::Stop()
{
	if (MqttImpl.IsValid())
	{
		MqttImpl->Disconnect();
	}
}

bool UApiGearMQTTHost::IsConnected() const
{
	return MqttImpl.IsValid() && MqttImpl->IsConnected();
}

void UApiGearMQTTHost::subscribeTopic(const FString& Topic, ApiGear::MQTT::FCallbackFunction Callback, IApiGearMqttClient::FSubscribeAckCallback OnSubscribed)
{
	{
		FScopeLock Lock(&TopicSubscriptionsMutex);
		TopicSubscriptions.Add(Topic, {MoveTemp(Callback), OnSubscribed});
	}

	if (MqttImpl.IsValid() && MqttImpl->IsConnected())
	{
		FScopeLock Lock(&TopicSubscriptionsMutex);
		if (FTopicSubscription* Sub = TopicSubscriptions.Find(Topic))
		{
			MqttImpl->Subscribe(Topic, Sub->Callback, Sub->OnSubscribed);
		}
	}
}

void UApiGearMQTTHost::unsubscribeTopic(const TArray<FString>& Topics)
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

void UApiGearMQTTHost::ResubscribeAllTopics()
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

void UApiGearMQTTHost::notifyPropertyChange(const FString& Topic, const FString& Value)
{
	if (!MqttImpl.IsValid() || !MqttImpl->IsConnected())
	{
		return;
	}

	TArray<uint8> PayloadBytes;
	FTCHARToUTF8 Converter(*Value);
	PayloadBytes.Append(reinterpret_cast<const uint8*>(Converter.Get()), Converter.Length());

	IApiGearMqttClient::FPublishOptions Options;
	Options.bRetain = true;
	MqttImpl->Publish(Topic, PayloadBytes, Options);
}

void UApiGearMQTTHost::notifySignal(const FString& Topic, const FString& Value)
{
	if (!MqttImpl.IsValid() || !MqttImpl->IsConnected())
	{
		return;
	}

	TArray<uint8> PayloadBytes;
	FTCHARToUTF8 Converter(*Value);
	PayloadBytes.Append(reinterpret_cast<const uint8*>(Converter.Get()), Converter.Length());

	MqttImpl->Publish(Topic, PayloadBytes, /*Options=*/{});
}

void UApiGearMQTTHost::notifyInvokeResponse(const FString& ResponseTopic, const FString& Value)
{
	if (!MqttImpl.IsValid() || !MqttImpl->IsConnected())
	{
		return;
	}

	TArray<uint8> PayloadBytes;
	FTCHARToUTF8 Converter(*Value);
	PayloadBytes.Append(reinterpret_cast<const uint8*>(Converter.Get()), Converter.Length());

	MqttImpl->Publish(ResponseTopic, PayloadBytes, /*Options=*/{});
}

void UApiGearMQTTHost::notifyInvokeResponseWithCorrelation(const FString& ResponseTopic,
	const FString& Value,
	const TArray<uint8>& CorrelationData)
{
	if (!MqttImpl.IsValid() || !MqttImpl->IsConnected())
	{
		return;
	}

	TArray<uint8> PayloadBytes;
	FTCHARToUTF8 Converter(*Value);
	PayloadBytes.Append(reinterpret_cast<const uint8*>(Converter.Get()), Converter.Length());

	IApiGearMqttClient::FPublishOptions Options;
	Options.bRetain = false;
	Options.CorrelationData = CorrelationData;
	MqttImpl->Publish(ResponseTopic, PayloadBytes, Options);
}
