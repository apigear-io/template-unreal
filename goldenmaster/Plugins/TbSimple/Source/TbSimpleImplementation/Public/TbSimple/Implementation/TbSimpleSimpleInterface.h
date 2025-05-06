
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
#include "TbSimple/Generated/api/AbstractTbSimpleSimpleInterface.h"
#include "TbSimpleSimpleInterface.generated.h"

UCLASS(BlueprintType)
class TBSIMPLEIMPLEMENTATION_API UTbSimpleSimpleInterface : public UAbstractTbSimpleSimpleInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleSimpleInterface();

	// properties
	bool GetPropBool() const override;
	void SetPropBool(bool bPropBool) override;

	int32 GetPropInt() const override;
	void SetPropInt(int32 PropInt) override;

	int32 GetPropInt32() const override;
	void SetPropInt32(int32 PropInt32) override;

	int64 GetPropInt64() const override;
	void SetPropInt64(int64 PropInt64) override;

	float GetPropFloat() const override;
	void SetPropFloat(float PropFloat) override;

	float GetPropFloat32() const override;
	void SetPropFloat32(float PropFloat32) override;

	double GetPropFloat64() const override;
	void SetPropFloat64(double PropFloat64) override;

	FString GetPropString() const override;
	void SetPropString(const FString& PropString) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	void _ResetProperties();

	// operations
	void FuncNoReturnValue(bool bParamBool) override;

	bool FuncBool(bool bParamBool) override;

	int32 FuncInt(int32 ParamInt) override;

	int32 FuncInt32(int32 ParamInt32) override;

	int64 FuncInt64(int64 ParamInt64) override;

	float FuncFloat(float ParamFloat) override;

	float FuncFloat32(float ParamFloat32) override;

	double FuncFloat64(double ParamFloat) override;

	FString FuncString(const FString& ParamString) override;
};
