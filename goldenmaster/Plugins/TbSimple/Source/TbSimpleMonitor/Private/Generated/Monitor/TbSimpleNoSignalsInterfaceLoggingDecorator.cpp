

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
#include "TbSimple/Generated/Monitor/TbSimpleNoSignalsInterfaceLoggingDecorator.h"
#include "TbSimpleSettings.h"
#include "TbSimple.trace.h"
#include "TbSimple/Generated/TbSimpleFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSimpleNoSignalsInterfaceLoggingDecorator);
UTbSimpleNoSignalsInterfaceLoggingDecorator::UTbSimpleNoSignalsInterfaceLoggingDecorator()
	: UAbstractTbSimpleNoSignalsInterface()
{
}

UTbSimpleNoSignalsInterfaceLoggingDecorator::~UTbSimpleNoSignalsInterfaceLoggingDecorator() = default;

void UTbSimpleNoSignalsInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbSimpleSettings::GetITbSimpleNoSignalsInterfaceInterfaceForLogging(Collection));
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleNoSignalsInterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleNoSignalsInterface"));
		BackendPublisher->Unsubscribe(TWeakInterfacePtr<ITbSimpleNoSignalsInterfaceSubscriberInterface>(this));
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleNoSignalsInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleNoSignalsInterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleNoSignalsInterface"));
	// connect property changed signals or simple events
	BackendPublisher->Subscribe(TWeakInterfacePtr<ITbSimpleNoSignalsInterfaceSubscriberInterface>(this));
	// populate service state to proxy
	bPropBool = BackendService->GetPropBool();
	PropInt = BackendService->GetPropInt();
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::OnPropBoolChanged(bool bInPropBool)
{
	TbSimpleNoSignalsInterfaceTracer::capture_state(BackendService.GetObject(), this);
	bPropBool = bInPropBool;
	_GetPublisher()->BroadcastPropBoolChanged(bInPropBool);
}

bool UTbSimpleNoSignalsInterfaceLoggingDecorator::GetPropBool() const
{
	return BackendService->GetPropBool();
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::SetPropBool(bool bInPropBool)
{
	TbSimpleNoSignalsInterfaceTracer::trace_callSetPropBool(bInPropBool);
	BackendService->SetPropBool(bInPropBool);
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::OnPropIntChanged(int32 InPropInt)
{
	TbSimpleNoSignalsInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	_GetPublisher()->BroadcastPropIntChanged(InPropInt);
}

int32 UTbSimpleNoSignalsInterfaceLoggingDecorator::GetPropInt() const
{
	return BackendService->GetPropInt();
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::SetPropInt(int32 InPropInt)
{
	TbSimpleNoSignalsInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->SetPropInt(InPropInt);
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::FuncVoid()
{
	TbSimpleNoSignalsInterfaceTracer::trace_callFuncVoid();
	BackendService->FuncVoid();
}

bool UTbSimpleNoSignalsInterfaceLoggingDecorator::FuncBool(bool bParamBool)
{
	TbSimpleNoSignalsInterfaceTracer::trace_callFuncBool(bParamBool);
	return BackendService->FuncBool(bParamBool);
}
