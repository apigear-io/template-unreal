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

#include "Generated/OLink/TbNamesNamEsOLinkClient.h"
#include "ApiGearSettings.h"
#include "ApiGearOLink.h"
#include "Async/Async.h"
#include "TbNames/Generated/api/TbNames.json.adapter.h"
#include "OLinkClientConnection.h"
#include "OLinkSink.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionsStore.h"
#include "Misc/DateTime.h"
#include "TbNamesSettings.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END
#include <atomic>

/**
   \brief data structure to hold the last sent property values
*/
struct TbNamesNamEsPropertiesData
{
	std::atomic<bool> bSwitch{false};
	std::atomic<int32> SomeProperty{0};
	std::atomic<int32> SomePoperty2{0};
};
DEFINE_LOG_CATEGORY(LogTbNamesNamEsOLinkClient);

UTbNamesNamEsOLinkClient::UTbNamesNamEsOLinkClient()
	: UAbstractTbNamesNamEs()
	, _SentData(MakePimpl<TbNamesNamEsPropertiesData>())
{
	m_sink = std::make_shared<FOLinkSink>("tb.names.Nam_Es");
}

UTbNamesNamEsOLinkClient::UTbNamesNamEsOLinkClient(FVTableHelper& Helper)
	: Super(Helper)
{
}
UTbNamesNamEsOLinkClient::~UTbNamesNamEsOLinkClient() = default;

void UTbNamesNamEsOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	m_sink->setOnInitCallback([this]()
		{
		_SubscriptionStatusChanged.Broadcast(true);
	});
	m_sink->setOnReleaseCallback([this]()
		{
		_SubscriptionStatusChanged.Broadcast(false);
	});

	FOLinkSink::FPropertyChangedFunc PropertyChangedFunc = [this](const nlohmann::json& props)
	{
		this->applyState(props);
	};
	m_sink->setOnPropertyChangedCallback(PropertyChangedFunc);

	FOLinkSink::FSignalEmittedFunc SignalEmittedFunc = [this](const std::string& signalName, const nlohmann::json& args)
	{
		this->emitSignal(signalName, args);
	};
	m_sink->setOnSignalEmittedCallback(SignalEmittedFunc);

	check(GEngine);
	UTbNamesSettings* settings = GetMutableDefault<UTbNamesSettings>();

	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	TScriptInterface<IApiGearConnection> OLinkConnection = AGCM->GetConnection(settings->OLinkConnectionIdentifier);

	if (!OLinkConnection.GetInterface())
	{
		return;
	}
	UseConnection(OLinkConnection);
	OLinkConnection->Connect();
}

void UTbNamesNamEsOLinkClient::Deinitialize()
{
	// tell the sink that we are gone and should not try to be invoked
	m_sink->resetOnPropertyChangedCallback();
	m_sink->resetOnSignalEmittedCallback();
	m_sink->resetOnInitCallback();
	m_sink->resetOnReleaseCallback();

	if (Connection.GetObject())
	{
		UOLinkClientConnection* UnrealOLinkConnection = Cast<UOLinkClientConnection>(Connection.GetObject());
		UnrealOLinkConnection->unlinkObjectSource(m_sink->olinkObjectName());
		UnrealOLinkConnection->node()->registry().removeSink(m_sink->olinkObjectName());
	}

	Super::Deinitialize();
}

void UTbNamesNamEsOLinkClient::UseConnection(TScriptInterface<IApiGearConnection> InConnection)
{
	if (!InConnection.GetInterface())
	{
		UE_LOG(LogTbNamesNamEsOLinkClient, Error, TEXT("The olink connection for the %s client does not implement the connection interface."), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only accept connections of type olink
	checkf(InConnection->GetConnectionProtocolIdentifier() == ApiGearOLinkProtocolIdentifier, TEXT("Cannot use connection - must be of type olink"));

	UOLinkClientConnection* UnrealOLinkConnection = nullptr;
	// remove old connection
	if (Connection.GetObject())
	{
		UnrealOLinkConnection = Cast<UOLinkClientConnection>(Connection.GetObject());
		UnrealOLinkConnection->unlinkObjectSource(m_sink->olinkObjectName());
		UnrealOLinkConnection->node()->registry().removeSink(m_sink->olinkObjectName());
		UnrealOLinkConnection = nullptr;
	}

	// set up new connection
	UnrealOLinkConnection = Cast<UOLinkClientConnection>(InConnection.GetObject());
	UnrealOLinkConnection->node()->registry().addSink(m_sink);
	UnrealOLinkConnection->linkObjectSource(m_sink->olinkObjectName());

	Connection = InConnection;
}

bool UTbNamesNamEsOLinkClient::GetSwitch_Implementation() const
{
	return bSwitch;
}

void UTbNamesNamEsOLinkClient::SetSwitch_Implementation(bool bInSwitch)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbNamesNamEsOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbNames plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetSwitch_Implementation() == bInSwitch)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->bSwitch == bInSwitch)
	{
		return;
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "Switch");
	m_sink->GetNode()->setRemoteProperty(memberId, bInSwitch);
	_SentData->bSwitch = bInSwitch;
}

