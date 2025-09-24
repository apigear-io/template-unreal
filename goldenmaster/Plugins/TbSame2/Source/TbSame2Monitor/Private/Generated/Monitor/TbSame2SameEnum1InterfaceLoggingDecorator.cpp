

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
#include "TbSame2/Generated/Monitor/TbSame2SameEnum1InterfaceLoggingDecorator.h"
#include "TbSame2Settings.h"
#include "TbSame2.trace.h"
#include "TbSame2/Generated/TbSame2Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSame2SameEnum1InterfaceLoggingDecorator);
UTbSame2SameEnum1InterfaceLoggingDecorator::UTbSame2SameEnum1InterfaceLoggingDecorator()
	: UAbstractTbSame2SameEnum1Interface()
{
}

UTbSame2SameEnum1InterfaceLoggingDecorator::~UTbSame2SameEnum1InterfaceLoggingDecorator() = default;

void UTbSame2SameEnum1InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbSame2Settings::GetITbSame2SameEnum1InterfaceInterfaceForLogging(Collection));
}

void UTbSame2SameEnum1InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSame2SameEnum1InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSame2SameEnum1InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSame2SameEnum1InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbSame2SameEnum1Interface"));
		BackendPublisher->Unsubscribe(TWeakInterfacePtr<ITbSame2SameEnum1InterfaceSubscriberInterface>(this));
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSame2SameEnum1Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSame2SameEnum1InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbSame2SameEnum1Interface"));
	// connect property changed signals or simple events
	BackendPublisher->Subscribe(TWeakInterfacePtr<ITbSame2SameEnum1InterfaceSubscriberInterface>(this));
	// populate service state to proxy
	Prop1 = BackendService->GetProp1();
}

void UTbSame2SameEnum1InterfaceLoggingDecorator::OnSig1Signal(ETbSame2Enum1 InParam1)
{
	TbSame2SameEnum1InterfaceTracer::trace_signalSig1(InParam1);
	_GetPublisher()->BroadcastSig1Signal(InParam1);
}

void UTbSame2SameEnum1InterfaceLoggingDecorator::OnProp1Changed(ETbSame2Enum1 InProp1)
{
	TbSame2SameEnum1InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	_GetPublisher()->BroadcastProp1Changed(InProp1);
}

ETbSame2Enum1 UTbSame2SameEnum1InterfaceLoggingDecorator::GetProp1() const
{
	return BackendService->GetProp1();
}

void UTbSame2SameEnum1InterfaceLoggingDecorator::SetProp1(ETbSame2Enum1 InProp1)
{
	TbSame2SameEnum1InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->SetProp1(InProp1);
}

ETbSame2Enum1 UTbSame2SameEnum1InterfaceLoggingDecorator::Func1(ETbSame2Enum1 Param1)
{
	TbSame2SameEnum1InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Func1(Param1);
}
