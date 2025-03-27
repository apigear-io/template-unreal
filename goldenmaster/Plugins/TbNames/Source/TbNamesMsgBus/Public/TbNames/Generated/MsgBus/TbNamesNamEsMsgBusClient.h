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

#include "TbNames/Generated/api/AbstractTbNamesNamEs.h"
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
#include "TbNamesNamEsMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbNamesNamEsInitMessage;
struct FTbNamesNamEsPongMessage;
struct FTbNamesNamEsServiceDisconnectMessage;
struct FTbNamesNamEsSomeSignalSignalMessage;
struct FTbNamesNamEsSomeSignal2SignalMessage;
struct FTbNamesNamEsSwitchChangedMessage;
struct FTbNamesNamEsSomePropertyChangedMessage;
struct FTbNamesNamEsSomePoperty2ChangedMessage;

USTRUCT(BlueprintType)
struct FTbNamesNamEsStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbNames|NamEs|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbNames|NamEs|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbNames|NamEs|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbNames|NamEs|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsStatsUpdatedDelegate, FTbNamesNamEsStats, Stats);

struct TbNamesNamEsPropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbNamesNamEsMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBNAMESMSGBUS_API UTbNamesNamEsMsgBusClient : public UAbstractTbNamesNamEs
{
	GENERATED_BODY()
public:
	explicit UTbNamesNamEsMsgBusClient();
	virtual ~UTbNamesNamEsMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Remote")
	const FTbNamesNamEsStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Remote", DisplayName = "Statistics Updated")
	FTbNamesNamEsStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Remote", DisplayName = "Connection Status Changed")
	FTbNamesNamEsConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbNamesNamEsConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	bool GetSwitch() const override;
	void SetSwitch(bool bSwitch) override;

	int32 GetSomeProperty() const override;
	void SetSomeProperty(int32 SomeProperty) override;

	int32 GetSomePoperty2() const override;
	void SetSomePoperty2(int32 SomePoperty2) override;

	// operations
	void SomeFunction(bool bSomeParam) override;

	void SomeFunction2(bool bSomeParam) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbNamesNamEsMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbNamesNamEsStats Stats;
	FTimerHandle _HeartbeatTimerHandle;
	void _OnHeartbeat();
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTbNamesNamEsInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbNamesNamEsPongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbNamesNamEsServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSomeSignal(const FTbNamesNamEsSomeSignalSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSomeSignal2(const FTbNamesNamEsSomeSignal2SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSwitchChanged(const FTbNamesNamEsSwitchChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSomePropertyChanged(const FTbNamesNamEsSomePropertyChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSomePoperty2Changed(const FTbNamesNamEsSomePoperty2ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbNamesNamEsPropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
