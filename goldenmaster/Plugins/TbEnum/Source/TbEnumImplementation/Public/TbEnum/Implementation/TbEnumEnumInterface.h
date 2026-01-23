// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbEnum/Generated/api/AbstractTbEnumEnumInterface.h"
#include "TbEnumEnumInterface.generated.h"

UCLASS(BlueprintType)
class TBENUMIMPLEMENTATION_API UTbEnumEnumInterfaceImplementation : public UAbstractTbEnumEnumInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbEnumEnumInterfaceImplementation();

	// properties
	ETbEnumEnum0 GetProp0() const override;
	void SetProp0(ETbEnumEnum0 Prop0) override;

	ETbEnumEnum1 GetProp1() const override;
	void SetProp1(ETbEnumEnum1 Prop1) override;

	ETbEnumEnum2 GetProp2() const override;
	void SetProp2(ETbEnumEnum2 Prop2) override;

	ETbEnumEnum3 GetProp3() const override;
	void SetProp3(ETbEnumEnum3 Prop3) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	void _ResetProperties();

	// operations
	ETbEnumEnum0 Func0(ETbEnumEnum0 Param0) override;

	ETbEnumEnum1 Func1(ETbEnumEnum1 Param1) override;

	ETbEnumEnum2 Func2(ETbEnumEnum2 Param2) override;

	ETbEnumEnum3 Func3(ETbEnumEnum3 Param3) override;

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	mutable FRWLock Prop0RWLock;
	mutable FRWLock Prop1RWLock;
	mutable FRWLock Prop2RWLock;
	mutable FRWLock Prop3RWLock;
#endif
};
