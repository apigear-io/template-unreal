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

#include "Generated/MsgBus/Testbed1StructInterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed1StructInterfaceMsgBusMessages.h"
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
struct Testbed1StructInterfacePropertiesMsgBusData
{
	FCriticalSection PropBoolMutex;
	FTestbed1StructBool PropBool{FTestbed1StructBool()};
	FCriticalSection PropIntMutex;
	FTestbed1StructInt PropInt{FTestbed1StructInt()};
	FCriticalSection PropFloatMutex;
	FTestbed1StructFloat PropFloat{FTestbed1StructFloat()};
	FCriticalSection PropStringMutex;
	FTestbed1StructString PropString{FTestbed1StructString()};
};
DEFINE_LOG_CATEGORY(LogTestbed1StructInterfaceMsgBusClient);

UTestbed1StructInterfaceMsgBusClient::UTestbed1StructInterfaceMsgBusClient()
	: UAbstractTestbed1StructInterface()
	, _SentData(MakePimpl<Testbed1StructInterfacePropertiesMsgBusData>())
{
}

UTestbed1StructInterfaceMsgBusClient::~UTestbed1StructInterfaceMsgBusClient() = default;

void UTestbed1StructInterfaceMsgBusClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed1StructInterfaceMsgBusClient::Deinitialize()
{
	_Disconnect();

	Super::Deinitialize();
}

void UTestbed1StructInterfaceMsgBusClient::_Connect()
{
	if (!_HeartbeatTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(_HeartbeatTimerHandle, this, &UTestbed1StructInterfaceMsgBusClient::_OnHeartbeat, _HeartbeatIntervalMS / 1000.0f, true);
	}

	if (_IsConnected())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Log, TEXT("Already connected, cannot connect again."));
		return;
	}

	if (Testbed1StructInterfaceMsgBusEndpoint.IsValid() && !ServiceAddress.IsValid())
	{
		_DiscoverService();
		return;
	}

	// clang-format off
	Testbed1StructInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/Testbed1/StructInterface/Client")
		.Handling<FTestbed1StructInterfaceInitMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnConnectionInit)
		.Handling<FTestbed1StructInterfacePongMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnPong)
		.Handling<FTestbed1StructInterfaceServiceDisconnectMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnServiceClosedConnection)
		.Handling<FTestbed1StructInterfaceSigBoolSignalMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnSigBool)
		.Handling<FTestbed1StructInterfaceSigIntSignalMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnSigInt)
		.Handling<FTestbed1StructInterfaceSigFloatSignalMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnSigFloat)
		.Handling<FTestbed1StructInterfaceSigStringSignalMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnSigString)
		.Handling<FTestbed1StructInterfacePropBoolChangedMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnPropBoolChanged)
		.Handling<FTestbed1StructInterfacePropIntChangedMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnPropIntChanged)
		.Handling<FTestbed1StructInterfacePropFloatChangedMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnPropFloatChanged)
		.Handling<FTestbed1StructInterfacePropStringChangedMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnPropStringChanged)
		.Handling<FTestbed1StructInterfaceFuncBoolReplyMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnFuncBoolReply)
		.Handling<FTestbed1StructInterfaceFuncIntReplyMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnFuncIntReply)
		.Handling<FTestbed1StructInterfaceFuncFloatReplyMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnFuncFloatReply)
		.Handling<FTestbed1StructInterfaceFuncStringReplyMessage>(this, &UTestbed1StructInterfaceMsgBusClient::OnFuncStringReply)
		.Build();
	// clang-format on

	_DiscoverService();
}

void UTestbed1StructInterfaceMsgBusClient::_Disconnect()
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

	auto msg = new FTestbed1StructInterfaceClientDisconnectMessage();

	Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceClientDisconnectMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	Testbed1StructInterfaceMsgBusEndpoint.Reset();
	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

void UTestbed1StructInterfaceMsgBusClient::_DiscoverService()
{
	if (!Testbed1StructInterfaceMsgBusEndpoint.IsValid())
	{
		return;
	}

	auto msg = new FTestbed1StructInterfaceDiscoveryMessage();
	msg->ClientPingIntervalMS = _HeartbeatIntervalMS;

	Testbed1StructInterfaceMsgBusEndpoint->Publish<FTestbed1StructInterfaceDiscoveryMessage>(msg);
}

bool UTestbed1StructInterfaceMsgBusClient::_IsConnected() const
{
	return Testbed1StructInterfaceMsgBusEndpoint.IsValid() && ServiceAddress.IsValid();
}

void UTestbed1StructInterfaceMsgBusClient::OnConnectionInit(const FTestbed1StructInterfaceInitMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress.IsValid())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Warning, TEXT("Got a second init message - should not happen"));
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

