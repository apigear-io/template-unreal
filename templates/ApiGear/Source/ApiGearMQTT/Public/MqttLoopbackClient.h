// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#pragma once

#include "IApiGearMqttClient.h"
#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "Misc/Guid.h"

/**
 * In-process MQTT broker for testing. Routes publishes directly to subscribers.
 * NOT thread-safe — designed for single-threaded test use only.
 */
class FMqttLoopbackBroker
{
public:
	using FMessageCallback = IApiGearMqttClient::FMessageCallback;

	struct FSubscription
	{
		FMessageCallback Callback;
	};

	void Subscribe(const FString& Topic, FMessageCallback Callback, IApiGearMqttClient::FSubscribeAckCallback OnSubscribed)
	{
		Subscriptions.FindOrAdd(Topic).Add({MoveTemp(Callback)});

		// deliver retained message if any (before ack, per MQTT spec)
		if (const TArray<uint8>* Retained = RetainedMessages.Find(Topic))
		{
			IApiGearMqttClient::FReceivedMessage Msg;
			Msg.Payload = *Retained;
			if (const IApiGearMqttClient::FPublishOptions* RetainedOpts = RetainedOptions.Find(Topic))
			{
				Msg.CorrelationData = RetainedOpts->CorrelationData;
				Msg.ResponseTopic = RetainedOpts->ResponseTopic;
			}
			Subscriptions[Topic].Last().Callback(Msg);
		}

		// acknowledge subscription
		if (OnSubscribed)
		{
			OnSubscribed(true);
		}
	}

	void Unsubscribe(const TArray<FString>& Topics)
	{
		for (const FString& Topic : Topics)
		{
			Subscriptions.Remove(Topic);
		}
	}

	void Publish(const FString& Topic, const TArray<uint8>& Payload, const IApiGearMqttClient::FPublishOptions& Options)
	{
		if (Options.bRetain)
		{
			RetainedMessages.Add(Topic, Payload);
			RetainedOptions.Add(Topic, Options);
		}

		if (TArray<FSubscription>* Subs = Subscriptions.Find(Topic))
		{
			IApiGearMqttClient::FReceivedMessage Msg;
			Msg.Payload = Payload;
			Msg.CorrelationData = Options.CorrelationData;
			Msg.ResponseTopic = Options.ResponseTopic;
			for (FSubscription& Sub : *Subs)
			{
				Sub.Callback(Msg);
			}
		}
	}

	void Reset()
	{
		Subscriptions.Empty();
		RetainedMessages.Empty();
		RetainedOptions.Empty();
	}

private:
	TMap<FString, TArray<FSubscription>> Subscriptions;
	TMap<FString, TArray<uint8>> RetainedMessages;
	TMap<FString, IApiGearMqttClient::FPublishOptions> RetainedOptions;
};

/**
 * In-process IApiGearMqttClient implementation for testing.
 * Routes all publishes through a shared FMqttLoopbackBroker.
 * NOT thread-safe — designed for single-threaded test use only.
 */
class FMqttLoopbackClient : public IApiGearMqttClient
{
public:
	FMqttLoopbackClient(TSharedPtr<FMqttLoopbackBroker> InBroker, const FString& InClientId)
		: Broker(InBroker)
		, ClientId(InClientId)
		, bConnected(false)
	{
	}

	virtual void Connect(const FString& /* URL */) override
	{
		bConnected = true;
		OnConnectionChangedDelegate.Broadcast(true);
	}

	virtual void Disconnect() override
	{
		bConnected = false;
		OnConnectionChangedDelegate.Broadcast(false);
	}

	virtual bool IsConnected() const override
	{
		return bConnected;
	}

	virtual FString GetClientId() const override
	{
		return ClientId;
	}

	virtual void Subscribe(const FString& Topic, FMessageCallback OnMessage, FSubscribeAckCallback OnSubscribed) override
	{
		if (Broker.IsValid())
		{
			Broker->Subscribe(Topic, MoveTemp(OnMessage), MoveTemp(OnSubscribed));
		}
	}

	virtual void Unsubscribe(const TArray<FString>& Topics) override
	{
		if (Broker.IsValid())
		{
			Broker->Unsubscribe(Topics);
		}
	}

	virtual void Publish(const FString& Topic, const TArray<uint8>& Payload, const FPublishOptions& Options) override
	{
		if (Broker.IsValid())
		{
			Broker->Publish(Topic, Payload, Options);
		}
	}

	virtual FOnConnectionChanged& OnConnectionChanged() override
	{
		return OnConnectionChangedDelegate;
	}

private:
	TSharedPtr<FMqttLoopbackBroker> Broker;
	FString ClientId;
	bool bConnected;
	FOnConnectionChanged OnConnectionChangedDelegate;
};
