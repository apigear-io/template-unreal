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

#include "TbSimple/Generated/api/AbstractTbSimpleSimpleInterface.h"
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
#include "TbSimpleSimpleInterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbSimpleSimpleInterfaceInitMessage;
struct FTbSimpleSimpleInterfacePongMessage;
struct FTbSimpleSimpleInterfaceServiceDisconnectMessage;
struct FTbSimpleSimpleInterfaceSigBoolSignalMessage;
struct FTbSimpleSimpleInterfaceSigIntSignalMessage;
struct FTbSimpleSimpleInterfaceSigInt32SignalMessage;
struct FTbSimpleSimpleInterfaceSigInt64SignalMessage;
struct FTbSimpleSimpleInterfaceSigFloatSignalMessage;
struct FTbSimpleSimpleInterfaceSigFloat32SignalMessage;
struct FTbSimpleSimpleInterfaceSigFloat64SignalMessage;
struct FTbSimpleSimpleInterfaceSigStringSignalMessage;
struct FTbSimpleSimpleInterfacePropBoolChangedMessage;
struct FTbSimpleSimpleInterfacePropIntChangedMessage;
struct FTbSimpleSimpleInterfacePropInt32ChangedMessage;
struct FTbSimpleSimpleInterfacePropInt64ChangedMessage;
struct FTbSimpleSimpleInterfacePropFloatChangedMessage;
struct FTbSimpleSimpleInterfacePropFloat32ChangedMessage;
struct FTbSimpleSimpleInterfacePropFloat64ChangedMessage;
struct FTbSimpleSimpleInterfacePropStringChangedMessage;
struct FTbSimpleSimpleInterfaceFuncBoolReplyMessage;
struct FTbSimpleSimpleInterfaceFuncIntReplyMessage;
struct FTbSimpleSimpleInterfaceFuncInt32ReplyMessage;
struct FTbSimpleSimpleInterfaceFuncInt64ReplyMessage;
struct FTbSimpleSimpleInterfaceFuncFloatReplyMessage;
struct FTbSimpleSimpleInterfaceFuncFloat32ReplyMessage;
struct FTbSimpleSimpleInterfaceFuncFloat64ReplyMessage;
struct FTbSimpleSimpleInterfaceFuncStringReplyMessage;

USTRUCT(BlueprintType)
struct FTbSimpleSimpleInterfaceStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|SimpleInterface|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|SimpleInterface|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|SimpleInterface|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|TbSimple|SimpleInterface|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceStatsUpdatedDelegate, FTbSimpleSimpleInterfaceStats, Stats);

struct TbSimpleSimpleInterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleSimpleInterfaceMsgBusClient, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceConnectionStatusChangedDelegate, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLE_API UTbSimpleSimpleInterfaceMsgBusClient : public UAbstractTbSimpleSimpleInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleInterfaceMsgBusClient();
	virtual ~UTbSimpleSimpleInterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Remote")
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Remote")
	const FTbSimpleSimpleInterfaceStats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Remote", DisplayName = "Statistics Updated")
	FTbSimpleSimpleInterfaceStatsUpdatedDelegate _StatsUpdated;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Remote", DisplayName = "Connection Status Changed")
	FTbSimpleSimpleInterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	bool GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(bool bPropBool) override;

	int32 GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(int32 PropInt) override;

	int32 GetPropInt32_Implementation() const override;
	void SetPropInt32_Implementation(int32 PropInt32) override;

	int64 GetPropInt64_Implementation() const override;
	void SetPropInt64_Implementation(int64 PropInt64) override;

	float GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(float PropFloat) override;

	float GetPropFloat32_Implementation() const override;
	void SetPropFloat32_Implementation(float PropFloat32) override;

	double GetPropFloat64_Implementation() const override;
	void SetPropFloat64_Implementation(double PropFloat64) override;

	FString GetPropString_Implementation() const override;
	void SetPropString_Implementation(const FString& PropString) override;

	// operations
	void FuncNoReturnValue_Implementation(bool bParamBool) override;

	bool FuncBool_Implementation(bool bParamBool) override;

	int32 FuncInt_Implementation(int32 ParamInt) override;

	int32 FuncInt32_Implementation(int32 ParamInt32) override;

	int64 FuncInt64_Implementation(int64 ParamInt64) override;

	float FuncFloat_Implementation(float ParamFloat) override;

	float FuncFloat32_Implementation(float ParamFloat32) override;

	double FuncFloat64_Implementation(double ParamFloat) override;

	FString FuncString_Implementation(const FString& ParamString) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSimpleSimpleInterfaceMsgBusEndpoint;

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	FTbSimpleSimpleInterfaceStats Stats;
	FTimerHandle _HeartbeatTimerHandle;
	void _OnHeartbeat();
	uint32 _HeartbeatIntervalMS = 1000;

	// connection handling
	void OnConnectionInit(const FTbSimpleSimpleInterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const FTbSimpleSimpleInterfacePongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbSimpleSimpleInterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigBool(const FTbSimpleSimpleInterfaceSigBoolSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigInt(const FTbSimpleSimpleInterfaceSigIntSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigInt32(const FTbSimpleSimpleInterfaceSigInt32SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigInt64(const FTbSimpleSimpleInterfaceSigInt64SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigFloat(const FTbSimpleSimpleInterfaceSigFloatSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigFloat32(const FTbSimpleSimpleInterfaceSigFloat32SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigFloat64(const FTbSimpleSimpleInterfaceSigFloat64SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigString(const FTbSimpleSimpleInterfaceSigStringSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropBoolChanged(const FTbSimpleSimpleInterfacePropBoolChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropIntChanged(const FTbSimpleSimpleInterfacePropIntChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropInt32Changed(const FTbSimpleSimpleInterfacePropInt32ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropInt64Changed(const FTbSimpleSimpleInterfacePropInt64ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropFloatChanged(const FTbSimpleSimpleInterfacePropFloatChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropFloat32Changed(const FTbSimpleSimpleInterfacePropFloat32ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropFloat64Changed(const FTbSimpleSimpleInterfacePropFloat64ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropStringChanged(const FTbSimpleSimpleInterfacePropStringChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncBoolReply(const FTbSimpleSimpleInterfaceFuncBoolReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncIntReply(const FTbSimpleSimpleInterfaceFuncIntReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncInt32Reply(const FTbSimpleSimpleInterfaceFuncInt32ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncInt64Reply(const FTbSimpleSimpleInterfaceFuncInt64ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloatReply(const FTbSimpleSimpleInterfaceFuncFloatReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloat32Reply(const FTbSimpleSimpleInterfaceFuncFloat32ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloat64Reply(const FTbSimpleSimpleInterfaceFuncFloat64ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncStringReply(const FTbSimpleSimpleInterfaceFuncStringReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbSimpleSimpleInterfacePropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
