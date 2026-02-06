
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
#include "TbSame2/Generated/api/AbstractTbSame2SameStruct1Interface.h"
#include "TbSame2SameStruct1Interface.generated.h"

UCLASS(BlueprintType)
class TBSAME2IMPLEMENTATION_API UTbSame2SameStruct1InterfaceImplementation : public UAbstractTbSame2SameStruct1Interface
{
	GENERATED_BODY()
public:
	virtual ~UTbSame2SameStruct1InterfaceImplementation();

	// properties
	FTbSame2Struct1 GetProp1() const override;
	void SetProp1(const FTbSame2Struct1& Prop1) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Properties")
	void _ResetProperties();

	// operations
	FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) override;

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	mutable FRWLock Prop1RWLock;
#endif
};
