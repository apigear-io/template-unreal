
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
#include "Testbed2ManyParamInterfaceProxy.h"
#include "ManyParamInterface/Testbed2ManyParamInterfaceLocal.h"
#include "apig/Testbed2.trace.h"
#include "Testbed2Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

class FTestbed2ManyParamInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed2ManyParamInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTestbed2ManyParamInterfaceProxy::UTestbed2ManyParamInterfaceProxy()
	: ITestbed2ManyParamInterfaceInterface()
	, Prop1(0)
	, Prop2(0)
	, Prop3(0)
	, Prop4(0)
{
	service = FTestbed2ModuleFactory::createITestbed2ManyParamInterfaceInterface();
	service->GetProp1ChangedDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnProp1Changed);
	service->GetProp2ChangedDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnProp2Changed);
	service->GetProp3ChangedDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnProp3Changed);
	service->GetProp4ChangedDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnProp4Changed);
	service->GetSig1SignalDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnSig1);
	service->GetSig2SignalDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnSig2);
	service->GetSig3SignalDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnSig3);
	service->GetSig4SignalDelegate().AddDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnSig4);
}

UTestbed2ManyParamInterfaceProxy::~UTestbed2ManyParamInterfaceProxy()
{
	service->GetProp1ChangedDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnProp1Changed);
	service->GetProp2ChangedDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnProp2Changed);
	service->GetProp3ChangedDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnProp3Changed);
	service->GetProp4ChangedDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnProp4Changed);
	service->GetSig1SignalDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnSig1);
	service->GetSig2SignalDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnSig2);
	service->GetSig3SignalDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnSig3);
	service->GetSig4SignalDelegate().RemoveDynamic(this, &UTestbed2ManyParamInterfaceProxy::OnSig4);
}
void UTestbed2ManyParamInterfaceProxy::OnSig1(int32 Param1)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig1(Param1);
	Sig1Signal.Broadcast(Param1);
}

FTestbed2ManyParamInterfaceSig1Delegate& UTestbed2ManyParamInterfaceProxy::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTestbed2ManyParamInterfaceProxy::OnSig2(int32 Param1, int32 Param2)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig2(Param1, Param2);
	Sig2Signal.Broadcast(Param1, Param2);
}

FTestbed2ManyParamInterfaceSig2Delegate& UTestbed2ManyParamInterfaceProxy::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTestbed2ManyParamInterfaceProxy::OnSig3(int32 Param1, int32 Param2, int32 Param3)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig3(Param1, Param2, Param3);
	Sig3Signal.Broadcast(Param1, Param2, Param3);
}

FTestbed2ManyParamInterfaceSig3Delegate& UTestbed2ManyParamInterfaceProxy::GetSig3SignalDelegate()
{
	return Sig3Signal;
}

void UTestbed2ManyParamInterfaceProxy::OnSig4(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Testbed2ManyParamInterfaceTracer::trace_signalSig4(Param1, Param2, Param3, Param4);
	Sig4Signal.Broadcast(Param1, Param2, Param3, Param4);
}

FTestbed2ManyParamInterfaceSig4Delegate& UTestbed2ManyParamInterfaceProxy::GetSig4SignalDelegate()
{
	return Sig4Signal;
}

void UTestbed2ManyParamInterfaceProxy::OnProp1Changed(int32 InProp1)
{
	Testbed2ManyParamInterfaceTracer::capture_state(this);
	Prop1Changed.Broadcast(InProp1);
}

int32 UTestbed2ManyParamInterfaceProxy::GetProp1_Implementation() const
{
	return service->GetProp1();
}

void UTestbed2ManyParamInterfaceProxy::SetProp1_Implementation(int32 InProp1)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp1(InProp1);
	service->SetProp1(InProp1);
}

int32 UTestbed2ManyParamInterfaceProxy::GetProp1_Private() const
{
	return GetProp1_Implementation();
}

void UTestbed2ManyParamInterfaceProxy::SetProp1_Private(int32 InProp1)
{
	service->SetProp1_Implementation(InProp1);
}

FTestbed2ManyParamInterfaceProp1ChangedDelegate& UTestbed2ManyParamInterfaceProxy::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTestbed2ManyParamInterfaceProxy::OnProp2Changed(int32 InProp2)
{
	Testbed2ManyParamInterfaceTracer::capture_state(this);
	Prop2Changed.Broadcast(InProp2);
}

int32 UTestbed2ManyParamInterfaceProxy::GetProp2_Implementation() const
{
	return service->GetProp2();
}

void UTestbed2ManyParamInterfaceProxy::SetProp2_Implementation(int32 InProp2)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp2(InProp2);
	service->SetProp2(InProp2);
}

