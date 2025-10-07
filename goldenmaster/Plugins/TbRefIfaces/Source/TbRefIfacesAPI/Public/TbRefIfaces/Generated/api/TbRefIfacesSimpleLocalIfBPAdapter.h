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
#include "TbRefIfaces_data.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfBPInterface.h"
#include "TbRefIfacesSimpleLocalIfBPAdapter.generated.h"

/**
 * Adapter UTbRefIfacesSimpleLocalIfBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TBREFIFACESAPI_API UTbRefIfacesSimpleLocalIfBPAdapter : public UObject, public ITbRefIfacesSimpleLocalIfInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|TbRefIfaces|SimpleLocalIf")
	TScriptInterface<ITbRefIfacesSimpleLocalIfBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf")
	void Initialize(TScriptInterface<ITbRefIfacesSimpleLocalIfBPInterface> InTarget);

	// signals
	UTbRefIfacesSimpleLocalIfPublisher* _GetPublisher() override;

	// methods
	void IntMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param) override;
	TFuture<int32> IntMethodAsync(int32 Param) override;
	int32 IntMethod(int32 Param) override;

	// properties
	int32 GetIntProperty() const override;
	void SetIntProperty(int32 InIntProperty) override;
};
