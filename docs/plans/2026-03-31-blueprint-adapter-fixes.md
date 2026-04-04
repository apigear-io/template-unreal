# Blueprint Adapter Fixes Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Fix the async threading model, unsafe object lifetime, and header hygiene issues in the Blueprint adapter code generation templates.

**Architecture:** The two template files (`bpadapter.cpp.tpl`, `bpadapter.h.tpl`) emit C++ for every interface in every generated plugin. Changes ripple across all plugins — the golden master (`goldenmaster/`) is the regression baseline and must be updated after each task. There is no unit test runner; validation is always: generate → diff → inspect → update master.

**Tech Stack:** Go text templates, Unreal Engine C++ (UE4.27+/UE5.4+), Mage build system (`go run main.go <cmd>`).

---

## Background

The adapter bridges Blueprint implementations to C++ interfaces. Three findings share a single root cause — the async execution model has no coherent threading or lifetime contract:

- `Async(EAsyncExecution::ThreadPool, ...)` calls Blueprint functions off the game thread (Blueprint is not thread-safe → crash/corruption)
- Raw `this` captured in the async lambda; the UObject can be GC'd before the task runs (dangling pointer → crash)
- `RemoveActionsForObject(CallbackTarget)` cancels *all* pending latent actions on the target, not just the replaced one

These must be fixed together. Additional independent fixes follow in Phase 2.

---

## Phase 1: Fix the Async Execution Model

### Task 1: Understand the current generated output

**Files:**
- Read: `templates/module/Source/moduleapi/Private/Generated/api/bpadapter.cpp.tpl`
- Reference: `goldenmaster/Plugins/TbSimple/Source/TbSimpleAPI/Private/Generated/api/TbSimpleSimpleInterfaceBPAdapter.cpp`

**Step 1: Locate the async pattern in the golden master**

Open `goldenmaster/Plugins/TbSimple/Source/TbSimpleAPI/Private/Generated/api/TbSimpleSimpleInterfaceBPAdapter.cpp` and find `FuncNoParamsAsync()` around line 66. Confirm it matches:

```cpp
TFuture<bool> UTbSimpleSimpleInterfaceBPAdapter::FuncNoParamsAsync()
{
    return Async(EAsyncExecution::ThreadPool,
        [this]()
        {
        return FuncNoParams();
    });
}
```

This is the broken pattern — ThreadPool + raw `this`.

**Step 2: Generate current output to establish baseline**

```bash
go run main.go gentest
```

Expected: output written to `test/` with no errors.

---

### Task 2: Fix thread execution and object lifetime in `bpadapter.cpp.tpl`

**Files:**
- Modify: `templates/module/Source/moduleapi/Private/Generated/api/bpadapter.cpp.tpl` (lines 80-87)

**Step 1: Open the template**

The relevant block is:

```
TFuture<{{ueReturn "" .Return}}> {{$adapter}}::{{Camel .Name}}Async({{ueParams "" .Params}})
{
	return Async(EAsyncExecution::ThreadPool,
		[{{range .Params}}{{ueVar "" .}}, {{ end }}this]()
		{
		return {{Camel .Name}}({{ueVars "" .Params}});
	});
}
```

**Step 2: Replace with game-thread execution and weak pointer capture**

Replace that block with:

```
TFuture<{{ueReturn "" .Return}}> {{$adapter}}::{{Camel .Name}}Async({{ueParams "" .Params}})
{
	TWeakObjectPtr<{{$adapter}}> WeakThis(this);
	return Async(EAsyncExecution::TaskGraphMainThread,
		[{{range .Params}}{{ueVar "" .}}, {{ end }}WeakThis]()
		{
		if ({{$adapter}}* StrongThis = WeakThis.Get())
		{
			return StrongThis->{{Camel .Name}}({{ueVars "" .Params}});
		}
		return {{ueDefault "" .Return}};
	});
}
```

Key changes:
- `ThreadPool` → `TaskGraphMainThread` — Blueprint functions must run on the game thread
- `this` → `TWeakObjectPtr<{{$adapter}}> WeakThis(this)` captured by value — safe across GC
- Guard with `WeakThis.Get()` before calling through the pointer
- Return `{{ueDefault "" .Return}}` as fallback when the adapter has been collected

