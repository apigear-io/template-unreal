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

#include "TbSame1/Generated/api/AbstractTbSame1SameEnum1Interface.h"
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
#include "TbSame1SameEnum1InterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbSame1SameEnum1InterfaceInitMessage;
struct FTbSame1SameEnum1InterfacePongMessage;
struct FTbSame1SameEnum1InterfaceServiceDisconnectMessage;
struct FTbSame1SameEnum1InterfaceSig1SignalMessage;
struct FTbSame1SameEnum1InterfaceProp1ChangedMessage;
struct FTbSame1SameEnum1InterfaceFunc1ReplyMessage;

USTRUCT(BlueprintType)
struct FTbSame1SameEnum1InterfaceStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum1InterfaceStatsUpdatedDelegate, FTbSame1SameEnum1InterfaceStats, Stats);

struct TbSame1SameEnum1InterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbSame1SameEnum1InterfaceMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum1InterfaceConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum1InterfaceConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME1MSGBUS_API UTbSame1SameEnum1InterfaceMsgBusClient : public UAbstractTbSame1SameEnum1Interface
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameEnum1InterfaceMsgBusClient();
	virtual ~UTbSame1SameEnum1InterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote")
	const FTbSame1SameEnum1InterfaceStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote", DisplayName = "Statistics Updated")
	FTbSame1SameEnum1InterfaceStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote", DisplayName = "Connection Status Changed")
	FTbSame1SameEnum1InterfaceConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbSame1SameEnum1InterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	ETbSame1Enum1 GetProp1() const override;
	void SetProp1(ETbSame1Enum1 Prop1) override;

	// operations
	ETbSame1Enum1 Func1(ETbSame1Enum1 Param1) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSame1SameEnum1InterfaceMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbSame1SameEnum1InterfaceStats Stats;
	FTimerHandle _HeartbeatTimerHandle;
	void _OnHeartbeat();
	uint32 _HeartbeatIntervalMS = 1000;

	// connection handling
	void OnConnectionInit(const FTbSame1SameEnum1InterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbSame1SameEnum1InterfacePongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbSame1SameEnum1InterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig1(const FTbSame1SameEnum1InterfaceSig1SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp1Changed(const FTbSame1SameEnum1InterfaceProp1ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Reply(const FTbSame1SameEnum1InterfaceFunc1ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbSame1SameEnum1InterfacePropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
