
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"
#include "HAL/Platform.h"
#include "TbSimpleNoPropertiesInterfaceMsgBusFixture.generated.h"

class UTbSimpleNoPropertiesInterfaceMsgBusSpec;
class ITbSimpleNoPropertiesInterfaceInterface;
class UTbSimpleNoPropertiesInterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbSimpleNoPropertiesInterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbSimpleNoPropertiesInterfaceMsgBusHelper();

	void SetSpec(UTbSimpleNoPropertiesInterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void SigVoidSignalCb();

	UFUNCTION()
	void SigBoolSignalCb(bool bParamBool);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleNoPropertiesInterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

class FTbSimpleNoPropertiesInterfaceMsgBusFixture
{
public:
	FTbSimpleNoPropertiesInterfaceMsgBusFixture();
	~FTbSimpleNoPropertiesInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleNoPropertiesInterfaceMsgBusHelper> GetHelper();
	UTbSimpleNoPropertiesInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleNoPropertiesInterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
