/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma once

#include "Counter/Generated/api/AbstractCounterCounter.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION < 5)
#include "Engine/EngineTypes.h"
#else
#include "Engine/TimerHandle.h"
#endif
#include "Templates/PimplPtr.h"
#include "IMessageContext.h"
#include "CounterCounterMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FCounterCounterInitMessage;
struct FCounterCounterPongMessage;
struct FCounterCounterServiceDisconnectMessage;
struct FCounterCounterValueChangedSignalMessage;
struct FCounterCounterVectorChangedMessage;
struct FCounterCounterExternVectorChangedMessage;
struct FCounterCounterVectorArrayChangedMessage;
struct FCounterCounterExternVectorArrayChangedMessage;
struct FCounterCounterIncrementReplyMessage;
struct FCounterCounterIncrementArrayReplyMessage;
struct FCounterCounterDecrementReplyMessage;
struct FCounterCounterDecrementArrayReplyMessage;

USTRUCT(BlueprintType)
struct FCounterCounterStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Counter|Counter|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Counter|Counter|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Counter|Counter|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Counter|Counter|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCounterCounterStatsUpdatedDelegate, FCounterCounterStats, Stats);

struct CounterCounterPropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogCounterCounterMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FCounterCounterConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCounterCounterConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class COUNTERMSGBUS_API UCounterCounterMsgBusClient : public UAbstractCounterCounter
{
	GENERATED_BODY()
public:
	explicit UCounterCounterMsgBusClient();
	virtual ~UCounterCounterMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Remote")
	const FCounterCounterStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Remote", DisplayName = "Statistics Updated")
	FCounterCounterStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Remote", DisplayName = "Connection Status Changed")
	FCounterCounterConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FCounterCounterConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	FCustomTypesVector3D GetVector() const override;
	void SetVector(const FCustomTypesVector3D& Vector) override;

	FVector GetExternVector() const override;
	void SetExternVector(const FVector& ExternVector) override;

	TArray<FCustomTypesVector3D> GetVectorArray() const override;
	void SetVectorArray(const TArray<FCustomTypesVector3D>& VectorArray) override;

	TArray<FVector> GetExternVectorArray() const override;
	void SetExternVectorArray(const TArray<FVector>& ExternVectorArray) override;

	// operations
	FVector Increment(const FVector& Vec) override;

	TArray<FVector> IncrementArray(const TArray<FVector>& Vec) override;

	FCustomTypesVector3D Decrement(const FCustomTypesVector3D& Vec) override;

	TArray<FCustomTypesVector3D> DecrementArray(const TArray<FCustomTypesVector3D>& Vec) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> CounterCounterMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FCounterCounterStats Stats;
	FTimerHandle _HeartbeatTimerHandle;
	void _OnHeartbeat();
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FCounterCounterInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FCounterCounterPongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FCounterCounterServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnValueChanged(const FCounterCounterValueChangedSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnVectorChanged(const FCounterCounterVectorChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnExternVectorChanged(const FCounterCounterExternVectorChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnVectorArrayChanged(const FCounterCounterVectorArrayChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnExternVectorArrayChanged(const FCounterCounterExternVectorArrayChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnIncrementReply(const FCounterCounterIncrementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnIncrementArrayReply(const FCounterCounterIncrementArrayReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnDecrementReply(const FCounterCounterDecrementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnDecrementArrayReply(const FCounterCounterDecrementArrayReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<CounterCounterPropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
