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

#include "TbIfaceimport/Generated/api/TbIfaceimportEmptyIfInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "TbIfaceimportEmptyIfMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbIfaceimportEmptyIfDiscoveryMessage;
struct FTbIfaceimportEmptyIfServiceAnnouncementReplyMessage;
struct FTbIfaceimportEmptyIfPingMessage;
struct FTbIfaceimportEmptyIfClientDisconnectMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbIfaceimportEmptyIfClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbIfaceimportEmptyIfClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbIfaceimportEmptyIfClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbIfaceimportEmptyIfClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTbIfaceimportEmptyIfMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbIfaceimportEmptyIfInterface
/// and holds the corresponding TbIfaceimportEmptyIfOLinkSource OLink source object
UCLASS(BlueprintType)
class TBIFACEIMPORTMSGBUS_API UTbIfaceimportEmptyIfMsgBusAdapter : public UGameInstanceSubsystem, public ITbIfaceimportEmptyIfSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbIfaceimportEmptyIfMsgBusAdapter();
	virtual ~UTbIfaceimportEmptyIfMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote", DisplayName = "New client connected")
	FTbIfaceimportEmptyIfClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote", DisplayName = "Client disconnected")
	FTbIfaceimportEmptyIfClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote", DisplayName = "Client timed out")
	FTbIfaceimportEmptyIfClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote", DisplayName = "Clients connected count changed")
	FTbIfaceimportEmptyIfClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf")
	void _setBackendService(TScriptInterface<ITbIfaceimportEmptyIfInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbIfaceimportEmptyIfMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTbIfaceimportEmptyIfDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTbIfaceimportEmptyIfServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbIfaceimportEmptyIfPingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbIfaceimportEmptyIfClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbIfaceimport|EmptyIf")
	TScriptInterface<ITbIfaceimportEmptyIfInterface> BackendService;

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
