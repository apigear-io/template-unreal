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
#include "TbNamesNamEsInterface.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "TbNames_data.h"
#include "TbNamesNamEsBPInterface.generated.h"

/**
 * Interface UTbNamesNamEsBPInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbNamesNamEsBPInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbNamesNamEsBPInterface
 */
class TBNAMESAPI_API ITbNamesNamEsBPInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs")
	UTbNamesNamEsSignals* _GetSignals();
	virtual UTbNamesNamEsSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Operations")
	void SomeFunction(bool bSomeParam);
	virtual void SomeFunction_Implementation(bool bSomeParam) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Operations")
	void SomeFunction2(bool bSomeParam);
	virtual void SomeFunction2_Implementation(bool bSomeParam) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	bool GetSwitch() const;
	virtual bool GetSwitch_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	void SetSwitch(bool bInSwitch);
	virtual void SetSwitch_Implementation(UPARAM(DisplayName = "bSwitch") bool bInSwitch) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	int32 GetSomeProperty() const;
	virtual int32 GetSomeProperty_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	void SetSomeProperty(int32 InSomeProperty);
	virtual void SetSomeProperty_Implementation(UPARAM(DisplayName = "SomeProperty") int32 InSomeProperty) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	int32 GetSomePoperty2() const;
	virtual int32 GetSomePoperty2_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	void SetSomePoperty2(int32 InSomePoperty2);
	virtual void SetSomePoperty2_Implementation(UPARAM(DisplayName = "SomePoperty2") int32 InSomePoperty2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	ETbNamesEnum_With_Under_scores GetEnumProperty() const;
	virtual ETbNamesEnum_With_Under_scores GetEnumProperty_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	void SetEnumProperty(ETbNamesEnum_With_Under_scores InEnumProperty);
	virtual void SetEnumProperty_Implementation(UPARAM(DisplayName = "EnumProperty") ETbNamesEnum_With_Under_scores InEnumProperty) = 0;
};
