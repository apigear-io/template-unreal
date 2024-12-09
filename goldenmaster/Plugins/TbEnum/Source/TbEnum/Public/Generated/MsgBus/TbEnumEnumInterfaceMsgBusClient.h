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

#include "Generated/api/AbstractTbEnumEnumInterface.h"
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
#include "TbEnumEnumInterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbEnumEnumInterfaceInitMessage;
struct FTbEnumEnumInterfaceServiceDisconnectMessage;
struct FTbEnumEnumInterfaceSig0SignalMessage;
struct FTbEnumEnumInterfaceSig1SignalMessage;
struct FTbEnumEnumInterfaceSig2SignalMessage;
struct FTbEnumEnumInterfaceSig3SignalMessage;
struct FTbEnumEnumInterfaceProp0ChangedMessage;
struct FTbEnumEnumInterfaceProp1ChangedMessage;
struct FTbEnumEnumInterfaceProp2ChangedMessage;
struct FTbEnumEnumInterfaceProp3ChangedMessage;
struct FTbEnumEnumInterfaceFunc0ReplyMessage;
struct FTbEnumEnumInterfaceFunc1ReplyMessage;
struct FTbEnumEnumInterfaceFunc2ReplyMessage;
struct FTbEnumEnumInterfaceFunc3ReplyMessage;

struct TbEnumEnumInterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbEnumEnumInterfaceMsgBusClient, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceConnectionStatusChangedDelegate, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBENUM_API UTbEnumEnumInterfaceMsgBusClient : public UAbstractTbEnumEnumInterface
{
	GENERATED_BODY()
public:
	explicit UTbEnumEnumInterfaceMsgBusClient();
	virtual ~UTbEnumEnumInterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Remote")
	void Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Remote")
	void Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Remote")
	bool IsConnected() const;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Remote", DisplayName = "Connection Status Changed")
	FTbEnumEnumInterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	ETbEnumEnum0 GetProp0_Implementation() const override;
	void SetProp0_Implementation(ETbEnumEnum0 Prop0) override;

	ETbEnumEnum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(ETbEnumEnum1 Prop1) override;

	ETbEnumEnum2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(ETbEnumEnum2 Prop2) override;

	ETbEnumEnum3 GetProp3_Implementation() const override;
	void SetProp3_Implementation(ETbEnumEnum3 Prop3) override;

	// operations
	ETbEnumEnum0 Func0_Implementation(ETbEnumEnum0 Param0) override;

	ETbEnumEnum1 Func1_Implementation(ETbEnumEnum1 Param1) override;

	ETbEnumEnum2 Func2_Implementation(ETbEnumEnum2 Param2) override;

	ETbEnumEnum3 Func3_Implementation(ETbEnumEnum3 Param3) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbEnumEnumInterfaceMsgBusEndpoint;

	void DiscoverService();
	FMessageAddress ServiceAddress;

	// connection handling
	void OnConnectionInit(const FTbEnumEnumInterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbEnumEnumInterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig0(const FTbEnumEnumInterfaceSig0SignalMessage& InSig0Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig1(const FTbEnumEnumInterfaceSig1SignalMessage& InSig1Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig2(const FTbEnumEnumInterfaceSig2SignalMessage& InSig2Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig3(const FTbEnumEnumInterfaceSig3SignalMessage& InSig3Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp0Changed(const FTbEnumEnumInterfaceProp0ChangedMessage& InProp0Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp1Changed(const FTbEnumEnumInterfaceProp1ChangedMessage& InProp1Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp2Changed(const FTbEnumEnumInterfaceProp2ChangedMessage& InProp2Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp3Changed(const FTbEnumEnumInterfaceProp3ChangedMessage& InProp3Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc0Reply(const FTbEnumEnumInterfaceFunc0ReplyMessage& InFunc0Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Reply(const FTbEnumEnumInterfaceFunc1ReplyMessage& InFunc1Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc2Reply(const FTbEnumEnumInterfaceFunc2ReplyMessage& InFunc2Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc3Reply(const FTbEnumEnumInterfaceFunc3ReplyMessage& InFunc3Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbEnumEnumInterfacePropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
