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

#include "TbSimple/Generated/OLink/TbSimpleNoSignalsInterfaceOLinkClient.h"
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
#include <atomic>

/**
   \brief data structure to hold the last sent property values
*/
struct TbSimpleNoSignalsInterfacePropertiesData
{
	std::atomic<bool> bPropBool{false};
	std::atomic<int32> PropInt{0};
};
DEFINE_LOG_CATEGORY(LogTbSimpleNoSignalsInterfaceOLinkClient);

UTbSimpleNoSignalsInterfaceOLinkClient::UTbSimpleNoSignalsInterfaceOLinkClient()
	: UAbstractTbSimpleNoSignalsInterface()
	, _SentData(MakePimpl<TbSimpleNoSignalsInterfacePropertiesData>())
{
	m_sink = std::make_shared<FOLinkSink>("tb.simple.NoSignalsInterface");
}

UTbSimpleNoSignalsInterfaceOLinkClient::UTbSimpleNoSignalsInterfaceOLinkClient(FVTableHelper& Helper)
	: Super(Helper)
{
}
UTbSimpleNoSignalsInterfaceOLinkClient::~UTbSimpleNoSignalsInterfaceOLinkClient() = default;

void UTbSimpleNoSignalsInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
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
		return;
	}
	UseConnection(OLinkConnection);
	OLinkConnection->Connect();
}

void UTbSimpleNoSignalsInterfaceOLinkClient::Deinitialize()
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

void UTbSimpleNoSignalsInterfaceOLinkClient::UseConnection(TScriptInterface<IApiGearConnection> InConnection)
{
	if (!InConnection.GetInterface())
	{
		UE_LOG(LogTbSimpleNoSignalsInterfaceOLinkClient, Error, TEXT("The olink connection for the %s client does not implement the connection interface."), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
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

bool UTbSimpleNoSignalsInterfaceOLinkClient::GetPropBool() const
{
	return bPropBool;
}

void UTbSimpleNoSignalsInterfaceOLinkClient::SetPropBool(bool bInPropBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleNoSignalsInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropBool() == bInPropBool)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->bPropBool == bInPropBool)
	{
		return;
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propBool");
	m_sink->GetNode()->setRemoteProperty(memberId, bInPropBool);
	_SentData->bPropBool = bInPropBool;
}

int32 UTbSimpleNoSignalsInterfaceOLinkClient::GetPropInt() const
{
	return PropInt;
}

void UTbSimpleNoSignalsInterfaceOLinkClient::SetPropInt(int32 InPropInt)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleNoSignalsInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropInt() == InPropInt)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->PropInt == InPropInt)
	{
		return;
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propInt");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropInt);
	_SentData->PropInt = InPropInt;
}

void UTbSimpleNoSignalsInterfaceOLinkClient::FuncVoid()
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleNoSignalsInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return;
	}
	ApiGear::ObjectLink::InvokeReplyFunc GetNoSignalsInterfaceStateFunc = [this](ApiGear::ObjectLink::InvokeReplyArg arg) {};
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcVoid");
	m_sink->GetNode()->invokeRemote(memberId, {}, GetNoSignalsInterfaceStateFunc);
}

bool UTbSimpleNoSignalsInterfaceOLinkClient::FuncBool(bool bParamBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleNoSignalsInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSimple plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return false;
	}
	TPromise<bool> Promise;
	Async(EAsyncExecution::ThreadPool,
		[bParamBool, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetNoSignalsInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			if (!arg.value.empty())
			{
				Promise.SetValue(arg.value.get<bool>());
			}
			else
			{
				UE_LOG(LogTbSimpleNoSignalsInterfaceOLinkClient, Error, TEXT("FuncBool: OLink service returned empty value - should have returned type of bool"));
				Promise.SetValue(bool());
			}
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcBool");
		m_sink->GetNode()->invokeRemote(memberId, {bParamBool}, GetNoSignalsInterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

bool UTbSimpleNoSignalsInterfaceOLinkClient::_IsSubscribed() const
{
	return m_sink->IsReady();
}

void UTbSimpleNoSignalsInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	const bool bPropBoolChanged = fields.contains("propBool") && (bPropBool != fields["propBool"].get<bool>());
	if (bPropBoolChanged)
	{
		bPropBool = fields["propBool"].get<bool>();
		_GetSignals()->OnPropBoolChanged.Broadcast(bPropBool);
	}

	const bool bPropIntChanged = fields.contains("propInt") && (PropInt != fields["propInt"].get<int32>());
	if (bPropIntChanged)
	{
		PropInt = fields["propInt"].get<int32>();
		_GetSignals()->OnPropIntChanged.Broadcast(PropInt);
	}
}

void UTbSimpleNoSignalsInterfaceOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
}
