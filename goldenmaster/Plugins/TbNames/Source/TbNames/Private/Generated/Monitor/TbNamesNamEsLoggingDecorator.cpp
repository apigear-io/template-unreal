
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
#include "Generated/Monitor/TbNamesNamEsLoggingDecorator.h"
#include "TbNames.trace.h"
#include "Generated/TbNamesFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbNamesNamEsLoggingDecorator);
UTbNamesNamEsLoggingDecorator::UTbNamesNamEsLoggingDecorator()
	: UAbstractTbNamesNamEs()
{
}

UTbNamesNamEsLoggingDecorator::~UTbNamesNamEsLoggingDecorator() = default;

void UTbNamesNamEsLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(FTbNamesModuleFactory::createITbNamesNamEsInterface(Collection));
}

void UTbNamesNamEsLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbNamesNamEsLoggingDecorator::setBackendService(TScriptInterface<ITbNamesNamEsInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbNamesNamEsSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbNamesNamEs"));
		BackendSignals->OnSwitchChanged.RemoveDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSwitchChanged);
		BackendSignals->OnSomePropertyChanged.RemoveDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSomePropertyChanged);
		BackendSignals->OnSomePoperty2Changed.RemoveDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSomePoperty2Changed);
		BackendSignals->OnSomeSignalSignal.RemoveDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSomeSignal);
		BackendSignals->OnSomeSignal2Signal.RemoveDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSomeSignal2);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbNamesNamEs is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbNamesNamEsSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbNamesNamEs"));
	// connect property changed signals or simple events
	BackendSignals->OnSwitchChanged.AddDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSwitchChanged);
	BackendSignals->OnSomePropertyChanged.AddDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSomePropertyChanged);
	BackendSignals->OnSomePoperty2Changed.AddDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSomePoperty2Changed);
	BackendSignals->OnSomeSignalSignal.AddDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSomeSignal);
	BackendSignals->OnSomeSignal2Signal.AddDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSomeSignal2);
	// populate service state to proxy
	bSwitch = BackendService->Execute_GetSwitch(BackendService.GetObject());
	SomeProperty = BackendService->Execute_GetSomeProperty(BackendService.GetObject());
	SomePoperty2 = BackendService->Execute_GetSomePoperty2(BackendService.GetObject());
}

void UTbNamesNamEsLoggingDecorator::OnSomeSignal(bool bInSomeParam)
{
	TbNamesNamEsTracer::trace_signalSomeSignal(bInSomeParam);
	Execute__GetSignals(this)->OnSomeSignalSignal.Broadcast(bInSomeParam);
}

void UTbNamesNamEsLoggingDecorator::OnSomeSignal2(bool bInSomeParam)
{
	TbNamesNamEsTracer::trace_signalSomeSignal2(bInSomeParam);
	Execute__GetSignals(this)->OnSomeSignal2Signal.Broadcast(bInSomeParam);
}

void UTbNamesNamEsLoggingDecorator::OnSwitchChanged(bool bInSwitch)
{
	TbNamesNamEsTracer::capture_state(BackendService.GetObject(), this);
	bSwitch = bInSwitch;
	Execute__GetSignals(this)->OnSwitchChanged.Broadcast(bInSwitch);
}

bool UTbNamesNamEsLoggingDecorator::GetSwitch_Implementation() const
{
	return BackendService->Execute_GetSwitch(BackendService.GetObject());
}

void UTbNamesNamEsLoggingDecorator::SetSwitch_Implementation(bool bInSwitch)
{
	TbNamesNamEsTracer::trace_callSetSwitch(bInSwitch);
	BackendService->Execute_SetSwitch(BackendService.GetObject(), bInSwitch);
}

void UTbNamesNamEsLoggingDecorator::OnSomePropertyChanged(int32 InSomeProperty)
{
	TbNamesNamEsTracer::capture_state(BackendService.GetObject(), this);
	SomeProperty = InSomeProperty;
	Execute__GetSignals(this)->OnSomePropertyChanged.Broadcast(InSomeProperty);
}

int32 UTbNamesNamEsLoggingDecorator::GetSomeProperty_Implementation() const
{
	return BackendService->Execute_GetSomeProperty(BackendService.GetObject());
}

void UTbNamesNamEsLoggingDecorator::SetSomeProperty_Implementation(int32 InSomeProperty)
{
	TbNamesNamEsTracer::trace_callSetSomeProperty(InSomeProperty);
	BackendService->Execute_SetSomeProperty(BackendService.GetObject(), InSomeProperty);
}

void UTbNamesNamEsLoggingDecorator::OnSomePoperty2Changed(int32 InSomePoperty2)
{
	TbNamesNamEsTracer::capture_state(BackendService.GetObject(), this);
	SomePoperty2 = InSomePoperty2;
	Execute__GetSignals(this)->OnSomePoperty2Changed.Broadcast(InSomePoperty2);
}

int32 UTbNamesNamEsLoggingDecorator::GetSomePoperty2_Implementation() const
{
	return BackendService->Execute_GetSomePoperty2(BackendService.GetObject());
}

void UTbNamesNamEsLoggingDecorator::SetSomePoperty2_Implementation(int32 InSomePoperty2)
{
	TbNamesNamEsTracer::trace_callSetSomePoperty2(InSomePoperty2);
	BackendService->Execute_SetSomePoperty2(BackendService.GetObject(), InSomePoperty2);
}

void UTbNamesNamEsLoggingDecorator::SomeFunction_Implementation(bool bSomeParam)
{
	TbNamesNamEsTracer::trace_callSomeFunction(bSomeParam);
	BackendService->Execute_SomeFunction(BackendService.GetObject(), bSomeParam);
}

void UTbNamesNamEsLoggingDecorator::SomeFunction2_Implementation(bool bSomeParam)
{
	TbNamesNamEsTracer::trace_callSomeFunction2(bSomeParam);
	BackendService->Execute_SomeFunction2(BackendService.GetObject(), bSomeParam);
}