**Step 3: Generate test output**

```bash
go run main.go gentest
```

Expected: no errors.

**Step 4: Inspect the diff**

```bash
go run main.go diffonly
```

Expected: every `*BPAdapter.cpp` file that has async operations should show the pattern change. Verify `TbSimpleSimpleInterfaceBPAdapter.cpp` — `FuncNoParamsAsync` should now read:

```cpp
TFuture<bool> UTbSimpleSimpleInterfaceBPAdapter::FuncNoParamsAsync()
{
    TWeakObjectPtr<UTbSimpleSimpleInterfaceBPAdapter> WeakThis(this);
    return Async(EAsyncExecution::TaskGraphMainThread,
        [WeakThis]()
        {
        if (UTbSimpleSimpleInterfaceBPAdapter* StrongThis = WeakThis.Get())
        {
            return StrongThis->FuncNoParams();
        }
        return false;
    });
}
```

Confirm no other files changed unexpectedly.

**Step 5: Update golden master**

```bash
go run main.go master
```

**Step 6: Commit**

```bash
git add templates/module/Source/moduleapi/Private/Generated/api/bpadapter.cpp.tpl
git add goldenmaster/
git commit -m "fix(api): execute blueprint calls on game thread, use weak ptr in async lambdas"
```

---

### Task 3: Fix `RemoveActionsForObject` overshoot in `bpadapter.cpp.tpl`

**Files:**
- Modify: `templates/module/Source/moduleapi/Private/Generated/api/bpadapter.cpp.tpl` (lines 66-77)

**Step 1: Locate the latent action cancellation block**

The current template block in the `{{Camel .Name}}Async(UObject* WorldContextObject, ...)` overload:

```
		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}
```

**Step 2: Remove the over-aggressive removal**

The `Cancel()` call sets `bCancelled = true` on the pending action. On the next tick, `UpdateOperation` sees this flag and calls `Response.DoneIf(true)`, which removes the action from the manager cleanly. Calling `RemoveActionsForObject(CallbackTarget)` also cancels any other in-flight async operations the same object has pending (e.g., a concurrent `FuncString` and `FuncInt` call on the same Actor).

Replace with:

```
		if (oldRequest != nullptr)
		{
			// Cancel only this specific action; it will be removed by LatentActionManager on next tick
			// when UpdateOperation sees bCancelled and calls Response.DoneIf(true).
			// Do NOT call RemoveActionsForObject — that would cancel all pending latent actions
			// on CallbackTarget, not just this one.
			oldRequest->Cancel();
		}
```

**Step 3: Generate and inspect diff**

```bash
go run main.go gentest
go run main.go diffonly
```

Expected: every `*BPAdapter.cpp` with non-void operations loses the `RemoveActionsForObject` call. Check `TbSimpleSimpleInterfaceBPAdapter.cpp` `FuncBoolAsync` method.

**Step 4: Update golden master and commit**

```bash
go run main.go master
git add templates/module/Source/moduleapi/Private/Generated/api/bpadapter.cpp.tpl
git add goldenmaster/
git commit -m "fix(api): scope latent action cancellation to specific request only"
```

---

## Phase 2: Header Hygiene and Contract Clarity

### Task 4: Remove unused include from `bpadapter.h.tpl`

**Files:**
- Modify: `templates/module/Source/moduleapi/Public/module/Generated/api/bpadapter.h.tpl` (line 23)

**Step 1: Confirm the include is unused**

The generated class inherits from `UObject` and `I{Class}Interface`. It uses `TScriptInterface<>`. None of these require `GameInstanceSubsystem.h`. The include was likely a copy-paste artefact.

**Step 2: Remove the include**

Delete line 23:

```
#include "Subsystems/GameInstanceSubsystem.h"
```

**Step 3: Generate, diff, update master, commit**

```bash
go run main.go gentest
go run main.go diffonly
```

Expected: every `*BPAdapter.h` loses one include line.

