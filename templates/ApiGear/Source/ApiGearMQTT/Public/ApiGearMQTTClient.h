// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#pragma once

#include "AbstractApiGearConnection.h"
#include "apigearmqtt.h"
#include "ApiGearMQTTTypes.h"
#include "IApiGearMqttClient.h"
#include "Misc/Guid.h"
#include "ApiGearMQTTClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogApiGearMQTTClient, Log, All);

class APIGEARMQTT_API MQTTFactory
{
public:
	static TScriptInterface<IApiGearConnection> Create(UObject* Outer, FString UniqueConnectionIdentifier);
};

UCLASS(BlueprintType, Displayname = "ApiGear MQTT Connection", Category = "ApiGear|Connection")
class APIGEARMQTT_API UApiGearMQTTClient final : public UAbstractApiGearConnection
{
	GENERATED_BODY()
public:
	explicit UApiGearMQTTClient(const FObjectInitializer& ObjectInitializer);
	virtual ~UApiGearMQTTClient();

	void Configure(FString InServerURL, bool bInAutoReconnectEnabled) override;

	// UAbstractApiGearConnection
	void Connect_Implementation() final;
	void Disconnect_Implementation() final;
	void OnConnected_Implementation() final;
	void OnDisconnected_Implementation(bool bReconnect) final;
	bool IsConnected() override;

	FString GetUniqueEndpointIdentifier() const override;
	FString GetConnectionProtocolIdentifier() const override
	{
		return ApiGearMQTTProtocolIdentifier;
	}

	FString GetServerURL() const override
	{
		return m_serverURL;
	}

	/** Set the MQTT library implementation. Must be called before Connect(). */
	void SetMqttImplementation(TSharedPtr<IApiGearMqttClient> InMqttImpl);

	DECLARE_MULTICAST_DELEGATE_OneParam(FOnConnectionStatusChanged, bool)
		FOnConnectionStatusChanged& OnConnectionStatusChanged()
	{
		return OnConnectionStatusChangedDelegate;
	}

	// MQTT operations used by generated per-interface clients
	void subscribeTopic(const FString& Topic, ApiGear::MQTT::FCallbackFunction Callback, IApiGearMqttClient::FSubscribeAckCallback OnSubscribed = nullptr);
	void unsubscribeTopic(const TArray<FString>& Topics);

	void invokeRemote(const FString& Topic, const FString& Payload);
	void invokeRemoteWithProps(const FString& Topic, const FString& Payload, const FString& ResponseTopic, const TArray<uint8>& CorrelationData);
	void setRemoteProperty(const FString& Topic, const FString& Value);

	FGuid RegisterResponseHandler(ApiGear::MQTT::InvokeReplyFunc&& Handler);
	void RemoveResponseHandler(const FGuid& ResponseId);
	void CancelAllPendingPromises();

	FString getClientId() const;

private:
	void ResubscribeAllTopics();

	FOnConnectionStatusChanged OnConnectionStatusChangedDelegate;

	FString m_serverURL;
	TSharedPtr<IApiGearMqttClient> MqttImpl;

	struct FTopicSubscription
	{
		ApiGear::MQTT::FCallbackFunction Callback;
		IApiGearMqttClient::FSubscribeAckCallback OnSubscribed;
	};
	TMap<FString, FTopicSubscription> TopicSubscriptions;
	FCriticalSection TopicSubscriptionsMutex;

	TMap<FGuid, ApiGear::MQTT::InvokeReplyFunc> ResponseHandlerMap;
	FCriticalSection ResponseHandlerMutex;
};
