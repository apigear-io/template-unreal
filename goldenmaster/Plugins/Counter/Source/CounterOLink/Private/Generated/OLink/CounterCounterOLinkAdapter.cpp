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

#include "Counter/Generated/OLink/CounterCounterOLinkAdapter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Counter/Generated/api/Counter.json.adapter.h"
#include "OLinkClientConnection.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "CounterCounterOLinkSource.h"
#include "OLinkCommon.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)

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
		UCounterCounterSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service CounterCounter"));
		if (OnVectorChangedHandle.IsValid())
		{
			BackendSignals->OnVectorChanged.Remove(OnVectorChangedHandle);
			OnVectorChangedHandle.Reset();
		}
		if (OnExternVectorChangedHandle.IsValid())
		{
			BackendSignals->OnExternVectorChanged.Remove(OnExternVectorChangedHandle);
			OnExternVectorChangedHandle.Reset();
		}
		if (OnVectorArrayChangedHandle.IsValid())
		{
			BackendSignals->OnVectorArrayChanged.Remove(OnVectorArrayChangedHandle);
			OnVectorArrayChangedHandle.Reset();
		}
		if (OnExternVectorArrayChangedHandle.IsValid())
		{
			BackendSignals->OnExternVectorArrayChanged.Remove(OnExternVectorArrayChangedHandle);
			OnExternVectorArrayChangedHandle.Reset();
		}
		if (OnValueChangedSignalHandle.IsValid())
		{
			BackendSignals->OnValueChangedSignal.Remove(OnValueChangedSignalHandle);
			OnValueChangedSignalHandle.Reset();
		}
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface CounterCounter is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UCounterCounterSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service CounterCounter"));
	// connect property changed signals or simple events
	OnVectorChangedHandle = BackendSignals->OnVectorChanged.AddUObject(this, &UCounterCounterOLinkAdapter::OnVectorChanged);
	OnExternVectorChangedHandle = BackendSignals->OnExternVectorChanged.AddUObject(this, &UCounterCounterOLinkAdapter::OnExternVectorChanged);
	OnVectorArrayChangedHandle = BackendSignals->OnVectorArrayChanged.AddUObject(this, &UCounterCounterOLinkAdapter::OnVectorArrayChanged);
	OnExternVectorArrayChangedHandle = BackendSignals->OnExternVectorArrayChanged.AddUObject(this, &UCounterCounterOLinkAdapter::OnExternVectorArrayChanged);
	OnValueChangedSignalHandle = BackendSignals->OnValueChangedSignal.AddUObject(this, &UCounterCounterOLinkAdapter::OnValueChanged);

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
#else  // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)

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
}

void UCounterCounterOLinkAdapter::OnValueChanged(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
}

void UCounterCounterOLinkAdapter::OnVectorChanged(const FCustomTypesVector3D& InVector)
{
}

void UCounterCounterOLinkAdapter::OnExternVectorChanged(const FVector& InExternVector)
{
}

void UCounterCounterOLinkAdapter::OnVectorArrayChanged(const TArray<FCustomTypesVector3D>& InVectorArray)
{
}

void UCounterCounterOLinkAdapter::OnExternVectorArrayChanged(const TArray<FVector>& InExternVectorArray)
{
}

void UCounterCounterOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
