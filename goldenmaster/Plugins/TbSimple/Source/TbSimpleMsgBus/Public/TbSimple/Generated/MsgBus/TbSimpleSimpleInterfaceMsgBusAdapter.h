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

#include "TbSimple/Generated/api/TbSimpleSimpleInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"
#include "TbSimpleSimpleInterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbSimpleSimpleInterfaceDiscoveryMessage;
struct FTbSimpleSimpleInterfaceServiceAnnouncementReplyMessage;
struct FTbSimpleSimpleInterfacePingMessage;
struct FTbSimpleSimpleInterfaceClientDisconnectMessage;
struct FTbSimpleSimpleInterfaceSigBoolSignalMessage;
struct FTbSimpleSimpleInterfaceSigIntSignalMessage;
struct FTbSimpleSimpleInterfaceSigInt32SignalMessage;
struct FTbSimpleSimpleInterfaceSigInt64SignalMessage;
struct FTbSimpleSimpleInterfaceSigFloatSignalMessage;
struct FTbSimpleSimpleInterfaceSigFloat32SignalMessage;
struct FTbSimpleSimpleInterfaceSigFloat64SignalMessage;
struct FTbSimpleSimpleInterfaceSigStringSignalMessage;
struct FTbSimpleSimpleInterfaceSetPropBoolRequestMessage;
struct FTbSimpleSimpleInterfacePropBoolChangedMessage;
struct FTbSimpleSimpleInterfaceSetPropIntRequestMessage;
struct FTbSimpleSimpleInterfacePropIntChangedMessage;
struct FTbSimpleSimpleInterfaceSetPropInt32RequestMessage;
struct FTbSimpleSimpleInterfacePropInt32ChangedMessage;
struct FTbSimpleSimpleInterfaceSetPropInt64RequestMessage;
struct FTbSimpleSimpleInterfacePropInt64ChangedMessage;
struct FTbSimpleSimpleInterfaceSetPropFloatRequestMessage;
struct FTbSimpleSimpleInterfacePropFloatChangedMessage;
struct FTbSimpleSimpleInterfaceSetPropFloat32RequestMessage;
struct FTbSimpleSimpleInterfacePropFloat32ChangedMessage;
struct FTbSimpleSimpleInterfaceSetPropFloat64RequestMessage;
struct FTbSimpleSimpleInterfacePropFloat64ChangedMessage;
struct FTbSimpleSimpleInterfaceSetPropStringRequestMessage;
struct FTbSimpleSimpleInterfacePropStringChangedMessage;
struct FTbSimpleSimpleInterfaceFuncNoReturnValueRequestMessage;
struct FTbSimpleSimpleInterfaceFuncNoParamsRequestMessage;
struct FTbSimpleSimpleInterfaceFuncBoolRequestMessage;
struct FTbSimpleSimpleInterfaceFuncIntRequestMessage;
struct FTbSimpleSimpleInterfaceFuncInt32RequestMessage;
struct FTbSimpleSimpleInterfaceFuncInt64RequestMessage;
struct FTbSimpleSimpleInterfaceFuncFloatRequestMessage;
struct FTbSimpleSimpleInterfaceFuncFloat32RequestMessage;
struct FTbSimpleSimpleInterfaceFuncFloat64RequestMessage;
struct FTbSimpleSimpleInterfaceFuncStringRequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceClientCountDelegate, int32, Count);

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleSimpleInterfaceMsgBusAdapter, Log, All);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbSimpleSimpleInterfaceInterface
/// and holds the corresponding TbSimpleSimpleInterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBSIMPLEMSGBUS_API UTbSimpleSimpleInterfaceMsgBusAdapter : public UGameInstanceSubsystem, public ITbSimpleSimpleInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleInterfaceMsgBusAdapter();
	virtual ~UTbSimpleSimpleInterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Remote", DisplayName = "New client connected")
	FTbSimpleSimpleInterfaceClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Remote", DisplayName = "Client disconnected")
	FTbSimpleSimpleInterfaceClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Remote", DisplayName = "Client timed out")
	FTbSimpleSimpleInterfaceClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Remote", DisplayName = "Clients connected count changed")
	FTbSimpleSimpleInterfaceClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void _setBackendService(TScriptInterface<ITbSimpleSimpleInterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSimpleSimpleInterfaceMsgBusEndpoint;

	void _AnnounceService();
	void OnDiscoveryMessage(const FTbSimpleSimpleInterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceAnnouncementMessage(const FTbSimpleSimpleInterfaceServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbSimpleSimpleInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbSimpleSimpleInterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncNoReturnValueRequest(const FTbSimpleSimpleInterfaceFuncNoReturnValueRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncNoParamsRequest(const FTbSimpleSimpleInterfaceFuncNoParamsRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncBoolRequest(const FTbSimpleSimpleInterfaceFuncBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncIntRequest(const FTbSimpleSimpleInterfaceFuncIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncInt32Request(const FTbSimpleSimpleInterfaceFuncInt32RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncInt64Request(const FTbSimpleSimpleInterfaceFuncInt64RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloatRequest(const FTbSimpleSimpleInterfaceFuncFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloat32Request(const FTbSimpleSimpleInterfaceFuncFloat32RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloat64Request(const FTbSimpleSimpleInterfaceFuncFloat64RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncStringRequest(const FTbSimpleSimpleInterfaceFuncStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropBoolRequest(const FTbSimpleSimpleInterfaceSetPropBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropIntRequest(const FTbSimpleSimpleInterfaceSetPropIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropInt32Request(const FTbSimpleSimpleInterfaceSetPropInt32RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropInt64Request(const FTbSimpleSimpleInterfaceSetPropInt64RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropFloatRequest(const FTbSimpleSimpleInterfaceSetPropFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropFloat32Request(const FTbSimpleSimpleInterfaceSetPropFloat32RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropFloat64Request(const FTbSimpleSimpleInterfaceSetPropFloat64RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropStringRequest(const FTbSimpleSimpleInterfaceSetPropStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	void OnSigBoolSignal(bool bParamBool) override;

	void OnSigIntSignal(int32 ParamInt) override;

	void OnSigInt32Signal(int32 ParamInt32) override;

	void OnSigInt64Signal(int64 ParamInt64) override;

	void OnSigFloatSignal(float ParamFloat) override;

	void OnSigFloat32Signal(float ParamFloat32) override;

	void OnSigFloat64Signal(double ParamFloat64) override;

	void OnSigStringSignal(const FString& ParamString) override;

	void OnPropBoolChanged(bool bPropBool) override;

	void OnPropIntChanged(int32 PropInt) override;

	void OnPropInt32Changed(int32 PropInt32) override;

	void OnPropInt64Changed(int64 PropInt64) override;

	void OnPropFloatChanged(float PropFloat) override;

	void OnPropFloat32Changed(float PropFloat32) override;

	void OnPropFloat64Changed(double PropFloat64) override;

	void OnPropStringChanged(const FString& PropString) override;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|SimpleInterface")
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> BackendService;

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
