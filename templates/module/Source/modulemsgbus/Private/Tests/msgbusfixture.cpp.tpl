{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
#include "{{$DisplayName}}MsgBusFixture.h"
#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "{{$ModuleName}}/Generated/MsgBus/{{$DisplayName}}MsgBusClient.h"
#include "{{$ModuleName}}/Generated/MsgBus/{{$DisplayName}}MsgBusAdapter.h"
#include "Engine/GameInstance.h"

F{{ $DisplayName }}MsgBusFixture::F{{ $DisplayName }}MsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<{{ $Class }}MsgBusClient>();
}

F{{ $DisplayName }}MsgBusFixture::~F{{ $DisplayName }}MsgBusFixture()
{
	CleanUp();
}

TScriptInterface<I{{$DisplayName}}Interface> F{{ $DisplayName }}MsgBusFixture::GetImplementation()
{
	return testImplementation;
}

U{{ $DisplayName }}MsgBusAdapter* F{{ $DisplayName }}MsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<U{{ $DisplayName }}MsgBusAdapter>();
}

UGameInstance* F{{ $DisplayName }}MsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void F{{ $DisplayName }}MsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
