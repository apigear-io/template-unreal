// Copyright Epic Games, Inc. All Rights Reserved
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
