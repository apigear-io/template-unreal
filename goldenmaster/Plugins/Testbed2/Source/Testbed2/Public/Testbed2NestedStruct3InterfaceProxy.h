
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
#include "apig/Testbed2_apig.h"
#include "Testbed2NestedStruct3InterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "Testbed2NestedStruct3Interface")
class TESTBED2_API UTestbed2NestedStruct3InterfaceProxy : public UGameInstanceSubsystem, public ITestbed2NestedStruct3InterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTestbed2NestedStruct3InterfaceProxy();
	virtual ~UTestbed2NestedStruct3InterfaceProxy();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	void setBackendService(TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> InService);

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface", DisplayName = "Sig1 Signal")
	FTestbed2NestedStruct3InterfaceSig1Delegate Sig1Signal;
	FTestbed2NestedStruct3InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface", DisplayName = "Sig2 Signal")
	FTestbed2NestedStruct3InterfaceSig2Delegate Sig2Signal;
	FTestbed2NestedStruct3InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface", DisplayName = "Sig3 Signal")
	FTestbed2NestedStruct3InterfaceSig3Delegate Sig3Signal;
	FTestbed2NestedStruct3InterfaceSig3Delegate& GetSig3SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface", DisplayName = "Prop1 Changed")
	FTestbed2NestedStruct3InterfaceProp1ChangedDelegate Prop1Changed;
	FTestbed2NestedStruct3InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface", DisplayName = "Prop2 Changed")
	FTestbed2NestedStruct3InterfaceProp2ChangedDelegate Prop2Changed;
	FTestbed2NestedStruct3InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface", DisplayName = "Prop3 Changed")
	FTestbed2NestedStruct3InterfaceProp3ChangedDelegate Prop3Changed;
	FTestbed2NestedStruct3InterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() override;

	// properties
	FTestbed2NestedStruct1 GetProp1_Implementation() const override;

	void SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1) override;

	FTestbed2NestedStruct2 GetProp2_Implementation() const override;

	void SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2) override;

	FTestbed2NestedStruct3 GetProp3_Implementation() const override;

	void SetProp3_Implementation(const FTestbed2NestedStruct3& InProp3) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override;
	FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;
	FTestbed2NestedStruct1 Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;

	void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) override;
	FTestbed2NestedStruct1 Func3_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void OnSig1(const FTestbed2NestedStruct1& Param1);

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void OnSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void OnSig3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void OnProp2Changed(const FTestbed2NestedStruct2& Prop2);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void OnProp3Changed(const FTestbed2NestedStruct3& Prop3);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	FTestbed2NestedStruct1 Prop1;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	FTestbed2NestedStruct1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTestbed2NestedStruct1& InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	FTestbed2NestedStruct2 Prop2;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	FTestbed2NestedStruct2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void SetProp2_Private(const FTestbed2NestedStruct2& InProp2);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp3_Private, BlueprintSetter = SetProp3_Private, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	FTestbed2NestedStruct3 Prop3;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	FTestbed2NestedStruct3 GetProp3_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|NestedStruct3Interface", BlueprintInternalUseOnly)
	void SetProp3_Private(const FTestbed2NestedStruct3& InProp3);
};
