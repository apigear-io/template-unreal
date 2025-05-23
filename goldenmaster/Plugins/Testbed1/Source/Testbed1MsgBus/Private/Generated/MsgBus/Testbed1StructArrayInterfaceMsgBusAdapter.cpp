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

#include "Testbed1/Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusAdapter.h"
#include "Testbed1/Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusMessages.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Engine/World.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "Misc/DateTime.h"
#include "Testbed1Settings.h"

DEFINE_LOG_CATEGORY(LogTestbed1StructArrayInterfaceMsgBusAdapter);
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

	if (!_HeartbeatTickerHandle.IsValid())
	{
		UTestbed1Settings* settings = GetMutableDefault<UTestbed1Settings>();
		check(settings);
		_HeartbeatIntervalMS = settings->MsgBusHeartbeatIntervalMS;

#if (ENGINE_MAJOR_VERSION < 5)
		_HeartbeatTickerHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::_CheckClientTimeoutsTick), _HeartbeatIntervalMS / 1000.0f);
#else
		_HeartbeatTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::_CheckClientTimeoutsTick), _HeartbeatIntervalMS / 1000.0f);
#endif
	}

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
		return;

	// clang-format off
	Testbed1StructArrayInterfaceMsgBusEndpoint = FMessageEndpoint::Builder("ApiGear/Testbed1/StructArrayInterface/Service")
		.Handling<FTestbed1StructArrayInterfaceDiscoveryMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnDiscoveryMessage)
		.Handling<FTestbed1StructArrayInterfaceServiceAnnouncementReplyMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnServiceAnnouncementMessage)
		.Handling<FTestbed1StructArrayInterfacePingMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPing)
		.Handling<FTestbed1StructArrayInterfaceClientDisconnectMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnClientDisconnected)
		.Handling<FTestbed1StructArrayInterfaceSetPropBoolRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropBoolRequest)
		.Handling<FTestbed1StructArrayInterfaceSetPropIntRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropIntRequest)
		.Handling<FTestbed1StructArrayInterfaceSetPropFloatRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropFloatRequest)
		.Handling<FTestbed1StructArrayInterfaceSetPropStringRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropStringRequest)
		.Handling<FTestbed1StructArrayInterfaceSetPropEnumRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropEnumRequest)
		.Handling<FTestbed1StructArrayInterfaceFuncBoolRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnFuncBoolRequest)
		.Handling<FTestbed1StructArrayInterfaceFuncIntRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnFuncIntRequest)
		.Handling<FTestbed1StructArrayInterfaceFuncFloatRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnFuncFloatRequest)
		.Handling<FTestbed1StructArrayInterfaceFuncStringRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnFuncStringRequest)
		.Handling<FTestbed1StructArrayInterfaceFuncEnumRequestMessage>(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnFuncEnumRequest)
		.Build();
	// clang-format on

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Subscribe<FTestbed1StructArrayInterfaceDiscoveryMessage>();
		Testbed1StructArrayInterfaceMsgBusEndpoint->Subscribe<FTestbed1StructArrayInterfaceServiceAnnouncementReplyMessage>();
	}

	_AnnounceService();
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::_AnnounceService()
{
	if (!Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
	{
		return;
	}

	auto msg = new FTestbed1StructArrayInterfaceDiscoveryMessage();
	msg->Type = ETestbed1StructArrayInterfaceDiscoveryMessageType::ServiceAnnouncement;
	Testbed1StructArrayInterfaceMsgBusEndpoint->Publish<FTestbed1StructArrayInterfaceDiscoveryMessage>(msg);
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::_StopListening()
{
	if (_HeartbeatTickerHandle.IsValid())
	{
#if (ENGINE_MAJOR_VERSION < 5)
		FTicker::GetCoreTicker().RemoveTicker(_HeartbeatTickerHandle);
#else
		FTSTicker::GetCoreTicker().RemoveTicker(_HeartbeatTickerHandle);
#endif
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
		UTestbed1StructArrayInterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructArrayInterface"));
		if (OnPropBoolChangedHandle.IsValid())
		{
			BackendSignals->OnPropBoolChanged.Remove(OnPropBoolChangedHandle);
			OnPropBoolChangedHandle.Reset();
		}
		if (OnPropIntChangedHandle.IsValid())
		{
			BackendSignals->OnPropIntChanged.Remove(OnPropIntChangedHandle);
			OnPropIntChangedHandle.Reset();
		}
		if (OnPropFloatChangedHandle.IsValid())
		{
			BackendSignals->OnPropFloatChanged.Remove(OnPropFloatChangedHandle);
			OnPropFloatChangedHandle.Reset();
		}
		if (OnPropStringChangedHandle.IsValid())
		{
			BackendSignals->OnPropStringChanged.Remove(OnPropStringChangedHandle);
			OnPropStringChangedHandle.Reset();
		}
		if (OnPropEnumChangedHandle.IsValid())
		{
			BackendSignals->OnPropEnumChanged.Remove(OnPropEnumChangedHandle);
			OnPropEnumChangedHandle.Reset();
		}
		if (OnSigBoolSignalHandle.IsValid())
		{
			BackendSignals->OnSigBoolSignal.Remove(OnSigBoolSignalHandle);
			OnSigBoolSignalHandle.Reset();
		}
		if (OnSigIntSignalHandle.IsValid())
		{
			BackendSignals->OnSigIntSignal.Remove(OnSigIntSignalHandle);
			OnSigIntSignalHandle.Reset();
		}
		if (OnSigFloatSignalHandle.IsValid())
		{
			BackendSignals->OnSigFloatSignal.Remove(OnSigFloatSignalHandle);
			OnSigFloatSignalHandle.Reset();
		}
		if (OnSigStringSignalHandle.IsValid())
		{
			BackendSignals->OnSigStringSignal.Remove(OnSigStringSignalHandle);
			OnSigStringSignalHandle.Reset();
		}
		if (OnSigEnumSignalHandle.IsValid())
		{
			BackendSignals->OnSigEnumSignal.Remove(OnSigEnumSignalHandle);
			OnSigEnumSignalHandle.Reset();
		}
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed1StructArrayInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed1StructArrayInterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service Testbed1StructArrayInterface"));
	// connect property changed signals or simple events
	OnPropBoolChangedHandle = BackendSignals->OnPropBoolChanged.AddUObject(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropBoolChanged);
	OnPropIntChangedHandle = BackendSignals->OnPropIntChanged.AddUObject(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropIntChanged);
	OnPropFloatChangedHandle = BackendSignals->OnPropFloatChanged.AddUObject(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropFloatChanged);
	OnPropStringChangedHandle = BackendSignals->OnPropStringChanged.AddUObject(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropStringChanged);
	OnPropEnumChangedHandle = BackendSignals->OnPropEnumChanged.AddUObject(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropEnumChanged);
	OnSigBoolSignalHandle = BackendSignals->OnSigBoolSignal.AddUObject(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigBool);
	OnSigIntSignalHandle = BackendSignals->OnSigIntSignal.AddUObject(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigInt);
	OnSigFloatSignalHandle = BackendSignals->OnSigFloatSignal.AddUObject(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigFloat);
	OnSigStringSignalHandle = BackendSignals->OnSigStringSignal.AddUObject(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigString);
	OnSigEnumSignalHandle = BackendSignals->OnSigEnumSignal.AddUObject(this, &UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigEnum);
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnDiscoveryMessage(const FTestbed1StructArrayInterfaceDiscoveryMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	switch (InMessage.Type)
	{
	case ETestbed1StructArrayInterfaceDiscoveryMessageType::ServiceAnnouncement:
		HandleServiceAnnouncement(Context);
		break;
	case ETestbed1StructArrayInterfaceDiscoveryMessageType::ConnectionRequest:
	default:
		HandleClientConnectionRequest(Context);
		break;
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::HandleClientConnectionRequest(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (ConnectedClientsTimestamps.Contains(Context->GetSender()))
	{
		return;
	}

	const FMessageAddress& ClientAddress = Context->GetSender();

	auto msg = new FTestbed1StructArrayInterfaceInitMessage();
	msg->_ClientPingIntervalMS = _HeartbeatIntervalMS;
	msg->PropBool = BackendService->GetPropBool();
	msg->PropInt = BackendService->GetPropInt();
	msg->PropFloat = BackendService->GetPropFloat();
	msg->PropString = BackendService->GetPropString();
	msg->PropEnum = BackendService->GetPropEnum();

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

void UTestbed1StructArrayInterfaceMsgBusAdapter::HandleServiceAnnouncement(const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	// send service announcement
	auto msg = new FTestbed1StructArrayInterfaceServiceAnnouncementReplyMessage();

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceServiceAnnouncementReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnServiceAnnouncementMessage(const FTestbed1StructArrayInterfaceServiceAnnouncementReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	if (Testbed1StructArrayInterfaceMsgBusEndpoint->GetAddress() == Context->GetSender())
	{
		return;
	}
	UE_LOG(LogTestbed1StructArrayInterfaceMsgBusAdapter, Error, TEXT("Service announcement from existing endpoint(%s) received, we should stop listening."), *Context->GetSender().ToString());
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
	if (!ConnectedClientsTimestamps.Contains(Context->GetSender()))
	{
		return;
	}

	ConnectedClientsTimestamps.Remove(Context->GetSender());
	_OnClientDisconnected.Broadcast(Context->GetSender().ToString());
	_UpdateClientsConnected();
}

bool UTestbed1StructArrayInterfaceMsgBusAdapter::_CheckClientTimeoutsTick(float /*DeltaTime*/)
{
	_CheckClientTimeouts();
	return true;
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::_CheckClientTimeouts()
{
	const double CurrentTime = FPlatformTime::Seconds();
	TArray<FMessageAddress> TimedOutClients;

	for (const auto& ClientPair : ConnectedClientsTimestamps)
	{
		const double DeltaMS = (CurrentTime - ClientPair.Value) * 1000.0;

		if (DeltaMS > 2 * _HeartbeatIntervalMS)
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
	msg->Result = BackendService->FuncBool(InMessage.ParamBool);

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
	msg->Result = BackendService->FuncInt(InMessage.ParamInt);

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
	msg->Result = BackendService->FuncFloat(InMessage.ParamFloat);

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
	msg->Result = BackendService->FuncString(InMessage.ParamString);

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceFuncStringReplyMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			TArrayBuilder<FMessageAddress>().Add(Context->GetSender()),
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnFuncEnumRequest(const FTestbed1StructArrayInterfaceFuncEnumRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	auto msg = new FTestbed1StructArrayInterfaceFuncEnumReplyMessage();
	msg->ResponseId = InMessage.ResponseId;
	msg->Result = BackendService->FuncEnum(InMessage.ParamEnum);

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid())
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceFuncEnumReplyMessage>(msg, EMessageFlags::Reliable,
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

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnSigEnum(const TArray<ETestbed1Enum0>& InParamEnum)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTestbed1StructArrayInterfaceSigEnumSignalMessage();
	msg->ParamEnum = InParamEnum;
	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfaceSigEnumSignalMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropBoolRequest(const FTestbed1StructArrayInterfaceSetPropBoolRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->SetPropBool(InMessage.PropBool);
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
	BackendService->SetPropInt(InMessage.PropInt);
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
	BackendService->SetPropFloat(InMessage.PropFloat);
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
	BackendService->SetPropString(InMessage.PropString);
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

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnSetPropEnumRequest(const FTestbed1StructArrayInterfaceSetPropEnumRequestMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& /*Context*/)
{
	BackendService->SetPropEnum(InMessage.PropEnum);
}

void UTestbed1StructArrayInterfaceMsgBusAdapter::OnPropEnumChanged(const TArray<ETestbed1Enum0>& InPropEnum)
{
	TArray<FMessageAddress> ConnectedClients;
	int32 NumberOfClients = ConnectedClientsTimestamps.GetKeys(ConnectedClients);

	auto msg = new FTestbed1StructArrayInterfacePropEnumChangedMessage();
	msg->PropEnum = InPropEnum;

	if (Testbed1StructArrayInterfaceMsgBusEndpoint.IsValid() && NumberOfClients > 0)
	{
		Testbed1StructArrayInterfaceMsgBusEndpoint->Send<FTestbed1StructArrayInterfacePropEnumChangedMessage>(msg, EMessageFlags::Reliable,
			nullptr,
			ConnectedClients,
			FTimespan::Zero(),
			FDateTime::MaxValue());
	}
}
