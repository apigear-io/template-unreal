
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
#include "Generated/api/AbstractTbNamesNamEs.h"
#include "TbNamesNamEs.generated.h"

UCLASS(BlueprintType)
class TBNAMES_API UTbNamesNamEs : public UAbstractTbNamesNamEs
{
	GENERATED_BODY()
public:
	virtual ~UTbNamesNamEs();

	// properties
	bool GetSwitch_Implementation() const override;
	void SetSwitch_Implementation(bool bSwitch) override;

	int32 GetSomeProperty_Implementation() const override;
	void SetSomeProperty_Implementation(int32 SomeProperty) override;

	int32 GetSomePoperty2_Implementation() const override;
	void SetSomePoperty2_Implementation(int32 SomePoperty2) override;

	ETbNamesEnum_With_Under_scores GetEnumProperty_Implementation() const override;
	void SetEnumProperty_Implementation(ETbNamesEnum_With_Under_scores EnumProperty) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	void _ResetProperties();

	// operations
	void SomeFunction_Implementation(bool bSomeParam) override;

	void SomeFunction2_Implementation(bool bSomeParam) override;
};
