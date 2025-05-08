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
#include "HAL/Platform.h"
#include "{{$DisplayName}}MsgBusFixture.generated.h"

class F{{$DisplayName}}MsgBusFixture;
class I{{$DisplayName}}Interface;
class U{{$DisplayName}}MsgBusAdapter;
class IApiGearConnection;

UCLASS()
class {{$Class}}MsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~{{$Class}}MsgBusHelper();

	void SetParentFixture(TWeakPtr<F{{ $DisplayName }}MsgBusFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}

	UFUNCTION()
	void {{ Camel .Name }}PropertyCb({{ueParam "" .}});
	UFUNCTION()
	void {{ Camel .Name }}PropertyChangeLocalCheckRemoteCb({{ueParam "" .}});
	UFUNCTION()
	void {{ Camel .Name }}PropertyChangeLocalChangeRemoteCb({{ueParam "" .}});
{{- end }}
{{- end }}
{{- range .Interface.Signals }}

	UFUNCTION()
	void {{ Camel .Name }}SignalCb({{ueParams "" .Params}});
{{- end }}

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	TWeakPtr<F{{ $DisplayName }}MsgBusFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class F{{ $DisplayName }}MsgBusFixture
{
public:
	F{{ $DisplayName }}MsgBusFixture();
	~F{{ $DisplayName }}MsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<I{{$DisplayName}}Interface> GetImplementation();
	TSoftObjectPtr<{{$Class}}MsgBusHelper> GetHelper();
	{{$Class}}MsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<I{{$DisplayName}}Interface> testImplementation;
	TSoftObjectPtr<{{$Class}}MsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
