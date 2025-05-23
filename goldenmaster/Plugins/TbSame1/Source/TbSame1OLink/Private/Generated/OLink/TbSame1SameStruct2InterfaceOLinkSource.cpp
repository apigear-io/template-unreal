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

#include "TbSame1SameStruct2InterfaceOLinkSource.h"
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "Async/Future.h"
#include "Async/Async.h"
#include "TbSame1/Generated/api/TbSame1.json.adapter.h"
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
static const std::string TbSame1SameStruct2InterfaceIdentifier{"tb.same1.SameStruct2Interface"};
}

DEFINE_LOG_CATEGORY(LogTbSame1SameStruct2InterfaceOLinkSource);
TbSame1SameStruct2InterfaceOLinkSource::TbSame1SameStruct2InterfaceOLinkSource()
	: Host(nullptr)
{
}

void TbSame1SameStruct2InterfaceOLinkSource::setBackendService(TScriptInterface<ITbSame1SameStruct2InterfaceInterface> InService)
{
	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTbSame1SameStruct2InterfaceOLinkSource, Error, TEXT("Cannot set backend service - interface TbSame1SameStruct2Interface is not fully implemented"));
		return;
	}

	BackendService = InService;
}
void TbSame1SameStruct2InterfaceOLinkSource::OnSig1(const FTbSame1Struct1& Param1)
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

void TbSame1SameStruct2InterfaceOLinkSource::OnSig2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
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

void TbSame1SameStruct2InterfaceOLinkSource::OnProp1Changed(const FTbSame1Struct2& InProp1)
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

void TbSame1SameStruct2InterfaceOLinkSource::OnProp2Changed(const FTbSame1Struct2& InProp2)
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

void TbSame1SameStruct2InterfaceOLinkSource::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
	Host = InHost.Get();
}

//
// IObjectSource interface
//

std::string TbSame1SameStruct2InterfaceOLinkSource::olinkObjectName()
{
	return TbSame1SameStruct2InterfaceIdentifier;
}

nlohmann::json TbSame1SameStruct2InterfaceOLinkSource::olinkInvoke(const std::string& methodId, const nlohmann::json& args)
{
	if (!BackendService)
	{
		UE_LOG(LogTbSame1SameStruct2InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSame1SameStruct2InterfaceOLinkAdapter which implements the TbSame1SameStruct2Interface interface"));
		return nlohmann::json();
	}

	const std::string path = Name::getMemberName(methodId);
	if (path == "func1")
	{
		FTbSame1Struct1 Param1 = args.at(0).get<FTbSame1Struct1>();
		FTbSame1Struct1 result = BackendService->Func1(Param1);
		return result;
	}
	if (path == "func2")
	{
		FTbSame1Struct1 Param1 = args.at(0).get<FTbSame1Struct1>();
		FTbSame1Struct2 Param2 = args.at(1).get<FTbSame1Struct2>();
		FTbSame1Struct1 result = BackendService->Func2(Param1, Param2);
		return result;
	}
	return nlohmann::json();
}

void TbSame1SameStruct2InterfaceOLinkSource::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
	if (!BackendService)
	{
		UE_LOG(LogTbSame1SameStruct2InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSame1SameStruct2InterfaceOLinkAdapter which implements the TbSame1SameStruct2Interface interface"));
		return;
	}

	const std::string path = Name::getMemberName(propertyId);
	if (path == "prop1")
	{
		FTbSame1Struct2 Prop1 = value.get<FTbSame1Struct2>();
		BackendService->SetProp1(Prop1);
	}
	if (path == "prop2")
	{
		FTbSame1Struct2 Prop2 = value.get<FTbSame1Struct2>();
		BackendService->SetProp2(Prop2);
	}
}

nlohmann::json TbSame1SameStruct2InterfaceOLinkSource::olinkCollectProperties()
{
	if (!BackendService)
	{
		UE_LOG(LogTbSame1SameStruct2InterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSame1SameStruct2InterfaceOLinkAdapter which implements the TbSame1SameStruct2Interface interface"));
		return nlohmann::json();
	}

	return nlohmann::json::object({

		{"prop1", BackendService->GetProp1()},
		{"prop2", BackendService->GetProp2()}});
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
