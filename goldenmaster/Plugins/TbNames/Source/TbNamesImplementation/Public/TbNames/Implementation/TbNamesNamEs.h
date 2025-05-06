
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
#include "TbNames/Generated/api/AbstractTbNamesNamEs.h"
#include "TbNamesNamEs.generated.h"

UCLASS(BlueprintType)
class TBNAMESIMPLEMENTATION_API UTbNamesNamEs : public UAbstractTbNamesNamEs
{
	GENERATED_BODY()
public:
	virtual ~UTbNamesNamEs();

	// properties
	bool GetSwitch() const override;
	void SetSwitch(bool bSwitch) override;

	int32 GetSomeProperty() const override;
	void SetSomeProperty(int32 SomeProperty) override;

	int32 GetSomePoperty2() const override;
	void SetSomePoperty2(int32 SomePoperty2) override;

	ETbNamesEnum_With_Under_scores GetEnumProperty() const override;
	void SetEnumProperty(ETbNamesEnum_With_Under_scores EnumProperty) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	void _ResetProperties();

	// operations
	void SomeFunction(bool bSomeParam) override;

	void SomeFunction2(bool bSomeParam) override;
};
