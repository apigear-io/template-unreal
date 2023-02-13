
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
#include "TbSame2SameStruct1InterfaceInterface.h"
#include "TbSame2SameStruct1InterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbSame2SameStruct1InterfaceLoggingDecorator, Log, All);

UCLASS(BlueprintType, Blueprintable)
class TBSAME2_API UTbSame2SameStruct1InterfaceLoggingDecorator : public UAbstractTbSame2SameStruct1Interface
{
	GENERATED_BODY()

public:
	explicit UTbSame2SameStruct1InterfaceLoggingDecorator();
	virtual ~UTbSame2SameStruct1InterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface")
	void setBackendService(TScriptInterface<ITbSame2SameStruct1InterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FTbSame2Struct1 GetProp1_Implementation() const override;

	void SetProp1_Implementation(const FTbSame2Struct1& InProp1) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) override;
	FTbSame2Struct1 Func1_Implementation(const FTbSame2Struct1& Param1) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame2|SameStruct1Interface")
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct1Interface", BlueprintInternalUseOnly)
	void OnSig1(const FTbSame2Struct1& Param1);

	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct1Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const FTbSame2Struct1& Prop1);
};
