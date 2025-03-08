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

#include "TbSimple/Generated/OLink/TbSimpleVoidInterfaceOLinkAdapter.h"
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
#include "TbSimpleVoidInterfaceOLinkSource.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID)

using namespace ApiGear::ObjectLink;
UTbSimpleVoidInterfaceOLinkAdapter::UTbSimpleVoidInterfaceOLinkAdapter()
	: Source(std::make_shared<TbSimpleVoidInterfaceOLinkSource>())
{
}

void UTbSimpleVoidInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleVoidInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTbSimpleVoidInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITbSimpleVoidInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleVoidInterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleVoidInterface"));
		BackendSignals->OnSigVoidSignal.RemoveDynamic(this, &UTbSimpleVoidInterfaceOLinkAdapter::OnSigVoid);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleVoidInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleVoidInterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSimpleVoidInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnSigVoidSignal.AddDynamic(this, &UTbSimpleVoidInterfaceOLinkAdapter::OnSigVoid);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UTbSimpleVoidInterfaceOLinkAdapter::OnSigVoid()
{
	Source->OnSigVoid();
}

void UTbSimpleVoidInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
	check(InHost);
	Source->setOLinkHost(InHost.Get());

	if (Registry)
	{
		Registry->removeSource(Source->olinkObjectName());
	}
	Registry = InHost->GetOLinkRegistry();
	// register source to host registry
	Registry->addSource(Source);
}
#else  // !(PLATFORM_IOS || PLATFORM_ANDROID)

UTbSimpleVoidInterfaceOLinkAdapter::UTbSimpleVoidInterfaceOLinkAdapter()
	: Source(std::make_shared<TbSimpleVoidInterfaceOLinkSource>())
{
}

void UTbSimpleVoidInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleVoidInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTbSimpleVoidInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITbSimpleVoidInterfaceInterface> InService)
{
}

void UTbSimpleVoidInterfaceOLinkAdapter::OnSigVoid()
{
}

void UTbSimpleVoidInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
