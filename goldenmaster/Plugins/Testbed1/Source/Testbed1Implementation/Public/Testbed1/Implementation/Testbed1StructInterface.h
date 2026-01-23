// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "Testbed1/Generated/api/AbstractTestbed1StructInterface.h"
#include "Testbed1StructInterface.generated.h"

UCLASS(BlueprintType)
class TESTBED1IMPLEMENTATION_API UTestbed1StructInterfaceImplementation : public UAbstractTestbed1StructInterface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed1StructInterfaceImplementation();

	// properties
	FTestbed1StructBool GetPropBool() const override;
	void SetPropBool(const FTestbed1StructBool& PropBool) override;

	FTestbed1StructInt GetPropInt() const override;
	void SetPropInt(const FTestbed1StructInt& PropInt) override;

	FTestbed1StructFloat GetPropFloat() const override;
	void SetPropFloat(const FTestbed1StructFloat& PropFloat) override;

	FTestbed1StructString GetPropString() const override;
	void SetPropString(const FTestbed1StructString& PropString) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	void _ResetProperties();

	// operations
	FTestbed1StructBool FuncBool(const FTestbed1StructBool& ParamBool) override;

	FTestbed1StructInt FuncInt(const FTestbed1StructInt& ParamInt) override;

	FTestbed1StructFloat FuncFloat(const FTestbed1StructFloat& ParamFloat) override;

	FTestbed1StructString FuncString(const FTestbed1StructString& ParamString) override;

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	mutable FRWLock PropBoolRWLock;
	mutable FRWLock PropIntRWLock;
	mutable FRWLock PropFloatRWLock;
	mutable FRWLock PropStringRWLock;
#endif
};
