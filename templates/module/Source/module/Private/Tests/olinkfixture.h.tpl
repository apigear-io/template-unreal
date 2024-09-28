{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/{{$ModuleName}}_data.h"
#include "{{$DisplayName}}OLinkFixture.generated.h"

class {{$Class}}OLinkSpec;
class I{{$DisplayName}}Interface;
class U{{$DisplayName}}OLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class {{$Class}}OLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec({{$Class}}OLinkSpec* InSpec);
{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}

	UFUNCTION()
	void {{ Camel .Name }}PropertyCb({{ueParam "" .}});
{{- end }}
{{- end }}
{{- range .Interface.Signals }}

	UFUNCTION()
	void {{ Camel .Name }}SignalCb({{ueParams "" .Params}});
{{- end }}

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	{{$Class}}OLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class F{{ $DisplayName }}OLinkFixture
{
public:
	F{{ $DisplayName }}OLinkFixture();
	~F{{ $DisplayName }}OLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<I{{$DisplayName}}Interface> GetImplementation();
	TSoftObjectPtr<{{$Class}}OLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	{{$Class}}OLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<I{{$DisplayName}}Interface> testImplementation;
	TSoftObjectPtr<{{$Class}}OLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
