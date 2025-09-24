
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
#include "TbSame2/Generated/api/AbstractTbSame2SameStruct2Interface.h"
#include "TbSame2SameStruct2InterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbSame2SameStruct2InterfaceLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME2MONITOR_API UTbSame2SameStruct2InterfaceLoggingDecorator : public UAbstractTbSame2SameStruct2Interface, public ITbSame2SameStruct2InterfaceSubscriberInterface
{
	GENERATED_BODY()

public:
	explicit UTbSame2SameStruct2InterfaceLoggingDecorator();
	virtual ~UTbSame2SameStruct2InterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface")
	void setBackendService(TScriptInterface<ITbSame2SameStruct2InterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FTbSame2Struct2 GetProp1() const override;

	void SetProp1(const FTbSame2Struct2& InProp1) override;

	FTbSame2Struct2 GetProp2() const override;

	void SetProp2(const FTbSame2Struct2& InProp2) override;

	// operations
	FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) override;

	FTbSame2Struct1 Func2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame2|SameStruct2Interface")
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> BackendService;

	// signals
	void OnSig1Signal(const FTbSame2Struct1& InParam1);

	void OnSig2Signal(const FTbSame2Struct1& InParam1, const FTbSame2Struct2& InParam2);

	void OnProp1Changed(const FTbSame2Struct2& InProp1);

	void OnProp2Changed(const FTbSame2Struct2& InProp2);
};
