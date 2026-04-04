# Tracer Safety Fixes Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Fix the CRITICAL singleton race (SA-02), HIGH data race on `isbusy` (SA-01), and MEDIUM null-dereference in HTTP callback (SA-17) in the ApiGear `Tracer` class.

**Architecture:** The `Tracer` is a raw C++ singleton (not a UObject) in `templates/ApiGear/Source/ApiGear/`. Files are `raw: true` in `rules.yaml` — they are copied verbatim to `goldenmaster/Plugins/ApiGear/`. Changes to the template files must be followed by `go run main.go master` to sync the golden master, then `go run main.go diff` to verify no unexpected delta. There is no unit test runner for the Tracer; validation is generate → diff → inspect.

**Tech Stack:** C++17 (`std::atomic`, `std::once_flag`, `std::call_once`), Unreal Engine HTTP module, nlohmann::json.

---

## Task 1: Fix the singleton race condition (SA-02)

**Files:**
- Modify: `templates/ApiGear/Source/ApiGear/Public/tracer.h:38`
- Modify: `templates/ApiGear/Source/ApiGear/Private/tracer.cpp:16,37-44`

**Step 1: Modify `tracer.h` — remove `s_instance` from the class declaration**

The static member `s_instance` at line 38 moves to a file-static in `.cpp`. This avoids exposing the implementation detail in the public header.

Replace line 38:

```cpp
	static Tracer* s_instance;
```

With nothing — delete the line entirely.

**Step 2: Modify `tracer.cpp` — replace the check-then-create pattern with `std::call_once`**

Add `#include <mutex>` and `#include <atomic>` to the includes at the top of the file (after `#include "ApiGearSettings.h"` at line 12). Both are needed: `<mutex>` for this task, `<atomic>` for Task 2.

Replace lines 16 and 37-44:

```cpp
// OLD (line 16):
Tracer* Tracer::s_instance(nullptr);

// OLD (lines 37-44):
Tracer* Tracer::instance()
{
	if (!s_instance)
	{
		s_instance = new Tracer();
	}
	return s_instance;
}
```

With:

```cpp
// NEW (line 16 area):
static Tracer* s_instance = nullptr;
static std::once_flag s_onceFlag;

// NEW (replacing lines 37-44):
Tracer* Tracer::instance()
{
	std::call_once(s_onceFlag, []()
	{
		s_instance = new Tracer();
	});
	return s_instance;
}
```

**Step 2b: Remove dead `if (s_instance)` guard in constructor**

The constructor (lines 20-35) contains a guard that is now dead code:

```cpp
// OLD (lines 24-27):
	if (s_instance)
	{
		log("Tracer can only be instantiated once");
	}
```

Delete these 4 lines. `std::call_once` guarantees single invocation, so `s_instance` is always `nullptr` when the constructor runs.

Key design decisions:
- `std::call_once` guarantees exactly one construction even under concurrent first calls
- Heap allocation (`new Tracer()`) is intentionally leaked — the destructor must NOT run during static teardown because `FHttpModule` is already destroyed by then
- `s_instance` becomes file-static (not class-static) since it's now only accessed in this `.cpp` file
- Dead constructor guard removed — `std::call_once` makes it unreachable

**Step 3: Generate and verify**

```bash
go run main.go master
go run main.go diff
```

Expected: `diff` reports no differences (golden master is in sync with templates).

**Step 4: Run code simplifier, then commit**

```bash
git add templates/ApiGear/Source/ApiGear/Public/tracer.h
git add templates/ApiGear/Source/ApiGear/Private/tracer.cpp
git add goldenmaster/Plugins/ApiGear/Source/ApiGear/Public/tracer.h
git add goldenmaster/Plugins/ApiGear/Source/ApiGear/Private/tracer.cpp
git commit -m "fix(apigear): use std::call_once for thread-safe tracer singleton"
```

---

## Task 2: Fix the `isbusy` data race (SA-01)

**Files:**
- Modify: `templates/ApiGear/Source/ApiGear/Private/tracer.cpp:18`

