# MsgBus Promise Safety Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Fix the MsgBus client's broken promise pattern (SA-05) and add promise cleanup on disconnect (SA-06).

**Architecture:** The current code stores `&stack_local_TPromise` as `void*` — use-after-scope UB. The fix uses type-erased `TFunction<void(const void*)>` lambdas that capture a `TSharedPtr<TPromise<T>>`. The map stores these fulfillers; `FulfillPromise` invokes with the real value, `CancelAllPromises` invokes with `nullptr` (triggering default-value `SetValue`). This avoids illegal casts between unrelated `TPromise<T>` types.

**Tech Stack:** Unreal Engine C++ (`TSharedPtr`, `TPromise`, `TFuture`, `TFunction`, `TMap`), Go text templates.

**CAUTION:** Operations that currently block indefinitely on service crash will return default values on disconnect. The existing pattern is already UB. Release note: "MsgBus operations return default values on service disconnect."

---

## Task 1: Update header and implementation with type-erased promise map

**Files:**
- Modify: `templates/module/Source/modulemsgbus/Public/Generated/MsgBus/msgbusclient.h.tpl:163-173`
- Modify: `templates/module/Source/modulemsgbus/Private/Generated/MsgBus/msgbusclient.cpp.tpl:394-512`

### Step 1: Replace map type and signatures in header

Find (lines 163-173):
```
{{- if len .Interface.Operations }}

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
{{- end }}
```

Replace with:
```
{{- if len .Interface.Operations }}

	TMap<FGuid, TFunction<void(const void*)>> ReplyPromiseFulfillers;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	TSharedPtr<TPromise<ResultType>> StorePromise(const FGuid& Id);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);

	void CancelAllPromises();
{{- end }}
```

### Step 2: Replace implementations in cpp template

Find the `StorePromise`/`FulfillPromise` implementations and explicit instantiations (lines 470-512). Replace entirely with:

```
{{- if len .Interface.Operations }}

template <typename ResultType>
TSharedPtr<TPromise<ResultType>> U{{$Iface}}MsgBusClient::StorePromise(const FGuid& Id)
{
	auto Promise = MakeShared<TPromise<ResultType>>();
	FScopeLock Lock(&ReplyPromisesMapCS);
	ReplyPromiseFulfillers.Add(Id, [Promise](const void* ValuePtr)
		{
		if (ValuePtr)
		{
			Promise->SetValue(*static_cast<const ResultType*>(ValuePtr));
		}
		else
		{
			Promise->SetValue(ResultType{});
		}
	});
	return Promise;
}

template <typename ResultType>
bool U{{$Iface}}MsgBusClient::FulfillPromise(const FGuid& Id, const ResultType& Value)
{
	TFunction<void(const void*)> Fulfiller;

	{
		FScopeLock Lock(&ReplyPromisesMapCS);
		if (auto* Found = ReplyPromiseFulfillers.Find(Id))
		{
			Fulfiller = MoveTemp(*Found);
			ReplyPromiseFulfillers.Remove(Id);
		}
	}

	if (Fulfiller)
	{
		Fulfiller(&Value);
		return true;
	}
	return false;
}

void U{{$Iface}}MsgBusClient::CancelAllPromises()
{
	TArray<TFunction<void(const void*)>> PendingFulfillers;
	{
		FScopeLock Lock(&ReplyPromisesMapCS);
		ReplyPromiseFulfillers.GenerateValueArray(PendingFulfillers);
		ReplyPromiseFulfillers.Empty();
	}
	for (auto& Fulfiller : PendingFulfillers)
	{
		Fulfiller(nullptr);
	}
}
{{- $retTypes := getEmptyStringList}}
{{- range .Interface.Operations }}
{{- if not .Return.IsVoid }}
{{- $retType :=  ueReturn "" .Return }}
{{- $retTypes = (appendList $retTypes $retType) }}
{{- end }}
{{- end }}
{{- $retTypes = unique $retTypes }}
{{- if len $retTypes }}{{- nl }}{{- end }}
{{- range $retTypes }}
template TSharedPtr<TPromise<{{ .}}>> U{{$Iface}}MsgBusClient::StorePromise<{{ .}}>(const FGuid& Id);
template bool U{{$Iface}}MsgBusClient::FulfillPromise<{{ .}}>(const FGuid& Id, const {{ .}}& Value);
{{- end }}
{{- end }}
```

