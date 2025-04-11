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

#include "Testbed2/Generated/api/AbstractTestbed2NestedStruct1Interface.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "Templates/PimplPtr.h"
#include "IMessageContext.h"
#include "Testbed2NestedStruct1InterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTestbed2NestedStruct1InterfaceInitMessage;
struct FTestbed2NestedStruct1InterfacePongMessage;
struct FTestbed2NestedStruct1InterfaceServiceDisconnectMessage;
struct FTestbed2NestedStruct1InterfaceSig1SignalMessage;
struct FTestbed2NestedStruct1InterfaceProp1ChangedMessage;
struct FTestbed2NestedStruct1InterfaceFunc1ReplyMessage;

USTRUCT(BlueprintType)
struct FTestbed2NestedStruct1InterfaceStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct1InterfaceStatsUpdatedDelegate, FTestbed2NestedStruct1InterfaceStats, Stats);

struct Testbed2NestedStruct1InterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2NestedStruct1InterfaceMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct1InterfaceConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct1InterfaceConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED2MSGBUS_API UTestbed2NestedStruct1InterfaceMsgBusClient : public UAbstractTestbed2NestedStruct1Interface
{
	GENERATED_BODY()
public:
	explicit UTestbed2NestedStruct1InterfaceMsgBusClient();
	virtual ~UTestbed2NestedStruct1InterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote")
	const FTestbed2NestedStruct1InterfaceStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote", DisplayName = "Statistics Updated")
	FTestbed2NestedStruct1InterfaceStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote", DisplayName = "Connection Status Changed")
	FTestbed2NestedStruct1InterfaceConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTestbed2NestedStruct1InterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	FTestbed2NestedStruct1 GetProp1() const override;
	void SetProp1(const FTestbed2NestedStruct1& Prop1) override;

	// operations
	FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> Testbed2NestedStruct1InterfaceMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTestbed2NestedStruct1InterfaceStats Stats;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	void _OnHeartbeat();
	bool _OnHeartbeatTick(float DeltaTime);
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTestbed2NestedStruct1InterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTestbed2NestedStruct1InterfacePongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTestbed2NestedStruct1InterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig1(const FTestbed2NestedStruct1InterfaceSig1SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp1Changed(const FTestbed2NestedStruct1InterfaceProp1ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Reply(const FTestbed2NestedStruct1InterfaceFunc1ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<Testbed2NestedStruct1InterfacePropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
