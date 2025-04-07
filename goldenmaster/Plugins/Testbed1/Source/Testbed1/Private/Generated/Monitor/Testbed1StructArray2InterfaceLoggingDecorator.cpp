
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
#include "Generated/Monitor/Testbed1StructArray2InterfaceLoggingDecorator.h"
#include "Generated/Monitor/Testbed1.trace.h"
#include "Generated/Monitor/Testbed1Factory.h"
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
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService(FTestbed1ModuleFactory::createITestbed1StructArray2InterfaceInterface(GetGameInstance(), Collection));
#else
	setBackendService(FTestbed1ModuleFactory::createITestbed1StructArray2InterfaceInterface(Collection));
#endif
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
		UTestbed1StructArray2InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructArray2Interface"));
		BackendSignals->OnPropBoolChanged.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropBoolChanged);
		BackendSignals->OnPropIntChanged.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropIntChanged);
		BackendSignals->OnPropFloatChanged.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropFloatChanged);
		BackendSignals->OnPropStringChanged.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropStringChanged);
		BackendSignals->OnPropEnumChanged.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropEnumChanged);
		BackendSignals->OnSigBoolSignal.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigBool);
		BackendSignals->OnSigIntSignal.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigInt);
		BackendSignals->OnSigFloatSignal.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigFloat);
		BackendSignals->OnSigStringSignal.RemoveDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed1StructArray2Interface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed1StructArray2InterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructArray2Interface"));
	// connect property changed signals or simple events
	BackendSignals->OnPropBoolChanged.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropBoolChanged);
	BackendSignals->OnPropIntChanged.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropIntChanged);
	BackendSignals->OnPropFloatChanged.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropFloatChanged);
	BackendSignals->OnPropStringChanged.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropStringChanged);
	BackendSignals->OnPropEnumChanged.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnPropEnumChanged);
	BackendSignals->OnSigBoolSignal.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigBool);
	BackendSignals->OnSigIntSignal.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigInt);
	BackendSignals->OnSigFloatSignal.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigFloat);
	BackendSignals->OnSigStringSignal.AddDynamic(this, &UTestbed1StructArray2InterfaceLoggingDecorator::OnSigString);
	// populate service state to proxy
	PropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
	PropFloat = BackendService->Execute_GetPropFloat(BackendService.GetObject());
	PropString = BackendService->Execute_GetPropString(BackendService.GetObject());
	PropEnum = BackendService->Execute_GetPropEnum(BackendService.GetObject());
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnSigBool(const FTestbed1StructBoolWithArray& InParamBool)
{
	Testbed1StructArray2InterfaceTracer::trace_signalSigBool(InParamBool);
	Execute__GetSignals(this)->OnSigBoolSignal.Broadcast(InParamBool);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnSigInt(const FTestbed1StructIntWithArray& InParamInt)
{
	Testbed1StructArray2InterfaceTracer::trace_signalSigInt(InParamInt);
	Execute__GetSignals(this)->OnSigIntSignal.Broadcast(InParamInt);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnSigFloat(const FTestbed1StructFloatWithArray& InParamFloat)
{
	Testbed1StructArray2InterfaceTracer::trace_signalSigFloat(InParamFloat);
	Execute__GetSignals(this)->OnSigFloatSignal.Broadcast(InParamFloat);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnSigString(const FTestbed1StructStringWithArray& InParamString)
{
	Testbed1StructArray2InterfaceTracer::trace_signalSigString(InParamString);
	Execute__GetSignals(this)->OnSigStringSignal.Broadcast(InParamString);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropBoolChanged(const FTestbed1StructBoolWithArray& InPropBool)
{
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropBool = InPropBool;
	Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(InPropBool);
}

FTestbed1StructBoolWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropBool_Implementation() const
{
	return BackendService->Execute_GetPropBool(BackendService.GetObject());
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropBool_Implementation(const FTestbed1StructBoolWithArray& InPropBool)
{
	Testbed1StructArray2InterfaceTracer::trace_callSetPropBool(InPropBool);
	BackendService->Execute_SetPropBool(BackendService.GetObject(), InPropBool);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropIntChanged(const FTestbed1StructIntWithArray& InPropInt)
{
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	Execute__GetSignals(this)->OnPropIntChanged.Broadcast(InPropInt);
}

FTestbed1StructIntWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropInt_Implementation() const
{
	return BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropInt_Implementation(const FTestbed1StructIntWithArray& InPropInt)
{
	Testbed1StructArray2InterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InPropInt);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropFloatChanged(const FTestbed1StructFloatWithArray& InPropFloat)
{
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(InPropFloat);
}

FTestbed1StructFloatWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropFloat_Implementation() const
{
	return BackendService->Execute_GetPropFloat(BackendService.GetObject());
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropFloat_Implementation(const FTestbed1StructFloatWithArray& InPropFloat)
{
	Testbed1StructArray2InterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->Execute_SetPropFloat(BackendService.GetObject(), InPropFloat);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropStringChanged(const FTestbed1StructStringWithArray& InPropString)
{
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	Execute__GetSignals(this)->OnPropStringChanged.Broadcast(InPropString);
}

FTestbed1StructStringWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropString_Implementation() const
{
	return BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropString_Implementation(const FTestbed1StructStringWithArray& InPropString)
{
	Testbed1StructArray2InterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->Execute_SetPropString(BackendService.GetObject(), InPropString);
}

void UTestbed1StructArray2InterfaceLoggingDecorator::OnPropEnumChanged(const FTestbed1StructEnumWithArray& InPropEnum)
{
	Testbed1StructArray2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropEnum = InPropEnum;
	Execute__GetSignals(this)->OnPropEnumChanged.Broadcast(InPropEnum);
}

FTestbed1StructEnumWithArray UTestbed1StructArray2InterfaceLoggingDecorator::GetPropEnum_Implementation() const
{
	return BackendService->Execute_GetPropEnum(BackendService.GetObject());
}

void UTestbed1StructArray2InterfaceLoggingDecorator::SetPropEnum_Implementation(const FTestbed1StructEnumWithArray& InPropEnum)
{
	Testbed1StructArray2InterfaceTracer::trace_callSetPropEnum(InPropEnum);
	BackendService->Execute_SetPropEnum(BackendService.GetObject(), InPropEnum);
}

TArray<FTestbed1StructBool> UTestbed1StructArray2InterfaceLoggingDecorator::FuncBool_Implementation(const FTestbed1StructBoolWithArray& ParamBool)
{
	Testbed1StructArray2InterfaceTracer::trace_callFuncBool(ParamBool);
	return BackendService->Execute_FuncBool(BackendService.GetObject(), ParamBool);
}

TArray<FTestbed1StructInt> UTestbed1StructArray2InterfaceLoggingDecorator::FuncInt_Implementation(const FTestbed1StructIntWithArray& ParamInt)
{
	Testbed1StructArray2InterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
}

TArray<FTestbed1StructFloat> UTestbed1StructArray2InterfaceLoggingDecorator::FuncFloat_Implementation(const FTestbed1StructFloatWithArray& ParamFloat)
{
	Testbed1StructArray2InterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
}

TArray<FTestbed1StructString> UTestbed1StructArray2InterfaceLoggingDecorator::FuncString_Implementation(const FTestbed1StructStringWithArray& ParamString)
{
	Testbed1StructArray2InterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
}

TArray<ETestbed1Enum0> UTestbed1StructArray2InterfaceLoggingDecorator::FuncEnum_Implementation(const FTestbed1StructEnumWithArray& ParamEnum)
{
	Testbed1StructArray2InterfaceTracer::trace_callFuncEnum(ParamEnum);
	return BackendService->Execute_FuncEnum(BackendService.GetObject(), ParamEnum);
}
