
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
#include "Generated/Monitor/Testbed2NestedStruct3InterfaceLoggingDecorator.h"
#include "Implementation/Testbed2NestedStruct3Interface.h"
#include "Testbed2.trace.h"
#include "Testbed2Factory.h"
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
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService(FTestbed2ModuleFactory::createITestbed2NestedStruct3InterfaceInterface(GetGameInstance(), Collection));
#else
	setBackendService(FTestbed2ModuleFactory::createITestbed2NestedStruct3InterfaceInterface(Collection));
#endif
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
		UTestbed2NestedStruct3InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2NestedStruct3Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp1Changed);
		BackendSignals->OnProp2Changed.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp2Changed);
		BackendSignals->OnProp3Changed.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp3Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig1);
		BackendSignals->OnSig2Signal.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig2);
		BackendSignals->OnSig3Signal.RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig3);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed2NestedStruct3Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed2NestedStruct3InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2NestedStruct3Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp1Changed);
	BackendSignals->OnProp2Changed.AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp2Changed);
	BackendSignals->OnProp3Changed.AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp3Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig1);
	BackendSignals->OnSig2Signal.AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig2);
	BackendSignals->OnSig3Signal.AddDynamic(this, &UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig3);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());
	Prop3 = BackendService->Execute_GetProp3(BackendService.GetObject());
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig1(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct3InterfaceTracer::trace_signalSig1(Param1);
	Execute__GetSignals(this)->OnSig1Signal.Broadcast(Param1);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Testbed2NestedStruct3InterfaceTracer::trace_signalSig2(Param1, Param2);
	Execute__GetSignals(this)->OnSig2Signal.Broadcast(Param1, Param2);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnSig3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	Testbed2NestedStruct3InterfaceTracer::trace_signalSig3(Param1, Param2, Param3);
	Execute__GetSignals(this)->OnSig3Signal.Broadcast(Param1, Param2, Param3);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct3InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute__GetSignals(this)->OnProp1Changed.Broadcast(InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp2Changed(const FTestbed2NestedStruct2& InProp2)
{
	Testbed2NestedStruct3InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Execute__GetSignals(this)->OnProp2Changed.Broadcast(InProp2);
}

FTestbed2NestedStruct2 UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp2_Implementation() const
{
	return BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::OnProp3Changed(const FTestbed2NestedStruct3& InProp3)
{
	Testbed2NestedStruct3InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop3 = InProp3;
	Execute__GetSignals(this)->OnProp3Changed.Broadcast(InProp3);
}

FTestbed2NestedStruct3 UTestbed2NestedStruct3InterfaceLoggingDecorator::GetProp3_Implementation() const
{
	return BackendService->Execute_GetProp3(BackendService.GetObject());
}

void UTestbed2NestedStruct3InterfaceLoggingDecorator::SetProp3_Implementation(const FTestbed2NestedStruct3& InProp3)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callSetProp3(InProp3);
	BackendService->Execute_SetProp3(BackendService.GetObject(), InProp3);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLoggingDecorator::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLoggingDecorator::Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceLoggingDecorator::Func3_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	Testbed2NestedStruct3InterfaceTracer::trace_callFunc3(Param1, Param2, Param3);
	return BackendService->Execute_Func3(BackendService.GetObject(), Param1, Param2, Param3);
}
