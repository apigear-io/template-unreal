
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
#include "TbSame2SameEnum2InterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "TbSame2SameEnum2Interface")
class TBSAME2_API UTbSame2SameEnum2InterfaceProxy : public UGameInstanceSubsystem, public ITbSame2SameEnum2InterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTbSame2SameEnum2InterfaceProxy();
	virtual ~UTbSame2SameEnum2InterfaceProxy();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface")
	void setBackendService(TScriptInterface<ITbSame2SameEnum2InterfaceInterface> InService);

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface", DisplayName = "Sig1 Signal")
	FTbSame2SameEnum2InterfaceSig1Delegate Sig1Signal;
	FTbSame2SameEnum2InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface", DisplayName = "Sig2 Signal")
	FTbSame2SameEnum2InterfaceSig2Delegate Sig2Signal;
	FTbSame2SameEnum2InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface", DisplayName = "Prop1 Changed")
	FTbSame2SameEnum2InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame2SameEnum2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface", DisplayName = "Prop2 Changed")
	FTbSame2SameEnum2InterfaceProp2ChangedDelegate Prop2Changed;
	FTbSame2SameEnum2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	// properties
	void GetProp1_Implementation(ETbSame2Enum1& ReturnValue) const override;

	void SetProp1_Implementation(const ETbSame2Enum1& InProp1) override;

	void GetProp2_Implementation(ETbSame2Enum2& ReturnValue) const override;

	void SetProp2_Implementation(const ETbSame2Enum2& InProp2) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, const ETbSame2Enum1& Param1) override;
	void Func1_Implementation(ETbSame2Enum1& Result, const ETbSame2Enum1& Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2) override;
	void Func2_Implementation(ETbSame2Enum1& Result, const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame2|SameEnum2Interface")
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnSig1(const ETbSame2Enum1& Param1);

	UFUNCTION(Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnSig2(const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const ETbSame2Enum1& Prop1);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnProp2Changed(const ETbSame2Enum2& Prop2);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame2|SameEnum2Interface")
	ETbSame2Enum1 Prop1;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	ETbSame2Enum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void SetProp1_Private(const ETbSame2Enum1& InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbSame2|SameEnum2Interface")
	ETbSame2Enum2 Prop2;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	ETbSame2Enum2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void SetProp2_Private(const ETbSame2Enum2& InProp2);
};
