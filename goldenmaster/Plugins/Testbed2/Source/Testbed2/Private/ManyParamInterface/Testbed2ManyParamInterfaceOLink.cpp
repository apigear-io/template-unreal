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

#include "Testbed2ManyParamInterfaceOLink.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "apig/Testbed2.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;
UTestbed2ManyParamInterfaceOLinkService::UTestbed2ManyParamInterfaceOLinkService()
	: ITestbed2ManyParamInterfaceInterface()
	, m_node(nullptr)
	, m_isReady(false)
{
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->Connect();
		AGCM->GetOLinkConnection()->linkObjectSource(olinkObjectName());
	}
	m_node = ClientRegistry::get().addObjectSink(this);
}

UTestbed2ManyParamInterfaceOLinkService::~UTestbed2ManyParamInterfaceOLinkService()
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

void UTestbed2ManyParamInterfaceOLinkService::BroadcastSig0_Implementation()
{
	Sig0Signal.Broadcast();
}

FTestbed2ManyParamInterfaceSig0Delegate& UTestbed2ManyParamInterfaceOLinkService::GetSig0SignalDelegate()
{
	return Sig0Signal;
}

void UTestbed2ManyParamInterfaceOLinkService::BroadcastSig1_Implementation(int32 Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTestbed2ManyParamInterfaceSig1Delegate& UTestbed2ManyParamInterfaceOLinkService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTestbed2ManyParamInterfaceOLinkService::BroadcastSig2_Implementation(int32 Param1, int32 Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
}

FTestbed2ManyParamInterfaceSig2Delegate& UTestbed2ManyParamInterfaceOLinkService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTestbed2ManyParamInterfaceOLinkService::BroadcastSig3_Implementation(int32 Param1, int32 Param2, int32 Param3)
{
	Sig3Signal.Broadcast(Param1, Param2, Param3);
}

FTestbed2ManyParamInterfaceSig3Delegate& UTestbed2ManyParamInterfaceOLinkService::GetSig3SignalDelegate()
{
	return Sig3Signal;
}

void UTestbed2ManyParamInterfaceOLinkService::BroadcastSig4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Sig4Signal.Broadcast(Param1, Param2, Param3, Param4);
}

FTestbed2ManyParamInterfaceSig4Delegate& UTestbed2ManyParamInterfaceOLinkService::GetSig4SignalDelegate()
{
	return Sig4Signal;
}

void UTestbed2ManyParamInterfaceOLinkService::BroadcastProp1Changed_Implementation(int32 InProp1)
{
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

int32 UTestbed2ManyParamInterfaceOLinkService::GetProp1_Implementation() const
{
	return Prop1;
}

void UTestbed2ManyParamInterfaceOLinkService::SetProp1_Implementation(int32 InProp1)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed2.ManyParamInterface/prop1", InProp1);
}

FTestbed2ManyParamInterfaceProp1ChangedDelegate& UTestbed2ManyParamInterfaceOLinkService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTestbed2ManyParamInterfaceOLinkService::BroadcastProp2Changed_Implementation(int32 InProp2)
{
	Prop2 = InProp2;
	Prop2Changed.Broadcast(InProp2);
}

int32 UTestbed2ManyParamInterfaceOLinkService::GetProp2_Implementation() const
{
	return Prop2;
}

void UTestbed2ManyParamInterfaceOLinkService::SetProp2_Implementation(int32 InProp2)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed2.ManyParamInterface/prop2", InProp2);
}

FTestbed2ManyParamInterfaceProp2ChangedDelegate& UTestbed2ManyParamInterfaceOLinkService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTestbed2ManyParamInterfaceOLinkService::BroadcastProp3Changed_Implementation(int32 InProp3)
{
	Prop3 = InProp3;
	Prop3Changed.Broadcast(InProp3);
}

int32 UTestbed2ManyParamInterfaceOLinkService::GetProp3_Implementation() const
{
	return Prop3;
}

void UTestbed2ManyParamInterfaceOLinkService::SetProp3_Implementation(int32 InProp3)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed2.ManyParamInterface/prop3", InProp3);
}

FTestbed2ManyParamInterfaceProp3ChangedDelegate& UTestbed2ManyParamInterfaceOLinkService::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}

void UTestbed2ManyParamInterfaceOLinkService::BroadcastProp4Changed_Implementation(int32 InProp4)
{
	Prop4 = InProp4;
	Prop4Changed.Broadcast(InProp4);
}

