

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
#include "TbSame2/Generated/Monitor/TbSame2SameStruct2InterfaceLoggingDecorator.h"
#include "TbSame2Settings.h"
#include "TbSame2.trace.h"
#include "TbSame2/Generated/TbSame2Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSame2SameStruct2InterfaceLoggingDecorator);
UTbSame2SameStruct2InterfaceLoggingDecorator::UTbSame2SameStruct2InterfaceLoggingDecorator()
	: UAbstractTbSame2SameStruct2Interface()
{
}

UTbSame2SameStruct2InterfaceLoggingDecorator::~UTbSame2SameStruct2InterfaceLoggingDecorator() = default;

void UTbSame2SameStruct2InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbSame2Settings::GetITbSame2SameStruct2InterfaceInterfaceForLogging(Collection));
}

void UTbSame2SameStruct2InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSame2SameStruct2InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSame2SameStruct2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame2SameStruct2InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbSame2SameStruct2Interface"));
		BackendPublisher->OnProp1ChangedBP.RemoveDynamic(this, &UTbSame2SameStruct2InterfaceLoggingDecorator::OnProp1Changed);
		BackendPublisher->OnProp2ChangedBP.RemoveDynamic(this, &UTbSame2SameStruct2InterfaceLoggingDecorator::OnProp2Changed);
		BackendPublisher->OnSig1SignalBP.RemoveDynamic(this, &UTbSame2SameStruct2InterfaceLoggingDecorator::OnSig1);
		BackendPublisher->OnSig2SignalBP.RemoveDynamic(this, &UTbSame2SameStruct2InterfaceLoggingDecorator::OnSig2);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame2SameStruct2Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame2SameStruct2InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbSame2SameStruct2Interface"));
	// connect property changed signals or simple events
	BackendPublisher->OnProp1ChangedBP.AddDynamic(this, &UTbSame2SameStruct2InterfaceLoggingDecorator::OnProp1Changed);
	BackendPublisher->OnProp2ChangedBP.AddDynamic(this, &UTbSame2SameStruct2InterfaceLoggingDecorator::OnProp2Changed);
	BackendPublisher->OnSig1SignalBP.AddDynamic(this, &UTbSame2SameStruct2InterfaceLoggingDecorator::OnSig1);
	BackendPublisher->OnSig2SignalBP.AddDynamic(this, &UTbSame2SameStruct2InterfaceLoggingDecorator::OnSig2);
	// populate service state to proxy
	Prop1 = BackendService->GetProp1();
	Prop2 = BackendService->GetProp2();
}

void UTbSame2SameStruct2InterfaceLoggingDecorator::OnSig1(const FTbSame2Struct1& InParam1)
{
	TbSame2SameStruct2InterfaceTracer::trace_signalSig1(InParam1);
	_GetPublisher()->BroadcastSig1Signal(InParam1);
}

void UTbSame2SameStruct2InterfaceLoggingDecorator::OnSig2(const FTbSame2Struct1& InParam1, const FTbSame2Struct2& InParam2)
{
	TbSame2SameStruct2InterfaceTracer::trace_signalSig2(InParam1, InParam2);
	_GetPublisher()->BroadcastSig2Signal(InParam1, InParam2);
}

void UTbSame2SameStruct2InterfaceLoggingDecorator::OnProp1Changed(const FTbSame2Struct2& InProp1)
{
	TbSame2SameStruct2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	_GetPublisher()->BroadcastProp1Changed(InProp1);
}

FTbSame2Struct2 UTbSame2SameStruct2InterfaceLoggingDecorator::GetProp1() const
{
	return BackendService->GetProp1();
}

void UTbSame2SameStruct2InterfaceLoggingDecorator::SetProp1(const FTbSame2Struct2& InProp1)
{
	TbSame2SameStruct2InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->SetProp1(InProp1);
}

void UTbSame2SameStruct2InterfaceLoggingDecorator::OnProp2Changed(const FTbSame2Struct2& InProp2)
{
	TbSame2SameStruct2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	_GetPublisher()->BroadcastProp2Changed(InProp2);
}

FTbSame2Struct2 UTbSame2SameStruct2InterfaceLoggingDecorator::GetProp2() const
{
	return BackendService->GetProp2();
}

void UTbSame2SameStruct2InterfaceLoggingDecorator::SetProp2(const FTbSame2Struct2& InProp2)
{
	TbSame2SameStruct2InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->SetProp2(InProp2);
}

FTbSame2Struct1 UTbSame2SameStruct2InterfaceLoggingDecorator::Func1(const FTbSame2Struct1& Param1)
{
	TbSame2SameStruct2InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Func1(Param1);
}

FTbSame2Struct1 UTbSame2SameStruct2InterfaceLoggingDecorator::Func2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	TbSame2SameStruct2InterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Func2(Param1, Param2);
}
