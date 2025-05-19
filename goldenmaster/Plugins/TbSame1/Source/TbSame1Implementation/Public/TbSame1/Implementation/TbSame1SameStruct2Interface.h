
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
#include "TbSame1/Generated/api/AbstractTbSame1SameStruct2Interface.h"
#include "TbSame1SameStruct2Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME1IMPLEMENTATION_API UTbSame1SameStruct2InterfaceImplementation : public UAbstractTbSame1SameStruct2Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame1SameStruct2InterfaceImplementation();

	// properties
	FTbSame1Struct2 GetProp1() const override;
	void SetProp1(const FTbSame1Struct2& Prop1) override;

	FTbSame1Struct2 GetProp2() const override;
	void SetProp2(const FTbSame1Struct2& Prop2) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface|Properties")
	void _ResetProperties();

	// operations
	FTbSame1Struct1 Func1(const FTbSame1Struct1& Param1) override;

	FTbSame1Struct1 Func2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;
};
