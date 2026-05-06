// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbEnum/Generated/api/TbEnum_data.h"

class UTbEnumEnumInterfaceMQTTSpec;
class ITbEnumEnumInterfaceInterface;
class UTbEnumEnumInterfaceMQTTAdapter;
class IApiGearConnection;
class UApiGearMQTTClient;
class UApiGearMQTTHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbEnum
{
namespace EnumInterface
{
namespace MQTT
{
namespace Tests
{
class FTbEnumEnumInterfaceMQTTFixture
{
public:
	FTbEnumEnumInterfaceMQTTFixture();
	~FTbEnumEnumInterfaceMQTTFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbEnumEnumInterfaceInterface> GetImplementation();
	UApiGearMQTTHost* GetHost();
	UTbEnumEnumInterfaceMQTTAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbEnumEnumInterfaceInterface> testImplementation;
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
} // namespace Tests
} // namespace MQTT
} // namespace EnumInterface
} // namespace TbEnum

#endif // WITH_DEV_AUTOMATION_TESTS
