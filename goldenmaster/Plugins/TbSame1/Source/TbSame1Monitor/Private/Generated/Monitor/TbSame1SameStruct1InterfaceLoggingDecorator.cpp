

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
#include "TbSame1/Generated/Monitor/TbSame1SameStruct1InterfaceLoggingDecorator.h"
#include "TbSame1Settings.h"
#include "TbSame1.trace.h"
#include "TbSame1/Generated/TbSame1Factory.h"
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
	setBackendService(UTbSame1Settings::GetITbSame1SameStruct1InterfaceInterfaceForLogging(Collection));
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
		UTbSame1SameStruct1InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameStruct1Interface"));
		BackendPublisher->Unsubscribe(TWeakInterfacePtr<ITbSame1SameStruct1InterfaceSubscriberInterface>(this));
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame1SameStruct1Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame1SameStruct1InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbSame1SameStruct1Interface"));
	// connect property changed signals or simple events
	BackendPublisher->Subscribe(TWeakInterfacePtr<ITbSame1SameStruct1InterfaceSubscriberInterface>(this));
	// populate service state to proxy
	Prop1 = BackendService->GetProp1();
}

void UTbSame1SameStruct1InterfaceLoggingDecorator::OnSig1Signal(const FTbSame1Struct1& InParam1)
{
	TbSame1SameStruct1InterfaceTracer::trace_signalSig1(InParam1);
	_GetPublisher()->BroadcastSig1Signal(InParam1);
}

void UTbSame1SameStruct1InterfaceLoggingDecorator::OnProp1Changed(const FTbSame1Struct1& InProp1)
{
	TbSame1SameStruct1InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	_GetPublisher()->BroadcastProp1Changed(InProp1);
}

FTbSame1Struct1 UTbSame1SameStruct1InterfaceLoggingDecorator::GetProp1() const
{
	return BackendService->GetProp1();
}

void UTbSame1SameStruct1InterfaceLoggingDecorator::SetProp1(const FTbSame1Struct1& InProp1)
{
	TbSame1SameStruct1InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->SetProp1(InProp1);
}

FTbSame1Struct1 UTbSame1SameStruct1InterfaceLoggingDecorator::Func1(const FTbSame1Struct1& Param1)
{
	TbSame1SameStruct1InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Func1(Param1);
}
