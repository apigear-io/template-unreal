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

#include "TbNames/Generated/api/TbNamesNamEsInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION < 5)
#include "Engine/EngineTypes.h"
#else
#include "Engine/TimerHandle.h"
#endif
#include "TbNamesNamEsMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbNamesNamEsDiscoveryMessage;
struct FTbNamesNamEsServiceAnnouncementReplyMessage;
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
struct FTbNamesNamEsSetEnumPropertyRequestMessage;
struct FTbNamesNamEsEnumPropertyChangedMessage;
struct FTbNamesNamEsSomeFunctionRequestMessage;
struct FTbNamesNamEsSomeFunction2RequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTbNamesNamEsMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbNamesNamEsInterface
/// and holds the corresponding TbNamesNamEsOLinkSource OLink source object
UCLASS(BlueprintType)
class TBNAMESMSGBUS_API UTbNamesNamEsMsgBusAdapter : public UGameInstanceSubsystem
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

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Remote", DisplayName = "New client connected")
	FTbNamesNamEsClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Remote", DisplayName = "Client disconnected")
	FTbNamesNamEsClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Remote", DisplayName = "Client timed out")
	FTbNamesNamEsClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Remote", DisplayName = "Clients connected count changed")
	FTbNamesNamEsClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs")
	void _setBackendService(TScriptInterface<ITbNamesNamEsInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbNamesNamEsMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTbNamesNamEsDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTbNamesNamEsServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbNamesNamEsPingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbNamesNamEsClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSomeFunctionRequest(const FTbNamesNamEsSomeFunctionRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSomeFunction2Request(const FTbNamesNamEsSomeFunction2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetSwitchRequest(const FTbNamesNamEsSetSwitchRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetSomePropertyRequest(const FTbNamesNamEsSetSomePropertyRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetSomePoperty2Request(const FTbNamesNamEsSetSomePoperty2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetEnumPropertyRequest(const FTbNamesNamEsSetEnumPropertyRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

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

	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnEnumPropertyChanged(ETbNamesEnum_With_Under_scores EnumProperty);

	// delegate handles
	FDelegateHandle OnSwitchChangedHandle;
	FDelegateHandle OnSomePropertyChangedHandle;
	FDelegateHandle OnSomePoperty2ChangedHandle;
	FDelegateHandle OnEnumPropertyChangedHandle;
	FDelegateHandle OnSomeSignalSignalHandle;
	FDelegateHandle OnSomeSignal2SignalHandle;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbNames|NamEs")
	TScriptInterface<ITbNamesNamEsInterface> BackendService;

	// Heartbeat handling
	void _CheckClientTimeouts();
	void _UpdateClientsConnected();
	TMap<FMessageAddress, double> ConnectedClientsTimestamps;
	FTimerHandle _HeartbeatTimerHandle;
	int32 _ClientsConnected = 0;
	uint32 _HeartbeatIntervalMS = 100;
};
