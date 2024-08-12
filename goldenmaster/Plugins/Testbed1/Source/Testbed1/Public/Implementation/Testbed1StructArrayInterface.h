
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
#include "Generated/api/AbstractTestbed1StructArrayInterface.h"
#include "Testbed1StructArrayInterface.generated.h"

UCLASS(BlueprintType)
class TESTBED1_API UTestbed1StructArrayInterface : public UAbstractTestbed1StructArrayInterface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed1StructArrayInterface();

	// properties
	TArray<FTestbed1StructBool> GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(const TArray<FTestbed1StructBool>& PropBool) override;

	TArray<FTestbed1StructInt> GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(const TArray<FTestbed1StructInt>& PropInt) override;

	TArray<FTestbed1StructFloat> GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& PropFloat) override;

	TArray<FTestbed1StructString> GetPropString_Implementation() const override;
	void SetPropString_Implementation(const TArray<FTestbed1StructString>& PropString) override;

	// operations
	TArray<FTestbed1StructBool> FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool) override;

	TArray<FTestbed1StructInt> FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt) override;

	TArray<FTestbed1StructFloat> FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat) override;

	TArray<FTestbed1StructString> FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString) override;
};
