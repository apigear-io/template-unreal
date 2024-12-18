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

#include "Generated/api/Testbed2NestedStruct3InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Testbed2NestedStruct3InterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTestbed2NestedStruct3InterfaceDiscoveryMessage;
struct FTestbed2NestedStruct3InterfacePingMessage;
struct FTestbed2NestedStruct3InterfaceClientDisconnectMessage;
struct FTestbed2NestedStruct3InterfaceSig1SignalMessage;
struct FTestbed2NestedStruct3InterfaceSig2SignalMessage;
struct FTestbed2NestedStruct3InterfaceSig3SignalMessage;
struct FTestbed2NestedStruct3InterfaceSetProp1RequestMessage;
struct FTestbed2NestedStruct3InterfaceProp1ChangedMessage;
struct FTestbed2NestedStruct3InterfaceSetProp2RequestMessage;
struct FTestbed2NestedStruct3InterfaceProp2ChangedMessage;
struct FTestbed2NestedStruct3InterfaceSetProp3RequestMessage;
struct FTestbed2NestedStruct3InterfaceProp3ChangedMessage;
struct FTestbed2NestedStruct3InterfaceFunc1RequestMessage;
struct FTestbed2NestedStruct3InterfaceFunc2RequestMessage;
struct FTestbed2NestedStruct3InterfaceFunc3RequestMessage;

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITestbed2NestedStruct3InterfaceInterface
/// and holds the corresponding Testbed2NestedStruct3InterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TESTBED2_API UTestbed2NestedStruct3InterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTestbed2NestedStruct3InterfaceMsgBusAdapter();
	virtual ~UTestbed2NestedStruct3InterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Remote")
	bool _IsListening() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	void _setBackendService(TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> Testbed2NestedStruct3InterfaceMsgBusEndpoint;

	void OnNewClientDiscovered(const FTestbed2NestedStruct3InterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTestbed2NestedStruct3InterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTestbed2NestedStruct3InterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Request(const FTestbed2NestedStruct3InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc2Request(const FTestbed2NestedStruct3InterfaceFunc2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc3Request(const FTestbed2NestedStruct3InterfaceFunc3RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp1Request(const FTestbed2NestedStruct3InterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp2Request(const FTestbed2NestedStruct3InterfaceSetProp2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp3Request(const FTestbed2NestedStruct3InterfaceSetProp3RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void OnSig1(const FTestbed2NestedStruct1& Param1);

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void OnSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void OnSig3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3);

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void OnProp2Changed(const FTestbed2NestedStruct2& Prop2);

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void OnProp3Changed(const FTestbed2NestedStruct3& Prop3);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> BackendService;

	TArray<FMessageAddress> ConnectedClients;
};