
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
#include "TbSame1/Generated/api/AbstractTbSame1SameEnum2Interface.h"
#include "TbSame1SameEnum2InterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbSame1SameEnum2InterfaceLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME1_API UTbSame1SameEnum2InterfaceLoggingDecorator : public UAbstractTbSame1SameEnum2Interface
{
	GENERATED_BODY()

public:
	explicit UTbSame1SameEnum2InterfaceLoggingDecorator();
	virtual ~UTbSame1SameEnum2InterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
	void setBackendService(TScriptInterface<ITbSame1SameEnum2InterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	ETbSame1Enum1 GetProp1_Implementation() const override;

	void SetProp1_Implementation(ETbSame1Enum1 InProp1) override;

	ETbSame1Enum2 GetProp2_Implementation() const override;

	void SetProp2_Implementation(ETbSame1Enum2 InProp2) override;

	// operations
	ETbSame1Enum1 Func1_Implementation(ETbSame1Enum1 Param1) override;

	ETbSame1Enum1 Func2_Implementation(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame1|SameEnum2Interface")
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnSig1(ETbSame1Enum1 InParam1);

	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnSig2(ETbSame1Enum1 InParam1, ETbSame1Enum2 InParam2);

	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(ETbSame1Enum1 InProp1);

	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
	void OnProp2Changed(ETbSame1Enum2 InProp2);
};
