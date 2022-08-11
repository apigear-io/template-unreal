
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
#include "Testbed2NestedStruct3InterfaceProxy.h"
#include "NestedStruct3Interface/Testbed2NestedStruct3InterfaceLocal.h"
#include "apig/Testbed2.trace.h"
#include "Testbed2Factory.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTestbed2NestedStruct3InterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed2NestedStruct3InterfaceLatentAction(const FLatentActionInfo& LatentInfo)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, bInProgress(true)
	{
	}

    void Cancel() {
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
UTestbed2NestedStruct3InterfaceProxy::UTestbed2NestedStruct3InterfaceProxy()
    : ITestbed2NestedStruct3InterfaceInterface()
    , Prop1(FTestbed2NestedStruct1())
    , Prop2(FTestbed2NestedStruct2())
    , Prop3(FTestbed2NestedStruct3())
{
    service = FTestbed2ModuleFactory::createITestbed2NestedStruct3InterfaceInterface();
    service->GetProp1ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceProxy::OnProp1Changed);
    service->GetProp2ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceProxy::OnProp2Changed);
    service->GetProp3ChangedDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceProxy::OnProp3Changed);
    service->GetSig1SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceProxy::OnSig1);
    service->GetSig2SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceProxy::OnSig2);
    service->GetSig3SignalDelegate().AddDynamic(this, &UTestbed2NestedStruct3InterfaceProxy::OnSig3);
}

UTestbed2NestedStruct3InterfaceProxy::~UTestbed2NestedStruct3InterfaceProxy()
{
    service->GetProp1ChangedDelegate().RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceProxy::OnProp1Changed);
    service->GetProp2ChangedDelegate().RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceProxy::OnProp2Changed);
    service->GetProp3ChangedDelegate().RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceProxy::OnProp3Changed);
    service->GetSig1SignalDelegate().RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceProxy::OnSig1);
    service->GetSig2SignalDelegate().RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceProxy::OnSig2);
    service->GetSig3SignalDelegate().RemoveDynamic(this, &UTestbed2NestedStruct3InterfaceProxy::OnSig3);
}
void UTestbed2NestedStruct3InterfaceProxy::OnSig1(const FTestbed2NestedStruct1& Param1)
{
    Testbed2NestedStruct3InterfaceTracer::trace_signalSig1(Param1);
    Sig1Signal.Broadcast(Param1);
}

FTestbed2NestedStruct3InterfaceSig1Delegate& UTestbed2NestedStruct3InterfaceProxy::GetSig1SignalDelegate()
{
    return Sig1Signal;
}

void UTestbed2NestedStruct3InterfaceProxy::OnSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
    Testbed2NestedStruct3InterfaceTracer::trace_signalSig2(Param1,Param2);
    Sig2Signal.Broadcast(Param1,Param2);
}

FTestbed2NestedStruct3InterfaceSig2Delegate& UTestbed2NestedStruct3InterfaceProxy::GetSig2SignalDelegate()
{
    return Sig2Signal;
}

void UTestbed2NestedStruct3InterfaceProxy::OnSig3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
    Testbed2NestedStruct3InterfaceTracer::trace_signalSig3(Param1,Param2,Param3);
    Sig3Signal.Broadcast(Param1,Param2,Param3);
}

FTestbed2NestedStruct3InterfaceSig3Delegate& UTestbed2NestedStruct3InterfaceProxy::GetSig3SignalDelegate()
{
    return Sig3Signal;
}

void UTestbed2NestedStruct3InterfaceProxy::OnProp1Changed(const FTestbed2NestedStruct1& InProp1)
{
    Testbed2NestedStruct3InterfaceTracer::capture_state(this);
    Prop1Changed.Broadcast(InProp1);
}

FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceProxy::GetProp1() const
{
    return service->GetProp1();
}

void UTestbed2NestedStruct3InterfaceProxy::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
    Testbed2NestedStruct3InterfaceTracer::trace_callSetProp1(InProp1);
    service->SetProp1(InProp1);
}

FTestbed2NestedStruct3InterfaceProp1ChangedDelegate& UTestbed2NestedStruct3InterfaceProxy::GetProp1ChangedDelegate()
{
    return Prop1Changed;
}

