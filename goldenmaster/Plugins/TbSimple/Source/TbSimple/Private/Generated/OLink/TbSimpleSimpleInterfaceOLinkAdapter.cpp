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
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "TbSimpleSimpleInterfaceOLinkSource.h"

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
		BackendService->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropBoolChanged);
		BackendService->GetPropIntChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropIntChanged);
		BackendService->GetPropInt32ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropInt32Changed);
		BackendService->GetPropInt64ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropInt64Changed);
		BackendService->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloatChanged);
		BackendService->GetPropFloat32ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloat32Changed);
		BackendService->GetPropFloat64ChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloat64Changed);
		BackendService->GetPropStringChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropStringChanged);
		BackendService->GetPropReadOnlyStringChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropReadOnlyStringChanged);
		BackendService->GetSigVoidSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigVoid);
		BackendService->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigBool);
		BackendService->GetSigIntSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt);
		BackendService->GetSigInt32SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt32);
		BackendService->GetSigInt64SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt64);
		BackendService->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat);
		BackendService->GetSigFloat32SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat32);
		BackendService->GetSigFloat64SignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat64);
		BackendService->GetSigStringSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface HmiFrontDisplay is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropIntChanged);
	BackendService->GetPropInt32ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropInt32Changed);
	BackendService->GetPropInt64ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropInt64Changed);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloatChanged);
	BackendService->GetPropFloat32ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloat32Changed);
	BackendService->GetPropFloat64ChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropFloat64Changed);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropStringChanged);
	BackendService->GetPropReadOnlyStringChangedDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnPropReadOnlyStringChanged);
	BackendService->GetSigVoidSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigVoid);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt);
	BackendService->GetSigInt32SignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt32);
	BackendService->GetSigInt64SignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigInt64);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat);
	BackendService->GetSigFloat32SignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat32);
	BackendService->GetSigFloat64SignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat64);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTbSimpleSimpleInterfaceOLinkAdapter::OnSigString);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigVoid()
{
	Source->OnSigVoid();
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

void UTbSimpleSimpleInterfaceOLinkAdapter::OnSigFloat32(float ParamFloa32)
{
	Source->OnSigFloat32(ParamFloa32);
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

void UTbSimpleSimpleInterfaceOLinkAdapter::OnPropReadOnlyStringChanged(const FString& InPropReadOnlyString)
{
	Source->OnPropReadOnlyStringChanged(InPropReadOnlyString);
}

void UTbSimpleSimpleInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost)
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