---
sidebar_position: 0
sidebar_label: "Quick Start"
title: "Quick Start: Generate Unreal Engine Plugins from API Definitions"
description: "Step-by-step guide to generate Unreal Engine plugins from YAML API definitions. Learn to create Blueprint and C++ interfaces with ApiGear code generator."
keywords: [unreal engine quickstart, api code generation, blueprint interface, c++ plugin, apigear tutorial]
---
import Figure from '@site/src/components/figure'
import QuickStartCommon from "@site/docs/_quickstart_common.md"
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

# Quick-Start

The Quick-Start guide explains how to, in few steps, get from an API to a functional *Unreal Engine* plugin.

<QuickStartCommon />

## 5. How to use the plugin

### Project folder structure

For the code generation we assume that both *ApiGear* files reside in an `apigear` subfolder next to the *Unreal Engine* project.
In this case the folder structure should look similar to this.
```bash
📦ue_docs_example_project
 ┣ 📂apigear
 ┃ ┣ 📜helloworld.solution.yaml
 ┃ ┗ 📜helloworld.module.yaml
 ┣ 📂ue_docs
 ┃ ┣ 📂Config
 ┃ ┣ 📂Content
 ┃ ┣ 📂Platforms
 # highlight-next-line
 ┃ ┣ 📂Plugins
 ┃ ┣ 📂Source
 ┃ ┗ 📜ue_docs.uproject
```
Using the solution file from the previous paragraph the code will be generated in the `ue_docs/Plugins` folder.

:::tip Solution `output:` path
The generator writes each module's plugin folder **directly** under `output:` — it does not append `Plugins/` for you. To land plugins under your Unreal project's `Plugins/` directory, set `output: ../ue_docs/Plugins` in your `solution.yaml`. The path you give is the parent of the generated plugin folders (e.g. `IoWorld/`, `ApiGear/`).
:::

:::tip Prerequisites
This guide assumes you already have an Unreal Engine project. The generated plugin will be placed in your project's `Plugins` folder.
:::

