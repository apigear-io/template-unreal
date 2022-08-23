
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
#include "TbSimpleSimpleArrayInterfaceProxy.h"
#include "SimpleArrayInterface/TbSimpleSimpleArrayInterfaceLocal.h"
#include "apig/TbSimple.trace.h"
#include "TbSimpleFactory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

class FTbSimpleSimpleArrayInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSimpleSimpleArrayInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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
UTbSimpleSimpleArrayInterfaceProxy::UTbSimpleSimpleArrayInterfaceProxy()
	: ITbSimpleSimpleArrayInterfaceInterface()
	, PropBool(TArray<bool>())
	, PropInt(TArray<int32>())
	, PropFloat(TArray<float>())
	, PropString(TArray<FString>())
{
	service = FTbSimpleModuleFactory::createITbSimpleSimpleArrayInterfaceInterface();
	service->GetPropBoolChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropBoolChanged);
	service->GetPropIntChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropIntChanged);
	service->GetPropFloatChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropFloatChanged);
	service->GetPropStringChangedDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropStringChanged);
	service->GetSigBoolSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigBool);
	service->GetSigIntSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigInt);
	service->GetSigFloatSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigFloat);
	service->GetSigStringSignalDelegate().AddDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigString);
}

UTbSimpleSimpleArrayInterfaceProxy::~UTbSimpleSimpleArrayInterfaceProxy()
{
	service->GetPropBoolChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropBoolChanged);
	service->GetPropIntChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropIntChanged);
	service->GetPropFloatChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropFloatChanged);
	service->GetPropStringChangedDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnPropStringChanged);
	service->GetSigBoolSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigBool);
	service->GetSigIntSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigInt);
	service->GetSigFloatSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigFloat);
	service->GetSigStringSignalDelegate().RemoveDynamic(this, &UTbSimpleSimpleArrayInterfaceProxy::OnSigString);
}
void UTbSimpleSimpleArrayInterfaceProxy::OnSigBool(const TArray<bool>& ParamBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigBool(ParamBool);
	SigBoolSignal.Broadcast(ParamBool);
}

FTbSimpleSimpleArrayInterfaceSigBoolDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTbSimpleSimpleArrayInterfaceProxy::OnSigInt(const TArray<int32>& ParamInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigInt(ParamInt);
	SigIntSignal.Broadcast(ParamInt);
}

FTbSimpleSimpleArrayInterfaceSigIntDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTbSimpleSimpleArrayInterfaceProxy::OnSigFloat(const TArray<float>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigFloat(ParamFloat);
	SigFloatSignal.Broadcast(ParamFloat);
}

FTbSimpleSimpleArrayInterfaceSigFloatDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTbSimpleSimpleArrayInterfaceProxy::OnSigString(const TArray<FString>& ParamString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_signalSigString(ParamString);
	SigStringSignal.Broadcast(ParamString);
}

FTbSimpleSimpleArrayInterfaceSigStringDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTbSimpleSimpleArrayInterfaceProxy::OnPropBoolChanged(const TArray<bool>& InPropBool)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(this);
	PropBoolChanged.Broadcast(InPropBool);
}

TArray<bool> UTbSimpleSimpleArrayInterfaceProxy::GetPropBool() const
{
	return service->GetPropBool();
}

void UTbSimpleSimpleArrayInterfaceProxy::SetPropBool(const TArray<bool>& InPropBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropBool(InPropBool);
	service->SetPropBool(InPropBool);
}

FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTbSimpleSimpleArrayInterfaceProxy::OnPropIntChanged(const TArray<int32>& InPropInt)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(this);
	PropIntChanged.Broadcast(InPropInt);
}

TArray<int32> UTbSimpleSimpleArrayInterfaceProxy::GetPropInt() const
{
	return service->GetPropInt();
}

void UTbSimpleSimpleArrayInterfaceProxy::SetPropInt(const TArray<int32>& InPropInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropInt(InPropInt);
	service->SetPropInt(InPropInt);
}

FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTbSimpleSimpleArrayInterfaceProxy::OnPropFloatChanged(const TArray<float>& InPropFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(this);
	PropFloatChanged.Broadcast(InPropFloat);
}

TArray<float> UTbSimpleSimpleArrayInterfaceProxy::GetPropFloat() const
{
	return service->GetPropFloat();
}

void UTbSimpleSimpleArrayInterfaceProxy::SetPropFloat(const TArray<float>& InPropFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropFloat(InPropFloat);
	service->SetPropFloat(InPropFloat);
}

FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTbSimpleSimpleArrayInterfaceProxy::OnPropStringChanged(const TArray<FString>& InPropString)
{
	TbSimpleSimpleArrayInterfaceTracer::capture_state(this);
	PropStringChanged.Broadcast(InPropString);
}

TArray<FString> UTbSimpleSimpleArrayInterfaceProxy::GetPropString() const
{
	return service->GetPropString();
}

void UTbSimpleSimpleArrayInterfaceProxy::SetPropString(const TArray<FString>& InPropString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropString(InPropString);
	service->SetPropString(InPropString);
}

FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& UTbSimpleSimpleArrayInterfaceProxy::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

void UTbSimpleSimpleArrayInterfaceProxy::FuncBool(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncBool(ParamBool);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamBool, this, &Result, CompletionAction]()
			{
				Result = service->FuncBool(ParamBool);
				CompletionAction->Cancel();
			});
	}
}
TArray<bool> UTbSimpleSimpleArrayInterfaceProxy::FuncBool(const TArray<bool>& ParamBool)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncBool(ParamBool);
	return service->FuncBool(ParamBool);
}
void UTbSimpleSimpleArrayInterfaceProxy::FuncInt(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt(ParamInt);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamInt, this, &Result, CompletionAction]()
			{
				Result = service->FuncInt(ParamInt);
				CompletionAction->Cancel();
			});
	}
}
TArray<int32> UTbSimpleSimpleArrayInterfaceProxy::FuncInt(const TArray<int32>& ParamInt)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt(ParamInt);
	return service->FuncInt(ParamInt);
}
void UTbSimpleSimpleArrayInterfaceProxy::FuncFloat(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat(ParamFloat);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamFloat, this, &Result, CompletionAction]()
			{
				Result = service->FuncFloat(ParamFloat);
				CompletionAction->Cancel();
			});
	}
}
TArray<float> UTbSimpleSimpleArrayInterfaceProxy::FuncFloat(const TArray<float>& ParamFloat)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat(ParamFloat);
	return service->FuncFloat(ParamFloat);
}
void UTbSimpleSimpleArrayInterfaceProxy::FuncString(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncString(ParamString);

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbSimpleSimpleArrayInterfaceLatentAction* oldRequest = LatentActionManager.FindExistingAction<FTbSimpleSimpleArrayInterfaceLatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		FTbSimpleSimpleArrayInterfaceLatentAction* CompletionAction = new FTbSimpleSimpleArrayInterfaceLatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[ParamString, this, &Result, CompletionAction]()
			{
				Result = service->FuncString(ParamString);
				CompletionAction->Cancel();
			});
	}
}
TArray<FString> UTbSimpleSimpleArrayInterfaceProxy::FuncString(const TArray<FString>& ParamString)
{
	TbSimpleSimpleArrayInterfaceTracer::trace_callFuncString(ParamString);
	return service->FuncString(ParamString);
}
