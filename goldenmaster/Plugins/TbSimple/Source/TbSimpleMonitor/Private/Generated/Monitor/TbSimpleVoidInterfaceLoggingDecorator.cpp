

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
#include "TbSimple/Generated/Monitor/TbSimpleVoidInterfaceLoggingDecorator.h"
#include "TbSimpleSettings.h"
#include "TbSimple.trace.h"
#include "TbSimple/Generated/TbSimpleFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbSimpleVoidInterfaceLoggingDecorator);
UTbSimpleVoidInterfaceLoggingDecorator::UTbSimpleVoidInterfaceLoggingDecorator()
	: UAbstractTbSimpleVoidInterface()
{
}

UTbSimpleVoidInterfaceLoggingDecorator::~UTbSimpleVoidInterfaceLoggingDecorator() = default;

void UTbSimpleVoidInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbSimpleSettings::GetITbSimpleVoidInterfaceInterfaceForLogging(Collection));
}

void UTbSimpleVoidInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSimpleVoidInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSimpleVoidInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbSimpleVoidInterfaceSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleVoidInterface"));
		BackendSignals->OnSigVoidSignalBP.RemoveDynamic(this, &UTbSimpleVoidInterfaceLoggingDecorator::OnSigVoid);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleVoidInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbSimpleVoidInterfaceSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbSimpleVoidInterface"));
	// connect property changed signals or simple events
	BackendSignals->OnSigVoidSignalBP.AddDynamic(this, &UTbSimpleVoidInterfaceLoggingDecorator::OnSigVoid);
	// populate service state to proxy
}

void UTbSimpleVoidInterfaceLoggingDecorator::OnSigVoid()
{
	TbSimpleVoidInterfaceTracer::trace_signalSigVoid();
	_GetSignals()->BroadcastSigVoidSignal();
}

void UTbSimpleVoidInterfaceLoggingDecorator::FuncVoid()
{
	TbSimpleVoidInterfaceTracer::trace_callFuncVoid();
	BackendService->FuncVoid();
}
