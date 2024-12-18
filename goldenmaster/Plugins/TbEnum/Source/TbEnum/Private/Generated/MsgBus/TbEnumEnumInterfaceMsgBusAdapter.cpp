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

#include "Generated/MsgBus/TbEnumEnumInterfaceMsgBusAdapter.h"
#include "Generated/MsgBus/TbEnumEnumInterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTbEnumEnumInterfaceMsgBusAdapter::UTbEnumEnumInterfaceMsgBusAdapter()
{
}

void UTbEnumEnumInterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbEnumEnumInterfaceMsgBusAdapter::Deinitialize()
{
	_StopListening();

	Super::Deinitialize();
}

void UTbEnumEnumInterfaceMsgBusAdapter::_StartListening()
{
	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	TbEnumEnumInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbEnum/EnumInterface/Service")
		.Handling<FTbEnumEnumInterfaceDiscoveryMessage>(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTbEnumEnumInterfacePingMessage>(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnPing)
		.Handling<FTbEnumEnumInterfaceClientDisconnectMessage>(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTbEnumEnumInterfaceSetProp0RequestMessage>(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnSetProp0Request)
		.Handling<FTbEnumEnumInterfaceSetProp1RequestMessage>(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnSetProp1Request)
		.Handling<FTbEnumEnumInterfaceSetProp2RequestMessage>(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnSetProp2Request)
		.Handling<FTbEnumEnumInterfaceSetProp3RequestMessage>(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnSetProp3Request)
		.Handling<FTbEnumEnumInterfaceFunc0RequestMessage>(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnFunc0Request)
		.Handling<FTbEnumEnumInterfaceFunc1RequestMessage>(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnFunc1Request)
		.Handling<FTbEnumEnumInterfaceFunc2RequestMessage>(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnFunc2Request)
		.Handling<FTbEnumEnumInterfaceFunc3RequestMessage>(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnFunc3Request)
		.Build();
	// clang-format on

	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Subscribe<FTbEnumEnumInterfaceDiscoveryMessage>();
	}
}

void UTbEnumEnumInterfaceMsgBusAdapter::_StopListening()
{
	auto msg = new FTbEnumEnumInterfaceServiceDisconnectMessage();

	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	TbEnumEnumInterfaceMsgBusEndpoint.Reset();
	ConnectedClients.Reset();
}

bool UTbEnumEnumInterfaceMsgBusAdapter::_IsListening() const
{
	return TbEnumEnumInterfaceMsgBusEndpoint.IsValid();
}

void UTbEnumEnumInterfaceMsgBusAdapter::_setBackendService(TScriptInterface<ITbEnumEnumInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbEnumEnumInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbEnumEnumInterface"));
		BackendSignals->OnProp0Changed.RemoveDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnProp0Changed);
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnProp1Changed);
		BackendSignals->OnProp2Changed.RemoveDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnProp2Changed);
		BackendSignals->OnProp3Changed.RemoveDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnProp3Changed);
		BackendSignals->OnSig0Signal.RemoveDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnSig0);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnSig1);
		BackendSignals->OnSig2Signal.RemoveDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnSig2);
		BackendSignals->OnSig3Signal.RemoveDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnSig3);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbEnumEnumInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbEnumEnumInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbEnumEnumInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp0Changed.AddDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnProp0Changed);
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnProp1Changed);
	BackendSignals->OnProp2Changed.AddDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnProp2Changed);
	BackendSignals->OnProp3Changed.AddDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnProp3Changed);
	BackendSignals->OnSig0Signal.AddDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnSig0);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnSig1);
	BackendSignals->OnSig2Signal.AddDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnSig2);
	BackendSignals->OnSig3Signal.AddDynamic(this, &UTbEnumEnumInterfaceMsgBusAdapter::OnSig3);
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnNewClientDiscovered(const FTbEnumEnumInterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FMessageAddress& ClientAddress = ConnectedClients.AddDefaulted_GetRef();
	ClientAddress = Context->GetSender();

	auto msg = new FTbEnumEnumInterfaceInitMessage();
	msg->Prop0 = BackendService->Execute_GetProp0(BackendService.GetObject());
	msg->Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	msg->Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());
	msg->Prop3 = BackendService->Execute_GetProp3(BackendService.GetObject());

	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnPing(const FTbEnumEnumInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbEnumEnumInterfacePongMessage();
	msg->Timestamp = InMessage.Timestamp;

	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfacePongMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnClientDisconnected(const FTbEnumEnumInterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	ConnectedClients.Remove(Context->GetSender());
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnFunc0Request(const FTbEnumEnumInterfaceFunc0RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbEnumEnumInterfaceFunc0ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_Func0(BackendService.GetObject(), InMessage.Param0);

	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceFunc0ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnFunc1Request(const FTbEnumEnumInterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbEnumEnumInterfaceFunc1ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_Func1(BackendService.GetObject(), InMessage.Param1);

	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceFunc1ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnFunc2Request(const FTbEnumEnumInterfaceFunc2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbEnumEnumInterfaceFunc2ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_Func2(BackendService.GetObject(), InMessage.Param2);

	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceFunc2ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnFunc3Request(const FTbEnumEnumInterfaceFunc3RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbEnumEnumInterfaceFunc3ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_Func3(BackendService.GetObject(), InMessage.Param3);

	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceFunc3ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnSig0(ETbEnumEnum0 InParam0)
{
	auto msg = new FTbEnumEnumInterfaceSig0SignalMessage();
	msg->Param0 = InParam0;
	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceSig0SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnSig1(ETbEnumEnum1 InParam1)
{
	auto msg = new FTbEnumEnumInterfaceSig1SignalMessage();
	msg->Param1 = InParam1;
	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceSig1SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnSig2(ETbEnumEnum2 InParam2)
{
	auto msg = new FTbEnumEnumInterfaceSig2SignalMessage();
	msg->Param2 = InParam2;
	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceSig2SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnSig3(ETbEnumEnum3 InParam3)
{
	auto msg = new FTbEnumEnumInterfaceSig3SignalMessage();
	msg->Param3 = InParam3;
	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceSig3SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnSetProp0Request(const FTbEnumEnumInterfaceSetProp0RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetProp0(BackendService.GetObject(), InMessage.Prop0);
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnProp0Changed(ETbEnumEnum0 InProp0)
{
	auto msg = new FTbEnumEnumInterfaceProp0ChangedMessage();
	msg->Prop0 = InProp0;

	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceProp0ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnSetProp1Request(const FTbEnumEnumInterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetProp1(BackendService.GetObject(), InMessage.Prop1);
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnProp1Changed(ETbEnumEnum1 InProp1)
{
	auto msg = new FTbEnumEnumInterfaceProp1ChangedMessage();
	msg->Prop1 = InProp1;

	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceProp1ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnSetProp2Request(const FTbEnumEnumInterfaceSetProp2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetProp2(BackendService.GetObject(), InMessage.Prop2);
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnProp2Changed(ETbEnumEnum2 InProp2)
{
	auto msg = new FTbEnumEnumInterfaceProp2ChangedMessage();
	msg->Prop2 = InProp2;

	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceProp2ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnSetProp3Request(const FTbEnumEnumInterfaceSetProp3RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetProp3(BackendService.GetObject(), InMessage.Prop3);
}

void UTbEnumEnumInterfaceMsgBusAdapter::OnProp3Changed(ETbEnumEnum3 InProp3)
{
	auto msg = new FTbEnumEnumInterfaceProp3ChangedMessage();
	msg->Prop3 = InProp3;

	if (TbEnumEnumInterfaceMsgBusEndpoint.IsValid())
	{
		TbEnumEnumInterfaceMsgBusEndpoint->Send<FTbEnumEnumInterfaceProp3ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}