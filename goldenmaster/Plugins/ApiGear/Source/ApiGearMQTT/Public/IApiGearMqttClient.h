// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#pragma once

#include "CoreMinimal.h"
#include "Delegates/Delegate.h"

/**
 * Abstract MQTT client interface.
 * Implement this interface to adapt any MQTT library (Mqttify, MQTTCore, Paho, etc.)
 * for use with the ApiGear MQTT transport layer.
 */
class APIGEARMQTT_API IApiGearMqttClient
{
public:
	virtual ~IApiGearMqttClient() = default;

	virtual void Connect(const FString& URL) = 0;
	virtual void Disconnect() = 0;
	virtual bool IsConnected() const = 0;
	virtual FString GetClientId() const = 0;

	/**
	 * Wraps an inbound message with optional MQTT 5 properties.
	 * For MQTT 3.1.1 backends, CorrelationData and ResponseTopic are empty.
	 */
	struct FReceivedMessage
	{
		TArray<uint8> Payload;
		TArray<uint8> CorrelationData;
		FString ResponseTopic;
	};

	using FMessageCallback = TFunction<void(const FReceivedMessage& Message)>;
	using FSubscribeAckCallback = TFunction<void(bool bSuccess)>;

	/**
	 * Subscribe to a topic.
	 * @param Topic The MQTT topic to subscribe to.
	 * @param OnMessage Callback invoked when a message is received on this topic. May be called on any thread.
	 * @param OnSubscribed Optional callback invoked when the broker acknowledges the subscription.
	 */
	virtual void Subscribe(const FString& Topic, FMessageCallback OnMessage, FSubscribeAckCallback OnSubscribed = nullptr) = 0;
	virtual void Unsubscribe(const TArray<FString>& Topics) = 0;

	/**
	 * MQTT publish options. MQTT 5 backends propagate CorrelationData and
	 * ResponseTopic; MQTT 3.1.1 backends ignore them.
	 */
	struct FPublishOptions
	{
		bool bRetain;
		TArray<uint8> CorrelationData;
		FString ResponseTopic;
	};

	virtual void Publish(const FString& Topic, const TArray<uint8>& Payload, const FPublishOptions& Options) = 0;

	DECLARE_MULTICAST_DELEGATE_OneParam(FOnConnectionChanged, bool);
	virtual FOnConnectionChanged& OnConnectionChanged() = 0;
};
