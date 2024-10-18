/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include "Testbed1Settings.h"
#include "Testbed1/Generated/Testbed1Factory.h"
#include "Testbed1/Generated/Testbed1LogCategories.h"
#include "ApiGearConnectionsStore.h"
#include "Engine/Engine.h"
#include "Misc/CoreDelegates.h"

UTestbed1Settings::UTestbed1Settings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FCoreDelegates::OnPostEngineInit.AddUObject(this, &UTestbed1Settings::ValidateSettingsPostEngineInit);
}

void UTestbed1Settings::ValidateSettingsPostEngineInit()
{
	check(GEngine);
	UApiGearConnectionsStore* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	if (!AGCM->DoesConnectionExist(OLinkConnectionIdentifier))
	{
		UE_LOG(LogTestbed1, Warning, TEXT("UTestbed1Settings could not find connection %s."), *OLinkConnectionIdentifier);
		OLinkConnectionIdentifier = "";
	}

	// the local backend does not require configuration
	if (TracerServiceIdentifier == Testbed1LocalBackendIdentifier)
	{
		return;
	}

	if (!AGCM->DoesConnectionExist(TracerServiceIdentifier))
	{
		UE_LOG(LogTestbed1, Warning, TEXT("UTestbed1Settings could not find connection %s, falling back to local backend."), *TracerServiceIdentifier);
		TracerServiceIdentifier = Testbed1LocalBackendIdentifier;
	}
}

TScriptInterface<ITestbed1StructInterfaceInterface> UTestbed1Settings::GetITestbed1StructInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTestbed1Settings* Testbed1Settings = GetMutableDefault<UTestbed1Settings>();

	FString BackendIdentifier = Testbed1Settings->TracerServiceIdentifier;

	if (Testbed1Settings->TracerServiceIdentifier == Testbed1LocalBackendIdentifier)
	{
		return FTestbed1ModuleFactory::GetTestbed1StructInterfaceImplementation(Testbed1LocalBackendIdentifier, Collection);
	}

	if (Testbed1Settings->TracerServiceIdentifier != Testbed1LocalBackendIdentifier)
	{
		return FTestbed1ModuleFactory::GetTestbed1StructInterfaceImplementation("olink", Collection);
	}

	return nullptr;
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> UTestbed1Settings::GetITestbed1StructArrayInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection)
{
	UTestbed1Settings* Testbed1Settings = GetMutableDefault<UTestbed1Settings>();

	FString BackendIdentifier = Testbed1Settings->TracerServiceIdentifier;

	if (Testbed1Settings->TracerServiceIdentifier == Testbed1LocalBackendIdentifier)
	{
		return FTestbed1ModuleFactory::GetTestbed1StructArrayInterfaceImplementation(Testbed1LocalBackendIdentifier, Collection);
	}

	if (Testbed1Settings->TracerServiceIdentifier != Testbed1LocalBackendIdentifier)
	{
		return FTestbed1ModuleFactory::GetTestbed1StructArrayInterfaceImplementation("olink", Collection);
	}

	return nullptr;
}
