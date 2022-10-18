
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
#include "TbSame2SameStruct1InterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "TbSame2SameStruct1Interface")
class TBSAME2_API UTbSame2SameStruct1InterfaceProxy : public UGameInstanceSubsystem, public ITbSame2SameStruct1InterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTbSame2SameStruct1InterfaceProxy();
	virtual ~UTbSame2SameStruct1InterfaceProxy();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface")
	void setBackendService(TScriptInterface<ITbSame2SameStruct1InterfaceInterface> InService);

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct1Interface", DisplayName = "Sig1 Signal")
	FTbSame2SameStruct1InterfaceSig1Delegate Sig1Signal;
	FTbSame2SameStruct1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct1Interface", DisplayName = "Prop1 Changed")
	FTbSame2SameStruct1InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame2SameStruct1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// properties
	FTbSame2Struct1 GetProp1_Implementation() const override;

	void SetProp1_Implementation(const FTbSame2Struct1& InProp1) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) override;
	FTbSame2Struct1 Func1_Implementation(const FTbSame2Struct1& Param1) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame2|SameStruct1Interface")
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct1Interface", BlueprintInternalUseOnly)
	void OnSig1(const FTbSame2Struct1& Param1);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const FTbSame2Struct1& Prop1);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame2|SameStruct1Interface")
	FTbSame2Struct1 Prop1;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameStruct1Interface", BlueprintInternalUseOnly)
	FTbSame2Struct1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameStruct1Interface", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTbSame2Struct1& InProp1);
};
