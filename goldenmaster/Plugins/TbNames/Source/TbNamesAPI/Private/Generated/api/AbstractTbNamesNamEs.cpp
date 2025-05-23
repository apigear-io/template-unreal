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
#include "TbNames/Generated/api/AbstractTbNamesNamEs.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FTbNamesNamEsLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTbNamesNamEsLatentAction(const FLatentActionInfo& LatentInfo)
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

UAbstractTbNamesNamEs::UAbstractTbNamesNamEs()
{
	TbNamesNamEsSignals = NewObject<UTbNamesNamEsSignals>();
}

UTbNamesNamEsSignals* UAbstractTbNamesNamEs::_GetSignals()
{
	if (!TbNamesNamEsSignals)
	{
		TbNamesNamEsSignals = NewObject<UTbNamesNamEsSignals>();
	}
	return TbNamesNamEsSignals;
}

bool UAbstractTbNamesNamEs::GetSwitch_Private() const
{
	return GetSwitch();
};

void UAbstractTbNamesNamEs::SetSwitch_Private(bool bInSwitch)
{
	SetSwitch(bInSwitch);
};

int32 UAbstractTbNamesNamEs::GetSomeProperty_Private() const
{
	return GetSomeProperty();
};

void UAbstractTbNamesNamEs::SetSomeProperty_Private(int32 InSomeProperty)
{
	SetSomeProperty(InSomeProperty);
};

int32 UAbstractTbNamesNamEs::GetSomePoperty2_Private() const
{
	return GetSomePoperty2();
};

void UAbstractTbNamesNamEs::SetSomePoperty2_Private(int32 InSomePoperty2)
{
	SetSomePoperty2(InSomePoperty2);
};

ETbNamesEnum_With_Under_scores UAbstractTbNamesNamEs::GetEnumProperty_Private() const
{
	return GetEnumProperty();
};

void UAbstractTbNamesNamEs::SetEnumProperty_Private(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	SetEnumProperty(InEnumProperty);
};

void UAbstractTbNamesNamEs::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbNamesNamEs::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbNamesNamEsSignals)
	{
		TbNamesNamEsSignals->OnSomeSignalSignal.RemoveAll(TbNamesNamEsSignals);
		TbNamesNamEsSignals->OnSomeSignalSignalBP.RemoveAll(TbNamesNamEsSignals);
		TbNamesNamEsSignals->OnSomeSignal2Signal.RemoveAll(TbNamesNamEsSignals);
		TbNamesNamEsSignals->OnSomeSignal2SignalBP.RemoveAll(TbNamesNamEsSignals);

		TbNamesNamEsSignals->OnSwitchChanged.RemoveAll(TbNamesNamEsSignals);
		TbNamesNamEsSignals->OnSwitchChangedBP.RemoveAll(TbNamesNamEsSignals);
		TbNamesNamEsSignals->OnSomePropertyChanged.RemoveAll(TbNamesNamEsSignals);
		TbNamesNamEsSignals->OnSomePropertyChangedBP.RemoveAll(TbNamesNamEsSignals);
		TbNamesNamEsSignals->OnSomePoperty2Changed.RemoveAll(TbNamesNamEsSignals);
		TbNamesNamEsSignals->OnSomePoperty2ChangedBP.RemoveAll(TbNamesNamEsSignals);
		TbNamesNamEsSignals->OnEnumPropertyChanged.RemoveAll(TbNamesNamEsSignals);
		TbNamesNamEsSignals->OnEnumPropertyChangedBP.RemoveAll(TbNamesNamEsSignals);
	}

	Super::Deinitialize();
}

bool UAbstractTbNamesNamEs::IsInitialized() const
{
	return bInitialized;
}
