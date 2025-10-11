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
#include "TbIfaceimportEmptyIfInterface.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "TbIfaceimport_data.h"
#include "TbIfaceimportEmptyIfBPInterface.generated.h"

/**
 * Interface UTbIfaceimportEmptyIfBPInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbIfaceimportEmptyIfBPInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbIfaceimportEmptyIfBPInterface
 */
class TBIFACEIMPORTAPI_API ITbIfaceimportEmptyIfBPInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf")
	UTbIfaceimportEmptyIfPublisher* _GetPublisher();
	virtual UTbIfaceimportEmptyIfPublisher* _GetPublisher_Implementation() = 0;

	// methods

	// properties
};
