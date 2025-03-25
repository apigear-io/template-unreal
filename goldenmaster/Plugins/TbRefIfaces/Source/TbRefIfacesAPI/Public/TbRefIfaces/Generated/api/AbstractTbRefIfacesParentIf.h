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
	virtual UTbRefIfacesParentIfSignals* _GetSignals() override;

	// methods
	virtual void LocalIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Result, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override;
	virtual TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::LocalIfMethod, return TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>(););

	virtual void ImportedIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbIfaceimportEmptyIfInterface>& Result, const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override;
	virtual TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::ImportedIfMethod, return TScriptInterface<ITbIfaceimportEmptyIfInterface>(););

	// properties
	virtual TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetLocalIf() const override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::GetLocalIf, return TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>(););
	virtual void SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf) override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::SetLocalIf, return;);

	virtual TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf() const override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::GetImportedIf, return TScriptInterface<ITbIfaceimportEmptyIfInterface>(););
	virtual void SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf) override PURE_VIRTUAL(UAbstractTbRefIfacesParentIf::SetImportedIf, return;);

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

	UPROPERTY(EditAnywhere, BlueprintGetter = GetImportedIf_Private, BlueprintSetter = SetImportedIf_Private, Category = "ApiGear|TbRefIfaces|ParentIf")
	TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIf{TScriptInterface<ITbIfaceimportEmptyIfInterface>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbRefIfaces|ParentIf|Properties", BlueprintInternalUseOnly)
	TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbRefIfaces|ParentIf|Properties", BlueprintInternalUseOnly)
	void SetImportedIf_Private(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf);

private:
	// signals
	UPROPERTY()
	UTbRefIfacesParentIfSignals* TbRefIfacesParentIfSignals;
};