```bash
go run main.go master
git add templates/module/Source/moduleapi/Public/module/Generated/api/bpadapter.h.tpl
git add goldenmaster/
git commit -m "fix(api): remove unused GameInstanceSubsystem include from BP adapter header"
```

---

### Task 5: Document C++-only intent of latent async overloads in `bpadapter.h.tpl`

**Files:**
- Modify: `templates/module/Source/moduleapi/Public/module/Generated/api/bpadapter.h.tpl` (around line 59)

**Step 1: Find the latent overload declarations**

In the template, the non-void operation block is:

```
{{- else }}
	void {{Camel .Name}}Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}}, {{end}}{{ueParams "" .Params}}) override;
	TFuture<{{ueReturn "" .Return}}> {{Camel .Name}}Async({{ueParams "" .Params}}) override;
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override;
```

**Step 2: Add a comment above the latent overload**

```
{{- else }}
	/** C++ only. Latent overload for async operations used by the latent action system.
	 *  Not exposed to Blueprint — Blueprint callers should use the sync {{Camel .Name}}() overload.
	 *  Adding BlueprintCallable here would create a circular call path (BP → adapter → BP). */
	void {{Camel .Name}}Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}}, {{end}}{{ueParams "" .Params}}) override;
	TFuture<{{ueReturn "" .Return}}> {{Camel .Name}}Async({{ueParams "" .Params}}) override;
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override;
```

**Step 3: Generate, diff, update master, commit**

```bash
go run main.go gentest
go run main.go diffonly
```

Expected: every `*BPAdapter.h` that has non-void operations gains the doc comment above the latent overloads.

```bash
go run main.go master
git add templates/module/Source/moduleapi/Public/module/Generated/api/bpadapter.h.tpl
git add goldenmaster/
git commit -m "docs(api): document c++-only intent of latent async overloads in bp adapter"
```

---

## Phase 3: Const-Correctness Comment

### Task 6: Annotate const getter dispatch in `bpadapter.cpp.tpl`

**Files:**
- Modify: `templates/module/Source/moduleapi/Private/Generated/api/bpadapter.cpp.tpl` (lines 105-113)

**Step 1: Find the getter block**

```
{{ueReturn "" .}} {{$adapter}}::Get{{Camel .Name}}() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return {{$bpinterface}}::Execute_Get{{Camel .Name}}(Obj);
	}
	return {{ueDefault "" .}};
}
```

**Step 2: Add explanation comment**

The `Execute_Get*` static functions go through UE's reflection machinery (`ProcessEvent`/`FFrame`), which writes to internal UObject bookkeeping state. This violates strict C++ `const` — `this` is logically const (no observable state change from the caller's perspective), but the underlying dispatch is not physically const. This is a well-known UE-ism with no clean fix short of changing the C++ interface to non-const.

```
{{ueReturn "" .}} {{$adapter}}::Get{{Camel .Name}}() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		// UE Blueprint dispatch (Execute_*) is not physically const — it writes to UObject
		// reflection bookkeeping internally. This is a known UE pattern; const here is a
		// logical-const contract with C++ callers, not a physical-const guarantee.
		return {{$bpinterface}}::Execute_Get{{Camel .Name}}(Obj);
	}
	return {{ueDefault "" .}};
}
```

**Step 3: Generate, diff, update master, commit**

```bash
go run main.go gentest
go run main.go diffonly
```

Expected: every `*BPAdapter.cpp` with properties gains the comment on each getter.

```bash
go run main.go master
git add templates/module/Source/moduleapi/Private/Generated/api/bpadapter.cpp.tpl
git add goldenmaster/
git commit -m "docs(api): document ue const-dispatch caveat in bp adapter property getters"
```

---

## Phase 4: Lifecycle Hardening (New Findings)

### Task 7: Validate backing object in `Initialize()` in `bpadapter.cpp.tpl`

**Files:**
- Modify: `templates/module/Source/moduleapi/Private/Generated/api/bpadapter.cpp.tpl` (lines 31-34)

**Step 1: Find the Initialize function**

