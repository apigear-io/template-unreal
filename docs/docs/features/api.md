---
sidebar_position: 1
sidebar_label: "API"
title: "API Feature: UInterface, USTRUCT & UENUM for Unreal"
description: "Generate Unreal Engine interfaces, structs, and enums from API definitions. Full Blueprint and C++ support with property change notifications and async operations."
keywords: [uinterface, ustruct, uenum, unreal engine api, blueprint interface, c++ interface]
---

import CodeBlock from '@theme/CodeBlock';
import helloWorldModuleComponent from '!!raw-loader!./data/helloworld.module.yaml';

# API Feature

The `api` feature is the foundation for code generation. It generates:

- Unreal interfaces (`UInterface`) for each API interface
- Abstract base classes with property storage and change notification
- Data types: `USTRUCT` for structs and `UENUM` for enumerations
- Blueprint-compatible property accessors and operations
- Signal delegates for reactive programming

:::note
The `api` feature generates interface definitions only. For a working implementation, also enable the [stubs](stubs.md) feature.
:::

## Files overview per module

Using the example API definition:

<details>
  <summary>Hello World API (click to expand)</summary>
  <CodeBlock language="yaml" showLineNumbers>{helloWorldModuleComponent}</CodeBlock>
</details>

The following file structure is generated in the `IoWorldAPI` module:

```bash
📂IoWorld/Source/IoWorldAPI
 ┣ 📂Private
 ┃ ┣ 📂Generated
 ┃ ┃ ┣ 📂api
 ┃ ┃ ┃ ┣ 📜AbstractIoWorldHello.cpp
 ┃ ┃ ┃ ┣ 📜IoWorld_data.cpp
 ┃ ┃ ┃ ┗ 📜IoWorldHelloBPAdapter.cpp
 ┃ ┃ ┣ 📜IoWorldAPI.cpp
 ┃ ┃ ┗ 📜IoWorldLogCategories.cpp
 ┃ ┗ 📂IoWorld
 ┃   ┗ 📂Generated
 ┃     ┗ 📂api
 ┃       ┗ 📜IoWorldHelloPublisher.cpp
 ┣ 📂Public
 ┃ ┗ 📂IoWorld
 ┃   ┗ 📂Generated
 ┃     ┣ 📂api
 ┃     ┃ ┣ 📜IoWorld_apig.h
 ┃     ┃ ┣ 📜IoWorld_data.h
 ┃     ┃ ┣ 📜IoWorldHelloInterface.h
 ┃     ┃ ┣ 📜IoWorldHelloBPInterface.h
 ┃     ┃ ┣ 📜IoWorldHelloBPHelperInterface.h
 ┃     ┃ ┣ 📜IoWorldHelloBPAdapter.h
 ┃     ┃ ┗ 📜AbstractIoWorldHello.h
 ┃     ┣ 📜IoWorldAPI.h
 ┃     ┗ 📜IoWorldLogCategories.h
 ┗ 📜IoWorldAPI.Build.cs
```

:::note
Private also contains `IoWorldHelloLatentAction.h` for Blueprint async operations support.
:::

## Enums and Structures

The file `IoWorld_data.h` contains all data types defined in your API module.

### Enums

For each enum in your API, a `UENUM` is generated:

```cpp
UENUM(BlueprintType)
enum class EIoWorldWhen : uint8
{
    IWW_Now = 0 UMETA(Displayname = "Now"),
    IWW_Soon = 1 UMETA(Displayname = "Soon"),
    IWW_Never = 2 UMETA(Displayname = "Never")
};
```

The enum values are prefixed with the enum name initials (`IWW_` for `IoWorld::When`) to ensure uniqueness across modules.

:::tip
Enums are fully Blueprint-compatible and appear in dropdowns with their display names.
:::

### Structs

For each struct in your API, a `USTRUCT` is generated:

```cpp
USTRUCT(BlueprintType)
struct IOWORLDAPI_API FIoWorldMessage : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|IoWorld")
    FString content{FString()};

    FString ToJSON(bool bPrettyPrint = false) const;
    FString ToString() const;
    explicit operator FString() const;

    bool operator==(const FIoWorldMessage& rhs) const;
    bool operator!=(const FIoWorldMessage& rhs) const;
};
```

Each struct includes:
- `FTableRowBase` inheritance for DataTable compatibility
- `UPROPERTY` declarations for all fields with Blueprint read/write access and default initializers
- JSON serialization (`ToJSON()`) and string conversion methods
- Equality comparison operators

## Interfaces

For each interface in your API module, several files are generated to support both C++ and Blueprint usage.

### Interface Definition (`IoWorldHelloInterface.h`)

The core interface as a Unreal `UInterface`. It includes the Publisher accessor, operations (synchronous, async with `TFuture`, and Blueprint latent), and property accessors:

