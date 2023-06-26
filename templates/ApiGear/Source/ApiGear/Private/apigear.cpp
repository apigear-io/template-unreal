// Copyright Epic Games, Inc. All Rights Reserved
#include "apigear.h"
#include "Modules/ModuleManager.h"
#include "HttpModule.h"

#define LOCTEXT_NAMESPACE "FApiGearModule"

void FApiGearModule::StartupModule()
{
	// No Libraries to load from non mobile platforms because of the web api
	FHttpModule& HttpModule = FModuleManager::LoadModuleChecked<FHttpModule>(TEXT("HTTP"));
}

void FApiGearModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FApiGearModule, ApiGear)
