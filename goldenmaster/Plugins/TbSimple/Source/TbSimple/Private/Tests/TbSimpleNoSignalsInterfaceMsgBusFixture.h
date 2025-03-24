
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "HAL/Platform.h"
#include "TbSimpleNoSignalsInterfaceMsgBusFixture.generated.h"

class UTbSimpleNoSignalsInterfaceMsgBusSpec;
class ITbSimpleNoSignalsInterfaceInterface;
class UTbSimpleNoSignalsInterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbSimpleNoSignalsInterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbSimpleNoSignalsInterfaceMsgBusHelper();

	void SetSpec(UTbSimpleNoSignalsInterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(bool bPropBool);

	UFUNCTION()
	void PropIntPropertyCb(int32 PropInt);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleNoSignalsInterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleNoSignalsInterfaceMsgBusFixture
{
public:
	FTbSimpleNoSignalsInterfaceMsgBusFixture();
	~FTbSimpleNoSignalsInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleNoSignalsInterfaceMsgBusHelper> GetHelper();
	UTbSimpleNoSignalsInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleNoSignalsInterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
