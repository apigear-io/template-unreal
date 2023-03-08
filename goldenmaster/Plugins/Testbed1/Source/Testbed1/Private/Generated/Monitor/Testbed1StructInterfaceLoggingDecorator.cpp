
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
#include "Generated/Monitor/Testbed1StructInterfaceLoggingDecorator.h"
#include "Implementation/Testbed1StructInterface.h"
#include "Testbed1.trace.h"
#include "Testbed1Factory.h"
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
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService(FTestbed1ModuleFactory::createITestbed1StructInterfaceInterface(GetGameInstance(), Collection));
#else
	setBackendService(FTestbed1ModuleFactory::createITestbed1StructInterfaceInterface(Collection));
#endif
}

void UTestbed1StructInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTestbed1StructInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed1StructInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropBoolChanged);
		BackendService->GetPropIntChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropIntChanged);
		BackendService->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropFloatChanged);
		BackendService->GetPropStringChangedDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropStringChanged);
		BackendService->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigBool);
		BackendService->GetSigIntSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigInt);
		BackendService->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigFloat);
		BackendService->GetSigStringSignalDelegate().RemoveDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed1StructInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropIntChanged);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropFloatChanged);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnPropStringChanged);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigInt);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigFloat);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTestbed1StructInterfaceLoggingDecorator::OnSigString);
	// populate service state to proxy
	PropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
	PropFloat = BackendService->Execute_GetPropFloat(BackendService.GetObject());
	PropString = BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTestbed1StructInterfaceLoggingDecorator::OnSigBool(const FTestbed1StructBool& ParamBool)
{
	Testbed1StructInterfaceTracer::trace_signalSigBool(ParamBool);
	Execute_BroadcastSigBool(this, ParamBool);
}

void UTestbed1StructInterfaceLoggingDecorator::OnSigInt(const FTestbed1StructInt& ParamInt)
{
	Testbed1StructInterfaceTracer::trace_signalSigInt(ParamInt);
	Execute_BroadcastSigInt(this, ParamInt);
}

void UTestbed1StructInterfaceLoggingDecorator::OnSigFloat(const FTestbed1StructFloat& ParamFloat)
{
	Testbed1StructInterfaceTracer::trace_signalSigFloat(ParamFloat);
	Execute_BroadcastSigFloat(this, ParamFloat);
}

void UTestbed1StructInterfaceLoggingDecorator::OnSigString(const FTestbed1StructString& ParamString)
{
	Testbed1StructInterfaceTracer::trace_signalSigString(ParamString);
	Execute_BroadcastSigString(this, ParamString);
}

void UTestbed1StructInterfaceLoggingDecorator::OnPropBoolChanged(const FTestbed1StructBool& InPropBool)
{
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropBool = InPropBool;
	Execute_BroadcastPropBoolChanged(this, InPropBool);
}

FTestbed1StructBool UTestbed1StructInterfaceLoggingDecorator::GetPropBool_Implementation() const
{
	return BackendService->Execute_GetPropBool(BackendService.GetObject());
}

void UTestbed1StructInterfaceLoggingDecorator::SetPropBool_Implementation(const FTestbed1StructBool& InPropBool)
{
	Testbed1StructInterfaceTracer::trace_callSetPropBool(InPropBool);
	BackendService->Execute_SetPropBool(BackendService.GetObject(), InPropBool);
}

void UTestbed1StructInterfaceLoggingDecorator::OnPropIntChanged(const FTestbed1StructInt& InPropInt)
{
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	Execute_BroadcastPropIntChanged(this, InPropInt);
}

FTestbed1StructInt UTestbed1StructInterfaceLoggingDecorator::GetPropInt_Implementation() const
{
	return BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTestbed1StructInterfaceLoggingDecorator::SetPropInt_Implementation(const FTestbed1StructInt& InPropInt)
{
	Testbed1StructInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InPropInt);
}

void UTestbed1StructInterfaceLoggingDecorator::OnPropFloatChanged(const FTestbed1StructFloat& InPropFloat)
{
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	Execute_BroadcastPropFloatChanged(this, InPropFloat);
}

FTestbed1StructFloat UTestbed1StructInterfaceLoggingDecorator::GetPropFloat_Implementation() const
{
	return BackendService->Execute_GetPropFloat(BackendService.GetObject());
}

void UTestbed1StructInterfaceLoggingDecorator::SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	Testbed1StructInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->Execute_SetPropFloat(BackendService.GetObject(), InPropFloat);
}

void UTestbed1StructInterfaceLoggingDecorator::OnPropStringChanged(const FTestbed1StructString& InPropString)
{
	Testbed1StructInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	Execute_BroadcastPropStringChanged(this, InPropString);
}

FTestbed1StructString UTestbed1StructInterfaceLoggingDecorator::GetPropString_Implementation() const
{
	return BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTestbed1StructInterfaceLoggingDecorator::SetPropString_Implementation(const FTestbed1StructString& InPropString)
{
	Testbed1StructInterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->Execute_SetPropString(BackendService.GetObject(), InPropString);
}

FTestbed1StructBool UTestbed1StructInterfaceLoggingDecorator::FuncBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	Testbed1StructInterfaceTracer::trace_callFuncBool(ParamBool);
	return BackendService->Execute_FuncBool(BackendService.GetObject(), ParamBool);
}

FTestbed1StructBool UTestbed1StructInterfaceLoggingDecorator::FuncInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	Testbed1StructInterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
}

FTestbed1StructFloat UTestbed1StructInterfaceLoggingDecorator::FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	Testbed1StructInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
}

FTestbed1StructString UTestbed1StructInterfaceLoggingDecorator::FuncString_Implementation(const FTestbed1StructString& ParamString)
{
	Testbed1StructInterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
}
