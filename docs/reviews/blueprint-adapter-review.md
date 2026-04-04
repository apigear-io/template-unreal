# Blueprint Adapter Code Review

**Date:** 2026-01-19
**Scope:** `templates/module/Source/moduleapi/**/bpadapter.*`, `latentaction.h.tpl`, `interfacebp.h.tpl`
**Target:** UE5 Best Practices Assessment

---

## Overview

The Blueprint adapter implements the **Adapter Pattern** to bridge Blueprint implementations to C++ interfaces. It allows Blueprint-implemented objects to satisfy C++ interface contracts, enabling interoperability between the two systems.

### Architecture

```
┌─────────────────────────────────────────────────────────┐
│ Blueprint Implementation (User Code)                     │
│ - Implements ITbSimpleSimpleInterfaceBPInterface        │
└──────────────────────────────────┬──────────────────────┘
                                   │
                                   │ TScriptInterface
                                   ▼
┌──────────────────────────────────────────────────────────┐
│ UTbSimpleSimpleInterfaceBPAdapter                        │
│ - Bridges C++ Interface to Blueprint                     │
│ - Forwards all calls to Blueprint implementation         │
│ - Handles async operations with latent actions           │
└──────────────────────────────────┬──────────────────────┘
                                   │ Implements
                                   ▼
┌──────────────────────────────────────────────────────────┐
│ ITbSimpleSimpleInterfaceInterface (C++ Interface)        │
│ - Pure C++ interface expected by rest of engine          │
└──────────────────────────────────────────────────────────┘
```

---

## What's Done Well

### 1. Sound Architectural Pattern

The dual-interface approach (`ITbSimpleSimpleInterfaceInterface` for C++, `ITbSimpleSimpleInterfaceBPInterface` for Blueprint) with an adapter bridging them is a solid pattern that correctly separates concerns.

### 2. Proper Use of `TScriptInterface`

Using `TScriptInterface<IBPInterface>` for the target is the correct UE pattern for holding Blueprint-compatible interface references.

### 3. Latent Action Implementation

The `FPendingLatentAction` subclass properly:
- Uses `TAtomic<bool>` for thread-safe cancellation
- Implements `NotifyObjectDestroyed()` and `NotifyActionAborted()`
- Correctly manages future lifecycle

### 4. Validity Checks

Consistent use of `IsValid(Obj)` before calling Blueprint functions prevents crashes from null/pending-kill objects.

---

## Issues & Recommendations

### CRITICAL: Thread Safety Concerns

**Location:** `bpadapter.cpp.tpl:82-86`

**Issue:**
```cpp
return Async(EAsyncExecution::ThreadPool,
    [{{range .Params}}{{ueVar "" .}}, {{ end }}this]()
    {
    return {{Camel .Name}}({{ueVars "" .Params}});
});
```

The lambda captures `this` and calls Blueprint functions from a thread pool worker. **Blueprint functions are not thread-safe** - they must execute on the game thread.

**Recommendation:** Use `EAsyncExecution::TaskGraphMainThread` or explicitly marshal back to the game thread:

```cpp
return Async(EAsyncExecution::TaskGraphMainThread, [this, Params...]() {
    return SyncMethod(Params...);
});
```

Or use `AsyncTask`:
```cpp
TPromise<ResultType> Promise;
TFuture<ResultType> Future = Promise.GetFuture();
AsyncTask(ENamedThreads::GameThread, [this, Promise = MoveTemp(Promise), Params...]() mutable {
    Promise.SetValue(SyncMethod(Params...));
});
return Future;
```

---

### HIGH: Unsafe `this` Capture in Async Lambdas

**Location:** `bpadapter.cpp.tpl:82-86`

**Issue:** The adapter object could be garbage collected while the async task is pending, causing a dangling pointer crash.

**Current code:**
```cpp
[ParamFloat, this]()
{
    return FuncFloat(ParamFloat);
}
```

**Recommendation:** Use `TWeakObjectPtr` or ensure the object stays alive:

```cpp
TWeakObjectPtr<ThisClass> WeakThis(this);
return Async(EAsyncExecution::TaskGraphMainThread,
    [WeakThis, ParamFloat]() -> float
    {
        if (ThisClass* StrongThis = WeakThis.Get())
        {
            return StrongThis->FuncFloat(ParamFloat);
        }
        return 0.0f;  // Default on destroyed
    });
```

---

### HIGH: Missing `UFUNCTION` Metadata for Latent Functions

**Location:** `bpadapter.h.tpl:59`

**Issue:** The async overloads taking `WorldContextObject` and `LatentInfo` are not exposed to Blueprints:

```cpp
void {{Camel .Name}}Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo,
    {{ueReturn "" .Return}}& Result{{if len .Params}}, {{end}}{{ueParams "" .Params}}) override;
```

For Blueprint latent nodes, these should have:
```cpp
UFUNCTION(BlueprintCallable, Category = "...",
    meta = (Latent, LatentInfo = "LatentInfo", WorldContext = "WorldContextObject"))
```

