
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
#include "Generated/api/AbstractTestbed1StructInterface.h"
#include "Testbed1StructInterface.generated.h"

UCLASS(BlueprintType)
class TESTBED1_API UTestbed1StructInterface : public UAbstractTestbed1StructInterface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed1StructInterface();

	// properties
	FTestbed1StructBool GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(const FTestbed1StructBool& PropBool) override;

	FTestbed1StructInt GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(const FTestbed1StructInt& PropInt) override;

	FTestbed1StructFloat GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(const FTestbed1StructFloat& PropFloat) override;

	FTestbed1StructString GetPropString_Implementation() const override;
	void SetPropString_Implementation(const FTestbed1StructString& PropString) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	void _ResetProperties();

	// operations
	FTestbed1StructBool FuncBool_Implementation(const FTestbed1StructBool& ParamBool) override;

	FTestbed1StructInt FuncInt_Implementation(const FTestbed1StructInt& ParamInt) override;

	FTestbed1StructFloat FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat) override;

	FTestbed1StructString FuncString_Implementation(const FTestbed1StructString& ParamString) override;
};
