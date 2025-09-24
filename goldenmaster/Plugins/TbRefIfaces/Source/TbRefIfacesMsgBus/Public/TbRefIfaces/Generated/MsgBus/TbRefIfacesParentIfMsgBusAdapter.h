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

#include "TbRefIfaces/Generated/api/TbRefIfacesParentIfInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "TbRefIfacesParentIfMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbRefIfacesParentIfDiscoveryMessage;
struct FTbRefIfacesParentIfServiceAnnouncementReplyMessage;
struct FTbRefIfacesParentIfPingMessage;
struct FTbRefIfacesParentIfClientDisconnectMessage;
struct FTbRefIfacesParentIfLocalIfSignalSignalMessage;
struct FTbRefIfacesParentIfLocalIfSignalListSignalMessage;
struct FTbRefIfacesParentIfImportedIfSignalSignalMessage;
struct FTbRefIfacesParentIfImportedIfSignalListSignalMessage;
struct FTbRefIfacesParentIfSetLocalIfRequestMessage;
struct FTbRefIfacesParentIfLocalIfChangedMessage;
struct FTbRefIfacesParentIfSetLocalIfListRequestMessage;
struct FTbRefIfacesParentIfLocalIfListChangedMessage;
struct FTbRefIfacesParentIfSetImportedIfRequestMessage;
struct FTbRefIfacesParentIfImportedIfChangedMessage;
struct FTbRefIfacesParentIfSetImportedIfListRequestMessage;
struct FTbRefIfacesParentIfImportedIfListChangedMessage;
struct FTbRefIfacesParentIfLocalIfMethodRequestMessage;
struct FTbRefIfacesParentIfLocalIfMethodListRequestMessage;
struct FTbRefIfacesParentIfImportedIfMethodRequestMessage;
struct FTbRefIfacesParentIfImportedIfMethodListRequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTbRefIfacesParentIfMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbRefIfacesParentIfInterface
/// and holds the corresponding TbRefIfacesParentIfOLinkSource OLink source object
UCLASS(BlueprintType)
class TBREFIFACESMSGBUS_API UTbRefIfacesParentIfMsgBusAdapter : public UGameInstanceSubsystem, public ITbRefIfacesParentIfSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbRefIfacesParentIfMsgBusAdapter();
	virtual ~UTbRefIfacesParentIfMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Remote", DisplayName = "New client connected")
	FTbRefIfacesParentIfClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Remote", DisplayName = "Client disconnected")
	FTbRefIfacesParentIfClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Remote", DisplayName = "Client timed out")
	FTbRefIfacesParentIfClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Remote", DisplayName = "Clients connected count changed")
	FTbRefIfacesParentIfClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf")
	void _setBackendService(TScriptInterface<ITbRefIfacesParentIfInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbRefIfacesParentIfMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTbRefIfacesParentIfDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTbRefIfacesParentIfServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbRefIfacesParentIfPingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbRefIfacesParentIfClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnLocalIfMethodRequest(const FTbRefIfacesParentIfLocalIfMethodRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnLocalIfMethodListRequest(const FTbRefIfacesParentIfLocalIfMethodListRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnImportedIfMethodRequest(const FTbRefIfacesParentIfImportedIfMethodRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnImportedIfMethodListRequest(const FTbRefIfacesParentIfImportedIfMethodListRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetLocalIfRequest(const FTbRefIfacesParentIfSetLocalIfRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetLocalIfListRequest(const FTbRefIfacesParentIfSetLocalIfListRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetImportedIfRequest(const FTbRefIfacesParentIfSetImportedIfRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetImportedIfListRequest(const FTbRefIfacesParentIfSetImportedIfListRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	void OnLocalIfSignalSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override;

	void OnLocalIfSignalListSignal(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) override;

	void OnImportedIfSignalSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override;

	void OnImportedIfSignalListSignal(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) override;

	void OnLocalIfChanged(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& LocalIf) override;

	void OnLocalIfListChanged(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& LocalIfList) override;

	void OnImportedIfChanged(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& ImportedIf) override;

	void OnImportedIfListChanged(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& ImportedIfList) override;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefIfaces|ParentIf")
	TScriptInterface<ITbRefIfacesParentIfInterface> BackendService;

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
