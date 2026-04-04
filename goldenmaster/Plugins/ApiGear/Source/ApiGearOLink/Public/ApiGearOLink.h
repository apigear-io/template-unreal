// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#pragma once

#include "Modules/ModuleManager.h"
#include "Containers/UnrealString.h"

const FString ApiGearOLinkProtocolIdentifier = "olink";

class FApiGearOLinkModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
