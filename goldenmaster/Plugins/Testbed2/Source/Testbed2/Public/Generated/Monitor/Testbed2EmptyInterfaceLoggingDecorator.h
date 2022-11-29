
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
#include "Testbed2EmptyInterfaceInterface.h"
#include "Testbed2EmptyInterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2EmptyInterfaceLoggingDecorator, Log, All);

UCLASS(BlueprintType, Blueprintable)
class TESTBED2_API UTestbed2EmptyInterfaceLoggingDecorator : public UGameInstanceSubsystem, public ITestbed2EmptyInterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTestbed2EmptyInterfaceLoggingDecorator();
	virtual ~UTestbed2EmptyInterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|EmptyInterface")
	void setBackendService(TScriptInterface<ITestbed2EmptyInterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
	// properties
	// operations
protected:
	// signals

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|EmptyInterface")
	TScriptInterface<ITestbed2EmptyInterfaceInterface> BackendService;

	// signals

	// properties - local copy
};