```cpp
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UIoWorldHelloInterface : public UInterface
{
    GENERATED_BODY()
};

class IOWORLDAPI_API IIoWorldHelloInterface
{
    GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|IoWorld|Hello")
	virtual UIoWorldHelloPublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|IoWorld|Hello|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void SayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, const FIoWorldMessage& Msg, EIoWorldWhen When) = 0;
	virtual TFuture<int32> SayAsync(const FIoWorldMessage& Msg, EIoWorldWhen When) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|IoWorld|Hello|Operations")
	virtual int32 Say(const FIoWorldMessage& Msg, EIoWorldWhen When) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|IoWorld|Hello|Properties")
	virtual FIoWorldMessage GetLast() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|IoWorld|Hello|Properties")
	virtual void SetLast(UPARAM(DisplayName = "Last") const FIoWorldMessage& InLast) = 0;
};
```

The interface uses a **Publisher** pattern for reactive updates. The Publisher object (`UIoWorldHelloPublisher`) contains all delegates for signals and property changes.

### Properties

Properties are exposed through getter/setter methods with `UFUNCTION(BlueprintCallable)` for Blueprint access. Each property also has change delegates (C++ and Blueprint variants) for reactive updates:

```cpp
// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FIoWorldHelloLastChangedDelegate, const FIoWorldMessage& /* Last */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIoWorldHelloLastChangedDelegateBP, const FIoWorldMessage&, Last);
```

### Operations

Operations are generated with three variants to support different use cases:

#### Synchronous (Blocking)

The basic synchronous method blocks until completion:

```cpp
virtual int32 Say(const FIoWorldMessage& Msg, EIoWorldWhen When) = 0;
```

#### Asynchronous with TFuture (C++)

For non-blocking C++ code, use the `TFuture` variant:

```cpp
virtual TFuture<int32> SayAsync(const FIoWorldMessage& Msg, EIoWorldWhen When) = 0;
```

Usage example:

```cpp
// Non-blocking call - returns immediately
TFuture<int32> Future = Hello->SayAsync(Msg, EIoWorldWhen::IWW_Now);

// Option 1: Chain a callback
Future.Next([](const int32& Result) {
    UE_LOG(LogTemp, Log, TEXT("Say returned: %d"), Result);
});

// Option 2: Wait for result (blocks current thread)
int32 Result = Future.Get();

// Option 3: Check if ready without blocking
if (Future.IsReady())
{
    int32 Result = Future.Get();
}
```

#### Asynchronous with Latent Actions (Blueprints)

For Blueprint support, a latent action version is generated:

```cpp
virtual void SayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo,
    int32& Result, const FIoWorldMessage& Msg, EIoWorldWhen When) = 0;
```

This appears as an async node in Blueprints with execution pins for completion. The result is available when the output execution pin fires.

:::tip
Use async variants for:
- Network operations (OLink, MsgBus) to avoid blocking the game thread
- Long-running computations
- Operations that may take variable time
:::

### Signals

Signals are events broadcast from the interface. Each signal has both C++ and Blueprint delegate variants:

```cpp
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FIoWorldHelloJustSaidDelegate, const FIoWorldMessage& /* Msg */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIoWorldHelloJustSaidDelegateBP, const FIoWorldMessage&, Msg);
```

The Publisher class (`UIoWorldHelloPublisher`) contains all signal and property change delegates. Access it through the interface:

```cpp
UIoWorldHelloPublisher* Publisher = Hello->_GetPublisher();

Publisher->OnJustSaidSignalBP.AddDynamic(this, &UMyClass::OnJustSaid);
Publisher->OnLastChangedBP.AddDynamic(this, &UMyClass::OnLastChanged);
```

The Publisher also supports batch subscription via subscriber interfaces for classes that need to handle multiple events.

#### Subscribing to Events

**Using delegates directly:**

```cpp
// For Blueprint-compatible binding (UFUNCTION required)
Hello->_GetPublisher()->OnJustSaidSignalBP.AddDynamic(this, &UMyClass::OnJustSaid);
Hello->_GetPublisher()->OnLastChangedBP.AddDynamic(this, &UMyClass::OnLastChanged);

// For C++ raw binding (no UFUNCTION needed)
Hello->_GetPublisher()->OnJustSaidSignal.AddRaw(this, &UMyClass::OnJustSaid);
Hello->_GetPublisher()->OnLastChanged.AddLambda([](const FIoWorldMessage& Last) {
    // Handle property change
});
```

**Using subscriber interfaces (recommended for multiple events):**

```cpp
// Implement IIoWorldHelloSubscriberInterface in your class
class UMyListener : public UObject, public IIoWorldHelloSubscriberInterface
{
    virtual void OnJustSaidSignal(const FIoWorldMessage& Msg) override;
    virtual void OnLastChanged(const FIoWorldMessage& Last) override;
};

// Subscribe to all events at once
TWeakInterfacePtr<IIoWorldHelloSubscriberInterface> Subscriber(this);
Hello->_GetPublisher()->Subscribe(Subscriber);

// Later: Unsubscribe
Hello->_GetPublisher()->Unsubscribe(Subscriber);
```

