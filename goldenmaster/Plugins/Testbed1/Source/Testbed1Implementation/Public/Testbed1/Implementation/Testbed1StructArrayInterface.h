// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "Testbed1/Generated/api/AbstractTestbed1StructArrayInterface.h"
#include "Testbed1StructArrayInterface.generated.h"

UCLASS(BlueprintType)
class TESTBED1IMPLEMENTATION_API UTestbed1StructArrayInterfaceImplementation : public UAbstractTestbed1StructArrayInterface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed1StructArrayInterfaceImplementation();

	// properties
	TArray<FTestbed1StructBool> GetPropBool() const override;
	void SetPropBool(const TArray<FTestbed1StructBool>& PropBool) override;

	TArray<FTestbed1StructInt> GetPropInt() const override;
	void SetPropInt(const TArray<FTestbed1StructInt>& PropInt) override;

	TArray<FTestbed1StructFloat> GetPropFloat() const override;
	void SetPropFloat(const TArray<FTestbed1StructFloat>& PropFloat) override;

	TArray<FTestbed1StructString> GetPropString() const override;
	void SetPropString(const TArray<FTestbed1StructString>& PropString) override;

	TArray<ETestbed1Enum0> GetPropEnum() const override;
	void SetPropEnum(const TArray<ETestbed1Enum0>& PropEnum) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	void _ResetProperties();

	// operations
	TArray<FTestbed1StructBool> FuncBool(const TArray<FTestbed1StructBool>& ParamBool) override;

	TArray<FTestbed1StructInt> FuncInt(const TArray<FTestbed1StructInt>& ParamInt) override;

	TArray<FTestbed1StructFloat> FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat) override;

	TArray<FTestbed1StructString> FuncString(const TArray<FTestbed1StructString>& ParamString) override;

	TArray<ETestbed1Enum0> FuncEnum(const TArray<ETestbed1Enum0>& ParamEnum) override;

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	mutable FRWLock PropBoolRWLock;
	mutable FRWLock PropIntRWLock;
	mutable FRWLock PropFloatRWLock;
	mutable FRWLock PropStringRWLock;
	mutable FRWLock PropEnumRWLock;
#endif
};
