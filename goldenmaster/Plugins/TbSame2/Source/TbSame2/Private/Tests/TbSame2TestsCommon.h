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

#include "Generated/api/TbSame2_data.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS
FTbSame2Struct1 TBSAME2_API createTestFTbSame2Struct1();

TArray<FTbSame2Struct1> TBSAME2_API createTestFTbSame2Struct1Array();

FTbSame2Struct2 TBSAME2_API createTestFTbSame2Struct2();

TArray<FTbSame2Struct2> TBSAME2_API createTestFTbSame2Struct2Array();

#endif // WITH_DEV_AUTOMATION_TESTS
