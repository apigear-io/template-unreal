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

#include "TbSame2/Generated/api/AbstractTbSame2SameEnum2Interface.h"
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
#include "TbSame2SameEnum2InterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbSame2SameEnum2InterfaceInitMessage;
struct FTbSame2SameEnum2InterfacePongMessage;
struct FTbSame2SameEnum2InterfaceServiceDisconnectMessage;
struct FTbSame2SameEnum2InterfaceSig1SignalMessage;
struct FTbSame2SameEnum2InterfaceSig2SignalMessage;
struct FTbSame2SameEnum2InterfaceProp1ChangedMessage;
struct FTbSame2SameEnum2InterfaceProp2ChangedMessage;
struct FTbSame2SameEnum2InterfaceFunc1ReplyMessage;
struct FTbSame2SameEnum2InterfaceFunc2ReplyMessage;

USTRUCT(BlueprintType)
struct FTbSame2SameEnum2InterfaceStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame2|SameEnum2Interface|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame2|SameEnum2Interface|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame2|SameEnum2Interface|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame2|SameEnum2Interface|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum2InterfaceStatsUpdatedDelegate, FTbSame2SameEnum2InterfaceStats, Stats);

struct TbSame2SameEnum2InterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbSame2SameEnum2InterfaceMsgBusClient, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum2InterfaceConnectionStatusChangedDelegate, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME2MSGBUS_API UTbSame2SameEnum2InterfaceMsgBusClient : public UAbstractTbSame2SameEnum2Interface
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameEnum2InterfaceMsgBusClient();
	virtual ~UTbSame2SameEnum2InterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Remote")
	const FTbSame2SameEnum2InterfaceStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface|Remote", DisplayName = "Statistics Updated")
	FTbSame2SameEnum2InterfaceStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface|Remote", DisplayName = "Connection Status Changed")
	FTbSame2SameEnum2InterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	ETbSame2Enum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(ETbSame2Enum1 Prop1) override;

	ETbSame2Enum2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(ETbSame2Enum2 Prop2) override;

	// operations
	ETbSame2Enum1 Func1_Implementation(ETbSame2Enum1 Param1) override;

	ETbSame2Enum1 Func2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSame2SameEnum2InterfaceMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbSame2SameEnum2InterfaceStats Stats;
	FTimerHandle _HeartbeatTimerHandle;
	void _OnHeartbeat();
	uint32 _HeartbeatIntervalMS = 1000;

	// connection handling
	void OnConnectionInit(const FTbSame2SameEnum2InterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbSame2SameEnum2InterfacePongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbSame2SameEnum2InterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig1(const FTbSame2SameEnum2InterfaceSig1SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig2(const FTbSame2SameEnum2InterfaceSig2SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp1Changed(const FTbSame2SameEnum2InterfaceProp1ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp2Changed(const FTbSame2SameEnum2InterfaceProp2ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Reply(const FTbSame2SameEnum2InterfaceFunc1ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc2Reply(const FTbSame2SameEnum2InterfaceFunc2ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbSame2SameEnum2InterfacePropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
