
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
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbEnumEnumInterfaceInterface.h"
#include "TbEnumEnumInterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbEnumEnumInterfaceLoggingDecorator, Log, All);

UCLASS(BlueprintType, Blueprintable)
class TBENUM_API UTbEnumEnumInterfaceLoggingDecorator : public UGameInstanceSubsystem, public ITbEnumEnumInterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTbEnumEnumInterfaceLoggingDecorator();
	virtual ~UTbEnumEnumInterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void setBackendService(TScriptInterface<ITbEnumEnumInterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

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
	ETbEnumEnum0 GetProp0_Implementation() const override;

	void SetProp0_Implementation(const ETbEnumEnum0& InProp0) override;

	ETbEnumEnum1 GetProp1_Implementation() const override;

	void SetProp1_Implementation(const ETbEnumEnum1& InProp1) override;

	ETbEnumEnum2 GetProp2_Implementation() const override;

	void SetProp2_Implementation(const ETbEnumEnum2& InProp2) override;

	ETbEnumEnum3 GetProp3_Implementation() const override;

	void SetProp3_Implementation(const ETbEnumEnum3& InProp3) override;

	// operations
	void Func0Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, const ETbEnumEnum0& Param0) override;
	ETbEnumEnum0 Func0_Implementation(const ETbEnumEnum0& Param0) override;

	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, const ETbEnumEnum1& Param1) override;
	ETbEnumEnum1 Func1_Implementation(const ETbEnumEnum1& Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, const ETbEnumEnum2& Param2) override;
	ETbEnumEnum2 Func2_Implementation(const ETbEnumEnum2& Param2) override;

	void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, const ETbEnumEnum3& Param3) override;
	ETbEnumEnum3 Func3_Implementation(const ETbEnumEnum3& Param3) override;

protected:
	// signals
	void BroadcastSig0_Implementation(const ETbEnumEnum0& Param0) override;

	void BroadcastSig1_Implementation(const ETbEnumEnum1& Param1) override;

	void BroadcastSig2_Implementation(const ETbEnumEnum2& Param2) override;

	void BroadcastSig3_Implementation(const ETbEnumEnum3& Param3) override;

	void BroadcastProp0Changed_Implementation(const ETbEnumEnum0& Prop0) override;

	void BroadcastProp1Changed_Implementation(const ETbEnumEnum1& Prop1) override;

	void BroadcastProp2Changed_Implementation(const ETbEnumEnum2& Prop2) override;

	void BroadcastProp3Changed_Implementation(const ETbEnumEnum3& Prop3) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbEnum|EnumInterface")
	TScriptInterface<ITbEnumEnumInterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig0(const ETbEnumEnum0& Param0);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig1(const ETbEnumEnum1& Param1);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig2(const ETbEnumEnum2& Param2);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig3(const ETbEnumEnum3& Param3);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp0Changed(const ETbEnumEnum0& Prop0);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp1Changed(const ETbEnumEnum1& Prop1);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp2Changed(const ETbEnumEnum2& Prop2);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp3Changed(const ETbEnumEnum3& Prop3);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp0_Private, BlueprintSetter = SetProp0_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum0 Prop0{ETbEnumEnum0::VALUE0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	ETbEnumEnum0 GetProp0_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void SetProp0_Private(const ETbEnumEnum0& InProp0);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum1 Prop1{ETbEnumEnum1::VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	ETbEnumEnum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void SetProp1_Private(const ETbEnumEnum1& InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum2 Prop2{ETbEnumEnum2::VALUE2};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	ETbEnumEnum2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void SetProp2_Private(const ETbEnumEnum2& InProp2);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp3_Private, BlueprintSetter = SetProp3_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum3 Prop3{ETbEnumEnum3::VALUE3};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	ETbEnumEnum3 GetProp3_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void SetProp3_Private(const ETbEnumEnum3& InProp3);
};
