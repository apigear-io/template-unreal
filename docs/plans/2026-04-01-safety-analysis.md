# Safety Analysis Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Write a comprehensive safety analysis document at `docs/reviews/safety-analysis.md` covering all template layers and the ApiGear runtime, with 25 findings ranked by severity.

**Architecture:** Layer-by-layer analysis (Runtime → API → Stubs → Monitor → OLink → MsgBus → Cross-cutting), each covering thread safety, memory safety, input validation, and identified hazards. Follows the style of the existing `docs/reviews/blueprint-adapter-review.md`. All findings verified against source files before documenting.

**Tech Stack:** Go text templates (`.tpl`), Unreal Engine C++ (UE4.27+/UE5.4+), nlohmann::json, OLink WebSocket protocol, UE Message Bus.

---

## Findings Registry

All 25 findings with final severity calibrations (post architecture review + API compatibility audit):

| ID | Severity | Layer | File | One-Line |
|----|----------|-------|------|----------|
| SA-02 | CRITICAL | Runtime | `tracer.cpp:37-44` | Singleton check-then-create race → double construction, leak |
| SA-01 | HIGH | Runtime | `tracer.cpp:18,107,137,149` | `static bool isbusy` data race across threads |
| SA-03 | HIGH | Runtime | `OLinkSink.h` | Callbacks set/reset on game thread, invoked from WebSocket thread |
| SA-05 | HIGH | MsgBus | `msgbusclient.cpp.tpl:395-410` | Stack-local `TPromise` stored as `void*` — dangling pointer + infinite block |
| SA-06 | HIGH | MsgBus | `msgbusclient.cpp.tpl` | No timeout/cleanup for pending promises on disconnect |
| SA-07 | HIGH | OLink | `olinksource.cpp.tpl:124-125` | No `args.size()` check before `args.at(i)` in server invoke |
| SA-08 | HIGH | MsgBus | `msgbusadapter.cpp.tpl` | `BackendService->Method()` without null check |
| SA-14 | HIGH | Cross-cutting | Multiple | `checkf` compiles out in Shipping → null deref |
| SA-18 | HIGH | Monitor | `loggingdecorator.cpp.tpl:57,106-133` | Post-deinit `BackendService` null deref |
| SA-23 | HIGH | OLink | `olinkclient.cpp.tpl:62-83` | Raw `this` in sink callbacks — use-after-destruction |
| SA-04 | MEDIUM | Monitor | `loggingdecorator.cpp.tpl:75-83` | Subscribe before property read → stale callback state |
| SA-09 | MEDIUM | API | `abstract.cpp.tpl:~98` | ThreadPool dispatch — undocumented threading contract |
| SA-10 | MEDIUM | OLink | `OLinkClientConnection.cpp` | C++ callbacks fire on WebSocket thread |
| SA-12 | MEDIUM | MsgBus | `msgbusclient.cpp.tpl` | Handlers run on transport thread, mutate members |
| SA-13 | MEDIUM | Cross-cutting | Multiple | No unified threading contract across layers |
| SA-15 | MEDIUM | Monitor | `trace.cpp.tpl` | Non-atomic multi-property state capture |
| SA-16 | MEDIUM | OLink | `olinkclient.cpp.tpl` | Partial init if connection store returns null |
| SA-17 | MEDIUM | Runtime | `tracer.cpp:143-146` | Null `HttpResponse` deref on failed request |
| SA-24 | MEDIUM | OLink | `olinkclient.cpp.tpl:284-349` | Property writes from WebSocket thread race with game-thread reads |
| SA-25 | MEDIUM | MsgBus | `msgbusadapter.cpp.tpl` | `ConnectedClientsTimestamps` map: no synchronization |
| SA-11 | LOW | MsgBus | `msgbusclient.cpp.tpl:220` | Aggressive heartbeat timeout (200ms) |
| SA-19 | LOW | API | `abstract.h.tpl` | Publisher raw `UObject*` relies on `AddReferencedObjects` |
| SA-20 | LOW | API | `json.adapter.h.tpl` | Enum deser: no range validation |
| SA-21 | LOW | OLink | `olinkclient.cpp.tpl` | `_SentData` cross-thread write — redundant sends only |
| SA-22 | LOW | Runtime | `tracer.cpp:16,37-44` | Singleton never freed, `m_http` dangles on hot-reload |

---

## API Compatibility Notes

All proposed mitigations audited for public API breaks. **No breaking changes.** Include these notes in the document:

