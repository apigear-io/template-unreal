
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
#include "Generated/api/AbstractTbSame2SameStruct2Interface.h"
#include "TbSame2SameStruct2Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME2_API UTbSame2SameStruct2Interface : public UAbstractTbSame2SameStruct2Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame2SameStruct2Interface();

	// properties
	FTbSame2Struct2 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTbSame2Struct2& Prop1) override;

	FTbSame2Struct2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(const FTbSame2Struct2& Prop2) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Properties")
	void _ResetProperties();

	// operations
	FTbSame2Struct1 Func1_Implementation(const FTbSame2Struct1& Param1) override;

	FTbSame2Struct1 Func2_Implementation(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;
};