:::warning
Always remove delegate bindings before the subscribing object is destroyed to avoid dangling references.
```cpp
Hello->_GetPublisher()->OnJustSaidSignalBP.RemoveDynamic(this, &UMyClass::OnJustSaid);
```
:::

## Abstract Base Class

The `UAbstractIoWorldHello` class provides a partial implementation:

- **Lifecycle management**: Inherits from `UGameInstanceSubsystem` for automatic initialization/cleanup
- **Property storage**: Protected `UPROPERTY` members with Blueprint getters/setters
- **Publisher**: Manages signals and property change notifications
- **Async support**: Default implementations that execute synchronous operations on a thread pool
- **Pure virtual operations**: You must implement the synchronous operation methods

To create your own implementation, extend this class and implement the pure virtual methods. Alternatively, enable the [stubs](stubs.md) feature to generate a ready-to-use implementation.

:::note
The async implementations safely handle object destruction using weak pointers, preventing crashes if the object is destroyed while an async operation is in progress.
:::

## Blueprint Integration

The generated interface is fully Blueprint-compatible:

- All properties and operations are exposed as Blueprint-callable functions via `UFUNCTION` macros
- Signals and property changes can be bound using Blueprint event dispatchers
- Async operations work as latent nodes in Blueprint graphs

### Using in Blueprints

1. **Get the subsystem**: Use "Get Game Instance Subsystem" and select your interface type
2. **Read properties**: Call the getter function (e.g., `Get Last`)
3. **Write properties**: Call the setter function (e.g., `Set Last`)
4. **Call operations**: Call operation functions directly (e.g., `Say`)
5. **React to changes**: Bind to the property changed or signal delegates

## Using in C++

### Module Dependency

Add the API module to your `.Build.cs`:

```cs
PublicDependencyModuleNames.AddRange(new string[] { "IoWorldAPI" });
```

### Include Headers

```cpp
#include "IoWorld/Generated/api/IoWorldHelloInterface.h"
#include "IoWorld/Generated/api/IoWorld_data.h"
```

### Access the Interface

Through a subsystem (requires [stubs](stubs.md) feature):

```cpp
#include "IoWorld/Implementation/IoWorldHello.h"

TScriptInterface<IIoWorldHelloInterface> Hello =
    GetGameInstance()->GetSubsystem<UIoWorldHelloImplementation>();

// Read property
FIoWorldMessage LastMsg = Hello->GetLast();

// Write property
FIoWorldMessage NewMsg;
NewMsg.content = TEXT("Hello World");
Hello->SetLast(NewMsg);

// Call operation
int32 Result = Hello->Say(NewMsg, EIoWorldWhen::IWW_Now);
```

### Subscribe to Changes

**Using lambdas (simplest approach):**

```cpp
// Subscribe with lambda - no class method needed
Hello->_GetPublisher()->OnLastChanged.AddLambda([](const FIoWorldMessage& Last) {
    UE_LOG(LogTemp, Log, TEXT("Last changed to: %s"), *Last.content);
});

Hello->_GetPublisher()->OnJustSaidSignal.AddLambda([this](const FIoWorldMessage& Msg) {
    // Can capture 'this' if needed - be careful of object lifecycle
    HandleMessage(Msg);
});
```

**Using member functions (C++ delegates):**

```cpp
// In your class header - regular C++ method, no UFUNCTION needed
void OnLastChanged(const FIoWorldMessage& Last);
void OnJustSaid(const FIoWorldMessage& Msg);

// In implementation - bind to C++ delegates
Hello->_GetPublisher()->OnLastChanged.AddRaw(this, &UMyClass::OnLastChanged);
Hello->_GetPublisher()->OnJustSaidSignal.AddUObject(this, &UMyClass::OnJustSaid);
```

**Using Blueprint-compatible delegates (requires UFUNCTION):**

```cpp
// In your class header
UFUNCTION()
void OnLastChanged(const FIoWorldMessage& Last);

// In implementation - bind to BP delegates
Hello->_GetPublisher()->OnLastChangedBP.AddDynamic(this, &UMyClass::OnLastChanged);
```

:::caution
Always remove delegate bindings when your object is destroyed to prevent crashes:
```cpp
// For C++ delegates
Hello->_GetPublisher()->OnLastChanged.RemoveAll(this);

// For Blueprint delegates
Hello->_GetPublisher()->OnLastChangedBP.RemoveDynamic(this, &UMyClass::OnLastChanged);
```
:::

## Other Files

- `📜IoWorldAPI.Build.cs` - Unreal build configuration for the module, including dependencies
- `📜IoWorld_apig.h` - Module convenience header that includes all API headers
- `📜IoWorldLogCategories.h/cpp` - Log category definitions for the module
- `📜IoWorldHelloPublisher.cpp` - Publisher implementation for signals and property changes
