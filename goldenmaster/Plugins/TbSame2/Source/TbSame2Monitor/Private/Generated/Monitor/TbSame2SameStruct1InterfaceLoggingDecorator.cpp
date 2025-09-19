

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
#include "TbSame2/Generated/Monitor/TbSame2SameStruct1InterfaceLoggingDecorator.h"
#include "TbSame2Settings.h"
#include "TbSame2.trace.h"
#include "TbSame2/Generated/TbSame2Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSame2SameStruct1InterfaceLoggingDecorator);
UTbSame2SameStruct1InterfaceLoggingDecorator::UTbSame2SameStruct1InterfaceLoggingDecorator()
	: UAbstractTbSame2SameStruct1Interface()
{
}

UTbSame2SameStruct1InterfaceLoggingDecorator::~UTbSame2SameStruct1InterfaceLoggingDecorator() = default;

void UTbSame2SameStruct1InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbSame2Settings::GetITbSame2SameStruct1InterfaceInterfaceForLogging(Collection));
}

void UTbSame2SameStruct1InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSame2SameStruct1InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSame2SameStruct1InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame2SameStruct1InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbSame2SameStruct1Interface"));
		BackendPublisher->OnProp1ChangedBP.RemoveDynamic(this, &UTbSame2SameStruct1InterfaceLoggingDecorator::OnProp1Changed);
		BackendPublisher->OnSig1SignalBP.RemoveDynamic(this, &UTbSame2SameStruct1InterfaceLoggingDecorator::OnSig1);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame2SameStruct1Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame2SameStruct1InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbSame2SameStruct1Interface"));
	// connect property changed signals or simple events
	BackendPublisher->OnProp1ChangedBP.AddDynamic(this, &UTbSame2SameStruct1InterfaceLoggingDecorator::OnProp1Changed);
	BackendPublisher->OnSig1SignalBP.AddDynamic(this, &UTbSame2SameStruct1InterfaceLoggingDecorator::OnSig1);
	// populate service state to proxy
	Prop1 = BackendService->GetProp1();
}

void UTbSame2SameStruct1InterfaceLoggingDecorator::OnSig1(const FTbSame2Struct1& InParam1)
{
	TbSame2SameStruct1InterfaceTracer::trace_signalSig1(InParam1);
	_GetPublisher()->BroadcastSig1Signal(InParam1);
}

void UTbSame2SameStruct1InterfaceLoggingDecorator::OnProp1Changed(const FTbSame2Struct1& InProp1)
{
	TbSame2SameStruct1InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	_GetPublisher()->BroadcastProp1Changed(InProp1);
}

FTbSame2Struct1 UTbSame2SameStruct1InterfaceLoggingDecorator::GetProp1() const
{
	return BackendService->GetProp1();
}

void UTbSame2SameStruct1InterfaceLoggingDecorator::SetProp1(const FTbSame2Struct1& InProp1)
{
	TbSame2SameStruct1InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->SetProp1(InProp1);
}

FTbSame2Struct1 UTbSame2SameStruct1InterfaceLoggingDecorator::Func1(const FTbSame2Struct1& Param1)
{
	TbSame2SameStruct1InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Func1(Param1);
}
