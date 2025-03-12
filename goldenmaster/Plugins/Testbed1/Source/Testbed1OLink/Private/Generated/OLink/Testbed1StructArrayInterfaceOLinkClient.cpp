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

#include "Testbed1/Generated/OLink/Testbed1StructArrayInterfaceOLinkClient.h"
#include "ApiGearSettings.h"
#include "ApiGearOLink.h"
#include "Async/Async.h"
#include "Testbed1/Generated/api/Testbed1.json.adapter.h"
#include "OLinkClientConnection.h"
#include "OLinkSink.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionsStore.h"
#include "Misc/DateTime.h"
#include "Testbed1Settings.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END
#include "HAL/CriticalSection.h"

/**
   \brief data structure to hold the last sent property values
*/
struct Testbed1StructArrayInterfacePropertiesData
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
DEFINE_LOG_CATEGORY(LogTestbed1StructArrayInterfaceOLinkClient);

UTestbed1StructArrayInterfaceOLinkClient::UTestbed1StructArrayInterfaceOLinkClient()
	: UAbstractTestbed1StructArrayInterface()
	, _SentData(MakePimpl<Testbed1StructArrayInterfacePropertiesData>())
{
	m_sink = std::make_shared<FOLinkSink>("testbed1.StructArrayInterface");
}

UTestbed1StructArrayInterfaceOLinkClient::UTestbed1StructArrayInterfaceOLinkClient(FVTableHelper& Helper)
	: Super(Helper)
{
}
UTestbed1StructArrayInterfaceOLinkClient::~UTestbed1StructArrayInterfaceOLinkClient() = default;

void UTestbed1StructArrayInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
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
	UTestbed1Settings* settings = GetMutableDefault<UTestbed1Settings>();

	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	TScriptInterface<IApiGearConnection> OLinkConnection = AGCM->GetConnection(settings->OLinkConnectionIdentifier);

	if (!OLinkConnection.GetInterface())
	{
		return;
	}
	UseConnection(OLinkConnection);
	OLinkConnection->Connect();
}

void UTestbed1StructArrayInterfaceOLinkClient::Deinitialize()
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

void UTestbed1StructArrayInterfaceOLinkClient::UseConnection(TScriptInterface<IApiGearConnection> InConnection)
{
	if (!InConnection.GetInterface())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Error, TEXT("The olink connection for the %s client does not implement the connection interface."), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
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

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceOLinkClient::GetPropBool() const
{
	return PropBool;
}

void UTestbed1StructArrayInterfaceOLinkClient::SetPropBool(const TArray<FTestbed1StructBool>& InPropBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear Testbed1 plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropBool() == InPropBool)
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
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propBool");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropBool);
	FScopeLock Lock(&(_SentData->PropBoolMutex));
	_SentData->PropBool = InPropBool;
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceOLinkClient::GetPropInt() const
{
	return PropInt;
}

void UTestbed1StructArrayInterfaceOLinkClient::SetPropInt(const TArray<FTestbed1StructInt>& InPropInt)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear Testbed1 plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropInt() == InPropInt)
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
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propInt");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropInt);
	FScopeLock Lock(&(_SentData->PropIntMutex));
	_SentData->PropInt = InPropInt;
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceOLinkClient::GetPropFloat() const
{
	return PropFloat;
}

void UTestbed1StructArrayInterfaceOLinkClient::SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear Testbed1 plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropFloat() == InPropFloat)
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
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propFloat");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropFloat);
	FScopeLock Lock(&(_SentData->PropFloatMutex));
	_SentData->PropFloat = InPropFloat;
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceOLinkClient::GetPropString() const
{
	return PropString;
}

