/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSimple_data.h"
#include "TbSimple/Generated/api/TbSimpleEmptyInterfaceInterface.h"
#include "AbstractTbSimpleEmptyInterface.generated.h"

/**
 * Abstract UAbstractTbSimpleEmptyInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSIMPLEAPI_API UAbstractTbSimpleEmptyInterface : public UGameInstanceSubsystem, public ITbSimpleEmptyInterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSimpleEmptyInterface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSimpleEmptyInterfacePublisher* _GetPublisher() override;

	// methods

	// properties

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy

private:
	// signals
	UPROPERTY()
	UTbSimpleEmptyInterfacePublisher* TbSimpleEmptyInterfacePublisher;
};
