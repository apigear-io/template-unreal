
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
#include "apig/TbSame1_apig.h"
#include "TbSame1SameStruct1InterfaceLocal.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "TbSame1SameStruct1Interface")
class TBSAME1_API UTbSame1SameStruct1InterfaceLocalService : public UObject, public ITbSame1SameStruct1InterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameStruct1InterfaceLocalService();
	virtual ~UTbSame1SameStruct1InterfaceLocalService();

	// signals
	FTbSame1SameStruct1InterfaceSig1Delegate Sig1Signal;
	FTbSame1SameStruct1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTbSame1SameStruct1InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame1SameStruct1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// properties
	void GetProp1_Implementation(FTbSame1Struct1& ReturnValue) const override;
	void SetProp1_Implementation(const FTbSame1Struct1& Prop1) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) override{};
	void Func1_Implementation(FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) override;

private:
	// properties - local copy - use setter functions to emit changed signals
	FTbSame1Struct1 Prop1;
};
