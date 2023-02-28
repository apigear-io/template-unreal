
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
#include "Generated/api/TbSame1SameStruct2InterfaceInterface.h"
#include "TbSame1SameStruct2Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME1_API UTbSame1SameStruct2Interface : public UAbstractTbSame1SameStruct2Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame1SameStruct2Interface();

	// properties
	FTbSame1Struct2 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTbSame1Struct2& Prop1) override;

	FTbSame1Struct2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(const FTbSame1Struct2& Prop2) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) override{};
	FTbSame1Struct1 Func1_Implementation(const FTbSame1Struct1& Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override{};
	FTbSame1Struct1 Func2_Implementation(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;
};
