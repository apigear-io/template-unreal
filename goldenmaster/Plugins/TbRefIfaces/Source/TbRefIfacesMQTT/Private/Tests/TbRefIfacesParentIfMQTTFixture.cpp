// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbRefIfacesParentIfMQTTFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Engine/GameInstance.h"
#include "TbRefIfaces/Generated/MQTT/TbRefIfacesParentIfMQTTClient.h"
#include "TbRefIfaces/Generated/MQTT/TbRefIfacesParentIfMQTTAdapter.h"
#include "TbRefIfaces/Implementation/TbRefIfacesParentIf.h"
#include "MqttLoopbackClient.h"
#include "ApiGearMQTTClient.h"
#include "ApiGearMQTTHost.h"
#include "ApiGearConnectionsStore.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace ParentIf
{
namespace MQTT
{
namespace Tests
{
FTbRefIfacesParentIfMQTTFixture::FTbRefIfacesParentIfMQTTFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbRefIfacesParentIfMQTTClient>();

	// create a shared in-process broker and two loopback clients
	auto Broker = MakeShared<FMqttLoopbackBroker>();
	auto ClientLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-client"));
	auto HostLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-host"));

	// set up host with loopback transport
	Host = NewObject<UApiGearMQTTHost>(GetTransientPackage());
	Host->AddToRoot();
	Host->SetMqttImplementation(HostLoopback);

	// wire adapter to implementation and host
	auto service = GetGameInstance()->GetSubsystem<UTbRefIfacesParentIfImplementation>();
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

FTbRefIfacesParentIfMQTTFixture::~FTbRefIfacesParentIfMQTTFixture()
{
	CleanUp();
}

TScriptInterface<ITbRefIfacesParentIfInterface> FTbRefIfacesParentIfMQTTFixture::GetImplementation()
{
	return testImplementation;
}

UApiGearMQTTHost* FTbRefIfacesParentIfMQTTFixture::GetHost()
{
	return Host.Get();
}

UTbRefIfacesParentIfMQTTAdapter* FTbRefIfacesParentIfMQTTFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbRefIfacesParentIfMQTTAdapter>();
}

UGameInstance* FTbRefIfacesParentIfMQTTFixture::GetGameInstance()
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

void FTbRefIfacesParentIfMQTTFixture::CleanUp()
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
} // namespace ParentIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS
