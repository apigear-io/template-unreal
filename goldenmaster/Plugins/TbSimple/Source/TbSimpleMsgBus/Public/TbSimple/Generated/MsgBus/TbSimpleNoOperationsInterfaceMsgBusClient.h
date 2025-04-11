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

#include "TbSimple/Generated/api/AbstractTbSimpleNoOperationsInterface.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "Templates/PimplPtr.h"
#include "IMessageContext.h"
#include "TbSimpleNoOperationsInterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbSimpleNoOperationsInterfaceInitMessage;
struct FTbSimpleNoOperationsInterfacePongMessage;
struct FTbSimpleNoOperationsInterfaceServiceDisconnectMessage;
struct FTbSimpleNoOperationsInterfaceSigVoidSignalMessage;
struct FTbSimpleNoOperationsInterfaceSigBoolSignalMessage;
struct FTbSimpleNoOperationsInterfacePropBoolChangedMessage;
struct FTbSimpleNoOperationsInterfacePropIntChangedMessage;

USTRUCT(BlueprintType)
struct FTbSimpleNoOperationsInterfaceStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfaceStatsUpdatedDelegate, FTbSimpleNoOperationsInterfaceStats, Stats);

struct TbSimpleNoOperationsInterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleNoOperationsInterfaceMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfaceConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfaceConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLEMSGBUS_API UTbSimpleNoOperationsInterfaceMsgBusClient : public UAbstractTbSimpleNoOperationsInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleNoOperationsInterfaceMsgBusClient();
	virtual ~UTbSimpleNoOperationsInterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote")
	const FTbSimpleNoOperationsInterfaceStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote", DisplayName = "Statistics Updated")
	FTbSimpleNoOperationsInterfaceStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote", DisplayName = "Connection Status Changed")
	FTbSimpleNoOperationsInterfaceConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbSimpleNoOperationsInterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	bool GetPropBool() const override;
	void SetPropBool(bool bPropBool) override;

	int32 GetPropInt() const override;
	void SetPropInt(int32 PropInt) override;

	// operations

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSimpleNoOperationsInterfaceMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbSimpleNoOperationsInterfaceStats Stats;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	void _OnHeartbeat();
	bool _OnHeartbeatTick(float DeltaTime);
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTbSimpleNoOperationsInterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbSimpleNoOperationsInterfacePongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbSimpleNoOperationsInterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigVoid(const FTbSimpleNoOperationsInterfaceSigVoidSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigBool(const FTbSimpleNoOperationsInterfaceSigBoolSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropBoolChanged(const FTbSimpleNoOperationsInterfacePropBoolChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropIntChanged(const FTbSimpleNoOperationsInterfacePropIntChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbSimpleNoOperationsInterfacePropertiesMsgBusData> _SentData;
};
