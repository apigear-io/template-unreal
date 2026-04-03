

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
#include "TbStructArray/Generated/Monitor/TbStructArrayStructArrayFieldInterfaceLoggingDecorator.h"
#include "TbStructArraySettings.h"
#include "TbStructArray.trace.h"
#include "TbStructArray/Generated/TbStructArrayFactory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(LogTbStructArrayStructArrayFieldInterfaceLoggingDecorator);
UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::UTbStructArrayStructArrayFieldInterfaceLoggingDecorator()
	: UAbstractTbStructArrayStructArrayFieldInterface()
{
}

UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::~UTbStructArrayStructArrayFieldInterfaceLoggingDecorator() = default;

void UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	setBackendService(UTbStructArraySettings::GetITbStructArrayStructArrayFieldInterfaceInterfaceForLogging(Collection));
}

void UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::Deinitialize()
{
	Super::Deinitialize();
	if (BackendService != nullptr)
	{
		UTbStructArrayStructArrayFieldInterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		if (BackendPublisher)
		{
			BackendPublisher->Unsubscribe(TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>(this));
		}
	}
	BackendService = nullptr;
}

void UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		UTbStructArrayStructArrayFieldInterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service TbStructArrayStructArrayFieldInterface"));
		if (!BackendPublisher)
		{
			return;
		}
		BackendPublisher->Unsubscribe(TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>(this));
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbStructArrayStructArrayFieldInterface is not fully implemented"));
	if (InService.GetInterface() == nullptr)
	{
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	UTbStructArrayStructArrayFieldInterfacePublisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot subscribe to delegates from backend service TbStructArrayStructArrayFieldInterface"));
	if (!BackendPublisher)
	{
		return;
	}
	// populate service state to proxy before subscribing
	PropStructArray = BackendService->GetPropStructArray();
	PropEnumArray = BackendService->GetPropEnumArray();
	PropIntArray = BackendService->GetPropIntArray();
	PropMixed = BackendService->GetPropMixed();
	// connect property changed signals or simple events
	BackendPublisher->Subscribe(TWeakInterfacePtr<ITbStructArrayStructArrayFieldInterfaceSubscriberInterface>(this));
}

void UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::OnSigMixedSignal(const FTbStructArrayMixedStruct& InParamMixed)
{
	if (!BackendService)
	{
		return;
	}
	TbStructArrayStructArrayFieldInterfaceTracer::trace_signalSigMixed(InParamMixed);
	_GetPublisher()->BroadcastSigMixedSignal(InParamMixed);
}

void UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::OnSigStructArraySignal(const FTbStructArrayStructWithArrayOfStructs& InParamPoints)
{
	if (!BackendService)
	{
		return;
	}
	TbStructArrayStructArrayFieldInterfaceTracer::trace_signalSigStructArray(InParamPoints);
	_GetPublisher()->BroadcastSigStructArraySignal(InParamPoints);
}

void UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::OnPropStructArrayChanged(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
{
	if (!BackendService)
	{
		return;
	}
	TbStructArrayStructArrayFieldInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropStructArray = InPropStructArray;
	_GetPublisher()->BroadcastPropStructArrayChanged(InPropStructArray);
}

FTbStructArrayStructWithArrayOfStructs UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::GetPropStructArray() const
{
	if (!BackendService)
	{
		UE_LOG(LogTbStructArrayStructArrayFieldInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTbStructArrayStructWithArrayOfStructs();
	}
	return BackendService->GetPropStructArray();
}

void UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::SetPropStructArray(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
{
	if (!BackendService)
	{
		UE_LOG(LogTbStructArrayStructArrayFieldInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	TbStructArrayStructArrayFieldInterfaceTracer::trace_callSetPropStructArray(InPropStructArray);
	BackendService->SetPropStructArray(InPropStructArray);
}

void UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::OnPropEnumArrayChanged(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
{
	if (!BackendService)
	{
		return;
	}
	TbStructArrayStructArrayFieldInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropEnumArray = InPropEnumArray;
	_GetPublisher()->BroadcastPropEnumArrayChanged(InPropEnumArray);
}

FTbStructArrayStructWithArrayOfEnums UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::GetPropEnumArray() const
{
	if (!BackendService)
	{
		UE_LOG(LogTbStructArrayStructArrayFieldInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTbStructArrayStructWithArrayOfEnums();
	}
	return BackendService->GetPropEnumArray();
}

void UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::SetPropEnumArray(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
{
	if (!BackendService)
	{
		UE_LOG(LogTbStructArrayStructArrayFieldInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	TbStructArrayStructArrayFieldInterfaceTracer::trace_callSetPropEnumArray(InPropEnumArray);
	BackendService->SetPropEnumArray(InPropEnumArray);
}

void UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::OnPropIntArrayChanged(const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
{
	if (!BackendService)
	{
		return;
	}
	TbStructArrayStructArrayFieldInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropIntArray = InPropIntArray;
	_GetPublisher()->BroadcastPropIntArrayChanged(InPropIntArray);
}

FTbStructArrayStructWithArrayOfInts UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::GetPropIntArray() const
{
	if (!BackendService)
	{
		UE_LOG(LogTbStructArrayStructArrayFieldInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTbStructArrayStructWithArrayOfInts();
	}
	return BackendService->GetPropIntArray();
}

void UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::SetPropIntArray(const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
{
	if (!BackendService)
	{
		UE_LOG(LogTbStructArrayStructArrayFieldInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	TbStructArrayStructArrayFieldInterfaceTracer::trace_callSetPropIntArray(InPropIntArray);
	BackendService->SetPropIntArray(InPropIntArray);
}

void UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::OnPropMixedChanged(const FTbStructArrayMixedStruct& InPropMixed)
{
	if (!BackendService)
	{
		return;
	}
	TbStructArrayStructArrayFieldInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropMixed = InPropMixed;
	_GetPublisher()->BroadcastPropMixedChanged(InPropMixed);
}

FTbStructArrayMixedStruct UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::GetPropMixed() const
{
	if (!BackendService)
	{
		UE_LOG(LogTbStructArrayStructArrayFieldInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTbStructArrayMixedStruct();
	}
	return BackendService->GetPropMixed();
}

void UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::SetPropMixed(const FTbStructArrayMixedStruct& InPropMixed)
{
	if (!BackendService)
	{
		UE_LOG(LogTbStructArrayStructArrayFieldInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return;
	}
	TbStructArrayStructArrayFieldInterfaceTracer::trace_callSetPropMixed(InPropMixed);
	BackendService->SetPropMixed(InPropMixed);
}

FTbStructArrayMixedStruct UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::FuncMixed(const FTbStructArrayMixedStruct& ParamMixed)
{
	if (!BackendService)
	{
		UE_LOG(LogTbStructArrayStructArrayFieldInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTbStructArrayMixedStruct();
	}
	TbStructArrayStructArrayFieldInterfaceTracer::trace_callFuncMixed(ParamMixed);
	return BackendService->FuncMixed(ParamMixed);
}

FTbStructArrayStructWithArrayOfStructs UTbStructArrayStructArrayFieldInterfaceLoggingDecorator::FuncStructArray(const FTbStructArrayStructWithArrayOfStructs& ParamPoints)
{
	if (!BackendService)
	{
		UE_LOG(LogTbStructArrayStructArrayFieldInterfaceLoggingDecorator, Error, TEXT("BackendService not set"));
		return FTbStructArrayStructWithArrayOfStructs();
	}
	TbStructArrayStructArrayFieldInterfaceTracer::trace_callFuncStructArray(ParamPoints);
	return BackendService->FuncStructArray(ParamPoints);
}
