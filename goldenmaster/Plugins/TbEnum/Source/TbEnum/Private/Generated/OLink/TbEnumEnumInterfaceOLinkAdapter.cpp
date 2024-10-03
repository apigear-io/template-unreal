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
#include "TbEnum/Generated/api/TbEnum.json.adapter.h"
#include "OLinkClientConnection.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "TbEnumEnumInterfaceOLinkSource.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID)

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
		UTbEnumEnumInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbEnumEnumInterface"));
		BackendSignals->OnProp0Changed.RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp0Changed);
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp1Changed);
		BackendSignals->OnProp2Changed.RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp2Changed);
		BackendSignals->OnProp3Changed.RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp3Changed);
		BackendSignals->OnSig0Signal.RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig0);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig1);
		BackendSignals->OnSig2Signal.RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig2);
		BackendSignals->OnSig3Signal.RemoveDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig3);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbEnumEnumInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbEnumEnumInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbEnumEnumInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp0Changed.AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp0Changed);
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp1Changed);
	BackendSignals->OnProp2Changed.AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp2Changed);
	BackendSignals->OnProp3Changed.AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnProp3Changed);
	BackendSignals->OnSig0Signal.AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig0);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig1);
	BackendSignals->OnSig2Signal.AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig2);
	BackendSignals->OnSig3Signal.AddDynamic(this, &UTbEnumEnumInterfaceOLinkAdapter::OnSig3);

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

void UTbEnumEnumInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
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
}

void UTbEnumEnumInterfaceOLinkAdapter::OnSig0(ETbEnumEnum0 Param0)
{
}

void UTbEnumEnumInterfaceOLinkAdapter::OnSig1(ETbEnumEnum1 Param1)
{
}

void UTbEnumEnumInterfaceOLinkAdapter::OnSig2(ETbEnumEnum2 Param2)
{
}

void UTbEnumEnumInterfaceOLinkAdapter::OnSig3(ETbEnumEnum3 Param3)
{
}

void UTbEnumEnumInterfaceOLinkAdapter::OnProp0Changed(ETbEnumEnum0 InProp0)
{
}

void UTbEnumEnumInterfaceOLinkAdapter::OnProp1Changed(ETbEnumEnum1 InProp1)
{
}

void UTbEnumEnumInterfaceOLinkAdapter::OnProp2Changed(ETbEnumEnum2 InProp2)
{
}

void UTbEnumEnumInterfaceOLinkAdapter::OnProp3Changed(ETbEnumEnum3 InProp3)
{
}

void UTbEnumEnumInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