void UTestbed1StructInterfaceMsgBusClient::_OnHeartbeat()
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
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Warning, TEXT("Heartbeat failed. Client has no connection to service. Reconnecting ..."));

		_Connect();
		return;
	}

	auto msg = new FTestbed1StructInterfacePingMessage();
	msg->Timestamp = FPlatformTime::Seconds();

	Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfacePingMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
}

void UTestbed1StructInterfaceMsgBusClient::OnPong(const FTestbed1StructInterfacePongMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
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

const FTestbed1StructInterfaceStats& UTestbed1StructInterfaceMsgBusClient::_GetStats() const
{
	return Stats;
}

void UTestbed1StructInterfaceMsgBusClient::OnServiceClosedConnection(const FTestbed1StructInterfaceServiceDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		return;
	}

	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

FTestbed1StructBool UTestbed1StructInterfaceMsgBusClient::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructInterfaceMsgBusClient::SetPropBool_Implementation(const FTestbed1StructBool& InPropBool)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
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

	auto msg = new FTestbed1StructInterfaceSetPropBoolRequestMessage();
	msg->PropBool = InPropBool;

	Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceSetPropBoolRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	FScopeLock Lock(&(_SentData->PropBoolMutex));
	_SentData->PropBool = InPropBool;
}

FTestbed1StructInt UTestbed1StructInterfaceMsgBusClient::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTestbed1StructInterfaceMsgBusClient::SetPropInt_Implementation(const FTestbed1StructInt& InPropInt)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
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

	auto msg = new FTestbed1StructInterfaceSetPropIntRequestMessage();
	msg->PropInt = InPropInt;

	Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceSetPropIntRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	FScopeLock Lock(&(_SentData->PropIntMutex));
	_SentData->PropInt = InPropInt;
}

FTestbed1StructFloat UTestbed1StructInterfaceMsgBusClient::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTestbed1StructInterfaceMsgBusClient::SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
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

	auto msg = new FTestbed1StructInterfaceSetPropFloatRequestMessage();
	msg->PropFloat = InPropFloat;

	Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceSetPropFloatRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	FScopeLock Lock(&(_SentData->PropFloatMutex));
	_SentData->PropFloat = InPropFloat;
}

FTestbed1StructString UTestbed1StructInterfaceMsgBusClient::GetPropString_Implementation() const
{
	return PropString;
}

void UTestbed1StructInterfaceMsgBusClient::SetPropString_Implementation(const FTestbed1StructString& InPropString)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
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

	auto msg = new FTestbed1StructInterfaceSetPropStringRequestMessage();
	msg->PropString = InPropString;

	Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceSetPropStringRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());
	FScopeLock Lock(&(_SentData->PropStringMutex));
	_SentData->PropString = InPropString;
}

FTestbed1StructBool UTestbed1StructInterfaceMsgBusClient::FuncBool_Implementation(const FTestbed1StructBool& InParamBool)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return FTestbed1StructBool();
	}

	auto msg = new FTestbed1StructInterfaceFuncBoolRequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamBool = InParamBool;
	TPromise<FTestbed1StructBool> Promise;
	StorePromise(msg->ResponseId, Promise);

	Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceFuncBoolRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTestbed1StructInterfaceMsgBusClient::OnFuncBoolReply(const FTestbed1StructInterfaceFuncBoolReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

FTestbed1StructInt UTestbed1StructInterfaceMsgBusClient::FuncInt_Implementation(const FTestbed1StructInt& InParamInt)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return FTestbed1StructInt();
	}

	auto msg = new FTestbed1StructInterfaceFuncIntRequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamInt = InParamInt;
	TPromise<FTestbed1StructInt> Promise;
	StorePromise(msg->ResponseId, Promise);

	Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceFuncIntRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTestbed1StructInterfaceMsgBusClient::OnFuncIntReply(const FTestbed1StructInterfaceFuncIntReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

FTestbed1StructFloat UTestbed1StructInterfaceMsgBusClient::FuncFloat_Implementation(const FTestbed1StructFloat& InParamFloat)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return FTestbed1StructFloat();
	}

	auto msg = new FTestbed1StructInterfaceFuncFloatRequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamFloat = InParamFloat;
	TPromise<FTestbed1StructFloat> Promise;
	StorePromise(msg->ResponseId, Promise);

	Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceFuncFloatRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTestbed1StructInterfaceMsgBusClient::OnFuncFloatReply(const FTestbed1StructInterfaceFuncFloatReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

FTestbed1StructString UTestbed1StructInterfaceMsgBusClient::FuncString_Implementation(const FTestbed1StructString& InParamString)
{
	if (!_IsConnected())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return FTestbed1StructString();
	}

	auto msg = new FTestbed1StructInterfaceFuncStringRequestMessage();
	msg->ResponseId = FGuid::NewGuid();
	msg->ParamString = InParamString;
	TPromise<FTestbed1StructString> Promise;
	StorePromise(msg->ResponseId, Promise);

	Testbed1StructInterfaceMsgBusEndpoint->Send<FTestbed1StructInterfaceFuncStringRequestMessage>(msg, EMessageFlags::Reliable,
		nullptr,
		TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
		FTimespan::Zero(),
		FDateTime::MaxValue());

	return Promise.GetFuture().Get();
}

