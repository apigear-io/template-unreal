
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
#include "TbSame2/Generated/api/AbstractTbSame2SameStruct2Interface.h"
#include "TbSame2SameStruct2Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME2IMPLEMENTATION_API UTbSame2SameStruct2Interface : public UAbstractTbSame2SameStruct2Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame2SameStruct2Interface();

	// properties
	FTbSame2Struct2 GetProp1() const override;
	void SetProp1(const FTbSame2Struct2& Prop1) override;

	FTbSame2Struct2 GetProp2() const override;
	void SetProp2(const FTbSame2Struct2& Prop2) override;

	// operations
	FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) override;

	FTbSame2Struct1 Func2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;
};
