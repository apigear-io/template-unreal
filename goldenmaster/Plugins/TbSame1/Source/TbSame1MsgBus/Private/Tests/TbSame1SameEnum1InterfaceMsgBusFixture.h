
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"
#include "HAL/Platform.h"
#include "TbSame1SameEnum1InterfaceMsgBusFixture.generated.h"

class UTbSame1SameEnum1InterfaceMsgBusSpec;
class ITbSame1SameEnum1InterfaceInterface;
class UTbSame1SameEnum1InterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbSame1SameEnum1InterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbSame1SameEnum1InterfaceMsgBusHelper();

	void SetSpec(UTbSame1SameEnum1InterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame1Enum1 Prop1);

	UFUNCTION()
	void Sig1SignalCb(ETbSame1Enum1 Param1);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame1SameEnum1InterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

class FTbSame1SameEnum1InterfaceMsgBusFixture
{
public:
	FTbSame1SameEnum1InterfaceMsgBusFixture();
	~FTbSame1SameEnum1InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame1SameEnum1InterfaceMsgBusHelper> GetHelper();
	UTbSame1SameEnum1InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame1SameEnum1InterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
