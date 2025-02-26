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

#include "TbSimple/Generated/api/TbSimpleNoOperationsInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION < 5)
#include "Engine/EngineTypes.h"
#else
#include "Engine/TimerHandle.h"
#endif
#include "TbSimpleNoOperationsInterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbSimpleNoOperationsInterfaceDiscoveryMessage;
struct FTbSimpleNoOperationsInterfacePingMessage;
struct FTbSimpleNoOperationsInterfaceClientDisconnectMessage;
struct FTbSimpleNoOperationsInterfaceSigVoidSignalMessage;
struct FTbSimpleNoOperationsInterfaceSigBoolSignalMessage;
struct FTbSimpleNoOperationsInterfaceSetPropBoolRequestMessage;
struct FTbSimpleNoOperationsInterfacePropBoolChangedMessage;
struct FTbSimpleNoOperationsInterfaceSetPropIntRequestMessage;
struct FTbSimpleNoOperationsInterfacePropIntChangedMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfaceClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfaceClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfaceClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfaceClientCountDelegate, int32, Count);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbSimpleNoOperationsInterfaceInterface
/// and holds the corresponding TbSimpleNoOperationsInterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBSIMPLEMSGBUS_API UTbSimpleNoOperationsInterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSimpleNoOperationsInterfaceMsgBusAdapter();
	virtual ~UTbSimpleNoOperationsInterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote", DisplayName = "New client connected")
	FTbSimpleNoOperationsInterfaceClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote", DisplayName = "Client disconnected")
	FTbSimpleNoOperationsInterfaceClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote", DisplayName = "Client timed out")
	FTbSimpleNoOperationsInterfaceClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote", DisplayName = "Clients connected count changed")
	FTbSimpleNoOperationsInterfaceClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface")
	void _setBackendService(TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSimpleNoOperationsInterfaceMsgBusEndpoint;

	void OnNewClientDiscovered(const FTbSimpleNoOperationsInterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbSimpleNoOperationsInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbSimpleNoOperationsInterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropBoolRequest(const FTbSimpleNoOperationsInterfaceSetPropBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropIntRequest(const FTbSimpleNoOperationsInterfaceSetPropIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnSigVoid();

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnSigBool(bool bParamBool);

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(bool bPropBool);

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(int32 PropInt);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|NoOperationsInterface")
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> BackendService;

	// Heartbeat handling
	void _CheckClientTimeouts();
	void _UpdateClientsConnected();
	TMap<FMessageAddress, double> ConnectedClientsTimestamps;
	FTimerHandle _HeartbeatTimerHandle;
	int32 _ClientsConnected = 0;
	uint32 _HeartbeatIntervalMS = 1000;
};
