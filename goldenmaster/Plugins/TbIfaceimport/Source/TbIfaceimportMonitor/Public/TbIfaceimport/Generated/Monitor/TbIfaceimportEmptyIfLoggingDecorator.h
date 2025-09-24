
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
#include "TbIfaceimport/Generated/api/AbstractTbIfaceimportEmptyIf.h"
#include "TbIfaceimportEmptyIfLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbIfaceimportEmptyIfLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBIFACEIMPORTMONITOR_API UTbIfaceimportEmptyIfLoggingDecorator : public UAbstractTbIfaceimportEmptyIf, public ITbIfaceimportEmptyIfSubscriberInterface
{
	GENERATED_BODY()

public:
	explicit UTbIfaceimportEmptyIfLoggingDecorator();
	virtual ~UTbIfaceimportEmptyIfLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf")
	void setBackendService(TScriptInterface<ITbIfaceimportEmptyIfInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	// operations
private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbIfaceimport|EmptyIf")
	TScriptInterface<ITbIfaceimportEmptyIfInterface> BackendService;

	// signals
};
