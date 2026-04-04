# OLink Callback Safety Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Fix the OLink callback thread-safety race (SA-03) and raw `this` capture in client sink callbacks (SA-23) to prevent use-after-destruction during WebSocket teardown.

**Architecture:** Two files need changes: `FOLinkSink` (raw runtime file in `templates/ApiGear/`) gets a `FCriticalSection` protecting all callback access. The OLink client template (`olinkclient.cpp.tpl`) replaces raw `this` captures with `TWeakObjectPtr`. Both are `raw: true` or generated — changes need `go run main.go master` + `diff` to verify.

**Tech Stack:** Unreal Engine C++ (`FCriticalSection`, `FScopeLock`, `TWeakObjectPtr`), OLink protocol library.

**CAUTION:** Adding `FCriticalSection` to `OLinkSink.h` is an ABI change (class size changes). Not a source break — all consumers recompile from source. Release note: "OLink teardown: stale callbacks safely skipped."

---

## Task 1: Add FCriticalSection to FOLinkSink (SA-03)

**Files:**
- Modify: `templates/ApiGear/Source/ApiGearOLink/Public/OLinkSink.h`
- Modify: `templates/ApiGear/Source/ApiGearOLink/Private/OLinkSink.cpp`

**Step 1: Add mutex member to header**

In `OLinkSink.h`, add to the private section (after line 61, before the closing `};`):

```cpp
	mutable FCriticalSection CallbackMutex;
```

Also add `#include "HAL/CriticalSection.h"` after line 3 (`#include "Templates/Function.h"`).

**Step 2: Wrap all callback invocations in OLinkSink.cpp with FScopeLock**

For each `olink*` method that invokes a callback, acquire the lock before checking and calling:

Use **copy-and-invoke** pattern: copy the `TFunction` under the lock, release the lock, then invoke. This prevents deadlock if a callback triggers a sink reset on the same thread.

`olinkOnSignal` (lines 16-23):
```cpp
void FOLinkSink::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
	const std::string MemberName = ApiGear::ObjectLink::Name::getMemberName(signalId);
	FSignalEmittedFunc LocalFunc;
	{
		FScopeLock Lock(&CallbackMutex);
		LocalFunc = SignalEmittedFunc;
	}
	if (LocalFunc)
	{
		LocalFunc(MemberName, args);
	}
}
```

`olinkOnPropertyChanged` (lines 25-32):
```cpp
void FOLinkSink::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
	const std::string MemberName = ApiGear::ObjectLink::Name::getMemberName(propertyId);
	FPropertyChangedFunc LocalFunc;
	{
		FScopeLock Lock(&CallbackMutex);
		LocalFunc = PropertyChangedFunc;
	}
	if (LocalFunc)
	{
		LocalFunc({{MemberName, value}});
	}
}
```

`olinkOnInit` (lines 34-46):
```cpp
void FOLinkSink::olinkOnInit(const std::string& objectId, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode* node)
{
	m_node = node;
	FInitializedFromSourceCallback LocalInitFunc;
	FPropertyChangedFunc LocalPropFunc;
	{
		FScopeLock Lock(&CallbackMutex);
		LocalInitFunc = OnInitCallback;
		LocalPropFunc = PropertyChangedFunc;
	}
	if (LocalInitFunc)
	{
		LocalInitFunc();
	}
	if (LocalPropFunc)
	{
		LocalPropFunc(props);
	}
}
```

`olinkOnRelease` (lines 48-55):
```cpp
void FOLinkSink::olinkOnRelease()
{
	FSourceConnectionReleasedCallback LocalFunc;
	{
		FScopeLock Lock(&CallbackMutex);
		LocalFunc = OnReleaseCallback;
	}
	if (LocalFunc)
	{
		LocalFunc();
	}
	m_node = nullptr;
}
```

**Step 3: Wrap all set/reset methods with FScopeLock**

Each setter and resetter (lines 57-96) needs the lock:

```cpp
void FOLinkSink::setOnPropertyChangedCallback(FPropertyChangedFunc func)
{
	FScopeLock Lock(&CallbackMutex);
	PropertyChangedFunc = func;
}

void FOLinkSink::resetOnPropertyChangedCallback()
{
	FScopeLock Lock(&CallbackMutex);
	PropertyChangedFunc = nullptr;
}
```

