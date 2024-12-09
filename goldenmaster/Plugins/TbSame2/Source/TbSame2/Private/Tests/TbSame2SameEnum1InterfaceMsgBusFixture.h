
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame2_data.h"
#include "HAL/Platform.h"
#include "TbSame2SameEnum1InterfaceMsgBusFixture.generated.h"

class UTbSame2SameEnum1InterfaceMsgBusSpec;
class ITbSame2SameEnum1InterfaceInterface;
class UTbSame2SameEnum1InterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbSame2SameEnum1InterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbSame2SameEnum1InterfaceMsgBusHelper();

	void SetSpec(UTbSame2SameEnum1InterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame2Enum1 Prop1);

	UFUNCTION()
	void Sig1SignalCb(ETbSame2Enum1 Param1);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame2SameEnum1InterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

class FTbSame2SameEnum1InterfaceMsgBusFixture
{
public:
	FTbSame2SameEnum1InterfaceMsgBusFixture();
	~FTbSame2SameEnum1InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame2SameEnum1InterfaceMsgBusHelper> GetHelper();
	UTbSame2SameEnum1InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame2SameEnum1InterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
