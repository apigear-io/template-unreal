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

#include "Generated/MsgBus/Testbed2NestedStruct1InterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed2NestedStruct1InterfaceMsgBusMessages.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "Misc/DateTime.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "GenericPlatform/GenericPlatformTime.h"
#include "MessageEndpointBuilder.h"
#include "MessageEndpoint.h"
#include "HAL/CriticalSection.h"

/**
   \brief data structure to hold the last sent property values
*/
struct Testbed2NestedStruct1InterfacePropertiesMsgBusData
{
	FCriticalSection Prop1Mutex;
	FTestbed2NestedStruct1 Prop1{FTestbed2NestedStruct1()};
};
DEFINE_LOG_CATEGORY(LogTestbed2NestedStruct1InterfaceMsgBusClient);

UTestbed2NestedStruct1InterfaceMsgBusClient::UTestbed2NestedStruct1InterfaceMsgBusClient()
	: UAbstractTestbed2NestedStruct1Interface()
	, _SentData(MakePimpl<Testbed2NestedStruct1InterfacePropertiesMsgBusData>())
{
	PingRTTBuffer.SetNumZeroed(PING_RTT_BUFFER_SIZE);
}

UTestbed2NestedStruct1InterfaceMsgBusClient::~UTestbed2NestedStruct1InterfaceMsgBusClient() = default;

void UTestbed2NestedStruct1InterfaceMsgBusClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed2NestedStruct1InterfaceMsgBusClient::Deinitialize()
{
	_Disconnect();

	Super::Deinitialize();
}

void UTestbed2NestedStruct1InterfaceMsgBusClient::_Connect()
{
	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTestbed2NestedStruct1InterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (_IsConnected())
	{
		UE_LOG(LogTestbed2NestedStruct1InterfaceMsgBusClient, Log, TEXT("Already connected, cannot connect again."));
		return;
	}

	if (Testbed2NestedStruct1InterfaceMsgBusEndpoint.IsValid() && !ServiceAddress.IsValid())
	{
		_DiscoverService();
		return;
	}

	// clang-format off
	Testbed2NestedStruct1InterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/Testbed2/NestedStruct1Interface/Client")
		.Handling<FTestbed2NestedStruct1InterfaceInitMessage>(this, &UTestbed2NestedStruct1InterfaceMsgBusClient::OnConnectionInit)
		.Handling<FTestbed2NestedStruct1InterfacePongMessage>(this, &UTestbed2NestedStruct1InterfaceMsgBusClient::OnPong)
		.Handling<FTestbed2NestedStruct1InterfaceServiceDisconnectMessage>(this, &UTestbed2NestedStruct1InterfaceMsgBusClient::OnServiceClosedConnection)
		.Handling<FTestbed2NestedStruct1InterfaceSig1SignalMessage>(this, &UTestbed2NestedStruct1InterfaceMsgBusClient::OnSig1)
		.Handling<FTestbed2NestedStruct1InterfaceProp1ChangedMessage>(this, &UTestbed2NestedStruct1InterfaceMsgBusClient::OnProp1Changed)
		.Handling<FTestbed2NestedStruct1InterfaceFunc1ReplyMessage>(this, &UTestbed2NestedStruct1InterfaceMsgBusClient::OnFunc1Reply)
		.Build();
	// clang-format on

	_DiscoverService();
}

