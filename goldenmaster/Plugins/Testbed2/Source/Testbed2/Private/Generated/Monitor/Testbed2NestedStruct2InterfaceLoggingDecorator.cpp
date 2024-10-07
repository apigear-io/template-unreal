
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
#include "Generated/Monitor/Testbed2NestedStruct2InterfaceLoggingDecorator.h"
#include "Testbed2.trace.h"
#include "Generated/Testbed2Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTestbed2NestedStruct2InterfaceLoggingDecorator);
UTestbed2NestedStruct2InterfaceLoggingDecorator::UTestbed2NestedStruct2InterfaceLoggingDecorator()
	: UAbstractTestbed2NestedStruct2Interface()
{
}

UTestbed2NestedStruct2InterfaceLoggingDecorator::~UTestbed2NestedStruct2InterfaceLoggingDecorator() = default;

void UTestbed2NestedStruct2InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(FTestbed2ModuleFactory::createITestbed2NestedStruct2InterfaceInterface(Collection));
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed2NestedStruct2InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2NestedStruct2Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp1Changed);
		BackendSignals->OnProp2Changed.RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp2Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig1);
		BackendSignals->OnSig2Signal.RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig2);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed2NestedStruct2Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed2NestedStruct2InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2NestedStruct2Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp1Changed);
	BackendSignals->OnProp2Changed.AddDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp2Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig1);
	BackendSignals->OnSig2Signal.AddDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig2);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig1(const FTestbed2NestedStruct1& InParam1)
{
	Testbed2NestedStruct2InterfaceTracer::trace_signalSig1(InParam1);
	Execute__GetSignals(this)->OnSig1Signal.Broadcast(InParam1);
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig2(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2)
{
	Testbed2NestedStruct2InterfaceTracer::trace_signalSig2(InParam1, InParam2);
	Execute__GetSignals(this)->OnSig2Signal.Broadcast(InParam1, InParam2);
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute__GetSignals(this)->OnProp1Changed.Broadcast(InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp2Changed(const FTestbed2NestedStruct2& InProp2)
{
	Testbed2NestedStruct2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Execute__GetSignals(this)->OnProp2Changed.Broadcast(InProp2);
}

FTestbed2NestedStruct2 UTestbed2NestedStruct2InterfaceLoggingDecorator::GetProp2_Implementation() const
{
	return BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceLoggingDecorator::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceLoggingDecorator::Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
}
