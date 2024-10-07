
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
#include "Generated/Monitor/TbSimpleNoOperationsInterfaceLoggingDecorator.h"
#include "TbSimple.trace.h"
#include "Generated/TbSimpleFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSimpleNoOperationsInterfaceLoggingDecorator);
UTbSimpleNoOperationsInterfaceLoggingDecorator::UTbSimpleNoOperationsInterfaceLoggingDecorator()
	: UAbstractTbSimpleNoOperationsInterface()
{
}

UTbSimpleNoOperationsInterfaceLoggingDecorator::~UTbSimpleNoOperationsInterfaceLoggingDecorator() = default;

void UTbSimpleNoOperationsInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService(FTbSimpleModuleFactory::createITbSimpleNoOperationsInterfaceInterface(GetGameInstance(), Collection));
#else
	setBackendService(FTbSimpleModuleFactory::createITbSimpleNoOperationsInterfaceInterface(Collection));
#endif
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleNoOperationsInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleNoOperationsInterface"));
		BackendSignals->OnPropBoolChanged.RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropBoolChanged);
		BackendSignals->OnPropIntChanged.RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropIntChanged);
		BackendSignals->OnSigVoidSignal.RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigVoid);
		BackendSignals->OnSigBoolSignal.RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigBool);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleNoOperationsInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleNoOperationsInterfaceSignals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleNoOperationsInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnPropBoolChanged.AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendSignals->OnPropIntChanged.AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropIntChanged);
	BackendSignals->OnSigVoidSignal.AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigVoid);
	BackendSignals->OnSigBoolSignal.AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigBool);
	// populate service state to proxy
	bPropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigVoid()
{
	TbSimpleNoOperationsInterfaceTracer::trace_signalSigVoid();
	Execute__GetSignals(this)->OnSigVoidSignal.Broadcast();
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigBool(bool bInParamBool)
{
	TbSimpleNoOperationsInterfaceTracer::trace_signalSigBool(bInParamBool);
	Execute__GetSignals(this)->OnSigBoolSignal.Broadcast(bInParamBool);
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropBoolChanged(bool bInPropBool)
{
	TbSimpleNoOperationsInterfaceTracer::capture_state(BackendService.GetObject(), this);
	bPropBool = bInPropBool;
	Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(bInPropBool);
}

bool UTbSimpleNoOperationsInterfaceLoggingDecorator::GetPropBool_Implementation() const
{
	return BackendService->Execute_GetPropBool(BackendService.GetObject());
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::SetPropBool_Implementation(bool bInPropBool)
{
	TbSimpleNoOperationsInterfaceTracer::trace_callSetPropBool(bInPropBool);
	BackendService->Execute_SetPropBool(BackendService.GetObject(), bInPropBool);
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropIntChanged(int32 InPropInt)
{
	TbSimpleNoOperationsInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	Execute__GetSignals(this)->OnPropIntChanged.Broadcast(InPropInt);
}

int32 UTbSimpleNoOperationsInterfaceLoggingDecorator::GetPropInt_Implementation() const
{
	return BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::SetPropInt_Implementation(int32 InPropInt)
{
	TbSimpleNoOperationsInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InPropInt);
}
