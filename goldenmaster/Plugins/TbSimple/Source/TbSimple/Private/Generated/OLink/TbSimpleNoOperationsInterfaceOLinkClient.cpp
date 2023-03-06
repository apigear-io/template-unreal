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
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/TbSimple.json.adapter.h"
#include "unrealolink.h"
#include "unrealolinksink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END

UTbSimpleNoOperationsInterfaceOLinkClient::UTbSimpleNoOperationsInterfaceOLinkClient()
	: UAbstractTbSimpleNoOperationsInterface()
{
	m_sink = std::make_shared<FUnrealOLinkSink>("tb.simple.NoOperationsInterface");
}

void UTbSimpleNoOperationsInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->Connect();
		AGCM->GetOLinkConnection()->node()->registry().addSink(m_sink);
		AGCM->GetOLinkConnection()->linkObjectSource(m_sink->olinkObjectName());
	}

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
}

void UTbSimpleNoOperationsInterfaceOLinkClient::Deinitialize()
{
	// tell the sink that we are gone and should not try to be invoked
	m_sink->resetOnPropertyChangedCallback();
	m_sink->resetOnSignalEmittedCallback();

	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->unlinkObjectSource(m_sink->olinkObjectName());
		AGCM->GetOLinkConnection()->node()->registry().removeSink(m_sink->olinkObjectName());
	}

	Super::Deinitialize();
}

bool UTbSimpleNoOperationsInterfaceOLinkClient::GetPropBool_Implementation() const
{
	return bPropBool;
}

void UTbSimpleNoOperationsInterfaceOLinkClient::SetPropBool_Implementation(bool bInPropBool)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propBool"), bInPropBool);
}

int32 UTbSimpleNoOperationsInterfaceOLinkClient::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleNoOperationsInterfaceOLinkClient::SetPropInt_Implementation(int32 InPropInt)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propInt"), InPropInt);
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
		Execute_BroadcastSigBool(this, ParamBool);
		return;
	}
}
