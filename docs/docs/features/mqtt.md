---
sidebar_position: 5
sidebar_label: "MQTT"
title: "MQTT Feature: Pub/Sub Connectivity for Unreal Engine"
description: "Connect Unreal Engine to any MQTT broker. Publish and subscribe to topics for IoT, telemetry, and many-to-many communication with non-Unreal peers."
keywords: [mqtt, pub/sub, iot, paho, broker, unreal engine networking, apigear]
---

import CodeBlock from '@theme/CodeBlock';
import helloWorldModuleComponent from '!!raw-loader!./data/helloworld.module.yaml';

# MQTT

The `mqtt` feature provides client and adapter implementations on top of the [MQTT](https://mqtt.org/) pub/sub protocol. This enables:

- **Broker-mediated connections**: Connect Unreal applications through any MQTT-compliant broker (Mosquitto, EMQX, HiveMQ, AWS IoT Core, etc.)
- **Cross-platform fan-out**: Communicate with Python services, JavaScript dashboards, mobile apps, and embedded devices that all speak MQTT
- **IoT and telemetry**: Stream data into and out of Unreal alongside the broader IoT ecosystem
- **Many-to-many communication**: One adapter can serve many clients, and any client can subscribe to topics from many adapters

Use an _MQTT client_ instead of your local implementation to consume a remote service over MQTT. Use an _MQTT adapter_ to expose your local implementation to MQTT subscribers.

:::note
Unlike OLink (point-to-point WebSocket) and Message Bus (intra-Unreal IPC), MQTT requires an external broker. The broker decouples publishers from subscribers and handles message routing, retention, and last-will semantics.
:::

## When to use MQTT vs OLink vs Message Bus

| Feature | MQTT | OLink | Message Bus |
|---------|------|-------|-------------|
| Protocol | MQTT 5 over TCP / TLS | WebSocket (ObjectLink) | Unreal's UDP Message Bus |
| Topology | Pub/sub via broker | Direct request/response | Local UDP discovery |
| Best for | IoT, telemetry, many-to-many | Tight Unreal-to-service link | Unreal-to-Unreal IPC |
| Setup | Requires broker URL | Requires server URL | Zero configuration on localhost |
| Network | Any network with broker reachable | Any network | Local network / same machine |
| Non-Unreal peers | Yes (Python, JS, mobile, embedded) | Yes (Qt, C++, simulation) | No |
| Retained state | Yes (broker retains last property) | No (live link only) | No (heartbeat-based) |
| ApiGear Simulation | No | Yes | No |

:::tip
Use **MQTT** when fanning state out to many heterogeneous subscribers or integrating with an existing IoT topology.
Use **OLink** for direct Unreal-to-service or simulation connections.
Use **Message Bus** for IPC between Unreal applications.
:::

## ApiGear MQTT Protocol

The generated code maps interface concepts to MQTT topics following the shared ApiGear MQTT mapping. The topic structure, JSON payloads, MQTT 5 correlation (`CorrelationData` / `ResponseTopic`), and retained property notifications are documented in **[ApiGear over MQTT](/docs/protocols/mqtt/mapping)**.

## File overview for module

With our example API definition:

<details>
  <summary>Hello World API (click to expand)</summary>
  <CodeBlock language="yaml" showLineNumbers>{helloWorldModuleComponent}</CodeBlock>
</details>

The following file structure is generated:

```bash
📂ApiGear/Source
 ┣ 📂ApiGearMQTT
 ┃ ┣ 📂Private
 ┃ ┃ ┣ 📜apigearmqtt.cpp
 ┃ ┃ ┣ 📜ApiGearMQTTClient.cpp
 ┃ ┃ ┗ 📜ApiGearMQTTHost.cpp
 ┃ ┣ 📂Public
 ┃ ┃ ┣ 📜apigearmqtt.h
 ┃ ┃ ┣ 📜ApiGearMQTTClient.h
 ┃ ┃ ┣ 📜ApiGearMQTTHost.h
 ┃ ┃ ┣ 📜ApiGearMQTTTypes.h
 ┃ ┃ ┣ 📜IApiGearMqttClient.h
 ┃ ┃ ┗ 📜MqttLoopbackClient.h
 ┃ ┗ 📜apigearmqtt.Build.cs
 ┣ 📂ApiGearMQTTPaho
 ┃ ┣ 📂Private
 ┃ ┃ ┣ 📜ApiGearMQTTPaho.cpp
 ┃ ┃ ┗ 📜PahoMqttClient.cpp
 ┃ ┣ 📂Public
 ┃ ┃ ┣ 📜ApiGearMQTTPaho.h
 ┃ ┃ ┗ 📜PahoMqttClient.h
 ┃ ┗ 📜ApiGearMQTTPaho.Build.cs
 ┗ 📂ThirdParty/PahoMQTTLibrary

📂IoWorld/Source/IoWorldMQTT
 ┣ 📂Private
 ┃ ┗ 📂Generated
 ┃   ┣ 📜IoWorldMQTT.cpp
 ┃   ┗ 📂MQTT
 ┃     ┣ 📜IoWorldHelloMQTTClient.cpp
 ┃     ┗ 📜IoWorldHelloMQTTAdapter.cpp
 ┣ 📂Public
 ┃ ┗ 📂IoWorld
 ┃   ┣ 📜IoWorldMQTT.h
 ┃   ┗ 📂Generated/MQTT
 ┃     ┣ 📜IoWorldHelloMQTTClient.h
 ┃     ┗ 📜IoWorldHelloMQTTAdapter.h
 ┗ 📜IoWorldMQTT.Build.cs
```

## ApiGear MQTT Network Layer

The MQTT support is split into two infrastructure modules in the `ApiGear` plugin:

### ApiGearMQTT (transport-agnostic)

`ApiGearMQTT` defines the abstract transport layer used by every generated MQTT client and adapter. It does not depend on any specific MQTT library:

- **`IApiGearMqttClient`** — the abstract seam. Any MQTT library (Paho, Mqttify, MQTTCore, a mock) can be adapted by implementing this interface:

  ```cpp
  class APIGEARMQTT_API IApiGearMqttClient
  {
  public:
      virtual void Connect(const FString& URL) = 0;
      virtual void Disconnect() = 0;
      virtual bool IsConnected() const = 0;
      virtual FString GetClientId() const = 0;

      // FMessageCallback receives an FReceivedMessage carrying the
      // payload plus the MQTT 5 CorrelationData and ResponseTopic
      // properties (empty for MQTT 3.1.1 backends).
      virtual void Subscribe(const FString& Topic, FMessageCallback OnMessage,
          FSubscribeAckCallback OnSubscribed = nullptr) = 0;
      virtual void Unsubscribe(const TArray<FString>& Topics) = 0;
      virtual void Publish(const FString& Topic, const TArray<uint8>& Payload,
          const FPublishOptions& Options) = 0;

      virtual FOnConnectionChanged& OnConnectionChanged() = 0;
  };
  ```

- **`UApiGearMQTTClient`** — a `UAbstractApiGearConnection` consumed by generated per-interface clients. Holds the broker URL, dispatches subscribe/publish calls to the underlying `IApiGearMqttClient`, and tracks pending operation responses.
- **`UApiGearMQTTHost`** — a plain `UObject` (not a subsystem) that adapters use to publish property changes, signals, and operation replies. Multiple hosts can be instantiated to serve different scopes if needed.
- **`MqttLoopbackClient`** — an in-process `IApiGearMqttClient` plus broker for unit testing. Routes publishes directly to subscribers without touching the network.

The `UApiGearMQTTClient` constant `ApiGearMQTTProtocolIdentifier` is `"mqtt"`. Generated clients verify this when binding to a connection from the `UApiGearConnectionsStore`.

:::note
This is the [Strategy Pattern](https://en.wikipedia.org/wiki/Strategy_pattern). The generated code calls into `IApiGearMqttClient`, and the concrete strategy is chosen at startup based on which backend module is loaded.
:::

### ApiGearMQTTPaho (production backend)

`ApiGearMQTTPaho` provides a production-ready `IApiGearMqttClient` implementation built on the [Eclipse Paho C asynchronous client](https://github.com/eclipse-paho/paho.mqtt.c) (`MQTTAsync_*` API):

- `FPahoMqttClient` implements `IApiGearMqttClient` against `MQTTAsync` handles.
- The module's `StartupModule` registers a factory under the `"mqtt"` protocol identifier:

  ```cpp
  void FApiGearMQTTPahoModule::StartupModule()
  {
      UApiGearConnectionsStore::RegisterConnectionFactory(
          ApiGearMQTTProtocolIdentifier, &CreatePahoMQTTConnection);
  }
  ```

- The factory wires a fresh `FPahoMqttClient` into a new `UApiGearMQTTClient` whenever the connection store creates an MQTT connection.

The `ThirdParty/PahoMQTTLibrary` module bootstraps Paho on first build:

1. Clones `https://github.com/eclipse-paho/paho.mqtt.c.git` at tag `v1.3.14` (depth 1, ~2 MB).
2. Configures and builds the static `paho-mqtt3as` library via CMake with `PAHO_WITH_SSL=ON`.
3. Links against the OpenSSL bundled with Unreal Engine (auto-detected under `Engine/Source/ThirdParty/OpenSSL`).

:::warning
**Build prerequisites**: `git` and `cmake` must be installed and on `PATH`. The first build of any MQTT-enabled plugin downloads and compiles Paho; subsequent builds reuse the cached static library.
:::

:::tip
TLS is supported out of the box. URLs starting with `mqtts://` or `ssl://` trigger SSL configuration in the Paho backend. For broker authentication, extend `FPahoMqttClient::Connect` or pre-configure your broker accordingly.
:::

## MQTT Client

The `UIoWorldHelloMQTTClient` class implements `IIoWorldHelloInterface` (via `UAbstractIoWorldHello`) and forwards calls to a remote service over MQTT:

```cpp
UCLASS(NotBlueprintable, BlueprintType)
class IOWORLDMQTT_API UIoWorldHelloMQTTClient : public UAbstractIoWorldHello
{
    // properties
    FIoWorldMessage GetLast() const override;
    void SetLast(const FIoWorldMessage& Last) override;

    // operations
    int32 Say(const FIoWorldMessage& Msg, EIoWorldWhen When) override;
    TFuture<int32> SayAsync(const FIoWorldMessage& Msg, EIoWorldWhen When) override;

    UFUNCTION(BlueprintCallable, Category = "ApiGear|IoWorld|Hello")
    void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);
};
```

### How it works

1. **Subscribes to topics**: On connect, the client subscribes to property, signal, and reply topics for its interface. Subscriptions are tracked so re-connection re-subscribes automatically.
2. **Caches properties**: Property values broadcast on `prop/*` topics (retained) update the local cache and fire publisher delegates.
3. **Publishes set requests**: Setters publish to `set/*` topics; the client also caches the last sent value to suppress redundant publishes.
4. **Invokes operations with MQTT 5 correlation properties**: Each operation call generates a `FGuid`, attaches it as MQTT 5 `CorrelationData` (and the per-client reply topic as `ResponseTopic`) on the PUBLISH packet, and registers a `TPromise` keyed by that GUID. The matching reply — routed via the broker to the client's response topic with `CorrelationData` echoed — resolves the promise.
5. **Reports subscription readiness**: After all topic subscriptions are acknowledged, `_SubscriptionStatusChanged` fires with `true`. Until then, the client is connected to the broker but not yet ready to use.

```mermaid
graph TB
    subgraph Local[" Your Application "]
        Code[Application Code]
    end

    subgraph Client[" MQTT Client "]
        Interface["IIoWorldHelloInterface"]
    end

    subgraph Transport[" MQTT Broker "]
        Bus((Broker))
    end

    subgraph Remote[" Remote "]
        Adapter[MQTT Adapter]
        Other[Other MQTT Peers]
    end

    Code -->|uses| Interface
    Interface -->|publish set/rpc| Bus
    Bus -.->|deliver prop/sig/reply| Interface
    Bus <-->|publish/subscribe| Adapter
    Bus <-.->|publish/subscribe| Other
```

*The client acts as a **Remote Proxy** - it implements the same interface as the backend service but exchanges payloads via the broker. Properties are cached locally for fast reads, and operation replies are correlated by GUID.*

### Properties

Property getters return the locally cached value synchronized from the broker. Setters publish a JSON-encoded payload to the `set/*` topic:

```cpp
// Getter returns the locally cached value (last received on prop/last)
FIoWorldMessage UIoWorldHelloMQTTClient::GetLast() const
{
    return Last;
}

// Setter publishes to "io.world/Hello/set/last"
void UIoWorldHelloMQTTClient::SetLast(const FIoWorldMessage& InLast);
```

The setter skips the publish if the new value equals either the current cached value or the last sent value, reducing broker traffic when the application sets properties frequently.

:::note
Because property notifications are published as **retained** messages, a newly-subscribing client receives the current property values immediately upon subscription - no separate handshake is required.
:::

### Operations

Operations are routed through the broker. Choose between synchronous (blocking) and asynchronous (non-blocking) variants.

#### Synchronous (Blocking)

```cpp
int32 UIoWorldHelloMQTTClient::Say(const FIoWorldMessage& Msg, EIoWorldWhen When);
```

:::caution
Synchronous calls block the calling thread until the broker delivers the reply. On the game thread, this can cause frame hitches or freezes depending on broker latency. **Prefer async variants for network operations.**
:::

#### Asynchronous (Non-Blocking)

Returns a `TFuture` immediately while the operation completes:

```cpp
TFuture<int32> UIoWorldHelloMQTTClient::SayAsync(const FIoWorldMessage& Msg, EIoWorldWhen When);
```

**Usage examples:**

```cpp
// Chain a callback (recommended for UI updates)
TFuture<int32> Future = HelloClient->SayAsync(Msg, EIoWorldWhen::IWW_Now);
Future.Next([this](const int32& Result) {
    AsyncTask(ENamedThreads::GameThread, [this, Result]() {
        UpdateUI(Result);
    });
});

// Fire and forget
HelloClient->SayAsync(Msg, EIoWorldWhen::IWW_Now);
```

Internally, `SayAsync` registers a response handler keyed by a freshly-generated `FGuid`, then publishes the args-only payload `[args...]` to `io.world/Hello/rpc/say` with two MQTT 5 properties: `CorrelationData` set to the GUID bytes and `ResponseTopic` set to `io.world/Hello/rpc/say/{clientId}/result`. The service echoes `CorrelationData` on its reply, which lands on the response topic; the client matches the GUID and resolves the promise.

### Signals

Signals received from the broker are decoded and broadcast to local subscribers via the publisher:

```cpp
// Subscribe to signals using the Publisher
Hello->_GetPublisher()->OnJustSaidSignalBP.AddDynamic(this, &UMyClass::OnJustSaid);
```

Signal payloads are dispatched on the game thread via `AsyncTask(ENamedThreads::GameThread, ...)`, so subscribers do not need to marshal manually.

### Subscription Status

The MQTT client distinguishes broker connectivity from interface readiness. A client may be connected to the broker but still mid-subscription. Use the subscription status delegate:

```cpp
// Check if currently subscribed (all topics acknowledged)
if (HelloClient->_IsSubscribed())
{
    // Client is ready to use
}

// React to subscription changes
HelloClient->_SubscriptionStatusChanged.AddLambda([](bool bSubscribed) {
    UE_LOG(LogTemp, Log, TEXT("Subscription: %s"), bSubscribed ? TEXT("ready") : TEXT("not ready"));
});
```

### Using the MQTT Client

#### Setup Connection

Create an MQTT connection with `MQTTFactory::Create`, inject a concrete `IApiGearMqttClient` (Paho in production), call `Configure` with the broker URL, and register the connection with the connections store:

```cpp
#include "ApiGearConnectionsStore.h"
#include "ApiGearMQTTClient.h"
#include "PahoMqttClient.h"
#include "IoWorld/Generated/MQTT/IoWorldHelloMQTTClient.h"

// 1. Create the connection (UApiGearMQTTClient implements IApiGearConnection)
TScriptInterface<IApiGearConnection> Connection =
    MQTTFactory::Create(GetTransientPackage(), TEXT("MyMQTTConnection"));

// 2. Inject the Paho backend (use mqtts:// or ssl:// in the URL for TLS)
UApiGearMQTTClient* MQTT = Cast<UApiGearMQTTClient>(Connection.GetObject());
MQTT->SetMqttImplementation(MakeShared<FPahoMqttClient>());
MQTT->Configure(TEXT("tcp://localhost:1883"), /*bAutoReconnect*/ true);

// 3. Register with the engine-wide connections store so generated clients can find it
UApiGearConnectionsStore* Store = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();
Store->AddConnection(Connection);

// 4. Bind the per-interface MQTT client (GameInstance subsystem)
UIoWorldHelloMQTTClient* HelloClient = GetGameInstance()->GetSubsystem<UIoWorldHelloMQTTClient>();
HelloClient->UseConnection(Connection);
Connection->Connect();

// 5. Use as IIoWorldHelloInterface once subscriptions are acknowledged
HelloClient->_SubscriptionStatusChanged.AddLambda([HelloClient](bool bReady) {
    if (bReady) {
        TScriptInterface<IIoWorldHelloInterface> Hello = HelloClient;
        FIoWorldMessage Msg;
        Hello->Say(Msg, EIoWorldWhen::IWW_Now);
    }
});
```

:::note
`UApiGearConnectionsStore` exposes `GetConnection`, `AddConnection`, and `RegisterConnectionFactory` — there is no combined "get-or-create" helper. Either use `MQTTFactory::Create` directly (as above) or pre-configure the connection in Project Settings and look it up via `Store->GetConnection(Identifier)`.
:::

#### Using Project Settings

Configure connections in Project Settings under ApiGear:

1. Open Project Settings > Plugins > ApiGear
2. Add a new connection and pick the `mqtt` protocol from the dropdown
3. Set the broker URL (e.g., `tcp://localhost:1883` or `mqtts://broker.example.com:8883`)
4. Optionally enable auto-connect

The Project Settings dropdown lists every protocol that has registered a factory. Loading `ApiGearMQTTPaho` registers the `"mqtt"` entry.

The generated client picks up the configured connection automatically via the module setting `MQTTConnectionIdentifier`:

```cpp
UIoWorldSettings* settings = GetMutableDefault<UIoWorldSettings>();
TScriptInterface<IApiGearConnection> MQTTConnection =
    AGCM->GetConnection(settings->MQTTConnectionIdentifier);
```

## MQTT Adapter (Service)

The `UIoWorldHelloMQTTAdapter` wraps a local `IIoWorldHelloInterface` implementation and exposes it to MQTT subscribers through a `UApiGearMQTTHost`:

```cpp
UCLASS(BlueprintType)
class IOWORLDMQTT_API UIoWorldHelloMQTTAdapter : public UGameInstanceSubsystem,
    public IIoWorldHelloSubscriberInterface
{
    UFUNCTION(BlueprintCallable, Category = "ApiGear|IoWorld|Hello")
    void setBackendService(TScriptInterface<IIoWorldHelloInterface> InService);

    UFUNCTION(BlueprintCallable, Category = "ApiGear|IoWorld|Hello")
    void setMQTTHost(TSoftObjectPtr<UApiGearMQTTHost> InHost);
};
```

### How it works

1. **Wraps local implementation**: Subscribes to the backend's publisher to forward signals and property changes.
2. **Subscribes to inbound topics**: When the host connects, the adapter subscribes to its `set/*` and `rpc/*` topics.
3. **Handles set requests**: Decodes the JSON payload and forwards the value to the backend.
4. **Handles operation invocations**: Reads `CorrelationData` and `ResponseTopic` from the inbound MQTT 5 properties, decodes the args-only payload, invokes the backend, and publishes the result to the caller's `ResponseTopic` with `CorrelationData` echoed back.
5. **Broadcasts updates**: When the backend's property or signal fires, the adapter publishes to `prop/*` (retained) or `sig/*`.
6. **Replays state on reconnect**: When the host reconnects, the adapter republishes current property values so retained-message storage stays consistent.

```mermaid
graph BT
    subgraph Local[" Your Backend "]
        Impl["IIoWorldHelloInterface<br/>(your implementation)"]
    end

    subgraph Adapter[" MQTT Adapter "]
        Handler[Topic Handler]
    end

    subgraph Transport[" MQTT Broker "]
        Bus((Broker))
    end

    subgraph Remote[" Remote Subscribers "]
        UE[Unreal MQTT Client]
        Py[Python Client]
        JS[Web Dashboard]
        IoT[IoT Device]
    end

    Handler -->|calls| Impl
    Impl -.->|notifies| Handler

    UE & Py & JS & IoT -->|publish set/rpc| Bus
    Bus -->|deliver| Handler
    Handler -.->|publish prop/sig/reply| Bus
    Bus -.->|deliver| UE & Py & JS & IoT
```

*The adapter uses the **Adapter Pattern** - it wraps any `IIoWorldHelloInterface` implementation and exposes it via the broker. Multiple heterogeneous subscribers (Unreal, Python, web, embedded) can interact with it simultaneously.*

### Properties

When a subscriber publishes to `set/last`, the adapter decodes the JSON and forwards the value to the backend. The backend's property change notification is then broadcast on `prop/last` with `retain=true`:

```cpp
void UIoWorldHelloMQTTAdapter::OnLastChanged(const FIoWorldMessage& InLast)
{
    if (!Host.IsValid() || !bIsConnected) { return; }
    const FString Topic = TEXT("io.world/Hello/prop/last");
    Host.Get()->notifyPropertyChange(Topic, UTF8_TO_TCHAR(nlohmann::json(InLast).dump().c_str()));
}
```

### Operations

Remote operation calls carry their correlation in the MQTT 5 `CorrelationData` property and tell the service where to publish the reply via `ResponseTopic`. The adapter just echoes those properties back, so concurrent invocations from different clients never collide:

```cpp
// InMsg.CorrelationData and InMsg.ResponseTopic are MQTT 5 properties
// from the inbound PUBLISH packet.
int32 Result = BackendService->Say(Msg, When);
const nlohmann::json ResponsePayload = Result;
Host.Get()->notifyInvokeResponseWithCorrelation(
    InMsg.ResponseTopic,
    UTF8_TO_TCHAR(ResponsePayload.dump().c_str()),
    InMsg.CorrelationData);
```

### Signals

The adapter subscribes to the backend implementation's publisher. When the implementation broadcasts a signal, the adapter forwards it to `sig/*`:

```cpp
LocalImpl->_GetPublisher()->BroadcastJustSaidSignal(Msg);
```

### Using the MQTT Adapter

```cpp
#include "ApiGearMQTTHost.h"
#include "IoWorld/Generated/MQTT/IoWorldHelloMQTTAdapter.h"
#include "IoWorld/Implementation/IoWorldHello.h"

// Get your local implementation (GameInstance subsystem)
UIoWorldHelloImplementation* LocalHello =
    GetGameInstance()->GetSubsystem<UIoWorldHelloImplementation>();

// Create and start an MQTT host
UApiGearMQTTHost* Host = NewObject<UApiGearMQTTHost>(GetTransientPackage());
// Production: wire in the Paho backend
Host->SetMqttImplementation(MakeShared<FPahoMqttClient>());
Host->Start(TEXT("tcp://localhost:1883"));

// Get the adapter (GameInstance subsystem)
UIoWorldHelloMQTTAdapter* Adapter =
    GetGameInstance()->GetSubsystem<UIoWorldHelloMQTTAdapter>();
Adapter->setBackendService(LocalHello);
Adapter->setMQTTHost(Host);

// Adapter publishes property/signal changes; subscribers consume them via the broker
```

:::note
The adapter is a `UGameInstanceSubsystem`, but the host is a plain `UObject`. This lets you instantiate multiple hosts (for example, to publish to different brokers or topic prefixes) while keeping a single adapter per interface.
:::

## Communication Flow

The following diagram traces a complete interaction between a client and an adapter through the broker:

```mermaid
sequenceDiagram
    participant App as Application
    participant Client as MQTTClient
    participant Broker as MQTT Broker
    participant Adapter as MQTTAdapter
    participant Backend as Backend Service

    rect rgb(240, 248, 255)
        Note over Client,Adapter: Connect & Subscribe
        App->>Client: UseConnection(...) / Connect
        Client->>Broker: CONNECT
        Broker->>Client: CONNACK
        Client->>Broker: SUBSCRIBE prop/last, sig/justSaid, rpc/say/{clientId}/result
        Broker->>Client: SUBACK + retained prop/last
        Client->>Client: cache initial property
        Client->>App: _SubscriptionStatusChanged(true)
    end

    rect rgb(255, 250, 240)
        Note over Client,Adapter: Property Change
        App->>Client: SetLast(newValue)
        Client->>Broker: PUBLISH set/last (JSON)
        Broker->>Adapter: deliver set/last
        Adapter->>Backend: SetLast(newValue)
        Backend-->>Adapter: OnLastChanged(newValue)
        Adapter->>Broker: PUBLISH prop/last (retained)
        Broker->>Client: deliver prop/last
        Client->>Client: update cache
        Client->>App: BroadcastLastChanged
    end

    rect rgb(240, 255, 240)
        Note over Client,Adapter: Operation Request/Response (MQTT 5)
        App->>Client: Say(msg, when)
        Client->>Client: register handler with FGuid
        Client->>Broker: PUBLISH rpc/say [args] + CorrelationData=guid, ResponseTopic=…/{clientId}/result
        Broker->>Adapter: deliver rpc/say
        Adapter->>Backend: Say(msg, when)
        Backend-->>Adapter: result
        Adapter->>Broker: PUBLISH (caller's ResponseTopic) [result] + CorrelationData=guid (echoed)
        Broker->>Client: deliver reply
        Client->>Client: match guid, resolve TPromise
        Client-->>App: return result
    end

    rect rgb(255, 240, 245)
        Note over Client,Adapter: Signal Broadcast
        Backend->>Backend: emit JustSaid signal
        Backend-->>Adapter: OnJustSaidSignal
        Adapter->>Broker: PUBLISH sig/justSaid
        Broker->>Client: deliver sig/justSaid
        Client->>App: BroadcastJustSaidSignal (game thread)
    end
```

## Testing with MQTT

The `mqtt_tests` feature generates test fixtures that exercise the full client/adapter pair without needing a real broker:

```bash
📂IoWorld/Source/IoWorldMQTT/Private/Tests
 ┣ 📜IoWorldHelloMQTT.spec.cpp
 ┣ 📜IoWorldHelloMQTTFixture.h
 ┗ 📜IoWorldHelloMQTTFixture.cpp
```

The fixture wires up an in-process broker (`FMqttLoopbackBroker`) and two `FMqttLoopbackClient` instances - one for the host and one for the client - so the test runs entirely in memory:

```cpp
// from IoWorldHelloMQTTFixture.cpp
auto Broker = MakeShared<FMqttLoopbackBroker>();
auto ClientLoopback = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-client"));
auto HostLoopback   = MakeShared<FMqttLoopbackClient>(Broker, TEXT("loopback-host"));

Host = NewObject<UApiGearMQTTHost>(GetTransientPackage());
Host->SetMqttImplementation(HostLoopback);

GetAdapter()->setBackendService(service);
GetAdapter()->setMQTTHost(Host.Get());
Host->Start(TEXT("loopback://test"));

Connection = MQTTFactory::Create(GetTransientPackage(), TEXT("MQTTTestingConnection"));
auto* MQTTConnection = Cast<UApiGearMQTTClient>(Connection.GetObject());
MQTTConnection->SetMqttImplementation(ClientLoopback);
MQTTConnection->Configure(TEXT("loopback://test"), false);
```

These tests verify:

- Subscription handshake and `_IsSubscribed()` readiness signaling
- Property synchronization via retained messages
- Operation invocation and per-client reply routing
- Signal propagation onto the game thread

### Running Tests

```bash
UnrealEditor-Cmd.exe YourProject.uproject -ExecCmds="Automation RunTests IoWorld.Hello.MQTT"
```

:::tip
The loopback transport is also useful in your own tests when you need deterministic MQTT semantics without provisioning a broker. Construct an `FMqttLoopbackBroker`, share it across as many `FMqttLoopbackClient`s as you need, and inject them via `SetMqttImplementation` on the host and connection.
:::

## Best Practices

### Broker Selection

- For local development, [Mosquitto](https://mosquitto.org/) is the simplest broker to run.
- For production, choose a broker that supports your scale and reliability requirements (EMQX, HiveMQ, AWS IoT Core, Azure IoT Hub).
- Configure broker authentication, ACLs, and TLS appropriately - the generated code defers credential handling to your `IApiGearMqttClient` implementation.

### Topic Discipline

- The generated topic structure (`{module}/{Interface}/{action}/{member}`) is fixed by the template. Do not publish to these topics from non-generated code unless you fully understand the payload format.
- If multiple Unreal instances run the same plugin, they all subscribe to and publish on the same topics. Coordinate which instance acts as the adapter.

### Connection Lifecycle

- Wait for `_SubscriptionStatusChanged(true)` before invoking operations - publishing before subscriptions are acknowledged risks losing replies.
- Re-subscription on reconnect is automatic. Pending operation promises are cancelled on `Deinitialize` to avoid use-after-free in test teardown.
- Adapters re-publish their current property values when the host reconnects, keeping retained-message storage consistent.

### Performance Considerations

- MQTT publishes are network calls - avoid invoking operations every frame.
- Property setters automatically suppress duplicate publishes; rely on this rather than guarding manually.
- Use QoS 1 (the default) unless you have a specific reason to relax delivery guarantees.
- The generated MQTT code includes CPU profiler instrumentation (`TRACE_CPUPROFILER_EVENT_SCOPE_STR`) for performance tracing in Unreal Insights.
