
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbEnum_data.h"
#include "TbEnumEnumInterfaceOLinkFixture.generated.h"

class UTbEnumEnumInterfaceOLinkSpec;
class ITbEnumEnumInterfaceInterface;
class UTbEnumEnumInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbEnumEnumInterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbEnumEnumInterfaceOLinkSpec* InSpec);

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
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbEnumEnumInterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbEnumEnumInterfaceOLinkFixture
{
public:
	FTbEnumEnumInterfaceOLinkFixture();
	~FTbEnumEnumInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbEnumEnumInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbEnumEnumInterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbEnumEnumInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbEnumEnumInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbEnumEnumInterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
