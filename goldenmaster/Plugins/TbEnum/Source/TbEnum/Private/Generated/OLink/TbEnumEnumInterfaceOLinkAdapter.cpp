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

#include "Generated/OLink/TbEnumEnumInterfaceOLinkAdapter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/TbEnum.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "TbEnumEnumInterfaceOLinkSource.h"

using namespace ApiGear::ObjectLink;
UTbEnumEnumInterfaceOLinkAdapter::UTbEnumEnumInterfaceOLinkAdapter()
	: Source(std::make_shared<TbEnumEnumInterfaceOLinkSource>())
{
}

void UTbEnumEnumInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbEnumEnumInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTbEnumEnumInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITbEnumEnumInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetProp0ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp0Changed);
		BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp1Changed);
		BackendService->GetProp2ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp2Changed);
		BackendService->GetProp3ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp3Changed);
		BackendService->GetSig0SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig0);
		BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig1);
		BackendService->GetSig2SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig2);
		BackendService->GetSig3SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig3);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface HmiFrontDisplay is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetProp0ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp0Changed);
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp2Changed);
	BackendService->GetProp3ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp3Changed);
	BackendService->GetSig0SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig0);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig2);
	BackendService->GetSig3SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig3);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UTbEnumEnumInterfaceOLinkAdapter::OnSig0(ETbEnumEnum0 Param0)
{
	Source->OnSig0(Param0);
}

void UTbEnumEnumInterfaceOLinkAdapter::OnSig1(ETbEnumEnum1 Param1)
{
	Source->OnSig1(Param1);
}

void UTbEnumEnumInterfaceOLinkAdapter::OnSig2(ETbEnumEnum2 Param2)
{
	Source->OnSig2(Param2);
}

void UTbEnumEnumInterfaceOLinkAdapter::OnSig3(ETbEnumEnum3 Param3)
{
	Source->OnSig3(Param3);
}

void UTbEnumEnumInterfaceOLinkAdapter::OnProp0Changed(ETbEnumEnum0 InProp0)
{
	Source->OnProp0Changed(InProp0);
}

void UTbEnumEnumInterfaceOLinkAdapter::OnProp1Changed(ETbEnumEnum1 InProp1)
{
	Source->OnProp1Changed(InProp1);
}

void UTbEnumEnumInterfaceOLinkAdapter::OnProp2Changed(ETbEnumEnum2 InProp2)
{
	Source->OnProp2Changed(InProp2);
}

void UTbEnumEnumInterfaceOLinkAdapter::OnProp3Changed(ETbEnumEnum3 InProp3)
{
	Source->OnProp3Changed(InProp3);
}

void UTbEnumEnumInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost)
{
	check(InHost);
	Source->setOLinkHost(InHost.Get());

	// register source to host
	InHost->GetOLinkRegistry()->addSource(Source);
}
