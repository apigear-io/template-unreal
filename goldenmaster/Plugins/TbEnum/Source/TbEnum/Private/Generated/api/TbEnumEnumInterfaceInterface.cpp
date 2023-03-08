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
#include "TbEnumEnumInterfaceInterface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbEnumEnumInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbEnumEnumInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

FTbEnumEnumInterfaceSig0Delegate& UAbstractTbEnumEnumInterface::GetSig0SignalDelegate()
{
	return Sig0Signal;
};

void UAbstractTbEnumEnumInterface::BroadcastSig0_Implementation(ETbEnumEnum0 Param0)
{
	Sig0Signal.Broadcast(Param0);
};

FTbEnumEnumInterfaceSig1Delegate& UAbstractTbEnumEnumInterface::GetSig1SignalDelegate()
{
	return Sig1Signal;
};

void UAbstractTbEnumEnumInterface::BroadcastSig1_Implementation(ETbEnumEnum1 Param1)
{
	Sig1Signal.Broadcast(Param1);
};

FTbEnumEnumInterfaceSig2Delegate& UAbstractTbEnumEnumInterface::GetSig2SignalDelegate()
{
	return Sig2Signal;
};

void UAbstractTbEnumEnumInterface::BroadcastSig2_Implementation(ETbEnumEnum2 Param2)
{
	Sig2Signal.Broadcast(Param2);
};

FTbEnumEnumInterfaceSig3Delegate& UAbstractTbEnumEnumInterface::GetSig3SignalDelegate()
{
	return Sig3Signal;
};

void UAbstractTbEnumEnumInterface::BroadcastSig3_Implementation(ETbEnumEnum3 Param3)
{
	Sig3Signal.Broadcast(Param3);
};

FTbEnumEnumInterfaceProp0ChangedDelegate& UAbstractTbEnumEnumInterface::GetProp0ChangedDelegate()
{
	return Prop0Changed;
};

void UAbstractTbEnumEnumInterface::BroadcastProp0Changed_Implementation(ETbEnumEnum0 InProp0)
{
	Prop0Changed.Broadcast(InProp0);
}

ETbEnumEnum0 UAbstractTbEnumEnumInterface::GetProp0_Private() const
{
	return Execute_GetProp0(this);
};

void UAbstractTbEnumEnumInterface::SetProp0_Private(ETbEnumEnum0 InProp0)
{
	Execute_SetProp0(this, InProp0);
};

FTbEnumEnumInterfaceProp1ChangedDelegate& UAbstractTbEnumEnumInterface::GetProp1ChangedDelegate()
{
	return Prop1Changed;
};

void UAbstractTbEnumEnumInterface::BroadcastProp1Changed_Implementation(ETbEnumEnum1 InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

ETbEnumEnum1 UAbstractTbEnumEnumInterface::GetProp1_Private() const
{
	return Execute_GetProp1(this);
};

void UAbstractTbEnumEnumInterface::SetProp1_Private(ETbEnumEnum1 InProp1)
{
	Execute_SetProp1(this, InProp1);
};

FTbEnumEnumInterfaceProp2ChangedDelegate& UAbstractTbEnumEnumInterface::GetProp2ChangedDelegate()
{
	return Prop2Changed;
};

void UAbstractTbEnumEnumInterface::BroadcastProp2Changed_Implementation(ETbEnumEnum2 InProp2)
{
	Prop2Changed.Broadcast(InProp2);
}

ETbEnumEnum2 UAbstractTbEnumEnumInterface::GetProp2_Private() const
{
	return Execute_GetProp2(this);
};

void UAbstractTbEnumEnumInterface::SetProp2_Private(ETbEnumEnum2 InProp2)
{
	Execute_SetProp2(this, InProp2);
};

FTbEnumEnumInterfaceProp3ChangedDelegate& UAbstractTbEnumEnumInterface::GetProp3ChangedDelegate()
{
	return Prop3Changed;
};

void UAbstractTbEnumEnumInterface::BroadcastProp3Changed_Implementation(ETbEnumEnum3 InProp3)
{
	Prop3Changed.Broadcast(InProp3);
}

ETbEnumEnum3 UAbstractTbEnumEnumInterface::GetProp3_Private() const
{
	return Execute_GetProp3(this);
};

void UAbstractTbEnumEnumInterface::SetProp3_Private(ETbEnumEnum3 InProp3)
{
	Execute_SetProp3(this, InProp3);
};
void UAbstractTbEnumEnumInterface::Func0Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbEnumEnumInterfaceLatentAction* CompletionAction = new FTbEnumEnumInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param0, this, &Result, CompletionAction]()
			{
				Result = Execute_Func0(this, Param0);
				CompletionAction->Cancel();
			});
	}
}

void UAbstractTbEnumEnumInterface::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbEnumEnumInterfaceLatentAction* CompletionAction = new FTbEnumEnumInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = Execute_Func1(this, Param1);
				CompletionAction->Cancel();
			});
	}
}

void UAbstractTbEnumEnumInterface::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbEnumEnumInterfaceLatentAction* CompletionAction = new FTbEnumEnumInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param2, this, &Result, CompletionAction]()
			{
				Result = Execute_Func2(this, Param2);
				CompletionAction->Cancel();
			});
	}
}

void UAbstractTbEnumEnumInterface::Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbEnumEnumInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbEnumEnumInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbEnumEnumInterfaceLatentAction* CompletionAction = new FTbEnumEnumInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param3, this, &Result, CompletionAction]()
			{
				Result = Execute_Func3(this, Param3);
				CompletionAction->Cancel();
			});
	}
}

void UAbstractTbEnumEnumInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbEnumEnumInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	Super::Deinitialize();
}

bool UAbstractTbEnumEnumInterface::IsInitialized() const
{
	return bInitialized;
}
