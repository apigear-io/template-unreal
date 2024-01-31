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

#include "Generated/OLink/Testbed2ManyParamInterfaceOLinkClient.h"
#include "ApiGearSettings.h"
#include "apigearolink.h"
#include "Async/Async.h"
#include "Generated/api/Testbed2.json.adapter.h"
#include "unrealolink.h"
#include "unrealolinksink.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionsStore.h"
#include "Misc/DateTime.h"
#include "Testbed2Settings.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
#include "olink/iobjectsink.h"
THIRD_PARTY_INCLUDES_END
#include <atomic>

/**
   \brief data structure to hold the last sent property values
*/
struct Testbed2ManyParamInterfacePropertiesData
{
	std::atomic<int32> Prop1{0};
	std::atomic<int32> Prop2{0};
	std::atomic<int32> Prop3{0};
	std::atomic<int32> Prop4{0};
};
DEFINE_LOG_CATEGORY(LogTestbed2ManyParamInterfaceOLinkClient);

UTestbed2ManyParamInterfaceOLinkClient::UTestbed2ManyParamInterfaceOLinkClient()
	: UAbstractTestbed2ManyParamInterface()
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	, _SentData(MakeUnique<Testbed2ManyParamInterfacePropertiesData>())
#else
	, _SentData(MakePimpl<Testbed2ManyParamInterfacePropertiesData>())
#endif
{
	m_sink = std::make_shared<FUnrealOLinkSink>("testbed2.ManyParamInterface");
}

UTestbed2ManyParamInterfaceOLinkClient::UTestbed2ManyParamInterfaceOLinkClient(FVTableHelper& Helper)
	: Super(Helper)
{
}
UTestbed2ManyParamInterfaceOLinkClient::~UTestbed2ManyParamInterfaceOLinkClient() = default;

void UTestbed2ManyParamInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	m_sink->setOnInitCallback([this]()
		{ _SubscriptionStatusChanged.Broadcast(true); });
	m_sink->setOnReleaseCallback([this]()
		{ _SubscriptionStatusChanged.Broadcast(false); });

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
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	TScriptInterface<IApiGearConnection> OLinkConnection = AGCM->GetConnection(settings->OLinkConnectionIdentifier);

	if (!OLinkConnection.GetInterface())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceOLinkClient, Warning, TEXT("No valid olink connection for the %s client, please set in the ApiGear Testbed2 plugin settings or during run time"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}
	UseConnection(OLinkConnection);
	OLinkConnection->Connect();
}

void UTestbed2ManyParamInterfaceOLinkClient::Deinitialize()
{
	// tell the sink that we are gone and should not try to be invoked
	m_sink->resetOnPropertyChangedCallback();
	m_sink->resetOnSignalEmittedCallback();
	m_sink->resetOnInitCallback();
	m_sink->resetOnReleaseCallback();

	if (Connection.GetObject())
	{
		UUnrealOLink* UnrealOLinkConnection = Cast<UUnrealOLink>(Connection.GetObject());
		UnrealOLinkConnection->unlinkObjectSource(m_sink->olinkObjectName());
		UnrealOLinkConnection->node()->registry().removeSink(m_sink->olinkObjectName());
	}

	Super::Deinitialize();
}

void UTestbed2ManyParamInterfaceOLinkClient::UseConnection(TScriptInterface<IApiGearConnection> InConnection)
{
	checkf(InConnection.GetInterface() != nullptr, TEXT("Cannot use connection - interface IApiGearConnection is not fully implemented"));

	// only accept connections of type olink
	checkf(InConnection->GetConnectionProtocolIdentifier() == ApiGearOLinkProtocolIdentifier, TEXT("Cannot use connection - must be of type olink"));

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

int32 UTestbed2ManyParamInterfaceOLinkClient::GetProp1_Implementation() const
{
	return Prop1;
}

void UTestbed2ManyParamInterfaceOLinkClient::SetProp1_Implementation(int32 InProp1)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp1_Implementation() == InProp1)
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

int32 UTestbed2ManyParamInterfaceOLinkClient::GetProp2_Implementation() const
{
	return Prop2;
}

void UTestbed2ManyParamInterfaceOLinkClient::SetProp2_Implementation(int32 InProp2)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp2_Implementation() == InProp2)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop2 == InProp2)
	{
		return;
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop2");
	m_sink->GetNode()->setRemoteProperty(memberId, InProp2);
	_SentData->Prop2 = InProp2;
}

int32 UTestbed2ManyParamInterfaceOLinkClient::GetProp3_Implementation() const
{
	return Prop3;
}

void UTestbed2ManyParamInterfaceOLinkClient::SetProp3_Implementation(int32 InProp3)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp3_Implementation() == InProp3)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop3 == InProp3)
	{
		return;
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop3");
	m_sink->GetNode()->setRemoteProperty(memberId, InProp3);
	_SentData->Prop3 = InProp3;
}

int32 UTestbed2ManyParamInterfaceOLinkClient::GetProp4_Implementation() const
{
	return Prop4;
}

