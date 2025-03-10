

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
#include "Testbed1/Generated/Monitor/Testbed1StructArrayInterfaceLoggingDecorator.h"
#include "Testbed1Settings.h"
#include "Testbed1.trace.h"
#include "Testbed1/Generated/Testbed1Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTestbed1StructArrayInterfaceLoggingDecorator);
UTestbed1StructArrayInterfaceLoggingDecorator::UTestbed1StructArrayInterfaceLoggingDecorator()
	: UAbstractTestbed1StructArrayInterface()
{
}

UTestbed1StructArrayInterfaceLoggingDecorator::~UTestbed1StructArrayInterfaceLoggingDecorator() = default;

void UTestbed1StructArrayInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTestbed1Settings::GetITestbed1StructArrayInterfaceInterfaceForLogging(Collection));
}

void UTestbed1StructArrayInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTestbed1StructArrayInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed1StructArrayInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTestbed1StructArrayInterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructArrayInterface"));
		BackendSignals->OnPropBoolChanged.RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropBoolChanged);
		BackendSignals->OnPropIntChanged.RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropIntChanged);
		BackendSignals->OnPropFloatChanged.RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropFloatChanged);
		BackendSignals->OnPropStringChanged.RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropStringChanged);
		BackendSignals->OnSigBoolSignal.RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigBool);
		BackendSignals->OnSigIntSignal.RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigInt);
		BackendSignals->OnSigFloatSignal.RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigFloat);
		BackendSignals->OnSigStringSignal.RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed1StructArrayInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTestbed1StructArrayInterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service Testbed1StructArrayInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnPropBoolChanged.AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendSignals->OnPropIntChanged.AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropIntChanged);
	BackendSignals->OnPropFloatChanged.AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropFloatChanged);
	BackendSignals->OnPropStringChanged.AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropStringChanged);
	BackendSignals->OnSigBoolSignal.AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigBool);
	BackendSignals->OnSigIntSignal.AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigInt);
	BackendSignals->OnSigFloatSignal.AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigFloat);
	BackendSignals->OnSigStringSignal.AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigString);
	// populate service state to proxy
	PropBool = BackendService->GetPropBool();
	PropInt = BackendService->GetPropInt();
	PropFloat = BackendService->GetPropFloat();
	PropString = BackendService->GetPropString();
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnSigBool(const TArray<FTestbed1StructBool>& InParamBool)
{
	Testbed1StructArrayInterfaceTracer::trace_signalSigBool(InParamBool);
	_GetSignals()->BroadcastSigBoolSignal(InParamBool);
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnSigInt(const TArray<FTestbed1StructInt>& InParamInt)
{
	Testbed1StructArrayInterfaceTracer::trace_signalSigInt(InParamInt);
	_GetSignals()->BroadcastSigIntSignal(InParamInt);
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnSigFloat(const TArray<FTestbed1StructFloat>& InParamFloat)
{
	Testbed1StructArrayInterfaceTracer::trace_signalSigFloat(InParamFloat);
	_GetSignals()->BroadcastSigFloatSignal(InParamFloat);
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnSigString(const TArray<FTestbed1StructString>& InParamString)
{
	Testbed1StructArrayInterfaceTracer::trace_signalSigString(InParamString);
	_GetSignals()->BroadcastSigStringSignal(InParamString);
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnPropBoolChanged(const TArray<FTestbed1StructBool>& InPropBool)
{
	Testbed1StructArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropBool = InPropBool;
	_GetSignals()->BroadcastPropBoolChanged(InPropBool);
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceLoggingDecorator::GetPropBool() const
{
	return BackendService->GetPropBool();
}

void UTestbed1StructArrayInterfaceLoggingDecorator::SetPropBool(const TArray<FTestbed1StructBool>& InPropBool)
{
	Testbed1StructArrayInterfaceTracer::trace_callSetPropBool(InPropBool);
	BackendService->SetPropBool(InPropBool);
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnPropIntChanged(const TArray<FTestbed1StructInt>& InPropInt)
{
	Testbed1StructArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	_GetSignals()->BroadcastPropIntChanged(InPropInt);
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceLoggingDecorator::GetPropInt() const
{
	return BackendService->GetPropInt();
}

void UTestbed1StructArrayInterfaceLoggingDecorator::SetPropInt(const TArray<FTestbed1StructInt>& InPropInt)
{
	Testbed1StructArrayInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->SetPropInt(InPropInt);
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnPropFloatChanged(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	Testbed1StructArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	_GetSignals()->BroadcastPropFloatChanged(InPropFloat);
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceLoggingDecorator::GetPropFloat() const
{
	return BackendService->GetPropFloat();
}

void UTestbed1StructArrayInterfaceLoggingDecorator::SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	Testbed1StructArrayInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->SetPropFloat(InPropFloat);
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnPropStringChanged(const TArray<FTestbed1StructString>& InPropString)
{
	Testbed1StructArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	_GetSignals()->BroadcastPropStringChanged(InPropString);
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceLoggingDecorator::GetPropString() const
{
	return BackendService->GetPropString();
}

void UTestbed1StructArrayInterfaceLoggingDecorator::SetPropString(const TArray<FTestbed1StructString>& InPropString)
{
	Testbed1StructArrayInterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->SetPropString(InPropString);
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceLoggingDecorator::FuncBool(const TArray<FTestbed1StructBool>& ParamBool)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncBool(ParamBool);
	return BackendService->FuncBool(ParamBool);
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceLoggingDecorator::FuncInt(const TArray<FTestbed1StructInt>& ParamInt)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->FuncInt(ParamInt);
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceLoggingDecorator::FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->FuncFloat(ParamFloat);
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceLoggingDecorator::FuncString(const TArray<FTestbed1StructString>& ParamString)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->FuncString(ParamString);
}
