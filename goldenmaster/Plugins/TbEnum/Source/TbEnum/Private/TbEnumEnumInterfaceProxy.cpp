
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
#include "TbEnumEnumInterfaceProxy.h"
#include "EnumInterface/TbEnumEnumInterfaceLocal.h"
#include "apig/TbEnum.trace.h"
#include "TbEnumFactory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

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
UTbEnumEnumInterfaceProxy::UTbEnumEnumInterfaceProxy()
	: ITbEnumEnumInterfaceInterface()
	, Prop0(ETbEnumEnum0::VALUE0)
	, Prop1(ETbEnumEnum1::VALUE1)
	, Prop2(ETbEnumEnum2::VALUE2)
	, Prop3(ETbEnumEnum3::VALUE3)
{
	BackendService = FTbEnumModuleFactory::createITbEnumEnumInterfaceInterface();
	BackendService->GetProp0ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp0Changed);
	BackendService->GetProp1ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp1Changed);
	BackendService->GetProp2ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp2Changed);
	BackendService->GetProp3ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp3Changed);
	BackendService->GetSig0SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig0);
	BackendService->GetSig1SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig1);
	BackendService->GetSig2SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig2);
	BackendService->GetSig3SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig3);
}

UTbEnumEnumInterfaceProxy::~UTbEnumEnumInterfaceProxy()
{
	if (BackendService != nullptr)
	{
		//BackendService->GetProp0ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp0Changed);
		//BackendService->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp1Changed);
		//BackendService->GetProp2ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp2Changed);
		//BackendService->GetProp3ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp3Changed);
		//BackendService->GetSig0SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig0);
		//BackendService->GetSig1SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig1);
		//BackendService->GetSig2SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig2);
		//BackendService->GetSig3SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig3);
	}
}
void UTbEnumEnumInterfaceProxy::OnSig0(const ETbEnumEnum0& Param0)
{
	TbEnumEnumInterfaceTracer::trace_signalSig0(Param0);
	Sig0Signal.Broadcast(Param0);
}

FTbEnumEnumInterfaceSig0Delegate& UTbEnumEnumInterfaceProxy::GetSig0SignalDelegate()
{
	return Sig0Signal;
}

void UTbEnumEnumInterfaceProxy::OnSig1(const ETbEnumEnum1& Param1)
{
	TbEnumEnumInterfaceTracer::trace_signalSig1(Param1);
	Sig1Signal.Broadcast(Param1);
}

FTbEnumEnumInterfaceSig1Delegate& UTbEnumEnumInterfaceProxy::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbEnumEnumInterfaceProxy::OnSig2(const ETbEnumEnum2& Param2)
{
	TbEnumEnumInterfaceTracer::trace_signalSig2(Param2);
	Sig2Signal.Broadcast(Param2);
}

FTbEnumEnumInterfaceSig2Delegate& UTbEnumEnumInterfaceProxy::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTbEnumEnumInterfaceProxy::OnSig3(const ETbEnumEnum3& Param3)
{
	TbEnumEnumInterfaceTracer::trace_signalSig3(Param3);
	Sig3Signal.Broadcast(Param3);
}

FTbEnumEnumInterfaceSig3Delegate& UTbEnumEnumInterfaceProxy::GetSig3SignalDelegate()
{
	return Sig3Signal;
}

void UTbEnumEnumInterfaceProxy::OnProp0Changed(const ETbEnumEnum0& InProp0)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop0 = InProp0;
	Prop0Changed.Broadcast(InProp0);
}

void UTbEnumEnumInterfaceProxy::GetProp0_Implementation(ETbEnumEnum0& ReturnValue) const
{
	BackendService->Execute_GetProp0(BackendService.GetObject(), ReturnValue);
}

void UTbEnumEnumInterfaceProxy::SetProp0_Implementation(const ETbEnumEnum0& InProp0)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp0(InProp0);
	BackendService->Execute_SetProp0(BackendService.GetObject(), InProp0);
}

ETbEnumEnum0 UTbEnumEnumInterfaceProxy::GetProp0_Private() const
{
	ETbEnumEnum0 outProp0;
	Execute_GetProp0(this, outProp0);
	return outProp0;
}

void UTbEnumEnumInterfaceProxy::SetProp0_Private(const ETbEnumEnum0& InProp0)
{
	Execute_SetProp0(this, InProp0);
}

FTbEnumEnumInterfaceProp0ChangedDelegate& UTbEnumEnumInterfaceProxy::GetProp0ChangedDelegate()
{
	return Prop0Changed;
}

void UTbEnumEnumInterfaceProxy::OnProp1Changed(const ETbEnumEnum1& InProp1)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop1 = InProp1;
	Prop1Changed.Broadcast(InProp1);
}

void UTbEnumEnumInterfaceProxy::GetProp1_Implementation(ETbEnumEnum1& ReturnValue) const
{
	BackendService->Execute_GetProp1(BackendService.GetObject(), ReturnValue);
}

void UTbEnumEnumInterfaceProxy::SetProp1_Implementation(const ETbEnumEnum1& InProp1)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp1(InProp1);
	BackendService->Execute_SetProp1(BackendService.GetObject(), InProp1);
}

ETbEnumEnum1 UTbEnumEnumInterfaceProxy::GetProp1_Private() const
{
	ETbEnumEnum1 outProp1;
	Execute_GetProp1(this, outProp1);
	return outProp1;
}

