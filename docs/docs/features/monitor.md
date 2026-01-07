---
sidebar_position: 5
sidebar_label: "Monitor"
title: "Monitor Feature: API Tracing and Runtime Debugging for Unreal Engine"
description: "Trace API calls, property changes, and signals at runtime. View live debugging data in ApiGear Studio or CLI for Unreal Engine interfaces."
keywords: [monitor, tracing, debugging, runtime logging, apigear studio, unreal engine]
---

import CodeBlock from '@theme/CodeBlock';
import helloWorldModuleComponent from '!!raw-loader!./data/helloworld.module.yaml';

# Monitor

The `monitor` feature generates tracing capabilities to observe your interfaces at runtime. It enables:

- **Property tracking**: See when properties change and their new values
- **Operation logging**: Track method calls with parameters and return values
- **Signal monitoring**: Observe signal emissions and their data
- **Live debugging**: View all activity in ApiGear Studio or CLI

The monitoring server is integrated into [ApiGear Studio](/docs/studio/intro) and the [CLI](/docs/cli/intro).

For more details on monitoring concepts, see [monitoring documentation](/docs/monitor/intro).

## File overview for module

With our example API definition:

<details>
  <summary>Hello World API (click to expand)</summary>
  <CodeBlock language="yaml" showLineNumbers>{helloWorldModuleComponent}</CodeBlock>
</details>

The following file structure is generated:

```bash
📂ApiGear/Source/ApiGear
 ┣ 📂Public
 ┃ ┗ 📜tracer.h
 ┗ 📂Private
   ┗ 📜tracer.cpp

📂IoWorld/Source/IoWorldMonitor
 ┣ 📂Private
 ┃ ┗ 📂Generated
 ┃   ┣ 📜IoWorldMonitor.cpp
 ┃   ┗ 📂Monitor
 ┃     ┣ 📜IoWorld.trace.h
 ┃     ┣ 📜IoWorld.trace.cpp
 ┃     ┗ 📜IoWorldHelloLoggingDecorator.cpp
 ┣ 📂Public
 ┃ ┗ 📂IoWorld
 ┃   ┣ 📜IoWorldMonitor.h
 ┃   ┗ 📂Generated/Monitor
 ┃     ┗ 📜IoWorldHelloLoggingDecorator.h
 ┗ 📜IoWorldMonitor.Build.cs
```

The `ApiGear` plugin provides the tracer client that connects to the monitoring server. Each module generates interface-specific trace helpers (in the `Monitor` subdirectory) and a logging decorator class that wraps implementations.

## Tracer

The `ApiGear` plugin includes a tracer client that connects to the monitoring server and sends trace data.

### Tracer Configuration

Configure the tracer in your game initialization:

```cpp
#include "tracer.h"

UApiGearTracer* Tracer = GetGameInstance()->GetSubsystem<UApiGearTracer>();

Tracer->Connect(TEXT("ws://localhost:8182/ws"), TEXT("MyUnrealApp"));
```

### Project Settings

You can also configure tracing in Project Settings:

1. Open Project Settings > Plugins > ApiGear
2. Set the Tracer URL (e.g., `ws://localhost:8182/ws`)
3. Set the Application Name for identification
4. Enable/disable auto-connect

## Logging Decorator

The `UIoWorldHelloLoggingDecorator` wraps any `IIoWorldHelloInterface` implementation and logs all interactions to the tracer.

### How it works

The decorator:
1. Wraps an existing interface implementation
2. Intercepts all property access, operation calls, and signal emissions
3. Sends trace data to the connected monitoring server
4. Forwards all calls to the wrapped implementation (transparent)

The decorator extends `UAbstractIoWorldHello` and subscribes to notifications from the wrapped backend service. The key method for setup is:

```cpp
// Set which implementation to wrap and trace
void setBackendService(TScriptInterface<IIoWorldHelloInterface> InService);
```

Once configured, use the decorator exactly like any other implementation—it implements the full interface and forwards all calls to the backend while logging.

:::note
The monitor feature uses generated tracer helper classes (in `Private/`) that handle JSON serialization automatically. The logging decorator manages all tracing - you don't need to interact with these classes directly.
:::

### What Gets Traced

The logging decorator automatically traces:

- **Property writes**: When you call `SetLast()`, a `call` event is sent with the new value
- **Property changes**: When the backend notifies of a change, the full interface state is captured
- **Operations**: All operation calls are traced with their parameters
- **Signals**: Signal emissions are traced with their data

Property reads (`GetLast()`) are not traced since they don't modify state.

## Using the Monitor

### Basic Setup

The logging decorator is a GameInstance Subsystem, so you access it via `GetSubsystem<>()` and configure which implementation it wraps. You can wrap any implementation, including network clients.

```cpp
#include "tracer.h"
#include "IoWorld/Generated/Monitor/IoWorldHelloLoggingDecorator.h"
#include "IoWorld/Implementation/IoWorldHello.h"

UIoWorldHelloImplementation* HelloImpl = GetGameInstance()->GetSubsystem<UIoWorldHelloImplementation>();

UIoWorldHelloLoggingDecorator* TracedHello = GetGameInstance()->GetSubsystem<UIoWorldHelloLoggingDecorator>();
TracedHello->setBackendService(HelloImpl);

TScriptInterface<IIoWorldHelloInterface> Hello = TracedHello;
Hello->Say(Msg, EIoWorldWhen::IWW_Now);
```

### Settings Integration

Instead of manual setup, configure the backend service via Project Settings:

1. Open **Project Settings > Plugins > IoWorld**
2. Set **Tracer Service Identifier** to the backend you want to trace (e.g., `Local` for stubs, `OLink` for network)

The decorator automatically wraps the configured backend during initialization.

## Best Practices

### Performance Considerations

- Tracing adds overhead for serialization and network transmission
- Disable in performance-critical sections if needed
- Consider tracing only specific interfaces of interest
