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

#include "Generated/MsgBus/TbSame1SameStruct2InterfaceMsgBusAdapter.h"
#include "Generated/MsgBus/TbSame1SameStruct2InterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTbSame1SameStruct2InterfaceMsgBusAdapter::UTbSame1SameStruct2InterfaceMsgBusAdapter()
{
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::Deinitialize()
{
	_StopListening();

	Super::Deinitialize();
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::_StartListening()
{
	if (TbSame1SameStruct2InterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	TbSame1SameStruct2InterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSame1/SameStruct2Interface/Service")
		.Handling<FTbSame1SameStruct2InterfaceDiscoveryMessage>(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTbSame1SameStruct2InterfacePingMessage>(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnPing)
		.Handling<FTbSame1SameStruct2InterfaceClientDisconnectMessage>(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTbSame1SameStruct2InterfaceSetProp1RequestMessage>(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnSetProp1Request)
		.Handling<FTbSame1SameStruct2InterfaceSetProp2RequestMessage>(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnSetProp2Request)
		.Handling<FTbSame1SameStruct2InterfaceFunc1RequestMessage>(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnFunc1Request)
		.Handling<FTbSame1SameStruct2InterfaceFunc2RequestMessage>(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnFunc2Request)
		.Build();
	// clang-format on

	if (TbSame1SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct2InterfaceMsgBusEndpoint->Subscribe<FTbSame1SameStruct2InterfaceDiscoveryMessage>();
	}
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::_StopListening()
{
	auto msg = new FTbSame1SameStruct2InterfaceServiceDisconnectMessage();

	if (TbSame1SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct2InterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	TbSame1SameStruct2InterfaceMsgBusEndpoint.Reset();
	ConnectedClients.Reset();
}

bool UTbSame1SameStruct2InterfaceMsgBusAdapter::_IsListening() const
{
	return TbSame1SameStruct2InterfaceMsgBusEndpoint.IsValid();
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::_setBackendService(TScriptInterface<ITbSame1SameStruct2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame1SameStruct2InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameStruct2Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnProp1Changed);
		BackendSignals->OnProp2Changed.RemoveDynamic(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnProp2Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnSig1);
		BackendSignals->OnSig2Signal.RemoveDynamic(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnSig2);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame1SameStruct2Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame1SameStruct2InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSame1SameStruct2Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnProp1Changed);
	BackendSignals->OnProp2Changed.AddDynamic(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnProp2Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnSig1);
	BackendSignals->OnSig2Signal.AddDynamic(this, &UTbSame1SameStruct2InterfaceMsgBusAdapter::OnSig2);
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::OnNewClientDiscovered(const FTbSame1SameStruct2InterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FMessageAddress& ClientAddress = ConnectedClients.AddDefaulted_GetRef();
	ClientAddress = Context->GetSender();

	auto msg = new FTbSame1SameStruct2InterfaceInitMessage();
	msg->Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	msg->Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());

	if (TbSame1SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct2InterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::OnPing(const FTbSame1SameStruct2InterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSame1SameStruct2InterfacePongMessage();
	msg->Timestamp = InMessage.Timestamp;

	if (TbSame1SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct2InterfacePongMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::OnClientDisconnected(const FTbSame1SameStruct2InterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	ConnectedClients.Remove(Context->GetSender());
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::OnFunc1Request(const FTbSame1SameStruct2InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSame1SameStruct2InterfaceFunc1ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_Func1(BackendService.GetObject(), InMessage.Param1);

	if (TbSame1SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct2InterfaceFunc1ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::OnFunc2Request(const FTbSame1SameStruct2InterfaceFunc2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSame1SameStruct2InterfaceFunc2ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_Func2(BackendService.GetObject(), InMessage.Param1, InMessage.Param2);

	if (TbSame1SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct2InterfaceFunc2ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::OnSig1(const FTbSame1Struct1& InParam1)
{
	auto msg = new FTbSame1SameStruct2InterfaceSig1SignalMessage();
	msg->Param1 = InParam1;
	if (TbSame1SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct2InterfaceSig1SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::OnSig2(const FTbSame1Struct1& InParam1, const FTbSame1Struct2& InParam2)
{
	auto msg = new FTbSame1SameStruct2InterfaceSig2SignalMessage();
	msg->Param1 = InParam1;
	msg->Param2 = InParam2;
	if (TbSame1SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct2InterfaceSig2SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::OnSetProp1Request(const FTbSame1SameStruct2InterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetProp1(BackendService.GetObject(), InMessage.Prop1);
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::OnProp1Changed(const FTbSame1Struct2& InProp1)
{
	auto msg = new FTbSame1SameStruct2InterfaceProp1ChangedMessage();
	msg->Prop1 = InProp1;

	if (TbSame1SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct2InterfaceProp1ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::OnSetProp2Request(const FTbSame1SameStruct2InterfaceSetProp2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetProp2(BackendService.GetObject(), InMessage.Prop2);
}

void UTbSame1SameStruct2InterfaceMsgBusAdapter::OnProp2Changed(const FTbSame1Struct2& InProp2)
{
	auto msg = new FTbSame1SameStruct2InterfaceProp2ChangedMessage();
	msg->Prop2 = InProp2;

	if (TbSame1SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame1SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame1SameStruct2InterfaceProp2ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}