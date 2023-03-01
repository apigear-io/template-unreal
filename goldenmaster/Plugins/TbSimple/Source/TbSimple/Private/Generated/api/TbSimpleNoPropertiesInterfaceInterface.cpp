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
#include "TbSimpleNoPropertiesInterfaceInterface.h"

UFUNCTION(Category = "ApiGear|TbSimple|NoPropertiesInterface")
FTbSimpleNoPropertiesInterfaceSigVoidDelegate& UAbstractTbSimpleNoPropertiesInterface::GetSigVoidSignalDelegate()
{
	return SigVoidSignal;
};

UFUNCTION(Category = "ApiGear|TbSimple|NoPropertiesInterface")
FTbSimpleNoPropertiesInterfaceSigBoolDelegate& UAbstractTbSimpleNoPropertiesInterface::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
};
void UAbstractTbSimpleNoPropertiesInterface::BroadcastSigVoid_Implementation()
{
	SigVoidSignal.Broadcast();
};

void UAbstractTbSimpleNoPropertiesInterface::BroadcastSigBool_Implementation(bool bParamBool)
{
	SigBoolSignal.Broadcast(bParamBool);
};

void UAbstractTbSimpleNoPropertiesInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSimpleNoPropertiesInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	Super::Deinitialize();
}

bool UAbstractTbSimpleNoPropertiesInterface::IsInitialized() const
{
	return bInitialized;
}
