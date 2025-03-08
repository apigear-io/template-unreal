

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
		UTbSimpleSimpleArrayInterfaceSignals* BackendSignals = BackendService->_GetSignals();
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
	UTbSimpleSimpleArrayInterfaceSignals* BackendSignals = BackendService->_GetSignals();
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
	PropBool = BackendService->GetPropBool();
	PropInt = BackendService->GetPropInt();
	PropInt32 = BackendService->GetPropInt32();
	PropInt64 = BackendService->GetPropInt64();
	PropFloat = BackendService->GetPropFloat();
	PropFloat32 = BackendService->GetPropFloat32();
	PropFloat64 = BackendService->GetPropFloat64();
	PropString = BackendService->GetPropString();
	PropReadOnlyString = BackendService->GetPropReadOnlyString();
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigBool(const TArray<bool>& InParamBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigBool(InParamBool);
	_GetSignals()->OnSigBoolSignal.Broadcast(InParamBool);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt(const TArray<int32>& InParamInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigInt(InParamInt);
	_GetSignals()->OnSigIntSignal.Broadcast(InParamInt);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt32(const TArray<int32>& InParamInt32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigInt32(InParamInt32);
	_GetSignals()->OnSigInt32Signal.Broadcast(InParamInt32);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigInt64(const TArray<int64>& InParamInt64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigInt64(InParamInt64);
	_GetSignals()->OnSigInt64Signal.Broadcast(InParamInt64);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat(const TArray<float>& InParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigFloat(InParamFloat);
	_GetSignals()->OnSigFloatSignal.Broadcast(InParamFloat);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat32(const TArray<float>& InParamFloa32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigFloat32(InParamFloa32);
	_GetSignals()->OnSigFloat32Signal.Broadcast(InParamFloa32);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigFloat64(const TArray<double>& InParamFloat64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigFloat64(InParamFloat64);
	_GetSignals()->OnSigFloat64Signal.Broadcast(InParamFloat64);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnSigString(const TArray<FString>& InParamString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigString(InParamString);
	_GetSignals()->OnSigStringSignal.Broadcast(InParamString);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropBoolChanged(const TArray<bool>& InPropBool)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropBool = InPropBool;
	_GetSignals()->OnPropBoolChanged.Broadcast(InPropBool);
}

TArray<bool> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropBool() const
{
	return BackendService->GetPropBool();
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropBool(const TArray<bool>& InPropBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropBool(InPropBool);
	BackendService->SetPropBool(InPropBool);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropIntChanged(const TArray<int32>& InPropInt)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	_GetSignals()->OnPropIntChanged.Broadcast(InPropInt);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropInt() const
{
	return BackendService->GetPropInt();
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropInt(const TArray<int32>& InPropInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->SetPropInt(InPropInt);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropInt32Changed(const TArray<int32>& InPropInt32)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt32 = InPropInt32;
	_GetSignals()->OnPropInt32Changed.Broadcast(InPropInt32);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropInt32() const
{
	return BackendService->GetPropInt32();
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropInt32(const TArray<int32>& InPropInt32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropInt32(InPropInt32);
	BackendService->SetPropInt32(InPropInt32);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropInt64Changed(const TArray<int64>& InPropInt64)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt64 = InPropInt64;
	_GetSignals()->OnPropInt64Changed.Broadcast(InPropInt64);
}

TArray<int64> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropInt64() const
{
	return BackendService->GetPropInt64();
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropInt64(const TArray<int64>& InPropInt64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropInt64(InPropInt64);
	BackendService->SetPropInt64(InPropInt64);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloatChanged(const TArray<float>& InPropFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	_GetSignals()->OnPropFloatChanged.Broadcast(InPropFloat);
}

TArray<float> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropFloat() const
{
	return BackendService->GetPropFloat();
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropFloat(const TArray<float>& InPropFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->SetPropFloat(InPropFloat);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloat32Changed(const TArray<float>& InPropFloat32)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat32 = InPropFloat32;
	_GetSignals()->OnPropFloat32Changed.Broadcast(InPropFloat32);
}

TArray<float> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropFloat32() const
{
	return BackendService->GetPropFloat32();
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropFloat32(const TArray<float>& InPropFloat32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropFloat32(InPropFloat32);
	BackendService->SetPropFloat32(InPropFloat32);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropFloat64Changed(const TArray<double>& InPropFloat64)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat64 = InPropFloat64;
	_GetSignals()->OnPropFloat64Changed.Broadcast(InPropFloat64);
}

TArray<double> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropFloat64() const
{
	return BackendService->GetPropFloat64();
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropFloat64(const TArray<double>& InPropFloat64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropFloat64(InPropFloat64);
	BackendService->SetPropFloat64(InPropFloat64);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropStringChanged(const TArray<FString>& InPropString)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	_GetSignals()->OnPropStringChanged.Broadcast(InPropString);
}

TArray<FString> UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropString() const
{
	return BackendService->GetPropString();
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::SetPropString(const TArray<FString>& InPropString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->SetPropString(InPropString);
}

void UTbSimpleSimpleArrayInterfaceLoggingDecorator::OnPropReadOnlyStringChanged(const FString& InPropReadOnlyString)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropReadOnlyString = InPropReadOnlyString;
	_GetSignals()->OnPropReadOnlyStringChanged.Broadcast(InPropReadOnlyString);
}

FString UTbSimpleSimpleArrayInterfaceLoggingDecorator::GetPropReadOnlyString() const
{
	return BackendService->GetPropReadOnlyString();
}

TArray<bool> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncBool(const TArray<bool>& ParamBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncBool(ParamBool);
	return BackendService->FuncBool(ParamBool);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncInt(const TArray<int32>& ParamInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->FuncInt(ParamInt);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncInt32(const TArray<int32>& ParamInt32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt32(ParamInt32);
	return BackendService->FuncInt32(ParamInt32);
}

TArray<int64> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncInt64(const TArray<int64>& ParamInt64)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt64(ParamInt64);
	return BackendService->FuncInt64(ParamInt64);
}

TArray<float> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncFloat(const TArray<float>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->FuncFloat(ParamFloat);
}

TArray<float> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncFloat32(const TArray<float>& ParamFloat32)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat32(ParamFloat32);
	return BackendService->FuncFloat32(ParamFloat32);
}

TArray<double> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncFloat64(const TArray<double>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat64(ParamFloat);
	return BackendService->FuncFloat64(ParamFloat);
}

TArray<FString> UTbSimpleSimpleArrayInterfaceLoggingDecorator::FuncString(const TArray<FString>& ParamString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->FuncString(ParamString);
}
