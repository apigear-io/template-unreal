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

#include "Generated/MsgBus/Testbed2ManyParamInterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed2ManyParamInterfaceMsgBusMessages.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "Misc/DateTime.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "GenericPlatform/GenericPlatformTime.h"
#include "MessageEndpointBuilder.h"
#include "MessageEndpoint.h"
#include <atomic>

/**
   \brief data structure to hold the last sent property values
*/
struct Testbed2ManyParamInterfacePropertiesMsgBusData
{
	std::atomic<int32> Prop1{0};
	std::atomic<int32> Prop2{0};
	std::atomic<int32> Prop3{0};
	std::atomic<int32> Prop4{0};
};
DEFINE_LOG_CATEGORY(LogTestbed2ManyParamInterfaceMsgBusClient);

UTestbed2ManyParamInterfaceMsgBusClient::UTestbed2ManyParamInterfaceMsgBusClient()
	: UAbstractTestbed2ManyParamInterface()
	, _SentData(MakePimpl<Testbed2ManyParamInterfacePropertiesMsgBusData>())
{
}

UTestbed2ManyParamInterfaceMsgBusClient::~UTestbed2ManyParamInterfaceMsgBusClient() = default;

void UTestbed2ManyParamInterfaceMsgBusClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed2ManyParamInterfaceMsgBusClient::Deinitialize()
{
	_Disconnect();

	Super::Deinitialize();
}

void UTestbed2ManyParamInterfaceMsgBusClient::_Connect()
{
	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTestbed2ManyParamInterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (_IsConnected())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Log, TEXT("Already connected, cannot connect again."));
		return;
	}

	if (Testbed2ManyParamInterfaceMsgBusEndpoint.IsValid() && !ServiceAddress.IsValid())
	{
		_DiscoverService();
		return;
	}

	// clang-format off
	Testbed2ManyParamInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/Testbed2/ManyParamInterface/Client")
		.Handling<FTestbed2ManyParamInterfaceInitMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnConnectionInit)
		.Handling<FTestbed2ManyParamInterfacePongMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnPong)
		.Handling<FTestbed2ManyParamInterfaceServiceDisconnectMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnServiceClosedConnection)
		.Handling<FTestbed2ManyParamInterfaceSig1SignalMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnSig1)
		.Handling<FTestbed2ManyParamInterfaceSig2SignalMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnSig2)
		.Handling<FTestbed2ManyParamInterfaceSig3SignalMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnSig3)
		.Handling<FTestbed2ManyParamInterfaceSig4SignalMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnSig4)
		.Handling<FTestbed2ManyParamInterfaceProp1ChangedMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnProp1Changed)
		.Handling<FTestbed2ManyParamInterfaceProp2ChangedMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnProp2Changed)
		.Handling<FTestbed2ManyParamInterfaceProp3ChangedMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnProp3Changed)
		.Handling<FTestbed2ManyParamInterfaceProp4ChangedMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnProp4Changed)
		.Handling<FTestbed2ManyParamInterfaceFunc1ReplyMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnFunc1Reply)
		.Handling<FTestbed2ManyParamInterfaceFunc2ReplyMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnFunc2Reply)
		.Handling<FTestbed2ManyParamInterfaceFunc3ReplyMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnFunc3Reply)
		.Handling<FTestbed2ManyParamInterfaceFunc4ReplyMessage>(this, &UTestbed2ManyParamInterfaceMsgBusClient::OnFunc4Reply)
		.Build();
	// clang-format on

	_DiscoverService();
}

void UTestbed2ManyParamInterfaceMsgBusClient::_Disconnect()
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

	auto msg = new FTestbed2ManyParamInterfaceClientDisconnectMessage();

	Testbed2ManyParamInterfaceMsgBusEndpoint->Send<FTestbed2ManyParamInterfaceClientDisconnectMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	Testbed2ManyParamInterfaceMsgBusEndpoint.Reset();
	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

void UTestbed2ManyParamInterfaceMsgBusClient::_DiscoverService()
{
	if (!Testbed2ManyParamInterfaceMsgBusEndpoint.IsValid())
	{
		return;
	}

	auto msg = new FTestbed2ManyParamInterfaceDiscoveryMessage();
	Testbed2ManyParamInterfaceMsgBusEndpoint->Publish<FTestbed2ManyParamInterfaceDiscoveryMessage>(msg);
}

