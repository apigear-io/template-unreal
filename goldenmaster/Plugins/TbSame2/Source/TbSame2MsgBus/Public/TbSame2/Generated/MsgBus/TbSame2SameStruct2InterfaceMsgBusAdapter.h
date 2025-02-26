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

#include "TbSame2/Generated/api/TbSame2SameStruct2InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IMessageContext.h"
#include "Templates/SharedPointer.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION < 5)
#include "Engine/EngineTypes.h"
#else
#include "Engine/TimerHandle.h"
#endif
#include "TbSame2SameStruct2InterfaceMsgBusAdapter.generated.h"

class FMessageEndpoint;
// messages
struct FTbSame2SameStruct2InterfaceDiscoveryMessage;
struct FTbSame2SameStruct2InterfacePingMessage;
struct FTbSame2SameStruct2InterfaceClientDisconnectMessage;
struct FTbSame2SameStruct2InterfaceSig1SignalMessage;
struct FTbSame2SameStruct2InterfaceSig2SignalMessage;
struct FTbSame2SameStruct2InterfaceSetProp1RequestMessage;
struct FTbSame2SameStruct2InterfaceProp1ChangedMessage;
struct FTbSame2SameStruct2InterfaceSetProp2RequestMessage;
struct FTbSame2SameStruct2InterfaceProp2ChangedMessage;
struct FTbSame2SameStruct2InterfaceFunc1RequestMessage;
struct FTbSame2SameStruct2InterfaceFunc2RequestMessage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceClientConnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceClientDisconnectedDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceClientTimeoutDelegate, const FString&, ClientAddress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceClientCountDelegate, int32, Count);

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbSame2SameStruct2InterfaceInterface
/// and holds the corresponding TbSame2SameStruct2InterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBSAME2MSGBUS_API UTbSame2SameStruct2InterfaceMsgBusAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameStruct2InterfaceMsgBusAdapter();
	virtual ~UTbSame2SameStruct2InterfaceMsgBusAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Remote")
	void _StartListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Remote")
	void _StopListening();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Remote")
	bool _IsListening() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface|Remote", DisplayName = "New client connected")
	FTbSame2SameStruct2InterfaceClientConnectedDelegate _OnClientConnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface|Remote", DisplayName = "Client disconnected")
	FTbSame2SameStruct2InterfaceClientDisconnectedDelegate _OnClientDisconnected;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface|Remote", DisplayName = "Client timed out")
	FTbSame2SameStruct2InterfaceClientTimeoutDelegate _OnClientTimeout;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface|Remote", DisplayName = "Clients connected count changed")
	FTbSame2SameStruct2InterfaceClientCountDelegate _OnClientsConnectedCountChanged;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Remote")
	const int32 _GetClientsConnectedCount() const
	{
		return _ClientsConnected;
	};

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface")
	void _setBackendService(TScriptInterface<ITbSame2SameStruct2InterfaceInterface> InService);

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> TbSame2SameStruct2InterfaceMsgBusEndpoint;

	void OnNewClientDiscovered(const FTbSame2SameStruct2InterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPing(const FTbSame2SameStruct2InterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnClientDisconnected(const FTbSame2SameStruct2InterfaceClientDisconnectMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc1Request(const FTbSame2SameStruct2InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnFunc2Request(const FTbSame2SameStruct2InterfaceFunc2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp1Request(const FTbSame2SameStruct2InterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnSetProp2Request(const FTbSame2SameStruct2InterfaceSetProp2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	// signals
	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct2Interface", BlueprintInternalUseOnly)
	void OnSig1(const FTbSame2Struct1& Param1);

	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct2Interface", BlueprintInternalUseOnly)
	void OnSig2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2);

	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct2Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const FTbSame2Struct2& Prop1);

	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct2Interface", BlueprintInternalUseOnly)
	void OnProp2Changed(const FTbSame2Struct2& Prop2);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame2|SameStruct2Interface")
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> BackendService;

	// Heartbeat handling
	void _CheckClientTimeouts();
	void _UpdateClientsConnected();
	TMap<FMessageAddress, double> ConnectedClientsTimestamps;
	FTimerHandle _HeartbeatTimerHandle;
	int32 _ClientsConnected = 0;
	uint32 _HeartbeatIntervalMS = 1000;
};
