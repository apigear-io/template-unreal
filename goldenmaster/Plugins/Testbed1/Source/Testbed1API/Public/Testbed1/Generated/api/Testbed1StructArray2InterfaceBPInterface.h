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
#include "Testbed1StructArray2InterfaceInterface.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "Testbed1_data.h"
#include "Testbed1StructArray2InterfaceBPInterface.generated.h"

/**
 * Interface UTestbed1StructArray2InterfaceBPInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTestbed1StructArray2InterfaceBPInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed1StructArray2InterfaceBPInterface
 */
class TESTBED1API_API ITestbed1StructArray2InterfaceBPInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface")
	UTestbed1StructArray2InterfacePublisher* _GetPublisher();
	virtual UTestbed1StructArray2InterfacePublisher* _GetPublisher_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	TArray<FTestbed1StructBool> FuncBool(const FTestbed1StructBoolWithArray& ParamBool);
	virtual TArray<FTestbed1StructBool> FuncBool_Implementation(const FTestbed1StructBoolWithArray& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	TArray<FTestbed1StructInt> FuncInt(const FTestbed1StructIntWithArray& ParamInt);
	virtual TArray<FTestbed1StructInt> FuncInt_Implementation(const FTestbed1StructIntWithArray& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	TArray<FTestbed1StructFloat> FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat);
	virtual TArray<FTestbed1StructFloat> FuncFloat_Implementation(const FTestbed1StructFloatWithArray& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	TArray<FTestbed1StructString> FuncString(const FTestbed1StructStringWithArray& ParamString);
	virtual TArray<FTestbed1StructString> FuncString_Implementation(const FTestbed1StructStringWithArray& ParamString) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	TArray<ETestbed1Enum0> FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum);
	virtual TArray<ETestbed1Enum0> FuncEnum_Implementation(const FTestbed1StructEnumWithArray& ParamEnum) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	FTestbed1StructBoolWithArray GetPropBool() const;
	virtual FTestbed1StructBoolWithArray GetPropBool_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	void SetPropBool(const FTestbed1StructBoolWithArray& InPropBool);
	virtual void SetPropBool_Implementation(UPARAM(DisplayName = "PropBool") const FTestbed1StructBoolWithArray& InPropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	FTestbed1StructIntWithArray GetPropInt() const;
	virtual FTestbed1StructIntWithArray GetPropInt_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	void SetPropInt(const FTestbed1StructIntWithArray& InPropInt);
	virtual void SetPropInt_Implementation(UPARAM(DisplayName = "PropInt") const FTestbed1StructIntWithArray& InPropInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	FTestbed1StructFloatWithArray GetPropFloat() const;
	virtual FTestbed1StructFloatWithArray GetPropFloat_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	void SetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat);
	virtual void SetPropFloat_Implementation(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloatWithArray& InPropFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	FTestbed1StructStringWithArray GetPropString() const;
	virtual FTestbed1StructStringWithArray GetPropString_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	void SetPropString(const FTestbed1StructStringWithArray& InPropString);
	virtual void SetPropString_Implementation(UPARAM(DisplayName = "PropString") const FTestbed1StructStringWithArray& InPropString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	FTestbed1StructEnumWithArray GetPropEnum() const;
	virtual FTestbed1StructEnumWithArray GetPropEnum_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	void SetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum);
	virtual void SetPropEnum_Implementation(UPARAM(DisplayName = "PropEnum") const FTestbed1StructEnumWithArray& InPropEnum) = 0;
};
