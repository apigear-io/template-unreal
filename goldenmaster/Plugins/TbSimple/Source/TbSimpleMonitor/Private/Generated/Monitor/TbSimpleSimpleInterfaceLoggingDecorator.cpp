

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
		UTbSimpleSimpleInterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleSimpleInterface"));
		BackendPublisher->Unsubscribe(TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>(this));
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleSimpleInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleSimpleInterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleSimpleInterface"));
	// connect property changed signals or simple events
	BackendPublisher->Subscribe(TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>(this));
	// populate service state to proxy
	bPropBool = BackendService->GetPropBool();
	PropInt = BackendService->GetPropInt();
	PropInt32 = BackendService->GetPropInt32();
	PropInt64 = BackendService->GetPropInt64();
	PropFloat = BackendService->GetPropFloat();
	PropFloat32 = BackendService->GetPropFloat32();
	PropFloat64 = BackendService->GetPropFloat64();
	PropString = BackendService->GetPropString();
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigBoolSignal(bool bInParamBool)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigBool(bInParamBool);
	_GetPublisher()->BroadcastSigBoolSignal(bInParamBool);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigIntSignal(int32 InParamInt)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigInt(InParamInt);
	_GetPublisher()->BroadcastSigIntSignal(InParamInt);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt32Signal(int32 InParamInt32)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigInt32(InParamInt32);
	_GetPublisher()->BroadcastSigInt32Signal(InParamInt32);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigInt64Signal(int64 InParamInt64)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigInt64(InParamInt64);
	_GetPublisher()->BroadcastSigInt64Signal(InParamInt64);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloatSignal(float InParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigFloat(InParamFloat);
	_GetPublisher()->BroadcastSigFloatSignal(InParamFloat);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat32Signal(float InParamFloat32)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigFloat32(InParamFloat32);
	_GetPublisher()->BroadcastSigFloat32Signal(InParamFloat32);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigFloat64Signal(double InParamFloat64)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigFloat64(InParamFloat64);
	_GetPublisher()->BroadcastSigFloat64Signal(InParamFloat64);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnSigStringSignal(const FString& InParamString)
{
	TbSimpleSimpleInterfaceTracer::trace_signalSigString(InParamString);
	_GetPublisher()->BroadcastSigStringSignal(InParamString);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropBoolChanged(bool bInPropBool)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	bPropBool = bInPropBool;
	_GetPublisher()->BroadcastPropBoolChanged(bInPropBool);
}

bool UTbSimpleSimpleInterfaceLoggingDecorator::GetPropBool() const
{
	return BackendService->GetPropBool();
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropBool(bool bInPropBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropBool(bInPropBool);
	BackendService->SetPropBool(bInPropBool);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropIntChanged(int32 InPropInt)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	_GetPublisher()->BroadcastPropIntChanged(InPropInt);
}

int32 UTbSimpleSimpleInterfaceLoggingDecorator::GetPropInt() const
{
	return BackendService->GetPropInt();
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropInt(int32 InPropInt)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->SetPropInt(InPropInt);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropInt32Changed(int32 InPropInt32)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt32 = InPropInt32;
	_GetPublisher()->BroadcastPropInt32Changed(InPropInt32);
}

int32 UTbSimpleSimpleInterfaceLoggingDecorator::GetPropInt32() const
{
	return BackendService->GetPropInt32();
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropInt32(int32 InPropInt32)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropInt32(InPropInt32);
	BackendService->SetPropInt32(InPropInt32);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropInt64Changed(int64 InPropInt64)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt64 = InPropInt64;
	_GetPublisher()->BroadcastPropInt64Changed(InPropInt64);
}

int64 UTbSimpleSimpleInterfaceLoggingDecorator::GetPropInt64() const
{
	return BackendService->GetPropInt64();
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropInt64(int64 InPropInt64)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropInt64(InPropInt64);
	BackendService->SetPropInt64(InPropInt64);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloatChanged(float InPropFloat)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat = InPropFloat;
	_GetPublisher()->BroadcastPropFloatChanged(InPropFloat);
}

float UTbSimpleSimpleInterfaceLoggingDecorator::GetPropFloat() const
{
	return BackendService->GetPropFloat();
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropFloat(float InPropFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	BackendService->SetPropFloat(InPropFloat);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloat32Changed(float InPropFloat32)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat32 = InPropFloat32;
	_GetPublisher()->BroadcastPropFloat32Changed(InPropFloat32);
}

float UTbSimpleSimpleInterfaceLoggingDecorator::GetPropFloat32() const
{
	return BackendService->GetPropFloat32();
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropFloat32(float InPropFloat32)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropFloat32(InPropFloat32);
	BackendService->SetPropFloat32(InPropFloat32);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropFloat64Changed(double InPropFloat64)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropFloat64 = InPropFloat64;
	_GetPublisher()->BroadcastPropFloat64Changed(InPropFloat64);
}

double UTbSimpleSimpleInterfaceLoggingDecorator::GetPropFloat64() const
{
	return BackendService->GetPropFloat64();
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropFloat64(double InPropFloat64)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropFloat64(InPropFloat64);
	BackendService->SetPropFloat64(InPropFloat64);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::OnPropStringChanged(const FString& InPropString)
{
	TbSimpleSimpleInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropString = InPropString;
	_GetPublisher()->BroadcastPropStringChanged(InPropString);
}

FString UTbSimpleSimpleInterfaceLoggingDecorator::GetPropString() const
{
	return BackendService->GetPropString();
}

void UTbSimpleSimpleInterfaceLoggingDecorator::SetPropString(const FString& InPropString)
{
	TbSimpleSimpleInterfaceTracer::trace_callSetPropString(InPropString);
	BackendService->SetPropString(InPropString);
}

void UTbSimpleSimpleInterfaceLoggingDecorator::FuncNoReturnValue(bool bParamBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncNoReturnValue(bParamBool);
	BackendService->FuncNoReturnValue(bParamBool);
}

bool UTbSimpleSimpleInterfaceLoggingDecorator::FuncBool(bool bParamBool)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncBool(bParamBool);
	return BackendService->FuncBool(bParamBool);
}

int32 UTbSimpleSimpleInterfaceLoggingDecorator::FuncInt(int32 ParamInt)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt(ParamInt);
	return BackendService->FuncInt(ParamInt);
}

int32 UTbSimpleSimpleInterfaceLoggingDecorator::FuncInt32(int32 ParamInt32)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt32(ParamInt32);
	return BackendService->FuncInt32(ParamInt32);
}

int64 UTbSimpleSimpleInterfaceLoggingDecorator::FuncInt64(int64 ParamInt64)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncInt64(ParamInt64);
	return BackendService->FuncInt64(ParamInt64);
}

float UTbSimpleSimpleInterfaceLoggingDecorator::FuncFloat(float ParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return BackendService->FuncFloat(ParamFloat);
}

float UTbSimpleSimpleInterfaceLoggingDecorator::FuncFloat32(float ParamFloat32)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat32(ParamFloat32);
	return BackendService->FuncFloat32(ParamFloat32);
}

double UTbSimpleSimpleInterfaceLoggingDecorator::FuncFloat64(double ParamFloat)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncFloat64(ParamFloat);
	return BackendService->FuncFloat64(ParamFloat);
}

FString UTbSimpleSimpleInterfaceLoggingDecorator::FuncString(const FString& ParamString)
{
	TbSimpleSimpleInterfaceTracer::trace_callFuncString(ParamString);
	return BackendService->FuncString(ParamString);
}
