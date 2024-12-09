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

#include "Generated/MsgBus/TbSame2SameStruct2InterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSame2SameStruct2InterfaceMsgBusMessages.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
#include "MessageEndpointBuilder.h"
#include "MessageEndpoint.h"
#include "HAL/CriticalSection.h"

/**
   \brief data structure to hold the last sent property values
*/
struct TbSame2SameStruct2InterfacePropertiesMsgBusData
{
	FCriticalSection Prop1Mutex;
	FTbSame2Struct2 Prop1{FTbSame2Struct2()};
	FCriticalSection Prop2Mutex;
	FTbSame2Struct2 Prop2{FTbSame2Struct2()};
};
DEFINE_LOG_CATEGORY(LogTbSame2SameStruct2InterfaceMsgBusClient);

UTbSame2SameStruct2InterfaceMsgBusClient::UTbSame2SameStruct2InterfaceMsgBusClient()
	: UAbstractTbSame2SameStruct2Interface()
	, _SentData(MakePimpl<TbSame2SameStruct2InterfacePropertiesMsgBusData>())
{
	/* m_sink = std::make_shared<FOLinkSink>("tb.same2.SameStruct2Interface"); */
}

UTbSame2SameStruct2InterfaceMsgBusClient::~UTbSame2SameStruct2InterfaceMsgBusClient() = default;

void UTbSame2SameStruct2InterfaceMsgBusClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Connect();
}

void UTbSame2SameStruct2InterfaceMsgBusClient::Deinitialize()
{
	Disconnect();

	Super::Deinitialize();
}

void UTbSame2SameStruct2InterfaceMsgBusClient::Connect()
{
	if (IsConnected())
	{
		return;
	}

	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid() && !ServiceAddress.IsValid())
	{
		DiscoverService();
		return;
	}

	// clang-format off
	TbSame2SameStruct2InterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/TbSame2/SameStruct2Interface/Client")
		.Handling<FTbSame2SameStruct2InterfaceInitMessage>(this, &UTbSame2SameStruct2InterfaceMsgBusClient::OnConnectionInit)
		.Handling<FTbSame2SameStruct2InterfaceServiceDisconnectMessage>(this, &UTbSame2SameStruct2InterfaceMsgBusClient::OnServiceClosedConnection)
		.Handling<FTbSame2SameStruct2InterfaceSig1SignalMessage>(this, &UTbSame2SameStruct2InterfaceMsgBusClient::OnSig1)

		.Handling<FTbSame2SameStruct2InterfaceSig2SignalMessage>(this, &UTbSame2SameStruct2InterfaceMsgBusClient::OnSig2)
		.Handling<FTbSame2SameStruct2InterfaceProp1ChangedMessage>(this, &UTbSame2SameStruct2InterfaceMsgBusClient::OnProp1Changed)

		.Handling<FTbSame2SameStruct2InterfaceProp2ChangedMessage>(this, &UTbSame2SameStruct2InterfaceMsgBusClient::OnProp2Changed)
		.Handling<FTbSame2SameStruct2InterfaceFunc1ReplyMessage>(this, &UTbSame2SameStruct2InterfaceMsgBusClient::OnFunc1Reply)
		.Handling<FTbSame2SameStruct2InterfaceFunc2ReplyMessage>(this, &UTbSame2SameStruct2InterfaceMsgBusClient::OnFunc2Reply)
		.Build();
	// clang-format on

	DiscoverService();
}

void UTbSame2SameStruct2InterfaceMsgBusClient::Disconnect()
{
	if (!IsConnected())
	{
		return;
	}

	auto msg = new FTbSame2SameStruct2InterfaceClientDisconnectMessage();

	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct2InterfaceClientDisconnectMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}

	TbSame2SameStruct2InterfaceMsgBusEndpoint.Reset();
	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

void UTbSame2SameStruct2InterfaceMsgBusClient::DiscoverService()
{
	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameStruct2InterfaceMsgBusEndpoint->Publish<FTbSame2SameStruct2InterfaceDiscoveryMessage>(new FTbSame2SameStruct2InterfaceDiscoveryMessage());
	}
}

