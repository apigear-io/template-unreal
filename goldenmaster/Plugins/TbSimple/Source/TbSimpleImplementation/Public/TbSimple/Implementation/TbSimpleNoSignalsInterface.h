
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

#include "CoreMinimal.h"
#include "TbSimple/Generated/api/AbstractTbSimpleNoSignalsInterface.h"
#include "TbSimpleNoSignalsInterface.generated.h"

UCLASS(BlueprintType)
class TBSIMPLEIMPLEMENTATION_API UTbSimpleNoSignalsInterface : public UAbstractTbSimpleNoSignalsInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleNoSignalsInterface();

	// properties
	bool GetPropBool() const override;
	void SetPropBool(bool bPropBool) override;

	int32 GetPropInt() const override;
	void SetPropInt(int32 PropInt) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Properties")
	void _ResetProperties();

	// operations
	void FuncVoid() override;

	bool FuncBool(bool bParamBool) override;
};
