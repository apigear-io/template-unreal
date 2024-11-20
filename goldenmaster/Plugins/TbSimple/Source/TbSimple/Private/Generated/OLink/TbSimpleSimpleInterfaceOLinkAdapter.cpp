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

#include "Generated/OLink/TbSimpleSimpleInterfaceOLinkAdapter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/TbSimple.json.adapter.h"
#include "OLinkClientConnection.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "TbSimpleSimpleInterfaceOLinkSource.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID)

using namespace ApiGear::ObjectLink;
UTbSimpleSimpleInterfaceOLinkAdapter::UTbSimpleSimpleInterfaceOLinkAdapter()
	: Source(std::make_shared<TbSimpleSimpleInterfaceOLinkSource>())
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTbSimpleSimpleInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITbSimpleSimpleInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleSimpleInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleSimpleInterface"));
		BackendSignals->OnPropBoolChanged.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropBoolChanged);
		BackendSignals->OnPropIntChanged.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropIntChanged);
		BackendSignals->OnPropInt32Changed.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropInt32Changed);
		BackendSignals->OnPropInt64Changed.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropInt64Changed);
		BackendSignals->OnPropFloatChanged.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloatChanged);
		BackendSignals->OnPropFloat32Changed.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloat32Changed);
		BackendSignals->OnPropFloat64Changed.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloat64Changed);
		BackendSignals->OnPropStringChanged.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropStringChanged);
		BackendSignals->OnSigBoolSignal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigBool);
		BackendSignals->OnSigIntSignal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt);
		BackendSignals->OnSigInt32Signal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt32);
		BackendSignals->OnSigInt64Signal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt64);
		BackendSignals->OnSigFloatSignal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat);
		BackendSignals->OnSigFloat32Signal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat32);
		BackendSignals->OnSigFloat64Signal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat64);
		BackendSignals->OnSigStringSignal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleSimpleInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleSimpleInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service TbSimpleSimpleInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnPropBoolChanged.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropBoolChanged);
	BackendSignals->OnPropIntChanged.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropIntChanged);
	BackendSignals->OnPropInt32Changed.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropInt32Changed);
	BackendSignals->OnPropInt64Changed.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropInt64Changed);
	BackendSignals->OnPropFloatChanged.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloatChanged);
	BackendSignals->OnPropFloat32Changed.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloat32Changed);
	BackendSignals->OnPropFloat64Changed.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloat64Changed);
	BackendSignals->OnPropStringChanged.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropStringChanged);
	BackendSignals->OnSigBoolSignal.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigBool);
	BackendSignals->OnSigIntSignal.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt);
	BackendSignals->OnSigInt32Signal.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt32);
	BackendSignals->OnSigInt64Signal.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt64);
	BackendSignals->OnSigFloatSignal.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat);
	BackendSignals->OnSigFloat32Signal.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat32);
	BackendSignals->OnSigFloat64Signal.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat64);
	BackendSignals->OnSigStringSignal.AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigString);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigBool(bool bParamBool)
{
	Source->OnSigBool(bParamBool);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt(int32 ParamInt)
{
	Source->OnSigInt(ParamInt);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt32(int32 ParamInt32)
{
	Source->OnSigInt32(ParamInt32);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt64(int64 ParamInt64)
{
	Source->OnSigInt64(ParamInt64);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat(float ParamFloat)
{
	Source->OnSigFloat(ParamFloat);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat32(float ParamFloat32)
{
	Source->OnSigFloat32(ParamFloat32);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat64(double ParamFloat64)
{
	Source->OnSigFloat64(ParamFloat64);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigString(const FString& ParamString)
{
	Source->OnSigString(ParamString);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropBoolChanged(bool bInPropBool)
{
	Source->OnPropBoolChanged(bInPropBool);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropIntChanged(int32 InPropInt)
{
	Source->OnPropIntChanged(InPropInt);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropInt32Changed(int32 InPropInt32)
{
	Source->OnPropInt32Changed(InPropInt32);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropInt64Changed(int64 InPropInt64)
{
	Source->OnPropInt64Changed(InPropInt64);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloatChanged(float InPropFloat)
{
	Source->OnPropFloatChanged(InPropFloat);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloat32Changed(float InPropFloat32)
{
	Source->OnPropFloat32Changed(InPropFloat32);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloat64Changed(double InPropFloat64)
{
	Source->OnPropFloat64Changed(InPropFloat64);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropStringChanged(const FString& InPropString)
{
	Source->OnPropStringChanged(InPropString);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
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

UTbSimpleSimpleInterfaceOLinkAdapter::UTbSimpleSimpleInterfaceOLinkAdapter()
	: Source(std::make_shared<TbSimpleSimpleInterfaceOLinkSource>())
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTbSimpleSimpleInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITbSimpleSimpleInterfaceInterface> InService)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigBool(bool bParamBool)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt(int32 ParamInt)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt32(int32 ParamInt32)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt64(int64 ParamInt64)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat(float ParamFloat)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat32(float ParamFloat32)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat64(double ParamFloat64)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigString(const FString& ParamString)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropBoolChanged(bool bInPropBool)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropIntChanged(int32 InPropInt)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropInt32Changed(int32 InPropInt32)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropInt64Changed(int64 InPropInt64)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloatChanged(float InPropFloat)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloat32Changed(float InPropFloat32)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloat64Changed(double InPropFloat64)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropStringChanged(const FString& InPropString)
{
}

void UTbSimpleSimpleInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
