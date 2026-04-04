// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "Testbed2/Generated/api/AbstractTestbed2ManyParamInterface.h"
#include "Testbed2ManyParamInterface.generated.h"

UCLASS(BlueprintType)
class TESTBED2IMPLEMENTATION_API UTestbed2ManyParamInterfaceImplementation : public UAbstractTestbed2ManyParamInterface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed2ManyParamInterfaceImplementation();

	// properties
	int32 GetProp1() const override;
	void SetProp1(int32 Prop1) override;

	int32 GetProp2() const override;
	void SetProp2(int32 Prop2) override;

	int32 GetProp3() const override;
	void SetProp3(int32 Prop3) override;

	int32 GetProp4() const override;
	void SetProp4(int32 Prop4) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	void _ResetProperties();

	// operations
	int32 Func1(int32 Param1) override;

	int32 Func2(int32 Param1, int32 Param2) override;

	int32 Func3(int32 Param1, int32 Param2, int32 Param3) override;

	int32 Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;
};
