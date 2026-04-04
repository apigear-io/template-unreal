// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbSame2/Generated/api/AbstractTbSame2SameEnum2Interface.h"
#include "TbSame2SameEnum2Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME2IMPLEMENTATION_API UTbSame2SameEnum2InterfaceImplementation : public UAbstractTbSame2SameEnum2Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame2SameEnum2InterfaceImplementation();

	// properties
	ETbSame2Enum1 GetProp1() const override;
	void SetProp1(ETbSame2Enum1 Prop1) override;

	ETbSame2Enum2 GetProp2() const override;
	void SetProp2(ETbSame2Enum2 Prop2) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties")
	void _ResetProperties();

	// operations
	ETbSame2Enum1 Func1(ETbSame2Enum1 Param1) override;

	ETbSame2Enum1 Func2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;
};
