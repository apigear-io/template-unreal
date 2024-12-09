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

#include "Generated/api/AbstractTbSame1SameStruct2Interface.h"
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
#include "TbSame1SameStruct2InterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTbSame1SameStruct2InterfaceInitMessage;
struct FTbSame1SameStruct2InterfaceServiceDisconnectMessage;
struct FTbSame1SameStruct2InterfaceSig1SignalMessage;
struct FTbSame1SameStruct2InterfaceSig2SignalMessage;
struct FTbSame1SameStruct2InterfaceProp1ChangedMessage;
struct FTbSame1SameStruct2InterfaceProp2ChangedMessage;
struct FTbSame1SameStruct2InterfaceFunc1ReplyMessage;
struct FTbSame1SameStruct2InterfaceFunc2ReplyMessage;

struct TbSame1SameStruct2InterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbSame1SameStruct2InterfaceMsgBusClient, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct2InterfaceConnectionStatusChangedDelegate, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME1_API UTbSame1SameStruct2InterfaceMsgBusClient : public UAbstractTbSame1SameStruct2Interface
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameStruct2InterfaceMsgBusClient();
	virtual ~UTbSame1SameStruct2InterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface|Remote")
	void Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface|Remote")
	void Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface|Remote")
	bool IsConnected() const;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct2Interface|Remote", DisplayName = "Connection Status Changed")
	FTbSame1SameStruct2InterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	FTbSame1Struct2 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTbSame1Struct2& Prop1) override;

	FTbSame1Struct2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(const FTbSame1Struct2& Prop2) override;

	// operations
	FTbSame1Struct1 Func1_Implementation(const FTbSame1Struct1& Param1) override;

	FTbSame1Struct1 Func2_Implementation(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSame1SameStruct2InterfaceMsgBusEndpoint;

	void DiscoverService();
	FMessageAddress ServiceAddress;

	// connection handling
	void OnConnectionInit(const FTbSame1SameStruct2InterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTbSame1SameStruct2InterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig1(const FTbSame1SameStruct2InterfaceSig1SignalMessage& InSig1Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig2(const FTbSame1SameStruct2InterfaceSig2SignalMessage& InSig2Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp1Changed(const FTbSame1SameStruct2InterfaceProp1ChangedMessage& InProp1Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp2Changed(const FTbSame1SameStruct2InterfaceProp2ChangedMessage& InProp2Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Reply(const FTbSame1SameStruct2InterfaceFunc1ReplyMessage& InFunc1Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc2Reply(const FTbSame1SameStruct2InterfaceFunc2ReplyMessage& InFunc2Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<TbSame1SameStruct2InterfacePropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
