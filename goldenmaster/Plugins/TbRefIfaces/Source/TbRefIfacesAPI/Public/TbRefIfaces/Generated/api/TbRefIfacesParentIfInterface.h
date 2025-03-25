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

DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfImportedIfSignalDelegate, const TScriptInterface<ITbIfaceimportEmptyIfInterface>& /* Param */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfImportedIfSignalDelegateBP, const TScriptInterface<ITbIfaceimportEmptyIfInterface>&, Param);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfLocalIfChangedDelegate, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& /* LocalIf */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfLocalIfChangedDelegateBP, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>&, LocalIf);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfImportedIfChangedDelegate, const TScriptInterface<ITbIfaceimportEmptyIfInterface>& /* ImportedIf */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesParentIfImportedIfChangedDelegateBP, const TScriptInterface<ITbIfaceimportEmptyIfInterface>&, ImportedIf);

/**
 * Class UTbRefIfacesParentIfInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBREFIFACESAPI_API UTbRefIfacesParentIfSignals : public UObject
{
	GENERATED_BODY()

public:
	FTbRefIfacesParentIfLocalIfSignalDelegate OnLocalIfSignalSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "LocalIfSignal Signal")
	FTbRefIfacesParentIfLocalIfSignalDelegateBP OnLocalIfSignalSignalBP;
	/// C++ wrapper for BP functions to safely call LocalIfSignalSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Broadcast LocalIfSignal Signal")
	void BroadcastLocalIfSignalSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
	{
		OnLocalIfSignalSignal.Broadcast(Param);
		OnLocalIfSignalSignalBP.Broadcast(Param);
	}

	FTbRefIfacesParentIfImportedIfSignalDelegate OnImportedIfSignalSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "ImportedIfSignal Signal")
	FTbRefIfacesParentIfImportedIfSignalDelegateBP OnImportedIfSignalSignalBP;
	/// C++ wrapper for BP functions to safely call ImportedIfSignalSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Broadcast ImportedIfSignal Signal")
	void BroadcastImportedIfSignalSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
	{
		OnImportedIfSignalSignal.Broadcast(Param);
		OnImportedIfSignalSignalBP.Broadcast(Param);
	}

	FTbRefIfacesParentIfLocalIfChangedDelegate OnLocalIfChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Property LocalIf Changed")
	FTbRefIfacesParentIfLocalIfChangedDelegateBP OnLocalIfChangedBP;
	/// C++ wrapper for BP functions to safely call OnLocalIfChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Broadcast Property LocalIf Changed")
	void BroadcastLocalIfChanged(UPARAM(DisplayName = "LocalIf") const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
	{
		OnLocalIfChanged.Broadcast(InLocalIf);
		OnLocalIfChangedBP.Broadcast(InLocalIf);
	}

	FTbRefIfacesParentIfImportedIfChangedDelegate OnImportedIfChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Property ImportedIf Changed")
	FTbRefIfacesParentIfImportedIfChangedDelegateBP OnImportedIfChangedBP;
	/// C++ wrapper for BP functions to safely call OnImportedIfChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Signals", DisplayName = "Broadcast Property ImportedIf Changed")
	void BroadcastImportedIfChanged(UPARAM(DisplayName = "ImportedIf") const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf)
	{
		OnImportedIfChanged.Broadcast(InImportedIf);
		OnImportedIfChangedBP.Broadcast(InImportedIf);
	}
};

/**
 * Interface UTbRefIfacesParentIfInterface only for Unreal Engine's reflection system
 */
// Note: meta=(CannotImplementInterfaceInBlueprint) is equal to NotBlueprintable and is only needed for UE 4.27
UINTERFACE(NotBlueprintable, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
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
	virtual UTbRefIfacesParentIfSignals* _GetSignals() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void LocalIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Result, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations")
	virtual TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void ImportedIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbIfaceimportEmptyIfInterface>& Result, const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations")
	virtual TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	virtual TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetLocalIf() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	virtual void SetLocalIf(UPARAM(DisplayName = "LocalIf") const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	virtual TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	virtual void SetImportedIf(UPARAM(DisplayName = "ImportedIf") const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf) = 0;
};
