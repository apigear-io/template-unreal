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

#include "TbSame1/Generated/api/AbstractTbSame1SameStruct2Interface.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "Templates/PimplPtr.h"
#include "IMessageContext.h"
#include "TbSame1SameStruct2InterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbSame1SameStruct2InterfaceInitMessage;
struct FTbSame1SameStruct2InterfacePongMessage;
struct FTbSame1SameStruct2InterfaceServiceDisconnectMessage;
struct FTbSame1SameStruct2InterfaceSig1SignalMessage;
struct FTbSame1SameStruct2InterfaceSig2SignalMessage;
struct FTbSame1SameStruct2InterfaceProp1ChangedMessage;
struct FTbSame1SameStruct2InterfaceProp2ChangedMessage;
struct FTbSame1SameStruct2InterfaceFunc1ReplyMessage;
struct FTbSame1SameStruct2InterfaceFunc2ReplyMessage;

USTRUCT(BlueprintType)
struct FTbSame1SameStruct2InterfaceStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame1|SameStruct2Interface|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame1|SameStruct2Interface|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame1|SameStruct2Interface|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame1|SameStruct2Interface|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct2InterfaceStatsUpdatedDelegate, FTbSame1SameStruct2InterfaceStats, Stats);

struct TbSame1SameStruct2InterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbSame1SameStruct2InterfaceMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct2InterfaceConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct2InterfaceConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME1MSGBUS_API UTbSame1SameStruct2InterfaceMsgBusClient : public UAbstractTbSame1SameStruct2Interface
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameStruct2InterfaceMsgBusClient();
	virtual ~UTbSame1SameStruct2InterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface|Remote")
	const FTbSame1SameStruct2InterfaceStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct2Interface|Remote", DisplayName = "Statistics Updated")
	FTbSame1SameStruct2InterfaceStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct2Interface|Remote", DisplayName = "Connection Status Changed")
	FTbSame1SameStruct2InterfaceConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbSame1SameStruct2InterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	FTbSame1Struct2 GetProp1() const override;
	void SetProp1(const FTbSame1Struct2& Prop1) override;

	FTbSame1Struct2 GetProp2() const override;
	void SetProp2(const FTbSame1Struct2& Prop2) override;

	// operations
	FTbSame1Struct1 Func1(const FTbSame1Struct1& Param1) override;

	FTbSame1Struct1 Func2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSame1SameStruct2InterfaceMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbSame1SameStruct2InterfaceStats Stats;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	void _OnHeartbeat();
	bool _OnHeartbeatTick(float DeltaTime);
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTbSame1SameStruct2InterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbSame1SameStruct2InterfacePongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbSame1SameStruct2InterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig1(const FTbSame1SameStruct2InterfaceSig1SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig2(const FTbSame1SameStruct2InterfaceSig2SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp1Changed(const FTbSame1SameStruct2InterfaceProp1ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp2Changed(const FTbSame1SameStruct2InterfaceProp2ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Reply(const FTbSame1SameStruct2InterfaceFunc1ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc2Reply(const FTbSame1SameStruct2InterfaceFunc2ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbSame1SameStruct2InterfacePropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
