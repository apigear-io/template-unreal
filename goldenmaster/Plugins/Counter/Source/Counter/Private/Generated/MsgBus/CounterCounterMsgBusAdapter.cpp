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

#include "Generated/MsgBus/CounterCounterMsgBusAdapter.h"
#include "Generated/MsgBus/CounterCounterMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
UCounterCounterMsgBusAdapter::UCounterCounterMsgBusAdapter()
{
}

void UCounterCounterMsgBusAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UCounterCounterMsgBusAdapter::Deinitialize()
{
	_StopListening();

	Super::Deinitialize();
}

void UCounterCounterMsgBusAdapter::_StartListening()
{

	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UCounterCounterMsgBusAdapter::_CheckClientTimeouts, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (CounterCounterMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	CounterCounterMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/Counter/Counter/Service")
		.Handling<FCounterCounterDiscoveryMessage>(this, &UCounterCounterMsgBusAdapter::OnNewClientDiscovered)
		.Handling<FCounterCounterPingMessage>(this, &UCounterCounterMsgBusAdapter::OnPing)
		.Handling<FCounterCounterClientDisconnectMessage>(this, &UCounterCounterMsgBusAdapter::OnClientDisconnected)
		.Handling<FCounterCounterSetVectorRequestMessage>(this, &UCounterCounterMsgBusAdapter::OnSetVectorRequest)
		.Handling<FCounterCounterSetExternVectorRequestMessage>(this, &UCounterCounterMsgBusAdapter::OnSetExternVectorRequest)
		.Handling<FCounterCounterSetVectorArrayRequestMessage>(this, &UCounterCounterMsgBusAdapter::OnSetVectorArrayRequest)
		.Handling<FCounterCounterSetExternVectorArrayRequestMessage>(this, &UCounterCounterMsgBusAdapter::OnSetExternVectorArrayRequest)
		.Handling<FCounterCounterIncrementRequestMessage>(this, &UCounterCounterMsgBusAdapter::OnIncrementRequest)
		.Handling<FCounterCounterIncrementArrayRequestMessage>(this, &UCounterCounterMsgBusAdapter::OnIncrementArrayRequest)
		.Handling<FCounterCounterDecrementRequestMessage>(this, &UCounterCounterMsgBusAdapter::OnDecrementRequest)
		.Handling<FCounterCounterDecrementArrayRequestMessage>(this, &UCounterCounterMsgBusAdapter::OnDecrementArrayRequest)
		.Build();
	// clang-format on

	if (CounterCounterMsgBusEndpoint.IsValid())
	{
		CounterCounterMsgBusEndpoint->Subscribe<FCounterCounterDiscoveryMessage>();
	}
}

void UCounterCounterMsgBusAdapter::_StopListening()
{
	if (_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(_HeartbeatTimerHandle);
	}

	auto msg = new FCounterCounterServiceDisconnectMessage();

	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	if (CounterCounterMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		CounterCounterMsgBusEndpoint->Send<FCounterCounterServiceDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	CounterCounterMsgBusEndpoint.Reset();
	ConnectedClientsTimestamps.Empty();
	_UpdateClientsConnected();
}

bool UCounterCounterMsgBusAdapter::_IsListening() const
{
	return CounterCounterMsgBusEndpoint.IsValid();
}

void UCounterCounterMsgBusAdapter::_setBackendService(TScriptInterface<ICounterCounterInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UCounterCounterSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service CounterCounter"));
		BackendSignals->OnVectorChanged.RemoveDynamic(this, &UCounterCounterMsgBusAdapter::OnVectorChanged);
		BackendSignals->OnExternVectorChanged.RemoveDynamic(this, &UCounterCounterMsgBusAdapter::OnExternVectorChanged);
		BackendSignals->OnVectorArrayChanged.RemoveDynamic(this, &UCounterCounterMsgBusAdapter::OnVectorArrayChanged);
		BackendSignals->OnExternVectorArrayChanged.RemoveDynamic(this, &UCounterCounterMsgBusAdapter::OnExternVectorArrayChanged);
		BackendSignals->OnValueChangedSignal.RemoveDynamic(this, &UCounterCounterMsgBusAdapter::OnValueChanged);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface CounterCounter is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UCounterCounterSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service CounterCounter"));
	// connect property changed signals or simple events
	BackendSignals->OnVectorChanged.AddDynamic(this, &UCounterCounterMsgBusAdapter::OnVectorChanged);
	BackendSignals->OnExternVectorChanged.AddDynamic(this, &UCounterCounterMsgBusAdapter::OnExternVectorChanged);
	BackendSignals->OnVectorArrayChanged.AddDynamic(this, &UCounterCounterMsgBusAdapter::OnVectorArrayChanged);
	BackendSignals->OnExternVectorArrayChanged.AddDynamic(this, &UCounterCounterMsgBusAdapter::OnExternVectorArrayChanged);
	BackendSignals->OnValueChangedSignal.AddDynamic(this, &UCounterCounterMsgBusAdapter::OnValueChanged);
}

void UCounterCounterMsgBusAdapter::OnNewClientDiscovered(const FCounterCounterDiscoveryMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	const FMessageAddress& ClientAddress = Context->GetSender();

	auto msg = new FCounterCounterInitMessage();
	msg->_ClientPingIntervalMS = _HeartbeatIntervalMS;
	msg->Vector = BackendService->Execute_GetVector(BackendService.GetObject());
	msg->ExternVector = BackendService->Execute_GetExternVector(BackendService.GetObject());
	msg->VectorArray = BackendService->Execute_GetVectorArray(BackendService.GetObject());
	msg->ExternVectorArray = BackendService->Execute_GetExternVectorArray(BackendService.GetObject());

	if (CounterCounterMsgBusEndpoint.IsValid())
	{
		CounterCounterMsgBusEndpoint->Send<FCounterCounterInitMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ClientAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	_OnClientConnected.Broadcast(ClientAddress.ToString());
	ConnectedClientsTimestamps.Add(ClientAddress, FPlatformTime::Seconds());
	_UpdateClientsConnected();
}

void UCounterCounterMsgBusAdapter::OnPing(const FCounterCounterPingMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FCounterCounterPongMessage();
	msg->Timestamp = InMessage.Timestamp;

	ConnectedClientsTimestamps.Add(Context->GetSender(), FPlatformTime::Seconds());

	if (CounterCounterMsgBusEndpoint.IsValid())
	{
		CounterCounterMsgBusEndpoint->Send<FCounterCounterPongMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UCounterCounterMsgBusAdapter::OnClientDisconnected(const FCounterCounterClientDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	_OnClientDisconnected.Broadcast(Context->GetSender().ToString());
	ConnectedClientsTimestamps.Remove(Context->GetSender());
	_UpdateClientsConnected();
}

void UCounterCounterMsgBusAdapter::_CheckClientTimeouts()
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

void UCounterCounterMsgBusAdapter::_UpdateClientsConnected()
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);
	_ClientsConnected = NumberOfClients;
	_OnClientsConnectedCountChanged.Broadcast(_ClientsConnected);
}

void UCounterCounterMsgBusAdapter::OnIncrementRequest(const FCounterCounterIncrementRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FCounterCounterIncrementReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_Increment(BackendService.GetObject(), InMessage.Vec);

	if (CounterCounterMsgBusEndpoint.IsValid())
	{
		CounterCounterMsgBusEndpoint->Send<FCounterCounterIncrementReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UCounterCounterMsgBusAdapter::OnIncrementArrayRequest(const FCounterCounterIncrementArrayRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FCounterCounterIncrementArrayReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_IncrementArray(BackendService.GetObject(), InMessage.Vec);

	if (CounterCounterMsgBusEndpoint.IsValid())
	{
		CounterCounterMsgBusEndpoint->Send<FCounterCounterIncrementArrayReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UCounterCounterMsgBusAdapter::OnDecrementRequest(const FCounterCounterDecrementRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FCounterCounterDecrementReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_Decrement(BackendService.GetObject(), InMessage.Vec);

	if (CounterCounterMsgBusEndpoint.IsValid())
	{
		CounterCounterMsgBusEndpoint->Send<FCounterCounterDecrementReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UCounterCounterMsgBusAdapter::OnDecrementArrayRequest(const FCounterCounterDecrementArrayRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FCounterCounterDecrementArrayReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->Execute_DecrementArray(BackendService.GetObject(), InMessage.Vec);

	if (CounterCounterMsgBusEndpoint.IsValid())
	{
		CounterCounterMsgBusEndpoint->Send<FCounterCounterDecrementArrayReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UCounterCounterMsgBusAdapter::OnValueChanged(const FCustomTypesVector3D& InVector, const FVector& InExternVector, const TArray<FCustomTypesVector3D>& InVectorArray, const TArray<FVector>& InExternVectorArray)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FCounterCounterValueChangedSignalMessage();
	msg->Vector = InVector;
	msg->ExternVector = InExternVector;
	msg->VectorArray = InVectorArray;
	msg->ExternVectorArray = InExternVectorArray;
	if (CounterCounterMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		CounterCounterMsgBusEndpoint->Send<FCounterCounterValueChangedSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UCounterCounterMsgBusAdapter::OnSetVectorRequest(const FCounterCounterSetVectorRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetVector(BackendService.GetObject(), InMessage.Vector);
}

void UCounterCounterMsgBusAdapter::OnVectorChanged(const FCustomTypesVector3D& InVector)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FCounterCounterVectorChangedMessage();
	msg->Vector = InVector;

	if (CounterCounterMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		CounterCounterMsgBusEndpoint->Send<FCounterCounterVectorChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UCounterCounterMsgBusAdapter::OnSetExternVectorRequest(const FCounterCounterSetExternVectorRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetExternVector(BackendService.GetObject(), InMessage.ExternVector);
}

void UCounterCounterMsgBusAdapter::OnExternVectorChanged(const FVector& InExternVector)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FCounterCounterExternVectorChangedMessage();
	msg->ExternVector = InExternVector;

	if (CounterCounterMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		CounterCounterMsgBusEndpoint->Send<FCounterCounterExternVectorChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UCounterCounterMsgBusAdapter::OnSetVectorArrayRequest(const FCounterCounterSetVectorArrayRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetVectorArray(BackendService.GetObject(), InMessage.VectorArray);
}

void UCounterCounterMsgBusAdapter::OnVectorArrayChanged(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FCounterCounterVectorArrayChangedMessage();
	msg->VectorArray = InVectorArray;

	if (CounterCounterMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		CounterCounterMsgBusEndpoint->Send<FCounterCounterVectorArrayChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UCounterCounterMsgBusAdapter::OnSetExternVectorArrayRequest(const FCounterCounterSetExternVectorArrayRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->Execute_SetExternVectorArray(BackendService.GetObject(), InMessage.ExternVectorArray);
}

void UCounterCounterMsgBusAdapter::OnExternVectorArrayChanged(const TArray<FVector>& InExternVectorArray)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FCounterCounterExternVectorArrayChangedMessage();
	msg->ExternVectorArray = InExternVectorArray;

	if (CounterCounterMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		CounterCounterMsgBusEndpoint->Send<FCounterCounterExternVectorArrayChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}
