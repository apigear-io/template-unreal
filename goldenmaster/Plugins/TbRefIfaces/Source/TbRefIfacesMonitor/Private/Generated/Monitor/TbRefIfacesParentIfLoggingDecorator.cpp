

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
		BackendSignals->OnLocalIfListChangedBP.RemoveDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnLocalIfListChanged);
		BackendSignals->OnImportedIfChangedBP.RemoveDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnImportedIfChanged);
		BackendSignals->OnImportedIfListChangedBP.RemoveDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnImportedIfListChanged);
		BackendSignals->OnLocalIfSignalSignalBP.RemoveDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnLocalIfSignal);
		BackendSignals->OnLocalIfSignalListSignalBP.RemoveDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnLocalIfSignalList);
		BackendSignals->OnImportedIfSignalSignalBP.RemoveDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnImportedIfSignal);
		BackendSignals->OnImportedIfSignalListSignalBP.RemoveDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnImportedIfSignalList);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbRefIfacesParentIf is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbRefIfacesParentIfSignals* BackendSignals = BackendService->_GetSignals();
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service TbRefIfacesParentIf"));
	// connect property changed signals or simple events
	BackendSignals->OnLocalIfChangedBP.AddDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnLocalIfChanged);
	BackendSignals->OnLocalIfListChangedBP.AddDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnLocalIfListChanged);
	BackendSignals->OnImportedIfChangedBP.AddDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnImportedIfChanged);
	BackendSignals->OnImportedIfListChangedBP.AddDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnImportedIfListChanged);
	BackendSignals->OnLocalIfSignalSignalBP.AddDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnLocalIfSignal);
	BackendSignals->OnLocalIfSignalListSignalBP.AddDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnLocalIfSignalList);
	BackendSignals->OnImportedIfSignalSignalBP.AddDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnImportedIfSignal);
	BackendSignals->OnImportedIfSignalListSignalBP.AddDynamic(this, &UTbRefIfacesParentIfLoggingDecorator::OnImportedIfSignalList);
	// populate service state to proxy
	LocalIf = BackendService->GetLocalIf();
	LocalIfList = BackendService->GetLocalIfList();
	ImportedIf = BackendService->GetImportedIf();
	ImportedIfList = BackendService->GetImportedIfList();
}

void UTbRefIfacesParentIfLoggingDecorator::OnLocalIfSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InParam)
{
	TbRefIfacesParentIfTracer::trace_signalLocalIfSignal(InParam);
	_GetSignals()->BroadcastLocalIfSignalSignal(InParam);
}

void UTbRefIfacesParentIfLoggingDecorator::OnLocalIfSignalList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InParam)
{
	TbRefIfacesParentIfTracer::trace_signalLocalIfSignalList(InParam);
	_GetSignals()->BroadcastLocalIfSignalListSignal(InParam);
}

void UTbRefIfacesParentIfLoggingDecorator::OnImportedIfSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InParam)
{
	TbRefIfacesParentIfTracer::trace_signalImportedIfSignal(InParam);
	_GetSignals()->BroadcastImportedIfSignalSignal(InParam);
}

void UTbRefIfacesParentIfLoggingDecorator::OnImportedIfSignalList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InParam)
{
	TbRefIfacesParentIfTracer::trace_signalImportedIfSignalList(InParam);
	_GetSignals()->BroadcastImportedIfSignalListSignal(InParam);
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

void UTbRefIfacesParentIfLoggingDecorator::OnLocalIfListChanged(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList)
{
	TbRefIfacesParentIfTracer::capture_state(BackendService.GetObject(), this);
	LocalIfList = InLocalIfList;
	_GetSignals()->BroadcastLocalIfListChanged(InLocalIfList);
}

TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> UTbRefIfacesParentIfLoggingDecorator::GetLocalIfList() const
{
	return BackendService->GetLocalIfList();
}

void UTbRefIfacesParentIfLoggingDecorator::SetLocalIfList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList)
{
	TbRefIfacesParentIfTracer::trace_callSetLocalIfList(InLocalIfList);
	BackendService->SetLocalIfList(InLocalIfList);
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

void UTbRefIfacesParentIfLoggingDecorator::OnImportedIfListChanged(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList)
{
	TbRefIfacesParentIfTracer::capture_state(BackendService.GetObject(), this);
	ImportedIfList = InImportedIfList;
	_GetSignals()->BroadcastImportedIfListChanged(InImportedIfList);
}

TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> UTbRefIfacesParentIfLoggingDecorator::GetImportedIfList() const
{
	return BackendService->GetImportedIfList();
}

void UTbRefIfacesParentIfLoggingDecorator::SetImportedIfList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList)
{
	TbRefIfacesParentIfTracer::trace_callSetImportedIfList(InImportedIfList);
	BackendService->SetImportedIfList(InImportedIfList);
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> UTbRefIfacesParentIfLoggingDecorator::LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	TbRefIfacesParentIfTracer::trace_callLocalIfMethod(Param);
	return BackendService->LocalIfMethod(Param);
}

TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> UTbRefIfacesParentIfLoggingDecorator::LocalIfMethodList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param)
{
	TbRefIfacesParentIfTracer::trace_callLocalIfMethodList(Param);
	return BackendService->LocalIfMethodList(Param);
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> UTbRefIfacesParentIfLoggingDecorator::ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	TbRefIfacesParentIfTracer::trace_callImportedIfMethod(Param);
	return BackendService->ImportedIfMethod(Param);
}

TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> UTbRefIfacesParentIfLoggingDecorator::ImportedIfMethodList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param)
{
	TbRefIfacesParentIfTracer::trace_callImportedIfMethodList(Param);
	return BackendService->ImportedIfMethodList(Param);
}
