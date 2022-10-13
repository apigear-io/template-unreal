
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
#include "apig/TbEnum_apig.h"
#include "TbEnumEnumInterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "TbEnumEnumInterface")
class TBENUM_API UTbEnumEnumInterfaceProxy : public UGameInstanceSubsystem, public ITbEnumEnumInterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTbEnumEnumInterfaceProxy();
	virtual ~UTbEnumEnumInterfaceProxy();

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Sig0 Signal")
	FTbEnumEnumInterfaceSig0Delegate Sig0Signal;
	FTbEnumEnumInterfaceSig0Delegate& GetSig0SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Sig1 Signal")
	FTbEnumEnumInterfaceSig1Delegate Sig1Signal;
	FTbEnumEnumInterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Sig2 Signal")
	FTbEnumEnumInterfaceSig2Delegate Sig2Signal;
	FTbEnumEnumInterfaceSig2Delegate& GetSig2SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Sig3 Signal")
	FTbEnumEnumInterfaceSig3Delegate Sig3Signal;
	FTbEnumEnumInterfaceSig3Delegate& GetSig3SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Prop0 Changed")
	FTbEnumEnumInterfaceProp0ChangedDelegate Prop0Changed;
	FTbEnumEnumInterfaceProp0ChangedDelegate& GetProp0ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Prop1 Changed")
	FTbEnumEnumInterfaceProp1ChangedDelegate Prop1Changed;
	FTbEnumEnumInterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Prop2 Changed")
	FTbEnumEnumInterfaceProp2ChangedDelegate Prop2Changed;
	FTbEnumEnumInterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Prop3 Changed")
	FTbEnumEnumInterfaceProp3ChangedDelegate Prop3Changed;
	FTbEnumEnumInterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() override;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum0 GetProp0() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void SetProp0(const ETbEnumEnum0& Prop0) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum1 GetProp1() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void SetProp1(const ETbEnumEnum1& Prop1) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum2 GetProp2() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void SetProp2(const ETbEnumEnum2& Prop2) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum3 GetProp3() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void SetProp3(const ETbEnumEnum3& Prop3) override;

	// operations
	void Func0Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, const ETbEnumEnum0& Param0);
	ETbEnumEnum0 Func0(const ETbEnumEnum0& Param0) override;

	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, const ETbEnumEnum1& Param1);
	ETbEnumEnum1 Func1(const ETbEnumEnum1& Param1) override;

	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, const ETbEnumEnum2& Param2);
	ETbEnumEnum2 Func2(const ETbEnumEnum2& Param2) override;

	void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, const ETbEnumEnum3& Param3);
	ETbEnumEnum3 Func3(const ETbEnumEnum3& Param3) override;

private:
	/** The connection to the service backend. */
	TSharedPtr<ITbEnumEnumInterfaceInterface, ESPMode::ThreadSafe> service;

	// signals
	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig0(const ETbEnumEnum0& Param0);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig1(const ETbEnumEnum1& Param1);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig2(const ETbEnumEnum2& Param2);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig3(const ETbEnumEnum3& Param3);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp0Changed(const ETbEnumEnum0& Prop0);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp1Changed(const ETbEnumEnum1& Prop1);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp2Changed(const ETbEnumEnum2& Prop2);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp3Changed(const ETbEnumEnum3& Prop3);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp0, BlueprintSetter = SetProp0, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum0 Prop0;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1, BlueprintSetter = SetProp1, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum1 Prop1;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2, BlueprintSetter = SetProp2, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum2 Prop2;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp3, BlueprintSetter = SetProp3, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum3 Prop3;
};
