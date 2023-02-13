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
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/Testbed2.json.adapter.h"
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

UTestbed2ManyParamInterfaceOLinkClient::UTestbed2ManyParamInterfaceOLinkClient()
	: UAbstractTestbed2ManyParamInterface()
{
	m_sink = std::make_shared<FUnrealOLinkSink>("testbed2.ManyParamInterface");
}

void UTestbed2ManyParamInterfaceOLinkClient::Initialize(FSubsystemCollectionBase& Collection)
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

void UTestbed2ManyParamInterfaceOLinkClient::Deinitialize()
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

int32 UTestbed2ManyParamInterfaceOLinkClient::GetProp1_Implementation() const
{
	return Prop1;
}

void UTestbed2ManyParamInterfaceOLinkClient::SetProp1_Implementation(int32 InProp1)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop1"), InProp1);
}

int32 UTestbed2ManyParamInterfaceOLinkClient::GetProp2_Implementation() const
{
	return Prop2;
}

void UTestbed2ManyParamInterfaceOLinkClient::SetProp2_Implementation(int32 InProp2)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop2"), InProp2);
}

int32 UTestbed2ManyParamInterfaceOLinkClient::GetProp3_Implementation() const
{
	return Prop3;
}

void UTestbed2ManyParamInterfaceOLinkClient::SetProp3_Implementation(int32 InProp3)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop3"), InProp3);
}

int32 UTestbed2ManyParamInterfaceOLinkClient::GetProp4_Implementation() const
{
	return Prop4;
}

void UTestbed2ManyParamInterfaceOLinkClient::SetProp4_Implementation(int32 InProp4)
{
	if (!m_sink->IsReady())
	{
		return;
	}
	m_sink->GetNode()->setRemoteProperty(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "prop4"), InProp4);
}

int32 UTestbed2ManyParamInterfaceOLinkClient::Func1_Implementation(int32 Param1)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetManyParamInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<int32>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func1"), {Param1}, GetManyParamInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

int32 UTestbed2ManyParamInterfaceOLinkClient::Func2_Implementation(int32 Param1, int32 Param2)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetManyParamInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<int32>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func2"), {Param1, Param2}, GetManyParamInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

int32 UTestbed2ManyParamInterfaceOLinkClient::Func3_Implementation(int32 Param1, int32 Param2, int32 Param3)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, Param3, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetManyParamInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<int32>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func3"), {Param1, Param2, Param3}, GetManyParamInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

int32 UTestbed2ManyParamInterfaceOLinkClient::Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	if (!m_sink->IsReady())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(m_sink->olinkObjectName().c_str()));
		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, Param3, Param4, &Promise, this]()
		{
			ApiGear::ObjectLink::InvokeReplyFunc GetManyParamInterfaceStateFunc = [&Promise](ApiGear::ObjectLink::InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<int32>()); };
			m_sink->GetNode()->invokeRemote(ApiGear::ObjectLink::Name::createMemberId(m_sink->olinkObjectName(), "func4"), {Param1, Param2, Param3, Param4}, GetManyParamInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTestbed2ManyParamInterfaceOLinkClient::applyState(const nlohmann::json& fields)
{
	if (fields.contains("prop1"))
	{
		if (Prop1 != fields["prop1"].get<int32>())
		{
			Prop1 = fields["prop1"].get<int32>();
			Execute_BroadcastProp1Changed(this, Prop1);
		}
	}
	if (fields.contains("prop2"))
	{
		if (Prop2 != fields["prop2"].get<int32>())
		{
			Prop2 = fields["prop2"].get<int32>();
			Execute_BroadcastProp2Changed(this, Prop2);
		}
	}
	if (fields.contains("prop3"))
	{
		if (Prop3 != fields["prop3"].get<int32>())
		{
			Prop3 = fields["prop3"].get<int32>();
			Execute_BroadcastProp3Changed(this, Prop3);
		}
	}
	if (fields.contains("prop4"))
	{
		if (Prop4 != fields["prop4"].get<int32>())
		{
			Prop4 = fields["prop4"].get<int32>();
			Execute_BroadcastProp4Changed(this, Prop4);
		}
	}
}

void UTestbed2ManyParamInterfaceOLinkClient::emitSignal(const std::string& signalName, const nlohmann::json& args)
{
	if (signalName == "sig1")
	{
		Execute_BroadcastSig1(this, args[0].get<int32>());
		return;
	}
	if (signalName == "sig2")
	{
		Execute_BroadcastSig2(this, args[0].get<int32>(), args[1].get<int32>());
		return;
	}
	if (signalName == "sig3")
	{
		Execute_BroadcastSig3(this, args[0].get<int32>(), args[1].get<int32>(), args[2].get<int32>());
		return;
	}
	if (signalName == "sig4")
	{
		Execute_BroadcastSig4(this, args[0].get<int32>(), args[1].get<int32>(), args[2].get<int32>(), args[3].get<int32>());
		return;
	}
}
