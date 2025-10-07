/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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
#include "TbSame1/Generated/api/TbSame1SameEnum1InterfaceBPAdapter.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

template <typename TAsyncResult>
class FTbSame1SameEnum1InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	TAtomic<bool> bCancelled{false};
	TFuture<TAsyncResult> Future;
	TAsyncResult* OutPtr;

public:
	FTbSame1SameEnum1InterfaceLatentAction(const FLatentActionInfo& LatentInfo,
		TFuture<TAsyncResult>&& InFuture,
		TAsyncResult& ResultReference)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, Future(MoveTemp(InFuture))
		, OutPtr(&ResultReference)
	{
	}

	void Cancel()
	{
		bCancelled.Store(true);
	}

	void UpdateOperation(FLatentResponse& Response) override
	{
		if (bCancelled.Load())
		{
			Response.DoneIf(true);
			return;
		}

		if (Future.IsReady())
		{
			*OutPtr = Future.Get();
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
	}

	void NotifyObjectDestroyed() override
	{
		Cancel();
	}

	void NotifyActionAborted() override
	{
		Cancel();
	}
};

void UTbSame1SameEnum1InterfaceBPAdapter::Initialize(TScriptInterface<ITbSame1SameEnum1InterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTbSame1SameEnum1InterfacePublisher* UTbSame1SameEnum1InterfaceBPAdapter::_GetPublisher()
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSame1SameEnum1InterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTbSame1SameEnum1InterfaceBPAdapter::Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSame1SameEnum1InterfaceLatentAction<ETbSame1Enum1>* oldRequest = LatentActionManager.FindExistingAction<FTbSame1SameEnum1InterfaceLatentAction<ETbSame1Enum1>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<ETbSame1Enum1> Future = Func1Async(Param1);
		FTbSame1SameEnum1InterfaceLatentAction<ETbSame1Enum1>* CompletionAction = new FTbSame1SameEnum1InterfaceLatentAction<ETbSame1Enum1>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<ETbSame1Enum1> UTbSame1SameEnum1InterfaceBPAdapter::Func1Async(ETbSame1Enum1 Param1)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param1, this]()
		{
		return Func1(Param1);
	});
}

ETbSame1Enum1 UTbSame1SameEnum1InterfaceBPAdapter::Func1(ETbSame1Enum1 Param1)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSame1SameEnum1InterfaceBPInterface::Execute_Func1(Obj, Param1);
	}
	return ETbSame1Enum1::TS1E1_Value1;
}

ETbSame1Enum1 UTbSame1SameEnum1InterfaceBPAdapter::GetProp1() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSame1SameEnum1InterfaceBPInterface::Execute_GetProp1(Obj);
	}
	return ETbSame1Enum1::TS1E1_Value1;
}
void UTbSame1SameEnum1InterfaceBPAdapter::SetProp1(ETbSame1Enum1 InProp1)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSame1SameEnum1InterfaceBPInterface::Execute_SetProp1(Obj, InProp1);
	}
}
