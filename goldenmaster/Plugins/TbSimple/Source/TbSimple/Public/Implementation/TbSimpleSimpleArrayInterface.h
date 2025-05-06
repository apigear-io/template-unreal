
/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma once

#include "CoreMinimal.h"
#include "Generated/api/AbstractTbSimpleSimpleArrayInterface.h"
#include "TbSimpleSimpleArrayInterface.generated.h"

UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleSimpleArrayInterface : public UAbstractTbSimpleSimpleArrayInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleSimpleArrayInterface();

	// properties
	TArray<bool> GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(const TArray<bool>& PropBool) override;

	TArray<int32> GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(const TArray<int32>& PropInt) override;

	TArray<int32> GetPropInt32_Implementation() const override;
	void SetPropInt32_Implementation(const TArray<int32>& PropInt32) override;

	TArray<int64> GetPropInt64_Implementation() const override;
	void SetPropInt64_Implementation(const TArray<int64>& PropInt64) override;

	TArray<float> GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(const TArray<float>& PropFloat) override;

	TArray<float> GetPropFloat32_Implementation() const override;
	void SetPropFloat32_Implementation(const TArray<float>& PropFloat32) override;

	TArray<double> GetPropFloat64_Implementation() const override;
	void SetPropFloat64_Implementation(const TArray<double>& PropFloat64) override;

	TArray<FString> GetPropString_Implementation() const override;
	void SetPropString_Implementation(const TArray<FString>& PropString) override;

	FString GetPropReadOnlyString_Implementation() const override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void _ResetProperties();

	// operations
	TArray<bool> FuncBool_Implementation(const TArray<bool>& ParamBool) override;

	TArray<int32> FuncInt_Implementation(const TArray<int32>& ParamInt) override;

	TArray<int32> FuncInt32_Implementation(const TArray<int32>& ParamInt32) override;

	TArray<int64> FuncInt64_Implementation(const TArray<int64>& ParamInt64) override;

	TArray<float> FuncFloat_Implementation(const TArray<float>& ParamFloat) override;

	TArray<float> FuncFloat32_Implementation(const TArray<float>& ParamFloat32) override;

	TArray<double> FuncFloat64_Implementation(const TArray<double>& ParamFloat) override;

	TArray<FString> FuncString_Implementation(const TArray<FString>& ParamString) override;
};
