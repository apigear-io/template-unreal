
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
#include "TbSame2/Generated/api/AbstractTbSame2SameStruct1Interface.h"
#include "TbSame2SameStruct1Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME2_API UTbSame2SameStruct1Interface : public UAbstractTbSame2SameStruct1Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame2SameStruct1Interface();

	// properties
	FTbSame2Struct1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTbSame2Struct1& Prop1) override;

	// operations
	FTbSame2Struct1 Func1_Implementation(const FTbSame2Struct1& Param1) override;
};
