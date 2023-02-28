
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
#include "TbSame1SameStruct2InterfaceInterface.h"
#include "TbSame1SameStruct2InterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbSame1SameStruct2InterfaceLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME1_API UTbSame1SameStruct2InterfaceLoggingDecorator : public UAbstractTbSame1SameStruct2Interface
{
	GENERATED_BODY()

public:
	explicit UTbSame1SameStruct2InterfaceLoggingDecorator();
	virtual ~UTbSame1SameStruct2InterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface")
	void setBackendService(TScriptInterface<ITbSame1SameStruct2InterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FTbSame1Struct2 GetProp1_Implementation() const override;

	void SetProp1_Implementation(const FTbSame1Struct2& InProp1) override;

	FTbSame1Struct2 GetProp2_Implementation() const override;

	void SetProp2_Implementation(const FTbSame1Struct2& InProp2) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) override;
	FTbSame1Struct1 Func1_Implementation(const FTbSame1Struct1& Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;
	FTbSame1Struct1 Func2_Implementation(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame1|SameStruct2Interface")
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	void OnSig1(const FTbSame1Struct1& Param1);

	UFUNCTION(Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	void OnSig2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2);

	UFUNCTION(Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const FTbSame1Struct2& Prop1);

	UFUNCTION(Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	void OnProp2Changed(const FTbSame1Struct2& Prop2);
};