int32 UTbNamesNamEsOLinkClient::GetSomeProperty_Implementation() const
{
	return SomeProperty;
}

void UTbNamesNamEsOLinkClient::SetSomeProperty_Implementation(int32 InSomeProperty)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbNamesNamEsOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbNames plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetSomeProperty_Implementation() == InSomeProperty)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->SomeProperty == InSomeProperty)
	{
		return;
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "SOME_PROPERTY");
	m_sink->GetNode()->setRemoteProperty(memberId, InSomeProperty);
	_SentData->SomeProperty = InSomeProperty;
}

int32 UTbNamesNamEsOLinkClient::GetSomePoperty2_Implementation() const
{
	return SomePoperty2;
}

void UTbNamesNamEsOLinkClient::SetSomePoperty2_Implementation(int32 InSomePoperty2)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbNamesNamEsOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbNames plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetSomePoperty2_Implementation() == InSomePoperty2)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->SomePoperty2 == InSomePoperty2)
	{
		return;
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "Some_Poperty2");
	m_sink->GetNode()->setRemoteProperty(memberId, InSomePoperty2);
	_SentData->SomePoperty2 = InSomePoperty2;
}

void UTbNamesNamEsOLinkClient::SomeFunction_Implementation(bool bSomeParam)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbNamesNamEsOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbNames plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return;
	}
	ApiGear::ObjectLink::InvokeReplyFunc GetNamEsStateFunc = [this](ApiGear::ObjectLink::InvokeReplyArg arg) {};
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "SOME_FUNCTION");
	m_sink->GetNode()->invokeRemote(memberId, {bSomeParam}, GetNamEsStateFunc);
}

void UTbNamesNamEsOLinkClient::SomeFunction2_Implementation(bool bSomeParam)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbNamesNamEsOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbNames plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return;
	}
	ApiGear::ObjectLink::InvokeReplyFunc GetNamEsStateFunc = [this](ApiGear::ObjectLink::InvokeReplyArg arg) {};
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "Some_Function2");
	m_sink->GetNode()->invokeRemote(memberId, {bSomeParam}, GetNamEsStateFunc);
}

bool UTbNamesNamEsOLinkClient::_IsSubscribed() const
{
	return m_sink->IsReady();
}

void UTbNamesNamEsOLinkClient::applyState(const nlohmann::json& fields)
{
	const bool bSwitchChanged = fields.contains("Switch") && (bSwitch != fields["Switch"].get<bool>());
	if (bSwitchChanged)
	{
		bSwitch = fields["Switch"].get<bool>();
		Execute__GetSignals(this)->OnSwitchChanged.Broadcast(bSwitch);
	}

	const bool bSomePropertyChanged = fields.contains("SOME_PROPERTY") && (SomeProperty != fields["SOME_PROPERTY"].get<int32>());
	if (bSomePropertyChanged)
	{
		SomeProperty = fields["SOME_PROPERTY"].get<int32>();
		Execute__GetSignals(this)->OnSomePropertyChanged.Broadcast(SomeProperty);
	}

	const bool bSomePoperty2Changed = fields.contains("Some_Poperty2") && (SomePoperty2 != fields["Some_Poperty2"].get<int32>());
	if (bSomePoperty2Changed)
	{
		SomePoperty2 = fields["Some_Poperty2"].get<int32>();
		Execute__GetSignals(this)->OnSomePoperty2Changed.Broadcast(SomePoperty2);
	}
}

void UTbNamesNamEsOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "SOME_SIGNAL")
	{
		bool boutSomeParam = args[0].get<bool>();
		Execute__GetSignals(this)->OnSomeSignalSignal.Broadcast(boutSomeParam);
		return;
	}

	if (signalName == "Some_Signal2")
	{
		bool boutSomeParam = args[0].get<bool>();
		Execute__GetSignals(this)->OnSomeSignal2Signal.Broadcast(boutSomeParam);
		return;
	}
}
