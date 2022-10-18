
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
#include "apig/Testbed2_apig.h"
#include "Testbed2ManyParamInterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "Testbed2ManyParamInterface")
class TESTBED2_API UTestbed2ManyParamInterfaceProxy : public UGameInstanceSubsystem, public ITestbed2ManyParamInterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTestbed2ManyParamInterfaceProxy();
	virtual ~UTestbed2ManyParamInterfaceProxy();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	void setBackendService(TScriptInterface<ITestbed2ManyParamInterfaceInterface> InService);

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Sig1 Signal")
	FTestbed2ManyParamInterfaceSig1Delegate Sig1Signal;
	FTestbed2ManyParamInterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Sig2 Signal")
	FTestbed2ManyParamInterfaceSig2Delegate Sig2Signal;
	FTestbed2ManyParamInterfaceSig2Delegate& GetSig2SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Sig3 Signal")
	FTestbed2ManyParamInterfaceSig3Delegate Sig3Signal;
	FTestbed2ManyParamInterfaceSig3Delegate& GetSig3SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Sig4 Signal")
	FTestbed2ManyParamInterfaceSig4Delegate Sig4Signal;
	FTestbed2ManyParamInterfaceSig4Delegate& GetSig4SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Prop1 Changed")
	FTestbed2ManyParamInterfaceProp1ChangedDelegate Prop1Changed;
	FTestbed2ManyParamInterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Prop2 Changed")
	FTestbed2ManyParamInterfaceProp2ChangedDelegate Prop2Changed;
	FTestbed2ManyParamInterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Prop3 Changed")
	FTestbed2ManyParamInterfaceProp3ChangedDelegate Prop3Changed;
	FTestbed2ManyParamInterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Prop4 Changed")
	FTestbed2ManyParamInterfaceProp4ChangedDelegate Prop4Changed;
	FTestbed2ManyParamInterfaceProp4ChangedDelegate& GetProp4ChangedDelegate() override;

	// properties
	int32 GetProp1_Implementation() const override;

	void SetProp1_Implementation(int32 InProp1) override;

	int32 GetProp2_Implementation() const override;

	void SetProp2_Implementation(int32 InProp2) override;

	int32 GetProp3_Implementation() const override;

	void SetProp3_Implementation(int32 InProp3) override;

	int32 GetProp4_Implementation() const override;

	void SetProp4_Implementation(int32 InProp4) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1) override;
	int32 Func1_Implementation(int32 Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2) override;
	int32 Func2_Implementation(int32 Param1, int32 Param2) override;

	void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3) override;
	int32 Func3_Implementation(int32 Param1, int32 Param2, int32 Param3) override;

	void Func4Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;
	int32 Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;

protected:
	// signals
	void BroadcastSig1_Implementation(int32 Param1) override;

	void BroadcastSig2_Implementation(int32 Param1, int32 Param2) override;

	void BroadcastSig3_Implementation(int32 Param1, int32 Param2, int32 Param3) override;

	void BroadcastSig4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;

	void BroadcastProp1Changed_Implementation(int32 Prop1) override;

	void BroadcastProp2Changed_Implementation(int32 Prop2) override;

	void BroadcastProp3Changed_Implementation(int32 Prop3) override;

	void BroadcastProp4Changed_Implementation(int32 Prop4) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|ManyParamInterface")
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig1(int32 Param1);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig2(int32 Param1, int32 Param2);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig3(int32 Param1, int32 Param2, int32 Param3);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig4(int32 Param1, int32 Param2, int32 Param3, int32 Param4);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp1Changed(int32 Prop1);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp2Changed(int32 Prop2);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp3Changed(int32 Prop3);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp4Changed(int32 Prop4);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop1;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	int32 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void SetProp1_Private(int32 InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop2;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	int32 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void SetProp2_Private(int32 InProp2);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp3_Private, BlueprintSetter = SetProp3_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop3;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	int32 GetProp3_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void SetProp3_Private(int32 InProp3);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp4_Private, BlueprintSetter = SetProp4_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop4;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	int32 GetProp4_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void SetProp4_Private(int32 InProp4);
};
