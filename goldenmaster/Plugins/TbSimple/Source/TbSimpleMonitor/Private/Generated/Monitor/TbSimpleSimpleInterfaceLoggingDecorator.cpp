

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
#include "TbSimple/Generated/Monitor/TbSimpleSimpleInterfaceLoggingDecorator.h"
#include "TbSimpleSettings.h"
#include "TbSimple.trace.h"
#include "TbSimple/Generated/TbSimpleFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSimpleSimpleInterfaceLoggingDecorator);
UTbSimpleSimpleInterfaceLoggingDecorator::UTbSimpleSimpleInterfaceLoggingDecorator()
	: UAbstractTbSimpleSimpleInterface()
{
}

UTbSimpleSimpleInterfaceLoggingDecorator::~UTbSimpleSimpleInterfaceLoggingDecorator() = default;

void UTbSimpleSimpleInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbSimpleSettings::GetITbSimpleSimpleInterfaceInterfaceForLogging(Collection));
}

void UTbSimpleSimpleInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSimpleSimpleInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSimpleSimpleInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleSimpleInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleSimpleInterface"));
		BackendSignals->OnPropBoolChanged.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropBoolChanged);
		BackendSignals->OnPropIntChanged.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropIntChanged);
		BackendSignals->OnPropInt32Changed.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropInt32Changed);
		BackendSignals->OnPropInt64Changed.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropInt64Changed);
		BackendSignals->OnPropFloatChanged.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloatChanged);
		BackendSignals->OnPropFloat32Changed.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloat32Changed);
		BackendSignals->OnPropFloat64Changed.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloat64Changed);
		BackendSignals->OnPropStringChanged.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropStringChanged);
		BackendSignals->OnSigBoolSignal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigBool);
		BackendSignals->OnSigIntSignal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt);
		BackendSignals->OnSigInt32Signal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt32);
		BackendSignals->OnSigInt64Signal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt64);
		BackendSignals->OnSigFloatSignal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat);
		BackendSignals->OnSigFloat32Signal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat32);
		BackendSignals->OnSigFloat64Signal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat64);
		BackendSignals->OnSigStringSignal.RemoveDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleSimpleInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleSimpleInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleSimpleInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnPropBoolChanged.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendSignals->OnPropIntChanged.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropIntChanged);
	BackendSignals->OnPropInt32Changed.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropInt32Changed);
	BackendSignals->OnPropInt64Changed.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropInt64Changed);
	BackendSignals->OnPropFloatChanged.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloatChanged);
	BackendSignals->OnPropFloat32Changed.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloat32Changed);
	BackendSignals->OnPropFloat64Changed.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloat64Changed);
	BackendSignals->OnPropStringChanged.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnPropStringChanged);
	BackendSignals->OnSigBoolSignal.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigBool);
	BackendSignals->OnSigIntSignal.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt);
	BackendSignals->OnSigInt32Signal.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt32);
	BackendSignals->OnSigInt64Signal.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt64);
	BackendSignals->OnSigFloatSignal.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat);
	BackendSignals->OnSigFloat32Signal.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat32);
	BackendSignals->OnSigFloat64Signal.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat64);
	BackendSignals->OnSigStringSignal.AddDynamic(this, &UTbSimpleSimpleInterfaceLoggingDecorator::OnSigString);
	// populate service state to proxy
	bPropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
	PropInt32 = BackendService->Execute_GetPropInt32(BackendService.GetObject());
	PropInt64 = BackendService->Execute_GetPropInt64(BackendService.GetObject());
	PropFloat = BackendService->Execute_GetPropFloat(BackendService.GetObject());
	PropFloat32 = BackendService->Execute_GetPropFloat32(BackendService.GetObject());
	PropFloat64 = BackendService->Execute_GetPropFloat64(BackendService.GetObject());
	PropString = BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigBool(bool bInParamBool)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigBool(bInParamBool);
	Execute__GetSignals(this)->OnSigBoolSignal.Broadcast(bInParamBool);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt(int32 InParamInt)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigInt(InParamInt);
	Execute__GetSignals(this)->OnSigIntSignal.Broadcast(InParamInt);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt32(int32 InParamInt32)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigInt32(InParamInt32);
	Execute__GetSignals(this)->OnSigInt32Signal.Broadcast(InParamInt32);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt64(int64 InParamInt64)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigInt64(InParamInt64);
	Execute__GetSignals(this)->OnSigInt64Signal.Broadcast(InParamInt64);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat(float InParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigFloat(InParamFloat);
	Execute__GetSignals(this)->OnSigFloatSignal.Broadcast(InParamFloat);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat32(float InParamFloat32)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigFloat32(InParamFloat32);
	Execute__GetSignals(this)->OnSigFloat32Signal.Broadcast(InParamFloat32);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat64(double InParamFloat64)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigFloat64(InParamFloat64);
	Execute__GetSignals(this)->OnSigFloat64Signal.Broadcast(InParamFloat64);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigString(const FString& InParamString)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigString(InParamString);
	Execute__GetSignals(this)->OnSigStringSignal.Broadcast(InParamString);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropBoolChanged(bool bInPropBool)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	bPropBool = bInPropBool;
	Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(bInPropBool);
}

bool UTbSimpleSimpleInterfaceLoggingDecorator::GetPropBool_Implementation() const
{
	return BackendService->Execute_GetPropBool(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropBool_Implementation(bool bInPropBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropBool(bInPropBool);
	BackendService->Execute_SetPropBool(BackendService.GetObject(), bInPropBool);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropIntChanged(int32 InPropInt)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	Execute__GetSignals(this)->OnPropIntChanged.Broadcast(InPropInt);
}

int32 UTbSimpleSimpleInterfaceLoggingDecorator::GetPropInt_Implementation() const
{
	return BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropInt_Implementation(int32 InPropInt)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InPropInt);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropInt32Changed(int32 InPropInt32)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt32 = InPropInt32;
	Execute__GetSignals(this)->OnPropInt32Changed.Broadcast(InPropInt32);
}

int32 UTbSimpleSimpleInterfaceLoggingDecorator::GetPropInt32_Implementation() const
{
	return BackendService->Execute_GetPropInt32(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropInt32_Implementation(int32 InPropInt32)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropInt32(InPropInt32);
	BackendService->Execute_SetPropInt32(BackendService.GetObject(), InPropInt32);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropInt64Changed(int64 InPropInt64)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt64 = InPropInt64;
	Execute__GetSignals(this)->OnPropInt64Changed.Broadcast(InPropInt64);
}

int64 UTbSimpleSimpleInterfaceLoggingDecorator::GetPropInt64_Implementation() const
{
	return BackendService->Execute_GetPropInt64(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropInt64_Implementation(int64 InPropInt64)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropInt64(InPropInt64);
	BackendService->Execute_SetPropInt64(BackendService.GetObject(), InPropInt64);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloatChanged(float InPropFloat)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(InPropFloat);
}

float UTbSimpleSimpleInterfaceLoggingDecorator::GetPropFloat_Implementation() const
{
	return BackendService->Execute_GetPropFloat(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropFloat_Implementation(float InPropFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->Execute_SetPropFloat(BackendService.GetObject(), InPropFloat);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloat32Changed(float InPropFloat32)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat32 = InPropFloat32;
	Execute__GetSignals(this)->OnPropFloat32Changed.Broadcast(InPropFloat32);
}

float UTbSimpleSimpleInterfaceLoggingDecorator::GetPropFloat32_Implementation() const
{
	return BackendService->Execute_GetPropFloat32(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropFloat32_Implementation(float InPropFloat32)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropFloat32(InPropFloat32);
	BackendService->Execute_SetPropFloat32(BackendService.GetObject(), InPropFloat32);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloat64Changed(double InPropFloat64)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat64 = InPropFloat64;
	Execute__GetSignals(this)->OnPropFloat64Changed.Broadcast(InPropFloat64);
}

double UTbSimpleSimpleInterfaceLoggingDecorator::GetPropFloat64_Implementation() const
{
	return BackendService->Execute_GetPropFloat64(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropFloat64_Implementation(double InPropFloat64)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropFloat64(InPropFloat64);
	BackendService->Execute_SetPropFloat64(BackendService.GetObject(), InPropFloat64);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropStringChanged(const FString& InPropString)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	Execute__GetSignals(this)->OnPropStringChanged.Broadcast(InPropString);
}

FString UTbSimpleSimpleInterfaceLoggingDecorator::GetPropString_Implementation() const
{
	return BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropString_Implementation(const FString& InPropString)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->Execute_SetPropString(BackendService.GetObject(), InPropString);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::FuncNoReturnValue_Implementation(bool bParamBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncNoReturnValue(bParamBool);
	BackendService->Execute_FuncNoReturnValue(BackendService.GetObject(), bParamBool);
}

bool UTbSimpleSimpleInterfaceLoggingDecorator::FuncBool_Implementation(bool bParamBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncBool(bParamBool);
	return BackendService->Execute_FuncBool(BackendService.GetObject(), bParamBool);
}

int32 UTbSimpleSimpleInterfaceLoggingDecorator::FuncInt_Implementation(int32 ParamInt)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
}

int32 UTbSimpleSimpleInterfaceLoggingDecorator::FuncInt32_Implementation(int32 ParamInt32)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt32(ParamInt32);
	return BackendService->Execute_FuncInt32(BackendService.GetObject(), ParamInt32);
}

int64 UTbSimpleSimpleInterfaceLoggingDecorator::FuncInt64_Implementation(int64 ParamInt64)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt64(ParamInt64);
	return BackendService->Execute_FuncInt64(BackendService.GetObject(), ParamInt64);
}

float UTbSimpleSimpleInterfaceLoggingDecorator::FuncFloat_Implementation(float ParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
}

float UTbSimpleSimpleInterfaceLoggingDecorator::FuncFloat32_Implementation(float ParamFloat32)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat32(ParamFloat32);
	return BackendService->Execute_FuncFloat32(BackendService.GetObject(), ParamFloat32);
}

double UTbSimpleSimpleInterfaceLoggingDecorator::FuncFloat64_Implementation(double ParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat64(ParamFloat);
	return BackendService->Execute_FuncFloat64(BackendService.GetObject(), ParamFloat);
}

FString UTbSimpleSimpleInterfaceLoggingDecorator::FuncString_Implementation(const FString& ParamString)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
}
