
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
#include <atomic>
#include "TbNames/Generated/api/TbNames_data.h"

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TBNAMESCORE_API TbNamesNamEsPropertiesData
{
public:
	std::atomic<bool> bSwitch{false};
	std::atomic<int32> SomeProperty{0};
	std::atomic<int32> SomePoperty2{0};
	std::atomic<ETbNamesEnum_With_Under_scores> EnumProperty{ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue};

private:
};
