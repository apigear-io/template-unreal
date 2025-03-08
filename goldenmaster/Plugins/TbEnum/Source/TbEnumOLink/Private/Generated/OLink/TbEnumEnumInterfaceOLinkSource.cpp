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

#include "TbEnumEnumInterfaceOLinkSource.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID)
#include "Async/Future.h"
#include "Async/Async.h"
#include "TbEnum/Generated/api/TbEnum.json.adapter.h"
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
static const std::string TbEnumEnumInterfaceIdentifier{"tb.enum.EnumInterface"};
}

DEFINE_LOG_CATEGORY(LogTbEnumEnumInterfaceOLinkSource);
TbEnumEnumInterfaceOLinkSource::TbEnumEnumInterfaceOLinkSource()
	: Host(nullptr)
{
}

void TbEnumEnumInterfaceOLinkSource::setBackendService(TScriptInterface<ITbEnumEnumInterfaceInterface> InService)
{
	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTbEnumEnumInterfaceOLinkSource, Error, TEXT("Cannot set backend service - interface TbEnumEnumInterface is not fully implemented"));
		return;
	}

	BackendService = InService;
}
void TbEnumEnumInterfaceOLinkSource::OnSig0(ETbEnumEnum0 Param0)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig0");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {Param0};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbEnumEnumInterfaceOLinkSource::OnSig1(ETbEnumEnum1 Param1)
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

void TbEnumEnumInterfaceOLinkSource::OnSig2(ETbEnumEnum2 Param2)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig2");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {Param2};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbEnumEnumInterfaceOLinkSource::OnSig3(ETbEnumEnum3 Param3)
{
	static const auto& signalId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "sig3");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(signalId);
	const nlohmann::json& args = {Param3};
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifySignal(signalId, args);
		}
	}
}

void TbEnumEnumInterfaceOLinkSource::OnProp0Changed(ETbEnumEnum0 InProp0)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop0");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InProp0);
		}
	}
}

void TbEnumEnumInterfaceOLinkSource::OnProp1Changed(ETbEnumEnum1 InProp1)
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

void TbEnumEnumInterfaceOLinkSource::OnProp2Changed(ETbEnumEnum2 InProp2)
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

void TbEnumEnumInterfaceOLinkSource::OnProp3Changed(ETbEnumEnum3 InProp3)
{
	static const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop3");
	static const auto& objectId = ApiGear::ObjectLink::Name::getObjectId(propertyId);
	for (auto node : Host->GetOLinkRegistry()->getNodes(objectId))
	{
		auto lockedNode = node.lock();
		if (lockedNode)
		{
			lockedNode->notifyPropertyChange(propertyId, InProp3);
		}
	}
}

void TbEnumEnumInterfaceOLinkSource::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
	Host = InHost.Get();
}

//
// IObjectSource interface
//

std::string TbEnumEnumInterfaceOLinkSource::olinkObjectName()
{
	return TbEnumEnumInterfaceIdentifier;
}

nlohmann::json TbEnumEnumInterfaceOLinkSource::olinkInvoke(const std::string& methodId, const nlohmann::json& args)
{
	if (!BackendService)
	{
		UE_LOG(LogTbEnumEnumInterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbEnumEnumInterfaceOLinkAdapter which implements the TbEnumEnumInterface interface"));
		return nlohmann::json();
	}

	const std::string path = Name::getMemberName(methodId);
	if (path == "func0")
	{
		ETbEnumEnum0 Param0 = args.at(0).get<ETbEnumEnum0>();
		ETbEnumEnum0 result = BackendService->Func0(Param0);
		return result;
	}
	if (path == "func1")
	{
		ETbEnumEnum1 Param1 = args.at(0).get<ETbEnumEnum1>();
		ETbEnumEnum1 result = BackendService->Func1(Param1);
		return result;
	}
	if (path == "func2")
	{
		ETbEnumEnum2 Param2 = args.at(0).get<ETbEnumEnum2>();
		ETbEnumEnum2 result = BackendService->Func2(Param2);
		return result;
	}
	if (path == "func3")
	{
		ETbEnumEnum3 Param3 = args.at(0).get<ETbEnumEnum3>();
		ETbEnumEnum3 result = BackendService->Func3(Param3);
		return result;
	}
	return nlohmann::json();
}

void TbEnumEnumInterfaceOLinkSource::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
	if (!BackendService)
	{
		UE_LOG(LogTbEnumEnumInterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbEnumEnumInterfaceOLinkAdapter which implements the TbEnumEnumInterface interface"));
		return;
	}

	const std::string path = Name::getMemberName(propertyId);
	if (path == "prop0")
	{
		ETbEnumEnum0 Prop0 = value.get<ETbEnumEnum0>();
		BackendService->SetProp0(Prop0);
	}
	if (path == "prop1")
	{
		ETbEnumEnum1 Prop1 = value.get<ETbEnumEnum1>();
		BackendService->SetProp1(Prop1);
	}
	if (path == "prop2")
	{
		ETbEnumEnum2 Prop2 = value.get<ETbEnumEnum2>();
		BackendService->SetProp2(Prop2);
	}
	if (path == "prop3")
	{
		ETbEnumEnum3 Prop3 = value.get<ETbEnumEnum3>();
		BackendService->SetProp3(Prop3);
	}
}

nlohmann::json TbEnumEnumInterfaceOLinkSource::olinkCollectProperties()
{
	if (!BackendService)
	{
		UE_LOG(LogTbEnumEnumInterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbEnumEnumInterfaceOLinkAdapter which implements the TbEnumEnumInterface interface"));
		return nlohmann::json();
	}

	return nlohmann::json::object({

		{"prop0", BackendService->GetProp0()},
		{"prop1", BackendService->GetProp1()},
		{"prop2", BackendService->GetProp2()},
		{"prop3", BackendService->GetProp3()}});
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
