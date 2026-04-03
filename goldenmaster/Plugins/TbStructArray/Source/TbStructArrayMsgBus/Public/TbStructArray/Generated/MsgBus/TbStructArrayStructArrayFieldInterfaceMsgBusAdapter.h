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

#include "TbStructArray/Generated/api/TbStructArrayStructArrayFieldInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "TbStructArrayStructArrayFieldInterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbStructArrayStructArrayFieldInterfaceDiscoveryMessage;
struct FTbStructArrayStructArrayFieldInterfaceServiceAnnouncementReplyMessage;
struct FTbStructArrayStructArrayFieldInterfacePingMessage;
struct FTbStructArrayStructArrayFieldInterfaceClientDisconnectMessage;
struct FTbStructArrayStructArrayFieldInterfaceSigMixedSignalMessage;
struct FTbStructArrayStructArrayFieldInterfaceSigStructArraySignalMessage;
struct FTbStructArrayStructArrayFieldInterfaceSetPropStructArrayRequestMessage;
struct FTbStructArrayStructArrayFieldInterfacePropStructArrayChangedMessage;
struct FTbStructArrayStructArrayFieldInterfaceSetPropEnumArrayRequestMessage;
struct FTbStructArrayStructArrayFieldInterfacePropEnumArrayChangedMessage;
struct FTbStructArrayStructArrayFieldInterfaceSetPropIntArrayRequestMessage;
struct FTbStructArrayStructArrayFieldInterfacePropIntArrayChangedMessage;
struct FTbStructArrayStructArrayFieldInterfaceSetPropMixedRequestMessage;
struct FTbStructArrayStructArrayFieldInterfacePropMixedChangedMessage;
struct FTbStructArrayStructArrayFieldInterfaceFuncMixedRequestMessage;
struct FTbStructArrayStructArrayFieldInterfaceFuncStructArrayRequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbStructArrayStructArrayFieldInterfaceClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbStructArrayStructArrayFieldInterfaceClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbStructArrayStructArrayFieldInterfaceClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbStructArrayStructArrayFieldInterfaceClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTbStructArrayStructArrayFieldInterfaceMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbStructArrayStructArrayFieldInterfaceInterface
/// and holds the corresponding TbStructArrayStructArrayFieldInterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBSTRUCTARRAYMSGBUS_API UTbStructArrayStructArrayFieldInterfaceMsgBusAdapter : public UGameInstanceSubsystem, public ITbStructArrayStructArrayFieldInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbStructArrayStructArrayFieldInterfaceMsgBusAdapter();
	virtual ~UTbStructArrayStructArrayFieldInterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Remote", DisplayName = "New client connected")
	FTbStructArrayStructArrayFieldInterfaceClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Remote", DisplayName = "Client disconnected")
	FTbStructArrayStructArrayFieldInterfaceClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Remote", DisplayName = "Client timed out")
	FTbStructArrayStructArrayFieldInterfaceClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Remote", DisplayName = "Clients connected count changed")
	FTbStructArrayStructArrayFieldInterfaceClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	void _setBackendService(TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbStructArrayStructArrayFieldInterfaceMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTbStructArrayStructArrayFieldInterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTbStructArrayStructArrayFieldInterfaceServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbStructArrayStructArrayFieldInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbStructArrayStructArrayFieldInterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncMixedRequest(const FTbStructArrayStructArrayFieldInterfaceFuncMixedRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncStructArrayRequest(const FTbStructArrayStructArrayFieldInterfaceFuncStructArrayRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropStructArrayRequest(const FTbStructArrayStructArrayFieldInterfaceSetPropStructArrayRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropEnumArrayRequest(const FTbStructArrayStructArrayFieldInterfaceSetPropEnumArrayRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropIntArrayRequest(const FTbStructArrayStructArrayFieldInterfaceSetPropIntArrayRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropMixedRequest(const FTbStructArrayStructArrayFieldInterfaceSetPropMixedRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	void OnSigMixedSignal(const FTbStructArrayMixedStruct& ParamMixed) override;

	void OnSigStructArraySignal(const FTbStructArrayStructWithArrayOfStructs& ParamPoints) override;

	void OnPropStructArrayChanged(const FTbStructArrayStructWithArrayOfStructs& PropStructArray) override;

	void OnPropEnumArrayChanged(const FTbStructArrayStructWithArrayOfEnums& PropEnumArray) override;

	void OnPropIntArrayChanged(const FTbStructArrayStructWithArrayOfInts& PropIntArray) override;

	void OnPropMixedChanged(const FTbStructArrayMixedStruct& PropMixed) override;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> BackendService;

	// Heartbeat handling
	void _CheckClientTimeouts();
	bool _CheckClientTimeoutsTick(float DeltaTime);
	void _UpdateClientsConnected();
	TMap<FMessageAddress, double> ConnectedClientsTimestamps;
	FCriticalSection ConnectedClientsTimestampsCS;
#if (ENGINE_MAJOR_VERSION < 5)
	::FDelegateHandle _HeartbeatTickerHandle;
#else
	FTSTicker::FDelegateHandle _HeartbeatTickerHandle;
#endif
	int32 _ClientsConnected = 0;
	uint32 _HeartbeatIntervalMS = 100;
};
