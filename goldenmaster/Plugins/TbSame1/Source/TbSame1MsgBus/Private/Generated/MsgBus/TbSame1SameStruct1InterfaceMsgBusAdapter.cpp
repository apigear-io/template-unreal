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

#include "TbSame1/Generated/MsgBus/TbSame1SameStruct1InterfaceMsgBusAdapter.h"
#include "TbSame1/Generated/MsgBus/TbSame1SameStruct1InterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTbSame1SameStruct1InterfaceMsgBusAdapter::UTbSame1SameStruct1InterfaceMsgBusAdapter()
{
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::Deinitialize()
{
	_StopListening();

	Super::Deinitialize();
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::_StartListening()
{

	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTbSame1SameStruct1InterfaceMsgBusAdapter::_CheckClientTimeouts, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	TbSame1SameStruct1InterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSame1/SameStruct1Interface/Service")
		.Handling<FTbSame1SameStruct1InterfaceDiscoveryMessage>(this, &UTbSame1SameStruct1InterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTbSame1SameStruct1InterfacePingMessage>(this, &UTbSame1SameStruct1InterfaceMsgBusAdapter::OnPing)
		.Handling<FTbSame1SameStruct1InterfaceClientDisconnectMessage>(this, &UTbSame1SameStruct1InterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTbSame1SameStruct1InterfaceSetProp1RequestMessage>(this, &UTbSame1SameStruct1InterfaceMsgBusAdapter::OnSetProp1Request)
		.Handling<FTbSame1SameStruct1InterfaceFunc1RequestMessage>(this, &UTbSame1SameStruct1InterfaceMsgBusAdapter::OnFunc1Request)
		.Build();
	// clang-format on

	if (TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct1InterfaceMsgBusEndpoint->Subscribe<FTbSame1SameStruct1InterfaceDiscoveryMessage>();
	}
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::_StopListening()
{
	if (_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(_HeartbeatTimerHandle);
	}

	auto msg = new FTbSame1SameStruct1InterfaceServiceDisconnectMessage();

	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	if (TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		TbSame1SameStruct1InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct1InterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	TbSame1SameStruct1InterfaceMsgBusEndpoint.Reset();
	ConnectedClientsTimestamps.Empty();
	_UpdateClientsConnected();
}

bool UTbSame1SameStruct1InterfaceMsgBusAdapter::_IsListening() const
{
	return TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid();
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::_setBackendService(TScriptInterface<ITbSame1SameStruct1InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame1SameStruct1InterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameStruct1Interface"));
		if (OnProp1ChangedHandle.IsValid())
		{
			BackendSignals->OnProp1Changed.Remove(OnProp1ChangedHandle);
			OnProp1ChangedHandle.Reset();
		}
		if (OnSig1SignalHandle.IsValid())
		{
			BackendSignals->OnSig1Signal.Remove(OnSig1SignalHandle);
			OnSig1SignalHandle.Reset();
		}
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame1SameStruct1Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame1SameStruct1InterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSame1SameStruct1Interface"));
	// connect property changed signals or simple events
	OnProp1ChangedHandle = BackendSignals->OnProp1Changed.AddUObject(this, &UTbSame1SameStruct1InterfaceMsgBusAdapter::OnProp1Changed);
	OnSig1SignalHandle = BackendSignals->OnSig1Signal.AddUObject(this, &UTbSame1SameStruct1InterfaceMsgBusAdapter::OnSig1);
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::OnNewClientDiscovered(const FTbSame1SameStruct1InterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	const FMessageAddress& ClientAddress = Context->GetSender();

	auto msg = new FTbSame1SameStruct1InterfaceInitMessage();
	msg->_ClientPingIntervalMS = _HeartbeatIntervalMS;
	msg->Prop1 = BackendService->GetProp1();

	if (TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct1InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct1InterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	_OnClientConnected.Broadcast(ClientAddress.ToString());
	ConnectedClientsTimestamps.Add(ClientAddress, FPlatformTime::Seconds());
	_UpdateClientsConnected();
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::OnPing(const FTbSame1SameStruct1InterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSame1SameStruct1InterfacePongMessage();
	msg->Timestamp = InMessage.Timestamp;

	ConnectedClientsTimestamps.Add(Context->GetSender(), FPlatformTime::Seconds());

	if (TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct1InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct1InterfacePongMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::OnClientDisconnected(const FTbSame1SameStruct1InterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (!ConnectedClientsTimestamps.Contains(Context->GetSender()))
	{
		return;
	}

	ConnectedClientsTimestamps.Remove(Context->GetSender());
	_OnClientDisconnected.Broadcast(Context->GetSender().ToString());
	_UpdateClientsConnected();
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::_CheckClientTimeouts()
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

void UTbSame1SameStruct1InterfaceMsgBusAdapter::_UpdateClientsConnected()
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);
	_ClientsConnected = NumberOfClients;
	_OnClientsConnectedCountChanged.Broadcast(_ClientsConnected);
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::OnFunc1Request(const FTbSame1SameStruct1InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSame1SameStruct1InterfaceFunc1ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Func1(InMessage.Param1);

	if (TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct1InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct1InterfaceFunc1ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::OnSig1(const FTbSame1Struct1& InParam1)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTbSame1SameStruct1InterfaceSig1SignalMessage();
	msg->Param1 = InParam1;
	if (TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		TbSame1SameStruct1InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct1InterfaceSig1SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::OnSetProp1Request(const FTbSame1SameStruct1InterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->SetProp1(InMessage.Prop1);
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::OnProp1Changed(const FTbSame1Struct1& InProp1)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTbSame1SameStruct1InterfaceProp1ChangedMessage();
	msg->Prop1 = InProp1;

	if (TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		TbSame1SameStruct1InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct1InterfaceProp1ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}
