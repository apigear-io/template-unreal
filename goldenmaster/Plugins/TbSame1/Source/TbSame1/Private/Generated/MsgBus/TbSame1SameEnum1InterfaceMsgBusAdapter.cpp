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

#include "Generated/MsgBus/TbSame1SameEnum1InterfaceMsgBusAdapter.h"
#include "Generated/MsgBus/TbSame1SameEnum1InterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTbSame1SameEnum1InterfaceMsgBusAdapter::UTbSame1SameEnum1InterfaceMsgBusAdapter()
{
}

void UTbSame1SameEnum1InterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSame1SameEnum1InterfaceMsgBusAdapter::Deinitialize()
{
	StopListening();

	Super::Deinitialize();
}

void UTbSame1SameEnum1InterfaceMsgBusAdapter::StartListening()
{
	if (TbSame1SameEnum1InterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	TbSame1SameEnum1InterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSame1/SameEnum1Interface/Service")
		.Handling<FTbSame1SameEnum1InterfaceDiscoveryMessage>(this, &UTbSame1SameEnum1InterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTbSame1SameEnum1InterfaceClientDisconnectMessage>(this, &UTbSame1SameEnum1InterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTbSame1SameEnum1InterfaceSetProp1RequestMessage>(this, &UTbSame1SameEnum1InterfaceMsgBusAdapter::OnSetProp1Request)
		.Handling<FTbSame1SameEnum1InterfaceFunc1RequestMessage>(this, &UTbSame1SameEnum1InterfaceMsgBusAdapter::OnFunc1Request)
		.Build();
	// clang-format on

	if (TbSame1SameEnum1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameEnum1InterfaceMsgBusEndpoint->Subscribe<FTbSame1SameEnum1InterfaceDiscoveryMessage>();
	}
}

void UTbSame1SameEnum1InterfaceMsgBusAdapter::StopListening()
{
	auto msg = new FTbSame1SameEnum1InterfaceServiceDisconnectMessage();

	if (TbSame1SameEnum1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameEnum1InterfaceMsgBusEndpoint->Send<FTbSame1SameEnum1InterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	TbSame1SameEnum1InterfaceMsgBusEndpoint.Reset();
	ConnectedClients.Reset();
}

bool UTbSame1SameEnum1InterfaceMsgBusAdapter::IsListening() const
{
	return TbSame1SameEnum1InterfaceMsgBusEndpoint.IsValid();
}

void UTbSame1SameEnum1InterfaceMsgBusAdapter::setBackendService(TScriptInterface<ITbSame1SameEnum1InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame1SameEnum1InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameEnum1Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTbSame1SameEnum1InterfaceMsgBusAdapter::OnProp1Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTbSame1SameEnum1InterfaceMsgBusAdapter::OnSig1);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame1SameEnum1Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame1SameEnum1InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSame1SameEnum1Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTbSame1SameEnum1InterfaceMsgBusAdapter::OnProp1Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTbSame1SameEnum1InterfaceMsgBusAdapter::OnSig1);
}

void UTbSame1SameEnum1InterfaceMsgBusAdapter::OnNewClientDiscovered(const FTbSame1SameEnum1InterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FMessageAddress& ClientAddress = ConnectedClients.AddDefaulted_GetRef();
	ClientAddress = Context->GetSender();

	auto msg = new FTbSame1SameEnum1InterfaceInitMessage();
	msg->Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());

	if (TbSame1SameEnum1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameEnum1InterfaceMsgBusEndpoint->Send<FTbSame1SameEnum1InterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame1SameEnum1InterfaceMsgBusAdapter::OnClientDisconnected(const FTbSame1SameEnum1InterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	ConnectedClients.Remove(Context->GetSender());
}

void UTbSame1SameEnum1InterfaceMsgBusAdapter::OnFunc1Request(const FTbSame1SameEnum1InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSame1SameEnum1InterfaceFunc1ReplyMessage();
	msg->RepsonseId = InMessage.RepsonseId;
	msg->Result = BackendService->Execute_Func1(BackendService.GetObject(), InMessage.Param1);

	if (TbSame1SameEnum1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameEnum1InterfaceMsgBusEndpoint->Send<FTbSame1SameEnum1InterfaceFunc1ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame1SameEnum1InterfaceMsgBusAdapter::OnSig1(ETbSame1Enum1 InParam1)
{
	auto msg = new FTbSame1SameEnum1InterfaceSig1SignalMessage();
	msg->Param1 = InParam1;
	if (TbSame1SameEnum1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameEnum1InterfaceMsgBusEndpoint->Send<FTbSame1SameEnum1InterfaceSig1SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame1SameEnum1InterfaceMsgBusAdapter::OnSetProp1Request(const FTbSame1SameEnum1InterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetProp1(BackendService.GetObject(), InMessage.Prop1);
}

void UTbSame1SameEnum1InterfaceMsgBusAdapter::OnProp1Changed(ETbSame1Enum1 InProp1)
{
	auto msg = new FTbSame1SameEnum1InterfaceProp1ChangedMessage();
	msg->Prop1 = InProp1;

	if (TbSame1SameEnum1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameEnum1InterfaceMsgBusEndpoint->Send<FTbSame1SameEnum1InterfaceProp1ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}
