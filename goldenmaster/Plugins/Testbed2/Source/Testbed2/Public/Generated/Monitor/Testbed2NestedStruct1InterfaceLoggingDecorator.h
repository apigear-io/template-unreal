
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
#include "Testbed2NestedStruct1InterfaceInterface.h"
#include "Testbed2NestedStruct1InterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2NestedStruct1InterfaceLoggingDecorator, Log, All);

UCLASS(BlueprintType, Blueprintable)
class TESTBED2_API UTestbed2NestedStruct1InterfaceLoggingDecorator : public UGameInstanceSubsystem, public ITestbed2NestedStruct1InterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTestbed2NestedStruct1InterfaceLoggingDecorator();
	virtual ~UTestbed2NestedStruct1InterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	void setBackendService(TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> InService);

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface", DisplayName = "Sig1 Signal")
	FTestbed2NestedStruct1InterfaceSig1Delegate Sig1Signal;
	FTestbed2NestedStruct1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface", DisplayName = "Prop1 Changed")
	FTestbed2NestedStruct1InterfaceProp1ChangedDelegate Prop1Changed;
	FTestbed2NestedStruct1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// properties
	FTestbed2NestedStruct1 GetProp1_Implementation() const override;

	void SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override;
	FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) override;

protected:
	// signals
	void BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1) override;

	void BroadcastProp1Changed_Implementation(const FTestbed2NestedStruct1& Prop1) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct1Interface", BlueprintInternalUseOnly)
	void OnSig1(const FTestbed2NestedStruct1& Param1);

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct1Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const FTestbed2NestedStruct1& Prop1);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	FTestbed2NestedStruct1 Prop1{FTestbed2NestedStruct1()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|NestedStruct1Interface", BlueprintInternalUseOnly)
	FTestbed2NestedStruct1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|NestedStruct1Interface", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTestbed2NestedStruct1& InProp1);
};
