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

#include "Generated/OLink/TbNamesNamEsOLinkAdapter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "TbNames/Generated/api/TbNames.json.adapter.h"
#include "OLinkClientConnection.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "TbNamesNamEsOLinkSource.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID)

using namespace ApiGear::ObjectLink;
UTbNamesNamEsOLinkAdapter::UTbNamesNamEsOLinkAdapter()
	: Source(std::make_shared<TbNamesNamEsOLinkSource>())
{
}

void UTbNamesNamEsOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbNamesNamEsOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTbNamesNamEsOLinkAdapter::setBackendService(TScriptInterface<ITbNamesNamEsInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbNamesNamEsSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbNamesNamEs"));
		BackendSignals->OnSwitchChanged.RemoveDynamic(this, &UTbNamesNamEsOLinkAdapter::OnSwitchChanged);
		BackendSignals->OnSomePropertyChanged.RemoveDynamic(this, &UTbNamesNamEsOLinkAdapter::OnSomePropertyChanged);
		BackendSignals->OnSomePoperty2Changed.RemoveDynamic(this, &UTbNamesNamEsOLinkAdapter::OnSomePoperty2Changed);
		BackendSignals->OnSomeSignalSignal.RemoveDynamic(this, &UTbNamesNamEsOLinkAdapter::OnSomeSignal);
		BackendSignals->OnSomeSignal2Signal.RemoveDynamic(this, &UTbNamesNamEsOLinkAdapter::OnSomeSignal2);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbNamesNamEs is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbNamesNamEsSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbNamesNamEs"));
	// connect property changed signals or simple events
	BackendSignals->OnSwitchChanged.AddDynamic(this, &UTbNamesNamEsOLinkAdapter::OnSwitchChanged);
	BackendSignals->OnSomePropertyChanged.AddDynamic(this, &UTbNamesNamEsOLinkAdapter::OnSomePropertyChanged);
	BackendSignals->OnSomePoperty2Changed.AddDynamic(this, &UTbNamesNamEsOLinkAdapter::OnSomePoperty2Changed);
	BackendSignals->OnSomeSignalSignal.AddDynamic(this, &UTbNamesNamEsOLinkAdapter::OnSomeSignal);
	BackendSignals->OnSomeSignal2Signal.AddDynamic(this, &UTbNamesNamEsOLinkAdapter::OnSomeSignal2);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UTbNamesNamEsOLinkAdapter::OnSomeSignal(bool bSomeParam)
{
	Source->OnSomeSignal(bSomeParam);
}

void UTbNamesNamEsOLinkAdapter::OnSomeSignal2(bool bSomeParam)
{
	Source->OnSomeSignal2(bSomeParam);
}

void UTbNamesNamEsOLinkAdapter::OnSwitchChanged(bool bInSwitch)
{
	Source->OnSwitchChanged(bInSwitch);
}

void UTbNamesNamEsOLinkAdapter::OnSomePropertyChanged(int32 InSomeProperty)
{
	Source->OnSomePropertyChanged(InSomeProperty);
}

void UTbNamesNamEsOLinkAdapter::OnSomePoperty2Changed(int32 InSomePoperty2)
{
	Source->OnSomePoperty2Changed(InSomePoperty2);
}

void UTbNamesNamEsOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
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

UTbNamesNamEsOLinkAdapter::UTbNamesNamEsOLinkAdapter()
	: Source(std::make_shared<TbNamesNamEsOLinkSource>())
{
}

void UTbNamesNamEsOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbNamesNamEsOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTbNamesNamEsOLinkAdapter::setBackendService(TScriptInterface<ITbNamesNamEsInterface> InService)
{
}

void UTbNamesNamEsOLinkAdapter::OnSomeSignal(bool bSomeParam)
{
}

void UTbNamesNamEsOLinkAdapter::OnSomeSignal2(bool bSomeParam)
{
}

void UTbNamesNamEsOLinkAdapter::OnSwitchChanged(bool bInSwitch)
{
}

void UTbNamesNamEsOLinkAdapter::OnSomePropertyChanged(int32 InSomeProperty)
{
}

void UTbNamesNamEsOLinkAdapter::OnSomePoperty2Changed(int32 InSomePoperty2)
{
}

void UTbNamesNamEsOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
