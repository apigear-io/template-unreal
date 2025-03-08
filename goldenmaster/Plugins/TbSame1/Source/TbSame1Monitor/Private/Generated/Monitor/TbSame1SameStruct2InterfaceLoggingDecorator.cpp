

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
#include "TbSame1/Generated/Monitor/TbSame1SameStruct2InterfaceLoggingDecorator.h"
#include "TbSame1Settings.h"
#include "TbSame1.trace.h"
#include "TbSame1/Generated/TbSame1Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSame1SameStruct2InterfaceLoggingDecorator);
UTbSame1SameStruct2InterfaceLoggingDecorator::UTbSame1SameStruct2InterfaceLoggingDecorator()
	: UAbstractTbSame1SameStruct2Interface()
{
}

UTbSame1SameStruct2InterfaceLoggingDecorator::~UTbSame1SameStruct2InterfaceLoggingDecorator() = default;

void UTbSame1SameStruct2InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbSame1Settings::GetITbSame1SameStruct2InterfaceInterfaceForLogging(Collection));
}

void UTbSame1SameStruct2InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSame1SameStruct2InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSame1SameStruct2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame1SameStruct2InterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameStruct2Interface"));
		BackendSignals->OnProp1Changed.RemoveDynamic(this, &UTbSame1SameStruct2InterfaceLoggingDecorator::OnProp1Changed);
		BackendSignals->OnProp2Changed.RemoveDynamic(this, &UTbSame1SameStruct2InterfaceLoggingDecorator::OnProp2Changed);
		BackendSignals->OnSig1Signal.RemoveDynamic(this, &UTbSame1SameStruct2InterfaceLoggingDecorator::OnSig1);
		BackendSignals->OnSig2Signal.RemoveDynamic(this, &UTbSame1SameStruct2InterfaceLoggingDecorator::OnSig2);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame1SameStruct2Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame1SameStruct2InterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameStruct2Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnProp1Changed.AddDynamic(this, &UTbSame1SameStruct2InterfaceLoggingDecorator::OnProp1Changed);
	BackendSignals->OnProp2Changed.AddDynamic(this, &UTbSame1SameStruct2InterfaceLoggingDecorator::OnProp2Changed);
	BackendSignals->OnSig1Signal.AddDynamic(this, &UTbSame1SameStruct2InterfaceLoggingDecorator::OnSig1);
	BackendSignals->OnSig2Signal.AddDynamic(this, &UTbSame1SameStruct2InterfaceLoggingDecorator::OnSig2);
	// populate service state to proxy
	Prop1 = BackendService->GetProp1();
	Prop2 = BackendService->GetProp2();
}

void UTbSame1SameStruct2InterfaceLoggingDecorator::OnSig1(const FTbSame1Struct1& InParam1)
{
	TbSame1SameStruct2InterfaceTracer::trace_signalSig1(InParam1);
	_GetSignals()->OnSig1Signal.Broadcast(InParam1);
}

void UTbSame1SameStruct2InterfaceLoggingDecorator::OnSig2(const FTbSame1Struct1& InParam1, const FTbSame1Struct2& InParam2)
{
	TbSame1SameStruct2InterfaceTracer::trace_signalSig2(InParam1, InParam2);
	_GetSignals()->OnSig2Signal.Broadcast(InParam1, InParam2);
}

void UTbSame1SameStruct2InterfaceLoggingDecorator::OnProp1Changed(const FTbSame1Struct2& InProp1)
{
	TbSame1SameStruct2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	_GetSignals()->OnProp1Changed.Broadcast(InProp1);
}

FTbSame1Struct2 UTbSame1SameStruct2InterfaceLoggingDecorator::GetProp1() const
{
	return BackendService->GetProp1();
}

void UTbSame1SameStruct2InterfaceLoggingDecorator::SetProp1(const FTbSame1Struct2& InProp1)
{
	TbSame1SameStruct2InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->SetProp1(InProp1);
}

void UTbSame1SameStruct2InterfaceLoggingDecorator::OnProp2Changed(const FTbSame1Struct2& InProp2)
{
	TbSame1SameStruct2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	_GetSignals()->OnProp2Changed.Broadcast(InProp2);
}

FTbSame1Struct2 UTbSame1SameStruct2InterfaceLoggingDecorator::GetProp2() const
{
	return BackendService->GetProp2();
}

void UTbSame1SameStruct2InterfaceLoggingDecorator::SetProp2(const FTbSame1Struct2& InProp2)
{
	TbSame1SameStruct2InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->SetProp2(InProp2);
}

FTbSame1Struct1 UTbSame1SameStruct2InterfaceLoggingDecorator::Func1(const FTbSame1Struct1& Param1)
{
	TbSame1SameStruct2InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Func1(Param1);
}

FTbSame1Struct1 UTbSame1SameStruct2InterfaceLoggingDecorator::Func2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	TbSame1SameStruct2InterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Func2(Param1, Param2);
}
