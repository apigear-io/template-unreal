
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

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbRefIfaces/Generated/api/AbstractTbRefIfacesParentIf.h"
#include "TbRefIfacesParentIfLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbRefIfacesParentIfLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBREFIFACESMONITOR_API UTbRefIfacesParentIfLoggingDecorator : public UAbstractTbRefIfacesParentIf, public ITbRefIfacesParentIfSubscriberInterface
{
	GENERATED_BODY()

public:
	explicit UTbRefIfacesParentIfLoggingDecorator();
	virtual ~UTbRefIfacesParentIfLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf")
	void setBackendService(TScriptInterface<ITbRefIfacesParentIfInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetLocalIf() const override;

	void SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf) override;

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> GetLocalIfList() const override;

	void SetLocalIfList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList) override;

	TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf() const override;

	void SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf) override;

	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> GetImportedIfList() const override;

	void SetImportedIfList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList) override;

	// operations
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override;

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfMethodList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) override;

	TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override;

	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfMethodList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefIfaces|ParentIf")
	TScriptInterface<ITbRefIfacesParentIfInterface> BackendService;

	// signals
	void OnLocalIfSignalSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InParam);

	void OnLocalIfSignalListSignal(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InParam);

	void OnImportedIfSignalSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InParam);

	void OnImportedIfSignalListSignal(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InParam);

	void OnLocalIfChanged(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf);

	void OnLocalIfListChanged(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList);

	void OnImportedIfChanged(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf);

	void OnImportedIfListChanged(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList);
};
