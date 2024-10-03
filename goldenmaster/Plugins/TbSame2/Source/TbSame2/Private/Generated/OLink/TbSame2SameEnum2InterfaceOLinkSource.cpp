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

#include "TbSame2SameEnum2InterfaceOLinkSource.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID)
#include "Async/Future.h"
#include "Async/Async.h"
#include "TbSame2/Generated/api/TbSame2.json.adapter.h"
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
static const std::string TbSame2SameEnum2InterfaceIdentifier{"tb.same2.SameEnum2Interface"};
}

DEFINE_LOG_CATEGORY(LogTbSame2SameEnum2InterfaceOLinkSource);
TbSame2SameEnum2InterfaceOLinkSource::TbSame2SameEnum2InterfaceOLinkSource()
	: Host(nullptr)
{
}

void TbSame2SameEnum2InterfaceOLinkSource::setBackendService(TScriptInterface<ITbSame2SameEnum2InterfaceInterface> InService)
{
	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTbSame2SameEnum2InterfaceOLinkSource, Error, TEXT("Cannot set backend service - interface TbSame2SameEnum2Interface is not fully implemented"));
		return;
	}

	BackendService = InService;
}
void TbSame2SameEnum2InterfaceOLinkSource::OnSig1(ETbSame2Enum1 Param1)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig1");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {Param1};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSame2SameEnum2InterfaceOLinkSource::OnSig2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {Param1, Param2};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbSame2SameEnum2InterfaceOLinkSource::OnProp1Changed(ETbSame2Enum1 InProp1)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InProp1);
		}
	}
}

void TbSame2SameEnum2InterfaceOLinkSource::OnProp2Changed(ETbSame2Enum2 InProp2)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop2");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InProp2);
		}
	}
}

void TbSame2SameEnum2InterfaceOLinkSource::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
	Host = InHost.Get();
}

//
// IObjectSource interface
//

std::string TbSame2SameEnum2InterfaceOLinkSource::olinkObjectName()
{
	return TbSame2SameEnum2InterfaceIdentifier;
}

nlohmann::json TbSame2SameEnum2InterfaceOLinkSource::olinkInvoke(const std::string& methodId, const nlohmann::json& args)
{
	if (!BackendService)
	{
		UE_LOG(LogTbSame2SameEnum2InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSame2SameEnum2InterfaceOLinkAdapter which implements the TbSame2SameEnum2Interface interface"));
		return nlohmann::json();
	}

	const std::string path = Name::getMemberName(methodId);
	if (path == "func1")
	{
		ETbSame2Enum1 Param1 = args.at(0).get<ETbSame2Enum1>();
		ETbSame2Enum1 result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
		return result;
	}
	if (path == "func2")
	{
		ETbSame2Enum1 Param1 = args.at(0).get<ETbSame2Enum1>();
		ETbSame2Enum2 Param2 = args.at(1).get<ETbSame2Enum2>();
		ETbSame2Enum1 result = BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
		return result;
	}
	return nlohmann::json();
}

void TbSame2SameEnum2InterfaceOLinkSource::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
	if (!BackendService)
	{
		UE_LOG(LogTbSame2SameEnum2InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSame2SameEnum2InterfaceOLinkAdapter which implements the TbSame2SameEnum2Interface interface"));
		return;
	}

	const std::string path = Name::getMemberName(propertyId);
	if (path == "prop1")
	{
		ETbSame2Enum1 Prop1 = value.get<ETbSame2Enum1>();
		BackendService->Execute_SetProp1(BackendService.GetObject(), Prop1);
	}
	if (path == "prop2")
	{
		ETbSame2Enum2 Prop2 = value.get<ETbSame2Enum2>();
		BackendService->Execute_SetProp2(BackendService.GetObject(), Prop2);
	}
}

nlohmann::json TbSame2SameEnum2InterfaceOLinkSource::olinkCollectProperties()
{
	if (!BackendService)
	{
		UE_LOG(LogTbSame2SameEnum2InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSame2SameEnum2InterfaceOLinkAdapter which implements the TbSame2SameEnum2Interface interface"));
		return nlohmann::json();
	}

	return nlohmann::json::object({

		{"prop1", BackendService->Execute_GetProp1(BackendService.GetObject())},
		{"prop2", BackendService->Execute_GetProp2(BackendService.GetObject())}});
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
