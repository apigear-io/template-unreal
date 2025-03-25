

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
#include "TbRefIfaces/Generated/Monitor/TbRefIfacesParentIfLoggingDecorator.h"
#include "TbRefIfacesSettings.h"
#include "TbRefIfaces.trace.h"
#include "TbRefIfaces/Generated/TbRefIfacesFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbRefIfacesParentIfLoggingDecorator);
UTbRefIfacesParentIfLoggingDecorator::UTbRefIfacesParentIfLoggingDecorator()
	: UAbstractTbRefIfacesParentIf()
{
}

UTbRefIfacesParentIfLoggingDecorator::~UTbRefIfacesParentIfLoggingDecorator() = default;

void UTbRefIfacesParentIfLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbRefIfacesSettings::GetITbRefIfacesParentIfInterfaceForLogging(Collection));
}

void UTbRefIfacesParentIfLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbRefIfacesParentIfLoggingDecorator::setBackendService(TScriptInterface<ITbRefIfacesParentIfInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbRefIfacesParentIfSignals* BackendSignals = BackendService->_GetSignals();
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbRefIfacesParentIf"));
		BackendSignals->OnLocalIfChangedBP.RemoveDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnLocalIfChanged);
		BackendSignals->OnImportedIfChangedBP.RemoveDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnImportedIfChanged);
		BackendSignals->OnLocalIfSignalSignalBP.RemoveDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnLocalIfSignal);
		BackendSignals->OnImportedIfSignalSignalBP.RemoveDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnImportedIfSignal);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbRefIfacesParentIf is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbRefIfacesParentIfSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbRefIfacesParentIf"));
	// connect property changed signals or simple events
	BackendSignals->OnLocalIfChangedBP.AddDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnLocalIfChanged);
	BackendSignals->OnImportedIfChangedBP.AddDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnImportedIfChanged);
	BackendSignals->OnLocalIfSignalSignalBP.AddDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnLocalIfSignal);
	BackendSignals->OnImportedIfSignalSignalBP.AddDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnImportedIfSignal);
	// populate service state to proxy
	LocalIf = BackendService->GetLocalIf();
	ImportedIf = BackendService->GetImportedIf();
}

void UTbRefIfacesParentIfLoggingDecorator::OnLocalIfSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InParam)
{
	TbRefIfacesParentIfTracer::trace_signalLocalIfSignal(InParam);
	_GetSignals()->BroadcastLocalIfSignalSignal(InParam);
}

void UTbRefIfacesParentIfLoggingDecorator::OnImportedIfSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InParam)
{
	TbRefIfacesParentIfTracer::trace_signalImportedIfSignal(InParam);
	_GetSignals()->BroadcastImportedIfSignalSignal(InParam);
}

void UTbRefIfacesParentIfLoggingDecorator::OnLocalIfChanged(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
{
	TbRefIfacesParentIfTracer::capture_state(BackendService.GetObject(), this);
	LocalIf = InLocalIf;
	_GetSignals()->BroadcastLocalIfChanged(InLocalIf);
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> UTbRefIfacesParentIfLoggingDecorator::GetLocalIf() const
{
	return BackendService->GetLocalIf();
}

void UTbRefIfacesParentIfLoggingDecorator::SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
{
	TbRefIfacesParentIfTracer::trace_callSetLocalIf(InLocalIf);
	BackendService->SetLocalIf(InLocalIf);
}

void UTbRefIfacesParentIfLoggingDecorator::OnImportedIfChanged(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf)
{
	TbRefIfacesParentIfTracer::capture_state(BackendService.GetObject(), this);
	ImportedIf = InImportedIf;
	_GetSignals()->BroadcastImportedIfChanged(InImportedIf);
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> UTbRefIfacesParentIfLoggingDecorator::GetImportedIf() const
{
	return BackendService->GetImportedIf();
}

void UTbRefIfacesParentIfLoggingDecorator::SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf)
{
	TbRefIfacesParentIfTracer::trace_callSetImportedIf(InImportedIf);
	BackendService->SetImportedIf(InImportedIf);
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> UTbRefIfacesParentIfLoggingDecorator::LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	TbRefIfacesParentIfTracer::trace_callLocalIfMethod(Param);
	return BackendService->LocalIfMethod(Param);
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> UTbRefIfacesParentIfLoggingDecorator::ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	TbRefIfacesParentIfTracer::trace_callImportedIfMethod(Param);
	return BackendService->ImportedIfMethod(Param);
}
