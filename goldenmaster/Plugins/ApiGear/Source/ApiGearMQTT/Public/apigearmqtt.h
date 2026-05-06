// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#pragma once

#include "Modules/ModuleManager.h"
#include "Containers/UnrealString.h"

const FString ApiGearMQTTProtocolIdentifier = "mqtt";

class FApiGearMQTTModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
