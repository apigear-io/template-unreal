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
#pragma once
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "Misc/ScopeRWLock.h"
#include "UObject/WeakInterfacePtr.h"
#include "TbIfaceimport/Generated/api/TbIfaceimportEmptyIfInterface.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "TbRefIfaces_data.h"
#include "TbRefIfacesParentIfInterface.generated.h"

/**
 * Declaration for ParentIf
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfLocalIfSignalDelegate, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& /* Param */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfLocalIfSignalDelegateBP, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>&, Param);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfLocalIfSignalListDelegate, const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& /* Param */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfLocalIfSignalListDelegateBP, const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>&, Param);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfImportedIfSignalDelegate, const TScriptInterface<ITbIfaceimportEmptyIfInterface>& /* Param */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfImportedIfSignalDelegateBP, const TScriptInterface<ITbIfaceimportEmptyIfInterface>&, Param);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfImportedIfSignalListDelegate, const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& /* Param */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfImportedIfSignalListDelegateBP, const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>&, Param);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfLocalIfChangedDelegate, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& /* LocalIf */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfLocalIfChangedDelegateBP, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>&, LocalIf);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfLocalIfListChangedDelegate, const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& /* LocalIfList */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfLocalIfListChangedDelegateBP, const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>&, LocalIfList);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfImportedIfChangedDelegate, const TScriptInterface<ITbIfaceimportEmptyIfInterface>& /* ImportedIf */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfImportedIfChangedDelegateBP, const TScriptInterface<ITbIfaceimportEmptyIfInterface>&, ImportedIf);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfImportedIfListChangedDelegate, const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& /* ImportedIfList */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfImportedIfListChangedDelegateBP, const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>&, ImportedIfList);

/**
 * Helper interface for TbRefIfacesParentIf events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events and property-changed events.
 */
UINTERFACE(BlueprintType)
class UTbRefIfacesParentIfBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBREFIFACESAPI_API ITbRefIfacesParentIfBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "On LocalIfSignal Signal")
	void OnLocalIfSignalSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "On LocalIfSignalList Signal")
	void OnLocalIfSignalListSignal(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "On ImportedIfSignal Signal")
	void OnImportedIfSignalSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "On ImportedIfSignalList Signal")
	void OnImportedIfSignalListSignal(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "On Property LocalIf Changed")
	void OnLocalIfChanged(UPARAM(DisplayName = "LocalIf") const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "On Property LocalIfList Changed")
	void OnLocalIfListChanged(UPARAM(DisplayName = "LocalIfList") const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "On Property ImportedIf Changed")
	void OnImportedIfChanged(UPARAM(DisplayName = "ImportedIf") const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "On Property ImportedIfList Changed")
	void OnImportedIfListChanged(UPARAM(DisplayName = "ImportedIfList") const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList);
};

UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbRefIfacesParentIfSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBREFIFACESAPI_API ITbRefIfacesParentIfSubscriberInterface
{
	GENERATED_BODY()
public:
	virtual void OnLocalIfSignalSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) = 0;

	virtual void OnLocalIfSignalListSignal(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) = 0;

	virtual void OnImportedIfSignalSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) = 0;

	virtual void OnImportedIfSignalListSignal(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) = 0;

	virtual void OnLocalIfChanged(UPARAM(DisplayName = "LocalIf") const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf) = 0;

	virtual void OnLocalIfListChanged(UPARAM(DisplayName = "LocalIfList") const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList) = 0;

	virtual void OnImportedIfChanged(UPARAM(DisplayName = "ImportedIf") const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf) = 0;

	virtual void OnImportedIfListChanged(UPARAM(DisplayName = "ImportedIfList") const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList) = 0;
};

