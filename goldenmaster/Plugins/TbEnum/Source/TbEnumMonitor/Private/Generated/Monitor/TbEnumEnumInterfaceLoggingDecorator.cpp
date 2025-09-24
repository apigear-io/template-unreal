

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
#include "TbEnum/Generated/Monitor/TbEnumEnumInterfaceLoggingDecorator.h"
#include "TbEnumSettings.h"
#include "TbEnum.trace.h"
#include "TbEnum/Generated/TbEnumFactory.h"
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
		UTbEnumEnumInterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbEnumEnumInterface"));
		BackendPublisher->Unsubscribe(TWeakInterfacePtr<ITbEnumEnumInterfaceSubscriberInterface>(this));
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbEnumEnumInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbEnumEnumInterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbEnumEnumInterface"));
	// connect property changed signals or simple events
	BackendPublisher->Subscribe(TWeakInterfacePtr<ITbEnumEnumInterfaceSubscriberInterface>(this));
	// populate service state to proxy
	Prop0 = BackendService->GetProp0();
	Prop1 = BackendService->GetProp1();
	Prop2 = BackendService->GetProp2();
	Prop3 = BackendService->GetProp3();
}

void UTbEnumEnumInterfaceLoggingDecorator::OnSig0Signal(ETbEnumEnum0 InParam0)
{
	TbEnumEnumInterfaceTracer::trace_signalSig0(InParam0);
	_GetPublisher()->BroadcastSig0Signal(InParam0);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnSig1Signal(ETbEnumEnum1 InParam1)
{
	TbEnumEnumInterfaceTracer::trace_signalSig1(InParam1);
	_GetPublisher()->BroadcastSig1Signal(InParam1);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnSig2Signal(ETbEnumEnum2 InParam2)
{
	TbEnumEnumInterfaceTracer::trace_signalSig2(InParam2);
	_GetPublisher()->BroadcastSig2Signal(InParam2);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnSig3Signal(ETbEnumEnum3 InParam3)
{
	TbEnumEnumInterfaceTracer::trace_signalSig3(InParam3);
	_GetPublisher()->BroadcastSig3Signal(InParam3);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnProp0Changed(ETbEnumEnum0 InProp0)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop0 = InProp0;
	_GetPublisher()->BroadcastProp0Changed(InProp0);
}

ETbEnumEnum0 UTbEnumEnumInterfaceLoggingDecorator::GetProp0() const
{
	return BackendService->GetProp0();
}

void UTbEnumEnumInterfaceLoggingDecorator::SetProp0(ETbEnumEnum0 InProp0)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp0(InProp0);
	BackendService->SetProp0(InProp0);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnProp1Changed(ETbEnumEnum1 InProp1)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	_GetPublisher()->BroadcastProp1Changed(InProp1);
}

ETbEnumEnum1 UTbEnumEnumInterfaceLoggingDecorator::GetProp1() const
{
	return BackendService->GetProp1();
}

void UTbEnumEnumInterfaceLoggingDecorator::SetProp1(ETbEnumEnum1 InProp1)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->SetProp1(InProp1);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnProp2Changed(ETbEnumEnum2 InProp2)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	_GetPublisher()->BroadcastProp2Changed(InProp2);
}

ETbEnumEnum2 UTbEnumEnumInterfaceLoggingDecorator::GetProp2() const
{
	return BackendService->GetProp2();
}

void UTbEnumEnumInterfaceLoggingDecorator::SetProp2(ETbEnumEnum2 InProp2)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->SetProp2(InProp2);
}

void UTbEnumEnumInterfaceLoggingDecorator::OnProp3Changed(ETbEnumEnum3 InProp3)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop3 = InProp3;
	_GetPublisher()->BroadcastProp3Changed(InProp3);
}

ETbEnumEnum3 UTbEnumEnumInterfaceLoggingDecorator::GetProp3() const
{
	return BackendService->GetProp3();
}

void UTbEnumEnumInterfaceLoggingDecorator::SetProp3(ETbEnumEnum3 InProp3)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp3(InProp3);
	BackendService->SetProp3(InProp3);
}

ETbEnumEnum0 UTbEnumEnumInterfaceLoggingDecorator::Func0(ETbEnumEnum0 Param0)
{
	TbEnumEnumInterfaceTracer::trace_callFunc0(Param0);
	return BackendService->Func0(Param0);
}

ETbEnumEnum1 UTbEnumEnumInterfaceLoggingDecorator::Func1(ETbEnumEnum1 Param1)
{
	TbEnumEnumInterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Func1(Param1);
}

ETbEnumEnum2 UTbEnumEnumInterfaceLoggingDecorator::Func2(ETbEnumEnum2 Param2)
{
	TbEnumEnumInterfaceTracer::trace_callFunc2(Param2);
	return BackendService->Func2(Param2);
}

ETbEnumEnum3 UTbEnumEnumInterfaceLoggingDecorator::Func3(ETbEnumEnum3 Param3)
{
	TbEnumEnumInterfaceTracer::trace_callFunc3(Param3);
	return BackendService->Func3(Param3);
}
