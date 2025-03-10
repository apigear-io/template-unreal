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

#include "TbSimple/Generated/MsgBus/TbSimpleNoPropertiesInterfaceMsgBusAdapter.h"
#include "TbSimple/Generated/MsgBus/TbSimpleNoPropertiesInterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTbSimpleNoPropertiesInterfaceMsgBusAdapter::UTbSimpleNoPropertiesInterfaceMsgBusAdapter()
{
}

void UTbSimpleNoPropertiesInterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleNoPropertiesInterfaceMsgBusAdapter::Deinitialize()
{
	_StopListening();

	Super::Deinitialize();
}

void UTbSimpleNoPropertiesInterfaceMsgBusAdapter::_StartListening()
{

	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTbSimpleNoPropertiesInterfaceMsgBusAdapter::_CheckClientTimeouts, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (TbSimpleNoPropertiesInterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	TbSimpleNoPropertiesInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSimple/NoPropertiesInterface/Service")
		.Handling<FTbSimpleNoPropertiesInterfaceDiscoveryMessage>(this, &UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTbSimpleNoPropertiesInterfacePingMessage>(this, &UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnPing)
		.Handling<FTbSimpleNoPropertiesInterfaceClientDisconnectMessage>(this, &UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTbSimpleNoPropertiesInterfaceFuncVoidRequestMessage>(this, &UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnFuncVoidRequest)
		.Handling<FTbSimpleNoPropertiesInterfaceFuncBoolRequestMessage>(this, &UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnFuncBoolRequest)
		.Build();
	// clang-format on

	if (TbSimpleNoPropertiesInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoPropertiesInterfaceMsgBusEndpoint->Subscribe<FTbSimpleNoPropertiesInterfaceDiscoveryMessage>();
	}
}

void UTbSimpleNoPropertiesInterfaceMsgBusAdapter::_StopListening()
{
	if (_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(_HeartbeatTimerHandle);
	}

	auto msg = new FTbSimpleNoPropertiesInterfaceServiceDisconnectMessage();

	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	if (TbSimpleNoPropertiesInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		TbSimpleNoPropertiesInterfaceMsgBusEndpoint->Send<FTbSimpleNoPropertiesInterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	TbSimpleNoPropertiesInterfaceMsgBusEndpoint.Reset();
	ConnectedClientsTimestamps.Empty();
	_UpdateClientsConnected();
}

bool UTbSimpleNoPropertiesInterfaceMsgBusAdapter::_IsListening() const
{
	return TbSimpleNoPropertiesInterfaceMsgBusEndpoint.IsValid();
}

void UTbSimpleNoPropertiesInterfaceMsgBusAdapter::_setBackendService(TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleNoPropertiesInterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleNoPropertiesInterface"));
		BackendSignals->OnSigVoidSignalBP.RemoveDynamic(this, &UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnSigVoid);
		BackendSignals->OnSigBoolSignalBP.RemoveDynamic(this, &UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnSigBool);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleNoPropertiesInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleNoPropertiesInterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSimpleNoPropertiesInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnSigVoidSignalBP.AddDynamic(this, &UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnSigVoid);
	BackendSignals->OnSigBoolSignalBP.AddDynamic(this, &UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnSigBool);
}

void UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnNewClientDiscovered(const FTbSimpleNoPropertiesInterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	const FMessageAddress& ClientAddress = Context->GetSender();

	auto msg = new FTbSimpleNoPropertiesInterfaceInitMessage();
	msg->_ClientPingIntervalMS = _HeartbeatIntervalMS;

	if (TbSimpleNoPropertiesInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoPropertiesInterfaceMsgBusEndpoint->Send<FTbSimpleNoPropertiesInterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	_OnClientConnected.Broadcast(ClientAddress.ToString());
	ConnectedClientsTimestamps.Add(ClientAddress, FPlatformTime::Seconds());
	_UpdateClientsConnected();
}

void UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnPing(const FTbSimpleNoPropertiesInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleNoPropertiesInterfacePongMessage();
	msg->Timestamp = InMessage.Timestamp;

	ConnectedClientsTimestamps.Add(Context->GetSender(), FPlatformTime::Seconds());

	if (TbSimpleNoPropertiesInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoPropertiesInterfaceMsgBusEndpoint->Send<FTbSimpleNoPropertiesInterfacePongMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnClientDisconnected(const FTbSimpleNoPropertiesInterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (!ConnectedClientsTimestamps.Contains(Context->GetSender()))
	{
		return;
	}

	ConnectedClientsTimestamps.Remove(Context->GetSender());
	_OnClientDisconnected.Broadcast(Context->GetSender().ToString());
	_UpdateClientsConnected();
}

void UTbSimpleNoPropertiesInterfaceMsgBusAdapter::_CheckClientTimeouts()
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

void UTbSimpleNoPropertiesInterfaceMsgBusAdapter::_UpdateClientsConnected()
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);
	_ClientsConnected = NumberOfClients;
	_OnClientsConnectedCountChanged.Broadcast(_ClientsConnected);
}

void UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnFuncVoidRequest(const FTbSimpleNoPropertiesInterfaceFuncVoidRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	BackendService->FuncVoid();
}

void UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnFuncBoolRequest(const FTbSimpleNoPropertiesInterfaceFuncBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTbSimpleNoPropertiesInterfaceFuncBoolReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->FuncBool(InMessage.bParamBool);

	if (TbSimpleNoPropertiesInterfaceMsgBusEndpoint.IsValid())
	{
		TbSimpleNoPropertiesInterfaceMsgBusEndpoint->Send<FTbSimpleNoPropertiesInterfaceFuncBoolReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnSigVoid()
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTbSimpleNoPropertiesInterfaceSigVoidSignalMessage();
	if (TbSimpleNoPropertiesInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		TbSimpleNoPropertiesInterfaceMsgBusEndpoint->Send<FTbSimpleNoPropertiesInterfaceSigVoidSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTbSimpleNoPropertiesInterfaceMsgBusAdapter::OnSigBool(bool bInParamBool)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTbSimpleNoPropertiesInterfaceSigBoolSignalMessage();
	msg->bParamBool = bInParamBool;
	if (TbSimpleNoPropertiesInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		TbSimpleNoPropertiesInterfaceMsgBusEndpoint->Send<FTbSimpleNoPropertiesInterfaceSigBoolSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}
