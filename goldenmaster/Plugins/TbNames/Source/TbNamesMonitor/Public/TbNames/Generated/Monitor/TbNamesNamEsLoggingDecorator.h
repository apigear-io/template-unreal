
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
#include "TbNames/Generated/api/AbstractTbNamesNamEs.h"
#include "TbNamesNamEsLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbNamesNamEsLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBNAMESMONITOR_API UTbNamesNamEsLoggingDecorator : public UAbstractTbNamesNamEs
{
	GENERATED_BODY()

public:
	explicit UTbNamesNamEsLoggingDecorator();
	virtual ~UTbNamesNamEsLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs")
	void setBackendService(TScriptInterface<ITbNamesNamEsInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	bool GetSwitch() const override;

	void SetSwitch(bool bInSwitch) override;

	int32 GetSomeProperty() const override;

	void SetSomeProperty(int32 InSomeProperty) override;

	int32 GetSomePoperty2() const override;

	void SetSomePoperty2(int32 InSomePoperty2) override;

	ETbNamesEnum_With_Under_scores GetEnumProperty() const override;

	void SetEnumProperty(ETbNamesEnum_With_Under_scores InEnumProperty) override;

	// operations
	void SomeFunction(bool bSomeParam) override;

	void SomeFunction2(bool bSomeParam) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbNames|NamEs")
	TScriptInterface<ITbNamesNamEsInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSomeSignal(bool bInSomeParam);

	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSomeSignal2(bool bInSomeParam);

	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSwitchChanged(bool bInSwitch);

	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSomePropertyChanged(int32 InSomeProperty);

	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSomePoperty2Changed(int32 InSomePoperty2);

	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnEnumPropertyChanged(ETbNamesEnum_With_Under_scores InEnumProperty);
};
