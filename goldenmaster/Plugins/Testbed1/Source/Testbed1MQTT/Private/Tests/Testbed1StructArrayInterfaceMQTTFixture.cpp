// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "Testbed1StructArrayInterfaceMQTTFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Engine/GameInstance.h"
#include "Testbed1/Generated/MQTT/Testbed1StructArrayInterfaceMQTTClient.h"
#include "Testbed1/Generated/MQTT/Testbed1StructArrayInterfaceMQTTAdapter.h"
#include "Testbed1/Implementation/Testbed1StructArrayInterface.h"
#include "MqttLoopbackClient.h"
#include "ApiGearMQTTClient.h"
#include "ApiGearMQTTHost.h"
#include "ApiGearConnectionsStore.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArrayInterface
{
namespace MQTT
{
namespace Tests
{
FTestbed1StructArrayInterfaceMQTTFixture::FTestbed1StructArrayInterfaceMQTTFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceMQTTClient>();

	// create a shared in-process broker and two loopback clients
	auto Broker = MakeShared<FMqttLoopbackBroker>();
	auto ClientLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-client"));
	auto HostLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-host"));

	// set up host with loopback transport
	Host = NewObject<UApiGearMQTTHost>(GetTransientPackage());
	Host->AddToRoot();
	Host->SetMqttImplementation(HostLoopback);

	// wire adapter to implementation and host
	auto service = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
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

FTestbed1StructArrayInterfaceMQTTFixture::~FTestbed1StructArrayInterfaceMQTTFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1StructArrayInterfaceMQTTFixture::GetImplementation()
{
	return testImplementation;
}

UApiGearMQTTHost* FTestbed1StructArrayInterfaceMQTTFixture::GetHost()
{
	return Host.Get();
}

UTestbed1StructArrayInterfaceMQTTAdapter* FTestbed1StructArrayInterfaceMQTTFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceMQTTAdapter>();
}

UGameInstance* FTestbed1StructArrayInterfaceMQTTFixture::GetGameInstance()
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

void FTestbed1StructArrayInterfaceMQTTFixture::CleanUp()
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
} // namespace StructArrayInterface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