- **SAFE** (7 fixes): SA-01, SA-04, SA-07, SA-08, SA-14, SA-17, SA-18 — purely internal, no header changes
- **CAUTION** (6 fixes, need release notes):
  - SA-02: Use `std::call_once` + heap leak (NOT magic static — avoids destructor-during-static-teardown AND `tracer.h` header change)
  - SA-03/SA-23: Adding `FCriticalSection` to `OLinkSink.h` is ABI change (not source break). Callbacks during teardown silently dropped
  - SA-05/SA-06: Operations timeout instead of blocking indefinitely. Current pattern is already broken (use-after-scope)
  - SA-09/10/12/13/24: Game-thread marshaling changes callback delivery thread — **most impactful behavioral change**

---

## Task 1: Create Document Skeleton

**Files:**
- Create: `docs/reviews/safety-analysis.md`

**Step 1: Write the skeleton**

Create the file with header, TOC, empty sections for all 8 layers, and severity appendix. Use the structure from `docs/reviews/blueprint-adapter-review.md` as reference for formatting style (Markdown tables, `**Location:**` tags, code blocks with file references).

```markdown
# Safety Analysis: UE Template Full Review

**Date:** 2026-04-01
**Scope:** All Go templates (`.tpl`), ApiGear runtime (`templates/ApiGear/`, `goldenmaster/Plugins/ApiGear/`), generated golden master output
**Methodology:** Manual code review of templates and generated output, architecture review, API compatibility audit
**Reviewers:** Automated analysis with architecture advisor validation

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

[25 findings: 1 CRITICAL, 8 HIGH, 8 MEDIUM, 8 LOW. Brief paragraph on key themes: threading model gaps, promise lifecycle bugs, null-pointer hazards behind checkf, and singleton races. Cross-reference with blueprint-adapter-review.md.]

---

## Appendix: Severity Definitions

| Level | Definition | Expected Response |
|-------|-----------|-------------------|
| **CRITICAL** | Data race or memory corruption exploitable under normal operation. May cause silent data loss or security vulnerabilities. | Fix before release. |
| **HIGH** | Crash or hang under plausible runtime conditions (service disconnect, concurrent access, shipping build). | Fix before release or document as known limitation. |
| **MEDIUM** | Incorrect behavior under edge conditions, undocumented contracts, or code that works by accident. | Fix in next release cycle. |
| **LOW** | Code quality, missing validation for unlikely inputs, or design debt that increases future risk. | Track and address opportunistically. |
```

**Step 2: Commit**

```bash
git add docs/reviews/safety-analysis.md
git commit -m "docs(api): add safety analysis skeleton"
```

---

## Task 2: Write Layer 0 — ApiGear Runtime Infrastructure

**Files:**
- Modify: `docs/reviews/safety-analysis.md`
- Verify against: `templates/ApiGear/Source/ApiGear/Private/tracer.cpp`
- Verify against: `templates/ApiGear/Source/ApiGear/Public/tracer.h`
- Verify against: `goldenmaster/Plugins/ApiGear/Source/ApiGearOLink/Public/OLinkSink.h`

**Step 1: Verify SA-02 (CRITICAL)**

Read `templates/ApiGear/Source/ApiGear/Private/tracer.cpp:37-44`. Confirm:
- `s_instance` is a raw static pointer (line 16)
- `instance()` does `if (!s_instance) { s_instance = new Tracer(); }` with no synchronization
- Constructor at line 20 calls `GetMutableDefault<UApiGearSettings>()` — unsafe off game thread

**Step 2: Verify SA-01 (HIGH)**

Same file, lines 18, 107, 137, 149. Confirm:
- `static bool isbusy` at line 18
- Read without lock at line 107
- Write under `FScopeLock` at line 137 (inside the queue lock scope)
- Write in HTTP callback lambda at line 149 (different thread, no lock)

**Step 3: Verify SA-03 (HIGH)**

Read `goldenmaster/Plugins/ApiGear/Source/ApiGearOLink/Public/OLinkSink.h`. Confirm:
- `TFunction<>` members for callbacks (`PropertyChangedFunc`, `SignalEmittedFunc`, etc.)
- No mutex protection on these members
- Set from game thread (client `Initialize`/`Deinitialize`), invoked from WebSocket thread

**Step 4: Verify SA-17 (MEDIUM)**

