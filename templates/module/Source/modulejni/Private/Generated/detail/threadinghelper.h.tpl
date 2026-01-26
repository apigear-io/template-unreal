{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
#pragma once

#include "Misc/Optional.h"
#include "Templates/Function.h"

class F{{Camel .Module.Name}}ThreadingHelper
{
public:
    static void RunInGameThreadAndWait(const TFunction<void()>& InTask);

    template <typename Fn>
    static auto EvalInGameThread(Fn&& InFn) -> decltype(InFn());

private:
    F{{Camel .Module.Name}}ThreadingHelper() = delete;
};

template <typename Fn>
auto F{{Camel .Module.Name}}ThreadingHelper::EvalInGameThread(Fn&& InFn) -> decltype(InFn())
{
    using ResultType = decltype(InFn());
    static_assert(!std::is_void_v<ResultType>, "Use RunInGameThreadAndWait for void tasks");

    TOptional<ResultType> Result;

    RunInGameThreadAndWait([&](){
        Result.Emplace(InFn());
    });

    return MoveTemp(*Result);
}
