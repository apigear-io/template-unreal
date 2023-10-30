
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
#include "Generated/Monitor/TbSame1SameStruct1InterfaceLoggingDecorator.h"
#include "TbSame1.trace.h"
#include "TbSame1Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSame1SameStruct1InterfaceLoggingDecorator);
UTbSame1SameStruct1InterfaceLoggingDecorator::UTbSame1SameStruct1InterfaceLoggingDecorator()
	: UAbstractTbSame1SameStruct1Interface()
{
}

UTbSame1SameStruct1InterfaceLoggingDecorator::~UTbSame1SameStruct1InterfaceLoggingDecorator() = default;

void UTbSame1SameStruct1InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService(FTbSame1ModuleFactory::createITbSame1SameStruct1InterfaceInterface(GetGameInstance(), Collection));
#else
	setBackendService(FTbSame1ModuleFactory::createITbSame1SameStruct1InterfaceInterface(Collection));
#endif
}

void UTbSame1SameStruct1InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSame1SameStruct1InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSame1SameStruct1InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame1SameStruct1InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameStruct1Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTbSame1SameStruct1InterfaceLoggingDecorator::OnProp1Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTbSame1SameStruct1InterfaceLoggingDecorator::OnSig1);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame1SameStruct1Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame1SameStruct1InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameStruct1Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTbSame1SameStruct1InterfaceLoggingDecorator::OnProp1Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTbSame1SameStruct1InterfaceLoggingDecorator::OnSig1);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTbSame1SameStruct1InterfaceLoggingDecorator::OnSig1(const FTbSame1Struct1& Param1)
{
	TbSame1SameStruct1InterfaceTracer::trace_signalSig1(Param1);
	Execute__GetSignals(this)->OnSig1Signal.Broadcast(Param1);
}

void UTbSame1SameStruct1InterfaceLoggingDecorator::OnProp1Changed(const FTbSame1Struct1& InProp1)
{
	TbSame1SameStruct1InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute__GetSignals(this)->OnProp1Changed.Broadcast(InProp1);
}

FTbSame1Struct1 UTbSame1SameStruct1InterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTbSame1SameStruct1InterfaceLoggingDecorator::SetProp1_Implementation(const FTbSame1Struct1& InProp1)
{
	TbSame1SameStruct1InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

FTbSame1Struct1 UTbSame1SameStruct1InterfaceLoggingDecorator::Func1_Implementation(const FTbSame1Struct1& Param1)
{
	TbSame1SameStruct1InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}