bool UTestbed2ManyParamInterfaceMsgBusClient::_IsConnected() const
{
	return Testbed2ManyParamInterfaceMsgBusEndpoint.IsValid() && ServiceAddress.IsValid();
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnConnectionInit(const FTestbed2ManyParamInterfaceInitMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress.IsValid())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Warning, TEXT("Got a second init message - should not happen"));
		return;
	}

	ServiceAddress = Context->GetSender();

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
			GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTestbed2ManyParamInterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
		}
	}
	const bool bProp1Changed = InMessage.Prop1 != Prop1;
	if (bProp1Changed)
	{
		Prop1 = InMessage.Prop1;
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}

	const bool bProp2Changed = InMessage.Prop2 != Prop2;
	if (bProp2Changed)
	{
		Prop2 = InMessage.Prop2;
		Execute__GetSignals(this)->OnProp2Changed.Broadcast(Prop2);
	}

	const bool bProp3Changed = InMessage.Prop3 != Prop3;
	if (bProp3Changed)
	{
		Prop3 = InMessage.Prop3;
		Execute__GetSignals(this)->OnProp3Changed.Broadcast(Prop3);
	}

	const bool bProp4Changed = InMessage.Prop4 != Prop4;
	if (bProp4Changed)
	{
		Prop4 = InMessage.Prop4;
		Execute__GetSignals(this)->OnProp4Changed.Broadcast(Prop4);
	}

	_ConnectionStatusChanged.Broadcast(true);
}

void UTestbed2ManyParamInterfaceMsgBusClient::_OnHeartbeat()
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
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Warning, TEXT("Heartbeat failed. Client has no connection to service. Reconnecting ..."));

		_Connect();
		return;
	}

	auto msg = new FTestbed2ManyParamInterfacePingMessage();
	msg->Timestamp = FPlatformTime::Seconds();

	Testbed2ManyParamInterfaceMsgBusEndpoint->Send<FTestbed2ManyParamInterfacePingMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnPong(const FTestbed2ManyParamInterfacePongMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	_LastHbTimestamp = InMessage.Timestamp;

	const double Current = FPlatformTime::Seconds();
	const double DeltaMS = (Current - InMessage.Timestamp) * 1000.0f;

	Stats.CurrentRTT_MS = DeltaMS;
	Stats.AverageRTT_MS = (Stats.AverageRTT_MS + Stats.CurrentRTT_MS) / 2.0f;
	Stats.MaxRTT_MS = FGenericPlatformMath::Max(Stats.MaxRTT_MS, Stats.CurrentRTT_MS);
	Stats.MinRTT_MS = FGenericPlatformMath::Min(Stats.MinRTT_MS, Stats.CurrentRTT_MS);

	_StatsUpdated.Broadcast(Stats);
}

const FTestbed2ManyParamInterfaceStats& UTestbed2ManyParamInterfaceMsgBusClient::_GetStats() const
{
	return Stats;
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnServiceClosedConnection(const FTestbed2ManyParamInterfaceServiceDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		return;
	}

	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

int32 UTestbed2ManyParamInterfaceMsgBusClient::GetProp1_Implementation() const
{
	return Prop1;
}

void UTestbed2ManyParamInterfaceMsgBusClient::SetProp1_Implementation(int32 InProp1)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp1_Implementation() == InProp1)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop1 == InProp1)
	{
		return;
	}

	auto msg = new FTestbed2ManyParamInterfaceSetProp1RequestMessage();
	msg->Prop1 = InProp1;

	Testbed2ManyParamInterfaceMsgBusEndpoint->Send<FTestbed2ManyParamInterfaceSetProp1RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->Prop1 = InProp1;
}

int32 UTestbed2ManyParamInterfaceMsgBusClient::GetProp2_Implementation() const
{
	return Prop2;
}

void UTestbed2ManyParamInterfaceMsgBusClient::SetProp2_Implementation(int32 InProp2)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp2_Implementation() == InProp2)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop2 == InProp2)
	{
		return;
	}

	auto msg = new FTestbed2ManyParamInterfaceSetProp2RequestMessage();
	msg->Prop2 = InProp2;

	Testbed2ManyParamInterfaceMsgBusEndpoint->Send<FTestbed2ManyParamInterfaceSetProp2RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->Prop2 = InProp2;
}

int32 UTestbed2ManyParamInterfaceMsgBusClient::GetProp3_Implementation() const
{
	return Prop3;
}

void UTestbed2ManyParamInterfaceMsgBusClient::SetProp3_Implementation(int32 InProp3)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp3_Implementation() == InProp3)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop3 == InProp3)
	{
		return;
	}

	auto msg = new FTestbed2ManyParamInterfaceSetProp3RequestMessage();
	msg->Prop3 = InProp3;

	Testbed2ManyParamInterfaceMsgBusEndpoint->Send<FTestbed2ManyParamInterfaceSetProp3RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->Prop3 = InProp3;
}

int32 UTestbed2ManyParamInterfaceMsgBusClient::GetProp4_Implementation() const
{
	return Prop4;
}

void UTestbed2ManyParamInterfaceMsgBusClient::SetProp4_Implementation(int32 InProp4)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp4_Implementation() == InProp4)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop4 == InProp4)
	{
		return;
	}

	auto msg = new FTestbed2ManyParamInterfaceSetProp4RequestMessage();
	msg->Prop4 = InProp4;

	Testbed2ManyParamInterfaceMsgBusEndpoint->Send<FTestbed2ManyParamInterfaceSetProp4RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	_SentData->Prop4 = InProp4;
}

