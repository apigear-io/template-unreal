
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
#include "Generated/Monitor/CounterCounterLoggingDecorator.h"
#include "Counter.trace.h"
#include "CounterFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogCounterCounterLoggingDecorator);
UCounterCounterLoggingDecorator::UCounterCounterLoggingDecorator()
	: UAbstractCounterCounter()
{
}

UCounterCounterLoggingDecorator::~UCounterCounterLoggingDecorator() = default;

void UCounterCounterLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService(FCounterModuleFactory::createICounterCounterInterface(GetGameInstance(), Collection));
#else
	setBackendService(FCounterModuleFactory::createICounterCounterInterface(Collection));
#endif
}

void UCounterCounterLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UCounterCounterLoggingDecorator::setBackendService(TScriptInterface<ICounterCounterInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UCounterCounterSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service CounterCounter"));
		BackendSignals->OnVectorChanged.RemoveDynamic(this, &UCounterCounterLoggingDecorator::OnVectorChanged);
		BackendSignals->OnExternVectorChanged.RemoveDynamic(this, &UCounterCounterLoggingDecorator::OnExternVectorChanged);
		BackendSignals->OnVectorArrayChanged.RemoveDynamic(this, &UCounterCounterLoggingDecorator::OnVectorArrayChanged);
		BackendSignals->OnExternVectorArrayChanged.RemoveDynamic(this, &UCounterCounterLoggingDecorator::OnExternVectorArrayChanged);
		BackendSignals->OnValueChangedSignal.RemoveDynamic(this, &UCounterCounterLoggingDecorator::OnValueChanged);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface CounterCounter is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UCounterCounterSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service CounterCounter"));
	// connect property changed signals or simple events
	BackendSignals->OnVectorChanged.AddDynamic(this, &UCounterCounterLoggingDecorator::OnVectorChanged);
	BackendSignals->OnExternVectorChanged.AddDynamic(this, &UCounterCounterLoggingDecorator::OnExternVectorChanged);
	BackendSignals->OnVectorArrayChanged.AddDynamic(this, &UCounterCounterLoggingDecorator::OnVectorArrayChanged);
	BackendSignals->OnExternVectorArrayChanged.AddDynamic(this, &UCounterCounterLoggingDecorator::OnExternVectorArrayChanged);
	BackendSignals->OnValueChangedSignal.AddDynamic(this, &UCounterCounterLoggingDecorator::OnValueChanged);
	// populate service state to proxy
	Vector = BackendService->Execute_GetVector(BackendService.GetObject());
	ExternVector = BackendService->Execute_GetExternVector(BackendService.GetObject());
	VectorArray = BackendService->Execute_GetVectorArray(BackendService.GetObject());
	ExternVectorArray = BackendService->Execute_GetExternVectorArray(BackendService.GetObject());
}

void UCounterCounterLoggingDecorator::OnValueChanged(const FCustomTypesVector3D& InVector, const FVector& InExternVector, const TArray<FCustomTypesVector3D>& InVectorArray, const TArray<FVector>& InExternVectorArray)
{
	CounterCounterTracer::trace_signalValueChanged(InVector, InExternVector, InVectorArray, InExternVectorArray);
	Execute__GetSignals(this)->OnValueChangedSignal.Broadcast(InVector, InExternVector, InVectorArray, InExternVectorArray);
}

void UCounterCounterLoggingDecorator::OnVectorChanged(const FCustomTypesVector3D& InVector)
{
	CounterCounterTracer::capture_state(BackendService.GetObject(), this);
	Vector = InVector;
	Execute__GetSignals(this)->OnVectorChanged.Broadcast(InVector);
}

FCustomTypesVector3D UCounterCounterLoggingDecorator::GetVector_Implementation() const
{
	return BackendService->Execute_GetVector(BackendService.GetObject());
}

void UCounterCounterLoggingDecorator::SetVector_Implementation(const FCustomTypesVector3D& InVector)
{
	CounterCounterTracer::trace_callSetVector(InVector);
	BackendService->Execute_SetVector(BackendService.GetObject(), InVector);
}

void UCounterCounterLoggingDecorator::OnExternVectorChanged(const FVector& InExternVector)
{
	CounterCounterTracer::capture_state(BackendService.GetObject(), this);
	ExternVector = InExternVector;
	Execute__GetSignals(this)->OnExternVectorChanged.Broadcast(InExternVector);
}

FVector UCounterCounterLoggingDecorator::GetExternVector_Implementation() const
{
	return BackendService->Execute_GetExternVector(BackendService.GetObject());
}

void UCounterCounterLoggingDecorator::SetExternVector_Implementation(const FVector& InExternVector)
{
	CounterCounterTracer::trace_callSetExternVector(InExternVector);
	BackendService->Execute_SetExternVector(BackendService.GetObject(), InExternVector);
}

void UCounterCounterLoggingDecorator::OnVectorArrayChanged(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	CounterCounterTracer::capture_state(BackendService.GetObject(), this);
	VectorArray = InVectorArray;
	Execute__GetSignals(this)->OnVectorArrayChanged.Broadcast(InVectorArray);
}

TArray<FCustomTypesVector3D> UCounterCounterLoggingDecorator::GetVectorArray_Implementation() const
{
	return BackendService->Execute_GetVectorArray(BackendService.GetObject());
}

void UCounterCounterLoggingDecorator::SetVectorArray_Implementation(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	CounterCounterTracer::trace_callSetVectorArray(InVectorArray);
	BackendService->Execute_SetVectorArray(BackendService.GetObject(), InVectorArray);
}

void UCounterCounterLoggingDecorator::OnExternVectorArrayChanged(const TArray<FVector>& InExternVectorArray)
{
	CounterCounterTracer::capture_state(BackendService.GetObject(), this);
	ExternVectorArray = InExternVectorArray;
	Execute__GetSignals(this)->OnExternVectorArrayChanged.Broadcast(InExternVectorArray);
}

TArray<FVector> UCounterCounterLoggingDecorator::GetExternVectorArray_Implementation() const
{
	return BackendService->Execute_GetExternVectorArray(BackendService.GetObject());
}

void UCounterCounterLoggingDecorator::SetExternVectorArray_Implementation(const TArray<FVector>& InExternVectorArray)
{
	CounterCounterTracer::trace_callSetExternVectorArray(InExternVectorArray);
	BackendService->Execute_SetExternVectorArray(BackendService.GetObject(), InExternVectorArray);
}

FVector UCounterCounterLoggingDecorator::Increment_Implementation(const FVector& Vec)
{
	CounterCounterTracer::trace_callIncrement(Vec);
	return BackendService->Execute_Increment(BackendService.GetObject(), Vec);
}

TArray<FVector> UCounterCounterLoggingDecorator::IncrementArray_Implementation(const TArray<FVector>& Vec)
{
	CounterCounterTracer::trace_callIncrementArray(Vec);
	return BackendService->Execute_IncrementArray(BackendService.GetObject(), Vec);
}

FCustomTypesVector3D UCounterCounterLoggingDecorator::Decrement_Implementation(const FCustomTypesVector3D& Vec)
{
	CounterCounterTracer::trace_callDecrement(Vec);
	return BackendService->Execute_Decrement(BackendService.GetObject(), Vec);
}

TArray<FCustomTypesVector3D> UCounterCounterLoggingDecorator::DecrementArray_Implementation(const TArray<FCustomTypesVector3D>& Vec)
{
	CounterCounterTracer::trace_callDecrementArray(Vec);
	return BackendService->Execute_DecrementArray(BackendService.GetObject(), Vec);
}
