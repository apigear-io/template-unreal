// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed1/Generated/api/Testbed1_data.h"

class UTestbed1StructInterfaceMQTTSpec;
class ITestbed1StructInterfaceInterface;
class UTestbed1StructInterfaceMQTTAdapter;
class IApiGearConnection;
class UApiGearMQTTClient;
class UApiGearMQTTHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructInterface
{
namespace MQTT
{
namespace Tests
{
class FTestbed1StructInterfaceMQTTFixture
{
public:
	FTestbed1StructInterfaceMQTTFixture();
	~FTestbed1StructInterfaceMQTTFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructInterfaceInterface> GetImplementation();
	UApiGearMQTTHost* GetHost();
	UTestbed1StructInterfaceMQTTAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructInterfaceInterface> testImplementation;
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
} // namespace Tests
} // namespace MQTT
} // namespace StructInterface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
