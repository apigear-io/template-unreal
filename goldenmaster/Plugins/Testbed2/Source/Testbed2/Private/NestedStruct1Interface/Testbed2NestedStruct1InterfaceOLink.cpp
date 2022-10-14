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

#include "Testbed2NestedStruct1InterfaceOLink.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "apig/Testbed2.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;

namespace Testbed2
{
namespace NestedStruct1Interface
{
namespace Private
{
OLinkService::OLinkService()
	: ITestbed2NestedStruct1InterfaceInterface()
	, m_node(nullptr)
	, m_isReady(false)
	, Prop1(FTestbed2NestedStruct1())
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->Connect();
		AGCM->GetOLinkConnection()->linkObjectSource(olinkObjectName());
	}
	m_node = ClientRegistry::get().addObjectSink(this);
}

OLinkService::~OLinkService()
{
	ClientRegistry::get().removeObjectSink(this);
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->unlinkObjectSource(olinkObjectName());
	}
	m_isReady = false;
	m_node = nullptr;
}

FTestbed2NestedStruct1InterfaceSig1Delegate& OLinkService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

FTestbed2NestedStruct1 OLinkService::GetProp1_Implementation() const
{
	return Prop1;
}

void OLinkService::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed2.NestedStruct1Interface/prop1", InProp1);
}

FTestbed2NestedStruct1InterfaceProp1ChangedDelegate& OLinkService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

FTestbed2NestedStruct1 OLinkService::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return FTestbed2NestedStruct1();
	}
	TPromise<FTestbed2NestedStruct1> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			InvokeReplyFunc GetNestedStruct1InterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FTestbed2NestedStruct1>()); };
			m_node->invokeRemote("testbed2.NestedStruct1Interface/func1", {Param1}, GetNestedStruct1InterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void OLinkService::applyState(const nlohmann::json& fields)
{
	if (fields.contains("prop1"))
	{
		if (Prop1 != fields["prop1"].get<FTestbed2NestedStruct1>())
		{
			Prop1 = fields["prop1"].get<FTestbed2NestedStruct1>();
			Prop1Changed.Broadcast(Prop1);
		}
	}
}

std::string OLinkService::olinkObjectName()
{
	return "testbed2.NestedStruct1Interface";
}

void OLinkService::olinkOnSignal(std::string name, nlohmann::json args)
{
	std::string path = Name::pathFromName(name);
	if (path == "sig1")
	{
		Sig1Signal.Broadcast(args[0].get<FTestbed2NestedStruct1>());
		return;
	}
}

void OLinkService::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
	std::string path = Name::pathFromName(name);
	applyState({{path, value}});
}

void OLinkService::olinkOnInit(std::string name, nlohmann::json props, IClientNode* node)
{
	m_isReady = true;
	m_node = node;
	applyState(props);
	// call isReady();
}

void OLinkService::olinkOnRelease()
{
	m_isReady = false;
	m_node = nullptr;
}

} // namespace Private
} // namespace NestedStruct1Interface
} // namespace Testbed2
