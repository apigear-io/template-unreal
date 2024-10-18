

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
#include "Generated/Monitor/TbEnumEnumInterfaceLoggingDecorator.h"
#include "TbEnumSettings.h"
#include "TbEnum.trace.h"
#include "Generated/TbEnumFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbEnumEnumInterfaceLoggingDecorator);
UTbEnumEnumInterfaceLoggingDecorator::UTbEnumEnumInterfaceLoggingDecorator()
	: UAbstractTbEnumEnumInterface()
{
}

UTbEnumEnumInterfaceLoggingDecorator::~UTbEnumEnumInterfaceLoggingDecorator() = default;

void UTbEnumEnumInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbEnumSettings::GetITbEnumEnumInterfaceInterfaceForLogging(Collection));
}

void UTbEnumEnumInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbEnumEnumInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbEnumEnumInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbEnumEnumInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbEnumEnumInterface"));
		BackendSignals->OnProp0Changed.RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp0Changed);
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp1Changed);
		BackendSignals->OnProp2Changed.RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp2Changed);
		BackendSignals->OnProp3Changed.RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp3Changed);
		BackendSignals->OnSig0Signal.RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig0);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig1);
		BackendSignals->OnSig2Signal.RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig2);
		BackendSignals->OnSig3Signal.RemoveDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig3);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbEnumEnumInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbEnumEnumInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbEnumEnumInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp0Changed.AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp0Changed);
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp1Changed);
	BackendSignals->OnProp2Changed.AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp2Changed);
	BackendSignals->OnProp3Changed.AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnProp3Changed);
	BackendSignals->OnSig0Signal.AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig0);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig1);
	BackendSignals->OnSig2Signal.AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig2);
	BackendSignals->OnSig3Signal.AddDynamic(this, &UTbEnumEnumInterfaceLoggingDecorator::OnSig3);
	// populate service state to proxy
	Prop0 = BackendService->Execute_GetProp0(BackendService.GetObject());
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());
	Prop3 = BackendService->Execute_GetProp3(BackendService.GetObject());
}

void UTbEnumEnumInterfaceLoggingDecorator::OnSig0(ETbEnumEnum0 InParam0)
{
	TbEnumEnumInterfaceTracer::trace_signalSig0(InParam0);
	Execute__GetSignals(this)->OnSig0Signal.Broadcast(InParam0);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnSig1(ETbEnumEnum1 InParam1)
{
	TbEnumEnumInterfaceTracer::trace_signalSig1(InParam1);
	Execute__GetSignals(this)->OnSig1Signal.Broadcast(InParam1);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnSig2(ETbEnumEnum2 InParam2)
{
	TbEnumEnumInterfaceTracer::trace_signalSig2(InParam2);
	Execute__GetSignals(this)->OnSig2Signal.Broadcast(InParam2);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnSig3(ETbEnumEnum3 InParam3)
{
	TbEnumEnumInterfaceTracer::trace_signalSig3(InParam3);
	Execute__GetSignals(this)->OnSig3Signal.Broadcast(InParam3);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnProp0Changed(ETbEnumEnum0 InProp0)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop0 = InProp0;
	Execute__GetSignals(this)->OnProp0Changed.Broadcast(InProp0);
}

ETbEnumEnum0 UTbEnumEnumInterfaceLoggingDecorator::GetProp0_Implementation() const
{
	return BackendService->Execute_GetProp0(BackendService.GetObject());
}

void UTbEnumEnumInterfaceLoggingDecorator::SetProp0_Implementation(ETbEnumEnum0 InProp0)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp0(InProp0);
	BackendService->Execute_SetProp0(BackendService.GetObject(), InProp0);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnProp1Changed(ETbEnumEnum1 InProp1)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute__GetSignals(this)->OnProp1Changed.Broadcast(InProp1);
}

ETbEnumEnum1 UTbEnumEnumInterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTbEnumEnumInterfaceLoggingDecorator::SetProp1_Implementation(ETbEnumEnum1 InProp1)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnProp2Changed(ETbEnumEnum2 InProp2)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Execute__GetSignals(this)->OnProp2Changed.Broadcast(InProp2);
}

ETbEnumEnum2 UTbEnumEnumInterfaceLoggingDecorator::GetProp2_Implementation() const
{
	return BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTbEnumEnumInterfaceLoggingDecorator::SetProp2_Implementation(ETbEnumEnum2 InProp2)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnProp3Changed(ETbEnumEnum3 InProp3)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop3 = InProp3;
	Execute__GetSignals(this)->OnProp3Changed.Broadcast(InProp3);
}

ETbEnumEnum3 UTbEnumEnumInterfaceLoggingDecorator::GetProp3_Implementation() const
{
	return BackendService->Execute_GetProp3(BackendService.GetObject());
}

void UTbEnumEnumInterfaceLoggingDecorator::SetProp3_Implementation(ETbEnumEnum3 InProp3)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp3(InProp3);
	BackendService->Execute_SetProp3(BackendService.GetObject(), InProp3);
}

ETbEnumEnum0 UTbEnumEnumInterfaceLoggingDecorator::Func0_Implementation(ETbEnumEnum0 Param0)
{
	TbEnumEnumInterfaceTracer::trace_callFunc0(Param0);
	return BackendService->Execute_Func0(BackendService.GetObject(), Param0);
}

ETbEnumEnum1 UTbEnumEnumInterfaceLoggingDecorator::Func1_Implementation(ETbEnumEnum1 Param1)
{
	TbEnumEnumInterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}

ETbEnumEnum2 UTbEnumEnumInterfaceLoggingDecorator::Func2_Implementation(ETbEnumEnum2 Param2)
{
	TbEnumEnumInterfaceTracer::trace_callFunc2(Param2);
	return BackendService->Execute_Func2(BackendService.GetObject(), Param2);
}

ETbEnumEnum3 UTbEnumEnumInterfaceLoggingDecorator::Func3_Implementation(ETbEnumEnum3 Param3)
{
	TbEnumEnumInterfaceTracer::trace_callFunc3(Param3);
	return BackendService->Execute_Func3(BackendService.GetObject(), Param3);
}
