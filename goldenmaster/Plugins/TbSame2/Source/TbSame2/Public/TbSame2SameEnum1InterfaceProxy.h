
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
#include "UObject/NoExportTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/LatentActionManager.h"
#include "Templates/SharedPointer.h"
#include "apig/TbSame2_apig.h"
#include "TbSame2SameEnum1InterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "TbSame2SameEnum1Interface")
class TBSAME2_API UTbSame2SameEnum1InterfaceProxy : public UGameInstanceSubsystem, public ITbSame2SameEnum1InterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTbSame2SameEnum1InterfaceProxy();
	virtual ~UTbSame2SameEnum1InterfaceProxy();

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum1Interface", DisplayName = "Sig1 Signal")
	FTbSame2SameEnum1InterfaceSig1Delegate Sig1Signal;
	FTbSame2SameEnum1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum1Interface", DisplayName = "Prop1 Changed")
	FTbSame2SameEnum1InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame2SameEnum1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum1Interface")
	ETbSame2Enum1 GetProp1() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum1Interface")
	void SetProp1(const ETbSame2Enum1& Prop1) override;

	// operations
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, const ETbSame2Enum1& Param1);
	ETbSame2Enum1 Func1(const ETbSame2Enum1& Param1) override;

private:
	/** The connection to the service backend. */
	TSharedPtr<ITbSame2SameEnum1InterfaceInterface, ESPMode::ThreadSafe> service;

	// signals
	UFUNCTION(Category = "ApiGear|TbSame2|SameEnum1Interface", BlueprintInternalUseOnly)
	void OnSig1(const ETbSame2Enum1& Param1);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum1Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const ETbSame2Enum1& Prop1);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1, BlueprintSetter = SetProp1, Category = "ApiGear|TbSame2|SameEnum1Interface")
	ETbSame2Enum1 Prop1;
};
