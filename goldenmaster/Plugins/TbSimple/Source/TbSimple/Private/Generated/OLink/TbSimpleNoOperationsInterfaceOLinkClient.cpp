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

#include "Generated/OLink/TbSimpleNoOperationsInterfaceOLinkClient.h"
#include "ApiGearSettings.h"
#include "Async/Async.h"
#include "Generated/api/TbSimple.json.adapter.h"
#include "unrealolink.h"
#include "unrealolinksink.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"
#include "TbSimpleSettings.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END

/**
   \brief data structure to hold the last sent property values
*/
struct TbSimpleNoOperationsInterfacePropertiesData
{
	bool bPropBool{false};
	int32 PropInt{0};
};
DEFINE_LOG_CATEGORY(LogTbSimpleNoOperationsInterfaceOLinkClient);

UTbSimpleNoOperationsInterfaceOLinkClient::UTbSimpleNoOperationsInterfaceOLinkClient()
	: UAbstractTbSimpleNoOperationsInterface()
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	, _SentData(MakeUnique<TbSimpleNoOperationsInterfacePropertiesData>())
#else
	, _SentData(MakePimpl<TbSimpleNoOperationsInterfacePropertiesData>())
#endif
{
	m_sink = std::make_shared<FUnrealOLinkSink>("tb.simple.NoOperationsInterface");
}

UTbSimpleNoOperationsInterfaceOLinkClient::UTbSimpleNoOperationsInterfaceOLinkClient(FVTableHelper& Helper)
	: Super(Helper)
{
}
UTbSimpleNoOperationsInterfaceOLinkClient::~UTbSimpleNoOperationsInterfaceOLinkClient() = default;

void UTbSimpleNoOperationsInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FUnrealOLinkSink::FPropertyChangedFunc PropertyChangedFunc = [this](const nlohmann::json& props)
	{
		this->applyState(props);
	};
	m_sink->setOnPropertyChangedCallback(PropertyChangedFunc);

	FUnrealOLinkSink::FSignalEmittedFunc SignalEmittedFunc = [this](const std::string& signalName, const nlohmann::json& args)
	{
		this->emitSignal(signalName, args);
	};
	m_sink->setOnSignalEmittedCallback(SignalEmittedFunc);

	check(GEngine);
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();

	TScriptInterface<IApiGearConnection> OLinkConnection = AGCM->GetConnection(settings->ConnectionIdentifier);

	UseConnection(OLinkConnection);
	OLinkConnection->Connect();
}

void UTbSimpleNoOperationsInterfaceOLinkClient::Deinitialize()
{
	// tell the sink that we are gone and should not try to be invoked
	m_sink->resetOnPropertyChangedCallback();
	m_sink->resetOnSignalEmittedCallback();

	if (Connection.GetObject())
	{
		UUnrealOLink* UnrealOLinkConnection = Cast<UUnrealOLink>(Connection.GetObject());
		UnrealOLinkConnection->unlinkObjectSource(m_sink->olinkObjectName());
		UnrealOLinkConnection->node()->registry().removeSink(m_sink->olinkObjectName());
	}

	Super::Deinitialize();
}

void UTbSimpleNoOperationsInterfaceOLinkClient::UseConnection(TScriptInterface<IApiGearConnection> InConnection)
{
	checkf(InConnection.GetInterface() != nullptr, TEXT("Cannot use connection - interface IApiGearConnection is not fully implemented"));

	// only accept connections of type olink
	checkf(InConnection->GetConnectionProtocolIdentifier() == "olink", TEXT("Cannot use connection - must be of type olink"));

	UUnrealOLink* UnrealOLinkConnection = nullptr;
	// remove old connection
	if (Connection.GetObject())
	{
		UnrealOLinkConnection = Cast<UUnrealOLink>(Connection.GetObject());
		UnrealOLinkConnection->unlinkObjectSource(m_sink->olinkObjectName());
		UnrealOLinkConnection->node()->registry().removeSink(m_sink->olinkObjectName());
		UnrealOLinkConnection = nullptr;
	}

	// set up new connection
	UnrealOLinkConnection = Cast<UUnrealOLink>(InConnection.GetObject());
	UnrealOLinkConnection->node()->registry().addSink(m_sink);
	UnrealOLinkConnection->linkObjectSource(m_sink->olinkObjectName());

	Connection = InConnection;
}

bool UTbSimpleNoOperationsInterfaceOLinkClient::GetPropBool_Implementation() const
{
	return bPropBool;
}

void UTbSimpleNoOperationsInterfaceOLinkClient::SetPropBool_Implementation(bool bInPropBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleNoOperationsInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropBool_Implementation() == bInPropBool)
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

int32 UTbSimpleNoOperationsInterfaceOLinkClient::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleNoOperationsInterfaceOLinkClient::SetPropInt_Implementation(int32 InPropInt)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTbSimpleNoOperationsInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropInt_Implementation() == InPropInt)
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

void UTbSimpleNoOperationsInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	const bool bPropBoolChanged = fields.contains("propBool") && (bPropBool != fields["propBool"].get<bool>());
	if (bPropBoolChanged)
	{
		bPropBool = fields["propBool"].get<bool>();
		Execute_BroadcastPropBoolChanged(this, bPropBool);
	}

	const bool bPropIntChanged = fields.contains("propInt") && (PropInt != fields["propInt"].get<int32>());
	if (bPropIntChanged)
	{
		PropInt = fields["propInt"].get<int32>();
		Execute_BroadcastPropIntChanged(this, PropInt);
	}
}

void UTbSimpleNoOperationsInterfaceOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "sigVoid")
	{
		Execute_BroadcastSigVoid(this);
		return;
	}

	if (signalName == "sigBool")
	{
		bool bParamBool = args[0].get<bool>();
		Execute_BroadcastSigBool(this, bParamBool);
		return;
	}
}
