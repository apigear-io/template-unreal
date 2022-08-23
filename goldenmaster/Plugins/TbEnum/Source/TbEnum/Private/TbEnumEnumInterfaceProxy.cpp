
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
	service = FTbEnumModuleFactory::createITbEnumEnumInterfaceInterface();
	service->GetProp0ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp0Changed);
	service->GetProp1ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp1Changed);
	service->GetProp2ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp2Changed);
	service->GetProp3ChangedDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp3Changed);
	service->GetSig0SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig0);
	service->GetSig1SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig1);
	service->GetSig2SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig2);
	service->GetSig3SignalDelegate().AddDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig3);
}

UTbEnumEnumInterfaceProxy::~UTbEnumEnumInterfaceProxy()
{
	service->GetProp0ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp0Changed);
	service->GetProp1ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp1Changed);
	service->GetProp2ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp2Changed);
	service->GetProp3ChangedDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnProp3Changed);
	service->GetSig0SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig0);
	service->GetSig1SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig1);
	service->GetSig2SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig2);
	service->GetSig3SignalDelegate().RemoveDynamic(this, &UTbEnumEnumInterfaceProxy::OnSig3);
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
	TbEnumEnumInterfaceTracer::capture_state(this);
	Prop0Changed.Broadcast(InProp0);
}

ETbEnumEnum0 UTbEnumEnumInterfaceProxy::GetProp0() const
{
	return service->GetProp0();
}

void UTbEnumEnumInterfaceProxy::SetProp0(const ETbEnumEnum0& InProp0)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp0(InProp0);
	service->SetProp0(InProp0);
}

FTbEnumEnumInterfaceProp0ChangedDelegate& UTbEnumEnumInterfaceProxy::GetProp0ChangedDelegate()
{
	return Prop0Changed;
}

void UTbEnumEnumInterfaceProxy::OnProp1Changed(const ETbEnumEnum1& InProp1)
{
	TbEnumEnumInterfaceTracer::capture_state(this);
	Prop1Changed.Broadcast(InProp1);
}

ETbEnumEnum1 UTbEnumEnumInterfaceProxy::GetProp1() const
{
	return service->GetProp1();
}

void UTbEnumEnumInterfaceProxy::SetProp1(const ETbEnumEnum1& InProp1)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp1(InProp1);
	service->SetProp1(InProp1);
}

FTbEnumEnumInterfaceProp1ChangedDelegate& UTbEnumEnumInterfaceProxy::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbEnumEnumInterfaceProxy::OnProp2Changed(const ETbEnumEnum2& InProp2)
{
	TbEnumEnumInterfaceTracer::capture_state(this);
	Prop2Changed.Broadcast(InProp2);
}

ETbEnumEnum2 UTbEnumEnumInterfaceProxy::GetProp2() const
{
	return service->GetProp2();
}

void UTbEnumEnumInterfaceProxy::SetProp2(const ETbEnumEnum2& InProp2)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp2(InProp2);
	service->SetProp2(InProp2);
}

FTbEnumEnumInterfaceProp2ChangedDelegate& UTbEnumEnumInterfaceProxy::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTbEnumEnumInterfaceProxy::OnProp3Changed(const ETbEnumEnum3& InProp3)
{
	TbEnumEnumInterfaceTracer::capture_state(this);
	Prop3Changed.Broadcast(InProp3);
}

ETbEnumEnum3 UTbEnumEnumInterfaceProxy::GetProp3() const
{
	return service->GetProp3();
}

void UTbEnumEnumInterfaceProxy::SetProp3(const ETbEnumEnum3& InProp3)
{
	TbEnumEnumInterfaceTracer::trace_callSetProp3(InProp3);
	service->SetProp3(InProp3);
}

FTbEnumEnumInterfaceProp3ChangedDelegate& UTbEnumEnumInterfaceProxy::GetProp3ChangedDelegate()
{
	return Prop3Changed;
}

void UTbEnumEnumInterfaceProxy::Func0(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, const ETbEnumEnum0& Param0)
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
				Result = service->Func0(Param0);
				CompletionAction->Cancel();
			});
	}
}
ETbEnumEnum0 UTbEnumEnumInterfaceProxy::Func0(const ETbEnumEnum0& Param0)
{
	TbEnumEnumInterfaceTracer::trace_callFunc0(Param0);
	return service->Func0(Param0);
}
void UTbEnumEnumInterfaceProxy::Func1(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, const ETbEnumEnum1& Param1)
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
				Result = service->Func1(Param1);
				CompletionAction->Cancel();
			});
	}
}
ETbEnumEnum1 UTbEnumEnumInterfaceProxy::Func1(const ETbEnumEnum1& Param1)
{
	TbEnumEnumInterfaceTracer::trace_callFunc1(Param1);
	return service->Func1(Param1);
}
void UTbEnumEnumInterfaceProxy::Func2(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, const ETbEnumEnum2& Param2)
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
				Result = service->Func2(Param2);
				CompletionAction->Cancel();
			});
	}
}
ETbEnumEnum2 UTbEnumEnumInterfaceProxy::Func2(const ETbEnumEnum2& Param2)
{
	TbEnumEnumInterfaceTracer::trace_callFunc2(Param2);
	return service->Func2(Param2);
}
void UTbEnumEnumInterfaceProxy::Func3(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, const ETbEnumEnum3& Param3)
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
				Result = service->Func3(Param3);
				CompletionAction->Cancel();
			});
	}
}
ETbEnumEnum3 UTbEnumEnumInterfaceProxy::Func3(const ETbEnumEnum3& Param3)
{
	TbEnumEnumInterfaceTracer::trace_callFunc3(Param3);
	return service->Func3(Param3);
}
