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
#include "Generated/api/TbNames_data.h"
#include "Generated/api/TbNamesNamEsInterface.h"
#include "AbstractTbNamesNamEs.generated.h"

/**
 * Abstract UAbstractTbNamesNamEs
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBNAMES_API UAbstractTbNamesNamEs : public UGameInstanceSubsystem, public ITbNamesNamEsInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbNamesNamEs();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbNamesNamEsSignals* _GetSignals_Implementation() override;

	// methods
	virtual void SomeFunction_Implementation(bool bSomeParam) override PURE_VIRTUAL(UAbstractTbNamesNamEs::SomeFunction_Implementation, return;);

	virtual void SomeFunction2_Implementation(bool bSomeParam) override PURE_VIRTUAL(UAbstractTbNamesNamEs::SomeFunction2_Implementation, return;);

	// properties
	virtual bool GetSwitch_Implementation() const override PURE_VIRTUAL(UAbstractTbNamesNamEs::GetSwitch_Implementation, return false;);
	virtual void SetSwitch_Implementation(bool bInSwitch) override PURE_VIRTUAL(UAbstractTbNamesNamEs::SetSwitch_Implementation, return;);

	virtual int32 GetSomeProperty_Implementation() const override PURE_VIRTUAL(UAbstractTbNamesNamEs::GetSomeProperty_Implementation, return 0;);
	virtual void SetSomeProperty_Implementation(int32 InSomeProperty) override PURE_VIRTUAL(UAbstractTbNamesNamEs::SetSomeProperty_Implementation, return;);

	virtual int32 GetSomePoperty2_Implementation() const override PURE_VIRTUAL(UAbstractTbNamesNamEs::GetSomePoperty2_Implementation, return 0;);
	virtual void SetSomePoperty2_Implementation(int32 InSomePoperty2) override PURE_VIRTUAL(UAbstractTbNamesNamEs::SetSomePoperty2_Implementation, return;);

	virtual ETbNamesEnum_With_Under_scores GetEnumProperty_Implementation() const override PURE_VIRTUAL(UAbstractTbNamesNamEs::GetEnumProperty_Implementation, return ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE;);
	virtual void SetEnumProperty_Implementation(ETbNamesEnum_With_Under_scores InEnumProperty) override PURE_VIRTUAL(UAbstractTbNamesNamEs::SetEnumProperty_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetSwitch_Private, BlueprintSetter = SetSwitch_Private, Category = "ApiGear|TbNames|NamEs")
	bool bSwitch{false};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbNames|NamEs|Properties", BlueprintInternalUseOnly)
	bool GetSwitch_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbNames|NamEs|Properties", BlueprintInternalUseOnly)
	void SetSwitch_Private(bool bInSwitch);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetSomeProperty_Private, BlueprintSetter = SetSomeProperty_Private, Category = "ApiGear|TbNames|NamEs")
	int32 SomeProperty{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbNames|NamEs|Properties", BlueprintInternalUseOnly)
	int32 GetSomeProperty_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbNames|NamEs|Properties", BlueprintInternalUseOnly)
	void SetSomeProperty_Private(int32 InSomeProperty);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetSomePoperty2_Private, BlueprintSetter = SetSomePoperty2_Private, Category = "ApiGear|TbNames|NamEs")
	int32 SomePoperty2{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbNames|NamEs|Properties", BlueprintInternalUseOnly)
	int32 GetSomePoperty2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbNames|NamEs|Properties", BlueprintInternalUseOnly)
	void SetSomePoperty2_Private(int32 InSomePoperty2);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetEnumProperty_Private, BlueprintSetter = SetEnumProperty_Private, Category = "ApiGear|TbNames|NamEs")
	ETbNamesEnum_With_Under_scores EnumProperty{ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbNames|NamEs|Properties", BlueprintInternalUseOnly)
	ETbNamesEnum_With_Under_scores GetEnumProperty_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbNames|NamEs|Properties", BlueprintInternalUseOnly)
	void SetEnumProperty_Private(ETbNamesEnum_With_Under_scores InEnumProperty);

private:
	// signals
	UPROPERTY()
	UTbNamesNamEsSignals* TbNamesNamEsSignals;
};
