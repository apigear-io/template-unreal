
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
#include "Testbed2NestedStruct2InterfaceProxy.h"
#include "NestedStruct2Interface/Testbed2NestedStruct2InterfaceLocal.h"
#include "apig/Testbed2.trace.h"
#include "Testbed2Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

class FTestbed2NestedStruct2InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed2NestedStruct2InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTestbed2NestedStruct2InterfaceProxy::UTestbed2NestedStruct2InterfaceProxy()
	: ITestbed2NestedStruct2InterfaceInterface()
	, Prop1(FTestbed2NestedStruct1())
	, Prop2(FTestbed2NestedStruct2())
{
	BackendService = FTestbed2ModuleFactory::createITestbed2NestedStruct2InterfaceInterface();
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnProp2Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnSig2);
}

UTestbed2NestedStruct2InterfaceProxy::~UTestbed2NestedStruct2InterfaceProxy()
{
	if (BackendService != nullptr)
	{
		//BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnProp1Changed);
		//BackendService->GetProp2ChangedDelegate().RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnProp2Changed);
		//BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnSig1);
		//BackendService->GetSig2SignalDelegate().RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnSig2);
	}
}

void UTestbed2NestedStruct2InterfaceProxy::setBackendService(TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnProp1Changed);
		BackendService->GetProp2ChangedDelegate().RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnProp2Changed);
		BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnSig1);
		BackendService->GetSig2SignalDelegate().RemoveDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnSig2);
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnProp2Changed);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct2InterfaceProxy::OnSig2);
	// populate service state to proxy
	BackendService->Execute_GetProp1(BackendService.GetObject(), Prop1);
	BackendService->Execute_GetProp2(BackendService.GetObject(), Prop2);
}
void UTestbed2NestedStruct2InterfaceProxy::OnSig1(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct2InterfaceTracer::trace_signalSig1(Param1);
	Sig1Signal.Broadcast(Param1);
}

FTestbed2NestedStruct2InterfaceSig1Delegate& UTestbed2NestedStruct2InterfaceProxy::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTestbed2NestedStruct2InterfaceProxy::OnSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Testbed2NestedStruct2InterfaceTracer::trace_signalSig2(Param1, Param2);
	Sig2Signal.Broadcast(Param1, Param2);
}

FTestbed2NestedStruct2InterfaceSig2Delegate& UTestbed2NestedStruct2InterfaceProxy::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTestbed2NestedStruct2InterfaceProxy::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

void UTestbed2NestedStruct2InterfaceProxy::GetProp1_Implementation(FTestbed2NestedStruct1& ReturnValue) const
{
	BackendService->Execute_GetProp1(BackendService.GetObject(), ReturnValue);
}

void UTestbed2NestedStruct2InterfaceProxy::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceProxy::GetProp1_Private() const
{
	FTestbed2NestedStruct1 outProp1;
	Execute_GetProp1(this, outProp1);
	return outProp1;
}

void UTestbed2NestedStruct2InterfaceProxy::SetProp1_Private(const FTestbed2NestedStruct1& InProp1)
{
	Execute_SetProp1(this, InProp1);
}

FTestbed2NestedStruct2InterfaceProp1ChangedDelegate& UTestbed2NestedStruct2InterfaceProxy::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTestbed2NestedStruct2InterfaceProxy::OnProp2Changed(const FTestbed2NestedStruct2& InProp2)
{
	Testbed2NestedStruct2InterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Prop2Changed.Broadcast(InProp2);
}

void UTestbed2NestedStruct2InterfaceProxy::GetProp2_Implementation(FTestbed2NestedStruct2& ReturnValue) const
{
	BackendService->Execute_GetProp2(BackendService.GetObject(), ReturnValue);
}

void UTestbed2NestedStruct2InterfaceProxy::SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

FTestbed2NestedStruct2 UTestbed2NestedStruct2InterfaceProxy::GetProp2_Private() const
{
	FTestbed2NestedStruct2 outProp2;
	Execute_GetProp2(this, outProp2);
	return outProp2;
}

void UTestbed2NestedStruct2InterfaceProxy::SetProp2_Private(const FTestbed2NestedStruct2& InProp2)
{
	Execute_SetProp2(this, InProp2);
}

FTestbed2NestedStruct2InterfaceProp2ChangedDelegate& UTestbed2NestedStruct2InterfaceProxy::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTestbed2NestedStruct2InterfaceProxy::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2NestedStruct2InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				BackendService->Execute_Func1(BackendService.GetObject(), Result, Param1);
				CompletionAction->Cancel();
			});
	}
}
void UTestbed2NestedStruct2InterfaceProxy::Func1_Implementation(FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callFunc1(Param1);
	BackendService->Execute_Func1(BackendService.GetObject(), Result, Param1);
}
void UTestbed2NestedStruct2InterfaceProxy::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callFunc2(Param1, Param2);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct2InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct2InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2NestedStruct2InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct2InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, this, &Result, CompletionAction]()
			{
				BackendService->Execute_Func2(BackendService.GetObject(), Result, Param1, Param2);
				CompletionAction->Cancel();
			});
	}
}
void UTestbed2NestedStruct2InterfaceProxy::Func2_Implementation(FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Testbed2NestedStruct2InterfaceTracer::trace_callFunc2(Param1, Param2);
	BackendService->Execute_Func2(BackendService.GetObject(), Result, Param1, Param2);
}
