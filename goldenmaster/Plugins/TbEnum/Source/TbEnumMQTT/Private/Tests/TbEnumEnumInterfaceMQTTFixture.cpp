// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbEnumEnumInterfaceMQTTFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Engine/GameInstance.h"
#include "TbEnum/Generated/MQTT/TbEnumEnumInterfaceMQTTClient.h"
#include "TbEnum/Generated/MQTT/TbEnumEnumInterfaceMQTTAdapter.h"
#include "TbEnum/Implementation/TbEnumEnumInterface.h"
#include "MqttLoopbackClient.h"
#include "ApiGearMQTTClient.h"
#include "ApiGearMQTTHost.h"
#include "ApiGearConnectionsStore.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbEnum
{
namespace EnumInterface
{
namespace MQTT
{
namespace Tests
{
FTbEnumEnumInterfaceMQTTFixture::FTbEnumEnumInterfaceMQTTFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceMQTTClient>();

	// create a shared in-process broker and two loopback clients
	auto Broker = MakeShared<FMqttLoopbackBroker>();
	auto ClientLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-client"));
	auto HostLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-host"));

	// set up host with loopback transport
	Host = NewObject<UApiGearMQTTHost>(GetTransientPackage());
	Host->AddToRoot();
	Host->SetMqttImplementation(HostLoopback);

	// wire adapter to implementation and host
	auto service = GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceImplementation>();
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

FTbEnumEnumInterfaceMQTTFixture::~FTbEnumEnumInterfaceMQTTFixture()
{
	CleanUp();
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumEnumInterfaceMQTTFixture::GetImplementation()
{
	return testImplementation;
}

UApiGearMQTTHost* FTbEnumEnumInterfaceMQTTFixture::GetHost()
{
	return Host.Get();
}

UTbEnumEnumInterfaceMQTTAdapter* FTbEnumEnumInterfaceMQTTFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceMQTTAdapter>();
}

UGameInstance* FTbEnumEnumInterfaceMQTTFixture::GetGameInstance()
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

void FTbEnumEnumInterfaceMQTTFixture::CleanUp()
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
} // namespace EnumInterface
} // namespace TbEnum

#endif // WITH_DEV_AUTOMATION_TESTS