void UTestbed2NestedStruct1InterfaceMsgBusClient::_Disconnect()
{
	_LastHbTimestamp = 0.0f;
	if (_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(_HeartbeatTimerHandle);
	}

	if (!_IsConnected())
	{
		return;
	}

	auto msg = new FTestbed2NestedStruct1InterfaceClientDisconnectMessage();

	Testbed2NestedStruct1InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct1InterfaceClientDisconnectMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	Testbed2NestedStruct1InterfaceMsgBusEndpoint.Reset();
	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

void UTestbed2NestedStruct1InterfaceMsgBusClient::_DiscoverService()
{
	if (!Testbed2NestedStruct1InterfaceMsgBusEndpoint.IsValid())
	{
		return;
	}

	auto msg = new FTestbed2NestedStruct1InterfaceDiscoveryMessage();
	Testbed2NestedStruct1InterfaceMsgBusEndpoint->Publish<FTestbed2NestedStruct1InterfaceDiscoveryMessage>(msg);
}

bool UTestbed2NestedStruct1InterfaceMsgBusClient::_IsConnected() const
{
	return Testbed2NestedStruct1InterfaceMsgBusEndpoint.IsValid() && ServiceAddress.IsValid();
}

void UTestbed2NestedStruct1InterfaceMsgBusClient::OnConnectionInit(const FTestbed2NestedStruct1InterfaceInitMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress.IsValid())
	{
		UE_LOG(LogTestbed2NestedStruct1InterfaceMsgBusClient, Warning, TEXT("Got a second init message - should not happen"));
		return;
	}

	ServiceAddress = Context->GetSender();
	// reset ping stats for a new connection
	PingRTTBuffer.Empty();
	PingRTTBuffer.SetNumZeroed(PING_RTT_BUFFER_SIZE);
	CurrentPingCounter = 0;
	Stats.CurrentRTT_MS = 0.0f;
	Stats.AverageRTT_MS = 0.0f;
	Stats.MaxRTT_MS = 0.0f;
	Stats.MinRTT_MS = 0.0f;

	const bool b_ClientPingIntervalMSChanged = InMessage._ClientPingIntervalMS != _HeartbeatIntervalMS;
	if (b_ClientPingIntervalMSChanged)
	{
		_HeartbeatIntervalMS = InMessage._ClientPingIntervalMS;

		if (_HeartbeatTimerHandle.IsValid() && GetWorld())
		{
			GetWorld()->GetTimerManager().ClearTimer(_HeartbeatTimerHandle);
		}

		if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
		{
			GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTestbed2NestedStruct1InterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
		}
	}
	const bool bProp1Changed = InMessage.Prop1 != Prop1;
	if (bProp1Changed)
	{
		Prop1 = InMessage.Prop1;
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}

	_ConnectionStatusChanged.Broadcast(true);
}

void UTestbed2NestedStruct1InterfaceMsgBusClient::_OnHeartbeat()
{
	if (_LastHbTimestamp > 0.1f)
	{
		double Delta = (FPlatformTime::Seconds() - _LastHbTimestamp) * 1000;

		if (Delta > 2 * _HeartbeatIntervalMS)
		{
			// service seems to be dead or not responding - reset connection
			ServiceAddress.Invalidate();
			_LastHbTimestamp = 0.0f;
		}
	}

	if (!_IsConnected())
	{
		UE_LOG(LogTestbed2NestedStruct1InterfaceMsgBusClient, Warning, TEXT("Heartbeat failed. Client has no connection to service. Reconnecting ..."));

		_Connect();
		return;
	}

	auto msg = new FTestbed2NestedStruct1InterfacePingMessage();
	msg->Timestamp = FPlatformTime::Seconds();

	Testbed2NestedStruct1InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct1InterfacePingMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
}

float UTestbed2NestedStruct1InterfaceMsgBusClient::_CalculateAverageRTT() const
{
	if (CurrentPingCounter == 0)
	{
		return 0.0f;
	}

	float TotalRTT = 0.0f;

	for (const float& RTT : PingRTTBuffer)
	{
		TotalRTT += RTT;
	}

	return CurrentPingCounter > 0 ? TotalRTT / CurrentPingCounter : 0.0f;
}

void UTestbed2NestedStruct1InterfaceMsgBusClient::OnPong(const FTestbed2NestedStruct1InterfacePongMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	_LastHbTimestamp = InMessage.Timestamp;

	const double Current = FPlatformTime::Seconds();
	const double DeltaMS = (Current - InMessage.Timestamp) * 1000.0f;

	Stats.CurrentRTT_MS = DeltaMS;
	if (CurrentPingCounter < PING_RTT_BUFFER_SIZE)
	{
		CurrentPingCounter++;
	}
	PingRTTBuffer.RemoveAt(0);
	PingRTTBuffer.Add(Stats.CurrentRTT_MS);
	Stats.AverageRTT_MS = _CalculateAverageRTT();
	Stats.MaxRTT_MS = FGenericPlatformMath::Max(Stats.MaxRTT_MS, Stats.CurrentRTT_MS);
	Stats.MinRTT_MS = FGenericPlatformMath::Min(Stats.MinRTT_MS, Stats.CurrentRTT_MS);

	_StatsUpdated.Broadcast(Stats);
}

