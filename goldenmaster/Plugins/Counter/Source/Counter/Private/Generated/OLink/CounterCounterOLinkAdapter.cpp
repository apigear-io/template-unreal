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

#include "Generated/OLink/CounterCounterOLinkAdapter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/Counter.json.adapter.h"
#include "OLinkClientConnection.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "CounterCounterOLinkSource.h"

using namespace ApiGear::ObjectLink;
UCounterCounterOLinkAdapter::UCounterCounterOLinkAdapter()
	: Source(std::make_shared<CounterCounterOLinkSource>())
{
}

void UCounterCounterOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UCounterCounterOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UCounterCounterOLinkAdapter::setBackendService(TScriptInterface<ICounterCounterInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UCounterCounterSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service CounterCounter"));
		BackendSignals->OnVectorChanged.RemoveDynamic(this, &UCounterCounterOLinkAdapter::OnVectorChanged);
		BackendSignals->OnExternVectorChanged.RemoveDynamic(this, &UCounterCounterOLinkAdapter::OnExternVectorChanged);
		BackendSignals->OnVectorArrayChanged.RemoveDynamic(this, &UCounterCounterOLinkAdapter::OnVectorArrayChanged);
		BackendSignals->OnExternVectorArrayChanged.RemoveDynamic(this, &UCounterCounterOLinkAdapter::OnExternVectorArrayChanged);
		BackendSignals->OnValueChangedSignal.RemoveDynamic(this, &UCounterCounterOLinkAdapter::OnValueChanged);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface CounterCounter is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UCounterCounterSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service CounterCounter"));
	// connect property changed signals or simple events
	BackendSignals->OnVectorChanged.AddDynamic(this, &UCounterCounterOLinkAdapter::OnVectorChanged);
	BackendSignals->OnExternVectorChanged.AddDynamic(this, &UCounterCounterOLinkAdapter::OnExternVectorChanged);
	BackendSignals->OnVectorArrayChanged.AddDynamic(this, &UCounterCounterOLinkAdapter::OnVectorArrayChanged);
	BackendSignals->OnExternVectorArrayChanged.AddDynamic(this, &UCounterCounterOLinkAdapter::OnExternVectorArrayChanged);
	BackendSignals->OnValueChangedSignal.AddDynamic(this, &UCounterCounterOLinkAdapter::OnValueChanged);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UCounterCounterOLinkAdapter::OnValueChanged(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
	Source->OnValueChanged(Vector, ExternVector, VectorArray, ExternVectorArray);
}

void UCounterCounterOLinkAdapter::OnVectorChanged(const FCustomTypesVector3D& InVector)
{
	Source->OnVectorChanged(InVector);
}

void UCounterCounterOLinkAdapter::OnExternVectorChanged(const FVector& InExternVector)
{
	Source->OnExternVectorChanged(InExternVector);
}

void UCounterCounterOLinkAdapter::OnVectorArrayChanged(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	Source->OnVectorArrayChanged(InVectorArray);
}

void UCounterCounterOLinkAdapter::OnExternVectorArrayChanged(const TArray<FVector>& InExternVectorArray)
{
	Source->OnExternVectorArrayChanged(InExternVectorArray);
}

void UCounterCounterOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
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
