
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbEnum/Generated/api/TbEnum_data.h"
#include "HAL/Platform.h"
#include "TbEnumEnumInterfaceMsgBusFixture.generated.h"

class UTbEnumEnumInterfaceMsgBusSpec;
class ITbEnumEnumInterfaceInterface;
class UTbEnumEnumInterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbEnumEnumInterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbEnumEnumInterfaceMsgBusHelper();

	void SetSpec(UTbEnumEnumInterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void Prop0PropertyCb(ETbEnumEnum0 Prop0);

	UFUNCTION()
	void Prop1PropertyCb(ETbEnumEnum1 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(ETbEnumEnum2 Prop2);

	UFUNCTION()
	void Prop3PropertyCb(ETbEnumEnum3 Prop3);

	UFUNCTION()
	void Sig0SignalCb(ETbEnumEnum0 Param0);

	UFUNCTION()
	void Sig1SignalCb(ETbEnumEnum1 Param1);

	UFUNCTION()
	void Sig2SignalCb(ETbEnumEnum2 Param2);

	UFUNCTION()
	void Sig3SignalCb(ETbEnumEnum3 Param3);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbEnumEnumInterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

class FTbEnumEnumInterfaceMsgBusFixture
{
public:
	FTbEnumEnumInterfaceMsgBusFixture();
	~FTbEnumEnumInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbEnumEnumInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbEnumEnumInterfaceMsgBusHelper> GetHelper();
	UTbEnumEnumInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbEnumEnumInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbEnumEnumInterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
