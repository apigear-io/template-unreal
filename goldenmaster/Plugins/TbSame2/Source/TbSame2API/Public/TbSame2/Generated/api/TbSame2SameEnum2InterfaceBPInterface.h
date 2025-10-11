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
#include "TbSame2SameEnum2InterfaceInterface.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "TbSame2_data.h"
#include "TbSame2SameEnum2InterfaceBPInterface.generated.h"

/**
 * Interface UTbSame2SameEnum2InterfaceBPInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSame2SameEnum2InterfaceBPInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame2SameEnum2InterfaceBPInterface
 */
class TBSAME2API_API ITbSame2SameEnum2InterfaceBPInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface")
	UTbSame2SameEnum2InterfacePublisher* _GetPublisher();
	virtual UTbSame2SameEnum2InterfacePublisher* _GetPublisher_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Operations")
	ETbSame2Enum1 Func1(ETbSame2Enum1 Param1);
	virtual ETbSame2Enum1 Func1_Implementation(ETbSame2Enum1 Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Operations")
	ETbSame2Enum1 Func2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);
	virtual ETbSame2Enum1 Func2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties")
	ETbSame2Enum1 GetProp1() const;
	virtual ETbSame2Enum1 GetProp1_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties")
	void SetProp1(ETbSame2Enum1 InProp1);
	virtual void SetProp1_Implementation(UPARAM(DisplayName = "Prop1") ETbSame2Enum1 InProp1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties")
	ETbSame2Enum2 GetProp2() const;
	virtual ETbSame2Enum2 GetProp2_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties")
	void SetProp2(ETbSame2Enum2 InProp2);
	virtual void SetProp2_Implementation(UPARAM(DisplayName = "Prop2") ETbSame2Enum2 InProp2) = 0;
};