void UTestbed2NestedStruct3InterfaceProxy::OnProp2Changed(const FTestbed2NestedStruct2& InProp2)
{
    Testbed2NestedStruct3InterfaceTracer::capture_state(this);
    Prop2Changed.Broadcast(InProp2);
}

FTestbed2NestedStruct2 UTestbed2NestedStruct3InterfaceProxy::GetProp2() const
{
    return service->GetProp2();
}

void UTestbed2NestedStruct3InterfaceProxy::SetProp2(const FTestbed2NestedStruct2& InProp2)
{
    Testbed2NestedStruct3InterfaceTracer::trace_callSetProp2(InProp2);
    service->SetProp2(InProp2);
}

FTestbed2NestedStruct3InterfaceProp2ChangedDelegate& UTestbed2NestedStruct3InterfaceProxy::GetProp2ChangedDelegate()
{
    return Prop2Changed;
}

void UTestbed2NestedStruct3InterfaceProxy::OnProp3Changed(const FTestbed2NestedStruct3& InProp3)
{
    Testbed2NestedStruct3InterfaceTracer::capture_state(this);
    Prop3Changed.Broadcast(InProp3);
}

FTestbed2NestedStruct3 UTestbed2NestedStruct3InterfaceProxy::GetProp3() const
{
    return service->GetProp3();
}

void UTestbed2NestedStruct3InterfaceProxy::SetProp3(const FTestbed2NestedStruct3& InProp3)
{
    Testbed2NestedStruct3InterfaceTracer::trace_callSetProp3(InProp3);
    service->SetProp3(InProp3);
}

FTestbed2NestedStruct3InterfaceProp3ChangedDelegate& UTestbed2NestedStruct3InterfaceProxy::GetProp3ChangedDelegate()
{
    return Prop3Changed;
}

void UTestbed2NestedStruct3InterfaceProxy::Func1(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result,const FTestbed2NestedStruct1& Param1)
{
    Testbed2NestedStruct3InterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
        FTestbed2NestedStruct3InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct3InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		
        if (oldRequest != nullptr)
		{
            // cancel old request
            oldRequest->Cancel();
            LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
        }

		FTestbed2NestedStruct3InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct3InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
        Async(EAsyncExecution::Thread, [Param1,this, &Result, CompletionAction]()
        {
            Result = service->Func1(Param1);
            CompletionAction->Cancel();
        });
	}
}
FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceProxy::Func1(const FTestbed2NestedStruct1& Param1)
{
    Testbed2NestedStruct3InterfaceTracer::trace_callFunc1(Param1);
    return service->Func1(Param1);
}
void UTestbed2NestedStruct3InterfaceProxy::Func2(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result,const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
    Testbed2NestedStruct3InterfaceTracer::trace_callFunc2(Param1,Param2);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
        FTestbed2NestedStruct3InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct3InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		
        if (oldRequest != nullptr)
		{
            // cancel old request
            oldRequest->Cancel();
            LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
        }

		FTestbed2NestedStruct3InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct3InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
        Async(EAsyncExecution::Thread, [Param1,Param2,this, &Result, CompletionAction]()
        {
            Result = service->Func2(Param1,Param2);
            CompletionAction->Cancel();
        });
	}
}
FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceProxy::Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
    Testbed2NestedStruct3InterfaceTracer::trace_callFunc2(Param1,Param2);
    return service->Func2(Param1,Param2);
}
void UTestbed2NestedStruct3InterfaceProxy::Func3(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result,const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
    Testbed2NestedStruct3InterfaceTracer::trace_callFunc3(Param1,Param2,Param3);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
        FTestbed2NestedStruct3InterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2NestedStruct3InterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		
        if (oldRequest != nullptr)
		{
            // cancel old request
            oldRequest->Cancel();
            LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
        }

		FTestbed2NestedStruct3InterfaceLatentAction* CompletionAction = new FTestbed2NestedStruct3InterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
        Async(EAsyncExecution::Thread, [Param1,Param2,Param3,this, &Result, CompletionAction]()
        {
            Result = service->Func3(Param1,Param2,Param3);
            CompletionAction->Cancel();
        });
	}
}
FTestbed2NestedStruct1 UTestbed2NestedStruct3InterfaceProxy::Func3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
    Testbed2NestedStruct3InterfaceTracer::trace_callFunc3(Param1,Param2,Param3);
    return service->Func3(Param1,Param2,Param3);
}