void UTestbed2ManyParamInterfaceOLinkClient::SetProp4_Implementation(int32 InProp4)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return;
	}

	// only send change requests if the value changed -> reduce network load
	if (GetProp4_Implementation() == InProp4)
	{
		return;
	}

	// only send change requests if the value wasn't already sent -> reduce network load
	if (_SentData->Prop4 == InProp4)
	{
		return;
	}
	static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop4");
	m_sink->GetNode()->setRemoteProperty(memberId, InProp4);
	_SentData->Prop4 = InProp4;
}

int32 UTestbed2ManyParamInterfaceOLinkClient::Func1_Implementation(int32 Param1)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetManyParamInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{
				if (!arg.value.empty())
				{
					Promise.SetValue(arg.value.get<int32>());
				}
				else
				{
					UE_LOG(LogTestbed2ManyParamInterfaceOLinkClient, Error, TEXT("Func1: OLink service returned empty value - should have returned type of int32"));
					Promise.SetValue(int32());
				}
			};
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func1");
			m_sink->GetNode()->invokeRemote(memberId, {Param1}, GetManyParamInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

int32 UTestbed2ManyParamInterfaceOLinkClient::Func2_Implementation(int32 Param1, int32 Param2)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetManyParamInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{
				if (!arg.value.empty())
				{
					Promise.SetValue(arg.value.get<int32>());
				}
				else
				{
					UE_LOG(LogTestbed2ManyParamInterfaceOLinkClient, Error, TEXT("Func2: OLink service returned empty value - should have returned type of int32"));
					Promise.SetValue(int32());
				}
			};
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func2");
			m_sink->GetNode()->invokeRemote(memberId, {Param1, Param2}, GetManyParamInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

int32 UTestbed2ManyParamInterfaceOLinkClient::Func3_Implementation(int32 Param1, int32 Param2, int32 Param3)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, Param3, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetManyParamInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{
				if (!arg.value.empty())
				{
					Promise.SetValue(arg.value.get<int32>());
				}
				else
				{
					UE_LOG(LogTestbed2ManyParamInterfaceOLinkClient, Error, TEXT("Func3: OLink service returned empty value - should have returned type of int32"));
					Promise.SetValue(int32());
				}
			};
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func3");
			m_sink->GetNode()->invokeRemote(memberId, {Param1, Param2, Param3}, GetManyParamInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

int32 UTestbed2ManyParamInterfaceOLinkClient::Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTestbed2ManyParamInterfaceOLinkClient, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));

		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, Param3, Param4, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetManyParamInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{
				if (!arg.value.empty())
				{
					Promise.SetValue(arg.value.get<int32>());
				}
				else
				{
					UE_LOG(LogTestbed2ManyParamInterfaceOLinkClient, Error, TEXT("Func4: OLink service returned empty value - should have returned type of int32"));
					Promise.SetValue(int32());
				}
			};
			static const auto memberId = ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func4");
			m_sink->GetNode()->invokeRemote(memberId, {Param1, Param2, Param3, Param4}, GetManyParamInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

bool UTestbed2ManyParamInterfaceOLinkClient::_IsSubscribed() const
{
	return m_sink->IsReady();
}

void UTestbed2ManyParamInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	const bool bProp1Changed = fields.contains("prop1") && (Prop1 != fields["prop1"].get<int32>());
	if (bProp1Changed)
	{
		Prop1 = fields["prop1"].get<int32>();
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}

	const bool bProp2Changed = fields.contains("prop2") && (Prop2 != fields["prop2"].get<int32>());
	if (bProp2Changed)
	{
		Prop2 = fields["prop2"].get<int32>();
		Execute__GetSignals(this)->OnProp2Changed.Broadcast(Prop2);
	}

	const bool bProp3Changed = fields.contains("prop3") && (Prop3 != fields["prop3"].get<int32>());
	if (bProp3Changed)
	{
		Prop3 = fields["prop3"].get<int32>();
		Execute__GetSignals(this)->OnProp3Changed.Broadcast(Prop3);
	}

	const bool bProp4Changed = fields.contains("prop4") && (Prop4 != fields["prop4"].get<int32>());
	if (bProp4Changed)
	{
		Prop4 = fields["prop4"].get<int32>();
		Execute__GetSignals(this)->OnProp4Changed.Broadcast(Prop4);
	}
}

void UTestbed2ManyParamInterfaceOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "sig1")
	{
		int32 Param1 = args[0].get<int32>();
		Execute__GetSignals(this)->OnSig1Signal.Broadcast(Param1);
		return;
	}

	if (signalName == "sig2")
	{
		int32 Param1 = args[0].get<int32>();
		int32 Param2 = args[1].get<int32>();
		Execute__GetSignals(this)->OnSig2Signal.Broadcast(Param1, Param2);
		return;
	}

	if (signalName == "sig3")
	{
		int32 Param1 = args[0].get<int32>();
		int32 Param2 = args[1].get<int32>();
		int32 Param3 = args[2].get<int32>();
		Execute__GetSignals(this)->OnSig3Signal.Broadcast(Param1, Param2, Param3);
		return;
	}

	if (signalName == "sig4")
	{
		int32 Param1 = args[0].get<int32>();
		int32 Param2 = args[1].get<int32>();
		int32 Param3 = args[2].get<int32>();
		int32 Param4 = args[3].get<int32>();
		Execute__GetSignals(this)->OnSig4Signal.Broadcast(Param1, Param2, Param3, Param4);
		return;
	}
}
