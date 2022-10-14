
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
#include "TbSame1SameEnum2InterfaceProxy.h"
#include "SameEnum2Interface/TbSame1SameEnum2InterfaceLocal.h"
#include "apig/TbSame1.trace.h"
#include "TbSame1Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

class FTbSame1SameEnum2InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSame1SameEnum2InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTbSame1SameEnum2InterfaceProxy::UTbSame1SameEnum2InterfaceProxy()
	: ITbSame1SameEnum2InterfaceInterface()
	, Prop1(ETbSame1Enum1::VALUE1)
	, Prop2(ETbSame1Enum2::VALUE1)
{
	service = FTbSame1ModuleFactory::createITbSame1SameEnum2InterfaceInterface();
	service->GetProp1ChangedDelegate().AddDynamic(this, &UTbSame1SameEnum2InterfaceProxy::OnProp1Changed);
	service->GetProp2ChangedDelegate().AddDynamic(this, &UTbSame1SameEnum2InterfaceProxy::OnProp2Changed);
	service->GetSig1SignalDelegate().AddDynamic(this, &UTbSame1SameEnum2InterfaceProxy::OnSig1);
	service->GetSig2SignalDelegate().AddDynamic(this, &UTbSame1SameEnum2InterfaceProxy::OnSig2);
}

UTbSame1SameEnum2InterfaceProxy::~UTbSame1SameEnum2InterfaceProxy()
{
	service->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbSame1SameEnum2InterfaceProxy::OnProp1Changed);
	service->GetProp2ChangedDelegate().RemoveDynamic(this, &UTbSame1SameEnum2InterfaceProxy::OnProp2Changed);
	service->GetSig1SignalDelegate().RemoveDynamic(this, &UTbSame1SameEnum2InterfaceProxy::OnSig1);
	service->GetSig2SignalDelegate().RemoveDynamic(this, &UTbSame1SameEnum2InterfaceProxy::OnSig2);
}
void UTbSame1SameEnum2InterfaceProxy::OnSig1(const ETbSame1Enum1& Param1)
{
	TbSame1SameEnum2InterfaceTracer::trace_signalSig1(Param1);
	Sig1Signal.Broadcast(Param1);
}

FTbSame1SameEnum2InterfaceSig1Delegate& UTbSame1SameEnum2InterfaceProxy::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame1SameEnum2InterfaceProxy::OnSig2(const ETbSame1Enum1& Param1, const ETbSame1Enum2& Param2)
{
	TbSame1SameEnum2InterfaceTracer::trace_signalSig2(Param1, Param2);
	Sig2Signal.Broadcast(Param1, Param2);
}

FTbSame1SameEnum2InterfaceSig2Delegate& UTbSame1SameEnum2InterfaceProxy::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTbSame1SameEnum2InterfaceProxy::OnProp1Changed(const ETbSame1Enum1& InProp1)
{
	TbSame1SameEnum2InterfaceTracer::capture_state(this);
	Prop1Changed.Broadcast(InProp1);
}

ETbSame1Enum1 UTbSame1SameEnum2InterfaceProxy::GetProp1_Implementation() const
{
	return service->GetProp1();
}

void UTbSame1SameEnum2InterfaceProxy::SetProp1_Implementation(const ETbSame1Enum1& InProp1)
{
	TbSame1SameEnum2InterfaceTracer::trace_callSetProp1(InProp1);
	service->SetProp1(InProp1);
}

ETbSame1Enum1 UTbSame1SameEnum2InterfaceProxy::GetProp1_Private() const
{
	return GetProp1_Implementation();
}

void UTbSame1SameEnum2InterfaceProxy::SetProp1_Private(const ETbSame1Enum1& InProp1)
{
	service->SetProp1_Implementation(InProp1);
}

FTbSame1SameEnum2InterfaceProp1ChangedDelegate& UTbSame1SameEnum2InterfaceProxy::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbSame1SameEnum2InterfaceProxy::OnProp2Changed(const ETbSame1Enum2& InProp2)
{
	TbSame1SameEnum2InterfaceTracer::capture_state(this);
	Prop2Changed.Broadcast(InProp2);
}

ETbSame1Enum2 UTbSame1SameEnum2InterfaceProxy::GetProp2_Implementation() const
{
	return service->GetProp2();
}

void UTbSame1SameEnum2InterfaceProxy::SetProp2_Implementation(const ETbSame1Enum2& InProp2)
{
	TbSame1SameEnum2InterfaceTracer::trace_callSetProp2(InProp2);
	service->SetProp2(InProp2);
}

ETbSame1Enum2 UTbSame1SameEnum2InterfaceProxy::GetProp2_Private() const
{
	return GetProp2_Implementation();
}

void UTbSame1SameEnum2InterfaceProxy::SetProp2_Private(const ETbSame1Enum2& InProp2)
{
	service->SetProp2_Implementation(InProp2);
}

FTbSame1SameEnum2InterfaceProp2ChangedDelegate& UTbSame1SameEnum2InterfaceProxy::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTbSame1SameEnum2InterfaceProxy::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, const ETbSame1Enum1& Param1)
{
	TbSame1SameEnum2InterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameEnum2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameEnum2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame1SameEnum2InterfaceLatentAction* CompletionAction = new FTbSame1SameEnum2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = service->Func1(Param1);
				CompletionAction->Cancel();
			});
	}
}
ETbSame1Enum1 UTbSame1SameEnum2InterfaceProxy::Func1_Implementation(const ETbSame1Enum1& Param1)
{
	TbSame1SameEnum2InterfaceTracer::trace_callFunc1(Param1);
	return service->Func1(Param1);
}
void UTbSame1SameEnum2InterfaceProxy::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, const ETbSame1Enum1& Param1, const ETbSame1Enum2& Param2)
{
	TbSame1SameEnum2InterfaceTracer::trace_callFunc2(Param1, Param2);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameEnum2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameEnum2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame1SameEnum2InterfaceLatentAction* CompletionAction = new FTbSame1SameEnum2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, this, &Result, CompletionAction]()
			{
				Result = service->Func2(Param1, Param2);
				CompletionAction->Cancel();
			});
	}
}
ETbSame1Enum1 UTbSame1SameEnum2InterfaceProxy::Func2_Implementation(const ETbSame1Enum1& Param1, const ETbSame1Enum2& Param2)
{
	TbSame1SameEnum2InterfaceTracer::trace_callFunc2(Param1, Param2);
	return service->Func2(Param1, Param2);
}
