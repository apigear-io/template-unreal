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
#include "TbSimple/Generated/api/AbstractTbSimpleVoidInterface.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbSimpleVoidInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbSimpleVoidInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTbSimpleVoidInterface::UAbstractTbSimpleVoidInterface()
{
	TbSimpleVoidInterfaceSignals = NewObject<UTbSimpleVoidInterfaceSignals>();
}

UTbSimpleVoidInterfaceSignals* UAbstractTbSimpleVoidInterface::_GetSignals()
{
	if (!TbSimpleVoidInterfaceSignals)
	{
		TbSimpleVoidInterfaceSignals = NewObject<UTbSimpleVoidInterfaceSignals>();
	}
	return TbSimpleVoidInterfaceSignals;
}

void UAbstractTbSimpleVoidInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSimpleVoidInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSimpleVoidInterfaceSignals)
	{
		TbSimpleVoidInterfaceSignals->OnSigVoidSignal.RemoveAll(TbSimpleVoidInterfaceSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTbSimpleVoidInterface::IsInitialized() const
{
	return bInitialized;
}
