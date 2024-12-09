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

#include "Generated/MsgBus/TbSame2SameStruct2InterfaceMsgBusAdapter.h"
#include "Generated/MsgBus/TbSame2SameStruct2InterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTbSame2SameStruct2InterfaceMsgBusAdapter::UTbSame2SameStruct2InterfaceMsgBusAdapter()
{
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::Deinitialize()
{
	StopListening();

	Super::Deinitialize();
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::StartListening()
{
	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	TbSame2SameStruct2InterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSame2/SameStruct2Interface/Service")
		.Handling<FTbSame2SameStruct2InterfaceDiscoveryMessage>(this, &UTbSame2SameStruct2InterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTbSame2SameStruct2InterfaceClientDisconnectMessage>(this, &UTbSame2SameStruct2InterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTbSame2SameStruct2InterfaceSetProp1RequestMessage>(this, &UTbSame2SameStruct2InterfaceMsgBusAdapter::OnSetProp1Request)
		.Handling<FTbSame2SameStruct2InterfaceSetProp2RequestMessage>(this, &UTbSame2SameStruct2InterfaceMsgBusAdapter::OnSetProp2Request)
		.Handling<FTbSame2SameStruct2InterfaceFunc1RequestMessage>(this, &UTbSame2SameStruct2InterfaceMsgBusAdapter::OnFunc1Request)
		.Handling<FTbSame2SameStruct2InterfaceFunc2RequestMessage>(this, &UTbSame2SameStruct2InterfaceMsgBusAdapter::OnFunc2Request)
		.Build();
	// clang-format on

	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameStruct2InterfaceMsgBusEndpoint->Subscribe<FTbSame2SameStruct2InterfaceDiscoveryMessage>();
	}
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::StopListening()
{
	auto msg = new FTbSame2SameStruct2InterfaceServiceDisconnectMessage();

	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct2InterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	TbSame2SameStruct2InterfaceMsgBusEndpoint.Reset();
	ConnectedClients.Reset();
}

bool UTbSame2SameStruct2InterfaceMsgBusAdapter::IsListening() const
{
	return TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid();
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::setBackendService(TScriptInterface<ITbSame2SameStruct2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame2SameStruct2InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame2SameStruct2Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTbSame2SameStruct2InterfaceMsgBusAdapter::OnProp1Changed);
		BackendSignals->OnProp2Changed.RemoveDynamic(this, &UTbSame2SameStruct2InterfaceMsgBusAdapter::OnProp2Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTbSame2SameStruct2InterfaceMsgBusAdapter::OnSig1);
		BackendSignals->OnSig2Signal.RemoveDynamic(this, &UTbSame2SameStruct2InterfaceMsgBusAdapter::OnSig2);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame2SameStruct2Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame2SameStruct2InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSame2SameStruct2Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTbSame2SameStruct2InterfaceMsgBusAdapter::OnProp1Changed);
	BackendSignals->OnProp2Changed.AddDynamic(this, &UTbSame2SameStruct2InterfaceMsgBusAdapter::OnProp2Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTbSame2SameStruct2InterfaceMsgBusAdapter::OnSig1);
	BackendSignals->OnSig2Signal.AddDynamic(this, &UTbSame2SameStruct2InterfaceMsgBusAdapter::OnSig2);
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::OnNewClientDiscovered(const FTbSame2SameStruct2InterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FMessageAddress& ClientAddress = ConnectedClients.AddDefaulted_GetRef();
	ClientAddress = Context->GetSender();

	auto msg = new FTbSame2SameStruct2InterfaceInitMessage();
	msg->Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	msg->Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());

	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct2InterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::OnClientDisconnected(const FTbSame2SameStruct2InterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	ConnectedClients.Remove(Context->GetSender());
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::OnFunc1Request(const FTbSame2SameStruct2InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSame2SameStruct2InterfaceFunc1ReplyMessage();
	msg->RepsonseId = InMessage.RepsonseId;
	msg->Result = BackendService->Execute_Func1(BackendService.GetObject(), InMessage.Param1);

	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct2InterfaceFunc1ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::OnFunc2Request(const FTbSame2SameStruct2InterfaceFunc2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSame2SameStruct2InterfaceFunc2ReplyMessage();
	msg->RepsonseId = InMessage.RepsonseId;
	msg->Result = BackendService->Execute_Func2(BackendService.GetObject(), InMessage.Param1, InMessage.Param2);

	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct2InterfaceFunc2ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::OnSig1(const FTbSame2Struct1& InParam1)
{
	auto msg = new FTbSame2SameStruct2InterfaceSig1SignalMessage();
	msg->Param1 = InParam1;
	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct2InterfaceSig1SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::OnSig2(const FTbSame2Struct1& InParam1, const FTbSame2Struct2& InParam2)
{
	auto msg = new FTbSame2SameStruct2InterfaceSig2SignalMessage();
	msg->Param1 = InParam1;
	msg->Param2 = InParam2;
	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct2InterfaceSig2SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::OnSetProp1Request(const FTbSame2SameStruct2InterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetProp1(BackendService.GetObject(), InMessage.Prop1);
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::OnProp1Changed(const FTbSame2Struct2& InProp1)
{
	auto msg = new FTbSame2SameStruct2InterfaceProp1ChangedMessage();
	msg->Prop1 = InProp1;

	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct2InterfaceProp1ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::OnSetProp2Request(const FTbSame2SameStruct2InterfaceSetProp2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetProp2(BackendService.GetObject(), InMessage.Prop2);
}

void UTbSame2SameStruct2InterfaceMsgBusAdapter::OnProp2Changed(const FTbSame2Struct2& InProp2)
{
	auto msg = new FTbSame2SameStruct2InterfaceProp2ChangedMessage();
	msg->Prop2 = InProp2;

	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct2InterfaceProp2ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}
