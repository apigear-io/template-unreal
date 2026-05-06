// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ApiGearMQTTTypes.h"
#include "IApiGearMqttClient.h"
#include "ApiGearMQTTHost.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogApiGearMQTTHost, Log, All);

/**
 * Service-side MQTT host. Connects to a broker and publishes property changes,
 * signals, and operation responses. Subscribes to set-property and invoke requests.
 *
 * This is a plain UObject (not a subsystem) for flexibility in hosting multiple instances.
 */
UCLASS(BlueprintType)
class APIGEARMQTT_API UApiGearMQTTHost : public UObject
{
	GENERATED_BODY()
public:
	UApiGearMQTTHost() = default;
	virtual ~UApiGearMQTTHost() = default;

	/** Set the MQTT library implementation. Must be called before Start(). */
	void SetMqttImplementation(TSharedPtr<IApiGearMqttClient> InMqttImpl);

	/** Connect to a broker. */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|MQTT")
	bool Start(const FString& URL);

	/** Disconnect from the broker. */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|MQTT")
	void Stop();

	bool IsConnected() const;

	DECLARE_MULTICAST_DELEGATE_OneParam(FOnConnectionStatusChanged, bool)
		FOnConnectionStatusChanged& OnConnectionStatusChanged()
	{
		return OnConnectionStatusChangedDelegate;
	}

	void subscribeTopic(const FString& Topic, ApiGear::MQTT::FCallbackFunction Callback, IApiGearMqttClient::FSubscribeAckCallback OnSubscribed = nullptr);
	void unsubscribeTopic(const TArray<FString>& Topics);

	/** Publish a property change (retained). */
	void notifyPropertyChange(const FString& Topic, const FString& Value);
	/** Publish a signal (not retained). */
	void notifySignal(const FString& Topic, const FString& Value);
	/** Publish an operation response (not retained). */
	void notifyInvokeResponse(const FString& ResponseTopic, const FString& Value);
	/** Publish an operation response with MQTT 5 CorrelationData echoed back to the caller. */
	void notifyInvokeResponseWithCorrelation(const FString& ResponseTopic, const FString& Value, const TArray<uint8>& CorrelationData);

private:
	void ResubscribeAllTopics();

	FOnConnectionStatusChanged OnConnectionStatusChangedDelegate;
	TSharedPtr<IApiGearMqttClient> MqttImpl;
	FString m_serverURL;

	struct FTopicSubscription
	{
		ApiGear::MQTT::FCallbackFunction Callback;
		IApiGearMqttClient::FSubscribeAckCallback OnSubscribed;
	};
	TMap<FString, FTopicSubscription> TopicSubscriptions;
	FCriticalSection TopicSubscriptionsMutex;
};
