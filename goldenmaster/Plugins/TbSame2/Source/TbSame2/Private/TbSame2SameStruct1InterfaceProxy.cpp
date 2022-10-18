
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
#include "TbSame2SameStruct1InterfaceProxy.h"
#include "SameStruct1Interface/TbSame2SameStruct1InterfaceLocal.h"
#include "apig/TbSame2.trace.h"
#include "TbSame2Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

class FTbSame2SameStruct1InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSame2SameStruct1InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTbSame2SameStruct1InterfaceProxy::UTbSame2SameStruct1InterfaceProxy()
	: ITbSame2SameStruct1InterfaceInterface()
	, Prop1(FTbSame2Struct1())
{
	BackendService = FTbSame2ModuleFactory::createITbSame2SameStruct1InterfaceInterface();
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTbSame2SameStruct1InterfaceProxy::OnProp1Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTbSame2SameStruct1InterfaceProxy::OnSig1);
}

UTbSame2SameStruct1InterfaceProxy::~UTbSame2SameStruct1InterfaceProxy()
{
	if (BackendService != nullptr)
	{
		//BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbSame2SameStruct1InterfaceProxy::OnProp1Changed);
		//BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTbSame2SameStruct1InterfaceProxy::OnSig1);
	}
}

void UTbSame2SameStruct1InterfaceProxy::setBackendService(TScriptInterface<ITbSame2SameStruct1InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbSame2SameStruct1InterfaceProxy::OnProp1Changed);
		BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTbSame2SameStruct1InterfaceProxy::OnSig1);
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTbSame2SameStruct1InterfaceProxy::OnProp1Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTbSame2SameStruct1InterfaceProxy::OnSig1);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
}
void UTbSame2SameStruct1InterfaceProxy::OnSig1(const FTbSame2Struct1& Param1)
{
	TbSame2SameStruct1InterfaceTracer::trace_signalSig1(Param1);
	Sig1Signal.Broadcast(Param1);
}

FTbSame2SameStruct1InterfaceSig1Delegate& UTbSame2SameStruct1InterfaceProxy::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame2SameStruct1InterfaceProxy::OnProp1Changed(const FTbSame2Struct1& InProp1)
{
	TbSame2SameStruct1InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

FTbSame2Struct1 UTbSame2SameStruct1InterfaceProxy::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTbSame2SameStruct1InterfaceProxy::SetProp1_Implementation(const FTbSame2Struct1& InProp1)
{
	TbSame2SameStruct1InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

FTbSame2Struct1 UTbSame2SameStruct1InterfaceProxy::GetProp1_Private() const
{
	return Execute_GetProp1(this);
}

void UTbSame2SameStruct1InterfaceProxy::SetProp1_Private(const FTbSame2Struct1& InProp1)
{
	Execute_SetProp1(this, InProp1);
}

FTbSame2SameStruct1InterfaceProp1ChangedDelegate& UTbSame2SameStruct1InterfaceProxy::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbSame2SameStruct1InterfaceProxy::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1)
{
	TbSame2SameStruct1InterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameStruct1InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameStruct1InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame2SameStruct1InterfaceLatentAction* CompletionAction = new FTbSame2SameStruct1InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
				CompletionAction->Cancel();
			});
	}
}
FTbSame2Struct1 UTbSame2SameStruct1InterfaceProxy::Func1_Implementation(const FTbSame2Struct1& Param1)
{
	TbSame2SameStruct1InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}
