
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "TbSimpleNoPropertiesInterfaceImplFixture.generated.h"

class UTbSimpleNoPropertiesInterfaceImplSpec;
class ITbSimpleNoPropertiesInterfaceInterface;

UCLASS()
class UTbSimpleNoPropertiesInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleNoPropertiesInterfaceImplSpec* InSpec);

	UFUNCTION()
	void SigVoidSignalCb();

	UFUNCTION()
	void SigBoolSignalCb(bool bParamBool);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleNoPropertiesInterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleNoPropertiesInterfaceImplFixture
{
public:
	FTbSimpleNoPropertiesInterfaceImplFixture();
	~FTbSimpleNoPropertiesInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleNoPropertiesInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleNoPropertiesInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
