// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbSame1/Generated/api/AbstractTbSame1SameStruct1Interface.h"
#include "TbSame1SameStruct1Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME1IMPLEMENTATION_API UTbSame1SameStruct1InterfaceImplementation : public UAbstractTbSame1SameStruct1Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame1SameStruct1InterfaceImplementation();

	// properties
	FTbSame1Struct1 GetProp1() const override;
	void SetProp1(const FTbSame1Struct1& Prop1) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Properties")
	void _ResetProperties();

	// operations
	FTbSame1Struct1 Func1(const FTbSame1Struct1& Param1) override;

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	mutable FRWLock Prop1RWLock;
#endif
};