Same tracer.cpp, lines 143-146. Confirm:
- HTTP completion callback: `Messagebody = HttpResponse->GetContentAsString();`
- No check on `bSucceeded` or `HttpResponse` validity
- `HttpResponse` is null on timeout/DNS failure

**Step 5: Verify SA-22 (LOW)**

Same file, line 16 and 37-44. Confirm:
- `new Tracer()` is never `delete`d
- `m_http` is raw `FHttpModule*` — dangles after module unload in editor

**Step 6: Write the Layer 0 section**

Write the full section including:
- Positive pattern: `FCriticalSection m_queueMutex` correctly protects the event queue
- All 5 findings with `**Location:**`, code snippets, and `**Recommendation:**`
- Architecture diagram showing Tracer as singleton serving all layers

**Step 7: Commit**

```bash
git add docs/reviews/safety-analysis.md
git commit -m "docs(api): add layer 0 runtime infrastructure analysis"
```

---

## Task 3: Write Layer 1 — API

**Files:**
- Modify: `docs/reviews/safety-analysis.md`
- Verify against: `templates/module/Source/moduleapi/Private/Generated/api/publisher.cpp.tpl`
- Verify against: `templates/module/Source/moduleapi/Public/module/Generated/api/abstract.h.tpl`
- Verify against: `templates/module/Source/moduleapi/Private/Generated/api/abstract.cpp.tpl`

**Step 1: Verify positive patterns in publisher.cpp.tpl**

Confirm:
- `FRWLock` with `FReadScopeLock`/`FWriteScopeLock` for subscriber lists
- Copy-under-read-lock before iteration
- `TWeakInterfacePtr::IsValid()` check before callback
- `IsInGameThread()` check — BP subscribers deferred via `AsyncTask(ENamedThreads::GameThread)`
- `TWeakObjectPtr` capture in async lambdas

**Step 2: Verify SA-09 (MEDIUM)**

Read `abstract.cpp.tpl`, find `Async(EAsyncExecution::ThreadPool, ...)` block. Confirm:
- Operations dispatched to thread pool
- No documentation that subclass overrides must be thread-safe
- Cross-reference: this is the same mechanism the BP adapter review's CRITICAL finding exploits

**Step 3: Verify SA-19 (LOW) and SA-20 (LOW)**

- `abstract.h.tpl`: Publisher stored as raw `UObject*`, protected only by `AddReferencedObjects`
- JSON adapter: enum deserialization uses `is_number_integer()` but no `static_cast` range check

**Step 4: Write the Layer 1 section**

Include:
- Positive patterns subsection (publisher is gold standard)
- All 3 findings
- Architecture diagram: dual interface pattern (C++ interface + BP subscriber interface + Publisher)

**Step 5: Commit**

```bash
git add docs/reviews/safety-analysis.md
git commit -m "docs(api): add layer 1 api analysis"
```

---

## Task 4: Write Layer 2 — Stubs

**Files:**
- Modify: `docs/reviews/safety-analysis.md`
- Verify against: `templates/module/Source/moduleimpl/Private/Implementation/implementation.cpp.tpl`

**Step 1: Brief verification**

Confirm:
- Dirty-check pattern: `if (Property != InProperty)` before broadcast
- `TRACE_CPUPROFILER_EVENT_SCOPE_STR()` on all operations
- `(void)Param;` for unused parameter suppression
- `preserve: true` in `rules.yaml` for implementation files

**Step 2: Write the Layer 2 section**

Brief section — this is the simplest layer. Note that `preserve: true` makes user modifications the safety boundary. No findings above LOW.

**Step 3: Commit**

```bash
git add docs/reviews/safety-analysis.md
git commit -m "docs(api): add layer 2 stubs analysis"
```

---

## Task 5: Write Layer 3 — Monitor

**Files:**
- Modify: `docs/reviews/safety-analysis.md`
- Verify against: `templates/module/Source/modulemonitor/Private/Generated/Monitor/loggingdecorator.cpp.tpl`
- Verify against: `templates/module/Source/modulemonitor/Private/Generated/Monitor/trace.cpp.tpl`

**Step 1: Verify SA-18 (HIGH)**

Read `loggingdecorator.cpp.tpl`. Confirm:
- `Deinitialize()` at line 57: `BackendService = nullptr`
- Forwarding methods (lines 104-133): `BackendService->GetProp()`, `BackendService->SetProp()`, `BackendService->Method()` — all dereference without null check
- No lifecycle guard after deinit

