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

#include "TbSimpleSimpleInterfaceOLinkSource.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/TbSimple.json.adapter.h"
#include "OLinkClientConnection.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END

using namespace ApiGear::ObjectLink;

namespace
{
static const std::string TbSimpleSimpleInterfaceIdentifier{"tb.simple.SimpleInterface"};
}

DEFINE_LOG_CATEGORY(LogTbSimpleSimpleInterfaceOLinkSource);
TbSimpleSimpleInterfaceOLinkSource::TbSimpleSimpleInterfaceOLinkSource()
	: Host(nullptr)
{
}

void TbSimpleSimpleInterfaceOLinkSource::setBackendService(TScriptInterface<ITbSimpleSimpleInterfaceInterface> InService)
{
	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTbSimpleSimpleInterfaceOLinkSource, Error, TEXT("Cannot set backend service - interface TbSimpleSimpleInterface is not fully implemented"));
		return;
	}

	BackendService = InService;
}
void TbSimpleSimpleInterfaceOLinkSource::OnSigBool(bool bParamBool)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigBool");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {bParamBool};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnSigInt(int32 ParamInt)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamInt};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnSigInt32(int32 ParamInt32)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt32");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamInt32};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnSigInt64(int64 ParamInt64)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigInt64");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamInt64};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnSigFloat(float ParamFloat)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamFloat};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnSigFloat32(float ParamFloat32)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat32");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamFloat32};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnSigFloat64(double ParamFloat64)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigFloat64");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamFloat64};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnSigString(const FString& ParamString)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sigString");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {ParamString};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnPropBoolChanged(bool bInPropBool)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propBool");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, bInPropBool);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnPropIntChanged(int32 InPropInt)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropInt);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnPropInt32Changed(int32 InPropInt32)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt32");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropInt32);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnPropInt64Changed(int64 InPropInt64)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propInt64");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropInt64);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnPropFloatChanged(float InPropFloat)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropFloat);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnPropFloat32Changed(float InPropFloat32)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat32");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropFloat32);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnPropFloat64Changed(double InPropFloat64)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propFloat64");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropFloat64);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::OnPropStringChanged(const FString& InPropString)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "propString");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InPropString);
		}
	}
}

void TbSimpleSimpleInterfaceOLinkSource::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
	Host = InHost.Get();
}

//
// IObjectSource interface
//

std::string TbSimpleSimpleInterfaceOLinkSource::olinkObjectName()
{
	return TbSimpleSimpleInterfaceIdentifier;
}

nlohmann::json TbSimpleSimpleInterfaceOLinkSource::olinkInvoke(const std::string& methodId, const nlohmann::json& args)
{
	if (!BackendService)
	{
		UE_LOG(LogTbSimpleSimpleInterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSimpleSimpleInterfaceOLinkAdapter which implements the TbSimpleSimpleInterface interface"));
		return nlohmann::json();
	}

	const std::string path = Name::getMemberName(methodId);
	if (path == "funcNoReturnValue")
	{
		bool bParamBool = args.at(0).get<bool>();
		BackendService->Execute_FuncNoReturnValue(BackendService.GetObject(), bParamBool);
		return nlohmann::json{};
	}
	if (path == "funcBool")
	{
		bool bParamBool = args.at(0).get<bool>();
		bool result = BackendService->Execute_FuncBool(BackendService.GetObject(), bParamBool);
		return result;
	}
	if (path == "funcInt")
	{
		int32 ParamInt = args.at(0).get<int32>();
		int32 result = BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
		return result;
	}
	if (path == "funcInt32")
	{
		int32 ParamInt32 = args.at(0).get<int32>();
		int32 result = BackendService->Execute_FuncInt32(BackendService.GetObject(), ParamInt32);
		return result;
	}
	if (path == "funcInt64")
	{
		int64 ParamInt64 = args.at(0).get<int64>();
		int64 result = BackendService->Execute_FuncInt64(BackendService.GetObject(), ParamInt64);
		return result;
	}
	if (path == "funcFloat")
	{
		float ParamFloat = args.at(0).get<float>();
		float result = BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
		return result;
	}
	if (path == "funcFloat32")
	{
		float ParamFloat32 = args.at(0).get<float>();
		float result = BackendService->Execute_FuncFloat32(BackendService.GetObject(), ParamFloat32);
		return result;
	}
	if (path == "funcFloat64")
	{
		double ParamFloat = args.at(0).get<double>();
		double result = BackendService->Execute_FuncFloat64(BackendService.GetObject(), ParamFloat);
		return result;
	}
	if (path == "funcString")
	{
		FString ParamString = args.at(0).get<FString>();
		FString result = BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
		return result;
	}
	return nlohmann::json();
}

void TbSimpleSimpleInterfaceOLinkSource::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
	if (!BackendService)
	{
		UE_LOG(LogTbSimpleSimpleInterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSimpleSimpleInterfaceOLinkAdapter which implements the TbSimpleSimpleInterface interface"));
		return;
	}

	const std::string path = Name::getMemberName(propertyId);
	if (path == "propBool")
	{
		bool bPropBool = value.get<bool>();
		BackendService->Execute_SetPropBool(BackendService.GetObject(), bPropBool);
	}
	if (path == "propInt")
	{
		int32 PropInt = value.get<int32>();
		BackendService->Execute_SetPropInt(BackendService.GetObject(), PropInt);
	}
	if (path == "propInt32")
	{
		int32 PropInt32 = value.get<int32>();
		BackendService->Execute_SetPropInt32(BackendService.GetObject(), PropInt32);
	}
	if (path == "propInt64")
	{
		int64 PropInt64 = value.get<int64>();
		BackendService->Execute_SetPropInt64(BackendService.GetObject(), PropInt64);
	}
	if (path == "propFloat")
	{
		float PropFloat = value.get<float>();
		BackendService->Execute_SetPropFloat(BackendService.GetObject(), PropFloat);
	}
	if (path == "propFloat32")
	{
		float PropFloat32 = value.get<float>();
		BackendService->Execute_SetPropFloat32(BackendService.GetObject(), PropFloat32);
	}
	if (path == "propFloat64")
	{
		double PropFloat64 = value.get<double>();
		BackendService->Execute_SetPropFloat64(BackendService.GetObject(), PropFloat64);
	}
	if (path == "propString")
	{
		FString PropString = value.get<FString>();
		BackendService->Execute_SetPropString(BackendService.GetObject(), PropString);
	}
}

nlohmann::json TbSimpleSimpleInterfaceOLinkSource::olinkCollectProperties()
{
	if (!BackendService)
	{
		UE_LOG(LogTbSimpleSimpleInterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSimpleSimpleInterfaceOLinkAdapter which implements the TbSimpleSimpleInterface interface"));
		return nlohmann::json();
	}

	return nlohmann::json::object({

		{"propBool", BackendService->Execute_GetPropBool(BackendService.GetObject())},
		{"propInt", BackendService->Execute_GetPropInt(BackendService.GetObject())},
		{"propInt32", BackendService->Execute_GetPropInt32(BackendService.GetObject())},
		{"propInt64", BackendService->Execute_GetPropInt64(BackendService.GetObject())},
		{"propFloat", BackendService->Execute_GetPropFloat(BackendService.GetObject())},
		{"propFloat32", BackendService->Execute_GetPropFloat32(BackendService.GetObject())},
		{"propFloat64", BackendService->Execute_GetPropFloat64(BackendService.GetObject())},
		{"propString", BackendService->Execute_GetPropString(BackendService.GetObject())}});
}