void UTbEnumEnumInterfaceProxy::SetProp1_Private(const ETbEnumEnum1& InProp1)
{
	Execute_SetProp1(this, InProp1);
}

FTbEnumEnumInterfaceProp1ChangedDelegate& UTbEnumEnumInterfaceProxy::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbEnumEnumInterfaceProxy::OnProp2Changed(const ETbEnumEnum2& InProp2)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop2 = InProp2;
	Prop2Changed.Broadcast(InProp2);
}

void UTbEnumEnumInterfaceProxy::GetProp2_Implementation(ETbEnumEnum2& ReturnValue) const
{
	BackendService->Execute_GetProp2(BackendService.GetObject(), ReturnValue);
}

void UTbEnumEnumInterfaceProxy::SetProp2_Implementation(const ETbEnumEnum2& InProp2)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp2(InProp2);
	BackendService->Execute_SetProp2(BackendService.GetObject(), InProp2);
}

ETbEnumEnum2 UTbEnumEnumInterfaceProxy::GetProp2_Private() const
{
	ETbEnumEnum2 outProp2;
	Execute_GetProp2(this, outProp2);
	return outProp2;
}

void UTbEnumEnumInterfaceProxy::SetProp2_Private(const ETbEnumEnum2& InProp2)
{
	Execute_SetProp2(this, InProp2);
}

FTbEnumEnumInterfaceProp2ChangedDelegate& UTbEnumEnumInterfaceProxy::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTbEnumEnumInterfaceProxy::OnProp3Changed(const ETbEnumEnum3& InProp3)
{
	TbEnumEnumInterfaceTracer::capture_state(BackendService.GetObject(), this);
	Prop3 = InProp3;
	Prop3Changed.Broadcast(InProp3);
}

void UTbEnumEnumInterfaceProxy::GetProp3_Implementation(ETbEnumEnum3& ReturnValue) const
{
	BackendService->Execute_GetProp3(BackendService.GetObject(), ReturnValue);
}

void UTbEnumEnumInterfaceProxy::SetProp3_Implementation(const ETbEnumEnum3& InProp3)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp3(InProp3);
	BackendService->Execute_SetProp3(BackendService.GetObject(), InProp3);
}

ETbEnumEnum3 UTbEnumEnumInterfaceProxy::GetProp3_Private() const
{
	ETbEnumEnum3 outProp3;
	Execute_GetProp3(this, outProp3);
	return outProp3;
}

void UTbEnumEnumInterfaceProxy::SetProp3_Private(const ETbEnumEnum3& InProp3)
{
	Execute_SetProp3(this, InProp3);
}

FTbEnumEnumInterfaceProp3ChangedDelegate& UTbEnumEnumInterfaceProxy::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}

void UTbEnumEnumInterfaceProxy::Func0Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, const ETbEnumEnum0& Param0)
{
	TbEnumEnumInterfaceTracer::trace_callFunc0(Param0);

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
				BackendService->Execute_Func0(BackendService.GetObject(), Result, Param0);
				CompletionAction->Cancel();
			});
	}
}
void UTbEnumEnumInterfaceProxy::Func0_Implementation(ETbEnumEnum0& Result, const ETbEnumEnum0& Param0)
{
	TbEnumEnumInterfaceTracer::trace_callFunc0(Param0);
	BackendService->Execute_Func0(BackendService.GetObject(), Result, Param0);
}
void UTbEnumEnumInterfaceProxy::Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, const ETbEnumEnum1& Param1)
{
	TbEnumEnumInterfaceTracer::trace_callFunc1(Param1);

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
				BackendService->Execute_Func1(BackendService.GetObject(), Result, Param1);
				CompletionAction->Cancel();
			});
	}
}
void UTbEnumEnumInterfaceProxy::Func1_Implementation(ETbEnumEnum1& Result, const ETbEnumEnum1& Param1)
{
	TbEnumEnumInterfaceTracer::trace_callFunc1(Param1);
	BackendService->Execute_Func1(BackendService.GetObject(), Result, Param1);
}
void UTbEnumEnumInterfaceProxy::Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, const ETbEnumEnum2& Param2)
{
	TbEnumEnumInterfaceTracer::trace_callFunc2(Param2);

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
				BackendService->Execute_Func2(BackendService.GetObject(), Result, Param2);
				CompletionAction->Cancel();
			});
	}
}
void UTbEnumEnumInterfaceProxy::Func2_Implementation(ETbEnumEnum2& Result, const ETbEnumEnum2& Param2)
{
	TbEnumEnumInterfaceTracer::trace_callFunc2(Param2);
	BackendService->Execute_Func2(BackendService.GetObject(), Result, Param2);
}
void UTbEnumEnumInterfaceProxy::Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, const ETbEnumEnum3& Param3)
{
	TbEnumEnumInterfaceTracer::trace_callFunc3(Param3);

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
				BackendService->Execute_Func3(BackendService.GetObject(), Result, Param3);
				CompletionAction->Cancel();
			});
	}
}
void UTbEnumEnumInterfaceProxy::Func3_Implementation(ETbEnumEnum3& Result, const ETbEnumEnum3& Param3)
{
	TbEnumEnumInterfaceTracer::trace_callFunc3(Param3);
	BackendService->Execute_Func3(BackendService.GetObject(), Result, Param3);
}
