// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSame2SameStruct2InterfaceMQTTFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Engine/GameInstance.h"
#include "TbSame2/Generated/MQTT/TbSame2SameStruct2InterfaceMQTTClient.h"
#include "TbSame2/Generated/MQTT/TbSame2SameStruct2InterfaceMQTTAdapter.h"
#include "TbSame2/Implementation/TbSame2SameStruct2Interface.h"
#include "MqttLoopbackClient.h"
#include "ApiGearMQTTClient.h"
#include "ApiGearMQTTHost.h"
#include "ApiGearConnectionsStore.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameStruct2Interface
{
namespace MQTT
{
namespace Tests
{
FTbSame2SameStruct2InterfaceMQTTFixture::FTbSame2SameStruct2InterfaceMQTTFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameStruct2InterfaceMQTTClient>();

	// create a shared in-process broker and two loopback clients
	auto Broker = MakeShared<FMqttLoopbackBroker>();
	auto ClientLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-client"));
	auto HostLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-host"));

	// set up host with loopback transport
	Host = NewObject<UApiGearMQTTHost>(GetTransientPackage());
	Host->AddToRoot();
	Host->SetMqttImplementation(HostLoopback);

	// wire adapter to implementation and host
	auto service = GetGameInstance()->GetSubsystem<UTbSame2SameStruct2InterfaceImplementation>();
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

FTbSame2SameStruct2InterfaceMQTTFixture::~FTbSame2SameStruct2InterfaceMQTTFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> FTbSame2SameStruct2InterfaceMQTTFixture::GetImplementation()
{
	return testImplementation;
}

UApiGearMQTTHost* FTbSame2SameStruct2InterfaceMQTTFixture::GetHost()
{
	return Host.Get();
}

UTbSame2SameStruct2InterfaceMQTTAdapter* FTbSame2SameStruct2InterfaceMQTTFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameStruct2InterfaceMQTTAdapter>();
}

UGameInstance* FTbSame2SameStruct2InterfaceMQTTFixture::GetGameInstance()
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

void FTbSame2SameStruct2InterfaceMQTTFixture::CleanUp()
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
} // namespace SameStruct2Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS
