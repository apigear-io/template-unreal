

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
#include "TbSimple/Generated/Monitor/TbSimpleSimpleArrayInterfaceLoggingDecorator.h"
#include "TbSimpleSettings.h"
#include "TbSimple.trace.h"
#include "TbSimple/Generated/TbSimpleFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSimpleSimpleArrayInterfaceLoggingDecorator);
UTbSimpleSimpleArrayInterfaceLoggingDecorator::UTbSimpleSimpleArrayInterfaceLoggingDecorator()
	: UAbstractTbSimpleSimpleArrayInterface()
{
}

UTbSimpleSimpleArrayInterfaceLoggingDecorator::~UTbSimpleSimpleArrayInterfaceLoggingDecorator() = default;

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbSimpleSettings::GetITbSimpleSimpleArrayInterfaceInterfaceForLogging(Collection));
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleSimpleArrayInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleSimpleArrayInterface"));
		BackendSignals->OnPropBoolChanged.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropBoolChanged);
		BackendSignals->OnPropIntChanged.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropIntChanged);
		BackendSignals->OnPropInt32Changed.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropInt32Changed);
		BackendSignals->OnPropInt64Changed.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropInt64Changed);
		BackendSignals->OnPropFloatChanged.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloatChanged);
		BackendSignals->OnPropFloat32Changed.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloat32Changed);
		BackendSignals->OnPropFloat64Changed.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloat64Changed);
		BackendSignals->OnPropStringChanged.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropStringChanged);
		BackendSignals->OnPropReadOnlyStringChanged.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropReadOnlyStringChanged);
		BackendSignals->OnSigBoolSignal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigBool);
		BackendSignals->OnSigIntSignal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt);
		BackendSignals->OnSigInt32Signal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt32);
		BackendSignals->OnSigInt64Signal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt64);
		BackendSignals->OnSigFloatSignal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat);
		BackendSignals->OnSigFloat32Signal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat32);
		BackendSignals->OnSigFloat64Signal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat64);
		BackendSignals->OnSigStringSignal.RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigString);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleSimpleArrayInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleSimpleArrayInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleSimpleArrayInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnPropBoolChanged.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendSignals->OnPropIntChanged.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropIntChanged);
	BackendSignals->OnPropInt32Changed.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropInt32Changed);
	BackendSignals->OnPropInt64Changed.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropInt64Changed);
	BackendSignals->OnPropFloatChanged.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloatChanged);
	BackendSignals->OnPropFloat32Changed.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloat32Changed);
	BackendSignals->OnPropFloat64Changed.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloat64Changed);
	BackendSignals->OnPropStringChanged.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropStringChanged);
	BackendSignals->OnPropReadOnlyStringChanged.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropReadOnlyStringChanged);
	BackendSignals->OnSigBoolSignal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigBool);
	BackendSignals->OnSigIntSignal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt);
	BackendSignals->OnSigInt32Signal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt32);
	BackendSignals->OnSigInt64Signal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt64);
	BackendSignals->OnSigFloatSignal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat);
	BackendSignals->OnSigFloat32Signal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat32);
	BackendSignals->OnSigFloat64Signal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat64);
	BackendSignals->OnSigStringSignal.AddDynamic(this, &UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigString);
	// populate service state to proxy
	PropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
	PropInt32 = BackendService->Execute_GetPropInt32(BackendService.GetObject());
	PropInt64 = BackendService->Execute_GetPropInt64(BackendService.GetObject());
	PropFloat = BackendService->Execute_GetPropFloat(BackendService.GetObject());
	PropFloat32 = BackendService->Execute_GetPropFloat32(BackendService.GetObject());
	PropFloat64 = BackendService->Execute_GetPropFloat64(BackendService.GetObject());
	PropString = BackendService->Execute_GetPropString(BackendService.GetObject());
	PropReadOnlyString = BackendService->Execute_GetPropReadOnlyString(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigBool(const TArray<bool>& InParamBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigBool(InParamBool);
	Execute__GetSignals(this)->OnSigBoolSignal.Broadcast(InParamBool);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt(const TArray<int32>& InParamInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigInt(InParamInt);
	Execute__GetSignals(this)->OnSigIntSignal.Broadcast(InParamInt);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt32(const TArray<int32>& InParamInt32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigInt32(InParamInt32);
	Execute__GetSignals(this)->OnSigInt32Signal.Broadcast(InParamInt32);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt64(const TArray<int64>& InParamInt64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigInt64(InParamInt64);
	Execute__GetSignals(this)->OnSigInt64Signal.Broadcast(InParamInt64);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat(const TArray<float>& InParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigFloat(InParamFloat);
	Execute__GetSignals(this)->OnSigFloatSignal.Broadcast(InParamFloat);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat32(const TArray<float>& InParamFloa32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigFloat32(InParamFloa32);
	Execute__GetSignals(this)->OnSigFloat32Signal.Broadcast(InParamFloa32);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat64(const TArray<double>& InParamFloat64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigFloat64(InParamFloat64);
	Execute__GetSignals(this)->OnSigFloat64Signal.Broadcast(InParamFloat64);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigString(const TArray<FString>& InParamString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigString(InParamString);
	Execute__GetSignals(this)->OnSigStringSignal.Broadcast(InParamString);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropBoolChanged(const TArray<bool>& InPropBool)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropBool = InPropBool;
	Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(InPropBool);
}

TArray<bool> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropBool_Implementation() const
{
	return BackendService->Execute_GetPropBool(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropBool_Implementation(const TArray<bool>& InPropBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropBool(InPropBool);
	BackendService->Execute_SetPropBool(BackendService.GetObject(), InPropBool);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropIntChanged(const TArray<int32>& InPropInt)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	Execute__GetSignals(this)->OnPropIntChanged.Broadcast(InPropInt);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropInt_Implementation() const
{
	return BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropInt_Implementation(const TArray<int32>& InPropInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InPropInt);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropInt32Changed(const TArray<int32>& InPropInt32)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt32 = InPropInt32;
	Execute__GetSignals(this)->OnPropInt32Changed.Broadcast(InPropInt32);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropInt32_Implementation() const
{
	return BackendService->Execute_GetPropInt32(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropInt32_Implementation(const TArray<int32>& InPropInt32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropInt32(InPropInt32);
	BackendService->Execute_SetPropInt32(BackendService.GetObject(), InPropInt32);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropInt64Changed(const TArray<int64>& InPropInt64)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt64 = InPropInt64;
	Execute__GetSignals(this)->OnPropInt64Changed.Broadcast(InPropInt64);
}

TArray<int64> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropInt64_Implementation() const
{
	return BackendService->Execute_GetPropInt64(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropInt64_Implementation(const TArray<int64>& InPropInt64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropInt64(InPropInt64);
	BackendService->Execute_SetPropInt64(BackendService.GetObject(), InPropInt64);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloatChanged(const TArray<float>& InPropFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(InPropFloat);
}

TArray<float> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropFloat_Implementation() const
{
	return BackendService->Execute_GetPropFloat(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropFloat_Implementation(const TArray<float>& InPropFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->Execute_SetPropFloat(BackendService.GetObject(), InPropFloat);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloat32Changed(const TArray<float>& InPropFloat32)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat32 = InPropFloat32;
	Execute__GetSignals(this)->OnPropFloat32Changed.Broadcast(InPropFloat32);
}

TArray<float> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropFloat32_Implementation() const
{
	return BackendService->Execute_GetPropFloat32(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropFloat32_Implementation(const TArray<float>& InPropFloat32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropFloat32(InPropFloat32);
	BackendService->Execute_SetPropFloat32(BackendService.GetObject(), InPropFloat32);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloat64Changed(const TArray<double>& InPropFloat64)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat64 = InPropFloat64;
	Execute__GetSignals(this)->OnPropFloat64Changed.Broadcast(InPropFloat64);
}

TArray<double> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropFloat64_Implementation() const
{
	return BackendService->Execute_GetPropFloat64(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropFloat64_Implementation(const TArray<double>& InPropFloat64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropFloat64(InPropFloat64);
	BackendService->Execute_SetPropFloat64(BackendService.GetObject(), InPropFloat64);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropStringChanged(const TArray<FString>& InPropString)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	Execute__GetSignals(this)->OnPropStringChanged.Broadcast(InPropString);
}

TArray<FString> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropString_Implementation() const
{
	return BackendService->Execute_GetPropString(BackendService.GetObject());
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropString_Implementation(const TArray<FString>& InPropString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->Execute_SetPropString(BackendService.GetObject(), InPropString);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropReadOnlyStringChanged(const FString& InPropReadOnlyString)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropReadOnlyString = InPropReadOnlyString;
	Execute__GetSignals(this)->OnPropReadOnlyStringChanged.Broadcast(InPropReadOnlyString);
}

FString UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropReadOnlyString_Implementation() const
{
	return BackendService->Execute_GetPropReadOnlyString(BackendService.GetObject());
}

TArray<bool> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncBool_Implementation(const TArray<bool>& ParamBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncBool(ParamBool);
	return BackendService->Execute_FuncBool(BackendService.GetObject(), ParamBool);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncInt_Implementation(const TArray<int32>& ParamInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->Execute_FuncInt(BackendService.GetObject(), ParamInt);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncInt32_Implementation(const TArray<int32>& ParamInt32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt32(ParamInt32);
	return BackendService->Execute_FuncInt32(BackendService.GetObject(), ParamInt32);
}

TArray<int64> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncInt64_Implementation(const TArray<int64>& ParamInt64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt64(ParamInt64);
	return BackendService->Execute_FuncInt64(BackendService.GetObject(), ParamInt64);
}

TArray<float> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncFloat_Implementation(const TArray<float>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->Execute_FuncFloat(BackendService.GetObject(), ParamFloat);
}

TArray<float> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncFloat32_Implementation(const TArray<float>& ParamFloat32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat32(ParamFloat32);
	return BackendService->Execute_FuncFloat32(BackendService.GetObject(), ParamFloat32);
}

TArray<double> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncFloat64_Implementation(const TArray<double>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat64(ParamFloat);
	return BackendService->Execute_FuncFloat64(BackendService.GetObject(), ParamFloat);
}

TArray<FString> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncString_Implementation(const TArray<FString>& ParamString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->Execute_FuncString(BackendService.GetObject(), ParamString);
}
