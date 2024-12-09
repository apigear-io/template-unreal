
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "HAL/Platform.h"
#include "TbSimpleVoidInterfaceMsgBusFixture.generated.h"

class UTbSimpleVoidInterfaceMsgBusSpec;
class ITbSimpleVoidInterfaceInterface;
class UTbSimpleVoidInterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbSimpleVoidInterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbSimpleVoidInterfaceMsgBusHelper();

	void SetSpec(UTbSimpleVoidInterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void SigVoidSignalCb();

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleVoidInterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

class FTbSimpleVoidInterfaceMsgBusFixture
{
public:
	FTbSimpleVoidInterfaceMsgBusFixture();
	~FTbSimpleVoidInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleVoidInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleVoidInterfaceMsgBusHelper> GetHelper();
	UTbSimpleVoidInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleVoidInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleVoidInterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