/**
 * Class UTbRefIfacesParentIfInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBREFIFACESAPI_API UTbRefIfacesParentIfPublisher : public UObject
{
	GENERATED_BODY()

public:
	FTbRefIfacesParentIfLocalIfSignalDelegate OnLocalIfSignalSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "LocalIfSignal Signal")
	FTbRefIfacesParentIfLocalIfSignalDelegateBP OnLocalIfSignalSignalBP;
	/// C++ wrapper for BP functions to safely call LocalIfSignalSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Broadcast LocalIfSignal Signal")
	void BroadcastLocalIfSignalSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param);

	FTbRefIfacesParentIfLocalIfSignalListDelegate OnLocalIfSignalListSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "LocalIfSignalList Signal")
	FTbRefIfacesParentIfLocalIfSignalListDelegateBP OnLocalIfSignalListSignalBP;
	/// C++ wrapper for BP functions to safely call LocalIfSignalListSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Broadcast LocalIfSignalList Signal")
	void BroadcastLocalIfSignalListSignal(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param);

	FTbRefIfacesParentIfImportedIfSignalDelegate OnImportedIfSignalSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "ImportedIfSignal Signal")
	FTbRefIfacesParentIfImportedIfSignalDelegateBP OnImportedIfSignalSignalBP;
	/// C++ wrapper for BP functions to safely call ImportedIfSignalSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Broadcast ImportedIfSignal Signal")
	void BroadcastImportedIfSignalSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param);

	FTbRefIfacesParentIfImportedIfSignalListDelegate OnImportedIfSignalListSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "ImportedIfSignalList Signal")
	FTbRefIfacesParentIfImportedIfSignalListDelegateBP OnImportedIfSignalListSignalBP;
	/// C++ wrapper for BP functions to safely call ImportedIfSignalListSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Broadcast ImportedIfSignalList Signal")
	void BroadcastImportedIfSignalListSignal(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param);

	FTbRefIfacesParentIfLocalIfChangedDelegate OnLocalIfChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Property LocalIf Changed")
	FTbRefIfacesParentIfLocalIfChangedDelegateBP OnLocalIfChangedBP;
	/// C++ wrapper for BP functions to safely call OnLocalIfChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Broadcast Property LocalIf Changed")
	void BroadcastLocalIfChanged(UPARAM(DisplayName = "LocalIf") const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf);

	FTbRefIfacesParentIfLocalIfListChangedDelegate OnLocalIfListChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Property LocalIfList Changed")
	FTbRefIfacesParentIfLocalIfListChangedDelegateBP OnLocalIfListChangedBP;
	/// C++ wrapper for BP functions to safely call OnLocalIfListChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Broadcast Property LocalIfList Changed")
	void BroadcastLocalIfListChanged(UPARAM(DisplayName = "LocalIfList") const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList);

	FTbRefIfacesParentIfImportedIfChangedDelegate OnImportedIfChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Property ImportedIf Changed")
	FTbRefIfacesParentIfImportedIfChangedDelegateBP OnImportedIfChangedBP;
	/// C++ wrapper for BP functions to safely call OnImportedIfChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Broadcast Property ImportedIf Changed")
	void BroadcastImportedIfChanged(UPARAM(DisplayName = "ImportedIf") const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf);

	FTbRefIfacesParentIfImportedIfListChangedDelegate OnImportedIfListChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Property ImportedIfList Changed")
	FTbRefIfacesParentIfImportedIfListChangedDelegateBP OnImportedIfListChangedBP;
	/// C++ wrapper for BP functions to safely call OnImportedIfListChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Broadcast Property ImportedIfList Changed")
	void BroadcastImportedIfListChanged(UPARAM(DisplayName = "ImportedIfList") const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals")
	void Subscribe(const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber);
	void Subscribe(const TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals")
	void Unsubscribe(const TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>& Subscriber);
	void Unsubscribe(const TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>& Subscriber);

private:
	UPROPERTY()
	TArray<TScriptInterface<ITbRefIfacesParentIfBPSubscriberInterface>> BPSubscribers;
	FRWLock BPSubscribersLock;
	TArray<TWeakInterfacePtr<ITbRefIfacesParentIfSubscriberInterface>> Subscribers;
	FRWLock SubscribersLock;
};

/**
 * Interface UTbRefIfacesParentIfInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbRefIfacesParentIfInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbRefIfacesParentIfInterface
 */
class TBREFIFACESAPI_API ITbRefIfacesParentIfInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf")
	virtual UTbRefIfacesParentIfPublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void LocalIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Result, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations")
	virtual TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void LocalIfMethodListAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Result, const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations")
	virtual TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfMethodList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void ImportedIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbIfaceimportEmptyIfInterface>& Result, const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations")
	virtual TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void ImportedIfMethodListAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Result, const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations")
	virtual TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfMethodList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	virtual TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetLocalIf() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	virtual void SetLocalIf(UPARAM(DisplayName = "LocalIf") const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	virtual TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> GetLocalIfList() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	virtual void SetLocalIfList(UPARAM(DisplayName = "LocalIfList") const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	virtual TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	virtual void SetImportedIf(UPARAM(DisplayName = "ImportedIf") const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	virtual TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> GetImportedIfList() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	virtual void SetImportedIfList(UPARAM(DisplayName = "ImportedIfList") const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList) = 0;
};
