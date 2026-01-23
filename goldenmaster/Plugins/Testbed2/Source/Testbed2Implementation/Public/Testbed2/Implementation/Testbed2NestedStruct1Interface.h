// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "Testbed2/Generated/api/AbstractTestbed2NestedStruct1Interface.h"
#include "Testbed2NestedStruct1Interface.generated.h"

UCLASS(BlueprintType)
class TESTBED2IMPLEMENTATION_API UTestbed2NestedStruct1InterfaceImplementation : public UAbstractTestbed2NestedStruct1Interface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed2NestedStruct1InterfaceImplementation();

	// properties
	FTestbed2NestedStruct1 GetProp1() const override;
	void SetProp1(const FTestbed2NestedStruct1& Prop1) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface|Properties")
	void _ResetProperties();

	// operations
	void FuncNoReturnValue(const FTestbed2NestedStruct1& Param1) override;

	FTestbed2NestedStruct1 FuncNoParams() override;

	FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) override;

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	mutable FRWLock Prop1RWLock;
#endif
};
