
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
#include "Engine/LatentActionManager.h"
#include "Templates/SharedPointer.h"
#include "apig/Testbed2_apig.h"
#include "Testbed2NestedStruct2InterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "Testbed2NestedStruct2Interface")
class TESTBED2_API UTestbed2NestedStruct2InterfaceProxy : public UGameInstanceSubsystem, public ITestbed2NestedStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTestbed2NestedStruct2InterfaceProxy();
	virtual ~UTestbed2NestedStruct2InterfaceProxy();

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct2Interface", DisplayName = "Sig1 Signal")
	FTestbed2NestedStruct2InterfaceSig1Delegate Sig1Signal;
	FTestbed2NestedStruct2InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct2Interface", DisplayName = "Sig2 Signal")
	FTestbed2NestedStruct2InterfaceSig2Delegate Sig2Signal;
	FTestbed2NestedStruct2InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct2Interface", DisplayName = "Prop1 Changed")
	FTestbed2NestedStruct2InterfaceProp1ChangedDelegate Prop1Changed;
	FTestbed2NestedStruct2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct2Interface", DisplayName = "Prop2 Changed")
	FTestbed2NestedStruct2InterfaceProp2ChangedDelegate Prop2Changed;
	FTestbed2NestedStruct2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	FTestbed2NestedStruct1 GetProp1() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	void SetProp1(const FTestbed2NestedStruct1& Prop1) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	FTestbed2NestedStruct2 GetProp2() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	void SetProp2(const FTestbed2NestedStruct2& Prop2) override;

	// operations
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	FTestbed2NestedStruct1 Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;

private:
	/** The connection to the service backend. */
	TSharedPtr<ITestbed2NestedStruct2InterfaceInterface, ESPMode::ThreadSafe> service;

	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct2Interface", BlueprintInternalUseOnly)
	void OnSig1(const FTestbed2NestedStruct1& Param1);

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct2Interface", BlueprintInternalUseOnly)
	void OnSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface", BlueprintInternalUseOnly)
	void OnProp2Changed(const FTestbed2NestedStruct2& Prop2);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1, BlueprintSetter = SetProp1, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	FTestbed2NestedStruct1 Prop1;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2, BlueprintSetter = SetProp2, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	FTestbed2NestedStruct2 Prop2;
};
