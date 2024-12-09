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

#include "Generated/api/AbstractTestbed2NestedStruct1Interface.h"
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
#include "Testbed2NestedStruct1InterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTestbed2NestedStruct1InterfaceInitMessage;
struct FTestbed2NestedStruct1InterfaceServiceDisconnectMessage;
struct FTestbed2NestedStruct1InterfaceSig1SignalMessage;
struct FTestbed2NestedStruct1InterfaceProp1ChangedMessage;
struct FTestbed2NestedStruct1InterfaceFunc1ReplyMessage;

struct Testbed2NestedStruct1InterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2NestedStruct1InterfaceMsgBusClient, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct1InterfaceConnectionStatusChangedDelegate, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED2_API UTestbed2NestedStruct1InterfaceMsgBusClient : public UAbstractTestbed2NestedStruct1Interface
{
	GENERATED_BODY()
public:
	explicit UTestbed2NestedStruct1InterfaceMsgBusClient();
	virtual ~UTestbed2NestedStruct1InterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote")
	void Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote")
	void Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote")
	bool IsConnected() const;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote", DisplayName = "Connection Status Changed")
	FTestbed2NestedStruct1InterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	FTestbed2NestedStruct1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTestbed2NestedStruct1& Prop1) override;

	// operations
	FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> Testbed2NestedStruct1InterfaceMsgBusEndpoint;

	void DiscoverService();
	FMessageAddress ServiceAddress;

	// connection handling
	void OnConnectionInit(const FTestbed2NestedStruct1InterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTestbed2NestedStruct1InterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig1(const FTestbed2NestedStruct1InterfaceSig1SignalMessage& InSig1Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp1Changed(const FTestbed2NestedStruct1InterfaceProp1ChangedMessage& InProp1Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Reply(const FTestbed2NestedStruct1InterfaceFunc1ReplyMessage& InFunc1Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<Testbed2NestedStruct1InterfacePropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
