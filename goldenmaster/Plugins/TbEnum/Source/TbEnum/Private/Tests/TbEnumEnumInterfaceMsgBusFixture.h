
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbEnum_data.h"
#include "HAL/Platform.h"
#include "TbEnumEnumInterfaceMsgBusFixture.generated.h"

class FTbEnumEnumInterfaceMsgBusFixture;
class ITbEnumEnumInterfaceInterface;
class UTbEnumEnumInterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbEnumEnumInterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbEnumEnumInterfaceMsgBusHelper();

	void SetParentFixture(TWeakPtr<FTbEnumEnumInterfaceMsgBusFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop0PropertyCb(ETbEnumEnum0 Prop0);
	UFUNCTION()
	void Prop0PropertyChangeLocalCheckRemoteCb(ETbEnumEnum0 Prop0);
	UFUNCTION()
	void Prop0PropertyChangeLocalChangeRemoteCb(ETbEnumEnum0 Prop0);

	UFUNCTION()
	void Prop1PropertyCb(ETbEnumEnum1 Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalCheckRemoteCb(ETbEnumEnum1 Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalChangeRemoteCb(ETbEnumEnum1 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(ETbEnumEnum2 Prop2);
	UFUNCTION()
	void Prop2PropertyChangeLocalCheckRemoteCb(ETbEnumEnum2 Prop2);
	UFUNCTION()
	void Prop2PropertyChangeLocalChangeRemoteCb(ETbEnumEnum2 Prop2);

	UFUNCTION()
	void Prop3PropertyCb(ETbEnumEnum3 Prop3);
	UFUNCTION()
	void Prop3PropertyChangeLocalCheckRemoteCb(ETbEnumEnum3 Prop3);
	UFUNCTION()
	void Prop3PropertyChangeLocalChangeRemoteCb(ETbEnumEnum3 Prop3);

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
	TWeakPtr<FTbEnumEnumInterfaceMsgBusFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

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

#endif // WITH_DEV_AUTOMATION_TESTS
