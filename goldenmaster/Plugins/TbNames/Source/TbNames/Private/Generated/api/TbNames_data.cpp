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

#include "Generated/api/TbNames_data.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"

/**
 * Enumeration ETbNamesEnum_With_Under_scores
 */
bool UTbNamesLibrary::toTbNamesEnum_With_Under_scores(ETbNamesEnum_With_Under_scores& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
	case 0:
		ConvertedEnum = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE;
		bSuccessful = true;
		break;
	case 1:
		ConvertedEnum = ETbNamesEnum_With_Under_scores::TNEWUS_SECONDVALUE;
		bSuccessful = true;
		break;
	case 2:
		ConvertedEnum = ETbNamesEnum_With_Under_scores::TNEWUS_THIRDVALUE;
		bSuccessful = true;
		break;
	default:
		ConvertedEnum = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE;
	}
	return bSuccessful;
}
