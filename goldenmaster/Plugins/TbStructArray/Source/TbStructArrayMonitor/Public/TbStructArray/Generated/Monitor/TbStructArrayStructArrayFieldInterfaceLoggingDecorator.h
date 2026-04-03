
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
#include "TbStructArray/Generated/api/AbstractTbStructArrayStructArrayFieldInterface.h"
#include "TbStructArrayStructArrayFieldInterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbStructArrayStructArrayFieldInterfaceLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSTRUCTARRAYMONITOR_API UTbStructArrayStructArrayFieldInterfaceLoggingDecorator : public UAbstractTbStructArrayStructArrayFieldInterface, public ITbStructArrayStructArrayFieldInterfaceSubscriberInterface
{
	GENERATED_BODY()

public:
	explicit UTbStructArrayStructArrayFieldInterfaceLoggingDecorator();
	virtual ~UTbStructArrayStructArrayFieldInterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	void setBackendService(TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FTbStructArrayStructWithArrayOfStructs GetPropStructArray() const override;

	void SetPropStructArray(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray) override;

	FTbStructArrayStructWithArrayOfEnums GetPropEnumArray() const override;

	void SetPropEnumArray(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray) override;

	FTbStructArrayStructWithArrayOfInts GetPropIntArray() const override;

	void SetPropIntArray(const FTbStructArrayStructWithArrayOfInts& InPropIntArray) override;

	FTbStructArrayMixedStruct GetPropMixed() const override;

	void SetPropMixed(const FTbStructArrayMixedStruct& InPropMixed) override;

	// operations
	FTbStructArrayMixedStruct FuncMixed(const FTbStructArrayMixedStruct& ParamMixed) override;

	FTbStructArrayStructWithArrayOfStructs FuncStructArray(const FTbStructArrayStructWithArrayOfStructs& ParamPoints) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> BackendService;

	// signals
	void OnSigMixedSignal(const FTbStructArrayMixedStruct& InParamMixed);

	void OnSigStructArraySignal(const FTbStructArrayStructWithArrayOfStructs& InParamPoints);

	void OnPropStructArrayChanged(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray);

	void OnPropEnumArrayChanged(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray);

	void OnPropIntArrayChanged(const FTbStructArrayStructWithArrayOfInts& InPropIntArray);

	void OnPropMixedChanged(const FTbStructArrayMixedStruct& InPropMixed);
};
