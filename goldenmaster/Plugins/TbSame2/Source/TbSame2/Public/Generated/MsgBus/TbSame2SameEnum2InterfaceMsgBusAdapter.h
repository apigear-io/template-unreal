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

#include "Generated/api/TbSame2SameEnum2InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "TbSame2SameEnum2InterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbSame2SameEnum2InterfaceDiscoveryMessage;
struct FTbSame2SameEnum2InterfacePingMessage;
struct FTbSame2SameEnum2InterfaceClientDisconnectMessage;
struct FTbSame2SameEnum2InterfaceSig1SignalMessage;
struct FTbSame2SameEnum2InterfaceSig2SignalMessage;
struct FTbSame2SameEnum2InterfaceSetProp1RequestMessage;
struct FTbSame2SameEnum2InterfaceProp1ChangedMessage;
struct FTbSame2SameEnum2InterfaceSetProp2RequestMessage;
struct FTbSame2SameEnum2InterfaceProp2ChangedMessage;
struct FTbSame2SameEnum2InterfaceFunc1RequestMessage;
struct FTbSame2SameEnum2InterfaceFunc2RequestMessage;

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbSame2SameEnum2InterfaceInterface
/// and holds the corresponding TbSame2SameEnum2InterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBSAME2_API UTbSame2SameEnum2InterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameEnum2InterfaceMsgBusAdapter();
	virtual ~UTbSame2SameEnum2InterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Remote")
	bool _IsListening() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface")
	void _setBackendService(TScriptInterface<ITbSame2SameEnum2InterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSame2SameEnum2InterfaceMsgBusEndpoint;

	void OnNewClientDiscovered(const FTbSame2SameEnum2InterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbSame2SameEnum2InterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbSame2SameEnum2InterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Request(const FTbSame2SameEnum2InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc2Request(const FTbSame2SameEnum2InterfaceFunc2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp1Request(const FTbSame2SameEnum2InterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp2Request(const FTbSame2SameEnum2InterfaceSetProp2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnSig1(ETbSame2Enum1 Param1);

	UFUNCTION(Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnSig2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);

	UFUNCTION(Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(ETbSame2Enum1 Prop1);

	UFUNCTION(Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnProp2Changed(ETbSame2Enum2 Prop2);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame2|SameEnum2Interface")
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> BackendService;

	TArray<FMessageAddress> ConnectedClients;

	uint32 _HeartbeatIntervalMS = 1000;
};
