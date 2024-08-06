// Copyright Epic Games, Inc. All Rights Reserved
#include "ApiGearOLink.h"
#include "Modules/ModuleManager.h"
#include "WebSocketsModule.h"
#include "ApiGearConnectionsStore.h"
#include "OLinkClientConnection.h"
#include "IWebSocketNetworkingModule.h"

#define LOCTEXT_NAMESPACE "FApiGearOLinkModule"

void FApiGearOLinkModule::StartupModule()
{
	// used by olink client implementations
	FModuleManager::LoadModuleChecked<FWebSocketsModule>(TEXT("WebSockets"));

	// register olink factory function
	UApiGearConnectionsStore::RegisterConnectionFactory(ApiGearOLinkProtocolIdentifier, &OLinkFactory::Create);

	// used by the olink websocket server host
	FModuleManager::LoadModuleChecked<IWebSocketNetworkingModule>(TEXT("WebSocketNetworking"));
}

void FApiGearOLinkModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FApiGearOLinkModule, ApiGearOLink)
