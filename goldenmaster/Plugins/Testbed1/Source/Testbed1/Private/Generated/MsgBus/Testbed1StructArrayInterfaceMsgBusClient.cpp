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

#include "Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusMessages.h"
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
struct Testbed1StructArrayInterfacePropertiesMsgBusData
{
	FCriticalSection PropBoolMutex;
	TArray<FTestbed1StructBool> PropBool{TArray<FTestbed1StructBool>()};
	FCriticalSection PropIntMutex;
	TArray<FTestbed1StructInt> PropInt{TArray<FTestbed1StructInt>()};
	FCriticalSection PropFloatMutex;
	TArray<FTestbed1StructFloat> PropFloat{TArray<FTestbed1StructFloat>()};
	FCriticalSection PropStringMutex;
	TArray<FTestbed1StructString> PropString{TArray<FTestbed1StructString>()};
};
DEFINE_LOG_CATEGORY(LogTestbed1StructArrayInterfaceMsgBusClient);

UTestbed1StructArrayInterfaceMsgBusClient::UTestbed1StructArrayInterfaceMsgBusClient()
	: UAbstractTestbed1StructArrayInterface()
	, _SentData(MakePimpl<Testbed1StructArrayInterfacePropertiesMsgBusData>())
{
}

UTestbed1StructArrayInterfaceMsgBusClient::~UTestbed1StructArrayInterfaceMsgBusClient() = default;

void UTestbed1StructArrayInterfaceMsgBusClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed1StructArrayInterfaceMsgBusClient::Deinitialize()
{
	_Disconnect();

	Super::Deinitialize();
}

void UTestbed1StructArrayInterfaceMsgBusClient::_Connect()
{
	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTestbed1StructArrayInterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (_IsConnected())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Log, TEXT("Already connected, cannot connect again."));
		return;
	}

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid() && !ServiceAddress.IsValid())
	{
		_DiscoverService();
		return;
	}

	// clang-format off
	Testbed1StructArrayInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/Testbed1/StructArrayInterface/Client")
		.Handling<FTestbed1StructArrayInterfaceInitMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnConnectionInit)
		.Handling<FTestbed1StructArrayInterfacePongMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnPong)
		.Handling<FTestbed1StructArrayInterfaceServiceDisconnectMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnServiceClosedConnection)
		.Handling<FTestbed1StructArrayInterfaceSigBoolSignalMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnSigBool)
		.Handling<FTestbed1StructArrayInterfaceSigIntSignalMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnSigInt)
		.Handling<FTestbed1StructArrayInterfaceSigFloatSignalMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnSigFloat)
		.Handling<FTestbed1StructArrayInterfaceSigStringSignalMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnSigString)
		.Handling<FTestbed1StructArrayInterfacePropBoolChangedMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnPropBoolChanged)
		.Handling<FTestbed1StructArrayInterfacePropIntChangedMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnPropIntChanged)
		.Handling<FTestbed1StructArrayInterfacePropFloatChangedMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnPropFloatChanged)
		.Handling<FTestbed1StructArrayInterfacePropStringChangedMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnPropStringChanged)
		.Handling<FTestbed1StructArrayInterfaceFuncBoolReplyMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnFuncBoolReply)
		.Handling<FTestbed1StructArrayInterfaceFuncIntReplyMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnFuncIntReply)
		.Handling<FTestbed1StructArrayInterfaceFuncFloatReplyMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnFuncFloatReply)
		.Handling<FTestbed1StructArrayInterfaceFuncStringReplyMessage>(this, &UTestbed1StructArrayInterfaceMsgBusClient::OnFuncStringReply)
		.Build();
	// clang-format on

	_DiscoverService();
}

void UTestbed1StructArrayInterfaceMsgBusClient::_Disconnect()
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

	auto msg = new FTestbed1StructArrayInterfaceClientDisconnectMessage();

	Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceClientDisconnectMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	Testbed1StructArrayInterfaceMsgBusEndpoint.Reset();
	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

void UTestbed1StructArrayInterfaceMsgBusClient::_DiscoverService()
{
	if (!Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
	{
		return;
	}

	auto msg = new FTestbed1StructArrayInterfaceDiscoveryMessage();
	msg->ClientPingIntervalMS = _HeartbeatIntervalMS;

	Testbed1StructArrayInterfaceMsgBusEndpoint->Publish<FTestbed1StructArrayInterfaceDiscoveryMessage>(msg);
}

bool UTestbed1StructArrayInterfaceMsgBusClient::_IsConnected() const
{
	return Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid() && ServiceAddress.IsValid();
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnConnectionInit(const FTestbed1StructArrayInterfaceInitMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress.IsValid())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Warning, TEXT("Got a second init message - should not happen"));
		return;
	}

	ServiceAddress = Context->GetSender();
	const bool bPropBoolChanged = InMessage.PropBool != PropBool;
	if (bPropBoolChanged)
	{
		PropBool = InMessage.PropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(PropBool);
	}

	const bool bPropIntChanged = InMessage.PropInt != PropInt;
	if (bPropIntChanged)
	{
		PropInt = InMessage.PropInt;
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}

	const bool bPropFloatChanged = InMessage.PropFloat != PropFloat;
	if (bPropFloatChanged)
	{
		PropFloat = InMessage.PropFloat;
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}

	const bool bPropStringChanged = InMessage.PropString != PropString;
	if (bPropStringChanged)
	{
		PropString = InMessage.PropString;
		Execute__GetSignals(this)->OnPropStringChanged.Broadcast(PropString);
	}

	_ConnectionStatusChanged.Broadcast(true);
}

