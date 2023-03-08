
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
#include "Generated/Monitor/Testbed1StructArrayInterfaceLoggingDecorator.h"
#include "Implementation/Testbed1StructArrayInterface.h"
#include "Testbed1.trace.h"
#include "Testbed1Factory.h"
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
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService(FTestbed1ModuleFactory::createITestbed1StructArrayInterfaceInterface(GetGameInstance(), Collection));
#else
	setBackendService(FTestbed1ModuleFactory::createITestbed1StructArrayInterfaceInterface(Collection));
#endif
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
		BackendService->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropBoolChanged);
		BackendService->GetPropIntChangedDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropIntChanged);
		BackendService->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropFloatChanged);
		BackendService->GetPropStringChangedDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropStringChanged);
		BackendService->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigBool);
		BackendService->GetSigIntSignalDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigInt);
		BackendService->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigFloat);
		BackendService->GetSigStringSignalDelegate().RemoveDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface Testbed1StructArrayInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropIntChanged);
	BackendService->GetPropFloatChangedDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropFloatChanged);
	BackendService->GetPropStringChangedDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnPropStringChanged);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigBool);
	BackendService->GetSigIntSignalDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigInt);
	BackendService->GetSigFloatSignalDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigFloat);
	BackendService->GetSigStringSignalDelegate().AddDynamic(this, &UTestbed1StructArrayInterfaceLoggingDecorator::OnSigString);
	// populate service state to proxy
	PropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
	PropFloat = BackendService->Execute_GetPropFloat(BackendService.GetObject());
	PropString = BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnSigBool(const TArray<FTestbed1StructBool>& ParamBool)
{
	Testbed1StructArrayInterfaceTracer::trace_signalSigBool(ParamBool);
	Execute_BroadcastSigBool(this, ParamBool);
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnSigInt(const TArray<FTestbed1StructInt>& ParamInt)
{
	Testbed1StructArrayInterfaceTracer::trace_signalSigInt(ParamInt);
	Execute_BroadcastSigInt(this, ParamInt);
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnSigFloat(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	Testbed1StructArrayInterfaceTracer::trace_signalSigFloat(ParamFloat);
	Execute_BroadcastSigFloat(this, ParamFloat);
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnSigString(const TArray<FTestbed1StructString>& ParamString)
{
	Testbed1StructArrayInterfaceTracer::trace_signalSigString(ParamString);
	Execute_BroadcastSigString(this, ParamString);
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnPropBoolChanged(const TArray<FTestbed1StructBool>& InPropBool)
{
	Testbed1StructArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropBool = InPropBool;
	Execute_BroadcastPropBoolChanged(this, InPropBool);
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceLoggingDecorator::GetPropBool_Implementation() const
{
	return BackendService->Execute_GetPropBool(BackendService.GetObject());
}

void UTestbed1StructArrayInterfaceLoggingDecorator::SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	Testbed1StructArrayInterfaceTracer::trace_callSetPropBool(InPropBool);
	BackendService->Execute_SetPropBool(BackendService.GetObject(), InPropBool);
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnPropIntChanged(const TArray<FTestbed1StructInt>& InPropInt)
{
	Testbed1StructArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	Execute_BroadcastPropIntChanged(this, InPropInt);
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceLoggingDecorator::GetPropInt_Implementation() const
{
	return BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTestbed1StructArrayInterfaceLoggingDecorator::SetPropInt_Implementation(const TArray<FTestbed1StructInt>& InPropInt)
{
	Testbed1StructArrayInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InPropInt);
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnPropFloatChanged(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	Testbed1StructArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	Execute_BroadcastPropFloatChanged(this, InPropFloat);
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceLoggingDecorator::GetPropFloat_Implementation() const
{
	return BackendService->Execute_GetPropFloat(BackendService.GetObject());
}

void UTestbed1StructArrayInterfaceLoggingDecorator::SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	Testbed1StructArrayInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->Execute_SetPropFloat(BackendService.GetObject(), InPropFloat);
}

void UTestbed1StructArrayInterfaceLoggingDecorator::OnPropStringChanged(const TArray<FTestbed1StructString>& InPropString)
{
	Testbed1StructArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	Execute_BroadcastPropStringChanged(this, InPropString);
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceLoggingDecorator::GetPropString_Implementation() const
{
	return BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTestbed1StructArrayInterfaceLoggingDecorator::SetPropString_Implementation(const TArray<FTestbed1StructString>& InPropString)
{
	Testbed1StructArrayInterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->Execute_SetPropString(BackendService.GetObject(), InPropString);
}

FTestbed1StructBool UTestbed1StructArrayInterfaceLoggingDecorator::FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncBool(ParamBool);
	return BackendService->Execute_FuncBool(BackendService.GetObject(), ParamBool);
}

FTestbed1StructBool UTestbed1StructArrayInterfaceLoggingDecorator::FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
}

FTestbed1StructBool UTestbed1StructArrayInterfaceLoggingDecorator::FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
}

FTestbed1StructBool UTestbed1StructArrayInterfaceLoggingDecorator::FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString)
{
	Testbed1StructArrayInterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
}