const FTestbed2NestedStruct1InterfaceStats& UTestbed2NestedStruct1InterfaceMsgBusClient::_GetStats() const
{
	return Stats;
}

void UTestbed2NestedStruct1InterfaceMsgBusClient::OnServiceClosedConnection(const FTestbed2NestedStruct1InterfaceServiceDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		return;
	}

	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceMsgBusClient::GetProp1_Implementation() const
{
	return Prop1;
}

void UTestbed2NestedStruct1InterfaceMsgBusClient::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed2NestedStruct1InterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp1_Implementation() == InProp1)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->Prop1Mutex));
		if (_SentData->Prop1 == InProp1)
		{
			return;
		}
	}

	auto msg = new FTestbed2NestedStruct1InterfaceSetProp1RequestMessage();
	msg->Prop1 = InProp1;

	Testbed2NestedStruct1InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct1InterfaceSetProp1RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	FScopeLock Lock(&(_SentData->Prop1Mutex));
	_SentData->Prop1 = InProp1;
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceMsgBusClient::Func1_Implementation(const FTestbed2NestedStruct1& InParam1)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed2NestedStruct1InterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return FTestbed2NestedStruct1();
	}

	auto msg = new FTestbed2NestedStruct1InterfaceFunc1RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->Param1 = InParam1;
	TPromise<FTestbed2NestedStruct1> Promise;
	StorePromise(msg->ResponseId, Promise);

	Testbed2NestedStruct1InterfaceMsgBusEndpoint->Send<FTestbed2NestedStruct1InterfaceFunc1RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTestbed2NestedStruct1InterfaceMsgBusClient::OnFunc1Reply(const FTestbed2NestedStruct1InterfaceFunc1ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

void UTestbed2NestedStruct1InterfaceMsgBusClient::OnSig1(const FTestbed2NestedStruct1InterfaceSig1SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed2NestedStruct1InterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSig1Signal.Broadcast(InMessage.Param1);
	return;
}

void UTestbed2NestedStruct1InterfaceMsgBusClient::OnProp1Changed(const FTestbed2NestedStruct1InterfaceProp1ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed2NestedStruct1InterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bProp1Changed = InMessage.Prop1 != Prop1;
	if (bProp1Changed)
	{
		Prop1 = InMessage.Prop1;
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}
}

template <typename ResultType>
bool UTestbed2NestedStruct1InterfaceMsgBusClient::StorePromise(const FGuid& Id, TPromise<ResultType>& Promise)
{
	FScopeLock Lock(&ReplyPromisesMapCS);
	return ReplyPromisesMap.Add(Id, &Promise) != nullptr;
}

template <typename ResultType>
bool UTestbed2NestedStruct1InterfaceMsgBusClient::FulfillPromise(const FGuid& Id, const ResultType& Value)
{
	TPromise<ResultType>* PromisePtr = nullptr;

	{
		FScopeLock Lock(&ReplyPromisesMapCS);
		if (auto** Found = ReplyPromisesMap.Find(Id))
		{
			PromisePtr = static_cast<TPromise<ResultType>*>(*Found);
			ReplyPromisesMap.Remove(Id);
		}
	}

	if (PromisePtr)
	{
		PromisePtr->SetValue(Value);
		return true;
	}
	return false;
}

template bool UTestbed2NestedStruct1InterfaceMsgBusClient::StorePromise<FTestbed2NestedStruct1>(const FGuid& Id, TPromise<FTestbed2NestedStruct1>& Promise);
template bool UTestbed2NestedStruct1InterfaceMsgBusClient::FulfillPromise<FTestbed2NestedStruct1>(const FGuid& Id, const FTestbed2NestedStruct1& Value);
