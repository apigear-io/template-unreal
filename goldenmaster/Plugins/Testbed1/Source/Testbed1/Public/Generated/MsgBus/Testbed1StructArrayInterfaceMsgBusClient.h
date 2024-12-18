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

#include "Generated/api/AbstractTestbed1StructArrayInterface.h"
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
#include "Testbed1StructArrayInterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTestbed1StructArrayInterfaceInitMessage;
struct FTestbed1StructArrayInterfacePongMessage;
struct FTestbed1StructArrayInterfaceServiceDisconnectMessage;
struct FTestbed1StructArrayInterfaceSigBoolSignalMessage;
struct FTestbed1StructArrayInterfaceSigIntSignalMessage;
struct FTestbed1StructArrayInterfaceSigFloatSignalMessage;
struct FTestbed1StructArrayInterfaceSigStringSignalMessage;
struct FTestbed1StructArrayInterfacePropBoolChangedMessage;
struct FTestbed1StructArrayInterfacePropIntChangedMessage;
struct FTestbed1StructArrayInterfacePropFloatChangedMessage;
struct FTestbed1StructArrayInterfacePropStringChangedMessage;
struct FTestbed1StructArrayInterfaceFuncBoolReplyMessage;
struct FTestbed1StructArrayInterfaceFuncIntReplyMessage;
struct FTestbed1StructArrayInterfaceFuncFloatReplyMessage;
struct FTestbed1StructArrayInterfaceFuncStringReplyMessage;

USTRUCT(BlueprintType)
struct FTestbed1StructArrayInterfaceStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed1|StructArrayInterface|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed1|StructArrayInterface|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed1|StructArrayInterface|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|Testbed1|StructArrayInterface|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceStatsUpdatedDelegate, FTestbed1StructArrayInterfaceStats, Stats);

struct Testbed1StructArrayInterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructArrayInterfaceMsgBusClient, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceConnectionStatusChangedDelegate, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1_API UTestbed1StructArrayInterfaceMsgBusClient : public UAbstractTestbed1StructArrayInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructArrayInterfaceMsgBusClient();
	virtual ~UTestbed1StructArrayInterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote")
	const FTestbed1StructArrayInterfaceStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote", DisplayName = "Statistics Updated")
	FTestbed1StructArrayInterfaceStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote", DisplayName = "Connection Status Changed")
	FTestbed1StructArrayInterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	TArray<FTestbed1StructBool> GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(const TArray<FTestbed1StructBool>& PropBool) override;

	TArray<FTestbed1StructInt> GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(const TArray<FTestbed1StructInt>& PropInt) override;

	TArray<FTestbed1StructFloat> GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& PropFloat) override;

	TArray<FTestbed1StructString> GetPropString_Implementation() const override;
	void SetPropString_Implementation(const TArray<FTestbed1StructString>& PropString) override;

	// operations
	TArray<FTestbed1StructBool> FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool) override;

	TArray<FTestbed1StructInt> FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt) override;

	TArray<FTestbed1StructFloat> FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat) override;

	TArray<FTestbed1StructString> FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> Testbed1StructArrayInterfaceMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	FTestbed1StructArrayInterfaceStats Stats;
	FTimerHandle _HeartbeatTimerHandle;
	void _OnHeartbeat();
	uint32 _HeartbeatIntervalMS = 1000;

	// connection handling
	void OnConnectionInit(const FTestbed1StructArrayInterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTestbed1StructArrayInterfacePongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTestbed1StructArrayInterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigBool(const FTestbed1StructArrayInterfaceSigBoolSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigInt(const FTestbed1StructArrayInterfaceSigIntSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigFloat(const FTestbed1StructArrayInterfaceSigFloatSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigString(const FTestbed1StructArrayInterfaceSigStringSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropBoolChanged(const FTestbed1StructArrayInterfacePropBoolChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropIntChanged(const FTestbed1StructArrayInterfacePropIntChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropFloatChanged(const FTestbed1StructArrayInterfacePropFloatChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropStringChanged(const FTestbed1StructArrayInterfacePropStringChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncBoolReply(const FTestbed1StructArrayInterfaceFuncBoolReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncIntReply(const FTestbed1StructArrayInterfaceFuncIntReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloatReply(const FTestbed1StructArrayInterfaceFuncFloatReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncStringReply(const FTestbed1StructArrayInterfaceFuncStringReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<Testbed1StructArrayInterfacePropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};