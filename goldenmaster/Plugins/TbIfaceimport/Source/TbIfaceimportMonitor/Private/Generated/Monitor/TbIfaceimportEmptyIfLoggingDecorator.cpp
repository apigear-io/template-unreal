

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
#include "TbIfaceimport/Generated/Monitor/TbIfaceimportEmptyIfLoggingDecorator.h"
#include "TbIfaceimportSettings.h"
#include "TbIfaceimport.trace.h"
#include "TbIfaceimport/Generated/TbIfaceimportFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbIfaceimportEmptyIfLoggingDecorator);
UTbIfaceimportEmptyIfLoggingDecorator::UTbIfaceimportEmptyIfLoggingDecorator()
	: UAbstractTbIfaceimportEmptyIf()
{
}

UTbIfaceimportEmptyIfLoggingDecorator::~UTbIfaceimportEmptyIfLoggingDecorator() = default;

void UTbIfaceimportEmptyIfLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbIfaceimportSettings::GetITbIfaceimportEmptyIfInterfaceForLogging(Collection));
}

void UTbIfaceimportEmptyIfLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	if (BackendService != nullptr)
	{
		UTbIfaceimportEmptyIfPublisher* BackendPublisher = BackendService->_GetPublisher();
		if (BackendPublisher)
		{
			BackendPublisher->Unsubscribe(TWeakInterfacePtr<ITbIfaceimportEmptyIfSubscriberInterface>(this));
		}
	}
	BackendService = nullptr;
}

void UTbIfaceimportEmptyIfLoggingDecorator::setBackendService(TScriptInterface<ITbIfaceimportEmptyIfInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbIfaceimportEmptyIfPublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbIfaceimportEmptyIf"));
		if (!BackendPublisher)
		{
			return;
		}
		BackendPublisher->Unsubscribe(TWeakInterfacePtr<ITbIfaceimportEmptyIfSubscriberInterface>(this));
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbIfaceimportEmptyIf is not fully implemented"));
	if (InService.GetInterface() == nullptr)
	{
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	UTbIfaceimportEmptyIfPublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot subscribe to delegates from backend service TbIfaceimportEmptyIf"));
	if (!BackendPublisher)
	{
		return;
	}
	// populate service state to proxy before subscribing
	// connect property changed signals or simple events
	BackendPublisher->Subscribe(TWeakInterfacePtr<ITbIfaceimportEmptyIfSubscriberInterface>(this));
}
