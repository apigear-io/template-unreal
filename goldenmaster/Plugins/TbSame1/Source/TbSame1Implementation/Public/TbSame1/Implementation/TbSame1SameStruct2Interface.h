// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbSame1/Generated/api/AbstractTbSame1SameStruct2Interface.h"
#include "TbSame1SameStruct2Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME1IMPLEMENTATION_API UTbSame1SameStruct2InterfaceImplementation : public UAbstractTbSame1SameStruct2Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame1SameStruct2InterfaceImplementation();

	// properties
	FTbSame1Struct2 GetProp1() const override;
	void SetProp1(const FTbSame1Struct2& Prop1) override;

	FTbSame1Struct2 GetProp2() const override;
	void SetProp2(const FTbSame1Struct2& Prop2) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface|Properties")
	void _ResetProperties();

	// operations
	FTbSame1Struct1 Func1(const FTbSame1Struct1& Param1) override;

	FTbSame1Struct1 Func2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;
};
