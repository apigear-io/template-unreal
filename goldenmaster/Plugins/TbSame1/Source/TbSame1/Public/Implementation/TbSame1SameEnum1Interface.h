
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
#include "Generated/api/TbSame1SameEnum1InterfaceInterface.h"
#include "TbSame1SameEnum1Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME1_API UTbSame1SameEnum1Interface : public UAbstractTbSame1SameEnum1Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame1SameEnum1Interface();

	// properties
	ETbSame1Enum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(ETbSame1Enum1 Prop1) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1) override{};
	ETbSame1Enum1 Func1_Implementation(ETbSame1Enum1 Param1) override;
};
