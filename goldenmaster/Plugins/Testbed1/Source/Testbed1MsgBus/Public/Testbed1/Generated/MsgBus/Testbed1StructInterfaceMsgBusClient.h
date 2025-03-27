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

#include "Testbed1/Generated/api/AbstractTestbed1StructInterface.h"
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
#include "Testbed1StructInterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTestbed1StructInterfaceInitMessage;
struct FTestbed1StructInterfacePongMessage;
struct FTestbed1StructInterfaceServiceDisconnectMessage;
struct FTestbed1StructInterfaceSigBoolSignalMessage;
struct FTestbed1StructInterfaceSigIntSignalMessage;
struct FTestbed1StructInterfaceSigFloatSignalMessage;
struct FTestbed1StructInterfaceSigStringSignalMessage;
struct FTestbed1StructInterfacePropBoolChangedMessage;
struct FTestbed1StructInterfacePropIntChangedMessage;
struct FTestbed1StructInterfacePropFloatChangedMessage;
struct FTestbed1StructInterfacePropStringChangedMessage;
struct FTestbed1StructInterfaceFuncBoolReplyMessage;
struct FTestbed1StructInterfaceFuncIntReplyMessage;
struct FTestbed1StructInterfaceFuncFloatReplyMessage;
struct FTestbed1StructInterfaceFuncStringReplyMessage;

USTRUCT(BlueprintType)
struct FTestbed1StructInterfaceStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed1|StructInterface|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed1|StructInterface|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed1|StructInterface|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed1|StructInterface|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfaceStatsUpdatedDelegate, FTestbed1StructInterfaceStats, Stats);

struct Testbed1StructInterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructInterfaceMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfaceConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfaceConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1MSGBUS_API UTestbed1StructInterfaceMsgBusClient : public UAbstractTestbed1StructInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructInterfaceMsgBusClient();
	virtual ~UTestbed1StructInterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Remote")
	const FTestbed1StructInterfaceStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Remote", DisplayName = "Statistics Updated")
	FTestbed1StructInterfaceStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Remote", DisplayName = "Connection Status Changed")
	FTestbed1StructInterfaceConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTestbed1StructInterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	FTestbed1StructBool GetPropBool() const override;
	void SetPropBool(const FTestbed1StructBool& PropBool) override;

	FTestbed1StructInt GetPropInt() const override;
	void SetPropInt(const FTestbed1StructInt& PropInt) override;

	FTestbed1StructFloat GetPropFloat() const override;
	void SetPropFloat(const FTestbed1StructFloat& PropFloat) override;

	FTestbed1StructString GetPropString() const override;
	void SetPropString(const FTestbed1StructString& PropString) override;

	// operations
	FTestbed1StructBool FuncBool(const FTestbed1StructBool& ParamBool) override;

	FTestbed1StructInt FuncInt(const FTestbed1StructInt& ParamInt) override;

	FTestbed1StructFloat FuncFloat(const FTestbed1StructFloat& ParamFloat) override;

	FTestbed1StructString FuncString(const FTestbed1StructString& ParamString) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> Testbed1StructInterfaceMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTestbed1StructInterfaceStats Stats;
	FTimerHandle _HeartbeatTimerHandle;
	void _OnHeartbeat();
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTestbed1StructInterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTestbed1StructInterfacePongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTestbed1StructInterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigBool(const FTestbed1StructInterfaceSigBoolSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigInt(const FTestbed1StructInterfaceSigIntSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigFloat(const FTestbed1StructInterfaceSigFloatSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigString(const FTestbed1StructInterfaceSigStringSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropBoolChanged(const FTestbed1StructInterfacePropBoolChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropIntChanged(const FTestbed1StructInterfacePropIntChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropFloatChanged(const FTestbed1StructInterfacePropFloatChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropStringChanged(const FTestbed1StructInterfacePropStringChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncBoolReply(const FTestbed1StructInterfaceFuncBoolReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncIntReply(const FTestbed1StructInterfaceFuncIntReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloatReply(const FTestbed1StructInterfaceFuncFloatReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncStringReply(const FTestbed1StructInterfaceFuncStringReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<Testbed1StructInterfacePropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
