

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
#include "Testbed2/Generated/Monitor/Testbed2NestedStruct3InterfaceLoggingDecorator.h"
#include "Testbed2Settings.h"
#include "Testbed2.trace.h"
#include "Testbed2/Generated/Testbed2Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTestbed2NestedStruct3InterfaceLoggingDecorator);
UTestbed2NestedStruct3InterfaceLoggingDecorator::UTestbed2NestedStruct3InterfaceLoggingDecorator()
	: UAbstractTestbed2NestedStruct3Interface()
{
}

UTestbed2NestedStruct3InterfaceLoggingDecorator::~UTestbed2NestedStruct3InterfaceLoggingDecorator() = default;

void UTestbed2NestedStruct3InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTestbed2Settings::GetITestbed2NestedStruct3InterfaceInterfaceForLogging(Collection));
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed2NestedStruct3InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service Testbed2NestedStruct3Interface"));
		BackendPublisher->OnProp1ChangedBP.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp1Changed);
		BackendPublisher->OnProp2ChangedBP.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp2Changed);
		BackendPublisher->OnProp3ChangedBP.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp3Changed);
		BackendPublisher->OnSig1SignalBP.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig1);
		BackendPublisher->OnSig2SignalBP.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig2);
		BackendPublisher->OnSig3SignalBP.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig3);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed2NestedStruct3Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed2NestedStruct3InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service Testbed2NestedStruct3Interface"));
	// connect property changed signals or simple events
	BackendPublisher->OnProp1ChangedBP.AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp1Changed);
	BackendPublisher->OnProp2ChangedBP.AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp2Changed);
	BackendPublisher->OnProp3ChangedBP.AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp3Changed);
	BackendPublisher->OnSig1SignalBP.AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig1);
	BackendPublisher->OnSig2SignalBP.AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig2);
	BackendPublisher->OnSig3SignalBP.AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig3);
	// populate service state to proxy
	Prop1 = BackendService->GetProp1();
	Prop2 = BackendService->GetProp2();
	Prop3 = BackendService->GetProp3();
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig1(const FTestbed2NestedStruct1& InParam1)
{
	Testbed2NestedStruct3InterfaceTracer::trace_signalSig1(InParam1);
	_GetPublisher()->BroadcastSig1Signal(InParam1);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig2(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2)
{
	Testbed2NestedStruct3InterfaceTracer::trace_signalSig2(InParam1, InParam2);
	_GetPublisher()->BroadcastSig2Signal(InParam1, InParam2);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig3(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2, const FTestbed2NestedStruct3& InParam3)
{
	Testbed2NestedStruct3InterfaceTracer::trace_signalSig3(InParam1, InParam2, InParam3);
	_GetPublisher()->BroadcastSig3Signal(InParam1, InParam2, InParam3);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct3InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	_GetPublisher()->BroadcastProp1Changed(InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp1() const
{
	return BackendService->GetProp1();
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->SetProp1(InProp1);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp2Changed(const FTestbed2NestedStruct2& InProp2)
{
	Testbed2NestedStruct3InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	_GetPublisher()->BroadcastProp2Changed(InProp2);
}

FTestbed2NestedStruct2 UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp2() const
{
	return BackendService->GetProp2();
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::SetProp2(const FTestbed2NestedStruct2& InProp2)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->SetProp2(InProp2);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp3Changed(const FTestbed2NestedStruct3& InProp3)
{
	Testbed2NestedStruct3InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop3 = InProp3;
	_GetPublisher()->BroadcastProp3Changed(InProp3);
}

FTestbed2NestedStruct3 UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp3() const
{
	return BackendService->GetProp3();
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::SetProp3(const FTestbed2NestedStruct3& InProp3)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callSetProp3(InProp3);
	BackendService->SetProp3(InProp3);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLoggingDecorator::Func1(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Func1(Param1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLoggingDecorator::Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Func2(Param1, Param2);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLoggingDecorator::Func3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callFunc3(Param1, Param2, Param3);
	return BackendService->Func3(Param1, Param2, Param3);
}
