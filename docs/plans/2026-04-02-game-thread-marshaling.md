# Game-Thread Marshaling Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Move all publisher subscriber callbacks (C++ and BP) and multicast delegate broadcasts to the game thread, establishing a uniform threading contract: "all publisher notifications fire on the game thread."

**Architecture:** The publisher already has game-thread marshaling for BP subscribers via `IsInGameThread()` + `AsyncTask`. The fix moves the C++ subscriber dispatch and multicast delegate broadcasts into the same game-thread lambda. The `IsInGameThread()` fast path means zero overhead when already on game thread (stubs, MsgBus). Only OLink (calling from WebSocket/IO thread) actually enqueues an `AsyncTask`.

**Tech Stack:** Unreal Engine C++ (`AsyncTask`, `ENamedThreads::GameThread`), Go text templates.

**CAUTION:** This changes the thread on which C++ subscribers receive callbacks. Previously they fired on the caller's thread; now they always fire on the game thread. This is a correctness improvement (prevents race conditions) but changes callback timing. Release note: "Property/signal callbacks now delivered on game thread."

---

## Task 1: Move C++ subscriber and delegate dispatch into game-thread lambda

**Files:**
- Modify: `templates/module/Source/moduleapi/Private/Generated/api/publisher.cpp.tpl`

### Step 1: Understand the current structure

The publisher has two broadcast methods, one for signals and one for property changes. Both follow the same pattern:

```
1. Copy subscriber lists under read locks
2. Fire C++ multicast delegate (On*Signal / On*Changed) — CALLER'S THREAD
3. Iterate C++ subscribers, call each — CALLER'S THREAD
4. Build a lambda that:
   a. Fires BP multicast delegate (On*SignalBP / On*ChangedBP)
   b. Iterates BP subscribers, calls each
   c. CleanUpSubscribers()
5. If IsInGameThread(): invoke lambda directly
6. Else: AsyncTask(GameThread, lambda)
```

The fix merges steps 2-3 into step 4, so ALL dispatch happens inside the game-thread lambda.

### Step 2: Modify the SIGNAL broadcast method

Find the signal broadcast method pattern (around lines 19-75). The structure to change is:

```cpp
	On{{Camel .Name}}Signal.Broadcast({{ueVars "" .Params}});
	for (const TWeakInterfacePtr<I{{$Class}}SubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (Subscriber.IsValid())
		{
			if (I{{$Class}}SubscriberInterface* Iface = Subscriber.Get())
			{
				Iface->On{{Camel .Name}}Signal({{ueVars "" .Params}});
			}
		}
	}

	auto BroadCastOnGameThread = [WeakPtr = TWeakObjectPtr<U{{$Class}}Publisher>(this), BPSubscribersCopy{{- if (len .Params) }}, {{ end }}{{ueVars "" .Params}}]()
	{
		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->On{{Camel .Name}}SignalBP.Broadcast({{ueVars "" .Params}});
		}

		for (const TScriptInterface<I{{$Class}}BPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				I{{$Class}}BPSubscriberInterface::Execute_On{{Camel .Name}}Signal(Obj{{- if (len .Params) }}, {{ end }}{{ueVars "" .Params}});
			}
		}

		if (WeakPtr.IsValid())
		{
			WeakPtr.Get()->CleanUpSubscribers();
		}
	};

	if (IsInGameThread())
	{
		BroadCastOnGameThread();
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, MoveTemp(BroadCastOnGameThread));
	}
```

Replace with (move C++ dispatch + multicast delegate INSIDE the lambda):

```cpp
	auto BroadcastAll = [WeakPtr = TWeakObjectPtr<U{{$Class}}Publisher>(this), SubscribersCopy, BPSubscribersCopy{{- if (len .Params) }}, {{ end }}{{ueVars "" .Params}}]()
	{
		if (!WeakPtr.IsValid())
		{
			return;
		}

		WeakPtr.Get()->On{{Camel .Name}}Signal.Broadcast({{ueVars "" .Params}});
		for (const TWeakInterfacePtr<I{{$Class}}SubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (Subscriber.IsValid())
			{
				if (I{{$Class}}SubscriberInterface* Iface = Subscriber.Get())
				{
					Iface->On{{Camel .Name}}Signal({{ueVars "" .Params}});
				}
			}
		}

		WeakPtr.Get()->On{{Camel .Name}}SignalBP.Broadcast({{ueVars "" .Params}});
		for (const TScriptInterface<I{{$Class}}BPSubscriberInterface>& Subscriber : BPSubscribersCopy)
		{
			UObject* Obj = Subscriber.GetObject();
			if (IsValid(Obj))
			{
				I{{$Class}}BPSubscriberInterface::Execute_On{{Camel .Name}}Signal(Obj{{- if (len .Params) }}, {{ end }}{{ueVars "" .Params}});
			}
		}

		WeakPtr.Get()->CleanUpSubscribers();
	};

	if (IsInGameThread())
	{
		BroadcastAll();
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, MoveTemp(BroadcastAll));
	}
```

Key changes:
- `SubscribersCopy` (C++ list) is now captured by the lambda
- C++ multicast delegate `On*Signal.Broadcast()` moved inside lambda, accessed via `WeakPtr.Get()->`
- C++ subscriber iteration moved inside lambda
- Single `WeakPtr.IsValid()` guard at the top of the lambda
- Removed the duplicate `WeakPtr.IsValid()` checks (one at top covers all)
- Lambda renamed from `BroadCastOnGameThread` to `BroadcastAll`

### Step 3: Apply the same change to the PROPERTY CHANGED broadcast method

The property-changed broadcast (around lines 80-134) follows the identical pattern. Apply the same structural change: move C++ multicast delegate + C++ subscriber iteration into the lambda, capture `SubscribersCopy`.

### Step 4: Generate and verify

```bash
go run main.go master && go run main.go diff
```

### Step 5: Spot-check golden master

Open `goldenmaster/Plugins/TbSimple/Source/TbSimpleAPI/Private/Generated/api/TbSimpleSimpleInterfacePublisher.cpp`. Verify:
- No C++ subscriber calls happen outside the lambda
- The `BroadcastAll` lambda captures both `SubscribersCopy` and `BPSubscribersCopy`
- `IsInGameThread()` check + `AsyncTask` pattern is preserved

### Step 6: Run style check

```bash
go run main.go teststyle
```

### Step 7: Commit

```bash
git add templates/module/Source/moduleapi/Private/Generated/api/publisher.cpp.tpl goldenmaster/
git commit -m "$(cat <<'EOF'
fix(api): dispatch all callbacks on game thread

Move C++ subscriber dispatch and multicast delegate
broadcasts into the game-thread lambda alongside BP
subscribers. All publisher notifications now fire on
the game thread regardless of which backend triggers
them. IsInGameThread fast path avoids overhead when
already on game thread.
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

Expected: 1,394 tests pass. The OLink and MsgBus tests exercise the full callback path through the publisher.

---

## Not in Scope

- **OLink `applyState`/`emitSignal` changes** — not needed for this plan. The publisher now marshals all subscriber dispatch to the game thread. Note: OLink property writes still happen on the IO thread (`applyState` line 305), creating a pre-existing data race with game-thread reads via `Get*()`. This race exists today and is not introduced or worsened by this change. A full fix would require marshaling the entire `applyState` body to the game thread, which is a follow-up item.
- **MsgBus changes** — already on game thread, publisher fast-paths.
- **Per-operation timeout** — separate concern, separate plan.
