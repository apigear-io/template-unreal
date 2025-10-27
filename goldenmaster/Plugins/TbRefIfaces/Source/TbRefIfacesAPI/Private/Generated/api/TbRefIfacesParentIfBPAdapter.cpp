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
#include "TbRefIfaces/Generated/api/TbRefIfacesParentIfBPAdapter.h"
#include "TbRefIfacesParentIfLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTbRefIfacesParentIfBPAdapter::Initialize(TScriptInterface<ITbRefIfacesParentIfBPInterface> InTarget)
{
	Target = InTarget;
}

UTbRefIfacesParentIfPublisher* UTbRefIfacesParentIfBPAdapter::_GetPublisher()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbRefIfacesParentIfBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTbRefIfacesParentIfBPAdapter::LocalIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Result, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
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

TFuture<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> UTbRefIfacesParentIfBPAdapter::LocalIfMethodAsync(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param, this]()
		{
		return LocalIfMethod(Param);
	});
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> UTbRefIfacesParentIfBPAdapter::LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbRefIfacesParentIfBPInterface::Execute_LocalIfMethod(Obj, Param);
	}
	return TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
}

void UTbRefIfacesParentIfBPAdapter::LocalIfMethodListAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Result, const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param)
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

TFuture<TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>> UTbRefIfacesParentIfBPAdapter::LocalIfMethodListAsync(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param, this]()
		{
		return LocalIfMethodList(Param);
	});
}

TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> UTbRefIfacesParentIfBPAdapter::LocalIfMethodList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbRefIfacesParentIfBPInterface::Execute_LocalIfMethodList(Obj, Param);
	}
	return TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>();
}

void UTbRefIfacesParentIfBPAdapter::ImportedIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbIfaceimportEmptyIfInterface>& Result, const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
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

TFuture<TScriptInterface<ITbIfaceimportEmptyIfInterface>> UTbRefIfacesParentIfBPAdapter::ImportedIfMethodAsync(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param, this]()
		{
		return ImportedIfMethod(Param);
	});
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> UTbRefIfacesParentIfBPAdapter::ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbRefIfacesParentIfBPInterface::Execute_ImportedIfMethod(Obj, Param);
	}
	return TScriptInterface<ITbIfaceimportEmptyIfInterface>();
}

void UTbRefIfacesParentIfBPAdapter::ImportedIfMethodListAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Result, const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param)
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

TFuture<TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>> UTbRefIfacesParentIfBPAdapter::ImportedIfMethodListAsync(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param)
{
	return Async(EAsyncExecution::ThreadPool,
		[Param, this]()
		{
		return ImportedIfMethodList(Param);
	});
}

TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> UTbRefIfacesParentIfBPAdapter::ImportedIfMethodList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbRefIfacesParentIfBPInterface::Execute_ImportedIfMethodList(Obj, Param);
	}
	return TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>();
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> UTbRefIfacesParentIfBPAdapter::GetLocalIf() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbRefIfacesParentIfBPInterface::Execute_GetLocalIf(Obj);
	}
	return TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
}
void UTbRefIfacesParentIfBPAdapter::SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbRefIfacesParentIfBPInterface::Execute_SetLocalIf(Obj, InLocalIf);
	}
}

TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> UTbRefIfacesParentIfBPAdapter::GetLocalIfList() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbRefIfacesParentIfBPInterface::Execute_GetLocalIfList(Obj);
	}
	return TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>();
}
void UTbRefIfacesParentIfBPAdapter::SetLocalIfList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbRefIfacesParentIfBPInterface::Execute_SetLocalIfList(Obj, InLocalIfList);
	}
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> UTbRefIfacesParentIfBPAdapter::GetImportedIf() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbRefIfacesParentIfBPInterface::Execute_GetImportedIf(Obj);
	}
	return TScriptInterface<ITbIfaceimportEmptyIfInterface>();
}
void UTbRefIfacesParentIfBPAdapter::SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbRefIfacesParentIfBPInterface::Execute_SetImportedIf(Obj, InImportedIf);
	}
}

TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> UTbRefIfacesParentIfBPAdapter::GetImportedIfList() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbRefIfacesParentIfBPInterface::Execute_GetImportedIfList(Obj);
	}
	return TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>();
}
void UTbRefIfacesParentIfBPAdapter::SetImportedIfList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList)
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		ITbRefIfacesParentIfBPInterface::Execute_SetImportedIfList(Obj, InImportedIfList);
	}
}
