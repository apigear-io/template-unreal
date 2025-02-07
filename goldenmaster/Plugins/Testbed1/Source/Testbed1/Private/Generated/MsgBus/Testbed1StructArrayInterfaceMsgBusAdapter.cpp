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

#include "Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusAdapter.h"
#include "Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UTestbed1StructArrayInterfaceMsgBusAdapter::UTestbed1StructArrayInterfaceMsgBusAdapter()
{
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::Deinitialize()
{
	_StopListening();

	Super::Deinitialize();
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::_StartListening()
{

	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTestbed1StructArrayInterfaceMsgBusAdapter::_CheckClientTimeouts, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	Testbed1StructArrayInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/Testbed1/StructArrayInterface/Service")
		.Handling<FTestbed1StructArrayInterfaceDiscoveryMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FTestbed1StructArrayInterfacePingMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPing)
		.Handling<FTestbed1StructArrayInterfaceClientDisconnectMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTestbed1StructArrayInterfaceSetPropBoolRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropBoolRequest)
		.Handling<FTestbed1StructArrayInterfaceSetPropIntRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropIntRequest)
		.Handling<FTestbed1StructArrayInterfaceSetPropFloatRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropFloatRequest)
		.Handling<FTestbed1StructArrayInterfaceSetPropStringRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropStringRequest)
		.Handling<FTestbed1StructArrayInterfaceFuncBoolRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnFuncBoolRequest)
		.Handling<FTestbed1StructArrayInterfaceFuncIntRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnFuncIntRequest)
		.Handling<FTestbed1StructArrayInterfaceFuncFloatRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnFuncFloatRequest)
		.Handling<FTestbed1StructArrayInterfaceFuncStringRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnFuncStringRequest)
		.Build();
	// clang-format on

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Subscribe<FTestbed1StructArrayInterfaceDiscoveryMessage>();
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::_StopListening()
{
	if (_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(_HeartbeatTimerHandle);
	}

	auto msg = new FTestbed1StructArrayInterfaceServiceDisconnectMessage();

	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	Testbed1StructArrayInterfaceMsgBusEndpoint.Reset();
	ConnectedClientsTimestamps.Empty();
	_UpdateClientsConnected();
}

