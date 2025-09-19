

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
#include "TbSame1/Generated/Monitor/TbSame1SameEnum2InterfaceLoggingDecorator.h"
#include "TbSame1Settings.h"
#include "TbSame1.trace.h"
#include "TbSame1/Generated/TbSame1Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSame1SameEnum2InterfaceLoggingDecorator);
UTbSame1SameEnum2InterfaceLoggingDecorator::UTbSame1SameEnum2InterfaceLoggingDecorator()
	: UAbstractTbSame1SameEnum2Interface()
{
}

UTbSame1SameEnum2InterfaceLoggingDecorator::~UTbSame1SameEnum2InterfaceLoggingDecorator() = default;

void UTbSame1SameEnum2InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbSame1Settings::GetITbSame1SameEnum2InterfaceInterfaceForLogging(Collection));
}

void UTbSame1SameEnum2InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSame1SameEnum2InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSame1SameEnum2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame1SameEnum2InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameEnum2Interface"));
		BackendPublisher->OnProp1ChangedBP.RemoveDynamic(this, &UTbSame1SameEnum2InterfaceLoggingDecorator::OnProp1Changed);
		BackendPublisher->OnProp2ChangedBP.RemoveDynamic(this, &UTbSame1SameEnum2InterfaceLoggingDecorator::OnProp2Changed);
		BackendPublisher->OnSig1SignalBP.RemoveDynamic(this, &UTbSame1SameEnum2InterfaceLoggingDecorator::OnSig1);
		BackendPublisher->OnSig2SignalBP.RemoveDynamic(this, &UTbSame1SameEnum2InterfaceLoggingDecorator::OnSig2);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame1SameEnum2Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame1SameEnum2InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameEnum2Interface"));
	// connect property changed signals or simple events
	BackendPublisher->OnProp1ChangedBP.AddDynamic(this, &UTbSame1SameEnum2InterfaceLoggingDecorator::OnProp1Changed);
	BackendPublisher->OnProp2ChangedBP.AddDynamic(this, &UTbSame1SameEnum2InterfaceLoggingDecorator::OnProp2Changed);
	BackendPublisher->OnSig1SignalBP.AddDynamic(this, &UTbSame1SameEnum2InterfaceLoggingDecorator::OnSig1);
	BackendPublisher->OnSig2SignalBP.AddDynamic(this, &UTbSame1SameEnum2InterfaceLoggingDecorator::OnSig2);
	// populate service state to proxy
	Prop1 = BackendService->GetProp1();
	Prop2 = BackendService->GetProp2();
}

void UTbSame1SameEnum2InterfaceLoggingDecorator::OnSig1(ETbSame1Enum1 InParam1)
{
	TbSame1SameEnum2InterfaceTracer::trace_signalSig1(InParam1);
	_GetPublisher()->BroadcastSig1Signal(InParam1);
}

void UTbSame1SameEnum2InterfaceLoggingDecorator::OnSig2(ETbSame1Enum1 InParam1, ETbSame1Enum2 InParam2)
{
	TbSame1SameEnum2InterfaceTracer::trace_signalSig2(InParam1, InParam2);
	_GetPublisher()->BroadcastSig2Signal(InParam1, InParam2);
}

void UTbSame1SameEnum2InterfaceLoggingDecorator::OnProp1Changed(ETbSame1Enum1 InProp1)
{
	TbSame1SameEnum2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	_GetPublisher()->BroadcastProp1Changed(InProp1);
}

ETbSame1Enum1 UTbSame1SameEnum2InterfaceLoggingDecorator::GetProp1() const
{
	return BackendService->GetProp1();
}

void UTbSame1SameEnum2InterfaceLoggingDecorator::SetProp1(ETbSame1Enum1 InProp1)
{
	TbSame1SameEnum2InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->SetProp1(InProp1);
}

void UTbSame1SameEnum2InterfaceLoggingDecorator::OnProp2Changed(ETbSame1Enum2 InProp2)
{
	TbSame1SameEnum2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	_GetPublisher()->BroadcastProp2Changed(InProp2);
}

ETbSame1Enum2 UTbSame1SameEnum2InterfaceLoggingDecorator::GetProp2() const
{
	return BackendService->GetProp2();
}

void UTbSame1SameEnum2InterfaceLoggingDecorator::SetProp2(ETbSame1Enum2 InProp2)
{
	TbSame1SameEnum2InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->SetProp2(InProp2);
}

ETbSame1Enum1 UTbSame1SameEnum2InterfaceLoggingDecorator::Func1(ETbSame1Enum1 Param1)
{
	TbSame1SameEnum2InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Func1(Param1);
}

ETbSame1Enum1 UTbSame1SameEnum2InterfaceLoggingDecorator::Func2(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	TbSame1SameEnum2InterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Func2(Param1, Param2);
}
