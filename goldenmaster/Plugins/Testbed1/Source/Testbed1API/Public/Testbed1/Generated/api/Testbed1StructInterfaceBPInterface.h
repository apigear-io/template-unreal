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
#include "Testbed1StructInterfaceInterface.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "Testbed1_data.h"
#include "Testbed1StructInterfaceBPInterface.generated.h"

/**
 * Interface UTestbed1StructInterfaceBPInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTestbed1StructInterfaceBPInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed1StructInterfaceBPInterface
 */
class TESTBED1API_API ITestbed1StructInterfaceBPInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	UTestbed1StructInterfacePublisher* _GetPublisher();
	virtual UTestbed1StructInterfacePublisher* _GetPublisher_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Operations")
	FTestbed1StructBool FuncBool(const FTestbed1StructBool& ParamBool);
	virtual FTestbed1StructBool FuncBool_Implementation(const FTestbed1StructBool& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Operations")
	FTestbed1StructInt FuncInt(const FTestbed1StructInt& ParamInt);
	virtual FTestbed1StructInt FuncInt_Implementation(const FTestbed1StructInt& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Operations")
	FTestbed1StructFloat FuncFloat(const FTestbed1StructFloat& ParamFloat);
	virtual FTestbed1StructFloat FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Operations")
	FTestbed1StructString FuncString(const FTestbed1StructString& ParamString);
	virtual FTestbed1StructString FuncString_Implementation(const FTestbed1StructString& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	FTestbed1StructBool GetPropBool() const;
	virtual FTestbed1StructBool GetPropBool_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	void SetPropBool(const FTestbed1StructBool& InPropBool);
	virtual void SetPropBool_Implementation(UPARAM(DisplayName = "PropBool") const FTestbed1StructBool& InPropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	FTestbed1StructInt GetPropInt() const;
	virtual FTestbed1StructInt GetPropInt_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	void SetPropInt(const FTestbed1StructInt& InPropInt);
	virtual void SetPropInt_Implementation(UPARAM(DisplayName = "PropInt") const FTestbed1StructInt& InPropInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	FTestbed1StructFloat GetPropFloat() const;
	virtual FTestbed1StructFloat GetPropFloat_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	void SetPropFloat(const FTestbed1StructFloat& InPropFloat);
	virtual void SetPropFloat_Implementation(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloat& InPropFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	FTestbed1StructString GetPropString() const;
	virtual FTestbed1StructString GetPropString_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	void SetPropString(const FTestbed1StructString& InPropString);
	virtual void SetPropString_Implementation(UPARAM(DisplayName = "PropString") const FTestbed1StructString& InPropString) = 0;
};
