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

#include "TbSimple/Generated/api/TbSimpleNoPropertiesInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION < 5)
#include "Engine/EngineTypes.h"
#else
#include "Engine/TimerHandle.h"
#endif
#include "TbSimpleNoPropertiesInterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbSimpleNoPropertiesInterfaceDiscoveryMessage;
struct FTbSimpleNoPropertiesInterfacePingMessage;
struct FTbSimpleNoPropertiesInterfaceClientDisconnectMessage;
struct FTbSimpleNoPropertiesInterfaceSigVoidSignalMessage;
struct FTbSimpleNoPropertiesInterfaceSigBoolSignalMessage;
struct FTbSimpleNoPropertiesInterfaceFuncVoidRequestMessage;
struct FTbSimpleNoPropertiesInterfaceFuncBoolRequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoPropertiesInterfaceClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoPropertiesInterfaceClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoPropertiesInterfaceClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoPropertiesInterfaceClientCountDelegate, int32, Count);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbSimpleNoPropertiesInterfaceInterface
/// and holds the corresponding TbSimpleNoPropertiesInterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBSIMPLEMSGBUS_API UTbSimpleNoPropertiesInterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSimpleNoPropertiesInterfaceMsgBusAdapter();
	virtual ~UTbSimpleNoPropertiesInterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote", DisplayName = "New client connected")
	FTbSimpleNoPropertiesInterfaceClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote", DisplayName = "Client disconnected")
	FTbSimpleNoPropertiesInterfaceClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote", DisplayName = "Client timed out")
	FTbSimpleNoPropertiesInterfaceClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote", DisplayName = "Clients connected count changed")
	FTbSimpleNoPropertiesInterfaceClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface")
	void _setBackendService(TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSimpleNoPropertiesInterfaceMsgBusEndpoint;

	void OnNewClientDiscovered(const FTbSimpleNoPropertiesInterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbSimpleNoPropertiesInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbSimpleNoPropertiesInterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncVoidRequest(const FTbSimpleNoPropertiesInterfaceFuncVoidRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncBoolRequest(const FTbSimpleNoPropertiesInterfaceFuncBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|NoPropertiesInterface", BlueprintInternalUseOnly)
	void OnSigVoid();

	UFUNCTION(Category = "ApiGear|TbSimple|NoPropertiesInterface", BlueprintInternalUseOnly)
	void OnSigBool(bool bParamBool);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|NoPropertiesInterface")
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> BackendService;

	// Heartbeat handling
	void _CheckClientTimeouts();
	void _UpdateClientsConnected();
	TMap<FMessageAddress, double> ConnectedClientsTimestamps;
	FTimerHandle _HeartbeatTimerHandle;
	int32 _ClientsConnected = 0;
	uint32 _HeartbeatIntervalMS = 1000;
};
