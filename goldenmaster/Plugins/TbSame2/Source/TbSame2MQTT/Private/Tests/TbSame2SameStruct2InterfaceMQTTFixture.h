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

class UTbSame2SameStruct2InterfaceMQTTSpec;
class ITbSame2SameStruct2InterfaceInterface;
class UTbSame2SameStruct2InterfaceMQTTAdapter;
class IApiGearConnection;
class UApiGearMQTTClient;
class UApiGearMQTTHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameStruct2Interface
{
namespace MQTT
{
namespace Tests
{
class FTbSame2SameStruct2InterfaceMQTTFixture
{
public:
	FTbSame2SameStruct2InterfaceMQTTFixture();
	~FTbSame2SameStruct2InterfaceMQTTFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> GetImplementation();
	UApiGearMQTTHost* GetHost();
	UTbSame2SameStruct2InterfaceMQTTAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
} // namespace Tests
} // namespace MQTT
} // namespace SameStruct2Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS
