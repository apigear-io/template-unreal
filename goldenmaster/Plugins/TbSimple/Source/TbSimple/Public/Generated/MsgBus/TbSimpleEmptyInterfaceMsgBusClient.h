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

#include "Generated/api/AbstractTbSimpleEmptyInterface.h"
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
#include "TbSimpleEmptyInterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbSimpleEmptyInterfaceInitMessage;
struct FTbSimpleEmptyInterfacePongMessage;
struct FTbSimpleEmptyInterfaceServiceDisconnectMessage;

USTRUCT(BlueprintType)
struct FTbSimpleEmptyInterfaceStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|EmptyInterface|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|EmptyInterface|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|EmptyInterface|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|EmptyInterface|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleEmptyInterfaceStatsUpdatedDelegate, FTbSimpleEmptyInterfaceStats, Stats);
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleEmptyInterfaceMsgBusClient, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleEmptyInterfaceConnectionStatusChangedDelegate, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLE_API UTbSimpleEmptyInterfaceMsgBusClient : public UAbstractTbSimpleEmptyInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleEmptyInterfaceMsgBusClient();
	virtual ~UTbSimpleEmptyInterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|EmptyInterface|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|EmptyInterface|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|EmptyInterface|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|EmptyInterface|Remote")
	const FTbSimpleEmptyInterfaceStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|EmptyInterface|Remote", DisplayName = "Statistics Updated")
	FTbSimpleEmptyInterfaceStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|EmptyInterface|Remote", DisplayName = "Connection Status Changed")
	FTbSimpleEmptyInterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	// operations

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSimpleEmptyInterfaceMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbSimpleEmptyInterfaceStats Stats;
	FTimerHandle _HeartbeatTimerHandle;
	void _OnHeartbeat();
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTbSimpleEmptyInterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbSimpleEmptyInterfacePongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbSimpleEmptyInterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
};
