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

#include "Generated/api/Testbed1StructArrayInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION < 5)
#include "Engine/EngineTypes.h"
#else
#include "Engine/TimerHandle.h"
#endif
#include "Testbed1StructArrayInterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTestbed1StructArrayInterfaceDiscoveryMessage;
struct FTestbed1StructArrayInterfaceServiceAnnouncementReplyMessage;
struct FTestbed1StructArrayInterfacePingMessage;
struct FTestbed1StructArrayInterfaceClientDisconnectMessage;
struct FTestbed1StructArrayInterfaceSigBoolSignalMessage;
struct FTestbed1StructArrayInterfaceSigIntSignalMessage;
struct FTestbed1StructArrayInterfaceSigFloatSignalMessage;
struct FTestbed1StructArrayInterfaceSigStringSignalMessage;
struct FTestbed1StructArrayInterfaceSigEnumSignalMessage;
struct FTestbed1StructArrayInterfaceSetPropBoolRequestMessage;
struct FTestbed1StructArrayInterfacePropBoolChangedMessage;
struct FTestbed1StructArrayInterfaceSetPropIntRequestMessage;
struct FTestbed1StructArrayInterfacePropIntChangedMessage;
struct FTestbed1StructArrayInterfaceSetPropFloatRequestMessage;
struct FTestbed1StructArrayInterfacePropFloatChangedMessage;
struct FTestbed1StructArrayInterfaceSetPropStringRequestMessage;
struct FTestbed1StructArrayInterfacePropStringChangedMessage;
struct FTestbed1StructArrayInterfaceSetPropEnumRequestMessage;
struct FTestbed1StructArrayInterfacePropEnumChangedMessage;
struct FTestbed1StructArrayInterfaceFuncBoolRequestMessage;
struct FTestbed1StructArrayInterfaceFuncIntRequestMessage;
struct FTestbed1StructArrayInterfaceFuncFloatRequestMessage;
struct FTestbed1StructArrayInterfaceFuncStringRequestMessage;
struct FTestbed1StructArrayInterfaceFuncEnumRequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructArrayInterfaceMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITestbed1StructArrayInterfaceInterface
/// and holds the corresponding Testbed1StructArrayInterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TESTBED1_API UTestbed1StructArrayInterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructArrayInterfaceMsgBusAdapter();
	virtual ~UTestbed1StructArrayInterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote", DisplayName = "New client connected")
	FTestbed1StructArrayInterfaceClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote", DisplayName = "Client disconnected")
	FTestbed1StructArrayInterfaceClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote", DisplayName = "Client timed out")
	FTestbed1StructArrayInterfaceClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote", DisplayName = "Clients connected count changed")
	FTestbed1StructArrayInterfaceClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	void _setBackendService(TScriptInterface<ITestbed1StructArrayInterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> Testbed1StructArrayInterfaceMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTestbed1StructArrayInterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTestbed1StructArrayInterfaceServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTestbed1StructArrayInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTestbed1StructArrayInterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncBoolRequest(const FTestbed1StructArrayInterfaceFuncBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncIntRequest(const FTestbed1StructArrayInterfaceFuncIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloatRequest(const FTestbed1StructArrayInterfaceFuncFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncStringRequest(const FTestbed1StructArrayInterfaceFuncStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncEnumRequest(const FTestbed1StructArrayInterfaceFuncEnumRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropBoolRequest(const FTestbed1StructArrayInterfaceSetPropBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropIntRequest(const FTestbed1StructArrayInterfaceSetPropIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropFloatRequest(const FTestbed1StructArrayInterfaceSetPropFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropStringRequest(const FTestbed1StructArrayInterfaceSetPropStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropEnumRequest(const FTestbed1StructArrayInterfaceSetPropEnumRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnSigBool(const TArray<FTestbed1StructBool>& ParamBool);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnSigInt(const TArray<FTestbed1StructInt>& ParamInt);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnSigFloat(const TArray<FTestbed1StructFloat>& ParamFloat);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnSigString(const TArray<FTestbed1StructString>& ParamString);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnSigEnum(const TArray<ETestbed1Enum0>& ParamEnum);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(const TArray<FTestbed1StructBool>& PropBool);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(const TArray<FTestbed1StructInt>& PropInt);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnPropFloatChanged(const TArray<FTestbed1StructFloat>& PropFloat);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnPropStringChanged(const TArray<FTestbed1StructString>& PropString);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnPropEnumChanged(const TArray<ETestbed1Enum0>& PropEnum);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructArrayInterface")
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> BackendService;

	// Heartbeat handling
	void _CheckClientTimeouts();
	void _UpdateClientsConnected();
	TMap<FMessageAddress, double> ConnectedClientsTimestamps;
	FTimerHandle _HeartbeatTimerHandle;
	int32 _ClientsConnected = 0;
	uint32 _HeartbeatIntervalMS = 100;
};
