
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
#include "UObject/NoExportTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "apig/Testbed2_apig.h"
#include "Testbed2NestedStruct1InterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "Testbed2NestedStruct1Interface")
class TESTBED2_API UTestbed2NestedStruct1InterfaceProxy : public UGameInstanceSubsystem, public ITestbed2NestedStruct1InterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTestbed2NestedStruct1InterfaceProxy();
	virtual ~UTestbed2NestedStruct1InterfaceProxy();

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface", DisplayName = "Sig1 Signal")
	FTestbed2NestedStruct1InterfaceSig1Delegate Sig1Signal;
	FTestbed2NestedStruct1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface", DisplayName = "Prop1 Changed")
	FTestbed2NestedStruct1InterfaceProp1ChangedDelegate Prop1Changed;
	FTestbed2NestedStruct1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	FTestbed2NestedStruct1 GetProp1() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	void SetProp1(const FTestbed2NestedStruct1& Prop1) override;

	// operations
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1);
	FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) override;

private:
	/** The connection to the service backend. */
	TSharedPtr<ITestbed2NestedStruct1InterfaceInterface, ESPMode::ThreadSafe> service;

	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct1Interface", BlueprintInternalUseOnly)
	void OnSig1(const FTestbed2NestedStruct1& Param1);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const FTestbed2NestedStruct1& Prop1);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1, BlueprintSetter = SetProp1, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	FTestbed2NestedStruct1 Prop1;
};
