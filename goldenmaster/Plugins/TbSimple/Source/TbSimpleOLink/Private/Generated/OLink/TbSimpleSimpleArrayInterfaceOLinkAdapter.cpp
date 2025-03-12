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

#include "TbSimple/Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkAdapter.h"
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
#include "TbSimpleSimpleArrayInterfaceOLinkSource.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID)

using namespace ApiGear::ObjectLink;
UTbSimpleSimpleArrayInterfaceOLinkAdapter::UTbSimpleSimpleArrayInterfaceOLinkAdapter()
	: Source(std::make_shared<TbSimpleSimpleArrayInterfaceOLinkSource>())
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleSimpleArrayInterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleSimpleArrayInterface"));
		if (OnPropBoolChangedHandle.IsValid())
		{
			BackendSignals->OnPropBoolChanged.Remove(OnPropBoolChangedHandle);
			OnPropBoolChangedHandle.Reset();
		}
		if (OnPropIntChangedHandle.IsValid())
		{
			BackendSignals->OnPropIntChanged.Remove(OnPropIntChangedHandle);
			OnPropIntChangedHandle.Reset();
		}
		if (OnPropInt32ChangedHandle.IsValid())
		{
			BackendSignals->OnPropInt32Changed.Remove(OnPropInt32ChangedHandle);
			OnPropInt32ChangedHandle.Reset();
		}
		if (OnPropInt64ChangedHandle.IsValid())
		{
			BackendSignals->OnPropInt64Changed.Remove(OnPropInt64ChangedHandle);
			OnPropInt64ChangedHandle.Reset();
		}
		if (OnPropFloatChangedHandle.IsValid())
		{
			BackendSignals->OnPropFloatChanged.Remove(OnPropFloatChangedHandle);
			OnPropFloatChangedHandle.Reset();
		}
		if (OnPropFloat32ChangedHandle.IsValid())
		{
			BackendSignals->OnPropFloat32Changed.Remove(OnPropFloat32ChangedHandle);
			OnPropFloat32ChangedHandle.Reset();
		}
		if (OnPropFloat64ChangedHandle.IsValid())
		{
			BackendSignals->OnPropFloat64Changed.Remove(OnPropFloat64ChangedHandle);
			OnPropFloat64ChangedHandle.Reset();
		}
		if (OnPropStringChangedHandle.IsValid())
		{
			BackendSignals->OnPropStringChanged.Remove(OnPropStringChangedHandle);
			OnPropStringChangedHandle.Reset();
		}
		if (OnPropReadOnlyStringChangedHandle.IsValid())
		{
			BackendSignals->OnPropReadOnlyStringChanged.Remove(OnPropReadOnlyStringChangedHandle);
			OnPropReadOnlyStringChangedHandle.Reset();
		}
		if (OnSigBoolSignalHandle.IsValid())
		{
			BackendSignals->OnSigBoolSignal.Remove(OnSigBoolSignalHandle);
			OnSigBoolSignalHandle.Reset();
		}
		if (OnSigIntSignalHandle.IsValid())
		{
			BackendSignals->OnSigIntSignal.Remove(OnSigIntSignalHandle);
			OnSigIntSignalHandle.Reset();
		}
		if (OnSigInt32SignalHandle.IsValid())
		{
			BackendSignals->OnSigInt32Signal.Remove(OnSigInt32SignalHandle);
			OnSigInt32SignalHandle.Reset();
		}
		if (OnSigInt64SignalHandle.IsValid())
		{
			BackendSignals->OnSigInt64Signal.Remove(OnSigInt64SignalHandle);
			OnSigInt64SignalHandle.Reset();
		}
		if (OnSigFloatSignalHandle.IsValid())
		{
			BackendSignals->OnSigFloatSignal.Remove(OnSigFloatSignalHandle);
			OnSigFloatSignalHandle.Reset();
		}
		if (OnSigFloat32SignalHandle.IsValid())
		{
			BackendSignals->OnSigFloat32Signal.Remove(OnSigFloat32SignalHandle);
			OnSigFloat32SignalHandle.Reset();
		}
		if (OnSigFloat64SignalHandle.IsValid())
		{
			BackendSignals->OnSigFloat64Signal.Remove(OnSigFloat64SignalHandle);
			OnSigFloat64SignalHandle.Reset();
		}
		if (OnSigStringSignalHandle.IsValid())
		{
			BackendSignals->OnSigStringSignal.Remove(OnSigStringSignalHandle);
			OnSigStringSignalHandle.Reset();
		}
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleSimpleArrayInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleSimpleArrayInterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSimpleSimpleArrayInterface"));
	// connect property changed signals or simple events
	OnPropBoolChangedHandle = BackendSignals->OnPropBoolChanged.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropBoolChanged);
	OnPropIntChangedHandle = BackendSignals->OnPropIntChanged.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropIntChanged);
	OnPropInt32ChangedHandle = BackendSignals->OnPropInt32Changed.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropInt32Changed);
	OnPropInt64ChangedHandle = BackendSignals->OnPropInt64Changed.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropInt64Changed);
	OnPropFloatChangedHandle = BackendSignals->OnPropFloatChanged.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloatChanged);
	OnPropFloat32ChangedHandle = BackendSignals->OnPropFloat32Changed.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloat32Changed);
	OnPropFloat64ChangedHandle = BackendSignals->OnPropFloat64Changed.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloat64Changed);
	OnPropStringChangedHandle = BackendSignals->OnPropStringChanged.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropStringChanged);
	OnPropReadOnlyStringChangedHandle = BackendSignals->OnPropReadOnlyStringChanged.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropReadOnlyStringChanged);
	OnSigBoolSignalHandle = BackendSignals->OnSigBoolSignal.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigBool);
	OnSigIntSignalHandle = BackendSignals->OnSigIntSignal.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt);
	OnSigInt32SignalHandle = BackendSignals->OnSigInt32Signal.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt32);
	OnSigInt64SignalHandle = BackendSignals->OnSigInt64Signal.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt64);
	OnSigFloatSignalHandle = BackendSignals->OnSigFloatSignal.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat);
	OnSigFloat32SignalHandle = BackendSignals->OnSigFloat32Signal.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat32);
	OnSigFloat64SignalHandle = BackendSignals->OnSigFloat64Signal.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat64);
	OnSigStringSignalHandle = BackendSignals->OnSigStringSignal.AddUObject(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigString);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigBool(const TArray<bool>& ParamBool)
{
	Source->OnSigBool(ParamBool);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt(const TArray<int32>& ParamInt)
{
	Source->OnSigInt(ParamInt);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt32(const TArray<int32>& ParamInt32)
{
	Source->OnSigInt32(ParamInt32);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt64(const TArray<int64>& ParamInt64)
{
	Source->OnSigInt64(ParamInt64);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat(const TArray<float>& ParamFloat)
{
	Source->OnSigFloat(ParamFloat);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat32(const TArray<float>& ParamFloa32)
{
	Source->OnSigFloat32(ParamFloa32);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat64(const TArray<double>& ParamFloat64)
{
	Source->OnSigFloat64(ParamFloat64);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigString(const TArray<FString>& ParamString)
{
	Source->OnSigString(ParamString);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropBoolChanged(const TArray<bool>& InPropBool)
{
	Source->OnPropBoolChanged(InPropBool);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropIntChanged(const TArray<int32>& InPropInt)
{
	Source->OnPropIntChanged(InPropInt);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropInt32Changed(const TArray<int32>& InPropInt32)
{
	Source->OnPropInt32Changed(InPropInt32);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropInt64Changed(const TArray<int64>& InPropInt64)
{
	Source->OnPropInt64Changed(InPropInt64);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloatChanged(const TArray<float>& InPropFloat)
{
	Source->OnPropFloatChanged(InPropFloat);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloat32Changed(const TArray<float>& InPropFloat32)
{
	Source->OnPropFloat32Changed(InPropFloat32);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloat64Changed(const TArray<double>& InPropFloat64)
{
	Source->OnPropFloat64Changed(InPropFloat64);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropStringChanged(const TArray<FString>& InPropString)
{
	Source->OnPropStringChanged(InPropString);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropReadOnlyStringChanged(const FString& InPropReadOnlyString)
{
	Source->OnPropReadOnlyStringChanged(InPropReadOnlyString);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
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

UTbSimpleSimpleArrayInterfaceOLinkAdapter::UTbSimpleSimpleArrayInterfaceOLinkAdapter()
	: Source(std::make_shared<TbSimpleSimpleArrayInterfaceOLinkSource>())
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> InService)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigBool(const TArray<bool>& ParamBool)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt(const TArray<int32>& ParamInt)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt32(const TArray<int32>& ParamInt32)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt64(const TArray<int64>& ParamInt64)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat(const TArray<float>& ParamFloat)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat32(const TArray<float>& ParamFloa32)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat64(const TArray<double>& ParamFloat64)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigString(const TArray<FString>& ParamString)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropBoolChanged(const TArray<bool>& InPropBool)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropIntChanged(const TArray<int32>& InPropInt)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropInt32Changed(const TArray<int32>& InPropInt32)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropInt64Changed(const TArray<int64>& InPropInt64)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloatChanged(const TArray<float>& InPropFloat)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloat32Changed(const TArray<float>& InPropFloat32)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloat64Changed(const TArray<double>& InPropFloat64)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropStringChanged(const TArray<FString>& InPropString)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropReadOnlyStringChanged(const FString& InPropReadOnlyString)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
