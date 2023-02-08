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
#include "TbSimple_data.h"
#include "TbSimpleNoOperationsInterfaceInterface.generated.h"

/**
 * Declaration for NoOperationsInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbSimpleNoOperationsInterfaceSigVoidDelegate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfaceSigBoolDelegate, bool, bParamBool);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfacePropBoolChangedDelegate, bool, bPropBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfacePropIntChangedDelegate, int32, PropInt);

/**
 * Interface UTbSimpleNoOperationsInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSimpleNoOperationsInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSimpleNoOperationsInterfaceInterface
 */
class TBSIMPLE_API ITbSimpleNoOperationsInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface")
	virtual FTbSimpleNoOperationsInterfaceSigVoidDelegate& GetSigVoidSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface")
	virtual FTbSimpleNoOperationsInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface")
	virtual FTbSimpleNoOperationsInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface")
	virtual FTbSimpleNoOperationsInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() = 0;

	// methods

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface")
	bool GetPropBool() const;
	virtual bool GetPropBool_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface")
	void SetPropBool(bool bPropBool);
	virtual void SetPropBool_Implementation(bool bPropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface")
	int32 GetPropInt() const;
	virtual int32 GetPropInt_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface")
	void SetPropInt(int32 PropInt);
	virtual void SetPropInt_Implementation(int32 PropInt) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigVoid();
	virtual void BroadcastSigVoid_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigBool(bool bParamBool);
	virtual void BroadcastSigBool_Implementation(bool bParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropBoolChanged(bool bPropBool);
	virtual void BroadcastPropBoolChanged_Implementation(bool bPropBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropIntChanged(int32 PropInt);
	virtual void BroadcastPropIntChanged_Implementation(int32 PropInt) = 0;
};
