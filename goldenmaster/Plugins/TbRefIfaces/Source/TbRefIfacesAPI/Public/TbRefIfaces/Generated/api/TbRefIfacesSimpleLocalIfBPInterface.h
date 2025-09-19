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
#include "TbRefIfacesSimpleLocalIfInterface.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "TbRefIfaces_data.h"
#include "TbIfaceimport/Generated/api/TbIfaceimport_data.h"
#include "TbRefIfacesSimpleLocalIfBPInterface.generated.h"

/**
 * Interface UTbRefIfacesSimpleLocalIfBPInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbRefIfacesSimpleLocalIfBPInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbRefIfacesSimpleLocalIfBPInterface
 */
class TBREFIFACESAPI_API ITbRefIfacesSimpleLocalIfBPInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf")
	UTbRefIfacesSimpleLocalIfPublisher* _GetPublisher();
	virtual UTbRefIfacesSimpleLocalIfPublisher* _GetPublisher_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void IntMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param);
	virtual void IntMethodAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Operations")
	int32 IntMethod(int32 Param);
	virtual int32 IntMethod_Implementation(int32 Param) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Properties")
	int32 GetIntProperty() const;
	virtual int32 GetIntProperty_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Properties")
	void SetIntProperty(int32 InIntProperty);
	virtual void SetIntProperty_Implementation(UPARAM(DisplayName = "IntProperty") int32 InIntProperty) = 0;
};
