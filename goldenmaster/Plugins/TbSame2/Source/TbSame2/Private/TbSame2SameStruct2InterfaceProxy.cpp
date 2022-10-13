
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
#include "TbSame2SameStruct2InterfaceProxy.h"
#include "SameStruct2Interface/TbSame2SameStruct2InterfaceLocal.h"
#include "apig/TbSame2.trace.h"
#include "TbSame2Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

class FTbSame2SameStruct2InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSame2SameStruct2InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTbSame2SameStruct2InterfaceProxy::UTbSame2SameStruct2InterfaceProxy()
	: ITbSame2SameStruct2InterfaceInterface()
	, Prop1(FTbSame2Struct2())
	, Prop2(FTbSame2Struct2())
{
	service = FTbSame2ModuleFactory::createITbSame2SameStruct2InterfaceInterface();
	service->GetProp1ChangedDelegate().AddDynamic(this, &UTbSame2SameStruct2InterfaceProxy::OnProp1Changed);
	service->GetProp2ChangedDelegate().AddDynamic(this, &UTbSame2SameStruct2InterfaceProxy::OnProp2Changed);
	service->GetSig1SignalDelegate().AddDynamic(this, &UTbSame2SameStruct2InterfaceProxy::OnSig1);
	service->GetSig2SignalDelegate().AddDynamic(this, &UTbSame2SameStruct2InterfaceProxy::OnSig2);
}

UTbSame2SameStruct2InterfaceProxy::~UTbSame2SameStruct2InterfaceProxy()
{
	service->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbSame2SameStruct2InterfaceProxy::OnProp1Changed);
	service->GetProp2ChangedDelegate().RemoveDynamic(this, &UTbSame2SameStruct2InterfaceProxy::OnProp2Changed);
	service->GetSig1SignalDelegate().RemoveDynamic(this, &UTbSame2SameStruct2InterfaceProxy::OnSig1);
	service->GetSig2SignalDelegate().RemoveDynamic(this, &UTbSame2SameStruct2InterfaceProxy::OnSig2);
}
void UTbSame2SameStruct2InterfaceProxy::OnSig1(const FTbSame2Struct1& Param1)
{
	TbSame2SameStruct2InterfaceTracer::trace_signalSig1(Param1);
	Sig1Signal.Broadcast(Param1);
}

FTbSame2SameStruct2InterfaceSig1Delegate& UTbSame2SameStruct2InterfaceProxy::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame2SameStruct2InterfaceProxy::OnSig2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	TbSame2SameStruct2InterfaceTracer::trace_signalSig2(Param1, Param2);
	Sig2Signal.Broadcast(Param1, Param2);
}

FTbSame2SameStruct2InterfaceSig2Delegate& UTbSame2SameStruct2InterfaceProxy::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTbSame2SameStruct2InterfaceProxy::OnProp1Changed(const FTbSame2Struct2& InProp1)
{
	TbSame2SameStruct2InterfaceTracer::capture_state(this);
	Prop1Changed.Broadcast(InProp1);
}

FTbSame2Struct2 UTbSame2SameStruct2InterfaceProxy::GetProp1() const
{
	return service->GetProp1();
}

void UTbSame2SameStruct2InterfaceProxy::SetProp1(const FTbSame2Struct2& InProp1)
{
	TbSame2SameStruct2InterfaceTracer::trace_callSetProp1(InProp1);
	service->SetProp1(InProp1);
}

FTbSame2SameStruct2InterfaceProp1ChangedDelegate& UTbSame2SameStruct2InterfaceProxy::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbSame2SameStruct2InterfaceProxy::OnProp2Changed(const FTbSame2Struct2& InProp2)
{
	TbSame2SameStruct2InterfaceTracer::capture_state(this);
	Prop2Changed.Broadcast(InProp2);
}

FTbSame2Struct2 UTbSame2SameStruct2InterfaceProxy::GetProp2() const
{
	return service->GetProp2();
}

void UTbSame2SameStruct2InterfaceProxy::SetProp2(const FTbSame2Struct2& InProp2)
{
	TbSame2SameStruct2InterfaceTracer::trace_callSetProp2(InProp2);
	service->SetProp2(InProp2);
}

FTbSame2SameStruct2InterfaceProp2ChangedDelegate& UTbSame2SameStruct2InterfaceProxy::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTbSame2SameStruct2InterfaceProxy::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1)
{
	TbSame2SameStruct2InterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameStruct2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameStruct2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame2SameStruct2InterfaceLatentAction* CompletionAction = new FTbSame2SameStruct2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = service->Func1(Param1);
				CompletionAction->Cancel();
			});
	}
}
FTbSame2Struct1 UTbSame2SameStruct2InterfaceProxy::Func1(const FTbSame2Struct1& Param1)
{
	TbSame2SameStruct2InterfaceTracer::trace_callFunc1(Param1);
	return service->Func1(Param1);
}
void UTbSame2SameStruct2InterfaceProxy::Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	TbSame2SameStruct2InterfaceTracer::trace_callFunc2(Param1, Param2);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame2SameStruct2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSame2SameStruct2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSame2SameStruct2InterfaceLatentAction* CompletionAction = new FTbSame2SameStruct2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, this, &Result, CompletionAction]()
			{
				Result = service->Func2(Param1, Param2);
				CompletionAction->Cancel();
			});
	}
}
FTbSame2Struct1 UTbSame2SameStruct2InterfaceProxy::Func2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	TbSame2SameStruct2InterfaceTracer::trace_callFunc2(Param1, Param2);
	return service->Func2(Param1, Param2);
}
