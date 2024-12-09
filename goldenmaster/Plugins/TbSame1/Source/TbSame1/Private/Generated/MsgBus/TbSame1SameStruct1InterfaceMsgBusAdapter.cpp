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

#include "Generated/MsgBus/TbSame1SameStruct1InterfaceMsgBusAdapter.h"
#include "Generated/MsgBus/TbSame1SameStruct1InterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
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
	StopListening();

	Super::Deinitialize();
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::StartListening()
{
	if (TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	TbSame1SameStruct1InterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSame1/SameStruct1Interface/Service")
		.Handling<FTbSame1SameStruct1InterfaceDiscoveryMessage>(this, &UTbSame1SameStruct1InterfaceMsgBusAdapter::OnNewClientDiscovered)
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

void UTbSame1SameStruct1InterfaceMsgBusAdapter::StopListening()
{
	auto msg = new FTbSame1SameStruct1InterfaceServiceDisconnectMessage();

	if (TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct1InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct1InterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	TbSame1SameStruct1InterfaceMsgBusEndpoint.Reset();
	ConnectedClients.Reset();
}

bool UTbSame1SameStruct1InterfaceMsgBusAdapter::IsListening() const
{
	return TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid();
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::setBackendService(TScriptInterface<ITbSame1SameStruct1InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame1SameStruct1InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameStruct1Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTbSame1SameStruct1InterfaceMsgBusAdapter::OnProp1Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTbSame1SameStruct1InterfaceMsgBusAdapter::OnSig1);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame1SameStruct1Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame1SameStruct1InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSame1SameStruct1Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTbSame1SameStruct1InterfaceMsgBusAdapter::OnProp1Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTbSame1SameStruct1InterfaceMsgBusAdapter::OnSig1);
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::OnNewClientDiscovered(const FTbSame1SameStruct1InterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FMessageAddress& ClientAddress = ConnectedClients.AddDefaulted_GetRef();
	ClientAddress = Context->GetSender();

	auto msg = new FTbSame1SameStruct1InterfaceInitMessage();
	msg->Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());

	if (TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct1InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct1InterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::OnClientDisconnected(const FTbSame1SameStruct1InterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	ConnectedClients.Remove(Context->GetSender());
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::OnFunc1Request(const FTbSame1SameStruct1InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSame1SameStruct1InterfaceFunc1ReplyMessage();
	msg->RepsonseId = InMessage.RepsonseId;
	msg->Result = BackendService->Execute_Func1(BackendService.GetObject(), InMessage.Param1);

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
	auto msg = new FTbSame1SameStruct1InterfaceSig1SignalMessage();
	msg->Param1 = InParam1;
	if (TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid())
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
	BackendService->Execute_SetProp1(BackendService.GetObject(), InMessage.Prop1);
}

void UTbSame1SameStruct1InterfaceMsgBusAdapter::OnProp1Changed(const FTbSame1Struct1& InProp1)
{
	auto msg = new FTbSame1SameStruct1InterfaceProp1ChangedMessage();
	msg->Prop1 = InProp1;

	if (TbSame1SameStruct1InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct1InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct1InterfaceProp1ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}
