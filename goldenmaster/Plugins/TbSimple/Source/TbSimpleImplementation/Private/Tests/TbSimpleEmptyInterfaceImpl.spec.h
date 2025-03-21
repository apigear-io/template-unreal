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

#include "TbSimpleEmptyInterfaceImplFixture.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSimpleEmptyInterfaceImplSpec, "TbSimple.EmptyInterface.Impl", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleEmptyInterfaceImplFixture> ImplFixture;

// signal callbacks for testing
FDoneDelegate testDoneDelegate;

friend class UTbSimpleEmptyInterfaceImplHelper;
END_DEFINE_SPEC(UTbSimpleEmptyInterfaceImplSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
