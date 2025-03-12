{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}_data.h"

class {{$Class}}OLinkSpec;
class I{{$DisplayName}}Interface;
class U{{$DisplayName}}OLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace {{$ModuleName}}
{
namespace {{$IfaceName}}
{
namespace OLink
{
namespace Tests
{
class F{{ $DisplayName }}OLinkFixture
{
public:
	F{{ $DisplayName }}OLinkFixture();
	~F{{ $DisplayName }}OLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<I{{$DisplayName}}Interface> GetImplementation();
	UOLinkHost* GetHost();
	{{$Class}}OLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<I{{$DisplayName}}Interface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace {{$IfaceName}}
} // namespace {{$ModuleName}}

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
