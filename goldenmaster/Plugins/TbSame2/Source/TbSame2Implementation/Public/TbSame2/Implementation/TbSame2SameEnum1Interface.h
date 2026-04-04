// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbSame2/Generated/api/AbstractTbSame2SameEnum1Interface.h"
#include "TbSame2SameEnum1Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME2IMPLEMENTATION_API UTbSame2SameEnum1InterfaceImplementation : public UAbstractTbSame2SameEnum1Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame2SameEnum1InterfaceImplementation();

	// properties
	ETbSame2Enum1 GetProp1() const override;
	void SetProp1(ETbSame2Enum1 Prop1) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum1Interface|Properties")
	void _ResetProperties();

	// operations
	ETbSame2Enum1 Func1(ETbSame2Enum1 Param1) override;
};
