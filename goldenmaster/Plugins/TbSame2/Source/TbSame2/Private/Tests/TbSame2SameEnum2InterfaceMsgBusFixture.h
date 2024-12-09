
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame2_data.h"
#include "HAL/Platform.h"
#include "TbSame2SameEnum2InterfaceMsgBusFixture.generated.h"

class UTbSame2SameEnum2InterfaceMsgBusSpec;
class ITbSame2SameEnum2InterfaceInterface;
class UTbSame2SameEnum2InterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbSame2SameEnum2InterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbSame2SameEnum2InterfaceMsgBusHelper();

	void SetSpec(UTbSame2SameEnum2InterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame2Enum1 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(ETbSame2Enum2 Prop2);

	UFUNCTION()
	void Sig1SignalCb(ETbSame2Enum1 Param1);

	UFUNCTION()
	void Sig2SignalCb(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame2SameEnum2InterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

class FTbSame2SameEnum2InterfaceMsgBusFixture
{
public:
	FTbSame2SameEnum2InterfaceMsgBusFixture();
	~FTbSame2SameEnum2InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame2SameEnum2InterfaceMsgBusHelper> GetHelper();
	UTbSame2SameEnum2InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame2SameEnum2InterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
