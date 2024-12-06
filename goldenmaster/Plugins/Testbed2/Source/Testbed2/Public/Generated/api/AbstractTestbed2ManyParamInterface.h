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
#include "Generated/api/Testbed2_data.h"
#include "Generated/api/Testbed2ManyParamInterfaceInterface.h"
#include "AbstractTestbed2ManyParamInterface.generated.h"

/**
 * Abstract UAbstractTestbed2ManyParamInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TESTBED2_API UAbstractTestbed2ManyParamInterface : public UGameInstanceSubsystem, public ITestbed2ManyParamInterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTestbed2ManyParamInterface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTestbed2ManyParamInterfaceSignals* _GetSignals_Implementation() override;

	// methods
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1) override;
	virtual int32 Func1_Implementation(int32 Param1) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::Func1_Implementation, return 0;);

	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2) override;
	virtual int32 Func2_Implementation(int32 Param1, int32 Param2) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::Func2_Implementation, return 0;);

	virtual void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3) override;
	virtual int32 Func3_Implementation(int32 Param1, int32 Param2, int32 Param3) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::Func3_Implementation, return 0;);

	virtual void Func4Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;
	virtual int32 Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::Func4_Implementation, return 0;);

	// properties
	virtual int32 GetProp1_Implementation() const override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::GetProp1_Implementation, return 0;);
	virtual void SetProp1_Implementation(int32 InProp1) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::SetProp1_Implementation, return;);

	virtual int32 GetProp2_Implementation() const override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::GetProp2_Implementation, return 0;);
	virtual void SetProp2_Implementation(int32 InProp2) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::SetProp2_Implementation, return;);

	virtual int32 GetProp3_Implementation() const override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::GetProp3_Implementation, return 0;);
	virtual void SetProp3_Implementation(int32 InProp3) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::SetProp3_Implementation, return;);

	virtual int32 GetProp4_Implementation() const override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::GetProp4_Implementation, return 0;);
	virtual void SetProp4_Implementation(int32 InProp4) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::SetProp4_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop1{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	int32 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(int32 InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop2{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	int32 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	void SetProp2_Private(int32 InProp2);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp3_Private, BlueprintSetter = SetProp3_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop3{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	int32 GetProp3_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	void SetProp3_Private(int32 InProp3);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp4_Private, BlueprintSetter = SetProp4_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop4{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	int32 GetProp4_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface|Properties", BlueprintInternalUseOnly)
	void SetProp4_Private(int32 InProp4);

private:
	// signals
	UPROPERTY()
	UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals;
};
