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

#include "TbSimpleEmptyInterfaceOLinkSource.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/TbSimple.json.adapter.h"
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
static const std::string TbSimpleEmptyInterfaceIdentifier{"tb.simple.EmptyInterface"};
}
TbSimpleEmptyInterfaceOLinkSource::TbSimpleEmptyInterfaceOLinkSource()
	: Host(nullptr)
{
}

void TbSimpleEmptyInterfaceOLinkSource::setBackendService(TScriptInterface<ITbSimpleEmptyInterfaceInterface> InService)
{
	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot set backend service to %s - interface TbSimpleEmptyInterface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	BackendService = InService;
}
void TbSimpleEmptyInterfaceOLinkSource::setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost)
{
	Host = InHost.Get();
}

//
// IObjectSource interface
//

std::string TbSimpleEmptyInterfaceOLinkSource::olinkObjectName()
{
	return TbSimpleEmptyInterfaceIdentifier;
}

nlohmann::json TbSimpleEmptyInterfaceOLinkSource::olinkInvoke(const std::string& methodId, const nlohmann::json& args)
{
	const std::string path = Name::getMemberName(methodId);
	return nlohmann::json();
}

void TbSimpleEmptyInterfaceOLinkSource::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
	const std::string path = Name::getMemberName(propertyId);
}

nlohmann::json TbSimpleEmptyInterfaceOLinkSource::olinkCollectProperties()
{
	return nlohmann::json::object({});
}
