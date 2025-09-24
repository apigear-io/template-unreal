
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
#include "TbRefIfaces/Generated/api/AbstractTbRefIfacesSimpleLocalIf.h"
#include "TbRefIfacesSimpleLocalIfLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbRefIfacesSimpleLocalIfLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBREFIFACESMONITOR_API UTbRefIfacesSimpleLocalIfLoggingDecorator : public UAbstractTbRefIfacesSimpleLocalIf, public ITbRefIfacesSimpleLocalIfSubscriberInterface
{
	GENERATED_BODY()

public:
	explicit UTbRefIfacesSimpleLocalIfLoggingDecorator();
	virtual ~UTbRefIfacesSimpleLocalIfLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf")
	void setBackendService(TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	int32 GetIntProperty() const override;

	void SetIntProperty(int32 InIntProperty) override;

	// operations
	int32 IntMethod(int32 Param) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefIfaces|SimpleLocalIf")
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> BackendService;

	// signals
	void OnIntSignalSignal(int32 InParam);

	void OnIntPropertyChanged(int32 InIntProperty);
};
