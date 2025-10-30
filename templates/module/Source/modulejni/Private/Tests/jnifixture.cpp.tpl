{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
#include "{{$DisplayName}}JniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "{{$ModuleName}}/Generated/Jni/{{$DisplayName}}JniClient.h"
#include "{{$ModuleName}}/Generated/Jni/{{$DisplayName}}JniAdapter.h"
#include "{{$ModuleName}}/Implementation/{{$DisplayName}}.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace {{$ModuleName}}
{
namespace {{$IfaceName}}
{
namespace Jni
{
namespace Tests
{
F{{ $DisplayName }}JniFixture::F{{ $DisplayName }}JniFixture()
{
	source = GetGameInstance()->GetSubsystem<U{{$DisplayName}}Implementation>();
}

F{{ $DisplayName }}JniFixture::~F{{ $DisplayName }}JniFixture()
{
	CleanUp();
}

{{$Class}}JniClient* F{{ $DisplayName }}JniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<U{{ $DisplayName }}JniClient>();
}

TScriptInterface<I{{$DisplayName}}Interface> F{{ $DisplayName }}JniFixture::GetLocalImplementation()
{
	return source;
}

U{{ $DisplayName }}JniAdapter* F{{ $DisplayName }}JniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<U{{ $DisplayName }}JniAdapter>();
}

UGameInstance* F{{ $DisplayName }}JniFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>(GetTransientPackage());
		GameInstance->Init();
		// needed to prevent garbage collection and we can't use UPROPERTY on raw c++ objects
		GameInstance->AddToRoot();
	}

	return GameInstance.Get();
}

void F{{ $DisplayName }}JniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace {{$IfaceName}}
} // namespace {{$ModuleName}}
#endif // WITH_DEV_AUTOMATION_TESTS