bool UTbSame2SameStruct2InterfaceMsgBusClient::IsConnected() const
{
	return TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid() && ServiceAddress.IsValid();
}

void UTbSame2SameStruct2InterfaceMsgBusClient::OnConnectionInit(const FTbSame2SameStruct2InterfaceInitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (!ServiceAddress.IsValid())
	{
		ServiceAddress = Context->GetSender();
		const bool bProp1Changed = InInitMessage.Prop1 != Prop1;
		if (bProp1Changed)
		{
			Prop1 = InInitMessage.Prop1;
			Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
		}

		const bool bProp2Changed = InInitMessage.Prop2 != Prop2;
		if (bProp2Changed)
		{
			Prop2 = InInitMessage.Prop2;
			Execute__GetSignals(this)->OnProp2Changed.Broadcast(Prop2);
		}

		_ConnectionStatusChanged.Broadcast(true);
	}
	else
	{
		UE_LOG(LogTbSame2SameStruct2InterfaceMsgBusClient, Error, TEXT("Got a second init message - should not happen"));
	}
}

void UTbSame2SameStruct2InterfaceMsgBusClient::OnServiceClosedConnection(const FTbSame2SameStruct2InterfaceServiceDisconnectMessage& /*InMessage*/, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		return;
	}

	ServiceAddress.Invalidate();
	_ConnectionStatusChanged.Broadcast(false);
}

FTbSame2Struct2 UTbSame2SameStruct2InterfaceMsgBusClient::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame2SameStruct2InterfaceMsgBusClient::SetProp1_Implementation(const FTbSame2Struct2& InProp1)
{
	if (!IsConnected())
	{
		UE_LOG(LogTbSame2SameStruct2InterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
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

	auto msg = new FTbSame2SameStruct2InterfaceSetProp1RequestMessage();
	msg->Prop1 = InProp1;

	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct2InterfaceSetProp1RequestMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
		FScopeLock Lock(&(_SentData->Prop1Mutex));
		_SentData->Prop1 = InProp1;
	}
}

FTbSame2Struct2 UTbSame2SameStruct2InterfaceMsgBusClient::GetProp2_Implementation() const
{
	return Prop2;
}

void UTbSame2SameStruct2InterfaceMsgBusClient::SetProp2_Implementation(const FTbSame2Struct2& InProp2)
{
	if (!IsConnected())
	{
		UE_LOG(LogTbSame2SameStruct2InterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp2_Implementation() == InProp2)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	{
		FScopeLock Lock(&(_SentData->Prop2Mutex));
		if (_SentData->Prop2 == InProp2)
		{
			return;
		}
	}

	auto msg = new FTbSame2SameStruct2InterfaceSetProp2RequestMessage();
	msg->Prop2 = InProp2;

	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TbSame2SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct2InterfaceSetProp2RequestMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());
		FScopeLock Lock(&(_SentData->Prop2Mutex));
		_SentData->Prop2 = InProp2;
	}
}

FTbSame2Struct1 UTbSame2SameStruct2InterfaceMsgBusClient::Func1_Implementation(const FTbSame2Struct1& InParam1)
{
	if (!IsConnected())
	{
		UE_LOG(LogTbSame2SameStruct2InterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return FTbSame2Struct1();
	}

	auto msg = new FTbSame2SameStruct2InterfaceFunc1RequestMessage();
	msg->RepsonseId = FGuid::NewGuid();
	msg->Param1 = InParam1;

	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TPromise<FTbSame2Struct1> Promise;
		StorePromise(msg->RepsonseId, Promise);

		TbSame2SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct2InterfaceFunc1RequestMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());

		return Promise.GetFuture().Get();
	}

	return FTbSame2Struct1();
}

void UTbSame2SameStruct2InterfaceMsgBusClient::OnFunc1Reply(const FTbSame2SameStruct2InterfaceFunc1ReplyMessage& InFunc1ReplyMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InFunc1ReplyMessage.RepsonseId, InFunc1ReplyMessage.Result);
}

