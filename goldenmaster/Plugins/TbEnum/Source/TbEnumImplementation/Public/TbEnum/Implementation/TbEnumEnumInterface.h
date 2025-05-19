
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
#include "TbEnum/Generated/api/AbstractTbEnumEnumInterface.h"
#include "TbEnumEnumInterface.generated.h"

UCLASS(BlueprintType)
class TBENUMIMPLEMENTATION_API UTbEnumEnumInterfaceImplementation : public UAbstractTbEnumEnumInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbEnumEnumInterfaceImplementation();

	// properties
	ETbEnumEnum0 GetProp0() const override;
	void SetProp0(ETbEnumEnum0 Prop0) override;

	ETbEnumEnum1 GetProp1() const override;
	void SetProp1(ETbEnumEnum1 Prop1) override;

	ETbEnumEnum2 GetProp2() const override;
	void SetProp2(ETbEnumEnum2 Prop2) override;

	ETbEnumEnum3 GetProp3() const override;
	void SetProp3(ETbEnumEnum3 Prop3) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Properties")
	void _ResetProperties();

	// operations
	ETbEnumEnum0 Func0(ETbEnumEnum0 Param0) override;

	ETbEnumEnum1 Func1(ETbEnumEnum1 Param1) override;

	ETbEnumEnum2 Func2(ETbEnumEnum2 Param2) override;

	ETbEnumEnum3 Func3(ETbEnumEnum3 Param3) override;
};
