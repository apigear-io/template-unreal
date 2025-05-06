
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
#include "Generated/api/AbstractTestbed1StructArray2Interface.h"
#include "Testbed1StructArray2Interface.generated.h"

UCLASS(BlueprintType)
class TESTBED1_API UTestbed1StructArray2Interface : public UAbstractTestbed1StructArray2Interface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed1StructArray2Interface();

	// properties
	FTestbed1StructBoolWithArray GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(const FTestbed1StructBoolWithArray& PropBool) override;

	FTestbed1StructIntWithArray GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(const FTestbed1StructIntWithArray& PropInt) override;

	FTestbed1StructFloatWithArray GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(const FTestbed1StructFloatWithArray& PropFloat) override;

	FTestbed1StructStringWithArray GetPropString_Implementation() const override;
	void SetPropString_Implementation(const FTestbed1StructStringWithArray& PropString) override;

	FTestbed1StructEnumWithArray GetPropEnum_Implementation() const override;
	void SetPropEnum_Implementation(const FTestbed1StructEnumWithArray& PropEnum) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	void _ResetProperties();

	// operations
	TArray<FTestbed1StructBool> FuncBool_Implementation(const FTestbed1StructBoolWithArray& ParamBool) override;

	TArray<FTestbed1StructInt> FuncInt_Implementation(const FTestbed1StructIntWithArray& ParamInt) override;

	TArray<FTestbed1StructFloat> FuncFloat_Implementation(const FTestbed1StructFloatWithArray& ParamFloat) override;

	TArray<FTestbed1StructString> FuncString_Implementation(const FTestbed1StructStringWithArray& ParamString) override;

	TArray<ETestbed1Enum0> FuncEnum_Implementation(const FTestbed1StructEnumWithArray& ParamEnum) override;
};
