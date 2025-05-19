
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
#include "Testbed2/Generated/api/AbstractTestbed2NestedStruct3Interface.h"
#include "Testbed2NestedStruct3Interface.generated.h"

UCLASS(BlueprintType)
class TESTBED2IMPLEMENTATION_API UTestbed2NestedStruct3InterfaceImplementation : public UAbstractTestbed2NestedStruct3Interface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed2NestedStruct3InterfaceImplementation();

	// properties
	FTestbed2NestedStruct1 GetProp1() const override;
	void SetProp1(const FTestbed2NestedStruct1& Prop1) override;

	FTestbed2NestedStruct2 GetProp2() const override;
	void SetProp2(const FTestbed2NestedStruct2& Prop2) override;

	FTestbed2NestedStruct3 GetProp3() const override;
	void SetProp3(const FTestbed2NestedStruct3& Prop3) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	void _ResetProperties();

	// operations
	FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) override;

	FTestbed2NestedStruct1 Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;

	FTestbed2NestedStruct1 Func3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) override;
};
