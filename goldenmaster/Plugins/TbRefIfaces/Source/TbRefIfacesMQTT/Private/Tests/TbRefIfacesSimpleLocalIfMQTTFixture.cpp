// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbRefIfacesSimpleLocalIfMQTTFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Engine/GameInstance.h"
#include "TbRefIfaces/Generated/MQTT/TbRefIfacesSimpleLocalIfMQTTClient.h"
#include "TbRefIfaces/Generated/MQTT/TbRefIfacesSimpleLocalIfMQTTAdapter.h"
#include "TbRefIfaces/Implementation/TbRefIfacesSimpleLocalIf.h"
#include "MqttLoopbackClient.h"
#include "ApiGearMQTTClient.h"
#include "ApiGearMQTTHost.h"
#include "ApiGearConnectionsStore.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace SimpleLocalIf
{
namespace MQTT
{
namespace Tests
{
FTbRefIfacesSimpleLocalIfMQTTFixture::FTbRefIfacesSimpleLocalIfMQTTFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbRefIfacesSimpleLocalIfMQTTClient>();

	// create a shared in-process broker and two loopback clients
	auto Broker = MakeShared<FMqttLoopbackBroker>();
	auto ClientLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-client"));
	auto HostLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-host"));

	// set up host with loopback transport
	Host = NewObject<UApiGearMQTTHost>(GetTransientPackage());
	Host->AddToRoot();
	Host->SetMqttImplementation(HostLoopback);

	// wire adapter to implementation and host
	auto service = GetGameInstance()->GetSubsystem<UTbRefIfacesSimpleLocalIfImplementation>();
	GetAdapter()->setBackendService(service);
	GetAdapter()->setMQTTHost(Host.Get());

	// start the host side of the loopback
	Host->Start(TEXT("loopback://test"));

	// create client connection with loopback transport
	Connection = MQTTFactory::Create(GetTransientPackage(), TEXT("MQTTTestingConnection"));
	Connection.GetObject()->AddToRoot();
	auto* MQTTConnection = Cast<UApiGearMQTTClient>(Connection.GetObject());
	MQTTConnection->SetMqttImplementation(ClientLoopback);
	MQTTConnection->Configure(TEXT("loopback://test"), false);
}

FTbRefIfacesSimpleLocalIfMQTTFixture::~FTbRefIfacesSimpleLocalIfMQTTFixture()
{
	CleanUp();
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> FTbRefIfacesSimpleLocalIfMQTTFixture::GetImplementation()
{
	return testImplementation;
}

UApiGearMQTTHost* FTbRefIfacesSimpleLocalIfMQTTFixture::GetHost()
{
	return Host.Get();
}

UTbRefIfacesSimpleLocalIfMQTTAdapter* FTbRefIfacesSimpleLocalIfMQTTFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbRefIfacesSimpleLocalIfMQTTAdapter>();
}

UGameInstance* FTbRefIfacesSimpleLocalIfMQTTFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>(GetTransientPackage());
		GameInstance->Init();
		// needed to prevent garbage collection and we can't use UPROPERTY on raw c++ objects
		GameInstance->AddToRoot();
	}

	return GameInstance.Get();
}

void FTbRefIfacesSimpleLocalIfMQTTFixture::CleanUp()
{
	if (Host.IsValid())
	{
		Host->Stop();
		Host->RemoveFromRoot();
	}

	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MQTT
} // namespace SimpleLocalIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS
