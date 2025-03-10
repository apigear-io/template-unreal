

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
#include "Testbed2/Generated/Monitor/Testbed2NestedStruct2InterfaceLoggingDecorator.h"
#include "Testbed2Settings.h"
#include "Testbed2.trace.h"
#include "Testbed2/Generated/Testbed2Factory.h"
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
	setBackendService(UTestbed2Settings::GetITestbed2NestedStruct2InterfaceInterfaceForLogging(Collection));
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
		UTestbed2NestedStruct2InterfaceSignals* BackendSignals = BackendService->_GetSignals();
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
	UTestbed2NestedStruct2InterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2NestedStruct2Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp1Changed);
	BackendSignals->OnProp2Changed.AddDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp2Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig1);
	BackendSignals->OnSig2Signal.AddDynamic(this, &UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig2);
	// populate service state to proxy
	Prop1 = BackendService->GetProp1();
	Prop2 = BackendService->GetProp2();
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig1(const FTestbed2NestedStruct1& InParam1)
{
	Testbed2NestedStruct2InterfaceTracer::trace_signalSig1(InParam1);
	_GetSignals()->BroadcastSig1Signal(InParam1);
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::OnSig2(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2)
{
	Testbed2NestedStruct2InterfaceTracer::trace_signalSig2(InParam1, InParam2);
	_GetSignals()->BroadcastSig2Signal(InParam1, InParam2);
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	_GetSignals()->BroadcastProp1Changed(InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceLoggingDecorator::GetProp1() const
{
	return BackendService->GetProp1();
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->SetProp1(InProp1);
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::OnProp2Changed(const FTestbed2NestedStruct2& InProp2)
{
	Testbed2NestedStruct2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	_GetSignals()->BroadcastProp2Changed(InProp2);
}

FTestbed2NestedStruct2 UTestbed2NestedStruct2InterfaceLoggingDecorator::GetProp2() const
{
	return BackendService->GetProp2();
}

void UTestbed2NestedStruct2InterfaceLoggingDecorator::SetProp2(const FTestbed2NestedStruct2& InProp2)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->SetProp2(InProp2);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceLoggingDecorator::Func1(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Func1(Param1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceLoggingDecorator::Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Func2(Param1, Param2);
}
