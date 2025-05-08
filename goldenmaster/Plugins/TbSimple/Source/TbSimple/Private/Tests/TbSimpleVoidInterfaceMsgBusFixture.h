
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "HAL/Platform.h"
#include "TbSimpleVoidInterfaceMsgBusFixture.generated.h"

class FTbSimpleVoidInterfaceMsgBusFixture;
class ITbSimpleVoidInterfaceInterface;
class UTbSimpleVoidInterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbSimpleVoidInterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbSimpleVoidInterfaceMsgBusHelper();

	void SetParentFixture(TWeakPtr<FTbSimpleVoidInterfaceMsgBusFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void SigVoidSignalCb();

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	TWeakPtr<FTbSimpleVoidInterfaceMsgBusFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

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

#endif // WITH_DEV_AUTOMATION_TESTS
