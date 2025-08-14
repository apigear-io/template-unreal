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
#include "TbRefIfacesParentIfInterface.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "TbRefIfaces_data.h"
#include "TbIfaceimport/Generated/api/TbIfaceimport_data.h"
#include "TbRefIfacesParentIfBPInterface.generated.h"

/**
 * Interface UTbRefIfacesParentIfBPInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbRefIfacesParentIfBPInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbRefIfacesParentIfBPInterface
 */
class TBREFIFACESAPI_API ITbRefIfacesParentIfBPInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf")
	UTbRefIfacesParentIfSignals* _GetSignals();
	virtual UTbRefIfacesParentIfSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void LocalIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Result, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param);
	virtual void LocalIfMethodAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Result, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations")
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param);
	virtual TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIfMethod_Implementation(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void LocalIfMethodListAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Result, const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param);
	virtual void LocalIfMethodListAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Result, const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations")
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfMethodList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param);
	virtual TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfMethodList_Implementation(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void ImportedIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbIfaceimportEmptyIfInterface>& Result, const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param);
	virtual void ImportedIfMethodAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbIfaceimportEmptyIfInterface>& Result, const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations")
	TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param);
	virtual TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIfMethod_Implementation(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void ImportedIfMethodListAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Result, const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param);
	virtual void ImportedIfMethodListAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Result, const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Operations")
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfMethodList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param);
	virtual TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfMethodList_Implementation(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetLocalIf() const;
	virtual TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetLocalIf_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	void SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf);
	virtual void SetLocalIf_Implementation(UPARAM(DisplayName = "LocalIf") const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> GetLocalIfList() const;
	virtual TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> GetLocalIfList_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	void SetLocalIfList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList);
	virtual void SetLocalIfList_Implementation(UPARAM(DisplayName = "LocalIfList") const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf() const;
	virtual TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	void SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf);
	virtual void SetImportedIf_Implementation(UPARAM(DisplayName = "ImportedIf") const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> GetImportedIfList() const;
	virtual TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> GetImportedIfList_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	void SetImportedIfList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList);
	virtual void SetImportedIfList_Implementation(UPARAM(DisplayName = "ImportedIfList") const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList) = 0;
};