void UTestbed1StructArrayInterfaceMsgBusClient::_OnHeartbeat()
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
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Warning, TEXT("Heartbeat failed. Client has no connection to service. Reconnecting ..."));

		_Connect();
		return;
	}

	auto msg = new FTestbed1StructArrayInterfacePingMessage();
	msg->Timestamp = FPlatformTime::Seconds();

	Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfacePingMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnPong(const FTestbed1StructArrayInterfacePongMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
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

const FTestbed1StructArrayInterfaceStats& UTestbed1StructArrayInterfaceMsgBusClient::_GetStats() const
{
	return Stats;
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnServiceClosedConnection(const FTestbed1StructArrayInterfaceServiceDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		return;
	}

	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceMsgBusClient::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructArrayInterfaceMsgBusClient::SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropBool_Implementation() == InPropBool)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->PropBoolMutex));
		if (_SentData->PropBool == InPropBool)
		{
			return;
		}
	}

	auto msg = new FTestbed1StructArrayInterfaceSetPropBoolRequestMessage();
	msg->PropBool = InPropBool;

	Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceSetPropBoolRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	FScopeLock Lock(&(_SentData->PropBoolMutex));
	_SentData->PropBool = InPropBool;
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceMsgBusClient::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTestbed1StructArrayInterfaceMsgBusClient::SetPropInt_Implementation(const TArray<FTestbed1StructInt>& InPropInt)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropInt_Implementation() == InPropInt)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->PropIntMutex));
		if (_SentData->PropInt == InPropInt)
		{
			return;
		}
	}

	auto msg = new FTestbed1StructArrayInterfaceSetPropIntRequestMessage();
	msg->PropInt = InPropInt;

	Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceSetPropIntRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	FScopeLock Lock(&(_SentData->PropIntMutex));
	_SentData->PropInt = InPropInt;
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceMsgBusClient::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTestbed1StructArrayInterfaceMsgBusClient::SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropFloat_Implementation() == InPropFloat)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->PropFloatMutex));
		if (_SentData->PropFloat == InPropFloat)
		{
			return;
		}
	}

	auto msg = new FTestbed1StructArrayInterfaceSetPropFloatRequestMessage();
	msg->PropFloat = InPropFloat;

	Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceSetPropFloatRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	FScopeLock Lock(&(_SentData->PropFloatMutex));
	_SentData->PropFloat = InPropFloat;
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceMsgBusClient::GetPropString_Implementation() const
{
	return PropString;
}

