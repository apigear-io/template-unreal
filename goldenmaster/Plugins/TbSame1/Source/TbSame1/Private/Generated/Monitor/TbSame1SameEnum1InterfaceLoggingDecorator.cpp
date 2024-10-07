
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
#include "Generated/Monitor/TbSame1SameEnum1InterfaceLoggingDecorator.h"
#include "TbSame1.trace.h"
#include "Generated/TbSame1Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSame1SameEnum1InterfaceLoggingDecorator);
UTbSame1SameEnum1InterfaceLoggingDecorator::UTbSame1SameEnum1InterfaceLoggingDecorator()
	: UAbstractTbSame1SameEnum1Interface()
{
}

UTbSame1SameEnum1InterfaceLoggingDecorator::~UTbSame1SameEnum1InterfaceLoggingDecorator() = default;

void UTbSame1SameEnum1InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(FTbSame1ModuleFactory::createITbSame1SameEnum1InterfaceInterface(Collection));
}

void UTbSame1SameEnum1InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSame1SameEnum1InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSame1SameEnum1InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame1SameEnum1InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameEnum1Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTbSame1SameEnum1InterfaceLoggingDecorator::OnProp1Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTbSame1SameEnum1InterfaceLoggingDecorator::OnSig1);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame1SameEnum1Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame1SameEnum1InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameEnum1Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTbSame1SameEnum1InterfaceLoggingDecorator::OnProp1Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTbSame1SameEnum1InterfaceLoggingDecorator::OnSig1);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTbSame1SameEnum1InterfaceLoggingDecorator::OnSig1(ETbSame1Enum1 InParam1)
{
	TbSame1SameEnum1InterfaceTracer::trace_signalSig1(InParam1);
	Execute__GetSignals(this)->OnSig1Signal.Broadcast(InParam1);
}

void UTbSame1SameEnum1InterfaceLoggingDecorator::OnProp1Changed(ETbSame1Enum1 InProp1)
{
	TbSame1SameEnum1InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute__GetSignals(this)->OnProp1Changed.Broadcast(InProp1);
}

ETbSame1Enum1 UTbSame1SameEnum1InterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTbSame1SameEnum1InterfaceLoggingDecorator::SetProp1_Implementation(ETbSame1Enum1 InProp1)
{
	TbSame1SameEnum1InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

ETbSame1Enum1 UTbSame1SameEnum1InterfaceLoggingDecorator::Func1_Implementation(ETbSame1Enum1 Param1)
{
	TbSame1SameEnum1InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}
