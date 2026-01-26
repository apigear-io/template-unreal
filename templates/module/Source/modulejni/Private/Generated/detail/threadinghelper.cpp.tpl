{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/

#include "Generated/Detail/{{Camel .Module.Name}}ThreadingHelper.h"

#include "Async/Async.h"
#include "Async/Future.h"
#include "Async/TaskGraphInterfaces.h"

void F{{Camel .Module.Name}}ThreadingHelper::RunInGameThreadAndWait(const TFunction<void()>& InTask)
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
