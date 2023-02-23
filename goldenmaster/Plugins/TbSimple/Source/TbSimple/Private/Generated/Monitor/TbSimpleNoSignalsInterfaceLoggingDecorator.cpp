
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
#include "Generated/Monitor/TbSimpleNoSignalsInterfaceLoggingDecorator.h"
#include "Implementation/TbSimpleNoSignalsInterface.h"
#include "TbSimple.trace.h"
#include "TbSimpleFactory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(LogTbSimpleNoSignalsInterfaceLoggingDecorator);

class FTbSimpleNoSignalsInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSimpleNoSignalsInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTbSimpleNoSignalsInterfaceLoggingDecorator::UTbSimpleNoSignalsInterfaceLoggingDecorator()
	: UAbstractTbSimpleNoSignalsInterface()
{
}

UTbSimpleNoSignalsInterfaceLoggingDecorator::~UTbSimpleNoSignalsInterfaceLoggingDecorator() = default;

void UTbSimpleNoSignalsInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
	setBackendService(FTbSimpleModuleFactory::createITbSimpleNoSignalsInterfaceInterface(GetGameInstance(), Collection));
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	Super::Deinitialize();
	BackendService = nullptr;
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTbSimpleNoSignalsInterfaceLoggingDecorator::OnPropBoolChanged);
		BackendService->GetPropIntChangedDelegate().RemoveDynamic(this, &UTbSimpleNoSignalsInterfaceLoggingDecorator::OnPropIntChanged);
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface TbSimpleNoSignalsInterface is not fully implemented"));

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleNoSignalsInterfaceLoggingDecorator::OnPropBoolChanged);
	BackendService->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleNoSignalsInterfaceLoggingDecorator::OnPropIntChanged);
	// populate service state to proxy
	bPropBool = BackendService->Execute_GetPropBool(BackendService.GetObject());
	PropInt = BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::OnPropBoolChanged(bool bInPropBool)
{
	TbSimpleNoSignalsInterfaceTracer::capture_state(BackendService.GetObject(), this);
	bPropBool = bInPropBool;
	Execute_BroadcastPropBoolChanged(this, bInPropBool);
}

bool UTbSimpleNoSignalsInterfaceLoggingDecorator::GetPropBool_Implementation() const
{
	return BackendService->Execute_GetPropBool(BackendService.GetObject());
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::SetPropBool_Implementation(bool bInPropBool)
{
	TbSimpleNoSignalsInterfaceTracer::trace_callSetPropBool(bInPropBool);
	BackendService->Execute_SetPropBool(BackendService.GetObject(), bInPropBool);
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::OnPropIntChanged(int32 InPropInt)
{
	TbSimpleNoSignalsInterfaceTracer::capture_state(BackendService.GetObject(), this);
	PropInt = InPropInt;
	Execute_BroadcastPropIntChanged(this, InPropInt);
}

int32 UTbSimpleNoSignalsInterfaceLoggingDecorator::GetPropInt_Implementation() const
{
	return BackendService->Execute_GetPropInt(BackendService.GetObject());
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::SetPropInt_Implementation(int32 InPropInt)
{
	TbSimpleNoSignalsInterfaceTracer::trace_callSetPropInt(InPropInt);
	BackendService->Execute_SetPropInt(BackendService.GetObject(), InPropInt);
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::FuncVoid_Implementation()
{
	TbSimpleNoSignalsInterfaceTracer::trace_callFuncVoid();
	BackendService->Execute_FuncVoid(BackendService.GetObject());
}

void UTbSimpleNoSignalsInterfaceLoggingDecorator::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
{
	TbSimpleNoSignalsInterfaceTracer::trace_callFuncBool(bParamBool);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleNoSignalsInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleNoSignalsInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleNoSignalsInterfaceLatentAction* CompletionAction = new FTbSimpleNoSignalsInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[bParamBool, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncBool(BackendService.GetObject(), bParamBool);
				CompletionAction->Cancel();
			});
	}
}

bool UTbSimpleNoSignalsInterfaceLoggingDecorator::FuncBool_Implementation(bool bParamBool)
{
	TbSimpleNoSignalsInterfaceTracer::trace_callFuncBool(bParamBool);
	return BackendService->Execute_FuncBool(BackendService.GetObject(), bParamBool);
}
