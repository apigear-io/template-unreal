{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
#include "{{$DisplayName}}ImplFixture.h"
#include "{{$DisplayName}}Impl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

void {{$Class}}ImplHelper::SetSpec({{$Class}}ImplSpec* InSpec)
{
	Spec = InSpec;
}

{{- range .Interface.Signals }}

void {{$Class}}ImplHelper::{{ Camel .Name }}SignalCb({{ueParams "" .Params}})
{
	Spec->{{ Camel .Name }}SignalCb({{ueVars "" .Params}});
}
{{- end }}

#if WITH_DEV_AUTOMATION_TESTS

F{{ $DisplayName }}ImplFixture::F{{ $DisplayName }}ImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<{{ $Class }}>();
	Helper = NewObject<{{$Class}}ImplHelper>();
}

F{{ $DisplayName }}ImplFixture::~F{{ $DisplayName }}ImplFixture()
{
	CleanUp();
}

TScriptInterface<I{{$DisplayName}}Interface> F{{ $DisplayName }}ImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<{{$Class}}ImplHelper> F{{ $DisplayName }}ImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* F{{ $DisplayName }}ImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void F{{ $DisplayName }}ImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS