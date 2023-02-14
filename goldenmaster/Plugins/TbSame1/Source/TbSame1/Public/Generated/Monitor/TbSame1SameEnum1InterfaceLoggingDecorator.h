
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
#include "TbSame1SameEnum1InterfaceInterface.h"
#include "TbSame1SameEnum1InterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbSame1SameEnum1InterfaceLoggingDecorator, Log, All);

UCLASS(BlueprintType, Blueprintable)
class TBSAME1_API UTbSame1SameEnum1InterfaceLoggingDecorator : public UGameInstanceSubsystem, public ITbSame1SameEnum1InterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTbSame1SameEnum1InterfaceLoggingDecorator();
	virtual ~UTbSame1SameEnum1InterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
	void setBackendService(TScriptInterface<ITbSame1SameEnum1InterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum1Interface", DisplayName = "Sig1 Signal")
	FTbSame1SameEnum1InterfaceSig1Delegate Sig1Signal;
	FTbSame1SameEnum1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum1Interface", DisplayName = "Prop1 Changed")
	FTbSame1SameEnum1InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame1SameEnum1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// properties
	ETbSame1Enum1 GetProp1_Implementation() const override;

	void SetProp1_Implementation(ETbSame1Enum1 InProp1) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1) override;
	ETbSame1Enum1 Func1_Implementation(ETbSame1Enum1 Param1) override;

protected:
	// signals
	void BroadcastSig1_Implementation(ETbSame1Enum1 Param1) override;

	void BroadcastProp1Changed_Implementation(ETbSame1Enum1 Prop1) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame1|SameEnum1Interface")
	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum1Interface", BlueprintInternalUseOnly)
	void OnSig1(ETbSame1Enum1 Param1);

	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum1Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(ETbSame1Enum1 Prop1);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame1|SameEnum1Interface")
	ETbSame1Enum1 Prop1{ETbSame1Enum1::TSE_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameEnum1Interface", BlueprintInternalUseOnly)
	ETbSame1Enum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameEnum1Interface", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbSame1Enum1 InProp1);
};
