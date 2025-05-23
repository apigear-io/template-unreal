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

#include "Testbed1/Generated/OLink/Testbed1StructArray2InterfaceOLinkAdapter.h"
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
#include "Testbed1StructArray2InterfaceOLinkSource.h"
#include "OLinkCommon.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)

using namespace ApiGear::ObjectLink;
UTestbed1StructArray2InterfaceOLinkAdapter::UTestbed1StructArray2InterfaceOLinkAdapter()
	: Source(std::make_shared<Testbed1StructArray2InterfaceOLinkSource>())
{
}

void UTestbed1StructArray2InterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed1StructArray2InterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTestbed1StructArray2InterfaceOLinkAdapter::setBackendService(TScriptInterface<ITestbed1StructArray2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed1StructArray2InterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructArray2Interface"));
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
		if (OnPropFloatChangedHandle.IsValid())
		{
			BackendSignals->OnPropFloatChanged.Remove(OnPropFloatChangedHandle);
			OnPropFloatChangedHandle.Reset();
		}
		if (OnPropStringChangedHandle.IsValid())
		{
			BackendSignals->OnPropStringChanged.Remove(OnPropStringChangedHandle);
			OnPropStringChangedHandle.Reset();
		}
		if (OnPropEnumChangedHandle.IsValid())
		{
			BackendSignals->OnPropEnumChanged.Remove(OnPropEnumChangedHandle);
			OnPropEnumChangedHandle.Reset();
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
		if (OnSigFloatSignalHandle.IsValid())
		{
			BackendSignals->OnSigFloatSignal.Remove(OnSigFloatSignalHandle);
			OnSigFloatSignalHandle.Reset();
		}
		if (OnSigStringSignalHandle.IsValid())
		{
			BackendSignals->OnSigStringSignal.Remove(OnSigStringSignalHandle);
			OnSigStringSignalHandle.Reset();
		}
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed1StructArray2Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed1StructArray2InterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service Testbed1StructArray2Interface"));
	// connect property changed signals or simple events
	OnPropBoolChangedHandle = BackendSignals->OnPropBoolChanged.AddUObject(this, &UTestbed1StructArray2InterfaceOLinkAdapter::OnPropBoolChanged);
	OnPropIntChangedHandle = BackendSignals->OnPropIntChanged.AddUObject(this, &UTestbed1StructArray2InterfaceOLinkAdapter::OnPropIntChanged);
	OnPropFloatChangedHandle = BackendSignals->OnPropFloatChanged.AddUObject(this, &UTestbed1StructArray2InterfaceOLinkAdapter::OnPropFloatChanged);
	OnPropStringChangedHandle = BackendSignals->OnPropStringChanged.AddUObject(this, &UTestbed1StructArray2InterfaceOLinkAdapter::OnPropStringChanged);
	OnPropEnumChangedHandle = BackendSignals->OnPropEnumChanged.AddUObject(this, &UTestbed1StructArray2InterfaceOLinkAdapter::OnPropEnumChanged);
	OnSigBoolSignalHandle = BackendSignals->OnSigBoolSignal.AddUObject(this, &UTestbed1StructArray2InterfaceOLinkAdapter::OnSigBool);
	OnSigIntSignalHandle = BackendSignals->OnSigIntSignal.AddUObject(this, &UTestbed1StructArray2InterfaceOLinkAdapter::OnSigInt);
	OnSigFloatSignalHandle = BackendSignals->OnSigFloatSignal.AddUObject(this, &UTestbed1StructArray2InterfaceOLinkAdapter::OnSigFloat);
	OnSigStringSignalHandle = BackendSignals->OnSigStringSignal.AddUObject(this, &UTestbed1StructArray2InterfaceOLinkAdapter::OnSigString);

	// update olink source with new backend
	Source->setBackendService(InService);
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnSigBool(const FTestbed1StructBoolWithArray& ParamBool)
{
	Source->OnSigBool(ParamBool);
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnSigInt(const FTestbed1StructIntWithArray& ParamInt)
{
	Source->OnSigInt(ParamInt);
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnSigFloat(const FTestbed1StructFloatWithArray& ParamFloat)
{
	Source->OnSigFloat(ParamFloat);
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnSigString(const FTestbed1StructStringWithArray& ParamString)
{
	Source->OnSigString(ParamString);
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnPropBoolChanged(const FTestbed1StructBoolWithArray& InPropBool)
{
	Source->OnPropBoolChanged(InPropBool);
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnPropIntChanged(const FTestbed1StructIntWithArray& InPropInt)
{
	Source->OnPropIntChanged(InPropInt);
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnPropFloatChanged(const FTestbed1StructFloatWithArray& InPropFloat)
{
	Source->OnPropFloatChanged(InPropFloat);
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnPropStringChanged(const FTestbed1StructStringWithArray& InPropString)
{
	Source->OnPropStringChanged(InPropString);
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnPropEnumChanged(const FTestbed1StructEnumWithArray& InPropEnum)
{
	Source->OnPropEnumChanged(InPropEnum);
}

void UTestbed1StructArray2InterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
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

UTestbed1StructArray2InterfaceOLinkAdapter::UTestbed1StructArray2InterfaceOLinkAdapter()
	: Source(std::make_shared<Testbed1StructArray2InterfaceOLinkSource>())
{
}

void UTestbed1StructArray2InterfaceOLinkAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestbed1StructArray2InterfaceOLinkAdapter::Deinitialize()
{
	Super::Deinitialize();
}

void UTestbed1StructArray2InterfaceOLinkAdapter::setBackendService(TScriptInterface<ITestbed1StructArray2InterfaceInterface> InService)
{
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnSigBool(const FTestbed1StructBoolWithArray& ParamBool)
{
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnSigInt(const FTestbed1StructIntWithArray& ParamInt)
{
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnSigFloat(const FTestbed1StructFloatWithArray& ParamFloat)
{
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnSigString(const FTestbed1StructStringWithArray& ParamString)
{
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnPropBoolChanged(const FTestbed1StructBoolWithArray& InPropBool)
{
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnPropIntChanged(const FTestbed1StructIntWithArray& InPropInt)
{
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnPropFloatChanged(const FTestbed1StructFloatWithArray& InPropFloat)
{
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnPropStringChanged(const FTestbed1StructStringWithArray& InPropString)
{
}

void UTestbed1StructArray2InterfaceOLinkAdapter::OnPropEnumChanged(const FTestbed1StructEnumWithArray& InPropEnum)
{
}

void UTestbed1StructArray2InterfaceOLinkAdapter::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
