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

#include "Generated/Detail/TbNamesThreadingHelper.h"

#include "Async/Async.h"
#include "Async/Future.h"
#include "Async/TaskGraphInterfaces.h"

void FTbNamesThreadingHelper::RunInGameThreadAndWait(const TFunction<void()>& InTask)
{
    struct VoidReturnType
    {
    };

    if (IsInGameThread())
    {
        InTask();
        return;
    }

    TPromise<VoidReturnType> Promise;
    TFuture<VoidReturnType> Future = Promise.GetFuture();

    AsyncTask(
        ENamedThreads::GameThread,
        [&]() {
            InTask();
            Promise.SetValue({});
        });

    Future.Get();
}
