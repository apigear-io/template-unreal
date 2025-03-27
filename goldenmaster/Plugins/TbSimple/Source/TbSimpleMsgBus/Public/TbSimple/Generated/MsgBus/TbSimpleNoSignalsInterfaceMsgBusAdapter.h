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

#include "TbSimple/Generated/api/TbSimpleNoSignalsInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION < 5)
#include "Engine/EngineTypes.h"
#else
#include "Engine/TimerHandle.h"
#endif
#include "TbSimpleNoSignalsInterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbSimpleNoSignalsInterfaceDiscoveryMessage;
struct FTbSimpleNoSignalsInterfacePingMessage;
struct FTbSimpleNoSignalsInterfaceClientDisconnectMessage;
struct FTbSimpleNoSignalsInterfaceSetPropBoolRequestMessage;
struct FTbSimpleNoSignalsInterfacePropBoolChangedMessage;
struct FTbSimpleNoSignalsInterfaceSetPropIntRequestMessage;
struct FTbSimpleNoSignalsInterfacePropIntChangedMessage;
struct FTbSimpleNoSignalsInterfaceFuncVoidRequestMessage;
struct FTbSimpleNoSignalsInterfaceFuncBoolRequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoSignalsInterfaceClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoSignalsInterfaceClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoSignalsInterfaceClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoSignalsInterfaceClientCountDelegate, int32, Count);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbSimpleNoSignalsInterfaceInterface
/// and holds the corresponding TbSimpleNoSignalsInterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBSIMPLEMSGBUS_API UTbSimpleNoSignalsInterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSimpleNoSignalsInterfaceMsgBusAdapter();
	virtual ~UTbSimpleNoSignalsInterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoSignalsInterface|Remote", DisplayName = "New client connected")
	FTbSimpleNoSignalsInterfaceClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoSignalsInterface|Remote", DisplayName = "Client disconnected")
	FTbSimpleNoSignalsInterfaceClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoSignalsInterface|Remote", DisplayName = "Client timed out")
	FTbSimpleNoSignalsInterfaceClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoSignalsInterface|Remote", DisplayName = "Clients connected count changed")
	FTbSimpleNoSignalsInterfaceClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface")
	void _setBackendService(TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSimpleNoSignalsInterfaceMsgBusEndpoint;

	void OnNewClientDiscovered(const FTbSimpleNoSignalsInterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbSimpleNoSignalsInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbSimpleNoSignalsInterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncVoidRequest(const FTbSimpleNoSignalsInterfaceFuncVoidRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncBoolRequest(const FTbSimpleNoSignalsInterfaceFuncBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropBoolRequest(const FTbSimpleNoSignalsInterfaceSetPropBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropIntRequest(const FTbSimpleNoSignalsInterfaceSetPropIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals

	UFUNCTION(Category = "ApiGear|TbSimple|NoSignalsInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(bool bPropBool);

	UFUNCTION(Category = "ApiGear|TbSimple|NoSignalsInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(int32 PropInt);

	// delegate handles
	FDelegateHandle OnPropBoolChangedHandle;
	FDelegateHandle OnPropIntChangedHandle;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|NoSignalsInterface")
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> BackendService;

	// Heartbeat handling
	void _CheckClientTimeouts();
	void _UpdateClientsConnected();
	TMap<FMessageAddress, double> ConnectedClientsTimestamps;
	FTimerHandle _HeartbeatTimerHandle;
	int32 _ClientsConnected = 0;
	uint32 _HeartbeatIntervalMS = 100;
};