FTbSame2Struct1 UTbSame2SameStruct2InterfaceMsgBusClient::Func2_Implementation(const FTbSame2Struct1& InParam1, const FTbSame2Struct2& InParam2)
{
	if (!IsConnected())
	{
		UE_LOG(LogTbSame2SameStruct2InterfaceMsgBusClient, Error, TEXT("Client has no connection to service."));

		return FTbSame2Struct1();
	}

	auto msg = new FTbSame2SameStruct2InterfaceFunc2RequestMessage();
	msg->RepsonseId = FGuid::NewGuid();
	msg->Param1 = InParam1;
	msg->Param2 = InParam2;

	if (TbSame2SameStruct2InterfaceMsgBusEndpoint.IsValid())
	{
		TPromise<FTbSame2Struct1> Promise;
		StorePromise(msg->RepsonseId, Promise);

		TbSame2SameStruct2InterfaceMsgBusEndpoint->Send<FTbSame2SameStruct2InterfaceFunc2RequestMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(ServiceAddress),
			FTimespan::Zero(),
			FDateTime::MaxValue());

		return Promise.GetFuture().Get();
	}

	return FTbSame2Struct1();
}

void UTbSame2SameStruct2InterfaceMsgBusClient::OnFunc2Reply(const FTbSame2SameStruct2InterfaceFunc2ReplyMessage& InFunc2ReplyMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	FulfillPromise(InFunc2ReplyMessage.RepsonseId, InFunc2ReplyMessage.Result);
}

void UTbSame2SameStruct2InterfaceMsgBusClient::OnSig1(const FTbSame2SameStruct2InterfaceSig1SignalMessage& InSig1Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSame2SameStruct2InterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSig1Signal.Broadcast(InSig1Message.Param1);
	return;
}

void UTbSame2SameStruct2InterfaceMsgBusClient::OnSig2(const FTbSame2SameStruct2InterfaceSig2SignalMessage& InSig2Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSame2SameStruct2InterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	Execute__GetSignals(this)->OnSig2Signal.Broadcast(InSig2Message.Param1, InSig2Message.Param2);
	return;
}

void UTbSame2SameStruct2InterfaceMsgBusClient::OnProp1Changed(const FTbSame2SameStruct2InterfaceProp1ChangedMessage& InProp1Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSame2SameStruct2InterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bProp1Changed = InProp1Message.Prop1 != Prop1;
	if (bProp1Changed)
	{
		Prop1 = InProp1Message.Prop1;
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}
}

void UTbSame2SameStruct2InterfaceMsgBusClient::OnProp2Changed(const FTbSame2SameStruct2InterfaceProp2ChangedMessage& InProp2Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ServiceAddress != Context->GetSender())
	{
		UE_LOG(LogTbSame2SameStruct2InterfaceMsgBusClient, Error, TEXT("Got a message from wrong service(%s) instead of %s"), *Context->GetSender().ToString(), *ServiceAddress.ToString());
		return;
	}

	const bool bProp2Changed = InProp2Message.Prop2 != Prop2;
	if (bProp2Changed)
	{
		Prop2 = InProp2Message.Prop2;
		Execute__GetSignals(this)->OnProp2Changed.Broadcast(Prop2);
	}
}

template <typename ResultType>
bool UTbSame2SameStruct2InterfaceMsgBusClient::StorePromise(const FGuid& Id, TPromise<ResultType>& Promise)
{
	FScopeLock Lock(&ReplyPromisesMapCS);
	return ReplyPromisesMap.Add(Id, &Promise) != nullptr;
}

template <typename ResultType>
bool UTbSame2SameStruct2InterfaceMsgBusClient::FulfillPromise(const FGuid& Id, const ResultType& Value)
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

template bool UTbSame2SameStruct2InterfaceMsgBusClient::StorePromise<FTbSame2Struct1>(const FGuid& Id, TPromise<FTbSame2Struct1>& Promise);
template bool UTbSame2SameStruct2InterfaceMsgBusClient::FulfillPromise<FTbSame2Struct1>(const FGuid& Id, const FTbSame2Struct1& Value);