void UTestbed1StructInterfaceMsgBusClient::OnFuncStringReply(const FTestbed1StructInterfaceFuncStringReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InMessage.ResponseId, InMessage.Result);
}

void UTestbed1StructInterfaceMsgBusClient::OnSigBool(const FTestbed1StructInterfaceSigBoolSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigBoolSignal.Broadcast(InMessage.ParamBool);
	return;
}

void UTestbed1StructInterfaceMsgBusClient::OnSigInt(const FTestbed1StructInterfaceSigIntSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigIntSignal.Broadcast(InMessage.ParamInt);
	return;
}

void UTestbed1StructInterfaceMsgBusClient::OnSigFloat(const FTestbed1StructInterfaceSigFloatSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigFloatSignal.Broadcast(InMessage.ParamFloat);
	return;
}

void UTestbed1StructInterfaceMsgBusClient::OnSigString(const FTestbed1StructInterfaceSigStringSignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSigStringSignal.Broadcast(InMessage.ParamString);
	return;
}

void UTestbed1StructInterfaceMsgBusClient::OnPropBoolChanged(const FTestbed1StructInterfacePropBoolChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropBoolChanged = InMessage.PropBool != PropBool;
	if (bPropBoolChanged)
	{
		PropBool = InMessage.PropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(PropBool);
	}
}

void UTestbed1StructInterfaceMsgBusClient::OnPropIntChanged(const FTestbed1StructInterfacePropIntChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropIntChanged = InMessage.PropInt != PropInt;
	if (bPropIntChanged)
	{
		PropInt = InMessage.PropInt;
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
}

void UTestbed1StructInterfaceMsgBusClient::OnPropFloatChanged(const FTestbed1StructInterfacePropFloatChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bPropFloatChanged = InMessage.PropFloat != PropFloat;
	if (bPropFloatChanged)
	{
		PropFloat = InMessage.PropFloat;
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}
}

void UTestbed1StructInterfaceMsgBusClient::OnPropStringChanged(const FTestbed1StructInterfacePropStringChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTestbed1StructInterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
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
bool UTestbed1StructInterfaceMsgBusClient::StorePromise(const FGuid& Id, TPromise<ResultType>& Promise)
{
	FScopeLock Lock(&ReplyPromisesMapCS);
	return ReplyPromisesMap.Add(Id, &Promise) != nullptr;
}

template <typename ResultType>
bool UTestbed1StructInterfaceMsgBusClient::FulfillPromise(const FGuid& Id, const ResultType& Value)
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

template bool UTestbed1StructInterfaceMsgBusClient::StorePromise<FTestbed1StructBool>(const FGuid& Id, TPromise<FTestbed1StructBool>& Promise);
template bool UTestbed1StructInterfaceMsgBusClient::FulfillPromise<FTestbed1StructBool>(const FGuid& Id, const FTestbed1StructBool& Value);
template bool UTestbed1StructInterfaceMsgBusClient::StorePromise<FTestbed1StructFloat>(const FGuid& Id, TPromise<FTestbed1StructFloat>& Promise);
template bool UTestbed1StructInterfaceMsgBusClient::FulfillPromise<FTestbed1StructFloat>(const FGuid& Id, const FTestbed1StructFloat& Value);
template bool UTestbed1StructInterfaceMsgBusClient::StorePromise<FTestbed1StructInt>(const FGuid& Id, TPromise<FTestbed1StructInt>& Promise);
template bool UTestbed1StructInterfaceMsgBusClient::FulfillPromise<FTestbed1StructInt>(const FGuid& Id, const FTestbed1StructInt& Value);
template bool UTestbed1StructInterfaceMsgBusClient::StorePromise<FTestbed1StructString>(const FGuid& Id, TPromise<FTestbed1StructString>& Promise);
template bool UTestbed1StructInterfaceMsgBusClient::FulfillPromise<FTestbed1StructString>(const FGuid& Id, const FTestbed1StructString& Value);
