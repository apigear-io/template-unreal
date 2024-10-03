
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
#include "Testbed2/Generated/api/AbstractTestbed2NestedStruct1Interface.h"
#include "Testbed2NestedStruct1Interface.generated.h"

UCLASS(BlueprintType)
class TESTBED2_API UTestbed2NestedStruct1Interface : public UAbstractTestbed2NestedStruct1Interface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed2NestedStruct1Interface();

	// properties
	FTestbed2NestedStruct1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTestbed2NestedStruct1& Prop1) override;

	// operations
	FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) override;
};
