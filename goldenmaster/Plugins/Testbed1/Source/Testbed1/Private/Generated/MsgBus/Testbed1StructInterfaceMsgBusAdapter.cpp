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

#include "Generated/MsgBus/Testbed1StructInterfaceMsgBusAdapter.h"
#include "Generated/MsgBus/Testbed1StructInterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTestbed1StructInterfaceMsgBusAdapter::UTestbed1StructInterfaceMsgBusAdapter()
{
}

void UTestbed1StructInterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed1StructInterfaceMsgBusAdapter::Deinitialize()
{
	_StopListening();

	Super::Deinitialize();
}

void UTestbed1StructInterfaceMsgBusAdapter::_StartListening()
{
	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	Testbed1StructInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/Testbed1/StructInterface/Service")
		.Handling<FTestbed1StructInterfaceDiscoveryMessage>(this, &UTestbed1StructInterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTestbed1StructInterfacePingMessage>(this, &UTestbed1StructInterfaceMsgBusAdapter::OnPing)
		.Handling<FTestbed1StructInterfaceClientDisconnectMessage>(this, &UTestbed1StructInterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTestbed1StructInterfaceSetPropBoolRequestMessage>(this, &UTestbed1StructInterfaceMsgBusAdapter::OnSetPropBoolRequest)
		.Handling<FTestbed1StructInterfaceSetPropIntRequestMessage>(this, &UTestbed1StructInterfaceMsgBusAdapter::OnSetPropIntRequest)
		.Handling<FTestbed1StructInterfaceSetPropFloatRequestMessage>(this, &UTestbed1StructInterfaceMsgBusAdapter::OnSetPropFloatRequest)
		.Handling<FTestbed1StructInterfaceSetPropStringRequestMessage>(this, &UTestbed1StructInterfaceMsgBusAdapter::OnSetPropStringRequest)
		.Handling<FTestbed1StructInterfaceFuncBoolRequestMessage>(this, &UTestbed1StructInterfaceMsgBusAdapter::OnFuncBoolRequest)
		.Handling<FTestbed1StructInterfaceFuncIntRequestMessage>(this, &UTestbed1StructInterfaceMsgBusAdapter::OnFuncIntRequest)
		.Handling<FTestbed1StructInterfaceFuncFloatRequestMessage>(this, &UTestbed1StructInterfaceMsgBusAdapter::OnFuncFloatRequest)
		.Handling<FTestbed1StructInterfaceFuncStringRequestMessage>(this, &UTestbed1StructInterfaceMsgBusAdapter::OnFuncStringRequest)
		.Build();
	// clang-format on

	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Subscribe<FTestbed1StructInterfaceDiscoveryMessage>();
	}
}

void UTestbed1StructInterfaceMsgBusAdapter::_StopListening()
{
	auto msg = new FTestbed1StructInterfaceServiceDisconnectMessage();

	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	Testbed1StructInterfaceMsgBusEndpoint.Reset();
	ConnectedClients.Reset();
}

bool UTestbed1StructInterfaceMsgBusAdapter::_IsListening() const
{
	return Testbed1StructInterfaceMsgBusEndpoint.IsValid();
}

void UTestbed1StructInterfaceMsgBusAdapter::_setBackendService(TScriptInterface<ITestbed1StructInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed1StructInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructInterface"));
		BackendSignals->OnPropBoolChanged.RemoveDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnPropBoolChanged);
		BackendSignals->OnPropIntChanged.RemoveDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnPropIntChanged);
		BackendSignals->OnPropFloatChanged.RemoveDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnPropFloatChanged);
		BackendSignals->OnPropStringChanged.RemoveDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnPropStringChanged);
		BackendSignals->OnSigBoolSignal.RemoveDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnSigBool);
		BackendSignals->OnSigIntSignal.RemoveDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnSigInt);
		BackendSignals->OnSigFloatSignal.RemoveDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnSigFloat);
		BackendSignals->OnSigStringSignal.RemoveDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed1StructInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed1StructInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service Testbed1StructInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnPropBoolChanged.AddDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnPropBoolChanged);
	BackendSignals->OnPropIntChanged.AddDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnPropIntChanged);
	BackendSignals->OnPropFloatChanged.AddDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnPropFloatChanged);
	BackendSignals->OnPropStringChanged.AddDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnPropStringChanged);
	BackendSignals->OnSigBoolSignal.AddDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnSigBool);
	BackendSignals->OnSigIntSignal.AddDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnSigInt);
	BackendSignals->OnSigFloatSignal.AddDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnSigFloat);
	BackendSignals->OnSigStringSignal.AddDynamic(this, &UTestbed1StructInterfaceMsgBusAdapter::OnSigString);
}

