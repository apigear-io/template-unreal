
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
#include "TbSame1SameStruct2InterfaceProxy.h"
#include "SameStruct2Interface/TbSame1SameStruct2InterfaceLocal.h"
#include "apig/TbSame1.trace.h"
#include "TbSame1Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

class FTbSame1SameStruct2InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSame1SameStruct2InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTbSame1SameStruct2InterfaceProxy::UTbSame1SameStruct2InterfaceProxy()
	: ITbSame1SameStruct2InterfaceInterface()
	, Prop1(FTbSame1Struct2())
	, Prop2(FTbSame1Struct2())
{
	BackendService = FTbSame1ModuleFactory::createITbSame1SameStruct2InterfaceInterface();
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTbSame1SameStruct2InterfaceProxy::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTbSame1SameStruct2InterfaceProxy::OnProp2Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTbSame1SameStruct2InterfaceProxy::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTbSame1SameStruct2InterfaceProxy::OnSig2);
}

UTbSame1SameStruct2InterfaceProxy::~UTbSame1SameStruct2InterfaceProxy()
{
	if (BackendService != nullptr)
	{
		//BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbSame1SameStruct2InterfaceProxy::OnProp1Changed);
		//BackendService->GetProp2ChangedDelegate().RemoveDynamic(this, &UTbSame1SameStruct2InterfaceProxy::OnProp2Changed);
		//BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTbSame1SameStruct2InterfaceProxy::OnSig1);
		//BackendService->GetSig2SignalDelegate().RemoveDynamic(this, &UTbSame1SameStruct2InterfaceProxy::OnSig2);
	}
}
void UTbSame1SameStruct2InterfaceProxy::OnSig1(const FTbSame1Struct1& Param1)
{
	TbSame1SameStruct2InterfaceTracer::trace_signalSig1(Param1);
	Sig1Signal.Broadcast(Param1);
}

FTbSame1SameStruct2InterfaceSig1Delegate& UTbSame1SameStruct2InterfaceProxy::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame1SameStruct2InterfaceProxy::OnSig2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	TbSame1SameStruct2InterfaceTracer::trace_signalSig2(Param1, Param2);
	Sig2Signal.Broadcast(Param1, Param2);
}

FTbSame1SameStruct2InterfaceSig2Delegate& UTbSame1SameStruct2InterfaceProxy::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTbSame1SameStruct2InterfaceProxy::OnProp1Changed(const FTbSame1Struct2& InProp1)
{
	TbSame1SameStruct2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

FTbSame1Struct2 UTbSame1SameStruct2InterfaceProxy::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTbSame1SameStruct2InterfaceProxy::SetProp1_Implementation(const FTbSame1Struct2& InProp1)
{
	TbSame1SameStruct2InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

FTbSame1Struct2 UTbSame1SameStruct2InterfaceProxy::GetProp1_Private() const
{
	return Execute_GetProp1(this);
}

void UTbSame1SameStruct2InterfaceProxy::SetProp1_Private(const FTbSame1Struct2& InProp1)
{
	Execute_SetProp1(this, InProp1);
}

FTbSame1SameStruct2InterfaceProp1ChangedDelegate& UTbSame1SameStruct2InterfaceProxy::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbSame1SameStruct2InterfaceProxy::OnProp2Changed(const FTbSame1Struct2& InProp2)
{
	TbSame1SameStruct2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Prop2Changed.Broadcast(InProp2);
}

FTbSame1Struct2 UTbSame1SameStruct2InterfaceProxy::GetProp2_Implementation() const
{
	return BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTbSame1SameStruct2InterfaceProxy::SetProp2_Implementation(const FTbSame1Struct2& InProp2)
{
	TbSame1SameStruct2InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

FTbSame1Struct2 UTbSame1SameStruct2InterfaceProxy::GetProp2_Private() const
{
	return Execute_GetProp2(this);
}

void UTbSame1SameStruct2InterfaceProxy::SetProp2_Private(const FTbSame1Struct2& InProp2)
{
	Execute_SetProp2(this, InProp2);
}

FTbSame1SameStruct2InterfaceProp2ChangedDelegate& UTbSame1SameStruct2InterfaceProxy::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTbSame1SameStruct2InterfaceProxy::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1)
{
	TbSame1SameStruct2InterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameStruct2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameStruct2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame1SameStruct2InterfaceLatentAction* CompletionAction = new FTbSame1SameStruct2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
				CompletionAction->Cancel();
			});
	}
}
FTbSame1Struct1 UTbSame1SameStruct2InterfaceProxy::Func1_Implementation(const FTbSame1Struct1& Param1)
{
	TbSame1SameStruct2InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}
void UTbSame1SameStruct2InterfaceProxy::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	TbSame1SameStruct2InterfaceTracer::trace_callFunc2(Param1, Param2);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameStruct2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameStruct2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame1SameStruct2InterfaceLatentAction* CompletionAction = new FTbSame1SameStruct2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
				CompletionAction->Cancel();
			});
	}
}
FTbSame1Struct1 UTbSame1SameStruct2InterfaceProxy::Func2_Implementation(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	TbSame1SameStruct2InterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
}