The generated code can be used with *Blueprints* and *C++*. Make sure to have the generated plugin code in your projects plugins directory as noted in the [previous section](#4-generate-code).

### Hosting the plugin in a fresh UE project

If you don't have an existing Unreal project (for example, in a CI pipeline or when starting from a clean workspace), the four files below are the minimum needed to host a generated plugin. The example uses the `IoWorld` plugin produced from `io.world.Hello` and references it from a host module called `HelloHost`.

Drop these files next to the `Plugins/` directory you generated into:

```bash
📦HelloHost
 ┣ 📂Plugins
 ┃ ┣ 📂ApiGear
 ┃ ┗ 📂IoWorld
 ┣ 📂Source
 ┃ ┣ 📂HelloHost
 ┃ ┃ ┗ 📜HelloHost.Build.cs
 ┃ ┣ 📜HelloHost.Target.cs
 ┃ ┗ 📜HelloHostEditor.Target.cs
 ┗ 📜HelloHost.uproject
```

#### `HelloHost.uproject`

```json title="HelloHost.uproject"
{
    "FileVersion": 3,
    "EngineAssociation": "5.7",
    "Category": "",
    "Description": "ApiGear MQTT5 helloworld host project",
    "Modules": [
        {
            "Name": "HelloHost",
            "Type": "Runtime",
            "LoadingPhase": "Default",
            "AdditionalDependencies": [
                "Engine",
                "IoWorldAPI",
                "IoWorldCore",
                "IoWorldImplementation",
                "IoWorldMQTT",
                "ApiGear",
                "ApiGearMQTT",
                "ApiGearMQTTPaho"
            ]
        }
    ],
    "Plugins": [
        { "Name": "ApiGear", "Enabled": true },
        { "Name": "IoWorld", "Enabled": true }
    ]
}
```

#### `Source/HelloHost.Target.cs`

```cs title="Source/HelloHost.Target.cs"
using UnrealBuildTool;

public class HelloHostTarget : TargetRules
{
    public HelloHostTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V6;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_7;
        ExtraModuleNames.Add("HelloHost");
    }
}
```

#### `Source/HelloHostEditor.Target.cs`

```cs title="Source/HelloHostEditor.Target.cs"
using UnrealBuildTool;

public class HelloHostEditorTarget : TargetRules
{
    public HelloHostEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V6;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_7;
        ExtraModuleNames.Add("HelloHost");
    }
}
```

#### `Source/HelloHost/HelloHost.Build.cs`

The dependency list is the non-obvious bit. `IoWorldAPI` / `IoWorldCore` / `IoWorldImplementation` are always needed; add `IoWorldMQTT`, `ApiGearMQTT`, and `ApiGearMQTTPaho` only if you generated the `mqtt` feature. Swap in `IoWorldOLink` / `ApiGearOLink` for OLink, or `IoWorldMsgBus` for Message Bus.

```cs title="Source/HelloHost/HelloHost.Build.cs"
using UnrealBuildTool;

public class HelloHost : ModuleRules
{
    public HelloHost(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        IWYUSupport = IWYUSupport.Full;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "IoWorldAPI",
            "IoWorldCore",
            "IoWorldImplementation",
            "IoWorldMQTT",
            "ApiGear",
            "ApiGearMQTT",
            "ApiGearMQTTPaho",
            "JsonUtilities",
            "Projects"
        });

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
```

You also need a minimal module entry point — two short files next to `HelloHost.Build.cs`:

```cpp title="Source/HelloHost/HelloHost.h"
#pragma once

#include "CoreMinimal.h"
```

```cpp title="Source/HelloHost/HelloHost.cpp"
#include "HelloHost.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl, HelloHost, "HelloHost");
```

After dropping these files in place, right-click the `.uproject` and choose **Generate Visual Studio project files** (or run UnrealBuildTool's `-projectfiles` command), then build the editor target. The generated plugins compile alongside your host module.

### Verify Plugin Installation

After generating the code:

1. Open your Unreal project in the Editor
2. Go to **Edit → Plugins**
3. Search for `IoWorld` - you should see the generated plugin listed
4. Ensure the plugin is enabled (checkbox checked)
5. Restart the Editor if prompted

If the plugin does not appear, verify the generated files are in the correct `Plugins` folder and regenerate project files.

### Using the Interface

<Tabs groupId="language">
<TabItem value="blueprint" label="Blueprint" default>

#### Getting the Subsystem

Open your project in the Unreal Editor and choose a *Blueprint* where you want to use the interface.
First, get the *GameInstance* subsystem of the type `IoWorldHelloImplementation`:

<Figure caption="Get subsystem in Blueprint" src="/img/quick-start/quick-start-blueprint-get-subsystem.png" />

#### Calling Operations

On this subsystem we can choose the *asynchronous Say* function. Using the async version prevents blocking the game thread:

<Figure caption="Choose method on interface in Blueprint" src="/img/quick-start/quick-start-blueprint-choose-method.png" />

#### Complete Example

The complete setup to say "Hello world" on begin play:

<Figure caption="Hello interface example in Blueprint" src="/img/quick-start/quick-start-blueprint-complete.png" />

</TabItem>
<TabItem value="cpp" label="C++">

#### Module Dependencies

For any C++ module to access the generated interface, add the dependency in your `.Build.cs` file. The module name is a PascalCase transformation of the ApiGear module name (`io.world` becomes `IoWorld`):

```cs showLineNumbers title="ue_docs.Build.cs"
PrivateDependencyModuleNames.AddRange(new string[] { "IoWorldAPI", "IoWorldImplementation" });
```

After modifying your `.Build.cs` file, regenerate your project files and rebuild the project. In Visual Studio, this is typically done via **Build → Rebuild Solution**.

#### Include Headers

The generated plugin provides three key headers:

- **IoWorldHello.h** - The implementation class (GameInstance subsystem)
- **IoWorld_data.h** - Data types: structs (`FIoWorldMessage`) and enums (`EIoWorldWhen`)
- **IoWorldHelloInterface.h** - The interface definition (`IIoWorldHelloInterface`)

For most use cases, include all three:

```cpp
#include "IoWorld/Implementation/IoWorldHello.h"
#include "IoWorld/Generated/api/IoWorld_data.h"
#include "IoWorld/Generated/api/IoWorldHelloInterface.h"
```

#### Calling Operations

Get the implementation through the GameInstance subsystem. The `TScriptInterface` wrapper provides polymorphic access to the interface while holding a reference to the concrete implementation.

Enum values use a prefix derived from the module and enum name. For the `When` enum in `io.world`, the prefix is `IWW_` (IoWorld When), giving values like `IWW_Now`, `IWW_Soon`, and `IWW_Never`.

```cpp showLineNumbers title="ue_docsGameModeBase.cpp"
#include "ue_docsGameModeBase.h"
#include "IoWorld/Implementation/IoWorldHello.h"
#include "IoWorld/Generated/api/IoWorld_data.h"
#include "IoWorld/Generated/api/IoWorldHelloInterface.h"

void Aue_docsGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
    Super::InitGame(MapName, Options, ErrorMessage);

    TScriptInterface<IIoWorldHelloInterface> Hello =
        GetGameInstance()->GetSubsystem<UIoWorldHelloImplementation>();

    FIoWorldMessage MyMsg;
    MyMsg.content = FString("Hello world");
    Hello->Say(MyMsg, EIoWorldWhen::IWW_Now);
}
```

#### Async Operations (Recommended)

Operations with return values have async variants that prevent blocking the game thread. This is especially important when using network backends (OLink, MsgBus) where operations involve network latency. The async call returns immediately with a `TFuture` that resolves when the operation completes.

```cpp
TFuture<int32> Future = Hello->SayAsync(MyMsg, EIoWorldWhen::IWW_Now);

Future.Next([](const int32& Result) {
    UE_LOG(LogTemp, Log, TEXT("Say returned: %d"), Result);
});
```

</TabItem>
</Tabs>

### Subscribing to Events

<Tabs groupId="language">
<TabItem value="blueprint" label="Blueprint" default>

To react to property changes or signals in Blueprints:

1. Get the subsystem as shown above
2. Call **Get Publisher** on the subsystem
3. From the Publisher, drag off and search for **Assign** to find bindable events
4. Choose the event you want: **On Last Changed BP** (property change) or **On Just Said Signal BP** (signal)

The Publisher object holds all delegates because Unreal interfaces cannot declare delegates directly.

:::note
Blueprint screenshots for event binding coming soon.
:::

</TabItem>
<TabItem value="cpp" label="C++">

To receive property change and signal notifications, bind to delegates on the Publisher object. Callback methods must be marked with `UFUNCTION()` for dynamic delegate binding to work.

Delegate names follow these patterns:
- Property changes: `On{PropertyName}ChangedBP` (e.g., `OnLastChangedBP`)
- Signals: `On{SignalName}SignalBP` (e.g., `OnJustSaidSignalBP`)

In your class header, declare the callback functions:

```cpp
UFUNCTION()
void OnLastChanged(const FIoWorldMessage& Last);

UFUNCTION()
void OnJustSaid(const FIoWorldMessage& Msg);
```

In your implementation, bind to the events:

```cpp
Hello->_GetPublisher()->OnLastChangedBP.AddDynamic(this, &UMyClass::OnLastChanged);
Hello->_GetPublisher()->OnJustSaidSignalBP.AddDynamic(this, &UMyClass::OnJustSaid);
```

:::caution
Always remove delegate bindings when your object is destroyed. Failing to do so can cause crashes when the event fires after your object is gone:
```cpp
Hello->_GetPublisher()->OnLastChangedBP.RemoveDynamic(this, &UMyClass::OnLastChanged);
```
:::

</TabItem>
</Tabs>
