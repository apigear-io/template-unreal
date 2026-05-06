// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSame1SameStruct2InterfaceMQTTFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Engine/GameInstance.h"
#include "TbSame1/Generated/MQTT/TbSame1SameStruct2InterfaceMQTTClient.h"
#include "TbSame1/Generated/MQTT/TbSame1SameStruct2InterfaceMQTTAdapter.h"
#include "TbSame1/Implementation/TbSame1SameStruct2Interface.h"
#include "MqttLoopbackClient.h"
#include "ApiGearMQTTClient.h"
#include "ApiGearMQTTHost.h"
#include "ApiGearConnectionsStore.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameStruct2Interface
{
namespace MQTT
{
namespace Tests
{
FTbSame1SameStruct2InterfaceMQTTFixture::FTbSame1SameStruct2InterfaceMQTTFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceMQTTClient>();

	// create a shared in-process broker and two loopback clients
	auto Broker = MakeShared<FMqttLoopbackBroker>();
	auto ClientLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-client"));
	auto HostLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-host"));

	// set up host with loopback transport
	Host = NewObject<UApiGearMQTTHost>(GetTransientPackage());
	Host->AddToRoot();
	Host->SetMqttImplementation(HostLoopback);

	// wire adapter to implementation and host
	auto service = GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceImplementation>();
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

FTbSame1SameStruct2InterfaceMQTTFixture::~FTbSame1SameStruct2InterfaceMQTTFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> FTbSame1SameStruct2InterfaceMQTTFixture::GetImplementation()
{
	return testImplementation;
}

UApiGearMQTTHost* FTbSame1SameStruct2InterfaceMQTTFixture::GetHost()
{
	return Host.Get();
}

UTbSame1SameStruct2InterfaceMQTTAdapter* FTbSame1SameStruct2InterfaceMQTTFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceMQTTAdapter>();
}

UGameInstance* FTbSame1SameStruct2InterfaceMQTTFixture::GetGameInstance()
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

void FTbSame1SameStruct2InterfaceMQTTFixture::CleanUp()
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
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS
