---
sidebar_position: 3
sidebar_label: "OLink"
title: "OLink Feature: WebSocket Remote Connectivity for Unreal Engine"
description: "Connect Unreal Engine to remote services via ObjectLink WebSocket protocol. Client and server adapters for cross-platform communication and simulation."
keywords: [olink, websocket, remote procedure call, unreal engine networking, objectlink, apigear]
---

import CodeBlock from '@theme/CodeBlock';
import helloWorldModuleComponent from '!!raw-loader!./data/helloworld.module.yaml';

# OLink

The `olink` feature provides client and server adapters for the [ObjectLink](/docs/protocols/objectlink/intro) protocol. This enables:

- **Remote connections**: Connect your Unreal application to services running in other processes or machines
- **Cross-platform communication**: Communicate with applications built using other ApiGear templates (Qt, C++, etc.)
- **Simulation**: Connect to the ApiGear simulation tools for testing without a real backend

Use an _OLink client_ instead of your local implementation to connect to a remote service. Use an _OLink adapter_ (server) to expose your local implementation to remote clients.

:::note
The OLink client and adapter are ready-to-use. They handle all network communication transparently, so you can use them just like local implementations.
:::

## ApiGear ObjectLink Protocol

The [ObjectLink](/docs/protocols/objectlink/intro) protocol is a lightweight WebSocket-based protocol for object communication. It supports:

- Remote property changes (client requests, server notifies)
- Signal emission notifications
- Remote method invocation with responses

The generated code uses the ObjectLink protocol library included in the `ApiGear` plugin.

## File overview for module

With our example API definition:

<details>
  <summary>Hello World API (click to expand)</summary>
  <CodeBlock language="yaml" showLineNumbers>{helloWorldModuleComponent}</CodeBlock>
</details>

The following file structure is generated:

```bash
📂ApiGear/Source
 ┣ 📂ApiGearOLink
 ┃ ┣ 📂Private
 ┃ ┃ ┣ 📜OLinkClientConnection.cpp
 ┃ ┃ ┣ 📜OLinkHost.cpp
 ┃ ┃ ┣ 📜OLinkHostConnection.cpp
 ┃ ┃ ┗ 📜OLinkSink.cpp
 ┃ ┣ 📂Public
 ┃ ┃ ┣ 📜OLinkClientConnection.h
 ┃ ┃ ┣ 📜OLinkHost.h
 ┃ ┃ ┗ 📜OLinkSink.h
 ┃ ┗ 📜apigearolink.Build.cs
 ┗ 📂ThirdParty/OLinkProtocolLibrary

📂IoWorld/Source/IoWorldOLink
 ┣ 📂Private
 ┃ ┗ 📂Generated
 ┃   ┣ 📜IoWorldOLink.cpp
 ┃   ┗ 📂OLink
 ┃     ┣ 📜IoWorldHelloOLinkClient.cpp
 ┃     ┣ 📜IoWorldHelloOLinkAdapter.cpp
 ┃     ┣ 📜IoWorldHelloOLinkSource.h
 ┃     ┗ 📜IoWorldHelloOLinkSource.cpp
 ┣ 📂Public
 ┃ ┗ 📂IoWorld
 ┃   ┣ 📜IoWorldOLink.h
 ┃   ┗ 📂Generated/OLink
 ┃     ┣ 📜IoWorldHelloOLinkClient.h
 ┃     ┗ 📜IoWorldHelloOLinkAdapter.h
 ┗ 📜IoWorldOLink.Build.cs
```

## ApiGear OLink Network Layer

The `ApiGearOLink` module provides the network infrastructure:

### OLinkClientConnection

Manages WebSocket connections for OLink clients:

- Connects to a remote OLink host
- Routes incoming messages to registered client sinks
- Handles reconnection logic
- Manages message queuing during disconnection

### OLinkHost

Hosts OLink services for remote clients:

- Listens for incoming WebSocket connections
- Routes client requests to registered service adapters
- Manages multiple simultaneous client connections

## OLink Client

The `UIoWorldHelloOLinkClient` class implements `IIoWorldHelloInterface` and connects to a remote OLink service.

### How it works

1. **Properties**: Getter returns the locally cached value (synchronized from server). Setter sends a change request to the server.
2. **Operations**: Calls are forwarded to the remote server. The client waits for the response.
3. **Signals**: When the server emits a signal, the client receives it and broadcasts locally.

### Properties

Properties are synchronized between client and server:

```cpp
// Getter returns the locally cached value (synchronized from server)
FIoWorldMessage UIoWorldHelloOLinkClient::GetLast() const
{
    return Last;
}

// Setter sends a change request to the server
void UIoWorldHelloOLinkClient::SetLast(const FIoWorldMessage& InLast);
```

The setter validates the connection and optimizes network traffic by skipping redundant requests when the value hasn't changed.

:::note
When a client successfully links to a server, it receives the current property values automatically.
:::

### Operations

Operations are forwarded to the remote server. Choose between synchronous (blocking) and asynchronous (non-blocking) variants.

#### Synchronous (Blocking)

```cpp
int32 UIoWorldHelloOLinkClient::Say(const FIoWorldMessage& Msg, EIoWorldWhen When);
```

:::caution
Synchronous calls block the calling thread. On the game thread, this can cause frame hitches or freezes depending on network latency. **Prefer async variants for network operations.**
:::

#### Asynchronous (Non-Blocking)

Returns a `TFuture` immediately while the operation executes:

```cpp
TFuture<int32> UIoWorldHelloOLinkClient::SayAsync(const FIoWorldMessage& Msg, EIoWorldWhen When);
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

#### Blueprint Async Operations

In Blueprints, use the async version which appears as a latent node with execution pins. The latent action handles waiting internally without blocking the game thread.

### Signals

Signals received from the server are broadcast to local subscribers via the Publisher:

```cpp
// Subscribe to signals using the Publisher
Hello->_GetPublisher()->OnJustSaidSignalBP.AddDynamic(this, &UMyClass::OnJustSaid);
```

### Using the OLink Client

#### Setup Connection

In your game code or a custom subsystem:

```cpp
#include "OLinkClientConnection.h"
#include "IoWorld/Generated/OLink/IoWorldHelloOLinkClient.h"

// Get or create the connection
UOLinkClientConnection* Connection = NewObject<UOLinkClientConnection>();
Connection->Configure(TEXT("ws://localhost:8182/ws"), false);
Connection->Connect();

// Get the OLink client (GameInstance subsystem)
UIoWorldHelloOLinkClient* HelloClient = GetGameInstance()->GetSubsystem<UIoWorldHelloOLinkClient>();
HelloClient->UseConnection(Connection);  // Associate with the connection

// Use as IIoWorldHelloInterface
TScriptInterface<IIoWorldHelloInterface> Hello = HelloClient;
Hello->Say(Msg, EIoWorldWhen::IWW_Now);
```

#### Using Project Settings

Configure connections in Project Settings under ApiGear:

1. Open Project Settings > Plugins > ApiGear
2. Add a new OLink connection
3. Set the server URL (e.g., `ws://localhost:8182/ws`)
4. Enable auto-connect if desired

Then access the configured connection:

```cpp
#include "ApiGearConnectionsStore.h"

UApiGearConnectionsStore* Store = GetGameInstance()->GetSubsystem<UApiGearConnectionsStore>();
UOLinkClientConnection* Connection = Store->GetOLinkConnection(TEXT("MyConnection"));
```

#### Blueprint Setup

1. Get the `ApiGearConnectionsStore` subsystem
2. Call `GetOLinkConnection` with your connection name
3. Create your OLink client instance
4. Use it like any other interface implementation

#### Subscription Status

The OLink client provides delegates to track when it successfully links to a server:

