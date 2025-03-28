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

#include "Testbed2/Generated/api/Testbed2ManyParamInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION < 5)
#include "Engine/EngineTypes.h"
#else
#include "Engine/TimerHandle.h"
#endif
#include "Testbed2ManyParamInterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTestbed2ManyParamInterfaceDiscoveryMessage;
struct FTestbed2ManyParamInterfaceServiceAnnouncementReplyMessage;
struct FTestbed2ManyParamInterfacePingMessage;
struct FTestbed2ManyParamInterfaceClientDisconnectMessage;
struct FTestbed2ManyParamInterfaceSig1SignalMessage;
struct FTestbed2ManyParamInterfaceSig2SignalMessage;
struct FTestbed2ManyParamInterfaceSig3SignalMessage;
struct FTestbed2ManyParamInterfaceSig4SignalMessage;
struct FTestbed2ManyParamInterfaceSetProp1RequestMessage;
struct FTestbed2ManyParamInterfaceProp1ChangedMessage;
struct FTestbed2ManyParamInterfaceSetProp2RequestMessage;
struct FTestbed2ManyParamInterfaceProp2ChangedMessage;
struct FTestbed2ManyParamInterfaceSetProp3RequestMessage;
struct FTestbed2ManyParamInterfaceProp3ChangedMessage;
struct FTestbed2ManyParamInterfaceSetProp4RequestMessage;
struct FTestbed2ManyParamInterfaceProp4ChangedMessage;
struct FTestbed2ManyParamInterfaceFunc1RequestMessage;
struct FTestbed2ManyParamInterfaceFunc2RequestMessage;
struct FTestbed2ManyParamInterfaceFunc3RequestMessage;
struct FTestbed2ManyParamInterfaceFunc4RequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2ManyParamInterfaceMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITestbed2ManyParamInterfaceInterface
/// and holds the corresponding Testbed2ManyParamInterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TESTBED2MSGBUS_API UTestbed2ManyParamInterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTestbed2ManyParamInterfaceMsgBusAdapter();
	virtual ~UTestbed2ManyParamInterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote", DisplayName = "New client connected")
	FTestbed2ManyParamInterfaceClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote", DisplayName = "Client disconnected")
	FTestbed2ManyParamInterfaceClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote", DisplayName = "Client timed out")
	FTestbed2ManyParamInterfaceClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote", DisplayName = "Clients connected count changed")
	FTestbed2ManyParamInterfaceClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	void _setBackendService(TScriptInterface<ITestbed2ManyParamInterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> Testbed2ManyParamInterfaceMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTestbed2ManyParamInterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTestbed2ManyParamInterfaceServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTestbed2ManyParamInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTestbed2ManyParamInterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Request(const FTestbed2ManyParamInterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc2Request(const FTestbed2ManyParamInterfaceFunc2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc3Request(const FTestbed2ManyParamInterfaceFunc3RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc4Request(const FTestbed2ManyParamInterfaceFunc4RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp1Request(const FTestbed2ManyParamInterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp2Request(const FTestbed2ManyParamInterfaceSetProp2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp3Request(const FTestbed2ManyParamInterfaceSetProp3RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp4Request(const FTestbed2ManyParamInterfaceSetProp4RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig1(int32 Param1);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig2(int32 Param1, int32 Param2);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig3(int32 Param1, int32 Param2, int32 Param3);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig4(int32 Param1, int32 Param2, int32 Param3, int32 Param4);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp1Changed(int32 Prop1);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp2Changed(int32 Prop2);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp3Changed(int32 Prop3);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp4Changed(int32 Prop4);

	// delegate handles
	FDelegateHandle OnProp1ChangedHandle;
	FDelegateHandle OnProp2ChangedHandle;
	FDelegateHandle OnProp3ChangedHandle;
	FDelegateHandle OnProp4ChangedHandle;
	FDelegateHandle OnSig1SignalHandle;
	FDelegateHandle OnSig2SignalHandle;
	FDelegateHandle OnSig3SignalHandle;
	FDelegateHandle OnSig4SignalHandle;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|ManyParamInterface")
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> BackendService;

	// Heartbeat handling
	void _CheckClientTimeouts();
	void _UpdateClientsConnected();
	TMap<FMessageAddress, double> ConnectedClientsTimestamps;
	FTimerHandle _HeartbeatTimerHandle;
	int32 _ClientsConnected = 0;
	uint32 _HeartbeatIntervalMS = 100;
};
