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

#include "TbSame2/Generated/api/AbstractTbSame2SameStruct1Interface.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "Templates/PimplPtr.h"
#include "IMessageContext.h"
#include "TbSame2SameStruct1InterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbSame2SameStruct1InterfaceInitMessage;
struct FTbSame2SameStruct1InterfacePongMessage;
struct FTbSame2SameStruct1InterfaceServiceDisconnectMessage;
struct FTbSame2SameStruct1InterfaceSig1SignalMessage;
struct FTbSame2SameStruct1InterfaceProp1ChangedMessage;
struct FTbSame2SameStruct1InterfaceFunc1ReplyMessage;

USTRUCT(BlueprintType)
struct FTbSame2SameStruct1InterfaceStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame2|SameStruct1Interface|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame2|SameStruct1Interface|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame2|SameStruct1Interface|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame2|SameStruct1Interface|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct1InterfaceStatsUpdatedDelegate, FTbSame2SameStruct1InterfaceStats, Stats);

class TbSame2SameStruct1InterfacePropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbSame2SameStruct1InterfaceMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct1InterfaceConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct1InterfaceConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME2MSGBUS_API UTbSame2SameStruct1InterfaceMsgBusClient : public UAbstractTbSame2SameStruct1Interface
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameStruct1InterfaceMsgBusClient();
	virtual ~UTbSame2SameStruct1InterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Remote")
	const FTbSame2SameStruct1InterfaceStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct1Interface|Remote", DisplayName = "Statistics Updated")
	FTbSame2SameStruct1InterfaceStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct1Interface|Remote", DisplayName = "Connection Status Changed")
	FTbSame2SameStruct1InterfaceConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbSame2SameStruct1InterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	FTbSame2Struct1 GetProp1() const override;
	void SetProp1(const FTbSame2Struct1& Prop1) override;

	// operations
	FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSame2SameStruct1InterfaceMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbSame2SameStruct1InterfaceStats Stats;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	void _OnHeartbeat();
	bool _OnHeartbeatTick(float DeltaTime);
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTbSame2SameStruct1InterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbSame2SameStruct1InterfacePongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbSame2SameStruct1InterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig1(const FTbSame2SameStruct1InterfaceSig1SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp1Changed(const FTbSame2SameStruct1InterfaceProp1ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Reply(const FTbSame2SameStruct1InterfaceFunc1ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbSame2SameStruct1InterfacePropertiesData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
