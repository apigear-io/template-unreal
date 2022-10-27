
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
#pragma once

#include "CoreMinimal.h"
#include "Testbed2_apig.h"
#include "Testbed2EmptyInterface.generated.h"

UCLASS(BlueprintType, Blueprintable)
class TESTBED2_API UTestbed2EmptyInterface : public UObject, public ITestbed2EmptyInterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTestbed2EmptyInterface();

	// signals
	// properties
	// operations
protected:
	// signals
private:
	// properties - local copy - use setter functions to emit changed signals
};
