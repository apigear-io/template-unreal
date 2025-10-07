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
#include "TbNames_data.h"
#include "TbNames/Generated/api/TbNamesNamEsInterface.h"
#include "TbNames/Generated/api/TbNamesNamEsBPInterface.h"
#include "TbNamesNamEsBPAdapter.generated.h"

/**
 * Adapter UTbNamesNamEsBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TBNAMESAPI_API UTbNamesNamEsBPAdapter : public UObject, public ITbNamesNamEsInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|TbNames|NamEs")
	TScriptInterface<ITbNamesNamEsBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs")
	void Initialize(TScriptInterface<ITbNamesNamEsBPInterface> InTarget);

	// signals
	UTbNamesNamEsPublisher* _GetPublisher() override;

	// methods
	void SomeFunction(bool bSomeParam) override;

	void SomeFunction2(bool bSomeParam) override;

	// properties
	bool GetSwitch() const override;
	void SetSwitch(bool bInSwitch) override;

	int32 GetSomeProperty() const override;
	void SetSomeProperty(int32 InSomeProperty) override;

	int32 GetSomePoperty2() const override;
	void SetSomePoperty2(int32 InSomePoperty2) override;

	ETbNamesEnum_With_Under_scores GetEnumProperty() const override;
	void SetEnumProperty(ETbNamesEnum_With_Under_scores InEnumProperty) override;
};