```
void {{$adapter}}::Initialize(TScriptInterface<{{ $bpinterface }}> InTarget)
{
	Target = InTarget;
}
```

**Step 2: Add interface validation**

If a caller passes an object that does not implement the BP interface, every subsequent `Execute_*` call will silently fail. An `ensureMsgf` surfaces this early in development.

```
void {{$adapter}}::Initialize(TScriptInterface<{{ $bpinterface }}> InTarget)
{
	ensureMsgf(InTarget.GetObject() == nullptr || InTarget.GetObject()->Implements<U{{$Class}}BPInterface>(),
		TEXT("{{$adapter}}::Initialize: InTarget does not implement {{$bpinterface}}. All BP calls will be silently skipped."));
	Target = InTarget;
}
```

Note: `ensureMsgf` fires in Debug/Development builds and is compiled out in Shipping — appropriate for a developer-facing contract check.

**Step 3: Generate, diff, update master, commit**

```bash
go run main.go gentest
go run main.go diffonly
```

Expected: every `*BPAdapter.cpp` `Initialize()` gains the ensure check.

```bash
go run main.go master
git add templates/module/Source/moduleapi/Private/Generated/api/bpadapter.cpp.tpl
git add goldenmaster/
git commit -m "fix(api): validate bp interface implementation in adapter initialize"
```

---

## Verification

### Step 1: Template diff (fast, no UE needed)

After all tasks, confirm the golden master is in sync with the templates:

```bash
go run main.go diff
```

Expected: no differences reported.

Check formatting:

```bash
go run main.go teststyle
```

### Step 2: C++ compilation (requires UE installation)

`buildPlugins.sh` compiles all 11 plugins via UE's `RunUAT BuildPlugin`. Requires `RunUAT.sh` to be on `PATH`. UE is installed at `/home/wolfgang.bremer/ws/ue/Linux_Unreal_Engine_5.6.0/Engine/Build/BatchFiles/` — add it to PATH before running:

```bash
export PATH="/home/wolfgang.bremer/ws/ue/Linux_Unreal_Engine_5.6.0/Engine/Build/BatchFiles:$PATH"
cd goldenmaster/Plugins
./buildPlugins.sh
```

Expected: each plugin builds cleanly. On failure the script exits early with a non-zero code and prints which plugin failed. Fix the template change causing the compile error, re-run `go run main.go master`, and retry.

### Step 3: Automation tests (requires UE installation + blank project template)

`buildTestPlugins.sh` copies plugins into a blank UE project, builds it, and runs all automation tests matching `.Impl.+.OLink.+.MsgBus.`. Results land in `goldenmaster/Plugins/index.json`.

```bash
export PATH="/home/wolfgang.bremer/ws/ue/Linux_Unreal_Engine_5.6.0/Engine/Build/BatchFiles:$PATH"
cd goldenmaster/Plugins
./buildTestPlugins.sh
```

Expected:
- Script exits 0
- `index.json` exists and contains `"failed": 0`

If `index.json` is missing, the test runner could not start — check the UE installation path and blank project template location (`$UE_path/../Templates/TP_Blank`).

---

**Note:** Steps 2 and 3 are the definitive verification. The template diff (Step 1) catches regressions in the generation pipeline; the build scripts confirm the generated C++ actually compiles and passes tests. Run all three after the final `go run main.go master`.

---

## Not in Scope

- **`UE::Tasks` migration** (MEDIUM): Deferred — once the threading model is settled on game-thread dispatch, the difference between `Async(TaskGraphMainThread)` and `UE::Tasks` is marginal for this use case. Revisit when UE5.4+ becomes the minimum target.
- **`FObjectInitializer` constructor** (LOW): No current subclassing use case. Add when a concrete need arises.
- **`WITH_EDITORONLY_DATA` guard on `ExposeOnSpawn`** (LOW): Cooker strips this metadata anyway; not worth the template noise.
- **`RemoveActionsForObject` targeted API** (MEDIUM): Task 3 removes the call entirely; a targeted UUID-based removal API is not consistently available across UE4.27–UE5.x and is not needed given the Cancel() self-cleanup path.