void UTestbed1StructInterfaceMsgBusAdapter::OnNewClientDiscovered(const FTestbed1StructInterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FMessageAddress& ClientAddress = ConnectedClients.AddDefaulted_GetRef();
	ClientAddress = Context->GetSender();

	auto msg = new FTestbed1StructInterfaceInitMessage();
	msg->_ClientPingIntervalMS = _HeartbeatIntervalMS;
	msg->PropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	msg->PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
	msg->PropFloat = BackendService->Execute_GetPropFloat(BackendService.GetObject());
	msg->PropString = BackendService->Execute_GetPropString(BackendService.GetObject());

	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructInterfaceMsgBusAdapter::OnPing(const FTestbed1StructInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed1StructInterfacePongMessage();
	msg->Timestamp = InMessage.Timestamp;

	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfacePongMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructInterfaceMsgBusAdapter::OnClientDisconnected(const FTestbed1StructInterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	ConnectedClients.Remove(Context->GetSender());
}

void UTestbed1StructInterfaceMsgBusAdapter::OnFuncBoolRequest(const FTestbed1StructInterfaceFuncBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed1StructInterfaceFuncBoolReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncBool(BackendService.GetObject(), InMessage.ParamBool);

	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceFuncBoolReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructInterfaceMsgBusAdapter::OnFuncIntRequest(const FTestbed1StructInterfaceFuncIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed1StructInterfaceFuncIntReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncInt(BackendService.GetObject(), InMessage.ParamInt);

	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceFuncIntReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructInterfaceMsgBusAdapter::OnFuncFloatRequest(const FTestbed1StructInterfaceFuncFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed1StructInterfaceFuncFloatReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncFloat(BackendService.GetObject(), InMessage.ParamFloat);

	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceFuncFloatReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructInterfaceMsgBusAdapter::OnFuncStringRequest(const FTestbed1StructInterfaceFuncStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed1StructInterfaceFuncStringReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncString(BackendService.GetObject(), InMessage.ParamString);

	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceFuncStringReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructInterfaceMsgBusAdapter::OnSigBool(const FTestbed1StructBool& InParamBool)
{
	auto msg = new FTestbed1StructInterfaceSigBoolSignalMessage();
	msg->ParamBool = InParamBool;
	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceSigBoolSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructInterfaceMsgBusAdapter::OnSigInt(const FTestbed1StructInt& InParamInt)
{
	auto msg = new FTestbed1StructInterfaceSigIntSignalMessage();
	msg->ParamInt = InParamInt;
	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceSigIntSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructInterfaceMsgBusAdapter::OnSigFloat(const FTestbed1StructFloat& InParamFloat)
{
	auto msg = new FTestbed1StructInterfaceSigFloatSignalMessage();
	msg->ParamFloat = InParamFloat;
	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceSigFloatSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructInterfaceMsgBusAdapter::OnSigString(const FTestbed1StructString& InParamString)
{
	auto msg = new FTestbed1StructInterfaceSigStringSignalMessage();
	msg->ParamString = InParamString;
	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceSigStringSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructInterfaceMsgBusAdapter::OnSetPropBoolRequest(const FTestbed1StructInterfaceSetPropBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropBool(BackendService.GetObject(), InMessage.PropBool);
}

void UTestbed1StructInterfaceMsgBusAdapter::OnPropBoolChanged(const FTestbed1StructBool& InPropBool)
{
	auto msg = new FTestbed1StructInterfacePropBoolChangedMessage();
	msg->PropBool = InPropBool;

	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfacePropBoolChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructInterfaceMsgBusAdapter::OnSetPropIntRequest(const FTestbed1StructInterfaceSetPropIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InMessage.PropInt);
}

void UTestbed1StructInterfaceMsgBusAdapter::OnPropIntChanged(const FTestbed1StructInt& InPropInt)
{
	auto msg = new FTestbed1StructInterfacePropIntChangedMessage();
	msg->PropInt = InPropInt;

	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfacePropIntChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructInterfaceMsgBusAdapter::OnSetPropFloatRequest(const FTestbed1StructInterfaceSetPropFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropFloat(BackendService.GetObject(), InMessage.PropFloat);
}

void UTestbed1StructInterfaceMsgBusAdapter::OnPropFloatChanged(const FTestbed1StructFloat& InPropFloat)
{
	auto msg = new FTestbed1StructInterfacePropFloatChangedMessage();
	msg->PropFloat = InPropFloat;

	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfacePropFloatChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructInterfaceMsgBusAdapter::OnSetPropStringRequest(const FTestbed1StructInterfaceSetPropStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropString(BackendService.GetObject(), InMessage.PropString);
}

void UTestbed1StructInterfaceMsgBusAdapter::OnPropStringChanged(const FTestbed1StructString& InPropString)
{
	auto msg = new FTestbed1StructInterfacePropStringChangedMessage();
	msg->PropString = InPropString;

	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfacePropStringChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}
