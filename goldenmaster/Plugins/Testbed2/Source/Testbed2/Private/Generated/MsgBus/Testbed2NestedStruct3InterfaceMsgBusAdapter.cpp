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

#include "Generated/MsgBus/Testbed2NestedStruct3InterfaceMsgBusAdapter.h"
#include "Generated/MsgBus/Testbed2NestedStruct3InterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTestbed2NestedStruct3InterfaceMsgBusAdapter::UTestbed2NestedStruct3InterfaceMsgBusAdapter()
{
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::Deinitialize()
{
	_StopListening();

	Super::Deinitialize();
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::_StartListening()
{
	if (Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	Testbed2NestedStruct3InterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/Testbed2/NestedStruct3Interface/Service")
		.Handling<FTestbed2NestedStruct3InterfaceDiscoveryMessage>(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTestbed2NestedStruct3InterfacePingMessage>(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnPing)
		.Handling<FTestbed2NestedStruct3InterfaceClientDisconnectMessage>(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTestbed2NestedStruct3InterfaceSetProp1RequestMessage>(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSetProp1Request)
		.Handling<FTestbed2NestedStruct3InterfaceSetProp2RequestMessage>(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSetProp2Request)
		.Handling<FTestbed2NestedStruct3InterfaceSetProp3RequestMessage>(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSetProp3Request)
		.Handling<FTestbed2NestedStruct3InterfaceFunc1RequestMessage>(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnFunc1Request)
		.Handling<FTestbed2NestedStruct3InterfaceFunc2RequestMessage>(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnFunc2Request)
		.Handling<FTestbed2NestedStruct3InterfaceFunc3RequestMessage>(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnFunc3Request)
		.Build();
	// clang-format on

	if (Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct3InterfaceMsgBusEndpoint->Subscribe<FTestbed2NestedStruct3InterfaceDiscoveryMessage>();
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::_StopListening()
{
	auto msg = new FTestbed2NestedStruct3InterfaceServiceDisconnectMessage();

	if (Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct3InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct3InterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	Testbed2NestedStruct3InterfaceMsgBusEndpoint.Reset();
	ConnectedClients.Reset();
}

bool UTestbed2NestedStruct3InterfaceMsgBusAdapter::_IsListening() const
{
	return Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid();
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::_setBackendService(TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed2NestedStruct3InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2NestedStruct3Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnProp1Changed);
		BackendSignals->OnProp2Changed.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnProp2Changed);
		BackendSignals->OnProp3Changed.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnProp3Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSig1);
		BackendSignals->OnSig2Signal.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSig2);
		BackendSignals->OnSig3Signal.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSig3);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed2NestedStruct3Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed2NestedStruct3InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service Testbed2NestedStruct3Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnProp1Changed);
	BackendSignals->OnProp2Changed.AddDynamic(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnProp2Changed);
	BackendSignals->OnProp3Changed.AddDynamic(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnProp3Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSig1);
	BackendSignals->OnSig2Signal.AddDynamic(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSig2);
	BackendSignals->OnSig3Signal.AddDynamic(this, &UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSig3);
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnNewClientDiscovered(const FTestbed2NestedStruct3InterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FMessageAddress& ClientAddress = ConnectedClients.AddDefaulted_GetRef();
	ClientAddress = Context->GetSender();

	auto msg = new FTestbed2NestedStruct3InterfaceInitMessage();
	msg->_ClientPingIntervalMS = _HeartbeatIntervalMS;
	msg->Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	msg->Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());
	msg->Prop3 = BackendService->Execute_GetProp3(BackendService.GetObject());

	if (Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct3InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct3InterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnPing(const FTestbed2NestedStruct3InterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed2NestedStruct3InterfacePongMessage();
	msg->Timestamp = InMessage.Timestamp;

	if (Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct3InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct3InterfacePongMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnClientDisconnected(const FTestbed2NestedStruct3InterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	ConnectedClients.Remove(Context->GetSender());
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnFunc1Request(const FTestbed2NestedStruct3InterfaceFunc1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed2NestedStruct3InterfaceFunc1ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_Func1(BackendService.GetObject(), InMessage.Param1);

	if (Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct3InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct3InterfaceFunc1ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnFunc2Request(const FTestbed2NestedStruct3InterfaceFunc2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed2NestedStruct3InterfaceFunc2ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_Func2(BackendService.GetObject(), InMessage.Param1, InMessage.Param2);

	if (Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct3InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct3InterfaceFunc2ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnFunc3Request(const FTestbed2NestedStruct3InterfaceFunc3RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed2NestedStruct3InterfaceFunc3ReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_Func3(BackendService.GetObject(), InMessage.Param1, InMessage.Param2, InMessage.Param3);

	if (Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct3InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct3InterfaceFunc3ReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSig1(const FTestbed2NestedStruct1& InParam1)
{
	auto msg = new FTestbed2NestedStruct3InterfaceSig1SignalMessage();
	msg->Param1 = InParam1;
	if (Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct3InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct3InterfaceSig1SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSig2(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2)
{
	auto msg = new FTestbed2NestedStruct3InterfaceSig2SignalMessage();
	msg->Param1 = InParam1;
	msg->Param2 = InParam2;
	if (Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct3InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct3InterfaceSig2SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSig3(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2, const FTestbed2NestedStruct3& InParam3)
{
	auto msg = new FTestbed2NestedStruct3InterfaceSig3SignalMessage();
	msg->Param1 = InParam1;
	msg->Param2 = InParam2;
	msg->Param3 = InParam3;
	if (Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct3InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct3InterfaceSig3SignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSetProp1Request(const FTestbed2NestedStruct3InterfaceSetProp1RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetProp1(BackendService.GetObject(), InMessage.Prop1);
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	auto msg = new FTestbed2NestedStruct3InterfaceProp1ChangedMessage();
	msg->Prop1 = InProp1;

	if (Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct3InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct3InterfaceProp1ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSetProp2Request(const FTestbed2NestedStruct3InterfaceSetProp2RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetProp2(BackendService.GetObject(), InMessage.Prop2);
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnProp2Changed(const FTestbed2NestedStruct2& InProp2)
{
	auto msg = new FTestbed2NestedStruct3InterfaceProp2ChangedMessage();
	msg->Prop2 = InProp2;

	if (Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct3InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct3InterfaceProp2ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnSetProp3Request(const FTestbed2NestedStruct3InterfaceSetProp3RequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetProp3(BackendService.GetObject(), InMessage.Prop3);
}

void UTestbed2NestedStruct3InterfaceMsgBusAdapter::OnProp3Changed(const FTestbed2NestedStruct3& InProp3)
{
	auto msg = new FTestbed2NestedStruct3InterfaceProp3ChangedMessage();
	msg->Prop3 = InProp3;

	if (Testbed2NestedStruct3InterfaceMsgBusEndpoint.IsValid())
	{
		Testbed2NestedStruct3InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct3InterfaceProp3ChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}
