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
#pragma once

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbRefIfaces_data.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesParentIfInterface.h"
#include "AbstractTbRefIfacesParentIf.generated.h"

/**
 * Abstract UAbstractTbRefIfacesParentIf
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBREFIFACESAPI_API UAbstractTbRefIfacesParentIf : public UGameInstanceSubsystem, public ITbRefIfacesParentIfInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbRefIfacesParentIf();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbRefIfacesParentIfPublisher* _GetPublisher() override;

	// methods
	virtual void LocalIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Result, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override;
	virtual TFuture<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfMethodAsync(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override;
	virtual TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::LocalIfMethod, return TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>(););

	virtual void LocalIfMethodListAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Result, const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) override;
	virtual TFuture<TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>> LocalIfMethodListAsync(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) override;
	virtual TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfMethodList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::LocalIfMethodList, return TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>(););

	virtual void ImportedIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbIfaceimportEmptyIfInterface>& Result, const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override;
	virtual TFuture<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfMethodAsync(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override;
	virtual TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::ImportedIfMethod, return TScriptInterface<ITbIfaceimportEmptyIfInterface>(););

	virtual void ImportedIfMethodListAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Result, const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) override;
	virtual TFuture<TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>> ImportedIfMethodListAsync(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) override;
	virtual TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfMethodList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::ImportedIfMethodList, return TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>(););

	// properties
	virtual TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetLocalIf() const override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::GetLocalIf, return TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>(););
	virtual void SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf) override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::SetLocalIf, return;);

	virtual TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> GetLocalIfList() const override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::GetLocalIfList, return TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>(););
	virtual void SetLocalIfList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList) override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::SetLocalIfList, return;);

	virtual TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf() const override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::GetImportedIf, return TScriptInterface<ITbIfaceimportEmptyIfInterface>(););
	virtual void SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf) override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::SetImportedIf, return;);

	virtual TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> GetImportedIfList() const override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::GetImportedIfList, return TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>(););
	virtual void SetImportedIfList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList) override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::SetImportedIfList, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetLocalIf_Private, BlueprintSetter = SetLocalIf_Private, Category = "ApiGear|TbRefIfaces|ParentIf")
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIf{TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbRefIfaces|ParentIf|Properties", BlueprintInternalUseOnly)
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetLocalIf_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbRefIfaces|ParentIf|Properties", BlueprintInternalUseOnly)
	void SetLocalIf_Private(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetLocalIfList_Private, BlueprintSetter = SetLocalIfList_Private, Category = "ApiGear|TbRefIfaces|ParentIf")
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfList{TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbRefIfaces|ParentIf|Properties", BlueprintInternalUseOnly)
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> GetLocalIfList_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbRefIfaces|ParentIf|Properties", BlueprintInternalUseOnly)
	void SetLocalIfList_Private(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetImportedIf_Private, BlueprintSetter = SetImportedIf_Private, Category = "ApiGear|TbRefIfaces|ParentIf")
	TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIf{TScriptInterface<ITbIfaceimportEmptyIfInterface>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbRefIfaces|ParentIf|Properties", BlueprintInternalUseOnly)
	TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbRefIfaces|ParentIf|Properties", BlueprintInternalUseOnly)
	void SetImportedIf_Private(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetImportedIfList_Private, BlueprintSetter = SetImportedIfList_Private, Category = "ApiGear|TbRefIfaces|ParentIf")
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfList{TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbRefIfaces|ParentIf|Properties", BlueprintInternalUseOnly)
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> GetImportedIfList_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbRefIfaces|ParentIf|Properties", BlueprintInternalUseOnly)
	void SetImportedIfList_Private(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList);

private:
	// signals
	UPROPERTY()
	UTbRefIfacesParentIfPublisher* TbRefIfacesParentIfPublisher;
};
