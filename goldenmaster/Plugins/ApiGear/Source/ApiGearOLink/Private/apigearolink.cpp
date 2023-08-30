// Copyright Epic Games, Inc. All Rights Reserved
#include "apigearolink.h"
#include "Modules/ModuleManager.h"
#include "WebSocketsModule.h"
#include "ApiGearConnectionsStore.h"
#include "unrealolink.h"

#define LOCTEXT_NAMESPACE "FApiGearModuleOLink"

void FApiGearModuleOLink::StartupModule()
{
	// No Libraries to load from non mobile platforms because of the web api
	FWebSocketsModule& WebSocketsModule = FModuleManager::LoadModuleChecked<FWebSocketsModule>(TEXT("WebSockets"));

	// register olink factory function
	UApiGearConnectionsStore::RegisterConnectionFactory(ApiGearOLinkProtocolIdentifier, &OLinkFactory::Create);
}

void FApiGearModuleOLink::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FApiGearModuleOLink, ApiGearOLink)
