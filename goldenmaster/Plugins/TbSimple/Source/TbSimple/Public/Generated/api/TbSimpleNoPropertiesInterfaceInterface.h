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

#include "UObject/Interface.h"
#include "Engine/LatentActionManager.h"
#include "Subsystems/GameInstanceSubsystem.h"
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
	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|NoPropertiesInterface")
	virtual FTbSimpleNoPropertiesInterfaceSigVoidDelegate& GetSigVoidSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|NoPropertiesInterface")
	virtual FTbSimpleNoPropertiesInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface")
	void FuncVoid();
	virtual void FuncVoid_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface")
	bool FuncBool(bool bParamBool);
	virtual bool FuncBool_Implementation(bool bParamBool) = 0;

	// properties

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigVoid();
	virtual void BroadcastSigVoid_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigBool(bool bParamBool);
	virtual void BroadcastSigBool_Implementation(bool bParamBool) = 0;
};

/**
 * Abstract UAbstractTbSimpleNoPropertiesInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSIMPLE_API UAbstractTbSimpleNoPropertiesInterface : public UGameInstanceSubsystem, public ITbSimpleNoPropertiesInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoPropertiesInterface", DisplayName = "SigVoid Signal")
	FTbSimpleNoPropertiesInterfaceSigVoidDelegate SigVoidSignal;
	virtual FTbSimpleNoPropertiesInterfaceSigVoidDelegate& GetSigVoidSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoPropertiesInterface", DisplayName = "SigBool Signal")
	FTbSimpleNoPropertiesInterfaceSigBoolDelegate SigBoolSignal;
	virtual FTbSimpleNoPropertiesInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	// methods
	virtual void FuncVoid_Implementation() override PURE_VIRTUAL(UAbstractTbSimpleNoPropertiesInterface::FuncVoid_Implementation, return;);

	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override PURE_VIRTUAL(UAbstractTbSimpleNoPropertiesInterface::FuncBoolAsync_Implementation, return;);
	virtual bool FuncBool_Implementation(bool bParamBool) override PURE_VIRTUAL(UAbstractTbSimpleNoPropertiesInterface::FuncBool_Implementation, return false;);

	// properties

protected:
	// signals
	virtual void BroadcastSigVoid_Implementation() override;

	virtual void BroadcastSigBool_Implementation(bool bParamBool) override;

	// properties - local copy
};
