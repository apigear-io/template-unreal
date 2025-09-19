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
#include "TbEnumEnumInterfaceInterface.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "TbEnum_data.h"
#include "TbEnumEnumInterfaceBPInterface.generated.h"

/**
 * Interface UTbEnumEnumInterfaceBPInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbEnumEnumInterfaceBPInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbEnumEnumInterfaceBPInterface
 */
class TBENUMAPI_API ITbEnumEnumInterfaceBPInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	UTbEnumEnumInterfacePublisher* _GetPublisher();
	virtual UTbEnumEnumInterfacePublisher* _GetPublisher_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func0Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0);
	virtual void Func0Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations")
	ETbEnumEnum0 Func0(ETbEnumEnum0 Param0);
	virtual ETbEnumEnum0 Func0_Implementation(ETbEnumEnum0 Param0) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1);
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations")
	ETbEnumEnum1 Func1(ETbEnumEnum1 Param1);
	virtual ETbEnumEnum1 Func1_Implementation(ETbEnumEnum1 Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2);
	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations")
	ETbEnumEnum2 Func2(ETbEnumEnum2 Param2);
	virtual ETbEnumEnum2 Func2_Implementation(ETbEnumEnum2 Param2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3);
	virtual void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Operations")
	ETbEnumEnum3 Func3(ETbEnumEnum3 Param3);
	virtual ETbEnumEnum3 Func3_Implementation(ETbEnumEnum3 Param3) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	ETbEnumEnum0 GetProp0() const;
	virtual ETbEnumEnum0 GetProp0_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	void SetProp0(ETbEnumEnum0 InProp0);
	virtual void SetProp0_Implementation(UPARAM(DisplayName = "Prop0") ETbEnumEnum0 InProp0) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	ETbEnumEnum1 GetProp1() const;
	virtual ETbEnumEnum1 GetProp1_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	void SetProp1(ETbEnumEnum1 InProp1);
	virtual void SetProp1_Implementation(UPARAM(DisplayName = "Prop1") ETbEnumEnum1 InProp1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	ETbEnumEnum2 GetProp2() const;
	virtual ETbEnumEnum2 GetProp2_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	void SetProp2(ETbEnumEnum2 InProp2);
	virtual void SetProp2_Implementation(UPARAM(DisplayName = "Prop2") ETbEnumEnum2 InProp2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	ETbEnumEnum3 GetProp3() const;
	virtual ETbEnumEnum3 GetProp3_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	void SetProp3(ETbEnumEnum3 InProp3);
	virtual void SetProp3_Implementation(UPARAM(DisplayName = "Prop3") ETbEnumEnum3 InProp3) = 0;
};
