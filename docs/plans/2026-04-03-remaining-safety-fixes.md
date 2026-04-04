# Remaining Safety Fixes Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Fix SA-25 (ConnectedClientsTimestamps map race in MsgBus adapter) — the last remaining fixable finding.

**Architecture:** Add `FCriticalSection` to the MsgBus adapter header and wrap all map access with copy-under-lock pattern. Critical constraint: never hold the lock during `Send<>()`, `Broadcast()`, or other blocking calls.

**Tech Stack:** Unreal Engine C++ (`FCriticalSection`, `FScopeLock`), Go text templates.

---

## Triage: Final disposition of all remaining findings

| ID | Severity | Decision | Reason |
|----|----------|----------|--------|
| SA-25 | MEDIUM | **Fix** | Map accessed from transport and ticker threads without sync |
| SA-15 | MEDIUM | **Skip** | Project convention: no explanatory inline comments. Documented in review doc. |
| SA-20 | LOW | **Skip** | Already handled — switch/default pattern returns false for out-of-range values |
| SA-11 | LOW | **Skip** | Configurable via settings, not a code defect |
| SA-16 | MEDIUM | **Skip** | Mitigated by TWeakObjectPtr (Phase 3) |
| SA-19 | LOW | **Skip** | Safe for generated code |
| SA-21 | LOW | **Skip** | Redundant sends only |
| SA-22 | LOW | **Skip** | Intentional leak |

---

## Task 1: Add FCriticalSection to ConnectedClientsTimestamps (SA-25)

**Files:**
- Modify: `templates/module/Source/modulemsgbus/Public/Generated/MsgBus/msgbusadapter.h.tpl:129`
- Modify: `templates/module/Source/modulemsgbus/Private/Generated/MsgBus/msgbusadapter.cpp.tpl`

### Step 1: Add mutex to header

After line 129 (`TMap<FMessageAddress, double> ConnectedClientsTimestamps;`), add:
```
	FCriticalSection ConnectedClientsTimestampsCS;
```

### Step 2: Wrap map access in cpp template — copy-under-lock pattern

The rule: lock ONLY around map read/write, unlock BEFORE any Send/Broadcast/delegate call. Here are ALL access sites:

**`HandleClientConnectionRequest` (~line 177):**
The `Contains` check and `Add` are separated by a `Send<>()`. Restructure:
```cpp
void HandleClientConnectionRequest(...)
{
	{
		FScopeLock Lock(&ConnectedClientsTimestampsCS);
		if (ConnectedClientsTimestamps.Contains(Context->GetSender()))
		{
			return;
		}
	}
	// ... BackendService null check, build msg, Send<InitMessage> ...

	_OnClientConnected.Broadcast(ClientAddress.ToString());
	{
		FScopeLock Lock(&ConnectedClientsTimestampsCS);
		ConnectedClientsTimestamps.Add(ClientAddress, FPlatformTime::Seconds());
	}
	_UpdateClientsConnected();
}
```

**`OnPing` (~line 252):**
```cpp
void OnPing(...)
{
	auto msg = new FPongMessage();
	msg->Timestamp = InMessage.Timestamp;

	{
		FScopeLock Lock(&ConnectedClientsTimestampsCS);
		ConnectedClientsTimestamps.Add(Context->GetSender(), FPlatformTime::Seconds());
	}

	// Send<PongMessage> is OUTSIDE the lock
	if (MsgBusEndpoint.IsValid()) { ... Send ... }
}
```

**`OnClientDisconnected` (~line 264):**
```cpp
void OnClientDisconnected(...)
{
	{
		FScopeLock Lock(&ConnectedClientsTimestampsCS);
		if (!ConnectedClientsTimestamps.Contains(Context->GetSender()))
		{
			return;
		}
		ConnectedClientsTimestamps.Remove(Context->GetSender());
	}
	// Broadcast OUTSIDE the lock
	_OnClientDisconnected.Broadcast(Context->GetSender().ToString());
	_UpdateClientsConnected();
}
```

**`_CheckClientTimeouts` (~line 282):**
Iterate under lock to collect timed-out clients, unlock, then broadcast + remove:
```cpp
void _CheckClientTimeouts()
{
	const double CurrentTime = FPlatformTime::Seconds();
	TArray<FMessageAddress> TimedOutClients;

	{
		FScopeLock Lock(&ConnectedClientsTimestampsCS);
		for (const auto& ClientPair : ConnectedClientsTimestamps)
		{
			const double DeltaMS = (CurrentTime - ClientPair.Value) * 1000.0;
			if (DeltaMS > 2 * _HeartbeatIntervalMS)
			{
				TimedOutClients.Add(ClientPair.Key);
			}
		}
		for (const auto& ClientAddress : TimedOutClients)
		{
			ConnectedClientsTimestamps.Remove(ClientAddress);
		}
	}

	// Broadcasts OUTSIDE the lock
	for (const auto& ClientAddress : TimedOutClients)
	{
		_OnClientTimeout.Broadcast(ClientAddress.ToString());
	}
	_UpdateClientsConnected();
}
```

**`_StopListening` (~line 106):**
Copy keys under lock, unlock, then Send:
```cpp
void _StopListening()
{
	// ... remove ticker ...

	auto msg = new FServiceDisconnectMessage();

	TArray<FMessageAddress> ConnectedClients;
	{
		FScopeLock Lock(&ConnectedClientsTimestampsCS);
		ConnectedClientsTimestamps.GetKeys(ConnectedClients);
		ConnectedClientsTimestamps.Empty();
	}

	// Send OUTSIDE the lock
	if (MsgBusEndpoint.IsValid() && ConnectedClients.Num() > 0)
	{
		MsgBusEndpoint->Send<FServiceDisconnectMessage>(..., ConnectedClients, ...);
	}
	MsgBusEndpoint.Reset();
	_UpdateClientsConnected();
}
```

**`_UpdateClientsConnected` (~line 306):**
```cpp
void _UpdateClientsConnected()
{
	int32 NumberOfClients;
	{
		FScopeLock Lock(&ConnectedClientsTimestampsCS);
		NumberOfClients = ConnectedClientsTimestamps.Num();
	}
	_ClientsConnected = NumberOfClients;
	// Broadcast OUTSIDE the lock
	_OnClientsConnectedCountChanged.Broadcast(_ClientsConnected);
}
```

**Signal handlers (`On{Signal}Signal`, generated by `range .Interface.Signals`):**
```cpp
void On{Signal}Signal(...)
{
	TArray<FMessageAddress> ConnectedClients;
	{
		FScopeLock Lock(&ConnectedClientsTimestampsCS);
		ConnectedClientsTimestamps.GetKeys(ConnectedClients);
	}

	// Build msg, Send OUTSIDE the lock
	auto msg = new FSignalMessage();
	...
	if (MsgBusEndpoint.IsValid() && ConnectedClients.Num() > 0) { ... Send ... }
}
```

**Property changed handlers (`On{Property}Changed`, generated by `range .Interface.Properties`):**
Same pattern as signal handlers — lock around `GetKeys`, unlock before `Send`.

### Step 3: Generate and verify

```bash
go run main.go master && go run main.go diff
```

### Step 4: Commit

```bash
git add templates/module/Source/modulemsgbus/ goldenmaster/
git commit -m "fix(msgbus): synchronize client timestamps map"
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

## After This

All 25 findings from the safety analysis are resolved:
- 17 fixed in code (PRs #178, #179, and this PR)
- 8 explicitly skipped with documented rationale
