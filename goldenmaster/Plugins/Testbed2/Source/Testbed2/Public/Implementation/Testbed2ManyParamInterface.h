
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
#include "Generated/api/AbstractTestbed2ManyParamInterface.h"
#include "Testbed2ManyParamInterface.generated.h"

UCLASS(BlueprintType)
class TESTBED2_API UTestbed2ManyParamInterface : public UAbstractTestbed2ManyParamInterface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed2ManyParamInterface();

	// properties
	int32 GetProp1_Implementation() const override;
	void SetProp1_Implementation(int32 Prop1) override;

	int32 GetProp2_Implementation() const override;
	void SetProp2_Implementation(int32 Prop2) override;

	int32 GetProp3_Implementation() const override;
	void SetProp3_Implementation(int32 Prop3) override;

	int32 GetProp4_Implementation() const override;
	void SetProp4_Implementation(int32 Prop4) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	void _ResetProperties();

	// operations
	int32 Func1_Implementation(int32 Param1) override;

	int32 Func2_Implementation(int32 Param1, int32 Param2) override;

	int32 Func3_Implementation(int32 Param1, int32 Param2, int32 Param3) override;

	int32 Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;
};
