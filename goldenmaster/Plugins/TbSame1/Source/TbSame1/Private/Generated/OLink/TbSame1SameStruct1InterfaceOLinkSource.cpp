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

#include "TbSame1SameStruct1InterfaceOLinkSource.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/TbSame1.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END

using namespace ApiGear::ObjectLink;

namespace
{
static const std::string TbSame1SameStruct1InterfaceIdentifier{"tb.same1.SameStruct1Interface"};
}

DEFINE_LOG_CATEGORY(LogTbSame1SameStruct1InterfaceOLinkSource);
TbSame1SameStruct1InterfaceOLinkSource::TbSame1SameStruct1InterfaceOLinkSource()
	: Host(nullptr)
{
}

void TbSame1SameStruct1InterfaceOLinkSource::setBackendService(TScriptInterface<ITbSame1SameStruct1InterfaceInterface> InService)
{
	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTbSame1SameStruct1InterfaceOLinkSource, Error, TEXT("Cannot set backend service to %s - interface TbSame1SameStruct1Interface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	BackendService = InService;
}
void TbSame1SameStruct1InterfaceOLinkSource::OnSig1(const FTbSame1Struct1& Param1)
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

void TbSame1SameStruct1InterfaceOLinkSource::OnProp1Changed(const FTbSame1Struct1& InProp1)
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

void TbSame1SameStruct1InterfaceOLinkSource::setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost)
{
	Host = InHost.Get();
}

//
// IObjectSource interface
//

std::string TbSame1SameStruct1InterfaceOLinkSource::olinkObjectName()
{
	return TbSame1SameStruct1InterfaceIdentifier;
}

nlohmann::json TbSame1SameStruct1InterfaceOLinkSource::olinkInvoke(const std::string& methodId, const nlohmann::json& args)
{
	if (!BackendService)
	{
		UE_LOG(LogTbSame1SameStruct1InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSame1SameStruct1InterfaceOLinkAdapter which implements the TbSame1SameStruct1Interface interface"));
		return nlohmann::json();
	}

	const std::string path = Name::getMemberName(methodId);
	if (path == "func1")
	{
		FTbSame1Struct1 Param1 = args.at(0).get<FTbSame1Struct1>();
		FTbSame1Struct1 result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
		return result;
	}
	return nlohmann::json();
}

void TbSame1SameStruct1InterfaceOLinkSource::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
	if (!BackendService)
	{
		UE_LOG(LogTbSame1SameStruct1InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSame1SameStruct1InterfaceOLinkAdapter which implements the TbSame1SameStruct1Interface interface"));
		return;
	}

	const std::string path = Name::getMemberName(propertyId);
	if (path == "prop1")
	{
		FTbSame1Struct1 Prop1 = value.get<FTbSame1Struct1>();
		BackendService->Execute_SetProp1(BackendService.GetObject(), Prop1);
	}
}

nlohmann::json TbSame1SameStruct1InterfaceOLinkSource::olinkCollectProperties()
{
	if (!BackendService)
	{
		UE_LOG(LogTbSame1SameStruct1InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSame1SameStruct1InterfaceOLinkAdapter which implements the TbSame1SameStruct1Interface interface"));
		return nlohmann::json();
	}

	return nlohmann::json::object({

		{"prop1", BackendService->Execute_GetProp1(BackendService.GetObject())}});
}