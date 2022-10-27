
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
#include "Generated/Monitor/TbSame1SameStruct1InterfaceLoggingDecorator.h"
#include "Implementation/TbSame1SameStruct1Interface.h"
#include "Generated/api/TbSame1.trace.h"
#include "TbSame1Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(LogTbSame1SameStruct1InterfaceLoggingDecorator);

class FTbSame1SameStruct1InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSame1SameStruct1InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTbSame1SameStruct1InterfaceLoggingDecorator::UTbSame1SameStruct1InterfaceLoggingDecorator()
	: ITbSame1SameStruct1InterfaceInterface()
{
	BackendService = FTbSame1ModuleFactory::createITbSame1SameStruct1InterfaceInterface();
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTbSame1SameStruct1InterfaceLoggingDecorator::OnProp1Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTbSame1SameStruct1InterfaceLoggingDecorator::OnSig1);
}

UTbSame1SameStruct1InterfaceLoggingDecorator::~UTbSame1SameStruct1InterfaceLoggingDecorator() = default;

void UTbSame1SameStruct1InterfaceLoggingDecorator::setBackendService(TScriptInterface<ITbSame1SameStruct1InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbSame1SameStruct1InterfaceLoggingDecorator::OnProp1Changed);
		BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTbSame1SameStruct1InterfaceLoggingDecorator::OnSig1);
	}

	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTbSame1SameStruct1InterfaceLoggingDecorator, Error, TEXT("Cannot set backend service to %s - interface TbSame1SameStruct1Interface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTbSame1SameStruct1InterfaceLoggingDecorator::OnProp1Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTbSame1SameStruct1InterfaceLoggingDecorator::OnSig1);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
}
void UTbSame1SameStruct1InterfaceLoggingDecorator::BroadcastSig1_Implementation(const FTbSame1Struct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

void UTbSame1SameStruct1InterfaceLoggingDecorator::OnSig1(const FTbSame1Struct1& Param1)
{
	TbSame1SameStruct1InterfaceTracer::trace_signalSig1(Param1);
	Execute_BroadcastSig1(this, Param1);
}

FTbSame1SameStruct1InterfaceSig1Delegate& UTbSame1SameStruct1InterfaceLoggingDecorator::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame1SameStruct1InterfaceLoggingDecorator::BroadcastProp1Changed_Implementation(const FTbSame1Struct1& InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

void UTbSame1SameStruct1InterfaceLoggingDecorator::OnProp1Changed(const FTbSame1Struct1& InProp1)
{
	TbSame1SameStruct1InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Execute_BroadcastProp1Changed(this, InProp1);
}

FTbSame1Struct1 UTbSame1SameStruct1InterfaceLoggingDecorator::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTbSame1SameStruct1InterfaceLoggingDecorator::SetProp1_Implementation(const FTbSame1Struct1& InProp1)
{
	TbSame1SameStruct1InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

FTbSame1Struct1 UTbSame1SameStruct1InterfaceLoggingDecorator::GetProp1_Private() const
{
	return Execute_GetProp1(this);
}

void UTbSame1SameStruct1InterfaceLoggingDecorator::SetProp1_Private(const FTbSame1Struct1& InProp1)
{
	Execute_SetProp1(this, InProp1);
}

FTbSame1SameStruct1InterfaceProp1ChangedDelegate& UTbSame1SameStruct1InterfaceLoggingDecorator::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbSame1SameStruct1InterfaceLoggingDecorator::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1)
{
	TbSame1SameStruct1InterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameStruct1InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameStruct1InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame1SameStruct1InterfaceLatentAction* CompletionAction = new FTbSame1SameStruct1InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
				CompletionAction->Cancel();
			});
	}
}
FTbSame1Struct1 UTbSame1SameStruct1InterfaceLoggingDecorator::Func1_Implementation(const FTbSame1Struct1& Param1)
{
	TbSame1SameStruct1InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}