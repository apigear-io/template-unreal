
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
class TBENUM_API UTbEnumEnumInterfaceLoggingDecorator : public UAbstractTbEnumEnumInterface
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

	// properties
	ETbEnumEnum0 GetProp0_Implementation() const override;

	void SetProp0_Implementation(ETbEnumEnum0 InProp0) override;

	ETbEnumEnum1 GetProp1_Implementation() const override;

	void SetProp1_Implementation(ETbEnumEnum1 InProp1) override;

	ETbEnumEnum2 GetProp2_Implementation() const override;

	void SetProp2_Implementation(ETbEnumEnum2 InProp2) override;

	ETbEnumEnum3 GetProp3_Implementation() const override;

	void SetProp3_Implementation(ETbEnumEnum3 InProp3) override;

	// operations
	void Func0Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0) override;
	ETbEnumEnum0 Func0_Implementation(ETbEnumEnum0 Param0) override;

	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1) override;
	ETbEnumEnum1 Func1_Implementation(ETbEnumEnum1 Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2) override;
	ETbEnumEnum2 Func2_Implementation(ETbEnumEnum2 Param2) override;

	void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3) override;
	ETbEnumEnum3 Func3_Implementation(ETbEnumEnum3 Param3) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbEnum|EnumInterface")
	TScriptInterface<ITbEnumEnumInterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig0(ETbEnumEnum0 Param0);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig1(ETbEnumEnum1 Param1);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig2(ETbEnumEnum2 Param2);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig3(ETbEnumEnum3 Param3);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp0Changed(ETbEnumEnum0 Prop0);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp1Changed(ETbEnumEnum1 Prop1);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp2Changed(ETbEnumEnum2 Prop2);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp3Changed(ETbEnumEnum3 Prop3);
};
