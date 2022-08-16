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

#include "TbSimpleSimpleArrayInterfaceOLink.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "apig/TbSimple.json.adapter.h"
#include "unrealolink.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;

namespace TbSimple
{
namespace SimpleArrayInterface
{
namespace Private
{
OLinkService::OLinkService()
	: ITbSimpleSimpleArrayInterfaceInterface()
	, m_node(nullptr)
	, m_isReady(false)
	, PropBool(TArray<bool>())
	, PropInt(TArray<int32>())
	, PropFloat(TArray<float>())
	, PropString(TArray<FString>())
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

FTbSimpleSimpleArrayInterfaceSigBoolDelegate& OLinkService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

FTbSimpleSimpleArrayInterfaceSigIntDelegate& OLinkService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

FTbSimpleSimpleArrayInterfaceSigFloatDelegate& OLinkService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

FTbSimpleSimpleArrayInterfaceSigStringDelegate& OLinkService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

TArray<bool> OLinkService::GetPropBool() const
{
	return PropBool;
}

void OLinkService::SetPropBool(const TArray<bool>& InPropBool)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propBool", InPropBool);
}

FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& OLinkService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}
TArray<int32> OLinkService::GetPropInt() const
{
	return PropInt;
}

void OLinkService::SetPropInt(const TArray<int32>& InPropInt)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propInt", InPropInt);
}

FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& OLinkService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}
TArray<float> OLinkService::GetPropFloat() const
{
	return PropFloat;
}

void OLinkService::SetPropFloat(const TArray<float>& InPropFloat)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propFloat", InPropFloat);
}

FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& OLinkService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}
TArray<FString> OLinkService::GetPropString() const
{
	return PropString;
}

void OLinkService::SetPropString(const TArray<FString>& InPropString)
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propString", InPropString);
}

FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& OLinkService::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

TArray<bool> OLinkService::FuncBool(const TArray<bool>& ParamBool)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return TArray<bool>();
	}
	TPromise<TArray<bool>> Promise;
	Async(EAsyncExecution::Thread,
		[ParamBool, &Promise, this]()
		{
			InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<TArray<bool>>()); };
			m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcBool", {ParamBool}, GetSimpleArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

TArray<int32> OLinkService::FuncInt(const TArray<int32>& ParamInt)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return TArray<int32>();
	}
	TPromise<TArray<int32>> Promise;
	Async(EAsyncExecution::Thread,
		[ParamInt, &Promise, this]()
		{
			InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<TArray<int32>>()); };
			m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcInt", {ParamInt}, GetSimpleArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

TArray<float> OLinkService::FuncFloat(const TArray<float>& ParamFloat)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return TArray<float>();
	}
	TPromise<TArray<float>> Promise;
	Async(EAsyncExecution::Thread,
		[ParamFloat, &Promise, this]()
		{
			InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<TArray<float>>()); };
			m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcFloat", {ParamFloat}, GetSimpleArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

TArray<FString> OLinkService::FuncString(const TArray<FString>& ParamString)
{
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return TArray<FString>();
	}
	TPromise<TArray<FString>> Promise;
	Async(EAsyncExecution::Thread,
		[ParamString, &Promise, this]()
		{
			InvokeReplyFunc GetSimpleArrayInterfaceStateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<TArray<FString>>()); };
			m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcString", {ParamString}, GetSimpleArrayInterfaceStateFunc);
		});

	return Promise.GetFuture().Get();
}

void OLinkService::applyState(const nlohmann::json& fields)
{
	if (fields.contains("propBool"))
	{
		if (PropBool != fields["propBool"].get<TArray<bool>>())
		{
			PropBool = fields["propBool"].get<TArray<bool>>();
			PropBoolChanged.Broadcast(PropBool);
		}
	}
	if (fields.contains("propInt"))
	{
		if (PropInt != fields["propInt"].get<TArray<int32>>())
		{
			PropInt = fields["propInt"].get<TArray<int32>>();
			PropIntChanged.Broadcast(PropInt);
		}
	}
	if (fields.contains("propFloat"))
	{
		if (PropFloat != fields["propFloat"].get<TArray<float>>())
		{
			PropFloat = fields["propFloat"].get<TArray<float>>();
			PropFloatChanged.Broadcast(PropFloat);
		}
	}
	if (fields.contains("propString"))
	{
		if (PropString != fields["propString"].get<TArray<FString>>())
		{
			PropString = fields["propString"].get<TArray<FString>>();
			PropStringChanged.Broadcast(PropString);
		}
	}
}

std::string OLinkService::olinkObjectName()
{
	return "tb.simple.SimpleArrayInterface";
}

void OLinkService::olinkOnSignal(std::string name, nlohmann::json args)
{
	std::string path = Name::pathFromName(name);
	if (path == "sigBool")
	{
		SigBoolSignal.Broadcast(args[0].get<TArray<bool>>());
		return;
	}
	if (path == "sigInt")
	{
		SigIntSignal.Broadcast(args[0].get<TArray<int32>>());
		return;
	}
	if (path == "sigFloat")
	{
		SigFloatSignal.Broadcast(args[0].get<TArray<float>>());
		return;
	}
	if (path == "sigString")
	{
		SigStringSignal.Broadcast(args[0].get<TArray<FString>>());
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
} // namespace SimpleArrayInterface
} // namespace TbSimple
