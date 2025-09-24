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

#include "Testbed1/Generated/api/Testbed1StructArray2InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "Testbed1StructArray2InterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTestbed1StructArray2InterfaceDiscoveryMessage;
struct FTestbed1StructArray2InterfaceServiceAnnouncementReplyMessage;
struct FTestbed1StructArray2InterfacePingMessage;
struct FTestbed1StructArray2InterfaceClientDisconnectMessage;
struct FTestbed1StructArray2InterfaceSigBoolSignalMessage;
struct FTestbed1StructArray2InterfaceSigIntSignalMessage;
struct FTestbed1StructArray2InterfaceSigFloatSignalMessage;
struct FTestbed1StructArray2InterfaceSigStringSignalMessage;
struct FTestbed1StructArray2InterfaceSetPropBoolRequestMessage;
struct FTestbed1StructArray2InterfacePropBoolChangedMessage;
struct FTestbed1StructArray2InterfaceSetPropIntRequestMessage;
struct FTestbed1StructArray2InterfacePropIntChangedMessage;
struct FTestbed1StructArray2InterfaceSetPropFloatRequestMessage;
struct FTestbed1StructArray2InterfacePropFloatChangedMessage;
struct FTestbed1StructArray2InterfaceSetPropStringRequestMessage;
struct FTestbed1StructArray2InterfacePropStringChangedMessage;
struct FTestbed1StructArray2InterfaceSetPropEnumRequestMessage;
struct FTestbed1StructArray2InterfacePropEnumChangedMessage;
struct FTestbed1StructArray2InterfaceFuncBoolRequestMessage;
struct FTestbed1StructArray2InterfaceFuncIntRequestMessage;
struct FTestbed1StructArray2InterfaceFuncFloatRequestMessage;
struct FTestbed1StructArray2InterfaceFuncStringRequestMessage;
struct FTestbed1StructArray2InterfaceFuncEnumRequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructArray2InterfaceMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITestbed1StructArray2InterfaceInterface
/// and holds the corresponding Testbed1StructArray2InterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TESTBED1MSGBUS_API UTestbed1StructArray2InterfaceMsgBusAdapter : public UGameInstanceSubsystem, public ITestbed1StructArray2InterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructArray2InterfaceMsgBusAdapter();
	virtual ~UTestbed1StructArray2InterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote", DisplayName = "New client connected")
	FTestbed1StructArray2InterfaceClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote", DisplayName = "Client disconnected")
	FTestbed1StructArray2InterfaceClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote", DisplayName = "Client timed out")
	FTestbed1StructArray2InterfaceClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote", DisplayName = "Clients connected count changed")
	FTestbed1StructArray2InterfaceClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface")
	void _setBackendService(TScriptInterface<ITestbed1StructArray2InterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> Testbed1StructArray2InterfaceMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTestbed1StructArray2InterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTestbed1StructArray2InterfaceServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTestbed1StructArray2InterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTestbed1StructArray2InterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncBoolRequest(const FTestbed1StructArray2InterfaceFuncBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncIntRequest(const FTestbed1StructArray2InterfaceFuncIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloatRequest(const FTestbed1StructArray2InterfaceFuncFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncStringRequest(const FTestbed1StructArray2InterfaceFuncStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncEnumRequest(const FTestbed1StructArray2InterfaceFuncEnumRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropBoolRequest(const FTestbed1StructArray2InterfaceSetPropBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropIntRequest(const FTestbed1StructArray2InterfaceSetPropIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropFloatRequest(const FTestbed1StructArray2InterfaceSetPropFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropStringRequest(const FTestbed1StructArray2InterfaceSetPropStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropEnumRequest(const FTestbed1StructArray2InterfaceSetPropEnumRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	void OnSigBoolSignal(const FTestbed1StructBoolWithArray& ParamBool) override;

	void OnSigIntSignal(const FTestbed1StructIntWithArray& ParamInt) override;

	void OnSigFloatSignal(const FTestbed1StructFloatWithArray& ParamFloat) override;

	void OnSigStringSignal(const FTestbed1StructStringWithArray& ParamString) override;

	void OnPropBoolChanged(const FTestbed1StructBoolWithArray& PropBool) override;

	void OnPropIntChanged(const FTestbed1StructIntWithArray& PropInt) override;

	void OnPropFloatChanged(const FTestbed1StructFloatWithArray& PropFloat) override;

	void OnPropStringChanged(const FTestbed1StructStringWithArray& PropString) override;

	void OnPropEnumChanged(const FTestbed1StructEnumWithArray& PropEnum) override;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructArray2Interface")
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> BackendService;

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
