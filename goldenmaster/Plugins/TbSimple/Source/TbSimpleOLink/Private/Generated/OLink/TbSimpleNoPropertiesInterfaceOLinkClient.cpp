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

#include "Generated/OLink/TbSimpleNoPropertiesInterfaceOLinkClient.h"
#include "ApiGearSettings.h"
#include "ApiGearOLink.h"
#include "Async/Async.h"
#include "TbSimple/Generated/api/TbSimple.json.adapter.h"
#include "OLinkClientConnection.h"
#include "OLinkSink.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionsStore.h"
#include "Misc/DateTime.h"
#include "TbSimpleSettings.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END
DEFINE_LOG_CATEGORY(LogTbSimpleNoPropertiesInterfaceOLinkClient);

UTbSimpleNoPropertiesInterfaceOLinkClient::UTbSimpleNoPropertiesInterfaceOLinkClient()
	: UAbstractTbSimpleNoPropertiesInterface()
{
	m_sink = std::make_shared<FOLinkSink>("tb.simple.NoPropertiesInterface");
}

UTbSimpleNoPropertiesInterfaceOLinkClient::UTbSimpleNoPropertiesInterfaceOLinkClient(FVTableHelper& Helper)
	: Super(Helper)
{
}
UTbSimpleNoPropertiesInterfaceOLinkClient::~UTbSimpleNoPropertiesInterfaceOLinkClient() = default;

void UTbSimpleNoPropertiesInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
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
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	TScriptInterface<IApiGearConnection> OLinkConnection = AGCM->GetConnection(settings->OLinkConnectionIdentifier);

	if (!OLinkConnection.GetInterface())
	{
		UE_LOG(LogTbSimpleNoPropertiesInterfaceOLinkClient, Warning, TEXT("No valid olink connection for the %s client, please set in the ApiGear TbSimple plugin settings or during run time"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}
	UseConnection(OLinkConnection);
	OLinkConnection->Connect();
}

void UTbSimpleNoPropertiesInterfaceOLinkClient::Deinitialize()
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

void UTbSimpleNoPropertiesInterfaceOLinkClient::UseConnection(TScriptInterface<IApiGearConnection> InConnection)
{
	checkf(InConnection.GetInterface() != nullptr, TEXT("Cannot use connection - interface IApiGearConnection is not fully implemented"));

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

void UTbSimpleNoPropertiesInterfaceOLinkClient::FuncVoid_Implementation()
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleNoPropertiesInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return;
	}
	ApiGear::ObjectLink::InvokeReplyFunc GetNoPropertiesInterfaceStateFunc = [this](ApiGear::ObjectLink::InvokeReplyArg arg) {};
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcVoid");
	m_sink->GetNode()->invokeRemote(memberId, {}, GetNoPropertiesInterfaceStateFunc);
}

bool UTbSimpleNoPropertiesInterfaceOLinkClient::FuncBool_Implementation(bool bParamBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleNoPropertiesInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return false;
	}
	TPromise<bool> Promise;
	Async(EAsyncExecution::ThreadPool,
		[bParamBool, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetNoPropertiesInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			if (!arg.value.empty())
			{
				Promise.SetValue(arg.value.get<bool>());
			}
			else
			{
				UE_LOG(LogTbSimpleNoPropertiesInterfaceOLinkClient, Error, TEXT("FuncBool: OLink service returned empty value - should have returned type of bool"));
				Promise.SetValue(bool());
			}
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcBool");
		m_sink->GetNode()->invokeRemote(memberId, {bParamBool}, GetNoPropertiesInterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

bool UTbSimpleNoPropertiesInterfaceOLinkClient::_IsSubscribed() const
{
	return m_sink->IsReady();
}

void UTbSimpleNoPropertiesInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
}

void UTbSimpleNoPropertiesInterfaceOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "sigVoid")
	{
		Execute__GetSignals(this)->OnSigVoidSignal.Broadcast();
		return;
	}

	if (signalName == "sigBool")
	{
		bool boutParamBool = args[0].get<bool>();
		Execute__GetSignals(this)->OnSigBoolSignal.Broadcast(boutParamBool);
		return;
	}
}