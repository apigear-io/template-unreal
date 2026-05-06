// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_data.h"

class UTbRefIfacesParentIfMQTTSpec;
class ITbRefIfacesParentIfInterface;
class UTbRefIfacesParentIfMQTTAdapter;
class IApiGearConnection;
class UApiGearMQTTClient;
class UApiGearMQTTHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace ParentIf
{
namespace MQTT
{
namespace Tests
{
class FTbRefIfacesParentIfMQTTFixture
{
public:
	FTbRefIfacesParentIfMQTTFixture();
	~FTbRefIfacesParentIfMQTTFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefIfacesParentIfInterface> GetImplementation();
	UApiGearMQTTHost* GetHost();
	UTbRefIfacesParentIfMQTTAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefIfacesParentIfInterface> testImplementation;
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
} // namespace Tests
} // namespace MQTT
} // namespace ParentIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS
