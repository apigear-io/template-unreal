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

#include "Testbed2/Generated/api/AbstractTestbed2ManyParamInterface.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "Templates/PimplPtr.h"
#include "IMessageContext.h"
#include "Testbed2ManyParamInterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTestbed2ManyParamInterfaceInitMessage;
struct FTestbed2ManyParamInterfacePongMessage;
struct FTestbed2ManyParamInterfaceServiceDisconnectMessage;
struct FTestbed2ManyParamInterfaceSig1SignalMessage;
struct FTestbed2ManyParamInterfaceSig2SignalMessage;
struct FTestbed2ManyParamInterfaceSig3SignalMessage;
struct FTestbed2ManyParamInterfaceSig4SignalMessage;
struct FTestbed2ManyParamInterfaceProp1ChangedMessage;
struct FTestbed2ManyParamInterfaceProp2ChangedMessage;
struct FTestbed2ManyParamInterfaceProp3ChangedMessage;
struct FTestbed2ManyParamInterfaceProp4ChangedMessage;
struct FTestbed2ManyParamInterfaceFunc1ReplyMessage;
struct FTestbed2ManyParamInterfaceFunc2ReplyMessage;
struct FTestbed2ManyParamInterfaceFunc3ReplyMessage;
struct FTestbed2ManyParamInterfaceFunc4ReplyMessage;

USTRUCT(BlueprintType)
struct FTestbed2ManyParamInterfaceStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed2|ManyParamInterface|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed2|ManyParamInterface|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed2|ManyParamInterface|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed2|ManyParamInterface|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceStatsUpdatedDelegate, FTestbed2ManyParamInterfaceStats, Stats);

struct Testbed2ManyParamInterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2ManyParamInterfaceMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED2MSGBUS_API UTestbed2ManyParamInterfaceMsgBusClient : public UAbstractTestbed2ManyParamInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed2ManyParamInterfaceMsgBusClient();
	virtual ~UTestbed2ManyParamInterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote")
	const FTestbed2ManyParamInterfaceStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote", DisplayName = "Statistics Updated")
	FTestbed2ManyParamInterfaceStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote", DisplayName = "Connection Status Changed")
	FTestbed2ManyParamInterfaceConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTestbed2ManyParamInterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	int32 GetProp1() const override;
	void SetProp1(int32 Prop1) override;

	int32 GetProp2() const override;
	void SetProp2(int32 Prop2) override;

	int32 GetProp3() const override;
	void SetProp3(int32 Prop3) override;

	int32 GetProp4() const override;
	void SetProp4(int32 Prop4) override;

	// operations
	int32 Func1(int32 Param1) override;

	int32 Func2(int32 Param1, int32 Param2) override;

	int32 Func3(int32 Param1, int32 Param2, int32 Param3) override;

	int32 Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> Testbed2ManyParamInterfaceMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTestbed2ManyParamInterfaceStats Stats;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	void _OnHeartbeat();
	bool _OnHeartbeatTick(float DeltaTime);
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTestbed2ManyParamInterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTestbed2ManyParamInterfacePongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTestbed2ManyParamInterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig1(const FTestbed2ManyParamInterfaceSig1SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig2(const FTestbed2ManyParamInterfaceSig2SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig3(const FTestbed2ManyParamInterfaceSig3SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig4(const FTestbed2ManyParamInterfaceSig4SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp1Changed(const FTestbed2ManyParamInterfaceProp1ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp2Changed(const FTestbed2ManyParamInterfaceProp2ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp3Changed(const FTestbed2ManyParamInterfaceProp3ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp4Changed(const FTestbed2ManyParamInterfaceProp4ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Reply(const FTestbed2ManyParamInterfaceFunc1ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc2Reply(const FTestbed2ManyParamInterfaceFunc2ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc3Reply(const FTestbed2ManyParamInterfaceFunc3ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc4Reply(const FTestbed2ManyParamInterfaceFunc4ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<Testbed2ManyParamInterfacePropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