Key design:
- `StorePromise` creates a `TSharedPtr<TPromise<T>>`, stores a type-erased fulfiller lambda (capturing the promise), returns the promise
- `FulfillPromise` moves the fulfiller out of the map (releasing the lock), then invokes with the real value
- `CancelAllPromises` copies all fulfillers out, clears map, releases lock, then invokes each with `nullptr` — which triggers `SetValue(ResultType{})`. Lock is NOT held during `SetValue` to prevent deadlock

### Step 3: Update operation call sites

Find the operation pattern (lines 394-410):
```
	{{- if not .Return.IsVoid }}
	TPromise<{{$returnVal}}> Promise;
	StorePromise(msg->ResponseId, Promise);
	{{- end }}

	...

	return Promise.GetFuture().Get();
```

Replace with:
```
	{{- if not .Return.IsVoid }}
	auto Promise = StorePromise<{{$returnVal}}>(msg->ResponseId);
	{{- end }}

	...

	return Promise->GetFuture().Get();
```

Changes: `TPromise<T> Promise` → `auto Promise = StorePromise<T>(id)`, `Promise.GetFuture()` → `Promise->GetFuture()`.

### Step 4: Generate and verify

```bash
go run main.go master && go run main.go diff
```

### Step 5: Commit

```bash
git add templates/module/Source/modulemsgbus/ goldenmaster/
git commit -m "$(cat <<'EOF'
fix(msgbus): use type-erased promise fulfillers

Replace stack-local TPromise stored as void* with
heap-allocated TSharedPtr captured in type-erased
TFunction fulfillers. Prevents dangling pointer and
enables safe cancellation on disconnect.
EOF
)"
```

---

## Task 2: Add promise cleanup on all disconnect paths (SA-06)

**Files:**
- Modify: `templates/module/Source/modulemsgbus/Private/Generated/MsgBus/msgbusclient.cpp.tpl`

### Step 1: Add `CancelAllPromises()` in `_Disconnect()`

Find (around line 132):
```
	{{$Iface}}MsgBusEndpoint.Reset();
	ServiceAddress.Invalidate();
```

Add before it:
```
	CancelAllPromises();
	{{$Iface}}MsgBusEndpoint.Reset();
	ServiceAddress.Invalidate();
```

### Step 2: Add `CancelAllPromises()` in `OnServiceClosedConnection()`

Find (around line 302):
```
	_LastHbTimestamp = 0.0;
	ServiceAddress.Invalidate();
```

Add before it:
```
	CancelAllPromises();
	_LastHbTimestamp = 0.0;
	ServiceAddress.Invalidate();
```

### Step 3: Add `CancelAllPromises()` in heartbeat timeout path

Find the heartbeat timeout block in `_OnHeartbeat()` (around line 220-226):
```
		if (DeltaMS > 2 * _HeartbeatIntervalMS)
		{
			// service seems to be dead or not responding - reset connection
			ServiceAddress.Invalidate();
			_LastHbTimestamp = 0.0;
			_ConnectionStatusChanged.Broadcast(false);
		}
```

Add `CancelAllPromises()`:
```
		if (DeltaMS > 2 * _HeartbeatIntervalMS)
		{
			// service seems to be dead or not responding - reset connection
			CancelAllPromises();
			ServiceAddress.Invalidate();
			_LastHbTimestamp = 0.0;
			_ConnectionStatusChanged.Broadcast(false);
		}
```

### Step 4: Generate and verify

```bash
go run main.go master && go run main.go diff
```

### Step 5: Commit

```bash
git add templates/module/Source/modulemsgbus/ goldenmaster/
git commit -m "$(cat <<'EOF'
fix(msgbus): cancel promises on disconnect

Fulfill pending promises with default values on all
disconnect paths: explicit disconnect, service close,
and heartbeat timeout. Prevents infinite thread hang.
EOF
)"
```

---

## Verification

```bash
go run main.go diff
go run main.go teststyle
```

With UE:
```bash
export PATH="/home/wolfgang.bremer/ws/ue/Linux_Unreal_Engine_5.6.0/Engine/Build/BatchFiles:$PATH"
bash goldenmaster/Plugins/buildPlugins.sh
bash goldenmaster/Plugins/buildTestPlugins.sh
```

Expected: 1,394 tests pass. MsgBus tests exercise the promise pattern through actual send/receive cycles.

---

## Not in Scope

- **Per-operation timeout** — `CancelAllPromises` handles service-crash case. A `TFuture::WaitFor()` polling loop is a larger change. Defer to Phase 5.
- **SA-10/SA-12/SA-24** (game-thread marshaling) — Phase 5, separate plan.
