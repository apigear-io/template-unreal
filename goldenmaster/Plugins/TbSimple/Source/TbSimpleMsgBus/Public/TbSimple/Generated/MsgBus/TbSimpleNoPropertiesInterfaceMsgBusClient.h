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

#include "TbSimple/Generated/api/AbstractTbSimpleNoPropertiesInterface.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "Templates/PimplPtr.h"
#include "IMessageContext.h"
#include "TbSimpleNoPropertiesInterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbSimpleNoPropertiesInterfaceInitMessage;
struct FTbSimpleNoPropertiesInterfacePongMessage;
struct FTbSimpleNoPropertiesInterfaceServiceDisconnectMessage;
struct FTbSimpleNoPropertiesInterfaceSigVoidSignalMessage;
struct FTbSimpleNoPropertiesInterfaceSigBoolSignalMessage;
struct FTbSimpleNoPropertiesInterfaceFuncBoolReplyMessage;

USTRUCT(BlueprintType)
struct FTbSimpleNoPropertiesInterfaceStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoPropertiesInterfaceStatsUpdatedDelegate, FTbSimpleNoPropertiesInterfaceStats, Stats);
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleNoPropertiesInterfaceMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleNoPropertiesInterfaceConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoPropertiesInterfaceConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLEMSGBUS_API UTbSimpleNoPropertiesInterfaceMsgBusClient : public UAbstractTbSimpleNoPropertiesInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleNoPropertiesInterfaceMsgBusClient();
	virtual ~UTbSimpleNoPropertiesInterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote")
	const FTbSimpleNoPropertiesInterfaceStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote", DisplayName = "Statistics Updated")
	FTbSimpleNoPropertiesInterfaceStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote", DisplayName = "Connection Status Changed")
	FTbSimpleNoPropertiesInterfaceConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbSimpleNoPropertiesInterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	// operations
	void FuncVoid() override;

	bool FuncBool(bool bParamBool) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSimpleNoPropertiesInterfaceMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbSimpleNoPropertiesInterfaceStats Stats;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	void _OnHeartbeat();
	bool _OnHeartbeatTick(float DeltaTime);
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTbSimpleNoPropertiesInterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbSimpleNoPropertiesInterfacePongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbSimpleNoPropertiesInterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigVoid(const FTbSimpleNoPropertiesInterfaceSigVoidSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigBool(const FTbSimpleNoPropertiesInterfaceSigBoolSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncBoolReply(const FTbSimpleNoPropertiesInterfaceFuncBoolReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
