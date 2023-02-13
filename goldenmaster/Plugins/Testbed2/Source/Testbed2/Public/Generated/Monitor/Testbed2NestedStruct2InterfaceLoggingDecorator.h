
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
#include "Testbed2NestedStruct2InterfaceInterface.h"
#include "Testbed2NestedStruct2InterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2NestedStruct2InterfaceLoggingDecorator, Log, All);

UCLASS(BlueprintType, Blueprintable)
class TESTBED2_API UTestbed2NestedStruct2InterfaceLoggingDecorator : public UAbstractTestbed2NestedStruct2Interface
{
	GENERATED_BODY()

public:
	explicit UTestbed2NestedStruct2InterfaceLoggingDecorator();
	virtual ~UTestbed2NestedStruct2InterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	void setBackendService(TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FTestbed2NestedStruct1 GetProp1_Implementation() const override;

	void SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1) override;

	FTestbed2NestedStruct2 GetProp2_Implementation() const override;

	void SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override;
	FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;
	FTestbed2NestedStruct1 Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct2Interface", BlueprintInternalUseOnly)
	void OnSig1(const FTestbed2NestedStruct1& Param1);

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct2Interface", BlueprintInternalUseOnly)
	void OnSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct2Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct2Interface", BlueprintInternalUseOnly)
	void OnProp2Changed(const FTestbed2NestedStruct2& Prop2);
};
