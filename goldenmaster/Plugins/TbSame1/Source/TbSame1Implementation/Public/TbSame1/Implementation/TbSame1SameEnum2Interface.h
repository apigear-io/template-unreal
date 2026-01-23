// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbSame1/Generated/api/AbstractTbSame1SameEnum2Interface.h"
#include "TbSame1SameEnum2Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME1IMPLEMENTATION_API UTbSame1SameEnum2InterfaceImplementation : public UAbstractTbSame1SameEnum2Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame1SameEnum2InterfaceImplementation();

	// properties
	ETbSame1Enum1 GetProp1() const override;
	void SetProp1(ETbSame1Enum1 Prop1) override;

	ETbSame1Enum2 GetProp2() const override;
	void SetProp2(ETbSame1Enum2 Prop2) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Properties")
	void _ResetProperties();

	// operations
	ETbSame1Enum1 Func1(ETbSame1Enum1 Param1) override;

	ETbSame1Enum1 Func2(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) override;

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	mutable FRWLock Prop1RWLock;
	mutable FRWLock Prop2RWLock;
#endif
};
