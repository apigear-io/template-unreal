
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
#include "Generated/Monitor/TbSimpleNoPropertiesInterfaceLoggingDecorator.h"
#include "Implementation/TbSimpleNoPropertiesInterface.h"
#include "TbSimple.trace.h"
#include "TbSimpleFactory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(LogTbSimpleNoPropertiesInterfaceLoggingDecorator);

class FTbSimpleNoPropertiesInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSimpleNoPropertiesInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTbSimpleNoPropertiesInterfaceLoggingDecorator::UTbSimpleNoPropertiesInterfaceLoggingDecorator()
	: ITbSimpleNoPropertiesInterfaceInterface()
{
}

UTbSimpleNoPropertiesInterfaceLoggingDecorator::~UTbSimpleNoPropertiesInterfaceLoggingDecorator() = default;

void UTbSimpleNoPropertiesInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	BackendService = FTbSimpleModuleFactory::createITbSimpleNoPropertiesInterfaceInterface(GetGameInstance(), Collection);
	BackendService->GetSigVoidSignalDelegate().AddDynamic(this, &UTbSimpleNoPropertiesInterfaceLoggingDecorator::OnSigVoid);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleNoPropertiesInterfaceLoggingDecorator::OnSigBool);
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
		BackendService->GetSigVoidSignalDelegate().RemoveDynamic(this, &UTbSimpleNoPropertiesInterfaceLoggingDecorator::OnSigVoid);
		BackendService->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTbSimpleNoPropertiesInterfaceLoggingDecorator::OnSigBool);
	}

	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTbSimpleNoPropertiesInterfaceLoggingDecorator, Error, TEXT("Cannot set backend service to %s - interface TbSimpleNoPropertiesInterface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetSigVoidSignalDelegate().AddDynamic(this, &UTbSimpleNoPropertiesInterfaceLoggingDecorator::OnSigVoid);
	BackendService->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleNoPropertiesInterfaceLoggingDecorator::OnSigBool);
	// populate service state to proxy
}
void UTbSimpleNoPropertiesInterfaceLoggingDecorator::BroadcastSigVoid_Implementation()
{
	SigVoidSignal.Broadcast();
}

void UTbSimpleNoPropertiesInterfaceLoggingDecorator::OnSigVoid()
{
	TbSimpleNoPropertiesInterfaceTracer::trace_signalSigVoid();
	Execute_BroadcastSigVoid(this);
}

FTbSimpleNoPropertiesInterfaceSigVoidDelegate& UTbSimpleNoPropertiesInterfaceLoggingDecorator::GetSigVoidSignalDelegate()
{
	return SigVoidSignal;
}

void UTbSimpleNoPropertiesInterfaceLoggingDecorator::BroadcastSigBool_Implementation(bool bParamBool)
{
	SigBoolSignal.Broadcast(bParamBool);
}

void UTbSimpleNoPropertiesInterfaceLoggingDecorator::OnSigBool(bool bParamBool)
{
	TbSimpleNoPropertiesInterfaceTracer::trace_signalSigBool(bParamBool);
	Execute_BroadcastSigBool(this, bParamBool);
}

FTbSimpleNoPropertiesInterfaceSigBoolDelegate& UTbSimpleNoPropertiesInterfaceLoggingDecorator::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTbSimpleNoPropertiesInterfaceLoggingDecorator::FuncVoid_Implementation()
{
	TbSimpleNoPropertiesInterfaceTracer::trace_callFuncVoid();
	BackendService->Execute_FuncVoid(BackendService.GetObject());
}
void UTbSimpleNoPropertiesInterfaceLoggingDecorator::FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool)
{
	TbSimpleNoPropertiesInterfaceTracer::trace_callFuncBool(bParamBool);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleNoPropertiesInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleNoPropertiesInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleNoPropertiesInterfaceLatentAction* CompletionAction = new FTbSimpleNoPropertiesInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[bParamBool, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_FuncBool(BackendService.GetObject(), bParamBool);
				CompletionAction->Cancel();
			});
	}
}
bool UTbSimpleNoPropertiesInterfaceLoggingDecorator::FuncBool_Implementation(bool bParamBool)
{
	TbSimpleNoPropertiesInterfaceTracer::trace_callFuncBool(bParamBool);
	return BackendService->Execute_FuncBool(BackendService.GetObject(), bParamBool);
}
