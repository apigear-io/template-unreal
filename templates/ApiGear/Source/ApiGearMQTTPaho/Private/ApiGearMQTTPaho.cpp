// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "ApiGearMQTTPaho.h"
#include "Modules/ModuleManager.h"
#include "ApiGearConnectionsStore.h"
#include "ApiGearMQTTClient.h"
#include "PahoMqttClient.h"
#include "apigearmqtt.h"

#define LOCTEXT_NAMESPACE "FApiGearMQTTPahoModule"

static TScriptInterface<IApiGearConnection> CreatePahoMQTTConnection(
	UObject* Outer, FString UniqueConnectionIdentifier)
{
	UApiGearMQTTClient* Client = NewObject<UApiGearMQTTClient>(Outer, *UniqueConnectionIdentifier);
	Client->SetMqttImplementation(MakeShared<FPahoMqttClient>());
	return TScriptInterface<IApiGearConnection>(Client);
}

void FApiGearMQTTPahoModule::StartupModule()
{
	UApiGearConnectionsStore::RegisterConnectionFactory(
		ApiGearMQTTProtocolIdentifier, &CreatePahoMQTTConnection);
}

void FApiGearMQTTPahoModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FApiGearMQTTPahoModule, ApiGearMQTTPaho)
