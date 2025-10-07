/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbIfaceimport_data.h"
#include "TbIfaceimport/Generated/api/TbIfaceimportEmptyIfInterface.h"
#include "TbIfaceimport/Generated/api/TbIfaceimportEmptyIfBPInterface.h"
#include "TbIfaceimportEmptyIfBPAdapter.generated.h"

/**
 * Adapter UTbIfaceimportEmptyIfBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TBIFACEIMPORTAPI_API UTbIfaceimportEmptyIfBPAdapter : public UObject, public ITbIfaceimportEmptyIfInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|TbIfaceimport|EmptyIf")
	TScriptInterface<ITbIfaceimportEmptyIfBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf")
	void Initialize(TScriptInterface<ITbIfaceimportEmptyIfBPInterface> InTarget);

	// signals
	UTbIfaceimportEmptyIfPublisher* _GetPublisher() override;

	// methods

	// properties
};
