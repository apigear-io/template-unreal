
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
#include "Testbed2NestedStruct1InterfaceProxy.h"
#include "NestedStruct1Interface/Testbed2NestedStruct1InterfaceLocal.h"
#include "apig/Testbed2.trace.h"
#include "Testbed2Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

class FTestbed2NestedStruct1InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed2NestedStruct1InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTestbed2NestedStruct1InterfaceProxy::UTestbed2NestedStruct1InterfaceProxy()
	: ITestbed2NestedStruct1InterfaceInterface()
	, Prop1(FTestbed2NestedStruct1())
{
	service = FTestbed2ModuleFactory::createITestbed2NestedStruct1InterfaceInterface();
	service->GetProp1ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct1InterfaceProxy::OnProp1Changed);
	service->GetSig1SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct1InterfaceProxy::OnSig1);
}

UTestbed2NestedStruct1InterfaceProxy::~UTestbed2NestedStruct1InterfaceProxy()
{
	service->GetProp1ChangedDelegate().RemoveDynamic(this, &UTestbed2NestedStruct1InterfaceProxy::OnProp1Changed);
	service->GetSig1SignalDelegate().RemoveDynamic(this, &UTestbed2NestedStruct1InterfaceProxy::OnSig1);
}
void UTestbed2NestedStruct1InterfaceProxy::OnSig1(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct1InterfaceTracer::trace_signalSig1(Param1);
	Sig1Signal.Broadcast(Param1);
}

FTestbed2NestedStruct1InterfaceSig1Delegate& UTestbed2NestedStruct1InterfaceProxy::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTestbed2NestedStruct1InterfaceProxy::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct1InterfaceTracer::capture_state(this);
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceProxy::GetProp1_Implementation() const
{
	return service->Execute_GetProp1(service);
}

void UTestbed2NestedStruct1InterfaceProxy::SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Testbed2NestedStruct1InterfaceTracer::trace_callSetProp1(InProp1);
	service->Execute_SetProp1(service, InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceProxy::GetProp1_Private() const
{
	return Execute_GetProp1(this);
}

void UTestbed2NestedStruct1InterfaceProxy::SetProp1_Private(const FTestbed2NestedStruct1& InProp1)
{
	Execute_SetProp1(this, InProp1);
}

FTestbed2NestedStruct1InterfaceProp1ChangedDelegate& UTestbed2NestedStruct1InterfaceProxy::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTestbed2NestedStruct1InterfaceProxy::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct1InterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2NestedStruct1InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct1InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2NestedStruct1InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct1InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = service->Execute_Func1(service, Param1);
				CompletionAction->Cancel();
			});
	}
}
FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceProxy::Func1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Testbed2NestedStruct1InterfaceTracer::trace_callFunc1(Param1);
	return service->Execute_Func1(service, Param1);
}
