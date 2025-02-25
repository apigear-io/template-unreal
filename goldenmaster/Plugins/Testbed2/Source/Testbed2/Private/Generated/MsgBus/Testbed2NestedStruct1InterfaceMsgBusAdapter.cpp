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

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "Generated/MsgBus/Testbed2NestedStruct1InterfaceMsgBusAdapter.h"
#include "Generated/MsgBus/Testbed2NestedStruct1InterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTestbed2NestedStruct1InterfaceMsgBusAdapter::UTestbed2NestedStruct1InterfaceMsgBusAdapter()
{
}

void UTestbed2NestedStruct1InterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed2NestedStruct1InterfaceMsgBusAdapter::Deinitialize()
{
	_StopListening();

	Super::Deinitialize();
}

void UTestbed2NestedStruct1InterfaceMsgBusAdapter::_StartListening()
{

	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTestbed2NestedStruct1InterfaceMsgBusAdapter::_CheckClientTimeouts, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (Testbed2NestedStruct1InterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	Testbed2NestedStruct1InterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/Testbed2/NestedStruct1Interface/Service")
		.Handling<FTestbed2NestedStruct1InterfaceDiscoveryMessage>(this, &UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTestbed2NestedStruct1InterfacePingMessage>(this, &UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnPing)
		.Handling<FTestbed2NestedStruct1InterfaceClientDisconnectMessage>(this, &UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTestbed2NestedStruct1InterfaceSetProp1RequestMessage>(this, &UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnSetProp1Request)
		.Handling<FTestbed2NestedStruct1InterfaceFunc1RequestMessage>(this, &UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnFunc1Request)
		.Build();
	// clang-format on

	if (Testbed2NestedStruct1InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct1InterfaceMsgBusEndpoint->Subscribe<FTestbed2NestedStruct1InterfaceDiscoveryMessage>();
	}
}

void UTestbed2NestedStruct1InterfaceMsgBusAdapter::_StopListening()
{
	if (_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(_HeartbeatTimerHandle);
	}

	auto msg = new FTestbed2NestedStruct1InterfaceServiceDisconnectMessage();

	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	if (Testbed2NestedStruct1InterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		Testbed2NestedStruct1InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct1InterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	Testbed2NestedStruct1InterfaceMsgBusEndpoint.Reset();
	ConnectedClientsTimestamps.Empty();
	_UpdateClientsConnected();
}

bool UTestbed2NestedStruct1InterfaceMsgBusAdapter::_IsListening() const
{
	return Testbed2NestedStruct1InterfaceMsgBusEndpoint.IsValid();
}

void UTestbed2NestedStruct1InterfaceMsgBusAdapter::_setBackendService(TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed2NestedStruct1InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2NestedStruct1Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnProp1Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnSig1);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed2NestedStruct1Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed2NestedStruct1InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service Testbed2NestedStruct1Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnProp1Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnSig1);
}

void UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnNewClientDiscovered(const FTestbed2NestedStruct1InterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	const FMessageAddress& ClientAddress = Context->GetSender();

	auto msg = new FTestbed2NestedStruct1InterfaceInitMessage();
	msg->_ClientPingIntervalMS = _HeartbeatIntervalMS;
	msg->Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());

	if (Testbed2NestedStruct1InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct1InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct1InterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	_OnClientConnected.Broadcast(ClientAddress.ToString());
	ConnectedClientsTimestamps.Add(ClientAddress, FPlatformTime::Seconds());
	_UpdateClientsConnected();
}

void UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnPing(const FTestbed2NestedStruct1InterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed2NestedStruct1InterfacePongMessage();
	msg->Timestamp = InMessage.Timestamp;

	ConnectedClientsTimestamps.Add(Context->GetSender(), FPlatformTime::Seconds());

	if (Testbed2NestedStruct1InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct1InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct1InterfacePongMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnClientDisconnected(const FTestbed2NestedStruct1InterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (!ConnectedClientsTimestamps.Contains(Context->GetSender()))
	{
		return;
	}

	ConnectedClientsTimestamps.Remove(Context->GetSender());
	_OnClientDisconnected.Broadcast(Context->GetSender().ToString());
	_UpdateClientsConnected();
}

void UTestbed2NestedStruct1InterfaceMsgBusAdapter::_CheckClientTimeouts()
{
	float CurrentTime = FPlatformTime::Seconds();
	TArray<FMessageAddress> TimedOutClients;

	for (const auto& ClientPair : ConnectedClientsTimestamps)
	{
		const double Delta = (CurrentTime - ClientPair.Value) * 1000;

		if (Delta > 2 * _HeartbeatIntervalMS)
		{
			// service seems to be dead or not responding - reset connection
			TimedOutClients.Add(ClientPair.Key);
		}
	}

	for (const auto& ClientAddress : TimedOutClients)
	{
		_OnClientTimeout.Broadcast(ClientAddress.ToString());
		ConnectedClientsTimestamps.Remove(ClientAddress);
	}
	_UpdateClientsConnected();
}

void UTestbed2NestedStruct1InterfaceMsgBusAdapter::_UpdateClientsConnected()
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);
	_ClientsConnected = NumberOfClients;
	_OnClientsConnectedCountChanged.Broadcast(_ClientsConnected);
}

void UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnFunc1Request(const FTestbed2NestedStruct1InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed2NestedStruct1InterfaceFunc1ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_Func1(BackendService.GetObject(), InMessage.Param1);

	if (Testbed2NestedStruct1InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct1InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct1InterfaceFunc1ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnSig1(const FTestbed2NestedStruct1& InParam1)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTestbed2NestedStruct1InterfaceSig1SignalMessage();
	msg->Param1 = InParam1;
	if (Testbed2NestedStruct1InterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		Testbed2NestedStruct1InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct1InterfaceSig1SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnSetProp1Request(const FTestbed2NestedStruct1InterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetProp1(BackendService.GetObject(), InMessage.Prop1);
}

void UTestbed2NestedStruct1InterfaceMsgBusAdapter::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTestbed2NestedStruct1InterfaceProp1ChangedMessage();
	msg->Prop1 = InProp1;

	if (Testbed2NestedStruct1InterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		Testbed2NestedStruct1InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct1InterfaceProp1ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}
