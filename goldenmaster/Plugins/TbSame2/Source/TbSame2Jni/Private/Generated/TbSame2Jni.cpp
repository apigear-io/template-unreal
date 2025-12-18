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

#include "TbSame2/TbSame2Jni.h"
#include "TbSame2/Generated/TbSame2Factory.h"
#include "TbSame2/Generated/Jni/TbSame2DataJavaConverter.h"
#include "Engine/Engine.h"
#include "TbSame2Settings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "TbSame2Jni"

void FTbSame2JniModule::StartupModule()
{
}

void FTbSame2JniModule::ShutdownModule()
{
// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
// we call this function before unloading the module.
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	TbSame2DataJavaConverter::cleanJavaReferences();
#endif
}

IMPLEMENT_MODULE(FTbSame2JniModule, TbSame2Jni)

#undef LOCTEXT_NAMESPACE