void UTestbed1StructArrayInterfaceMsgBusClient::SetPropString_Implementation(const TArray<FTestbed1StructString>& InPropString)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropString_Implementation() == InPropString)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->PropStringMutex));
		if (_SentData->PropString == InPropString)
		{
			return;
		}
	}

	auto msg = new FTestbed1StructArrayInterfaceSetPropStringRequestMessage();
	msg->PropString = InPropString;

	Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceSetPropStringRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	FScopeLock Lock(&(_SentData->PropStringMutex));
	_SentData->PropString = InPropString;
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceMsgBusClient::FuncBool_Implementation(const TArray<FTestbed1StructBool>& InParamBool)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return TArray<FTestbed1StructBool>();
	}

	auto msg = new FTestbed1StructArrayInterfaceFuncBoolRequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamBool = InParamBool;
	TPromise<TArray<FTestbed1StructBool>> Promise;
	StorePromise(msg->ResponseId, Promise);

	Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceFuncBoolRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnFuncBoolReply(const FTestbed1StructArrayInterfaceFuncBoolReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceMsgBusClient::FuncInt_Implementation(const TArray<FTestbed1StructInt>& InParamInt)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return TArray<FTestbed1StructInt>();
	}

	auto msg = new FTestbed1StructArrayInterfaceFuncIntRequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamInt = InParamInt;
	TPromise<TArray<FTestbed1StructInt>> Promise;
	StorePromise(msg->ResponseId, Promise);

	Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceFuncIntRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnFuncIntReply(const FTestbed1StructArrayInterfaceFuncIntReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceMsgBusClient::FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& InParamFloat)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return TArray<FTestbed1StructFloat>();
	}

	auto msg = new FTestbed1StructArrayInterfaceFuncFloatRequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamFloat = InParamFloat;
	TPromise<TArray<FTestbed1StructFloat>> Promise;
	StorePromise(msg->ResponseId, Promise);

	Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceFuncFloatRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnFuncFloatReply(const FTestbed1StructArrayInterfaceFuncFloatReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceMsgBusClient::FuncString_Implementation(const TArray<FTestbed1StructString>& InParamString)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return TArray<FTestbed1StructString>();
	}

	auto msg = new FTestbed1StructArrayInterfaceFuncStringRequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamString = InParamString;
	TPromise<TArray<FTestbed1StructString>> Promise;
	StorePromise(msg->ResponseId, Promise);

	Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceFuncStringRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnFuncStringReply(const FTestbed1StructArrayInterfaceFuncStringReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnSigBool(const FTestbed1StructArrayInterfaceSigBoolSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigBoolSignal.Broadcast(InMessage.ParamBool);
	return;
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnSigInt(const FTestbed1StructArrayInterfaceSigIntSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigIntSignal.Broadcast(InMessage.ParamInt);
	return;
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnSigFloat(const FTestbed1StructArrayInterfaceSigFloatSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigFloatSignal.Broadcast(InMessage.ParamFloat);
	return;
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnSigString(const FTestbed1StructArrayInterfaceSigStringSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigStringSignal.Broadcast(InMessage.ParamString);
	return;
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnPropBoolChanged(const FTestbed1StructArrayInterfacePropBoolChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropBoolChanged = InMessage.PropBool != PropBool;
	if (bPropBoolChanged)
	{
		PropBool = InMessage.PropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(PropBool);
	}
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnPropIntChanged(const FTestbed1StructArrayInterfacePropIntChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropIntChanged = InMessage.PropInt != PropInt;
	if (bPropIntChanged)
	{
		PropInt = InMessage.PropInt;
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnPropFloatChanged(const FTestbed1StructArrayInterfacePropFloatChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropFloatChanged = InMessage.PropFloat != PropFloat;
	if (bPropFloatChanged)
	{
		PropFloat = InMessage.PropFloat;
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}
}

void UTestbed1StructArrayInterfaceMsgBusClient::OnPropStringChanged(const FTestbed1StructArrayInterfacePropStringChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropStringChanged = InMessage.PropString != PropString;
	if (bPropStringChanged)
	{
		PropString = InMessage.PropString;
		Execute__GetSignals(this)->OnPropStringChanged.Broadcast(PropString);
	}
}

template <typename ResultType>
bool UTestbed1StructArrayInterfaceMsgBusClient::StorePromise(const FGuid& Id, TPromise<ResultType>& Promise)
{
	FScopeLock Lock(&ReplyPromisesMapCS);
	return ReplyPromisesMap.Add(Id, &Promise) != nullptr;
}

template <typename ResultType>
bool UTestbed1StructArrayInterfaceMsgBusClient::FulfillPromise(const FGuid& Id, const ResultType& Value)
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

template bool UTestbed1StructArrayInterfaceMsgBusClient::StorePromise<TArray<FTestbed1StructBool>>(const FGuid& Id, TPromise<TArray<FTestbed1StructBool>>& Promise);
template bool UTestbed1StructArrayInterfaceMsgBusClient::FulfillPromise<TArray<FTestbed1StructBool>>(const FGuid& Id, const TArray<FTestbed1StructBool>& Value);
template bool UTestbed1StructArrayInterfaceMsgBusClient::StorePromise<TArray<FTestbed1StructFloat>>(const FGuid& Id, TPromise<TArray<FTestbed1StructFloat>>& Promise);
template bool UTestbed1StructArrayInterfaceMsgBusClient::FulfillPromise<TArray<FTestbed1StructFloat>>(const FGuid& Id, const TArray<FTestbed1StructFloat>& Value);
template bool UTestbed1StructArrayInterfaceMsgBusClient::StorePromise<TArray<FTestbed1StructInt>>(const FGuid& Id, TPromise<TArray<FTestbed1StructInt>>& Promise);
template bool UTestbed1StructArrayInterfaceMsgBusClient::FulfillPromise<TArray<FTestbed1StructInt>>(const FGuid& Id, const TArray<FTestbed1StructInt>& Value);
template bool UTestbed1StructArrayInterfaceMsgBusClient::StorePromise<TArray<FTestbed1StructString>>(const FGuid& Id, TPromise<TArray<FTestbed1StructString>>& Promise);
template bool UTestbed1StructArrayInterfaceMsgBusClient::FulfillPromise<TArray<FTestbed1StructString>>(const FGuid& Id, const TArray<FTestbed1StructString>& Value);
