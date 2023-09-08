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

#include "Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkAdapter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/TbSimple.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "TbSimpleSimpleArrayInterfaceOLinkSource.h"

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
		BackendService->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropBoolChanged);
		BackendService->GetPropIntChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropIntChanged);
		BackendService->GetPropInt32ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropInt32Changed);
		BackendService->GetPropInt64ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropInt64Changed);
		BackendService->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloatChanged);
		BackendService->GetPropFloat32ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloat32Changed);
		BackendService->GetPropFloat64ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloat64Changed);
		BackendService->GetPropStringChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropStringChanged);
		BackendService->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigBool);
		BackendService->GetSigIntSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt);
		BackendService->GetSigInt32SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt32);
		BackendService->GetSigInt64SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt64);
		BackendService->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat);
		BackendService->GetSigFloat32SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat32);
		BackendService->GetSigFloat64SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat64);
		BackendService->GetSigStringSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface HmiFrontDisplay is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropIntChanged);
	BackendService->GetPropInt32ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropInt32Changed);
	BackendService->GetPropInt64ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropInt64Changed);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloatChanged);
	BackendService->GetPropFloat32ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloat32Changed);
	BackendService->GetPropFloat64ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropFloat64Changed);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnPropStringChanged);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt);
	BackendService->GetSigInt32SignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt32);
	BackendService->GetSigInt64SignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigInt64);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat);
	BackendService->GetSigFloat32SignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat32);
	BackendService->GetSigFloat64SignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigFloat64);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceOLinkAdapter::OnSigString);

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

void UTbSimpleSimpleArrayInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost)
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