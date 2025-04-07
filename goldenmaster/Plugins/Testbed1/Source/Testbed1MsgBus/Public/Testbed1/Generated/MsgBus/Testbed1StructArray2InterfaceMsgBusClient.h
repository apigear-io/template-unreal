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

#include "Testbed1/Generated/api/AbstractTestbed1StructArray2Interface.h"
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
#include "Testbed1StructArray2InterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTestbed1StructArray2InterfaceInitMessage;
struct FTestbed1StructArray2InterfacePongMessage;
struct FTestbed1StructArray2InterfaceServiceDisconnectMessage;
struct FTestbed1StructArray2InterfaceSigBoolSignalMessage;
struct FTestbed1StructArray2InterfaceSigIntSignalMessage;
struct FTestbed1StructArray2InterfaceSigFloatSignalMessage;
struct FTestbed1StructArray2InterfaceSigStringSignalMessage;
struct FTestbed1StructArray2InterfacePropBoolChangedMessage;
struct FTestbed1StructArray2InterfacePropIntChangedMessage;
struct FTestbed1StructArray2InterfacePropFloatChangedMessage;
struct FTestbed1StructArray2InterfacePropStringChangedMessage;
struct FTestbed1StructArray2InterfacePropEnumChangedMessage;
struct FTestbed1StructArray2InterfaceFuncBoolReplyMessage;
struct FTestbed1StructArray2InterfaceFuncIntReplyMessage;
struct FTestbed1StructArray2InterfaceFuncFloatReplyMessage;
struct FTestbed1StructArray2InterfaceFuncStringReplyMessage;
struct FTestbed1StructArray2InterfaceFuncEnumReplyMessage;

USTRUCT(BlueprintType)
struct FTestbed1StructArray2InterfaceStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed1|StructArray2Interface|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed1|StructArray2Interface|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed1|StructArray2Interface|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed1|StructArray2Interface|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceStatsUpdatedDelegate, FTestbed1StructArray2InterfaceStats, Stats);

struct Testbed1StructArray2InterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructArray2InterfaceMsgBusClient, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceConnectionStatusChangedDelegate, bool /* IsConnected */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceConnectionStatusChangedDelegateBP, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1MSGBUS_API UTestbed1StructArray2InterfaceMsgBusClient : public UAbstractTestbed1StructArray2Interface
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructArray2InterfaceMsgBusClient();
	virtual ~UTestbed1StructArray2InterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote")
	const FTestbed1StructArray2InterfaceStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote", DisplayName = "Statistics Updated")
	FTestbed1StructArray2InterfaceStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote", DisplayName = "Connection Status Changed")
	FTestbed1StructArray2InterfaceConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTestbed1StructArray2InterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	FTestbed1StructBoolWithArray GetPropBool() const override;
	void SetPropBool(const FTestbed1StructBoolWithArray& PropBool) override;

	FTestbed1StructIntWithArray GetPropInt() const override;
	void SetPropInt(const FTestbed1StructIntWithArray& PropInt) override;

	FTestbed1StructFloatWithArray GetPropFloat() const override;
	void SetPropFloat(const FTestbed1StructFloatWithArray& PropFloat) override;

	FTestbed1StructStringWithArray GetPropString() const override;
	void SetPropString(const FTestbed1StructStringWithArray& PropString) override;

	FTestbed1StructEnumWithArray GetPropEnum() const override;
	void SetPropEnum(const FTestbed1StructEnumWithArray& PropEnum) override;

	// operations
	TArray<FTestbed1StructBool> FuncBool(const FTestbed1StructBoolWithArray& ParamBool) override;

	TArray<FTestbed1StructInt> FuncInt(const FTestbed1StructIntWithArray& ParamInt) override;

	TArray<FTestbed1StructFloat> FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat) override;

	TArray<FTestbed1StructString> FuncString(const FTestbed1StructStringWithArray& ParamString) override;

	TArray<ETestbed1Enum0> FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> Testbed1StructArray2InterfaceMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTestbed1StructArray2InterfaceStats Stats;
	FTimerHandle _HeartbeatTimerHandle;
	void _OnHeartbeat();
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const FTestbed1StructArray2InterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTestbed1StructArray2InterfacePongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTestbed1StructArray2InterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigBool(const FTestbed1StructArray2InterfaceSigBoolSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigInt(const FTestbed1StructArray2InterfaceSigIntSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigFloat(const FTestbed1StructArray2InterfaceSigFloatSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigString(const FTestbed1StructArray2InterfaceSigStringSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropBoolChanged(const FTestbed1StructArray2InterfacePropBoolChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropIntChanged(const FTestbed1StructArray2InterfacePropIntChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropFloatChanged(const FTestbed1StructArray2InterfacePropFloatChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropStringChanged(const FTestbed1StructArray2InterfacePropStringChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropEnumChanged(const FTestbed1StructArray2InterfacePropEnumChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncBoolReply(const FTestbed1StructArray2InterfaceFuncBoolReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncIntReply(const FTestbed1StructArray2InterfaceFuncIntReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloatReply(const FTestbed1StructArray2InterfaceFuncFloatReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncStringReply(const FTestbed1StructArray2InterfaceFuncStringReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncEnumReply(const FTestbed1StructArray2InterfaceFuncEnumReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<Testbed1StructArray2InterfacePropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
