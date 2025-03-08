

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
#include "TbNames/Generated/Monitor/TbNamesNamEsLoggingDecorator.h"
#include "TbNamesSettings.h"
#include "TbNames.trace.h"
#include "TbNames/Generated/TbNamesFactory.h"
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
	setBackendService(UTbNamesSettings::GetITbNamesNamEsInterfaceForLogging(Collection));
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
		UTbNamesNamEsSignals* BackendSignals = BackendService->_GetSignals();
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
	UTbNamesNamEsSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbNamesNamEs"));
	// connect property changed signals or simple events
	BackendSignals->OnSwitchChanged.AddDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSwitchChanged);
	BackendSignals->OnSomePropertyChanged.AddDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSomePropertyChanged);
	BackendSignals->OnSomePoperty2Changed.AddDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSomePoperty2Changed);
	BackendSignals->OnSomeSignalSignal.AddDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSomeSignal);
	BackendSignals->OnSomeSignal2Signal.AddDynamic(this, &UTbNamesNamEsLoggingDecorator::OnSomeSignal2);
	// populate service state to proxy
	bSwitch = BackendService->GetSwitch();
	SomeProperty = BackendService->GetSomeProperty();
	SomePoperty2 = BackendService->GetSomePoperty2();
}

void UTbNamesNamEsLoggingDecorator::OnSomeSignal(bool bInSomeParam)
{
	TbNamesNamEsTracer::trace_signalSomeSignal(bInSomeParam);
	_GetSignals()->OnSomeSignalSignal.Broadcast(bInSomeParam);
}

void UTbNamesNamEsLoggingDecorator::OnSomeSignal2(bool bInSomeParam)
{
	TbNamesNamEsTracer::trace_signalSomeSignal2(bInSomeParam);
	_GetSignals()->OnSomeSignal2Signal.Broadcast(bInSomeParam);
}

void UTbNamesNamEsLoggingDecorator::OnSwitchChanged(bool bInSwitch)
{
	TbNamesNamEsTracer::capture_state(BackendService.GetObject(), this);
	bSwitch = bInSwitch;
	_GetSignals()->OnSwitchChanged.Broadcast(bInSwitch);
}

bool UTbNamesNamEsLoggingDecorator::GetSwitch() const
{
	return BackendService->GetSwitch();
}

void UTbNamesNamEsLoggingDecorator::SetSwitch(bool bInSwitch)
{
	TbNamesNamEsTracer::trace_callSetSwitch(bInSwitch);
	BackendService->SetSwitch(bInSwitch);
}

void UTbNamesNamEsLoggingDecorator::OnSomePropertyChanged(int32 InSomeProperty)
{
	TbNamesNamEsTracer::capture_state(BackendService.GetObject(), this);
	SomeProperty = InSomeProperty;
	_GetSignals()->OnSomePropertyChanged.Broadcast(InSomeProperty);
}

int32 UTbNamesNamEsLoggingDecorator::GetSomeProperty() const
{
	return BackendService->GetSomeProperty();
}

void UTbNamesNamEsLoggingDecorator::SetSomeProperty(int32 InSomeProperty)
{
	TbNamesNamEsTracer::trace_callSetSomeProperty(InSomeProperty);
	BackendService->SetSomeProperty(InSomeProperty);
}

void UTbNamesNamEsLoggingDecorator::OnSomePoperty2Changed(int32 InSomePoperty2)
{
	TbNamesNamEsTracer::capture_state(BackendService.GetObject(), this);
	SomePoperty2 = InSomePoperty2;
	_GetSignals()->OnSomePoperty2Changed.Broadcast(InSomePoperty2);
}

int32 UTbNamesNamEsLoggingDecorator::GetSomePoperty2() const
{
	return BackendService->GetSomePoperty2();
}

void UTbNamesNamEsLoggingDecorator::SetSomePoperty2(int32 InSomePoperty2)
{
	TbNamesNamEsTracer::trace_callSetSomePoperty2(InSomePoperty2);
	BackendService->SetSomePoperty2(InSomePoperty2);
}

void UTbNamesNamEsLoggingDecorator::SomeFunction(bool bSomeParam)
{
	TbNamesNamEsTracer::trace_callSomeFunction(bSomeParam);
	BackendService->SomeFunction(bSomeParam);
}

void UTbNamesNamEsLoggingDecorator::SomeFunction2(bool bSomeParam)
{
	TbNamesNamEsTracer::trace_callSomeFunction2(bSomeParam);
	BackendService->SomeFunction2(bSomeParam);
}
