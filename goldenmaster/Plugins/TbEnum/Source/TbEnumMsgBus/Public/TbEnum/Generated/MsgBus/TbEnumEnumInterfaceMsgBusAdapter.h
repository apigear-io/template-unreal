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

#include "TbEnum/Generated/api/TbEnumEnumInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "TbEnumEnumInterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbEnumEnumInterfaceDiscoveryMessage;
struct FTbEnumEnumInterfaceServiceAnnouncementReplyMessage;
struct FTbEnumEnumInterfacePingMessage;
struct FTbEnumEnumInterfaceClientDisconnectMessage;
struct FTbEnumEnumInterfaceSig0SignalMessage;
struct FTbEnumEnumInterfaceSig1SignalMessage;
struct FTbEnumEnumInterfaceSig2SignalMessage;
struct FTbEnumEnumInterfaceSig3SignalMessage;
struct FTbEnumEnumInterfaceSetProp0RequestMessage;
struct FTbEnumEnumInterfaceProp0ChangedMessage;
struct FTbEnumEnumInterfaceSetProp1RequestMessage;
struct FTbEnumEnumInterfaceProp1ChangedMessage;
struct FTbEnumEnumInterfaceSetProp2RequestMessage;
struct FTbEnumEnumInterfaceProp2ChangedMessage;
struct FTbEnumEnumInterfaceSetProp3RequestMessage;
struct FTbEnumEnumInterfaceProp3ChangedMessage;
struct FTbEnumEnumInterfaceFunc0RequestMessage;
struct FTbEnumEnumInterfaceFunc1RequestMessage;
struct FTbEnumEnumInterfaceFunc2RequestMessage;
struct FTbEnumEnumInterfaceFunc3RequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTbEnumEnumInterfaceMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbEnumEnumInterfaceInterface
/// and holds the corresponding TbEnumEnumInterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBENUMMSGBUS_API UTbEnumEnumInterfaceMsgBusAdapter : public UGameInstanceSubsystem, public ITbEnumEnumInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbEnumEnumInterfaceMsgBusAdapter();
	virtual ~UTbEnumEnumInterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Remote", DisplayName = "New client connected")
	FTbEnumEnumInterfaceClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Remote", DisplayName = "Client disconnected")
	FTbEnumEnumInterfaceClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Remote", DisplayName = "Client timed out")
	FTbEnumEnumInterfaceClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Remote", DisplayName = "Clients connected count changed")
	FTbEnumEnumInterfaceClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void _setBackendService(TScriptInterface<ITbEnumEnumInterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbEnumEnumInterfaceMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTbEnumEnumInterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTbEnumEnumInterfaceServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbEnumEnumInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbEnumEnumInterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc0Request(const FTbEnumEnumInterfaceFunc0RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Request(const FTbEnumEnumInterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc2Request(const FTbEnumEnumInterfaceFunc2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc3Request(const FTbEnumEnumInterfaceFunc3RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp0Request(const FTbEnumEnumInterfaceSetProp0RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp1Request(const FTbEnumEnumInterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp2Request(const FTbEnumEnumInterfaceSetProp2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp3Request(const FTbEnumEnumInterfaceSetProp3RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	void OnSig0Signal(ETbEnumEnum0 Param0) override;

	void OnSig1Signal(ETbEnumEnum1 Param1) override;

	void OnSig2Signal(ETbEnumEnum2 Param2) override;

	void OnSig3Signal(ETbEnumEnum3 Param3) override;

	void OnProp0Changed(ETbEnumEnum0 Prop0) override;

	void OnProp1Changed(ETbEnumEnum1 Prop1) override;

	void OnProp2Changed(ETbEnumEnum2 Prop2) override;

	void OnProp3Changed(ETbEnumEnum3 Prop3) override;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbEnum|EnumInterface")
	TScriptInterface<ITbEnumEnumInterfaceInterface> BackendService;

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
