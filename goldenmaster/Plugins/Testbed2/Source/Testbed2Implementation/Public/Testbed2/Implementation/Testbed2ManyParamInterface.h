
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
#include "Testbed2/Generated/api/AbstractTestbed2ManyParamInterface.h"
#include "Testbed2ManyParamInterface.generated.h"

UCLASS(BlueprintType)
class TESTBED2IMPLEMENTATION_API UTestbed2ManyParamInterfaceImplementation : public UAbstractTestbed2ManyParamInterface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed2ManyParamInterfaceImplementation();

	// properties
	int32 GetProp1() const override;
	void SetProp1(int32 Prop1) override;

	int32 GetProp2() const override;
	void SetProp2(int32 Prop2) override;

	int32 GetProp3() const override;
	void SetProp3(int32 Prop3) override;

	int32 GetProp4() const override;
	void SetProp4(int32 Prop4) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	void _ResetProperties();

	// operations
	int32 Func1(int32 Param1) override;

	int32 Func2(int32 Param1, int32 Param2) override;

	int32 Func3(int32 Param1, int32 Param2, int32 Param3) override;

	int32 Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	mutable FRWLock Prop1RWLock;
	mutable FRWLock Prop2RWLock;
	mutable FRWLock Prop3RWLock;
	mutable FRWLock Prop4RWLock;
#endif
};
