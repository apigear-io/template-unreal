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

#include "Generated/api/TbSimpleEmptyInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "TbSimpleEmptyInterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbSimpleEmptyInterfaceDiscoveryMessage;
struct FTbSimpleEmptyInterfacePingMessage;
struct FTbSimpleEmptyInterfaceClientDisconnectMessage;

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbSimpleEmptyInterfaceInterface
/// and holds the corresponding TbSimpleEmptyInterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleEmptyInterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSimpleEmptyInterfaceMsgBusAdapter();
	virtual ~UTbSimpleEmptyInterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|EmptyInterface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|EmptyInterface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|EmptyInterface|Remote")
	bool _IsListening() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|EmptyInterface")
	void _setBackendService(TScriptInterface<ITbSimpleEmptyInterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSimpleEmptyInterfaceMsgBusEndpoint;

	void OnNewClientDiscovered(const FTbSimpleEmptyInterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbSimpleEmptyInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbSimpleEmptyInterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|EmptyInterface")
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> BackendService;

	TArray<FMessageAddress> ConnectedClients;

	uint32 _HeartbeatIntervalMS = 1000;
};
