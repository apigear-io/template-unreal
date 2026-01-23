// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbSame1/Generated/api/AbstractTbSame1SameEnum1Interface.h"
#include "TbSame1SameEnum1Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME1IMPLEMENTATION_API UTbSame1SameEnum1InterfaceImplementation : public UAbstractTbSame1SameEnum1Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame1SameEnum1InterfaceImplementation();

	// properties
	ETbSame1Enum1 GetProp1() const override;
	void SetProp1(ETbSame1Enum1 Prop1) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface|Properties")
	void _ResetProperties();

	// operations
	ETbSame1Enum1 Func1(ETbSame1Enum1 Param1) override;

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	mutable FRWLock Prop1RWLock;
#endif
};
