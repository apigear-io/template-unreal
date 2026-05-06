// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSimpleEmptyInterfaceMQTTFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Engine/GameInstance.h"
#include "TbSimple/Generated/MQTT/TbSimpleEmptyInterfaceMQTTClient.h"
#include "TbSimple/Generated/MQTT/TbSimpleEmptyInterfaceMQTTAdapter.h"
#include "TbSimple/Implementation/TbSimpleEmptyInterface.h"
#include "MqttLoopbackClient.h"
#include "ApiGearMQTTClient.h"
#include "ApiGearMQTTHost.h"
#include "ApiGearConnectionsStore.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace EmptyInterface
{
namespace MQTT
{
namespace Tests
{
FTbSimpleEmptyInterfaceMQTTFixture::FTbSimpleEmptyInterfaceMQTTFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceMQTTClient>();

	// create a shared in-process broker and two loopback clients
	auto Broker = MakeShared<FMqttLoopbackBroker>();
	auto ClientLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-client"));
	auto HostLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-host"));

	// set up host with loopback transport
	Host = NewObject<UApiGearMQTTHost>(GetTransientPackage());
	Host->AddToRoot();
	Host->SetMqttImplementation(HostLoopback);

	// wire adapter to implementation and host
	auto service = GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceImplementation>();
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

FTbSimpleEmptyInterfaceMQTTFixture::~FTbSimpleEmptyInterfaceMQTTFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> FTbSimpleEmptyInterfaceMQTTFixture::GetImplementation()
{
	return testImplementation;
}

UApiGearMQTTHost* FTbSimpleEmptyInterfaceMQTTFixture::GetHost()
{
	return Host.Get();
}

UTbSimpleEmptyInterfaceMQTTAdapter* FTbSimpleEmptyInterfaceMQTTFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceMQTTAdapter>();
}

UGameInstance* FTbSimpleEmptyInterfaceMQTTFixture::GetGameInstance()
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

void FTbSimpleEmptyInterfaceMQTTFixture::CleanUp()
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
} // namespace EmptyInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
