---
sidebar_position: 2
---
# Interface
The *interface* is at the core of [ObjectAPI](https://docs.apigear.io/objectapi/modules.html#interfaces) and offers an *Unreal* specific implementation for handling data in projects.

## Introduction
Every interface is designed to be used in *blueprints* and *C++*, as we well as to provide the business logic either in *blueprints* or in *C++*.
For more information on using and implementing interfaces in Blueprints check the [documentation](https://docs.unrealengine.com/implementing-blueprint-interfaces-in-unreal-engine/).


In the example we have an interface called *Hello*. It has a property *last* of type *Message*.
The operation *say* can be used to say a *msg* and specify *when*.
The signal *justSaid* could trigger when something was just said.

```yaml showLineNumbers {2,3,5,12} title="helloworld.module.yml interface section"
interfaces:
  - name: Hello
    properties:
      - { name: last, type: Message }
    operations:
      - name: say
        params:
          - { name: msg, type: Message }
          - { name: when, type: When }
        return:
          type: int
    signals:
      - name: justSaid
        params:
          - { name: msg, type: Message }
``` 

:::tip
The following explains the pure interface declaration. This can be used to inherit from it via *blueprints* or *C++* and provide your business logic.
If you want to start with a *stub* implementation check out the [stubs](/docs/features/stubs/intro.md) feature. There you only need to add your own logic.
:::

---------------

In *Unreal Engine C++* this interface is declared as:

```cpp {2,7} showLineNumbers
UINTERFACE(Blueprintable, MinimalAPI)
class UIoWorldHelloInterface : public UInterface
{
	GENERATED_BODY()
};

class IOWORLD_API IIoWorldHelloInterface
{
	GENERATED_BODY()

public:
   ...
};
```

* *Blueprintable* allows the use as a base class in *Blueprints*
* *WORLD_API* generates the proper import/export statements, this must match the module name
* *IWorldHelloInterface* the name of the interface consists of the *module* name and the specific *interface* name from the API specification

For more information please check the [*Unreal Engine* interface documentation](https://docs.unrealengine.com/ProgrammingAndScripting/GameplayArchitecture/Interfaces/).

## Operations

In our example we have an `say` operation specified as:
```yaml {2,4} showLineNumbers title="helloworld.module.yml interface operations section"
    operations:
      - name: say
        params:
          - { name: msg, type: Message }
          - { name: when, type: When }
        return:
          type: int
```

Before we can explain the declaration of the *operation* itself, we need to explain a few [**UFUNCTION** (documentation)](https://docs.unrealengine.com/ufunctions-in-unreal-engine/) macro keywords.
* *BlueprintNativeEvent* this function can be implemented in *Unreal Blueprints*
* *BlueprintCallable* this function can be called from *Unreal Blueprints*
* *Latent* this meta keyword enables functions to be run asynchronously

Every operation in the API has at least two declarations in the generated interface.
1. The operation itself e.g.
  ```cpp
   int32 Say(const FIoWorldMessage& Msg, const EIoWorldWhen& When);
   ```
   Due to the *BlueprintNativeEvent* this function is implemented by the *Unreal Engine* and **can not be overridden in *C++*** by the user. This should only be overridden when inheriting in *blueprints*.
3. The operation with the *_Implementation* postfix, e.g.
   ```cpp
   virtual int32 Say_Implementation(const FIoWorldMessage& Msg, const EIoWorldWhen& When) = 0;
   ```
   is a pure virtual function and **has to be overridden in *C++*** by the user when inheriting.

In case, the operation has a return value we generate additional declarations with an *Async* postfix.
For instance, the *say* function has four different functions declared.

The complete declaration looks like this:
```cpp 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|IoWorld|Hello", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void SayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, const FIoWorldMessage& Msg, EIoWorldWhen When);
	virtual void SayAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, const FIoWorldMessage& Msg, EIoWorldWhen When) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|IoWorld|Hello")
	int32 Say(const FIoWorldMessage& Msg, EIoWorldWhen When);
	virtual int32 Say_Implementation(const FIoWorldMessage& Msg, EIoWorldWhen When) = 0;
```

## Signals

In our example we have a `justSaid` signal specified as:
```yaml {2,4} showLineNumbers title="helloworld.module.yml interface signals section"
    signals:
      - name: justSaid
        params:
          - { name: msg, type: Message }
```

For signal handling we use [dynamic multicast delegates](https://docs.unrealengine.com/delegates-and-lamba-functions-in-unreal-engine/).
These delegates must be declared before use, for instance:

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIoWorldHelloJustSaidDelegate, const FIoWorldMessage&, Msg);
```

This signal has one parameter which must be added as postfix `_OneParam`.
* `FIoWorldHelloJustSaidDelegate` is the name of the delegate type. It is constructed based on the *module*, *interface* name and the actual name of the *signal* from line *2* above
* `const FIoWorldMessage&` is the type of the signal parameter and `Msg` the name

:::caution
Delegates cannot be exposed to *Blueprints* via *C++* interfaces. Therefore we must add some helper functions
:::
All implementations of the interface can now specify this *delegate* and consumers can bind to it.

However, this is the pure interface declaration and we cannot use any actual type.
Therefore we added getters for the delegate
```cpp
UFUNCTION(Category = "ApiGear|IoWorld|Hello")
virtual FIoWorldHelloJustSaidDelegate& GetJustSaidSignalDelegate() = 0;
```
Every actual implementation must return its own delegate in this function for consumers to bind to the delegate.

Also if we want to trigger this delegate from within a *blueprint* we need to call another helper function *broadcast*.
```cpp
UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|IoWorld|Hello", meta = (BlueprintProtected = "true"))
void BroadcastJustSaid(const FIoWorldMessage& Msg);
virtual void BroadcastJustSaid_Implementation(const FIoWorldMessage& Msg) = 0;
```
And again, the actual implementation must call *broadcast* on its delegate within this function.

## Properties

In our example we have a `last` property specified as:
```yaml {2} showLineNumbers title="helloworld.module.yml interface properties section"
    properties:
      - { name: last, type: Message }
```

Every property automatically has a *setter*, a *getter* and a *changed* signal. It is basically a combination of the operations and signals declaration above.

```cpp
// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIoWorldHelloLastChangedDelegate, const FIoWorldMessage&, Last);

...

class IOWORLD_API IIoWorldHelloInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(Category = "ApiGear|IoWorld|Hello")
	virtual FIoWorldHelloLastChangedDelegate& GetLastChangedDelegate() = 0;

...
	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|IoWorld|Hello")
	FIoWorldMessage GetLast() const;
	virtual FIoWorldMessage GetLast_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|IoWorld|Hello")
	void SetLast(const FIoWorldMessage& Last);
	virtual void SetLast_Implementation(const FIoWorldMessage& Last) = 0;

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|IoWorld|Hello", meta = (BlueprintProtected = "true"))
	void BroadcastLastChanged(const FIoWorldMessage& Last);
	virtual void BroadcastLastChanged_Implementation(const FIoWorldMessage& Last) = 0;
};
```

## Usage

### Blueprint
### C++
