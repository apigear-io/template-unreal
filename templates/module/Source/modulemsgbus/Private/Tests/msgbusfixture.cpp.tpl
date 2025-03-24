{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
#include "{{$DisplayName}}MsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "{{$ModuleName}}/Generated/MsgBus/{{$DisplayName}}MsgBusClient.h"
#include "{{$ModuleName}}/Generated/MsgBus/{{$DisplayName}}MsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace {{$ModuleName}}
{
namespace {{$IfaceName}}
{
namespace MsgBus
{
namespace Tests
{
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
} // namespace Tests
} // namespace MsgBus
} // namespace {{$IfaceName}}
} // namespace {{$ModuleName}}
#endif // WITH_DEV_AUTOMATION_TESTS
