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
#include "TbSame2SameStruct1InterfaceInterface.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "TbSame2_data.h"
#include "TbSame2SameStruct1InterfaceBPInterface.generated.h"

/**
 * Interface UTbSame2SameStruct1InterfaceBPInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSame2SameStruct1InterfaceBPInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame2SameStruct1InterfaceBPInterface
 */
class TBSAME2API_API ITbSame2SameStruct1InterfaceBPInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface")
	UTbSame2SameStruct1InterfacePublisher* _GetPublisher();
	virtual UTbSame2SameStruct1InterfacePublisher* _GetPublisher_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1);
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Operations")
	FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1);
	virtual FTbSame2Struct1 Func1_Implementation(const FTbSame2Struct1& Param1) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Properties")
	FTbSame2Struct1 GetProp1() const;
	virtual FTbSame2Struct1 GetProp1_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Properties")
	void SetProp1(const FTbSame2Struct1& InProp1);
	virtual void SetProp1_Implementation(UPARAM(DisplayName = "Prop1") const FTbSame2Struct1& InProp1) = 0;
};
