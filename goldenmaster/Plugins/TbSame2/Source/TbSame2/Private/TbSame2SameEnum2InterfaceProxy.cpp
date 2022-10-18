
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
#include "TbSame2SameEnum2InterfaceProxy.h"
#include "SameEnum2Interface/TbSame2SameEnum2InterfaceLocal.h"
#include "apig/TbSame2.trace.h"
#include "TbSame2Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

class FTbSame2SameEnum2InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSame2SameEnum2InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTbSame2SameEnum2InterfaceProxy::UTbSame2SameEnum2InterfaceProxy()
	: ITbSame2SameEnum2InterfaceInterface()
	, Prop1(ETbSame2Enum1::VALUE1)
	, Prop2(ETbSame2Enum2::VALUE1)
{
	BackendService = FTbSame2ModuleFactory::createITbSame2SameEnum2InterfaceInterface();
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnProp2Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnSig2);
}

UTbSame2SameEnum2InterfaceProxy::~UTbSame2SameEnum2InterfaceProxy()
{
	if (BackendService != nullptr)
	{
		//BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnProp1Changed);
		//BackendService->GetProp2ChangedDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnProp2Changed);
		//BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnSig1);
		//BackendService->GetSig2SignalDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnSig2);
	}
}

void UTbSame2SameEnum2InterfaceProxy::setBackendService(TScriptInterface<ITbSame2SameEnum2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnProp1Changed);
		BackendService->GetProp2ChangedDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnProp2Changed);
		BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnSig1);
		BackendService->GetSig2SignalDelegate().RemoveDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnSig2);
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnProp2Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTbSame2SameEnum2InterfaceProxy::OnSig2);
	// populate service state to proxy
	Prop1 = BackendService->Execute_GetProp1(BackendService.GetObject());
	Prop2 = BackendService->Execute_GetProp2(BackendService.GetObject());
}
void UTbSame2SameEnum2InterfaceProxy::OnSig1(const ETbSame2Enum1& Param1)
{
	TbSame2SameEnum2InterfaceTracer::trace_signalSig1(Param1);
	Sig1Signal.Broadcast(Param1);
}

FTbSame2SameEnum2InterfaceSig1Delegate& UTbSame2SameEnum2InterfaceProxy::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame2SameEnum2InterfaceProxy::OnSig2(const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2)
{
	TbSame2SameEnum2InterfaceTracer::trace_signalSig2(Param1, Param2);
	Sig2Signal.Broadcast(Param1, Param2);
}

FTbSame2SameEnum2InterfaceSig2Delegate& UTbSame2SameEnum2InterfaceProxy::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTbSame2SameEnum2InterfaceProxy::OnProp1Changed(const ETbSame2Enum1& InProp1)
{
	TbSame2SameEnum2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceProxy::GetProp1_Implementation() const
{
	return BackendService->Execute_GetProp1(BackendService.GetObject());
}

void UTbSame2SameEnum2InterfaceProxy::SetProp1_Implementation(const ETbSame2Enum1& InProp1)
{
	TbSame2SameEnum2InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceProxy::GetProp1_Private() const
{
	return Execute_GetProp1(this);
}

void UTbSame2SameEnum2InterfaceProxy::SetProp1_Private(const ETbSame2Enum1& InProp1)
{
	Execute_SetProp1(this, InProp1);
}

FTbSame2SameEnum2InterfaceProp1ChangedDelegate& UTbSame2SameEnum2InterfaceProxy::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbSame2SameEnum2InterfaceProxy::OnProp2Changed(const ETbSame2Enum2& InProp2)
{
	TbSame2SameEnum2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Prop2Changed.Broadcast(InProp2);
}

ETbSame2Enum2 UTbSame2SameEnum2InterfaceProxy::GetProp2_Implementation() const
{
	return BackendService->Execute_GetProp2(BackendService.GetObject());
}

void UTbSame2SameEnum2InterfaceProxy::SetProp2_Implementation(const ETbSame2Enum2& InProp2)
{
	TbSame2SameEnum2InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

ETbSame2Enum2 UTbSame2SameEnum2InterfaceProxy::GetProp2_Private() const
{
	return Execute_GetProp2(this);
}

void UTbSame2SameEnum2InterfaceProxy::SetProp2_Private(const ETbSame2Enum2& InProp2)
{
	Execute_SetProp2(this, InProp2);
}

FTbSame2SameEnum2InterfaceProp2ChangedDelegate& UTbSame2SameEnum2InterfaceProxy::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTbSame2SameEnum2InterfaceProxy::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, const ETbSame2Enum1& Param1)
{
	TbSame2SameEnum2InterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameEnum2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameEnum2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame2SameEnum2InterfaceLatentAction* CompletionAction = new FTbSame2SameEnum2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func1(BackendService.GetObject(), Param1);
				CompletionAction->Cancel();
			});
	}
}
ETbSame2Enum1 UTbSame2SameEnum2InterfaceProxy::Func1_Implementation(const ETbSame2Enum1& Param1)
{
	TbSame2SameEnum2InterfaceTracer::trace_callFunc1(Param1);
	return BackendService->Execute_Func1(BackendService.GetObject(), Param1);
}
void UTbSame2SameEnum2InterfaceProxy::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2)
{
	TbSame2SameEnum2InterfaceTracer::trace_callFunc2(Param1, Param2);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameEnum2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameEnum2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame2SameEnum2InterfaceLatentAction* CompletionAction = new FTbSame2SameEnum2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, this, &Result, CompletionAction]()
			{
				Result = BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
				CompletionAction->Cancel();
			});
	}
}
ETbSame2Enum1 UTbSame2SameEnum2InterfaceProxy::Func2_Implementation(const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2)
{
	TbSame2SameEnum2InterfaceTracer::trace_callFunc2(Param1, Param2);
	return BackendService->Execute_Func2(BackendService.GetObject(), Param1, Param2);
}
