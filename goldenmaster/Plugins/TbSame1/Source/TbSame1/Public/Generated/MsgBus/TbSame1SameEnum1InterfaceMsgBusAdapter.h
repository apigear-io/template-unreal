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

#include "TbSame1/Generated/api/TbSame1SameEnum1InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION < 5)
#include "Engine/EngineTypes.h"
#else
#include "Engine/TimerHandle.h"
#endif
#include "TbSame1SameEnum1InterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbSame1SameEnum1InterfaceDiscoveryMessage;
struct FTbSame1SameEnum1InterfacePingMessage;
struct FTbSame1SameEnum1InterfaceClientDisconnectMessage;
struct FTbSame1SameEnum1InterfaceSig1SignalMessage;
struct FTbSame1SameEnum1InterfaceSetProp1RequestMessage;
struct FTbSame1SameEnum1InterfaceProp1ChangedMessage;
struct FTbSame1SameEnum1InterfaceFunc1RequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum1InterfaceClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum1InterfaceClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum1InterfaceClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum1InterfaceClientCountDelegate, int32, Count);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbSame1SameEnum1InterfaceInterface
/// and holds the corresponding TbSame1SameEnum1InterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBSAME1_API UTbSame1SameEnum1InterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameEnum1InterfaceMsgBusAdapter();
	virtual ~UTbSame1SameEnum1InterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote", DisplayName = "New client connected")
	FTbSame1SameEnum1InterfaceClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote", DisplayName = "Client disconnected")
	FTbSame1SameEnum1InterfaceClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote", DisplayName = "Client timed out")
	FTbSame1SameEnum1InterfaceClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote", DisplayName = "Clients connected count changed")
	FTbSame1SameEnum1InterfaceClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
	void _setBackendService(TScriptInterface<ITbSame1SameEnum1InterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSame1SameEnum1InterfaceMsgBusEndpoint;

	void OnNewClientDiscovered(const FTbSame1SameEnum1InterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbSame1SameEnum1InterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbSame1SameEnum1InterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Request(const FTbSame1SameEnum1InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp1Request(const FTbSame1SameEnum1InterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum1Interface", BlueprintInternalUseOnly)
	void OnSig1(ETbSame1Enum1 Param1);

	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum1Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(ETbSame1Enum1 Prop1);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame1|SameEnum1Interface")
	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> BackendService;

	// Heartbeat handling
	void _CheckClientTimeouts();
	void _UpdateClientsConnected();
	TMap<FMessageAddress, double> ConnectedClientsTimestamps;
	FTimerHandle _HeartbeatTimerHandle;
	int32 _ClientsConnected = 0;
	uint32 _HeartbeatIntervalMS = 1000;
};