bool UTestbed1StructArrayInterfaceMsgBusAdapter::_IsListening() const
{
	return Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid();
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::_setBackendService(TScriptInterface<ITestbed1StructArrayInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed1StructArrayInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructArrayInterface"));
		BackendSignals->OnPropBoolChanged.RemoveDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropBoolChanged);
		BackendSignals->OnPropIntChanged.RemoveDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropIntChanged);
		BackendSignals->OnPropFloatChanged.RemoveDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropFloatChanged);
		BackendSignals->OnPropStringChanged.RemoveDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropStringChanged);
		BackendSignals->OnSigBoolSignal.RemoveDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigBool);
		BackendSignals->OnSigIntSignal.RemoveDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigInt);
		BackendSignals->OnSigFloatSignal.RemoveDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigFloat);
		BackendSignals->OnSigStringSignal.RemoveDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed1StructArrayInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed1StructArrayInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service Testbed1StructArrayInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnPropBoolChanged.AddDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropBoolChanged);
	BackendSignals->OnPropIntChanged.AddDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropIntChanged);
	BackendSignals->OnPropFloatChanged.AddDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropFloatChanged);
	BackendSignals->OnPropStringChanged.AddDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropStringChanged);
	BackendSignals->OnSigBoolSignal.AddDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigBool);
	BackendSignals->OnSigIntSignal.AddDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigInt);
	BackendSignals->OnSigFloatSignal.AddDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigFloat);
	BackendSignals->OnSigStringSignal.AddDynamic(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigString);
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnNewClientDiscovered(const FTestbed1StructArrayInterfaceDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	const FMessageAddress& ClientAddress = Context->GetSender();

	auto msg = new FTestbed1StructArrayInterfaceInitMessage();
	msg->_ClientPingIntervalMS = _HeartbeatIntervalMS;
	msg->PropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	msg->PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
	msg->PropFloat = BackendService->Execute_GetPropFloat(BackendService.GetObject());
	msg->PropString = BackendService->Execute_GetPropString(BackendService.GetObject());

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	_OnClientConnected.Broadcast(ClientAddress.ToString());
	ConnectedClientsTimestamps.Add(ClientAddress, FPlatformTime::Seconds());
	_UpdateClientsConnected();
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnPing(const FTestbed1StructArrayInterfacePingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed1StructArrayInterfacePongMessage();
	msg->Timestamp = InMessage.Timestamp;

	ConnectedClientsTimestamps.Add(Context->GetSender(), FPlatformTime::Seconds());

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfacePongMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnClientDisconnected(const FTestbed1StructArrayInterfaceClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	_OnClientDisconnected.Broadcast(Context->GetSender().ToString());
	ConnectedClientsTimestamps.Remove(Context->GetSender());
	_UpdateClientsConnected();
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::_CheckClientTimeouts()
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

void UTestbed1StructArrayInterfaceMsgBusAdapter::_UpdateClientsConnected()
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);
	_ClientsConnected = NumberOfClients;
	_OnClientsConnectedCountChanged.Broadcast(_ClientsConnected);
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnFuncBoolRequest(const FTestbed1StructArrayInterfaceFuncBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed1StructArrayInterfaceFuncBoolReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncBool(BackendService.GetObject(), InMessage.ParamBool);

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceFuncBoolReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnFuncIntRequest(const FTestbed1StructArrayInterfaceFuncIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed1StructArrayInterfaceFuncIntReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncInt(BackendService.GetObject(), InMessage.ParamInt);

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceFuncIntReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnFuncFloatRequest(const FTestbed1StructArrayInterfaceFuncFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed1StructArrayInterfaceFuncFloatReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncFloat(BackendService.GetObject(), InMessage.ParamFloat);

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceFuncFloatReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnFuncStringRequest(const FTestbed1StructArrayInterfaceFuncStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed1StructArrayInterfaceFuncStringReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_FuncString(BackendService.GetObject(), InMessage.ParamString);

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceFuncStringReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigBool(const TArray<FTestbed1StructBool>& InParamBool)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTestbed1StructArrayInterfaceSigBoolSignalMessage();
	msg->ParamBool = InParamBool;
	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceSigBoolSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigInt(const TArray<FTestbed1StructInt>& InParamInt)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTestbed1StructArrayInterfaceSigIntSignalMessage();
	msg->ParamInt = InParamInt;
	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceSigIntSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigFloat(const TArray<FTestbed1StructFloat>& InParamFloat)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTestbed1StructArrayInterfaceSigFloatSignalMessage();
	msg->ParamFloat = InParamFloat;
	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceSigFloatSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigString(const TArray<FTestbed1StructString>& InParamString)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTestbed1StructArrayInterfaceSigStringSignalMessage();
	msg->ParamString = InParamString;
	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceSigStringSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropBoolRequest(const FTestbed1StructArrayInterfaceSetPropBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropBool(BackendService.GetObject(), InMessage.PropBool);
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropBoolChanged(const TArray<FTestbed1StructBool>& InPropBool)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTestbed1StructArrayInterfacePropBoolChangedMessage();
	msg->PropBool = InPropBool;

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfacePropBoolChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropIntRequest(const FTestbed1StructArrayInterfaceSetPropIntRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InMessage.PropInt);
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropIntChanged(const TArray<FTestbed1StructInt>& InPropInt)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTestbed1StructArrayInterfacePropIntChangedMessage();
	msg->PropInt = InPropInt;

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfacePropIntChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropFloatRequest(const FTestbed1StructArrayInterfaceSetPropFloatRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropFloat(BackendService.GetObject(), InMessage.PropFloat);
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropFloatChanged(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTestbed1StructArrayInterfacePropFloatChangedMessage();
	msg->PropFloat = InPropFloat;

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfacePropFloatChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropStringRequest(const FTestbed1StructArrayInterfaceSetPropStringRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetPropString(BackendService.GetObject(), InMessage.PropString);
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropStringChanged(const TArray<FTestbed1StructString>& InPropString)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTestbed1StructArrayInterfacePropStringChangedMessage();
	msg->PropString = InPropString;

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfacePropStringChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}
