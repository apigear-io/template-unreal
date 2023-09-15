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

#include "Generated/OLink/TbSame1SameEnum1InterfaceOLinkAdapter.h"
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
#include "TbSame1SameEnum1InterfaceOLinkSource.h"

using namespace ApiGear::ObjectLink;
UTbSame1SameEnum1InterfaceOLinkAdapter::UTbSame1SameEnum1InterfaceOLinkAdapter()
	: Source(std::make_shared<TbSame1SameEnum1InterfaceOLinkSource>())
{
}

void UTbSame1SameEnum1InterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSame1SameEnum1InterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTbSame1SameEnum1InterfaceOLinkAdapter::setBackendService(TScriptInterface<ITbSame1SameEnum1InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame1SameEnum1InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameEnum1Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTbSame1SameEnum1InterfaceOLinkAdapter::OnProp1Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTbSame1SameEnum1InterfaceOLinkAdapter::OnSig1);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface HmiFrontDisplay is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame1SameEnum1InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameEnum1Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTbSame1SameEnum1InterfaceOLinkAdapter::OnProp1Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTbSame1SameEnum1InterfaceOLinkAdapter::OnSig1);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UTbSame1SameEnum1InterfaceOLinkAdapter::OnSig1(ETbSame1Enum1 Param1)
{
	Source->OnSig1(Param1);
}

void UTbSame1SameEnum1InterfaceOLinkAdapter::OnProp1Changed(ETbSame1Enum1 InProp1)
{
	Source->OnProp1Changed(InProp1);
}

void UTbSame1SameEnum1InterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost)
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
