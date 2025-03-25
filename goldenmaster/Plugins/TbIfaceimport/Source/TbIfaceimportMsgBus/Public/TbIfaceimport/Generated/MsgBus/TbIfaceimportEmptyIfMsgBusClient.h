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

#include "TbIfaceimport/Generated/api/AbstractTbIfaceimportEmptyIf.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "Templates/PimplPtr.h"
#include "IMessageContext.h"
#include "TbIfaceimportEmptyIfMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbIfaceimportEmptyIfInitMessage;
struct FTbIfaceimportEmptyIfPongMessage;
struct FTbIfaceimportEmptyIfServiceDisconnectMessage;

USTRUCT(BlueprintType)
struct FTbIfaceimportEmptyIfStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbIfaceimportEmptyIfStatsUpdatedDelegate, FTbIfaceimportEmptyIfStats, Stats);
DECLARE_LOG_CATEGORY_EXTERN(LogTbIfaceimportEmptyIfMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbIfaceimportEmptyIfConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbIfaceimportEmptyIfConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBIFACEIMPORTMSGBUS_API UTbIfaceimportEmptyIfMsgBusClient : public UAbstractTbIfaceimportEmptyIf
{
	GENERATED_BODY()
public:
	explicit UTbIfaceimportEmptyIfMsgBusClient();
	virtual ~UTbIfaceimportEmptyIfMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote")
	const FTbIfaceimportEmptyIfStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote", DisplayName = "Statistics Updated")
	FTbIfaceimportEmptyIfStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote", DisplayName = "Connection Status Changed")
	FTbIfaceimportEmptyIfConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbIfaceimportEmptyIfConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	// operations

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbIfaceimportEmptyIfMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbIfaceimportEmptyIfStats Stats;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	void _OnHeartbeat();
	bool _OnHeartbeatTick(float DeltaTime);
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTbIfaceimportEmptyIfInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbIfaceimportEmptyIfPongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbIfaceimportEmptyIfServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
};
