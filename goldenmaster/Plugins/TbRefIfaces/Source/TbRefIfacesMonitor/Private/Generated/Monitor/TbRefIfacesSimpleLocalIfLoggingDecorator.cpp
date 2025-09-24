

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
#include "TbRefIfaces/Generated/Monitor/TbRefIfacesSimpleLocalIfLoggingDecorator.h"
#include "TbRefIfacesSettings.h"
#include "TbRefIfaces.trace.h"
#include "TbRefIfaces/Generated/TbRefIfacesFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbRefIfacesSimpleLocalIfLoggingDecorator);
UTbRefIfacesSimpleLocalIfLoggingDecorator::UTbRefIfacesSimpleLocalIfLoggingDecorator()
	: UAbstractTbRefIfacesSimpleLocalIf()
{
}

UTbRefIfacesSimpleLocalIfLoggingDecorator::~UTbRefIfacesSimpleLocalIfLoggingDecorator() = default;

void UTbRefIfacesSimpleLocalIfLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbRefIfacesSettings::GetITbRefIfacesSimpleLocalIfInterfaceForLogging(Collection));
}

void UTbRefIfacesSimpleLocalIfLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbRefIfacesSimpleLocalIfLoggingDecorator::setBackendService(TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbRefIfacesSimpleLocalIfPublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbRefIfacesSimpleLocalIf"));
		BackendPublisher->Unsubscribe(TWeakInterfacePtr<ITbRefIfacesSimpleLocalIfSubscriberInterface>(this));
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbRefIfacesSimpleLocalIf is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	UTbRefIfacesSimpleLocalIfPublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbRefIfacesSimpleLocalIf"));
	// connect property changed signals or simple events
	BackendPublisher->Subscribe(TWeakInterfacePtr<ITbRefIfacesSimpleLocalIfSubscriberInterface>(this));
	// populate service state to proxy
	IntProperty = BackendService->GetIntProperty();
}

void UTbRefIfacesSimpleLocalIfLoggingDecorator::OnIntSignalSignal(int32 InParam)
{
	TbRefIfacesSimpleLocalIfTracer::trace_signalIntSignal(InParam);
	_GetPublisher()->BroadcastIntSignalSignal(InParam);
}

void UTbRefIfacesSimpleLocalIfLoggingDecorator::OnIntPropertyChanged(int32 InIntProperty)
{
	TbRefIfacesSimpleLocalIfTracer::capture_state(BackendService.GetObject(), this);
	IntProperty = InIntProperty;
	_GetPublisher()->BroadcastIntPropertyChanged(InIntProperty);
}

int32 UTbRefIfacesSimpleLocalIfLoggingDecorator::GetIntProperty() const
{
	return BackendService->GetIntProperty();
}

void UTbRefIfacesSimpleLocalIfLoggingDecorator::SetIntProperty(int32 InIntProperty)
{
	TbRefIfacesSimpleLocalIfTracer::trace_callSetIntProperty(InIntProperty);
	BackendService->SetIntProperty(InIntProperty);
}

int32 UTbRefIfacesSimpleLocalIfLoggingDecorator::IntMethod(int32 Param)
{
	TbRefIfacesSimpleLocalIfTracer::trace_callIntMethod(Param);
	return BackendService->IntMethod(Param);
}
