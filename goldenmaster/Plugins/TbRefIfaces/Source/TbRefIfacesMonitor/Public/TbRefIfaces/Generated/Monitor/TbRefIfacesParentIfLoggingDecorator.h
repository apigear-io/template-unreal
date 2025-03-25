
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
class TBREFIFACESMONITOR_API UTbRefIfacesParentIfLoggingDecorator : public UAbstractTbRefIfacesParentIf
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

	TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf() const override;

	void SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf) override;

	// operations
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override;

	TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefIfaces|ParentIf")
	TScriptInterface<ITbRefIfacesParentIfInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbRefIfaces|ParentIf", BlueprintInternalUseOnly)
	void OnLocalIfSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InParam);

	UFUNCTION(Category = "ApiGear|TbRefIfaces|ParentIf", BlueprintInternalUseOnly)
	void OnImportedIfSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InParam);

	UFUNCTION(Category = "ApiGear|TbRefIfaces|ParentIf", BlueprintInternalUseOnly)
	void OnLocalIfChanged(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf);

	UFUNCTION(Category = "ApiGear|TbRefIfaces|ParentIf", BlueprintInternalUseOnly)
	void OnImportedIfChanged(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf);
};
