# Safety Analysis: UE Template Full Review

**Date:** 2026-04-01
**Scope:** All Go templates (`.tpl`), ApiGear runtime (`templates/ApiGear/`, `goldenmaster/Plugins/ApiGear/`), generated golden master output
**Methodology:** Manual code review of templates and generated output, architecture review, API compatibility audit
**Reviewers:** Automated analysis with architecture advisor validation
**Findings:** 25 total (1 CRITICAL, 9 HIGH, 10 MEDIUM, 5 LOW)

---

## Table of Contents

1. [Executive Summary](#executive-summary)
2. [Layer 0: ApiGear Runtime Infrastructure](#layer-0-apigear-runtime-infrastructure)
3. [Layer 1: API](#layer-1-api)
4. [Layer 2: Stubs](#layer-2-stubs)
5. [Layer 3: Monitor](#layer-3-monitor)
6. [Layer 4: OLink IPC](#layer-4-olink-ipc)
7. [Layer 5: MsgBus IPC](#layer-5-msgbus-ipc)
8. [Cross-Cutting Concerns](#cross-cutting-concerns)
9. [Consolidated Findings](#consolidated-findings)
10. [Mitigation Roadmap](#mitigation-roadmap)
11. [API Compatibility](#api-compatibility)
12. [Appendix: Severity Definitions](#appendix-severity-definitions)

---

## Executive Summary

This review identified **25 findings** across the template-unreal code generation system: **1 CRITICAL**, **8 HIGH**, **8 MEDIUM**, and **8 LOW**. All proposed mitigations were audited for API compatibility -- **no public API breaks** were found.

**Key themes:**

1. **Threading model gaps.** The codebase lacks a unified threading contract. The publisher correctly defers Blueprint callbacks to the game thread, but C++ subscriber callbacks fire on whatever thread the caller uses -- WebSocket thread (OLink), transport thread (MsgBus), or caller's thread (Monitor). This inconsistency makes it impossible for subscribers to make safe threading assumptions. (SA-09, SA-10, SA-12, SA-13, SA-24)

2. **Singleton and static races in the Tracer.** The sole CRITICAL finding (SA-02) is a check-then-create race in `Tracer::instance()` compounded by an off-game-thread `GetMutableDefault` call. The `isbusy` flag (SA-01) has a data race between the HTTP callback thread and the caller's thread. Both are in non-templated runtime code that ships as-is.

3. **Promise lifecycle bugs in MsgBus.** Stack-local `TPromise<T>` stored as `void*` (SA-05) is use-after-scope undefined behavior. No timeout or cleanup on disconnect (SA-06) means service crashes permanently hang calling threads. The OLink client implements the correct pattern (`TSharedRef<TPromise<T>>`); MsgBus should follow it.

4. **Null-pointer hazards behind `checkf`.** Multiple layers rely on `checkf` as their only null-pointer protection (SA-14). In Shipping builds, `checkf` compiles out, leaving guaranteed null dereferences in the `BackendService` forwarding paths of the LoggingDecorator (SA-18), MsgBus adapter (SA-08), and OLink adapter.

5. **OLink sink callback safety.** Raw `this` captures in sink callbacks (SA-23) combined with no mutex in `FOLinkSink` (SA-03) create a use-after-destruction race between the WebSocket thread and UObject teardown.

**Positive patterns:** The publisher's `FRWLock` + copy-under-read-lock + `TWeakInterfacePtr` + game-thread dispatch pattern is well-designed and should serve as the model for callback safety across all layers. The stubs layer is structurally simple and free of safety issues. Property deduplication in both IPC clients reduces unnecessary network traffic.

**Cross-reference:** The [Blueprint Adapter Review](blueprint-adapter-review.md) identified a CRITICAL threading issue in the same `Async(EAsyncExecution::ThreadPool)` dispatch mechanism. SA-09 in this review documents the same root cause at the abstract class level, where `TWeakObjectPtr` mitigates the GC crash but not the threading contract violation.

---

## Layer 0: ApiGear Runtime Infrastructure

The ApiGear runtime plugin (`templates/ApiGear/`) provides cross-cutting services consumed by every generated module: tracing/telemetry via the `Tracer` singleton and OLink networking via `FOLinkSink`. Because this layer sits beneath all generated code, defects here propagate to every module in every generated plugin.

### Architecture

```
┌────────────────────────────────────────────────────────────────────┐
│                     Generated Plugin Modules                       │
│  {Module}Monitor   {Module}OLink   {Module}MsgBus   {Module}Core  │
└──────┬───────────────┬──────────────────┬──────────────────────────┘
       │               │                  │
       │  trace()      │  FOLinkSink      │
       ▼               ▼                  │
┌──────────────┐ ┌───────────────────┐    │
│   Tracer     │ │   OLinkSink       │    │
│  (singleton) │ │ (per-interface)   │    │
│              │ │                   │    │
│ ┌──────────┐ │ │ TFunction<> cbs  │    │
│ │ m_queue  │ │ │  - PropertyChanged│    │
│ │ (locked) │ │ │  - SignalEmitted  │    │
│ └──────────┘ │ │  - OnInit         │    │
│ isbusy (raw!)│ │  - OnRelease      │    │
│ s_instance   │ │  (no lock)        │    │
│  (raw ptr)   │ │                   │    │
└──────┬───────┘ └────────┬──────────┘    │
       │                  │               │
       ▼                  ▼               │
   FHttpModule      WebSocket Thread      │
   (HTTP POST)     (olink protocol)       │
```

### What Works Well

The `FCriticalSection m_queueMutex` in `Tracer` correctly protects the event queue across all access paths. Enqueue at `tracer.cpp:81-84` and drain at `tracer.cpp:122-163` both acquire the lock before touching `m_queue`. This is the one well-designed threading pattern in this file.

---

### SA-02 (CRITICAL) -- Singleton Race Condition in `Tracer::instance()`

**Location:** `templates/ApiGear/Source/ApiGear/Private/tracer.cpp:37-44`, `tracer.cpp:16`, `tracer.h:38`

**Issue:** The singleton factory uses a check-then-create pattern on a raw static pointer with no synchronization:

```cpp
// tracer.cpp:16
Tracer* Tracer::s_instance(nullptr);

// tracer.cpp:37-44
Tracer* Tracer::instance()
{
    if (!s_instance)          // <-- read with no barrier
    {
        s_instance = new Tracer();  // <-- write with no barrier
    }
    return s_instance;
}
```

If two threads call `instance()` concurrently before initialization completes, both observe `s_instance == nullptr` and both construct a `Tracer`. One instance leaks silently, and the two callers operate on different objects with separate queues and HTTP state.

**Compounding factor:** The `Tracer` constructor calls `GetMutableDefault<UApiGearSettings>()` at `tracer.cpp:29`. This function accesses the UObject CDO system, which is only safe on the game thread. If `instance()` is first called from a worker thread (plausible when a Monitor adapter fires during async initialization), the `GetMutableDefault` call races with engine CDO creation, risking corruption of the UObject allocator.

**Recommendation:** Use `std::call_once` with an intentional heap leak. A C++11 magic static (`static Tracer instance;`) is deliberately avoided here because its destructor would run during static teardown, after `FHttpModule` has already been destroyed, causing a crash.

```cpp
#include <mutex>

Tracer* Tracer::instance()
{
    static std::once_flag s_flag;
    std::call_once(s_flag, []() {
        check(IsInGameThread());  // Fail fast if first call is off game thread
        s_instance = new Tracer();  // Intentional leak -- destructor would crash
    });
    return s_instance;
}
```

---

### SA-01 (HIGH) -- Data Race on `isbusy` Flag

**Location:** `templates/ApiGear/Source/ApiGear/Private/tracer.cpp:18`, `tracer.cpp:107`, `tracer.cpp:137`, `tracer.cpp:149`

**Issue:** A file-scope `static bool isbusy` is read and written from multiple threads without synchronization:

```cpp
// tracer.cpp:18
static bool isbusy = false;

// tracer.cpp:107 -- read on calling thread (game thread or any thread calling trace())
if (isbusy)
{
    log("still busy ... skipping");
    return;
}

// tracer.cpp:137 -- write under m_queueMutex (incidental, not intentional protection)
isbusy = true;

// tracer.cpp:149 -- write in HTTP completion lambda (HTTP thread, no lock)
isbusy = false;
```

The read at line 107 has no lock. The write at line 149 executes on the HTTP module's completion thread with no lock. This is undefined behavior per the C++ standard (concurrent non-atomic read/write to the same variable). In practice, the likely failure mode is a skipped or redundant `process()` call rather than memory corruption, but the standard makes no such guarantee, and compiler optimizations (register caching, reordering) can produce surprising results on ARM targets (Android, Apple Silicon).

**Recommendation:** Replace with `std::atomic<bool>`:

```cpp
static std::atomic<bool> isbusy{false};
```

All existing reads and writes become well-defined. No other code changes required since the usage pattern (flag check, not read-modify-write) does not need `compare_exchange`.

---

### SA-03 (HIGH) -- OLinkSink Callback Thread Safety

**Location:** `goldenmaster/Plugins/ApiGear/Source/ApiGearOLink/Public/OLinkSink.h:52-60`, `goldenmaster/Plugins/ApiGear/Source/ApiGearOLink/Private/OLinkSink.cpp:19-52,57-95`

**Issue:** Four `TFunction<>` callback members are set/reset from the game thread and invoked from the WebSocket receive thread with no synchronization:

```cpp
// OLinkSink.h:52-60 -- raw TFunction members, no lock
FPropertyChangedFunc PropertyChangedFunc;
FSignalEmittedFunc SignalEmittedFunc;
FInitializedFromSourceCallback OnInitCallback;
FSourceConnectionReleasedCallback OnReleaseCallback;
```

The set/reset path (game thread):
```cpp
// OLinkSink.cpp:57-95
void FOLinkSink::setOnPropertyChangedCallback(FPropertyChangedFunc func) { PropertyChangedFunc = func; }
void FOLinkSink::resetOnInitCallback() { OnInitCallback = nullptr; }
// ... etc.
```

The invocation path (WebSocket thread, via `olinkOnSignal`, `olinkOnPropertyChanged`, `olinkOnInit`, `olinkOnRelease`):
```cpp
// OLinkSink.cpp:19-21
if (SignalEmittedFunc)        // <-- read TFunction state
{
    SignalEmittedFunc(...);   // <-- invoke TFunction
}
```

If a callback is reset to `nullptr` on the game thread between the null check and the invocation on the WebSocket thread, the `TFunction` internal state is torn, causing a crash. This race window is narrow but grows under load (high-frequency property updates during OLink client disconnect/reconnect).

**Recommendation:** Protect all callback set/reset/invoke paths with an `FCriticalSection`:

```cpp
// In OLinkSink.h, add:
mutable FCriticalSection CallbackMutex;

// In OLinkSink.cpp, wrap all callback access:
void FOLinkSink::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    FScopeLock Lock(&CallbackMutex);
    if (SignalEmittedFunc)
    {
        SignalEmittedFunc(MemberName, args);
    }
}

void FOLinkSink::resetOnSignalEmittedCallback()
{
    FScopeLock Lock(&CallbackMutex);
    SignalEmittedFunc = nullptr;
}
```

Apply the same pattern to all four callbacks. The lock contention is negligible since these paths are not high-frequency hot loops.

---

### SA-17 (MEDIUM) -- Null HttpResponse Dereference in Completion Callback

**Location:** `templates/ApiGear/Source/ApiGear/Private/tracer.cpp:142-151`

**Issue:** The HTTP completion callback dereferences `HttpResponse` without checking `bSucceeded`:

```cpp
m_httprequest->OnProcessRequestComplete().BindStatic(
    [](FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
    {
        FString Messagebody;
        Messagebody = HttpResponse->GetContentAsString();  // <-- null deref if !bSucceeded
        isbusy = false;
    });
```

When `bSucceeded` is `false` (network timeout, DNS failure, connection refused), `HttpResponse` is a null `TSharedPtr`. Calling `GetContentAsString()` on a null pointer crashes the process. This is reachable under normal operating conditions: the tracer sends HTTP POSTs to a configurable URL that may be unreachable.

**Recommendation:** Guard the response access:

```cpp
[](FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
    if (bSucceeded && HttpResponse.IsValid())
    {
        FString Messagebody = HttpResponse->GetContentAsString();
    }
    isbusy = false;
}
```

---

### SA-22 (LOW) -- Singleton Never Freed / Dangling FHttpModule Pointer

**Location:** `templates/ApiGear/Source/ApiGear/Private/tracer.cpp:16,37-44`, `templates/ApiGear/Source/ApiGear/Public/tracer.h:44`

**Issue:** `s_instance` is allocated with `new` and never `delete`d. The `m_http` member is a raw `FHttpModule*` that points into the module system:

```cpp
// tracer.h:44
FHttpModule* m_http;

// tracer.cpp:65
m_http = &FHttpModule::Get();
```

In a standalone game, the leak is harmless (process exit reclaims all memory). In the Unreal Editor with hot-reload or Play-In-Editor cycling, `FHttpModule` may be unloaded and reloaded, leaving `m_http` dangling. Subsequent `process()` calls through the stale pointer corrupt memory silently.

**Recommendation:** If the SA-02 fix adopts `std::call_once`, the intentional leak is already documented. For the dangling `m_http`, either:
1. Re-acquire `FHttpModule::Get()` each time in `process()` (safest, trivial perf cost), or
2. Set `m_http = nullptr` on module shutdown via an `FModuleManager` delegate and re-acquire on next use.

---

### Summary Table

| ID | Severity | Location | Issue | Fix Effort |
|----|----------|----------|-------|------------|
| SA-02 | CRITICAL | `tracer.cpp:37-44` | Singleton check-then-create race + unsafe `GetMutableDefault` off game thread | Low |
| SA-01 | HIGH | `tracer.cpp:18,107,137,149` | Non-atomic `isbusy` read/write across threads (undefined behavior) | Trivial |
| SA-03 | HIGH | `OLinkSink.h:52-60`, `OLinkSink.cpp` | `TFunction<>` callbacks set/reset/invoked across threads without lock | Low |
| SA-17 | MEDIUM | `tracer.cpp:143-146` | `HttpResponse->GetContentAsString()` without null/success check | Trivial |
| SA-22 | LOW | `tracer.cpp:16`, `tracer.h:44` | Singleton leak + dangling `FHttpModule*` on hot-reload | Low |

---

## Layer 1: API

The API layer generates the foundational types for every module: C++ interfaces, Blueprint subscriber interfaces, publisher classes, abstract base classes, data types (structs/enums), JSON serialization adapters, and latent action helpers. This is the most architecturally significant layer, establishing the dual-interface pattern and the publisher/subscriber threading model that all other layers build upon.

### Architecture: Dual Interface Pattern

```
┌──────────────────────────────────────────────────────────────────┐
│  I{Module}{Interface}Interface (C++ pure virtual)                │
│    - Get/Set properties                                          │
│    - Operations (sync + async)                                   │
│    - _GetPublisher()                                             │
└──────────────────────────────┬───────────────────────────────────┘
                               │ implements
                               ▼
┌──────────────────────────────────────────────────────────────────┐
│  UAbstract{Module}{Interface} (GameInstanceSubsystem)            │
│    - UPROPERTY storage                                           │
│    - AddReferencedObjects (pins Publisher)                        │
│    - Async dispatch via ThreadPool                               │
│    - Latent action support                                       │
└──────────────────────────────┬───────────────────────────────────┘
                               │ owns
                               ▼
┌──────────────────────────────────────────────────────────────────┐
│  U{Module}{Interface}Publisher                                   │
│    - FRWLock-protected subscriber lists (C++ + BP)               │
│    - Copy-under-read-lock before iteration                       │
│    - TWeakInterfacePtr for C++ subscribers                       │
│    - TScriptInterface for BP subscribers                         │
│    - Game-thread dispatch for BP via AsyncTask                   │
│    - Multicast delegates (C++ FMulticastDelegate + BP Dynamic)   │
└──────────────────────────────────────────────────────────────────┘
```

### What Works Well

**The publisher threading model is the gold standard in this codebase.** At `publisher.cpp.tpl:19-75`, every broadcast follows this pattern:

1. **Copy subscriber lists under read lock** -- `FReadScopeLock ReadLock(SubscribersLock)` creates a snapshot, then the lock is released before any callbacks fire. This prevents deadlocks from subscribers that modify the subscriber list during iteration.

2. **Validate weak pointers before each callback** -- `TWeakInterfacePtr::IsValid()` followed by `Get()` double-check prevents calling into destroyed subscribers.

3. **Game-thread dispatch for Blueprint** -- `IsInGameThread()` check at line 67: if already on game thread, BP callbacks fire inline; otherwise, `AsyncTask(ENamedThreads::GameThread, ...)` defers them. The lambda captures `TWeakObjectPtr<Publisher>` to prevent GC dangling.

4. **Periodic cleanup** -- `CleanUpSubscribers()` runs after each BP broadcast dispatch, removing stale weak pointers from the subscriber lists.

**`TWeakObjectPtr` capture in async lambdas** at `abstract.cpp.tpl:100-109`. The async operation dispatch correctly captures a weak pointer rather than raw `this`, preventing GC-related dangling pointer crashes.

---

### SA-09 (MEDIUM) -- ThreadPool Dispatch with Undocumented Threading Contract

**Location:** `templates/module/Source/moduleapi/Private/Generated/api/abstract.cpp.tpl:98-110`

**Issue:** Async operations are dispatched to `EAsyncExecution::ThreadPool`. The `Operation()` call executes on a thread pool worker. While `WeakThis` protects against GC dangling (an improvement over the BP adapter's raw `this` capture -- see [Blueprint Adapter Review](blueprint-adapter-review.md)), the underlying issue remains: **the operation body runs off the game thread**. Concrete subclasses may access game-thread-only UE APIs, read/write shared property state without synchronization, or touch UObjects that could be GC'd between the weak pointer check and the actual call.

This is the same root mechanism that the Blueprint Adapter Review identified as CRITICAL.

**Recommendation:** Switch to `EAsyncExecution::TaskGraphMainThread` (game-thread execution, no threading concern), or document the threading contract explicitly.

---

### SA-19 (LOW) -- Publisher Stored as Raw UObject Pointer

**Location:** `templates/module/Source/moduleapi/Public/module/Generated/api/abstract.h.tpl`

**Issue:** The publisher is stored as a raw `UObject*` member, relying solely on `AddReferencedObjects` for GC retention. If a user creates a C++ subclass and forgets to call `Super::AddReferencedObjects`, the publisher becomes eligible for GC.

**Recommendation:** Consider making the publisher a `UPROPERTY(Transient)` member instead.

---

### SA-20 (LOW) -- Enum Deserialization Without Range Validation

**Location:** `templates/module/Source/moduleapi/Public/module/Generated/api/data.h.tpl`

**Issue:** Enum conversion uses `is_number_integer()` type check but no range validation. A value of 255 is silently cast to the enum, producing undefined behavior in `switch` statements.

**Recommendation:** Add range check against enum max value before the cast.

---

### Layer 1 Summary

| Finding | Severity | Location | Issue | Fix Effort |
|---------|----------|----------|-------|------------|
| SA-09 | MEDIUM | `abstract.cpp.tpl:98-110` | ThreadPool dispatch -- operation runs off game thread | Low |
| SA-19 | LOW | `abstract.h.tpl` | Publisher as raw `UObject*`, relies on `AddReferencedObjects` chain | Low |
| SA-20 | LOW | `data.h.tpl` | Enum deserialization: no range validation | Trivial |

---

## Layer 2: Stubs

The `{Module}Implementation` module provides user-editable stub classes that inherit from the abstract base in `{Module}API`. These are the simplest generated files: thin property storage, delegating broadcasts, and empty operation bodies. All stub files carry `preserve: true` in `rules.yaml` (lines 294-309), meaning the code generator never overwrites them after initial creation.

### Architecture

```
┌──────────────────────────────────────────────────────┐
│              UAbstract{Module}{Interface}             │
│     (generated, overwritten on each regeneration)    │
└──────────────────────┬───────────────────────────────┘
                       │ inherits
                       ▼
┌──────────────────────────────────────────────────────┐
│       U{Module}{Interface}Implementation             │
│          (preserve: true -- user-editable)           │
│                                                      │
│  Get{Prop}()       → return member                   │
│  Set{Prop}(In)     → dirty check → broadcast         │
│  {Operation}(...)  → (void)Param; return default;    │
│  _ResetProperties()→ per-prop dirty check → broadcast│
└──────────────────────────────────────────────────────┘
```

### What Works Well

**Dirty-check pattern on property setters** (`implementation.cpp.tpl:22-28`). The `if (Property != InProperty)` guard prevents redundant broadcast storms. The same pattern is applied in `_ResetProperties()`.

**CPU profiler scoping** on all entry points via `TRACE_CPUPROFILER_EVENT_SCOPE_STR(...)`. Compiles to no-ops in shipping builds.

**Unused parameter suppression** via `(void)ParamName;`. Serves as a visible marker for unimplemented logic.

**Safe default return values.** Operations return zero-initialized defaults, ensuring unimplemented stubs never return uninitialized memory.

### Safety Boundary: `preserve: true`

- **Generated defaults are safe.** No undefined behavior in initial template output.
- **User modifications are unchecked.** Thread safety and memory management become the user's responsibility.
- **Regeneration does not heal preserved files.** Template improvements require manual adoption.

### Findings

No findings at MEDIUM or above. The generated stub code is structurally simple, single-threaded, and free of undefined behavior.

---

## Layer 3: Monitor

The Monitor layer generates a `ULoggingDecorator` subclass per interface, wrapping any `BackendService` implementation with tracing and rebroadcasting. Every property getter, setter, operation, signal, and property-changed notification passes through the decorator, which emits trace events to the `Tracer` singleton (Layer 0) before forwarding to the real implementation.

### Architecture

```
┌─────────────────────────────────────────────────────────┐
│  ULoggingDecorator  (GameInstanceSubsystem)             │
│  extends: UAbstract{Module}{Interface}                  │
│  implements: I{Iface}SubscriberInterface                │
│                                                         │
│  BackendService ─────────────────► Actual Implementation│
│  (TScriptInterface)                                     │
│                                                         │
│  Initialize()   → resolve backend via Settings          │
│  Deinitialize() → BackendService = nullptr              │
│                                                         │
│  Get*()  → BackendService->Get*()                       │
│  Set*()  → trace_callSet*() + BackendService->Set*()    │
│  Op()    → trace_callOp()  + BackendService->Op()       │
│                                                         │
│  OnSignal()      → trace_signal*() + rebroadcast        │
│  OnPropChanged() → capture_state() + update + rebroadcast│
└─────────────────────────────────────────────────────────┘
         │ trace calls
         ▼
   {Iface}Tracer → Tracer::instance() (Layer 0)
```

### What Works Well

The decorator pattern is transparent to callers: it implements the same interface as the wrapped service. The `TScriptInterface<>` member handles UObject lifecycle integration correctly. The publisher subscribe/unsubscribe logic in `setBackendService` properly tears down the old subscription before establishing a new one.

---

### SA-18 (HIGH) -- Post-deinit BackendService Null Dereference

**Location:** `templates/module/Source/modulemonitor/Private/Generated/Monitor/loggingdecorator.cpp.tpl:54-58`, all forwarding methods

**Issue:** `Deinitialize()` unconditionally sets `BackendService = nullptr`. Every forwarding method dereferences `BackendService->` without a null guard:
- Property getters: `return BackendService->GetPropBool();`
- Property setters: `BackendService->SetPropBool(bInPropBool);`
- Operations: `return BackendService->FuncBool(bParamBool);`
- Property-changed callbacks: `capture_state(BackendService.GetObject(), this);`

Additionally, `Deinitialize()` does not unsubscribe from the backend publisher before nulling the pointer.

**Recommendation:** Add null guard at top of every forwarding method. Unsubscribe from publisher before nulling in `Deinitialize()`.

---

### SA-04 (MEDIUM) -- Subscribe-Before-Read Ordering Race

**Location:** `templates/module/Source/modulemonitor/Private/Generated/Monitor/loggingdecorator.cpp.tpl:60-84`

**Issue:** `setBackendService` performs three steps: (1) assign BackendService (line 75), (2) subscribe to publisher (line 79), (3) read properties (lines 81-83). Between subscribe and property read, a callback may fire. The callback's `capture_state()` reads local properties which haven't been synced yet -- producing stale trace data.

**Recommendation:** Reorder to: assign, read properties, subscribe last. In the template, move the `range .Interface.Properties` loop above the `Subscribe` call.

---

### SA-15 (MEDIUM) -- Non-Atomic Multi-Property State Capture

**Location:** `templates/module/Source/modulemonitor/Private/Generated/Monitor/trace.cpp.tpl:21-28`

**Issue:** `capture_state` reads all interface properties sequentially with no snapshot mechanism. Each `Get*()` reads independently. Under concurrent modification, the captured JSON contains a mix of old and new values -- a torn state snapshot. The unused `UObject* Object` parameter is dead code.

**Recommendation:** For monitoring, torn reads are acceptable. Document the limitation explicitly in the template.

---

### Layer 3 Summary

| Finding | Severity | Location | Issue | Fix Effort |
|---------|----------|----------|-------|------------|
| SA-18 | HIGH | `loggingdecorator.cpp.tpl:54-58` | Post-deinit `BackendService` null deref; no unsubscribe in deinit | Low |
| SA-04 | MEDIUM | `loggingdecorator.cpp.tpl:75-83` | Subscribe before property read; callback sees stale local state | Trivial |
| SA-15 | MEDIUM | `trace.cpp.tpl:21-28` | Sequential multi-property reads; torn state snapshot | Trivial |

---

## Layer 4: OLink IPC

The OLink layer implements a JSON-over-WebSocket protocol for remote client-server communication. Each interface generates a client (`OLinkClient`), a server adapter (`OLinkAdapter`), and an internal protocol source (`OLinkSource`). OLink is **disabled on mobile platforms** (iOS, Android, QNX) with empty stub implementations.

### Architecture

```
┌─────────────────────────────────────────────────────────┐
│  OLinkClient (GameInstanceSubsystem)                     │
│  extends: UAbstract{Module}{Interface}                   │
│                                                          │
│  m_sink (shared_ptr<FOLinkSink>)                         │
│    - Held by OLink registry (outlives the UObject!)      │
│    - PropertyChangedFunc: [this](...) { applyState() }   │
│    - SignalEmittedFunc:   [this](...) { emitSignal() }   │
│                                                          │
│  _SentData (TPimplPtr) -- property deduplication cache   │
└─────────────┬───────────────────────────────────────────┘
              │ OLink protocol
              ▼
┌────────────────────────────────┐    ┌──────────────────────────┐
│  UOLinkClientConnection        │    │  OLinkSource             │
│  - WebSocket transport         │    │  - IObjectSource impl    │
│  - TQueue (MPSC, lock-free)    │    │  - olinkInvoke()         │
│  - Auto-reconnect              │    │  - olinkSetProperty()    │
└────────────────────────────────┘    └──────────────────────────┘
```

**Connection lifecycle:**
```
Constructed → Initialize (sink callbacks set) → UseConnection (linked to registry)
    → olinkOnInit (properties synced, ready) → olinkOnRelease (node released)
    → Deinitialize (callbacks reset, unlinked)
```

### What Works Well

**Property deduplication via `_SentData`** prevents redundant network traffic. **Robust JSON validation on the client side** -- signal handlers check array type, size, null, and element type. **`_SubscriptionStatusChanged` delegate** provides clean connection state tracking.

---

### SA-07 (HIGH) -- Missing Parameter Count Validation in Server Invoke

**Location:** `templates/module/Source/moduleolink/Private/Generated/OLink/olinksource.cpp.tpl:111-137`

**Issue:** `olinkInvoke` extracts parameters without validating array size:

```cpp
Type1 param1 = args.at(0).get<Type1>();  // No size check!
Type2 param2 = args.at(1).get<Type2>();  // No size check!
```

With `JSON_NOEXCEPTION=1`, `at()` on out-of-bounds returns discarded json. `get<T>()` on discarded json silently returns default value. A malformed remote call executes with zero/empty parameters.

**Recommendation:** Add `if (!args.is_array() || args.size() < N)` check with error log and early return.

---

### SA-23 (HIGH) -- Raw `this` Capture in OLink Sink Callbacks

**Location:** `templates/module/Source/moduleolink/Private/Generated/OLink/olinkclient.cpp.tpl:62-83`

**Issue:** Four sink callbacks capture raw `this`. The sink (`shared_ptr`) is held by the OLink registry and outlives the UObject. During `Deinitialize`, a WebSocket message arriving before callbacks are reset invokes a callback on a mid-destruction UObject. Compounds SA-03.

**Recommendation:** Capture `TWeakObjectPtr` instead of raw `this`. Combined with SA-03's `FCriticalSection`, this provides two layers of protection.

---

### SA-24 (MEDIUM) -- Property Writes from WebSocket Thread

**Location:** `templates/module/Source/moduleolink/Private/Generated/OLink/olinkclient.cpp.tpl:284-349`

**Issue:** `applyState`/`emitSignal` directly write member variables and call `_GetPublisher()->Broadcast...()` from the WebSocket thread. C++ subscriber callbacks fire on the WebSocket thread. Property writes race with game-thread reads.

**Recommendation:** Marshal state mutations to the game thread via `AsyncTask(ENamedThreads::GameThread, ...)`.

---

### SA-10 (MEDIUM) -- C++ Callbacks Fire on WebSocket Thread

**Location:** `goldenmaster/Plugins/ApiGear/Source/ApiGearOLink/Private/OLinkClientConnection.cpp`

**Issue:** `handleTextMessage` processes OLink messages synchronously on the WebSocket thread. All sink callbacks execute on this thread. C++ subscribers that touch game-thread-only state crash or corrupt state.

**Recommendation:** Document the threading contract or marshal sink callback processing to the game thread.

---

### SA-16 (MEDIUM) -- Partial Initialization on Null Connection

**Location:** `templates/module/Source/moduleolink/Private/Generated/OLink/olinkclient.cpp.tpl:58-98`

**Issue:** `Initialize` sets sink callbacks (lines 62-83) before checking the connection (lines 88-94). If connection store returns null, callbacks are installed with raw `this` into a partially initialized client.

**Recommendation:** Set callbacks AFTER connection validation, or reset them on early return.

---

### SA-21 (LOW) -- Cross-Thread `_SentData` Access

**Location:** `templates/module/Source/moduleolink/Private/Generated/OLink/olinkclient.cpp.tpl`

**Issue:** `_SentData` written on game thread (`SetProperty`), reset on WebSocket thread (`applyState`). Worst case: redundant network sends.

**Recommendation:** Acceptable risk. Game-thread marshaling (SA-24 fix) eliminates this as a side effect.

---

### Layer 4 Summary

| Finding | Severity | Location | Issue | Fix Effort |
|---------|----------|----------|-------|------------|
| SA-07 | HIGH | `olinksource.cpp.tpl:111-137` | No `args.size()` check -- silent default params on malformed call | Trivial |
| SA-23 | HIGH | `olinkclient.cpp.tpl:62-83` | Raw `this` in sink callbacks -- use-after-destruction (compounds SA-03) | Low |
| SA-24 | MEDIUM | `olinkclient.cpp.tpl:284-349` | Property writes + broadcasts from WebSocket thread | Medium |
| SA-10 | MEDIUM | `OLinkClientConnection.cpp` | C++ callbacks fire on WebSocket thread | Medium |
| SA-16 | MEDIUM | `olinkclient.cpp.tpl:58-98` | Callbacks installed before connection check | Trivial |
| SA-21 | LOW | `olinkclient.cpp.tpl` | `_SentData` cross-thread write -- redundant sends only | None |

---

## Layer 5: MsgBus IPC

The MsgBus layer uses Unreal Engine's native message bus for inter-process communication between client and service instances running in the same process or on the same machine. Unlike OLink, it requires no external protocol library and works on all platforms.

### Architecture

```
┌───────────────────────────────────┐     ┌───────────────────────────────────┐
│  MsgBusClient (GameInstanceSS)    │     │  MsgBusAdapter (GameInstanceSS)   │
│                                   │     │                                   │
│  FMessageEndpoint ───────────────────── FMessageEndpoint                   │
│    - Handles: Init, Pong,         │     │    - Handles: Discovery, Ping,    │
│      PropertyChanged, Signal,     │ UE  │      Set*Request, Op*Request,     │
│      OpReply, ServiceDisconnect   │ Msg │      ClientDisconnect             │
│                                   │ Bus │                                   │
│  ReplyPromisesMap<FGuid, void*>   │     │  ConnectedClientsTimestamps       │
│    (FCriticalSection protected)   │     │    (NO synchronization!)          │
│                                   │     │                                   │
│  PingRTTBuffer (60 samples)       │     │  BackendService → I*Interface     │
└───────────────────────────────────┘     └───────────────────────────────────┘
```

**Connection lifecycle:**
```
Client: _Connect() → Build endpoint → Publish DiscoveryMessage
Server: OnDiscoveryMessage → HandleClientConnectionRequest → Send InitMessage
Client: OnConnectionInit → Store ServiceAddress → Start heartbeat ping
        ← PingMessage/PongMessage cycle (configurable interval) →
        Timeout (2x interval with no pong) → Invalidate → Reconnect
```

### What Works Well

**Service address validation** in signal and property handlers prevents message spoofing. **RTT statistics tracking** with a 60-sample ring buffer provides latency diagnostics. **Property deduplication** on the client side reduces network traffic.

---

### SA-05 (HIGH) -- Stack-Local Promise Stored as Dangling Pointer

**Location:** `templates/module/Source/modulemsgbus/Private/Generated/MsgBus/msgbusclient.cpp.tpl:395-396,410`

**Issue:** For operations with return values, a `TPromise<T>` is created on the stack, its address stored in a map as `void*`, and `GetFuture().Get()` blocks until the reply:

```cpp
TPromise<ReturnType> Promise;           // Stack-local
StorePromise(msg->ResponseId, Promise); // Stores &Promise as void*
return Promise.GetFuture().Get();       // Blocks until reply
```

If the reply never arrives (service crash), `Get()` blocks the calling thread forever. If the thread is interrupted, the map holds a dangling pointer to a destroyed stack frame. The `FulfillPromise` method then dereferences `static_cast<TPromise<T>*>(void*)` into freed memory.

**Recommendation:** Use `TSharedRef<TPromise<T>>` (the OLink client already demonstrates the correct pattern).

---

### SA-06 (HIGH) -- No Timeout or Cleanup for Pending Promises

**Location:** `templates/module/Source/modulemsgbus/Private/Generated/MsgBus/msgbusclient.cpp.tpl:109-136,295-306`

**Issue:** `_Disconnect()` and `OnServiceClosedConnection` do not clear or fulfill pending promises in `ReplyPromisesMap`. Any thread blocked on `GetFuture().Get()` hangs permanently. There is no timeout mechanism.

**Recommendation:** On disconnect, iterate `ReplyPromisesMap` and fulfill all pending promises with default values. Add configurable timeout via `TFuture::WaitFor()`.

---

### SA-08 (HIGH) -- BackendService Null Dereference in Adapter

**Location:** `templates/module/Source/modulemsgbus/Private/Generated/MsgBus/msgbusadapter.cpp.tpl:188,300,308,351`

**Issue:** Message handlers dereference `BackendService->` without null checks. If `_setBackendService` was never called, these crash. The `checkf` in `_setBackendService` compiles out in Shipping (SA-14).

**Recommendation:** Add null guard with error log at top of each handler.

---

### SA-25 (MEDIUM) -- Unsynchronized ConnectedClientsTimestamps Map

**Location:** `templates/module/Source/modulemsgbus/Private/Generated/MsgBus/msgbusadapter.cpp.tpl:201,234,253,269-284`

**Issue:** `ConnectedClientsTimestamps` is accessed from the transport thread (message handlers) and the ticker thread (`_CheckClientTimeouts`) without synchronization. Concurrent `Add` during iteration can invalidate iterators.

**Recommendation:** Add `FCriticalSection` protecting all map access.

---

### SA-12 (MEDIUM) -- Message Handlers Run on Transport Thread

**Location:** `templates/module/Source/modulemsgbus/Private/Generated/MsgBus/msgbusclient.cpp.tpl` (all `On*` handlers)

**Issue:** `FMessageEndpoint` dispatches handlers on the transport thread. Handlers directly modify member variables and broadcast through the publisher. C++ subscriber callbacks fire on the transport thread. Property writes race with game-thread reads.

**Recommendation:** Marshal all state mutations and broadcasts to the game thread.

---

### SA-11 (LOW) -- Aggressive Heartbeat Timeout

**Location:** `templates/module/Source/modulemsgbus/Private/Generated/MsgBus/msgbusclient.cpp.tpl:220`

**Issue:** Timeout at `2 * _HeartbeatIntervalMS` (default 200ms). GC pauses and loading screens easily exceed this, causing false disconnections.

**Recommendation:** Tuning concern. Consider increasing default interval or timeout multiplier.

---

### OLink vs MsgBus Comparison

| Aspect | OLink | MsgBus |
|--------|-------|--------|
| **Protocol** | JSON over WebSocket | UE Message Bus (IPC) |
| **Network** | TCP (remote-capable) | Same-process/machine |
| **Serialization** | nlohmann::json (runtime) | USTRUCT (compile-time) |
| **Async Operations** | `TSharedRef<TPromise<T>>` (correct) | `void*` to stack-local `TPromise` (broken) |
| **Heartbeat** | Implicit (WebSocket ping/pong) | Explicit 100ms ping/pong |
| **Platform** | Not on iOS/Android/QNX | All platforms |

### Layer 5 Summary

| Finding | Severity | Location | Issue | Fix Effort |
|---------|----------|----------|-------|------------|
| SA-05 | HIGH | `msgbusclient.cpp.tpl:395-410` | Stack-local `TPromise` as `void*` -- dangling pointer + infinite block | Medium |
| SA-06 | HIGH | `msgbusclient.cpp.tpl:109-136` | No timeout/cleanup for pending promises on disconnect | Medium |
| SA-08 | HIGH | `msgbusadapter.cpp.tpl:188,300,308,351` | `BackendService->` without null check | Trivial |
| SA-25 | MEDIUM | `msgbusadapter.cpp.tpl:201,234,253,269` | `ConnectedClientsTimestamps` concurrent access | Low |
| SA-12 | MEDIUM | `msgbusclient.cpp.tpl` | Handlers modify members on transport thread | Medium |
| SA-11 | LOW | `msgbusclient.cpp.tpl:220` | 200ms heartbeat timeout too aggressive | Trivial |

---

## Cross-Cutting Concerns

### SA-14 (HIGH) -- `checkf` Compiles Out in Shipping Builds

**Location:** `loggingdecorator.cpp.tpl:66-67,71,77`, `msgbusadapter.cpp.tpl:147,152,157`, `olinksource.cpp.tpl:56-58`

**Issue:** Multiple layers use `checkf` as their only null-pointer protection:

```cpp
checkf(BackendPublisher, TEXT("Cannot unsubscribe from backend service"));
checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service"));
```

In Development/Debug builds, `checkf` halts execution with a message. In Shipping builds, `checkf` compiles to a no-op -- execution continues past the check into a null dereference crash. This removes the only protection from critical code paths across three layers.

**Recommendation:** Dual pattern -- keep `checkf` for development diagnostics AND add a graceful fallback:

```cpp
checkf(BackendPublisher, TEXT("Cannot unsubscribe from backend service"));
if (!BackendPublisher)
{
    UE_LOG(LogModule, Error, TEXT("BackendPublisher is null"));
    return;
}
```

---

### SA-13 (MEDIUM) -- Threading Model Inconsistency Across Layers

**Issue:** Each layer delivers property/signal callbacks on a different thread with no unified contract:

| Layer | Callback Thread | BP Safety |
|-------|----------------|-----------|
| Publisher (API) | Caller's thread (C++), game thread (BP) | Yes |
| Monitor | Caller's thread | Depends on caller |
| OLink | WebSocket thread | BP deferred correctly |
| MsgBus | Transport thread | BP deferred correctly |

C++ subscribers must be thread-safe but have no documentation warning them. Different concrete implementations of the same interface deliver callbacks on different threads, making it impossible for a subscriber to make consistent threading assumptions.

**Recommendation:** Document the threading contract at the interface level. Long-term, marshal all callbacks to the game thread.

---

### Observation: No Cancellation or Timeout for Async Operations

**Issue (systemic, see SA-05/SA-06):** Both OLink (`olinkclient.cpp.tpl`, blocks on `TFuture::Get()`) and MsgBus (`msgbusclient.cpp.tpl:410`, blocks on `Promise.GetFuture().Get()`) have no timeout mechanism. If the remote service dies during an in-flight operation, the calling thread blocks forever. This is systemic across both IPC layers.

**Recommendation:** Add configurable timeout via `TFuture::WaitFor()` or `FPlatformProcess::Sleep`-based polling. Expose timeout value in `U{Module}Settings`. Do NOT add parameters to operation signatures (that would be a public API break).

---

### Observation: Error Propagation Gap

**Issue:** All layers handle errors by logging and returning default values:
- JSON deserialization errors → default value + `UE_LOG(Error)`
- Connection failures → default value + `UE_LOG(Error)`
- Missing backend service → default value + `UE_LOG(Error)`

There is no error callback mechanism for consumers to react to failures. A consumer calling an operation on a disconnected MsgBus client receives `false`/`0`/`""` with no way to distinguish "operation returned false" from "operation failed."

**Recommendation:** Consider adding an error delegate or status return pattern in a future major version.

---

### Observation: Subsystem Lifecycle Ordering

**Issue:** No template uses `FSubsystemCollectionBase` dependency declarations. Cross-layer initialization order (e.g., monitor needs backend, backend needs adapter, adapter needs connection) is undefined and relies on registration order, which varies by platform and UE version.

**Recommendation:** Use the `Collection` parameter in `Initialize()` to declare dependencies:

```cpp
void Initialize(FSubsystemCollectionBase& Collection)
{
    Collection.InitializeDependency<UOtherSubsystem>();
    Super::Initialize(Collection);
}
```

---

## Consolidated Findings

| ID | Severity | Layer | Location | Issue | API Impact |
|----|----------|-------|----------|-------|------------|
| SA-02 | **CRITICAL** | Runtime | `tracer.cpp:37-44` | Singleton check-then-create race -- double construction, leak | CAUTION |
| SA-01 | **HIGH** | Runtime | `tracer.cpp:18,107,137,149` | `static bool isbusy` data race across threads | SAFE |
| SA-03 | **HIGH** | Runtime | `OLinkSink.h:52-60` | Callbacks set/reset/invoked across threads without lock | CAUTION |
| SA-05 | **HIGH** | MsgBus | `msgbusclient.cpp.tpl:395-410` | Stack-local `TPromise` stored as `void*` -- dangling + block | CAUTION |
| SA-06 | **HIGH** | MsgBus | `msgbusclient.cpp.tpl:109-136` | No timeout/cleanup for pending promises on disconnect | CAUTION |
| SA-07 | **HIGH** | OLink | `olinksource.cpp.tpl:111-137` | No `args.size()` check in server invoke | SAFE |
| SA-08 | **HIGH** | MsgBus | `msgbusadapter.cpp.tpl:188,300,308,351` | `BackendService->Method()` without null check | SAFE |
| SA-14 | **HIGH** | Cross-cutting | Multiple | `checkf` compiles out in Shipping -- null deref | SAFE |
| SA-18 | **HIGH** | Monitor | `loggingdecorator.cpp.tpl:54-58` | Post-deinit `BackendService` null deref | SAFE |
| SA-23 | **HIGH** | OLink | `olinkclient.cpp.tpl:62-83` | Raw `this` in sink callbacks -- use-after-destruction | CAUTION |
| SA-04 | **MEDIUM** | Monitor | `loggingdecorator.cpp.tpl:75-83` | Subscribe before property read -- stale callback state | SAFE |
| SA-09 | **MEDIUM** | API | `abstract.cpp.tpl:98-110` | ThreadPool dispatch -- undocumented threading contract | CAUTION |
| SA-10 | **MEDIUM** | OLink | `OLinkClientConnection.cpp` | C++ callbacks fire on WebSocket thread | CAUTION |
| SA-12 | **MEDIUM** | MsgBus | `msgbusclient.cpp.tpl` | Handlers run on transport thread, mutate members | CAUTION |
| SA-13 | **MEDIUM** | Cross-cutting | Multiple | No unified threading contract across layers | CAUTION |
| SA-15 | **MEDIUM** | Monitor | `trace.cpp.tpl:21-28` | Non-atomic multi-property state capture | SAFE |
| SA-16 | **MEDIUM** | OLink | `olinkclient.cpp.tpl:58-98` | Partial init if connection store returns null | SAFE |
| SA-17 | **MEDIUM** | Runtime | `tracer.cpp:143-146` | Null `HttpResponse` deref on failed request | SAFE |
| SA-24 | **MEDIUM** | OLink | `olinkclient.cpp.tpl:284-349` | Property writes from WebSocket thread | CAUTION |
| SA-25 | **MEDIUM** | MsgBus | `msgbusadapter.cpp.tpl:201,234,253,269` | `ConnectedClientsTimestamps` map unsynchronized | SAFE |
| SA-11 | **LOW** | MsgBus | `msgbusclient.cpp.tpl:220` | Aggressive heartbeat timeout (200ms) | SAFE |
| SA-19 | **LOW** | API | `abstract.h.tpl` | Publisher raw `UObject*` relies on `AddReferencedObjects` | SAFE |
| SA-20 | **LOW** | API | `data.h.tpl` | Enum deser: no range validation | SAFE |
| SA-21 | **LOW** | OLink | `olinkclient.cpp.tpl` | `_SentData` cross-thread write -- redundant sends only | SAFE |
| SA-22 | **LOW** | Runtime | `tracer.cpp:16,37-44` | Singleton never freed, `m_http` dangles on hot-reload | SAFE |

---

## Mitigation Roadmap

### Immediate (Before Final Release -- SAFE, no API impact)

| Fix | Finding | Effort |
|-----|---------|--------|
| `std::atomic<bool>` for `isbusy` | SA-01 | Trivial |
| `args.size()` check in `olinkInvoke` | SA-07 | Trivial |
| Null-check `BackendService` in MsgBus adapter handlers | SA-08 | Trivial |
| `bSucceeded && HttpResponse.IsValid()` check | SA-17 | Trivial |
| `checkf` + graceful null-check/return for Shipping | SA-14 | Low |
| Post-deinit null guard + unsubscribe in LoggingDecorator | SA-18 | Low |
| Reorder `setBackendService` (subscribe last) | SA-04 | Trivial |

### Immediate (Before Final Release -- CAUTION, need release notes)

| Fix | Finding | Effort | Release Note |
|-----|---------|--------|-------------|
| `std::call_once` + heap leak for Tracer singleton | SA-02 | Low | Internal only |
| `TSharedRef<TPromise<T>>` with timeout + cleanup on disconnect | SA-05, SA-06 | Medium | "MsgBus operations return defaults on timeout" |

### Short-Term

| Fix | Finding | Effort | Release Note |
|-----|---------|--------|-------------|
| `FCriticalSection` in `FOLinkSink` + weak pointer in callbacks | SA-03, SA-23 | Low | "OLink teardown: stale callbacks safely skipped" |
| `FCriticalSection` on `ConnectedClientsTimestamps` | SA-25 | Low | None |

### Medium-Term

| Fix | Finding | Effort | Release Note |
|-----|---------|--------|-------------|
| Game-thread marshaling for property mutations and callbacks | SA-09, SA-10, SA-12, SA-13, SA-24 | Medium | "Callbacks now delivered on game thread" |
| Configurable async operation timeout | Systemic | Medium | "Operation timeout added to settings" |

---

## API Compatibility

All proposed mitigations have been audited for public API breaks. **No breaking changes identified.**

### SAFE -- No public API impact

SA-01, SA-04, SA-07, SA-08, SA-14, SA-15, SA-17, SA-18, SA-19, SA-20, SA-25 -- purely internal changes, no header modifications, no signature changes.

### CAUTION -- Behavioral changes requiring release notes

| Fix | Change | Required Release Note |
|-----|--------|----------------------|
| SA-02 | `std::call_once` + heap leak (avoids `tracer.h` header change) | Internal only |
| SA-03/SA-23 | `FCriticalSection` added to `OLinkSink.h` (ABI change, not source break) | "OLink teardown: stale callbacks safely skipped" |
| SA-05/SA-06 | Operations timeout instead of blocking forever (current pattern is already UB) | "MsgBus operations return default values on service timeout" |
| SA-09/10/12/13/24 | Callbacks fire on game thread instead of network thread | "Property/signal callbacks now delivered on game thread" |

### BREAKING -- None

No fix in its recommended form breaks the public generated API. Function signatures, UFUNCTION/UPROPERTY declarations, USTRUCT definitions, and Build.cs dependencies are all preserved.

---

## Appendix: Severity Definitions

| Level | Definition | Expected Response |
|-------|-----------|-------------------|
| **CRITICAL** | Data race or memory corruption exploitable under normal operation. May cause silent data loss or security vulnerabilities. | Fix before release. |
| **HIGH** | Crash or hang under plausible runtime conditions (service disconnect, concurrent access, shipping build). | Fix before release or document as known limitation. |
| **MEDIUM** | Incorrect behavior under edge conditions, undocumented contracts, or code that works by accident. | Fix in next release cycle. |
| **LOW** | Code quality, missing validation for unlikely inputs, or design debt that increases future risk. | Track and address opportunistically. |

---

## References

- [Blueprint Adapter Code Review](blueprint-adapter-review.md) -- Prior review of the BP adapter layer
