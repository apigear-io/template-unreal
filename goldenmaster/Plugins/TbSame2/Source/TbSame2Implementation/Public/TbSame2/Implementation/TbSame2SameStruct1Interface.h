// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbSame2/Generated/api/AbstractTbSame2SameStruct1Interface.h"
#include "TbSame2SameStruct1Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME2IMPLEMENTATION_API UTbSame2SameStruct1InterfaceImplementation : public UAbstractTbSame2SameStruct1Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame2SameStruct1InterfaceImplementation();

	// properties
	FTbSame2Struct1 GetProp1() const override;
	void SetProp1(const FTbSame2Struct1& Prop1) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Properties")
	void _ResetProperties();

	// operations
	FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) override;
};
