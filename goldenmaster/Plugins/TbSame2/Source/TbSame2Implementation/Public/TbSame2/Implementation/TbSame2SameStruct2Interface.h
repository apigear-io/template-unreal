// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbSame2/Generated/api/AbstractTbSame2SameStruct2Interface.h"
#include "TbSame2SameStruct2Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME2IMPLEMENTATION_API UTbSame2SameStruct2InterfaceImplementation : public UAbstractTbSame2SameStruct2Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame2SameStruct2InterfaceImplementation();

	// properties
	FTbSame2Struct2 GetProp1() const override;
	void SetProp1(const FTbSame2Struct2& Prop1) override;

	FTbSame2Struct2 GetProp2() const override;
	void SetProp2(const FTbSame2Struct2& Prop2) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Properties")
	void _ResetProperties();

	// operations
	FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) override;

	FTbSame2Struct1 Func2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;
};
