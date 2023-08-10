
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
#include "Generated/api/AbstractTbSimpleSimpleInterface.h"
#include "TbSimpleSimpleInterface.generated.h"

UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleSimpleInterface : public UAbstractTbSimpleSimpleInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleSimpleInterface();

	// properties
	bool GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(bool bPropBool) override;

	int32 GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(int32 PropInt) override;

	int32 GetPropInt32_Implementation() const override;
	void SetPropInt32_Implementation(int32 PropInt32) override;

	int64 GetPropInt64_Implementation() const override;
	void SetPropInt64_Implementation(int64 PropInt64) override;

	float GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(float PropFloat) override;

	float GetPropFloat32_Implementation() const override;
	void SetPropFloat32_Implementation(float PropFloat32) override;

	double GetPropFloat64_Implementation() const override;
	void SetPropFloat64_Implementation(double PropFloat64) override;

	FString GetPropString_Implementation() const override;
	void SetPropString_Implementation(const FString& PropString) override;

	FString GetPropReadOnlyString_Implementation() const override;

	// operations
	void FuncVoid_Implementation() override;

	bool FuncBool_Implementation(bool bParamBool) override;

	int32 FuncInt_Implementation(int32 ParamInt) override;

	int32 FuncInt32_Implementation(int32 ParamInt32) override;

	int64 FuncInt64_Implementation(int64 ParamInt64) override;

	float FuncFloat_Implementation(float ParamFloat) override;

	float FuncFloat32_Implementation(float ParamFloat32) override;

	double FuncFloat64_Implementation(double ParamFloat) override;

	FString FuncString_Implementation(const FString& ParamString) override;
};
