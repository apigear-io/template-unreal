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

#include "TbSame2/Generated/MsgBus/TbSame2SameEnum1InterfaceMsgBusAdapter.h"
#include "TbSame2/Generated/MsgBus/TbSame2SameEnum1InterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTbSame2SameEnum1InterfaceMsgBusAdapter::UTbSame2SameEnum1InterfaceMsgBusAdapter()
{
}

void UTbSame2SameEnum1InterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSame2SameEnum1InterfaceMsgBusAdapter::Deinitialize()
{
	_StopListening();

	Super::Deinitialize();
}

void UTbSame2SameEnum1InterfaceMsgBusAdapter::_StartListening()
{

	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTbSame2SameEnum1InterfaceMsgBusAdapter::_CheckClientTimeouts, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (TbSame2SameEnum1InterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	TbSame2SameEnum1InterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSame2/SameEnum1Interface/Service")
		.Handling<FTbSame2SameEnum1InterfaceDiscoveryMessage>(this, &UTbSame2SameEnum1InterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTbSame2SameEnum1InterfacePingMessage>(this, &UTbSame2SameEnum1InterfaceMsgBusAdapter::OnPing)
		.Handling<FTbSame2SameEnum1InterfaceClientDisconnectMessage>(this, &UTbSame2SameEnum1InterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTbSame2SameEnum1InterfaceSetProp1RequestMessage>(this, &UTbSame2SameEnum1InterfaceMsgBusAdapter::OnSetProp1Request)
		.Handling<FTbSame2SameEnum1InterfaceFunc1RequestMessage>(this, &UTbSame2SameEnum1InterfaceMsgBusAdapter::OnFunc1Request)
		.Build();
	// clang-format on

	if (TbSame2SameEnum1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameEnum1InterfaceMsgBusEndpoint->Subscribe<FTbSame2SameEnum1InterfaceDiscoveryMessage>();
	}
}

void UTbSame2SameEnum1InterfaceMsgBusAdapter::_StopListening()
{
	if (_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(_HeartbeatTimerHandle);
	}

	auto msg = new FTbSame2SameEnum1InterfaceServiceDisconnectMessage();

	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	if (TbSame2SameEnum1InterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		TbSame2SameEnum1InterfaceMsgBusEndpoint->Send<FTbSame2SameEnum1InterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	TbSame2SameEnum1InterfaceMsgBusEndpoint.Reset();
	ConnectedClientsTimestamps.Empty();
	_UpdateClientsConnected();
}

bool UTbSame2SameEnum1InterfaceMsgBusAdapter::_IsListening() const
{
	return TbSame2SameEnum1InterfaceMsgBusEndpoint.IsValid();
}

void UTbSame2SameEnum1InterfaceMsgBusAdapter::_setBackendService(TScriptInterface<ITbSame2SameEnum1InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame2SameEnum1InterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame2SameEnum1Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTbSame2SameEnum1InterfaceMsgBusAdapter::OnProp1Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTbSame2SameEnum1InterfaceMsgBusAdapter::OnSig1);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame2SameEnum1Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame2SameEnum1InterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSame2SameEnum1Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTbSame2SameEnum1InterfaceMsgBusAdapter::OnProp1Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTbSame2SameEnum1InterfaceMsgBusAdapter::OnSig1);
}

void UTbSame2SameEnum1InterfaceMsgBusAdapter::OnNewClientDiscovered(const FTbSame2SameEnum1InterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	const FMessageAddress& ClientAddress = Context->GetSender();

	auto msg = new FTbSame2SameEnum1InterfaceInitMessage();
	msg->_ClientPingIntervalMS = _HeartbeatIntervalMS;
	msg->Prop1 = BackendService->GetProp1();

	if (TbSame2SameEnum1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameEnum1InterfaceMsgBusEndpoint->Send<FTbSame2SameEnum1InterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	_OnClientConnected.Broadcast(ClientAddress.ToString());
	ConnectedClientsTimestamps.Add(ClientAddress, FPlatformTime::Seconds());
	_UpdateClientsConnected();
}

void UTbSame2SameEnum1InterfaceMsgBusAdapter::OnPing(const FTbSame2SameEnum1InterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSame2SameEnum1InterfacePongMessage();
	msg->Timestamp = InMessage.Timestamp;

	ConnectedClientsTimestamps.Add(Context->GetSender(), FPlatformTime::Seconds());

	if (TbSame2SameEnum1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameEnum1InterfaceMsgBusEndpoint->Send<FTbSame2SameEnum1InterfacePongMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame2SameEnum1InterfaceMsgBusAdapter::OnClientDisconnected(const FTbSame2SameEnum1InterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (!ConnectedClientsTimestamps.Contains(Context->GetSender()))
	{
		return;
	}

	ConnectedClientsTimestamps.Remove(Context->GetSender());
	_OnClientDisconnected.Broadcast(Context->GetSender().ToString());
	_UpdateClientsConnected();
}

void UTbSame2SameEnum1InterfaceMsgBusAdapter::_CheckClientTimeouts()
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

void UTbSame2SameEnum1InterfaceMsgBusAdapter::_UpdateClientsConnected()
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);
	_ClientsConnected = NumberOfClients;
	_OnClientsConnectedCountChanged.Broadcast(_ClientsConnected);
}

void UTbSame2SameEnum1InterfaceMsgBusAdapter::OnFunc1Request(const FTbSame2SameEnum1InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSame2SameEnum1InterfaceFunc1ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Func1(InMessage.Param1);

	if (TbSame2SameEnum1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameEnum1InterfaceMsgBusEndpoint->Send<FTbSame2SameEnum1InterfaceFunc1ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame2SameEnum1InterfaceMsgBusAdapter::OnSig1(ETbSame2Enum1 InParam1)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTbSame2SameEnum1InterfaceSig1SignalMessage();
	msg->Param1 = InParam1;
	if (TbSame2SameEnum1InterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		TbSame2SameEnum1InterfaceMsgBusEndpoint->Send<FTbSame2SameEnum1InterfaceSig1SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame2SameEnum1InterfaceMsgBusAdapter::OnSetProp1Request(const FTbSame2SameEnum1InterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->SetProp1(InMessage.Prop1);
}

void UTbSame2SameEnum1InterfaceMsgBusAdapter::OnProp1Changed(ETbSame2Enum1 InProp1)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTbSame2SameEnum1InterfaceProp1ChangedMessage();
	msg->Prop1 = InProp1;

	if (TbSame2SameEnum1InterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		TbSame2SameEnum1InterfaceMsgBusEndpoint->Send<FTbSame2SameEnum1InterfaceProp1ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}
