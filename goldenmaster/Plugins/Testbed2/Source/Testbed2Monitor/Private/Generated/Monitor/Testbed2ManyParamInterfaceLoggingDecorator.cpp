

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
#include "Testbed2/Generated/Monitor/Testbed2ManyParamInterfaceLoggingDecorator.h"
#include "Testbed2Settings.h"
#include "Testbed2.trace.h"
#include "Testbed2/Generated/Testbed2Factory.h"
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
	setBackendService(UTestbed2Settings::GetITestbed2ManyParamInterfaceInterfaceForLogging(Collection));
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
		UTestbed2ManyParamInterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2ManyParamInterface"));
		BackendSignals->OnProp1ChangedBP.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp1Changed);
		BackendSignals->OnProp2ChangedBP.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp2Changed);
		BackendSignals->OnProp3ChangedBP.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp3Changed);
		BackendSignals->OnProp4ChangedBP.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp4Changed);
		BackendSignals->OnSig1SignalBP.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig1);
		BackendSignals->OnSig2SignalBP.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig2);
		BackendSignals->OnSig3SignalBP.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig3);
		BackendSignals->OnSig4SignalBP.RemoveDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig4);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed2ManyParamInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed2ManyParamInterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed2ManyParamInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1ChangedBP.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp1Changed);
	BackendSignals->OnProp2ChangedBP.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp2Changed);
	BackendSignals->OnProp3ChangedBP.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp3Changed);
	BackendSignals->OnProp4ChangedBP.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnProp4Changed);
	BackendSignals->OnSig1SignalBP.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig1);
	BackendSignals->OnSig2SignalBP.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig2);
	BackendSignals->OnSig3SignalBP.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig3);
	BackendSignals->OnSig4SignalBP.AddDynamic(this, &UTestbed2ManyParamInterfaceLoggingDecorator::OnSig4);
	// populate service state to proxy
	Prop1 = BackendService->GetProp1();
	Prop2 = BackendService->GetProp2();
	Prop3 = BackendService->GetProp3();
	Prop4 = BackendService->GetProp4();
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnSig1(int32 InParam1)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig1(InParam1);
	_GetSignals()->BroadcastSig1Signal(InParam1);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnSig2(int32 InParam1, int32 InParam2)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig2(InParam1, InParam2);
	_GetSignals()->BroadcastSig2Signal(InParam1, InParam2);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnSig3(int32 InParam1, int32 InParam2, int32 InParam3)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig3(InParam1, InParam2, InParam3);
	_GetSignals()->BroadcastSig3Signal(InParam1, InParam2, InParam3);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnSig4(int32 InParam1, int32 InParam2, int32 InParam3, int32 InParam4)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig4(InParam1, InParam2, InParam3, InParam4);
	_GetSignals()->BroadcastSig4Signal(InParam1, InParam2, InParam3, InParam4);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnProp1Changed(int32 InProp1)
{
	Testbed2ManyParamInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	_GetSignals()->BroadcastProp1Changed(InProp1);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp1() const
{
	return BackendService->GetProp1();
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp1(int32 InProp1)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->SetProp1(InProp1);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnProp2Changed(int32 InProp2)
{
	Testbed2ManyParamInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	_GetSignals()->BroadcastProp2Changed(InProp2);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp2() const
{
	return BackendService->GetProp2();
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp2(int32 InProp2)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->SetProp2(InProp2);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnProp3Changed(int32 InProp3)
{
	Testbed2ManyParamInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop3 = InProp3;
	_GetSignals()->BroadcastProp3Changed(InProp3);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp3() const
{
	return BackendService->GetProp3();
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp3(int32 InProp3)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp3(InProp3);
	BackendService->SetProp3(InProp3);
}

void UTestbed2ManyParamInterfaceLoggingDecorator::OnProp4Changed(int32 InProp4)
{
	Testbed2ManyParamInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop4 = InProp4;
	_GetSignals()->BroadcastProp4Changed(InProp4);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::GetProp4() const
{
	return BackendService->GetProp4();
}

void UTestbed2ManyParamInterfaceLoggingDecorator::SetProp4(int32 InProp4)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp4(InProp4);
	BackendService->SetProp4(InProp4);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::Func1(int32 Param1)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Func1(Param1);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::Func2(int32 Param1, int32 Param2)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Func2(Param1, Param2);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::Func3(int32 Param1, int32 Param2, int32 Param3)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc3(Param1, Param2, Param3);
	return BackendService->Func3(Param1, Param2, Param3);
}

int32 UTestbed2ManyParamInterfaceLoggingDecorator::Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc4(Param1, Param2, Param3, Param4);
	return BackendService->Func4(Param1, Param2, Param3, Param4);
}
