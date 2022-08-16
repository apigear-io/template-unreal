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

#include "TbSimpleSimpleInterfaceOLink.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "apig/TbSimple.json.adapter.h"
#include "unrealolink.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;

namespace TbSimple
{
namespace SimpleInterface
{
namespace Private
{
OLinkService::OLinkService()
	: ITbSimpleSimpleInterfaceInterface()
	, m_node(nullptr)
	, m_isReady(false)
	, bPropBool(false)
	, PropInt(0)
	, PropFloat(0.0f)
	, PropString(FString())
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

FTbSimpleSimpleInterfaceSigBoolDelegate& OLinkService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

FTbSimpleSimpleInterfaceSigIntDelegate& OLinkService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

FTbSimpleSimpleInterfaceSigFloatDelegate& OLinkService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

FTbSimpleSimpleInterfaceSigStringDelegate& OLinkService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

bool OLinkService::GetPropBool() const
{
	return bPropBool;
}

void OLinkService::SetPropBool(bool bInPropBool)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.simple.SimpleInterface/propBool", bInPropBool);
}

FTbSimpleSimpleInterfacePropBoolChangedDelegate& OLinkService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}
int32 OLinkService::GetPropInt() const
{
	return PropInt;
}

void OLinkService::SetPropInt(int32 InPropInt)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.simple.SimpleInterface/propInt", InPropInt);
}

FTbSimpleSimpleInterfacePropIntChangedDelegate& OLinkService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}
float OLinkService::GetPropFloat() const
{
	return PropFloat;
}

void OLinkService::SetPropFloat(float InPropFloat)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.simple.SimpleInterface/propFloat", InPropFloat);
}

FTbSimpleSimpleInterfacePropFloatChangedDelegate& OLinkService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}
FString OLinkService::GetPropString() const
{
	return PropString;
}

void OLinkService::SetPropString(const FString& InPropString)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.simple.SimpleInterface/propString", InPropString);
}

FTbSimpleSimpleInterfacePropStringChangedDelegate& OLinkService::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

bool OLinkService::FuncBool(bool bParamBool)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return false;
	}
	TPromise<bool> Promise;
	Async(EAsyncExecution::Thread,
		[bParamBool, &Promise, this]()
		{
			InvokeReplyFunc GetSimpleInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<bool>()); };
			m_node->invokeRemote("tb.simple.SimpleInterface/funcBool", {bParamBool}, GetSimpleInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

int32 OLinkService::FuncInt(int32 ParamInt)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return 0;
	}
	TPromise<int32> Promise;
	Async(EAsyncExecution::Thread,
		[ParamInt, &Promise, this]()
		{
			InvokeReplyFunc GetSimpleInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<int32>()); };
			m_node->invokeRemote("tb.simple.SimpleInterface/funcInt", {ParamInt}, GetSimpleInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

float OLinkService::FuncFloat(float ParamFloat)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return 0.0f;
	}
	TPromise<float> Promise;
	Async(EAsyncExecution::Thread,
		[ParamFloat, &Promise, this]()
		{
			InvokeReplyFunc GetSimpleInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<float>()); };
			m_node->invokeRemote("tb.simple.SimpleInterface/funcFloat", {ParamFloat}, GetSimpleInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

FString OLinkService::FuncString(const FString& ParamString)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return FString();
	}
	TPromise<FString> Promise;
	Async(EAsyncExecution::Thread,
		[ParamString, &Promise, this]()
		{
			InvokeReplyFunc GetSimpleInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<FString>()); };
			m_node->invokeRemote("tb.simple.SimpleInterface/funcString", {ParamString}, GetSimpleInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void OLinkService::applyState(const nlohmann::json& fields)
{
	if (fields.contains("propBool"))
	{
		if (bPropBool != fields["propBool"].get<bool>())
		{
			bPropBool = fields["propBool"].get<bool>();
			PropBoolChanged.Broadcast(bPropBool);
		}
	}
	if (fields.contains("propInt"))
	{
		if (PropInt != fields["propInt"].get<int32>())
		{
			PropInt = fields["propInt"].get<int32>();
			PropIntChanged.Broadcast(PropInt);
		}
	}
	if (fields.contains("propFloat"))
	{
		if (PropFloat != fields["propFloat"].get<float>())
		{
			PropFloat = fields["propFloat"].get<float>();
			PropFloatChanged.Broadcast(PropFloat);
		}
	}
	if (fields.contains("propString"))
	{
		if (PropString != fields["propString"].get<FString>())
		{
			PropString = fields["propString"].get<FString>();
			PropStringChanged.Broadcast(PropString);
		}
	}
}

std::string OLinkService::olinkObjectName()
{
	return "tb.simple.SimpleInterface";
}

void OLinkService::olinkOnSignal(std::string name, nlohmann::json args)
{
	std::string path = Name::pathFromName(name);
	if (path == "sigBool")
	{
		SigBoolSignal.Broadcast(args[0].get<bool>());
		return;
	}
	if (path == "sigInt")
	{
		SigIntSignal.Broadcast(args[0].get<int32>());
		return;
	}
	if (path == "sigFloat")
	{
		SigFloatSignal.Broadcast(args[0].get<float>());
		return;
	}
	if (path == "sigString")
	{
		SigStringSignal.Broadcast(args[0].get<FString>());
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
} // namespace SimpleInterface
} // namespace TbSimple
