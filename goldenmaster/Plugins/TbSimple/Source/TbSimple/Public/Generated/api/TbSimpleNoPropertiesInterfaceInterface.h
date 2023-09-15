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

#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "TbSimple_data.h"
#include "TbSimpleNoPropertiesInterfaceInterface.generated.h"

/**
 * Declaration for NoPropertiesInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbSimpleNoPropertiesInterfaceSigVoidDelegate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoPropertiesInterfaceSigBoolDelegate, bool, bParamBool);

// property delegates

/**
 * Class UTbSimpleNoPropertiesInterfaceInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleNoPropertiesInterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Signals", DisplayName = "SigVoid Signal")
	FTbSimpleNoPropertiesInterfaceSigVoidDelegate OnSigVoidSignal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Signals", DisplayName = "SigBool Signal")
	FTbSimpleNoPropertiesInterfaceSigBoolDelegate OnSigBoolSignal;
};

/**
 * Interface UTbSimpleNoPropertiesInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSimpleNoPropertiesInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSimpleNoPropertiesInterfaceInterface
 */
class TBSIMPLE_API ITbSimpleNoPropertiesInterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface")
	UTbSimpleNoPropertiesInterfaceSignals* _GetSignals();
	virtual UTbSimpleNoPropertiesInterfaceSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Operations")
	void FuncVoid();
	virtual void FuncVoid_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Operations")
	bool FuncBool(bool bParamBool);
	virtual bool FuncBool_Implementation(bool bParamBool) = 0;

	// properties
};
