// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleSimpleInterfaceMQTTSpec;
class ITbSimpleSimpleInterfaceInterface;
class UTbSimpleSimpleInterfaceMQTTAdapter;
class IApiGearConnection;
class UApiGearMQTTClient;
class UApiGearMQTTHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace SimpleInterface
{
namespace MQTT
{
namespace Tests
{
class FTbSimpleSimpleInterfaceMQTTFixture
{
public:
	FTbSimpleSimpleInterfaceMQTTFixture();
	~FTbSimpleSimpleInterfaceMQTTFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> GetImplementation();
	UApiGearMQTTHost* GetHost();
	UTbSimpleSimpleInterfaceMQTTAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> testImplementation;
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
} // namespace Tests
} // namespace MQTT
} // namespace SimpleInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
