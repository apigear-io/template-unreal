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

#include "Generated/api/AbstractTestbed2ManyParamInterface.h"
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
#include "Testbed2ManyParamInterfaceMsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct FTestbed2ManyParamInterfaceInitMessage;
struct FTestbed2ManyParamInterfaceServiceDisconnectMessage;
struct FTestbed2ManyParamInterfaceSig1SignalMessage;
struct FTestbed2ManyParamInterfaceSig2SignalMessage;
struct FTestbed2ManyParamInterfaceSig3SignalMessage;
struct FTestbed2ManyParamInterfaceSig4SignalMessage;
struct FTestbed2ManyParamInterfaceProp1ChangedMessage;
struct FTestbed2ManyParamInterfaceProp2ChangedMessage;
struct FTestbed2ManyParamInterfaceProp3ChangedMessage;
struct FTestbed2ManyParamInterfaceProp4ChangedMessage;
struct FTestbed2ManyParamInterfaceFunc1ReplyMessage;
struct FTestbed2ManyParamInterfaceFunc2ReplyMessage;
struct FTestbed2ManyParamInterfaceFunc3ReplyMessage;
struct FTestbed2ManyParamInterfaceFunc4ReplyMessage;

struct Testbed2ManyParamInterfacePropertiesMsgBusData;
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2ManyParamInterfaceMsgBusClient, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceConnectionStatusChangedDelegate, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED2_API UTestbed2ManyParamInterfaceMsgBusClient : public UAbstractTestbed2ManyParamInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed2ManyParamInterfaceMsgBusClient();
	virtual ~UTestbed2ManyParamInterfaceMsgBusClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote")
	void Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote")
	void Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote")
	bool IsConnected() const;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote", DisplayName = "Connection Status Changed")
	FTestbed2ManyParamInterfaceConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
	int32 GetProp1_Implementation() const override;
	void SetProp1_Implementation(int32 Prop1) override;

	int32 GetProp2_Implementation() const override;
	void SetProp2_Implementation(int32 Prop2) override;

	int32 GetProp3_Implementation() const override;
	void SetProp3_Implementation(int32 Prop3) override;

	int32 GetProp4_Implementation() const override;
	void SetProp4_Implementation(int32 Prop4) override;

	// operations
	int32 Func1_Implementation(int32 Param1) override;

	int32 Func2_Implementation(int32 Param1, int32 Param2) override;

	int32 Func3_Implementation(int32 Param1, int32 Param2, int32 Param3) override;

	int32 Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> Testbed2ManyParamInterfaceMsgBusEndpoint;

	void DiscoverService();
	FMessageAddress ServiceAddress;

	// connection handling
	void OnConnectionInit(const FTestbed2ManyParamInterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const FTestbed2ManyParamInterfaceServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig1(const FTestbed2ManyParamInterfaceSig1SignalMessage& InSig1Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig2(const FTestbed2ManyParamInterfaceSig2SignalMessage& InSig2Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig3(const FTestbed2ManyParamInterfaceSig3SignalMessage& InSig3Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSig4(const FTestbed2ManyParamInterfaceSig4SignalMessage& InSig4Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp1Changed(const FTestbed2ManyParamInterfaceProp1ChangedMessage& InProp1Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp2Changed(const FTestbed2ManyParamInterfaceProp2ChangedMessage& InProp2Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp3Changed(const FTestbed2ManyParamInterfaceProp3ChangedMessage& InProp3Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnProp4Changed(const FTestbed2ManyParamInterfaceProp4ChangedMessage& InProp4Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Reply(const FTestbed2ManyParamInterfaceFunc1ReplyMessage& InFunc1Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc2Reply(const FTestbed2ManyParamInterfaceFunc2ReplyMessage& InFunc2Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc3Reply(const FTestbed2ManyParamInterfaceFunc3ReplyMessage& InFunc3Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc4Reply(const FTestbed2ManyParamInterfaceFunc4ReplyMessage& InFunc4Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// member variable to store the last sent data
	TPimplPtr<Testbed2ManyParamInterfacePropertiesMsgBusData> _SentData;

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
};