Apply the same pattern to all 8 set/reset methods (4 setters + 4 resetters).

Add `#include "HAL/CriticalSection.h"` at the top of `OLinkSink.cpp` if not already included transitively.

**Step 4: Generate and verify**

```bash
go run main.go master && go run main.go diff
```

**Step 5: Commit**

```bash
git add templates/ApiGear/Source/ApiGearOLink/ goldenmaster/
git commit -m "$(cat <<'EOF'
fix(olink): protect sink callbacks with mutex

Add FCriticalSection to FOLinkSink protecting all
callback set/reset/invoke paths. Prevents race
between WebSocket thread and game-thread teardown.
EOF
)"
```

---

## Task 2: Replace raw `this` with TWeakObjectPtr in OLink client callbacks (SA-23)

**Files:**
- Modify: `templates/module/Source/moduleolink/Private/Generated/OLink/olinkclient.cpp.tpl:62-83`

**Step 1: Replace the four sink callback captures**

Find the callback setup block in `Initialize` (lines 62-83). Replace all four raw `this` captures with `TWeakObjectPtr`:

```
	TWeakObjectPtr<{{$Class}}> weak(this);
	m_sink->setOnInitCallback([weak]()
		{
		if (auto* self = weak.Get())
		{
			self->_SubscriptionStatusChanged.Broadcast(true);
			self->_SubscriptionStatusChangedBP.Broadcast(true);
		}
	});
	m_sink->setOnReleaseCallback([weak]()
		{
		if (auto* self = weak.Get())
		{
			self->_SubscriptionStatusChanged.Broadcast(false);
			self->_SubscriptionStatusChangedBP.Broadcast(false);
		}
	});

	FOLinkSink::FPropertyChangedFunc PropertyChangedFunc = [weak](const nlohmann::json& props)
	{
		if (auto* self = weak.Get())
		{
			self->applyState(props);
		}
	};
	m_sink->setOnPropertyChangedCallback(PropertyChangedFunc);

	FOLinkSink::FSignalEmittedFunc SignalEmittedFunc = [weak](const std::string& signalName, const nlohmann::json& args)
	{
		if (auto* self = weak.Get())
		{
			self->emitSignal(signalName, args);
		}
	};
	m_sink->setOnSignalEmittedCallback(SignalEmittedFunc);
```

Key: one `TWeakObjectPtr<{{$Class}}>` declaration shared by all four lambdas.

**Step 1b: Fix no-op lambda raw `this` capture**

Search the template for `invokeRemote` callbacks that capture `[this]` with empty bodies (around line 212). Change `[this]` to `[]` since the body is a no-op:

```
// Before: [this](ApiGear::ObjectLink::InvokeReplyArg arg) {}
// After:  [](ApiGear::ObjectLink::InvokeReplyArg arg) {}
```

**Step 2: Generate and verify**

```bash
go run main.go master && go run main.go diff
```

**Step 3: Spot-check golden master**

Open `goldenmaster/Plugins/TbSimple/Source/TbSimpleOLink/Private/Generated/OLink/TbSimpleSimpleInterfaceOLinkClient.cpp`. Verify:
- `TWeakObjectPtr<UTbSimpleSimpleInterfaceOLinkClient> weak(this);` near line 62
- All four callbacks capture `weak` by value (not `this`)
- Each callback does `if (auto* self = weak.Get())` before using `self->`

**Step 4: Commit**

```bash
git add templates/module/Source/moduleolink/ goldenmaster/
git commit -m "$(cat <<'EOF'
fix(olink): use weak ptr in sink callbacks

Replace raw this captures with TWeakObjectPtr in
OLink client sink callbacks. Prevents use-after-
destruction when WebSocket messages arrive during
UObject teardown.
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

---

## Not in Scope

- **SA-10/SA-24** (game-thread marshaling) — Phase 5, separate plan
- **SA-16** (partial init on null connection) — low priority, callbacks now safe via weak ptr
