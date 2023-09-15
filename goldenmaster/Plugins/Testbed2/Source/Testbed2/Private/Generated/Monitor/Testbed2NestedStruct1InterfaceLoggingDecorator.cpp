
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
#include "Generated/Monitor/Testbed2NestedStruct1InterfaceLoggingDecorator.h"
#include "Implementation/Testbed2NestedStruct1Interface.h"
#include "Testbed2.trace.h"
#include "Testbed2Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTestbed2NestedStruct1InterfaceLoggingDecorator);
UTestbed2NestedStruct1InterfaceLoggingDecorator::UTestbed2NestedStruct1InterfaceLoggingDecorator()
	: UAbstractTestbed2NestedStruct1Interface()
{
}

UTestbed2NestedStruct1InterfaceLoggingDecorator::~UTestbed2NestedStruct1InterfaceLoggingDecorator() = default;

void UTestbed2NestedStruct1InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService(FTestbed2ModuleFactory::createITestbed2NestedStruct1InterfaceInterface(GetGameInstance(), Collection));
#else
	setBackendService(FTestbed2ModuleFactory::createITestbed2NestedStruct1InterfaceInterface(Collection));
#endif
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed2NestedStruct1InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2NestedStruct1Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTestbed2NestedStruct1InterfaceLoggingDecorator::OnProp1Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTestbed2NestedStruct1InterfaceLoggingDecorator::OnSig1);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed2NestedStruct1Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed2NestedStruct1InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2NestedStruct1Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTestbed2NestedStruct1InterfaceLoggingDecorator::OnProp1Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTestbed2NestedStruct1InterfaceLoggingDecorator::OnSig1);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::OnSig1(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct1InterfaceTracer::trace_signalSig1(Param1);
	Execute__GetSignals(this)->OnSig1Signal.Broadcast(Param1);
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct1InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute__GetSignals(this)->OnProp1Changed.Broadcast(InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTestbed2NestedStruct1InterfaceLoggingDecorator::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct1InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceLoggingDecorator::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct1InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}
