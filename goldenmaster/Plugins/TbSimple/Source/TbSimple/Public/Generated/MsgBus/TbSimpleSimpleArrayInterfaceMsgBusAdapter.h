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

#include "Generated/api/TbSimpleSimpleArrayInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION < 5)
#include "Engine/EngineTypes.h"
#else
#include "Engine/TimerHandle.h"
#endif
#include "TbSimpleSimpleArrayInterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbSimpleSimpleArrayInterfaceDiscoveryMessage;
struct FTbSimpleSimpleArrayInterfacePingMessage;
struct FTbSimpleSimpleArrayInterfaceClientDisconnectMessage;
struct FTbSimpleSimpleArrayInterfaceSigBoolSignalMessage;
struct FTbSimpleSimpleArrayInterfaceSigIntSignalMessage;
struct FTbSimpleSimpleArrayInterfaceSigInt32SignalMessage;
struct FTbSimpleSimpleArrayInterfaceSigInt64SignalMessage;
struct FTbSimpleSimpleArrayInterfaceSigFloatSignalMessage;
struct FTbSimpleSimpleArrayInterfaceSigFloat32SignalMessage;
struct FTbSimpleSimpleArrayInterfaceSigFloat64SignalMessage;
struct FTbSimpleSimpleArrayInterfaceSigStringSignalMessage;
struct FTbSimpleSimpleArrayInterfaceSetPropBoolRequestMessage;
struct FTbSimpleSimpleArrayInterfacePropBoolChangedMessage;
struct FTbSimpleSimpleArrayInterfaceSetPropIntRequestMessage;
struct FTbSimpleSimpleArrayInterfacePropIntChangedMessage;
struct FTbSimpleSimpleArrayInterfaceSetPropInt32RequestMessage;
struct FTbSimpleSimpleArrayInterfacePropInt32ChangedMessage;
struct FTbSimpleSimpleArrayInterfaceSetPropInt64RequestMessage;
struct FTbSimpleSimpleArrayInterfacePropInt64ChangedMessage;
struct FTbSimpleSimpleArrayInterfaceSetPropFloatRequestMessage;
struct FTbSimpleSimpleArrayInterfacePropFloatChangedMessage;
struct FTbSimpleSimpleArrayInterfaceSetPropFloat32RequestMessage;
struct FTbSimpleSimpleArrayInterfacePropFloat32ChangedMessage;
struct FTbSimpleSimpleArrayInterfaceSetPropFloat64RequestMessage;
struct FTbSimpleSimpleArrayInterfacePropFloat64ChangedMessage;
struct FTbSimpleSimpleArrayInterfaceSetPropStringRequestMessage;
struct FTbSimpleSimpleArrayInterfacePropStringChangedMessage;
struct FTbSimpleSimpleArrayInterfaceSetPropReadOnlyStringRequestMessage;
struct FTbSimpleSimpleArrayInterfacePropReadOnlyStringChangedMessage;
struct FTbSimpleSimpleArrayInterfaceFuncBoolRequestMessage;
struct FTbSimpleSimpleArrayInterfaceFuncIntRequestMessage;
struct FTbSimpleSimpleArrayInterfaceFuncInt32RequestMessage;
struct FTbSimpleSimpleArrayInterfaceFuncInt64RequestMessage;
struct FTbSimpleSimpleArrayInterfaceFuncFloatRequestMessage;
struct FTbSimpleSimpleArrayInterfaceFuncFloat32RequestMessage;
struct FTbSimpleSimpleArrayInterfaceFuncFloat64RequestMessage;
struct FTbSimpleSimpleArrayInterfaceFuncStringRequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceClientCountDelegate, int32, Count);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbSimpleSimpleArrayInterfaceInterface
/// and holds the corresponding TbSimpleSimpleArrayInterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleSimpleArrayInterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleArrayInterfaceMsgBusAdapter();
	virtual ~UTbSimpleSimpleArrayInterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Remote", DisplayName = "New client connected")
	FTbSimpleSimpleArrayInterfaceClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Remote", DisplayName = "Client disconnected")
	FTbSimpleSimpleArrayInterfaceClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Remote", DisplayName = "Client timed out")
	FTbSimpleSimpleArrayInterfaceClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Remote", DisplayName = "Clients connected count changed")
	FTbSimpleSimpleArrayInterfaceClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void _setBackendService(TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSimpleSimpleArrayInterfaceMsgBusEndpoint;

	void OnNewClientDiscovered(const FTbSimpleSimpleArrayInterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbSimpleSimpleArrayInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbSimpleSimpleArrayInterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncBoolRequest(const FTbSimpleSimpleArrayInterfaceFuncBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncIntRequest(const FTbSimpleSimpleArrayInterfaceFuncIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncInt32Request(const FTbSimpleSimpleArrayInterfaceFuncInt32RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncInt64Request(const FTbSimpleSimpleArrayInterfaceFuncInt64RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloatRequest(const FTbSimpleSimpleArrayInterfaceFuncFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloat32Request(const FTbSimpleSimpleArrayInterfaceFuncFloat32RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncFloat64Request(const FTbSimpleSimpleArrayInterfaceFuncFloat64RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFuncStringRequest(const FTbSimpleSimpleArrayInterfaceFuncStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropBoolRequest(const FTbSimpleSimpleArrayInterfaceSetPropBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropIntRequest(const FTbSimpleSimpleArrayInterfaceSetPropIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropInt32Request(const FTbSimpleSimpleArrayInterfaceSetPropInt32RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropInt64Request(const FTbSimpleSimpleArrayInterfaceSetPropInt64RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropFloatRequest(const FTbSimpleSimpleArrayInterfaceSetPropFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropFloat32Request(const FTbSimpleSimpleArrayInterfaceSetPropFloat32RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropFloat64Request(const FTbSimpleSimpleArrayInterfaceSetPropFloat64RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetPropStringRequest(const FTbSimpleSimpleArrayInterfaceSetPropStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnSigBool(const TArray<bool>& ParamBool);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnSigInt(const TArray<int32>& ParamInt);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnSigInt32(const TArray<int32>& ParamInt32);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnSigInt64(const TArray<int64>& ParamInt64);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnSigFloat(const TArray<float>& ParamFloat);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnSigFloat32(const TArray<float>& ParamFloa32);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnSigFloat64(const TArray<double>& ParamFloat64);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnSigString(const TArray<FString>& ParamString);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(const TArray<bool>& PropBool);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(const TArray<int32>& PropInt);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnPropInt32Changed(const TArray<int32>& PropInt32);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnPropInt64Changed(const TArray<int64>& PropInt64);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnPropFloatChanged(const TArray<float>& PropFloat);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnPropFloat32Changed(const TArray<float>& PropFloat32);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnPropFloat64Changed(const TArray<double>& PropFloat64);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnPropStringChanged(const TArray<FString>& PropString);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnPropReadOnlyStringChanged(const FString& PropReadOnlyString);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> BackendService;

	// Heartbeat handling
	void _CheckClientTimeouts();
	void _UpdateClientsConnected();
	TMap<FMessageAddress, double> ConnectedClientsTimestamps;
	FTimerHandle _HeartbeatTimerHandle;
	int32 _ClientsConnected = 0;
	uint32 _HeartbeatIntervalMS = 1000;
};
