
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
#include "TbSame2SameEnum2InterfaceInterface.h"
#include "TbSame2SameEnum2InterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbSame2SameEnum2InterfaceLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME2_API UTbSame2SameEnum2InterfaceLoggingDecorator : public UAbstractTbSame2SameEnum2Interface
{
	GENERATED_BODY()

public:
	explicit UTbSame2SameEnum2InterfaceLoggingDecorator();
	virtual ~UTbSame2SameEnum2InterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface")
	void setBackendService(TScriptInterface<ITbSame2SameEnum2InterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	ETbSame2Enum1 GetProp1_Implementation() const override;

	void SetProp1_Implementation(ETbSame2Enum1 InProp1) override;

	ETbSame2Enum2 GetProp2_Implementation() const override;

	void SetProp2_Implementation(ETbSame2Enum2 InProp2) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1) override;
	ETbSame2Enum1 Func1_Implementation(ETbSame2Enum1 Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;
	ETbSame2Enum1 Func2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame2|SameEnum2Interface")
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnSig1(ETbSame2Enum1 Param1);

	UFUNCTION(Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnSig2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);

	UFUNCTION(Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(ETbSame2Enum1 Prop1);

	UFUNCTION(Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnProp2Changed(ETbSame2Enum2 Prop2);
};
