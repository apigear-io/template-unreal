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

#include "TbSimple/Generated/OLink/TbSimpleNoOperationsInterfaceOLinkAdapter.h"
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
#include "TbSimpleNoOperationsInterfaceOLinkSource.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID)

using namespace ApiGear::ObjectLink;
UTbSimpleNoOperationsInterfaceOLinkAdapter::UTbSimpleNoOperationsInterfaceOLinkAdapter()
	: Source(std::make_shared<TbSimpleNoOperationsInterfaceOLinkSource>())
{
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleNoOperationsInterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleNoOperationsInterface"));
		BackendSignals->OnPropBoolChangedBP.RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceOLinkAdapter::OnPropBoolChanged);
		BackendSignals->OnPropIntChangedBP.RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceOLinkAdapter::OnPropIntChanged);
		BackendSignals->OnSigVoidSignalBP.RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceOLinkAdapter::OnSigVoid);
		BackendSignals->OnSigBoolSignalBP.RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceOLinkAdapter::OnSigBool);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleNoOperationsInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleNoOperationsInterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSimpleNoOperationsInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnPropBoolChangedBP.AddDynamic(this, &UTbSimpleNoOperationsInterfaceOLinkAdapter::OnPropBoolChanged);
	BackendSignals->OnPropIntChangedBP.AddDynamic(this, &UTbSimpleNoOperationsInterfaceOLinkAdapter::OnPropIntChanged);
	BackendSignals->OnSigVoidSignalBP.AddDynamic(this, &UTbSimpleNoOperationsInterfaceOLinkAdapter::OnSigVoid);
	BackendSignals->OnSigBoolSignalBP.AddDynamic(this, &UTbSimpleNoOperationsInterfaceOLinkAdapter::OnSigBool);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::OnSigVoid()
{
	Source->OnSigVoid();
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::OnSigBool(bool bParamBool)
{
	Source->OnSigBool(bParamBool);
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::OnPropBoolChanged(bool bInPropBool)
{
	Source->OnPropBoolChanged(bInPropBool);
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::OnPropIntChanged(int32 InPropInt)
{
	Source->OnPropIntChanged(InPropInt);
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
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

UTbSimpleNoOperationsInterfaceOLinkAdapter::UTbSimpleNoOperationsInterfaceOLinkAdapter()
	: Source(std::make_shared<TbSimpleNoOperationsInterfaceOLinkSource>())
{
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> InService)
{
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::OnSigVoid()
{
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::OnSigBool(bool bParamBool)
{
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::OnPropBoolChanged(bool bInPropBool)
{
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::OnPropIntChanged(int32 InPropInt)
{
}

void UTbSimpleNoOperationsInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
