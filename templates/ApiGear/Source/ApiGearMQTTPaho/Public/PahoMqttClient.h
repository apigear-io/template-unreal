// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#pragma once

#include "IApiGearMqttClient.h"
#include "CoreMinimal.h"
#include <atomic>

THIRD_PARTY_INCLUDES_START
#include "MQTTAsync.h"
THIRD_PARTY_INCLUDES_END

DECLARE_LOG_CATEGORY_EXTERN(LogPahoMqttClient, Log, All);

class APIGEARMQTTPAHO_API FPahoMqttClient : public IApiGearMqttClient
{
public:
	FPahoMqttClient();
	virtual ~FPahoMqttClient() override;

	void Connect(const FString& URL) override;
	void Disconnect() override;
	bool IsConnected() const override;
	FString GetClientId() const override;

	void Subscribe(const FString& Topic, FMessageCallback OnMessage, FSubscribeAckCallback OnSubscribed) override;
	void Unsubscribe(const TArray<FString>& Topics) override;
	void Publish(const FString& Topic, const TArray<uint8>& Payload, const FPublishOptions& Options) override;

	FOnConnectionChanged& OnConnectionChanged() override;

private:
	static void OnConnectSuccess5(void* Context, MQTTAsync_successData5* Response);
	static void OnConnectFailure5(void* Context, MQTTAsync_failureData5* Response);
	static void OnConnectionLost(void* Context, char* Cause);
	static int OnMessageArrived(void* Context, char* TopicName, int TopicLen, MQTTAsync_message* Message);
	static void OnSubscribeSuccess5(void* Context, MQTTAsync_successData5* Response);
	static void OnSubscribeFailure5(void* Context, MQTTAsync_failureData5* Response);
	static void OnDisconnectComplete5(void* Context, MQTTAsync_successData5* Response);

	void DispatchConnectionChanged(bool bConnected);

	MQTTAsync Handle;
	FString ClientId;
	std::atomic<bool> bDestroying{false};
	TSharedPtr<std::atomic<bool>> AliveFlag;

	struct FSubscriptionEntry
	{
		FMessageCallback OnMessage;
		FSubscribeAckCallback OnSubscribed;
	};

	mutable FCriticalSection SubscriptionsMutex;
	TMap<FString, FSubscriptionEntry> Subscriptions;

	mutable FCriticalSection PendingTokensMutex;
	TMap<int, FString> PendingSubscribeTokens;

	FOnConnectionChanged OnConnectionChangedDelegate;
};
