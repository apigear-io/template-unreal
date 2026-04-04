// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbSimple/Generated/api/AbstractTbSimpleSimpleArrayInterface.h"
#include "TbSimpleSimpleArrayInterface.generated.h"

UCLASS(BlueprintType)
class TBSIMPLEIMPLEMENTATION_API UTbSimpleSimpleArrayInterfaceImplementation : public UAbstractTbSimpleSimpleArrayInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleSimpleArrayInterfaceImplementation();

	// properties
	TArray<bool> GetPropBool() const override;
	void SetPropBool(const TArray<bool>& PropBool) override;

	TArray<int32> GetPropInt() const override;
	void SetPropInt(const TArray<int32>& PropInt) override;

	TArray<int32> GetPropInt32() const override;
	void SetPropInt32(const TArray<int32>& PropInt32) override;

	TArray<int64> GetPropInt64() const override;
	void SetPropInt64(const TArray<int64>& PropInt64) override;

	TArray<float> GetPropFloat() const override;
	void SetPropFloat(const TArray<float>& PropFloat) override;

	TArray<float> GetPropFloat32() const override;
	void SetPropFloat32(const TArray<float>& PropFloat32) override;

	TArray<double> GetPropFloat64() const override;
	void SetPropFloat64(const TArray<double>& PropFloat64) override;

	TArray<FString> GetPropString() const override;
	void SetPropString(const TArray<FString>& PropString) override;

	FString GetPropReadOnlyString() const override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void _ResetProperties();

	// operations
	TArray<bool> FuncBool(const TArray<bool>& ParamBool) override;

	TArray<int32> FuncInt(const TArray<int32>& ParamInt) override;

	TArray<int32> FuncInt32(const TArray<int32>& ParamInt32) override;

	TArray<int64> FuncInt64(const TArray<int64>& ParamInt64) override;

	TArray<float> FuncFloat(const TArray<float>& ParamFloat) override;

	TArray<float> FuncFloat32(const TArray<float>& ParamFloat32) override;

	TArray<double> FuncFloat64(const TArray<double>& ParamFloat) override;

	TArray<FString> FuncString(const TArray<FString>& ParamString) override;
};
