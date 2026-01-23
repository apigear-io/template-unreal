// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "Testbed1/Generated/api/AbstractTestbed1StructArray2Interface.h"
#include "Testbed1StructArray2Interface.generated.h"

UCLASS(BlueprintType)
class TESTBED1IMPLEMENTATION_API UTestbed1StructArray2InterfaceImplementation : public UAbstractTestbed1StructArray2Interface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed1StructArray2InterfaceImplementation();

	// properties
	FTestbed1StructBoolWithArray GetPropBool() const override;
	void SetPropBool(const FTestbed1StructBoolWithArray& PropBool) override;

	FTestbed1StructIntWithArray GetPropInt() const override;
	void SetPropInt(const FTestbed1StructIntWithArray& PropInt) override;

	FTestbed1StructFloatWithArray GetPropFloat() const override;
	void SetPropFloat(const FTestbed1StructFloatWithArray& PropFloat) override;

	FTestbed1StructStringWithArray GetPropString() const override;
	void SetPropString(const FTestbed1StructStringWithArray& PropString) override;

	FTestbed1StructEnumWithArray GetPropEnum() const override;
	void SetPropEnum(const FTestbed1StructEnumWithArray& PropEnum) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	void _ResetProperties();

	// operations
	TArray<FTestbed1StructBool> FuncBool(const FTestbed1StructBoolWithArray& ParamBool) override;

	TArray<FTestbed1StructInt> FuncInt(const FTestbed1StructIntWithArray& ParamInt) override;

	TArray<FTestbed1StructFloat> FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat) override;

	TArray<FTestbed1StructString> FuncString(const FTestbed1StructStringWithArray& ParamString) override;

	TArray<ETestbed1Enum0> FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum) override;

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	mutable FRWLock PropBoolRWLock;
	mutable FRWLock PropIntRWLock;
	mutable FRWLock PropFloatRWLock;
	mutable FRWLock PropStringRWLock;
	mutable FRWLock PropEnumRWLock;
#endif
};
