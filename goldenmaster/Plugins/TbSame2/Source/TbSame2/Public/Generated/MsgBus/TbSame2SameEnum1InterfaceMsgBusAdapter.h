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

#include "Generated/api/TbSame2SameEnum1InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "TbSame2SameEnum1InterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbSame2SameEnum1InterfaceDiscoveryMessage;
struct FTbSame2SameEnum1InterfacePingMessage;
struct FTbSame2SameEnum1InterfaceClientDisconnectMessage;
struct FTbSame2SameEnum1InterfaceSig1SignalMessage;
struct FTbSame2SameEnum1InterfaceSetProp1RequestMessage;
struct FTbSame2SameEnum1InterfaceProp1ChangedMessage;
struct FTbSame2SameEnum1InterfaceFunc1RequestMessage;

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbSame2SameEnum1InterfaceInterface
/// and holds the corresponding TbSame2SameEnum1InterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBSAME2_API UTbSame2SameEnum1InterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameEnum1InterfaceMsgBusAdapter();
	virtual ~UTbSame2SameEnum1InterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum1Interface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum1Interface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum1Interface|Remote")
	bool _IsListening() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum1Interface")
	void _setBackendService(TScriptInterface<ITbSame2SameEnum1InterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSame2SameEnum1InterfaceMsgBusEndpoint;

	void OnNewClientDiscovered(const FTbSame2SameEnum1InterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbSame2SameEnum1InterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbSame2SameEnum1InterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Request(const FTbSame2SameEnum1InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp1Request(const FTbSame2SameEnum1InterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|TbSame2|SameEnum1Interface", BlueprintInternalUseOnly)
	void OnSig1(ETbSame2Enum1 Param1);

	UFUNCTION(Category = "ApiGear|TbSame2|SameEnum1Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(ETbSame2Enum1 Prop1);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame2|SameEnum1Interface")
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> BackendService;

	TArray<FMessageAddress> ConnectedClients;
};
