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
#include "TbRefIfaces/Generated/api/TbRefIfacesParentIfBPInterface.h"
#include "TbRefIfacesParentIfBPAdapter.generated.h"

/**
 * Adapter UTbRefIfacesParentIfBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TBREFIFACESAPI_API UTbRefIfacesParentIfBPAdapter : public UObject, public ITbRefIfacesParentIfInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|TbRefIfaces|ParentIf")
	TScriptInterface<ITbRefIfacesParentIfBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf")
	void Initialize(TScriptInterface<ITbRefIfacesParentIfBPInterface> InTarget);

	// signals
	UTbRefIfacesParentIfPublisher* _GetPublisher() override;

	// methods
	void LocalIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Result, const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override;
	TFuture<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfMethodAsync(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override;
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override;

	void LocalIfMethodListAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Result, const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) override;
	TFuture<TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>> LocalIfMethodListAsync(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) override;
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfMethodList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) override;

	void ImportedIfMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TScriptInterface<ITbIfaceimportEmptyIfInterface>& Result, const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override;
	TFuture<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfMethodAsync(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override;
	TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override;

	void ImportedIfMethodListAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Result, const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) override;
	TFuture<TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>> ImportedIfMethodListAsync(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) override;
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfMethodList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) override;

	// properties
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetLocalIf() const override;
	void SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf) override;

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> GetLocalIfList() const override;
	void SetLocalIfList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList) override;

	TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf() const override;
	void SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf) override;

	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> GetImportedIfList() const override;
	void SetImportedIfList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList) override;
};
