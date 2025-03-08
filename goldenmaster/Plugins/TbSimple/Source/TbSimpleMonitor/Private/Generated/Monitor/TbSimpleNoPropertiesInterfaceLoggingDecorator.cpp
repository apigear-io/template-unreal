

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
#include "TbSimple/Generated/Monitor/TbSimpleNoPropertiesInterfaceLoggingDecorator.h"
#include "TbSimpleSettings.h"
#include "TbSimple.trace.h"
#include "TbSimple/Generated/TbSimpleFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSimpleNoPropertiesInterfaceLoggingDecorator);
UTbSimpleNoPropertiesInterfaceLoggingDecorator::UTbSimpleNoPropertiesInterfaceLoggingDecorator()
	: UAbstractTbSimpleNoPropertiesInterface()
{
}

UTbSimpleNoPropertiesInterfaceLoggingDecorator::~UTbSimpleNoPropertiesInterfaceLoggingDecorator() = default;

void UTbSimpleNoPropertiesInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbSimpleSettings::GetITbSimpleNoPropertiesInterfaceInterfaceForLogging(Collection));
}

void UTbSimpleNoPropertiesInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSimpleNoPropertiesInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleNoPropertiesInterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleNoPropertiesInterface"));
		BackendSignals->OnSigVoidSignal.RemoveDynamic(this, &UTbSimpleNoPropertiesInterfaceLoggingDecorator::OnSigVoid);
		BackendSignals->OnSigBoolSignal.RemoveDynamic(this, &UTbSimpleNoPropertiesInterfaceLoggingDecorator::OnSigBool);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleNoPropertiesInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleNoPropertiesInterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleNoPropertiesInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnSigVoidSignal.AddDynamic(this, &UTbSimpleNoPropertiesInterfaceLoggingDecorator::OnSigVoid);
	BackendSignals->OnSigBoolSignal.AddDynamic(this, &UTbSimpleNoPropertiesInterfaceLoggingDecorator::OnSigBool);
	// populate service state to proxy
}

void UTbSimpleNoPropertiesInterfaceLoggingDecorator::OnSigVoid()
{
	TbSimpleNoPropertiesInterfaceTracer::trace_signalSigVoid();
	_GetSignals()->OnSigVoidSignal.Broadcast();
}

void UTbSimpleNoPropertiesInterfaceLoggingDecorator::OnSigBool(bool bInParamBool)
{
	TbSimpleNoPropertiesInterfaceTracer::trace_signalSigBool(bInParamBool);
	_GetSignals()->OnSigBoolSignal.Broadcast(bInParamBool);
}

void UTbSimpleNoPropertiesInterfaceLoggingDecorator::FuncVoid()
{
	TbSimpleNoPropertiesInterfaceTracer::trace_callFuncVoid();
	BackendService->FuncVoid();
}

bool UTbSimpleNoPropertiesInterfaceLoggingDecorator::FuncBool(bool bParamBool)
{
	TbSimpleNoPropertiesInterfaceTracer::trace_callFuncBool(bParamBool);
	return BackendService->FuncBool(bParamBool);
}
