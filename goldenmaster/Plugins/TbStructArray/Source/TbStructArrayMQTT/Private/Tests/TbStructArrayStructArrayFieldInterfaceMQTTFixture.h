// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbStructArray/Generated/api/TbStructArray_data.h"

class UTbStructArrayStructArrayFieldInterfaceMQTTSpec;
class ITbStructArrayStructArrayFieldInterfaceInterface;
class UTbStructArrayStructArrayFieldInterfaceMQTTAdapter;
class IApiGearConnection;
class UApiGearMQTTClient;
class UApiGearMQTTHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbStructArray
{
namespace StructArrayFieldInterface
{
namespace MQTT
{
namespace Tests
{
class FTbStructArrayStructArrayFieldInterfaceMQTTFixture
{
public:
	FTbStructArrayStructArrayFieldInterfaceMQTTFixture();
	~FTbStructArrayStructArrayFieldInterfaceMQTTFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> GetImplementation();
	UApiGearMQTTHost* GetHost();
	UTbStructArrayStructArrayFieldInterfaceMQTTAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> testImplementation;
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
} // namespace Tests
} // namespace MQTT
} // namespace StructArrayFieldInterface
} // namespace TbStructArray

#endif // WITH_DEV_AUTOMATION_TESTS
