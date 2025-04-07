
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
#include "Engine/DataTable.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TbNames_data.generated.h"

/**
 * Enumeration ETbNamesEnum_With_Under_scores
 */
UENUM(BlueprintType)
enum class ETbNamesEnum_With_Under_scores : uint8
{
	TNEWUS_FIRSTVALUE = 0 UMETA(Displayname = "First_Value"),
	TNEWUS_SECONDVALUE = 1 UMETA(Displayname = "second_value"),
	TNEWUS_THIRDVALUE = 2 UMETA(Displayname = "third_Value")
};

/**
 * @brief BP Function library for data types
 */
UCLASS(meta = (BlueprintThreadSafe))
class TBNAMESAPI_API UTbNamesLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/* Convert from uint8 to ETbNamesEnum_With_Under_scores @return true if successful */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames")
	static bool toTbNamesEnum_With_Under_scores(ETbNamesEnum_With_Under_scores& ConvertedEnum, UPARAM(DisplayName = "Value") uint8 InValue);
};
