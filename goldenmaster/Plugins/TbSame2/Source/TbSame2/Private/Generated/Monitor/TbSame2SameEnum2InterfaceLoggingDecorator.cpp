
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
#include "Generated/Monitor/TbSame2SameEnum2InterfaceLoggingDecorator.h"
#include "TbSame2.trace.h"
#include "Generated/TbSame2Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSame2SameEnum2InterfaceLoggingDecorator);
UTbSame2SameEnum2InterfaceLoggingDecorator::UTbSame2SameEnum2InterfaceLoggingDecorator()
	: UAbstractTbSame2SameEnum2Interface()
{
}

UTbSame2SameEnum2InterfaceLoggingDecorator::~UTbSame2SameEnum2InterfaceLoggingDecorator() = default;

void UTbSame2SameEnum2InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService(FTbSame2ModuleFactory::createITbSame2SameEnum2InterfaceInterface(GetGameInstance(), Collection));
#else
	setBackendService(FTbSame2ModuleFactory::createITbSame2SameEnum2InterfaceInterface(Collection));
#endif
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSame2SameEnum2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame2SameEnum2InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame2SameEnum2Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp1Changed);
		BackendSignals->OnProp2Changed.RemoveDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp2Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig1);
		BackendSignals->OnSig2Signal.RemoveDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig2);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame2SameEnum2Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame2SameEnum2InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame2SameEnum2Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp1Changed);
	BackendSignals->OnProp2Changed.AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp2Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig1);
	BackendSignals->OnSig2Signal.AddDynamic(this, &UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig2);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig1(ETbSame2Enum1 InParam1)
{
	TbSame2SameEnum2InterfaceTracer::trace_signalSig1(InParam1);
	Execute__GetSignals(this)->OnSig1Signal.Broadcast(InParam1);
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::OnSig2(ETbSame2Enum1 InParam1, ETbSame2Enum2 InParam2)
{
	TbSame2SameEnum2InterfaceTracer::trace_signalSig2(InParam1, InParam2);
	Execute__GetSignals(this)->OnSig2Signal.Broadcast(InParam1, InParam2);
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp1Changed(ETbSame2Enum1 InProp1)
{
	TbSame2SameEnum2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute__GetSignals(this)->OnProp1Changed.Broadcast(InProp1);
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::SetProp1_Implementation(ETbSame2Enum1 InProp1)
{
	TbSame2SameEnum2InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::OnProp2Changed(ETbSame2Enum2 InProp2)
{
	TbSame2SameEnum2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Execute__GetSignals(this)->OnProp2Changed.Broadcast(InProp2);
}

ETbSame2Enum2 UTbSame2SameEnum2InterfaceLoggingDecorator::GetProp2_Implementation() const
{
	return BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTbSame2SameEnum2InterfaceLoggingDecorator::SetProp2_Implementation(ETbSame2Enum2 InProp2)
{
	TbSame2SameEnum2InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceLoggingDecorator::Func1_Implementation(ETbSame2Enum1 Param1)
{
	TbSame2SameEnum2InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceLoggingDecorator::Func2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	TbSame2SameEnum2InterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
}