**Step 2: Verify SA-04 (MEDIUM)**

Same file, lines 73-83. Confirm:
- Line 75: `BackendService = InService;`
- Line 79: `BackendPublisher->Subscribe(...)` — callbacks now active
- Lines 81-83: Property reads from backend — these are AFTER subscribe
- Window: callback fires between line 79 and line 81, reads stale local property values

**Step 3: Verify SA-15 (MEDIUM)**

Read `trace.cpp.tpl`. Confirm:
- `capture_state` reads multiple properties sequentially from `BackendService`
- No lock, no snapshot — each read may see a different point in time

**Step 4: Write the Layer 3 section**

Include all 3 findings. Note the decorator pattern architecture (wraps `BackendService` via `TScriptInterface`).

**Step 5: Commit**

```bash
git add docs/reviews/safety-analysis.md
git commit -m "docs(api): add layer 3 monitor analysis"
```

---

## Task 6: Write Layer 4 — OLink IPC

**Files:**
- Modify: `docs/reviews/safety-analysis.md`
- Verify against: `templates/module/Source/moduleolink/Private/Generated/OLink/olinksource.cpp.tpl`
- Verify against: `templates/module/Source/moduleolink/Private/Generated/OLink/olinkclient.cpp.tpl`
- Verify against: `goldenmaster/Plugins/ApiGear/Source/ApiGearOLink/Private/OLinkClientConnection.cpp`

**Step 1: Verify SA-07 (HIGH)**

Read `olinksource.cpp.tpl:111-137`. Confirm:
- `olinkInvoke` method: `args.at(i).get<T>()` at line 125
- No `args.size() >= N` check before accessing elements
- With `JSON_NOEXCEPTION=1`, `at()` on out-of-bounds returns discarded json
- `get<T>()` on discarded json silently returns default value

**Step 2: Verify SA-23 (HIGH)**

Read `olinkclient.cpp.tpl`, `Initialize` method. Confirm:
- Sink callbacks capture raw `this` (e.g., `m_sink->setOnPropertyChangedCallback([this](...)`)
- Sink is `shared_ptr` held by OLink registry
- `Deinitialize` resets callbacks, but window exists between teardown start and reset

**Step 3: Verify SA-24 (MEDIUM), SA-10 (MEDIUM), SA-16 (MEDIUM), SA-21 (LOW)**

- SA-24: `applyState`/`emitSignal` write member variables from WebSocket thread
- SA-10: `OLinkClientConnection.cpp` — `handleTextMessage` on WebSocket thread
- SA-16: `Initialize` returns early on null connection but callbacks already installed
- SA-21: `_SentData` cross-thread access — worst case redundant sends

**Step 4: Write the Layer 4 section**

Include:
- Connection lifecycle state machine diagram (Constructed → Initialize → UseConnection → olinkOnInit → olinkOnRelease → Deinitialize)
- Platform guard note (disabled on iOS/Android/QNX with empty stubs)
- All 6 findings
- Positive pattern: property deduplication via `_SentData`

**Step 5: Commit**

```bash
git add docs/reviews/safety-analysis.md
git commit -m "docs(olink): add layer 4 olink analysis"
```

---

## Task 7: Write Layer 5 — MsgBus IPC

**Files:**
- Modify: `docs/reviews/safety-analysis.md`
- Verify against: `templates/module/Source/modulemsgbus/Private/Generated/MsgBus/msgbusclient.cpp.tpl`
- Verify against: `templates/module/Source/modulemsgbus/Private/Generated/MsgBus/msgbusadapter.cpp.tpl`

**Step 1: Verify SA-05/SA-06 (HIGH)**

Read `msgbusclient.cpp.tpl:370-412`. Confirm:
- Line 395: `TPromise<{{$returnVal}}> Promise;` — stack-local
- Line 396: `StorePromise(msg->ResponseId, Promise);` — stores `&Promise` as `void*`
- Line 410: `return Promise.GetFuture().Get();` — blocks until reply
- `_Disconnect()` (line 109-136): does NOT iterate `ReplyPromisesMap` or fulfill pending promises
- `OnServiceClosedConnection` (line 295-306): does NOT clear promises either

**Step 2: Verify SA-08 (HIGH)**

Read `msgbusadapter.cpp.tpl`. Find handler methods (e.g., `On{Operation}Request`). Confirm:
- `BackendService->Method()` called without null check
- `_setBackendService` may never have been called

