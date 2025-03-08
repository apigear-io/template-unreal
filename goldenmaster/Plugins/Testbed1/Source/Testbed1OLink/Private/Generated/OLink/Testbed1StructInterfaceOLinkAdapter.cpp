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

#include "Testbed1/Generated/OLink/Testbed1StructInterfaceOLinkAdapter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Testbed1/Generated/api/Testbed1.json.adapter.h"
#include "OLinkClientConnection.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "Testbed1StructInterfaceOLinkSource.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID)

using namespace ApiGear::ObjectLink;
UTestbed1StructInterfaceOLinkAdapter::UTestbed1StructInterfaceOLinkAdapter()
	: Source(std::make_shared<Testbed1StructInterfaceOLinkSource>())
{
}

void UTestbed1StructInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed1StructInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTestbed1StructInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITestbed1StructInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed1StructInterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructInterface"));
		BackendSignals->OnPropBoolChanged.RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropBoolChanged);
		BackendSignals->OnPropIntChanged.RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropIntChanged);
		BackendSignals->OnPropFloatChanged.RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropFloatChanged);
		BackendSignals->OnPropStringChanged.RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropStringChanged);
		BackendSignals->OnSigBoolSignal.RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigBool);
		BackendSignals->OnSigIntSignal.RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigInt);
		BackendSignals->OnSigFloatSignal.RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigFloat);
		BackendSignals->OnSigStringSignal.RemoveDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed1StructInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed1StructInterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service Testbed1StructInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnPropBoolChanged.AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropBoolChanged);
	BackendSignals->OnPropIntChanged.AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropIntChanged);
	BackendSignals->OnPropFloatChanged.AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropFloatChanged);
	BackendSignals->OnPropStringChanged.AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnPropStringChanged);
	BackendSignals->OnSigBoolSignal.AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigBool);
	BackendSignals->OnSigIntSignal.AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigInt);
	BackendSignals->OnSigFloatSignal.AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigFloat);
	BackendSignals->OnSigStringSignal.AddDynamic(this, &UTestbed1StructInterfaceOLinkAdapter::OnSigString);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UTestbed1StructInterfaceOLinkAdapter::OnSigBool(const FTestbed1StructBool& ParamBool)
{
	Source->OnSigBool(ParamBool);
}

void UTestbed1StructInterfaceOLinkAdapter::OnSigInt(const FTestbed1StructInt& ParamInt)
{
	Source->OnSigInt(ParamInt);
}

void UTestbed1StructInterfaceOLinkAdapter::OnSigFloat(const FTestbed1StructFloat& ParamFloat)
{
	Source->OnSigFloat(ParamFloat);
}

void UTestbed1StructInterfaceOLinkAdapter::OnSigString(const FTestbed1StructString& ParamString)
{
	Source->OnSigString(ParamString);
}

void UTestbed1StructInterfaceOLinkAdapter::OnPropBoolChanged(const FTestbed1StructBool& InPropBool)
{
	Source->OnPropBoolChanged(InPropBool);
}

void UTestbed1StructInterfaceOLinkAdapter::OnPropIntChanged(const FTestbed1StructInt& InPropInt)
{
	Source->OnPropIntChanged(InPropInt);
}

void UTestbed1StructInterfaceOLinkAdapter::OnPropFloatChanged(const FTestbed1StructFloat& InPropFloat)
{
	Source->OnPropFloatChanged(InPropFloat);
}

void UTestbed1StructInterfaceOLinkAdapter::OnPropStringChanged(const FTestbed1StructString& InPropString)
{
	Source->OnPropStringChanged(InPropString);
}

void UTestbed1StructInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
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

UTestbed1StructInterfaceOLinkAdapter::UTestbed1StructInterfaceOLinkAdapter()
	: Source(std::make_shared<Testbed1StructInterfaceOLinkSource>())
{
}

void UTestbed1StructInterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed1StructInterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTestbed1StructInterfaceOLinkAdapter::setBackendService(TScriptInterface<ITestbed1StructInterfaceInterface> InService)
{
}

void UTestbed1StructInterfaceOLinkAdapter::OnSigBool(const FTestbed1StructBool& ParamBool)
{
}

void UTestbed1StructInterfaceOLinkAdapter::OnSigInt(const FTestbed1StructInt& ParamInt)
{
}

void UTestbed1StructInterfaceOLinkAdapter::OnSigFloat(const FTestbed1StructFloat& ParamFloat)
{
}

void UTestbed1StructInterfaceOLinkAdapter::OnSigString(const FTestbed1StructString& ParamString)
{
}

void UTestbed1StructInterfaceOLinkAdapter::OnPropBoolChanged(const FTestbed1StructBool& InPropBool)
{
}

void UTestbed1StructInterfaceOLinkAdapter::OnPropIntChanged(const FTestbed1StructInt& InPropInt)
{
}

void UTestbed1StructInterfaceOLinkAdapter::OnPropFloatChanged(const FTestbed1StructFloat& InPropFloat)
{
}

void UTestbed1StructInterfaceOLinkAdapter::OnPropStringChanged(const FTestbed1StructString& InPropString)
{
}

void UTestbed1StructInterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
