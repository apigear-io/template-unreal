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

#include "Generated/api/TbSame1SameEnum2InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "TbSame1SameEnum2InterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbSame1SameEnum2InterfaceDiscoveryMessage;
struct FTbSame1SameEnum2InterfaceClientDisconnectMessage;
struct FTbSame1SameEnum2InterfaceSig1SignalMessage;

struct FTbSame1SameEnum2InterfaceSig2SignalMessage;
struct FTbSame1SameEnum2InterfaceSetProp1RequestMessage;
struct FTbSame1SameEnum2InterfaceProp1ChangedMessage;

struct FTbSame1SameEnum2InterfaceSetProp2RequestMessage;
struct FTbSame1SameEnum2InterfaceProp2ChangedMessage;
struct FTbSame1SameEnum2InterfaceFunc1RequestMessage;
struct FTbSame1SameEnum2InterfaceFunc2RequestMessage;

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbSame1SameEnum2InterfaceInterface
/// and holds the corresponding TbSame1SameEnum2InterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBSAME1_API UTbSame1SameEnum2InterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameEnum2InterfaceMsgBusAdapter();
	virtual ~UTbSame1SameEnum2InterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Remote")
	void StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Remote")
	void StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Remote")
	bool IsListening() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
	void setBackendService(TScriptInterface<ITbSame1SameEnum2InterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSame1SameEnum2InterfaceMsgBusEndpoint;

	void OnNewClientDiscovered(const FTbSame1SameEnum2InterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbSame1SameEnum2InterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Request(const FTbSame1SameEnum2InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc2Request(const FTbSame1SameEnum2InterfaceFunc2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp1Request(const FTbSame1SameEnum2InterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp2Request(const FTbSame1SameEnum2InterfaceSetProp2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnSig1(ETbSame1Enum1 Param1);

	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnSig2(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2);

	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(ETbSame1Enum1 Prop1);

	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnProp2Changed(ETbSame1Enum2 Prop2);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame1|SameEnum2Interface")
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> BackendService;

	TArray<FMessageAddress> ConnectedClients;
};