int32 UTestbed2ManyParamInterfaceMsgBusClient::Func1_Implementation(int32 InParam1)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return 0;
	}

	auto msg = new FTestbed2ManyParamInterfaceFunc1RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->Param1 = InParam1;
	TPromise<int32> Promise;
	StorePromise(msg->ResponseId, Promise);

	Testbed2ManyParamInterfaceMsgBusEndpoint->Send<FTestbed2ManyParamInterfaceFunc1RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnFunc1Reply(const FTestbed2ManyParamInterfaceFunc1ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

int32 UTestbed2ManyParamInterfaceMsgBusClient::Func2_Implementation(int32 InParam1, int32 InParam2)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return 0;
	}

	auto msg = new FTestbed2ManyParamInterfaceFunc2RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->Param1 = InParam1;
	msg->Param2 = InParam2;
	TPromise<int32> Promise;
	StorePromise(msg->ResponseId, Promise);

	Testbed2ManyParamInterfaceMsgBusEndpoint->Send<FTestbed2ManyParamInterfaceFunc2RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnFunc2Reply(const FTestbed2ManyParamInterfaceFunc2ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

int32 UTestbed2ManyParamInterfaceMsgBusClient::Func3_Implementation(int32 InParam1, int32 InParam2, int32 InParam3)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return 0;
	}

	auto msg = new FTestbed2ManyParamInterfaceFunc3RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->Param1 = InParam1;
	msg->Param2 = InParam2;
	msg->Param3 = InParam3;
	TPromise<int32> Promise;
	StorePromise(msg->ResponseId, Promise);

	Testbed2ManyParamInterfaceMsgBusEndpoint->Send<FTestbed2ManyParamInterfaceFunc3RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnFunc3Reply(const FTestbed2ManyParamInterfaceFunc3ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

int32 UTestbed2ManyParamInterfaceMsgBusClient::Func4_Implementation(int32 InParam1, int32 InParam2, int32 InParam3, int32 InParam4)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return 0;
	}

	auto msg = new FTestbed2ManyParamInterfaceFunc4RequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->Param1 = InParam1;
	msg->Param2 = InParam2;
	msg->Param3 = InParam3;
	msg->Param4 = InParam4;
	TPromise<int32> Promise;
	StorePromise(msg->ResponseId, Promise);

	Testbed2ManyParamInterfaceMsgBusEndpoint->Send<FTestbed2ManyParamInterfaceFunc4RequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnFunc4Reply(const FTestbed2ManyParamInterfaceFunc4ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnSig1(const FTestbed2ManyParamInterfaceSig1SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSig1Signal.Broadcast(InMessage.Param1);
	return;
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnSig2(const FTestbed2ManyParamInterfaceSig2SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSig2Signal.Broadcast(InMessage.Param1, InMessage.Param2);
	return;
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnSig3(const FTestbed2ManyParamInterfaceSig3SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSig3Signal.Broadcast(InMessage.Param1, InMessage.Param2, InMessage.Param3);
	return;
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnSig4(const FTestbed2ManyParamInterfaceSig4SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSig4Signal.Broadcast(InMessage.Param1, InMessage.Param2, InMessage.Param3, InMessage.Param4);
	return;
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnProp1Changed(const FTestbed2ManyParamInterfaceProp1ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bProp1Changed = InMessage.Prop1 != Prop1;
	if (bProp1Changed)
	{
		Prop1 = InMessage.Prop1;
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnProp2Changed(const FTestbed2ManyParamInterfaceProp2ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bProp2Changed = InMessage.Prop2 != Prop2;
	if (bProp2Changed)
	{
		Prop2 = InMessage.Prop2;
		Execute__GetSignals(this)->OnProp2Changed.Broadcast(Prop2);
	}
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnProp3Changed(const FTestbed2ManyParamInterfaceProp3ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bProp3Changed = InMessage.Prop3 != Prop3;
	if (bProp3Changed)
	{
		Prop3 = InMessage.Prop3;
		Execute__GetSignals(this)->OnProp3Changed.Broadcast(Prop3);
	}
}

void UTestbed2ManyParamInterfaceMsgBusClient::OnProp4Changed(const FTestbed2ManyParamInterfaceProp4ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bProp4Changed = InMessage.Prop4 != Prop4;
	if (bProp4Changed)
	{
		Prop4 = InMessage.Prop4;
		Execute__GetSignals(this)->OnProp4Changed.Broadcast(Prop4);
	}
}

template <typename ResultType>
bool UTestbed2ManyParamInterfaceMsgBusClient::StorePromise(const FGuid& Id, TPromise<ResultType>& Promise)
{
	FScopeLock Lock(&ReplyPromisesMapCS);
	return ReplyPromisesMap.Add(Id, &Promise) != nullptr;
}

template <typename ResultType>
bool UTestbed2ManyParamInterfaceMsgBusClient::FulfillPromise(const FGuid& Id, const ResultType& Value)
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

template bool UTestbed2ManyParamInterfaceMsgBusClient::StorePromise<int32>(const FGuid& Id, TPromise<int32>& Promise);
template bool UTestbed2ManyParamInterfaceMsgBusClient::FulfillPromise<int32>(const FGuid& Id, const int32& Value);
