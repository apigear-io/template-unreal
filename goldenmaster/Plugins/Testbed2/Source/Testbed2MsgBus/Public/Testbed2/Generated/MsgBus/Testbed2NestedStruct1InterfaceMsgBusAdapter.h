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

#include "Testbed2/Generated/api/Testbed2NestedStruct1InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "Testbed2NestedStruct1InterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTestbed2NestedStruct1InterfaceDiscoveryMessage;
struct FTestbed2NestedStruct1InterfaceServiceAnnouncementReplyMessage;
struct FTestbed2NestedStruct1InterfacePingMessage;
struct FTestbed2NestedStruct1InterfaceClientDisconnectMessage;
struct FTestbed2NestedStruct1InterfaceSig1SignalMessage;
struct FTestbed2NestedStruct1InterfaceSetProp1RequestMessage;
struct FTestbed2NestedStruct1InterfaceProp1ChangedMessage;
struct FTestbed2NestedStruct1InterfaceFunc1RequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct1InterfaceClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct1InterfaceClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct1InterfaceClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct1InterfaceClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2NestedStruct1InterfaceMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITestbed2NestedStruct1InterfaceInterface
/// and holds the corresponding Testbed2NestedStruct1InterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TESTBED2MSGBUS_API UTestbed2NestedStruct1InterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTestbed2NestedStruct1InterfaceMsgBusAdapter();
	virtual ~UTestbed2NestedStruct1InterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote", DisplayName = "New client connected")
	FTestbed2NestedStruct1InterfaceClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote", DisplayName = "Client disconnected")
	FTestbed2NestedStruct1InterfaceClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote", DisplayName = "Client timed out")
	FTestbed2NestedStruct1InterfaceClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote", DisplayName = "Clients connected count changed")
	FTestbed2NestedStruct1InterfaceClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	void _setBackendService(TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> Testbed2NestedStruct1InterfaceMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTestbed2NestedStruct1InterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTestbed2NestedStruct1InterfaceServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTestbed2NestedStruct1InterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTestbed2NestedStruct1InterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Request(const FTestbed2NestedStruct1InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp1Request(const FTestbed2NestedStruct1InterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct1Interface", BlueprintInternalUseOnly)
	void OnSig1(const FTestbed2NestedStruct1& Param1);

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct1Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const FTestbed2NestedStruct1& Prop1);

	// delegate handles
	FDelegateHandle OnProp1ChangedHandle;
	FDelegateHandle OnSig1SignalHandle;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> BackendService;

	// Heartbeat handling
	void _CheckClientTimeouts();
	bool _CheckClientTimeoutsTick(float DeltaTime);
	void _UpdateClientsConnected();
	TMap<FMessageAddress, double> ConnectedClientsTimestamps;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	int32 _ClientsConnected = 0;
	uint32 _HeartbeatIntervalMS = 100;
};