**Step 1: Replace `static bool` with `std::atomic<bool>`**

Add `#include <atomic>` to the includes (if not already present after Task 1's `#include <mutex>`).

Replace line 18:

```cpp
static bool isbusy = false;
```

With:

```cpp
static std::atomic<bool> isbusy{false};
```

No other code changes required — all existing reads (`if (isbusy)`) and writes (`isbusy = true`, `isbusy = false`) work with `std::atomic<bool>` via implicit load/store.

**Step 2: Generate and verify**

```bash
go run main.go master
go run main.go diff
```

Expected: no differences.

**Step 3: Run code simplifier, then commit**

```bash
git add templates/ApiGear/Source/ApiGear/Private/tracer.cpp
git add goldenmaster/Plugins/ApiGear/Source/ApiGear/Private/tracer.cpp
git commit -m "fix(apigear): use atomic flag for tracer http busy state"
```

---

## Task 3: Fix null HttpResponse dereference (SA-17)

**Files:**
- Modify: `templates/ApiGear/Source/ApiGear/Private/tracer.cpp:142-151`

**Step 1: Add success and validity check before accessing response**

Replace the HTTP completion lambda (lines 142-151):

```cpp
			m_httprequest->OnProcessRequestComplete().BindStatic(
				[](FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
				{
				FString Messagebody;
				Messagebody = HttpResponse->GetContentAsString();
				// log(Messagebody);
				// UE_LOG(LogApiGearTracer, Display, TEXT("Response: %s"), *Messagebody);
				isbusy = false;
				// HttpResponse->GetContentAsString();
			});
```

With:

```cpp
			m_httprequest->OnProcessRequestComplete().BindStatic(
				[](FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
				{
				if (bSucceeded && HttpResponse.IsValid())
				{
					FString Messagebody = HttpResponse->GetContentAsString();
				}
				isbusy = false;
			});
```

Key changes:
- Guard `HttpResponse->` with `bSucceeded && HttpResponse.IsValid()`
- Remove dead commented-out code
- `isbusy = false` must execute unconditionally (outside the guard) so the tracer unblocks even on failure

**Step 2: Generate and verify**

```bash
go run main.go master
go run main.go diff
```

Expected: no differences.

**Step 3: Run code simplifier, then commit**

```bash
git add templates/ApiGear/Source/ApiGear/Private/tracer.cpp
git add goldenmaster/Plugins/ApiGear/Source/ApiGear/Private/tracer.cpp
git commit -m "fix(apigear): guard tracer http response access"
```

---

## Verification

After all three tasks, run full verification:

```bash
go run main.go diff
```

Expected: no differences between generated output and golden master.

Optionally, if UE is available:

```bash
export PATH="/home/wolfgang.bremer/ws/ue/Linux_Unreal_Engine_5.6.0/Engine/Build/BatchFiles:$PATH"
cd goldenmaster/Plugins && ./buildPlugins.sh
```

Expected: all 11 plugins compile cleanly. The ApiGear plugin (which contains `tracer.cpp`) must build without errors.

---

## Code Quality Pass

After all three tasks are committed, run `@superpowers:simplify` once on the changed files (`tracer.h` and `tracer.cpp`). Batching the simplifier avoids intermediate churn between commits.

---

## Not in Scope

- **SA-22** (Tracer never freed / `m_http` dangle on hot-reload) — the `std::call_once` + intentional leak from Task 1 is the accepted pattern. Documenting is sufficient.
- **TOCTOU in `process()`** — `std::atomic<bool>` on `isbusy` makes the read/write well-defined, but does not serialize `process()`. Two threads can still race past `if (isbusy)` and both send HTTP requests. This is pre-existing and low-impact (duplicate trace sends are harmless).
- **SA-03** (OLinkSink callback thread safety) — separate plan, different files, CAUTION API impact.
- **SA-05/SA-06** (MsgBus promise pattern) — separate plan, different feature, CAUTION API impact.
