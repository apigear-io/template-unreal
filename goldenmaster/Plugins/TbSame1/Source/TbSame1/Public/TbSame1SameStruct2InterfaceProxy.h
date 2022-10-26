
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
#include "apig/TbSame1_apig.h"
#include "TbSame1SameStruct2InterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "TbSame1SameStruct2Interface")
class TBSAME1_API UTbSame1SameStruct2InterfaceProxy : public UGameInstanceSubsystem, public ITbSame1SameStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTbSame1SameStruct2InterfaceProxy();
	virtual ~UTbSame1SameStruct2InterfaceProxy();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct2Interface")
	void setBackendService(TScriptInterface<ITbSame1SameStruct2InterfaceInterface> InService);

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct2Interface", DisplayName = "Sig1 Signal")
	FTbSame1SameStruct2InterfaceSig1Delegate Sig1Signal;
	FTbSame1SameStruct2InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct2Interface", DisplayName = "Sig2 Signal")
	FTbSame1SameStruct2InterfaceSig2Delegate Sig2Signal;
	FTbSame1SameStruct2InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct2Interface", DisplayName = "Prop1 Changed")
	FTbSame1SameStruct2InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame1SameStruct2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct2Interface", DisplayName = "Prop2 Changed")
	FTbSame1SameStruct2InterfaceProp2ChangedDelegate Prop2Changed;
	FTbSame1SameStruct2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	// properties
	FTbSame1Struct2 GetProp1_Implementation() const override;

	void SetProp1_Implementation(const FTbSame1Struct2& InProp1) override;

	FTbSame1Struct2 GetProp2_Implementation() const override;

	void SetProp2_Implementation(const FTbSame1Struct2& InProp2) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) override;
	FTbSame1Struct1 Func1_Implementation(const FTbSame1Struct1& Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;
	FTbSame1Struct1 Func2_Implementation(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;

protected:
	// signals
	void BroadcastSig1_Implementation(const FTbSame1Struct1& Param1) override;

	void BroadcastSig2_Implementation(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;

	void BroadcastProp1Changed_Implementation(const FTbSame1Struct2& Prop1) override;

	void BroadcastProp2Changed_Implementation(const FTbSame1Struct2& Prop2) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame1|SameStruct2Interface")
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	void OnSig1(const FTbSame1Struct1& Param1);

	UFUNCTION(Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	void OnSig2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2);

	UFUNCTION(Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const FTbSame1Struct2& Prop1);

	UFUNCTION(Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	void OnProp2Changed(const FTbSame1Struct2& Prop2);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame1|SameStruct2Interface")
	FTbSame1Struct2 Prop1{FTbSame1Struct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	FTbSame1Struct2 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTbSame1Struct2& InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbSame1|SameStruct2Interface")
	FTbSame1Struct2 Prop2{FTbSame1Struct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	FTbSame1Struct2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameStruct2Interface", BlueprintInternalUseOnly)
	void SetProp2_Private(const FTbSame1Struct2& InProp2);
};
