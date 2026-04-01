

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
#include "Counter/Generated/Monitor/CounterCounterLoggingDecorator.h"
#include "CounterSettings.h"
#include "Counter.trace.h"
#include "Counter/Generated/CounterFactory.h"
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
	setBackendService(UCounterSettings::GetICounterCounterInterfaceForLogging(Collection));
}

void UCounterCounterLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	if (BackendService != nullptr)
	{
		UCounterCounterPublisher* BackendPublisher = BackendService->_GetPublisher();
		if (BackendPublisher)
		{
			BackendPublisher->Unsubscribe(TWeakInterfacePtr<ICounterCounterSubscriberInterface>(this));
		}
	}
	BackendService = nullptr;
}

void UCounterCounterLoggingDecorator::setBackendService(TScriptInterface<ICounterCounterInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UCounterCounterPublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service CounterCounter"));
		if (!BackendPublisher)
		{
			return;
		}
		BackendPublisher->Unsubscribe(TWeakInterfacePtr<ICounterCounterSubscriberInterface>(this));
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface CounterCounter is not fully implemented"));
	if (InService.GetInterface() == nullptr)
	{
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	UCounterCounterPublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service CounterCounter"));
	if (!BackendPublisher)
	{
		return;
	}
	// connect property changed signals or simple events
	BackendPublisher->Subscribe(TWeakInterfacePtr<ICounterCounterSubscriberInterface>(this));
	// populate service state to proxy
	Vector = BackendService->GetVector();
	ExternVector = BackendService->GetExternVector();
	VectorArray = BackendService->GetVectorArray();
	ExternVectorArray = BackendService->GetExternVectorArray();
}

void UCounterCounterLoggingDecorator::OnValueChangedSignal(const FCustomTypesVector3D& InVector, const FVector& InExternVector, const TArray<FCustomTypesVector3D>& InVectorArray, const TArray<FVector>& InExternVectorArray)
{
	if (!BackendService)
	{
		return;
	}
	CounterCounterTracer::trace_signalValueChanged(InVector, InExternVector, InVectorArray, InExternVectorArray);
	_GetPublisher()->BroadcastValueChangedSignal(InVector, InExternVector, InVectorArray, InExternVectorArray);
}

void UCounterCounterLoggingDecorator::OnVectorChanged(const FCustomTypesVector3D& InVector)
{
	if (!BackendService)
	{
		return;
	}
	CounterCounterTracer::capture_state(BackendService.GetObject(), this);
	Vector = InVector;
	_GetPublisher()->BroadcastVectorChanged(InVector);
}

FCustomTypesVector3D UCounterCounterLoggingDecorator::GetVector() const
{
	if (!BackendService)
	{
		UE_LOG(LogCounterCounterLoggingDecorator, Error, TEXT("BackendService not set"));
		return FCustomTypesVector3D();
	}
	return BackendService->GetVector();
}

void UCounterCounterLoggingDecorator::SetVector(const FCustomTypesVector3D& InVector)
{
	if (!BackendService)
	{
		UE_LOG(LogCounterCounterLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	CounterCounterTracer::trace_callSetVector(InVector);
	BackendService->SetVector(InVector);
}

void UCounterCounterLoggingDecorator::OnExternVectorChanged(const FVector& InExternVector)
{
	if (!BackendService)
	{
		return;
	}
	CounterCounterTracer::capture_state(BackendService.GetObject(), this);
	ExternVector = InExternVector;
	_GetPublisher()->BroadcastExternVectorChanged(InExternVector);
}

FVector UCounterCounterLoggingDecorator::GetExternVector() const
{
	if (!BackendService)
	{
		UE_LOG(LogCounterCounterLoggingDecorator, Error, TEXT("BackendService not set"));
		return FVector(0.f, 0.f, 0.f);
	}
	return BackendService->GetExternVector();
}

void UCounterCounterLoggingDecorator::SetExternVector(const FVector& InExternVector)
{
	if (!BackendService)
	{
		UE_LOG(LogCounterCounterLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	CounterCounterTracer::trace_callSetExternVector(InExternVector);
	BackendService->SetExternVector(InExternVector);
}

void UCounterCounterLoggingDecorator::OnVectorArrayChanged(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	if (!BackendService)
	{
		return;
	}
	CounterCounterTracer::capture_state(BackendService.GetObject(), this);
	VectorArray = InVectorArray;
	_GetPublisher()->BroadcastVectorArrayChanged(InVectorArray);
}

TArray<FCustomTypesVector3D> UCounterCounterLoggingDecorator::GetVectorArray() const
{
	if (!BackendService)
	{
		UE_LOG(LogCounterCounterLoggingDecorator, Error, TEXT("BackendService not set"));
		return TArray<FCustomTypesVector3D>();
	}
	return BackendService->GetVectorArray();
}

void UCounterCounterLoggingDecorator::SetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	if (!BackendService)
	{
		UE_LOG(LogCounterCounterLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	CounterCounterTracer::trace_callSetVectorArray(InVectorArray);
	BackendService->SetVectorArray(InVectorArray);
}

void UCounterCounterLoggingDecorator::OnExternVectorArrayChanged(const TArray<FVector>& InExternVectorArray)
{
	if (!BackendService)
	{
		return;
	}
	CounterCounterTracer::capture_state(BackendService.GetObject(), this);
	ExternVectorArray = InExternVectorArray;
	_GetPublisher()->BroadcastExternVectorArrayChanged(InExternVectorArray);
}

TArray<FVector> UCounterCounterLoggingDecorator::GetExternVectorArray() const
{
	if (!BackendService)
	{
		UE_LOG(LogCounterCounterLoggingDecorator, Error, TEXT("BackendService not set"));
		return TArray<FVector>();
	}
	return BackendService->GetExternVectorArray();
}

void UCounterCounterLoggingDecorator::SetExternVectorArray(const TArray<FVector>& InExternVectorArray)
{
	if (!BackendService)
	{
		UE_LOG(LogCounterCounterLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	CounterCounterTracer::trace_callSetExternVectorArray(InExternVectorArray);
	BackendService->SetExternVectorArray(InExternVectorArray);
}

FVector UCounterCounterLoggingDecorator::Increment(const FVector& Vec)
{
	if (!BackendService)
	{
		UE_LOG(LogCounterCounterLoggingDecorator, Error, TEXT("BackendService not set"));
		return FVector(0.f, 0.f, 0.f);
	}
	CounterCounterTracer::trace_callIncrement(Vec);
	return BackendService->Increment(Vec);
}

TArray<FVector> UCounterCounterLoggingDecorator::IncrementArray(const TArray<FVector>& Vec)
{
	if (!BackendService)
	{
		UE_LOG(LogCounterCounterLoggingDecorator, Error, TEXT("BackendService not set"));
		return TArray<FVector>();
	}
	CounterCounterTracer::trace_callIncrementArray(Vec);
	return BackendService->IncrementArray(Vec);
}

FCustomTypesVector3D UCounterCounterLoggingDecorator::Decrement(const FCustomTypesVector3D& Vec)
{
	if (!BackendService)
	{
		UE_LOG(LogCounterCounterLoggingDecorator, Error, TEXT("BackendService not set"));
		return FCustomTypesVector3D();
	}
	CounterCounterTracer::trace_callDecrement(Vec);
	return BackendService->Decrement(Vec);
}

TArray<FCustomTypesVector3D> UCounterCounterLoggingDecorator::DecrementArray(const TArray<FCustomTypesVector3D>& Vec)
{
	if (!BackendService)
	{
		UE_LOG(LogCounterCounterLoggingDecorator, Error, TEXT("BackendService not set"));
		return TArray<FCustomTypesVector3D>();
	}
	CounterCounterTracer::trace_callDecrementArray(Vec);
	return BackendService->DecrementArray(Vec);
}