**Current state:** These are only callable from C++ unless exposed through the interface. Verify this is intentional - if Blueprint users need async, they need proper `UFUNCTION` exposure.

---

### MEDIUM: `RemoveActionsForObject` Overly Aggressive

**Location:** `bpadapter.cpp.tpl:71-72`

**Issue:**
```cpp
oldRequest->Cancel();
LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
```

`RemoveActionsForObject` removes **all** pending actions for the callback target, not just the one being replaced. If multiple async operations are in flight, this cancels all of them.

**Recommendation:** Only cancel the specific action:
```cpp
if (oldRequest != nullptr)
{
    oldRequest->Cancel();
    // Let the LatentActionManager clean it up on next tick
    // The Cancel() sets bCancelled which causes UpdateOperation to call Response.DoneIf(true)
}
```

---

### MEDIUM: Missing `const` Correctness on Getters

**Location:** `bpadapter.cpp.tpl:105-113`

**Issue:** Property getters call Blueprint methods but are marked `const`. The Blueprint `Execute_` calls modify internal UObject state (reflection system bookkeeping).

```cpp
{{ueReturn "" .}} {{$adapter}}::Get{{Camel .Name}}() const  // <- const
{
    UObject* Obj = Target.GetObject();
    if (IsValid(Obj))
    {
        return {{$bpinterface}}::Execute_Get{{Camel .Name}}(Obj);  // Not const-safe
    }
```

This is technically UB in strict C++ terms, though UE's reflection system handles it.

**Options:**
1. Document this limitation
2. Use `mutable` if truly needed
3. Accept this is a UE-ism that works in practice

---

### MEDIUM: UE5.4+ Should Consider `UE::Tasks` Instead of `Async()`

**Location:** `bpadapter.cpp.tpl`

UE5.4 introduces a new task system that's more efficient than the legacy `Async()`:

```cpp
// UE5 modern approach
#include "Tasks/Task.h"

UE::Tasks::TTask<ResultType> Task = UE::Tasks::Launch(
    UE_SOURCE_LOCATION,
    [this, Params...]() { return SyncMethod(Params...); },
    UE::Tasks::ETaskPriority::Normal
);
return Task.GetResult();  // Or integrate with existing TFuture workflow
```

**Recommendation:** Consider version-gated code or a migration path:
```cpp
#if ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION >= 4
    // Use UE::Tasks
#else
    // Use Async()
#endif
```

---

### LOW: Unused Include

**Location:** `bpadapter.h.tpl:23`

**Issue:**
```cpp
#include "Subsystems/GameInstanceSubsystem.h"
```

The adapter inherits from `UObject`, not a subsystem. This include is unused.

---

### LOW: Missing `#if WITH_EDITOR` Guards

**Location:** `bpadapter.h.tpl:44`

The `ExposeOnSpawn` metadata may not be relevant for all build configurations:

```cpp
UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), ...)
```

This is minor but could be wrapped in `#if WITH_EDITORONLY_DATA` if the property is only set at spawn time in editor contexts.

---

### LOW: Consider `ObjectInitializer` Pattern

**Location:** `bpadapter.h.tpl`

For UE5 best practices, objects that need initialization should use the constructor with `FObjectInitializer`:

```cpp
UTbSimpleSimpleInterfaceBPAdapter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
```

This enables proper subclassing and CDO initialization.

---

## Summary Table

| Issue | Severity | Effort | Impact |
|-------|----------|--------|--------|
| Thread pool calls Blueprint from wrong thread | Critical | Medium | Crash/corruption |
| `this` capture without weak reference | High | Low | Crash on GC |
| Missing UFUNCTION for latent functions | High | Low | Missing Blueprint exposure |
| RemoveActionsForObject too aggressive | Medium | Low | Unexpected cancellations |
| const-correctness on getters | Medium | Low | Technical debt |
| Legacy Async() vs UE::Tasks | Medium | Medium | Performance/modernization |
| Unused include | Low | Trivial | Code cleanliness |
| Missing ObjectInitializer | Low | Low | Subclassing support |

---

## Recommended Action Plan

### Immediate (Before Next Release)

1. **Fix thread safety** - Execute Blueprint calls on game thread, not thread pool
2. **Add weak object pointer protection** for async lambdas to prevent GC crashes

### Short-term

3. Review UFUNCTION exposure requirements for latent async methods
4. Fix `RemoveActionsForObject` to only cancel the specific action

### Medium-term

5. Consider `UE::Tasks` migration for UE5.4+ builds
6. Clean up unused includes and add proper editor guards

---

## References

- [UE5 Async Programming](https://dev.epicgames.com/documentation/en-us/unreal-engine/asynchronous-programming-in-unreal-engine)
- [Blueprint Native Events](https://dev.epicgames.com/documentation/en-us/unreal-engine/ufunctions-in-unreal-engine)
- [Latent Actions](https://dev.epicgames.com/documentation/en-us/unreal-engine/latent-actions-in-unreal-engine)
- [UE::Tasks System (5.4+)](https://dev.epicgames.com/documentation/en-us/unreal-engine/tasks-system-in-unreal-engine)
