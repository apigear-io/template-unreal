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
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID)
#include "Async/Future.h"
#include "Async/Async.h"
#include "TbSimple/Generated/api/TbSimple.json.adapter.h"
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
static const std::string TbSimpleEmptyInterfaceIdentifier{"tb.simple.EmptyInterface"};
}

DEFINE_LOG_CATEGORY(LogTbSimpleEmptyInterfaceOLinkSource);
TbSimpleEmptyInterfaceOLinkSource::TbSimpleEmptyInterfaceOLinkSource()
	: Host(nullptr)
{
}

void TbSimpleEmptyInterfaceOLinkSource::setBackendService(TScriptInterface<ITbSimpleEmptyInterfaceInterface> InService)
{
	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTbSimpleEmptyInterfaceOLinkSource, Error, TEXT("Cannot set backend service - interface TbSimpleEmptyInterface is not fully implemented"));
		return;
	}

	BackendService = InService;
}
void TbSimpleEmptyInterfaceOLinkSource::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
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
	if (!BackendService)
	{
		UE_LOG(LogTbSimpleEmptyInterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSimpleEmptyInterfaceOLinkAdapter which implements the TbSimpleEmptyInterface interface"));
		return nlohmann::json();
	}

	const std::string path = Name::getMemberName(methodId);
	return nlohmann::json();
}

void TbSimpleEmptyInterfaceOLinkSource::olinkSetProperty(const std::string& propertyId, const nlohmann::json& value)
{
	if (!BackendService)
	{
		UE_LOG(LogTbSimpleEmptyInterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSimpleEmptyInterfaceOLinkAdapter which implements the TbSimpleEmptyInterface interface"));
		return;
	}

	const std::string path = Name::getMemberName(propertyId);
}

nlohmann::json TbSimpleEmptyInterfaceOLinkSource::olinkCollectProperties()
{
	if (!BackendService)
	{
		UE_LOG(LogTbSimpleEmptyInterfaceOLinkSource, Error, TEXT("No backend service set - please specify a service in the adapter TbSimpleEmptyInterfaceOLinkAdapter which implements the TbSimpleEmptyInterface interface"));
		return nlohmann::json();
	}

	return nlohmann::json::object({});
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