int32 UTestbed2ManyParamInterfaceOLinkService::GetProp4_Implementation() const
{
	return Prop4;
}

void UTestbed2ManyParamInterfaceOLinkService::SetProp4_Implementation(int32 InProp4)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("testbed2.ManyParamInterface/prop4", InProp4);
}

FTestbed2ManyParamInterfaceProp4ChangedDelegate& UTestbed2ManyParamInterfaceOLinkService::GetProp4ChangedDelegate()
{
	return Prop4Changed;
}

void UTestbed2ManyParamInterfaceOLinkService::Func0_Implementation()
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return;
	}
	InvokeReplyFunc GetManyParamInterfaceStateFunc = [this](InvokeReplyArg arg) {};
	m_node->invokeRemote("testbed2.ManyParamInterface/func0", {}, GetManyParamInterfaceStateFunc);
}

int32 UTestbed2ManyParamInterfaceOLinkService::Func1_Implementation(int32 Param1)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, &Promise, this]()
		{
			InvokeReplyFunc GetManyParamInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<int32>()); };
			m_node->invokeRemote("testbed2.ManyParamInterface/func1", {Param1}, GetManyParamInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

int32 UTestbed2ManyParamInterfaceOLinkService::Func2_Implementation(int32 Param1, int32 Param2)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, &Promise, this]()
		{
			InvokeReplyFunc GetManyParamInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<int32>()); };
			m_node->invokeRemote("testbed2.ManyParamInterface/func2", {Param1, Param2}, GetManyParamInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

int32 UTestbed2ManyParamInterfaceOLinkService::Func3_Implementation(int32 Param1, int32 Param2, int32 Param3)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, Param3, &Promise, this]()
		{
			InvokeReplyFunc GetManyParamInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<int32>()); };
			m_node->invokeRemote("testbed2.ManyParamInterface/func3", {Param1, Param2, Param3}, GetManyParamInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

int32 UTestbed2ManyParamInterfaceOLinkService::Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[Param1, Param2, Param3, Param4, &Promise, this]()
		{
			InvokeReplyFunc GetManyParamInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<int32>()); };
			m_node->invokeRemote("testbed2.ManyParamInterface/func4", {Param1, Param2, Param3, Param4}, GetManyParamInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void UTestbed2ManyParamInterfaceOLinkService::Func5_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4, int32 Param5)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return;
	}
	InvokeReplyFunc GetManyParamInterfaceStateFunc = [this](InvokeReplyArg arg) {};
	m_node->invokeRemote("testbed2.ManyParamInterface/func5", {Param1, Param2, Param3, Param4, Param5}, GetManyParamInterfaceStateFunc);
}

void UTestbed2ManyParamInterfaceOLinkService::applyState(const nlohmann::json& fields)
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

std::string UTestbed2ManyParamInterfaceOLinkService::olinkObjectName()
{
	return "testbed2.ManyParamInterface";
}

void UTestbed2ManyParamInterfaceOLinkService::olinkOnSignal(std::string name, nlohmann::json args)
{
	std::string path = Name::pathFromName(name);
	if (path == "sig0")
	{
		Execute_BroadcastSig0(this);
		return;
	}
	if (path == "sig1")
	{
		Execute_BroadcastSig1(this, args[0].get<int32>());
		return;
	}
	if (path == "sig2")
	{
		Execute_BroadcastSig2(this, args[0].get<int32>(), args[1].get<int32>());
		return;
	}
	if (path == "sig3")
	{
		Execute_BroadcastSig3(this, args[0].get<int32>(), args[1].get<int32>(), args[2].get<int32>());
		return;
	}
	if (path == "sig4")
	{
		Execute_BroadcastSig4(this, args[0].get<int32>(), args[1].get<int32>(), args[2].get<int32>(), args[3].get<int32>());
		return;
	}
}

void UTestbed2ManyParamInterfaceOLinkService::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
	std::string path = Name::pathFromName(name);
	applyState({{path, value}});
}

void UTestbed2ManyParamInterfaceOLinkService::olinkOnInit(std::string name, nlohmann::json props, IClientNode* node)
{
	m_isReady = true;
	m_node = node;
	applyState(props);
	// call isReady();
}

void UTestbed2ManyParamInterfaceOLinkService::olinkOnRelease()
{
	m_isReady = false;
	m_node = nullptr;
}
