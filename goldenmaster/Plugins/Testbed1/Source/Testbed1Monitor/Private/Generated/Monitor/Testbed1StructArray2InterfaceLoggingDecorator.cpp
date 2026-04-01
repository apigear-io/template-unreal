

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
#include "Testbed1/Generated/Monitor/Testbed1StructArray2InterfaceLoggingDecorator.h"
#include "Testbed1Settings.h"
#include "Testbed1.trace.h"
#include "Testbed1/Generated/Testbed1Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTestbed1StructArray2InterfaceLoggingDecorator);
UTestbed1StructArray2InterfaceLoggingDecorator::UTestbed1StructArray2InterfaceLoggingDecorator()
	: UAbstractTestbed1StructArray2Interface()
{
}

UTestbed1StructArray2InterfaceLoggingDecorator::~UTestbed1StructArray2InterfaceLoggingDecorator() = default;

void UTestbed1StructArray2InterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTestbed1Settings::GetITestbed1StructArray2InterfaceInterfaceForLogging(Collection));
}

void UTestbed1StructArray2InterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	if (BackendService != nullptr)
	{
		UTestbed1StructArray2InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		if (BackendPublisher)
		{
			BackendPublisher->Unsubscribe(TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>(this));
		}
	}
	BackendService = nullptr;
}

void UTestbed1StructArray2InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed1StructArray2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed1StructArray2InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructArray2Interface"));
		if (!BackendPublisher)
		{
			return;
		}
		BackendPublisher->Unsubscribe(TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>(this));
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed1StructArray2Interface is not fully implemented"));
	if (InService.GetInterface() == nullptr)
	{
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	UTestbed1StructArray2InterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructArray2Interface"));
	if (!BackendPublisher)
	{
		return;
	}
	// connect property changed signals or simple events
	BackendPublisher->Subscribe(TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>(this));
	// populate service state to proxy
	PropBool = BackendService->GetPropBool();
	PropInt = BackendService->GetPropInt();
	PropFloat = BackendService->GetPropFloat();
	PropString = BackendService->GetPropString();
	PropEnum = BackendService->GetPropEnum();
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnSigBoolSignal(const FTestbed1StructBoolWithArray& InParamBool)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructArray2InterfaceTracer::trace_signalSigBool(InParamBool);
	_GetPublisher()->BroadcastSigBoolSignal(InParamBool);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnSigIntSignal(const FTestbed1StructIntWithArray& InParamInt)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructArray2InterfaceTracer::trace_signalSigInt(InParamInt);
	_GetPublisher()->BroadcastSigIntSignal(InParamInt);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnSigFloatSignal(const FTestbed1StructFloatWithArray& InParamFloat)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructArray2InterfaceTracer::trace_signalSigFloat(InParamFloat);
	_GetPublisher()->BroadcastSigFloatSignal(InParamFloat);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnSigStringSignal(const FTestbed1StructStringWithArray& InParamString)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructArray2InterfaceTracer::trace_signalSigString(InParamString);
	_GetPublisher()->BroadcastSigStringSignal(InParamString);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropBoolChanged(const FTestbed1StructBoolWithArray& InPropBool)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropBool = InPropBool;
	_GetPublisher()->BroadcastPropBoolChanged(InPropBool);
}

FTestbed1StructBoolWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropBool() const
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTestbed1StructBoolWithArray();
	}
	return BackendService->GetPropBool();
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropBool(const FTestbed1StructBoolWithArray& InPropBool)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	Testbed1StructArray2InterfaceTracer::trace_callSetPropBool(InPropBool);
	BackendService->SetPropBool(InPropBool);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropIntChanged(const FTestbed1StructIntWithArray& InPropInt)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	_GetPublisher()->BroadcastPropIntChanged(InPropInt);
}

FTestbed1StructIntWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropInt() const
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTestbed1StructIntWithArray();
	}
	return BackendService->GetPropInt();
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropInt(const FTestbed1StructIntWithArray& InPropInt)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	Testbed1StructArray2InterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->SetPropInt(InPropInt);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropFloatChanged(const FTestbed1StructFloatWithArray& InPropFloat)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	_GetPublisher()->BroadcastPropFloatChanged(InPropFloat);
}

FTestbed1StructFloatWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropFloat() const
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTestbed1StructFloatWithArray();
	}
	return BackendService->GetPropFloat();
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	Testbed1StructArray2InterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->SetPropFloat(InPropFloat);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropStringChanged(const FTestbed1StructStringWithArray& InPropString)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	_GetPublisher()->BroadcastPropStringChanged(InPropString);
}

FTestbed1StructStringWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropString() const
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTestbed1StructStringWithArray();
	}
	return BackendService->GetPropString();
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropString(const FTestbed1StructStringWithArray& InPropString)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	Testbed1StructArray2InterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->SetPropString(InPropString);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropEnumChanged(const FTestbed1StructEnumWithArray& InPropEnum)
{
	if (!BackendService)
	{
		return;
	}
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropEnum = InPropEnum;
	_GetPublisher()->BroadcastPropEnumChanged(InPropEnum);
}

FTestbed1StructEnumWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropEnum() const
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTestbed1StructEnumWithArray();
	}
	return BackendService->GetPropEnum();
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	Testbed1StructArray2InterfaceTracer::trace_callSetPropEnum(InPropEnum);
	BackendService->SetPropEnum(InPropEnum);
}

TArray<FTestbed1StructBool> UTestbed1StructArray2InterfaceLoggingDecorator::FuncBool(const FTestbed1StructBoolWithArray& ParamBool)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return TArray<FTestbed1StructBool>();
	}
	Testbed1StructArray2InterfaceTracer::trace_callFuncBool(ParamBool);
	return BackendService->FuncBool(ParamBool);
}

TArray<FTestbed1StructInt> UTestbed1StructArray2InterfaceLoggingDecorator::FuncInt(const FTestbed1StructIntWithArray& ParamInt)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return TArray<FTestbed1StructInt>();
	}
	Testbed1StructArray2InterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->FuncInt(ParamInt);
}

TArray<FTestbed1StructFloat> UTestbed1StructArray2InterfaceLoggingDecorator::FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return TArray<FTestbed1StructFloat>();
	}
	Testbed1StructArray2InterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->FuncFloat(ParamFloat);
}

TArray<FTestbed1StructString> UTestbed1StructArray2InterfaceLoggingDecorator::FuncString(const FTestbed1StructStringWithArray& ParamString)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return TArray<FTestbed1StructString>();
	}
	Testbed1StructArray2InterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->FuncString(ParamString);
}

TArray<ETestbed1Enum0> UTestbed1StructArray2InterfaceLoggingDecorator::FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum)
{
	if (!BackendService)
	{
		UE_LOG(LogTestbed1StructArray2InterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return TArray<ETestbed1Enum0>();
	}
	Testbed1StructArray2InterfaceTracer::trace_callFuncEnum(ParamEnum);
	return BackendService->FuncEnum(ParamEnum);
}
