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

#include "Generated/MsgBus/TbSimpleNoSignalsInterfaceMsgBusAdapter.h"
#include "Generated/MsgBus/TbSimpleNoSignalsInterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTbSimpleNoSignalsInterfaceMsgBusAdapter::UTbSimpleNoSignalsInterfaceMsgBusAdapter()
{
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::Deinitialize()
{
	_StopListening();

	Super::Deinitialize();
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::_StartListening()
{
	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	TbSimpleNoSignalsInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSimple/NoSignalsInterface/Service")
		.Handling<FTbSimpleNoSignalsInterfaceDiscoveryMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTbSimpleNoSignalsInterfacePingMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnPing)
		.Handling<FTbSimpleNoSignalsInterfaceClientDisconnectMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTbSimpleNoSignalsInterfaceSetPropBoolRequestMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnSetPropBoolRequest)
		.Handling<FTbSimpleNoSignalsInterfaceSetPropIntRequestMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnSetPropIntRequest)
		.Handling<FTbSimpleNoSignalsInterfaceFuncVoidRequestMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnFuncVoidRequest)
		.Handling<FTbSimpleNoSignalsInterfaceFuncBoolRequestMessage>(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnFuncBoolRequest)
		.Build();
	// clang-format on

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoSignalsInterfaceMsgBusEndpoint->Subscribe<FTbSimpleNoSignalsInterfaceDiscoveryMessage>();
	}
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::_StopListening()
{
	auto msg = new FTbSimpleNoSignalsInterfaceServiceDisconnectMessage();

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	TbSimpleNoSignalsInterfaceMsgBusEndpoint.Reset();
	ConnectedClients.Reset();
}

bool UTbSimpleNoSignalsInterfaceMsgBusAdapter::_IsListening() const
{
	return TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid();
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::_setBackendService(TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleNoSignalsInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleNoSignalsInterface"));
		BackendSignals->OnPropBoolChanged.RemoveDynamic(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnPropBoolChanged);
		BackendSignals->OnPropIntChanged.RemoveDynamic(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnPropIntChanged);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleNoSignalsInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleNoSignalsInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSimpleNoSignalsInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnPropBoolChanged.AddDynamic(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnPropBoolChanged);
	BackendSignals->OnPropIntChanged.AddDynamic(this, &UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnPropIntChanged);
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnNewClientDiscovered(const FTbSimpleNoSignalsInterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FMessageAddress& ClientAddress = ConnectedClients.AddDefaulted_GetRef();
	ClientAddress = Context->GetSender();

	auto msg = new FTbSimpleNoSignalsInterfaceInitMessage();
	msg->bPropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	msg->PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnPing(const FTbSimpleNoSignalsInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleNoSignalsInterfacePongMessage();
	msg->Timestamp = InMessage.Timestamp;

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfacePongMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnClientDisconnected(const FTbSimpleNoSignalsInterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	ConnectedClients.Remove(Context->GetSender());
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnFuncVoidRequest(const FTbSimpleNoSignalsInterfaceFuncVoidRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	BackendService->Execute_FuncVoid(BackendService.GetObject());
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnFuncBoolRequest(const FTbSimpleNoSignalsInterfaceFuncBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleNoSignalsInterfaceFuncBoolReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncBool(BackendService.GetObject(), InMessage.bParamBool);

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfaceFuncBoolReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnSetPropBoolRequest(const FTbSimpleNoSignalsInterfaceSetPropBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropBool(BackendService.GetObject(), InMessage.bPropBool);
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnPropBoolChanged(bool bInPropBool)
{
	auto msg = new FTbSimpleNoSignalsInterfacePropBoolChangedMessage();
	msg->bPropBool = bInPropBool;

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfacePropBoolChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnSetPropIntRequest(const FTbSimpleNoSignalsInterfaceSetPropIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InMessage.PropInt);
}

void UTbSimpleNoSignalsInterfaceMsgBusAdapter::OnPropIntChanged(int32 InPropInt)
{
	auto msg = new FTbSimpleNoSignalsInterfacePropIntChangedMessage();
	msg->PropInt = InPropInt;

	if (TbSimpleNoSignalsInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoSignalsInterfaceMsgBusEndpoint->Send<FTbSimpleNoSignalsInterfacePropIntChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}