```cpp
// Check if currently subscribed (linked to server)
if (HelloClient->_IsSubscribed())
{
    // Client is ready to use
}

// React to subscription changes
HelloClient->_SubscriptionStatusChanged.AddLambda([](bool bSubscribed) {
    UE_LOG(LogTemp, Log, TEXT("Subscription: %s"), bSubscribed ? TEXT("linked") : TEXT("unlinked"));
});
```

## OLink Adapter (Server)

The `UIoWorldHelloOLinkAdapter` wraps a local `IIoWorldHelloInterface` implementation and exposes it to remote clients.

:::warning
The OLink adapter is disabled on mobile platforms (iOS, Android, QNX). Mobile devices typically act as clients only, not servers.
:::

### How it works

1. **Wraps local implementation**: Takes an existing implementation (e.g., your stub)
2. **Handles remote requests**: Forwards property changes and operation calls to the wrapped implementation
3. **Broadcasts updates**: Sends property changes and signals to all connected clients

### Properties

When a client requests a property change, the adapter receives the request, calls the wrapped implementation, and the property change is broadcast to all connected clients.

### Operations

Remote operation calls are forwarded to the local implementation. The result is sent back to the calling client.

### Signals

The adapter subscribes to the local implementation's signals. When the implementation emits a signal via the Publisher, the adapter broadcasts it to all connected remote clients:

```cpp
LocalImpl->_GetPublisher()->BroadcastJustSaidSignal(Msg);
```

### Using the OLink Adapter

```cpp
#include "OLinkHost.h"
#include "IoWorld/Generated/OLink/IoWorldHelloOLinkAdapter.h"
#include "IoWorld/Implementation/IoWorldHello.h"

// Get your local implementation (GameInstance subsystem)
UIoWorldHelloImplementation* LocalHello = GetGameInstance()->GetSubsystem<UIoWorldHelloImplementation>();

// Get the OLink host (GameInstance subsystem)
UOLinkHost* Host = GetGameInstance()->GetSubsystem<UOLinkHost>();
Host->Start(8182);  // Listen on port 8182

// Get the adapter (GameInstance subsystem)
UIoWorldHelloOLinkAdapter* Adapter = GetGameInstance()->GetSubsystem<UIoWorldHelloOLinkAdapter>();
Adapter->setBackendService(LocalHello);  // Note: lowercase 's'
Adapter->setOLinkHost(Host);  // Register with the host

// Now remote clients can connect and use your implementation
```

## Testing with OLink

The `olink_tests` feature generates test fixtures for OLink functionality:

```bash
📂IoWorld/Source/IoWorldOLink/Private/Tests
 ┣ 📜IoWorldHelloOLink.spec.cpp
 ┣ 📜IoWorldHelloOLinkFixture.h
 ┗ 📜IoWorldHelloOLinkFixture.cpp
```

These tests verify:
- Client-server connection
- Property synchronization
- Operation invocation and response
- Signal propagation

## Best Practices

### Connection Management

- Use the `ApiGearConnectionsStore` for centralized connection management
- Configure connections in Project Settings for easy adjustment
- Handle connection/disconnection events for UI feedback

### Error Handling

```cpp
Connection->GetOnConnectionStatusChangedDelegate().AddDynamic(this, &UMyClass::OnConnectionChanged);

void UMyClass::OnConnectionChanged(bool bConnected)
{
    if (!bConnected)
    {
        // Handle disconnection
        UE_LOG(LogTemp, Warning, TEXT("OLink connection lost"));
    }
}
```

### Performance Considerations

- OLink operations are network calls - avoid calling them every frame
- Use property change delegates for reactive updates instead of polling
- Consider async operation variants for non-blocking behavior

The generated OLink code includes CPU profiler instrumentation (`TRACE_CPUPROFILER_EVENT_SCOPE_STR`) for performance tracing in Unreal Insights.