int32 UTestbed2ManyParamInterfaceProxy::GetProp2_Private() const
{
	return GetProp2_Implementation();
}

void UTestbed2ManyParamInterfaceProxy::SetProp2_Private(int32 InProp2)
{
	service->SetProp2_Implementation(InProp2);
}

FTestbed2ManyParamInterfaceProp2ChangedDelegate& UTestbed2ManyParamInterfaceProxy::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTestbed2ManyParamInterfaceProxy::OnProp3Changed(int32 InProp3)
{
	Testbed2ManyParamInterfaceTracer::capture_state(this);
	Prop3Changed.Broadcast(InProp3);
}

int32 UTestbed2ManyParamInterfaceProxy::GetProp3_Implementation() const
{
	return service->GetProp3();
}

void UTestbed2ManyParamInterfaceProxy::SetProp3_Implementation(int32 InProp3)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp3(InProp3);
	service->SetProp3(InProp3);
}

int32 UTestbed2ManyParamInterfaceProxy::GetProp3_Private() const
{
	return GetProp3_Implementation();
}

void UTestbed2ManyParamInterfaceProxy::SetProp3_Private(int32 InProp3)
{
	service->SetProp3_Implementation(InProp3);
}

FTestbed2ManyParamInterfaceProp3ChangedDelegate& UTestbed2ManyParamInterfaceProxy::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}

void UTestbed2ManyParamInterfaceProxy::OnProp4Changed(int32 InProp4)
{
	Testbed2ManyParamInterfaceTracer::capture_state(this);
	Prop4Changed.Broadcast(InProp4);
}

int32 UTestbed2ManyParamInterfaceProxy::GetProp4_Implementation() const
{
	return service->GetProp4();
}

void UTestbed2ManyParamInterfaceProxy::SetProp4_Implementation(int32 InProp4)
{
	Testbed2ManyParamInterfaceTracer::trace_callSetProp4(InProp4);
	service->SetProp4(InProp4);
}

int32 UTestbed2ManyParamInterfaceProxy::GetProp4_Private() const
{
	return GetProp4_Implementation();
}

void UTestbed2ManyParamInterfaceProxy::SetProp4_Private(int32 InProp4)
{
	service->SetProp4_Implementation(InProp4);
}

FTestbed2ManyParamInterfaceProp4ChangedDelegate& UTestbed2ManyParamInterfaceProxy::GetProp4ChangedDelegate()
{
	return Prop4Changed;
}

void UTestbed2ManyParamInterfaceProxy::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc1(Param1);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2ManyParamInterfaceLatentAction* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, this, &Result, CompletionAction]()
			{
				Result = service->Func1(Param1);
				CompletionAction->Cancel();
			});
	}
}
int32 UTestbed2ManyParamInterfaceProxy::Func1_Implementation(int32 Param1)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc1(Param1);
	return service->Func1(Param1);
}
void UTestbed2ManyParamInterfaceProxy::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc2(Param1, Param2);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2ManyParamInterfaceLatentAction* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, this, &Result, CompletionAction]()
			{
				Result = service->Func2(Param1, Param2);
				CompletionAction->Cancel();
			});
	}
}
int32 UTestbed2ManyParamInterfaceProxy::Func2_Implementation(int32 Param1, int32 Param2)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc2(Param1, Param2);
	return service->Func2(Param1, Param2);
}
void UTestbed2ManyParamInterfaceProxy::Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc3(Param1, Param2, Param3);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2ManyParamInterfaceLatentAction* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, Param3, this, &Result, CompletionAction]()
			{
				Result = service->Func3(Param1, Param2, Param3);
				CompletionAction->Cancel();
			});
	}
}
int32 UTestbed2ManyParamInterfaceProxy::Func3_Implementation(int32 Param1, int32 Param2, int32 Param3)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc3(Param1, Param2, Param3);
	return service->Func3(Param1, Param2, Param3);
}
void UTestbed2ManyParamInterfaceProxy::Func4Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc4(Param1, Param2, Param3, Param4);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTestbed2ManyParamInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTestbed2ManyParamInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTestbed2ManyParamInterfaceLatentAction* CompletionAction = new FTestbed2ManyParamInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[Param1, Param2, Param3, Param4, this, &Result, CompletionAction]()
			{
				Result = service->Func4(Param1, Param2, Param3, Param4);
				CompletionAction->Cancel();
			});
	}
}
int32 UTestbed2ManyParamInterfaceProxy::Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Testbed2ManyParamInterfaceTracer::trace_callFunc4(Param1, Param2, Param3, Param4);
	return service->Func4(Param1, Param2, Param3, Param4);
}
