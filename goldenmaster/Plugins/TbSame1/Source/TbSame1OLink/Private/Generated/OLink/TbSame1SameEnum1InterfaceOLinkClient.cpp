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

#include "TbSame1/Generated/OLink/TbSame1SameEnum1InterfaceOLinkClient.h"
#include "ApiGearSettings.h"
#include "ApiGearOLink.h"
#include "Async/Async.h"
#include "TbSame1/Generated/api/TbSame1.json.adapter.h"
#include "OLinkClientConnection.h"
#include "OLinkSink.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionsStore.h"
#include "Misc/DateTime.h"
#include "TbSame1Settings.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END
#include <atomic>

/**
   \brief data structure to hold the last sent property values
*/
struct TbSame1SameEnum1InterfacePropertiesData
{
	std::atomic<ETbSame1Enum1> Prop1{ETbSame1Enum1::TS1E1_VALUE1};
};
DEFINE_LOG_CATEGORY(LogTbSame1SameEnum1InterfaceOLinkClient);

UTbSame1SameEnum1InterfaceOLinkClient::UTbSame1SameEnum1InterfaceOLinkClient()
	: UAbstractTbSame1SameEnum1Interface()
	, _SentData(MakePimpl<TbSame1SameEnum1InterfacePropertiesData>())
{
	m_sink = std::make_shared<FOLinkSink>("tb.same1.SameEnum1Interface");
}

UTbSame1SameEnum1InterfaceOLinkClient::UTbSame1SameEnum1InterfaceOLinkClient(FVTableHelper& Helper)
	: Super(Helper)
{
}
UTbSame1SameEnum1InterfaceOLinkClient::~UTbSame1SameEnum1InterfaceOLinkClient() = default;

void UTbSame1SameEnum1InterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	m_sink->setOnInitCallback([this]()
		{
		_SubscriptionStatusChanged.Broadcast(true);
		_SubscriptionStatusChangedBP.Broadcast(true);
	});
	m_sink->setOnReleaseCallback([this]()
		{
		_SubscriptionStatusChanged.Broadcast(false);
		_SubscriptionStatusChangedBP.Broadcast(false);
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
	UTbSame1Settings* settings = GetMutableDefault<UTbSame1Settings>();

	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	TScriptInterface<IApiGearConnection> OLinkConnection = AGCM->GetConnection(settings->OLinkConnectionIdentifier);

	if (!OLinkConnection.GetInterface())
	{
		return;
	}
	UseConnection(OLinkConnection);
	OLinkConnection->Connect();
}

void UTbSame1SameEnum1InterfaceOLinkClient::Deinitialize()
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

void UTbSame1SameEnum1InterfaceOLinkClient::UseConnection(TScriptInterface<IApiGearConnection> InConnection)
{
	if (!InConnection.GetInterface())
	{
		UE_LOG(LogTbSame1SameEnum1InterfaceOLinkClient, Error, TEXT("The olink connection for the %s client does not implement the connection interface."), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
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

ETbSame1Enum1 UTbSame1SameEnum1InterfaceOLinkClient::GetProp1() const
{
	return Prop1;
}

void UTbSame1SameEnum1InterfaceOLinkClient::SetProp1(ETbSame1Enum1 InProp1)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSame1SameEnum1InterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSame1 plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp1() == InProp1)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop1 == InProp1)
	{
		return;
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop1");
	m_sink->GetNode()->setRemoteProperty(memberId, InProp1);
	_SentData->Prop1 = InProp1;
}

ETbSame1Enum1 UTbSame1SameEnum1InterfaceOLinkClient::Func1(ETbSame1Enum1 Param1)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSame1SameEnum1InterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear TbSame1 plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return ETbSame1Enum1::TS1E1_VALUE1;
	}
	TPromise<ETbSame1Enum1> Promise;
	Async(EAsyncExecution::ThreadPool,
		[Param1, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetSameEnum1InterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			if (!arg.value.empty())
			{
				Promise.SetValue(arg.value.get<ETbSame1Enum1>());
			}
			else
			{
				UE_LOG(LogTbSame1SameEnum1InterfaceOLinkClient, Error, TEXT("Func1: OLink service returned empty value - should have returned type of ETbSame1Enum1"));
				Promise.SetValue(ETbSame1Enum1());
			}
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func1");
		m_sink->GetNode()->invokeRemote(memberId, {Param1}, GetSameEnum1InterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

bool UTbSame1SameEnum1InterfaceOLinkClient::_IsSubscribed() const
{
	return m_sink->IsReady();
}

void UTbSame1SameEnum1InterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	const bool bProp1Changed = fields.contains("prop1") && (Prop1 != fields["prop1"].get<ETbSame1Enum1>());
	if (bProp1Changed)
	{
		Prop1 = fields["prop1"].get<ETbSame1Enum1>();
		_GetSignals()->BroadcastProp1Changed(Prop1);
	}
}

void UTbSame1SameEnum1InterfaceOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "sig1")
	{
		ETbSame1Enum1 outParam1 = args[0].get<ETbSame1Enum1>();
		_GetSignals()->BroadcastSig1Signal(outParam1);
		return;
	}
}
