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

#include "Generated/api/AbstractTbSimpleSimpleArrayInterface.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
#include "Templates/UniquePtr.h"
#else
#include "Templates/PimplPtr.h"
#endif
#include "IMessageContext.h"
#include "TbSimpleSimpleArrayInterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbSimpleSimpleArrayInterfaceInitMessage;
struct FTbSimpleSimpleArrayInterfaceServiceDisconnectMessage;
struct FTbSimpleSimpleArrayInterfaceSigBoolSignalMessage;
struct FTbSimpleSimpleArrayInterfaceSigIntSignalMessage;
struct FTbSimpleSimpleArrayInterfaceSigInt32SignalMessage;
struct FTbSimpleSimpleArrayInterfaceSigInt64SignalMessage;
struct FTbSimpleSimpleArrayInterfaceSigFloatSignalMessage;
struct FTbSimpleSimpleArrayInterfaceSigFloat32SignalMessage;
struct FTbSimpleSimpleArrayInterfaceSigFloat64SignalMessage;
struct FTbSimpleSimpleArrayInterfaceSigStringSignalMessage;
struct FTbSimpleSimpleArrayInterfacePropBoolChangedMessage;
struct FTbSimpleSimpleArrayInterfacePropIntChangedMessage;
struct FTbSimpleSimpleArrayInterfacePropInt32ChangedMessage;
struct FTbSimpleSimpleArrayInterfacePropInt64ChangedMessage;
struct FTbSimpleSimpleArrayInterfacePropFloatChangedMessage;
struct FTbSimpleSimpleArrayInterfacePropFloat32ChangedMessage;
struct FTbSimpleSimpleArrayInterfacePropFloat64ChangedMessage;
struct FTbSimpleSimpleArrayInterfacePropStringChangedMessage;
struct FTbSimpleSimpleArrayInterfacePropReadOnlyStringChangedMessage;
struct FTbSimpleSimpleArrayInterfaceFuncBoolReplyMessage;
struct FTbSimpleSimpleArrayInterfaceFuncIntReplyMessage;
struct FTbSimpleSimpleArrayInterfaceFuncInt32ReplyMessage;
struct FTbSimpleSimpleArrayInterfaceFuncInt64ReplyMessage;
struct FTbSimpleSimpleArrayInterfaceFuncFloatReplyMessage;
struct FTbSimpleSimpleArrayInterfaceFuncFloat32ReplyMessage;
struct FTbSimpleSimpleArrayInterfaceFuncFloat64ReplyMessage;
struct FTbSimpleSimpleArrayInterfaceFuncStringReplyMessage;

struct TbSimpleSimpleArrayInterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleSimpleArrayInterfaceMsgBusClient, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceConnectionStatusChangedDelegate, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLE_API UTbSimpleSimpleArrayInterfaceMsgBusClient : public UAbstractTbSimpleSimpleArrayInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleArrayInterfaceMsgBusClient();
	virtual ~UTbSimpleSimpleArrayInterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Remote")
	void Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Remote")
	void Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Remote")
	bool IsConnected() const;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Remote", DisplayName = "Connection Status Changed")
	FTbSimpleSimpleArrayInterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	TArray<bool> GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(const TArray<bool>& PropBool) override;

	TArray<int32> GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(const TArray<int32>& PropInt) override;

	TArray<int32> GetPropInt32_Implementation() const override;
	void SetPropInt32_Implementation(const TArray<int32>& PropInt32) override;

	TArray<int64> GetPropInt64_Implementation() const override;
	void SetPropInt64_Implementation(const TArray<int64>& PropInt64) override;

	TArray<float> GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(const TArray<float>& PropFloat) override;

	TArray<float> GetPropFloat32_Implementation() const override;
	void SetPropFloat32_Implementation(const TArray<float>& PropFloat32) override;

	TArray<double> GetPropFloat64_Implementation() const override;
	void SetPropFloat64_Implementation(const TArray<double>& PropFloat64) override;

	TArray<FString> GetPropString_Implementation() const override;
	void SetPropString_Implementation(const TArray<FString>& PropString) override;

	FString GetPropReadOnlyString_Implementation() const override;

	// operations
	TArray<bool> FuncBool_Implementation(const TArray<bool>& ParamBool) override;

	TArray<int32> FuncInt_Implementation(const TArray<int32>& ParamInt) override;

	TArray<int32> FuncInt32_Implementation(const TArray<int32>& ParamInt32) override;

	TArray<int64> FuncInt64_Implementation(const TArray<int64>& ParamInt64) override;

	TArray<float> FuncFloat_Implementation(const TArray<float>& ParamFloat) override;

	TArray<float> FuncFloat32_Implementation(const TArray<float>& ParamFloat32) override;

	TArray<double> FuncFloat64_Implementation(const TArray<double>& ParamFloat) override;

	TArray<FString> FuncString_Implementation(const TArray<FString>& ParamString) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSimpleSimpleArrayInterfaceMsgBusEndpoint;

	void DiscoverService();
	FMessageAddress ServiceAddress;

	// connection handling
	void OnConnectionInit(const FTbSimpleSimpleArrayInterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbSimpleSimpleArrayInterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigBool(const FTbSimpleSimpleArrayInterfaceSigBoolSignalMessage& InSigBoolMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigInt(const FTbSimpleSimpleArrayInterfaceSigIntSignalMessage& InSigIntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigInt32(const FTbSimpleSimpleArrayInterfaceSigInt32SignalMessage& InSigInt32Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigInt64(const FTbSimpleSimpleArrayInterfaceSigInt64SignalMessage& InSigInt64Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigFloat(const FTbSimpleSimpleArrayInterfaceSigFloatSignalMessage& InSigFloatMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigFloat32(const FTbSimpleSimpleArrayInterfaceSigFloat32SignalMessage& InSigFloat32Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigFloat64(const FTbSimpleSimpleArrayInterfaceSigFloat64SignalMessage& InSigFloat64Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSigString(const FTbSimpleSimpleArrayInterfaceSigStringSignalMessage& InSigStringMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropBoolChanged(const FTbSimpleSimpleArrayInterfacePropBoolChangedMessage& InPropBoolMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropIntChanged(const FTbSimpleSimpleArrayInterfacePropIntChangedMessage& InPropIntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropInt32Changed(const FTbSimpleSimpleArrayInterfacePropInt32ChangedMessage& InPropInt32Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropInt64Changed(const FTbSimpleSimpleArrayInterfacePropInt64ChangedMessage& InPropInt64Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropFloatChanged(const FTbSimpleSimpleArrayInterfacePropFloatChangedMessage& InPropFloatMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropFloat32Changed(const FTbSimpleSimpleArrayInterfacePropFloat32ChangedMessage& InPropFloat32Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropFloat64Changed(const FTbSimpleSimpleArrayInterfacePropFloat64ChangedMessage& InPropFloat64Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropStringChanged(const FTbSimpleSimpleArrayInterfacePropStringChangedMessage& InPropStringMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPropReadOnlyStringChanged(const FTbSimpleSimpleArrayInterfacePropReadOnlyStringChangedMessage& InPropReadOnlyStringMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncBoolReply(const FTbSimpleSimpleArrayInterfaceFuncBoolReplyMessage& InFuncBoolMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncIntReply(const FTbSimpleSimpleArrayInterfaceFuncIntReplyMessage& InFuncIntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncInt32Reply(const FTbSimpleSimpleArrayInterfaceFuncInt32ReplyMessage& InFuncInt32Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncInt64Reply(const FTbSimpleSimpleArrayInterfaceFuncInt64ReplyMessage& InFuncInt64Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloatReply(const FTbSimpleSimpleArrayInterfaceFuncFloatReplyMessage& InFuncFloatMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloat32Reply(const FTbSimpleSimpleArrayInterfaceFuncFloat32ReplyMessage& InFuncFloat32Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloat64Reply(const FTbSimpleSimpleArrayInterfaceFuncFloat64ReplyMessage& InFuncFloat64Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncStringReply(const FTbSimpleSimpleArrayInterfaceFuncStringReplyMessage& InFuncStringMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbSimpleSimpleArrayInterfacePropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
