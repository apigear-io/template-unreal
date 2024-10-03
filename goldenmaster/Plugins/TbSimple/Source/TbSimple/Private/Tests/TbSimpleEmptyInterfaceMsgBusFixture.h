
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"
#include "HAL/Platform.h"
#include "TbSimpleEmptyInterfaceMsgBusFixture.generated.h"

class UTbSimpleEmptyInterfaceMsgBusSpec;
class ITbSimpleEmptyInterfaceInterface;
class UTbSimpleEmptyInterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbSimpleEmptyInterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbSimpleEmptyInterfaceMsgBusHelper();

	void SetSpec(UTbSimpleEmptyInterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleEmptyInterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

class FTbSimpleEmptyInterfaceMsgBusFixture
{
public:
	FTbSimpleEmptyInterfaceMsgBusFixture();
	~FTbSimpleEmptyInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleEmptyInterfaceMsgBusHelper> GetHelper();
	UTbSimpleEmptyInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleEmptyInterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
