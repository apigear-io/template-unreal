
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
#include "TbSimple/Generated/api/AbstractTbSimpleNoOperationsInterface.h"
#include "TbSimpleNoOperationsInterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleNoOperationsInterfaceLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLE_API UTbSimpleNoOperationsInterfaceLoggingDecorator : public UAbstractTbSimpleNoOperationsInterface
{
	GENERATED_BODY()

public:
	explicit UTbSimpleNoOperationsInterfaceLoggingDecorator();
	virtual ~UTbSimpleNoOperationsInterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface")
	void setBackendService(TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	bool GetPropBool_Implementation() const override;

	void SetPropBool_Implementation(bool bInPropBool) override;

	int32 GetPropInt_Implementation() const override;

	void SetPropInt_Implementation(int32 InPropInt) override;

	// operations
private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|NoOperationsInterface")
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnSigVoid();

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnSigBool(bool bInParamBool);

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(bool bInPropBool);

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(int32 InPropInt);
};
