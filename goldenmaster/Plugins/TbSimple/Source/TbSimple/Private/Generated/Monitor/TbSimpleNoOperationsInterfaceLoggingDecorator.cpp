
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
#include "Implementation/TbSimpleNoOperationsInterface.h"
#include "TbSimple.trace.h"
#include "TbSimpleFactory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(LogTbSimpleNoOperationsInterfaceLoggingDecorator);

class FTbSimpleNoOperationsInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSimpleNoOperationsInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, bInProgress(true)
	{
	}

	void Cancel()
	{
		bInProgress = false;
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		if (bInProgress == false)
		{
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
	}

	virtual void NotifyObjectDestroyed()
	{
		Cancel();
	}

	virtual void NotifyActionAborted()
	{
		Cancel();
	}
};
UTbSimpleNoOperationsInterfaceLoggingDecorator::UTbSimpleNoOperationsInterfaceLoggingDecorator()
	: UAbstractTbSimpleNoOperationsInterface()
{
}

UTbSimpleNoOperationsInterfaceLoggingDecorator::~UTbSimpleNoOperationsInterfaceLoggingDecorator() = default;

void UTbSimpleNoOperationsInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	BackendService = FTbSimpleModuleFactory::createITbSimpleNoOperationsInterfaceInterface(GetGameInstance(), Collection);
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropIntChanged);
	BackendService->GetSigVoidSignalDelegate().AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigVoid);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigBool);
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
		BackendService->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropBoolChanged);
		BackendService->GetPropIntChangedDelegate().RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropIntChanged);
		BackendService->GetSigVoidSignalDelegate().RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigVoid);
		BackendService->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigBool);
	}

	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTbSimpleNoOperationsInterfaceLoggingDecorator, Error, TEXT("Cannot set backend service - interface TbSimpleNoOperationsInterface is not fully implemented"));
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropIntChanged);
	BackendService->GetSigVoidSignalDelegate().AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigVoid);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigBool);
	// populate service state to proxy
	bPropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigVoid()
{
	TbSimpleNoOperationsInterfaceTracer::trace_signalSigVoid();
	Execute_BroadcastSigVoid(this);
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::OnSigBool(bool bParamBool)
{
	TbSimpleNoOperationsInterfaceTracer::trace_signalSigBool(bParamBool);
	Execute_BroadcastSigBool(this, bParamBool);
}

void UTbSimpleNoOperationsInterfaceLoggingDecorator::OnPropBoolChanged(bool bInPropBool)
{
	TbSimpleNoOperationsInterfaceTracer::capture_state(BackendService.GetObject(), this);
	bPropBool = bInPropBool;
	Execute_BroadcastPropBoolChanged(this, bInPropBool);
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
	Execute_BroadcastPropIntChanged(this, InPropInt);
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