**Step 3: Verify SA-25 (MEDIUM), SA-12 (MEDIUM), SA-11 (LOW)**

- SA-25: `ConnectedClientsTimestamps` — `.Add()` from transport thread, iterate/remove from ticker
- SA-12: `FMessageEndpoint` handlers modify members on transport thread
- SA-11: Timeout threshold `2 * _HeartbeatIntervalMS` (default 200ms)

**Step 4: Write the Layer 5 section**

Include:
- MsgBus connection state machine (Constructed → _Connect → discovery → OnConnectionInit → heartbeat → timeout → reconnect)
- Comparison table: OLink vs MsgBus (protocol, threading, validation, platform support)
- All 6 findings
- Positive patterns: service address validation, RTT stats tracking

**Step 5: Commit**

```bash
git add docs/reviews/safety-analysis.md
git commit -m "docs(msgbus): add layer 5 msgbus analysis"
```

---

## Task 8: Write Cross-Cutting Concerns + Consolidated Table

**Files:**
- Modify: `docs/reviews/safety-analysis.md`

**Step 1: Write the cross-cutting section**

6 systemic issues:
1. **SA-13 (MEDIUM)** — Threading model inconsistency across layers
2. **SA-14 (HIGH)** — `checkf` in Shipping builds removes null protection
3. No cancellation/timeout for async operations (OLink + MsgBus)
4. Error propagation gap (silent defaults everywhere)
5. Subsystem lifecycle ordering undefined
6. `BackendService` GC protection needs UPROPERTY verification

**Step 2: Write the consolidated findings table**

Full table of all 25 findings with: ID, Severity, Layer, File, Issue, Recommended Fix, API Impact (SAFE/CAUTION).

**Step 3: Write the mitigation roadmap**

Three tiers:

**Immediate** (before final release — SAFE):
- SA-01, SA-07, SA-08, SA-17, SA-14, SA-18, SA-04

**Immediate** (before final release — CAUTION, need release notes):
- SA-02 (`std::call_once` + heap leak, NOT magic static)
- SA-05/SA-06 (`TSharedRef<TPromise<T>>` with timeout)

**Short-term** (CAUTION):
- SA-03/SA-23 (`FCriticalSection` in `FOLinkSink`)
- SA-25 (`FCriticalSection` on adapter map)

**Medium-term** (CAUTION, most impactful):
- SA-09/10/12/13/24 (game-thread marshaling — changes callback delivery thread)
- Async cancellation/timeout via configurable settings

**Step 4: Write the API Compatibility section**

Include the SAFE/CAUTION/BREAKING tables from the audit.

**Step 5: Write the executive summary**

Now that all sections exist, write the summary paragraph referencing key themes and finding counts.

**Step 6: Commit**

```bash
git add docs/reviews/safety-analysis.md
git commit -m "docs(api): add cross-cutting concerns, findings table, and mitigation roadmap"
```

---

## Task 9: Final Review Pass

**Files:**
- Modify: `docs/reviews/safety-analysis.md`
- Reference: `docs/reviews/blueprint-adapter-review.md`

**Step 1: Cross-reference with BP adapter review**

Verify:
- SA-09 (ThreadPool dispatch) references the BP adapter CRITICAL finding without duplicating it
- The async lambda weak-pointer pattern from the BP adapter fix plan is cited as the correct approach

**Step 2: Verify completeness**

- All 25 SA-XX IDs present in consolidated table
- Every finding has a file path and line number
- Every finding has a recommended fix
- Every CAUTION fix has a release note entry

**Step 3: Formatting pass**

- Consistent Markdown headers (##/### levels)
- Code blocks with file references
- ASCII diagrams for architecture and state machines
- TOC links match section headers

**Step 4: Commit**

```bash
git add docs/reviews/safety-analysis.md
git commit -m "docs(api): finalize safety analysis review"
```

---

## Verification

### Step 1: Confirm no template changes leaked

```bash
go run main.go diff
```

Expected: no differences (this plan only writes to `docs/reviews/`, not templates).

### Step 2: Confirm document structure

Check that the final document has all sections from the TOC and that the consolidated findings table has exactly 25 entries.

---

## Not in Scope

- **Implementing the fixes** — this plan produces the analysis document only. Fix implementation will be a separate plan per priority tier.
- **UE compilation verification** — no template changes, so no need to rebuild plugins.
- **MISRA/ISO 26262 formal compliance** — this is a practical safety review, not a formal certification assessment.
