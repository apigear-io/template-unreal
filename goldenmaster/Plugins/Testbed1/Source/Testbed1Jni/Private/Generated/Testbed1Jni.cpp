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

#include "Testbed1/Testbed1Jni.h"
#include "Testbed1/Generated/Testbed1Factory.h"
#include "Testbed1/Generated/Jni/Testbed1DataJavaConverter.h"
#include "Engine/Engine.h"
#include "Testbed1Settings.h"
#include "Modules/ModuleManager.h"

#include "Generated/Detail/Testbed1MethodHelper.h"

#define LOCTEXT_NAMESPACE "Testbed1Jni"

DEFINE_LOG_CATEGORY(LogTestbed1MethodHelper_JNI);

void FTestbed1JniModule::StartupModule()
{
}

void FTestbed1JniModule::ShutdownModule()
{
// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
// we call this function before unloading the module.
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	Testbed1DataJavaConverter::cleanJavaReferences();
#endif
}

IMPLEMENT_MODULE(FTestbed1JniModule, Testbed1Jni)

#undef LOCTEXT_NAMESPACE
