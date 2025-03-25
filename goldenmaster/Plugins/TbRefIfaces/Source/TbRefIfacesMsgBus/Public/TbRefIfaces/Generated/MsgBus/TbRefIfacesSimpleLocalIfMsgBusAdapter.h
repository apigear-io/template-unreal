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

#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "TbRefIfacesSimpleLocalIfMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbRefIfacesSimpleLocalIfDiscoveryMessage;
struct FTbRefIfacesSimpleLocalIfServiceAnnouncementReplyMessage;
struct FTbRefIfacesSimpleLocalIfPingMessage;
struct FTbRefIfacesSimpleLocalIfClientDisconnectMessage;
struct FTbRefIfacesSimpleLocalIfIntSignalSignalMessage;
struct FTbRefIfacesSimpleLocalIfSetIntPropertyRequestMessage;
struct FTbRefIfacesSimpleLocalIfIntPropertyChangedMessage;
struct FTbRefIfacesSimpleLocalIfIntMethodRequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesSimpleLocalIfClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesSimpleLocalIfClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesSimpleLocalIfClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesSimpleLocalIfClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTbRefIfacesSimpleLocalIfMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbRefIfacesSimpleLocalIfInterface
/// and holds the corresponding TbRefIfacesSimpleLocalIfOLinkSource OLink source object
UCLASS(BlueprintType)
class TBREFIFACESMSGBUS_API UTbRefIfacesSimpleLocalIfMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbRefIfacesSimpleLocalIfMsgBusAdapter();
	virtual ~UTbRefIfacesSimpleLocalIfMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote", DisplayName = "New client connected")
	FTbRefIfacesSimpleLocalIfClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote", DisplayName = "Client disconnected")
	FTbRefIfacesSimpleLocalIfClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote", DisplayName = "Client timed out")
	FTbRefIfacesSimpleLocalIfClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote", DisplayName = "Clients connected count changed")
	FTbRefIfacesSimpleLocalIfClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf")
	void _setBackendService(TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbRefIfacesSimpleLocalIfMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTbRefIfacesSimpleLocalIfDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTbRefIfacesSimpleLocalIfServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbRefIfacesSimpleLocalIfPingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbRefIfacesSimpleLocalIfClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnIntMethodRequest(const FTbRefIfacesSimpleLocalIfIntMethodRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetIntPropertyRequest(const FTbRefIfacesSimpleLocalIfSetIntPropertyRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|TbRefIfaces|SimpleLocalIf", BlueprintInternalUseOnly)
	void OnIntSignal(int32 Param);

	UFUNCTION(Category = "ApiGear|TbRefIfaces|SimpleLocalIf", BlueprintInternalUseOnly)
	void OnIntPropertyChanged(int32 IntProperty);

	// delegate handles
	FDelegateHandle OnIntPropertyChangedHandle;
	FDelegateHandle OnIntSignalSignalHandle;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefIfaces|SimpleLocalIf")
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> BackendService;

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
