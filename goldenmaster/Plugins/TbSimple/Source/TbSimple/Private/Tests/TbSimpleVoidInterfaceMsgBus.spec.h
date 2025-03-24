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

#include "Generated/MsgBus/TbSimpleVoidInterfaceMsgBusClient.h"
#include "TbSimpleTestsCommon.h"
#include "TbSimpleVoidInterfaceMsgBusFixture.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSimpleVoidInterfaceMsgBusSpec, "TbSimple.VoidInterface.MsgBus", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleVoidInterfaceMsgBusFixture> ImplFixture;

// signal callbacks for testing
void SigVoidSignalCb();
void _ConnectionStatusChangedCb(bool bConnected);
FDoneDelegate testDoneDelegate;

friend class UTbSimpleVoidInterfaceMsgBusHelper;
END_DEFINE_SPEC(UTbSimpleVoidInterfaceMsgBusSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
