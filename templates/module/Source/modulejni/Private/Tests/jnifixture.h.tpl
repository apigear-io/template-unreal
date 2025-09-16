{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}_data.h"

class {{$Class}}JniSpec;
class I{{$DisplayName}}Interface;
class U{{$DisplayName}}JniAdapter;
class U{{$DisplayName}}JniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace {{$ModuleName}}
{
namespace {{$IfaceName}}
{
namespace Jni
{
namespace Tests
{
class F{{ $DisplayName }}JniFixture
{
public:
	F{{ $DisplayName }}JniFixture();
	~F{{ $DisplayName }}JniFixture();

	UGameInstance* GetGameInstance();
	{{$Class}}JniClient* GetClient();
	TScriptInterface<I{{$DisplayName}}Interface> GetLocalImplementation();
	{{$Class}}JniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<I{{$DisplayName}}Interface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace {{$IfaceName}}
} // namespace {{$ModuleName}}

#endif // WITH_DEV_AUTOMATION_TESTS
