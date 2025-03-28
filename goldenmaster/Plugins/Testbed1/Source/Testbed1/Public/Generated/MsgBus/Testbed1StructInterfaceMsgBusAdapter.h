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

#include "Generated/api/Testbed1StructInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION < 5)
#include "Engine/EngineTypes.h"
#else
#include "Engine/TimerHandle.h"
#endif
#include "Testbed1StructInterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTestbed1StructInterfaceDiscoveryMessage;
struct FTestbed1StructInterfaceServiceAnnouncementReplyMessage;
struct FTestbed1StructInterfacePingMessage;
struct FTestbed1StructInterfaceClientDisconnectMessage;
struct FTestbed1StructInterfaceSigBoolSignalMessage;
struct FTestbed1StructInterfaceSigIntSignalMessage;
struct FTestbed1StructInterfaceSigFloatSignalMessage;
struct FTestbed1StructInterfaceSigStringSignalMessage;
struct FTestbed1StructInterfaceSetPropBoolRequestMessage;
struct FTestbed1StructInterfacePropBoolChangedMessage;
struct FTestbed1StructInterfaceSetPropIntRequestMessage;
struct FTestbed1StructInterfacePropIntChangedMessage;
struct FTestbed1StructInterfaceSetPropFloatRequestMessage;
struct FTestbed1StructInterfacePropFloatChangedMessage;
struct FTestbed1StructInterfaceSetPropStringRequestMessage;
struct FTestbed1StructInterfacePropStringChangedMessage;
struct FTestbed1StructInterfaceFuncBoolRequestMessage;
struct FTestbed1StructInterfaceFuncIntRequestMessage;
struct FTestbed1StructInterfaceFuncFloatRequestMessage;
struct FTestbed1StructInterfaceFuncStringRequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfaceClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfaceClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfaceClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfaceClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructInterfaceMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITestbed1StructInterfaceInterface
/// and holds the corresponding Testbed1StructInterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TESTBED1_API UTestbed1StructInterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructInterfaceMsgBusAdapter();
	virtual ~UTestbed1StructInterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Remote", DisplayName = "New client connected")
	FTestbed1StructInterfaceClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Remote", DisplayName = "Client disconnected")
	FTestbed1StructInterfaceClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Remote", DisplayName = "Client timed out")
	FTestbed1StructInterfaceClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Remote", DisplayName = "Clients connected count changed")
	FTestbed1StructInterfaceClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void _setBackendService(TScriptInterface<ITestbed1StructInterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> Testbed1StructInterfaceMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTestbed1StructInterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTestbed1StructInterfaceServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTestbed1StructInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTestbed1StructInterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncBoolRequest(const FTestbed1StructInterfaceFuncBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncIntRequest(const FTestbed1StructInterfaceFuncIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloatRequest(const FTestbed1StructInterfaceFuncFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncStringRequest(const FTestbed1StructInterfaceFuncStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropBoolRequest(const FTestbed1StructInterfaceSetPropBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropIntRequest(const FTestbed1StructInterfaceSetPropIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropFloatRequest(const FTestbed1StructInterfaceSetPropFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropStringRequest(const FTestbed1StructInterfaceSetPropStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigBool(const FTestbed1StructBool& ParamBool);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigInt(const FTestbed1StructInt& ParamInt);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigFloat(const FTestbed1StructFloat& ParamFloat);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigString(const FTestbed1StructString& ParamString);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(const FTestbed1StructBool& PropBool);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(const FTestbed1StructInt& PropInt);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropFloatChanged(const FTestbed1StructFloat& PropFloat);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropStringChanged(const FTestbed1StructString& PropString);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructInterface")
	TScriptInterface<ITestbed1StructInterfaceInterface> BackendService;

	// Heartbeat handling
	void _CheckClientTimeouts();
	void _UpdateClientsConnected();
	TMap<FMessageAddress, double> ConnectedClientsTimestamps;
	FTimerHandle _HeartbeatTimerHandle;
	int32 _ClientsConnected = 0;
	uint32 _HeartbeatIntervalMS = 100;
};
