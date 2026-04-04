// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
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
