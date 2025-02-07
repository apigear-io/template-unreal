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

#include "Generated/api/TbNamesNamEsInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "TbNamesNamEsMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbNamesNamEsDiscoveryMessage;
struct FTbNamesNamEsPingMessage;
struct FTbNamesNamEsClientDisconnectMessage;
struct FTbNamesNamEsSomeSignalSignalMessage;
struct FTbNamesNamEsSomeSignal2SignalMessage;
struct FTbNamesNamEsSetSwitchRequestMessage;
struct FTbNamesNamEsSwitchChangedMessage;
struct FTbNamesNamEsSetSomePropertyRequestMessage;
struct FTbNamesNamEsSomePropertyChangedMessage;
struct FTbNamesNamEsSetSomePoperty2RequestMessage;
struct FTbNamesNamEsSomePoperty2ChangedMessage;
struct FTbNamesNamEsSomeFunctionRequestMessage;
struct FTbNamesNamEsSomeFunction2RequestMessage;

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbNamesNamEsInterface
/// and holds the corresponding TbNamesNamEsOLinkSource OLink source object
UCLASS(BlueprintType)
class TBNAMES_API UTbNamesNamEsMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbNamesNamEsMsgBusAdapter();
	virtual ~UTbNamesNamEsMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Remote")
	bool _IsListening() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs")
	void _setBackendService(TScriptInterface<ITbNamesNamEsInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbNamesNamEsMsgBusEndpoint;

	void OnNewClientDiscovered(const FTbNamesNamEsDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbNamesNamEsPingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbNamesNamEsClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSomeFunctionRequest(const FTbNamesNamEsSomeFunctionRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSomeFunction2Request(const FTbNamesNamEsSomeFunction2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetSwitchRequest(const FTbNamesNamEsSetSwitchRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetSomePropertyRequest(const FTbNamesNamEsSetSomePropertyRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetSomePoperty2Request(const FTbNamesNamEsSetSomePoperty2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSomeSignal(bool bSomeParam);

	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSomeSignal2(bool bSomeParam);

	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSwitchChanged(bool bSwitch);

	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSomePropertyChanged(int32 SomeProperty);

	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSomePoperty2Changed(int32 SomePoperty2);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbNames|NamEs")
	TScriptInterface<ITbNamesNamEsInterface> BackendService;

	TArray<FMessageAddress> ConnectedClients;

	uint32 _HeartbeatIntervalMS = 1000;
};
