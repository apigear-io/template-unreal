// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2/Generated/api/TbSame2_data.h"

class UTbSame2SameStruct1InterfaceMQTTSpec;
class ITbSame2SameStruct1InterfaceInterface;
class UTbSame2SameStruct1InterfaceMQTTAdapter;
class IApiGearConnection;
class UApiGearMQTTClient;
class UApiGearMQTTHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameStruct1Interface
{
namespace MQTT
{
namespace Tests
{
class FTbSame2SameStruct1InterfaceMQTTFixture
{
public:
	FTbSame2SameStruct1InterfaceMQTTFixture();
	~FTbSame2SameStruct1InterfaceMQTTFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> GetImplementation();
	UApiGearMQTTHost* GetHost();
	UTbSame2SameStruct1InterfaceMQTTAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
} // namespace Tests
} // namespace MQTT
} // namespace SameStruct1Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS
