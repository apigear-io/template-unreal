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

#include "Generated/MsgBus/TbSimpleEmptyInterfaceMsgBusAdapter.h"
#include "Generated/MsgBus/TbSimpleEmptyInterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTbSimpleEmptyInterfaceMsgBusAdapter::UTbSimpleEmptyInterfaceMsgBusAdapter()
{
}

void UTbSimpleEmptyInterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleEmptyInterfaceMsgBusAdapter::Deinitialize()
{
	_StopListening();

	Super::Deinitialize();
}

void UTbSimpleEmptyInterfaceMsgBusAdapter::_StartListening()
{
	if (TbSimpleEmptyInterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	TbSimpleEmptyInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSimple/EmptyInterface/Service")
		.Handling<FTbSimpleEmptyInterfaceDiscoveryMessage>(this, &UTbSimpleEmptyInterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTbSimpleEmptyInterfacePingMessage>(this, &UTbSimpleEmptyInterfaceMsgBusAdapter::OnPing)
		.Handling<FTbSimpleEmptyInterfaceClientDisconnectMessage>(this, &UTbSimpleEmptyInterfaceMsgBusAdapter::OnClientDisconnected)
		.Build();
	// clang-format on

	if (TbSimpleEmptyInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleEmptyInterfaceMsgBusEndpoint->Subscribe<FTbSimpleEmptyInterfaceDiscoveryMessage>();
	}
}

void UTbSimpleEmptyInterfaceMsgBusAdapter::_StopListening()
{
	auto msg = new FTbSimpleEmptyInterfaceServiceDisconnectMessage();

	if (TbSimpleEmptyInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleEmptyInterfaceMsgBusEndpoint->Send<FTbSimpleEmptyInterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	TbSimpleEmptyInterfaceMsgBusEndpoint.Reset();
	ConnectedClients.Reset();
}

bool UTbSimpleEmptyInterfaceMsgBusAdapter::_IsListening() const
{
	return TbSimpleEmptyInterfaceMsgBusEndpoint.IsValid();
}

void UTbSimpleEmptyInterfaceMsgBusAdapter::_setBackendService(TScriptInterface<ITbSimpleEmptyInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleEmptyInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
}

void UTbSimpleEmptyInterfaceMsgBusAdapter::OnNewClientDiscovered(const FTbSimpleEmptyInterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FMessageAddress& ClientAddress = ConnectedClients.AddDefaulted_GetRef();
	ClientAddress = Context->GetSender();

	auto msg = new FTbSimpleEmptyInterfaceInitMessage();

	if (TbSimpleEmptyInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleEmptyInterfaceMsgBusEndpoint->Send<FTbSimpleEmptyInterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleEmptyInterfaceMsgBusAdapter::OnPing(const FTbSimpleEmptyInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleEmptyInterfacePongMessage();
	msg->Timestamp = InMessage.Timestamp;

	if (TbSimpleEmptyInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleEmptyInterfaceMsgBusEndpoint->Send<FTbSimpleEmptyInterfacePongMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleEmptyInterfaceMsgBusAdapter::OnClientDisconnected(const FTbSimpleEmptyInterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	ConnectedClients.Remove(Context->GetSender());
}
