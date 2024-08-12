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
#include "{{$DisplayName}}ImplFixture.generated.h"

class {{$Class}}ImplSpec;
class I{{$DisplayName}}Interface;

UCLASS()
class {{$Class}}ImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec({{$Class}}ImplSpec* InSpec);
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

protected:
	const FDoneDelegate* testDoneDelegate;
	{{$Class}}ImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class F{{ $DisplayName }}ImplFixture
{
public:
	F{{ $DisplayName }}ImplFixture();
	~F{{ $DisplayName }}ImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<I{{$DisplayName}}Interface> GetImplementation();
	TWeakObjectPtr<{{$Class}}ImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<I{{$DisplayName}}Interface> testImplementation;
	TWeakObjectPtr<{{$Class}}ImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
