
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
#include "Generated/Monitor/Testbed2ManyParamInterfaceLoggingDecorator.h"
#include "Generated/Monitor/Testbed2.trace.h"
#include "Generated/Monitor/Testbed2Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTestbed2ManyParamInterfaceLoggingDecorator);
UTestbed2ManyParamInterfaceLoggingDecorator::UTestbed2ManyParamInterfaceLoggingDecorator()
	: UAbstractTestbed2ManyParamInterface()
{
}

UTestbed2ManyParamInterfaceLoggingDecorator::~UTestbed2ManyParamInterfaceLoggingDecorator() = default;

void UTestbed2ManyParamInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService(FTestbed2ModuleFactory::createITestbed2ManyParamInterfaceInterface(GetGameInstance(), Collection));
#else
	setBackendService(FTestbed2ModuleFactory::createITestbed2ManyParamInterfaceInterface(Collection));
#endif
}

void UTestbed2ManyParamInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTestbed2ManyParamInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed2ManyParamInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed2ManyParamInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2ManyParamInterface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp1Changed);
		BackendSignals->OnProp2Changed.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp2Changed);
		BackendSignals->OnProp3Changed.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp3Changed);
		BackendSignals->OnProp4Changed.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp4Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig1);
		BackendSignals->OnSig2Signal.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig2);
		BackendSignals->OnSig3Signal.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig3);
		BackendSignals->OnSig4Signal.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig4);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed2ManyParamInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed2ManyParamInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2ManyParamInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp1Changed);
	BackendSignals->OnProp2Changed.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp2Changed);
	BackendSignals->OnProp3Changed.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp3Changed);
	BackendSignals->OnProp4Changed.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp4Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig1);
	BackendSignals->OnSig2Signal.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig2);
	BackendSignals->OnSig3Signal.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig3);
	BackendSignals->OnSig4Signal.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig4);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());
	Prop3 = BackendService->Execute_GetProp3(BackendService.GetObject());
	Prop4 = BackendService->Execute_GetProp4(BackendService.GetObject());
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnSig1(int32 InParam1)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig1(InParam1);
	Execute__GetSignals(this)->OnSig1Signal.Broadcast(InParam1);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnSig2(int32 InParam1, int32 InParam2)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig2(InParam1, InParam2);
	Execute__GetSignals(this)->OnSig2Signal.Broadcast(InParam1, InParam2);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnSig3(int32 InParam1, int32 InParam2, int32 InParam3)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig3(InParam1, InParam2, InParam3);
	Execute__GetSignals(this)->OnSig3Signal.Broadcast(InParam1, InParam2, InParam3);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnSig4(int32 InParam1, int32 InParam2, int32 InParam3, int32 InParam4)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig4(InParam1, InParam2, InParam3, InParam4);
	Execute__GetSignals(this)->OnSig4Signal.Broadcast(InParam1, InParam2, InParam3, InParam4);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnProp1Changed(int32 InProp1)
{
	Testbed2ManyParamInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute__GetSignals(this)->OnProp1Changed.Broadcast(InProp1);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp1_Implementation(int32 InProp1)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnProp2Changed(int32 InProp2)
{
	Testbed2ManyParamInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Execute__GetSignals(this)->OnProp2Changed.Broadcast(InProp2);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp2_Implementation() const
{
	return BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp2_Implementation(int32 InProp2)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnProp3Changed(int32 InProp3)
{
	Testbed2ManyParamInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop3 = InProp3;
	Execute__GetSignals(this)->OnProp3Changed.Broadcast(InProp3);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp3_Implementation() const
{
	return BackendService->Execute_GetProp3(BackendService.GetObject());
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp3_Implementation(int32 InProp3)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp3(InProp3);
	BackendService->Execute_SetProp3(BackendService.GetObject(), InProp3);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnProp4Changed(int32 InProp4)
{
	Testbed2ManyParamInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop4 = InProp4;
	Execute__GetSignals(this)->OnProp4Changed.Broadcast(InProp4);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp4_Implementation() const
{
	return BackendService->Execute_GetProp4(BackendService.GetObject());
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp4_Implementation(int32 InProp4)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp4(InProp4);
	BackendService->Execute_SetProp4(BackendService.GetObject(), InProp4);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::Func1_Implementation(int32 Param1)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::Func2_Implementation(int32 Param1, int32 Param2)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::Func3_Implementation(int32 Param1, int32 Param2, int32 Param3)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc3(Param1, Param2, Param3);
	return BackendService->Execute_Func3(BackendService.GetObject(), Param1, Param2, Param3);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc4(Param1, Param2, Param3, Param4);
	return BackendService->Execute_Func4(BackendService.GetObject(), Param1, Param2, Param3, Param4);
}
