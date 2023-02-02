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

#include "Testbed2EmptyInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed2EmptyInterfaceSimulationClient.generated.h"

UCLASS(BlueprintType)
class UTestbed2EmptyInterfaceSimulationClient : public UGameInstanceSubsystem, public ITestbed2EmptyInterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed2EmptyInterfaceSimulationClient();
	virtual ~UTestbed2EmptyInterfaceSimulationClient() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
	// properties
	// operations

protected:
	// signals

private:
	// properties - local copy
};