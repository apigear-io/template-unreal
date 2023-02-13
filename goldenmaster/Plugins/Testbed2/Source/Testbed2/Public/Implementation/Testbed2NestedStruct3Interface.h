
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
#include "Generated/api/Testbed2NestedStruct3InterfaceInterface.h"
#include "Testbed2NestedStruct3Interface.generated.h"

UCLASS(BlueprintType, Blueprintable)
class TESTBED2_API UTestbed2NestedStruct3Interface : public UObject, public ITestbed2NestedStruct3InterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed2NestedStruct3Interface();

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface", DisplayName = "Sig1 Signal")
	FTestbed2NestedStruct3InterfaceSig1Delegate Sig1Signal;
	FTestbed2NestedStruct3InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface", DisplayName = "Sig2 Signal")
	FTestbed2NestedStruct3InterfaceSig2Delegate Sig2Signal;
	FTestbed2NestedStruct3InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface", DisplayName = "Sig3 Signal")
	FTestbed2NestedStruct3InterfaceSig3Delegate Sig3Signal;
	FTestbed2NestedStruct3InterfaceSig3Delegate& GetSig3SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface", DisplayName = "Prop1 Changed")
	FTestbed2NestedStruct3InterfaceProp1ChangedDelegate Prop1Changed;
	FTestbed2NestedStruct3InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface", DisplayName = "Prop2 Changed")
	FTestbed2NestedStruct3InterfaceProp2ChangedDelegate Prop2Changed;
	FTestbed2NestedStruct3InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface", DisplayName = "Prop3 Changed")
	FTestbed2NestedStruct3InterfaceProp3ChangedDelegate Prop3Changed;
	FTestbed2NestedStruct3InterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() override;

	// properties
	FTestbed2NestedStruct1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTestbed2NestedStruct1& Prop1) override;

	FTestbed2NestedStruct2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(const FTestbed2NestedStruct2& Prop2) override;

	FTestbed2NestedStruct3 GetProp3_Implementation() const override;
	void SetProp3_Implementation(const FTestbed2NestedStruct3& Prop3) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override{};
	FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override{};
	FTestbed2NestedStruct1 Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;

	void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) override{};
	FTestbed2NestedStruct1 Func3_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) override;

protected:
	// signals
	void BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1) override;

	void BroadcastSig2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;

	void BroadcastSig3_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) override;

	void BroadcastProp1Changed_Implementation(const FTestbed2NestedStruct1& Prop1) override;

	void BroadcastProp2Changed_Implementation(const FTestbed2NestedStruct2& Prop2) override;

	void BroadcastProp3Changed_Implementation(const FTestbed2NestedStruct3& Prop3) override;

private:
	// properties - local copy - use setter functions to emit changed signals
	FTestbed2NestedStruct1 Prop1{FTestbed2NestedStruct1()};
	FTestbed2NestedStruct2 Prop2{FTestbed2NestedStruct2()};
	FTestbed2NestedStruct3 Prop3{FTestbed2NestedStruct3()};
};