void UTestbed1StructArrayInterfaceOLinkClient::SetPropString(const TArray<FTestbed1StructString>& InPropString)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear Testbed1 plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetPropString() == InPropString)
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
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "propString");
	m_sink->GetNode()->setRemoteProperty(memberId, InPropString);
	FScopeLock Lock(&(_SentData->PropStringMutex));
	_SentData->PropString = InPropString;
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceOLinkClient::FuncBool(const TArray<FTestbed1StructBool>& ParamBool)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear Testbed1 plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return TArray<FTestbed1StructBool>();
	}
	TPromise<TArray<FTestbed1StructBool>> Promise;
	Async(EAsyncExecution::ThreadPool,
		[ParamBool, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetStructArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			Promise.SetValue(arg.value.get<TArray<FTestbed1StructBool>>());
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcBool");
		m_sink->GetNode()->invokeRemote(memberId, {ParamBool}, GetStructArrayInterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceOLinkClient::FuncInt(const TArray<FTestbed1StructInt>& ParamInt)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear Testbed1 plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return TArray<FTestbed1StructInt>();
	}
	TPromise<TArray<FTestbed1StructInt>> Promise;
	Async(EAsyncExecution::ThreadPool,
		[ParamInt, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetStructArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			Promise.SetValue(arg.value.get<TArray<FTestbed1StructInt>>());
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcInt");
		m_sink->GetNode()->invokeRemote(memberId, {ParamInt}, GetStructArrayInterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceOLinkClient::FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear Testbed1 plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return TArray<FTestbed1StructFloat>();
	}
	TPromise<TArray<FTestbed1StructFloat>> Promise;
	Async(EAsyncExecution::ThreadPool,
		[ParamFloat, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetStructArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			Promise.SetValue(arg.value.get<TArray<FTestbed1StructFloat>>());
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcFloat");
		m_sink->GetNode()->invokeRemote(memberId, {ParamFloat}, GetStructArrayInterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceOLinkClient::FuncString(const TArray<FTestbed1StructString>& ParamString)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed1StructArrayInterfaceOLinkClient, Error, TEXT("%s has no node. Probably no valid connection or service. Are the ApiGear Testbed1 plugin settings correct? Service set up correctly?"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return TArray<FTestbed1StructString>();
	}
	TPromise<TArray<FTestbed1StructString>> Promise;
	Async(EAsyncExecution::ThreadPool,
		[ParamString, &Promise, this]()
		{
		ApiGear::ObjectLink::InvokeReplyFunc GetStructArrayInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
		{
			Promise.SetValue(arg.value.get<TArray<FTestbed1StructString>>());
		};
		static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "funcString");
		m_sink->GetNode()->invokeRemote(memberId, {ParamString}, GetStructArrayInterfaceStateFunc);
	});

	return Promise.GetFuture().Get();
}

bool UTestbed1StructArrayInterfaceOLinkClient::_IsSubscribed() const
{
	return m_sink->IsReady();
}

void UTestbed1StructArrayInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	const bool bPropBoolChanged = fields.contains("propBool") && (PropBool != fields["propBool"].get<TArray<FTestbed1StructBool>>());
	if (bPropBoolChanged)
	{
		PropBool = fields["propBool"].get<TArray<FTestbed1StructBool>>();
		_GetSignals()->BroadcastPropBoolChanged(PropBool);
	}

	const bool bPropIntChanged = fields.contains("propInt") && (PropInt != fields["propInt"].get<TArray<FTestbed1StructInt>>());
	if (bPropIntChanged)
	{
		PropInt = fields["propInt"].get<TArray<FTestbed1StructInt>>();
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}

	const bool bPropFloatChanged = fields.contains("propFloat") && (PropFloat != fields["propFloat"].get<TArray<FTestbed1StructFloat>>());
	if (bPropFloatChanged)
	{
		PropFloat = fields["propFloat"].get<TArray<FTestbed1StructFloat>>();
		_GetSignals()->BroadcastPropFloatChanged(PropFloat);
	}

	const bool bPropStringChanged = fields.contains("propString") && (PropString != fields["propString"].get<TArray<FTestbed1StructString>>());
	if (bPropStringChanged)
	{
		PropString = fields["propString"].get<TArray<FTestbed1StructString>>();
		_GetSignals()->BroadcastPropStringChanged(PropString);
	}
}

void UTestbed1StructArrayInterfaceOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "sigBool")
	{
		const TArray<FTestbed1StructBool>& outParamBool = args[0].get<TArray<FTestbed1StructBool>>();
		_GetSignals()->BroadcastSigBoolSignal(outParamBool);
		return;
	}

	if (signalName == "sigInt")
	{
		const TArray<FTestbed1StructInt>& outParamInt = args[0].get<TArray<FTestbed1StructInt>>();
		_GetSignals()->BroadcastSigIntSignal(outParamInt);
		return;
	}

	if (signalName == "sigFloat")
	{
		const TArray<FTestbed1StructFloat>& outParamFloat = args[0].get<TArray<FTestbed1StructFloat>>();
		_GetSignals()->BroadcastSigFloatSignal(outParamFloat);
		return;
	}

	if (signalName == "sigString")
	{
		const TArray<FTestbed1StructString>& outParamString = args[0].get<TArray<FTestbed1StructString>>();
		_GetSignals()->BroadcastSigStringSignal(outParamString);
		return;
	}
}
