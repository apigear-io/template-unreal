

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
	BackendService = nullptr;
}

void UTestbed1StructArray2InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed1StructArray2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed1StructArray2InterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructArray2Interface"));
		BackendSignals->OnPropBoolChangedBP.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropBoolChanged);
		BackendSignals->OnPropIntChangedBP.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropIntChanged);
		BackendSignals->OnPropFloatChangedBP.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropFloatChanged);
		BackendSignals->OnPropStringChangedBP.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropStringChanged);
		BackendSignals->OnPropEnumChangedBP.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropEnumChanged);
		BackendSignals->OnSigBoolSignalBP.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigBool);
		BackendSignals->OnSigIntSignalBP.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigInt);
		BackendSignals->OnSigFloatSignalBP.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigFloat);
		BackendSignals->OnSigStringSignalBP.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed1StructArray2Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed1StructArray2InterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructArray2Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnPropBoolChangedBP.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropBoolChanged);
	BackendSignals->OnPropIntChangedBP.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropIntChanged);
	BackendSignals->OnPropFloatChangedBP.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropFloatChanged);
	BackendSignals->OnPropStringChangedBP.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropStringChanged);
	BackendSignals->OnPropEnumChangedBP.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropEnumChanged);
	BackendSignals->OnSigBoolSignalBP.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigBool);
	BackendSignals->OnSigIntSignalBP.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigInt);
	BackendSignals->OnSigFloatSignalBP.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigFloat);
	BackendSignals->OnSigStringSignalBP.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigString);
	// populate service state to proxy
	PropBool = BackendService->GetPropBool();
	PropInt = BackendService->GetPropInt();
	PropFloat = BackendService->GetPropFloat();
	PropString = BackendService->GetPropString();
	PropEnum = BackendService->GetPropEnum();
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnSigBool(const FTestbed1StructBoolWithArray& InParamBool)
{
	Testbed1StructArray2InterfaceTracer::trace_signalSigBool(InParamBool);
	_GetSignals()->BroadcastSigBoolSignal(InParamBool);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnSigInt(const FTestbed1StructIntWithArray& InParamInt)
{
	Testbed1StructArray2InterfaceTracer::trace_signalSigInt(InParamInt);
	_GetSignals()->BroadcastSigIntSignal(InParamInt);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnSigFloat(const FTestbed1StructFloatWithArray& InParamFloat)
{
	Testbed1StructArray2InterfaceTracer::trace_signalSigFloat(InParamFloat);
	_GetSignals()->BroadcastSigFloatSignal(InParamFloat);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnSigString(const FTestbed1StructStringWithArray& InParamString)
{
	Testbed1StructArray2InterfaceTracer::trace_signalSigString(InParamString);
	_GetSignals()->BroadcastSigStringSignal(InParamString);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropBoolChanged(const FTestbed1StructBoolWithArray& InPropBool)
{
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropBool = InPropBool;
	_GetSignals()->BroadcastPropBoolChanged(InPropBool);
}

FTestbed1StructBoolWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropBool() const
{
	return BackendService->GetPropBool();
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropBool(const FTestbed1StructBoolWithArray& InPropBool)
{
	Testbed1StructArray2InterfaceTracer::trace_callSetPropBool(InPropBool);
	BackendService->SetPropBool(InPropBool);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropIntChanged(const FTestbed1StructIntWithArray& InPropInt)
{
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	_GetSignals()->BroadcastPropIntChanged(InPropInt);
}

FTestbed1StructIntWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropInt() const
{
	return BackendService->GetPropInt();
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropInt(const FTestbed1StructIntWithArray& InPropInt)
{
	Testbed1StructArray2InterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->SetPropInt(InPropInt);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropFloatChanged(const FTestbed1StructFloatWithArray& InPropFloat)
{
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	_GetSignals()->BroadcastPropFloatChanged(InPropFloat);
}

FTestbed1StructFloatWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropFloat() const
{
	return BackendService->GetPropFloat();
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat)
{
	Testbed1StructArray2InterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->SetPropFloat(InPropFloat);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropStringChanged(const FTestbed1StructStringWithArray& InPropString)
{
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	_GetSignals()->BroadcastPropStringChanged(InPropString);
}

FTestbed1StructStringWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropString() const
{
	return BackendService->GetPropString();
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropString(const FTestbed1StructStringWithArray& InPropString)
{
	Testbed1StructArray2InterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->SetPropString(InPropString);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropEnumChanged(const FTestbed1StructEnumWithArray& InPropEnum)
{
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropEnum = InPropEnum;
	_GetSignals()->BroadcastPropEnumChanged(InPropEnum);
}

FTestbed1StructEnumWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropEnum() const
{
	return BackendService->GetPropEnum();
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum)
{
	Testbed1StructArray2InterfaceTracer::trace_callSetPropEnum(InPropEnum);
	BackendService->SetPropEnum(InPropEnum);
}

TArray<FTestbed1StructBool> UTestbed1StructArray2InterfaceLoggingDecorator::FuncBool(const FTestbed1StructBoolWithArray& ParamBool)
{
	Testbed1StructArray2InterfaceTracer::trace_callFuncBool(ParamBool);
	return BackendService->FuncBool(ParamBool);
}

TArray<FTestbed1StructInt> UTestbed1StructArray2InterfaceLoggingDecorator::FuncInt(const FTestbed1StructIntWithArray& ParamInt)
{
	Testbed1StructArray2InterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->FuncInt(ParamInt);
}

TArray<FTestbed1StructFloat> UTestbed1StructArray2InterfaceLoggingDecorator::FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat)
{
	Testbed1StructArray2InterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->FuncFloat(ParamFloat);
}

TArray<FTestbed1StructString> UTestbed1StructArray2InterfaceLoggingDecorator::FuncString(const FTestbed1StructStringWithArray& ParamString)
{
	Testbed1StructArray2InterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->FuncString(ParamString);
}

TArray<ETestbed1Enum0> UTestbed1StructArray2InterfaceLoggingDecorator::FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum)
{
	Testbed1StructArray2InterfaceTracer::trace_callFuncEnum(ParamEnum);
	return BackendService->FuncEnum(ParamEnum);
}
