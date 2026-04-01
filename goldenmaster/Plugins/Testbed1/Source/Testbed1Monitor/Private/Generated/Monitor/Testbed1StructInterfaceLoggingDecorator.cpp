

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
#include "Testbed1/Generated/Monitor/Testbed1StructInterfaceLoggingDecorator.h"
#include "Testbed1Settings.h"
#include "Testbed1.trace.h"
#include "Testbed1/Generated/Testbed1Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTestbed1StructInterfaceLoggingDecorator);
UTestbed1StructInterfaceLoggingDecorator::UTestbed1StructInterfaceLoggingDecorator()
	: UAbstractTestbed1StructInterface()
{
}

UTestbed1StructInterfaceLoggingDecorator::~UTestbed1StructInterfaceLoggingDecorator() = default;

void UTestbed1StructInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTestbed1Settings::GetITestbed1StructInterfaceInterfaceForLogging(Collection));
}

void UTestbed1StructInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	if (BackendService != nullptr)
	{
		UTestbed1StructInterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		if (BackendPublisher)
		{
			BackendPublisher->Unsubscribe(TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>(this));
		}
	}
	BackendService = nullptr;
}

void UTestbed1StructInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed1StructInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed1StructInterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructInterface"));
		if (!BackendPublisher)
		{
			return;
		}
		BackendPublisher->Unsubscribe(TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>(this));
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed1StructInterface is not fully implemented"));
	if (InService.GetInterface() == nullptr)
	{
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	UTestbed1StructInterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructInterface"));
	if (!BackendPublisher)
	{
		return;
	}
	// connect property changed signals or simple events
	BackendPublisher->Subscribe(TWeakInterfacePtr<ITestbed1StructInterfaceSubscriberInterface>(this));
	// populate service state to proxy
	PropBool = BackendService->GetPropBool();
	PropInt = BackendService->GetPropInt();
	PropFloat = BackendService->GetPropFloat();
	PropString = BackendService->GetPropString();
}

void UTestbed1StructInterfaceLoggingDecorator::OnSigBoolSignal(const FTestbed1StructBool& InParamBool)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructInterfaceTracer::trace_signalSigBool(InParamBool);
	_GetPublisher()->BroadcastSigBoolSignal(InParamBool);
}

void UTestbed1StructInterfaceLoggingDecorator::OnSigIntSignal(const FTestbed1StructInt& InParamInt)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructInterfaceTracer::trace_signalSigInt(InParamInt);
	_GetPublisher()->BroadcastSigIntSignal(InParamInt);
}

void UTestbed1StructInterfaceLoggingDecorator::OnSigFloatSignal(const FTestbed1StructFloat& InParamFloat)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructInterfaceTracer::trace_signalSigFloat(InParamFloat);
	_GetPublisher()->BroadcastSigFloatSignal(InParamFloat);
}

void UTestbed1StructInterfaceLoggingDecorator::OnSigStringSignal(const FTestbed1StructString& InParamString)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructInterfaceTracer::trace_signalSigString(InParamString);
	_GetPublisher()->BroadcastSigStringSignal(InParamString);
}

void UTestbed1StructInterfaceLoggingDecorator::OnPropBoolChanged(const FTestbed1StructBool& InPropBool)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropBool = InPropBool;
	_GetPublisher()->BroadcastPropBoolChanged(InPropBool);
}

FTestbed1StructBool UTestbed1StructInterfaceLoggingDecorator::GetPropBool() const
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTestbed1StructBool();
	}
	return BackendService->GetPropBool();
}

void UTestbed1StructInterfaceLoggingDecorator::SetPropBool(const FTestbed1StructBool& InPropBool)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	Testbed1StructInterfaceTracer::trace_callSetPropBool(InPropBool);
	BackendService->SetPropBool(InPropBool);
}

void UTestbed1StructInterfaceLoggingDecorator::OnPropIntChanged(const FTestbed1StructInt& InPropInt)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	_GetPublisher()->BroadcastPropIntChanged(InPropInt);
}

FTestbed1StructInt UTestbed1StructInterfaceLoggingDecorator::GetPropInt() const
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTestbed1StructInt();
	}
	return BackendService->GetPropInt();
}

void UTestbed1StructInterfaceLoggingDecorator::SetPropInt(const FTestbed1StructInt& InPropInt)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	Testbed1StructInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->SetPropInt(InPropInt);
}

void UTestbed1StructInterfaceLoggingDecorator::OnPropFloatChanged(const FTestbed1StructFloat& InPropFloat)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	_GetPublisher()->BroadcastPropFloatChanged(InPropFloat);
}

FTestbed1StructFloat UTestbed1StructInterfaceLoggingDecorator::GetPropFloat() const
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTestbed1StructFloat();
	}
	return BackendService->GetPropFloat();
}

void UTestbed1StructInterfaceLoggingDecorator::SetPropFloat(const FTestbed1StructFloat& InPropFloat)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	Testbed1StructInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->SetPropFloat(InPropFloat);
}

void UTestbed1StructInterfaceLoggingDecorator::OnPropStringChanged(const FTestbed1StructString& InPropString)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	_GetPublisher()->BroadcastPropStringChanged(InPropString);
}

FTestbed1StructString UTestbed1StructInterfaceLoggingDecorator::GetPropString() const
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTestbed1StructString();
	}
	return BackendService->GetPropString();
}

void UTestbed1StructInterfaceLoggingDecorator::SetPropString(const FTestbed1StructString& InPropString)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	Testbed1StructInterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->SetPropString(InPropString);
}

FTestbed1StructBool UTestbed1StructInterfaceLoggingDecorator::FuncBool(const FTestbed1StructBool& ParamBool)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTestbed1StructBool();
	}
	Testbed1StructInterfaceTracer::trace_callFuncBool(ParamBool);
	return BackendService->FuncBool(ParamBool);
}

FTestbed1StructInt UTestbed1StructInterfaceLoggingDecorator::FuncInt(const FTestbed1StructInt& ParamInt)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTestbed1StructInt();
	}
	Testbed1StructInterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->FuncInt(ParamInt);
}

FTestbed1StructFloat UTestbed1StructInterfaceLoggingDecorator::FuncFloat(const FTestbed1StructFloat& ParamFloat)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTestbed1StructFloat();
	}
	Testbed1StructInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->FuncFloat(ParamFloat);
}

FTestbed1StructString UTestbed1StructInterfaceLoggingDecorator::FuncString(const FTestbed1StructString& ParamString)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTestbed1StructString();
	}
	Testbed1StructInterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->FuncString(ParamString);
}
