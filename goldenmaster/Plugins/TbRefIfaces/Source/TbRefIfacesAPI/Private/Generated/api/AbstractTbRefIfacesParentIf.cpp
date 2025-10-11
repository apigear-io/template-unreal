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
#include "TbRefIfaces/Generated/api/AbstractTbRefIfacesParentIf.h"
#include "TbRefIfacesParentIfLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

UAbstractTbRefIfacesParentIf::UAbstractTbRefIfacesParentIf()
{
	TbRefIfacesParentIfPublisher = NewObject<UTbRefIfacesParentIfPublisher>();
}

UTbRefIfacesParentIfPublisher* UAbstractTbRefIfacesParentIf::_GetPublisher()
{
	if (!TbRefIfacesParentIfPublisher)
	{
		TbRefIfacesParentIfPublisher = NewObject<UTbRefIfacesParentIfPublisher>();
	}
	return TbRefIfacesParentIfPublisher;
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> UAbstractTbRefIfacesParentIf::GetLocalIf_Private() const
{
	return GetLocalIf();
};

void UAbstractTbRefIfacesParentIf::SetLocalIf_Private(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
{
	SetLocalIf(InLocalIf);
};

TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> UAbstractTbRefIfacesParentIf::GetLocalIfList_Private() const
{
	return GetLocalIfList();
};

void UAbstractTbRefIfacesParentIf::SetLocalIfList_Private(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList)
{
	SetLocalIfList(InLocalIfList);
};

TScriptInterface<ITbIfaceimportEmptyIfInterface> UAbstractTbRefIfacesParentIf::GetImportedIf_Private() const
{
	return GetImportedIf();
};

void UAbstractTbRefIfacesParentIf::SetImportedIf_Private(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf)
{
	SetImportedIf(InImportedIf);
};

TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> UAbstractTbRefIfacesParentIf::GetImportedIfList_Private() const
{
	return GetImportedIfList();
};

void UAbstractTbRefIfacesParentIf::SetImportedIfList_Private(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList)
{
	SetImportedIfList(InImportedIfList);
};

void UAbstractTbRefIfacesParentIf::LocalIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Result, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbRefIfacesParentIfLatentAction<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>* oldRequest = LatentActionManager.FindExistingAction<FTbRefIfacesParentIfLatentAction<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> Future = LocalIfMethodAsync(Param);
		FTbRefIfacesParentIfLatentAction<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>* CompletionAction = new FTbRefIfacesParentIfLatentAction<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> UAbstractTbRefIfacesParentIf::LocalIfMethodAsync(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param, this]()
		{
		return LocalIfMethod(Param);
	});
}

void UAbstractTbRefIfacesParentIf::LocalIfMethodListAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Result, const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbRefIfacesParentIfLatentAction<TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>>* oldRequest = LatentActionManager.FindExistingAction<FTbRefIfacesParentIfLatentAction<TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>> Future = LocalIfMethodListAsync(Param);
		FTbRefIfacesParentIfLatentAction<TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>>* CompletionAction = new FTbRefIfacesParentIfLatentAction<TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>> UAbstractTbRefIfacesParentIf::LocalIfMethodListAsync(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param, this]()
		{
		return LocalIfMethodList(Param);
	});
}

void UAbstractTbRefIfacesParentIf::ImportedIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbIfaceimportEmptyIfInterface>& Result, const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbRefIfacesParentIfLatentAction<TScriptInterface<ITbIfaceimportEmptyIfInterface>>* oldRequest = LatentActionManager.FindExistingAction<FTbRefIfacesParentIfLatentAction<TScriptInterface<ITbIfaceimportEmptyIfInterface>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TScriptInterface<ITbIfaceimportEmptyIfInterface>> Future = ImportedIfMethodAsync(Param);
		FTbRefIfacesParentIfLatentAction<TScriptInterface<ITbIfaceimportEmptyIfInterface>>* CompletionAction = new FTbRefIfacesParentIfLatentAction<TScriptInterface<ITbIfaceimportEmptyIfInterface>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TScriptInterface<ITbIfaceimportEmptyIfInterface>> UAbstractTbRefIfacesParentIf::ImportedIfMethodAsync(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param, this]()
		{
		return ImportedIfMethod(Param);
	});
}

void UAbstractTbRefIfacesParentIf::ImportedIfMethodListAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Result, const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FTbRefIfacesParentIfLatentAction<TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>>* oldRequest = LatentActionManager.FindExistingAction<FTbRefIfacesParentIfLatentAction<TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>> Future = ImportedIfMethodListAsync(Param);
		FTbRefIfacesParentIfLatentAction<TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>>* CompletionAction = new FTbRefIfacesParentIfLatentAction<TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>> UAbstractTbRefIfacesParentIf::ImportedIfMethodListAsync(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param, this]()
		{
		return ImportedIfMethodList(Param);
	});
}

void UAbstractTbRefIfacesParentIf::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbRefIfacesParentIf::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbRefIfacesParentIfPublisher)
	{
		TbRefIfacesParentIfPublisher->OnLocalIfSignalSignal.RemoveAll(TbRefIfacesParentIfPublisher);
		TbRefIfacesParentIfPublisher->OnLocalIfSignalSignalBP.RemoveAll(TbRefIfacesParentIfPublisher);
		TbRefIfacesParentIfPublisher->OnLocalIfSignalListSignal.RemoveAll(TbRefIfacesParentIfPublisher);
		TbRefIfacesParentIfPublisher->OnLocalIfSignalListSignalBP.RemoveAll(TbRefIfacesParentIfPublisher);
		TbRefIfacesParentIfPublisher->OnImportedIfSignalSignal.RemoveAll(TbRefIfacesParentIfPublisher);
		TbRefIfacesParentIfPublisher->OnImportedIfSignalSignalBP.RemoveAll(TbRefIfacesParentIfPublisher);
		TbRefIfacesParentIfPublisher->OnImportedIfSignalListSignal.RemoveAll(TbRefIfacesParentIfPublisher);
		TbRefIfacesParentIfPublisher->OnImportedIfSignalListSignalBP.RemoveAll(TbRefIfacesParentIfPublisher);

		TbRefIfacesParentIfPublisher->OnLocalIfChanged.RemoveAll(TbRefIfacesParentIfPublisher);
		TbRefIfacesParentIfPublisher->OnLocalIfChangedBP.RemoveAll(TbRefIfacesParentIfPublisher);
		TbRefIfacesParentIfPublisher->OnLocalIfListChanged.RemoveAll(TbRefIfacesParentIfPublisher);
		TbRefIfacesParentIfPublisher->OnLocalIfListChangedBP.RemoveAll(TbRefIfacesParentIfPublisher);
		TbRefIfacesParentIfPublisher->OnImportedIfChanged.RemoveAll(TbRefIfacesParentIfPublisher);
		TbRefIfacesParentIfPublisher->OnImportedIfChangedBP.RemoveAll(TbRefIfacesParentIfPublisher);
		TbRefIfacesParentIfPublisher->OnImportedIfListChanged.RemoveAll(TbRefIfacesParentIfPublisher);
		TbRefIfacesParentIfPublisher->OnImportedIfListChangedBP.RemoveAll(TbRefIfacesParentIfPublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbRefIfacesParentIf::IsInitialized() const
{
	return bInitialized;
}
